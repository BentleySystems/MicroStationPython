from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyDgnView

class AccuDraw:
    """
    None
    """

    def Activate(*args, **kwargs):
        """
        Activate(self: MSPyDgnView.AccuDraw) -> None
        
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
    def CompassViewport(arg0: MSPyDgnView.AccuDraw) -> Bentley.DgnPlatform.IndexedViewport:
        ...
    
    def Deactivate(*args, **kwargs):
        """
        Deactivate(self: MSPyDgnView.AccuDraw) -> None
        
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
    
    def GetAngle(*args, **kwargs):
        """
        GetAngle(self: MSPyDgnView.AccuDraw) -> float
        
        Current compass polar angle
        """
        ...
    
    def GetCompassMode(*args, **kwargs):
        """
        GetCompassMode(self: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.CompassMode
        
        Current compass mode
        """
        ...
    
    def GetCompassViewport(*args, **kwargs):
        """
        GetCompassViewport(self: MSPyDgnView.AccuDraw) -> Bentley.DgnPlatform.IndexedViewport
        
        Current compass viewport
        """
        ...
    
    def GetDelta(*args, **kwargs):
        """
        GetDelta(self: MSPyDgnView.AccuDraw, delta: MSPyBentleyGeom.DVec3d) -> None
        
        Current compass xyz delta
        """
        ...
    
    def GetDistance(*args, **kwargs):
        """
        GetDistance(self: MSPyDgnView.AccuDraw) -> float
        
        Current compass polar distance
        """
        ...
    
    def GetFloatingOrigin(*args, **kwargs):
        """
        GetFloatingOrigin(self: MSPyDgnView.AccuDraw) -> bool
        
        Current compass floating origin setting
        """
        ...
    
    def GetInstance(*args, **kwargs):
        """
        GetInstance() -> MSPyDgnView.AccuDraw
        
        Get the current AccuDraw instance.
        """
        ...
    
    def GetLocked(*args, **kwargs):
        """
        GetLocked(self: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.LockedStates
        
        Current compass locks bitmask
        """
        ...
    
    def GetOrigin(*args, **kwargs):
        """
        GetOrigin(self: MSPyDgnView.AccuDraw, origin: MSPyBentleyGeom.DPoint3d) -> None
        
        Current compass origin
        """
        ...
    
    def GetRotation(*args, **kwargs):
        """
        GetRotation(self: MSPyDgnView.AccuDraw, rMatrix: MSPyBentleyGeom.RotMatrix) -> None
        
        Current compass orientation
        """
        ...
    
    def GetRotationMode(*args, **kwargs):
        """
        GetRotationMode(self: MSPyDgnView.AccuDraw) -> MSPyDgnView.AccuDraw.RotationMode
        
        Current compass rotation type
        """
        ...
    
    def IsActive(*args, **kwargs):
        """
        IsActive(self: MSPyDgnView.AccuDraw) -> bool
        
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
    
    def SetContext(*args, **kwargs):
        """
        SetContext(self: MSPyDgnView.AccuDraw, flags: MSPyDgnView.AccuDrawFlags, origin: MSPyBentleyGeom.DPoint3d = None, orientation: MSPyBentleyGeom.DVec3d = None, delta: MSPyBentleyGeom.DVec3d = None, distance: Optional[float] = None, angle: Optional[float] = None, trans: MSPyBentleyGeom.Transform = None) -> MSPyDgnPlatform.BentleyStatus
        
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

    def AddEventHandler(*args, **kwargs):
        """
        AddEventHandler(accuSnapHandler: MSPyDgnView.AccuSnapHandler) -> None
        
        Add a new AccuSnapHandler to the list of installed AccuSnapHandlers.
        
        Parameter ``accuSnapHandler``:
        New AccuSnapHandler to add
        """
        ...
    
    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyDgnView.AccuSnap) -> None
        
        Clear the current AccuSnap/AutoLocate path so that it is no longer
        snapped or hilited.
        """
        ...
    
    @property
    def CurrHit(arg0: MSPyDgnView.AccuSnap) -> MSPyDgnPlatform.HitPath:
        ...
    
    def DropEventHandler(*args, **kwargs):
        """
        DropEventHandler(accuSnapHandler: MSPyDgnView.AccuSnapHandler) -> None
        
        Drop an AccuSnapHandler from list of installed AccuSnapHandlers. After
        this call, handler will not be notified of future AccuSnapHandler
        events.
        
        Parameter ``accuSnapHandler``:
        the AccuSnapHandler to drop.
        """
        ...
    
    def EnableLocate(*args, **kwargs):
        """
        EnableLocate(self: MSPyDgnView.AccuSnap, yesNo: bool) -> None
        
        Set the enabled state of AutoLocate for the current tool @note Even if
        yesNo is true, AutoLocate will not be enabled unless the user has also
        enabled it.
        """
        ...
    
    def EnableSnap(*args, **kwargs):
        """
        EnableSnap(self: MSPyDgnView.AccuSnap, yesNo: bool) -> None
        
        Set the enabled state of AccuSnap for the current tool @note Even if
        yesNo is true, AccuSnap will not be enabled unless the user has also
        enabled it.
        """
        ...
    
    def GetCurrHit(*args, **kwargs):
        """
        GetCurrHit(self: MSPyDgnView.AccuSnap) -> MSPyDgnPlatform.HitPath
        """
        ...
    
    def GetInstance(*args, **kwargs):
        """
        GetInstance() -> MSPyDgnView.AccuSnap
        
        Get the current AccuSnap instance.
        """
        ...
    
    Instance: AccuSnap
    
    def IsActive(*args, **kwargs):
        """
        IsActive(self: MSPyDgnView.AccuSnap, ev: Bentley.DgnPlatform.DgnButtonEvent) -> bool
        
        Determine whether AccuSnap is currently active. To be active both the
        tool and the user must indicate that they want it.
        
        Parameter ``ev``:
        The current button event. Used to check the modifier keys that can
        temporarily enable/disable AccuSnap.
        
        Returns:
        true if active.
        """
        ...
    
    def IsHot(*args, **kwargs):
        """
        IsHot(self: MSPyDgnView.AccuSnap) -> bool
        
        Returns:
        true if AccuSnap is currently active and snapped to an element.
        """
        ...
    
    def IsLocateEnabled(*args, **kwargs):
        """
        IsLocateEnabled(self: MSPyDgnView.AccuSnap) -> bool
        
        Returns:
        true if AutoLocate has been enabled by the current tool.
        """
        ...
    
    def IsSnapEnabled(*args, **kwargs):
        """
        IsSnapEnabled(self: MSPyDgnView.AccuSnap) -> bool
        
        Returns:
        true if AccuSnap has been enabled by the current tool.
        """
        ...
    
    def ResetButton(*args, **kwargs):
        """
        ResetButton(self: MSPyDgnView.AccuSnap) -> MSPyDgnPlatform.SnapStatus
        
        Can be called by tools to advance to the next AccuSnap/AutoLocate hit
        path when more than one element is under the cursor. @note Used in
        default implementation of DgnElementSetTool._OnResetButton.
        """
        ...
    
    def SetComponentMode(*args, **kwargs):
        """
        SetComponentMode(self: MSPyDgnView.AccuSnap, mode: Bentley.DgnPlatform.ComponentMode) -> None
        
        @note Resets to default value of ComponentMode.None whenever locate
        is enabled.
        """
        ...
    
    def Suspend(*args, **kwargs):
        """
        Suspend(self: MSPyDgnView.AccuSnap, doSuspend: bool) -> None
        
        Can be called by a tool to temporarily suspend Accusnap. Calls to this
        function should be paired.
        
        Parameter ``doSuspend``:
        true to suspend AccuSnap, false to resume it.
        """
        ...
    
    def UserWantsLocates(*args, **kwargs):
        """
        UserWantsLocates(self: MSPyDgnView.AccuSnap) -> bool
        
        Returns:
        true if the user has enabled AutoLocate. Controlled by " Identify Elements Automatically " preference.
        """
        ...
    
    def UserWantsSnaps(*args, **kwargs):
        """
        UserWantsSnaps(self: MSPyDgnView.AccuSnap) -> bool
        
        Returns:
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

    def GetRotMagnitude(*args, **kwargs):
        """
        GetRotMagnitude(self: MSPyDgnView.Dgn3DInputEvent) -> float
        """
        ...
    
    def GetRotation(*args, **kwargs):
        """
        GetRotation(self: MSPyDgnView.Dgn3DInputEvent) -> MSPyBentleyGeom.DVec3d
        """
        ...
    
    def GetTime(*args, **kwargs):
        """
        GetTime(self: MSPyDgnView.Dgn3DInputEvent) -> int
        """
        ...
    
    def GetTranslation(*args, **kwargs):
        """
        GetTranslation(self: MSPyDgnView.Dgn3DInputEvent) -> MSPyBentleyGeom.DVec3d
        """
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
    
    def GetButtonSource(*args, **kwargs):
        """
        GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(*args, **kwargs):
        """
        GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource
        
        Get the source of this event.
        """
        ...
    
    def GetKeyModifiers(*args, **kwargs):
        """
        GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(*args, **kwargs):
        """
        GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(*args, **kwargs):
        """
        GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(*args, **kwargs):
        """
        GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(*args, **kwargs):
        """
        GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(*args, **kwargs):
        """
        GetViewport(self: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport
        
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def Invalidate(*args, **kwargs):
        """
        Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None
        """
        ...
    
    def IsAltKey(*args, **kwargs):
        """
        IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(*args, **kwargs):
        """
        IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(*args, **kwargs):
        """
        IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def SetPoint(*args, **kwargs):
        """
        SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None
        
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: Bentley.DgnPlatform.IndexedViewport) -> None
        
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
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: Bentley.DgnPlatform.IndexedViewport) -> None:
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
    
class DgnElementSetTool:
    """
    None
    """

    ActivePrimitiveTool: DgnPrimitiveTool
    
    ActiveViewTool: NoneType
    
    def CallOnRestartTool(*args, **kwargs):
        """
        CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None
        
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
        
    def EnableUndoPreviousStep(*args, **kwargs):
        """
        EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None
        """
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
        
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetDynamicsStarted(*args, **kwargs):
        """
        GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool
        """
        ...
    
    def GetElementAgenda(*args, **kwargs):
        """
        GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def OnModifierKeyTransitionHelper(*args, **kwargs):
        """
        OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool
        """
        ...
    
    def OutputErrorMessage(*args, **kwargs):
        """
        OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None
        """
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
        
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(*args, **kwargs):
        """
        SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None
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
        
    def WantAdditionalLocateHelper(*args, **kwargs):
        """
        WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def GetButtonSource(*args, **kwargs):
        """
        GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(*args, **kwargs):
        """
        GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource
        
        Get the source of this event.
        """
        ...
    
    def GetFlickDirection(*args, **kwargs):
        """
        GetFlickDirection(self: MSPyDgnView.DgnFlickEvent) -> MSPyDgnView.DgnFlickEvent.FlickDirection
        """
        ...
    
    def GetKeyModifiers(*args, **kwargs):
        """
        GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(*args, **kwargs):
        """
        GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(*args, **kwargs):
        """
        GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(*args, **kwargs):
        """
        GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(*args, **kwargs):
        """
        GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(*args, **kwargs):
        """
        GetViewport(self: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport
        
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def Invalidate(*args, **kwargs):
        """
        Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None
        """
        ...
    
    def IsAltKey(*args, **kwargs):
        """
        IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(*args, **kwargs):
        """
        IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(*args, **kwargs):
        """
        IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def SetPoint(*args, **kwargs):
        """
        SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None
        
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: Bentley.DgnPlatform.IndexedViewport) -> None
        
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
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: Bentley.DgnPlatform.IndexedViewport) -> None:
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
        
        def GetDistance(*args, **kwargs):
            """
            GetDistance(self: MSPyDgnView.DgnGestureEvent.GestureInfo) -> float
            """
            ...
        
        def GetViewPoint(*args, **kwargs):
            """
            GetViewPoint(self: MSPyDgnView.DgnGestureEvent.GestureInfo, vp: Bentley.DgnPlatform.IndexedViewport) -> MSPyBentleyGeom.DPoint3d
            """
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    def GetButtonSource(*args, **kwargs):
        """
        GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(*args, **kwargs):
        """
        GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource
        
        Get the source of this event.
        """
        ...
    
    def GetInfo(*args, **kwargs):
        """
        GetInfo(self: MSPyDgnView.DgnGestureEvent) -> MSPyDgnView.DgnGestureEvent.GestureInfo
        """
        ...
    
    def GetKeyModifiers(*args, **kwargs):
        """
        GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(*args, **kwargs):
        """
        GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(*args, **kwargs):
        """
        GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(*args, **kwargs):
        """
        GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(*args, **kwargs):
        """
        GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(*args, **kwargs):
        """
        GetViewport(self: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport
        
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    @property
    def Info(arg0: MSPyDgnView.DgnGestureEvent) -> MSPyDgnView.DgnGestureEvent.GestureInfo:
        ...
    
    def Invalidate(*args, **kwargs):
        """
        Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None
        """
        ...
    
    def IsAltKey(*args, **kwargs):
        """
        IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(*args, **kwargs):
        """
        IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(*args, **kwargs):
        """
        IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def SetPoint(*args, **kwargs):
        """
        SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None
        
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: Bentley.DgnPlatform.IndexedViewport) -> None
        
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
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: Bentley.DgnPlatform.IndexedViewport) -> None:
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
    
    def GetButtonSource(*args, **kwargs):
        """
        GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(*args, **kwargs):
        """
        GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource
        
        Get the source of this event.
        """
        ...
    
    def GetKeyModifiers(*args, **kwargs):
        """
        GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(*args, **kwargs):
        """
        GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(*args, **kwargs):
        """
        GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetViewNum(*args, **kwargs):
        """
        GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(*args, **kwargs):
        """
        GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(*args, **kwargs):
        """
        GetViewport(self: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport
        
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def GetWheelDelta(*args, **kwargs):
        """
        GetWheelDelta(self: MSPyDgnView.DgnMouseWheelEvent) -> int
        
        Get the " delta " movement of the mouse wheel (see Microsoft
        documentation on mouse wheel events for units.)
        """
        ...
    
    def Invalidate(*args, **kwargs):
        """
        Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None
        """
        ...
    
    def IsAltKey(*args, **kwargs):
        """
        IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(*args, **kwargs):
        """
        IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(*args, **kwargs):
        """
        IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def SetPoint(*args, **kwargs):
        """
        SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None
        
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: Bentley.DgnPlatform.IndexedViewport) -> None
        
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
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: Bentley.DgnPlatform.IndexedViewport) -> None:
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
    
    def CallOnRestartTool(*args, **kwargs):
        """
        CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None
        
        Can be called to force restart of active tool in response to an
        external event.
        
        See also:
        _OnRestartTool.
        """
        ...
    
    @property
    def DynamicsStarted(arg0: MSPyDgnView.DgnPrimitiveTool) -> bool:
        ...
    
    def EnableUndoPreviousStep(*args, **kwargs):
        """
        EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None
        """
        ...
    
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetDynamicsStarted(*args, **kwargs):
        """
        GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
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
    
    def CallOnRestartTool(*args, **kwargs):
        """
        CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None
        
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
        
    def EnableUndoPreviousStep(*args, **kwargs):
        """
        EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None
        """
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
        
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetCurrentToolPhase(*args, **kwargs):
        """
        GetCurrentToolPhase(self: MSPyDgnView.DgnRegionElementTool) -> MSPyDgnView.DgnRegionElementTool.RegionToolPhase
        """
        ...
    
    def GetDynamicsStarted(*args, **kwargs):
        """
        GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool
        """
        ...
    
    def GetElementAgenda(*args, **kwargs):
        """
        GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetRegionContext(*args, **kwargs):
        """
        GetRegionContext(self: MSPyDgnView.DgnRegionElementTool) -> MSPyDgnPlatform.RegionGraphicsContext
        """
        ...
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def IsFloodRegionSelected(*args, **kwargs):
        """
        IsFloodRegionSelected(self: MSPyDgnView.DgnRegionElementTool) -> bool
        """
        ...
    
    def OnModifierKeyTransitionHelper(*args, **kwargs):
        """
        OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool
        """
        ...
    
    def OutputErrorMessage(*args, **kwargs):
        """
        OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None
        """
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
        
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(*args, **kwargs):
        """
        SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None
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
        
    def WantAdditionalLocateHelper(*args, **kwargs):
        """
        WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
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
    
    def GetButtonSource(*args, **kwargs):
        """
        GetButtonSource(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the " input source " for this event. See Inputq_element#hdr.source
        (msinputq.h)
        """
        ...
    
    def GetCoordSource(*args, **kwargs):
        """
        GetCoordSource(self: MSPyDgnView.DgnButtonEvent) -> MSPyDgnView.DgnButtonEvent.CoordSource
        
        Get the source of this event.
        """
        ...
    
    def GetKeyModifiers(*args, **kwargs):
        """
        GetKeyModifiers(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Returns:
        the complete key modifier mask when this event occurred.
        """
        ...
    
    def GetPoint(*args, **kwargs):
        """
        GetPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor for this event in active coordinates.
        The point has already been adjusted for locks and snaps.
        """
        ...
    
    def GetRawPoint(*args, **kwargs):
        """
        GetRawPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the 'raw' (before adjustment for locks and snaps) location of the
        cursor for this event in active coordinates.
        """
        ...
    
    def GetTouches(*args, **kwargs):
        """
        GetTouches(self: MSPyDgnView.DgnTouchEvent) -> list
        """
        ...
    
    def GetViewNum(*args, **kwargs):
        """
        GetViewNum(self: MSPyDgnView.DgnButtonEvent) -> int
        
        Get the view number from the viewport for this event.
        """
        ...
    
    def GetViewPoint(*args, **kwargs):
        """
        GetViewPoint(self: MSPyDgnView.DgnButtonEvent) -> MSPyBentleyGeom.DPoint3d
        
        Get the location of the cursor in view coordinates.
        """
        ...
    
    def GetViewport(*args, **kwargs):
        """
        GetViewport(self: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport
        
        Get the viewport in which the cursor resided for this event.
        """
        ...
    
    def Invalidate(*args, **kwargs):
        """
        Invalidate(self: MSPyDgnView.DgnButtonEvent) -> None
        """
        ...
    
    def IsAltKey(*args, **kwargs):
        """
        IsAltKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if an Altkey was pressed when this event occurred.
        """
        ...
    
    def IsControlKey(*args, **kwargs):
        """
        IsControlKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Control key was pressed when this event occurred.
        """
        ...
    
    def IsShiftKey(*args, **kwargs):
        """
        IsShiftKey(self: MSPyDgnView.DgnButtonEvent) -> bool
        
        Returns:
        true if a Shift key was pressed when this event occurred.
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyDgnView.DgnButtonEvent) -> bool
        """
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
    
    def SetPoint(*args, **kwargs):
        """
        SetPoint(self: MSPyDgnView.DgnButtonEvent, pt: MSPyBentleyGeom.DPoint3d) -> None
        
        Set the adjusted point location for this event (sometimes useful in
        DgnTools).
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.DgnButtonEvent, vp: Bentley.DgnPlatform.IndexedViewport) -> None
        
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
    
        def GetViewPoint(*args, **kwargs):
            """
            GetViewPoint(self: MSPyDgnView.DgnTouchEvent.TouchInput, vp: Bentley.DgnPlatform.IndexedViewport) -> MSPyBentleyGeom.DPoint3d
            """
            ...
        
        def IsDown(*args, **kwargs):
            """
            IsDown(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool
            """
            ...
        
        def IsMove(*args, **kwargs):
            """
            IsMove(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool
            """
            ...
        
        def IsPrimary(*args, **kwargs):
            """
            IsPrimary(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool
            """
            ...
        
        def IsUp(*args, **kwargs):
            """
            IsUp(self: MSPyDgnView.DgnTouchEvent.TouchInput) -> bool
            """
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
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent) -> Bentley.DgnPlatform.IndexedViewport:
        ...
    @Viewport.setter
    def Viewport(arg0: MSPyDgnView.DgnButtonEvent, arg1: Bentley.DgnPlatform.IndexedViewport) -> None:
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
    
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetPreferredViewport(*args, **kwargs):
        """
        GetPreferredViewport(unparsed: str, sourceToSearch: MSPyDgnView.DgnViewTool.PreferredView) -> tuple
        
        Call for viewing tools that have no tool settings or don't require a
        data point to determine if there is enough context in which to choose
        an initial viewport to use. Takes into account the preference for
        viewing tools to apply to the active view. For viewing tools on the
        view border, implement as an IconCmdX and setup
        HOOKITEMID_ViewBorderIconCmdHook in order to be passed the view number
        as unparsedP.
        
        Parameter ``sourceFoundP``:
        OUT Source of preferred viewport.
        
        Parameter ``unparsedP``:
        IN unparsed string containing a view number or NULL.
        
        Parameter ``sourceToSearch``:
        IN Mask of allow sources for preferred viewport,
        PREFERRED_VIEW_Unparsed only used as an output, assumed if
        unparsedP isn't NULL.
        
        Returns:
        Preferred viewport for tool or NULL.
        """
        ...
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
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
        
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
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
    
    def CallOnRestartTool(*args, **kwargs):
        """
        CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None
        
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
        
    def EnableUndoPreviousStep(*args, **kwargs):
        """
        EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None
        """
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
        
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetDisplayPath(*args, **kwargs):
        """
        GetDisplayPath(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyDgnPlatform.DisplayPath
        """
        ...
    
    def GetDynamicsStarted(*args, **kwargs):
        """
        GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool
        """
        ...
    
    def GetElementAgenda(*args, **kwargs):
        """
        GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda
        """
        ...
    
    def GetElementGraphicsCache(*args, **kwargs):
        """
        GetElementGraphicsCache(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle, geomCache: Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.IRefCounted>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.IRefCounted> > >) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    def GetElementGraphicsCacheCount(*args, **kwargs):
        """
        GetElementGraphicsCacheCount(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> int
        """
        ...
    
    def GetLocatedComponentPath(*args, **kwargs):
        """
        GetLocatedComponentPath(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> MSPyDgnPlatform.DisplayPath
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def IsFromLocatedComponent(*args, **kwargs):
        """
        IsFromLocatedComponent(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsGeometryMissing(*args, **kwargs):
        """
        IsGeometryMissing(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> bool
        """
        ...
    
    def IsGeometrySheet(*args, **kwargs):
        """
        IsGeometrySheet(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsGeometrySolid(*args, **kwargs):
        """
        IsGeometrySolid(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsGeometryWire(*args, **kwargs):
        """
        IsGeometryWire(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def OnModifierKeyTransitionHelper(*args, **kwargs):
        """
        OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool
        """
        ...
    
    def OutputErrorMessage(*args, **kwargs):
        """
        OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None
        """
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
        
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(*args, **kwargs):
        """
        SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None
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
    
    def TryGetAsBRep(*args, **kwargs):
        """
        TryGetAsBRep(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyDgnPlatform.ISolidKernelEntity
        """
        ...
    
    def TryGetAsCurveVector(*args, **kwargs):
        """
        TryGetAsCurveVector(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.CurveVector
        """
        ...
    
    def TryGetAsPolyface(*args, **kwargs):
        """
        TryGetAsPolyface(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.PolyfaceHeader
        """
        ...
    
    def TryGetAsPrimitive(*args, **kwargs):
        """
        TryGetAsPrimitive(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.ISolidPrimitive
        """
        ...
    
    def TryGetAsSurface(*args, **kwargs):
        """
        TryGetAsSurface(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.RefCountedMSBsplineSurface
        """
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
        
    def WantAdditionalLocateHelper(*args, **kwargs):
        """
        WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
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
    
    def BuildAgenda(*args, **kwargs):
        """
        BuildAgenda(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, agenda: MSPyDgnPlatform.ElementAgenda, modelRefList: MSPyDgnPlatform.DgnModelRefList, modifyOrig: bool, allowLocked: bool, callAsynch: bool) -> int
        
        Collect elements that satisfy the supplied FenceParams/criteria.
        """
        ...
    
    def ClearFence(*args, **kwargs):
        """
        ClearFence(self: MSPyDgnView.FenceManager) -> None
        
        Clear any active points/element fence so that are is no longer a fence
        active.
        """
        ...
    
    def ClipElement(*args, **kwargs):
        """
        ClipElement(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, inside: MSPyDgnPlatform.ElementAgenda, outside: MSPyDgnPlatform.ElementAgenda, eh: MSPyDgnPlatform.ElementHandle, flags: MSPyDgnPlatform.FenceClipFlags) -> int
        
        Apply fence clip operation to input element.
        """
        ...
    
    def DefineByElement(*args, **kwargs):
        """
        DefineByElement(self: MSPyDgnView.FenceManager, eh: MSPyDgnPlatform.ElementHandle, vp: MSPyDgnPlatform.Viewport) -> int
        
        Set active fence from an element.
        """
        ...
    
    def DefineByPoints(*args, **kwargs):
        """
        DefineByPoints(self: MSPyDgnView.FenceManager, points: MSPyBentleyGeom.DPoint3dArray, vp: MSPyDgnPlatform.Viewport) -> int
        
        Set active fence by points.
        """
        ...
    
    def DisplayFence(*args, **kwargs):
        """
        DisplayFence(self: MSPyDgnView.FenceManager, vp: MSPyDgnPlatform.Viewport, optTrans: MSPyBentleyGeom.Transform = None, optTransparency: Optional[int] = None) -> None
        
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
    
    def GetActiveFenceClipFlags(*args, **kwargs):
        """
        GetActiveFenceClipFlags(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.FenceClipFlags
        
        Get active fence clip behavior settings.
        """
        ...
    
    def GetActiveFenceStretchFlags(*args, **kwargs):
        """
        GetActiveFenceStretchFlags(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.FenceStretchFlags
        
        Get active fence stretch behavior setting.
        """
        ...
    
    def GetFenceElem(*args, **kwargs):
        """
        GetFenceElem(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.ElementHandle
        
        Get the element for a fence defined by element.
        """
        ...
    
    def GetFencePoints(*args, **kwargs):
        """
        GetFencePoints(self: MSPyDgnView.FenceManager, points: MSPyBentleyGeom.DPoint3dArray) -> int
        
        Get the points for a fence defined by points.
        """
        ...
    
    def GetFenceViewport(*args, **kwargs):
        """
        GetFenceViewport(self: MSPyDgnView.FenceManager) -> MSPyDgnPlatform.Viewport
        
        Get the fence viewport for a fence defined by points.
        """
        ...
    
    def GetManager(*args, **kwargs):
        """
        GetManager() -> MSPyDgnView.FenceManager
        
        Get the current FenceManager instance.
        """
        ...
    
    def InitFromActiveFence(*args, **kwargs):
        """
        InitFromActiveFence(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, overlap: bool, doClip: bool, allowClipFlag: MSPyDgnPlatform.FenceClipMode) -> int
        
        Populate the supplied FenceParams with information for the active
        fence.
        """
        ...
    
    def IsClipMode(*args, **kwargs):
        """
        IsClipMode(self: MSPyDgnView.FenceManager) -> bool
        
        Return whether current fence mode is clip. Accept and clip elements
        that overlap the fence boundary.
        """
        ...
    
    def IsDefinedByElem(*args, **kwargs):
        """
        IsDefinedByElem(self: MSPyDgnView.FenceManager) -> bool
        
        Return whether a fence defined by element is currently active.
        """
        ...
    
    def IsDefinedByPoints(*args, **kwargs):
        """
        IsDefinedByPoints(self: MSPyDgnView.FenceManager) -> bool
        
        Return whether a fence defined by points is currently active.
        """
        ...
    
    def IsFenceActive(*args, **kwargs):
        """
        IsFenceActive(self: MSPyDgnView.FenceManager) -> bool
        
        Return whether a fence is currently defined, either by points or
        element.
        """
        ...
    
    def IsOverlapMode(*args, **kwargs):
        """
        IsOverlapMode(self: MSPyDgnView.FenceManager) -> bool
        
        Return whether current fence mode is overlap. Accept elements that
        overlap the fence boundary and aren't completely inside (or outside if
        void mode).
        """
        ...
    
    def IsVoidMode(*args, **kwargs):
        """
        IsVoidMode(self: MSPyDgnView.FenceManager) -> bool
        
        Return whether current fence mode is void. Accept elements outside
        fence.
        """
        ...
    
    def SetInhibitFenceDisplay(*args, **kwargs):
        """
        SetInhibitFenceDisplay(self: MSPyDgnView.FenceManager, inhibit: MSPyDgnView.FenceManager.FenceDisplayMode) -> None
        
        For use in tools that need to automate fence creation/processing and
        don't want the fence displayed in the view.
        """
        ...
    
    def StretchElement(*args, **kwargs):
        """
        StretchElement(self: MSPyDgnView.FenceManager, fp: MSPyDgnPlatform.FenceParams, eeh: MSPyDgnPlatform.EditElementHandle, transform: MSPyBentleyGeom.Transform, flags: MSPyDgnPlatform.FenceStretchFlags) -> int
        
        Apply fence stretch operation to input element.
        """
        ...
    
    def TransformFence(*args, **kwargs):
        """
        TransformFence(self: MSPyDgnView.FenceManager, transform: MSPyBentleyGeom.Transform) -> int
        
        Apply a transform to the active fence.
        """
        ...
    
    def UseActiveFence(*args, **kwargs):
        """
        UseActiveFence(self: MSPyDgnView.FenceManager) -> bool
        
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
    
class IModelTransientHandler:
    """
    None
    """

    class ModelTransientPurpose:
        """
        Members:
        
        eModelTransientPurpose_Normal
        
        eModelTransientPurpose_PreDisplayList
        
        eModelTransientPurpose_PostDisplayList
        """
    
        def __init__(self: MSPyDgnView.IModelTransientHandler.ModelTransientPurpose, value: int) -> None:
            ...
        
        eModelTransientPurpose_Normal: ModelTransientPurpose
        
        eModelTransientPurpose_PostDisplayList: ModelTransientPurpose
        
        eModelTransientPurpose_PreDisplayList: ModelTransientPurpose
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnView.IModelTransientHandler.ModelTransientPurpose) -> int:
            ...
        
    def __init__(self: MSPyDgnView.IModelTransientHandler) -> None:
        ...
    
    eModelTransientPurpose_Normal: ModelTransientPurpose
    
    eModelTransientPurpose_PostDisplayList: ModelTransientPurpose
    
    eModelTransientPurpose_PreDisplayList: ModelTransientPurpose
    
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
    
class IViewDecoration:
    """
    None
    """

    def __init__(self: MSPyDgnView.IViewDecoration) -> None:
        ...
    
class IViewManager:
    """
    None
    """

    def AddElementDecorator(*args, **kwargs):
        """
        AddElementDecorator(self: MSPyDgnView.IViewManager, decorator: MSPyDgnView.IViewDecoration) -> None
        """
        ...
    
    def AddModelTransientHandler(*args, **kwargs):
        """
        AddModelTransientHandler(self: MSPyDgnView.IViewManager, handler: MSPyDgnView.IModelTransientHandler) -> None
        """
        ...
    
    def AddViewDecoration(*args, **kwargs):
        """
        AddViewDecoration(self: MSPyDgnView.IViewManager, decorator: MSPyDgnView.IViewDecoration) -> None
        
        @name Viewport Event Handlers
        """
        ...
    
    def AddViewMonitor(*args, **kwargs):
        """
        AddViewMonitor(self: MSPyDgnView.IViewManager, monitor: MSPyDgnView.IViewMonitor) -> None
        """
        ...
    
    def AddViewTransientHandler(*args, **kwargs):
        """
        AddViewTransientHandler(self: MSPyDgnView.IViewManager, handler: MSPyDgnPlatform.IViewTransients) -> None
        """
        ...
    
    @property
    def CurrentViewNumber(arg0: MSPyDgnView.IViewManager) -> int:
        ...
    
    def DropElementDecorator(*args, **kwargs):
        """
        DropElementDecorator(self: MSPyDgnView.IViewManager, decorator: MSPyDgnView.IViewDecoration) -> None
        """
        ...
    
    def DropModelTransientHandler(*args, **kwargs):
        """
        DropModelTransientHandler(self: MSPyDgnView.IViewManager, handler: MSPyDgnView.IModelTransientHandler) -> None
        """
        ...
    
    def DropViewDecoration(*args, **kwargs):
        """
        DropViewDecoration(self: MSPyDgnView.IViewManager, decorator: MSPyDgnView.IViewDecoration) -> None
        """
        ...
    
    def DropViewMonitor(*args, **kwargs):
        """
        DropViewMonitor(self: MSPyDgnView.IViewManager, monitor: MSPyDgnView.IViewMonitor) -> None
        """
        ...
    
    def DropViewTransientHandler(*args, **kwargs):
        """
        DropViewTransientHandler(self: MSPyDgnView.IViewManager, handler: MSPyDgnPlatform.IViewTransients) -> None
        """
        ...
    
    def GetActiveViewSet(*args, **kwargs):
        """
        GetActiveViewSet() -> MSPyDgnView.IndexedViewSet
        """
        ...
    
    def GetCurrentViewNumber(*args, **kwargs):
        """
        GetCurrentViewNumber(self: MSPyDgnView.IViewManager) -> int
        
        Return the index of the active viewport
        """
        ...
    
    def GetManager(*args, **kwargs):
        """
        GetManager() -> MSPyDgnView.IViewManager
        """
        ...
    
    def IsGraphicsOn(*args, **kwargs):
        """
        IsGraphicsOn(self: MSPyDgnView.IViewManager) -> bool
        """
        ...
    
    def OnHostTermination(*args, **kwargs):
        """
        OnHostTermination(self: MSPyDgnPlatform.DgnHost.IHostobject, isProgramExit: bool) -> None
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IViewMonitor:
    """
    None
    """

    def __init__(self: MSPyDgnView.IViewMonitor) -> None:
        ...
    
class IndexedViewSet:
    """
    None
    """

    @property
    def DgnHost(arg0: MSPyDgnView.IndexedViewSet) -> MSPyDgnPlatform.DgnHost:
        ...
    
    class DynamicUpdateInfo:
        """
        None
        """
    
        def ClearLastMotion(*args, **kwargs):
            """
            ClearLastMotion(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo) -> None
            """
            ...
        
        def GetLastCursorPos(*args, **kwargs):
            """
            GetLastCursorPos(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo) -> MSPyBentleyGeom.Point2d
            """
            ...
        
        @property
        def LastCursorPos(arg0: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo) -> MSPyBentleyGeom.Point2d:
            ...
        
        def SetDeferShadows(*args, **kwargs):
            """
            SetDeferShadows(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, deferShadows: bool) -> None
            """
            ...
        
        def SetDoBackingStore(*args, **kwargs):
            """
            SetDoBackingStore(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, doBackingStore: bool) -> None
            """
            ...
        
        def SetDynamicsMotionTolerance(*args, **kwargs):
            """
            SetDynamicsMotionTolerance(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, dynamicsMotionTolerance: int) -> None
            """
            ...
        
        def SetDynamicsStopInterval(*args, **kwargs):
            """
            SetDynamicsStopInterval(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, dynamicsStopInterval: int) -> None
            """
            ...
        
        def SetIncludeList(*args, **kwargs):
            """
            SetIncludeList(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, includeList: MSPyDgnPlatform.DgnModelRefList) -> None
            """
            ...
        
        def SetMaxFrameTime(*args, **kwargs):
            """
            SetMaxFrameTime(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, maxFrameTime: int) -> None
            """
            ...
        
        def SetMinLODDelta(*args, **kwargs):
            """
            SetMinLODDelta(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, minLodDelta: int) -> None
            """
            ...
        
        def SetStopEvents(*args, **kwargs):
            """
            SetStopEvents(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo, stopEvents: MSPyDgnView.StopEvents) -> None
            """
            ...
        
        def __init__(self: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo) -> None:
            ...
        
    @property
    def FirstOpenView(arg0: MSPyDgnView.IndexedViewSet) -> MSPyDgnView.IndexedViewport:
        ...
    
    def ForgetViewport(*args, **kwargs):
        """
        ForgetViewport(self: MSPyDgnView.IndexedViewSet, viewNum: int) -> int
        """
        ...
    
    class FullUpdateInfo:
        """
        None
        """
    
        def GetIncremental(*args, **kwargs):
            """
            GetIncremental(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo) -> bool
            """
            ...
        
        def GetStartEndMsg(*args, **kwargs):
            """
            GetStartEndMsg(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo) -> bool
            """
            ...
        
        @property
        def Incremental(arg0: MSPyDgnView.IndexedViewSet.FullUpdateInfo) -> bool:
            ...
        @Incremental.setter
        def Incremental(arg0: MSPyDgnView.IndexedViewSet.FullUpdateInfo, arg1: bool) -> None:
            ...
        
        def SetDeferShadows(*args, **kwargs):
            """
            SetDeferShadows(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, deferShadows: bool) -> None
            """
            ...
        
        def SetFenceParams(*args, **kwargs):
            """
            SetFenceParams(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, fp: MSPyDgnPlatform.FenceParams) -> None
            """
            ...
        
        def SetIncludeList(*args, **kwargs):
            """
            SetIncludeList(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, includeList: MSPyDgnPlatform.DgnModelRefList) -> None
            """
            ...
        
        def SetIncremental(*args, **kwargs):
            """
            SetIncremental(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, incremental: bool) -> None
            """
            ...
        
        def SetStartAbortState(*args, **kwargs):
            """
            SetStartAbortState(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, state: bool) -> None
            """
            ...
        
        def SetStartEndMsg(*args, **kwargs):
            """
            SetStartEndMsg(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, startEndMsg: bool) -> None
            """
            ...
        
        def SetStopEvents(*args, **kwargs):
            """
            SetStopEvents(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, stopEvents: MSPyDgnView.StopEvents) -> None
            """
            ...
        
        def SetSubRect(*args, **kwargs):
            """
            SetSubRect(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, subRect: MSPyDgnPlatform.BSIRect) -> None
            """
            ...
        
        def SetUseCachedElems(*args, **kwargs):
            """
            SetUseCachedElems(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo, useCacheElems: bool) -> None
            """
            ...
        
        @property
        def StartEndMsg(arg0: MSPyDgnView.IndexedViewSet.FullUpdateInfo) -> bool:
            ...
        @StartEndMsg.setter
        def StartEndMsg(arg0: MSPyDgnView.IndexedViewSet.FullUpdateInfo, arg1: bool) -> None:
            ...
        
        def __init__(self: MSPyDgnView.IndexedViewSet.FullUpdateInfo) -> None:
            ...
        
    def GetDgnHost(*args, **kwargs):
        """
        GetDgnHost(self: MSPyDgnView.IndexedViewSet) -> MSPyDgnPlatform.DgnHost
        """
        ...
    
    def GetFirstOpenView(*args, **kwargs):
        """
        GetFirstOpenView(self: MSPyDgnView.IndexedViewSet) -> MSPyDgnView.IndexedViewport
        """
        ...
    
    def GetSelectedView(*args, **kwargs):
        """
        GetSelectedView(self: MSPyDgnView.IndexedViewSet) -> int
        """
        ...
    
    def GetSelectedViewport(*args, **kwargs):
        """
        GetSelectedViewport(self: MSPyDgnView.IndexedViewSet) -> MSPyDgnView.IndexedViewport
        """
        ...
    
    def GetViewTitle(*args, **kwargs):
        """
        GetViewTitle(self: MSPyDgnView.IndexedViewSet, title: MSPyBentley.WString, viewIndex: int) -> None
        """
        ...
    
    def GetViewport(*args, **kwargs):
        """
        GetViewport(self: MSPyDgnView.IndexedViewSet, viewNum: int) -> MSPyDgnView.IndexedViewport
        """
        ...
    
    def IsHealingEnabled(*args, **kwargs):
        """
        IsHealingEnabled(self: MSPyDgnView.IndexedViewSet) -> bool
        """
        ...
    
    @property
    def SelectedView(arg0: MSPyDgnView.IndexedViewSet) -> int:
        ...
    
    @property
    def SelectedViewport(arg0: MSPyDgnView.IndexedViewSet) -> MSPyDgnView.IndexedViewport:
        ...
    
    def SetSelectedView(*args, **kwargs):
        """
        SetSelectedView(self: MSPyDgnView.IndexedViewSet, inVp: MSPyDgnView.IndexedViewport, setActiveModel: bool, fromButtonEvent: bool) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.IndexedViewSet, viewNum: int, vp: MSPyDgnView.IndexedViewport) -> int
        """
        ...
    
    def UpdateView(*args, **kwargs):
        """
        UpdateView(self: MSPyDgnView.IndexedViewSet, vp: MSPyDgnView.IndexedViewport, drawMode: MSPyDgnPlatform.DgnDrawMode, drawPurpose: MSPyDgnPlatform.DrawPurpose, info: MSPyDgnView.IndexedViewSet.FullUpdateInfo) -> bool
        """
        ...
    
    def UpdateViewDynamic(*args, **kwargs):
        """
        UpdateViewDynamic(self: MSPyDgnView.IndexedViewSet, vp: MSPyDgnView.IndexedViewport, info: MSPyDgnView.IndexedViewSet.DynamicUpdateInfo) -> MSPyDgnView.UpdateAbortReason
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IndexedViewport:
    """
    None
    """

    def ActiveToRoot(*args, **kwargs):
        """
        ActiveToRoot(*args, **kwargs)
        Overloaded function.
        
        1. ActiveToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, activePts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ActiveToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, activePt: MSPyBentleyGeom.DPoint3d) -> None
        
        3. ActiveToRoot(self: MSPyDgnPlatform.Viewport, rootRMatrix: MSPyBentleyGeom.RotMatrix, activeRMatrix: MSPyBentleyGeom.RotMatrix) -> None
        """
        ...
    
    @property
    def ActiveToRootMap(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d:
        ...
    
    def ActiveToView(*args, **kwargs):
        """
        ActiveToView(*args, **kwargs)
        Overloaded function.
        
        1. ActiveToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, activePts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ActiveToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, activePt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    @property
    def ActiveZRoot(arg0: MSPyDgnPlatform.Viewport) -> float:
        ...
    
    def AdjustColorForContrast(*args, **kwargs):
        """
        AdjustColorForContrast(self: MSPyDgnPlatform.Viewport, thisColor: int, againstColor: int) -> int
        """
        ...
    
    @property
    def BackgroundColor(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    @property
    def CameraRoot(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.CameraParams:
        ...
    
    @property
    def ClipBoundElementRef(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @property
    def ClipMaskElementRef(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def ComputeDisplayedModelRefRange(*args, **kwargs):
        """
        ComputeDisplayedModelRefRange(self: MSPyDgnPlatform.Viewport, range: MSPyBentleyGeom.DRange3d, modelRef: MSPyDgnPlatform.DgnModelRef, includeChildren: bool, fitParams: MSPyDgnPlatform.FitViewParams) -> int
        
        Compute range of a model ref when display in the viewport
        """
        ...
    
    def ComputeFittedElementRange(*args, **kwargs):
        """
        ComputeFittedElementRange(self: MSPyDgnPlatform.Viewport, range: MSPyBentleyGeom.DRange3d, elements: Bentley.DgnPlatform.IElementSet, rMatrix: MSPyBentleyGeom.RotMatrix) -> int
        
        Compute the range of the element when displayed in the viewport
        """
        ...
    
    @property
    def ContrastToBackgroundColor(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    def GetActiveToRootMap(*args, **kwargs):
        """
        GetActiveToRootMap(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d
        """
        ...
    
    def GetActiveZRoot(*args, **kwargs):
        """
        GetActiveZRoot(self: MSPyDgnPlatform.Viewport) -> float
        """
        ...
    
    def GetBackgroundColor(*args, **kwargs):
        """
        GetBackgroundColor(self: MSPyDgnPlatform.Viewport) -> int
        """
        ...
    
    def GetCameraRoot(*args, **kwargs):
        """
        GetCameraRoot(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.CameraParams
        """
        ...
    
    def GetCameraTarget(*args, **kwargs):
        """
        GetCameraTarget(self: MSPyDgnPlatform.Viewport, target: MSPyBentleyGeom.DPoint3d) -> int
        """
        ...
    
    def GetCameraView(*args, **kwargs):
        """
        GetCameraView(self: MSPyDgnPlatform.Viewport, camera: Bentley.DgnPlatform.CameraParams) -> None
        """
        ...
    
    def GetClipBoundElemHandle(*args, **kwargs):
        """
        GetClipBoundElemHandle(self: MSPyDgnPlatform.Viewport, eeh: Bentley.DgnPlatform.EditElementHandle) -> int
        """
        ...
    
    def GetClipBoundElementRef(*args, **kwargs):
        """
        GetClipBoundElementRef(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase
        """
        ...
    
    def GetClipMaskElemHandle(*args, **kwargs):
        """
        GetClipMaskElemHandle(self: MSPyDgnPlatform.Viewport, eeh: Bentley.DgnPlatform.EditElementHandle) -> int
        """
        ...
    
    def GetClipMaskElementRef(*args, **kwargs):
        """
        GetClipMaskElementRef(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase
        """
        ...
    
    def GetContrastToBackgroundColor(*args, **kwargs):
        """
        GetContrastToBackgroundColor(self: MSPyDgnPlatform.Viewport) -> int
        """
        ...
    
    def GetHiliteColor(*args, **kwargs):
        """
        GetHiliteColor(self: MSPyDgnPlatform.Viewport) -> int
        """
        ...
    
    def GetHiliteColorFromPath(*args, **kwargs):
        """
        GetHiliteColorFromPath(self: MSPyDgnPlatform.Viewport, path: Bentley.DgnPlatform.DisplayPath) -> int
        """
        ...
    
    def GetICachedDraw(*args, **kwargs):
        """
        GetICachedDraw(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ICachedDraw
        
        Gets the object required for advanced cached drawing to the Viewport.
        Cached Drawing is seldom required by applications.
        """
        ...
    
    def GetIViewDraw(*args, **kwargs):
        """
        GetIViewDraw(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.IViewDraw
        
        Gets the object required for immediate drawing to the Viewport. The
        methods on IViewDraw can be used to draw View Decorators.
        """
        ...
    
    def GetIViewOutput(*args, **kwargs):
        """
        GetIViewOutput(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.IViewOutput
        
        Gets the object required for advanced immediate drawing to the
        Viewport. IViewOutput is a subclass of IViewDraw, and generally only
        IViewDraw is needed.
        """
        ...
    
    def GetIndexedLinePattern(*args, **kwargs):
        """
        GetIndexedLinePattern(self: MSPyDgnPlatform.Viewport, index: int) -> int
        """
        ...
    
    def GetIndexedLineWidth(*args, **kwargs):
        """
        GetIndexedLineWidth(self: MSPyDgnPlatform.Viewport, index: int) -> int
        """
        ...
    
    def GetPixelSizeAtPoint(*args, **kwargs):
        """
        GetPixelSizeAtPoint(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, coordSys: MSPyDgnPlatform.DgnCoordSystem = <DgnCoordSystem.eRoot: 3>) -> float
        
        Get the size of a single pixel at a given point as a distance along
        the view-x axis. The size of a pixel will only differ at different
        points within the same Viewport if the camera is on for this Viewport
        (in which case, points closer to the eye return larger values than
        ones further from the eye.)
        
        Parameter ``rootPt``:
        The point in DgnCoordSystem.Root for determining pixel size. If
        NULL, use the center of the Viewport.
        
        Parameter ``coordSys``:
        The coordinate system for the returned distance.
        
        Returns:
        the size of the pixel at point ``rootPt.``
        """
        ...
    
    def GetRootModel(*args, **kwargs):
        """
        GetRootModel(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModel
        """
        ...
    
    def GetRootToNpcMap(*args, **kwargs):
        """
        GetRootToNpcMap(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d
        """
        ...
    
    def GetRootToViewMap(*args, **kwargs):
        """
        GetRootToViewMap(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d
        """
        ...
    
    def GetRotMatrix(*args, **kwargs):
        """
        GetRotMatrix(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.RotMatrix
        """
        ...
    
    def GetScale(*args, **kwargs):
        """
        GetScale(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d
        """
        ...
    
    def GetScreenNumber(*args, **kwargs):
        """
        GetScreenNumber(self: MSPyDgnPlatform.Viewport) -> int
        
        Get the screen number on which this Viewport resides.
        """
        ...
    
    def GetTargetModel(*args, **kwargs):
        """
        GetTargetModel(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModelRef
        """
        ...
    
    def GetViewBox(*args, **kwargs):
        """
        GetViewBox(self: MSPyDgnPlatform.Viewport, points: MSPyBentleyGeom.DPoint3dArray, sys: MSPyDgnPlatform.DgnCoordSystem, adjustedBox: bool) -> None
        """
        ...
    
    def GetViewCorners(*args, **kwargs):
        """
        GetViewCorners(self: MSPyDgnPlatform.Viewport, low: MSPyBentleyGeom.DPoint3d, high: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def GetViewDelta(*args, **kwargs):
        """
        GetViewDelta(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d
        
        Get the View Delta (size) of this Viewport in root coordinate
        distances.
        
        Returns:
        the view delta in root coordinate distances.
        """
        ...
    
    def GetViewFlags(*args, **kwargs):
        """
        GetViewFlags(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewFlags
        
        Get the current View Flags for this Viewport.
        
        Returns:
        the View flags for this Viewport.
        """
        ...
    
    def GetViewInfo(*args, **kwargs):
        """
        GetViewInfo(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewInfo
        """
        ...
    
    def GetViewName(*args, **kwargs):
        """
        GetViewName(self: MSPyDgnPlatform.Viewport, name: MSPyBentley.WString) -> None
        """
        ...
    
    def GetViewNumber(*args, **kwargs):
        """
        GetViewNumber(self: MSPyDgnPlatform.Viewport) -> int
        
        Get the view number of this Viewport. If this Viewport is one of the 8
        MicroStation numbered views (i.e. " View 1 " through " View 8 "), then
        return the index of view number (e.g. " View 1 " is view index 0, " View 8 " is view index 7). If the Viewport is not one of the 8 MicroStation
        numbered views, this method will return -1.
        
        Returns:
        the view index of this Viewport, or -1 if it is not one of the
        numbered views.
        """
        ...
    
    def GetViewOrigin(*args, **kwargs):
        """
        GetViewOrigin(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d
        
        Get View Origin for this Viewport.
        
        Returns:
        the root coordinates of the lower left back corner of the
        Viewport.
        """
        ...
    
    def GetViewRect(*args, **kwargs):
        """
        GetViewRect(self: MSPyDgnPlatform.Viewport, rect: MSPyDgnPlatform.BSIRect) -> None
        """
        ...
    
    @property
    def HiliteColor(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    @property
    def ICachedDraw(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ICachedDraw:
        ...
    
    @property
    def IViewDraw(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.IViewDraw:
        ...
    
    @property
    def IViewOutput(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.IViewOutput:
        ...
    
    def Is3dModel(*args, **kwargs):
        """
        Is3dModel(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsActive(*args, **kwargs):
        """
        IsActive(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsCameraOn(*args, **kwargs):
        """
        IsCameraOn(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsGridOn(*args, **kwargs):
        """
        IsGridOn(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsSheetView(*args, **kwargs):
        """
        IsSheetView(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def MakeColorTransparency(*args, **kwargs):
        """
        MakeColorTransparency(color: int, transparency: int) -> int
        """
        ...
    
    def MakeTransparentIfOpaque(*args, **kwargs):
        """
        MakeTransparentIfOpaque(color: int, transparency: int) -> int
        """
        ...
    
    def MakeTrgbColor(*args, **kwargs):
        """
        MakeTrgbColor(red: int, green: int, blue: int, transparency: int) -> int
        """
        ...
    
    def NpcToRoot(*args, **kwargs):
        """
        NpcToRoot(*args, **kwargs)
        Overloaded function.
        
        1. NpcToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. NpcToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def NpcToView(*args, **kwargs):
        """
        NpcToView(*args, **kwargs)
        Overloaded function.
        
        1. NpcToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. NpcToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ResynchColorMap(*args, **kwargs):
        """
        ResynchColorMap(self: MSPyDgnPlatform.Viewport) -> None
        """
        ...
    
    @property
    def RootModel(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModel:
        ...
    
    def RootToActive(*args, **kwargs):
        """
        RootToActive(*args, **kwargs)
        Overloaded function.
        
        1. RootToActive(self: MSPyDgnPlatform.Viewport, activePts: MSPyBentleyGeom.DPoint3dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToActive(self: MSPyDgnPlatform.Viewport, activePt: MSPyBentleyGeom.DPoint3d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        
        3. RootToActive(self: MSPyDgnPlatform.Viewport, activeRMatrix: MSPyBentleyGeom.RotMatrix, rootRMatrix: MSPyBentleyGeom.RotMatrix) -> None
        """
        ...
    
    def RootToNpc(*args, **kwargs):
        """
        RootToNpc(*args, **kwargs)
        Overloaded function.
        
        1. RootToNpc(self: MSPyDgnPlatform.Viewport, npcPts: MSPyBentleyGeom.DPoint3dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToNpc(self: MSPyDgnPlatform.Viewport, npcPt: MSPyBentleyGeom.DPoint3d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    @property
    def RootToNpcMap(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d:
        ...
    
    def RootToView(*args, **kwargs):
        """
        RootToView(*args, **kwargs)
        Overloaded function.
        
        1. RootToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint4dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint4d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        
        3. RootToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        4. RootToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def RootToView2d(*args, **kwargs):
        """
        RootToView2d(*args, **kwargs)
        Overloaded function.
        
        1. RootToView2d(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint2dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToView2d(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint2d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    @property
    def RootToViewMap(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d:
        ...
    
    @property
    def RotMatrix(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.RotMatrix:
        ...
    
    @property
    def Scale(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def ScreenNumber(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    def ScreenToView(*args, **kwargs):
        """
        ScreenToView(*args, **kwargs)
        Overloaded function.
        
        1. ScreenToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, screenPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ScreenToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, screenPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def Scroll(*args, **kwargs):
        """
        Scroll(self: MSPyDgnPlatform.Viewport, viewDist: MSPyBentleyGeom.Point2d) -> int
        
        @name Changing Viewport Frustum Scroll the Viewport by a given number
        of pixels in the view's X and/or Y direction. This method will move
        the Viewport's frustum in the indicated direction, but does *not*
        update the screen (even if the Viewport happens to be a visible View.)
        This method does change the ViewInfo associated with the Viewport.
        
        Parameter ``viewDist``:
        The distance to scroll, in pixels. @note To update the view, see
        IViewManager.UpdateView or IViewManager.UpdateViewDynamic. To
        save the change to the ViewInfo in the view undo buffer, see
        SynchWithViewInfo.
        """
        ...
    
    def SetMinimumLOD(*args, **kwargs):
        """
        SetMinimumLOD(self: MSPyDgnPlatform.Viewport, minLod: float) -> None
        """
        ...
    
    def SetNeedsRefresh(*args, **kwargs):
        """
        SetNeedsRefresh(self: MSPyDgnPlatform.Viewport) -> None
        
        Sets the flag indicating that the Viewport needs to be refreshed from
        the backing store at the next opportunity. When the Viewport is
        refreshed, the view decorators are redrawn.
        """
        ...
    
    def SetSymbologyRgb(*args, **kwargs):
        """
        SetSymbologyRgb(self: MSPyDgnPlatform.Viewport, lineColorTBGR: int, fillColorTBGR: int, lineWidth: int, lineColorIndex: int) -> None
        """
        ...
    
    def SetTemporaryClipElementRef(*args, **kwargs):
        """
        SetTemporaryClipElementRef(self: MSPyDgnPlatform.Viewport, element: MSPyDgnPlatform.ElementRefBase) -> None
        """
        ...
    
    def SetTemporaryClipMaskElementRef(*args, **kwargs):
        """
        SetTemporaryClipMaskElementRef(self: MSPyDgnPlatform.Viewport, element: MSPyDgnPlatform.ElementRefBase) -> None
        """
        ...
    
    def SetupFromFrustum(*args, **kwargs):
        """
        SetupFromFrustum(self: MSPyDgnPlatform.Viewport, frustPts: MSPyBentleyGeom.DPoint3dArray) -> int
        """
        ...
    
    def SynchWithViewInfo(*args, **kwargs):
        """
        SynchWithViewInfo(self: MSPyDgnPlatform.Viewport, saveInUndo: bool, updateViewTitle: bool) -> MSPyDgnPlatform.BentleyStatus
        
        Synchronizes the view information that is displayed with this
        viewport. Optionally add an entry in the view undo stack and update
        the view title.
        """
        ...
    
    @property
    def TargetModel(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    @property
    def ViewDelta(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def ViewFlags(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewFlags:
        ...
    
    @property
    def ViewInfo(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewInfo:
        ...
    
    @property
    def ViewNumber(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    @property
    def ViewOrigin(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def ViewToActive(*args, **kwargs):
        """
        ViewToActive(*args, **kwargs)
        Overloaded function.
        
        1. ViewToActive(self: MSPyDgnPlatform.Viewport, activePts: MSPyBentleyGeom.DPoint3dArray, viewPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ViewToActive(self: MSPyDgnPlatform.Viewport, activePt: MSPyBentleyGeom.DPoint3d, viewPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ViewToNpc(*args, **kwargs):
        """
        ViewToNpc(*args, **kwargs)
        Overloaded function.
        
        1. ViewToNpc(self: MSPyDgnPlatform.Viewport, npcPts: MSPyBentleyGeom.DPoint3dArray, viewPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ViewToNpc(self: MSPyDgnPlatform.Viewport, npcPt: MSPyBentleyGeom.DPoint3d, viewPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ViewToRoot(*args, **kwargs):
        """
        ViewToRoot(*args, **kwargs)
        Overloaded function.
        
        1. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint4dArray) -> None
        
        2. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint4d) -> None
        
        3. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        4. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ViewToScreen(*args, **kwargs):
        """
        ViewToScreen(*args, **kwargs)
        Overloaded function.
        
        1. ViewToScreen(self: MSPyDgnPlatform.Viewport, screenPts: MSPyBentleyGeom.DPoint3dArray, viewPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ViewToScreen(self: MSPyDgnPlatform.Viewport, screenPt: MSPyBentleyGeom.DPoint3d, viewPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def Zoom(*args, **kwargs):
        """
        Zoom(self: MSPyDgnPlatform.Viewport, newCenterPoint: MSPyBentleyGeom.DPoint3d, factor: float, normalizeCamera: bool) -> int
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
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
    
    def CallOnRestartTool(*args, **kwargs):
        """
        CallOnRestartTool(self: MSPyDgnView.DgnPrimitiveTool) -> None
        
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
        
    def DoPickFace(*args, **kwargs):
        """
        DoPickFace(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, subEntity: MSPyDgnPlatform.ISubEntity, ev: MSPyDgnView.DgnButtonEvent, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool
        """
        ...
    
    def DoPickSubEntities(*args, **kwargs):
        """
        DoPickSubEntities(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, ev: MSPyDgnView.DgnButtonEvent, intersectEntities: MSPyDgnPlatform.ISubEntityPtrArray, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool
        """
        ...
    
    def DoPickSurfaces(*args, **kwargs):
        """
        DoPickSurfaces(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, ev: MSPyDgnView.DgnButtonEvent, intersectEntities: MSPyDgnPlatform.ISubEntityPtrArray, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool
        """
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
        
    def EnableUndoPreviousStep(*args, **kwargs):
        """
        EnableUndoPreviousStep(self: MSPyDgnView.DgnPrimitiveTool) -> None
        """
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
        
    def EvaluateFace(*args, **kwargs):
        """
        EvaluateFace(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity, point: MSPyBentleyGeom.DPoint3d, normal: MSPyBentleyGeom.DVec3d, uDir: MSPyBentleyGeom.DVec3d, vDir: MSPyBentleyGeom.DVec3d, uvParam: MSPyBentleyGeom.DPoint2d) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    def FindAgendaEntry(*args, **kwargs):
        """
        FindAgendaEntry(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.EditElementHandle
        """
        ...
    
    def GetAcceptedSubEntities(*args, **kwargs):
        """
        GetAcceptedSubEntities(self: MSPyDgnView.LocateSubEntityTool) -> MSPyDgnPlatform.ISubEntityPtrArray
        """
        ...
    
    def GetActivePrimitiveTool(*args, **kwargs):
        """
        GetActivePrimitiveTool() -> Bentley.DgnPlatform.DgnPrimitiveTool
        """
        ...
    
    def GetActiveViewTool(*args, **kwargs):
        """
        GetActiveViewTool() -> MSPyDgnView.DgnTool
        """
        ...
    
    def GetClosestFace(*args, **kwargs):
        """
        GetClosestFace(self: MSPyDgnView.LocateSubEntityTool, eh: MSPyDgnPlatform.ElementHandle, ev: MSPyDgnView.DgnButtonEvent, closePoint: MSPyBentleyGeom.DPoint3d, closeParam: MSPyBentleyGeom.DPoint2d) -> tuple
        """
        ...
    
    def GetCurrentDgnButtonEvent(*args, **kwargs):
        """
        GetCurrentDgnButtonEvent(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to get a button event representing the current cursor location.
        
        Parameter ``ev``:
        IN Current button event.
        """
        ...
    
    def GetDisplayPath(*args, **kwargs):
        """
        GetDisplayPath(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyDgnPlatform.DisplayPath
        """
        ...
    
    def GetDynamicsStarted(*args, **kwargs):
        """
        GetDynamicsStarted(self: MSPyDgnView.DgnPrimitiveTool) -> bool
        """
        ...
    
    def GetElementAgenda(*args, **kwargs):
        """
        GetElementAgenda(self: MSPyDgnView.DgnElementSetTool) -> MSPyDgnPlatform.ElementAgenda
        """
        ...
    
    def GetElementGraphicsCache(*args, **kwargs):
        """
        GetElementGraphicsCache(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle, geomCache: Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.IRefCounted>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.IRefCounted> > >) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    def GetElementGraphicsCacheCount(*args, **kwargs):
        """
        GetElementGraphicsCacheCount(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> int
        """
        ...
    
    def GetFaceParameterRange(*args, **kwargs):
        """
        GetFaceParameterRange(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity, uRange: MSPyBentleyGeom.DRange1d, vRange: MSPyBentleyGeom.DRange1d) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    def GetIElementGraphics(*args, **kwargs):
        """
        GetIElementGraphics(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> Bentley.IRefCounted
        """
        ...
    
    def GetLocateInfo(*args, **kwargs):
        """
        GetLocateInfo(spacePoint: MSPyBentleyGeom.DPoint3d, viewToLocal: MSPyBentleyGeom.DMatrix4d, ev: MSPyDgnView.DgnButtonEvent, path: MSPyDgnPlatform.DisplayPath) -> float
        
        Compute locate information from button event GetRawPoint (adjusted to
        eye). The spacePoint and maxDistance are returned in local coordinates
        of path.
        """
        ...
    
    def GetLocatedComponentPath(*args, **kwargs):
        """
        GetLocatedComponentPath(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> MSPyDgnPlatform.DisplayPath
        """
        ...
    
    def GetModifierKeyTransitionState(*args, **kwargs):
        """
        GetModifierKeyTransitionState(self: MSPyDgnView.DgnTool) -> tuple
        
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
    
    def GetSpacePoint(*args, **kwargs):
        """
        GetSpacePoint(spacePoint: MSPyBentleyGeom.DPoint3d, ev: MSPyDgnView.DgnButtonEvent, path: MSPyDgnPlatform.DisplayPath) -> None
        
        Compute space point from button event GetPoint. The spacePoint is
        returned in local coordinates of path.
        """
        ...
    
    def GetSubEntityGeometry(*args, **kwargs):
        """
        GetSubEntityGeometry(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> tuple
        """
        ...
    
    def GetToolId(*args, **kwargs):
        """
        GetToolId(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def GetToolPrompt(*args, **kwargs):
        """
        GetToolPrompt(self: MSPyDgnView.DgnTool) -> int
        
        Not used in Python implementation
        """
        ...
    
    def InitBoresite(*args, **kwargs):
        """
        InitBoresite(boresite: MSPyBentleyGeom.DRay3d, spacePoint: MSPyBentleyGeom.DPoint3d, worldToLocal: MSPyBentleyGeom.DMatrix4d) -> None
        
        Compute boresite ray from space point and world to local matrix. (See
        GetLocateInfo).
        """
        ...
    
    def InstallTool(*args, **kwargs):
        """
        InstallTool(self: MSPyDgnView.DgnTool) -> int
        
        Call to make this tool instance the current active command.
        
        Returns:
        SUCCESS if new tool instance is now the current command.
        
        See also:
        #_OnInstall #_OnPostInstall
        """
        ...
    
    def IsFromLocatedComponent(*args, **kwargs):
        """
        IsFromLocatedComponent(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsGeometryMissing(*args, **kwargs):
        """
        IsGeometryMissing(self: MSPyDgnView.ElementGraphicsTool, eh: MSPyDgnPlatform.ElementHandle) -> bool
        """
        ...
    
    def IsGeometrySheet(*args, **kwargs):
        """
        IsGeometrySheet(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsGeometrySolid(*args, **kwargs):
        """
        IsGeometrySolid(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsGeometryWire(*args, **kwargs):
        """
        IsGeometryWire(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> bool
        """
        ...
    
    def IsSolidKernelSubEntity(*args, **kwargs):
        """
        IsSolidKernelSubEntity(self: MSPyDgnView.LocateSubEntityTool, subEntity: MSPyDgnPlatform.ISubEntity) -> bool
        """
        ...
    
    def OnModifierKeyTransitionHelper(*args, **kwargs):
        """
        OnModifierKeyTransitionHelper(self: MSPyDgnView.DgnElementSetTool, wentDown: bool, key: int) -> bool
        """
        ...
    
    def OutputErrorMessage(*args, **kwargs):
        """
        OutputErrorMessage(msg: MSPyDgnView.DgnElementSetTool.ErrorNums) -> None
        """
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
        
    def ResetCurrentQualifierMask(*args, **kwargs):
        """
        ResetCurrentQualifierMask(self: MSPyDgnView.DgnTool, mask: int) -> None
        
        Internal method to reset the current qualifier mask.
        
        Parameter ``mask``:
        IN New qualifier mask.
        """
        ...
    
    def ResetSubEntityLocate(*args, **kwargs):
        """
        ResetSubEntityLocate(self: MSPyDgnView.LocateSubEntityTool) -> None
        """
        ...
    
    def SetAdjustedDataPoint(*args, **kwargs):
        """
        SetAdjustedDataPoint(self: MSPyDgnView.DgnTool, ev: MSPyDgnView.DgnButtonEvent) -> None
        
        Call to set an adjusted point as the last datapoint location. This is
        the location that precision key-ins and axis/isometric lock will use.
        
        Parameter ``ev``:
        IN new button event.
        """
        ...
    
    def SetCmdName(*args, **kwargs):
        """
        SetCmdName(self: MSPyDgnView.DgnTool, id: int, prompt: int) -> None
        """
        ...
    
    def SetModifierKeyTransitionState(*args, **kwargs):
        """
        SetModifierKeyTransitionState(self: MSPyDgnView.DgnTool, modifierKey: int, modifierWentDown: bool, currentQualifierMask: int) -> None
        
        Called to set the current modifier transition state.
        
        Returns:
        The id of the current command promnpt.
        """
        ...
    
    def SetToolId(*args, **kwargs):
        """
        SetToolId(self: MSPyDgnView.DgnTool, toolId: int) -> None
        
        Not used in Python implementation override GetToolName instead
        """
        ...
    
    def SetToolPrompt(*args, **kwargs):
        """
        SetToolPrompt(self: MSPyDgnView.DgnTool, prompt: int) -> None
        
        Not used in Python implementation
        """
        ...
    
    def SetupAndPromptForNextActionHelper(*args, **kwargs):
        """
        SetupAndPromptForNextActionHelper(self: MSPyDgnView.DgnElementSetTool) -> None
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
    
    def TryGetAsBRep(*args, **kwargs):
        """
        TryGetAsBRep(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyDgnPlatform.ISolidKernelEntity
        """
        ...
    
    def TryGetAsCurveLocationDetail(*args, **kwargs):
        """
        TryGetAsCurveLocationDetail(self: MSPyDgnView.LocateSubEntityTool, location: MSPyBentleyGeom.CurveLocationDetail, subEntity: MSPyDgnPlatform.ISubEntity) -> bool
        """
        ...
    
    def TryGetAsCurveVector(*args, **kwargs):
        """
        TryGetAsCurveVector(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.CurveVector
        """
        ...
    
    def TryGetAsFacetLocationDetail(*args, **kwargs):
        """
        TryGetAsFacetLocationDetail(self: MSPyDgnView.LocateSubEntityTool, location: MSPyBentleyGeom.FacetLocationDetail, subEntity: MSPyDgnPlatform.ISubEntity) -> bool
        """
        ...
    
    def TryGetAsPolyface(*args, **kwargs):
        """
        TryGetAsPolyface(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.PolyfaceHeader
        """
        ...
    
    def TryGetAsPrimitive(*args, **kwargs):
        """
        TryGetAsPrimitive(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.ISolidPrimitive
        """
        ...
    
    def TryGetAsSolidLocationDetail(*args, **kwargs):
        """
        TryGetAsSolidLocationDetail(self: MSPyDgnView.LocateSubEntityTool, location: MSPyBentleyGeom.SolidLocationDetail, subEntity: MSPyDgnPlatform.ISubEntity) -> bool
        """
        ...
    
    def TryGetAsSurface(*args, **kwargs):
        """
        TryGetAsSurface(self: MSPyDgnView.ElementGraphicsTool, geom: Bentley.IRefCounted) -> MSPyBentleyGeom.RefCountedMSBsplineSurface
        """
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
        
    def WantAdditionalLocateHelper(*args, **kwargs):
        """
        WantAdditionalLocateHelper(self: MSPyDgnView.DgnElementSetTool, ev: MSPyDgnView.DgnButtonEvent) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
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
    
class ModifyOp:
    """
    None
    """

    def __init__(self: MSPyDgnView.ModifyOp) -> None:
        ...
    
class QvViewportRef:
    """
    None
    """

    def ActiveToRoot(*args, **kwargs):
        """
        ActiveToRoot(*args, **kwargs)
        Overloaded function.
        
        1. ActiveToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, activePts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ActiveToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, activePt: MSPyBentleyGeom.DPoint3d) -> None
        
        3. ActiveToRoot(self: MSPyDgnPlatform.Viewport, rootRMatrix: MSPyBentleyGeom.RotMatrix, activeRMatrix: MSPyBentleyGeom.RotMatrix) -> None
        """
        ...
    
    @property
    def ActiveToRootMap(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d:
        ...
    
    def ActiveToView(*args, **kwargs):
        """
        ActiveToView(*args, **kwargs)
        Overloaded function.
        
        1. ActiveToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, activePts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ActiveToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, activePt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    @property
    def ActiveZRoot(arg0: MSPyDgnPlatform.Viewport) -> float:
        ...
    
    def AdjustColorForContrast(*args, **kwargs):
        """
        AdjustColorForContrast(self: MSPyDgnPlatform.Viewport, thisColor: int, againstColor: int) -> int
        """
        ...
    
    @property
    def BackgroundColor(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    @property
    def CameraRoot(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.CameraParams:
        ...
    
    @property
    def ClipBoundElementRef(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @property
    def ClipMaskElementRef(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def ComputeDisplayedModelRefRange(*args, **kwargs):
        """
        ComputeDisplayedModelRefRange(self: MSPyDgnPlatform.Viewport, range: MSPyBentleyGeom.DRange3d, modelRef: MSPyDgnPlatform.DgnModelRef, includeChildren: bool, fitParams: MSPyDgnPlatform.FitViewParams) -> int
        
        Compute range of a model ref when display in the viewport
        """
        ...
    
    def ComputeFittedElementRange(*args, **kwargs):
        """
        ComputeFittedElementRange(self: MSPyDgnPlatform.Viewport, range: MSPyBentleyGeom.DRange3d, elements: Bentley.DgnPlatform.IElementSet, rMatrix: MSPyBentleyGeom.RotMatrix) -> int
        
        Compute the range of the element when displayed in the viewport
        """
        ...
    
    @property
    def ContrastToBackgroundColor(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    def GetActiveToRootMap(*args, **kwargs):
        """
        GetActiveToRootMap(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d
        """
        ...
    
    def GetActiveZRoot(*args, **kwargs):
        """
        GetActiveZRoot(self: MSPyDgnPlatform.Viewport) -> float
        """
        ...
    
    def GetBackgroundColor(*args, **kwargs):
        """
        GetBackgroundColor(self: MSPyDgnPlatform.Viewport) -> int
        """
        ...
    
    def GetCameraRoot(*args, **kwargs):
        """
        GetCameraRoot(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.CameraParams
        """
        ...
    
    def GetCameraTarget(*args, **kwargs):
        """
        GetCameraTarget(self: MSPyDgnPlatform.Viewport, target: MSPyBentleyGeom.DPoint3d) -> int
        """
        ...
    
    def GetCameraView(*args, **kwargs):
        """
        GetCameraView(self: MSPyDgnPlatform.Viewport, camera: Bentley.DgnPlatform.CameraParams) -> None
        """
        ...
    
    def GetClipBoundElemHandle(*args, **kwargs):
        """
        GetClipBoundElemHandle(self: MSPyDgnPlatform.Viewport, eeh: Bentley.DgnPlatform.EditElementHandle) -> int
        """
        ...
    
    def GetClipBoundElementRef(*args, **kwargs):
        """
        GetClipBoundElementRef(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase
        """
        ...
    
    def GetClipMaskElemHandle(*args, **kwargs):
        """
        GetClipMaskElemHandle(self: MSPyDgnPlatform.Viewport, eeh: Bentley.DgnPlatform.EditElementHandle) -> int
        """
        ...
    
    def GetClipMaskElementRef(*args, **kwargs):
        """
        GetClipMaskElementRef(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.ElementRefBase
        """
        ...
    
    def GetContrastToBackgroundColor(*args, **kwargs):
        """
        GetContrastToBackgroundColor(self: MSPyDgnPlatform.Viewport) -> int
        """
        ...
    
    def GetHiliteColor(*args, **kwargs):
        """
        GetHiliteColor(self: MSPyDgnPlatform.Viewport) -> int
        """
        ...
    
    def GetHiliteColorFromPath(*args, **kwargs):
        """
        GetHiliteColorFromPath(self: MSPyDgnPlatform.Viewport, path: Bentley.DgnPlatform.DisplayPath) -> int
        """
        ...
    
    def GetICachedDraw(*args, **kwargs):
        """
        GetICachedDraw(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ICachedDraw
        
        Gets the object required for advanced cached drawing to the Viewport.
        Cached Drawing is seldom required by applications.
        """
        ...
    
    def GetIViewDraw(*args, **kwargs):
        """
        GetIViewDraw(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.IViewDraw
        
        Gets the object required for immediate drawing to the Viewport. The
        methods on IViewDraw can be used to draw View Decorators.
        """
        ...
    
    def GetIViewOutput(*args, **kwargs):
        """
        GetIViewOutput(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.IViewOutput
        
        Gets the object required for advanced immediate drawing to the
        Viewport. IViewOutput is a subclass of IViewDraw, and generally only
        IViewDraw is needed.
        """
        ...
    
    def GetIndexedLinePattern(*args, **kwargs):
        """
        GetIndexedLinePattern(self: MSPyDgnPlatform.Viewport, index: int) -> int
        """
        ...
    
    def GetIndexedLineWidth(*args, **kwargs):
        """
        GetIndexedLineWidth(self: MSPyDgnPlatform.Viewport, index: int) -> int
        """
        ...
    
    def GetPixelSizeAtPoint(*args, **kwargs):
        """
        GetPixelSizeAtPoint(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, coordSys: MSPyDgnPlatform.DgnCoordSystem = <DgnCoordSystem.eRoot: 3>) -> float
        
        Get the size of a single pixel at a given point as a distance along
        the view-x axis. The size of a pixel will only differ at different
        points within the same Viewport if the camera is on for this Viewport
        (in which case, points closer to the eye return larger values than
        ones further from the eye.)
        
        Parameter ``rootPt``:
        The point in DgnCoordSystem.Root for determining pixel size. If
        NULL, use the center of the Viewport.
        
        Parameter ``coordSys``:
        The coordinate system for the returned distance.
        
        Returns:
        the size of the pixel at point ``rootPt.``
        """
        ...
    
    def GetRootModel(*args, **kwargs):
        """
        GetRootModel(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModel
        """
        ...
    
    def GetRootToNpcMap(*args, **kwargs):
        """
        GetRootToNpcMap(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d
        """
        ...
    
    def GetRootToViewMap(*args, **kwargs):
        """
        GetRootToViewMap(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d
        """
        ...
    
    def GetRotMatrix(*args, **kwargs):
        """
        GetRotMatrix(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.RotMatrix
        """
        ...
    
    def GetScale(*args, **kwargs):
        """
        GetScale(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d
        """
        ...
    
    def GetScreenNumber(*args, **kwargs):
        """
        GetScreenNumber(self: MSPyDgnPlatform.Viewport) -> int
        
        Get the screen number on which this Viewport resides.
        """
        ...
    
    def GetTargetModel(*args, **kwargs):
        """
        GetTargetModel(self: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModelRef
        """
        ...
    
    def GetViewBox(*args, **kwargs):
        """
        GetViewBox(self: MSPyDgnPlatform.Viewport, points: MSPyBentleyGeom.DPoint3dArray, sys: MSPyDgnPlatform.DgnCoordSystem, adjustedBox: bool) -> None
        """
        ...
    
    def GetViewCorners(*args, **kwargs):
        """
        GetViewCorners(self: MSPyDgnPlatform.Viewport, low: MSPyBentleyGeom.DPoint3d, high: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def GetViewDelta(*args, **kwargs):
        """
        GetViewDelta(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d
        
        Get the View Delta (size) of this Viewport in root coordinate
        distances.
        
        Returns:
        the view delta in root coordinate distances.
        """
        ...
    
    def GetViewFlags(*args, **kwargs):
        """
        GetViewFlags(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewFlags
        
        Get the current View Flags for this Viewport.
        
        Returns:
        the View flags for this Viewport.
        """
        ...
    
    def GetViewInfo(*args, **kwargs):
        """
        GetViewInfo(self: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewInfo
        """
        ...
    
    def GetViewName(*args, **kwargs):
        """
        GetViewName(self: MSPyDgnPlatform.Viewport, name: MSPyBentley.WString) -> None
        """
        ...
    
    def GetViewNumber(*args, **kwargs):
        """
        GetViewNumber(self: MSPyDgnPlatform.Viewport) -> int
        
        Get the view number of this Viewport. If this Viewport is one of the 8
        MicroStation numbered views (i.e. " View 1 " through " View 8 "), then
        return the index of view number (e.g. " View 1 " is view index 0, " View 8 " is view index 7). If the Viewport is not one of the 8 MicroStation
        numbered views, this method will return -1.
        
        Returns:
        the view index of this Viewport, or -1 if it is not one of the
        numbered views.
        """
        ...
    
    def GetViewOrigin(*args, **kwargs):
        """
        GetViewOrigin(self: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d
        
        Get View Origin for this Viewport.
        
        Returns:
        the root coordinates of the lower left back corner of the
        Viewport.
        """
        ...
    
    def GetViewRect(*args, **kwargs):
        """
        GetViewRect(self: MSPyDgnPlatform.Viewport, rect: MSPyDgnPlatform.BSIRect) -> None
        """
        ...
    
    @property
    def HiliteColor(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    @property
    def ICachedDraw(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ICachedDraw:
        ...
    
    @property
    def IViewDraw(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.IViewDraw:
        ...
    
    @property
    def IViewOutput(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.IViewOutput:
        ...
    
    def Is3dModel(*args, **kwargs):
        """
        Is3dModel(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsActive(*args, **kwargs):
        """
        IsActive(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsCameraOn(*args, **kwargs):
        """
        IsCameraOn(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsGridOn(*args, **kwargs):
        """
        IsGridOn(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def IsSheetView(*args, **kwargs):
        """
        IsSheetView(self: MSPyDgnPlatform.Viewport) -> bool
        """
        ...
    
    def MakeColorTransparency(*args, **kwargs):
        """
        MakeColorTransparency(color: int, transparency: int) -> int
        """
        ...
    
    def MakeTransparentIfOpaque(*args, **kwargs):
        """
        MakeTransparentIfOpaque(color: int, transparency: int) -> int
        """
        ...
    
    def MakeTrgbColor(*args, **kwargs):
        """
        MakeTrgbColor(red: int, green: int, blue: int, transparency: int) -> int
        """
        ...
    
    def NpcToRoot(*args, **kwargs):
        """
        NpcToRoot(*args, **kwargs)
        Overloaded function.
        
        1. NpcToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. NpcToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def NpcToView(*args, **kwargs):
        """
        NpcToView(*args, **kwargs)
        Overloaded function.
        
        1. NpcToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. NpcToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ResynchColorMap(*args, **kwargs):
        """
        ResynchColorMap(self: MSPyDgnPlatform.Viewport) -> None
        """
        ...
    
    @property
    def RootModel(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModel:
        ...
    
    def RootToActive(*args, **kwargs):
        """
        RootToActive(*args, **kwargs)
        Overloaded function.
        
        1. RootToActive(self: MSPyDgnPlatform.Viewport, activePts: MSPyBentleyGeom.DPoint3dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToActive(self: MSPyDgnPlatform.Viewport, activePt: MSPyBentleyGeom.DPoint3d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        
        3. RootToActive(self: MSPyDgnPlatform.Viewport, activeRMatrix: MSPyBentleyGeom.RotMatrix, rootRMatrix: MSPyBentleyGeom.RotMatrix) -> None
        """
        ...
    
    def RootToNpc(*args, **kwargs):
        """
        RootToNpc(*args, **kwargs)
        Overloaded function.
        
        1. RootToNpc(self: MSPyDgnPlatform.Viewport, npcPts: MSPyBentleyGeom.DPoint3dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToNpc(self: MSPyDgnPlatform.Viewport, npcPt: MSPyBentleyGeom.DPoint3d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    @property
    def RootToNpcMap(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d:
        ...
    
    def RootToView(*args, **kwargs):
        """
        RootToView(*args, **kwargs)
        Overloaded function.
        
        1. RootToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint4dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint4d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        
        3. RootToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        4. RootToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def RootToView2d(*args, **kwargs):
        """
        RootToView2d(*args, **kwargs)
        Overloaded function.
        
        1. RootToView2d(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint2dArray, rootPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. RootToView2d(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint2d, rootPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    @property
    def RootToViewMap(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DMap4d:
        ...
    
    @property
    def RotMatrix(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.RotMatrix:
        ...
    
    @property
    def Scale(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def ScreenNumber(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    def ScreenToView(*args, **kwargs):
        """
        ScreenToView(*args, **kwargs)
        Overloaded function.
        
        1. ScreenToView(self: MSPyDgnPlatform.Viewport, viewPts: MSPyBentleyGeom.DPoint3dArray, screenPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ScreenToView(self: MSPyDgnPlatform.Viewport, viewPt: MSPyBentleyGeom.DPoint3d, screenPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def Scroll(*args, **kwargs):
        """
        Scroll(self: MSPyDgnPlatform.Viewport, viewDist: MSPyBentleyGeom.Point2d) -> int
        
        @name Changing Viewport Frustum Scroll the Viewport by a given number
        of pixels in the view's X and/or Y direction. This method will move
        the Viewport's frustum in the indicated direction, but does *not*
        update the screen (even if the Viewport happens to be a visible View.)
        This method does change the ViewInfo associated with the Viewport.
        
        Parameter ``viewDist``:
        The distance to scroll, in pixels. @note To update the view, see
        IViewManager.UpdateView or IViewManager.UpdateViewDynamic. To
        save the change to the ViewInfo in the view undo buffer, see
        SynchWithViewInfo.
        """
        ...
    
    def SetMinimumLOD(*args, **kwargs):
        """
        SetMinimumLOD(self: MSPyDgnPlatform.Viewport, minLod: float) -> None
        """
        ...
    
    def SetNeedsRefresh(*args, **kwargs):
        """
        SetNeedsRefresh(self: MSPyDgnPlatform.Viewport) -> None
        
        Sets the flag indicating that the Viewport needs to be refreshed from
        the backing store at the next opportunity. When the Viewport is
        refreshed, the view decorators are redrawn.
        """
        ...
    
    def SetSymbologyRgb(*args, **kwargs):
        """
        SetSymbologyRgb(self: MSPyDgnPlatform.Viewport, lineColorTBGR: int, fillColorTBGR: int, lineWidth: int, lineColorIndex: int) -> None
        """
        ...
    
    def SetTemporaryClipElementRef(*args, **kwargs):
        """
        SetTemporaryClipElementRef(self: MSPyDgnPlatform.Viewport, element: MSPyDgnPlatform.ElementRefBase) -> None
        """
        ...
    
    def SetTemporaryClipMaskElementRef(*args, **kwargs):
        """
        SetTemporaryClipMaskElementRef(self: MSPyDgnPlatform.Viewport, element: MSPyDgnPlatform.ElementRefBase) -> None
        """
        ...
    
    def SetupFromFrustum(*args, **kwargs):
        """
        SetupFromFrustum(self: MSPyDgnPlatform.Viewport, frustPts: MSPyBentleyGeom.DPoint3dArray) -> int
        """
        ...
    
    def SynchWithViewInfo(*args, **kwargs):
        """
        SynchWithViewInfo(self: MSPyDgnPlatform.Viewport, saveInUndo: bool, updateViewTitle: bool) -> MSPyDgnPlatform.BentleyStatus
        
        Synchronizes the view information that is displayed with this
        viewport. Optionally add an entry in the view undo stack and update
        the view title.
        """
        ...
    
    @property
    def TargetModel(arg0: MSPyDgnPlatform.Viewport) -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    @property
    def ViewDelta(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def ViewFlags(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewFlags:
        ...
    
    @property
    def ViewInfo(arg0: MSPyDgnPlatform.Viewport) -> Bentley.DgnPlatform.ViewInfo:
        ...
    
    @property
    def ViewNumber(arg0: MSPyDgnPlatform.Viewport) -> int:
        ...
    
    @property
    def ViewOrigin(arg0: MSPyDgnPlatform.Viewport) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def ViewToActive(*args, **kwargs):
        """
        ViewToActive(*args, **kwargs)
        Overloaded function.
        
        1. ViewToActive(self: MSPyDgnPlatform.Viewport, activePts: MSPyBentleyGeom.DPoint3dArray, viewPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ViewToActive(self: MSPyDgnPlatform.Viewport, activePt: MSPyBentleyGeom.DPoint3d, viewPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ViewToNpc(*args, **kwargs):
        """
        ViewToNpc(*args, **kwargs)
        Overloaded function.
        
        1. ViewToNpc(self: MSPyDgnPlatform.Viewport, npcPts: MSPyBentleyGeom.DPoint3dArray, viewPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ViewToNpc(self: MSPyDgnPlatform.Viewport, npcPt: MSPyBentleyGeom.DPoint3d, viewPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ViewToRoot(*args, **kwargs):
        """
        ViewToRoot(*args, **kwargs)
        Overloaded function.
        
        1. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint4dArray) -> None
        
        2. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint4d) -> None
        
        3. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPts: MSPyBentleyGeom.DPoint3dArray, npcPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        4. ViewToRoot(self: MSPyDgnPlatform.Viewport, rootPt: MSPyBentleyGeom.DPoint3d, npcPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def ViewToScreen(*args, **kwargs):
        """
        ViewToScreen(*args, **kwargs)
        Overloaded function.
        
        1. ViewToScreen(self: MSPyDgnPlatform.Viewport, screenPts: MSPyBentleyGeom.DPoint3dArray, viewPts: MSPyBentleyGeom.DPoint3dArray) -> None
        
        2. ViewToScreen(self: MSPyDgnPlatform.Viewport, screenPt: MSPyBentleyGeom.DPoint3d, viewPt: MSPyBentleyGeom.DPoint3d) -> None
        """
        ...
    
    def Zoom(*args, **kwargs):
        """
        Zoom(self: MSPyDgnPlatform.Viewport, newCenterPoint: MSPyBentleyGeom.DPoint3d, factor: float, normalizeCamera: bool) -> int
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class RedrawElems:
    """
    None
    """

    def AddViewport(*args, **kwargs):
        """
        AddViewport(self: MSPyDgnView.RedrawElems, vp: MSPyDgnPlatform.Viewport) -> None
        
        Add a view to the current list of views to display to.
        """
        ...
    
    def DoRedraw(*args, **kwargs):
        """
        DoRedraw(*args, **kwargs)
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
    
    def SetAbort(*args, **kwargs):
        """
        SetAbort(self: MSPyDgnView.RedrawElems, abort: MSPyDgnView.IRedrawAbort) -> None
        
        Supply an optional class to handle CheckStop/abort processing.
        """
        ...
    
    def SetClipVector(*args, **kwargs):
        """
        SetClipVector(self: MSPyDgnView.RedrawElems, clip: MSPyDgnPlatform.ClipVector) -> None
        
        Supply an optional ClipVector to push before displaying elements.
        """
        ...
    
    def SetDrawMode(*args, **kwargs):
        """
        SetDrawMode(self: MSPyDgnView.RedrawElems, mode: MSPyDgnPlatform.DgnDrawMode) -> None
        
        Set DgnDrawMode to use for display. Use DRAW_MODE_TempDraw for
        dynamics.
        """
        ...
    
    def SetDrawPurpose(*args, **kwargs):
        """
        SetDrawPurpose(self: MSPyDgnView.RedrawElems, purpose: MSPyDgnPlatform.DrawPurpose) -> None
        
        Set DrawPurpose appropriate to display reason.
        """
        ...
    
    def SetDynamicsViews(*args, **kwargs):
        """
        SetDynamicsViews(self: MSPyDgnView.RedrawElems, viewSet: Bentley.DgnPlatform.IndexedViewSet, cursorView: MSPyDgnPlatform.Viewport) -> None
        
        Set views for dynamic display. The cursor view is given priority.
        """
        ...
    
    def SetIgnoreHilite(*args, **kwargs):
        """
        SetIgnoreHilite(self: MSPyDgnView.RedrawElems, ignore: bool) -> None
        
        Set to ignore locate/selection set hilite symbology when drawing a
        persistent element.
        """
        ...
    
    def SetOneView(*args, **kwargs):
        """
        SetOneView(self: MSPyDgnView.RedrawElems, viewSet: Bentley.DgnPlatform.IndexedViewSet, view: int) -> None
        
        Set an individual viewport to display to by view number.
        """
        ...
    
    def SetRedrawOp(*args, **kwargs):
        """
        SetRedrawOp(self: MSPyDgnView.RedrawElems, op: MSPyDgnView.IRedrawOperation) -> None
        
        Supply an optional class for element resymbolization and subsitution
        events.
        """
        ...
    
    def SetSearchDgnAttachments(*args, **kwargs):
        """
        SetSearchDgnAttachments(self: MSPyDgnView.RedrawElems, other: bool) -> None
        
        When drawing an element, or list of elements to a Viewport, sometimes
        it is desirable to also search all other DgnModelRefs that are visible
        in that Viewport and, if the other modelref points to the same cache
        (but most likely with a different transform), also draw the element
        through that other modelRef. In general, most users should not enable
        this.
        """
        ...
    
    def SetTransform(*args, **kwargs):
        """
        SetTransform(self: MSPyDgnView.RedrawElems, trans: MSPyBentleyGeom.Transform) -> None
        
        Supply an optional transform to push before displaying elements.
        """
        ...
    
    def SetViewport(*args, **kwargs):
        """
        SetViewport(self: MSPyDgnView.RedrawElems, vp: MSPyDgnPlatform.Viewport) -> None
        
        Set an individual viewport to display to.
        """
        ...
    
    def SetViews(*args, **kwargs):
        """
        SetViews(self: MSPyDgnView.RedrawElems, viewSet: Bentley.DgnPlatform.IndexedViewSet, viewMask: int) -> None
        
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

    def ActivatePrevious(*args, **kwargs):
        """
        ActivatePrevious(self: MSPyDgnView.SelectionSetManager) -> None
        
        Make previous selection set current. Bentley Systems +---------------+
        ---------------+---------------+---------------+---------------+------
        """
        ...
    
    def AddElement(*args, **kwargs):
        """
        AddElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus
        
        Add an element to the current selection set.
        
        Parameter ``elem``:
        IN Element to add.
        
        Parameter ``elemModel``:
        IN DgnModelRef of element being added.
        
        Returns:
        SUCCESS if entry was added. Bentley Systems +---------------+-----
        ----------+---------------+---------------+---------------+------
        """
        ...
    
    def AddElementSet(*args, **kwargs):
        """
        AddElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus
        
        Add a set of elements to the current selection set.
        
        Parameter ``elSet``:
        IN Elements to add.
        
        Returns:
        SUCCESS if at least one entry was added. Bentley Systems +--------
        -------+---------------+---------------+---------------+----------
        -----+------
        """
        ...
    
    def AddListener(*args, **kwargs):
        """
        AddListener(self: MSPyDgnView.SelectionSetManager, listener: MSPyDgnView.ISelectionEvents) -> None
        
        Add selection set changed/event listener.
        
        Parameter ``selectionListener``:
        IN The listener object to add. Bentley Systems +---------------+--
        -------------+---------------+---------------+---------------+----
        --
        """
        ...
    
    def BuildAgenda(*args, **kwargs):
        """
        BuildAgenda(*args, **kwargs)
        Overloaded function.
        
        1. BuildAgenda(self: MSPyDgnView.SelectionSetManager, agenda: MSPyDgnPlatform.ElementAgenda, searchList: MSPyDgnPlatform.DgnModelRefList, modifyOrig: bool, allowLocked: bool, callAsynch: bool) -> int
        
        Populate an element agenda suitable for modification from the current
        selection set.
        
        Parameter ``agenda``:
        IN OUT selection set entries that passed the input criteria.
        
        Parameter ``searchList``:
        IN list of acceptable modelRefs to filter selection set entries..
        
        Parameter ``modifyOrig``:
        IN whether agenda will be used to modify original elements.
        
        Parameter ``allowLocked``:
        IN whether to accept locked elements.
        
        Parameter ``callAsynch``:
        IN whether to call GLOBAL_LOCATE_SELECTIONSET filter.
        
        Returns:
        SUCCESS if agenda contains at least one entry. Bentley Systems +--
        -------------+---------------+---------------+---------------+----
        -----------+------
        
        2. BuildAgenda(self: MSPyDgnView.SelectionSetManager, agenda: MSPyDgnPlatform.ElementAgenda) -> int
        
        Populate an element agenda suitable for modification from the current
        selection set.
        
        Parameter ``agenda``:
        IN OUT selection set entries that passed the input criteria.
        
        Parameter ``searchList``:
        IN list of acceptable modelRefs to filter selection set entries..
        
        Parameter ``modifyOrig``:
        IN whether agenda will be used to modify original elements.
        
        Parameter ``allowLocked``:
        IN whether to accept locked elements.
        
        Parameter ``callAsynch``:
        IN whether to call GLOBAL_LOCATE_SELECTIONSET filter.
        
        Returns:
        SUCCESS if agenda contains at least one entry. Bentley Systems +--
        -------------+---------------+---------------+---------------+----
        -----------+------
        """
        ...
    
    def DropListener(*args, **kwargs):
        """
        DropListener(self: MSPyDgnView.SelectionSetManager, listener: MSPyDgnView.ISelectionEvents) -> None
        
        Drop selection set changed/event listener.
        
        Parameter ``selectionListener``:
        IN The listener object to drop. Bentley Systems +---------------+-
        --------------+---------------+---------------+---------------+---
        ---
        """
        ...
    
    def EmptyAll(*args, **kwargs):
        """
        EmptyAll(self: MSPyDgnView.SelectionSetManager) -> None
        
        Clear current selection set. Current selection set becomes previous
        selection set. Bentley Systems +---------------+---------------+------
        ---------+---------------+---------------+------
        """
        ...
    
    def GetElement(*args, **kwargs):
        """
        GetElement(self: MSPyDgnView.SelectionSetManager, index: int, eh: MSPyDgnPlatform.ElementHandle) -> int
        
        Get the ElementRefP and DgnModelRef in the current selection set by
        index.
        
        Parameter ``index``:
        IN The index to get the entry for.
        
        Parameter ``elemRef``:
        OUT ElementRefP at index.
        
        Parameter ``modelRef``:
        OUT DgnModelRef at index.
        
        Returns:
        SUCCESS if index was valid. Bentley Systems +---------------+-----
        ----------+---------------+---------------+---------------+------
        """
        ...
    
    def GetManager(*args, **kwargs):
        """
        GetManager() -> MSPyDgnView.SelectionSetManager
        
        Get the manager class for selection sets.
        
        Returns:
        The SelectionSetManager class. Bentley Systems +---------------+--
        -------------+---------------+---------------+---------------+----
        --
        """
        ...
    
    def InvertElement(*args, **kwargs):
        """
        InvertElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus
        
        Add element not currently selected and remove element currently
        selected.
        
        Parameter ``elem``:
        IN Element to process.
        
        Parameter ``elemModel``:
        IN DgnModelRef of element being processed.
        
        Returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def InvertElementSet(*args, **kwargs):
        """
        InvertElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus
        
        Add elements not currently selected and remove elements currently
        selected.
        
        Parameter ``elSet``:
        IN Elements to process.
        
        Returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def IsActive(*args, **kwargs):
        """
        IsActive(self: MSPyDgnView.SelectionSetManager) -> bool
        
        Check whether there is a current selection set active.
        
        Returns:
        true if current selection set contains at least one entry. Bentley
        Systems +---------------+---------------+---------------+---------
        ------+---------------+------
        """
        ...
    
    Manager: SelectionSetManager
    
    def ModifyWithElementSets(*args, **kwargs):
        """
        ModifyWithElementSets(self: MSPyDgnView.SelectionSetManager, toRemove: MSPyDgnPlatform.IElementSet, toAdd: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus
        
        Modifies current selection by removing and adding sets of elements.
        
        Parameter ``toRemove``:
        IN Elements to remove.
        
        Parameter ``toAdd``:
        IN Elements to add.
        
        Returns:
        SUCCESS if at least one entry was added or removed. @note Remove
        list is processed before add list. Bentley Systems +--------------
        -+---------------+---------------+---------------+---------------+
        ------
        """
        ...
    
    def NumSelected(*args, **kwargs):
        """
        NumSelected(self: MSPyDgnView.SelectionSetManager) -> int
        
        Get the number of entries in the current selection set.
        
        Returns:
        count of entries in current selection set. Bentley Systems +------
        ---------+---------------+---------------+---------------+--------
        -------+------
        """
        ...
    
    def RemoveElement(*args, **kwargs):
        """
        RemoveElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus
        
        Remove an element from the current selection set.
        
        Parameter ``elem``:
        IN Element to remove.
        
        Parameter ``elemModel``:
        IN DgnModelRef of element being removed.
        
        Returns:
        SUCCESS if entry was removed. Bentley Systems +---------------+---
        ------------+---------------+---------------+---------------+-----
        -
        """
        ...
    
    def RemoveElementSet(*args, **kwargs):
        """
        RemoveElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus
        
        Remove a set of elements to the current selection set.
        
        Parameter ``elSet``:
        IN Elements to remove.
        
        Returns:
        SUCCESS if at least one entry was removed. Bentley Systems +------
        ---------+---------------+---------------+---------------+--------
        -------+------
        """
        ...
    
    def ReplaceWithElement(*args, **kwargs):
        """
        ReplaceWithElement(self: MSPyDgnView.SelectionSetManager, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus
        
        Set the current selection set to the supplied element.
        
        Parameter ``elem``:
        IN Element to become new selection.
        
        Parameter ``elemModel``:
        IN DgnModelRef of replacement element.
        
        Returns:
        SUCCESS if current selection was changed. Bentley Systems +-------
        --------+---------------+---------------+---------------+---------
        ------+------
        """
        ...
    
    def ReplaceWithElementSet(*args, **kwargs):
        """
        ReplaceWithElementSet(self: MSPyDgnView.SelectionSetManager, elemSet: MSPyDgnPlatform.IElementSet) -> MSPyDgnPlatform.BentleyStatus
        
        Set the current selection set to the supplied set of elements.
        
        Parameter ``elSet``:
        IN Elements to become current selection.
        
        Returns:
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
    
class StopEvents:
    """
    None
    """

    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyDgnView.StopEvents) -> None
        """
        ...
    
    def SetStopOnModifierKey(*args, **kwargs):
        """
        SetStopOnModifierKey(self: MSPyDgnView.StopEvents, stop: bool) -> None
        
        Stop when the ctrl or shift key is pressed or released.
        """
        ...
    
    def __init__(self: MSPyDgnView.StopEvents, keystrokes: bool, controlC: bool, wheel: bool, button: bool, paint: bool, focus: bool) -> None:
        ...
    
    @property
    def button(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @button.setter
    def button(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
    @property
    def controlC(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @controlC.setter
    def controlC(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
    @property
    def focus(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @focus.setter
    def focus(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
    @property
    def keystrokes(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @keystrokes.setter
    def keystrokes(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
    @property
    def modifierKeyTransition(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @modifierKeyTransition.setter
    def modifierKeyTransition(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
    @property
    def paint(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @paint.setter
    def paint(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
    @property
    def wheel(arg0: MSPyDgnView.StopEvents) -> bool:
        ...
    @wheel.setter
    def wheel(arg0: MSPyDgnView.StopEvents, arg1: bool) -> None:
        ...
    
class TentativePoint:
    """
    None
    """

    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyDgnView.TentativePoint, erase: bool) -> None
        
        Clear the current tentative point so that it is no longer active.
        """
        ...
    
    def GetInstance(*args, **kwargs):
        """
        GetInstance() -> MSPyDgnView.TentativePoint
        
        Get the current TentativePoint instance.
        """
        ...
    
    def GetPoint(*args, **kwargs):
        """
        GetPoint(self: MSPyDgnView.TentativePoint) -> MSPyBentleyGeom.DPoint3d
        
        Returns:
        The current tentative point location as adjusted by the snap mode
        and locks.
        """
        ...
    
    Instance: TentativePoint
    
    def IsActive(*args, **kwargs):
        """
        IsActive(self: MSPyDgnView.TentativePoint) -> bool
        
        Returns:
        true if the tentative point is currently active.
        """
        ...
    
    def IsSnapped(*args, **kwargs):
        """
        IsSnapped(self: MSPyDgnView.TentativePoint) -> bool
        
        Returns:
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
    
class UpdateAbortReason:
    """
    Members:
    
    eUPDATE_ABORT_None
    
    eUPDATE_ABORT_BadView
    
    eUPDATE_ABORT_Motion
    
    eUPDATE_ABORT_MotionStopped
    
    eUPDATE_ABORT_Keystroke
    
    eUPDATE_ABORT_ControlC
    
    eUPDATE_ABORT_MouseWheel
    
    eUPDATE_ABORT_Timeout
    
    eUPDATE_ABORT_Button
    
    eUPDATE_ABORT_Paint
    
    eUPDATE_ABORT_Focus
    
    eUPDATE_ABORT_ModifierKey
    """

    def __init__(self: MSPyDgnView.UpdateAbortReason, value: int) -> None:
        ...
    
    eUPDATE_ABORT_BadView: UpdateAbortReason
    
    eUPDATE_ABORT_Button: UpdateAbortReason
    
    eUPDATE_ABORT_ControlC: UpdateAbortReason
    
    eUPDATE_ABORT_Focus: UpdateAbortReason
    
    eUPDATE_ABORT_Keystroke: UpdateAbortReason
    
    eUPDATE_ABORT_ModifierKey: UpdateAbortReason
    
    eUPDATE_ABORT_Motion: UpdateAbortReason
    
    eUPDATE_ABORT_MotionStopped: UpdateAbortReason
    
    eUPDATE_ABORT_MouseWheel: UpdateAbortReason
    
    eUPDATE_ABORT_None: UpdateAbortReason
    
    eUPDATE_ABORT_Paint: UpdateAbortReason
    
    eUPDATE_ABORT_Timeout: UpdateAbortReason
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyDgnView.UpdateAbortReason) -> int:
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

eUPDATE_ABORT_BadView: UpdateAbortReason

eUPDATE_ABORT_Button: UpdateAbortReason

eUPDATE_ABORT_ControlC: UpdateAbortReason

eUPDATE_ABORT_Focus: UpdateAbortReason

eUPDATE_ABORT_Keystroke: UpdateAbortReason

eUPDATE_ABORT_ModifierKey: UpdateAbortReason

eUPDATE_ABORT_Motion: UpdateAbortReason

eUPDATE_ABORT_MotionStopped: UpdateAbortReason

eUPDATE_ABORT_MouseWheel: UpdateAbortReason

eUPDATE_ABORT_None: UpdateAbortReason

eUPDATE_ABORT_Paint: UpdateAbortReason

eUPDATE_ABORT_Timeout: UpdateAbortReason

