import copy
import sys
import numpy as np
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_eeh = EditElementHandle()
m_entryList = []
MS_COLORBOOK_LEVEL = 64
MICROSTATION_ELM = 66

def AddEntry(m_colors, colorName, red, green, blue):
    global m_entryList
    colorDef = RgbColorDef()
    colorDef.red = red
    colorDef.green = green
    colorDef.blue = blue
    m_colors[colorName] = colorDef
    m_entryList.clear()
    del m_entryList[:]

def GetEntryCount(m_colors):
    return len(m_colors)

def GetEntry(m_colors, index, colorData):
    global m_entryList
    for key, value in m_colors.items():
        m_entryList.append([key, value])
    if index < 0 or index >= len(m_entryList):
        return BentleyStatus.eERROR
    if colorData["name"] != None:
        colorData["name"] = m_entryList[index][0]
    if colorData["color"] != None:
        colorData["color"] = m_entryList[index][1]
    return BentleyStatus.eSUCCESS

def FindColorByName(m_colors, color, colorName):
    item = None
    if colorName in m_colors:
        item = m_colors[colorName]
    if item == None:
        return BentleyStatus.eERROR
    if color != None and color[0] != None:
        color[0] = item
    return BentleyStatus.eSUCCESS

def isColorBookTableElem(ele, bookName, ret):
    # LinkageUtil::ExtractNamedStringLinkageByIndex This function is not yet exposed
    # m_eh = ElementHandle(MSElement(), ret[0]) // Could be used to get the element handle.
    m_eh = ElementHandle(ele, None)
    el = m_eh.GetElement()
    if el.ehdr.type != eMICROSTATION_ELM or el.ehdr.level != MS_COLORBOOK_LEVEL:
        return False
    # if BentleyStatus.eSUCCESS != LinkageUtil.ExtractNamedStringLinkageByIndex(name, MAX_COLORBOOK_NAME, STRING_LINKAGE_KEY_Name, 0, el):
    #     return  False;
    return True

def FindBookElem (bookName, dgnFile, ret, loadDgnFile):
    if None == bookName:
        return None
    nmCache = loadDgnFile.GetDictionaryModel().GetControlElements()
    for ele in nmCache:
        if isColorBookTableElem(ele, bookName, ret):
          return ele
    return None

def SaveToDgn(dgnFile, bookName, ret, loadDgnFile):
    colorBookElm = FindBookElem (bookName, dgnFile, ret, loadDgnFile)
    attrID = 0
    handlerID = XAttributeHandlerId(22276, 0)
    if colorBookElm != None:
        attrHandle = XAttributeHandle(colorBookElm, handlerID, attrID)
        status = CompressedXAttribute.Replace(attrHandle, xmlString, dataSize, COMPRESSION_THRESHOLD_MinimumAccess)
        if BentleyStatus.eSUCCESS != status:
            status = CompressedXAttribute.Add(colorBookElm, handlerID, attrID, xmlString, dataSize, COMPRESSION_THRESHOLD_MinimumAccess, NULL)
    else:
        class holderElement:
            ehdr = Elm_hdr
            reserved = [0*16]
        # holderElement = {"ehdr": Elm_hdr, "reserved": [0*16]}
        holderElement.ehdr.type   = eMICROSTATION_ELM
        holderElement.ehdr.level  = MS_COLORBOOK_LEVEL
        holderElement.ehdr.locked = True
        holderElement.ehdr.nonModel = True

        holderElement.ehdr.elementSize = sys.getsizeof(holderElement) / 2
        holderElement.ehdr.attrOffset  = holderElement.ehdr.elementSize

        pDescr = MSElementDescr.Allocate(m_eeh.GetElement(), ret[0])

        # LinkageUtil.SetStringLinkageUsingDescr() method not exposed.
        # LinkageUtil::SetStringLinkageUsingDescr (&pDescr, STRING_LINKAGE_KEY_Name, bookName)

        status = dgnFile.GetDictionaryModel().AddNewElementDescr(pDescr)
        # CompressedXAttribute.Add not exposed.
        # if BentleyStatus.eSUCCESS == status:
        #     status = CompressedXAttribute.Add(pDescr.h.elementRef, handlerID, attrID, xmlString[0], dataSize, COMPRESSION_THRESHOLD_MinimumAccess, NULL);

    return status