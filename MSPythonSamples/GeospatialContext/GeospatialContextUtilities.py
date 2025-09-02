from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

''' 
Example demonstrating how to Create a fence from a named boundary. 
'''

def CreateFenceFromNamedBoundary(boundary_name):
    """
    Create a fence from a named boundary.

    :param boundary_name: The name of the named boundary.
    :type boundary_name: str
    """

    existingBound = NamedBoundary.FindByName (WString (boundary_name), None, ISessionMgr.ActiveDgnModelRef)
    if existingBound is None:
        existingBound = NamedBoundary.FindOrphanByName (WString (boundary_name), ISessionMgr.ActiveDgnModelRef)    

    if existingBound is None:
        print(f"Named boundary {boundary_name} not found.")
        return

    eh = existingBound.GetGraphicalElement()
    
    FenceManager.GetManager().DefineByElement(eh, IViewManager.GetActiveViewSet().GetSelectedViewport())

def FitViewToNamedBoundary(boundary_name):
    """
    Fit the active view to a named boundary.

    :param boundary_name: The name of the named boundary.
    :type boundary_name: str
    """

    keyin = ""
    existingBound = NamedBoundary.FindByName (WString (boundary_name), None, ISessionMgr.ActiveDgnModelRef)
    if existingBound:
        print(f"Found boundary {boundary_name}")
        nbGroup = existingBound.ParentGroup
        if nbGroup:
            keyin = "NAMEDBOUNDARY FITVIEW \"" + str(existingBound.GetName()) + ":" + str(nbGroup.GetName()) + "\""
        else:
            keyin = "NAMEDBOUNDARY FITVIEW \"" + str(existingBound.GetName()) + "\""
    else:
        existingBound = NamedBoundary.FindOrphanByName (WString (boundary_name), ISessionMgr.ActiveDgnModelRef)
        if existingBound:
            keyin = "NAMEDBOUNDARY FITVIEW \"" + str(existingBound.GetName()) + "\""
    if keyin:
        PyCadInputQueue.SendKeyin (keyin)
        print(f"Fit view to boundary {boundary_name}. Keyin: {keyin}")

def FitActiveView():
    '''
    Fit active view

    :return: None
    :rtype: None
    '''
    
    vSet = IViewManager.GetActiveViewSet()  # Get the active view set
    if vSet is None:
        print(f"Failed to get ActiveViewSet.")
        return
    view_number = 1
    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if not viewport is None:
        view_number = viewport.GetViewNumber() # Get the active view index   

    keyin = "FIT VIEW EXTENDED " + str(view_number+1)
    PyCadInputQueue.SendKeyin (keyin)
    print(f"Sent keyin to fit view: {keyin}.")

def lat_long_to_dgn_units(lat, long):
    """
    Convert latitude and longitude to Dgn units.

    :param lat: Latitude value.
    :type lat: float
    :param long: Longitude value.
    :type long: float
    :return: Converted coordinates in dgn units.
    :rtype: tuple (x, y)
    """
    # Create a DPoint3d for the lat/long
    geo_point = GeoPoint()
    geo_point.Init(long, lat, 0)

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("Failed DgnGCS.FromModel.")
        return (0,0)       

    # Transform the geographic point to master units
    dgn_point = DPoint3d()
    status = dgnGCS.UorsFromLatLong(dgn_point, geo_point)
    
    if status != ReprojectStatus.eREPROJECT_Success:
        print("Failed CartesianFromLatLong.")
        return (0,0)

    return (dgn_point.x, dgn_point.y)

