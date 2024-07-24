REM ---------------------------------------------------------------------------------------------
REM  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
REM See LICENSE.md in the repository root for full copyright notice.
REM ---------------------------------------------------------------------------------------------
@ECHO ON
@IF NOT "%ECHO%." == "." ECHO %ECHO%
REM To not see this information echo to the screen
REM set ECHO as an environment variable in your system configuration.
REM For more information see the MicroStation SDK README.

REM ** SET MS **
set msdrive=%~d1
set mssource=%~p1
SET MS=%msdrive%%mssource%
for %%I in ("%MS%") do set MS=%%~sI
IF "%MS%." == "." goto USAGE_Error

set TOOL_VERSION=14.16
set BB_DEFAULT_TOOLSET=VS2019

REM MDLTOOLS is the location of the MDLSDK
set mdltoolsdrive=%~d2
set mdltoolspath=%~p2
set mdltools=%mdltoolsdrive%%mdltoolspath%
for %%I in ("%mdltools%") do set mdltools=%%~sI
REM make the internal settings work.
set toolspath=%mdltools%bin\
set MSMDE=%mdltools%

set pythonMKIdrive=%~d3
set pythonMKIpath=%~p3

REM ** Setup the compiler **
if defined VS120COMNTOOLS GOTO MdlSetup
@ECHO #-----------------------------------------------------------------------
@ECHO # Warning: Compiler Setup error
@ECHO # VS120COMNTOOLS not defined. That should have been set when the
@ECHO # .NET 2013 compiler was installed. You will not be able to do
@ECHO # any native C, C++ or C# development using the default compiler
@ECHO # for MicroStation.
@ECHO #-----------------------------------------------------------------------

:MdlSetup
set BMAKE_OPT=-I%pythonMKIdrive%%pythonMKIpath%
set PATH=%MS%;%mdltools%bin\;%PATH%

REM Set this if you want the output to go to a different location; otherwise it will appear next to MicroStation
REM MSMDE_OUTPUT = %MS%

rem Create the following folders if they do not exist
if not exist %MS%mdl\objects. mkdir %MS%mdl\objects
if not exist %MS%mdl\reqdobjs. mkdir %MS%mdl\reqdobjs
if not exist %MS%mdl\rscobj. mkdir %MS%mdl\rscobj

cd /d %msmde%

GOTO end

:USAGE_Error
@ECHO #-----------------------------------------------------------------------
@ECHO # ERROR: Bad parameter
@ECHO # Usage = MSTNDEVVARS.BAT [MicroStation dir] [MicroStation SDK dir]
@ECHO # e.g. %comspec% /x /k "C:\Program Files\Bentley\MicroStation\mdl\bin\mstndevvars.bat C:\Program Files\Bentley\MicroStation\ C:\Program Files\Bentley\MicroStationSDK\"
@ECHO #-----------------------------------------------------------------------
GOTO end

:CompilerSetup_Error
@ECHO #-----------------------------------------------------------------------
@ECHO # ERROR: Compiler Setup error
@ECHO # VCINSTALLDIR not defined. That should have been set when the
@ECHO # vsvars32.bat was run.
@ECHO #-----------------------------------------------------------------------

:end
