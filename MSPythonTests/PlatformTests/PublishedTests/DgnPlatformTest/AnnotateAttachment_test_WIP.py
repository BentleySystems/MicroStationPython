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

def getDefaultModel (dgnFile):
    defaultModelID = dgnFile.FindModelIdByName ("Default")
    defaultModel = dgnFile.LoadRootModelById (defaultModelID, True, True)
    return defaultModel

def GetAttachmentCount(model):
    attachments = model.GetDgnAttachments()
    if(None == attachments):
        return -1
    else:
       return len (attachments)


@pytest.mark.parametrize('fileName', ['AnnotationAttachment_Section_Plan_Elevantion.dgn']) 
def test_Show_Hide(initDgnPlatformHost,loadDgnFile):
    namedViewCollection = loadDgnFile.GetNamedViews ()
    m_defaultModel = getDefaultModel(loadDgnFile)
    displayed = False
    status = AnnotationAttachmentStatus.BentleyStatus.eSUCCESS
    numberViews = len(namedViewCollection)
    referencesCount = GetAttachmentCount (m_defaultModel[0])
    assert referencesCount == 3
    assert numberViews == 3

    for namedView in namedViewCollection:
        namedViewR = namedView
        displayed = namedView.IsAnnotationAttachmentDisplayed (m_defaultModel[0], 1)
        assert False == displayed

        status = namedViewR.ShowAnnotationAttachment (m_defaultModel[0], None, 1)
        assert True == (AnnotationAttachmentStatus.BentleyStatus.eSUCCESS == status)

        newRefCount = GetAttachmentCount (m_defaultModel[0])
        assert newRefCount == referencesCount + 1

        referencesCount+=1

        displayed = namedViewR.IsAnnotationAttachmentDisplayed (m_defaultModel[0], 1)
        assert True == displayed

        #Hide Annotation Attachment
        if (displayed):
            status = namedViewR.HideAnnotationAttachment (m_defaultModel[0])

        displayed = namedViewR.IsAnnotationAttachmentDisplayed (m_defaultModel[0], 1)
        assert False == displayed


@pytest.mark.parametrize('fileName', ['AnnotationAttachment_Section_Plan_Elevantion.dgn']) 
def test_Show_HideAll(initDgnPlatformHost,loadDgnFile):
    namedViewCollection = loadDgnFile.GetNamedViews ()
    m_defaultModel = getDefaultModel(loadDgnFile)
    displayed = False
    status = AnnotationAttachmentStatus.BentleyStatus.eSUCCESS
    numberViews = len(namedViewCollection)
    referencesCount = GetAttachmentCount (m_defaultModel[0])
    assert referencesCount == 3
    assert numberViews == 3

    for namedView in namedViewCollection:
        namedViewR = namedView
        displayed = namedView.IsAnnotationAttachmentDisplayed (m_defaultModel[0], 1)
        assert False == displayed

        status = namedViewR.ShowAnnotationAttachment (m_defaultModel[0], None, 1)
        assert True == (AnnotationAttachmentStatus.BentleyStatus.eSUCCESS == status)

        newRefCount = GetAttachmentCount (m_defaultModel[0])
        assert newRefCount == referencesCount + 1

        referencesCount+=1

        displayed = namedViewR.IsAnnotationAttachmentDisplayed (m_defaultModel[0], 1)
        assert True == displayed

        #Hide Annotation Attachment
        namedViewR.HideAllAnnotationAttachments (m_defaultModel[0], None)

        displayed = namedViewR.IsAnnotationAttachmentDisplayed (m_defaultModel[0], 1)
        assert False == displayed

