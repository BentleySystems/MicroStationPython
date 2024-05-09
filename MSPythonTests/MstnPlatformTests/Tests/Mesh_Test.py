import os
import pytest
import shutil
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import debugpy

# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    if not origin:
        return origin
    origin += fileLocation
    return origin

''' Get a DgnDocument from a filename and directory       '''    
def getFileFromDirectory(fileName, fileDir):
    ret = DgnDocument.CreateFromFileName (fileName, fileDir, -101, DgnDocument.FetchMode.eRead)
    return ret

class MyModalEventHandler(IPyModalDialogEvents):

    ''' Callback when a modal Microstation dialog is opened ''' 
    def OnDialogOpened (self, dialogBoxName):
        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK
        
    ''' Callback when a modal Microstation dialog is closed ''' 
    def OnDialogClosed (self, dialogBoxName, result):
        pass

class MeshCubeFromCenterAndSize ():
    def __init__ (self, center, sizePt):
        self.center = center
        self.sizePt = sizePt
        self.options = IFacetOptions ()

    def Mesh (self):
        box = ISolidPrimitive.CreateDgnBox (DgnBoxDetail.InitFromCenterAndSize (self.center, self.sizePt, True))
        meshBuilder = IPolyfaceConstruction (self.options)
        meshBuilder.AddSolidPrimitive (box)
        return meshBuilder.GetClientMesh()

class MeshSphereFromCenterAndRadius ():
    def __init__ (self, center, radius):
        self.center = center
        self.radius = radius
        self.options = IFacetOptions ()

    def Mesh (self):
        sphere = ISolidPrimitive.CreateDgnSphere (DgnSphereDetail (self.center, self.radius))
        meshBuilder = IPolyfaceConstruction (self.options)
        meshBuilder.AddSolidPrimitive (sphere)
        return meshBuilder.GetClientMesh()

        
def test_subdivideSmoothly ():
    center  = DPoint3d (0,0,0)
    size    = DPoint3d (100,100,100)
    cube    = MeshCubeFromCenterAndSize (center, size).Mesh ()
    ret     = Mesh.SubdivideSmoothly (cube, 1, ISessionMgr.ActiveDgnModelRef)

    assert (ret[0] == True)
    assert (ret[1].GetPointCount () > cube.GetPointCount ())

    eeh = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eeh, None, ret[1], True, ISessionMgr.ActiveDgnModelRef)
    eeh.AddToModel ()

    segment = DSegment3d ()
    assert (PolyfaceHeader.SearchClosestApproach (cube, ret[1], 0, segment))
    assert (segment.Length () > 2)    


def test_subdivideKeepSharp ():
    center  = DPoint3d (0,0,0)
    size    = DPoint3d (100,100,100)
    cube    = MeshCubeFromCenterAndSize (center, size).Mesh ()
    ret     = Mesh.SubdivideKeepSharp (cube, 1, ISessionMgr.ActiveDgnModelRef)

    assert (ret[0] == True)
    assert (ret[1].GetPointCount () > cube.GetPointCount ())

    eeh = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eeh, None, ret[1], True, ISessionMgr.ActiveDgnModelRef)
    eeh.AddToModel ()

    segment = DSegment3d ()
    assert (PolyfaceQuery.SearchClosestApproach (cube, ret[1], 0, segment))
    assert (segment.Length () < 1.0e-7)    

def test_subdivideSmoothly2 ():
    center  = DPoint3d (0,0,0)
    size    = DPoint3d (100,100,100)
    cube    = MeshCubeFromCenterAndSize (center, size).Mesh ()
    ret     = Mesh.SubdivideSmoothly (cube, 2, ISessionMgr.ActiveDgnModelRef)

    assert (ret[0] == True)
    assert (ret[1].GetPointCount () > cube.GetPointCount ())

    eeh = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eeh, None, ret[1], True, ISessionMgr.ActiveDgnModelRef)
    eeh.AddToModel ()

    segment = DSegment3d ()
    assert (PolyfaceQuery.SearchClosestApproach (cube, ret[1], 0, segment))
    assert (segment.Length () > 2)    

def test_subdivideKeepSharp2 ():
    center  = DPoint3d (0,0,0)
    size    = DPoint3d (100,100,100)
    cube    = MeshCubeFromCenterAndSize (center, size).Mesh ()
    ret     = Mesh.SubdivideKeepSharp (cube, 2, ISessionMgr.ActiveDgnModelRef)

    assert (ret[0] == True)
    assert (ret[1].GetPointCount () > cube.GetPointCount ())

    eeh = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eeh, None, ret[1], True, ISessionMgr.ActiveDgnModelRef)
    eeh.AddToModel ()

    segment = DSegment3d ()
    assert (PolyfaceQuery.SearchClosestApproach (cube, ret[1], 0, segment))
    assert (segment.Length () < 1.0e-7)    

def test_healHolesEmpty ():
    invalid = PolyfaceHeader.CreateVariableSizeIndexed ()
    ret = Mesh.Healholes (invalid)
    assert (False == ret[0])    


def getAllPolyfacesOfActiveModel ():
    graphicalElements = ISessionMgr.ActiveDgnModelRef.GetDgnModel ().GetGraphicElements()
    vector = list ()

    for ref in graphicalElements :
        eh = ElementHandle (ref, ISessionMgr.ActiveDgnModelRef)
        meshQuery = eh.GetIMeshQuery ()

        if (None != meshQuery):
            ret = meshQuery.GetMeshData (eh)
            if (BentleyStatus.eSUCCESS == ret[0]):
                vector.append (ret[1])
    return vector


