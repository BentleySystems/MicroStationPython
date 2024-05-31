#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os, re, subprocess, sys, tempfile

if os.name == 'nt':
  import win32api

# Controls debugging output to stderr.
s_debug = False
if not s_debug and "PRG" in os.environ:
    s_debug = True

#----------------------------------------------------------------------------------------
# @bsimethod
#----------------------------------------------------------------------------------------
def printUsage():
    print("Arguments: GeneratedMkiPath Command [CommandArgs]")

if os.name == 'nt':
    #----------------------------------------------------------------------------------------
    # @bsimethod
    #----------------------------------------------------------------------------------------
    def sub8dot3Path(matchObj):
        fullPath = matchObj.group(0)
        
        # I think we only care about directories... everything from vcvars should be.
        if not os.path.exists(fullPath) or not os.path.isdir(fullPath):
            if s_debug:
                sys.stderr.write('Path "{0}" either does not exist or is not a directory, and will not be used.\n'.format(fullPath))
            
            return ''

        # Ensure paths end in slahes (regardless of whether we have to shorten it)
        if fullPath[-1] != '\\':
            fullPath += '\\'

        # bmake only really cares if there are spaces...
        if not ' ' in fullPath:
            if s_debug:
                sys.stderr.write('Path "{0}" does not contain spaces, and will not be converted.\n'.format(fullPath))

            return fullPath

        try:
            shortPath = win32api.GetShortPathName(fullPath)
        except:
            if s_debug:
                sys.stderr.write('Path "{0}" failed to convert to 8.3, and will not be used.\n'.format(fullPath))
            
            return ''
        
        if s_debug:
            sys.stderr.write('Converted path "{0}" -> "{1}"\n'.format(fullPath, shortPath))

        return shortPath

