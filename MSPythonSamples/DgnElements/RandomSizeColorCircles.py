# Script Description and Usage Instructions
# What This Script Does
# This script allows you to fill a closed, planar region (such as a shape, rectangle, or circle) in a MicroStation DGN model with randomly placed, non-overlapping filled circles. The script:
# 1.	Prompts you to select a closed shape element in the active model.
# 2.	Floods the selected region to ensure a valid, planar, closed area for circle placement.
# 3.	Estimates the maximum possible circle diameter that can fit inside the region.
# 4.	Prompts you for minimum and maximum circle diameters (with suggestions based on the region size).
# 5.	Prompts you for the approximate number of circles to place (suggested based on region area and packing density).
# 6.	Randomly places filled circles within the region, ensuring no overlaps and that all circles are fully inside the boundary.
# 7.	Assigns a random color to each circle and adds them as filled ellipses to the active DGN model.
#  
# How To Use This Script
# 1.	Open your DGN file in MicroStation.
# 2.	Select a closed, planar shape element (such as a rectangle, circle, or closed shape) in the active model. 
# ○	The script works best with simple, closed shapes. If you have trouble, try selecting a rectangle or circle.
# 3.	Run the script in the MicroStation Python environment.
# 4.	Follow the prompts:
# ○	You will be asked to enter minimum and maximum circle diameters (in master units).
# ○	You will be asked for the approximate number of circles to place.
# 5.	Wait for the script to finish.
# ○	The script will attempt to fill the region with as many non-overlapping circles as possible, within the specified size range.
# ○	Each circle will be filled and colored randomly.
# 6.	Review the results in your DGN model. The script will print the number of circles placed.
#  
# Notes and Tips
# ○	Selection: The script uses the first element in the current selection set. Make sure only the desired shape is selected.
# ○	Shape Requirements: The selected element must be a closed, planar region (e.g., a shape, closed linestring, or circle). Open elements or non-planar shapes will be rejected.
# ○	Flooding: The script uses a flood operation to ensure the region is valid for circle packing.
# ○	Circle Placement: Circles are placed randomly and may not achieve perfect packing. If the region is very small or the minimum diameter is too large, few or no circles may be placed.
# ○	Colors: Circles are filled and colored using random color indices between 0 and 10.
# ○	User Input: All user prompts use simple dialog boxes (via tkinter). Canceling any prompt will abort the operation.
#  
# Troubleshooting
# ○	If no circles are placed, check that:
# ○	The selected shape is closed and planar.
# ○	The minimum diameter is not too large for the region.
# ○	The region is not too small or oddly shaped.
# ○	If you encounter errors, try with a simple rectangle or circle to confirm the script works in your environment.

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import random
import math
import tkinter as tk
from tkinter import simpledialog

# Check if two circles overlap based on their centers and radii
def circles_overlap(center1, radius1, center2, radius2):
    dx = center1.x - center2.x
    dy = center1.y - center2.y
    dz = center1.z - center2.z
    dist_sq = dx*dx + dy*dy + dz*dz
    min_dist = radius1 + radius2
    return dist_sq < (min_dist * min_dist)

