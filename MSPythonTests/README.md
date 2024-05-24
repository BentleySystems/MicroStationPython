# API Tests

This folder and its subfolders contain pytest tests which execute the Microstation Python API functions

## Running the Tests

The simplest way to run the tests is to do :

bmake PlatformTests

ensure that if you are not using the powerplatformpython delivered version of python, that your version matches exactly with it. Also ensure that the necessary python libraries are installed such as : pytest, numpy etc.

**Note: The built .pyd files from the bmake MSPython.mke, have to be located in the correct location in the Microstation delivery. This makefile will move the original .pyd files to a new name with _Original on the end i.e. MSPyBentley.pyd -> MSPyBentley_Original.pyd. Then a symlink will be added in that location to the .pyd just built.**

## Using VSCode to run and debug the tests.

Firstly python needs to be able to find the MSPyBentley.pyd etc. files in the Microstation Install. This is best achieved by using a .env file in your VSCode {workspaceRoot} directory.
If you use the OpenFolder method of opening VSCode files for editing then this is the folder you put the .env file in.

In this .env file you need to set PYTHONPATH i.e.:

PYTHONPATH=c:/Program Files/Bentley/Microstation 2024/;c:/Program Files/Bentley/Microstation 2024/Assemblies/;C:/Program Files/Bentley/Microstation 2024/MdlSys/Asneeded/;C:/Program Files/Bentley/Microstation 2024/MdlSys/FileHandler/;

Note : its also been noted that PYTHONPATH doesnt like spaces in directory names, so you may need to use the ~ version obtainable using dir /x from a command prompt

Once you have this setup ensure that the following extensions are installed in VSCode :

Python
Python Test Explorer For Visual Studio Code

In your VSCode settings.json file add :

    "python.testing.pytestArgs": [
        "c:/MicrostationPython/MSPythonTests/PlatformTests/PublishedTests/"
    ],
    "python.testing.unittestEnabled": false,
    "python.testing.pytestEnabled": true,
    "python.testing.cwd" : "c:/MicrostationPython/MSPythonTests/PlatformTests/PublishedTests/",
    "pythonTestExplorer.testFramework": "pytest",

Open your MicroStationSDK command shell. Set the MSPYTESTDATA environment variable to point to MicroStationPython/MSPythonTests/PlatformTests/data/

i.e. 

set MSPYTESTDATA=c:MicroStationPython/MSPythonTests/PlatformTests/data/

You then need to start VSCode from your MicrostationSDK command shell using by typing "code" at the command prompt. This is so it can pickup your shell environment variables

When you start VSCode and click on the flask icon in the left hand column you should see the tests listed. If you dont you need to open the Terminal window and go to the output tab, then on the right side click Python and look at the errors


