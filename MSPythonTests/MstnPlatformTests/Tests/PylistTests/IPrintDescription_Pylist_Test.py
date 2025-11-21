import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def test_get_view_independent_fence():
    obj = IPrintDescription()
    assert obj is not None, "Failed to create IPrintDescription object."

    input_points = [DPoint3d(1.0, 2.0, 3.0), DPoint3d(4.5, 5.5, 6.5)]

    obj.GetViewIndependentFence(input_points)

    assert isinstance(input_points, list) ,"Input points should be a list."
    assert len(input_points) > 0

def test_get_view_independent_fence_empty_list():
    obj = IPrintDescription()
    assert obj is not None, "Failed to create IPrintDescription object."

    input_points = []

    obj.GetViewIndependentFence(input_points)

    assert isinstance(input_points, list) ,"Input points should be a list."
    assert len(input_points) == 0
    
def test_get_view_dependent_fence():
    obj = IPrintDescription()
    assert obj is not None, "Failed to create IPrintDescription object."

    input_points = [DPoint2d(1.0, 2.0), DPoint2d(4.5, 5.5)]

    obj.GetViewDependentFence(input_points)

    assert isinstance(input_points, list) ,"Input points should be a list."
    assert len(input_points) > 0
    
def test_get_view_dependent_fence_empty_list():
    obj = IPrintDescription()
    assert obj is not None, "Failed to create IPrintDescription object."

    input_points = []

    obj.GetViewDependentFence(input_points)

    assert isinstance(input_points, list) ,"Input points should be a list."
    assert len(input_points) == 0
    
if __name__ == "__main__":
    print("Script start...")
    test_get_view_independent_fence()
    test_get_view_independent_fence_empty_list()
    test_get_view_dependent_fence()
    test_get_view_dependent_fence_empty_list()
    print("Script end...")
