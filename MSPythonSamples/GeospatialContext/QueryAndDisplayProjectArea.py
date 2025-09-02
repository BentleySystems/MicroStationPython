from MSPyBentley import *    
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from GeospatialContextConnection import *
from QueryServerConnection import *
from GeospatialContextUtilities import *

'''
Example showing Geospatial Context query and display of a project area in Fort Lauderdale, Florida.

1. Ensure that Geographic Coordinate System is set in active model
2. Create a named boundary from lat/long bounding box around Fort Lauderdale, Florida
3. Connect to Esri ArcGIS™ server URL: https://ca.dep.state.fl.us/arcgis/rest/services/OpenData/STATEWIDE_LU_2004_2013/MapServer/3
4. Query features from the server within the named boundary
5. Create a display rule set with display rules to display areas in two colors:
    a. Green - Areas suitable for infrastructure
    b. Red - Areas to be preserved
6. Create a display style that uses the display rule set
7. Assign the display style to the current view
8. Fit the named boundary in the view
'''

''' Get or create a display rule set with two rules. '''
def getOrCreate_display_rule(ruleSetName):
    '''
    Create a display rule set with two rules:
        Green - Areas suitable for infrastructure
        Red - Areas to be preserved
        
        Determined by LDI & LSI property values.

        For example, the area is highly developed and dominated by human activities (LDI) and the landscape has a low capacity to support ecological functions (LSI), so the parcel is physically suitable for infrastructure expansion or upgrades.    
        	LDI: 8.7000
        	LSI: 1.5000        

        :param ruleSetName: The name of the display rule set.
        :type ruleSetName: str
        :return: The display rule set.
        :rtype: DisplayRuleSet
    '''
    dgn_file = ISessionMgr.ActiveDgnFile
    if not dgn_file:
        print("Failed to get active DGN file.")
        return None

    displayRuleSetFromFile = DisplayRulesManager.GetDisplayRuleSetByName(ruleSetName, dgn_file)
    if displayRuleSetFromFile:
        print (f"Display rule set \"{ruleSetName}\" already exists.")
        return displayRuleSetFromFile

    # Create a new display rule set
    displayRuleSet = DisplayRuleSet((WString)(ruleSetName), dgn_file)
    if not displayRuleSet:
        print("Failed to create displayRuleSet.")
        return None

    # Add RED display rule - Areas to be preserved
    displayRule = DisplayRule(WString("Red rule"), True, dgn_file)
    if not displayRule:
        print("Failed to create DisplayRule(RED).")
        return None

    displayRule.SetStopIfTrue(True)
    displayRule.SetIsEnabled(True)

    # Set the condition for the DisplayRule
    displayRule.SetCondition(WString("element.DgnCustomItemTypes_OpenData_STATEWIDE_LU_2004_2013::Current__x0020__Landuse__x0020____x002D____x0020__Landscape__x0020__Development__x0020__Intensity__x0020____x0028__LDI__x0029____x0020__Map::LDI<7.0 AndAlso element.DgnCustomItemTypes_OpenData_STATEWIDE_LU_2004_2013::Current__x0020__Landuse__x0020____x002D____x0020__Landscape__x0020__Development__x0020__Intensity__x0020____x0028__LDI__x0029____x0020__Map::LSI>3.0"))
    displayRule.SetConditionDescription(WString("ELEMENT.Current Landuse - Landscape Development Intensity (LDI) Map.LDI < 7.0000 AND ELEMENT.Current Landuse - Landscape Development Intensity (LDI) Map.LSI > 3.0000"))

    actionColorOverride = ColorOverrideAction(3, dgn_file) # 3 is the color index for red
    if not actionColorOverride:
        print("Failed to create ColorOverrideAction.")
        return None

    actions = displayRule.GetActions()
    actions.clear()
    actions.append(actionColorOverride)
    displayRuleSet.GetDisplayRules().append(displayRule)

    # Add GREEN display rule - Areas suitable for infrastructure
    displayRule = DisplayRule(WString("Green rule"), True, dgn_file)
    if not displayRule:
        print("Failed to create DisplayRule(GREEN).")
        return None

    displayRule.SetStopIfTrue(True)
    displayRule.SetIsEnabled(True)

    # Set the condition for the DisplayRule
    displayRule.SetCondition(WString("element.DgnCustomItemTypes_OpenData_STATEWIDE_LU_2004_2013::Current__x0020__Landuse__x0020____x002D____x0020__Landscape__x0020__Development__x0020__Intensity__x0020____x0028__LDI__x0029____x0020__Map::LDI>=7.0 AndAlso element.DgnCustomItemTypes_OpenData_STATEWIDE_LU_2004_2013::Current__x0020__Landuse__x0020____x002D____x0020__Landscape__x0020__Development__x0020__Intensity__x0020____x0028__LDI__x0029____x0020__Map::LSI<=3.0"))
    displayRule.SetConditionDescription(WString("ELEMENT.Current Landuse - Landscape Development Intensity (LDI) Map.LDI >= 7.0000 AND ELEMENT.Current Landuse - Landscape Development Intensity (LDI) Map.LSI <= 3.0000"))

    actionColorOverride = ColorOverrideAction(2, dgn_file) # 2 is the color index for green
    if not actionColorOverride:
        print("Failed to create ColorOverrideAction.")
        return None

    actions = displayRule.GetActions()
    actions.clear()
    actions.append(actionColorOverride)
    displayRuleSet.GetDisplayRules().append(displayRule)

    displayRuleSet = DisplayRulesManager.WriteDisplayRuleSetToFile(displayRuleSet, dgn_file, False)
    
    return displayRuleSet

