from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from MeshToolCreateMesh import *
import os

'''
This sample demonstrates how to add a key-in command and use that command to launch a DgnElementSetTool, which creates a mesh element.
'''

def Place_MeshFunction():
    """
    Installs a new instance of the mesh creation tool to place a mesh 
    using a fixed block coordinate system. 
    """
    MeshCreateTool.InstallNewInstance(COMMAND_PlaceMeshFunction)

def Place_MeshClass():
    """
    Installs a new instance of the mesh creation tool to place a mesh 
    with variable size indexing.
    """
    MeshCreateTool.InstallNewInstance(COMMAND_PlaceMeshClass)

if __name__ == "__main__":
    # Load the XML command table for mesh tools
    keyinXml = os.path.dirname(__file__) + '/MeshTools.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(
        WString(__file__), WString(keyinXml)
    )
