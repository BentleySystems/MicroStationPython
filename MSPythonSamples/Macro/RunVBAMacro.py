# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyMstnPlatform import *

'''
This sample demos how to run Macro defined in mvba file by invoking the key command. 
1. Invoke "vba load [mvba file]" Command to load mvba project
2. Invoke "vba run [module.macro]" Command to run Macro which will start the copy tool
3. Select an element in the active model and place a copy of it at the cursor position.
'''

def RunVBAMacro():
    DataDir = os.path.join(os.path.dirname(__file__), "../data")
    mvbaFilepath = BeFileName(os.path.join(DataDir, "CopyMacro.mvba")) # Path to the mvba file
    MacroName = "modCommands.CopyElement"  # Name of Macro to be run

    # Load the VBA project
    print(f"Loading VBA project from: {mvbaFilepath}")
    PyCadInputQueue.SendKeyin(f"vba load {mvbaFilepath}")

   # Run the specified macro
    print(f"Running Macro: {MacroName}")
    PyCadInputQueue.SendKeyin(f"vba run {MacroName}")

if __name__ == "__main__":
    RunVBAMacro()


