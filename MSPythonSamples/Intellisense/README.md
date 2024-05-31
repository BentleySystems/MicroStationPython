# VSCode Intellisense

This folder contains the .pyi files for the MicroStation Python API's to enable Intellisense in VSCode.


## VSCode Extensions for Intellisense

You need to install the PyLance Extension from Microsoft for intellisense to work with Python in VSCode

## settings.json

You need to add the following lines in your settings.json file for the project folder you are editing


    "python.languageServer": "Default",
    "python.analysis.extraPaths": [
        "C:/ProgramData/Bentley/PowerPlatformPython/Examples/Microstation/Intellisense"],
		

Once you have this set you will find that Ctrl-Space will work for opening the intellisense window in VSCode and whilst you are writing code the intellisense will display information regarding the object you are editing