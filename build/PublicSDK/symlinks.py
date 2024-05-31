#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os

class SymLinkError (Exception):
    def __init__(self, message, trace=None):
        self.errmessage = message
        if trace:
            self.stackTrace = trace
        else:
            import traceback
            self.stackTrace = traceback.extract_stack()
    def __str__(self):
        return "\n" + self.errmessage

class SymLinkTargetError (SymLinkError):
    def __init__(self, message, trace=None):
        SymLinkError.__init__(self, message)

GET_SYM_LINK_STATUS_Success     = 0
GET_SYM_LINK_STATUS_NotSymLink  = 1
GET_SYM_LINK_STATUS_Error       = 2

    
#-------------------------------------------------------------------------------------------
# WINDOWS SPECIFIC SYMLINKS
#-------------------------------------------------------------------------------------------
if os.name == 'nt':
    import pywintypes, struct, win32file, win32con, winioctlcon

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def isSymbolicLink (pathName):
        attr = win32file.GetFileAttributes (pathName)
        if attr == -1:
            return False

        return (0 != (attr & 0x400))

    #----------------------------------------------------------------------------------------
    # @bsimethod
    #----------------------------------------------------------------------------------------
    # Calls getSymlinkImmediateTarget until it does not reach a symbolic link. There may still be directory symbolic links embedded in the path.
    def getSymlinkFinalTarget(path):
        while True:
            if not isSymbolicLink(path):
                return path if os.path.exists (path) else None

            linkTargetPath = getLinkTargetRealPath(path)
            if None == linkTargetPath:
                break
            
            path = linkTargetPath

        return path if os.path.exists (path) else None

    #----------------------------------------------------------------------------------------
    # @bsimethod
    #----------------------------------------------------------------------------------------
    def getFinalPath(path):
        handle = win32file.CreateFile(path, win32file.GENERIC_READ, win32file.FILE_SHARE_READ, None, win32file.OPEN_EXISTING, win32file.FILE_FLAG_BACKUP_SEMANTICS, 0)

        finalName = None
        try:
            finalName = win32file.GetFinalPathNameByHandle(handle, win32con.FILE_NAME_OPENED)
        except win32file.error as err:
            if err.winerror == 2:
                # This is for docker where the source is mounted in the container.
                finalName = getSymlinkFinalTarget (path)
            if not finalName:
                raise err
        except win32file.error as err:
            raise err
        finally:
            handle.Close()

        if finalName:
            # GetFinalPathNameByHandle always returns a long-name path (e.g. \\?\C:\... or \\?\UNC\host\share\...).
            # Aside from being ugly, not all commands and shells support this syntax, so try to normalize.
            if len(finalName) > 6 and ":" == finalName[5]:
                return finalName[4:]

            if len(finalName) > 7 and "UNC" == finalName[4:7]:
                return "\\" + finalName[7:]

        return finalName

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def tryGetFinalSymlinkTarget(linkname):
        try:
            return [GET_SYM_LINK_STATUS_Success, getFinalPath(linkname)]
        except:
            return [GET_SYM_LINK_STATUS_Error, None]

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def resetFileTime (linkname, target):
        if not os.path.isfile(target): return

        fstat = os.stat (target)
        handle = win32file.CreateFile (linkname, win32file.GENERIC_WRITE, win32file.FILE_SHARE_WRITE, None,
                              win32file.OPEN_EXISTING, win32file.FILE_FLAG_OPEN_REPARSE_POINT|win32file.FILE_FLAG_BACKUP_SEMANTICS, 0)
        win32file.SetFileTime (handle, pywintypes.Time(fstat[9]), pywintypes.Time(fstat[7]), pywintypes.Time(fstat[8])) # pylint: disable=no-member
        handle.Close()

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def deleteSymLink (linkName):
        if os.path.isdir (linkName):
            win32file.RemoveDirectory (linkName)
        else:
            win32file.DeleteFile (linkName)

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def createOsSymLink (linkName, targetFile, isDir):
        try:
            dirFlag = 1 if isDir else 0
            win32file.CreateSymbolicLink (linkName, targetFile, dirFlag)
            return None
        except winioctlcon.pywintypes.error as err:
            # Perhaps another thread created this symlink already, so return BentleyStatus.eSUCCESS if it matches what we wanted
            if os.path.exists (linkName):
                if (checkSameTarget (linkName, targetFile)):
                    return None
            # Otherwise, something else went wrong so raise the error
            msg = "####CreateSymlink error: {0}, {1}".format (err.args[2], linkName)
            raise SymLinkError (msg)
    
    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def getLinkTargetRealPath(pathIn):
        pathOut = None
        handle = None
        try:
            handle = win32file.CreateFile(pathIn, win32file.GENERIC_READ, win32file.FILE_SHARE_READ, None, win32file.OPEN_EXISTING, win32file.FILE_FLAG_OPEN_REPARSE_POINT | win32file.FILE_FLAG_BACKUP_SEMANTICS, 0)
            bufIn =  win32file.AllocateReadBuffer(1024)
            bufOut = win32file.DeviceIoControl(handle, winioctlcon.FSCTL_GET_REPARSE_POINT, None, bufIn, None)
            headerFormat = 'lhhhhhhl'
            headerSize = struct.calcsize(headerFormat)
            reparseTag, reparseDataLength, reserved, subNameOffset, subNameLength, printNameOffset, printNameLength, flags = struct.unpack(headerFormat, bufOut[:headerSize])
            pathStart = headerSize + printNameOffset
            pathEnd   = pathStart + printNameLength
            pathOut   = bufOut[pathStart:pathEnd].decode('utf-16')
        except winioctlcon.pywintypes.error as err: # pylint: disable=no-member
            pass
            #typically win32error.ERROR_NOT_A_REPARSE_POINT (4390)
        finally:
            if handle:
                handle.Close()
        return pathOut

