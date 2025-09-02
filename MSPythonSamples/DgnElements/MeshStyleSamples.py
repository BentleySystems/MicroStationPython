# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from math import pi
import os, math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

def createIndexedFaceLoopMeshElement():
    """
    Creates an indexed face loop mesh element in the active DGN model.

    This function performs the following steps:
    1. Retrieves the active DGN model reference and DGN file.
    2. Displays a message indicating whether the DGN model was successfully selected.
    3. Defines a set of 3D points and indices to create the mesh.
    4. Creates an indexed mesh using the defined points and indices.
    5. Applies active settings to the mesh element.
    6. Adds the mesh element to the model and displays a success or error message.

    :raises RuntimeError: If the DGN model is not selected or the mesh element creation fails.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    points = DPoint3dArray()
    points.extend((DPoint3d.From(0, 0, 0),  # Origin
        DPoint3d.From(10, 0, 0),  # X-axis
        DPoint3d.From(0, 10, 0),  # Y-axis
        DPoint3d.From(0, 0, 10),  # Z-axis
        DPoint3d.From(10, 10, 0),  # XY-plane
        DPoint3d.From(10, 0, 10),  # XZ-plane
        DPoint3d.From(0, 10, 10),  # YZ-plane
        DPoint3d.From(10, 10, 10),  # XYZ-space
        DPoint3d.From(5, 5, 5)))  # Center of the cube
    indices = Int32Array()
    indices.extend((6, 3, 1, 0,
                    3, 6, 5, 0,
                    5, 6, 9, 0,
                    9, 6, 8, 0,
                    6, 4, 7, 0,
                    4, 6, 1, 0,
                    8, 6, 7, 0,
                    4, 2, 7, 0,
                    2, 4, 1, 0))
    polyfaceIndexMesh = PolyfaceHeader.CreateIndexedMesh(0, points, indices)
    meshEditElementHandle = EditElementHandle()
    results = MeshHeaderHandler.CreateMeshElement(meshEditElementHandle, None, polyfaceIndexMesh, True, dgnModel)
    ElementPropertyUtils.ApplyActiveSettings(meshEditElementHandle)
    if BentleyStatus.eSUCCESS == results:
        meshEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("The mesh element of style indexed face loop was successfully created.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The mesh element of style indexed face loop was not created.", "", False)

def createQuadGridMesh():
    """
    Creates a quad grid mesh element in the active DGN model.

    This function creates a quad grid mesh with a specified number of edges in the X and Y directions.
    The mesh is created in the active DGN model and added to it if successful.

    :raises RuntimeError: If no active DGN model is selected or if the mesh element creation fails.

    :Example:

    >>> createQuadGridMesh()

    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    numYEdge = 6
    numXEdge = 5
    polyfaceQuadGridMesh = PolyfaceHeader.CreateQuadGrid(numXEdge)
    plane = DPlane3dByVectors.FromOriginAndParallelToXY(DPoint3d.From(0,0,0), 2, 3)
    for j in range(0, numYEdge):
        for i in range(0, numXEdge):
            polyfaceQuadGridMesh.Point().append(plane.Evaluate(i, j))
    meshEditElementHandle = EditElementHandle()
    results = MeshHeaderHandler.CreateMeshElement(meshEditElementHandle, None, polyfaceQuadGridMesh, True, dgnModel)
    ElementPropertyUtils.ApplyActiveSettings(meshEditElementHandle)
    if BentleyStatus.eSUCCESS == results:
        meshEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("The mesh element of style quad grid was successfully created.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The mesh element of style quad grid was not created.", "", False)

