#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_eeh = EditElementHandle()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_IBsplineSurfaceEdit(initDgnPlatformHost,loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    #SETUP: Create a upward paraboloid-shaped BsplineSurface with a square base and pass to m_eeh
    points = DPoint3dArray()
    points.append(DPoint3d(1000.0, 3000.0, 500.0))
    points.append(DPoint3d(2000.0, 3000.0, 0.0))
    points.append(DPoint3d(3000.0, 3000.0, 500.0))
    points.append(DPoint3d(1000.0, 2000.0, 0.0))
    points.append(DPoint3d(2000.0, 2000.0, -5000.0))
    points.append(DPoint3d(3000.0, 2000.0, 0.0))
    points.append(DPoint3d(1000.0, 1000.0, 500.0))
    points.append(DPoint3d(2000.0, 1000.0, 0.0))
    points.append(DPoint3d(3000.0, 1000.0, 500.0))

    surfPoints = DPoint3dArray()

    for i in range(0,len(points)):
        surfPoints.append(points[i])

    surface = MSBsplineSurface()
    surface.Populate(surfPoints, None, None, 3, 3, False, None, 3, 3, False, False)

    assert 0 == BSplineSurfaceHandler.CreateBSplineSurfaceElement(m_eeh, None, surface, ret[0])

    #EDIT: Flip the original surface so that it is opening downward and elongate it to extend to z=10000.0
    editPoints = DPoint3dArray()
    editPoints.append(DPoint3d(1000.0, 3000.0, -500.0))
    editPoints.append(DPoint3d(2000.0, 3000.0, 0.0))
    editPoints.append(DPoint3d(3000.0, 3000.0, -500.0))
    editPoints.append(DPoint3d(1000.0, 2000.0, 0.0))
    editPoints.append(DPoint3d(2000.0, 2000.0, 10000.0))
    editPoints.append(DPoint3d(3000.0, 2000.0, 0.0))
    editPoints.append(DPoint3d(1000.0, 1000.0, -500.0))
    editPoints.append(DPoint3d(2000.0, 1000.0, 0.0))
    editPoints.append(DPoint3d(3000.0, 1000.0, -500.0))

    editSurfPoints = DPoint3dArray()

    for i in range(0,len(editPoints)):
        editSurfPoints.append(editPoints[i])

    editSurface = MSBsplineSurface()
    editSurface.Populate(editSurfPoints, None, None, 3, 3, False, None, 3, 3, False, False)

    editor = m_eeh.GetHandler()
    editor.SetBsplineSurface(m_eeh, editSurface)

    #CHECK: Make sure the changes specified in the editor carried over by cross-checking the poles
    retVal, checkSurface = editor.GetBsplineSurface(m_eeh)

    editPoles = DPoint3dArray()
    checkPoles = DPoint3dArray()
    editSurface.GetPoles(editPoles)
    checkSurface.GetPoles(checkPoles)
    for i in range(len(editPoints)):
        assert checkPoles[i].x == editPoles[i].x
        assert checkPoles[i].y == editPoles[i].y
        assert checkPoles[i].z == editPoles[i].z

    surface.ReleaseMem()
    editSurface.ReleaseMem()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  #Not fully completed as it gives crash and also multiple methods are not exposed
def test_IMeshEdit(initDgnPlatformHost,loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    #SETUP: Create a basic square mesh and pass to m_eeh
    header = PolyfaceHeader.CreateVariableSizeIndexed ()
    header.SetMeshStyle (1)
    header.SetTwoSided (False)
    header.SetNumPerFace (0)

    points = DPoint3dArray()
    points.append(DPoint3d(1000.0, 1000.0, 0.0))
    points.append(DPoint3d(2000.0, 1000.0, 0.0))
    points.append(DPoint3d(2000.0, 2000.0, 0.0))
    points.append(DPoint3d(1000.0, 2000.0, 0.0))

    indices = [1, 2, 3, 4]
    header.Point().Active = True
    header.PointIndex().Active = True

    for i in range(0,len(indices)):
          header.PointIndex().append(indices[i])

    for i in range(0,len(points)):
          header.Point().append(points[i])
    assert 0 == MeshHeaderHandler.CreateMeshElement(m_eeh, None , header, False, ret[0])

    #EDIT: Use IMeshEdit to transform the basic square mesh into a much more complex one.
    editHeader = PolyfaceHeader.CreateVariableSizeIndexed ()
    editHeader.SetMeshStyle (1)
    editHeader.SetTwoSided (False)
    editHeader.SetNumPerFace (0)

    editPoints = DPoint3dArray()
    editPoints.append(DPoint3d(1000.0, 3000.0, 500.0))
    editPoints.append(DPoint3d(2000.0, 3000.0, 0.0))
    editPoints.append(DPoint3d(3000.0, 3000.0, 500.0))
    editPoints.append(DPoint3d(1000.0, 2000.0, 0.0))
    editPoints.append(DPoint3d(2000.0, 2000.0, -5000.0))
    editPoints.append(DPoint3d(3000.0, 2000.0, 0.0))
    editPoints.append(DPoint3d(1000.0, 1000.0, 500.0))
    editPoints.append(DPoint3d(2000.0, 1000.0, 0.0))
    editPoints.append(DPoint3d(3000.0, 1000.0, 500.0))

    editIndices = [0, 1, 2, 3, 4, 5, 6, 7]
    editHeader.Point().Active = True
    editHeader.PointIndex().Active = True

    for i in range(0,len(editIndices)):
          editHeader.PointIndex().append(editIndices[i])

    for i in range(0,len(editPoints)):
          editHeader.Point().append(editPoints[i])

    editor = m_eeh.GetHandler()
    editor.SetMeshData(m_eeh, editHeader)

    #CHECK: Cross-check the edit and check PolyfaceHeaders to make sure that the edit was carried out properly.
    checkHeader = PolyfaceHeader.CreateVariableSizeIndexed()
    retVal, checkHeader = editor.GetMeshData(m_eeh)

    for i in range(len(checkHeader.Point())):
          assert checkHeader.Point()[i].x == editHeader.Point()[i].x
          assert checkHeader.Point()[i].y == editHeader.Point()[i].y
          assert checkHeader.Point()[i].z == editHeader.Point()[i].z
    for i in range(len(checkHeader.PointIndex())):
          assert checkHeader.PointIndex()[i] == editHeader.PointIndex()[i]
