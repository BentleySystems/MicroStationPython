from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyDgnView

class AccuDraw:
    """
    None
    """

    def Activate(self: MSPyDgnView.AccuDraw) -> None:
        """
        For tools to explicitly enable AccuDraw before dynamics start.
        """
        ...
    
    @property
    def Angle(arg0: MSPyDgnView.AccuDraw) -> float:
        ...
    
    @property
    def CompassMode(arg0: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.CompassMode:
        ...
    
    @property
    def CompassViewport(arg0: MSPyDgnView.AccuDraw) -> MSPyDgnPlatform.IndexedViewport:
        ...
    
    def Deactivate(self: MSPyDgnView.AccuDraw) -> None:
        """
        For tools that don't support AccuDraw or don't want it automatically
        enabled.
        """
        ...
    
    @property
    def Delta(arg0: MSPyDgnView.AccuDraw) -> MSPyBentleyGeom.DVec3d:
        ...
    
    @property
    def Distance(arg0: MSPyDgnView.AccuDraw) -> float:
        ...
    
    @property
    def FloatingOrigin(arg0: MSPyDgnView.AccuDraw) -> bool:
        ...
    
    def GetAngle(self: MSPyDgnView.AccuDraw) -> float:
        """
        Current compass polar angle
        """
        ...
    
    def GetCompassMode(self: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.CompassMode:
        """
        Current compass mode
        """
        ...
    
    def GetCompassViewport(self: MSPyDgnView.AccuDraw) -> MSPyDgnPlatform.IndexedViewport:
        """
        Current compass viewport
        """
        ...
    
    def GetDelta(self: MSPyDgnView.AccuDraw, delta: MSPyBentleyGeom.DVec3d) -> None:
        """
        Current compass xyz delta
        """
        ...
    
    def GetDistance(self: MSPyDgnView.AccuDraw) -> float:
        """
        Current compass polar distance
        """
        ...
    
    def GetFloatingOrigin(self: MSPyDgnView.AccuDraw) -> bool:
        """
        Current compass floating origin setting
        """
        ...
    
    @staticmethod
    def GetInstance() -> MSPyDgnView.AccuDraw:
        """
        Get the current AccuDraw instance.
        """
        ...
    
    def GetLocked(self: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.LockedStates:
        """
        Current compass locks bitmask
        """
        ...
    
    def GetOrigin(self: MSPyDgnView.AccuDraw, origin: MSPyBentleyGeom.DPoint3d) -> None:
        """
        Current compass origin
        """
        ...
    
    def GetRotation(self: MSPyDgnView.AccuDraw, rMatrix: MSPyBentleyGeom.RotMatrix) -> None:
        """
        Current compass orientation
        """
        ...
    
    def GetRotationMode(self: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.RotationMode:
        """
        Current compass rotation type
        """
        ...
    
    def IsActive(self: MSPyDgnView.AccuDraw) -> bool:
        """
        Compass is active/displayed.
        """
        ...
    
    @property
    def Locked(arg0: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.LockedStates:
        ...
    
    class LockedStates:
        """
        Members:
        
        eNONE_LOCKED
        
        eX_BM
        
        eY_BM
        
        eVEC_BM
        
        eDIST_BM
        
        eXY_BM
        
        eANGLE_BM
        """
    
        def __init__(self: MSPyDgnView.AccuDraw.LockedStates, value: int) -> None:
            ...
        
        eANGLE_BM: LockedStates
        
        eDIST_BM: LockedStates
        
        eNONE_LOCKED: LockedStates
        
        eVEC_BM: LockedStates
        
        eXY_BM: LockedStates
        
        eX_BM: LockedStates
        
        eY_BM: LockedStates
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.AccuDraw.LockedStates) -> int:
            ...
        
    @property
    def Origin(arg0: MSPyDgnView.AccuDraw) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def Rotation(arg0: MSPyDgnView.AccuDraw) -> MSPyBentleyGeom.RotMatrix:
        ...
    
    @property
    def RotationMode(arg0: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.RotationMode:
        ...
    
    def SetContext(self: MSPyDgnView.AccuDraw, flags: MSPyDgnView.AccuDrawFlags, origin: MSPyBentleyGeom.DPoint3d = None, orientation: MSPyBentleyGeom.DVec3d = None, delta: MSPyBentleyGeom.DVec3d = None, distance: Optional[float] = None, angle: Optional[float] = None, trans: MSPyBentleyGeom.Transform = None) -> MSPyDgnPlatform.BentleyStatus:
        """
        Allows tools to provide hints to accudraw for setting compass
        location, orientation, mode, etc.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eANGLE_BM: LockedStates
    
    eDIST_BM: LockedStates
    
    eMODE_Polar: CompassMode
    
    eMODE_Rectangular: CompassMode
    
    eNONE_LOCKED: LockedStates
    
    eROTATION_ACS: RotationMode
    
    eROTATION_Context: RotationMode
    
    eROTATION_Front: RotationMode
    
    eROTATION_Restore: RotationMode
    
    eROTATION_Side: RotationMode
    
    eROTATION_Top: RotationMode
    
    eROTATION_View: RotationMode
    
    eVEC_BM: LockedStates
    
    eXY_BM: LockedStates
    
    eX_BM: LockedStates
    
    eY_BM: LockedStates
    
class AccuDrawFlags:
    """
    Members:
    
    eACCUDRAW_SetModePolar
    
    eACCUDRAW_SetModeRect
    
    eACCUDRAW_SetOrigin
    
    eACCUDRAW_FixedOrigin
    
    eACCUDRAW_SetRMatrix
    
    eACCUDRAW_SetXAxis
    
    eACCUDRAW_SetNormal
    
    eACCUDRAW_SetDistance
    
    eACCUDRAW_LockDistance
    
    eACCUDRAW_Lock_X
    
    eACCUDRAW_Lock_Y
    
    eACCUDRAW_Lock_Z
    
    eACCUDRAW_Disable
    
    eACCUDRAW_Set3dMatrix
    
    eACCUDRAW_OrientDefault
    
    eACCUDRAW_SetFocus
    
    eACCUDRAW_Delay
    
    eACCUDRAW_OrientACS
    
    eACCUDRAW_SetXAxis2
    
    eACCUDRAW_LockAngle
    
    eACCUDRAW_AllowStartInLocate
    
    eACCUDRAW_AlwaysSetOrigin
    
    eACCUDRAW_RedrawCompass
    
    eACCUDRAW_UpdateRotation
    """

    def __init__(self: MSPyDgnView.AccuDrawFlags, value: int) -> None:
        ...
    
    eACCUDRAW_AllowStartInLocate: AccuDrawFlags
    
    eACCUDRAW_AlwaysSetOrigin: AccuDrawFlags
    
    eACCUDRAW_Delay: AccuDrawFlags
    
    eACCUDRAW_Disable: AccuDrawFlags
    
    eACCUDRAW_FixedOrigin: AccuDrawFlags
    
    eACCUDRAW_LockAngle: AccuDrawFlags
    
    eACCUDRAW_LockDistance: AccuDrawFlags
    
    eACCUDRAW_Lock_X: AccuDrawFlags
    
    eACCUDRAW_Lock_Y: AccuDrawFlags
    
    eACCUDRAW_Lock_Z: AccuDrawFlags
    
    eACCUDRAW_OrientACS: AccuDrawFlags
    
    eACCUDRAW_OrientDefault: AccuDrawFlags
    
    eACCUDRAW_RedrawCompass: AccuDrawFlags
    
    eACCUDRAW_Set3dMatrix: AccuDrawFlags
    
    eACCUDRAW_SetDistance: AccuDrawFlags
    
    eACCUDRAW_SetFocus: AccuDrawFlags
    
    eACCUDRAW_SetModePolar: AccuDrawFlags
    
    eACCUDRAW_SetModeRect: AccuDrawFlags
    
    eACCUDRAW_SetNormal: AccuDrawFlags
    
    eACCUDRAW_SetOrigin: AccuDrawFlags
    
    eACCUDRAW_SetRMatrix: AccuDrawFlags
    
    eACCUDRAW_SetXAxis: AccuDrawFlags
    
    eACCUDRAW_SetXAxis2: AccuDrawFlags
    
    eACCUDRAW_UpdateRotation: AccuDrawFlags
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyDgnView.AccuDrawFlags) -> int:
        ...
    
class AccuSnap:
    """
    None
    """

    @staticmethod
    def AddEventHandler(accuSnapHandler: MSPyDgnView.AccuSnapHandler) -> None:
        """
        Add a new AccuSnapHandler to the list of installed AccuSnapHandlers.
        
        :param accuSnapHandler:
        New AccuSnapHandler to add
        """
        ...
    
    def Clear(self: MSPyDgnView.AccuSnap) -> None:
        """
        Clear the current AccuSnap/AutoLocate path so that it is no longer
        snapped or hilited.
        """
        ...
    
    @property
    def CurrHit(arg0: MSPyDgnView.AccuSnap) -> MSPyDgnPlatform.HitPath:
        ...
    
    @staticmethod
    def DropEventHandler(accuSnapHandler: MSPyDgnView.AccuSnapHandler) -> None:
        """
        Drop an AccuSnapHandler from list of installed AccuSnapHandlers. After
        this call, handler will not be notified of future AccuSnapHandler
        events.
        
        :param accuSnapHandler:
        the AccuSnapHandler to drop.
        """
        ...
    
    def EnableLocate(self: MSPyDgnView.AccuSnap, yesNo: bool) -> None:
        """
        Set the enabled state of AutoLocate for the current tool @note Even if
        yesNo is true, AutoLocate will not be enabled unless the user has also
        enabled it.
        """
        ...
    
    def EnableSnap(self: MSPyDgnView.AccuSnap, yesNo: bool) -> None:
        """
        Set the enabled state of AccuSnap for the current tool @note Even if
        yesNo is true, AccuSnap will not be enabled unless the user has also
        enabled it.
        """
        ...
    
    def GetCurrHit(self: MSPyDgnView.AccuSnap) -> MSPyDgnPlatform.HitPath:
        ...
    
    @staticmethod
    def GetInstance() -> MSPyDgnView.AccuSnap:
        """
        Get the current AccuSnap instance.
        """
        ...
    
    Instance: AccuSnap
    
    def IsActive(self: MSPyDgnView.AccuSnap, ev: MSPyDgnPlatform.DgnButtonEvent) -> bool:
        """
        Determine whether AccuSnap is currently active. To be active both the
        tool and the user must indicate that they want it.
        
        :param ev:
        The current button event. Used to check the modifier keys that can
        temporarily enable/disable AccuSnap.
        
        :returns:
        true if active.
        """
        ...
    
    def IsHot(self: MSPyDgnView.AccuSnap) -> bool:
        """
        :returns:
        true if AccuSnap is currently active and snapped to an element.
        """
        ...
    
    def IsLocateEnabled(self: MSPyDgnView.AccuSnap) -> bool:
        """
        :returns:
        true if AutoLocate has been enabled by the current tool.
        """
        ...
    
    def IsSnapEnabled(self: MSPyDgnView.AccuSnap) -> bool:
        """
        :returns:
        true if AccuSnap has been enabled by the current tool.
        """
        ...
    
    def ResetButton(self: MSPyDgnView.AccuSnap) -> MSPyDgnPlatform.SnapStatus:
        """
        Can be called by tools to advance to the next AccuSnap/AutoLocate hit
        path when more than one element is under the cursor. @note Used in
        default implementation of DgnElementSetTool._OnResetButton.
        """
        ...
    
    def SetComponentMode(self: MSPyDgnView.AccuSnap, mode: MSPyDgnPlatform.ComponentMode) -> None:
        """
        @note Resets to default value of ComponentMode.None whenever locate
        is enabled.
        """
        ...
    
    def Suspend(self: MSPyDgnView.AccuSnap, doSuspend: bool) -> None:
        """
        Can be called by a tool to temporarily suspend Accusnap. Calls to this
        function should be paired.
        
        :param doSuspend:
        true to suspend AccuSnap, false to resume it.
        """
        ...
    
    def UserWantsLocates(self: MSPyDgnView.AccuSnap) -> bool:
        """
        :returns:
        true if the user has enabled AutoLocate. Controlled by " Identify Elements Automatically " preference.
        """
        ...
    
    def UserWantsSnaps(self: MSPyDgnView.AccuSnap) -> bool:
        """
        :returns:
        true if the user has enabled AccuSnap.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class AccuSnapEnableFlag:
    """
    Members:
    
    eACCUSNAP_ENABLE_OffByDefault
    
    eACCUSNAP_ENABLE_OnByDefault
    
    eACCUSNAP_ENABLE_Never
    """

    def __init__(self: MSPyDgnView.AccuSnapEnableFlag, value: int) -> None:
        ...
    
    eACCUSNAP_ENABLE_Never: AccuSnapEnableFlag
    
    eACCUSNAP_ENABLE_OffByDefault: AccuSnapEnableFlag
    
    eACCUSNAP_ENABLE_OnByDefault: AccuSnapEnableFlag
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyDgnView.AccuSnapEnableFlag) -> int:
        ...
    
class AccuSnapHandler:
    """
    None
    """

    class AccuSnapEventHandlerPriority:
        """
        Members:
        
        eACCUSNAPHANDLER_PRIORITY_Highest
        
        eACCUSNAPHANDLER_PRIORITY_High
        
        eACCUSNAPHANDLER_PRIORITY_Normal
        
        eACCUSNAPHANDLER_PRIORITY_Low
        
        eACCUSNAPHANDLER_PRIORITY_Lowest
        """
    
        def __init__(self: MSPyDgnView.AccuSnapHandler.AccuSnapEventHandlerPriority, value: int) -> None:
            ...
        
        eACCUSNAPHANDLER_PRIORITY_High: AccuSnapEventHandlerPriority
        
        eACCUSNAPHANDLER_PRIORITY_Highest: AccuSnapEventHandlerPriority
        
        eACCUSNAPHANDLER_PRIORITY_Low: AccuSnapEventHandlerPriority
        
        eACCUSNAPHANDLER_PRIORITY_Lowest: AccuSnapEventHandlerPriority
        
        eACCUSNAPHANDLER_PRIORITY_Normal: AccuSnapEventHandlerPriority
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.AccuSnapHandler.AccuSnapEventHandlerPriority) -> int:
            ...
        
    class AsnapStatus:
        """
        Members:
        
        eOk
        
        eDontShow
        """
    
        def __init__(self: MSPyDgnView.AccuSnapHandler.AsnapStatus, value: int) -> None:
            ...
        
        eDontShow: AsnapStatus
        
        eOk: AsnapStatus
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.AccuSnapHandler.AsnapStatus) -> int:
            ...
        
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eACCUSNAPHANDLER_PRIORITY_High: AccuSnapEventHandlerPriority
    
    eACCUSNAPHANDLER_PRIORITY_Highest: AccuSnapEventHandlerPriority
    
    eACCUSNAPHANDLER_PRIORITY_Low: AccuSnapEventHandlerPriority
    
    eACCUSNAPHANDLER_PRIORITY_Lowest: AccuSnapEventHandlerPriority
    
    eACCUSNAPHANDLER_PRIORITY_Normal: AccuSnapEventHandlerPriority
    
    eDontShow: AsnapStatus
    
    eOk: AsnapStatus
    
class CoordinateLockOverrides:
    """
    Members:
    
    eOVERRIDE_COORDINATE_LOCK_None
    
    eOVERRIDE_COORDINATE_LOCK_Axis
    
    eOVERRIDE_COORDINATE_LOCK_ACS
    
    eOVERRIDE_COORDINATE_LOCK_Grid
    
    eOVERRIDE_COORDINATE_LOCK_All
    """

    def __init__(self: MSPyDgnView.CoordinateLockOverrides, value: int) -> None:
        ...
    
    eOVERRIDE_COORDINATE_LOCK_ACS: CoordinateLockOverrides
    
    eOVERRIDE_COORDINATE_LOCK_All: CoordinateLockOverrides
    
    eOVERRIDE_COORDINATE_LOCK_Axis: CoordinateLockOverrides
    
    eOVERRIDE_COORDINATE_LOCK_Grid: CoordinateLockOverrides
    
    eOVERRIDE_COORDINATE_LOCK_None: CoordinateLockOverrides
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyDgnView.CoordinateLockOverrides) -> int:
        ...
    
class Dgn3DInputEvent:
    """
    None
    """

    def GetRotMagnitude(self: MSPyDgnView.Dgn3DInputEvent) -> float:
        ...
    
    def GetRotation(self: MSPyDgnView.Dgn3DInputEvent) -> MSPyBentleyGeom.DVec3d:
        ...
    
    def GetTime(self: MSPyDgnView.Dgn3DInputEvent) -> int:
        ...
    
    def GetTranslation(self: MSPyDgnView.Dgn3DInputEvent) -> MSPyBentleyGeom.DVec3d:
        ...
    
    @property
    def RotMagnitude(arg0: MSPyDgnView.Dgn3DInputEvent) -> float:
        ...
    
    @property
    def Rotation(arg0: MSPyDgnView.Dgn3DInputEvent) -> MSPyBentleyGeom.DVec3d:
        ...
    
    @property
    def Time(arg0: MSPyDgnView.Dgn3DInputEvent) -> int:
        ...
    
    @property
    def Translation(arg0: MSPyDgnView.Dgn3DInputEvent) -> MSPyBentleyGeom.DVec3d:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DgnButtonEvent:
    """
    None
    """

    @property
    def ButtonSource(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def CoordSource(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        ...
    
    def GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        """
        Get the source of this event.
        """
        ...
    
    def GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        :returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        """
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None:
        ...
    
    def IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    @property
    def KeyModifiers(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def Point(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point.setter
    def Point(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @property
    def RawPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None:
        """
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: MSPyDgnPlatform.IndexedViewport) -> None:
        """
        Set the viewport.
        """
        ...
    
    @property
    def ViewNum(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def ViewPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyDgnPlatform.IndexedViewport) -> None:
        ...
    
    def __init__(self: MSPyDgnView.DgnButtonEvent) -> None:
        ...
    
    eFROM_ElemSnap: CoordSource
    
    eFROM_Precision: CoordSource
    
    eFROM_TentativePoint: CoordSource
    
    eFROM_User: CoordSource
    
class DgnElementSetTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        """
        Can be called to force restart of active tool in response to an
        external event.
        
        See also:
        _OnRestartTool.
        """
        ...
    
    class ClipResult:
        """
        Members:
        
        eCLIP_RESULT_NotSupported
        
        eCLIP_RESULT_NewElements
        
        eCLIP_RESULT_OriginalElements
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ClipResult, value: int) -> None:
            ...
        
        eCLIP_RESULT_NewElements: ClipResult
        
        eCLIP_RESULT_NotSupported: ClipResult
        
        eCLIP_RESULT_OriginalElements: ClipResult
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ClipResult) -> int:
            ...
        
    @property
    def DynamicsStarted(arg0: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    class ElemSource:
        """
        Members:
        
        eSOURCE_Pick
        
        eSOURCE_Fence
        
        eSOURCE_SelectionSet
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ElemSource, value: int) -> None:
            ...
        
        eSOURCE_Fence: ElemSource
        
        eSOURCE_Pick: ElemSource
        
        eSOURCE_SelectionSet: ElemSource
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ElemSource) -> int:
            ...
        
    def EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        ...
    
    class ErrorNums:
        """
        Members:
        
        eERROR_NUM_NoFence
        
        eERROR_NUM_NoFenceElems
        
        eERROR_NUM_NoFenceElemsOutside
        
        eERROR_NUM_NoSSElems
        
        eERROR_NUM_NotSuportedElmType
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ErrorNums, value: int) -> None:
            ...
        
        eERROR_NUM_NoFence: ErrorNums
        
        eERROR_NUM_NoFenceElems: ErrorNums
        
        eERROR_NUM_NoFenceElemsOutside: ErrorNums
        
        eERROR_NUM_NoSSElems: ErrorNums
        
        eERROR_NUM_NotSuportedElmType: ErrorNums
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ErrorNums) -> int:
            ...
        
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda:
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool:
        ...
    
    @staticmethod
    def OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None:
        ...
    
    class RefLocateOption:
        """
        Members:
        
        eREF_LOCATE_Normal
        
        eREF_LOCATE_SelfAttachment
        
        eREF_LOCATE_Editable
        
        eREF_LOCATE_TreatAsElement
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.RefLocateOption, value: int) -> None:
            ...
        
        eREF_LOCATE_Editable: RefLocateOption
        
        eREF_LOCATE_Normal: RefLocateOption
        
        eREF_LOCATE_SelfAttachment: RefLocateOption
        
        eREF_LOCATE_TreatAsElement: RefLocateOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.RefLocateOption) -> int:
            ...
        
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None:
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    class UsesDragSelect:
        """
        Members:
        
        eUSES_DRAGSELECT_Box
        
        eUSES_DRAGSELECT_Line
        
        eUSES_DRAGSELECT_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesDragSelect, value: int) -> None:
            ...
        
        eUSES_DRAGSELECT_Box: UsesDragSelect
        
        eUSES_DRAGSELECT_Line: UsesDragSelect
        
        eUSES_DRAGSELECT_None: UsesDragSelect
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesDragSelect) -> int:
            ...
        
    class UsesFence:
        """
        Members:
        
        eUSES_FENCE_Check
        
        eUSES_FENCE_Required
        
        eUSES_FENCE_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesFence, value: int) -> None:
            ...
        
        eUSES_FENCE_Check: UsesFence
        
        eUSES_FENCE_None: UsesFence
        
        eUSES_FENCE_Required: UsesFence
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesFence) -> int:
            ...
        
    class UsesSelection:
        """
        Members:
        
        eUSES_SS_Check
        
        eUSES_SS_Required
        
        eUSES_SS_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesSelection, value: int) -> None:
            ...
        
        eUSES_SS_Check: UsesSelection
        
        eUSES_SS_None: UsesSelection
        
        eUSES_SS_Required: UsesSelection
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesSelection) -> int:
            ...
        
    def WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyDgnView.DgnElementSetTool) -> None
        
        2. __init__(self: MSPyDgnView.DgnElementSetTool, toolId: int) -> None
        """
        ...
    
    eCLIP_RESULT_NewElements: ClipResult
    
    eCLIP_RESULT_NotSupported: ClipResult
    
    eCLIP_RESULT_OriginalElements: ClipResult
    
    eERROR_NUM_NoFence: ErrorNums
    
    eERROR_NUM_NoFenceElems: ErrorNums
    
    eERROR_NUM_NoFenceElemsOutside: ErrorNums
    
    eERROR_NUM_NoSSElems: ErrorNums
    
    eERROR_NUM_NotSuportedElmType: ErrorNums
    
    eREF_LOCATE_Editable: RefLocateOption
    
    eREF_LOCATE_Normal: RefLocateOption
    
    eREF_LOCATE_SelfAttachment: RefLocateOption
    
    eREF_LOCATE_TreatAsElement: RefLocateOption
    
    eSOURCE_Fence: ElemSource
    
    eSOURCE_Pick: ElemSource
    
    eSOURCE_SelectionSet: ElemSource
    
    eUSES_DRAGSELECT_Box: UsesDragSelect
    
    eUSES_DRAGSELECT_Line: UsesDragSelect
    
    eUSES_DRAGSELECT_None: UsesDragSelect
    
    eUSES_FENCE_Check: UsesFence
    
    eUSES_FENCE_None: UsesFence
    
    eUSES_FENCE_Required: UsesFence
    
    eUSES_SS_Check: UsesSelection
    
    eUSES_SS_None: UsesSelection
    
    eUSES_SS_Required: UsesSelection
    
