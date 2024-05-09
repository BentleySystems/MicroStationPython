import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

def IsEqual(ellipse0, ellipse1, tolerance = 1.0e-12):
    return (ellipse0.center.IsEqual (ellipse1.center, tolerance) and
            ellipse0.vector0.IsEqual (ellipse1.vector0, tolerance) and
            ellipse0.vector90.IsEqual (ellipse1.vector90, tolerance) and
            (abs(ellipse0.start - ellipse1.start) < tolerance) and
            (abs(ellipse0.sweep - ellipse1.sweep) < tolerance))

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateEllipseElement(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    ellipse = DEllipse3d.FromCenterNormalRadius(DPoint3d.From (0.0, 0.0, 0.0), DVec3d(0.0, 0.0, 1.0), 1.0)
    eeh = EditElementHandle()
    
    assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement(eeh, None, ellipse, ret[0].Is3d(), ret[0])
    
    pathCurve = ICurvePathQuery.ElementToCurveVector(eeh)
    
    validPathCurve = ( pathCurve != 0 )
    assert validPathCurve and ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Arc == pathCurve.HasSingleCurvePrimitive()
    pathCurve0 = list(pathCurve)
    assert IsEqual(ellipse, pathCurve0[0].GetArc())
    
    assert BentleyStatus.eSUCCESS == eeh.AddToModel()