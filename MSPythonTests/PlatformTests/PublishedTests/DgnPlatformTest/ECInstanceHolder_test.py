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


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Create(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
        assert False
        
    eeh = EditElementHandle()
    
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    
    assert BentleyStatus.eSUCCESS == ECInstanceHolderHandler.CreateECInstanceHolderElement(eeh, ret[0])[1]
    
    eeh.AddToModel()
    
    # verify the element has our handler attached
    ecih = eeh.GetHandler()
    
    if None == ecih:
        assert False
    
    
    