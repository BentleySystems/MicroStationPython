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

BentleyStatus.eSUCCESS = 0

class ElementPropertyQuery(IQueryProperties):
   
    m_colors = []
    m_mLineStyle = []
    m_weights=[]

    # int m_colorPosition;
    # int m_mLineStylePosition;
    # int m_weightsPosition;
    def _EachColorCallback(self,argu):
        self.m_colors.append(argu.GetStoredValue())

    def GetColors(self):
        return self.m_colors
    def GetMLineStyleID(self):
        return self.m_mLineStyle[0]
   



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetModelInfo_FixAzimuth(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    cache = dgnFile.CreateNewModel ("Model", DgnModelType.eNormal, True)
    eeh = EditElementHandle()
    points = DPoint3dArray()
    points.append(DPoint3d(0.0,0.0,0.0))
    points.append(DPoint3d(1000.0,1000.0,1000.0))
    normal = DVec3d(0.0,0.0,1.0)

    mlineStyle = MultilineStyle.GetSettings (dgnFile)
    MultilineHandler.CreateMultilineElement(eeh,None, mlineStyle, 1.0, normal, points, True, cache[0])
    eeh.AddToModel() 

    mlstyle = MultilineStyle.Create("TestStyle", dgnFile)

    styleprofA = MultilineProfile()
    styleprofB = MultilineProfile()
    styleprofC = MultilineProfile()

    styleprofA.SetLinestyle(0)
    styleprofA.SetWeight(1)
    styleprofA.SetColor(100)
    styleprofA.SetUsesLinestyle(True)
    styleprofA.SetUseWeight(True)
    styleprofA.SetUseColor(True)
    styleprofA.SetDistance(1)
    styleprofA.ScaleDistance(10)


    styleprofB.SetLinestyle(1)
    styleprofB.SetWeight(3)
    styleprofB.SetColor(200)
    styleprofA.SetUsesLinestyle(True)
    styleprofB.SetUseWeight(True)
    styleprofB.SetUseColor(True)
    styleprofB.SetDistance(2)
    styleprofB.ScaleDistance(50)
    

    styleprofC.SetLinestyle(2)
    styleprofC.SetWeight(6)
    styleprofC.SetColor(50)
    styleprofA.SetUsesLinestyle(True)
    styleprofC.SetUseWeight(True)
    styleprofC.SetUseColor(True)
    styleprofC.SetDistance(3)
    styleprofC.ScaleDistance(30)

    assert BentleyStatus.eSUCCESS == mlstyle.InsertProfile(styleprofA, int(1))
    assert BentleyStatus.eSUCCESS == mlstyle.InsertProfile(styleprofB, int(1))
    assert BentleyStatus.eSUCCESS == mlstyle.InsertProfile(styleprofC, int(1))

    assert BentleyStatus.eSUCCESS ==  mlstyle.Add(dgnFile)
    
    eid = mlstyle.GetID()
    
    

    epq= ElementPropertyQuery()
    # #PropertyContext.EditElementProperties(eeh,IEditProperties())
    PropertyContext.QueryElementProperties(eeh,epq)

    # colors = epq.GetColors()
    # print(colors)
    # assert False
     