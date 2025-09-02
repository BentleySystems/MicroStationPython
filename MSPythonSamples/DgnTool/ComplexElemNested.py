# $Copyright:(c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example demonstrating the process of adding nested complex element types in the active DGN model.
Performs transformations, appends descriptors, and updates elements as needed.
'''

eMESH_HEADER_ELM = 105
eEXTENDED_ELM = 106
PROMPT_AcceptRejectSelection = 2
PROMPT_SelectComplexElem = 1
MSG_PROMPT = 2
STRINGLISTID_Prompts = 1

class DrawComplexElement(DgnElementSetTool):

    def __init__(self, toolId=1):
        """
        Initializes the DrawComplexElement tool.

        :param toolId: An identifier for the tool, default is 1.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_self = self # Keep self reference

    def _OnElementModify(self, elementHandle):
        """
        Handles the modification of an element in the active DGN model.
        This method performs specific operations based on the type of the element being modified.
        It supports various element types such as cell headers, complex shapes, text elements, 
        complex strings, extended elements, surfaces, solids, and mesh headers. The method 
        applies transformations, creates new elements, and appends descriptors to the modified 
        elements as needed.
        
        :param elementHandle: The handle to the element being modified.
        :type elementHandle: ElementHandle
        
        :return: A status code indicating the success or failure of the operation.
        :rtype: BentleyStatus
        
        :raises ValueError: If the element type is unsupported or an error occurs during processing.
        
        Supported Element Types:
            - eCELL_HEADER_ELM: Applies a transformation and updates the cell header element.
            - eCMPLX_SHAPE_ELM: Creates and appends lines to a complex shape element.
            - eTEXT_NODE_ELM / eTEXT_ELM: Modifies the origin of text elements.
            - eCMPLX_STRING_ELM: Appends a line element to a complex string element.
            - eEXTENDED_ELM: Applies a transformation to an extended element.
            - eSURFACE_ELM / eSOLID_ELM: Creates a projection element for surface or solid elements.
            - eMESH_HEADER_ELM: Creates and appends a mesh element.
        Notes:
            - The method interacts with the active DGN model and uses various handlers to 
              manipulate elements.
            - The transformations and modifications are applied based on predefined offsets 
              and configurations.
            - If the element type is unsupported or an error occurs, the method returns 
              `BentleyStatus.eERROR`.
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        if dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        
        if eCELL_HEADER_ELM == elementHandle.GetElementType():
            brepHandler = elementHandle.GetHandler(eMISSING_HANDLER_PERMISSION_Transform)
            if not brepHandler:
                return BentleyStatus.eERROR

            cellEditElementHandler = EditElementHandle(elementHandle.ElementId, dgnModel)

            ptOrigin = DPoint3d()
            brepHandler.GetTransformOrigin(cellEditElementHandler, ptOrigin)
            ptOrigin.x += 100000
            ptOrigin.y += 100000

            transform = Transform()
            transform.InitIdentity()
            transform.SetTranslation(ptOrigin)

            brepHandler.ApplyTransform(cellEditElementHandler, TransformInfo(transform))
            chainDscr = cellEditElementHandler.ExtractElementDescr()
            chainDscr.AppendDescr(elementHandle.ElementDescr)
            cellEditElementHandler.SetElementDescr(chainDscr, True, False, ACTIVEMODEL)
            cellEditElementHandler.AddToModel()
            return BentleyStatus.eSUCCESS

        if eCMPLX_SHAPE_ELM == elementHandle.GetElementType():
            complexShapeEditElementHandler = EditElementHandle(elementHandle.ElementId, dgnModel)
            chainDscr = complexShapeEditElementHandler.ElementDescr
            chainHeaderEditElementHandler = EditElementHandle()
            ChainHeaderHandler.CreateChainHeaderElement(chainHeaderEditElementHandler, None, True, dgnModel.Is3d(), dgnModel)
            if BentleyStatus.eERROR == MSElementDescr.Allocate(chainHeaderEditElementHandler.Element, ACTIVEMODEL, chainDscr):
                return BentleyStatus.eERROR

            m_points = [DPoint3d(0.0, 0.0, 0.0), DPoint3d(1000000.0, 0.0, 0.0), DPoint3d(1000000.0, 1000000.0, 0.0)]
            lines0 = EditElementHandle()
            lines1 = EditElementHandle()
            lines2 = EditElementHandle()
            Lines = [lines0, lines1, lines2]
            # Create lines for complex shape.
            for j in range(0, 2):
                point1 = m_points[j]
                point2 = m_points[j+1]
                segment = DSegment3d(point1, point2)
                LineHandler.CreateLineElement(Lines[j], None, segment, dgnModel.Is3d(), dgnModel)
                elementLine = Lines[j].Element
                chainDscr.AppendElement(elementLine)

            chainDscr.AppendDescr(elementHandle.ElementDescr)
            complexShapeEditElementHandler.SetElementDescr(chainDscr, True, False, ACTIVEMODEL)
            complexShapeEditElementHandler.AddToModel()
            return BentleyStatus.eSUCCESS
        
        if eTEXT_NODE_ELM == elementHandle.GetElementType() or eTEXT_ELM == elementHandle.GetElementType():
            initialTextEditElementHandle = EditElementHandle()
            initialTextEditElementHandle.Duplicate (elementHandle)
            textQuery = initialTextEditElementHandle.GetITextQuery()
            if not textQuery or not textQuery.IsTextElement(initialTextEditElementHandle):
                return BentleyStatus.eERROR
            textPart = DimensionTextPartId.Create(0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)
            textBlock = textQuery.GetTextPart(initialTextEditElementHandle, textPart)
            if textBlock is None or textBlock.IsEmpty():
                return BentleyStatus.eERROR
            ptOrigin = DPoint3d()
            ptOrigin = textBlock.GetUserOrigin()
            ptOrigin.x += 100000
            ptOrigin.y += 100000
            textBlock.SetUserOrigin(ptOrigin)
            textEditElementHandle = EditElementHandle()
            TextHandlerBase.CreateElement(textEditElementHandle, None, textBlock)
            
            chainDscr = textEditElementHandle.ElementDescr
            chainDscr.AppendDescr(elementHandle.ExtractElementDescr())
            textEditElementHandle.SetElementDescr(chainDscr, True, False, elementHandle.GetModelRef())
            textEditElementHandle.AddToModel()
            return BentleyStatus.eSUCCESS
        
        if eCMPLX_STRING_ELM == elementHandle.GetElementType():
            complexStringEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)
            lineEditElementHandle = EditElementHandle()
            segment = DSegment3d(DPoint3d(0.0, 0.0, 0.0), DPoint3d(100.0, 0.0, 0.0))
            LineHandler.CreateLineElement(lineEditElementHandle, None, segment, dgnModel.Is3d(), dgnModel)
            elementLine = lineEditElementHandle.Element
            
            chainHeaderEditElementHandler = EditElementHandle()
            ChainHeaderHandler.CreateChainHeaderElement(chainHeaderEditElementHandler, None, True, dgnModel.Is3d(), dgnModel)
            chainDscr = complexStringEditElementHandle.ElementDescr
            if BentleyStatus.eERROR == MSElementDescr.Allocate(chainHeaderEditElementHandler.Element, ACTIVEMODEL, chainDscr):
                return BentleyStatus.eERROR

            chainDscr.AppendElement(elementLine)
            chainDscr.AppendDescr(elementHandle.ElementDescr)
            complexStringEditElementHandle.SetElementDescr(chainDscr, True, False, ACTIVEMODEL)
            complexStringEditElementHandle.AddToModel()
            return BentleyStatus.eSUCCESS
        
        if eEXTENDED_ELM == elementHandle.GetElementType():
            disHandler = elementHandle.GetHandler(eMISSING_HANDLER_PERMISSION_Transform)
            if not disHandler:
                return BentleyStatus.eERROR

            extendElementEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)

            ptOrigin = DPoint3d()
            disHandler.GetTransformOrigin(extendElementEditElementHandle, ptOrigin)
            ptOrigin.x += 100000
            ptOrigin.y += 100000

            transform = Transform()
            transform.InitIdentity()
            transform.SetTranslation(ptOrigin)

            disHandler.ApplyTransform(extendElementEditElementHandle, TransformInfo(transform))
            chainDscr = extendElementEditElementHandle.ExtractElementDescr()
            chainDscr.AppendDescr(elementHandle.ElementDescr)
            extendElementEditElementHandle.SetElementDescr(chainDscr, True, False, elementHandle.GetModelRef())
            extendElementEditElementHandle.AddToModel()
            return BentleyStatus.eSUCCESS
        
        if eSURFACE_ELM == elementHandle.GetElementType() or eSOLID_ELM == elementHandle.GetElementType():
            SurfaceOrSolidEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)
            shape = EditElementHandle()
            solidEditElementHandle = EditElementHandle()

            points = DPoint3dArray()
            # Add the points to the surface type18 element.
            points.extend((DPoint3d(0.0, 0.0, 0.0), DPoint3d(1000000.0, 0.0, 0.0), DPoint3d(1000000., 1000000., 0.0), DPoint3d(0.0, 900000.0, 0.0)))
            origin = DPoint3d(0.0, 0.0, 0)
            extrudeVector = DVec3d.From(0., 0., 2000000)

            shapeElement = ShapeHandler.CreateShapeElement(shape, None, points, dgnModel.Is3d(), dgnModel)
            solidElement = SurfaceOrSolidHandler.CreateProjectionElement(solidEditElementHandle, None, shape, origin, extrudeVector, None, True, dgnModel)

            if BentleyStatus.eERROR ==(shapeElement and solidElement):
                return BentleyStatus.eERROR

            chainDscr = solidEditElementHandle.ExtractElementDescr()
            chainDscr.AppendDescr(elementHandle.ElementDescr)
            SurfaceOrSolidEditElementHandle.SetElementDescr(chainDscr, True, False, ACTIVEMODEL)
            SurfaceOrSolidEditElementHandle.AddToModel()
            return BentleyStatus.eSUCCESS
        
        if eMESH_HEADER_ELM == elementHandle.GetElementType():
            existingMeshEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)
            points = DPoint3dArray()
            points.extend((DPoint3d(0.0, 0.0, 0.0), DPoint3d(1000000.0, 0.0, 0.0), DPoint3d(1000000., 1000000., 0.0), DPoint3d(0.0, 900000.0, 0.0)))
            nestedMesh = PolyfaceHeader.CreateVariableSizeIndexed()
            nestedMesh.AddPolygon(points)
            nestedMesh.Triangulate()
            nestedMesh.MarkAllEdgesVisible()
            meshEditElementHandle = EditElementHandle()
            MeshHeaderHandler.CreateMeshElement(meshEditElementHandle, None, nestedMesh, True, ACTIVEMODEL)

            chainDscr = meshEditElementHandle.ExtractElementDescr()
            chainDscr.AppendDescr(elementHandle.ElementDescr)
            existingMeshEditElementHandle.SetElementDescr(chainDscr, True, False, ACTIVEMODEL)
            existingMeshEditElementHandle.AddToModel()
            return BentleyStatus.eSUCCESS
        
        return BentleyStatus.eERROR
    
    def _SetupAndPromptForNextAction(self):
        """
        Sets up the environment and prompts the user for the next action.
        This method deactivates AccuDraw and determines the appropriate 
        message to display based on the current state of the element agenda. 
        If there are elements in the agenda, it prompts the user to accept 
        or reject the selection. Otherwise, it prompts the user to select 
        a complex element.
        
        :return: None
        """
        AccuDraw.Deactivate = True
        msgId = PROMPT_AcceptRejectSelection if self.GetElementAgenda().GetCount() > 0 else PROMPT_SelectComplexElem

        print(MSG_PROMPT, None, STRINGLISTID_Prompts, msgId)

    def _OnRestartTool(self):
        """
        Restarts the current tool by installing a new instance of the `DrawComplexElement` tool.

        This method creates a new instance of the `DrawComplexElement` class and installs it
        using the current tool's ID. It is typically used to reset the tool's state or behavior.

        :return: None
        """
        DrawComplexElement().InstallInstance(self.GetToolId())

    def InstallInstance(self, toolId):
        """
        Installs an instance of the DrawComplexElement tool with the specified tool ID.

        :param toolId: The identifier for the tool to be installed.
        :type toolId: int
        """
        tool = DrawComplexElement(toolId)
        tool.InstallTool()
    
    def _OnPostLocate(self, path, cantAcceptReason):
        """
        Handles the post-locate event for an element in the path.
        This method determines whether the located element is acceptable 
        based on its type and properties. It checks if the element is a 
        complex header or an extended element type.
        
        :param path: The path object containing the element to be located. 
                     If None, no element is processed.
        :type path: Path or None
        :param cantAcceptReason: A placeholder for the reason why the 
                                 element cannot be accepted.
        :type cantAcceptReason: Any
        
        :return: True if the element is a complex header or an extended 
                 element type, otherwise False.
        :rtype: bool
        """
        index = 0
        element = path.GetPathElem(index) if path is not None else None
        if not path:
            pathRoot = None
        else:
            pathRoot = path.GetRoot ()
        elHandle = EditElementHandle(
            element, pathRoot)

        if elHandle.Element.IsComplexHeader():
            return True

        if eEXTENDED_ELM == elHandle.GetElementType():
            return True
        return False

if __name__ == "__main__":
    DrawComplexElement().InstallInstance(1)