import os
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
    m_displayRule1 = None
    m_displayRule0 = None
    m_displayRuleSet1 = None
    m_displayRuleSet0 = None

def SetUpDisplayRules(loadDgnFile):
    m_displayRule0 = DisplayRule((WString)("element.DgnElementSchema::ShapeElement::EnclosedArea>2000000000"), True, loadDgnFile)
    m_displayRule1 = DisplayRule((WString)("element.DgnElementSchema::ShapeElement::EnclosedArea>1000000000"), False, loadDgnFile)

def SetUpDisplayRuleSets(loadDgnFile):
    m_displayRuleSet0 = DisplayRuleSet((WString)("RuleSet0"), loadDgnFile)
    m_displayRuleSet1 = DisplayRuleSet((WString)("RuleSet1"), loadDgnFile)

def SetStartingActions(loadDgnFile):
    m_actionElementDisplay = ElementDisplayAction(False)
    m_actionColorOverride = ColorOverrideAction(3, loadDgnFile)
    m_actionFillColorOverride = FillColorOverrideAction(3, loadDgnFile)
    m_actionStyleOverride = StyleOverrideAction(3, loadDgnFile)
    m_actionWeightOverride = WeightOverrideAction(5)
    m_actionTransparencyOverride = TransparencyOverrideAction(0.8)
    m_actionElementPriorityOverride = ElementPriorityAction(1)
    m_actionDisplayStyleOverride = DisplayStyleOverrideAction(1, loadDgnFile)
    m_actionAreaHatch = AreaHatchAction(AreaHatchAction.HatchParams (1, 1,None, None, False, None, None, None), loadDgnFile)
    m_actionAreaPattern = AreaPatternAction(AreaPatternAction.AreaPatternParams(0, 0.8, False, None, None, None, None), loadDgnFile)

def SetActions (displayRule_0):
    a = displayRule_0.GetActions()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetSetDisplayRuleSetTests(initDgnPlatformHost, loadDgnFile):
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

#ToDo: Complete the further tests
@pytest.mark.skip(reason="NEEDS WORK: Fix Me")    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayRuleSetCloneAndEquals(initDgnPlatformHost, loadDgnFile):
    SetUp(loadDgnFile)
    SetStartingActions(loadDgnFile)
    SetActions(m_displayRule0)
   