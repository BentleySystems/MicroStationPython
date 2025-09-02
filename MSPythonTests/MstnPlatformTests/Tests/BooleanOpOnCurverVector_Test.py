
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def is_shape_inside(shape1_id, shape2_id):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    shape1_handle = EditElementHandle(shape1_id, dgnModel)
    shape2_handle = EditElementHandle(shape2_id, dgnModel)

    if not shape1_handle.IsValid() or not shape2_handle.IsValid():
        print("Invalid element handles.")
        return None

    shape1_curve = ICurvePathQuery.ElementToCurveVector(shape1_handle)
    shape2_curve = ICurvePathQuery.ElementToCurveVector(shape2_handle)

    if shape1_curve is None or shape2_curve is None:
        print("Failed to convert elements to CurveVectors.")
        return None

    # test to perform area operations on the CurveVectors
    union_curve = CurveVector.AreaUnion (shape1_curve, shape2_curve)
    diff_curve = CurveVector.AreaDifference (shape1_curve, shape2_curve)
    parity_curve = CurveVector.AreaParity (shape1_curve, shape2_curve)
    intersection_curve = CurveVector.AreaIntersection (shape1_curve, shape2_curve)
    
    if union_curve is None or diff_curve is None or parity_curve is None or intersection_curve is None:
        print("Failed to compute area operations on CurveVectors.")
        return None
    
    __, __, shape2_area = shape2_curve.CentroidAreaXY()
    __, __, intersection_area = intersection_curve.CentroidAreaXY()

    return abs(intersection_area - shape2_area) < 1e-6

def main():
    shape1_id = 575
    shape2_id = 576
    result = is_shape_inside(shape1_id, shape2_id)
    print(f"Shape2 is inside Shape1: {result}")

if __name__ == "__main__":
    print ("***** Area Intersection *****")
    main()
