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

def GetAndFillDgnModel(dgnFile, modelId = -1):
    if -1 == modelId:
        modelId = dgnFile.DefaultModelId
    model = dgnFile.LoadRootModelById(modelId)[0]
    dgnFile.FillSectionsInModel(model)
    return model

@pytest.mark.parametrize('fileName', ['HasDigitalSignatureFileScope.dgn'])
def test_FileSignatureDelete(initDgnPlatformHost,loadDgnFile):
    assert loadDgnFile.GetSignatureCount() == 1
    
    nDeleted = 0
    
    signatures = FileSignatureCollection(loadDgnFile)
    
    for i in signatures:
        deleteThis = EditElementHandle(i, False)
        assert BentleyStatus.eSUCCESS == deleteThis.DeleteFromModel()
        nDeleted = nDeleted + 1
    
    assert 1 == nDeleted

    signList = list(signatures)
    # doubt regarding assert signatures.begin() == signatures.end()
    assert signList.__len__() == 0

@pytest.mark.parametrize('fileName', ['HasDigitalSignatureModelScope2.dgn'])
def test_Delete1Of2ModelsSignatures(initDgnPlatformHost,loadDgnFile):
    if loadDgnFile == None:
        assert False
    
    model = GetAndFillDgnModel(loadDgnFile)
    if model == None:
        assert False
        
    assert loadDgnFile.GetSignatureCount() == 2
    
    nDeleted = 0
    
    signatures = ModelSignatureCollection(model)
    it = iter(signatures)
    for i in it:
        if(nDeleted == 0):
            nDeleted = nDeleted + 1
            deleteThis = EditElementHandle(i, False)
            assert BentleyStatus.eSUCCESS == deleteThis.DeleteFromModel()
            
    assert 1 == nDeleted
    
    signList = list(signatures)
    # doubt regarding assert signatures.begin() != signatures.end()
    assert signList.__len__() != 0
    
    count = 0
    for i in signatures:
        count = count + 1
    
    assert 1 == count


@pytest.mark.parametrize('fileName', ['HasDigitalSignatureFileScope.dgn'])
def test_FindFileSignature(initDgnPlatformHost,loadDgnFileReadOnly):
    assert loadDgnFileReadOnly.GetSignatureCount() == 1
    
    count = 0
    for sigEh in FileSignatureCollection(loadDgnFileReadOnly):
        count = count + 1
        
        prereqs = ElementAgenda()
        assert BentleyStatus.eSUCCESS == DigitalSignatureCellHeaderHandler.GetPrerequisites(prereqs, sigEh)
        assert prereqs.IsEmpty()
        
        sigData = DigitalSignatureCellHeaderHandler.GetData(sigEh)
        
        assert True == sigData.IsValid()
        assert True == sigData.IncludesEntireFile()
        assert False == sigData.IncludesReferences()
        
        annotations = sigData.GetAnnotationData()
        assert annotations.Name == "FileSignatureV8i"
        assert annotations.Purpose == "purpose"
        assert annotations.Location == "location"
        assert 0 != annotations.expiryDate
        # assert sigData.IsExpired()
        
        cert = UInt8Array()
        assert BentleyStatus.eSUCCESS == sigData.GetCertificate(cert)
        assert cert.__len__() > 256
        
        # FILE* fp = fopen ("d:\\tmp\\cert.cer", "wb+");
        # fwrite (&cert[0], cert.size(), 1, fp);
        # fclose (fp);
        
        pkcs7 = UInt8Array()
        assert BentleyStatus.eSUCCESS == sigData.GetCertificateChain(pkcs7)
        assert pkcs7.__len__() > 256
        
        # fp = fopen ("d:\\tmp\\chain.p7b", "wb+");
        # fwrite (&pkcs7[0], pkcs7.size(), 1, fp);
        # fclose (fp);
        
    assert 1 == count

