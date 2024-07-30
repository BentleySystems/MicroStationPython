#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import math
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_eeh = EditElementHandle()
'''Allocate mselementdesce and adding this in list'''
def AllocateNDescriptors (n, ret):
    outDescr = []
    for i in range(n):
        buffer = f"test{i}"
        NormalCellHeaderHandler.CreateOrphanCellElement (m_eeh, buffer, False, ret[0])
        descr = MSElementDescr.Allocate(m_eeh.GetElement(), ret[0])
        outDescr.append (descr)
    return outDescr


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AllocateSimple(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    segment = DSegment3d (-1000.0, 0.0, 0.0, 1000.0, 0.0, 0.0)
    assert LineHandler.CreateLineElement (m_eeh, None, segment, False, ret[0]) == BentleyStatus.eSUCCESS
    descr = MSElementDescr.Allocate(m_eeh.GetElement(), ret[0])
    assert descr.h.next == None
    assert descr.h.previous == None
    assert descr.h.firstElem == None
    # this is not a complex header, so descr's myHeader should point to NULL, not back to descr
    assert descr.h.myHeader == None


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AllocateComplex(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NormalCellHeaderHandler.CreateOrphanCellElement (m_eeh, "test", False, ret[0])
    descr = MSElementDescr.Allocate(m_eeh.GetElement(), ret[0])
    assert descr.h.next == None
    assert descr.h.previous == None
    assert descr.h.firstElem == None
    # now we have a complex header, so the descr's myHeader should point to descr
    assert descr.h.myHeader == descr


 # DescrValidator is not exposed

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendChildToParent(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (2, ret)
    # validator = DescrValidator(descrs[0])
    descrs[0].AppendDescr(descrs[1])
    # validator.ValidateAppendDescr(descrs[0], descrs[0], descrs[1])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendSecondChild(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (3, ret)
    descrs[0].AppendDescr(descrs[1])
    # validator = DescrValidator(descrs[0])
    descrs[0].AppendDescr(descrs[2])
    # validator.ValidateAppendDescr(descrs[0], descrs[0], descrs[2])
	

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendThirdChild(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (4, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[0].AppendDescr(descrs[2])
    # validator = DescrValidator(descrs[0])
    descrs[0].AppendDescr(descrs[3])
    # validator.ValidateAppendDescr(descrs[0], descrs[0], descrs[3])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendChildtoChild(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (3, ret)
    descrs[0].AppendDescr(descrs[1])
    # validator = DescrValidator(descrs[0])
    descrs[1].AppendDescr(descrs[2])
    # validator.ValidateAppendDescr(descrs[0], descrs[1], descrs[2])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendSecondChildtoChild(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (4, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[1].AppendDescr(descrs[2])
    # validator = DescrValidator(descrs[0])
    descrs[1].AppendDescr(descrs[3])
    # validator.ValidateAppendDescr(descrs[0], descrs[1], descrs[3])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendThirdChildtoChild(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (5, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[1].AppendDescr(descrs[2])
    descrs[1].AppendDescr(descrs[3])
    # validator = DescrValidator(descrs[0])
    descrs[1].AppendDescr(descrs[4])
    # validator.ValidateAppendDescr(descrs[0], descrs[1], descrs[4])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendSecondChildFirstHasThreeGrandChildren(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (6, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[1].AppendDescr(descrs[2])
    descrs[1].AppendDescr(descrs[3])
    descrs[1].AppendDescr(descrs[4])
    # validator = DescrValidator(descrs[0])
    descrs[0].AppendDescr(descrs[5])
    # validator.ValidateAppendDescr(descrs[0], descrs[0], descrs[5])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendChildWithThreeChildren(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (6, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[2].AppendDescr(descrs[3])
    descrs[2].AppendDescr(descrs[4])
    descrs[2].AppendDescr(descrs[5])
    # validator = DescrValidator(descrs[0])
    descrs[0].AppendDescr(descrs[2])
    # validator.ValidateAppendDescr(descrs[0], descrs[0], descrs[2])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendThirdChildMiddleHasThreeGrandChildren(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (7, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[2].AppendDescr(descrs[3])
    descrs[2].AppendDescr(descrs[4])
    descrs[2].AppendDescr(descrs[5])
    descrs[0].AppendDescr(descrs[2])
    # validator = DescrValidator(descr[0])
    descrs[0].AppendDescr(descrs[6])
    # validator.ValidateAppendDescr(descrs[0], descrs[0], descrs[6])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AppendThreeChildrenEachHasThreeGrandChildren(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (13, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[1].AppendDescr(descrs[2])
    descrs[1].AppendDescr(descrs[3])
    descrs[1].AppendDescr(descrs[4])
    descrs[0].AppendDescr(descrs[5])
    # test appending a third child to a parent with two children, the second of which has three grandchildren
    descrs[5].AppendDescr(descrs[6])
    descrs[5].AppendDescr(descrs[7]) 
    descrs[0].AppendDescr(descrs[8])
    descrs[8].AppendDescr(descrs[9]) 
    descrs[8].AppendDescr(descrs[10])
    descrs[8].AppendDescr(descrs[11])
    # validator = DescrValidator(descr[0])
    descrs[5].AppendDescr(descrs[12])
    # validator.ValidateAppendDescr(descrs[0], descrs[5], descrs[12])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TwoDescrsReplaceParentDescr(initDgnPlatformHost, loadDgnFile):
    # ScopedDgnHost autoDgnHost
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = ret[0]
    parentEeh = EditElementHandle()
    NormalCellHeaderHandler.CreateOrphanCellElement (parentEeh, "parent", False, model)
    parent = MSElementDescr.Allocate(parentEeh.GetElement(), model)
    childEeh = EditElementHandle()
    NormalCellHeaderHandler.CreateOrphanCellElement (childEeh, "child", False, model)
    child = MSElementDescr.Allocate(childEeh.GetElement(), model)
    parent.AppendDescr(child)
    # validator = DescrValidator(parent)
    replacementEeh = EditElementHandle()
    NormalCellHeaderHandler.CreateOrphanCellElement (replacementEeh, "replacement", False, model)
    replacement = MSElementDescr.Allocate(replacementEeh.GetElement(), model)
    parent.ReplaceDescr(replacement)
    # validator.ValidateReplaceDescr(replacement, parent, replacement)
    


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TwoDescrsReplaceChildDescr(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (3, ret)
    descrs[0].AppendDescr(descrs[1])
    # validator = DescrValidator(descrs[0])
    descrs[1].ReplaceDescr(descrs[2])
    # validator.ValidateReplaceDescr(descrs[0], descrs[1], descrs[2])
    assert descrs[0].h.next == None
    assert descrs[0].h.previous == None
    assert descrs[0].h.firstElem != descrs[1]
    assert descrs[0].h.firstElem == descrs[2]
    assert descrs[0].h.myHeader == descrs[0]
    assert descrs[2].h.next == None
    assert descrs[2].h.previous == descrs[0]
    assert descrs[2].h.myHeader == descrs[0]


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TwoDescrsReplacementHasChildren(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (7, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[0].AppendDescr(descrs[2])
    descrs[3].AppendDescr(descrs[4])
    descrs[3].AppendDescr(descrs[5])
    descrs[3].AppendDescr(descrs[6])
    # validator = DescrValidator(descrs[0])
    descrs[2].ReplaceDescr(descrs[3])
    # validator.ValidateReplaceDescr(descrs[0], descrs[2], descrs[3])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ReplaceElement(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (2, ret)
    NormalCellHeaderHandler.CreateOrphanCellElement (m_eeh, "test", False, ret[0])
    descrs[0].AppendDescr(descrs[1])
    descrWithm_replacement = descrs[1].ReplaceElement((m_eeh.GetElement()))
    assert descrs[0].h.firstElem == descrWithm_replacement
    assert descrs[0].h.firstElem.el.ehdr.type == 2
    assert descrWithm_replacement.el.ehdr.type == 2


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ClearElementIds(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (13, ret)
    descrs[0].AppendDescr(descrs[1])
    descrs[1].AppendDescr(descrs[2])
    descrs[1].AppendDescr(descrs[3])
    descrs[1].AppendDescr(descrs[4])
    descrs[0].AppendDescr(descrs[5])
    # test appending a third child to a parent with two children, the second of which has three grandchildren
    descrs[5].AppendDescr(descrs[6])
    descrs[5].AppendDescr(descrs[7])
    descrs[0].AppendDescr(descrs[8])
    descrs[8].AppendDescr(descrs[9])
    descrs[8].AppendDescr(descrs[10]) 
    descrs[8].AppendDescr(descrs[11])
    descrs[5].AppendDescr(descrs[12])
    # validator = DescrValidator(descrs[0])
    descrs[0].ClearElementIds()
    # validator.ConfirmElementIDsCleared(descrs[0])



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateAChain(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (2, ret)
    # validator = DescrValidator(descrs[0])
    descrs[0].AddToChain(descrs[1])
    # validator.ValidateAddToChain(descrs[0], descrs[0], descrs[1])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AddToChain(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (3, ret)
    descrs[0].AddToChain(descrs[1])
    # validator = DescrValidator(descrs[0])
    descrs[1].AddToChain(descrs[2])
    # validator.ValidateAddToChain(descrs[0], descrs[1], descrs[2])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_InitOrAddToChainWithTailStartChain(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    descrs = AllocateNDescriptors (1, ret)
    pHead = None
    pTail = None
    MSElementDescr.InitOrAddToChainWithTail(pHead, pTail, descrs[0])
    # assert descrs[0] == pHead     # descrs[0] is not None
    # assert descrs[0] == pTail