#-------------------------------------------------------------------------------------------
# LINUX SPECIFIC SYMLINKS
#-------------------------------------------------------------------------------------------
elif os.name == 'posix':
    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def isSymbolicLink (pathName):
        return os.path.islink (pathName)

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def tryGetFinalSymlinkTarget(linkname):
        while isSymbolicLink(linkname):
            try:
                linkname = os.readlink(linkname)
            except:
                return [GET_SYM_LINK_STATUS_Error, None]

        return [GET_SYM_LINK_STATUS_Success, linkname]

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def resetFileTime (linkname, target):
        if not os.path.isfile(target):
            return

        os.stat (target)
        #os.utime (linkname, (fstat.st_atime, fstat.st_mtime))

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def deleteSymLink (linkName):
        os.unlink (linkName)

    #-------------------------------------------------------------------------------------------
    # bsimethod
    #-------------------------------------------------------------------------------------------
    def createOsSymLink (linkname, targetFile, isDir):
        try:
            os.symlink (targetFile, linkname)
        except OSError as err:
            # Perhaps another thread created this symlink already, so return BentleyStatus.eSUCCESS if it matches what we wanted
            if os.path.exists (linkname):
                if (checkSameTarget (linkname, targetFile)):
                    return None
            # Otherwise, something else went wrong so raise the error
            msg = "####CreateSymlink error: {0} - {1} -> {2} (hint: check capitalization of target file path)".format (err, linkname, targetFile)
            raise SymLinkError (msg)

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def getSymlinkTarget(linkname):
    status, linkTarget = tryGetFinalSymlinkTarget(linkname)
    
    # Allow non-symbolic links to be resolved in this same way. This ensures, for example on Windows, that path canonicalization occurs equally.
    if status not in [GET_SYM_LINK_STATUS_Success, GET_SYM_LINK_STATUS_NotSymLink]:
        raise SymLinkError ("####Cannot determine target of '{0}' (status {1}); an OS error occured.".format(linkname, status))
    
    return linkTarget

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def isTargetSame (linkname, testTarget):
    try:
        return getSymlinkTarget(normalizePathName(testTarget)).lower() == getSymlinkTarget(normalizePathName(linkname)).lower()
    except SymLinkError as err:
        return False

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def checkSameTarget (linkName, testTarget):
    currTarget = getSymlinkTarget(linkName)
    testTarget = getSymlinkTarget(testTarget)

    if testTarget.lower() != currTarget.lower():
        return False

    return True

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def makeSureDirectoryExists (dirName):
    if os.path.exists(dirName):
        return
    os.makedirs (dirName)

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def makeSureBaseDirectoryExists (filename):
    dir, file = os.path.split (filename)
    makeSureDirectoryExists (dir)

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def normalizePathName (pathName):
    # On windows abspath will convert \ to /, but the reverse isn't true on Posix.
    return os.path.abspath(os.path.expandvars(pathName)).replace ('\\', os.sep)

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def createFileSymLink (linkName, targetFile, checkSame=True, checkTargetExists=False, skipIntermediateLinks=False):
    linkName   = normalizePathName (linkName)
    targetFile = normalizePathName (targetFile)

    targetExists = os.path.exists (targetFile)

    if checkTargetExists and not targetExists:
        raise SymLinkError ("####Target File {0} does not exist".format (targetFile))

    if skipIntermediateLinks and targetExists:
        targetFile = getSymlinkTarget (targetFile)

    if os.path.exists (linkName):
        if (checkSameTarget (linkName, targetFile)):
            return 0
        if checkSame:
            raise SymLinkTargetError ("####Cannot link:\n '{0}' to: \n '{1}', because it is already linked to: \n '{2}'".format (linkName, targetFile, getSymlinkTarget (linkName)))
        deleteSymLink (linkName)

    makeSureBaseDirectoryExists (linkName)
    createOsSymLink (linkName, targetFile, False)

    resetFileTime (linkName, targetFile)    # set link file to date/time of target
    return 1

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def createDirSymLink (linkName, targetDir, checkSame=True, checkTargetExists=False, skipIntermediateLinks=False):
    linkName  = normalizePathName(linkName)
    targetDir = normalizePathName(targetDir)

    targetExists = os.path.exists (targetDir)
    if checkTargetExists and not targetExists:
        raise SymLinkError ("####Target Directory {0} does not exist".format (targetDir))

    if skipIntermediateLinks and targetExists:
        targetDir = getSymlinkTarget (targetDir)

    if os.path.exists (linkName):
        if (checkSameTarget (linkName, targetDir)):
            return 0
        if checkSame:
            raise SymLinkTargetError ("####Cannot link:\n '{0}' to: \n '{1}', because it is already linked to: \n '{2}'".format (linkName, targetDir, getSymlinkTarget (linkName)))
        deleteSymLink (linkName)

    makeSureBaseDirectoryExists (linkName)
    createOsSymLink (linkName, targetDir, True)
    return 1

# TODO_KN: This will not work on other platforms... Technically we aren't making transkit.zips on other platforms though...
#-------------------------------------------------------------------------------------------
# Method to symlink hg.exe from the path to a target dir (used for transkit delivery)
# bsimethod
#-------------------------------------------------------------------------------------------
def createHgSymlink (linkName):
    import which
    HG_EXE_NAME = "hg.exe"
    hg_exe = which.which (HG_EXE_NAME)
    if not hg_exe:
        msg = "###CreateSymLink error: Cannot find {0} in the PATH".format (HG_EXE_NAME);
        raise SymLinkError (msg)

    hg_dir = os.path.dirname (hg_exe)

    s = createDirSymLink (linkName, hg_dir)

    return s