class DgnFlickEvent:
    """
    None
    """

    @property
    def ButtonSource(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def CoordSource(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        ...
    
    @property
    def FlickDirection(arg0: MSPyDgnView.DgnFlickEvent) -> MSPyDgnView.DgnFlickEvent.FlickDirection:
        ...
    
    def GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        """
        Get the source of this event.
        """
        ...
    
    def GetFlickDirection(self: MSPyDgnView.DgnFlickEvent) -> MSPyDgnView.DgnFlickEvent.FlickDirection:
        ...
    
    def GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        :returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        """
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None:
        ...
    
    def IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    @property
    def KeyModifiers(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def Point(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point.setter
    def Point(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @property
    def RawPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None:
        """
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: MSPyDgnPlatform.IndexedViewport) -> None:
        """
        Set the viewport.
        """
        ...
    
    @property
    def ViewNum(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def ViewPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyDgnPlatform.IndexedViewport) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eFLICKDIRECTION_Down: FlickDirection
    
    eFLICKDIRECTION_DownLeft: FlickDirection
    
    eFLICKDIRECTION_DownRight: FlickDirection
    
    eFLICKDIRECTION_Left: FlickDirection
    
    eFLICKDIRECTION_Right: FlickDirection
    
    eFLICKDIRECTION_Up: FlickDirection
    
    eFLICKDIRECTION_UpLeft: FlickDirection
    
    eFLICKDIRECTION_UpRight: FlickDirection
    
    eFROM_ElemSnap: CoordSource
    
    eFROM_Precision: CoordSource
    
    eFROM_TentativePoint: CoordSource
    
    eFROM_User: CoordSource
    
class DgnGestureEvent:
    """
    None
    """

    @property
    def ButtonSource(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def CoordSource(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        ...
    
    class GestureIds:
        """
        Members:
        
        eGESTUREID_Begin
        
        eGESTUREID_End
        
        eGESTUREID_Zoom
        
        eGESTUREID_Pan
        
        eGESTUREID_Rotate
        
        eGESTUREID_TwoFingerTap
        
        eGESTUREID_PressAndTap
        
        eGESTUREID_Rollover
        """
    
        def __init__(self: MSPyDgnView.DgnGestureEvent.GestureIds, value: int) -> None:
            ...
        
        eGESTUREID_Begin: GestureIds
        
        eGESTUREID_End: GestureIds
        
        eGESTUREID_Pan: GestureIds
        
        eGESTUREID_PressAndTap: GestureIds
        
        eGESTUREID_Rollover: GestureIds
        
        eGESTUREID_Rotate: GestureIds
        
        eGESTUREID_TwoFingerTap: GestureIds
        
        eGESTUREID_Zoom: GestureIds
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnGestureEvent.GestureIds) -> int:
            ...
        
    class GestureInfo:
        """
        None
        """
    
        @property
        def Distance(arg0: MSPyDgnView.DgnGestureEvent.GestureInfo) -> float:
            ...
        
        def GetDistance(self: MSPyDgnView.DgnGestureEvent.GestureInfo) -> float:
            ...
        
        def GetViewPoint(self: MSPyDgnView.DgnGestureEvent.GestureInfo, vp: MSPyDgnPlatform.IndexedViewport) -> MSPyBentleyGeom.DPoint3d:
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    def GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        """
        Get the source of this event.
        """
        ...
    
    def GetInfo(self: MSPyDgnView.DgnGestureEvent) -> MSPyDgnView.DgnGestureEvent.GestureInfo:
        ...
    
    def GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        :returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        """
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    @property
    def Info(arg0: MSPyDgnView.DgnGestureEvent) -> MSPyDgnView.DgnGestureEvent.GestureInfo:
        ...
    
    def Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None:
        ...
    
    def IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    @property
    def KeyModifiers(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def Point(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point.setter
    def Point(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @property
    def RawPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None:
        """
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: MSPyDgnPlatform.IndexedViewport) -> None:
        """
        Set the viewport.
        """
        ...
    
    @property
    def ViewNum(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def ViewPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyDgnPlatform.IndexedViewport) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eFROM_ElemSnap: CoordSource
    
    eFROM_Precision: CoordSource
    
    eFROM_TentativePoint: CoordSource
    
    eFROM_User: CoordSource
    
    eGESTUREID_Begin: GestureIds
    
    eGESTUREID_End: GestureIds
    
    eGESTUREID_Pan: GestureIds
    
    eGESTUREID_PressAndTap: GestureIds
    
    eGESTUREID_Rollover: GestureIds
    
    eGESTUREID_Rotate: GestureIds
    
    eGESTUREID_TwoFingerTap: GestureIds
    
    eGESTUREID_Zoom: GestureIds
    
class DgnMouseWheelEvent:
    """
    None
    """

    @property
    def ButtonSource(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def CoordSource(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        ...
    
    def GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        """
        Get the source of this event.
        """
        ...
    
    def GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        :returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        """
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def GetWheelDelta(self: MSPyDgnView.DgnMouseWheelEvent) -> int:
        """
        Get the " delta " movement of the mouse wheel (see Microsoft
        documentation on mouse wheel events for units.)
        """
        ...
    
    def Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None:
        ...
    
    def IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    @property
    def KeyModifiers(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def Point(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point.setter
    def Point(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @property
    def RawPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None:
        """
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: MSPyDgnPlatform.IndexedViewport) -> None:
        """
        Set the viewport.
        """
        ...
    
    @property
    def ViewNum(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def ViewPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyDgnPlatform.IndexedViewport) -> None:
        ...
    
    @property
    def WheelDelta(arg0: MSPyDgnView.DgnMouseWheelEvent) -> int:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eFROM_ElemSnap: CoordSource
    
    eFROM_Precision: CoordSource
    
    eFROM_TentativePoint: CoordSource
    
    eFROM_User: CoordSource
    
class DgnPrimitiveTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        """
        Can be called to force restart of active tool in response to an
        external event.
        
        See also:
        _OnRestartTool.
        """
        ...
    
    @property
    def DynamicsStarted(arg0: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        ...
    
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    def __init__(self: MSPyDgnView.DgnPrimitiveTool, toolId: int, toolPrompt: int) -> None:
        ...
    
class DgnRegionElementTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        """
        Can be called to force restart of active tool in response to an
        external event.
        
        See also:
        _OnRestartTool.
        """
        ...
    
    class ClipResult:
        """
        Members:
        
        eCLIP_RESULT_NotSupported
        
        eCLIP_RESULT_NewElements
        
        eCLIP_RESULT_OriginalElements
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ClipResult, value: int) -> None:
            ...
        
        eCLIP_RESULT_NewElements: ClipResult
        
        eCLIP_RESULT_NotSupported: ClipResult
        
        eCLIP_RESULT_OriginalElements: ClipResult
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ClipResult) -> int:
            ...
        
    @property
    def CurrentToolPhase(arg0: MSPyDgnView.DgnRegionElementTool) -> MSPyDgnView.DgnRegionElementTool.RegionToolPhase:
        ...
    
    @property
    def DynamicsStarted(arg0: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    class ElemSource:
        """
        Members:
        
        eSOURCE_Pick
        
        eSOURCE_Fence
        
        eSOURCE_SelectionSet
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ElemSource, value: int) -> None:
            ...
        
        eSOURCE_Fence: ElemSource
        
        eSOURCE_Pick: ElemSource
        
        eSOURCE_SelectionSet: ElemSource
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ElemSource) -> int:
            ...
        
    def EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        ...
    
    class ErrorNums:
        """
        Members:
        
        eERROR_NUM_NoFence
        
        eERROR_NUM_NoFenceElems
        
        eERROR_NUM_NoFenceElemsOutside
        
        eERROR_NUM_NoSSElems
        
        eERROR_NUM_NotSuportedElmType
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ErrorNums, value: int) -> None:
            ...
        
        eERROR_NUM_NoFence: ErrorNums
        
        eERROR_NUM_NoFenceElems: ErrorNums
        
        eERROR_NUM_NoFenceElemsOutside: ErrorNums
        
        eERROR_NUM_NoSSElems: ErrorNums
        
        eERROR_NUM_NotSuportedElmType: ErrorNums
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ErrorNums) -> int:
            ...
        
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetCurrentToolPhase(self: MSPyDgnView.DgnRegionElementTool) -> MSPyDgnView.DgnRegionElementTool.RegionToolPhase:
        ...
    
    def GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda:
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    def GetRegionContext(self: MSPyDgnView.DgnRegionElementTool) -> MSPyDgnPlatform.RegionGraphicsContext:
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def IsFloodRegionSelected(self: MSPyDgnView.DgnRegionElementTool) -> bool:
        ...
    
    def OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool:
        ...
    
    def OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None:
        ...
    
    class RefLocateOption:
        """
        Members:
        
        eREF_LOCATE_Normal
        
        eREF_LOCATE_SelfAttachment
        
        eREF_LOCATE_Editable
        
        eREF_LOCATE_TreatAsElement
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.RefLocateOption, value: int) -> None:
            ...
        
        eREF_LOCATE_Editable: RefLocateOption
        
        eREF_LOCATE_Normal: RefLocateOption
        
        eREF_LOCATE_SelfAttachment: RefLocateOption
        
        eREF_LOCATE_TreatAsElement: RefLocateOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.RefLocateOption) -> int:
            ...
        
    @property
    def RegionContext(arg0: MSPyDgnView.DgnRegionElementTool) -> MSPyDgnPlatform.RegionGraphicsContext:
        ...
    
    class RegionCreateMode:
        """
        Members:
        
        eREGION_CREATE_Elements
        
        eREGION_CREATE_ByParams
        
        eREGION_CREATE_Points
        
        eREGION_CREATE_Fence
        """
    
        def __init__(self: MSPyDgnView.DgnRegionElementTool.RegionCreateMode, value: int) -> None:
            ...
        
        eREGION_CREATE_ByParams: RegionCreateMode
        
        eREGION_CREATE_Elements: RegionCreateMode
        
        eREGION_CREATE_Fence: RegionCreateMode
        
        eREGION_CREATE_Points: RegionCreateMode
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnRegionElementTool.RegionCreateMode) -> int:
            ...
        
    class RegionToolPhase:
        """
        Members:
        
        eREGION_PHASE_SelectBoundaries
        
        eREGION_PHASE_CreateRegion
        
        eREGION_PHASE_ProcessOriginals
        """
    
        def __init__(self: MSPyDgnView.DgnRegionElementTool.RegionToolPhase, value: int) -> None:
            ...
        
        eREGION_PHASE_CreateRegion: RegionToolPhase
        
        eREGION_PHASE_ProcessOriginals: RegionToolPhase
        
        eREGION_PHASE_SelectBoundaries: RegionToolPhase
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnRegionElementTool.RegionToolPhase) -> int:
            ...
        
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None:
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    class UsesDragSelect:
        """
        Members:
        
        eUSES_DRAGSELECT_Box
        
        eUSES_DRAGSELECT_Line
        
        eUSES_DRAGSELECT_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesDragSelect, value: int) -> None:
            ...
        
        eUSES_DRAGSELECT_Box: UsesDragSelect
        
        eUSES_DRAGSELECT_Line: UsesDragSelect
        
        eUSES_DRAGSELECT_None: UsesDragSelect
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesDragSelect) -> int:
            ...
        
    class UsesFence:
        """
        Members:
        
        eUSES_FENCE_Check
        
        eUSES_FENCE_Required
        
        eUSES_FENCE_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesFence, value: int) -> None:
            ...
        
        eUSES_FENCE_Check: UsesFence
        
        eUSES_FENCE_None: UsesFence
        
        eUSES_FENCE_Required: UsesFence
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesFence) -> int:
            ...
        
    class UsesSelection:
        """
        Members:
        
        eUSES_SS_Check
        
        eUSES_SS_Required
        
        eUSES_SS_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesSelection, value: int) -> None:
            ...
        
        eUSES_SS_Check: UsesSelection
        
        eUSES_SS_None: UsesSelection
        
        eUSES_SS_Required: UsesSelection
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesSelection) -> int:
            ...
        
    def WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    def __init__(self: MSPyDgnView.DgnRegionElementTool) -> None:
        ...
    
    eCLIP_RESULT_NewElements: ClipResult
    
    eCLIP_RESULT_NotSupported: ClipResult
    
    eCLIP_RESULT_OriginalElements: ClipResult
    
    eERROR_NUM_NoFence: ErrorNums
    
    eERROR_NUM_NoFenceElems: ErrorNums
    
    eERROR_NUM_NoFenceElemsOutside: ErrorNums
    
    eERROR_NUM_NoSSElems: ErrorNums
    
    eERROR_NUM_NotSuportedElmType: ErrorNums
    
    eREF_LOCATE_Editable: RefLocateOption
    
    eREF_LOCATE_Normal: RefLocateOption
    
    eREF_LOCATE_SelfAttachment: RefLocateOption
    
    eREF_LOCATE_TreatAsElement: RefLocateOption
    
    eREGION_CREATE_ByParams: RegionCreateMode
    
    eREGION_CREATE_Elements: RegionCreateMode
    
    eREGION_CREATE_Fence: RegionCreateMode
    
    eREGION_CREATE_Points: RegionCreateMode
    
    eREGION_PHASE_CreateRegion: RegionToolPhase
    
    eREGION_PHASE_ProcessOriginals: RegionToolPhase
    
    eREGION_PHASE_SelectBoundaries: RegionToolPhase
    
    eSOURCE_Fence: ElemSource
    
    eSOURCE_Pick: ElemSource
    
    eSOURCE_SelectionSet: ElemSource
    
    eUSES_DRAGSELECT_Box: UsesDragSelect
    
    eUSES_DRAGSELECT_Line: UsesDragSelect
    
    eUSES_DRAGSELECT_None: UsesDragSelect
    
    eUSES_FENCE_Check: UsesFence
    
    eUSES_FENCE_None: UsesFence
    
    eUSES_FENCE_Required: UsesFence
    
    eUSES_SS_Check: UsesSelection
    
    eUSES_SS_None: UsesSelection
    
    eUSES_SS_Required: UsesSelection
    
class DgnTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    @staticmethod
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    @staticmethod
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    def __init__(self: MSPyDgnView.DgnTool, toolId: int, toolPrompt: int) -> None:
        ...
    
class DgnTouchEvent:
    """
    None
    """

    @property
    def ButtonSource(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def CoordSource(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        ...
    
    def GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource:
        """
        Get the source of this event.
        """
        ...
    
    def GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        :returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetTouches(self: MSPyDgnView.DgnTouchEvent) -> list:
        ...
    
    def GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int:
        """
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        """
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        """
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None:
        ...
    
    def IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool:
        """
        :returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    @property
    def KeyModifiers(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def Point(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point.setter
    def Point(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @property
    def RawPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None:
        """
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: MSPyDgnPlatform.IndexedViewport) -> None:
        """
        Set the viewport.
        """
        ...
    
    class TouchFlags:
        """
        Members:
        
        eTOUCHFLAGS_Move
        
        eTOUCHFLAGS_Down
        
        eTOUCHFLAGS_Up
        
        eTOUCHFLAGS_InRange
        
        eTOUCHFLAGS_Primary
        
        eTOUCHFLAGS_NoCoalesce
        
        eTOUCHFLAGS_Pen
        
        eTOUCHFLAGS_Palm
        """
    
        def __init__(self: MSPyDgnView.DgnTouchEvent.TouchFlags, value: int) -> None:
            ...
        
        eTOUCHFLAGS_Down: TouchFlags
        
        eTOUCHFLAGS_InRange: TouchFlags
        
        eTOUCHFLAGS_Move: TouchFlags
        
        eTOUCHFLAGS_NoCoalesce: TouchFlags
        
        eTOUCHFLAGS_Palm: TouchFlags
        
        eTOUCHFLAGS_Pen: TouchFlags
        
        eTOUCHFLAGS_Primary: TouchFlags
        
        eTOUCHFLAGS_Up: TouchFlags
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnTouchEvent.TouchFlags) -> int:
            ...
        
    class TouchInput:
        """
        None
        """
    
        def GetViewPoint(self: MSPyDgnView.DgnTouchEvent.TouchInput, vp: MSPyDgnPlatform.IndexedViewport) -> MSPyBentleyGeom.DPoint3d:
            ...
        
        def IsDown(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool:
            ...
        
        def IsMove(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool:
            ...
        
        def IsPrimary(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool:
            ...
        
        def IsUp(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool:
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    @property
    def Touches(arg0: MSPyDgnView.DgnTouchEvent) -> list:
        ...
    
    @property
    def ViewNum(arg0: MSPyDgnView.DgnButtonEvent) -> int:
        ...
    
    @property
    def ViewPoint(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> MSPyDgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: MSPyDgnPlatform.IndexedViewport) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eFROM_ElemSnap: CoordSource
    
    eFROM_Precision: CoordSource
    
    eFROM_TentativePoint: CoordSource
    
    eFROM_User: CoordSource
    
    eTOUCHFLAGS_Down: TouchFlags
    
    eTOUCHFLAGS_InRange: TouchFlags
    
    eTOUCHFLAGS_Move: TouchFlags
    
    eTOUCHFLAGS_NoCoalesce: TouchFlags
    
    eTOUCHFLAGS_Palm: TouchFlags
    
    eTOUCHFLAGS_Pen: TouchFlags
    
    eTOUCHFLAGS_Primary: TouchFlags
    
    eTOUCHFLAGS_Up: TouchFlags
    
class DgnViewTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    @staticmethod
    def GetPreferredViewport(unparsed: str, sourceToSearch: MSPyDgnView.DgnViewTool.PreferredView) -> tuple:
        """
        Call for viewing tools that have no tool settings or don't require a
        data point to determine if there is enough context in which to choose
        an initial viewport to use. Takes into account the preference for
        viewing tools to apply to the active view. For viewing tools on the
        view border, implement as an IconCmdX and setup
        HOOKITEMID_ViewBorderIconCmdHook in order to be passed the view number
        as unparsedP.
        
        :param sourceFoundP:
        (output) Source of preferred viewport.
        
        :param unparsedP:
        (input) unparsed string containing a view number or NULL.
        
        :param sourceToSearch:
        (input) Mask of allow sources for preferred viewport,
        PREFERRED_VIEW_Unparsed only used as an output, assumed if
        unparsedP isn't NULL.
        
        :returns:
        Preferred viewport for tool or NULL.
        """
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    class PreferredView:
        """
        Members:
        
        ePREFERRED_VIEW_None
        
        ePREFERRED_VIEW_Unparsed
        
        ePREFERRED_VIEW_Selected
        
        ePREFERRED_VIEW_Single
        """
    
        def __init__(self: MSPyDgnView.DgnViewTool.PreferredView, value: int) -> None:
            ...
        
        ePREFERRED_VIEW_None: PreferredView
        
        ePREFERRED_VIEW_Selected: PreferredView
        
        ePREFERRED_VIEW_Single: PreferredView
        
        ePREFERRED_VIEW_Unparsed: PreferredView
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnViewTool.PreferredView) -> int:
            ...
        
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    def __init__(self: MSPyDgnView.DgnViewTool, toolName: int, toolPrompt: int) -> None:
        ...
    
    ePREFERRED_VIEW_None: PreferredView
    
    ePREFERRED_VIEW_Selected: PreferredView
    
    ePREFERRED_VIEW_Single: PreferredView
    
    ePREFERRED_VIEW_Unparsed: PreferredView
    
class ElementGraphicsTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        """
        Can be called to force restart of active tool in response to an
        external event.
        
        See also:
        _OnRestartTool.
        """
        ...
    
    class ClipResult:
        """
        Members:
        
        eCLIP_RESULT_NotSupported
        
        eCLIP_RESULT_NewElements
        
        eCLIP_RESULT_OriginalElements
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ClipResult, value: int) -> None:
            ...
        
        eCLIP_RESULT_NewElements: ClipResult
        
        eCLIP_RESULT_NotSupported: ClipResult
        
        eCLIP_RESULT_OriginalElements: ClipResult
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ClipResult) -> int:
            ...
        
    @property
    def DynamicsStarted(arg0: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    class ElemSource:
        """
        Members:
        
        eSOURCE_Pick
        
        eSOURCE_Fence
        
        eSOURCE_SelectionSet
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ElemSource, value: int) -> None:
            ...
        
        eSOURCE_Fence: ElemSource
        
        eSOURCE_Pick: ElemSource
        
        eSOURCE_SelectionSet: ElemSource
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ElemSource) -> int:
            ...
        
    def EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        ...
    
    class ErrorNums:
        """
        Members:
        
        eERROR_NUM_NoFence
        
        eERROR_NUM_NoFenceElems
        
        eERROR_NUM_NoFenceElemsOutside
        
        eERROR_NUM_NoSSElems
        
        eERROR_NUM_NotSuportedElmType
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ErrorNums, value: int) -> None:
            ...
        
        eERROR_NUM_NoFence: ErrorNums
        
        eERROR_NUM_NoFenceElems: ErrorNums
        
        eERROR_NUM_NoFenceElemsOutside: ErrorNums
        
        eERROR_NUM_NoSSElems: ErrorNums
        
        eERROR_NUM_NotSuportedElmType: ErrorNums
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ErrorNums) -> int:
            ...
        
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetDisplayPath(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyDgnPlatform.DisplayPath:
        ...
    
    def GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda:
        ...
    
    def GetElementGraphicsCache(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle, geomCache: List[IRefCounted]) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetElementGraphicsCacheCount(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> int:
        ...
    
    def GetLocatedComponentPath(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> MSPyDgnPlatform.DisplayPath:
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def IsFromLocatedComponent(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsGeometryMissing(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> bool:
        ...
    
    def IsGeometrySheet(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsGeometrySolid(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsGeometryWire(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool:
        ...
    
    def OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None:
        ...
    
    class RefLocateOption:
        """
        Members:
        
        eREF_LOCATE_Normal
        
        eREF_LOCATE_SelfAttachment
        
        eREF_LOCATE_Editable
        
        eREF_LOCATE_TreatAsElement
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.RefLocateOption, value: int) -> None:
            ...
        
        eREF_LOCATE_Editable: RefLocateOption
        
        eREF_LOCATE_Normal: RefLocateOption
        
        eREF_LOCATE_SelfAttachment: RefLocateOption
        
        eREF_LOCATE_TreatAsElement: RefLocateOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.RefLocateOption) -> int:
            ...
        
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None:
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    def TryGetAsBRep(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyDgnPlatform.ISolidKernelEntity:
        ...
    
    def TryGetAsCurveVector(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.CurveVector:
        ...
    
    def TryGetAsPolyface(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.PolyfaceHeader:
        ...
    
    def TryGetAsPrimitive(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.ISolidPrimitive:
        ...
    
    def TryGetAsSurface(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.RefCountedMSBsplineSurface:
        ...
    
    class UsesDragSelect:
        """
        Members:
        
        eUSES_DRAGSELECT_Box
        
        eUSES_DRAGSELECT_Line
        
        eUSES_DRAGSELECT_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesDragSelect, value: int) -> None:
            ...
        
        eUSES_DRAGSELECT_Box: UsesDragSelect
        
        eUSES_DRAGSELECT_Line: UsesDragSelect
        
        eUSES_DRAGSELECT_None: UsesDragSelect
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesDragSelect) -> int:
            ...
        
    class UsesFence:
        """
        Members:
        
        eUSES_FENCE_Check
        
        eUSES_FENCE_Required
        
        eUSES_FENCE_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesFence, value: int) -> None:
            ...
        
        eUSES_FENCE_Check: UsesFence
        
        eUSES_FENCE_None: UsesFence
        
        eUSES_FENCE_Required: UsesFence
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesFence) -> int:
            ...
        
    class UsesSelection:
        """
        Members:
        
        eUSES_SS_Check
        
        eUSES_SS_Required
        
        eUSES_SS_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesSelection, value: int) -> None:
            ...
        
        eUSES_SS_Check: UsesSelection
        
        eUSES_SS_None: UsesSelection
        
        eUSES_SS_Required: UsesSelection
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesSelection) -> int:
            ...
        
    def WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    def __init__(self: MSPyDgnView.ElementGraphicsTool) -> None:
        ...
    
    eCLIP_RESULT_NewElements: ClipResult
    
    eCLIP_RESULT_NotSupported: ClipResult
    
    eCLIP_RESULT_OriginalElements: ClipResult
    
    eERROR_NUM_NoFence: ErrorNums
    
    eERROR_NUM_NoFenceElems: ErrorNums
    
    eERROR_NUM_NoFenceElemsOutside: ErrorNums
    
    eERROR_NUM_NoSSElems: ErrorNums
    
    eERROR_NUM_NotSuportedElmType: ErrorNums
    
    eREF_LOCATE_Editable: RefLocateOption
    
    eREF_LOCATE_Normal: RefLocateOption
    
    eREF_LOCATE_SelfAttachment: RefLocateOption
    
    eREF_LOCATE_TreatAsElement: RefLocateOption
    
    eSOURCE_Fence: ElemSource
    
    eSOURCE_Pick: ElemSource
    
    eSOURCE_SelectionSet: ElemSource
    
    eUSES_DRAGSELECT_Box: UsesDragSelect
    
    eUSES_DRAGSELECT_Line: UsesDragSelect
    
    eUSES_DRAGSELECT_None: UsesDragSelect
    
    eUSES_FENCE_Check: UsesFence
    
    eUSES_FENCE_None: UsesFence
    
    eUSES_FENCE_Required: UsesFence
    
    eUSES_SS_Check: UsesSelection
    
    eUSES_SS_None: UsesSelection
    
    eUSES_SS_Required: UsesSelection
    
class FenceManager:
    """
    None
    """

    @property
    def ActiveFenceClipFlags(arg0: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.FenceClipFlags:
        ...
    
    @property
    def ActiveFenceStretchFlags(arg0: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.FenceStretchFlags:
        ...
    
    def BuildAgenda(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, agenda: MSPyDgnPlatform.ElementAgenda, modelRefList: MSPyDgnPlatform.DgnModelRefList, modifyOrig: bool, allowLocked: bool, callAsynch: bool) -> int:
        """
        Collect elements that satisfy the supplied FenceParams/criteria.
        """
        ...
    
    def ClearFence(self: MSPyDgnView.FenceManager) -> None:
        """
        Clear any active points/element fence so that are is no longer a fence
        active.
        """
        ...
    
    def ClipElement(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, inside: MSPyDgnPlatform.ElementAgenda, outside: MSPyDgnPlatform.ElementAgenda, eh: MSPyDgnPlatform.ElementHandle, flags: MSPyDgnPlatform.FenceClipFlags) -> int:
        """
        Apply fence clip operation to input element.
        """
        ...
    
    def DefineByElement(self: MSPyDgnView.FenceManager, eh: MSPyDgnPlatform.ElementHandle, vp: MSPyDgnPlatform.Viewport) -> int:
        """
        Set active fence from an element.
        """
        ...
    
    def DefineByPoints(*args, **kwargs):
        """
        Overloaded function.
        
        1. DefineByPoints(self: MSPyDgnView.FenceManager, points: MSPyBentleyGeom.DPoint3dArray, vp: MSPyDgnPlatform.Viewport) -> int
        
        Set active fence by points.
        
        2. DefineByPoints(self: MSPyDgnView.FenceManager, points: list, vp: MSPyDgnPlatform.Viewport) -> int
        
        Set active fence by points.
        """
        ...
    
    def DisplayFence(self: MSPyDgnView.FenceManager, vp: MSPyDgnPlatform.Viewport, optTrans: MSPyBentleyGeom.Transform = None, optTransparency: Optional[int] = None) -> None:
        """
        For use in tools that manipulate fence contents. Draw transforms fence
        as a decorator.
        """
        ...
    
    class FenceDisplayMode:
        """
        Members:
        
        eFENCE_NormalDraw
        
        eFENCE_InhibitDraw
        
        eFENCE_InhibitFill
        """
    
        def __init__(self: MSPyDgnView.FenceManager.FenceDisplayMode, value: int) -> None:
            ...
        
        eFENCE_InhibitDraw: FenceDisplayMode
        
        eFENCE_InhibitFill: FenceDisplayMode
        
        eFENCE_NormalDraw: FenceDisplayMode
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.FenceManager.FenceDisplayMode) -> int:
            ...
        
    @property
    def FenceElem(arg0: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def FenceViewport(arg0: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.Viewport:
        ...
    
    def GetActiveFenceClipFlags(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.FenceClipFlags:
        """
        Get active fence clip behavior settings.
        """
        ...
    
    def GetActiveFenceStretchFlags(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.FenceStretchFlags:
        """
        Get active fence stretch behavior setting.
        """
        ...
    
    def GetFenceElem(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.ElementHandle:
        """
        Get the element for a fence defined by element.
        """
        ...
    
    def GetFencePoints(self: MSPyDgnView.FenceManager, points: MSPyBentleyGeom.DPoint3dArray) -> int:
        """
        Get the points for a fence defined by points.
        """
        ...
    
    def GetFenceViewport(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.Viewport:
        """
        Get the fence viewport for a fence defined by points.
        """
        ...
    
    @staticmethod
    def GetManager() -> MSPyDgnView.FenceManager:
        """
        Get the current FenceManager instance.
        """
        ...
    
    def InitFromActiveFence(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, overlap: bool, doClip: bool, allowClipFlag: MSPyDgnPlatform.FenceClipMode) -> int:
        """
        Populate the supplied FenceParams with information for the active
        fence.
        """
        ...
    
    def IsClipMode(self: MSPyDgnView.FenceManager) -> bool:
        """
        Return whether current fence mode is clip. Accept and clip elements
        that overlap the fence boundary.
        """
        ...
    
    def IsDefinedByElem(self: MSPyDgnView.FenceManager) -> bool:
        """
        Return whether a fence defined by element is currently active.
        """
        ...
    
    def IsDefinedByPoints(self: MSPyDgnView.FenceManager) -> bool:
        """
        Return whether a fence defined by points is currently active.
        """
        ...
    
    def IsFenceActive(self: MSPyDgnView.FenceManager) -> bool:
        """
        Return whether a fence is currently defined, either by points or
        element.
        """
        ...
    
    def IsOverlapMode(self: MSPyDgnView.FenceManager) -> bool:
        """
        Return whether current fence mode is overlap. Accept elements that
        overlap the fence boundary and aren't completely inside (or outside if
        void mode).
        """
        ...
    
    def IsVoidMode(self: MSPyDgnView.FenceManager) -> bool:
        """
        Return whether current fence mode is void. Accept elements outside
        fence.
        """
        ...
    
    def SetInhibitFenceDisplay(self: MSPyDgnView.FenceManager, inhibit: MSPyDgnView.FenceManager.FenceDisplayMode) -> None:
        """
        For use in tools that need to automate fence creation/processing and
        don't want the fence displayed in the view.
        """
        ...
    
    def StretchElement(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, eeh: MSPyDgnPlatform.EditElementHandle, transform: MSPyBentleyGeom.Transform, flags: MSPyDgnPlatform.FenceStretchFlags) -> int:
        """
        Apply fence stretch operation to input element.
        """
        ...
    
    def TransformFence(self: MSPyDgnView.FenceManager, transform: MSPyBentleyGeom.Transform) -> int:
        """
        Apply a transform to the active fence.
        """
        ...
    
    def UseActiveFence(self: MSPyDgnView.FenceManager) -> bool:
        """
        Check the active setting for whether a tool should use the fence if
        one is currently active.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eFENCE_InhibitDraw: FenceDisplayMode
    
    eFENCE_InhibitFill: FenceDisplayMode
    
    eFENCE_NormalDraw: FenceDisplayMode
    
class IModifyElement:
    """
    None
    """

    def __init__(self: MSPyDgnView.IModifyElement) -> None:
        ...
    
class IRedrawAbort:
    """
    None
    """

    def __init__(self: MSPyDgnView.IRedrawAbort) -> None:
        ...
    
class IRedrawOperation:
    """
    None
    """

    def __init__(self: MSPyDgnView.IRedrawOperation) -> None:
        ...
    
class ISelectionEvents:
    """
    None
    """

    def __init__(self: MSPyDgnView.ISelectionEvents) -> None:
        ...
    
class KeyModifierMasks:
    """
    Members:
    
    eKEYMODIFIER_ShiftKey
    
    eKEYMODIFIER_ControlKey
    
    eKEYMODIFIER_AltKey
    """

    def __init__(self: MSPyDgnView.KeyModifierMasks, value: int) -> None:
        ...
    
    eKEYMODIFIER_AltKey: KeyModifierMasks
    
    eKEYMODIFIER_ControlKey: KeyModifierMasks
    
    eKEYMODIFIER_ShiftKey: KeyModifierMasks
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyDgnView.KeyModifierMasks) -> int:
        ...
    
class LocateSubEntityTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        """
        Can be called to force restart of active tool in response to an
        external event.
        
        See also:
        _OnRestartTool.
        """
        ...
    
    class ClipResult:
        """
        Members:
        
        eCLIP_RESULT_NotSupported
        
        eCLIP_RESULT_NewElements
        
        eCLIP_RESULT_OriginalElements
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ClipResult, value: int) -> None:
            ...
        
        eCLIP_RESULT_NewElements: ClipResult
        
        eCLIP_RESULT_NotSupported: ClipResult
        
        eCLIP_RESULT_OriginalElements: ClipResult
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ClipResult) -> int:
            ...
        
    def DoPickFace(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, subEntity: MSPyDgnPlatform.ISubEntity, ev: MSPyDgnView.DgnButtonEvent, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool:
        ...
    
    def DoPickSubEntities(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, ev: MSPyDgnView.DgnButtonEvent, intersectEntities: MSPyDgnPlatform.ISubEntityPtrArray, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool:
        ...
    
    def DoPickSurfaces(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, ev: MSPyDgnView.DgnButtonEvent, intersectEntities: MSPyDgnPlatform.ISubEntityPtrArray, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool:
        ...
    
    @property
    def DynamicsStarted(arg0: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    class ElemSource:
        """
        Members:
        
        eSOURCE_Pick
        
        eSOURCE_Fence
        
        eSOURCE_SelectionSet
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ElemSource, value: int) -> None:
            ...
        
        eSOURCE_Fence: ElemSource
        
        eSOURCE_Pick: ElemSource
        
        eSOURCE_SelectionSet: ElemSource
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ElemSource) -> int:
            ...
        
    def EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None:
        ...
    
    class ErrorNums:
        """
        Members:
        
        eERROR_NUM_NoFence
        
        eERROR_NUM_NoFenceElems
        
        eERROR_NUM_NoFenceElemsOutside
        
        eERROR_NUM_NoSSElems
        
        eERROR_NUM_NotSuportedElmType
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.ErrorNums, value: int) -> None:
            ...
        
        eERROR_NUM_NoFence: ErrorNums
        
        eERROR_NUM_NoFenceElems: ErrorNums
        
        eERROR_NUM_NoFenceElemsOutside: ErrorNums
        
        eERROR_NUM_NoSSElems: ErrorNums
        
        eERROR_NUM_NotSuportedElmType: ErrorNums
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.ErrorNums) -> int:
            ...
        
    def EvaluateFace(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity, point: MSPyBentleyGeom.DPoint3d, normal: MSPyBentleyGeom.DVec3d, uDir: MSPyBentleyGeom.DVec3d, vDir: MSPyBentleyGeom.DVec3d, uvParam: MSPyBentleyGeom.DPoint2d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def FindAgendaEntry(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.EditElementHandle:
        ...
    
    def GetAcceptedSubEntities(self: MSPyDgnView.LocateSubEntityTool) -> MSPyDgnPlatform.ISubEntityPtrArray:
        ...
    
    def GetActivePrimitiveTool() -> MSPyDgnPlatform.DgnPrimitiveTool:
        ...
    
    def GetActiveViewTool() -> MSPyDgnView.DgnTool:
        ...
    
    def GetClosestFace(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, ev: MSPyDgnView.DgnButtonEvent, closePoint: MSPyBentleyGeom.DPoint3d, closeParam: MSPyBentleyGeom.DPoint2d) -> tuple:
        ...
    
    def GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to get a button event representing the current cursor location.
        
        :param ev:
        (input) Current button event.
        """
        ...
    
    def GetDisplayPath(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyDgnPlatform.DisplayPath:
        ...
    
    def GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda:
        ...
    
    def GetElementGraphicsCache(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle, geomCache: List[IRefCounted]) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetElementGraphicsCacheCount(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> int:
        ...
    
    def GetFaceParameterRange(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity, uRange: MSPyBentleyGeom.DRange1d, vRange: MSPyBentleyGeom.DRange1d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetIElementGraphics(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> IRefCounted:
        ...
    
    @staticmethod
    def GetLocateInfo(spacePoint: MSPyBentleyGeom.DPoint3d, viewToLocal: MSPyBentleyGeom.DMatrix4d, ev: MSPyDgnView.DgnButtonEvent, path: MSPyDgnPlatform.DisplayPath) -> float:
        """
        Compute locate information from button event GetRawPoint (adjusted to
        eye). The spacePoint and maxDistance are returned in local coordinates
        of path.
        """
        ...
    
    def GetLocatedComponentPath(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> MSPyDgnPlatform.DisplayPath:
        ...
    
    def GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple:
        """
        Called to get the previous modifier transition state.
        
        Returns (Tuple, 0):
        The id of the current command promnpt.
        
        Returns (Tuple, 1) :
        modifierKey.
        
        Returns (Tuple, 2):
        modifierKeyWentDown.
        
        Returns (Tuple, 3):
        currentQualifierMask.
        """
        ...
    
    @staticmethod
    def GetSpacePoint(spacePoint: MSPyBentleyGeom.DPoint3d, ev: MSPyDgnView.DgnButtonEvent, path: MSPyDgnPlatform.DisplayPath) -> None:
        """
        Compute space point from button event GetPoint. The spacePoint is
        returned in local coordinates of path.
        """
        ...
    
    def GetSubEntityGeometry(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> tuple:
        ...
    
    def GetToolId(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(self: MSPyDgnView.DgnTool) -> int:
        """
        Not used in Python implementation
        """
        ...
    
    @staticmethod
    def InitBoresite(boresite: MSPyBentleyGeom.DRay3d, spacePoint: MSPyBentleyGeom.DPoint3d, worldToLocal: MSPyBentleyGeom.DMatrix4d) -> None:
        """
        Compute boresite ray from space point and world to local matrix. (See
        GetLocateInfo).
        """
        ...
    
    def InstallTool(self: MSPyDgnView.DgnTool) -> int:
        """
        Call to make this tool instance the current active command.
        
        :returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def IsFromLocatedComponent(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsGeometryMissing(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> bool:
        ...
    
    def IsGeometrySheet(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsGeometrySolid(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsGeometryWire(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> bool:
        ...
    
    def IsSolidKernelSubEntity(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> bool:
        ...
    
    def OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool:
        ...
    
    def OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None:
        ...
    
    class RefLocateOption:
        """
        Members:
        
        eREF_LOCATE_Normal
        
        eREF_LOCATE_SelfAttachment
        
        eREF_LOCATE_Editable
        
        eREF_LOCATE_TreatAsElement
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.RefLocateOption, value: int) -> None:
            ...
        
        eREF_LOCATE_Editable: RefLocateOption
        
        eREF_LOCATE_Normal: RefLocateOption
        
        eREF_LOCATE_SelfAttachment: RefLocateOption
        
        eREF_LOCATE_TreatAsElement: RefLocateOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.RefLocateOption) -> int:
            ...
        
    def ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None:
        """
        Internal method to reset the current qualifier mask.
        
        :param mask:
        (input) New qualifier mask.
        """
        ...
    
    def ResetSubEntityLocate(self: MSPyDgnView.LocateSubEntityTool) -> None:
        ...
    
    def SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None:
        """
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        :param ev:
        (input) new button event.
        """
        ...
    
    def SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None:
        ...
    
    def SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None:
        """
        Called to set the current modifier transition state.
        
        :returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None:
        """
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None:
        """
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None:
        ...
    
    @property
    def ToolId(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolId.setter
    def ToolId(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    @property
    def ToolPrompt(arg0: MSPyDgnView.DgnTool) -> int:
        ...
    @ToolPrompt.setter
    def ToolPrompt(arg0: MSPyDgnView.DgnTool, arg1: int) -> None:
        ...
    
    def TryGetAsBRep(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyDgnPlatform.ISolidKernelEntity:
        ...
    
    def TryGetAsCurveLocationDetail(self: MSPyDgnView.LocateSubEntityTool, location: MSPyBentleyGeom.CurveLocationDetail, subEntity: MSPyDgnPlatform.ISubEntity) -> bool:
        ...
    
    def TryGetAsCurveVector(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.CurveVector:
        ...
    
    def TryGetAsFacetLocationDetail(self: MSPyDgnView.LocateSubEntityTool, location: MSPyBentleyGeom.FacetLocationDetail, subEntity: MSPyDgnPlatform.ISubEntity) -> bool:
        ...
    
    def TryGetAsPolyface(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.PolyfaceHeader:
        ...
    
    def TryGetAsPrimitive(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.ISolidPrimitive:
        ...
    
    def TryGetAsSolidLocationDetail(self: MSPyDgnView.LocateSubEntityTool, location: MSPyBentleyGeom.SolidLocationDetail, subEntity: MSPyDgnPlatform.ISubEntity) -> bool:
        ...
    
    def TryGetAsSurface(self: MSPyDgnView.ElementGraphicsTool, geom: IRefCounted) -> MSPyBentleyGeom.RefCountedMSBsplineSurface:
        ...
    
    class UsesDragSelect:
        """
        Members:
        
        eUSES_DRAGSELECT_Box
        
        eUSES_DRAGSELECT_Line
        
        eUSES_DRAGSELECT_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesDragSelect, value: int) -> None:
            ...
        
        eUSES_DRAGSELECT_Box: UsesDragSelect
        
        eUSES_DRAGSELECT_Line: UsesDragSelect
        
        eUSES_DRAGSELECT_None: UsesDragSelect
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesDragSelect) -> int:
            ...
        
    class UsesFence:
        """
        Members:
        
        eUSES_FENCE_Check
        
        eUSES_FENCE_Required
        
        eUSES_FENCE_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesFence, value: int) -> None:
            ...
        
        eUSES_FENCE_Check: UsesFence
        
        eUSES_FENCE_None: UsesFence
        
        eUSES_FENCE_Required: UsesFence
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesFence) -> int:
            ...
        
    class UsesSelection:
        """
        Members:
        
        eUSES_SS_Check
        
        eUSES_SS_Required
        
        eUSES_SS_None
        """
    
        def __init__(self: MSPyDgnView.DgnElementSetTool.UsesSelection, value: int) -> None:
            ...
        
        eUSES_SS_Check: UsesSelection
        
        eUSES_SS_None: UsesSelection
        
        eUSES_SS_Required: UsesSelection
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.DgnElementSetTool.UsesSelection) -> int:
            ...
        
    def WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool:
        ...
    
    def __init__(self: MSPyDgnView.LocateSubEntityTool) -> None:
        ...
    
    eCLIP_RESULT_NewElements: ClipResult
    
    eCLIP_RESULT_NotSupported: ClipResult
    
    eCLIP_RESULT_OriginalElements: ClipResult
    
    eERROR_NUM_NoFence: ErrorNums
    
    eERROR_NUM_NoFenceElems: ErrorNums
    
    eERROR_NUM_NoFenceElemsOutside: ErrorNums
    
    eERROR_NUM_NoSSElems: ErrorNums
    
    eERROR_NUM_NotSuportedElmType: ErrorNums
    
    eREF_LOCATE_Editable: RefLocateOption
    
    eREF_LOCATE_Normal: RefLocateOption
    
    eREF_LOCATE_SelfAttachment: RefLocateOption
    
    eREF_LOCATE_TreatAsElement: RefLocateOption
    
    eSOURCE_Fence: ElemSource
    
    eSOURCE_Pick: ElemSource
    
    eSOURCE_SelectionSet: ElemSource
    
    eUSES_DRAGSELECT_Box: UsesDragSelect
    
    eUSES_DRAGSELECT_Line: UsesDragSelect
    
    eUSES_DRAGSELECT_None: UsesDragSelect
    
    eUSES_FENCE_Check: UsesFence
    
    eUSES_FENCE_None: UsesFence
    
    eUSES_FENCE_Required: UsesFence
    
    eUSES_SS_Check: UsesSelection
    
    eUSES_SS_None: UsesSelection
    
    eUSES_SS_Required: UsesSelection
    
class ModifyOp:
    """
    None
    """

    def __init__(self: MSPyDgnView.ModifyOp) -> None:
        ...
    
class RedrawElems:
    """
    None
    """

    def AddViewport(self: MSPyDgnView.RedrawElems, vp: MSPyDgnPlatform.Viewport) -> None:
        """
        Add a view to the current list of views to display to.
        """
        ...
    
    def DoRedraw(*args, **kwargs):
        """
        Overloaded function.
        
        1. DoRedraw(self: MSPyDgnView.RedrawElems, elements: MSPyDgnPlatform.IElementSet) -> None
        
        Draw a set of elements, such as from an ElementAgenda.
        
        2. DoRedraw(self: MSPyDgnView.RedrawElems, eh: MSPyDgnPlatform.ElementHandle) -> None
        
        Draw a set of elements, such as from an ElementAgenda.
        
        3. DoRedraw(self: MSPyDgnView.RedrawElems, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef = None) -> None
        
        Draw a set of elements, such as from an ElementAgenda.
        
        4. DoRedraw(self: MSPyDgnView.RedrawElems, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef = None) -> None
        
        Draw a set of elements, such as from an ElementAgenda.
        
        5. DoRedraw(self: MSPyDgnView.RedrawElems, elemDescr: MSPyDgnPlatform.MSElementDescr, modelRef: MSPyDgnPlatform.DgnModelRef = None) -> None
        
        Draw a set of elements, such as from an ElementAgenda.
        
        6. DoRedraw(self: MSPyDgnView.RedrawElems, viewTrans: MSPyDgnPlatform.IViewTransients, isPreUpdate: bool = None) -> None
        
        Draw a set of elements, such as from an ElementAgenda.
        """
        ...
    
    def SetAbort(self: MSPyDgnView.RedrawElems, abort: MSPyDgnView.IRedrawAbort) -> None:
        """
        Supply an optional class to handle CheckStop/abort processing.
        """
        ...
    
    def SetClipVector(self: MSPyDgnView.RedrawElems, clip: MSPyDgnPlatform.ClipVector) -> None:
        """
        Supply an optional ClipVector to push before displaying elements.
        """
        ...
    
    def SetDrawMode(self: MSPyDgnView.RedrawElems, mode: MSPyDgnPlatform.DgnDrawMode) -> None:
        """
        Set DgnDrawMode to use for display. Use DRAW_MODE_TempDraw for
        dynamics.
        """
        ...
    
    def SetDrawPurpose(self: MSPyDgnView.RedrawElems, purpose: MSPyDgnPlatform.DrawPurpose) -> None:
        """
        Set DrawPurpose appropriate to display reason.
        """
        ...
    
    def SetDynamicsViews(self: MSPyDgnView.RedrawElems, viewSet: MSPyDgnPlatform.IndexedViewSet, cursorView: MSPyDgnPlatform.Viewport) -> None:
        """
        Set views for dynamic display. The cursor view is given priority.
        """
        ...
    
    def SetIgnoreHilite(self: MSPyDgnView.RedrawElems, ignore: bool) -> None:
        """
        Set to ignore locate/selection set hilite symbology when drawing a
        persistent element.
        """
        ...
    
    def SetOneView(self: MSPyDgnView.RedrawElems, viewSet: MSPyDgnPlatform.IndexedViewSet, view: int) -> None:
        """
        Set an individual viewport to display to by view number.
        """
        ...
    
    def SetRedrawOp(self: MSPyDgnView.RedrawElems, op: MSPyDgnView.IRedrawOperation) -> None:
        """
        Supply an optional class for element resymbolization and subsitution
        events.
        """
        ...
    
    def SetSearchDgnAttachments(self: MSPyDgnView.RedrawElems, other: bool) -> None:
        """
        When drawing an element, or list of elements to a Viewport, sometimes
        it is desirable to also search all other DgnModelRefs that are visible
        in that Viewport and, if the other modelref points to the same cache
        (but most likely with a different transform), also draw the element
        through that other modelRef. In general, most users should not enable
        this.
        """
        ...
    
    def SetTransform(self: MSPyDgnView.RedrawElems, trans: MSPyBentleyGeom.Transform) -> None:
        """
        Supply an optional transform to push before displaying elements.
        """
        ...
    
    def SetViewport(self: MSPyDgnView.RedrawElems, vp: MSPyDgnPlatform.Viewport) -> None:
        """
        Set an individual viewport to display to.
        """
        ...
    
    def SetViews(self: MSPyDgnView.RedrawElems, viewSet: MSPyDgnPlatform.IndexedViewSet, viewMask: int) -> None:
        """
        Set a mask of views (0-7) to display to.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyDgnView.RedrawElems) -> None
        
        2. __init__(self: MSPyDgnView.RedrawElems, vp: MSPyDgnPlatform.Viewport, drawMode: MSPyDgnPlatform.DgnDrawMode, purpose: MSPyDgnPlatform.DrawPurpose, otherAttachments: bool = False, op: MSPyDgnView.IRedrawOperation = None, clip: MSPyDgnPlatform.ClipVector = None, trans: MSPyBentleyGeom.Transform = None, abort: MSPyDgnView.IRedrawAbort = None) -> None
        """
        ...
    
class SelectionSetAction:
    """
    Members:
    
    eSELECT_NOTHING
    
    eSELECT_STRETCH
    
    eSELECT_WINDOW
    
    eSELECT_DRAG
    
    eSELECT_DRAG_NEW
    
    eSELECT_SS_EMPTY
    
    eSELECT_SS_CHANGED
    
    eSELECT_DOUBLECLICK_HANDLE
    
    eSELECT_DOUBLECLICK_ELEMENT
    """

    def __init__(self: MSPyDgnView.SelectionSetAction, value: int) -> None:
        ...
    
    eSELECT_DOUBLECLICK_ELEMENT: SelectionSetAction
    
    eSELECT_DOUBLECLICK_HANDLE: SelectionSetAction
    
    eSELECT_DRAG: SelectionSetAction
    
    eSELECT_DRAG_NEW: SelectionSetAction
    
    eSELECT_NOTHING: SelectionSetAction
    
    eSELECT_SS_CHANGED: SelectionSetAction
    
    eSELECT_SS_EMPTY: SelectionSetAction
    
    eSELECT_STRETCH: SelectionSetAction
    
    eSELECT_WINDOW: SelectionSetAction
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyDgnView.SelectionSetAction) -> int:
        ...
    
class SelectionSetManager:
    """
    None
    """

    def ActivatePrevious(self: MSPyDgnView.SelectionSetManager) -> None:
        """
        Make previous selection set current. Bentley Systems +---------------+
        ---------------+---------------+---------------+---------------+------
        """
        ...
    
    def AddElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus:
        """
        Add an element to the current selection set.
        
        :param elem:
        (input) Element to add.
        
        :param elemModel:
        (input) DgnModelRef of element being added.
        
        :returns:
        SUCCESS if entry was added. Bentley Systems +---------------+-----
        ----------+---------------+---------------+---------------+------
        """
        ...
    
    def AddElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus:
        """
        Add a set of elements to the current selection set.
        
        :param elSet:
        (input) Elements to add.
        
        :returns:
        SUCCESS if at least one entry was added. Bentley Systems +--------
        -------+---------------+---------------+---------------+----------
        -----+------
        """
        ...
    
    def AddListener(self: MSPyDgnView.SelectionSetManager, listener: MSPyDgnView.ISelectionEvents) -> None:
        """
        Add selection set changed/event listener.
        
        :param selectionListener:
        (input) The listener object to add. Bentley Systems +---------------+--
        -------------+---------------+---------------+---------------+----
        --
        """
        ...
    
    def BuildAgenda(*args, **kwargs):
        """
        Overloaded function.
        
        1. BuildAgenda(self: MSPyDgnView.SelectionSetManager, agenda: MSPyDgnPlatform.ElementAgenda, searchList: MSPyDgnPlatform.DgnModelRefList, modifyOrig: bool, allowLocked: bool, callAsynch: bool) -> int
        
        Populate an element agenda suitable for modification from the current
        selection set.
        
        :param agenda:
        (input) (output) selection set entries that passed the input criteria.
        
        :param searchList:
        (input) list of acceptable modelRefs to filter selection set entries..
        
        :param modifyOrig:
        (input) whether agenda will be used to modify original elements.
        
        :param allowLocked:
        (input) whether to accept locked elements.
        
        :param callAsynch:
        (input) whether to call GLOBAL_LOCATE_SELECTIONSET filter.
        
        :returns:
        SUCCESS if agenda contains at least one entry. Bentley Systems +--
        -------------+---------------+---------------+---------------+----
        -----------+------
        
        2. BuildAgenda(self: MSPyDgnView.SelectionSetManager, agenda: MSPyDgnPlatform.ElementAgenda) -> int
        
        Populate an element agenda suitable for modification from the current
        selection set.
        
        :param agenda:
        (input) (output) selection set entries that passed the input criteria.
        
        :param searchList:
        (input) list of acceptable modelRefs to filter selection set entries..
        
        :param modifyOrig:
        (input) whether agenda will be used to modify original elements.
        
        :param allowLocked:
        (input) whether to accept locked elements.
        
        :param callAsynch:
        (input) whether to call GLOBAL_LOCATE_SELECTIONSET filter.
        
        :returns:
        SUCCESS if agenda contains at least one entry. Bentley Systems +--
        -------------+---------------+---------------+---------------+----
        -----------+------
        """
        ...
    
    def DropListener(self: MSPyDgnView.SelectionSetManager, listener: MSPyDgnView.ISelectionEvents) -> None:
        """
        Drop selection set changed/event listener.
        
        :param selectionListener:
        (input) The listener object to drop. Bentley Systems +---------------+-
        --------------+---------------+---------------+---------------+---
        ---
        """
        ...
    
    def EmptyAll(self: MSPyDgnView.SelectionSetManager) -> None:
        """
        Clear current selection set. Current selection set becomes previous
        selection set. Bentley Systems +---------------+---------------+------
        ---------+---------------+---------------+------
        """
        ...
    
    def GetElement(self: MSPyDgnView.SelectionSetManager, index: int, eh: MSPyDgnPlatform.ElementHandle) -> int:
        """
        Get the ElementRefP and DgnModelRef in the current selection set by
        index.
        
        :param index:
        (input) The index to get the entry for.
        
        :param elemRef:
        (output) ElementRefP at index.
        
        :param modelRef:
        (output) DgnModelRef at index.
        
        :returns:
        SUCCESS if index was valid. Bentley Systems +---------------+-----
        ----------+---------------+---------------+---------------+------
        """
        ...
    
    @staticmethod
    def GetManager() -> MSPyDgnView.SelectionSetManager:
        """
        Get the manager class for selection sets.
        
        :returns:
        The SelectionSetManager class. Bentley Systems +---------------+--
        -------------+---------------+---------------+---------------+----
        --
        """
        ...
    
    def InvertElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus:
        """
        Add element not currently selected and remove element currently
        selected.
        
        :param elem:
        (input) Element to process.
        
        :param elemModel:
        (input) DgnModelRef of element being processed.
        
        :returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def InvertElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus:
        """
        Add elements not currently selected and remove elements currently
        selected.
        
        :param elSet:
        (input) Elements to process.
        
        :returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def IsActive(self: MSPyDgnView.SelectionSetManager) -> bool:
        """
        Check whether there is a current selection set active.
        
        :returns:
        true if current selection set contains at least one entry. Bentley
        Systems +---------------+---------------+---------------+---------
        ------+---------------+------
        """
        ...
    
    Manager: SelectionSetManager
    
    def ModifyWithElementSets(self: MSPyDgnView.SelectionSetManager, toRemove: MSPyDgnPlatform.IElementSet, toAdd: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus:
        """
        Modifies current selection by removing and adding sets of elements.
        
        :param toRemove:
        (input) Elements to remove.
        
        :param toAdd:
        (input) Elements to add.
        
        :returns:
        SUCCESS if at least one entry was added or removed. @note Remove
        list is processed before add list. Bentley Systems +--------------
        -+---------------+---------------+---------------+---------------+
        ------
        """
        ...
    
    def NumSelected(self: MSPyDgnView.SelectionSetManager) -> int:
        """
        Get the number of entries in the current selection set.
        
        :returns:
        count of entries in current selection set. Bentley Systems +------
        ---------+---------------+---------------+---------------+--------
        -------+------
        """
        ...
    
    def RemoveElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus:
        """
        Remove an element from the current selection set.
        
        :param elem:
        (input) Element to remove.
        
        :param elemModel:
        (input) DgnModelRef of element being removed.
        
        :returns:
        SUCCESS if entry was removed. Bentley Systems +---------------+---
        ------------+---------------+---------------+---------------+-----
        -
        """
        ...
    
    def RemoveElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus:
        """
        Remove a set of elements to the current selection set.
        
        :param elSet:
        (input) Elements to remove.
        
        :returns:
        SUCCESS if at least one entry was removed. Bentley Systems +------
        ---------+---------------+---------------+---------------+--------
        -------+------
        """
        ...
    
    def ReplaceWithElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus:
        """
        Set the current selection set to the supplied element.
        
        :param elem:
        (input) Element to become new selection.
        
        :param elemModel:
        (input) DgnModelRef of replacement element.
        
        :returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def ReplaceWithElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus:
        """
        Set the current selection set to the supplied set of elements.
        
        :param elSet:
        (input) Elements to become current selection.
        
        :returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class TentativePoint:
    """
    None
    """

    def Clear(self: MSPyDgnView.TentativePoint, erase: bool) -> None:
        """
        Clear the current tentative point so that it is no longer active.
        """
        ...
    
    @staticmethod
    def GetInstance() -> MSPyDgnView.TentativePoint:
        """
        Get the current TentativePoint instance.
        """
        ...
    
    def GetPoint(self: MSPyDgnView.TentativePoint) -> MSPyBentleyGeom.DPoint3d:
        """
        :returns:
        The current tentative point location as adjusted by the snap mode
        and locks.
        """
        ...
    
    Instance: TentativePoint
    
    def IsActive(self: MSPyDgnView.TentativePoint) -> bool:
        """
        :returns:
        true if the tentative point is currently active.
        """
        ...
    
    def IsSnapped(self: MSPyDgnView.TentativePoint) -> bool:
        """
        :returns:
        true if the tentative point is currently active and snapped to an
        element.
        """
        ...
    
    @property
    def Point(arg0: MSPyDgnView.TentativePoint) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
eACCUDRAW_AllowStartInLocate: AccuDrawFlags

eACCUDRAW_AlwaysSetOrigin: AccuDrawFlags

eACCUDRAW_Delay: AccuDrawFlags

eACCUDRAW_Disable: AccuDrawFlags

eACCUDRAW_FixedOrigin: AccuDrawFlags

eACCUDRAW_LockAngle: AccuDrawFlags

eACCUDRAW_LockDistance: AccuDrawFlags

eACCUDRAW_Lock_X: AccuDrawFlags

eACCUDRAW_Lock_Y: AccuDrawFlags

eACCUDRAW_Lock_Z: AccuDrawFlags

eACCUDRAW_OrientACS: AccuDrawFlags

eACCUDRAW_OrientDefault: AccuDrawFlags

eACCUDRAW_RedrawCompass: AccuDrawFlags

eACCUDRAW_Set3dMatrix: AccuDrawFlags

eACCUDRAW_SetDistance: AccuDrawFlags

eACCUDRAW_SetFocus: AccuDrawFlags

eACCUDRAW_SetModePolar: AccuDrawFlags

eACCUDRAW_SetModeRect: AccuDrawFlags

eACCUDRAW_SetNormal: AccuDrawFlags

eACCUDRAW_SetOrigin: AccuDrawFlags

eACCUDRAW_SetRMatrix: AccuDrawFlags

eACCUDRAW_SetXAxis: AccuDrawFlags

eACCUDRAW_SetXAxis2: AccuDrawFlags

eACCUDRAW_UpdateRotation: AccuDrawFlags

eACCUSNAP_ENABLE_Never: AccuSnapEnableFlag

eACCUSNAP_ENABLE_OffByDefault: AccuSnapEnableFlag

eACCUSNAP_ENABLE_OnByDefault: AccuSnapEnableFlag

eKEYMODIFIER_AltKey: KeyModifierMasks

eKEYMODIFIER_ControlKey: KeyModifierMasks

eKEYMODIFIER_ShiftKey: KeyModifierMasks

eOVERRIDE_COORDINATE_LOCK_ACS: CoordinateLockOverrides

eOVERRIDE_COORDINATE_LOCK_All: CoordinateLockOverrides

eOVERRIDE_COORDINATE_LOCK_Axis: CoordinateLockOverrides

eOVERRIDE_COORDINATE_LOCK_Grid: CoordinateLockOverrides

eOVERRIDE_COORDINATE_LOCK_None: CoordinateLockOverrides

eSELECT_DOUBLECLICK_ELEMENT: SelectionSetAction

eSELECT_DOUBLECLICK_HANDLE: SelectionSetAction

eSELECT_DRAG: SelectionSetAction

eSELECT_DRAG_NEW: SelectionSetAction

eSELECT_NOTHING: SelectionSetAction

eSELECT_SS_CHANGED: SelectionSetAction

eSELECT_SS_EMPTY: SelectionSetAction

eSELECT_STRETCH: SelectionSetAction

eSELECT_WINDOW: SelectionSetAction

