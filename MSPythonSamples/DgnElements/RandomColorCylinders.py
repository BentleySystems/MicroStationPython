# -----------------------------------------------------------------------------
# RandomColorCircles9.py
#
# Description:
# This script allows users to select one or more closed, planar shapes in a
# MicroStation DGN model and fills each region with a specified number of
# randomly colored, non-overlapping circles. Each circle is placed fully
# inside the region, colored, and extruded as a solid. The user can specify
# minimum/maximum circle diameters and the number of circles via a Tkinter UI.
#
# Key Features:
# - Robust geometric helpers for region analysis and circle packing.
# - Efficient spatial indexing for overlap checks.
# - Tkinter dialog for user parameter input.
# - Works with arbitrary closed shapes (rectangles, circles, complex regions).
# - All geometry is written into the active DGN model.
#
# Usage:
# 1. Select one or more closed shapes in MicroStation.
# 2. Run this script.
# 3. Enter desired circle parameters in the dialog.
# 4. The script will fill the selected regions with colored, extruded circles.
# -----------------------------------------------------------------------------

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import random
import math
import tkinter as tk
from tkinter import ttk

# ---------------------------------------------------------------------------
# --- Geometry and Packing Helpers ---
# These functions and classes provide all the geometric calculations, 
# spatial indexing, and polygon/circle containment logic needed for 
# efficient and robust random circle packing within arbitrary closed regions.
# ---------------------------------------------------------------------------

def circles_overlap(center1, radius1, center2, radius2):
    """
    Returns True if two circles (in 3D, but only x/y used) overlap.
    Used for collision detection during circle packing.
    """
    dx = center1.x - center2.x
    dy = center1.y - center2.y
    dz = center1.z - center2.z
    dist_sq = dx*dx + dy*dy + dz*dz
    min_dist = radius1 + radius2
    return dist_sq < (min_dist * min_dist)

