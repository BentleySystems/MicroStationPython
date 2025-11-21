from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

class FloodShapeCreator(DgnRegionElementTool):
    def __init__(self):
        """
        Initializes the FloodShapeCreator class.

        This method calls the constructor of the base class DgnRegionElementTool
        and initializes the m_regionParams and m_self attributes.
        """
        DgnRegionElementTool.__init__(self)  # C++ base's __init__ must be called.
        self.m_regionParams = RegionParams()
        self.m_self = self  # Keep self reference

    def _WantFloodDynamicArea(self):
        return True  # Show valid flood region under the cursor without waiting for accept point.

    def _GetRegionCreateMode(self):
        return DgnRegionElementTool.eREGION_CREATE_ByParams  # Create region using _GetRegionParams.

    def _GetRegionParams(self):
        """
        Setup region params to create region by flood.

        This method sets the type of the region to flood using a seed point and allows
        regions to be created with holes.

        :return: The region parameters.
        :rtype: RegionParams
        """
        self.m_regionParams.SetType(RegionType.eFlood)  # Create region by flood using seed point.
        self.m_regionParams.SetFloodParams(RegionLoops.eOuter, 0.0)  # Allow regions to be created with holes.

        return self.m_regionParams

    def _OnProcessRegionResult(self, eeh):
        """
        Process a region element created by this tool.

        This method applies active symbology and area fill settings to the new region element
        and adds it to the model.

        :param eeh: The element handle of the region element.
        :type eeh: ElementHandle
        :return: The status of the operation.
        :rtype: BentleyStatus
        """
        ElementPropertyUtils.ApplyActiveSettings(eeh)  # Apply active symbology to new region element.
        ElementPropertyUtils.ApplyActiveAreaSettings(eeh, -1)  # Apply active area fill to new region element.
        eeh.AddToModel()

        return BentleyStatus.eSUCCESS

    def _OnRestartTool(self):
        """
        Install a new instance of the tool.

        This method will be called in response to external events such as undo or by the base class
        from _OnReinitialize when the tool needs to be reset to its initial state.

        :return: None
        """
        FloodShapeCreator.InstallNewInstance()

    @staticmethod
    def InstallNewInstance():
        """
        Create and install a new instance of the tool.

        If InstallTool returns ERROR, the new tool instance will be freed/invalid.
        Never call delete on RefCounted classes.

        :return: None
        """
        tool = FloodShapeCreator()
        tool.InstallTool()

# Install the tool
FloodShapeCreator.InstallNewInstance()