''' Get or create a display style using a display rule set. '''
def getOrCreateDisplayStyle (styleName, displayRuleSet):
    '''
    Get or create a display style using a display rule set.

    :param styleName: The name of the display style.
    :type styleName: str
    :param displayRuleSet: The display rule set.
    :type displayRuleSet: DisplayRuleSet
    :return: The display style.
    :rtype: DisplayStyle
    '''
    dgn_file = ISessionMgr.ActiveDgnFile
    if not dgn_file:
        print("Failed to get active DGN file.")
        return None    

    dsList = DisplayStyleList(dgn_file, eDISPLAY_STYLE_LIST_OPTIONS_IncludeAll)
    if dsList is None:
        print("Failed to get DisplayStyleList.")
        return None

    dStyle = dsList.FindDisplayStyleByName (styleName)
    if (dStyle is None):
        print(f"Display Style \"{styleName}\" not found.  Creating....")
        templateStyleName = "Smooth"
        smoothDStyle = dsList.FindDisplayStyleByName (templateStyleName)
        if smoothDStyle is None:
            vSet = IViewManager.GetActiveViewSet()  # Get the active view set
            if vSet is None:
                print(f"Failed to get ActiveViewSet.")
                return
            view_number = 1
            viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
            if not viewport is None:
                view_number = viewport.GetViewNumber() # Get the active view index        
            keyin = "CHANGE VIEW CUSTOM \"" + templateStyleName + "\"" + " " + str(view_number+1)
            PyCadInputQueue.SendKeyin (keyin)            
            print(f"Ensure template display style \"{templateStyleName}\" found in active dgn. Keyin: {keyin}")
            dsList = DisplayStyleList(dgn_file, eDISPLAY_STYLE_LIST_OPTIONS_IncludeAll)
            smoothDStyle = dsList.FindDisplayStyleByName (templateStyleName)
            if smoothDStyle is None:
                print(f"Failed to get {templateStyleName} display style.")
                return None

        dStyle = smoothDStyle.Clone(dgn_file, styleName)
        if dStyle is None:
            print(f"Failed to clone display style \"{templateStyleName}\".")
            return None

        DisplayRulesManager.SetDisplayRuleSetToDisplayStyle(displayRuleSet, dStyle)
        dStyle = DisplayStyleManager.WriteDisplayStyleToFile (dStyle, dgn_file)
    else:
        print(f"Display Style \"{styleName}\" already exists .")

    DisplayRulesManager.SetDisplayRuleSetToDisplayStyle(displayRuleSet, dStyle)

    return dStyle

''' Print display rule set information. '''    
def printDisplayRuleSet(ruleSetName):
    '''
    Print display rule set information.

    :param ruleSetName: The name of the display rule set.
    :type ruleSetName: str
    '''

    print(f"Rule set: {ruleSetName}")
    displayRuleSetFromFile = DisplayRulesManager.GetDisplayRuleSetByName(ruleSetName, ISessionMgr.ActiveDgnFile)
    if displayRuleSetFromFile:
        for i in range(displayRuleSetFromFile.GetDisplayRules().__len__()):
            ruleIter0 = displayRuleSetFromFile.GetDisplayRules()[i]
            print (f"Rule #{i}: Condition ", ruleIter0.GetCondition())
            print (f"Rule #{i}: Description ", ruleIter0.GetConditionDescription())