class CircleGridIndex:
    """
    A spatial grid index to accelerate overlap checks for circle packing.
    Circles are indexed by grid cell for efficient neighbor queries.
    """
    def __init__(self, drange, cell_size):
        self.cell_size = cell_size
        self.drange = drange
        self.grid = {}
        self.x0 = drange.low.x
        self.y0 = drange.low.y

    def _cell_coords(self, x, y):
        """
        Returns integer grid cell coordinates for a point.
        """
        ix = int((x - self.x0) // self.cell_size)
        iy = int((y - self.y0) // self.cell_size)
        return ix, iy

    def add(self, center, radius, obj):
        """
        Adds a circle to the grid index.
        """
        ix, iy = self._cell_coords(center.x, center.y)
        key = (ix, iy)
        if key not in self.grid:
            self.grid[key] = []
        self.grid[key].append((center, radius, obj))

    def nearby(self, center):
        """
        Yields all circles in neighboring grid cells (for overlap checks).
        """
        ix, iy = self._cell_coords(center.x, center.y)
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                key = (ix+dx, iy+dy)
                if key in self.grid:
                    for item in self.grid[key]:
                        yield item

def get_shape_curvevector_from_elementHandle(elementHandle):
    """
    Converts a MicroStation element to a planar, closed CurveVector if possible.
    Returns None if the element is not suitable for region packing.
    """
    curve_vector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    if curve_vector is None or not (hasattr(curve_vector, "IsClosedPath") and curve_vector.IsClosedPath()):
        return None
    try:
        localToWorld = Transform()
        worldToLocal = Transform()
        drange = DRange3d()
        is_planar = curve_vector.IsPlanar(localToWorld, worldToLocal, drange)
        if not is_planar:
            return None
    except Exception:
        return None
    try:
        boundary_type = curve_vector.GetBoundaryType()
        if boundary_type not in [
            CurveVector.eBOUNDARY_TYPE_Outer,
            CurveVector.eBOUNDARY_TYPE_ParityRegion,
            CurveVector.eBOUNDARY_TYPE_UnionRegion
        ]:
            return None
    except Exception:
        return None
    return curve_vector

def get_shape_area(curve_vector):
    """
    Attempts to compute the area of a CurveVector using several strategies.
    Returns area as a float, or None if area cannot be determined.
    """
    try:
        success, centroid, area = curve_vector.CentroidAreaXY()
        if success and area > 0.0:
            return area
    except Exception:
        pass
    try:
        cv_parity = CurveVector.AreaAnalysis(curve_vector, AreaSelect.eAreaSelect_Parity, BoolSelect.eBoolSelect_Union, False)
        if cv_parity is not None:
            success, centroid, area = cv_parity.CentroidAreaXY()
            if success and area > 0.0:
                return area
    except Exception:
        pass
    try:
        cv_outer = CurveVector.AreaAnalysis(curve_vector, AreaSelect.eAreaSelect_CCWPositiveWindingNumber, BoolSelect.eBoolSelect_Union, False)
        if cv_outer is not None:
            success, centroid, area = cv_outer.CentroidAreaXY()
            if success and area > 0.0:
                return area
    except Exception:
        pass
    try:
        total_area = 0.0
        for child in curve_vector:
            if hasattr(child, "GetChildCurveVector"):
                child_cv = child.GetChildCurveVector()
                if child_cv is not None:
                    a = get_shape_area(child_cv)
                    if a is not None and a > 0.0:
                        total_area += a
        if total_area > 0.0:
            return total_area
    except Exception:
        pass
    try:
        n_linestrings = curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString)
        if n_linestrings == 1 and curve_vector.CountPrimitivesOfType(ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line) == 0:
            prim = next(iter(curve_vector))
            points = prim.GetLineString()
            if points[0] != points[-1]:
                points.append(points[0])
            closed_cv = CurveVector.CreateLinear(points, CurveVector.eBOUNDARY_TYPE_Outer, True)
            success, centroid, area = closed_cv.CentroidAreaXY()
            if success and area > 0.0:
                return area
    except Exception:
        pass
    return None

def estimate_maximum_diameter(region_cv):
    """
    Estimates the largest possible circle diameter that fits in the region's bounding box.
    Used to limit user input for maximum circle size.
    """
    drange = DRange3d()
    region_cv.GetRange(drange)
    width = drange.high.x - drange.low.x
    height = drange.high.y - drange.low.y
    max_diameter = min(width, height)
    return max(0.0, max_diameter)

def get_first_agenda_elem(agenda):
    """
    Returns the first element from an ElementAgenda, or None if empty.
    """
    it = iter(agenda)
    try:
        return next(it)
    except StopIteration:
        return None

def get_flood_region_curvevector(elementHandle):
    """
    Floods a closed element to get a clean region CurveVector and its element handle.
    Returns (CurveVector, EditElementHandle) or (None, None) on failure.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    model = ACTIVEMODEL.GetDgnModel()
    agenda = ElementAgenda()
    agenda.Insert(elementHandle)
    region_context = RegionGraphicsContext.Create()
    curve_vector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    try:
        success, centroid, _ = curve_vector.CentroidAreaXY()
    except Exception:
        return None, None
    if not success:
        return None, None
    seed_points = DPoint3dArray()
    seed_points.append(centroid)
    transform = Transform()
    transform.InitIdentity()
    status = region_context.Flood(model, agenda, transform, seed_points)
    if status != BentleyStatus.eSUCCESS or agenda.GetCount() == 0:
        return None, None
    region_eeh = get_first_agenda_elem(agenda)
    if region_eeh is None:
        return None, None
    region_cv = ICurvePathQuery.ElementToCurveVector(region_eeh)
    return region_cv, region_eeh

def get_polygon_points_from_curvevector(curve_vector, stroke_tol=0.01, min_points=36):
    """
    Converts a CurveVector to a list of (x, y) tuples representing the polygon boundary.
    Used for point-in-polygon and containment checks.
    """
    polygons = []

    def stroke_primitive(prim):
        pts = []
        try:
            arr = DPoint3dArray()
            options = IFacetOptions.CreateForCurves()
            options.MaxEdgeLength = stroke_tol
            if hasattr(prim, "AddStrokes"):
                prim.AddStrokes(arr, options)
            if len(arr) < min_points and hasattr(prim, "AddStrokes"):
                prim.AddStrokes(arr)
            if len(arr) == 0 and hasattr(prim, "GetLineString"):
                arr = prim.GetLineString()
            for pt in arr:
                pts.append((pt.x, pt.y))
        except Exception:
            pass
        return pts

    def extract_points(cv):
        if cv is None:
            return
        btype = cv.GetBoundaryType() if hasattr(cv, "GetBoundaryType") else None
        if btype in (CurveVector.eBOUNDARY_TYPE_Outer, CurveVector.eBOUNDARY_TYPE_Open, CurveVector.eBOUNDARY_TYPE_None):
            poly = []
            for prim in cv:
                pts = stroke_primitive(prim)
                if pts:
                    if poly and pts[0] == poly[-1]:
                        pts = pts[1:]
                    poly.extend(pts)
                elif hasattr(prim, "GetChildCurveVector"):
                    child_cv = prim.GetChildCurveVector()
                    extract_points(child_cv)
            if poly and poly[0] != poly[-1]:
                poly.append(poly[0])
            if len(poly) >= 3:
                polygons.append(poly)
        else:
            for prim in cv:
                if hasattr(prim, "GetChildCurveVector"):
                    child_cv = prim.GetChildCurveVector()
                    extract_points(child_cv)

    extract_points(curve_vector)
    if polygons:
        polygons.sort(key=lambda poly: -abs(polygon_area(poly)))
        return polygons[0]
    return []

def polygon_area(poly):
    """
    Computes the signed area of a polygon (list of (x, y) tuples).
    """
    if not poly or len(poly) < 3:
        return 0.0
    area = 0.0
    n = len(poly)
    for i in range(n-1):
        x0, y0 = poly[i]
        x1, y1 = poly[i+1]
        area += (x0 * y1 - x1 * y0)
    return 0.5 * area

def is_point_inside_polygon(point, polygon):
    """
    Ray-casting algorithm for point-in-polygon test.
    Returns True if point is inside the polygon.
    """
    x, y = point
    inside = False
    n = len(polygon)
    for i in range(n):
        x1, y1 = polygon[i]
        x2, y2 = polygon[(i + 1) % n]
        if ((y1 > y) != (y2 > y)) and (x < (x2 - x1) * (y - y1) / (y2 - y1 + 1e-12) + x1):
            inside = not inside
    return inside

def get_region_range(region_cv):
    """
    Returns the DRange3d bounding box of a CurveVector.
    """
    drange = DRange3d()
    region_cv.GetRange(drange)
    return drange

def is_circle_fully_within_polygon(center, radius, polygon, n_check=24):
    """
    Checks if a circle is fully inside a polygon by sampling points on its circumference.
    Returns True if all sampled points are inside the polygon.
    """
    for i in range(n_check):
        angle = 2 * math.pi * i / n_check
        x = center.x + radius * math.cos(angle)
        y = center.y + radius * math.sin(angle)
        if not is_point_inside_polygon((x, y), polygon):
            return False
    return True

def generate_random_point_in_polygon_fully_inside(polygon, drange, radius, max_tries=100):
    """
    Attempts to generate a random point inside the polygon where a circle of given radius fits.
    Returns a DPoint3d or None if no suitable point is found.
    """
    for _ in range(max_tries):
        x = random.uniform(drange.low.x + radius, drange.high.x - radius)
        y = random.uniform(drange.low.y + radius, drange.high.y - radius)
        if is_point_inside_polygon((x, y), polygon):
            center = DPoint3d(x, y, 0.0)
            if is_circle_fully_within_polygon(center, radius, polygon):
                return center
    return None

def place_circles_in_region(region_cv, n_circles, min_radius, max_radius, color_min=224, color_max=235, extrude_height=None):
    """
    Main function to pack, color, and extrude circles in the given region.
    Circles are randomly placed, colored, and extruded as solids.
    """
    drange = get_region_range(region_cv)
    polygon = get_polygon_points_from_curvevector(region_cv)
    if not polygon or len(polygon) < 3:
        print("Could not extract polygon points from flooded region.")
        return

    # Generate a list of radii for the circles to be packed
    radii_list = [random.uniform(min_radius, max_radius) for _ in range(n_circles)]
    radii_list.sort(reverse=True)
    random.shuffle(radii_list)

    # Use a grid index for efficient overlap checking
    grid_cell_size = max_radius * 2
    grid_index = CircleGridIndex(drange, grid_cell_size)
    circles = []
    max_attempts = 10000
    attempts = 0

    # Try to place each circle randomly, checking for overlap and containment
    for radius in radii_list:
        found = False
        for _ in range(300):  # Increased attempts for tighter packing
            candidate = generate_random_point_in_polygon_fully_inside(polygon, drange, radius)
            if candidate is None:
                continue
            overlap = False
            for (other_center, other_radius, _) in grid_index.nearby(candidate):
                if circles_overlap(candidate, radius, other_center, other_radius):
                    overlap = True
                    break
            if not overlap:
                circles.append((candidate, radius))
                grid_index.add(candidate, radius, None)
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

    # Place each circle as a filled ellipse and extrude it as a solid in the DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    modelInfo = dgnModel.GetModelInfo()
    __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)

    for (center, radius) in circles:
        ell = DEllipse3d.FromCenterRadiusXY(center, radius)
        eeh = EditElementHandle()
        status = EllipseHandler.CreateEllipseElement(eeh, None, ell, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            print("Failed to create ellipse element.")
            continue

        color = random.randint(color_min, color_max)
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
            continue

        height = extrude_height if extrude_height is not None else radius
        if abs(height) < 1e-6:
            height = 1.0 * uorPerMast

        cv = CurveVector(CurveVector.eBOUNDARY_TYPE_Outer)
        cv.Add(ICurvePrimitive.CreateArc(ell))
        extrusionVec = DVec3d(0.0, 0.0, height)
        extrusionData = DgnExtrusionDetail(cv, extrusionVec, True)
        solid = ISolidPrimitive.CreateDgnExtrusion(extrusionData)
        solid_eeh = EditElementHandle()
        if BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement(solid_eeh, solid, None, ACTIVEMODEL):
            propSetter = ElementPropertiesSetter()
            propSetter.SetColor(color)
            propSetter.SetFillColor(color)
            propSetter.Apply(solid_eeh)
            solid_eeh.AddToModel()
        else:
            print("Failed to create solid extrusion for circle.")

    print(f"Placed {len(circles)} filled circles and extruded solids in the flooded region.")

# ---------------------------------------------------------------------------
# --- UI Dialog ---
# This section defines a tkinter-based dialog for user input of packing parameters.
# The dialog allows the user to set minimum/maximum circle diameter, number of circles,
# and displays the maximum allowed diameter for the selected region.
# ---------------------------------------------------------------------------

class CirclePackingDialog(tk.Tk):
    """
    Tkinter dialog for user input of circle packing parameters.
    Allows user to set min/max diameter, number of circles, and see region info.
    """
    def __init__(self, min_dia, max_dia, max_allowed, default_n_circles, uorPerMast, region_area, packing_density=0.785):
        super().__init__()
        self.title("Circle Packing Parameters")
        self.resizable(False, False)
        self.result = None
        self.uorPerMast = uorPerMast
        self.max_allowed_mast = int(round(max_allowed / uorPerMast))
        self.region_area = region_area
        self.packing_density = packing_density

        min_dia_mast = int(round(min_dia / uorPerMast))
        max_dia_mast = int(round(max_dia / uorPerMast))

        mainframe = ttk.Frame(self, padding="12 12 12 12")
        mainframe.grid(row=0, column=0, sticky="nsew")

        ttk.Label(mainframe, text="Minimum Diameter (master units):").grid(row=0, column=0, sticky="e", pady=2)
        self.min_dia_var = tk.StringVar(value=str(min_dia_mast))
        min_dia_entry = ttk.Entry(mainframe, textvariable=self.min_dia_var, width=10)
        min_dia_entry.grid(row=0, column=1, pady=2)

        ttk.Label(mainframe, text="Maximum Diameter (master units):").grid(row=1, column=0, sticky="e", pady=2)
        self.max_dia_var = tk.StringVar(value=str(max_dia_mast))
        max_dia_entry = ttk.Entry(mainframe, textvariable=self.max_dia_var, width=10)
        max_dia_entry.grid(row=1, column=1, pady=2)

        ttk.Label(mainframe, text=f"Maximum allowed diameter: {self.max_allowed_mast}").grid(row=2, column=0, columnspan=2, pady=(0, 8))

        ttk.Label(mainframe, text="Number of Circles:").grid(row=3, column=0, sticky="e", pady=2)
        self.n_circles_var = tk.StringVar(value=str(default_n_circles))
        n_circles_entry = ttk.Entry(mainframe, textvariable=self.n_circles_var, width=10)
        n_circles_entry.grid(row=3, column=1, pady=2)

        self.status_var = tk.StringVar(value="")
        ttk.Label(mainframe, textvariable=self.status_var, foreground="red").grid(row=4, column=0, columnspan=2, pady=(4, 0))

        self.tightest_var = tk.BooleanVar(value=True)
        ttk.Checkbutton(mainframe, text="Tightest Packing (max count, smallest circles)", variable=self.tightest_var, command=self.update_n_circles).grid(row=5, column=0, columnspan=2, pady=(4, 0))

        button_frame = ttk.Frame(mainframe, padding="0 8 0 0")
        button_frame.grid(row=6, column=0, columnspan=2, pady=(8, 0))
        ttk.Button(button_frame, text="OK", command=self.on_ok).grid(row=0, column=0, padx=6)
        ttk.Button(button_frame, text="Cancel", command=self.on_cancel).grid(row=0, column=1, padx=6)

        self.min_dia_var.trace_add("write", self.update_n_circles)
        self.max_dia_var.trace_add("write", self.update_n_circles)

        min_dia_entry.focus_set()
        self.attributes("-topmost", True)
        self.lift()
        self.focus_force()
        self.after(100, self._center_on_screen)

    def _center_on_screen(self):
        """
        Centers the dialog on the user's screen.
        """
        self.update_idletasks()
        w = self.winfo_width()
        h = self.winfo_height()
        screen_w = self.winfo_screenwidth()
        screen_h = self.winfo_screenheight()
        x = (screen_w // 2) - (w // 2)
        y = (screen_h // 2) - (h // 2)
        self.geometry(f"+{x}+{y}")

    def update_n_circles(self, *args):
        """
        Updates the suggested number of circles based on user input and region area.
        """
        try:
            min_dia = int(self.min_dia_var.get())
            max_dia = int(self.max_dia_var.get())
            if min_dia < 1 or max_dia < min_dia or max_dia > self.max_allowed_mast:
                self.status_var.set("Check diameters.")
                return
            min_radius = min_dia * self.uorPerMast / 2.0
            max_radius = max_dia * self.uorPerMast / 2.0
            if self.tightest_var.get():
                tightest_area = math.pi * (min_radius ** 2)
                default_count = int((self.region_area * self.packing_density) / tightest_area)
            else:
                avg_area = math.pi * ((min_radius + max_radius) / 2.0) ** 2
                default_count = int((self.region_area * self.packing_density) / avg_area)
            if default_count < 1:
                default_count = 1
            self.n_circles_var.set(str(default_count))
            self.status_var.set("")
        except Exception:
            self.status_var.set("Enter valid integers.")

    def on_ok(self):
        """
        Validates and returns the user's input when OK is pressed.
        """
        try:
            min_dia = int(self.min_dia_var.get())
            max_dia = int(self.max_dia_var.get())
            n_circles = int(self.n_circles_var.get())
            if min_dia < 1 or max_dia < min_dia or max_dia > self.max_allowed_mast or n_circles < 1:
                self.status_var.set("Invalid values. Please check your input.")
                return
            min_dia_uor = min_dia * self.uorPerMast
            max_dia_uor = max_dia * self.uorPerMast
            self.result = (min_dia_uor, max_dia_uor, n_circles)
            self.destroy()
        except Exception:
            self.status_var.set("Please enter valid integer values.")

    def on_cancel(self):
        """
        Cancels the dialog and returns None.
        """
        self.result = None
        self.destroy()

def get_circle_packing_parameters(default_min_dia, default_max_dia, max_allowed, default_n_circles, uorPerMast, region_area):
    """
    Shows the dialog and returns the user's chosen parameters.
    """
    dialog = CirclePackingDialog(default_min_dia, default_max_dia, max_allowed, default_n_circles, uorPerMast, region_area)
    dialog.mainloop()
    return dialog.result

def ask_circle_packing_parameters(default_min_dia, default_max_dia, max_allowed, default_n_circles, uorPerMast, region_area):
    """
    Wrapper for dialog invocation.
    """
    return get_circle_packing_parameters(default_min_dia, default_max_dia, max_allowed, default_n_circles, uorPerMast, region_area)

# ---------------------------------------------------------------------------
# --- Main Script Entry Point ---
# This is the main logic that runs when the script is executed.
# It checks for a valid selection, computes region and circle parameters,
# invokes the dialog, and then fills the region with circles and solids.
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        print("No active DGN model found.")
    else:
        dgnModel = ACTIVEMODEL.GetDgnModel()
        modelInfo = dgnModel.GetModelInfo()
        __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)
        selSetManager = SelectionSetManager.GetManager()
        nSelected = selSetManager.NumSelected()
        if nSelected == 0:
            print("Please select one or more closed shape elements before running this script.")
        else:
            print("Tip: If you have trouble, try selecting a simple rectangle or circle to test if the script works with basic shapes.")
            elementHandles = []
            for i in range(nSelected):
                eeh = EditElementHandle()
                selSetManager.GetElement(i, eeh)
                if not eeh.IsValid():
                    continue
                cv = get_shape_curvevector_from_elementHandle(eeh)
                if cv is not None:
                    elementHandles.append((eeh, cv))
            if not elementHandles:
                print("No valid closed, planar shapes found in selection.")
            else:
                first_cv = elementHandles[0][1]
                area = get_shape_area(first_cv)
                if area is None:
                    print("Could not determine area of the first selected shape.")
                    exit()
                region_cv, region_eeh = get_flood_region_curvevector(elementHandles[0][0])
                if region_cv is None or region_eeh is None:
                    print("Could not flood the first selected shape.")
                    exit()
                max_allowed_diameter = estimate_maximum_diameter(region_cv)
                min_circle_area = 0.05 * area
                max_circle_area = 0.15 * area
                min_radius_default = math.sqrt(min_circle_area / math.pi)
                max_radius_default = math.sqrt(max_circle_area / math.pi)
                default_min_dia = min(2 * min_radius_default, max_allowed_diameter)
                default_max_dia = min(2 * max_radius_default, max_allowed_diameter)
                packing_density = 0.785
                region_area = get_shape_area(region_cv)
                # Use smallest circle for tightest packing default
                tightest_area = math.pi * (min_radius_default ** 2)
                default_count = int((region_area * packing_density) / tightest_area)
                if default_count < 1:
                    default_count = 1

                params = ask_circle_packing_parameters(
                    default_min_dia, default_max_dia, max_allowed_diameter, default_count, uorPerMast, region_area
                )
                if params is None:
                    print("User cancelled or entered invalid values. No circles were placed.")
                else:
                    min_dia, max_dia, n_circles = params
                    min_radius = min_dia / 2.0
                    max_radius = max_dia / 2.0
                    for eeh, cv in elementHandles:
                        region_cv, region_eeh = get_flood_region_curvevector(eeh)
                        if region_cv is not None and region_eeh is not None:
                            place_circles_in_region(
                                region_cv,
                                n_circles=n_circles,
                                min_radius=min_radius,
                                max_radius=max_radius,
                                color_min=224,
                                color_max=239,
                                extrude_height=None
                            )
                            eeh.DeleteFromModel()