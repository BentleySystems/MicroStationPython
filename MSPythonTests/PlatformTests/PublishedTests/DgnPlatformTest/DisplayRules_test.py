#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import sys
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_displayRuleSet0 = DisplayRuleSet
m_displayRuleSet1 = DisplayRuleSet
m_displayRule0 = DisplayRule
m_displayRule1 = DisplayRule

m_actionElementDisplay = ElementDisplayAction
m_actionColorOverride = ColorOverrideAction
m_actionFillColorOverride = FillColorOverrideAction
m_actionStyleOverride = StyleOverrideAction
m_actionWeightOverride = WeightOverrideAction
m_actionTransparencyOverride = TransparencyOverrideAction
m_actionElementPriorityOverride = ElementPriorityAction
m_actionDisplayStyleOverride = DisplayStyleOverrideAction
m_actionAreaHatch = AreaHatchAction
m_actionAreaPattern = AreaPatternAction

def SetUp(loadDgnFile):
    SetUpDisplayRuleSets(loadDgnFile)
    SetUpDisplayRules(loadDgnFile)

def TearDown():
    global m_displayRuleSet0, m_displayRuleSet1, m_displayRule0, m_displayRule1
    m_displayRule1 = None
    m_displayRule0 = None
    m_displayRuleSet1 = None
    m_displayRuleSet0 = None

def SetUpDisplayRules(loadDgnFile):
    global m_displayRule0, m_displayRule1
    m_displayRule0 = DisplayRule((WString)("element.DgnElementSchema::ShapeElement::EnclosedArea>2000000000"), True, loadDgnFile)
    m_displayRule1 = DisplayRule((WString)("element.DgnElementSchema::ShapeElement::EnclosedArea>1000000000"), False, loadDgnFile)

def SetUpDisplayRuleSets(loadDgnFile):
    global m_displayRuleSet0, m_displayRuleSet1
    m_displayRuleSet0 = DisplayRuleSet((WString)("RuleSet0"), loadDgnFile)
    m_displayRuleSet1 = DisplayRuleSet((WString)("RuleSet1"), loadDgnFile)

def CompareDisplayRuleSetsProperties(ruleSet0, ruleSet1):
    ruleSet1Clone = ruleSet1.Clone(ruleSet1.GetDgnFile())
    assert ruleSet0.GetDisplayRules().__len__() == ruleSet1Clone.GetDisplayRules().__len__()
    for i in range(ruleSet0.GetDisplayRules().__len__()):
        ruleIter0 = ruleSet0.GetDisplayRules()[i]
        ruleIter1 = ruleSet1Clone.GetDisplayRules()[i]
        assert ruleIter0.GetCondition() == ruleIter1.GetCondition()
        assert ruleIter0.StopIfTrue() == ruleIter1.StopIfTrue()
        assert ruleIter0.IsEnabled() == ruleIter1.IsEnabled()
        assert ruleIter0.GetConditionDescription() == ruleIter1.GetConditionDescription()
        CheckAllActions(ruleIter0, 10)
        CheckAllActions(ruleIter1, 10)

def SetStartingActions(loadDgnFile):
    global m_actionElementDisplay, m_actionColorOverride, m_actionFillColorOverride, m_actionStyleOverride, m_actionWeightOverride
    global m_actionTransparencyOverride, m_actionElementPriorityOverride, m_actionDisplayStyleOverride, m_actionAreaHatch, m_actionAreaPattern
    m_actionElementDisplay = ElementDisplayAction(False)
    m_actionColorOverride = ColorOverrideAction(3, loadDgnFile)
    m_actionFillColorOverride = FillColorOverrideAction(3, loadDgnFile)
    m_actionStyleOverride = StyleOverrideAction(3, loadDgnFile)
    m_actionWeightOverride = WeightOverrideAction(5)
    m_actionTransparencyOverride = TransparencyOverrideAction(0.8)
    m_actionElementPriorityOverride = ElementPriorityAction(1)
    m_actionDisplayStyleOverride = DisplayStyleOverrideAction(1, loadDgnFile)
    m_actionAreaHatch = AreaHatchAction(AreaHatchAction.HatchParams(1, 1, None, None, False, None, None, None), loadDgnFile)
    m_actionAreaPattern = AreaPatternAction(AreaPatternAction.AreaPatternParams(0, 0.8, False, None, None, None, None), loadDgnFile)

