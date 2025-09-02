from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

def get_active_model_graphical_elements():
    """
    Retrieves the active DGN model and its graphical elements.

    :returns: A tuple containing the active DGN model and a collection of its graphical elements.
    :rtype: tuple
    """
    active_model = ISessionMgr.ActiveDgnModelRef
    dgn_model = active_model.GetDgnModel()
    graphical_elements = dgn_model.GetGraphicElements()
    return dgn_model, graphical_elements

def get_element_bounding_box(element_handle):
    """
    Retrieves the bounding box of a given element.

    :param element_handle: The handle to the element whose bounding box is to be retrieved.
                           This handle is expected to have a `DisplayHandler` attribute with
                           a `GetBasisRange` method.
    :type element_handle: object
    
    :return: The bounding box of the element as a `DRange3d` object.
    :rtype: DRange3d
    """
    rangeA = DRange3d(0,0,0,0,0,0)
    element_handle.DisplayHandler.GetBasisRange(element_handle, rangeA)
    return rangeA

def check_overlap(element1, element2, dgn_model):
    """
    Determines whether two elements overlap by checking their bounding boxes.

    :param element1: The first element to check.
    :type element1: object
    :param element2: The second element to check.
    :type element2: object
    :param dgn_model: The design model containing the elements.
    :type dgn_model: object
    
    :return: True if the bounding boxes of the two elements intersect, False otherwise.
    :rtype: bool
    """
    bbox1 = get_element_bounding_box(element1)
    bbox2 = get_element_bounding_box(element2)
    if bbox1 and bbox2:
        return bbox1.IntersectsWith(bbox2)
    return False

def move_element_to_non_overlapping_position(element, dgn_model):
    """
    Moves a given element to a non-overlapping position within the specified design model.
    This function duplicates the provided element, applies a translation transform to move it 
    to a new position, and then updates the model by adding the transformed element and 
    removing the original duplicate.
    
    :param element: The element to be moved. It should have an `ElementId` and support 
                    bounding box and handler operations.
    :type element: Element
    :param dgn_model: The design model containing the element.
    :type dgn_model: DgnModel
    
    :raises ValueError: If the bounding box of the element cannot be retrieved.
    :raises PermissionError: If the handler for transforming the element is missing.
    
    :return: None
    """
    elementEditElementHandle = EditElementHandle(element.ElementId, dgn_model)
    bbox = get_element_bounding_box(element)
    if bbox:
        elementHandler = element.GetHandler(eMISSING_HANDLER_PERMISSION_Transform)
        elementEditElementHandle = EditElementHandle(element.ElementId, dgn_model)
        copyElementEditElementHandle = EditElementHandle()
        copyElementEditElementHandle.Duplicate(elementEditElementHandle)

        ptOrigin = DPoint3d()
        elementHandler.GetTransformOrigin(elementEditElementHandle, ptOrigin)
        ptOrigin.x += 100000
        ptOrigin.y += 100000
        ptOrigin.z += 100000

        transform = Transform()
        transform.InitIdentity()
        transform.SetTranslation(ptOrigin)

        elementHandler.ApplyTransform(elementEditElementHandle, TransformInfo(transform))
        elementEditElementHandle.AddToModel()
        copyElementEditElementHandle.DeleteFromModel()
        return

def detect_and_resolve_overlaps():
    """
    Detects and resolves overlapping graphical elements in the active DGN model.

    This function retrieves the active DGN model and its graphical elements, 
    checks for overlaps between consecutive elements, and resolves any detected 
    overlaps by moving the overlapping element to a non-overlapping position.

    :raises RuntimeError: If the active model or graphical elements cannot be retrieved.
    """
    dgn_model, graphical_elements = get_active_model_graphical_elements()
    elements = [ElementHandle(per_element_ref) for per_element_ref in graphical_elements]
    for element1Handle, element2Handle in zip(elements, elements[1:]):
        if check_overlap(element1Handle, element2Handle, dgn_model):
            move_element_to_non_overlapping_position(element1Handle, dgn_model)
            return

if __name__ == "__main__":
    detect_and_resolve_overlaps()