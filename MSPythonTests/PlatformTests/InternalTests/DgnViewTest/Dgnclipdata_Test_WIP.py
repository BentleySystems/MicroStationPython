import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyGeomTest import *

# not tested
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DgnECFormat(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
       assert False
    
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnModel = loadDgnFile.FillSectionsInModel(ret[0])
    
    assert True == (dgnModel != None)
    
    points = DPoint3d()
    points = DPoint3dArray([DPoint3d(0, 0, 0), DPoint3d(0, 10000, 0), DPoint3d(10000, 10000, 0), DPoint3d(10000, 0, 0)])
    
    lineStringEeh = EditElementHandle()

    status = LineStringHandler.CreateLineStringElement(lineStringEeh, None, points, False, ret[0])
    if(status != BentleyStatus.eSUCCESS):
        assert False

    assert BentleyStatus.eSUCCESS == lineStringEeh.AddToModel()

    file = ret[0].GetDgnFile()
    scope = FindInstancesScope.CreateScope(file, FindInstancesScopeOption (DgnECHostType.All, True))
    # assert True == scope.IsValid()

    query = ECQuery.CreateQuery("BaseElementSchema", "MstnGraphHeader", True)
    mgr = DgnECManager.GetManager()
    iterable = mgr.FindInstances(scope, query)

    oldCount = -1
    for it in iterable:
        oldCount = oldCount + 1

    assert 1 == oldCount

    context = DgnClipBoardContext.CreateExternalFileContext(ret[0], DgnClipBoardContext.CopyPaste)
    # assert context.IsValid()

    cc = None
    assert BentleyStatus.eSUCCESS == context.GetCopyContext(cc)
    assert BentleyStatus.eSUCCESS == cc.DoCopy(lineStringEeh)
    assert BentleyStatus.eSUCCESS == context.SaveDgn(cc)
    clipStringDataNode = None
    assert BentleyStatus.eSUCCESS == context.GetClipBoardStringDataNode (clipStringDataNode, query)
    
    if clipStringDataNode.empty():
        assert False
    else:
        assert True

    clipDataNodes1 = None
    clipDataNodes1.push_back (clipStringDataNode)

    clipString = None
    assert BentleyStatus.eSUCCESS == context.PrepareClipBoardStringWithDataNodes (clipString, clipDataNodes1, 0)
    assert BentleyStatus.eSUCCESS == DgnClipBoardContext.CopyElementsToModel(ret[0], clipString)

    count = -1
    iterable = mgr.FindInstances(scope, query)
    instanceId = None
    for it in iterable:
        if (0 == count):
            instanceId = iter.GetInstanceId()
        count = count + 1

    assert 2 == count

    wh = WhereCriterion.CreateComparison (WhereExpression.CreateECInstanceIdExpression(), WhereCriterion.eEQ, WhereExpression.CreateConstant (ECN.ECValue(instanceId)))

    query.SetWhereCriterion(wh)

    context = DgnClipBoardContext.CreateContext(file, DgnClipBoardContext.CopyPaste)
    # assert context.IsValid()
    assert BentleyStatus.eSUCCESS == context.GetClipBoardStringDataNode(clipString, query)

    clipDataNodes2 = None
    clipDataNodes2.push_back (clipStringDataNode)

    assert BentleyStatus.eSUCCESS == context.PrepareClipBoardStringWithDataNodes (clipString, clipDataNodes2, 0)

    infos = None
    windowId = -1
    assert BentleyStatus.eSUCCESS == DgnClipBoardContext.GetClipInfos(infos, windowId, clipString)