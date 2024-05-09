import os
import pytest
import math
import sys
import numpy as np
from numpy import arange
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from collections import defaultdict
import ctypes

m_linkTree = None
StatusInt = ctypes.c_int

''' For getting Dng link tree'''
def GetLinkTree (loadDgnFile):
    dgnDocument = loadDgnFile.GetDocument()
    dgnMoniker = dgnDocument.GetMoniker()
    linkTreeSpec = DgnLinkManager.CreateTreeSpec ("Linkset", dgnMoniker, DgnLinkTreeKey.Project)
    m_linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, True)
    assert m_linkTree != None
    return m_linkTree

# Test for drowing region link
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])     #(Not completed)
def test_CreateDrawingRegionLink(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnFile = loadDgnFile
    dgnDocument = dgnFile.GetDocument ()
    dgnMoniker  = dgnDocument.GetMoniker ()
    linkTreeSpec = DgnLinkManager.CreateTreeSpec ("Linkset", dgnMoniker, DgnLinkTreeKey.Project)
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, True)
    root = linkTree.GetRoot ()
    status = StatusInt()
    # leaf = DgnLinkManager.CreateLink (DGNLINK_TYPEKEY_Drawing)             # Unable to convert call argument '0' to Python object

# Test for finding child node
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindChildNode(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    linkTree = GetLinkTree (loadDgnFile)
    root = linkTree.GetRoot ()
    node = root.FindChildNode ("FileNodeOnRootBranch", False)
    # assert node != None

# Test for creating link tree
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateProjectTree(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnDocument = loadDgnFile.GetDocument()
    dgnMoniker = dgnDocument.GetMoniker()
    linkTreeSpec = DgnLinkManager.CreateTreeSpec ("Linkset", dgnMoniker, DgnLinkTreeKey.Project)
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, True)
    assert linkTree != None
    DgnLinkManager.WriteLinkTree (linkTree)
    ITxnManager.GetManager().CloseCurrentTxn (True)
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree != None
    ITxnManager.GetManager().ReverseTxns (1, False)
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree != None
    ITxnManager.GetManager().ReinstateTxn ()
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree != None

# Test for deleting link tree
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DeleteProjectTree(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnDocument = loadDgnFile.GetDocument()
    dgnMoniker = dgnDocument.GetMoniker()
    linkTreeSpec = DgnLinkManager.CreateTreeSpec ("Linkset", dgnMoniker, DgnLinkTreeKey.Project)

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, True)
    assert linkTree != None
    DgnLinkManager.WriteLinkTree (linkTree)

    ITxnManager.GetManager().CloseCurrentTxn (True)

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree != None

    status = DgnLinkManager.DeleteProjectTree (linkTreeSpec)
    assert status == SUCCESS

    ITxnManager.GetManager().CloseCurrentTxn (True)

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree == None

    ITxnManager.GetManager().ReverseTxns (1, False)

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    # assert linkTree != None

    ITxnManager.GetManager().ReverseTxns (1, False)

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree == None

    ITxnManager.GetManager().ReinstateTxn()

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    # assert linkTree != None

    ITxnManager.GetManager().ReinstateTxn ()

    linkTree     = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree == None

    ITxnManager.GetManager().ReverseTxns (1, False)

    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    # assert linkTree != None

    ITxnManager.GetManager().ReverseTxns (1, False)
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree == None

# Test for deleting dgn link Tree
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DgnLinks_DeleteProjectTree(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    linkTree = GetLinkTree(loadDgnFile)
    linkTreeSpec = linkTree.GetTreeSpec ()
    status = DgnLinkManager.DeleteProjectTree (linkTreeSpec)
    # assert status == SUCCESS
    linkTree = DgnLinkManager.ReadLinkTree (linkTreeSpec, False)
    assert linkTree == None
    savedResult = WString("DeleteProjectTree.dgn")
    # In saveAndCopyFile method TestDgnManager is not exposed
    # SaveAndCopyFile (savedResult)