''' Query features to a project area by named boundary. '''
def queryProjectArea(boundary_name, clearAll = True):
    '''
    Query features to a project area by named boundary.

    :param boundary_name: The name of the boundary.
    :type boundary_name: str
    :param clearAll: True to clear all features, False to clear only the features for this connection.
    :type clearAll: bool
    :return: The number of features queried.
    :rtype: int

    '''

    url = "https://ca.dep.state.fl.us/arcgis/rest/services/OpenData/STATEWIDE_LU_2004_2013/MapServer/3"
    conn = GetArcGISConnection(url)
    if conn is not None:
        #conn.Show(WString("landuse"))
        
        if clearAll == True:
            # Clear all features for any connection...
            ConnectionManager.ClearAllFeatureInstances(eClearFeaturesAreaMode_All)
        else:
            # Clear all features for this connection...
            SetAllFeatureSelectedState(conn, True)
            clearConnections = ServerConnectionPtrArray()
            clearConnections.push_back (conn)
            status, nCleared = ConnectionManager.GetManager().ClearConnectionsFeatureInstances (eClearFeaturesAreaMode_All, clearConnections)

        boundary_result = createProjectArea ("FortLauderdaleBoundary")
        if boundary_result == False:
            print("Failed to create named boundary.")
            return 0

        # Query by named boundary...
        nQueried = QueryServerConnectionByNamedBoundary(conn, boundary_name, "Current Landuse - Landscape Development Intensity (LDI) Map")   
        return nQueried
    else:
        print("Connection failed...") 
        return 0

''' Create a named boundary for the project area in  Fort Lauderdale, Florida '''
def createProjectArea(boundary_name):
    '''
    Create a named boundary for the project area in Fort Lauderdale, Florida.

    :param boundary_name: The name of the boundary.
    :type boundary_name: str
    :return: True if the named boundary is successfully created, False otherwise.
    :rtype: bool
    '''

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        return False        

    existingBound = NamedBoundary.FindByName (WString (boundary_name), None, ISessionMgr.ActiveDgnModelRef)
    if existingBound is None:
        existingBound = NamedBoundary.FindOrphanByName (WString (boundary_name), ISessionMgr.ActiveDgnModelRef)

    boundary_result = True
    if existingBound is None:
    # Approximate Lat/Lon bounding box coordinates for Fort Lauderdale, Florida
        boundary_coordinates = [
            (26.1224, -80.1373),  # Northwest corner
            (26.1224, -80.1045),  # Northeast corner
            (26.0842, -80.1045),  # Southeast corner
            (26.0842, -80.1373),  # Southwest corner
            (26.1224, -80.1373)   # Closing the polygon
        ]
        boundary_result = CreateNamedBoundary(boundary_name, boundary_coordinates)        
    else:
        print(f"Named boundary '{boundary_name}' already exists.")
    return boundary_result

''' Display the project area in Fort Lauderdale, Florida '''
def displayProjectArea(boundary_name):
    '''
    Display the project area in Fort Lauderdale, Florida.

    :param boundary_name: The name of the boundary.
    :type boundary_name: str
    '''

    ruleSetName = "feasible Land construction"
    #printDisplayRuleSet (ruleSetName)
    printDisplayRuleSet ("CCfeasible Land construction")

    print(f"Getting display rule set \"{ruleSetName}\".")
    displayRuleSet = getOrCreate_display_rule(ruleSetName)
    if (displayRuleSet is None):
        print(f"Failed to get or create display rule set \"{ruleSetName}\".")
        return
    else:
        print(f"Found display rule set \"{ruleSetName}\".")

    displayStyleName = "feasibleLand"
    print(f"Getting display style \"{displayStyleName}\".")
    dStyle = getOrCreateDisplayStyle(displayStyleName, displayRuleSet)
    #dStyle = None
    if (dStyle is None):
        print(f"Failed to get or create display style \"{displayStyleName}\".")
        return
    else:
        print(f"Found display style \"{displayStyleName}\".")

    ApplyDisplayStyleToActiveView(displayStyleName)

    FitViewToNamedBoundary(boundary_name)

# Example usage
if __name__ == "__main__":
    print("Script start...")

    # Ensure that Geographic Coordinate System is set in active model
    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        newGCS = DgnGCS.CreateGCS("EPSG:3857", ISessionMgr.ActiveDgnModelRef)
        if newGCS is None:
            print("No GCS in the active model.")
        else:
           newGCS.ToModel(ISessionMgr.ActiveDgnModelRef, True, True, True, True)

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if not dgnGCS is None:
        # Query Landuse features by named boundary
        boundary_name = "FortLauderdaleBoundary"
        nQueried = queryProjectArea(boundary_name, True)
        if nQueried != 0:
            displayProjectArea(boundary_name)
    
    print("Script end...")