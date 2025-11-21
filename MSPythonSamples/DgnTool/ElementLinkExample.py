# $Copyright:(c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import sys

class ElementLink(DgnElementSetTool):

    def __init__(self, toolId, command):
        """
        Initializes the ElementLinkExample tool with the specified tool ID and command.

        :param toolId: The unique identifier for the tool.
        :type toolId: int or str
        :param command: The command associated with the tool.
        :type command: str
        """
        DgnElementSetTool.__init__(self, toolId)
        self.m_transform = Transform()
        self.m_self = self
        self.command = command
        
    def _SetupForModify(self, ev, isDynamics):
        """
        Prepares the object for modification by calculating a transformation vector 
        based on the difference between the event point and an anchor point.

        :param ev: The event object containing the point to be used for the transformation.
        :type ev: Event
        :param isDynamics: A flag indicating whether the operation is dynamic.
        :type isDynamics: bool
        
        :return: Returns True if the anchor point is successfully retrieved and the 
                 transformation is initialized, otherwise False.
        :rtype: bool
        """
        anchorPt = DPoint3d()
        if not self._GetAnchorPoint(anchorPt):
            return False
        vec = DVec3d()
        vec.DifferenceOf(ev.Point, anchorPt)
        self.m_transform.InitFrom(vec)
        return True
    
    def CreateURLLink(self, urlAddress):
        """
        Creates a URL link and sets its address.

        :param urlAddress: The URL address to associate with the link.
        :type urlAddress: str
        
        :returns: The created link object if successful, otherwise None.
        :rtype: DgnLink or None
        
        :raises: Displays an error message if the link creation fails.
        """
        linkType = DGNLINK_TYPEKEY_URLLink
        link, status = DgnLinkManager.CreateLink(linkType)    
        if link is None:
            MessageCenter.ShowErrorMessage("DgnLinkManager.CreateLink failed to create new leaf: {status}", "", False)
            return None
        urlLink = link.GetLink()
        urlLink.SetAddress(urlAddress)
        return link

    def _OnElementModify(self, elementHandle):
        """
        Handles the modification of an element in the DGN model.
        This method performs various operations on a DGN element based on the 
        specified command. Supported commands include creating, deleting, modifying, 
        and extracting links associated with the element.
        
        :param elementHandle: The handle to the element being modified.
        :type elementHandle: ElementHandle
        
        :raises ValueError: If the DGN model is not selected or if any operation fails.
        
        :return: A status code indicating the success or failure of the operation.
        :rtype: BentleyStatus
        
        Supported Commands:
            - "CreateLink": Creates a new URL link and associates it with the element.
            - "DeleteLink": Deletes the first child link from the element's link tree.
            - "ModifyLink": Modifies the first child link in the element's link tree 
              with a new URL.
            - "ExtractLink": Extracts and prints the URL address of the first child 
              link in the element's link tree.
        Workflow:
            1. Retrieves the active DGN model and validates its existence.
            2. Depending on the command, performs the corresponding operation:
                - For "CreateLink", creates a new link and adds it to the link tree.
                - For "DeleteLink", removes the first child link from the link tree.
                - For "ModifyLink", replaces the first child link with a new link.
                - For "ExtractLink", retrieves and prints the URL of the first child link.
            3. Updates the element in the model after modifying its link tree.
        Note:
            - The method uses the `DgnLinkManager` to manage link trees and links.
            - Error messages are displayed using the `MessageCenter` in case of failures.
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        self.dgnModel = ACTIVEMODEL.GetDgnModel()
        if self.dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        self.dgnFile = self.dgnModel.GetDgnFile()

        elementEditElementHandle = EditElementHandle(elementHandle.ElementId, self.dgnModel)
        oldRef = elementEditElementHandle.ElementRef
        if self.command == "CreateLink":
            urlAddress = "https://www.google.org/"
            createdLink = self.CreateURLLink(urlAddress)
            if createdLink is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.CreateLink failed to create new leaf: {status}", "", False)
                return BentleyStatus.eERROR

            spec = DgnLinkManager.CreateTreeSpec(elementEditElementHandle.GetElementRef())
            
            if spec is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.CreateTreeSpec failed", "", False)
                return BentleyStatus.eERROR
            elementTree = DgnLinkManager.ReadLinkTree(spec, True)
            if elementTree is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.ReadLinkTree failed", "", False)
                return BentleyStatus.eERROR

            root = elementTree.GetRoot()

            #   Create and add the new node to the linkTree
            nodeToAdd = createdLink.AsDgnLinkTreeLeaf()
            if elementTree is None:
                MessageCenter.ShowErrorMessage("createdLink.AsDgnLinkTreeLeaf failed", "", False)
                return BentleyStatus.eERROR

            destLeaf    = nodeToAdd.Copy(elementTree.GetTreeSpec())
            sourceLink  = nodeToAdd.GetLink()

            suggestedName = sourceLink.BuildSuggestedName(None, True)
            newName = root.GetUniqueChildName(str(suggestedName))
            destLeaf.SetName(str(newName))

            stat = root.AddChild(destLeaf, 0)
            if stat != DgnLinkAddChildStatus.eSuccess:
                MessageCenter.ShowErrorMessage(f"root.AddChild Failed to add child to link tree: {stat}", "", False)
                return stat

            stat = DgnLinkManager.WriteLinkTree(elementTree, elementEditElementHandle)    
            if stat != BentleyStatus.eSUCCESS:
                MessageCenter.ShowErrorMessage(f"DgnLinkManager.WriteLinkTree failed to write link tree: {stat}", "", False)
                return stat
            copy = EditElementHandle()
            copy.Duplicate(elementEditElementHandle)
            elementEditElementHandle.DeleteFromModel()
            copy.AddToModel()
            return BentleyStatus.eSUCCESS

        elif self.command == "DeleteLink":
            spec = DgnLinkManager.CreateTreeSpec(elementEditElementHandle.GetElementRef())
            
            if spec is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.CreateTreeSpec failed", "", False)
                return BentleyStatus.eERROR
            elementTree = DgnLinkManager.ReadLinkTree(spec, True)
            if elementTree is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.ReadLinkTree failed", "", False)
                return BentleyStatus.eERROR

            root = elementTree.GetRoot()
            stat = root.DropChild(0)
            if stat != DgnLinkAddChildStatus.eSuccess.value:
                MessageCenter.ShowErrorMessage(f"root.DropChild Failed to drop child from link tree: {stat}", "", False)
                return stat

            stat = DgnLinkManager.WriteLinkTree(elementTree, elementEditElementHandle)    
            if stat != BentleyStatus.eSUCCESS:
                MessageCenter.ShowErrorMessage(f"DgnLinkManager.WriteLinkTree failed to write link tree: {stat}", "", False)
                return stat

            copy = EditElementHandle()
            copy.Duplicate(elementEditElementHandle)
            elementEditElementHandle.DeleteFromModel()
            copy.AddToModel()
            return BentleyStatus.eSUCCESS
        
        elif self.command == "ModifyLink":
            urlAddress = "https://www.bentley.com/"
            createdLink = self.CreateURLLink(urlAddress)
            if createdLink is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.CreateLink failed to create new leaf: {status}", "", False)
                return BentleyStatus.eERROR

            spec = DgnLinkManager.CreateTreeSpec(elementEditElementHandle.GetElementRef())
            
            if spec is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.CreateTreeSpec failed", "", False)
                return BentleyStatus.eERROR
            elementTree = DgnLinkManager.ReadLinkTree(spec, True)
            if elementTree is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.ReadLinkTree failed", "", False)
                return BentleyStatus.eERROR

            root = elementTree.GetRoot()

            #   Create and add the new node to the linkTree
            nodeToAdd = createdLink.AsDgnLinkTreeLeaf()
            if elementTree is None:
                MessageCenter.ShowErrorMessage("createdLink.AsDgnLinkTreeLeaf failed", "", False)
                return BentleyStatus.eERROR

            destLeaf    = nodeToAdd.Copy(elementTree.GetTreeSpec())
            sourceLink  = nodeToAdd.GetLink()

            suggestedName = sourceLink.BuildSuggestedName(None, True)
            newName = root.GetUniqueChildName(str(suggestedName))
            destLeaf.SetName(str(newName))

            stat = root.DropChild(0)
            stat = root.AddChild(destLeaf, 0)
            if stat != DgnLinkAddChildStatus.eSuccess:
                MessageCenter.ShowErrorMessage(f"root.AddChild Failed to add child to link tree: {stat}", "", False)
                return stat

            stat = DgnLinkManager.WriteLinkTree(elementTree, elementEditElementHandle)    
            if stat != BentleyStatus.eSUCCESS:
                MessageCenter.ShowErrorMessage(f"DgnLinkManager.WriteLinkTree failed to write link tree: {stat}", "", False)
                return stat

            copy = EditElementHandle()
            copy.Duplicate(elementEditElementHandle)
            elementEditElementHandle.DeleteFromModel()
            copy.AddToModel()
            return BentleyStatus.eSUCCESS

        elif self.command == "ExtractLink":
            spec = DgnLinkManager.CreateTreeSpec(elementEditElementHandle.GetElementRef())
            
            if spec is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.CreateTreeSpec failed", "", False)
                return BentleyStatus.eERROR
            elementTree = DgnLinkManager.ReadLinkTree(spec, True)
            if elementTree is None:
                MessageCenter.ShowErrorMessage("DgnLinkManager.ReadLinkTree failed", "", False)
                return BentleyStatus.eERROR

            root = elementTree.GetRoot()
            urlAddress = root.GetChild(0).Link.Address
            print(f"Extracted URL Address: {urlAddress}")
            return BentleyStatus.eSUCCESS

    def _OnRestartTool(self):
        """
        Restarts the current tool by installing a new instance of the tool.

        :returns: None
        """
        ElementLink.InstallNewInstance(self.ToolId, self.command)

    def InstallNewInstance(toolId, command):
        """
        Installs a new instance of the ElementLink tool with the specified tool ID and command.

        :param toolId: The unique identifier for the tool to be installed.
        :type toolId: Any
        :param command: The command associated with the tool.
        :type command: Any
        
        :return: None
        :rtype: NoneType
        """
        tool = ElementLink(toolId, command)
        tool.InstallTool()

def createElementLink():
    """
    Creates a new element link by installing a new instance with a specified ID and name.

    This function utilizes the `ElementLink.InstallNewInstance` method to create a link
    with an ID of 1 and the name "CreateLink".

    :return: None
    """
    ElementLink.InstallNewInstance(1, "CreateLink")

def deleteElementLink():
    """
    Deletes an element link by installing a new instance with the specified parameters.

    This function utilizes the `ElementLink.InstallNewInstance` method to create a new 
    instance of an element link with the ID `1` and the name `"DeleteLink"`. It is 
    intended to handle the deletion of element links in the application.

    :return: None
    """
    ElementLink.InstallNewInstance(1, "DeleteLink")

def modifyElementLink():
    """
    Modifies an element link by installing a new instance.

    This function calls the `InstallNewInstance` method of the `ElementLink` 
    class to create or modify an element link with a specified ID and name.

    :raises Exception: If the `ElementLink.InstallNewInstance` method fails.
    """
    ElementLink.InstallNewInstance(1, "ModifyLink")

def extractElementLink():
    """
    Installs a new instance of an element link with a specified ID and name.

    This function utilizes the `ElementLink.InstallNewInstance` method to create
    a new element link with an ID of `1` and a name of `"ExtractLink"`.

    :return: None
    """
    ElementLink.InstallNewInstance(1, "ExtractLink")

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ElementLinkExample.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))