@pytest.mark.parametrize('fileName',['HasDigitalSignatureModelScope.dgn'])
def test_FindModelSignature(initDgnPlatformHost, loadDgnFileReadOnly):
    # model = loadDgnFile.GetAndFillDgnModelP()
    model = GetAndFillDgnModel(loadDgnFileReadOnly)
    if None == model:
        assert False
    
    assert loadDgnFileReadOnly.GetSignatureCount() == 1
    
    count = 0
    for sigEh in ModelSignatureCollection(model):
        count = count + 1
        
        prereqs = ElementAgenda()
        assert BentleyStatus.eSUCCESS == DigitalSignatureCellHeaderHandler.GetPrerequisites(prereqs, sigEh)
        assert prereqs.IsEmpty()
        
        sigData = DigitalSignatureCellHeaderHandler.GetData(sigEh)
        
        assert True == sigData.IsValid()
        assert False == sigData.IncludesEntireFile()
        assert False == sigData.IncludesReferences()
        
        annotations = sigData.GetAnnotationData()
        assert annotations.Name == "ModelSignatureV8i"
        assert annotations.Purpose == ""
        assert annotations.Location == "location1"
        assert 0 == annotations.expiryDate
        # assert True != sigData.IsExpired()
        
        cert = UInt8Array()
        assert BentleyStatus.eSUCCESS == sigData.GetCertificate(cert)
        assert cert.__len__() > 256
       
        # FILE* fp = fopen ("d:\\tmp\\cert.cer", "wb+");
        # fwrite (&cert[0], cert.size(), 1, fp);
        # fclose (fp);
        
        pkcs7 = UInt8Array()
        assert BentleyStatus.eSUCCESS == sigData.GetCertificateChain(pkcs7)
        assert pkcs7.__len__() > 256
        
        # fp = fopen ("d:\\tmp\\chain.p7b", "wb+");
        # fwrite (&pkcs7[0], pkcs7.size(), 1, fp);
        # fclose (fp);
        
    assert 1 == count

@pytest.mark.parametrize('fileName',['HasDigitalSignatureModelScope2.dgn'])
def test_Find2ModelSignatures(initDgnPlatformHost, loadDgnFileReadOnly):
  # model = loadDgnFile.GetAndFillDgnModelP()
    model = GetAndFillDgnModel(loadDgnFileReadOnly)
    if None == model:
        assert False
    
    assert loadDgnFileReadOnly.GetSignatureCount() == 2
    
    count = 0
    found1 = False
    found2 = False
    for sigEh in ModelSignatureCollection(model):
        count = count + 1
      
        sigData = DigitalSignatureCellHeaderHandler.GetData (sigEh)
        
        assert True == sigData.IsValid()
        assert False == sigData.IncludesEntireFile()
        
        annotations = sigData.GetAnnotationData()

        if (annotations.Name == '1'):
            found1 = True
        elif (annotations.Name == '2'):
            found2 = True
            
            
    assert 2 == count
    assert True == (found1 and found2)

@pytest.mark.parametrize('fileName',['HasDigitalSignatureFileScope.dgn'])
def test_AllApplicableSignaturesFileOnly(initDgnPlatformHost, loadDgnFileReadOnly):
    ret = loadDgnFileReadOnly.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = ret[0]
    model = GetAndFillDgnModel(loadDgnFileReadOnly, model.ModelId)
    
    if None == model:
        assert False
        
    assert loadDgnFileReadOnly.GetSignatureCount() == 1
    
    count = 0
    applicableSignatureCollection = ApplicableSignaturesCollection(model)
    for sigEh in applicableSignatureCollection:
        count = count + 1
        
        sigData = DigitalSignatureCellHeaderHandler.GetData (sigEh)
        
        assert True == sigData.IsValid()
        assert True == sigData.IncludesEntireFile()
        assert False == sigData.IncludesReferences()
        
        annotations = sigData.GetAnnotationData()
        assert annotations.Name == "FileSignatureV8i"
        assert annotations.Purpose == "purpose"
        assert annotations.Location == "location"
        assert 0 != annotations.expiryDate
        # assert True != sigData.IsExpired()
        
        cert = UInt8Array()
        assert BentleyStatus.eSUCCESS == sigData.GetCertificate(cert)
        assert cert.__len__() > 256
        
        # FILE* fp = fopen ("d:\\tmp\\cert.cer", "wb+");
        # fwrite (&cert[0], cert.size(), 1, fp);
        # fclose (fp);
        
        pkcs7 = UInt8Array()
        assert BentleyStatus.eSUCCESS == sigData.GetCertificateChain(pkcs7)
        assert pkcs7.__len__() > 256
        
        # fp = fopen ("d:\\tmp\\chain.p7b", "wb+");
        # fwrite (&pkcs7[0], pkcs7.size(), 1, fp);
        # fclose (fp);
        
    assert 1 == count