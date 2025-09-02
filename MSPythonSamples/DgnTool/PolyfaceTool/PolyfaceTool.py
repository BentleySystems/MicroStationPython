import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from PolyfaceCreateTool import *

'''
This sample demonstrates how to add a key-in command and use that command to launch a DgnElementSetTool
'''

def CreatePolyface():
    """
    Activates the Polyface creation tool.
    """
    StartPolyfaceCreateTool()

if __name__ == "__main__":
    # Load the XML command table for Polyface tools
    keyinXml = os.path.dirname(__file__) + '/PolyfaceTool.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(
        WString(__file__), WString(keyinXml)
    )