# Retrieve the first selected shape element as a CurveVector and its handle
def get_shape_curvevector_from_selection():
    selSetManager = SelectionSetManager.GetManager()
    nSelected = selSetManager.NumSelected()
    if nSelected == 0:
        print("Please select a shape element before running this script.")
        return None, None
    elementHandle = EditElementHandle()
    selSetManager.GetElement(0, elementHandle)
    curve_vector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    if curve_vector is not None:
        print("CurveVector Info:")
        try:
            is_closed = curve_vector.IsClosedPath()
        except Exception as e:
            print("  Error checking IsClosedPath:", e)
            is_closed = None
        print("  IsClosedPath:\n ", is_closed)
        try:
            localToWorld = Transform()
            worldToLocal = Transform()
            drange = DRange3d()
            is_planar = curve_vector.IsPlanar(localToWorld, worldToLocal, drange)
        except Exception as e:
            print("  Error checking IsPlanar:", e)
            is_planar = None
        print("  IsPlanar:\n ", is_planar)
        try:
            boundary_type = curve_vector.GetBoundaryType()
        except Exception as e:
            print("  Error checking BoundaryType:", e)
            boundary_type = None
        print("  BoundaryType:\n ", boundary_type)
        try:
            n_lines = curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line)
        except Exception as e:
            print("  Error counting Line primitives:", e)
            n_lines = None
        print("  Primitive count (Line):\n ", n_lines)
        try:
            n_arcs = curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Arc)
        except Exception as e:
            print("  Error counting Arc primitives:", e)
            n_arcs = None
        print("  Primitive count (Arc):\n ", n_arcs)
        try:
            n_linestrings = curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString)
        except Exception as e:
            print("  Error counting LineString primitives:", e)
            n_linestrings = None
        print("  Primitive count (LineString):\n ", n_linestrings)
        # Print primitive types for debugging
        try:
            print("  Primitive types in CurveVector:")
            for i, prim in enumerate(curve_vector):
                try:
                    prim_type = prim.GetCurvePrimitiveType()
                    print(f"    Primitive {i}: type={prim_type}")
                except Exception as e:
                    print(f"    Primitive {i}: Error getting type: {e}")
        except Exception as e:
            print("  Error iterating CurveVector primitives:", e)
    # Ensure the element is a closed, planar region suitable for flooding
    if curve_vector is None or not (hasattr(curve_vector, "IsClosedPath") and curve_vector.IsClosedPath()):
        print("Selected element is not a closed shape.")
        return None, None
    try:
        localToWorld = Transform()
        worldToLocal = Transform()
        drange = DRange3d()
        is_planar = curve_vector.IsPlanar(localToWorld, worldToLocal, drange)
        if not is_planar:
            print("Selected shape is not planar.")
            return None, None
    except Exception as e:
        print("Could not check planarity:", e)
    try:
        boundary_type = curve_vector.GetBoundaryType()
        if boundary_type not in [
            CurveVector.eBOUNDARY_TYPE_Outer,
            CurveVector.eBOUNDARY_TYPE_ParityRegion,
            CurveVector.eBOUNDARY_TYPE_UnionRegion
        ]:
            print("Selected shape is not a valid region type.")
            return None, None
    except Exception as e:
        print("Could not check boundary type:", e)
        return None, None
    return curve_vector, elementHandle

# Compute the area of a shape from its CurveVector
def get_shape_area(curve_vector):
    # Try CentroidAreaXY first
    try:
        success, centroid, area = curve_vector.CentroidAreaXY()
    except Exception as e:
        print("Error computing area with CentroidAreaXY:", e)
        success, area = False, None
    # If CentroidAreaXY fails, try to convert LineString to a closed region
    if not success or area is None or area <= 0.0:
        # Try to "close" a LineString if that's the only primitive
        try:
            n_linestrings = curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString)
            if n_linestrings == 1 and curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line) == 0:
                print("Attempting to close LineString as region for area calculation...")
                prim = next(iter(curve_vector))
                points = prim.GetLineString()
                # Check if already closed
                if points[0] != points[-1]:
                    points.append(points[0])
                closed_cv = CurveVector.CreateLinear(points, CurveVector.eBOUNDARY_TYPE_Outer, True)
                try:
                    success, centroid, area = closed_cv.CentroidAreaXY()
                except Exception as e:
                    print("Error computing area with closed LineString:", e)
                    success, area = False, None
                if success and area > 0.0:
                    print("Area computed after closing LineString.")
                    return area
        except Exception as e:
            print("Error attempting to close LineString:", e)
        print("Could not determine area of the selected shape.")
        return None
    return area

# Estimate the maximum possible diameter for a circle to fit inside the region
def estimate_maximum_diameter(region_cv):
    drange = DRange3d()
    region_cv.GetRange(drange)
    width = drange.high.x - drange.low.x
    height = drange.high.y - drange.low.y
    max_diameter = min(width, height)
    return max(0.0, max_diameter)

# Prompt the user for minimum and maximum circle diameters, with bounds
def ask_user_min_max_diameter_with_bounds(default_min, default_max, max_allowed):
    root = tk.Tk()
    root.withdraw()
    min_dia = simpledialog.askfloat(
        "Minimum Diameter",
        f"Enter minimum circle diameter (suggested: {default_min:.3f}, max allowed: {max_allowed:.3f}):",
        minvalue=0.0, maxvalue=max_allowed, initialvalue=default_min
    )
    if min_dia is None:
        root.destroy()
        return None, None
    max_dia = simpledialog.askfloat(
        "Maximum Diameter",
        f"Enter maximum circle diameter (suggested: {default_max:.3f}, max allowed: {max_allowed:.3f}):",
        minvalue=min_dia, maxvalue=max_allowed, initialvalue=default_max
    )
    root.destroy()
    if max_dia is None:
        return None, None
    return min_dia, max_dia

