import math
import os
import sys
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

EPSILON = 0.000000001
PI = 3.1415926535897932384626433
DISTANCE = 10.0
TOLERANCE_ExtrusionSkew = 5.0


def GetAndFillDgnModel(dgnFile, modelId = -1):
    if -1 == modelId:
        modelId = dgnFile.DefaultModelId
    model = dgnFile.LoadRootModelById(modelId)[0]
    dgnFile.FillSectionsInModel(model)
    return model

def validateExpectedMaterial(elemRef, model, materialName, palette, materialModel, levelId, ret):
    
    assert elemRef != None
    
    segment = DSegment3d()
    eeh = EditElementHandle()
    LineHandler.CreateLineElement(eeh, None, segment, ret[0].Is3d(), ret[0])
    eeh.AddToModel()
    m_eh = ElementHandle(eeh.GetElementId(), ret[0])
    eh = ElementHandle(elemRef, ret[0])
    query = IMaterialPropertiesExtension.Cast (eh.GetHandler ())
    colourIndex = 0
    
    assert query != None
    
    # ElementHandle does not return the object of its class. 
    # For the query.FindMaterial we need the object.
    material = query.FindMaterial(eh, levelId, colourIndex, eh.ModelRef, False)
    # assert  materialName.__eq__(material.GetName(NULL))
    # assert material.GetPalette () == (palette, false)
    # assert materialModel == material.GetModelRefR ()

@pytest.mark.parametrize('fileName', ['Attach_081107.dgn'])  
def test_GetMaterialFromAttachment081107 (initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    #ret = loadDgnFile.CreateNewModel ("Attach_081107.dgn", DgnModelType.eNormal, False)
    model = GetAndFillDgnModel(loadDgnFile)
    
    assert model != None

    retVal = loadDgnFile.LoadRootModelById (loadDgnFile.DefaultModelId, True)
    initialElemRef = retVal[0].FindElementByID (612)

    dgnDocument = loadDgnFile.GetDocument()
    dgnMoniker = dgnDocument.GetMoniker()
    paletteInfo = PaletteInfo("External_080904.pal", dgnMoniker, PaletteInfo.ePALETTETYPE_Dgn)

    levelCache = loadDgnFile.GetLevelCache()
    level = levelCache.GetLevel(LEVEL_DEFAULT_LEVEL_ID)
    levelId = level.GetLevelId()

    validateExpectedMaterial(initialElemRef, model, "Material2", paletteInfo, model, levelId, retVal)

@pytest.mark.parametrize('fileName', ['Attach_080904.dgn'])  
def test_GetMaterialFromAttachment080904 (initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    ret = loadDgnFile.CreateNewModel ("Attach_080904.dgn", DgnModelType.eNormal, False)
    model = GetAndFillDgnModel(loadDgnFile, ret[0].ModelId)
    
    assert model != None

    dgnCache, retVal = loadDgnFile.LoadRootModelById (loadDgnFile.DefaultModelId, True)
    initialElemRef = dgnCache.FindElementByID (188)

    dgnDocument = loadDgnFile.GetDocument()
    dgnMoniker = dgnDocument.GetMoniker()
    paletteInfo = PaletteInfo("External_080904.pal", dgnMoniker, PaletteInfo.ePALETTETYPE_Dgn)

    levelCache = loadDgnFile.GetLevelCache()
    level = levelCache.GetLevel(LEVEL_DEFAULT_LEVEL_ID)
    levelId = level.GetLevelId()

    validateExpectedMaterial(initialElemRef, model, "External2", paletteInfo, model, levelId, ret)
    if 'PSEUDOLOCALIZE' in vars() or 'PSEUDOLOCALIZE' in globals():
        initialElemRef = dgnCache.FindElementByID (195)
        validateExpectedMaterial(initialElemRef, model, "External1", paletteInfo, model, levelId, ret)