def CreateNamedBoundary(boundary_name, boundary_coordinates):
    """
    Create a named boundary in the active DGN model.

    :param boundary_name: The name of the boundary to create.
    :type boundary_name: str
    :param boundary_coordinates: The coordinates of the boundary in lat/long.
    :type boundary_coordinates: list of tuples (lat, long)
    :return: True if the boundary was created successfully, False otherwise.
    :rtype: bool
    """
    points = DPoint3dArray()
    for coord in boundary_coordinates:
        dgn_units = lat_long_to_dgn_units(coord[0], coord[1])
        point = DPoint3d(dgn_units[0], dgn_units[1], 0)
        points.append(point)

    eeh = EditElementHandle()
    status = ShapeHandler.CreateShapeElement(eeh, None, points, ISessionMgr.ActiveDgnModelRef.Is3d(), ISessionMgr.ActiveDgnModelRef)
    if BentleyStatus.eSUCCESS != status:
        print("Failed to create polygon element.")
        return False
    print("Polygon element created successfully.")

    # Add the polygon to the active model
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        print("Failed to add polygon element to the active model.")
        return False
    print("Polygon element added to the active model.")

    # Create the named boundary
    boundary = NamedBoundary.Create()
    if not boundary:
        print("Failed to create named boundary.")    
        return False
    boundary.SetName(WString(boundary_name))
    boundary.SetGraphicalElement(eeh)
    boundary.SetModelRef(ISessionMgr.ActiveDgnModelRef)
    boundary.Save()
    print(f"Named boundary '{boundary_name}' created successfully.")
    return True

def ApplyDisplayStyleToActiveView(display_style_name):
    """
    Apply a display style to the active view.

    :param display_style_name: The name of the display style to apply.
    :type display_style_name: str

    """
    dgn_file = ISessionMgr.ActiveDgnFile
    if not dgn_file:
        print("Failed to get active DGN file.")
        return    

    dsList = DisplayStyleList(dgn_file, eDISPLAY_STYLE_LIST_OPTIONS_IncludeAll)
    if dsList is None:
        print("Failed to get DisplayStyleList.")
        return

    dStyle = dsList.FindDisplayStyleByName (display_style_name)
    if dStyle is None:
        print(f"Failed to get DisplayStyle {display_style_name}.")
        return

    # Apply the display style to the active view
    vSet = IViewManager.GetActiveViewSet()  # Get the active view set
    if vSet is None:
        print(f"Failed to get ActiveViewSet.")
        return
    viewport = vSet.GetSelectedViewport()   # Get the selected viewport from the view set
    viewInfo = viewport.GetViewInfo()   # Get information about the viewport
    DisplayStyleManager.ApplyDisplayStyleToView (dStyle, viewInfo)

def CreateExampleProjectArea(boundary_name):
    '''
    Create a named boundary for the project area around SE 17th Street Causeway Bridge in Fort Lauderdale, Florida.

    :param boundary_name: The name of the boundary.
    :type boundary_name: str
    :return: True if the named boundary is successfully created, False otherwise.
    :rtype: bool
    '''

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        return False        

    existingBound = NamedBoundary.FindByName(WString(boundary_name), None, ISessionMgr.ActiveDgnModelRef)
    if existingBound is None:
        existingBound = NamedBoundary.FindOrphanByName(WString(boundary_name), ISessionMgr.ActiveDgnModelRef)
    
    boundary_result = True
    if existingBound is None:
        # Approximate Lat/Lon bounding box coordinates for SE 17th Street Causeway Bridge, Fort Lauderdale, Florida
        boundary_coordinates = [
            (26.107, -80.136),  # Northwest corner
            (26.107, -80.103),  # Northeast corner
            (26.093, -80.103),  # Southeast corner
            (26.093, -80.136),  # Southwest corner
            (26.107, -80.136)   # Closing the polygon
        ]
        boundary_result = CreateNamedBoundary(boundary_name, boundary_coordinates)        
    else:
        print(f"Named boundary '{boundary_name}' already exists.")
    return boundary_result
    
if __name__ == "__main__":
    print("Script start...")

    FenceManager.GetManager().ClearFence()

    boundary_name = "ExampleProjectArea"
    boundary_result = CreateExampleProjectArea (boundary_name)
    if boundary_result == False:
        print(f"Failed to create named boundary {boundary_name}.")    
    else:
        if CreateFenceFromNamedBoundary(boundary_name) == False:
            print(f"Failed to create fence from named boundary {boundary_name}.")
        else:
            print(f"Created fence from named boundary {boundary_name}.")

    print("Script end...") 