# Get the first element from an agenda (utility function)
def get_first_agenda_elem(agenda):
    it = iter(agenda)
    try:
        return next(it)
    except StopIteration:
        return None

# Perform a flood operation to get a region CurveVector from a shape element
def get_flood_region_curvevector(elementHandle):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    model = ACTIVEMODEL.GetDgnModel()
    agenda = ElementAgenda()
    agenda.Insert(elementHandle)
    region_context = RegionGraphicsContext.Create()
    curve_vector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    try:
        success, centroid, _ = curve_vector.CentroidAreaXY()
    except Exception as e:
        print("Error getting centroid for flood seed:", e)
        return None, None
    if not success:
        print("Failed to get centroid for flood seed.")
        return None, None
    seed_points = DPoint3dArray()
    seed_points.append(centroid)
    transform = Transform()
    transform.InitIdentity()
    status = region_context.Flood(model, agenda, transform, seed_points)
    if status != BentleyStatus.eSUCCESS or agenda.GetCount() == 0:
        print("Flood operation failed or returned no region.")
        return None, None
    region_eeh = get_first_agenda_elem(agenda)
    if region_eeh is None:
        print("Flood operation did not return a valid region element.")
        return None, None
    region_cv = ICurvePathQuery.ElementToCurveVector(region_eeh)
    return region_cv, region_eeh

# Extract polygon points from a CurveVector for point-in-polygon tests
def get_polygon_points_from_curvevector(curve_vector):
    polygon = []
    for prim in curve_vector:
        if hasattr(prim, "GetLineString"):
            try:
                points = prim.GetLineString()
            except Exception as e:
                print("Error getting linestring points:", e)
                continue
            if len(points) > 2:
                for pt in points:
                    polygon.append((pt.x, pt.y))
                if polygon and polygon[0] != polygon[-1]:
                    polygon.append(polygon[0])
                return polygon
        elif hasattr(prim, "TryGetLine"):
            seg = DSegment3d()
            try:
                if prim.TryGetLine(seg):
                    polygon.append((seg.point[0].x, seg.point[0].y))
            except Exception as e:
                print("Error getting line segment:", e)
    if len(polygon) > 2 and polygon[0] != polygon[-1]:
        polygon.append(polygon[0])
    if polygon:
        return polygon
    for prim in curve_vector:
        if hasattr(prim, "GetArc"):
            try:
                arc = prim.GetArc()
                num_pts = 36
                for j in range(num_pts):
                    frac = j / float(num_pts)
                    pt = DPoint3d()
                    arc.FractionToPoint(frac, pt)
                    polygon.append((pt.x, pt.y))
                if polygon and polygon[0] != polygon[-1]:
                    polygon.append(polygon[0])
                return polygon
            except Exception as e:
                print("Error getting arc points:", e)
    return polygon

# Determine if a 2D point is inside a polygon (ray-casting algorithm)
def is_point_inside_polygon(point, polygon):
    x, y = point
    inside = False
    n = len(polygon)
    for i in range(n):
        x1, y1 = polygon[i]
        x2, y2 = polygon[(i + 1) % n]
        if ((y1 > y) != (y2 > y)) and (x < (x2 - x1) * (y - y1) / (y2 - y1 + 1e-12) + x1):
            inside = not inside
    return inside

# Get the bounding range of a region CurveVector
def get_region_range(region_cv):
    drange = DRange3d()
    region_cv.GetRange(drange)
    return drange

# Check if a circle (center, radius) is fully within a polygon by sampling points on its circumference
def is_circle_fully_within_polygon(center, radius, polygon, n_check=24):
    for i in range(n_check):
        angle = 2 * math.pi * i / n_check
        x = center.x + radius * math.cos(angle)
        y = center.y + radius * math.sin(angle)
        if not is_point_inside_polygon((x, y), polygon):
            return False
    return True

# Generate a random point inside the polygon such that a circle of given radius is fully inside
def generate_random_point_in_polygon_fully_inside(polygon, drange, radius, max_tries=1000):
    for _ in range(max_tries):
        x = random.uniform(drange.low.x + radius, drange.high.x - radius)
        y = random.uniform(drange.low.y + radius, drange.high.y - radius)
        if is_point_inside_polygon((x, y), polygon):
            center = DPoint3d(x, y, 0.0)
            if is_circle_fully_within_polygon(center, radius, polygon):
                return center
    return None

