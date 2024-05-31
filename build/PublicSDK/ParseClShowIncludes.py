#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import sys, os
import win32api

#-----------------------------------------------------------------------------------------------
# @bsimethod
#-----------------------------------------------------------------------------------------------
def doParse (includes_file,depend_file,writefile):
    f = open (includes_file)
    lines = f.readlines()
    f.close ()

    deps = set()
    nondeps = ''

    for line in lines:
        if line.startswith('Note: including file:'):
            dep = line[21:].strip()
            #if os.name == 'nt':
            #    dep = win32api.GetShortPathName (dep)
            dep = os.path.normpath(dep)
            #dep = os.path.normcase(dep)
            dep = dep.replace('\\', '/') # use forward slashes for path separators
            #dep = dep.replace(' ', '\ ') # escape spaces in paths with a backslash
            if dep.find (' ') != -1:
                dep = '\"' + dep + '\"'
            deps.add(dep)
        else:
            print (line)

    # Write the .d file, one dependency per line
    # But, on error, do NOT write the dependency file. That would create an incomplete file, which 
    # PreCompileHeader.mke would try to use next time around to get dependencies for rebuilding the PCH.
    if writefile:
        f = open (depend_file, 'wt')
        for dep in sorted(deps):
            f.write (dep+'\n')
        f.close ()

#-----------------------------------------------------------------------------------------------
# @bsimethod
#-----------------------------------------------------------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) < 4:
        print ('This transforms the output of MS cl -showIncludes into a list of file names')
        print ('syntax: ' + sys.argv[0] + ' inputShowIncludesFileName outputDependencyFileName compilerErrorLevel')
        exit (1)
    
    compilerError = int (sys.argv[3])
        
    doParse (sys.argv[1], sys.argv[2], (compilerError==0))

    exit (compilerError)