def SetNewActionsValues():
    global m_actionElementDisplay, m_actionColorOverride, m_actionFillColorOverride, m_actionStyleOverride, m_actionWeightOverride
    global m_actionTransparencyOverride, m_actionElementPriorityOverride, m_actionDisplayStyleOverride, m_actionAreaHatch, m_actionAreaPattern
    m_actionElementDisplay.SetIsElementDisplayOff(True)
    m_actionColorOverride.SetElementColor(1)
    m_actionFillColorOverride.SetElementFillColor(1)
    m_actionStyleOverride.SetLineStyle(1)
    m_actionWeightOverride.SetLineWeight(1)
    m_actionTransparencyOverride.SetTransparency(1)
    m_actionElementPriorityOverride.SetElementPriority(2)
    m_actionDisplayStyleOverride.SetDisplayStyleIndex(2)
    m_actionAreaHatch.Params = AreaHatchAction.HatchParams(2, 2, None, None, False, None, None, None)
    m_actionAreaPattern.Params = AreaPatternAction.AreaPatternParams(1, 0.7, False, None, None, None, None)

def SetStartingActionsBack():
    global m_actionElementDisplay, m_actionColorOverride, m_actionFillColorOverride, m_actionStyleOverride, m_actionWeightOverride
    global m_actionTransparencyOverride, m_actionElementPriorityOverride, m_actionDisplayStyleOverride, m_actionAreaHatch, m_actionAreaPattern
    m_actionElementDisplay.SetIsElementDisplayOff(False)
    m_actionColorOverride.SetElementColor(3)
    m_actionFillColorOverride.SetElementFillColor(3)
    m_actionStyleOverride.SetLineStyle(3)
    m_actionWeightOverride.SetLineWeight(5)
    m_actionTransparencyOverride.SetTransparency(0.8)
    m_actionElementPriorityOverride.SetElementPriority(1)
    m_actionDisplayStyleOverride.SetDisplayStyleIndex(1)
    m_actionAreaHatch.Params = AreaHatchAction.HatchParams(1, 1, None, None, False, None, None, None)
    m_actionAreaPattern.Params = AreaPatternAction.AreaPatternParams(0, 0.8, False, None, None, None, None)

def SetActions(displayRule):
    global m_actionElementDisplay, m_actionColorOverride, m_actionFillColorOverride, m_actionStyleOverride, m_actionWeightOverride
    global m_actionTransparencyOverride, m_actionElementPriorityOverride, m_actionDisplayStyleOverride, m_actionAreaHatch, m_actionAreaPattern
    actions = displayRule.GetActions()
    actions.clear()
    actions.append(m_actionElementDisplay)
    actions.append(m_actionColorOverride)
    actions.append(m_actionFillColorOverride)
    actions.append(m_actionStyleOverride)
    actions.append(m_actionWeightOverride)
    actions.append(m_actionTransparencyOverride)
    actions.append(m_actionElementPriorityOverride)
    actions.append(m_actionDisplayStyleOverride)
    actions.append(m_actionAreaHatch)
    actions.append(m_actionAreaPattern)