def createTriangleGridMesh():
    """
    Creates a triangle grid mesh and adds it to the active DGN model.

    This function creates a triangle grid mesh using the PolyfaceHeader class and adds it to the active DGN model.
    It first checks if a DGN model is selected and displays appropriate messages. Then, it creates a triangle grid mesh
    and evaluates points on a plane to form the mesh. Finally, it adds the mesh element to the model and applies active settings.

    :raises: Displays error messages if no DGN model is selected or if the mesh element creation fails.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    numYEdge = 6
    numXEdge = 3
    polyfaceTriangleMesh = PolyfaceHeader.CreateTriangleGrid(3)
    plane = DPlane3dByVectors.FromOriginAndParallelToXY(DPoint3d.From(0,0,0), 2, 3)
    for j in range(0, numYEdge):
        for i in range(0, numXEdge):
            polyfaceTriangleMesh.Point().append(plane.Evaluate(i, j))
    meshEditElementHandle = EditElementHandle()
    results = MeshHeaderHandler.CreateMeshElement(meshEditElementHandle, None, polyfaceTriangleMesh, True, dgnModel)
    ElementPropertyUtils.ApplyActiveSettings(meshEditElementHandle)
    if BentleyStatus.eSUCCESS == results:
        meshEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("The mesh element of style triangle grid was successfully created.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The mesh element of style triangle grid was not created.", "", False)

def createCoordinateTriangleMesh():
    """
    Creates a coordinate triangle mesh and adds it to the active DGN model.

    This function creates a coordinate triangle mesh using fixed block coordinates and adds it to the active DGN model.
    It first retrieves the active DGN model and file, then creates a polyface triangle mesh with specified dimensions.
    The mesh points are evaluated and appended to the polyface triangle mesh. Finally, the mesh element is created,
    active settings are applied, and the mesh element is added to the model.

    :raises RuntimeError: If no DGN model is selected or if the mesh element creation fails.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if dgnModel is not None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    polyfaceTriangleMesh = PolyfaceHeader.CreateFixedBlockCoordinates(3)
    numYEdge = 6
    numXEdge = 3
    plane = DPlane3dByVectors.FromOriginAndParallelToXY(DPoint3d.From(0, 0, 0), 2, 3)
    for j in range(0, numYEdge):
        for i in range(0, numXEdge):
            xyz00 = plane.Evaluate(i, j)
            xyz10 = plane.Evaluate((i + 1), j)
            xyz11 = plane.Evaluate((i + 1), (j + 1))
            xyz01 = plane.Evaluate(i, (j + 1))
            polyfaceTriangleMesh.Point().append(xyz00)
            polyfaceTriangleMesh.Point().append(xyz10)
            polyfaceTriangleMesh.Point().append(xyz01)
            polyfaceTriangleMesh.Point().append(xyz10)
            polyfaceTriangleMesh.Point().append(xyz11)
            polyfaceTriangleMesh.Point().append(xyz01)
    meshEditElementHandle = EditElementHandle()
    results = MeshHeaderHandler.CreateMeshElement(meshEditElementHandle, None, polyfaceTriangleMesh, True, dgnModel)
    ElementPropertyUtils.ApplyActiveSettings(meshEditElementHandle)
    if BentleyStatus.eSUCCESS == results:
        meshEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("The mesh element of style coordinate triangle was successfully created.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The mesh element of style coordinate triangle was not created.", "", False)

def createCoordinateQuadMesh():
    """
    Creates a coordinate quad mesh in the active DGN model.

    This function creates a quad mesh with fixed block coordinates and adds it to the active DGN model.
    It uses the `PolyfaceHeader` to create the mesh and `MeshHeaderHandler` to handle the mesh element creation.
    The mesh is created on a plane parallel to the XY plane with specified edge counts.

    Steps:
    1. Retrieves the active DGN model and file.
    2. Creates a quad grid mesh with fixed block coordinates.
    3. Evaluates points on the plane and appends them to the mesh.
    4. Creates a mesh element handle and applies active settings.
    5. Adds the mesh element to the model if creation is successful.

    Messages are displayed in the MessageCenter to indicate success or failure.

    :raises RuntimeError: If no active DGN model is selected.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if dgnModel is not None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    polyfaceQuadGridMesh = PolyfaceHeader.CreateFixedBlockCoordinates(4)
    numYEdge = 6
    numXEdge = 3
    plane = DPlane3dByVectors.FromOriginAndParallelToXY(DPoint3d.From(0, 0, 0), 2, 3)
    for j in range(0, numYEdge):
        for i in range(0, numXEdge):
            xyz00 = plane.Evaluate(i, j)
            xyz10 = plane.Evaluate((i + 1), j)
            xyz11 = plane.Evaluate((i + 1), (j + 1))
            xyz01 = plane.Evaluate(i, (j + 1))
            polyfaceQuadGridMesh.Point().append(xyz00)
            polyfaceQuadGridMesh.Point().append(xyz10)
            polyfaceQuadGridMesh.Point().append(xyz11)
            polyfaceQuadGridMesh.Point().append(xyz01)
    meshEditElementHandle = EditElementHandle()
    results = MeshHeaderHandler.CreateMeshElement(meshEditElementHandle, None, polyfaceQuadGridMesh, True, dgnModel)
    ElementPropertyUtils.ApplyActiveSettings(meshEditElementHandle)
    if BentleyStatus.eSUCCESS == results:
        meshEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("The mesh element of style coordinate quad was successfully created.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The mesh element of style coordinate quad was not created.", "", False)

#main
if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/MeshStyleSamples.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))