# Ask the user for the approximate number of circles to place
def ask_user_approximate_count(default_count):
    root = tk.Tk()
    root.withdraw()
    n_circles = simpledialog.askinteger(
        "Input",
        f"Approximate number of circles to place (suggested: {default_count}):",
        minvalue=1, maxvalue=default_count*3 if default_count > 0 else 100
    )
    root.destroy()
    return n_circles

# Main function to place circles in the region CurveVector
def place_circles_in_region(region_cv, n_circles, min_radius, max_radius, color_min=0, color_max=10):
    drange = get_region_range(region_cv)
    polygon = get_polygon_points_from_curvevector(region_cv)
    if not polygon:
        print("Could not extract polygon points from flooded region.")
        return

    circles = []
    max_attempts = 10000
    attempts = 0
    radii_list = [random.uniform(min_radius, max_radius) for _ in range(n_circles)]
    random.shuffle(radii_list)
    for radius in radii_list:
        found = False
        for _ in range(300):
            candidate = generate_random_point_in_polygon_fully_inside(polygon, drange, radius)
            if candidate is None:
                continue
            overlap = False
            for (other_center, other_radius) in circles:
                if circles_overlap(candidate, radius, other_center, other_radius):
                    overlap = True
                    break
            if not overlap:
                circles.append((candidate, radius))
                found = True
                break
        if not found:
            continue
        attempts += 1
        if attempts > max_attempts:
            break

    if len(circles) == 0:
        print("No circles could be placed in the flooded region. This may be because the region is too small, the minimum circle area is too large, or the region is not suitable for circle packing.")
        return

    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    for (center, radius) in circles:
        ell = DEllipse3d.FromCenterRadiusXY(center, radius)
        eeh = EditElementHandle()
        status = EllipseHandler.CreateEllipseElement(eeh, None, ell, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            print("Failed to create ellipse element.")
            continue

        color = random.randint(color_min, color_max)
        # Set color and fill color using ElementPropertiesSetter
        propSetter = ElementPropertiesSetter()
        propSetter.SetColor(color)
        propSetter.SetFillColor(color)
        propSetter.Apply(eeh)

        handler = eeh.GetHandler()
        if handler is not None:
            handler.AddSolidFill(eeh, color, True)
        else:
            print("Could not get EllipseHandler for element.")

        status = eeh.AddToModel()
        if BentleyStatus.eSUCCESS != status:
            print("Failed to add ellipse element to model.")
    print(f"Placed {len(circles)} filled circles in the flooded region.")

# Main script entry point
if __name__ == "__main__":
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        print("No active DGN model found.")
    else:
        print("Tip: If you have trouble, try selecting a simple rectangle or circle to test if the script works with basic shapes.")
        curve_vector, elementHandle = get_shape_curvevector_from_selection()
        if curve_vector is not None and elementHandle is not None:
            area = get_shape_area(curve_vector)
            if area is None:
                exit()
            region_cv, region_eeh = get_flood_region_curvevector(elementHandle)
            if region_cv is not None and region_eeh is not None:
                max_allowed_diameter = estimate_maximum_diameter(region_cv)
                min_circle_area = 0.05 * area
                max_circle_area = 0.15 * area
                min_radius_default = math.sqrt(min_circle_area / math.pi)
                max_radius_default = math.sqrt(max_circle_area / math.pi)
                default_min_dia = min(2 * min_radius_default, max_allowed_diameter)
                default_max_dia = min(2 * max_radius_default, max_allowed_diameter)
                min_dia, max_dia = ask_user_min_max_diameter_with_bounds(
                    default_min_dia, default_max_dia, max_allowed_diameter
                )
                if min_dia is None or max_dia is None or min_dia <= 0 or max_dia < min_dia:
                    print("User cancelled or entered invalid diameters. No circles were placed.")
                else:
                    min_radius = min_dia / 2.0
                    max_radius = max_dia / 2.0
                    avg_area = math.pi * ((min_radius + max_radius) / 2.0) ** 2
                    packing_density = 0.785
                    region_area = get_shape_area(region_cv)
                    default_count = int((region_area * packing_density) / avg_area)
                    if default_count < 1:
                        default_count = 1
                    n_circles = ask_user_approximate_count(default_count)
                    if n_circles is None or n_circles < 1:
                        print("User cancelled or entered an invalid number. No circles were placed.")
                    else:
                        place_circles_in_region(
                            region_cv,
                            n_circles=n_circles,
                            min_radius=min_radius,
                            max_radius=max_radius,
                            color_min=0,
                            color_max=10
                        )