def CheckAllActions(displayRule, expectedSize):
    global m_actionElementDisplay, m_actionColorOverride, m_actionFillColorOverride, m_actionStyleOverride, m_actionWeightOverride
    global m_actionTransparencyOverride, m_actionElementPriorityOverride, m_actionDisplayStyleOverride, m_actionAreaHatch, m_actionAreaPattern
    assert displayRule.GetActions()
    successCounter = 0

    for action in displayRule.GetActions():
        if action.GetActionId() == DisplayRuleActionId.eElementDisplay:
            act = ElementDisplayAction
            act = action
            assert act.IsElementDisplayOff() == m_actionElementDisplay.IsElementDisplayOff()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eColorOverride:
            act = ColorOverrideAction
            act = action
            assert act.GetElementColor() == m_actionColorOverride.GetElementColor()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eFillColorOverride:
            act = FillColorOverrideAction
            act = action
            assert act.GetElementFillColor() == m_actionFillColorOverride.GetElementFillColor()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eStyleOverride:
            act = StyleOverrideAction
            act = action
            assert act.GetLineStyle() == m_actionStyleOverride.GetLineStyle()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eWeightOverride:
            act = WeightOverrideAction
            act = action
            assert act.GetLineWeight() == m_actionWeightOverride.GetLineWeight()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eTransparencyOverride:
            act = TransparencyOverrideAction
            act = action
            assert act.GetTransparency() == m_actionTransparencyOverride.GetTransparency()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eElementPriority:
            act = ElementPriorityAction
            act = action
            assert act.GetElementPriority() == m_actionElementPriorityOverride.GetElementPriority()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eDisplayStyleOverride:
            act = DisplayStyleOverrideAction
            act = action
            assert act.GetDisplayStyleIndex() == m_actionDisplayStyleOverride.GetDisplayStyleIndex()
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eAreaHatch:
            act = AreaHatchAction
            act = action
            assert act.Params.m_distance1 == m_actionAreaHatch.Params.m_distance1
            assert act.Params.m_angle1 == m_actionAreaHatch.Params.m_angle1
            assert act.Params.m_distance2 == m_actionAreaHatch.Params.m_distance2
            assert act.Params.m_angle2 == m_actionAreaHatch.Params.m_angle2
            assert act.Params.m_annotationScaleOn == m_actionAreaHatch.Params.m_annotationScaleOn
            assert act.Params.m_color == m_actionAreaHatch.Params.m_color
            assert act.Params.m_style == m_actionAreaHatch.Params.m_style
            assert act.Params.m_weight == m_actionAreaHatch.Params.m_weight
            successCounter = successCounter + 1
        elif action.GetActionId() == DisplayRuleActionId.eAreaPattern:
            act = AreaPatternAction
            act = action
            assert act.Params.m_cellId == m_actionAreaPattern.Params.m_cellId
            assert act.Params.m_scale == m_actionAreaPattern.Params.m_scale
            assert act.Params.m_annotationScaleOn == m_actionAreaPattern.Params.m_annotationScaleOn
            assert act.Params.m_angle == m_actionAreaPattern.Params.m_angle
            assert act.Params.m_color == m_actionAreaPattern.Params.m_color
            assert act.Params.m_weight == m_actionAreaPattern.Params.m_weight
            assert act.Params.m_style == m_actionAreaPattern.Params.m_style
            successCounter = successCounter + 1
        else:
            assert False

    assert expectedSize == successCounter

def SetDisplayRuleSets(loadDgnFile):
    global m_displayRule0, m_displayRule1, m_displayRuleSet0, m_displayRuleSet1
    SetStartingActions(loadDgnFile)
    SetActions(m_displayRule0)
    SetActions(m_displayRule1)

    m_displayRule0.SetConditionDescription(WString("Applies now"))
    m_displayRule1.SetConditionDescription(WString("Apllies always"))

    m_displayRuleSet0.GetDisplayRules().append(m_displayRule0)
    m_displayRuleSet1.GetDisplayRules().append(m_displayRule1)

def SetUpOverride(loadDgnFile):
    SetUpDisplayRules(loadDgnFile)
    SetUpDisplayRuleSets(loadDgnFile)
    SetDisplayRuleSets(loadDgnFile)