#----------------------------------------------------------------------------------------
# @bsimethod
#----------------------------------------------------------------------------------------
def main():
    if len(sys.argv) < 3:
        printUsage()
        sys.exit(1)

    generatedMkiPath = sys.argv[1]
    
    commandArgIndex = 2
    excludePatterns = []
    varsToPruneMissing = []
    
    while sys.argv[commandArgIndex].startswith("--exclude=") or sys.argv[commandArgIndex].startswith("--pruneMissing="):
        if sys.argv[commandArgIndex].startswith("--exclude="):
            excludePatterns.append(sys.argv[commandArgIndex].split("=", 1)[1].lower())
        elif sys.argv[commandArgIndex].startswith("--pruneMissing="):
            varsToPruneMissing.append(sys.argv[commandArgIndex].split("=", 1)[1].lower())
        
        commandArgIndex += 1

    if s_debug:
        sys.stderr.write('excludePatterns=\n')
        for excludePattern in excludePatterns:
            sys.stderr.write('    {0}\n'.format(excludePattern))
        sys.stderr.write('\n')

        sys.stderr.write('varsToPruneMissing=\n')
        for varToPruneMissing in varsToPruneMissing:
            sys.stderr.write('    {0}\n'.format(varToPruneMissing))
        sys.stderr.write('\n')

    commandString = ' '.join(x if not ' ' in x else '"' + x + '"' for x in sys.argv[commandArgIndex:])
    
    envBeforePath = tempfile.mktemp()
    envAfterPath = tempfile.mktemp()
    
    # Run the command and capture the environment change
    #..............................................................................................
    if os.name == 'nt':
        captureCommand = ['cmd.exe', '/c', 'set', '>', envBeforePath, '&&'] + sys.argv[commandArgIndex:] + ['&&', 'set', '>', envAfterPath]
    else:
        captureCommand = ['printenv', '>', envBeforePath, '&&'] + sys.argv[commandArgIndex:] + ['&&', 'printenv', '>', envAfterPath]

    if s_debug:
        sys.stderr.write('captureCommand="{0}"\n'.format(' '.join(captureCommand)))

    if os.name == 'nt':
        runningProcess = subprocess.call (captureCommand)
    else:
        runningProcess = subprocess.call (' '.join(captureCommand), executable="bash", shell=True)


    # Read the before and after environments
    #..............................................................................................
    if not os.path.exists(envBeforePath):
        print('ERROR: Capture command did not create the "before" environment file.')
        sys.exit(1)

    beforeEnv = []
    with open(envBeforePath) as envBeforeFile:
        beforeEnv = [line.strip() for line in envBeforeFile.readlines()]
    
    os.unlink(envBeforePath)

    if s_debug:
        sys.stderr.write('beforeEnv=\n')
        for envVar in beforeEnv:
            sys.stderr.write('    {0}\n'.format(envVar))
        sys.stderr.write('\n')

    if not os.path.exists(envAfterPath):
        print('ERROR: Capture command did not create the "after" environment file.')
        sys.exit(1)

    afterEnv = []
    with open(envAfterPath) as envAfterFile:
        afterEnv = [line.strip() for line in envAfterFile.readlines()]

    os.unlink(envAfterPath)

    if s_debug:
        sys.stderr.write('afterEnv=\n')
        for envVar in afterEnv:
            sys.stderr.write('    {0}\n'.format(envVar))
        sys.stderr.write('\n')

    # Compute the difference between the environments, and sanitize the paths
    # Just capture entire changed variables... I don't think we need to care about exactly what changed
    #..............................................................................................
    rawEnvDiffSet = set(afterEnv).difference(set(beforeEnv))
    
    if s_debug:
        sys.stderr.write('rawEnvDiffSet=\n')
        for envVar in rawEnvDiffSet:
            sys.stderr.write('    {0}\n'.format(envVar))
        sys.stderr.write('\n')
    
    prunedEnvDiff = []
    for envVar in rawEnvDiffSet:
        if any(None != re.search(excludePattern, envVar.split("=", 1)[0].lower()) for excludePattern in excludePatterns):
            continue

        prunedEnvDiff.append(envVar)
    
    if s_debug:
        sys.stderr.write('prunedEnvDiff=\n')
        for envVar in prunedEnvDiff:
            sys.stderr.write('    {0}\n'.format(envVar))
        sys.stderr.write('\n')
    
    envDiff = []
    for envVar in prunedEnvDiff:
        if os.name == 'nt':
            # Convert long paths to 8.3 format
            envVar = re.sub(r'[a-zA-Z]:\\[^;]+', sub8dot3Path, envVar)

        # Convert backslash to forward slash
        envVar = envVar.replace('\\', '/')

        # Prune missing directories if requested; helps avoid warnings during the build for missing UWP paths on certain machines
        envVarName = envVar.split("=", 1)[0]
        if envVarName.lower() in varsToPruneMissing:
            allPaths = envVar.split("=", 1)[1].split(";")
            goodPaths = [d for d in allPaths if os.path.exists(d)]
            envVar = "{0}={1}".format(envVarName, ";".join(goodPaths))

            if s_debug:
                sys.stderr.write("prunedMissing in ")
                sys.stderr.write(envVarName)
                sys.stderr.write(":\n  from=")
                sys.stderr.write(";".join(allPaths))
                sys.stderr.write("\n    to=")
                sys.stderr.write(";".join(goodPaths))
                sys.stderr.write("\n")

        # Escape bmake comment characters
        envVar = envVar.replace('#', '\\#')

        # Append
        envDiff.append(envVar)

    # Makes printouts easier to search through
    envDiff.sort()

    if s_debug:
        sys.stderr.write('\n') # makes up for sub8dot3Path above
        sys.stderr.write('envDiff=\n')
        for envVar in envDiff:
            sys.stderr.write('    {0}\n'.format(envVar))
        sys.stderr.write('\n')

    # Generate the MKI file
    #..............................................................................................
    with open(generatedMkiPath, 'w') as generatedMkiFile:
        generatedMkiFile.write('# Generated by "{0}" to capture the environment changes of "{1}".\n'.format(sys.argv[0], commandString))
        generatedMkiFile.write('\n')

        # As bmake variables
        for envVar in envDiff:
            generatedMkiFile.write('{0}\n'.format(envVar))
        
        # As environment variables
        generatedMkiFile.write('\n')
        generatedMkiFile.write('always:\n')
        
        for envVar in envDiff:
            generatedMkiFile.write('    ~@putenv {0}\n'.format(envVar))

        generatedMkiFile.write('\n')

        # As diagnostic messages
        generatedMkiFile.write('%if defined (TOOLSET_DIAGNOSTICS)\n')
        generatedMkiFile.write('%if "full" == $(TOOLSET_DIAGNOSTICS)\n')

        for envVar in envDiff:
            if envVar.find (";") > -1:
               envVarName = envVar.split("=", 1)[0]
               envVarValues = envVar.split("=", 1)[1].split(";")
               generatedMkiFile.write('    %message toolset> vcvars set {0}=\n'.format(envVarName))
               for envValue in envVarValues:
                    generatedMkiFile.write('    %message toolset>            {0}\n'.format(envValue))
            else:
                generatedMkiFile.write('    %message toolset> vcvars set {0}\n'.format(envVar))

        generatedMkiFile.write('%endif\n')
        generatedMkiFile.write('%endif\n')

    # Done
    #..............................................................................................
    sys.exit(0)

if __name__ == '__main__':
    main()