def test_healHoles ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    newFile = emptyDir + WString ("\\TerrainVolumeWithHoles.dgn")
    shutil.copyfile (str (doc.GetFileName ()), str (newFile))

    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    vector = getAllPolyfacesOfActiveModel ()

    ret = Mesh.Healholes (vector[0])
    assert (ret[0])
    assert (ret[1].ValidatedVolume ().IsValid ())

def test_boolEmpty ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\BoolEmpty.dgn")
    shutil.copyfile (str (doc.GetFileName ()), str (newFile))

    doc, status = getFileFromDirectory ('BoolEmpty.dgn', str (emptyDir))
    
    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    invalid = PolyfaceHeader.CreateVariableSizeIndexed ()

    ret = Mesh.BooleanUnion (invalid, invalid, ISessionMgr.ActiveDgnModelRef)
    assert (ret[0] == False)
    ret1 = Mesh.BooleanIntersection (invalid, invalid, ISessionMgr.ActiveDgnModelRef)
    assert (ret1[0] == False)
    ret1 = Mesh.BooleanDifference (invalid, invalid, ISessionMgr.ActiveDgnModelRef)
    assert (ret1[0] == False)

def test_boolUnion ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\BoolUnion.dgn")
    shutil.copyfile (str (doc.GetFileName ()), str (newFile))

    doc, status = getFileFromDirectory ('BoolUnion.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
    center          = DPoint3d (500, 500, 500)
    size            = DPoint3d (1000,1000,1000)
    cube            = MeshCubeFromCenterAndSize (center, size).Mesh ()
    sphereCenter    = DPoint3d (0, 0, 0)
    sphere          = MeshSphereFromCenterAndRadius (sphereCenter, 500).Mesh ()

    eehC = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eehC, None, cube, True, ISessionMgr.ActiveDgnModelRef)
    eehC.AddToModel ()

    eehS = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eehS, None, sphere, True, ISessionMgr.ActiveDgnModelRef)
    eehS.AddToModel ()

    ret = Mesh.BooleanUnion (cube, sphere, ISessionMgr.ActiveDgnModelRef)
    assert (ret[0] == True)
    assert (cube.PointRange ().IsContained (ret[1].PointRange ()))
    assert (sphere.PointRange ().IsContained (ret[1].PointRange ()))

def test_boolIntersection ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\BoolIntersection.dgn")
    shutil.copyfile (str (doc.GetFileName ()), str (newFile))

    doc, status = getFileFromDirectory ('BoolIntersection.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
    center          = DPoint3d (500, 500, 500)
    size            = DPoint3d (1000,1000,1000)
    cube            = MeshCubeFromCenterAndSize (center, size).Mesh ()
    sphereCenter    = DPoint3d (0, 0, 0)
    sphere          = MeshSphereFromCenterAndRadius (sphereCenter, 500).Mesh ()

    eehC = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eehC, None, cube, True, ISessionMgr.ActiveDgnModelRef)
    eehC.AddToModel ()

    eehS = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eehS, None, sphere, True, ISessionMgr.ActiveDgnModelRef)
    eehS.AddToModel ()

    ret = Mesh.BooleanIntersection (cube, sphere, ISessionMgr.ActiveDgnModelRef)
    assert (ret[0] == True)
    assert (ret[1].PointRange ().IsContained (cube.PointRange ()))
    assert (ret[1].PointRange ().IsContained (sphere.PointRange ()))


def test_boolDifference ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\BoolDifference.dgn")
    shutil.copyfile (str (doc.GetFileName ()), str (newFile))

    doc, status = getFileFromDirectory ('BoolDifference.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
    center          = DPoint3d (500, 500, 500)
    size            = DPoint3d (1000,1000,1000)
    cube            = MeshCubeFromCenterAndSize (center, size).Mesh ()
    sphereCenter    = DPoint3d (0, 0, 0)
    sphere          = MeshSphereFromCenterAndRadius (sphereCenter, 500).Mesh ()

    eehC = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eehC, None, cube, True, ISessionMgr.ActiveDgnModelRef)
    eehC.AddToModel ()

    eehS = EditElementHandle ()
    MeshHeaderHandler.CreateMeshElement (eehS, None, sphere, True, ISessionMgr.ActiveDgnModelRef)
    eehS.AddToModel ()

    ret = Mesh.BooleanDifference (sphere, cube, ISessionMgr.ActiveDgnModelRef)
    assert (ret[0] == True)
    assert (False == ret[1].PointRange ().IsContained (cube.PointRange ()))
    assert (ret[1].PointRange ().IsContained (sphere.PointRange ()))

#if __name__ == "__main__":
#    debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
#    print("Waiting for debugger attach")
#    debugpy.wait_for_client()
#    debugpy.breakpoint()
#    test_subdivideSmoothly ()
#    test_subdivideKeepSharp ()
#    test_subdivideSmoothly2 ()
#    test_subdivideKeepSharp2 ()
#    test_healHolesEmpty ()
#    test_healHoles ()
#    test_boolEmpty ()
#    test_boolUnion ()
#    test_boolIntersection ()
#    test_boolDifference ()