def SaveCloseAndReopenFile(dgnFile):
    assert dgnFile
    assert not dgnFile.IsReadOnly()
    assert BentleyStatus.eSUCCESS == dgnFile.ProcessChanges(DgnSaveReason.eApplInitiated, 0)

    ret = DgnDocument.CreateFromFileName(str(dgnFile.FileName), None, -101, DgnDocument.FetchMode.eWrite)
    if ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success:
        assert False
    dgnFileRet = DgnFile(ret[0], DgnFileOpenMode.eReadOnly)
    dgnFileRet.LoadDgnFile()
    dgnFileRet.FillDictionaryModel()
    return dgnFileRet

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetSetDisplayRuleSetTests(initDgnPlatformHost, loadDgnFile):
    global m_displayRuleSet0, m_displayRuleSet1
    SetUp(loadDgnFile)
    m_displayRuleSet0 = DisplayRuleSet((WString)("Test0"), loadDgnFile)
    m_displayRuleSet1 = DisplayRuleSet((WString)("Test1"), loadDgnFile)
    assert str(m_displayRuleSet0.GetName()) == "Test0"
    assert str(m_displayRuleSet1.GetName()) == "Test1"

    m_displayRuleSet0.SetName((WString)("Changed0"))
    assert str(m_displayRuleSet0.GetName()) == "Changed0"
    assert loadDgnFile == m_displayRuleSet0.GetDgnFile()

    dStyle1 = DisplayStyle(loadDgnFile, "TestStyle")
    assert True != m_displayRuleSet0.IsUsedByDisplayStyle(dStyle1)

    DisplayRulesManager.SetDisplayRuleSetToDisplayStyle(m_displayRuleSet0, dStyle1)
    assert True == m_displayRuleSet0.IsUsedByDisplayStyle(dStyle1)
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayRuleSetCloneAndEquals(initDgnPlatformHost, loadDgnFile):
    global m_displayRule0, m_displayRule1, m_displayRuleSet0
    SetUp(loadDgnFile)
    SetStartingActions(loadDgnFile)
    SetActions(m_displayRule0)

    m_displayRuleSet0.GetDisplayRules().append(m_displayRule0)
    displayRuleSet0Clone = m_displayRuleSet0.Clone(loadDgnFile)

    assert displayRuleSet0Clone.GetName() == m_displayRuleSet0.GetName()
    assert displayRuleSet0Clone.GetDgnFile() == m_displayRuleSet0.GetDgnFile()

    assert m_displayRuleSet0.GetDisplayRules()
    assert m_displayRuleSet0.GetDisplayRules()[-1] == m_displayRule0

    assert displayRuleSet0Clone.GetDisplayRules()
    assert displayRuleSet0Clone.GetDisplayRules()[-1] == m_displayRule0

    assert displayRuleSet0Clone == m_displayRuleSet0

    displayRuleSet0Clone.SetName(WString("ChangedSet"))
    assert displayRuleSet0Clone != m_displayRuleSet0
    displayRuleSet0Clone.SetName(m_displayRuleSet0.GetName())

    SetNewActionsValues()
    assert displayRuleSet0Clone != m_displayRuleSet0
    SetStartingActionsBack()

    SetActions(m_displayRule1)
    displayRuleSet0Clone.GetDisplayRules().append(m_displayRule1)
    assert displayRuleSet0Clone != m_displayRuleSet0
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetSetDisplayRuleTests(initDgnPlatformHost, loadDgnFile):
    global m_displayRule0, m_displayRule1
    SetUp(loadDgnFile)
    m_displayRule0 = DisplayRule(WString("element.DgnElementSchema::ShapeElement::EnclosedArea>2000000000"), True, loadDgnFile)
    m_displayRule1 = DisplayRule(WString("element.DgnElementSchema::ShapeElement::EnclosedArea>1000000000"), False, loadDgnFile)

    assert WString("element.DgnElementSchema::ShapeElement::EnclosedArea>2000000000") == m_displayRule0.GetCondition()
    assert WString("element.DgnElementSchema::ShapeElement::EnclosedArea>1000000000") == m_displayRule1.GetCondition()

    m_displayRule0.SetCondition(WString("element.IsOfClass(\"Room\",\"Bentley_Facilities_ExpImp_Schema_becert__x003a__Marlow\")"))
    assert WString("element.IsOfClass(\"Room\",\"Bentley_Facilities_ExpImp_Schema_becert__x003a__Marlow\")") == m_displayRule0.GetCondition()

    assert m_displayRule0.StopIfTrue()
    assert not m_displayRule1.StopIfTrue()

    m_displayRule0.SetStopIfTrue(False)
    assert not m_displayRule0.StopIfTrue()

    assert m_displayRule0.IsEnabled()
    m_displayRule0.SetIsEnabled(False)
    assert not m_displayRule0.IsEnabled()

    assert WString("") == m_displayRule0.GetConditionDescription()
    m_displayRule0.SetConditionDescription(WString("Applies sometimes"))
    assert WString("Applies sometimes") == m_displayRule0.GetConditionDescription()
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetSetDisplayRuleActionTests(initDgnPlatformHost, loadDgnFile):
    global m_displayRule0
    SetUp(loadDgnFile)
    SetStartingActions(loadDgnFile)
    SetActions(m_displayRule0)
    CheckAllActions(m_displayRule0, 10)

    SetNewActionsValues()
    CheckAllActions(m_displayRule0, 10)
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayRuleCloneAndEquals(initDgnPlatformHost, loadDgnFile):
    global m_displayRule0
    SetUp(loadDgnFile)
    SetStartingActions(loadDgnFile)
    SetActions(m_displayRule0)
    displayRule0Clone = m_displayRule0.Clone(loadDgnFile)

    assert m_displayRule0.IsEnabled() == displayRule0Clone.IsEnabled()
    assert m_displayRule0.StopIfTrue() == displayRule0Clone.StopIfTrue()
    assert m_displayRule0.GetCondition() == displayRule0Clone.GetCondition()
    assert m_displayRule0.GetConditionDescription() == displayRule0Clone.GetConditionDescription()

    CheckAllActions(m_displayRule0, 10)
    CheckAllActions(displayRule0Clone, 10)

    assert m_displayRule0 == displayRule0Clone

    displayRule0Clone.SetCondition(WString("element.DgnElementSchema::ShapeElement::EnclosedArea>3000000000"))
    assert m_displayRule0 != displayRule0Clone
    displayRule0Clone.SetCondition(m_displayRule0.GetCondition())

    displayRule0Clone.SetConditionDescription(WString("Applies today"))
    assert m_displayRule0 != displayRule0Clone
    displayRule0Clone.SetConditionDescription(m_displayRule0.GetConditionDescription())

    displayRule0Clone.SetIsEnabled(False)
    assert m_displayRule0 != displayRule0Clone
    displayRule0Clone.SetIsEnabled(m_displayRule0.IsEnabled())

    displayRule0Clone.SetStopIfTrue(False)
    assert m_displayRule0 != displayRule0Clone
    displayRule0Clone.SetStopIfTrue(m_displayRule0.StopIfTrue())


    SetNewActionsValues()
    assert m_displayRule0 != displayRule0Clone
    SetStartingActionsBack()

    actionColorOverrideAdd = ColorOverrideAction(5, loadDgnFile)
    m_displayRule0.GetActions().append(actionColorOverrideAdd)
    assert m_displayRule0 != displayRule0Clone
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayRuleActionCloneEquals(initDgnPlatformHost, loadDgnFile):
    global m_actionElementDisplay, m_actionColorOverride, m_actionFillColorOverride, m_actionStyleOverride, m_actionWeightOverride
    global m_actionTransparencyOverride, m_actionElementPriorityOverride, m_actionDisplayStyleOverride, m_actionAreaHatch, m_actionAreaPattern
    SetUp(loadDgnFile)
    SetStartingActions(loadDgnFile)

    #ElementDisplayActionP 
    actionElementDisplayCloneTemp = m_actionElementDisplay.Clone(loadDgnFile)
    actionElementDisplayClone = actionElementDisplayCloneTemp
    assert m_actionElementDisplay.IsElementDisplayOff() == actionElementDisplayClone.IsElementDisplayOff()
    assert m_actionElementDisplay == actionElementDisplayClone
    m_actionElementDisplay.SetIsElementDisplayOff(True)
    assert m_actionElementDisplay != actionElementDisplayClone

    #ColorOverrideActionP
    actionColorOverrideCloneTemp = m_actionColorOverride.Clone(loadDgnFile)
    actionColorOverrideClone = actionColorOverrideCloneTemp
    assert m_actionColorOverride.GetElementColor() == actionColorOverrideClone.GetElementColor()
    assert m_actionColorOverride == actionColorOverrideClone
    m_actionColorOverride.SetElementColor(1)
    assert m_actionColorOverride != actionElementDisplayClone

    #FillColorOverrideActionP
    actionFillColorOverrideCloneTemp = m_actionFillColorOverride.Clone(loadDgnFile)
    actionFillColorOverrideClone = actionFillColorOverrideCloneTemp
    assert m_actionFillColorOverride.GetElementFillColor() == actionFillColorOverrideClone.GetElementFillColor()
    assert m_actionFillColorOverride == actionFillColorOverrideClone
    m_actionFillColorOverride.SetElementFillColor(1)
    assert m_actionFillColorOverride != actionFillColorOverrideClone

    #StyleOverrideActionP
    actionStyleOverrideCloneTemp = m_actionStyleOverride.Clone(loadDgnFile)
    actionStyleOverrideClone = actionStyleOverrideCloneTemp
    assert m_actionStyleOverride.GetLineStyle() == actionStyleOverrideClone.GetLineStyle()
    assert m_actionStyleOverride == actionStyleOverrideClone
    m_actionStyleOverride.SetLineStyle(1)
    assert m_actionStyleOverride != actionStyleOverrideClone

    #WeightOverrideActionP
    actionWeightOverrideCloneTemp = m_actionWeightOverride.Clone(loadDgnFile)
    actionWeightOverrideClone = actionWeightOverrideCloneTemp
    assert m_actionWeightOverride.GetLineWeight() == actionWeightOverrideClone.GetLineWeight()
    assert m_actionWeightOverride == actionWeightOverrideClone
    m_actionWeightOverride.SetLineWeight(1)
    assert m_actionWeightOverride != actionWeightOverrideClone

    #TransparencyOverrideActionP
    actionTransparencyOverrideCloneTemp = m_actionTransparencyOverride.Clone(loadDgnFile)
    actionTransparencyOverrideClone = actionTransparencyOverrideCloneTemp
    assert m_actionTransparencyOverride.GetTransparency() == actionTransparencyOverrideClone.GetTransparency()
    assert m_actionTransparencyOverride == actionTransparencyOverrideClone
    m_actionTransparencyOverride.SetTransparency(1)
    assert m_actionTransparencyOverride != actionTransparencyOverrideClone

    #ElementPriorityActionP
    actionElementPriorityOverrideCloneTemp = m_actionElementPriorityOverride.Clone(loadDgnFile)
    actionElementPriorityOverrideClone = actionElementPriorityOverrideCloneTemp
    assert m_actionElementPriorityOverride.GetElementPriority() == actionElementPriorityOverrideClone.GetElementPriority()
    assert m_actionElementPriorityOverride == actionElementPriorityOverrideClone
    m_actionElementPriorityOverride.SetElementPriority(2)
    assert m_actionElementPriorityOverride != actionElementPriorityOverrideClone

    #DisplayStyleOverrideActionP
    actionDisplayStyleOverrideCloneTemp = m_actionDisplayStyleOverride.Clone(loadDgnFile)
    actionDisplayStyleOverrideClone = actionDisplayStyleOverrideCloneTemp
    assert m_actionDisplayStyleOverride.GetDisplayStyleIndex() == actionDisplayStyleOverrideClone.GetDisplayStyleIndex()
    assert m_actionDisplayStyleOverride == actionDisplayStyleOverrideClone
    m_actionDisplayStyleOverride.SetDisplayStyleIndex(2)
    assert m_actionDisplayStyleOverride != actionDisplayStyleOverrideClone

    #AreaHatchActionP
    actionAreaHatchCloneTemp = m_actionAreaHatch.Clone(loadDgnFile)
    actionAreaHatchClone = actionAreaHatchCloneTemp
    assert m_actionAreaHatch.Params.m_distance1 == actionAreaHatchClone.Params.m_distance1
    assert m_actionAreaHatch.Params.m_angle1 == actionAreaHatchClone.Params.m_angle1
    assert m_actionAreaHatch.Params.m_distance2 == actionAreaHatchClone.Params.m_distance2
    assert m_actionAreaHatch.Params.m_angle2 == actionAreaHatchClone.Params.m_angle2
    assert m_actionAreaHatch.Params.m_annotationScaleOn == actionAreaHatchClone.Params.m_annotationScaleOn
    assert m_actionAreaHatch.Params.m_color == actionAreaHatchClone.Params.m_color
    assert m_actionAreaHatch.Params.m_style == actionAreaHatchClone.Params.m_style
    assert m_actionAreaHatch.Params.m_weight == actionAreaHatchClone.Params.m_weight
    assert m_actionAreaHatch.Params.m_style == actionAreaHatchClone.Params.m_style
    assert m_actionAreaHatch == actionAreaHatchClone
    m_actionAreaHatch.Params = AreaHatchAction.HatchParams(2, 2, None, None, False, None, None, None)
    assert m_actionAreaHatch != actionAreaHatchClone

    #AreaPatternActionP
    actionAreaPatternCloneTemp = m_actionAreaPattern.Clone(loadDgnFile)
    actionAreaPatternClone = actionAreaPatternCloneTemp
    assert m_actionAreaPattern.Params.m_cellId == actionAreaPatternClone.Params.m_cellId
    assert m_actionAreaPattern.Params.m_scale == actionAreaPatternClone.Params.m_scale
    assert m_actionAreaPattern.Params.m_annotationScaleOn == actionAreaPatternClone.Params.m_annotationScaleOn
    assert m_actionAreaPattern.Params.m_angle == actionAreaPatternClone.Params.m_angle
    assert m_actionAreaPattern.Params.m_color == actionAreaPatternClone.Params.m_color
    assert m_actionAreaPattern.Params.m_weight == actionAreaPatternClone.Params.m_weight
    assert m_actionAreaPattern.Params.m_style == actionAreaPatternClone.Params.m_style
    assert m_actionAreaPattern == actionAreaPatternClone
    m_actionAreaPattern.Params = AreaPatternAction.AreaPatternParams(1, 0.7, False, None, None, None, None)
    assert m_actionAreaPattern != actionAreaPatternClone
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetDisplayRuleSetsInFile(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global m_displayRuleSet0, m_displayRuleSet1
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    SetUpOverride(srcDgnFile)

    displayRuleSetCP0 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet0, srcDgnFile, False)
    assert displayRuleSetCP0
    assert displayRuleSetCP0 == m_displayRuleSet0

    displayRuleSetCP1 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet1, srcDgnFile, False)
    assert displayRuleSetCP1
    assert displayRuleSetCP1 == m_displayRuleSet1

    displayRuleSetVector = DisplayRulesManager.GetDisplayRuleSetsInFile(srcDgnFile)
    assert displayRuleSetVector
    totalDisplayRuleSetsFound = 0
    for currentDisplayRuleSet in displayRuleSetVector:
        if currentDisplayRuleSet == m_displayRuleSet0:
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        elif currentDisplayRuleSet == m_displayRuleSet1:
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        else:
             assert False

    assert 2 == totalDisplayRuleSetsFound

    displayRuleSet2 = DisplayRuleSet(WString("RuleSet2"), srcDgnFile)
    displayRuleSetCP2 = DisplayRulesManager.WriteDisplayRuleSetToFile(displayRuleSet2, srcDgnFile, False)
    assert displayRuleSetCP2
    assert displayRuleSetCP2 == displayRuleSet2

    displayRuleSetVector = DisplayRulesManager.GetDisplayRuleSetsInFile(srcDgnFile)
    assert displayRuleSetVector
    totalDisplayRuleSetsFound = 0
    for currentDisplayRuleSet in displayRuleSetVector:
        if currentDisplayRuleSet == m_displayRuleSet0:
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        elif currentDisplayRuleSet == m_displayRuleSet1:
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        elif currentDisplayRuleSet == displayRuleSet2:
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        else:
             assert False

    assert 3 == totalDisplayRuleSetsFound

    dgnFile = SaveCloseAndReopenFile(srcDgnFile)

    displayRuleSetVector = DisplayRulesManager.GetDisplayRuleSetsInFile(dgnFile)
    assert displayRuleSetVector
    totalDisplayRuleSetsFound = 0
    for currentDisplayRuleSet in displayRuleSetVector:
        if m_displayRuleSet0.GetName() == currentDisplayRuleSet.GetName():
             CompareDisplayRuleSetsProperties(m_displayRuleSet0, currentDisplayRuleSet)
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        elif m_displayRuleSet1.GetName() == currentDisplayRuleSet.GetName():
             CompareDisplayRuleSetsProperties(m_displayRuleSet1, currentDisplayRuleSet)
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        elif displayRuleSet2.GetName() == currentDisplayRuleSet.GetName():
             CompareDisplayRuleSetsProperties(displayRuleSet2, currentDisplayRuleSet)
             totalDisplayRuleSetsFound = totalDisplayRuleSetsFound + 1
        else:
             assert False

    assert 3 == totalDisplayRuleSetsFound
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetDisplayRuleSetByName(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global m_displayRuleSet0, m_displayRuleSet1
    srcDgnFile = createTempDgnFileFromSeed(loadDgnFile)
    SetUpOverride(srcDgnFile)

    displayRuleSetCP0 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet0, srcDgnFile, False)
    assert displayRuleSetCP0

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", srcDgnFile)
    assert displayRuleSetCP0FromFile
    assert displayRuleSetCP0 == displayRuleSetCP0FromFile

    displayRuleSetCP1 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet1, srcDgnFile, False)
    assert displayRuleSetCP1

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", srcDgnFile)
    assert displayRuleSetCP0FromFile
    assert m_displayRuleSet0 == displayRuleSetCP0FromFile

    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet1", srcDgnFile)
    assert displayRuleSetCP1FromFile
    assert m_displayRuleSet1 == displayRuleSetCP1FromFile

    displayRuleSetFail = DisplayRulesManager.GetDisplayRuleSetByName("SomeName", srcDgnFile)
    assert not displayRuleSetFail

    dgnFile = SaveCloseAndReopenFile(srcDgnFile)

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", dgnFile)
    assert displayRuleSetCP0FromFile
    CompareDisplayRuleSetsProperties(m_displayRuleSet0, displayRuleSetCP0FromFile)

    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet1", dgnFile)
    assert displayRuleSetCP1FromFile
    CompareDisplayRuleSetsProperties(m_displayRuleSet1, displayRuleSetCP1FromFile)
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RenameDisplayRuleSetInFile(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global m_displayRuleSet0, m_displayRuleSet1
    srcDgnFile = createTempDgnFileFromSeed(loadDgnFile)
    SetUpOverride(srcDgnFile)

    displayRuleSetCP0 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet0, srcDgnFile, False)
    assert displayRuleSetCP0
 
    assert BentleyStatus.eSUCCESS == DisplayRulesManager.RenameDisplayRuleSetInFile("RuleSet0", "Renamed0", srcDgnFile)
    displayRuleSetFail = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", srcDgnFile)
    assert not displayRuleSetFail

    displayRuleSet0Clone = m_displayRuleSet0.Clone(srcDgnFile)
    displayRuleSet0Clone.SetName(WString("Renamed0"))
    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("Renamed0", srcDgnFile)
    assert displayRuleSetCP0FromFile
    assert displayRuleSet0Clone == displayRuleSetCP0FromFile

    displayRuleSetCP1 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet1, srcDgnFile, False)
    assert displayRuleSetCP1

    assert BentleyStatus.eSUCCESS == DisplayRulesManager.RenameDisplayRuleSetInFile("RuleSet1", "Renamed1", srcDgnFile)
    displayRuleSetFail = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet1", srcDgnFile)
    assert not displayRuleSetFail
    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("Renamed1", srcDgnFile)
    assert displayRuleSetCP1FromFile

    displayRuleSet1Clone = m_displayRuleSet1.Clone(srcDgnFile)
    displayRuleSet1Clone.SetName(WString("Renamed1"))
    assert displayRuleSet1Clone == displayRuleSetCP1FromFile

    assert BentleyStatus.eERROR == DisplayRulesManager.RenameDisplayRuleSetInFile("Renamed0", "Renamed1", srcDgnFile)
    drscpFromFile = DisplayRulesManager.GetDisplayRuleSetByName("Renamed1", srcDgnFile)
    assert drscpFromFile
    displayRuleSet0Clone.SetName(WString("Renamed1"))
    assert displayRuleSet0Clone != drscpFromFile
    assert displayRuleSet1Clone == drscpFromFile
    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("Renamed0", srcDgnFile)
    assert displayRuleSetCP0FromFile
    displayRuleSet0Clone.SetName(WString("Renamed0"))
    assert displayRuleSet0Clone == displayRuleSetCP0FromFile

    displayRuleSetFail = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet5", srcDgnFile)
    assert not displayRuleSetFail
    assert BentleyStatus.eERROR == DisplayRulesManager.RenameDisplayRuleSetInFile("RuleSet5", "Renamed5", srcDgnFile)
    displayRuleSetFail = DisplayRulesManager.GetDisplayRuleSetByName("Renamed5", srcDgnFile)
    assert not displayRuleSetFail

    dgnFile = SaveCloseAndReopenFile(srcDgnFile)

    displayRuleSetVector = DisplayRulesManager.GetDisplayRuleSetsInFile(dgnFile)
    assert 2 == displayRuleSetVector.__len__()

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("Renamed0", dgnFile)
    assert displayRuleSetCP0FromFile
    CompareDisplayRuleSetsProperties(displayRuleSet0Clone, displayRuleSetCP0FromFile)

    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("Renamed1", dgnFile)
    assert displayRuleSetCP1FromFile
    CompareDisplayRuleSetsProperties(displayRuleSet1Clone, displayRuleSetCP1FromFile)

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", dgnFile)
    assert not displayRuleSetCP0FromFile
    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet1", dgnFile)
    assert not displayRuleSetCP1FromFile
    TearDown()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RemoveDisplayRuleSetFromFile(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global m_displayRuleSet0, m_displayRuleSet1
    srcDgnFile = createTempDgnFileFromSeed(loadDgnFile)
    SetUpOverride(srcDgnFile)

    displayRuleSetCP0 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet0, srcDgnFile, False)
    assert displayRuleSetCP0
    displayRuleSetCP1 = DisplayRulesManager.WriteDisplayRuleSetToFile(m_displayRuleSet1, srcDgnFile, False)
    assert displayRuleSetCP1

    DisplayRulesManager.RemoveDisplayRuleSetFromFile("RuleSet0", srcDgnFile)

    displayRuleSetVector = DisplayRulesManager.GetDisplayRuleSetsInFile(srcDgnFile)
    assert 1 == displayRuleSetVector.__len__()

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", srcDgnFile)
    assert not displayRuleSetCP0FromFile
    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet1", srcDgnFile)
    assert displayRuleSetCP1FromFile
    assert displayRuleSetCP1FromFile == displayRuleSetCP1

    dgnFile = SaveCloseAndReopenFile(srcDgnFile)

    displayRuleSetVector = DisplayRulesManager.GetDisplayRuleSetsInFile(dgnFile)
    assert 1 == displayRuleSetVector.__len__()

    displayRuleSetCP0FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet0", dgnFile)
    assert not displayRuleSetCP0FromFile
    displayRuleSetCP1FromFile = DisplayRulesManager.GetDisplayRuleSetByName("RuleSet1", dgnFile)
    assert displayRuleSetCP1FromFile
    CompareDisplayRuleSetsProperties(m_displayRuleSet1, displayRuleSetCP1FromFile)
    TearDown()
   