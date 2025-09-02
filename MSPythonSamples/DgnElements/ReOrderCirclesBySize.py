from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import math

# Description:
# This script finds all true circles (not ellipses) in the active DGN model,
# sorts them by diameter (smallest to largest), and moves them so they are
# aligned along the X axis, touching each other edge-to-edge, starting at X=0.
# The script uses the MicroStation Python API to access, sort, and move the elements.
# To use, place a collection of different sized circles and run the script.

def move_all_circles_to_x_axis_sorted():
    # Get the active model reference and model info
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    modelInfo = dgnModel.GetModelInfo()
    # Get UORs per master unit (not used in this script, but could be for scaling)
    __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)

    # Collect all circle (ellipse) elements in the model
    circle_handles = []
    for elemRef in dgnModel.GetGraphicElements():
        eeh = EditElementHandle(elemRef, dgnModel)
        if not eeh.IsValid():
            continue
        if eeh.GetElementType() == 15:  # 15 = eELLIPSE_ELM (circle/ellipse)
            # Use CurveVector to get geometry (recommended API pattern)
            curve_vector = ICurvePathQuery.ElementToCurveVector(eeh)
            if curve_vector is None or len(curve_vector) != 1:
                continue
            primitive = curve_vector[0]
            # Only process if the primitive is an Arc (which includes circles)
            if primitive.GetCurvePrimitiveType() == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Arc:
                arc = primitive.GetArc()
                # Only process true circles (vector0 and vector90 have same magnitude)
                r0 = arc.vector0.Magnitude()
                r90 = arc.vector90.Magnitude()
                if math.isclose(r0, r90, rel_tol=1e-8):
                    # Store the handle, center, and radius for later processing
                    circle_handles.append((eeh, arc.center, r0))

    # If no circles found, exit
    if not circle_handles:
        return

    # Sort circles by radius (smallest to largest)
    circle_handles.sort(key=lambda tup: tup[2])

    # Compute new X positions for each circle so they touch edge-to-edge
    x = 0.0
    spacing = 0.0  # No gap between circles
    new_centers = []
    for idx, (eeh, center, radius) in enumerate(circle_handles):
        # Place the first circle so its left edge is at x=0
        if idx == 0:
            x = radius
        else:
            prev_radius = circle_handles[idx-1][2]
            x += prev_radius + radius + spacing
        # All circles are placed at y=0, z preserved
        new_centers.append(DPoint3d(x, 0.0, center.z))

    # Move each circle to its new computed center on the X axis
    for (eeh, old_center, radius), new_center in zip(circle_handles, new_centers):
        dx = new_center.x - old_center.x
        dy = new_center.y - old_center.y
        dz = new_center.z - old_center.z
        # Build translation transform
        t = Transform()
        t.InitIdentity()
        t.SetTranslation(DPoint3d(dx, dy, dz))
        tinfo = TransformInfo(t)
        # Get the handler instance and apply the transform to the element
        handler = eeh.GetHandler()
        oldRef = eeh.GetElementRef()
        handler.ApplyTransform(eeh, tinfo)
        # Replace the element in the model with the moved version
        eeh.ReplaceInModel(oldRef)

# Run the function to move all circles as described
move_all_circles_to_x_axis_sorted()