from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyMstnPlatform

class ACS:
    """
    None
    """

    @staticmethod
    def AttachNamed(acsName: str, useRot: bool, useOrg: bool) -> int:
        """
        @description Attaches the named auxiliary coordinate system (ACS) to
        the active model.
        
        Parameter ``unparsed``:
        the name of the coordinate system to attach
        
        Parameter ``useRot``:
        true means apply the rotation stored in the named ACS, and false
        means ignore it
        
        Parameter ``useOrg``:
        true means apply the origin stored in the named ACS, and false
        means ignore it
        
        Returns:
        SUCCESS if the coordinate system is successfully attached and
        MDLERR_ACSNOTFOUND if the specified coordinate system is not
        found.
        
        See also:
        ACS.DeleteNamed ACS.SaveNamed @See ACS.SaveNamed
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateElmdscrFromParams(type: int, origin: MSPyBentleyGeom.DPoint3d, rotation: MSPyBentleyGeom.RotMatrix, name: str, description: str) -> tuple:
        """
        @description Creates an ACS element descriptor from the given
        parameters.
        
        Parameter ``edPP``:
        is the newly created ACS element descriptor, which you must free
        when done.
        
        Parameter ``type``:
        is one of the valid ACS type constants. Possible values are:<UL>
        <LI>ACS_TYPE_NONE <LI>ACS_TYPE_RECT <LI>ACS_TYPE_CYL
        <LI>ACS_TYPE_SPHERE </UL>
        
        Parameter ``originP``:
        origin of the ACS.
        
        Parameter ``rotationP``:
        rotation of the ACS.
        
        Parameter ``nameP``:
        name of the ACS.
        
        Parameter ``descriptionP``:
        the description of the ACS.
        
        Returns:
        SUCCESS if the element descriptor was created successfully,
        MDLERR_BADARG if any of the parameters was not valid.
        
        Remark:
        """
        ...
    
    @staticmethod
    def DeleteNamed(acsName: str) -> int:
        """
        @description Deletes the named coordinate system specified.
        
        Parameter ``acsName``:
        name of the coordinate system
        
        Returns:
        SUCCESS if the coordinate system is successfully deleted and
        MDLERR_ACSNOTFOUND if the specified coordinate system is not
        found.
        
        See also:
        ACS.AttachNamed ACS.SaveNamed
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetCanonicalDescription(descr: str) -> tuple:
        """
        @description Canonize the specified ACS description string. The result
        is the name string stripped of leading and trailing whitespace
        characters, whose length and content has been validated.
        
        Parameter ``canonicalP``:
        points to a string buffer where the canonized description is
        placed. This buffer should be MAX_ACS_DESCR_LENGTH MSWChars long.
        
        Parameter ``descrP``:
        ACS description to be canonized.
        
        Returns:
        SUCCESS unless the name string is too large (MDLERR_BADARG) or
        there is not enough memory to allocate working buffers
        (MDLERR_INSFMEMORY).
        
        See also:
        ACS.GetDescriptionOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetCanonicalName(name: str) -> tuple:
        """
        @description Canonizes the specified ACS name string. The result is
        the name string stripped of leading and trailing whitespace
        characters, whose length and content has been validated.
        
        Parameter ``canonicalP``:
        is a pointer to a string buffer where the canonized name is
        placed. This buffer should be MAX_ACS_NAME_LENGTH MSWChars long.
        
        Parameter ``nameP``:
        ACS name to be canonized.
        
        Returns:
        SUCCESS unless the name string is too large or there is not enough
        memory to allocate working buffers.
        
        See also:
        ACS.GetNameOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetCurrent() -> tuple:
        """
        @description Returns the current ACS's origin, rotation matrix, and
        type. @Remarks The coordinate system type is specified by one of the
        following types from msdefs.h:<UL> <LI>ACS_RECTANGULAR
        <LI>ACS_CYLINDRICAL <LI>ACS_SPHERICAL </UL>
        
        Parameter ``originP``:
        current ACS origin
        
        Parameter ``rotMatrixP``:
        current ACS orientation
        
        Parameter ``typeP``:
        current ACS type
        
        Parameter ``nameP``:
        points to a buffer where the name is copied. This buffer should be
        MAX_ACS_NAME_LENGTH MSWChars long.
        
        Parameter ``descriptionP``:
        points to a buffer where the description is copied. This buffer
        should be MAX_ACS_DESCR_LENGTH MSWChars long
        
        Returns:
        SUCCESS if an ACS is active and MDLERR_NOACSDEFINED if no system
        is currently defined.
        
        See also:
        ACS.SetCurrent
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDescriptionOfElmdscr(edP: MSPyDgnPlatform.MSElementDescr) -> tuple:
        """
        @description Gets the description from the specified ACS element.
        
        Parameter ``acsDescriptionP``:
        points to a buffer where the description is copied. This buffer
        should be MAX_ACS_DESCR_LENGTH MSWChars long
        
        Parameter ``edP``:
        points to the ACS element to get the description from.
        
        Returns:
        SUCCESS if the operation was completed successfully, otherwise
        ERROR.
        
        See also:
        ACS.SetDescriptionOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetNameOfElmdscr(edP: MSPyDgnPlatform.MSElementDescr) -> tuple:
        """
        @description Gets the name from the specified ACS element descriptor.
        
        Parameter ``acsNameP``:
        points to a buffer where the name is copied. This buffer should be
        MAX_ACS_NAME_LENGTH MSWChars long.
        
        Parameter ``edP``:
        points to the ACS element to get the name from.
        
        Returns:
        SUCCESS if the operation was completed successfully, otherwise
        ERROR.
        
        See also:
        ACS.SetNameOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetTypeOfElmdscr(edP: MSPyDgnPlatform.MSElementDescr) -> tuple:
        """
        @description Get the ACS type of the ACS element descriptor.
        
        Parameter ``acsTypeP``:
        points to a variable which will contain one of the following
        values upon a return of SUCCESS. <UL> <LI>ACS_TYPE_NONE
        <LI>ACS_TYPE_RECT <LI>ACS_TYPE_CYL <LI>ACS_TYPE_SPHERE </UL>
        
        Parameter ``edP``:
        points to the ACS element.
        
        Returns:
        SUCCESS if the element is an ACS element, MDLERR_BADARG if it is
        not.
        
        See also:
        ACS.SetTypeOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsDefined() -> bool:
        ...
    
    @staticmethod
    def Locate(name: str, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        @description Searches for an ACS using its assigned name.
        
        Parameter ``edPP``:
        Copy of ACS element descriptor. You must free it when done.
        
        Parameter ``filePosP``:
        file position of the located ACS element.
        
        Parameter ``inName``:
        name of the ACS element to find.
        
        Parameter ``modelRef``:
        model to search for the ACS element.
        
        Returns:
        SUCCESS if the operation completed successfully, otherwise ERROR.
        
        See also:
        ACS.TraverseElements
        
        Remark:
        """
        ...
    
    @staticmethod
    def SaveNamed(name: str, description: str) -> int:
        """
        @description Saves the current coordinate system with the specified
        name and description. The name must consist of one to
        MAX_ACS_NAME_LENGTH MSWChars, and the description can contain up to
        MAX_ACS_DESCR_LENGTH MSWChars. The user or an MDL application can
        recall saved coordinate systems with the ACS.AttachNamed function.
        
        Parameter ``name``:
        name of the ACS
        
        Parameter ``description``:
        description of the ACS
        
        Returns:
        SUCCESS if the coordinate system is successfully saved. If the
        coordinate system name already exists, the existing ACS is
        overwritten. If no ACS is active, MDLERR_NOACSDEFINED is returned.
        
        See also:
        ACS.AttachNamed ACS.DeleteNamed
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetCurrent(origin: MSPyBentleyGeom.DPoint3d, rotMatrix: MSPyBentleyGeom.RotMatrix, type: MSPyDgnPlatform.ACSType) -> int:
        """
        @description Defines the ACS of the active model. <UL>
        <LI>ACS_RECTANGULAR <LI>ACS_CYLINDRICAL <LI>ACS_SPHERICAL </UL>
        
        Parameter ``originP``:
        new ACS origin or pass NULL to leave unchanged
        
        Parameter ``rotMatrixP``:
        new ACS orientation or pass NULL to leave unchanged
        
        Parameter ``type``:
        new ACS type or pass NULL to leave unchanged
        
        Returns:
        SUCCESS if the coordinate system is successfully defined.
        
        See also:
        ACS.GetCurrent
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDescriptionOfElmdscr(edP: MSPyDgnPlatform.MSElementDescr, description: str) -> tuple:
        """
        @description Sets the description on the specified ACS element.
        
        Parameter ``edPP``:
        points to ACS element descriptor pointer.
        
        Parameter ``description``:
        points to a buffer where the description is stored.
        
        Returns:
        SUCCESS if the operation was completed successfully, otherwise
        ERROR.
        
        See also:
        ACS.GetDescriptionOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetNameOfElmdscr(edP: MSPyDgnPlatform.MSElementDescr, name: str) -> tuple:
        """
        @description Sets the name on the specified ACS element.
        
        Parameter ``edPP``:
        points to ACS element descriptor pointer.
        
        Parameter ``name``:
        points to a buffer where the name is stored.
        
        Returns:
        SUCCESS if the operation was completed successfully, otherwise
        ERROR.
        
        See also:
        ACS.GetNameOfElmdscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetTypeOfElmdscr(edP: MSPyDgnPlatform.MSElementDescr, acsType: int) -> int:
        """
        @description Sets the ACS type of the ACS element descriptor.
        
        Parameter ``edP``:
        ACS element descriptor which is being accessed
        
        Parameter ``acsTypeP``:
        type to set in the ACS, and should be one of:<UL>
        <LI>ACS_TYPE_NONE <LI>ACS_TYPE_RECT <LI>ACS_TYPE_CYL
        <LI>ACS_TYPE_SPHERE </UL>
        
        Returns:
        SUCCESS if the element is an ACS element, MDLERR_BADARG if it is
        not.
        
        See also:
        ACS.GetTypeOfElmdscr
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ActionButtonValue:
    """
    Members:
    
    eACTIONBUTTON_APPLY
    
    eACTIONBUTTON_RESET
    
    eACTIONBUTTON_OK
    
    eACTIONBUTTON_CANCEL
    
    eACTIONBUTTON_DEFAULT
    
    eACTIONBUTTON_YES
    
    eACTIONBUTTON_NO
    
    eACTIONBUTTON_RETRY
    
    eACTIONBUTTON_STOP
    
    eACTIONBUTTON_HELP
    
    eACTIONBUTTON_YESTOALL
    
    eACTIONBUTTON_NOTOALL
    
    eACTIONBUTTON_OPEN
    """

    def __init__(self: MSPyMstnPlatform.ActionButtonValue, value: int) -> None:
        ...
    
    eACTIONBUTTON_APPLY: ActionButtonValue
    
    eACTIONBUTTON_CANCEL: ActionButtonValue
    
    eACTIONBUTTON_DEFAULT: ActionButtonValue
    
    eACTIONBUTTON_HELP: ActionButtonValue
    
    eACTIONBUTTON_NO: ActionButtonValue
    
    eACTIONBUTTON_NOTOALL: ActionButtonValue
    
    eACTIONBUTTON_OK: ActionButtonValue
    
    eACTIONBUTTON_OPEN: ActionButtonValue
    
    eACTIONBUTTON_RESET: ActionButtonValue
    
    eACTIONBUTTON_RETRY: ActionButtonValue
    
    eACTIONBUTTON_STOP: ActionButtonValue
    
    eACTIONBUTTON_YES: ActionButtonValue
    
    eACTIONBUTTON_YESTOALL: ActionButtonValue
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.ActionButtonValue) -> int:
        ...
    
class ActiveModel:
    """
    None
    """

    @staticmethod
    def Is3d() -> bool:
        ...
    
    @staticmethod
    def IsReadonly() -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Angle3dConstraint:
    """
    None
    """

    class AngleSettings:
        """
        Members:
        
        eNO_INVERTED_AXIS
        
        eINVERTED_AXIS
        """
    
        def __init__(self: MSPyMstnPlatform.Angle3dConstraint.AngleSettings, value: int) -> None:
            ...
        
        eINVERTED_AXIS: AngleSettings
        
        eNO_INVERTED_AXIS: AngleSettings
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.Angle3dConstraint.AngleSettings) -> int:
            ...
        
    @staticmethod
    def Create(geometryIds: MSPyMstnPlatform.GeometryIdPtrArray, axis: MSPyBentleyGeom.DRay3d, flags: int, value: float, variableAccess: MSPyBentley.WString, settings: int) -> MSPyMstnPlatform.Constraint3dBase:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_SurfaceOrientation
        
        eFlagMask_GroupLock
        
        eFlagMask_HalfSpace1
        
        eFlagMask_HalfSpace2
        """
    
        def __init__(self: MSPyMstnPlatform.Constraint3dBase.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_GroupLock: FlagMasks
        
        eFlagMask_HalfSpace1: FlagMasks
        
        eFlagMask_HalfSpace2: FlagMasks
        
        eFlagMask_SurfaceOrientation: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.Constraint3dBase.FlagMasks) -> int:
            ...
        
    @property
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    @Flags.setter
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: int) -> None:
        ...
    
    def GetElementRefs(*args, **kwargs):
        """
        GetElementRefs(self: MSPyMstnPlatform.Constraint3dBase, elemRefs: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >) -> None
        """
        ...
    
    def GetFlags(self: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    
    def GetGroupLock(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def GetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.Constraint3dBase, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    
    def GetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    
    def GetType(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    @property
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    @GroupLock.setter
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: bool) -> None:
        ...
    
    @property
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace1.setter
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    @property
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace2.setter
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def HasBoundVariable(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def HasElementRef(self: MSPyMstnPlatform.Constraint3dBase, elemRef: MSPyDgnPlatform.ElementRefBase) -> bool:
        ...
    
    def IsRedundant(self: MSPyMstnPlatform.Constraint3dBase, other: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def SetFlags(self: MSPyMstnPlatform.Constraint3dBase, flags: int) -> None:
        ...
    
    def SetGeometryIds(self: MSPyMstnPlatform.Constraint3dBase, geometryIds: MSPyMstnPlatform.GeometryIdPtrArray) -> None:
        ...
    
    def SetGroupLock(self: MSPyMstnPlatform.Constraint3dBase, groupLock: bool) -> None:
        ...
    
    def SetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.Constraint3dBase, status: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    def SetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase, orientation: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    @property
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    @SurfaceOrientation.setter
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eDCM3_D_BETWEEN_FIXED: Status
    
    eDCM3_D_BETWEEN_SET_MEMBERS: Status
    
    eDCM3_D_NOT_CHANGED: Status
    
    eDCM3_D_NOT_CONSISTENT: Status
    
    eDCM3_D_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_D_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_D_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_D_NOT_SOLVED: Status
    
    eDCM3_D_OVER_DEFINED: Status
    
    eDCM3_D_SOLVED: Status
    
    eDCM3_D_UNKNOWN: Status
    
    eFlagMask_GroupLock: FlagMasks
    
    eFlagMask_HalfSpace1: FlagMasks
    
    eFlagMask_HalfSpace2: FlagMasks
    
    eFlagMask_SurfaceOrientation: FlagMasks
    
    eINVERTED_AXIS: AngleSettings
    
    eNO_INVERTED_AXIS: AngleSettings
    
    eRedundant: Status
    
class Assoc:
    """
    None
    """

    @staticmethod
    def CreateArc(assoc: MSPyDgnPlatform.AssocPoint, angle: float, keyPoint: int, path: MSPyDgnPlatform.DisplayPath, elemId: int) -> int:
        """
        @Description Creates an association that represents a point on an arc
        or ellipse element.
        
        @Param[out] assoc If a valid association is created, the association
        information is returned in assoc. @Param[in] angle the angle (in
        radians) from the primary axis of the arc or ellipse to the
        association point. This argument is used only when the value of
        *keyPoint* is
        
        ```
        ASSOC_ARC_ANGLE
        ```
        
        @Param[in] keyPoint determines the type of association that is
        created.
        
        @Param[in] path display path for the element.
        @Param[in] elemId used if path is NULL...i.e. creating assoc to
        element that has not been added to the file yet. No verification on
        the association can be done in this case.
        
        @Return SUCCESS (zero) if it
        is able to create a valid association. Otherwise, it returns a non-
        zero value.
        
        See also:
        Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateBCurve(assoc: MSPyDgnPlatform.AssocPoint, u: float, path: MSPyDgnPlatform.DisplayPath, elemId: int) -> int:
        """
        @Description Creates an association that represents a point along a
        B-spline curve.
        
        @Param[out] assoc If a valid association is created, the association
        information is returned in assoc. @Param[in] u the parameter along the
        B-spline curve representing the associative point. @Param[in] path
        display path for the element. @Param[in] elemId used if path is
        NULL...i.e. creating assoc to element that has @Return SUCCESS (zero)
        if it is able to create a valid association. Otherwise, it returns a
        non-zero value.
        
        See also:
        Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateIntersection(assoc: MSPyDgnPlatform.AssocPoint, index: int, seg1: int, seg2: int, nSeg1: int, nSeg2: int, path1: MSPyDgnPlatform.DisplayPath, path2: MSPyDgnPlatform.DisplayPath, elemId1: int, elemId2: int) -> int:
        """
        @Description Create an intersection association between the two
        elements identified by the elemId1 and elemId2 parameters.
        
        @Param[out] assoc is the intersection association created by the
        operation. @Param[in] index is the index of the intersection between
        the two elements where the association will be created. The number of
        intersections between two elements can be found via the
        Intersect.AllBetweenElms function. @Param[in] seg1 is the index of
        the segment of element 1 where the intersection occurs. @Param[in]
        seg2 is the index of the segment of element 2 where the intersection
        occurs. @Param[in] nSeg1 the number of vertices of element 1. This
        parameter is optional, you can pass zero. If non-zero this value is
        used to avoid the association jumping as vertices are
        inserted/deleted. @Param[in] nSeg2 the number of vertices of element
        2. This parameter is optional, you can pass zero. If non-zero this
        value is used to avoid the association jumping as vertices are
        inserted/deleted. @Param[in] path1 display path for the element1.
        @Param[in] path2 display path for the element2. @Param[in] elemId1
        used if path1 is NULL...i.e. creating assoc to element that has not
        been added to the file yet. No verification on the association can be
        done in this case. @Param[in] elemId2 used if path2 is NULL...i.e.
        creating assoc to element that has not been added to the file yet. No
        verification on the association can be done in this case. @Return
        returns SUCCESS if the operation is successful
        
        See also:
        Assoc.GetPoint .CreateIntersection
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateKeypoint(assoc: MSPyDgnPlatform.AssocPoint, vertex: int, nVertex: int, numerator: int, divisor: int, path: MSPyDgnPlatform.DisplayPath, elemId: int) -> int:
        """
        @Description Creates an association that represents a point on a
        linear element.
        
        @Param[out] assoc If a valid association is created, the association
        information is returned in assoc. Linear elements are lines, line
        strings and shapes. @Param[in] vertex the index of the vertex directly
        preceding the association point. @Param[in] nVertex the total number
        of vertices of the linear element. This parameter is optional, you can
        pass zero. If non-zero this value is used to avoid the association
        jumping as vertices are inserted/deleted. @Param[in] numerator the
        distance from vertex number vertex in units of divisor as described
        below. Its range must be between 0 and 32767. @Param[in] divisor the
        number of units (segments) to be considered between the points at
        vertex and vertex+1. The values of numerator and divisor are used
        together as the fraction of the distance between the points at vertex
        and vertex+1, where the association point will be located. The
        denominator must be between 1 and 32767. @Param[in] path display path
        for the element. @Param[in] elemId used if path is NULL...i.e.
        creating assoc to element that has not been added to the file yet. No
        verification on the association can be done in this case. @Return
        returns SUCCESS (zero) if it is able to create a valid association.
        Otherwise, it returns a non-zero value.
        
        See also:
        Assoc.CreateLinear Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateLinear(assoc: MSPyDgnPlatform.AssocPoint, inPoint: MSPyBentleyGeom.DPoint3d, vertex: int, nVertex: int, lineNo: int, path: MSPyDgnPlatform.DisplayPath, elemId: int) -> int:
        """
        @Description Creates an association that represents a point on a
        linear element. This function is similar to Assoc.CreateKeypoint
        but has the advantage that it creates associations to multi-line
        elements as well as other linear elements. Also, this function does
        not require the numerator and divisor parameters as does
        Assoc.CreateKeypoint. Instead, this function automatically
        calculates the keypoint numerator and divisor based on inPoint and the
        specified segment of the linear element.
        
        @Param[out] assoc If a valid association is created, the association
        information is returned in assoc. @Param[in] inPoint is the location
        on the specified linear element that is converted to an associative
        point. @Param[in] vertex is the index of the vertex directly preceding
        the associative point. @Param[in] nVertex the total number of vertices
        of the linear element. This parameter is optional, you can pass zero.
        If non-zero this value is used to avoid the association jumping as
        vertices are inserted/deleted. @Param[in] lineNo is a line number used
        for multi-lines only. @Param[in] path display path for the element.
        @Param[in] elemId used if path is NULL...i.e. creating assoc to
        element that has not been added to the file yet. No verification on
        the association can be done in this case. @Return SUCCESS if a valid
        linear association is created. Otherwise an non-zero error status is
        returned.
        
        See also:
        Assoc.CreateKeypoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateMline(assoc: MSPyDgnPlatform.AssocPoint, vertex: int, nVertex: int, lineNo: int, offset: float, joint: int, path: MSPyDgnPlatform.DisplayPath, elemId: int) -> int:
        """
        @Description Creates an association that represents a point on a
        multi-line element.
        
        @Param[out] assoc If a valid association is created, the association
        information is returned in assoc. @Param[in] vertex the index of the
        vertex directly preceding or at the association point. @Param[in]
        nVertex the total number of vertices of the linear element. This
        parameter is optional, you can pass zero. If non-zero this value is
        used to avoid the association jumping as vertices are
        inserted/deleted. @Param[in] lineNo indicates which line in the multi-
        line is the association's object. This value is an index into the
        multi-line profile information that was copied into the multi-line
        from the tcb when the multi-line was created. @Param[in] offset the
        distance from the specified vertex to the association point, measured
        along the work line and divided by the work line length. The
        information needed to calculate this parameter can be obtained using
        the Vec.... functions. offset is not used if joint is set to true.
        @Param[in] joint If joint is true, the association point is at the
        intersection of the line specified by lineNo and the joint vector is
        at vertex. In other words, the association point will always be on the
        joint. @Param[in] path display path for the element. @Param[in] elemId
        used if path is NULL...i.e. creating assoc to element that has @Return
        SUCCESS (zero) if it is able to create a valid association. Otherwise,
        it returns a non-zero value.
        
        See also:
        Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateOrigin(assoc: MSPyDgnPlatform.AssocPoint, option: int, path: MSPyDgnPlatform.DisplayPath, elemId: int) -> int:
        """
        @Description Creates an association that represents the origin of the
        base element. Origin associations can currently be created for cell
        headers, shared cells, text nodes and text elements. For elements
        other than these, an associative point representing the lower left-
        hand corner of the range block for the element is created.
        
        @Param[out] assoc If a valid association is created, the association
        information is returned in assoc. @Param[in] option Origin of
        association options. @Param[in] path display path for the element.
        @Param[in] elemId used if path is NULL...i.e. creating assoc to
        element that has @Return SUCCESS (zero) if it is able to create a
        valid association. Otherwise, it returns a non-zero value.
        
        See also:
        Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def ExtractPoint(assoc: MSPyDgnPlatform.AssocPoint, elem: MSPyDgnPlatform.MSElement, pointNum: int, maxPoints: int) -> int:
        """
        @Description Extracts the association information from the specified
        point on the given element
        
        @Param[out] assoc Association information @Param[in] elemP element to
        extract point from @Param[in] pointNum index of point to extract
        @Param[in] maxPoints max assoc pts on element @Return SUCCESS if the
        information is found, ERROR if an error occurs
        
        See also:
        Assoc.InsertPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetCurrent(assoc: MSPyDgnPlatform.AssocPoint, point: MSPyBentleyGeom.DPoint3d, option: int, createMask: int) -> bool:
        """
        @Description Gets the current associative point.
        
        @Param[out] assoc the current association point @Param[out] pointP
        location of current association @Param[in] option Option (pass zero)
        @Param[in] createMask element categories not to create associations
        for, use ASSOC_CREATE_MASK_ defines or pass 0 to not restrict allowed
        associations. For example to create an associative dimension you would
        want to check that dimension associations are enabled so you would
        pass ASSOC_CREATE_MASK_DIMENSION. @Return true if associative point
        returned
        
        See also:
        Assoc.ExtractPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElement(outElem: MSPyDgnPlatform.MSElement, tagValue: int, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        @Description Attempts to locate the element with the unique ID elemID
        in the model specified by modelRef.
        
        @Param[out] outElmP If found, the element is returned in element If
        NULL is passed for element or filePos, the corresponding data is not
        returned. @Param[out] filePosP If found, the element's file position
        is returned in filePos. @Param[in] tagValue the tag (unique ID number)
        of the element that is the association's object (or root). @Param[in]
        modelRef indicates the model that the element is in. @Return SUCCESS
        (zero) if the requested element is located. If the function is unable
        to locate the element, it returns a non-zero value.
        
        See also:
        $Remark:
        """
        ...
    
    @staticmethod
    def GetElementDescr(tagValue: int, modelRef: MSPyDgnPlatform.DgnModelRef, expandShared: bool) -> tuple:
        """
        @Description Search for the element with the unique ID specified by
        elemID and, if found, return an element descriptor that contains the
        element and any child elements it might have if it is a complex
        element.
        
        @Param[out] outElDPP Return element descr or NULL @Param[out] filePosP
        Return file position or NULL @Param[in] tagValue Tag value to search
        for @Param[in] modelRef source of tagged element @Param[in]
        expandShared expand shared cells @Return SUCCESS if the element is
        found and an element descriptor was successfully created.
        MDLERR_BADFILENUMBER is returned if modelRef is not valid. May return
        ERROR if the element descriptor could not be created.
        
        See also:
        Element.GetID
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetPoint(outPoint: MSPyBentleyGeom.DPoint3d, assocPoint: MSPyDgnPlatform.AssocPoint, modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Uses the information in assocPoint to create a 3D data
        point that is returned in outPoint. An Assoc.Create... function
        must create the information in assocPoint.
        
        @Param[out] outPoint the point created by the function. @Param[in]
        assoc association information used to create the point. @Param[in]
        modelRef the model that contains the element and the association.
        @Return SUCCESS (zero) if a valid point is created in dPoint. If the
        information in assocPoint is invalid, the function returns a non-zero
        value.
        
        See also:
        Assoc.CreateArc Assoc.CreateIntersection
        Assoc.CreateKeypoint Assoc.CreateMline
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetPointFromElement(outPoint: MSPyBentleyGeom.DPoint3d, elem: MSPyDgnPlatform.MSElement, pointNum: int, maxPoints: int, modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Uses the element and point number to create a 3D data
        point that is returned in outPoint. An Assoc.Create... function
        must create the information in assocPoint.
        
        @Param[out] outPoint the point created by the function. @Param[in]
        elemP element to get the point from. @Param[in] pointNum point number
        to get. @Param[in] maxPoints total number of points on element.
        @Param[in] modelRef the model that contains the element and the
        association. @Return SUCCESS (zero) if a valid point is created in
        dPoint. If the information in assocPoint is invalid, the function
        returns a non-zero value.
        
        See also:
        Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetRoot(assocPoint: MSPyDgnPlatform.AssocPoint, modelRef: MSPyDgnPlatform.DgnModelRef, rootIndex: int) -> tuple:
        ...
    
    @staticmethod
    def InsertPoint(elem: MSPyDgnPlatform.MSElement, assocPoint: MSPyDgnPlatform.AssocPoint, pointNum: int, maxPoints: int) -> int:
        """
        @Description Insert an association point to the specified element.
        
        @Param[in] elemP element to add association information to @Param[in]
        assocPointP Association information @Param[in] pointNum index of point
        to insert @Param[in] maxPoints max assoc pts on element @Return
        SUCCESS if the information is found, ERROR if an error occurs
        
        See also:
        Assoc.ExtractPoint
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def RemovePoint(elem: MSPyDgnPlatform.MSElement, pointNum: int, maxPoints: int) -> int:
        """
        @Description Removes from element. An Assoc.Create... function must
        create the information in assocPoint.
        
        @Param[in] elemP element to remove assoc point from. @Param[in]
        pointNum point number to remove. @Param[in] maxPoints total number of
        points on element. @Return SUCCESS (zero) if point was associative and
        was removed. If the information is invalid, the function returns a
        non-zero value.
        
        See also:
        Assoc.GetPoint
        
        Remark:
        """
        ...
    
    @staticmethod
    def ResolveAssociations(elem: MSPyDgnPlatform.MSElement, modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Removes all association points from an element.
        
        @Param[in] elemP element to remove assoc point from. @Param[in]
        modelRef the model that contains the element and the association.
        @Return SUCCESS (zero) if associative points removed. If the
        information is invalid, the function returns a non-zero value.
        
        See also:
        Assoc.GetPoint @Remarks For an ATTRIBUTE_ELM element (tag
        element) that is associated with a base element, this computes the
        distance from the tag to the base element and adds that distance
        to the origin of the tag. Then it breaks the association between
        the tag and the base element. @Remarks For all element types, the
        final step is to remove all association point dependency linkages.
        
        Remark:
        """
        ...
    
    @staticmethod
    def StripTag(elem: MSPyDgnPlatform.MSElement) -> int:
        """
        @Description Remove an association tag from a single element
        
        @Param[in] elemP element to strip tag from @Return SUCCESS if the
        operation is complete successfully, ERROR otherwise
        
        See also:
        Assoc.StripTags
        
        Remark:
        """
        ...
    
    @staticmethod
    def TagElementDescr(elDescr: MSPyDgnPlatform.MSElementDescr, mnodelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        @Description Get the tag value from an element at the specified offset
        within the specified element descriptor. If the specified element does
        not have a tag, then it is assigned a tag and the new tag value is
        returned in the newTagP argument. This function will return an error
        if the element descriptor has the complex bit set.
        
        @Param[out] newTagP is the new tag created by the function.
        @Param[in,out] elDscrP is the element descriptor to which the tag is
        added. @Param[in] modelRef indicates the model containing the element
        receiving the tag. @Return SUCCESS if the operation is completed
        successfully, otherwise ERROR
        
        See also:
        Assoc.TagElementValue
        
        Remark:
        """
        ...
    
    @staticmethod
    def TagElementValue(elem: MSPyDgnPlatform.MSElement, modelRef: MSPyDgnPlatform.DgnModelRef, tag: int) -> tuple:
        """
        @Description Assign a new tag value to the specified element if it
        doesn't already have one.
        
        @Param[out] tagValue is the tag value assigned to the element.
        @Param[in] elemP is the element that receives the tag. @Param[in]
        modelRef inidcates the model containing the element. @Param[in] inTag
        is the input tag value, or zero. @Return SUCCESS if the operation
        completed successfully, otherwise ERROR.
        
        See also:
        Assoc.TagElementDescr
        
        Remark:
        """
        ...
    
    @staticmethod
    def VertexAddedOrRemoved(elem: MSPyDgnPlatform.MSElement, pointNum: int, maxPoints: int, inserted: bool) -> int:
        """
        @Description Adjust association point indices for the specified
        element.
        
        @Param[in] elemP element to add association information to @Param[in]
        pointNum index of point added/removed @Param[in] maxPoints max assoc
        pts on element @Param[in] inserted pass true is vertex has been added;
        false if it's been removed @Return SUCCESS if the information is
        found, ERROR if an error occurs
        
        See also:
        Assoc.ExtractPoint
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class AssociativeExtractSettings:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.AssociativeExtractSettings) -> None
        
        2. __init__(self: MSPyMstnPlatform.AssociativeExtractSettings, dgnModel: MSPyDgnPlatform.DgnModel) -> None
        """
        ...
    
    @property
    def deleteWithParent(arg0: MSPyMstnPlatform.AssociativeExtractSettings) -> bool:
        ...
    @deleteWithParent.setter
    def deleteWithParent(arg0: MSPyMstnPlatform.AssociativeExtractSettings, arg1: bool) -> None:
        ...
    
    @property
    def keepAssociative(arg0: MSPyMstnPlatform.AssociativeExtractSettings) -> bool:
        ...
    @keepAssociative.setter
    def keepAssociative(arg0: MSPyMstnPlatform.AssociativeExtractSettings, arg1: bool) -> None:
        ...
    
    @property
    def moveElement(arg0: MSPyMstnPlatform.AssociativeExtractSettings) -> bool:
        ...
    @moveElement.setter
    def moveElement(arg0: MSPyMstnPlatform.AssociativeExtractSettings, arg1: bool) -> None:
        ...
    
    @property
    def offset(self: MSPyMstnPlatform.AssociativeExtractSettings) -> float:
        ...
    @offset.setter
    def offset(self: MSPyMstnPlatform.AssociativeExtractSettings, arg0: float) -> None:
        ...
    
    @property
    def type(self: MSPyMstnPlatform.AssociativeExtractSettings) -> int:
        ...
    @type.setter
    def type(self: MSPyMstnPlatform.AssociativeExtractSettings, arg0: int) -> None:
        ...
    
class AssociativeExtractSymbologySettings:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> None
        
        2. __init__(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings, dgnModel: MSPyDgnPlatform.DgnModel) -> None
        """
        ...
    
    @property
    def circularProfile(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting) -> bool:
        ...
    @circularProfile.setter
    def circularProfile(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting, arg1: bool) -> None:
        ...
    
    @property
    def classOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> bool:
        ...
    @classOverride.setter
    def classOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg1: bool) -> None:
        ...
    
    @property
    def color(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> int:
        ...
    @color.setter
    def color(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg0: int) -> None:
        ...
    
    @property
    def colorOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> bool:
        ...
    @colorOverride.setter
    def colorOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg1: bool) -> None:
        ...
    
    @property
    def doEditmode(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting) -> bool:
        ...
    @doEditmode.setter
    def doEditmode(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting, arg1: bool) -> None:
        ...
    
    @property
    def doInsideDiameter(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting) -> bool:
        ...
    @doInsideDiameter.setter
    def doInsideDiameter(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting, arg1: bool) -> None:
        ...
    
    @property
    def doOutsideDiameter(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting) -> bool:
        ...
    @doOutsideDiameter.setter
    def doOutsideDiameter(arg0: MSPyMstnPlatform.ExtrudeAlongProfileSetting, arg1: bool) -> None:
        ...
    
    @property
    def elementclass(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> bool:
        ...
    @elementclass.setter
    def elementclass(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg1: bool) -> None:
        ...
    
    @property
    def level(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> int:
        ...
    @level.setter
    def level(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg0: int) -> None:
        ...
    
    @property
    def levelOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> bool:
        ...
    @levelOverride.setter
    def levelOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg1: bool) -> None:
        ...
    
    @property
    def style(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> int:
        ...
    @style.setter
    def style(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg0: int) -> None:
        ...
    
    @property
    def styleOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> bool:
        ...
    @styleOverride.setter
    def styleOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg1: bool) -> None:
        ...
    
    @property
    def weight(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> int:
        ...
    @weight.setter
    def weight(self: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg0: int) -> None:
        ...
    
    @property
    def weightOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings) -> bool:
        ...
    @weightOverride.setter
    def weightOverride(arg0: MSPyMstnPlatform.AssociativeExtractSymbologySettings, arg1: bool) -> None:
        ...
    
class BRepVertexGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class BitMask:
    """
    None
    """

    @staticmethod
    def AnyBitSet(bitMask: MSPyDgnPlatform.BitMask) -> bool:
        """
        @Description Check if specified bit-mask has any bit set to true
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Returns:
        true if any bit is set
        
        Remark:
        """
        ...
    
    @staticmethod
    def Clone(bitMask: MSPyDgnPlatform.BitMask) -> MSPyDgnPlatform.BitMask:
        """
        @Description Clone the specified BitMask.
        
        Parameter ``pBitMask``:
        IN the BitMask to copy
        
        Returns:
        a deep copy of the BitMask or NULL if there was an error
        
        Remark:
        """
        ...
    
    @staticmethod
    def Create(arg0: bool) -> tuple:
        """
        defaultBitValue
        """
        ...
    
    @staticmethod
    def CreateFromBitArray(bitArray: MSPyBentley.UInt16Array, defaultBitValue: bool) -> tuple:
        """
        @Description Create a new bit-mask structure - initializes itself from
        input bit-array. Note:This function copies the input bit-array.
        
        Parameter ``ppBitMaskOut``:
        OUT new bit-mask structure
        
        Parameter ``numValidBitsIn``:
        IN number of bits that are valid in pBitArrayIn
        
        Parameter ``pBitArrayIn``:
        IN bit array as an array of short-words
        
        Parameter ``defaultBitValueIn``:
        IN the default value for bits in the mask.
        
        Returns:
        ERROR if the bit-mask structure cannot be created
        
        Remark:
        """
        ...
    
    @staticmethod
    def Dump(fileName: str, bitMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Dump specified bit-mask data into specified file
        
        Parameter ``pFileNameIn``:
        IN file name to dump into
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Returns:
        SUCCESS
        
        Remark:
        """
        ...
    
    @staticmethod
    def EnsureCapacity(bitMask: MSPyDgnPlatform.BitMask, numBit: int) -> int:
        """
        @Description Ensure that if the specified bit-mask can carry the
        specified number of bits. This function will only expand the specified
        the bit-mask to specified number of bits (conversely, will never
        contract the specified bit-mask)
        
        Parameter ``pBitMaskIn``:
        IN bit-mask
        
        Parameter ``numBitIn``:
        IN number of bits to ensure
        
        Returns:
        ERROR if the bit-mask structure cannot be expanded.
        
        Remark:
        """
        ...
    
    @staticmethod
    def Equal(bitMask1: MSPyDgnPlatform.BitMask, bitMask2: MSPyDgnPlatform.BitMask) -> bool:
        """
        @Description Check if two specified bit-masks are equal
        
        Parameter ``pBitMask1In``:
        IN first bit mask
        
        Parameter ``pBitMask2In``:
        IN second bit mask
        
        Returns:
        true if the bit-masks are equal, false if not
        
        Remark:
        """
        ...
    
    @staticmethod
    def Free(bitMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Free specified bit-mask & all its internal memory
        
        Parameter ``ppBitMaskIn``:
        IN bit-mask structure to free
        
        Returns:
        ERROR if the bit-mask structure cannot be freed
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetAsString(stringOut: MSPyBentley.WString, bitMask: MSPyDgnPlatform.BitMask, indexOrigin: int) -> int:
        """
        @Description Get a string which represents the bit-mask. The string
        will a ", " delimited set of bit indices which are set to ON. Ranges of
        ON bit-indices will be returned in a range form (such as n1-n2). An
        example return string:1,10-15,20,31-35
        
        Parameter ``pStringOut``:
        OUT pre-allocated string in which the bit-mask will be outputted
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``indexOriginIn``:
        IN index corresponding to lowest order bit (1 or 0)
        
        Returns:
        ERROR if the bits from specified string cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetBit(bitMask: MSPyDgnPlatform.BitMask, bitIndex: int) -> tuple:
        """
        @Description Get value at specified bit-position in bit-mask.
        
        Parameter ``pBitFlagOut``:
        OUT bit flag, true then bit is on, else false
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``bitIndexIn``:
        IN bit index to get
        
        Returns:
        ERROR if the bit-position is outside the size of bit-mask
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDefaultBitValue(bitMask: MSPyDgnPlatform.BitMask) -> bool:
        """
        @Description Get the default value for bits beyond the allocated
        number of bits in the bit mask.
        
        Parameter ``pBitMaskIn``:
        IN bit-mask for which to get defaultBitValue
        
        Returns:
        the default bit value for pBitMaskIn
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetHighestBit(bitMask: MSPyDgnPlatform.BitMask) -> tuple:
        """
        @Description Get the position of the highest possible bit in specified
        bit-mask that can be set without expanding the bit-mask
        
        Parameter ``pHighestPositionOut``:
        OUT highest bit position possible without requiring an expansion
        
        Parameter ``pBitMaskIn``:
        IN bit-mask array
        
        Returns:
        ERROR if the highest bit cannot be got
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetNumBitsSet(bitMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Get the number of bits set to 1 in the bit mask.
        
        Parameter ``pBitMaskIn``:
        IN bit-mask for which to get number valid bits
        
        Returns:
        The number of bits set
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetNumValidBits(bitMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Get the number of valid bits in the bit mask.
        
        Parameter ``pBitMaskIn``:
        IN bit-mask for which to get number valid bits
        
        Returns:
        the number of valid bits.
        
        Remark:
        """
        ...
    
    @staticmethod
    def InvertAll(bitMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Invert value of all bits in specified bit-mask
        
        Parameter ``pBitMaskIn``:
        IN bit-mask array
        
        Returns:
        ERROR if the bits cannot be inverted
        
        Remark:
        """
        ...
    
    @staticmethod
    def InvertBit(bitMask: MSPyDgnPlatform.BitMask, bitIndex: int) -> int:
        """
        @Description Invert value of specified bit in specified bit-mask
        
        Parameter ``pBitMaskIn``:
        IN bit-mask array
        
        Parameter ``bitIndexIn``:
        IN bit index to invert
        
        Returns:
        ERROR if the specified bit cannot be inverted
        
        Remark:
        """
        ...
    
    @staticmethod
    def LogicalOperation(bitMaskOut: MSPyDgnPlatform.BitMask, bitMaskIn: MSPyDgnPlatform.BitMask, operation: MSPyDgnPlatform.BitMaskOperation) -> int:
        """
        @Description Apply " pBitMask " on " pBitMaskOut " using specified logical
        operation. The logical operation may be BitMaskOperation.And,
        BitMaskOperation.Or, BitMaskOperation.Xor, BitMaskOperation.OrNot,
        BitMaskOperation.AndNot.
        
        Parameter ``pBitMaskOut``:
        OUT destination bit-mask array and first operand
        
        Parameter ``pBitMaskIn``:
        IN second operand
        
        Parameter ``operation``:
        IN operation code (see above)
        
        Returns:
        ERROR if the bits from specified string cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetAll(bitMask: MSPyDgnPlatform.BitMask, bitFlag: bool) -> int:
        """
        @Description Set all bits in specified bit-mask to either true or
        false
        
        Parameter ``pBitMaskIn``:
        IN bit-mask array
        
        Parameter ``bitFlagIn``:
        IN bit flag, if false then set all bits off, else set all bits ON
        
        Returns:
        ERROR if the bits cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetBit(bitMask: MSPyDgnPlatform.BitMask, bitIndex: int, bitFlag: bool) -> int:
        """
        @Description Set value at specified bit-position in bit-mask. If the
        specified bit-position is outside the size of the bit-mask, then this
        function will expand the size of the input bit-mask to fit in the bit-
        position.
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``bitIndexIn``:
        IN bit index to set
        
        Parameter ``bitFlagIn``:
        IN bit flag, if true then bit as on, else as off
        
        Returns:
        ERROR if the bit at specified position cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetBitAtPositions(bitMask: MSPyDgnPlatform.BitMask, arrayPosition: int, bitPosition: int, bitFlag: bool) -> int:
        """
        @Description Set bit at specified array-position (bitIndexIn / 16) &
        bit-position in array (bitIndexIn % 16)
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``arrayPositionIn``:
        IN internal array position of bit index
        
        Parameter ``bitPositionIn``:
        IN internal bit position of bit index
        
        Parameter ``bitFlagIn``:
        IN bit value to set
        
        Returns:
        ERROR if the bit at specified position cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetBits(bitMask: MSPyDgnPlatform.BitMask, bitIndexArray: MSPyBentley.UInt32Array, bitFlag: bool) -> int:
        """
        @Description Set the value of an array of specified bit-positions in
        bit-mask. If any of the specified bit-positions are outside the size
        of the bit-mask, then this function will expand the size of the input
        bit-mask to fit-in for the maximum possible bit-position.
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``numBitInArray``:
        IN number of bits in array
        
        Parameter ``pBitIndexArrayIn``:
        IN bit index array
        
        Parameter ``bitFlagIn``:
        IN bit flag, if true then bit as on, else as off
        
        Returns:
        ERROR if the bits at specified positions cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDefaultBitValue(bitMask: MSPyDgnPlatform.BitMask, defaultBitValue: bool) -> int:
        """
        @Description Set the default value for bits beyond the allocated
        number of bits in the bit mask.
        
        Parameter ``pBitMaskIn``:
        IN bit-mask for which to set defaultBitValue
        
        Parameter ``defaultBitValueIn``:
        IN the default value for bits in the mask.
        
        Returns:
        ERROR if pBitMaskIn is NULL
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetFromBitArray(bitMask: MSPyDgnPlatform.BitMask, bitArray: MSPyBentley.UInt16Array) -> int:
        """
        @Description Set bit-mask from specified bit-array. The resultant bit-
        mask will be of the same size as the specified bit-array.
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``numValidBitsIn``:
        IN number of bits that are valid in pBitArrayIn
        
        Parameter ``pBitArrayIn``:
        IN bit array as an array of short-words
        
        Returns:
        ERROR if the bit from bit-array cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetFromBitMask(bitMask: MSPyDgnPlatform.BitMask, sourceBitMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Set bit-mask from specified source bit-mask. The
        resultant bit-mask will be of the same size as the specified source
        bit-mask. The default value of the resultant bit-mask will be set to
        be the same as that of the source bit-mask.
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``pSourceBitMaskIn``:
        IN source bit mask array
        
        Returns:
        ERROR if the bits from specified bit-mask cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetFromString(bitMask: MSPyDgnPlatform.BitMask, sourceString: str, indexOrigin: int, maxIndex: int) -> int:
        """
        @Description Set bit-mask from specified string. Set bit-mask from a
        set of " " or ", " delimited in a string. The string may contain ranges
        too. e.g. string:1,10-15,3,20,25-28,31-35 If the largest bit-position
        implied in the specified string is larger than the bit-mask size, then
        the bit-mask will expand to fit-in the largest bit-position.
        " maxIndexIn " is used if you have/want a bitmask of a predetermined
        size & do not want its size to exceed the specified value.
        " maxIndexIn " can be set to -1, in which case the argument is ignored.
        
        Parameter ``pBitMaskOut``:
        OUT bit mask array
        
        Parameter ``pSourceStringIn``:
        IN source string from which to parse the bit-mask information
        
        Parameter ``indexOriginIn``:
        IN index corresponding to lowest order bit (1 or 0)
        
        Parameter ``maxIndexIn``:
        IN maximum index to set
        
        Returns:
        ERROR if the bits from specified string cannot be set
        
        Remark:
        """
        ...
    
    @staticmethod
    def TestBit(bitMask: MSPyDgnPlatform.BitMask, bitPosition: int) -> bool:
        """
        @Description Check if specified bit of bit-mask is set to true
        
        Parameter ``pBitMaskIn``:
        IN bit mask array
        
        Parameter ``bitPositionIn``:
        IN bit position to test
        
        Returns:
        true if the bit at specified position is ON (true), false if not
        
        Remark:
        """
        ...
    
    @staticmethod
    def TestBitMask(bitMask1: MSPyDgnPlatform.BitMask, bitMask2: MSPyDgnPlatform.BitMask) -> bool:
        """
        @Description Check if two specified bit-masks have any bits which have
        the same value
        
        Parameter ``pBitMask1In``:
        IN first bit mask
        
        Parameter ``pBitMask2In``:
        IN second bit mask
        
        Returns:
        true if the bit-masks have any bit in common
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class CadInputType:
    """
    Members:
    
    eCadInputTypeNone
    
    eCadInputTypeCommand
    
    eCadInputTypeReset
    
    eCadInputTypeDataPoint
    
    eCadInputTypeKeyin
    
    eCadInputTypeAny
    """

    def __init__(self: MSPyMstnPlatform.CadInputType, value: int) -> None:
        ...
    
    eCadInputTypeAny: CadInputType
    
    eCadInputTypeCommand: CadInputType
    
    eCadInputTypeDataPoint: CadInputType
    
    eCadInputTypeKeyin: CadInputType
    
    eCadInputTypeNone: CadInputType
    
    eCadInputTypeReset: CadInputType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.CadInputType) -> int:
        ...
    
class Cell:
    """
    None
    """

    @staticmethod
    def AddLibDescr(cellEdP: MSPyDgnPlatform.MSElementDescr, cellType: MSPyMstnPlatform.CellAddType, convertNestedCellsToRefs: bool) -> int:
        """
        @Description Create a new cell in the currently attached cell library.
        This function also handles copying styles, dependencies, etc. into the
        library. @Param[in] cellEdP a cell element descriptor (type 2) to add
        to the library. @Param[in] cellType the type of the cell in the
        library. Use CellAddType.FromContext to choose GRAPHIC or POINT based
        on the type of the cell. Otherwise, possible values for cellType are
        CellAddType.NormalCell for a normal graphic cell or
        CellAddType.PointCell for a point cell. @Param[in]
        convertNestedCellsToRefs if true, a nested cell with the same name as
        a cell (model) in the destination library will be replaced by a
        reference to that cell, which matches the behavior of the MicroStation
        cell creation tool. When deciding whether to replace, only the cell
        names are compared, not the geometry. Pre-V8 behavior of this function
        was to set this to false. Cell.CreateFromFence calls this function
        with convertNestedCellsToRefs set to true. @Return SUCCESS if the cell
        is added to the library, or an error otherwise. mdlErrno is set to the
        value that indicates the error cause. Possible values include
        MDLERR_INVALIDLIBRARY, MDLERR_NOCELLLIBRARY and MDLERR_FILEREADONLY.
        @Remarks If a cell with the same name already exists in the library,
        it will be replaced.
        
        See also:
        Cell.Create Cell.CreateFromFence
        
        Remark:
        """
        ...
    
    @staticmethod
    def AttachLibrary(fileName: MSPyBentley.BeFileName, inputName: MSPyBentley.BeFileName, defaultDir: str, fromKeyin: int) -> int:
        """
        @Description Attaches a new cell library to the current design file.
        If a library is successfully attached, filename is set to the cell
        library's full file specification. If the library is a V7 cell library
        then this function will fail. It is the equivalent of calling
        Cell.AttachLibraryEx with LIBRARY_IgnoreV7Libraries. @Param[out]
        filename name of cell library opened. This should be a string buffer
        at least MAXFILELENGTH characters long. @Param[in] inputname is the
        name of the cell library. inputName may contain a path specification.
        However, if it does not, then MS_CELL and defaultDir (if defined) are
        searched for the file. If this parameter is NULL, then the active
        library is detached. @Param[in] defaultDir additional path to search.
        Can be NULL. @Param[in] fromkeyin if true, the path information from
        inputName is used. If it is false, Cell.AttachLibrary assumes that
        inputName came from the information stored in the design file header
        (where the path information is not always correct), and it only uses
        the path information from inputName if the library cannot be found
        anywhere else. MDL applications should normally set fromKeyin to true.
        @Remarks To detach a cell library, pass a NULL string for inputName.
        @Return SUCCESS if a cell library is attached. If it cannot find the
        cell library, it returns a non-zero value.
        
        See also:
        Cell.AttachLibraryEx
        
        Remark:
        """
        ...
    
    @staticmethod
    def AttachLibraryEx(fileName: MSPyBentley.BeFileName, inputName: MSPyBentley.BeFileName, defaultDir: str, fromKeyin: int, libraryFlag: int) -> int:
        """
        @Description Attach a new cell library to the current design file. If
        a library is successfully attached, filename is set to the cell
        library's full file specification. @Param[out] filename name of cell
        library opened. This should be a string buffer at least MAXFILELENGTH
        characters long. @Param[in] inputname is the name of the cell library.
        inputName may contain a path specification. However, if it does not,
        then MS_CELL and defaultDir (if defined) are searched for the file. If
        this parameter is NULL, then the active library is detached.
        @Param[in] defaultDir additional path to search. Can be NULL.
        @Param[in] fromkeyin if true, the path information from inputName is
        used. If it is false, Cell.AttachLibraryEx assumes that inputName
        came from the information stored in the design file header (where the
        path information is not always correct), and it only uses the path
        information from inputName if the library cannot be found anywhere
        else. MDL applications should normally set fromKeyin to true.
        @Param[in] libraryFlag specifies how to handle the cell library if its
        format is not up to date. If the cell library is a V7 cell library,
        then it can be upgraded. See for the possible values. @Return SUCCESS
        if the operation is completed and a cell library was attached,
        otherwise an error value.
        
        See also:
        Cell.AttachLibrary
        
        Remark:
        """
        ...
    
    @staticmethod
    def CopyCellDefinition(destLibrary: MSPyDgnPlatform.DgnFile, cellName: str, sourceLibrary: MSPyDgnPlatform.DgnFile) -> int:
        """
        @Description Duplicate a cell definition from one cell library to
        another.
        
        Remark:
        s This function always try to convert nested cells to references
        (see Cell.AddLibDescr). @Param[in] destLibrary the cell library
        to copy the cell to. @Param[in] cellName the name of the cell to
        copy. @Param[in] sourceLibrary the cell library to copy the cell
        from. @Return SUCCESS if the cell is copied, otherwise an error
        code.
        
        Remark:
        
        
        @See Cell.GetLibraryObject
        """
        ...
    
    @staticmethod
    def Create(cellElm: MSPyDgnPlatform.MSElement, cellName: str, origin: MSPyBentleyGeom.DPoint3d, pointCell: bool) -> int:
        """
        @Description Creates a new cell element based on the data provided.
        This can be used as an orphan cell, or later added to a cell library
        using Cell.AddLibDescr. Typically this function is used to create a
        cell header, and Elmdscr.AppendDscr is then used to add elements.
        @Param[out] cellElm This is a pointer to a full MSElement union which
        is filled in. @Param[in] cellName the name of the cell; may be NULL.
        @Param[in] origin the origin of the cell. If NULL is passed for
        cellOrigin, the (0, 0, 0) point for the current coordinate system is
        used. @Param[in] pointCell true if the cell is to be a point cell,
        otherwise false. @Return SUCCESS if the operation is completed
        successfully, otherwise ERROR
        
        See also:
        Cell.AddLibDescr Cell.CreateFromFence
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateFromFence(cellName: str, description: str, origin: MSPyBentleyGeom.DPoint3d, pointCell: bool) -> int:
        """
        @Description Create a new cell in the current cell library that
        contains the elements in the fence. It creates the new cell from the
        current selection set if no fence is defined. @Param[in] cellName the
        name of the cell in the library. This must be less than
        DgnPlatform.MAX_CELLNAME_LENGTH characters, and must be valid as
        tested by Model.NameIsValid. @Param[in] descr is the cell
        description; it may not exceed MAX_CELLDSCR_LENGTH characters.
        @Param[in] rOrigin the origin of the cell. If NULL is passed for
        cellOrigin, tcb->celor is used. @Param[in] pointCell true if the cell
        is to be a point cell, otherwise false. @Remarks This function
        collects up all the elements in the fence or selection set and creates
        a cell element out of them. @Return SUCCESS or the error that occurred
        which prevented the cell creation. mdlErrno is also set to the error
        value. Possible values include MDLERR_INVALIDLIBRARY,
        MDLERR_NOCELLLIBRARY and MDLERR_FILEREADONLY.
        
        See also:
        Cell.Create Cell.AddLibDescr
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateFromFenceByType(cellName: str, description: str, origin: MSPyBentleyGeom.DPoint3d, cellType: int) -> int:
        """
        @Description Create a new cell in the current cell library that
        contains the elements in the fence. It creates the new cell from the
        current selection set if no fence is defined. @Param[in] cellName the
        name of the cell in the library. This must be less than
        DgnPlatform.MAX_CELLNAME_LENGTH characters, and must be valid as
        tested by Model.NameIsValid. @Param[in] descr is the cell
        description; it may not exceed MAX_CELLDSCR_LENGTH characters.
        @Param[in] rOrigin the origin of the cell. If NULL is passed for
        cellOrigin, tcb->celor is used. @Param[in] cellType the type of cell
        to create (point, graphic, parametric) @Remarks This function collects
        up all the elements in the fence or selection set and creates a cell
        element out of them. @Return SUCCESS or the error that occurred which
        prevented the cell creation. mdlErrno is also set to the error value.
        Possible values include MDLERR_INVALIDLIBRARY, MDLERR_NOCELLLIBRARY
        and MDLERR_FILEREADONLY.
        
        See also:
        Cell.Create Cell.AddLibDescr
        
        Remark:
        """
        ...
    
    @staticmethod
    def DeleteInLibrary(cellName: str) -> int:
        """
        @Description Remove a cell from the current active cell library by
        name. @Param[in] cellName name of cell to be deleted. @Return SUCCESS
        if the specified cell was deleted or one of the following error
        values:MDLERR_CELLNOTFOUND, MDLERR_CELLEXISTS, MDLERR_INVALIDLIBRARY,
        MDLERR_NOCELLLIBRARY or MDLERR_FILEREADONLY.
        
        Remark:
        """
        ...
    
    @staticmethod
    def ExistsInLibrary(cellName: str) -> bool:
        """
        @Description Indicates whether a cell with the specified name exists
        in the current cell library. @Param[in] cellName name of the cell to
        search for. @Return true if the cell name exists in the library;
        otherwise it returns false.
        
        See also:
        Cell.PlaceCell Cell.GetElmDscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def Extract(origin: MSPyBentleyGeom.DPoint3d, shape: MSPyBentleyGeom.DPoint3d, rMatrix: MSPyBentleyGeom.RotMatrix, scale: MSPyBentleyGeom.DPoint3d, cellName: MSPyBentley.WString, cell: MSPyDgnPlatform.MSElement) -> int:
        """
        @Description Extracts the information from a cell header element. If
        any parameters are NULL, this function does not attempt to fill them
        in. All parameters are returned in the current (design file)
        coordinate system. @Param[out] origin is the cell origin. @Param[out]
        shape returns an array of eight Dpoint3d's which represent the minimum
        bounding box for the cell in the coordinate system of the cell. This
        idea can be illustrated by using MicroStation's element selection tool
        to select a cell. MicroStation places handles on the boundary which
        defines the cell, and these handles correlate to the eight Dpoint3ds
        returned by Cell.Extract. Note that this must point to an array
        large enough to hold the 8 points. @Param[out] rMatrix the rotation
        matrix for the cell. @Param[out] scale the cell's X, Y and Z scale
        factors. @Param[out] cellName the cell's name in Unicode. @Param[in]
        bufferSize if extracting cell's name, number of widechars name buffer
        can hold. This is ignored if cellName is NULL. @Param[in] cell cell
        element to extract information from. @Remarks The points in shape are
        transformed into the current coordinate system before they are
        returned. They do not necessarily represent a minimum bounding box in
        the current coordinate system. @Return SUCCESS if cell is a valid
        MicroStation element of type CELL_HEADER_ELM. Otherwise, it returns
        MDLERR_BADELEMENT.
        
        See also:
        Cell.Create
        
        Remark:
        """
        ...
    
    @staticmethod
    def ExtractDescription(cellDescr: MSPyBentley.WString, elem: MSPyDgnPlatform.MSElement) -> int:
        """
        @Description Retrieve the description from a cell element and copy it
        to the provided buffer. Note that graphic cells and shared cell
        instances as placed by MicroStation do not keep their descriptions.
        For shared cells, you should use this function on the definition. For
        graphic cells, you must find the cell in a library and extract its
        description that way. @Param[in] cellDescrP the buffer where the
        extracted cell description will be placed. @Param[in] bufferSize the
        maximum number of MSWChars to copy to the cellDescrP buffer.
        @Param[in] elmP is the cell element from which the description is
        extracted. @Return SUCCESS if the operation is completed successfully,
        otherwise ERROR
        
        See also:
        Cell.SetDescription Cell.ExtractName
        
        Remark:
        """
        ...
    
    @staticmethod
    def ExtractName(cellName: MSPyBentley.WString, elem: MSPyDgnPlatform.MSElement) -> int:
        """
        @Description Retrieve the name string from a non-shared or shared cell
        element and copy it to the provided buffer. @Param[out] cellNameP the
        buffer where the extracted cell name will be placed. @Param[in]
        bufferSize the maximum number of MSWChars to copy to cellNameP.
        @Param[in] elmP the cell element from which the name is extracted.
        @Return SUCCESS if the cell name is successfully found and copied to
        the buffer, otherwise ERROR.
        
        See also:
        Cell.SetName Cell.ExtractDescription
        
        Remark:
        """
        ...
    
    @staticmethod
    def FindCell(preferredLib: MSPyDgnPlatform.DgnFile, cellName: str, searchAll: int) -> tuple:
        """
        @Description Search for a cell with the specified cell name. The
        search order is first the library passed in as preferredLib; then the
        current active cell library; and then sequentially though the files
        listed in MS_CELLLIST and MS_BLOCKLIST if the searchAll parameter is
        true. The first cell found with the requested name will stop the
        search. @Remarks This function will only find cells which have export
        rights or better. Because of the rights limitation, protected
        libraries will be skipped and cells will be searched for through th
        rest of the path. To specify rights, see Cell.FindCellEx.
        @Param[out] library is the library where the cell was found, if the
        search was successful. This argument will be NULL if the cell was not
        found. @Param[in] preferredLib the cell library to search first, or
        NULL. @Param[in] cellName the name of the cell to search for.
        @Param[in] searchAll indicates whether all of the cell libraries in
        the MS_CELLLIST and MS_BLOCKLIST paths are to be searched. Setting
        this value to 0 indicates that only the preferredLib library is
        searched; setting this value to 1 indicates that all cell libraries
        are to be searched; setting this value to 2 indicates that all cell
        libraries are to be searched and messages generated as the search
        progresses. Messages are sent to the error display field in the
        MicroStation window. @Return SUCCESS if the cell was found, otherwise
        MDLERR_CELLNOTFOUND.
        
        Remark:
        """
        ...
    
    @staticmethod
    def FindCellEx(preferredLib: MSPyDgnPlatform.DgnFile, cellName: str, searchAll: int, rights: int) -> tuple:
        """
        @Description Search for a cell with the specified cell name. The
        search order is first the library passed in as preferredLib; then the
        current active cell library; and then sequentially though the files
        listed in MS_CELLLIST and MS_BLOCKLIST if the searchAll parameter is
        true. The first cell found with the requested name will stop the
        search. This function differs from Cell.FindCell by the rights
        parameter which allows the caller to specify the desired permission
        level. @Param[out] library is the library where the cell was found, if
        the search was successful. This argument will be NULL if the cell was
        not found. @Param[in] preferredLib the cell library to search first,
        or NULL. @Param[in] cellName the name of the cell to search for.
        @Param[in] searchAll indicates whether all of the cell libraries in
        the MS_CELLLIST and MS_BLOCKLIST paths are to be searched. Setting
        this value to 0 indicates that only the preferredLib library is
        searched; setting this value to 1 indicates that all cell libraries
        are to be searched; setting this value to 2 indicates that all cell
        libraries are to be searched and messages generated as the search
        progresses. Messages are sent to the error display field in the
        MicroStation window. @Param[in] rights The level of rights that should
        be tested. See DgnFileObj.CheckRights for a description of the
        choices. @Return SUCCESS if the cell was found, otherwise
        MDLERR_CELLNOTFOUND.
        
        Remark:
        """
        ...
    
    @staticmethod
    def FixLevels(elemDescr: MSPyDgnPlatform.MSElementDescr, relativeMode: int, baseLevel: int, library: MSPyDgnPlatform.DgnFile) -> int:
        """
        @Description This function is just a direct call to
        Cell.FixLevelsByCode, so that function should be called instead. It
        will adjust element levels in a cell element descriptor, elemDscr.
        This adjustment is based on the cell type and the values of
        relativeMode and baseLevel. It uses the following logic:
        
        ```
        if (cell is a point cell)
        {
        set all levels to baseLevel
        }
        else if (relativeMode is true)
        {
        adjust so the lowest level used in cell is baseLevel
        }
        ```
        
        If relative mode is chosen, the all element level ids are adjusted by
        the difference between the lowest level id in the cell and the base
        level id provided.
        
        @Param[in] elemDscr cell element descriptor @Param[in] relativeMode
        true for relative level. @Param[in] baseLevel used for point cells and
        relative mode. @Param[in] library This is no longer used and can be
        NULL. Instead the model ref from elemDscr->h.dgnModelRef is used.
        @Remarks This function is needed because Cell.GetElmDscr does not
        apply the above logic before it returns the cell's element descriptor.
        This functionality was left out of Cell.GetElmDscr so that you
        could get the original level values. @Return SUCCESS if the levels
        could be fixed.
        
        See also:
        Cell.GetElmDscr Cell.FixLevelsByCode
        
        Remark:
        """
        ...
    
    @staticmethod
    def FixLevelsByCode(elemDescr: MSPyDgnPlatform.MSElementDescr, modelRef: MSPyDgnPlatform.DgnModelRef, relativeMode: int, baseLevel: int) -> int:
        """
        @Description Adjust element levels in a cell element descriptor,
        elemDscr. This adjustment is based on the cell type and the values of
        relativeMode and baseLevelId. It uses the following logic:
        
        ```
        if (cell is a point cell)
        {
        set all levels to baseLevel
        }
        else if (relativeMode is true)
        {
        adjust so the lowest level used in cell is baseLevel
        }
        ```
        
        If relative mode is chosen, the baseLevelId is converted to a level
        code and all element level codes are adjusted by the difference
        between the base level code and lowest level code in the cell.
        
        @Param[in] elemDscr cell element descriptor @Param[in] pModelRef model
        ref of element descriptor @Param[in] relativeMode relative or absolute
        @Param[in] baseLevelId used for point cells and relative mode. This is
        a level number, not a level code. @Remarks This function is needed
        because Cell.GetElmDscr does not apply the above logic before it
        returns the cell's element descriptor. This functionality was left out
        of Cell.GetElmDscr so that you could get the original level values.
        @Return SUCCESS if the level codes could be adjusted.
        
        See also:
        Cell.GetElmDscr Cell.FixLevels
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElmDscr(origin: MSPyBentleyGeom.DPoint3d, scale: MSPyBentleyGeom.DPoint3d, trueScale: bool, rotMatrix: MSPyBentleyGeom.RotMatrix, attributes: int, ggroup: int, sharedFlag: int, updateMasterFile: bool, cellName: str, library: MSPyDgnPlatform.DgnFile) -> tuple:
        """
        @Description Read the specified cell from the cell library and returns
        the cell's element descriptor. The address of the element descriptor
        for the cell's graphic elements is returned in cellDscrPP. @Remarks If
        empty text nodes are in a cell, MicroStation removes them before it
        places the cell. These empty text nodes are placed immediately after
        the cell. For this reason, Cell.GetElmDscr also extracts the empty
        text node elements and returns them in a separate element descriptor,
        txtNodeDscrPP. Applications should treat these empty text nodes
        similarly. If txtNodeDscrPP is NULL, then empty text nodes will be
        lost. @Remarks If sharedFlag is 1 or 2 and the user has turned shared
        cells on, the function first searches the active file for a shared
        cell instance without reading the cell library. If no shared cell is
        found, then the library is searched. @Param[out] cellDscrPP cell
        element descriptor @Param[out] txtNodeDscrPP element descriptor for
        empty text nodes. If NULL, these text nodes are lost. @Param[in]
        rOrigin the location of the cell's origin. If origin is NULL, the cell
        is transformed to the (0, 0, 0) point in the current coordinate
        system. @Param[in] scale points to a Dpoint3d structure holding the X,
        Y and (in 3D) Z scale factors to be applied to the cell's elements. If
        scale is NULL, the cell is not scaled. @Param[in] trueScale indicates
        whether the cell definition and DGN file units are used in scaling the
        cell, resulting in cells that have the same size between models with
        different units. ACTIVEMODEL is assumed for the destination.
        @Param[in] rotMatrix is the rotation matrix that defines the cell's
        orientation. If rMatrix is NULL, the identity matrix is used.
        @Param[in] attributes an array of attribute information to append to
        the cell header. This parameter has been deprecated; please see the
        mdlLinkage functions to append attributes to the cell header.
        @Param[in] ggroup is the graphic group number for the cell's elements.
        A value of 0 means that the elements will not be part of a graphic
        group. @Param[in] sharedFlag indicates whether the element descriptor
        is for a shared or unshared cell. If sharedFlag is 0, an unshared cell
        is returned. If sharedFlag is 1, a shared cell is returned if found,
        otherwise an unshared cell. If sharedFlag is 2, the state of the user-
        specified shared flag is used. @Param[in] updateMasterFile indicates
        that the cell is to be placed in the active model ref, so all
        necessary styles, etc. should be copied to the active file. If this
        parameter is set to false, then the display of the cell elements may
        not match the original model. @Param[in] cellName the name of the cell
        to be returned. @Param[in] library the library object containing the
        cell. If this argument is NULL, the cell is searched for. It is
        usually acquired via Cell.FindCell or Cell.GetLibraryObject.
        @Return SUCCESS if the cell is read and cellDscrPP is valid.
        Otherwise, it returns an error status.
        
        See also:
        Cell.PlaceCell Cell.GetElmDscrExtended
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElmDscrExtended(origin: MSPyBentleyGeom.DPoint3d, scale: MSPyBentleyGeom.DPoint3d, trueScale: bool, destModelRef: MSPyDgnPlatform.DgnModelRef, rotMatrix: MSPyBentleyGeom.RotMatrix, attributes: int, ggroup: int, sharedFlag: int, keepCellDimensionality: bool, updateDestFile: bool, cellName: str, library: MSPyDgnPlatform.DgnFile) -> tuple:
        ...
    
    @staticmethod
    def GetLibraryName(fileName: MSPyBentley.BeFileName) -> None:
        ...
    
    @staticmethod
    def GetLibraryObject(libName: str, unused: bool) -> tuple:
        """
        @Description Returns a pointer to the cell library object of the given
        name. This is used by Cell.GetElmDscr, Cell.PlaceCell, and other
        functions that require a cell library handle. @Param[out] ppLibraryObj
        pointer to the cell library object. @Param[in] pLibName name of the
        cell library to find. @Param[in] unused Unused; pass false. @Return
        SUCCESS if the library of the given name is found, otherwise ERROR.
        
        See also:
        Cell.PlaceCell Cell.GetElmDscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsPointCell(hdr: MSPyDgnPlatform.MSElement) -> bool:
        """
        @Description Determine whether the cell cellHeader is a point cell.
        @Param[in] hdr cell header element @Return true if cellHeader is a
        point cell, false for any other type.
        
        Remark:
        """
        ...
    
    @staticmethod
    def ModifyInfo(newName: str, newDescr: str, cellName: str, library: MSPyDgnPlatform.DgnFile) -> int:
        """
        @Description Replace the name and description of a cell in a library.
        @Param[in] newName is the new cell name. Pass NULL to use the old
        name. @Param[in] newdescr is the new cell description. Pass NULL to
        use the old description. @Param[in] cellName is the name of the cell
        to modify. @Param[in] library is the pointer to the cell library to
        use. @Return SUCCESS if the operation is completed successfully,
        otherwise ERROR. @Remarks Cell names are case-insensitive, so this
        function will not work to change only the case of a name. If the cell
        name contains invalid characters, this operation will fail. See
        Model.NameIsValid to test for validity. Cell names are limited to
        DgnPlatform.MAX_CELLNAME_LENGTH wchars.
        
        Remark:
        
        
        @See Cell.ReadLibraryElements mdlCell_getElmDscr
        Cell.ReplaceLibraryHeaderElement
        """
        ...
    
    @staticmethod
    def PlaceCell(origin: MSPyBentleyGeom.DPoint3d, scale: MSPyBentleyGeom.DPoint3d, trueScale: bool, rotMatrix: MSPyBentleyGeom.RotMatrix, attributes: int, ggroup: int, relativeMode: bool, baseLevel: int, sharedFlag: int, cellName: str, library: MSPyDgnPlatform.DgnFile) -> int:
        """
        @Description Place a cell in the active model of the current design
        file.
        
        Remark:
        s If library is NULL, Cell.PlaceCell scans the current cell
        library for the cell using cellName, and if not found then scans
        libraries in the MS_CELLLIST path.
        
        Remark:
        s If sharedFlag is 1 and a shared cell definition for cellName
        exists in the design file, a new shared cell instance is placed
        without the cell library being read, and library is ignored. If
        the sharedFlag is 1 and no shared cell definition exists, the cell
        will be read from the library and both the shared cell definition
        and instance will be created.
        
        Remark:
        s If the active model's Annotation Scale lock is ON, the active
        annotation scale is propagated to the cell. The cell model (from
        cell library) needs to have the " Can be placed as annotation cell "
        toggle ON in order to be placed as an annotation cell. If that
        toggle is OFF, the active annotation scale is propagated only to
        the annotations contained in that cell model. @Param[in] rOrigin
        the location to place the cell origin. If origin is NULL, the cell
        is placed at the (0, 0, 0) point in the current coordinate system.
        @Param[in] scale points to a Dpoint3d structure holding the X, Y,
        and (in 3D) Z scale factors to be applied to the cell elements
        before they are placed. If scale is NULL, the cell is placed at a
        scale factor of 1.0. @Param[in] trueScale if true, use cell model
        and master model units to scale the cell. @Param[in] rotMatrix the
        rotation matrix that defines the orientation for cell placement.
        If rMatrix is NULL, the identity matrix is used. rMatrix does not
        necessarily need to be orthogonal or normalized. (Cells can be
        placed skewed). @Param[in] attributes is an array of attribute
        information to append to the cell header before it is placed. The
        first short of this array is the length, in shorts, of the
        attribute data. Note that attribute linkage lengths must be a
        multiple of four words. If attributes is NULL, the cell has no
        attributes attached to the header. @Param[in] ggroup the graphic
        group number for the cell's elements. A value of 0 means that the
        elements will not be part of a graphic group. @Param[in]
        relativeMode determines how the levels for the cell's elements are
        assigned. All elements for a point cell are assigned to baseLevel.
        If relativeMode is true, the lowest level used in the cell
        definition is assigned to baseLevel and all other element levels
        are adjusted accordingly. If relativeMode is false, the levels are
        taken from the cell library unchanged. @Param[in] baseLevel
        determines how the levels for the cell's elements are assigned.
        All elements for a point cell are assigned to baseLevel. For a
        graphic cell, this is ignored if relativeMode is false. This is a
        level ID, gotten through functions such as Level.GetIdFromName.
        Relative placement internally works by level numbers. @Param[in]
        sharedFlag indicates whether the cell should be placed as shared
        or unshared. If sharedFlag is 0, an unshared cell is placed. If
        sharedFlag is 1, a shared cell is created. If sharedFlag is 2, the
        state of the user-specified shared flag is used. Cell.PlaceCell
        also creates and places the shared cell definition if it does not
        exist in the file. @Param[in] cellName is the name of the cell to
        be placed. @Param[in] library name of library or NULL. If the
        library is NULL, the cell will be searched for in the active cell
        library, then all files found on MS_CELLLIST. If the shared flag
        is 1, then the active file will be searched for a shared cell
        definition first. @Remarks The rotation matrix, rotMatrix, is
        applied before the scale factors. @Return the file position of a
        newly placed cell. If an error occurs, it returns 0 and sets
        mdlErrno to the specific error cause.
        
        See also:
        Cell.GetElmDscr
        
        Remark:
        """
        ...
    
    @staticmethod
    def ReadLibraryElements(celName: str, library: MSPyDgnPlatform.DgnFile, justHeader: bool) -> tuple:
        """
        @Description Get the component elements of the specified cell from the
        cell library. Calling this function with justHeader false is the same
        as calling Cell.GetElmDscr with no transformations. @Param[out]
        cellElementsPP is an element descriptor containing the elements of the
        cell. @Param[in] cellName the name of the cell to find and read.
        @Param[in] library the cell library to read the cell from, or NULL to
        search. @Param[in] justHeader if set true, only the cell header is
        read and returned. @Return SUCCESS if the operation is completed
        successfully, otherwise ERROR.
        
        Remark:
        """
        ...
    
    @staticmethod
    def Rename(newName: str, oldName: str) -> int:
        """
        @Description Changes the name of cell in the current cell library.
        @Param[in] newName is the new name of the cell in the library. This
        must be less than DgnPlatform.MAX_CELLNAME_LENGTH characters, and
        must be valid as tested by Model.NameIsValid. @Param[in] oldName
        old name for cell in library @Return SUCCESS if the specified cell was
        renamed. If an error occurs, they return one the following values:
        MDLERR_CELLNOTFOUND, MDLERR_CELLEXISTS, MDLERR_INVALIDLIBRARY,
        MDLERR_NOCELLLIBRARY or MDLERR_FILEREADONLY.
        
        Remark:
        """
        ...
    
    @staticmethod
    def ReplaceLibraryHeaderElement(library: MSPyDgnPlatform.DgnFile, cellEdP: MSPyDgnPlatform.MSElementDescr, cellType: MSPyMstnPlatform.CellAddType) -> int:
        """
        @Description Replace the data for a cell header in a library. Since
        this will replace all linkages on the element except name and
        description, care must be taken to avoid removing linkages that should
        remain. Typically Cell.ReadLibraryElements is used to get the cell
        header so that the original linkages are in place. @Param[in] library
        is the pointer to the cell library to use. @Param[in] cellEdP is the
        new cell element to use to replace the header. @Param[in] cellType is
        the cell type; see Cell.AddLibDescr for a description of types.
        @Return SUCCESS if the operation is completed successfully, otherwise
        ERROR.
        
        Remark:
        
        
        @See Cell.ReadLibraryElements Cell.GetElmDscr Cell.ModifyInfo
        """
        ...
    
    @staticmethod
    def SetDescription(elem: MSPyDgnPlatform.MSElement, cellDescr: str) -> int:
        """
        @Description Set the description of the specified cell element. When
        setting the description of a cell using an element descriptor you need
        to be careful about changing the length of the cell description as the
        element descriptor has only been allocated to be large enough for the
        current description length. The proper way to change the cell
        descriptor is:
        
        ```
        MSElement   element;
        memcpy (&element, &cellDP->el, Element.Size (&cellDP->el));
        Cell.SetDescription (&element, L" NEW DESCRIPTION ");
        Elmdscr.ReplaceElement (&cellDP, &element);
        ```
        
        @Param[in] elmP the cell element on which the description will be set.
        @Param[in] cellDescrP the description to give the cell. @Return
        SUCCESS if the operation is completed successfully, otherwise ERROR.
        
        See also:
        Cell.ExtractDescription Cell.SetName
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetName(elem: MSPyDgnPlatform.MSElement, cellName: str) -> int:
        """
        @Description Set the name of the specified cell. When setting the name
        of a cell using an element descriptor you need to be careful about
        changing the length of the cell name as the element descriptor has
        only been allocated to be large enough for the current name length.
        The proper way to change the cell descriptor is:<BR>
        
        ```
        MSElement   element;
        memcpy (&element, &cellDP->el, Element.Size (&cellDP->el));
        Cell.SetName (&element, L" NEW NAME ");
        Elmdscr.ReplaceElement (&cellDP, &element);
        ```
        
        @Param[in] elmP the cell element on which the name will be set.
        @Param[in] cellNameP the name to give to the cell. @Return SUCCESS if
        the operation is completed successfully, otherwise ERROR .
        
        See also:
        Cell.ExtractName Cell.SetDescription
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetOriginAndRange(cellDP: MSPyDgnPlatform.MSElementDescr) -> None:
        """
        @Description Set the cell's range, range diagonal, and origin. The
        origin is set to the middle of the range. This function only validates
        the range of the cell against the ACTIVEMODEL. If you are working with
        a different modelRef, you must use Elmdscr.Validate and
        Cell.SetRange. @Param[in] cellDP the cell's element descriptor.
        
        See also:
        Cell.SetRange
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetRange(cellDP: MSPyDgnPlatform.MSElementDescr, modelRef: MSPyDgnPlatform.DgnModelRef) -> None:
        """
        @Description The Cell.Create and Cell.SetRange functions are
        generally used to create library cells in memory for subsequent
        addition to a cell library using Cell.AddLibDescr. The programmer
        typically creates a cell element, creates a new element descriptor,
        adds the component elements to that element descriptor, calls
        Cell.SetRange, and then adds the cell to the library using
        Cell.AddLibDescr. @Param[in,out] cellDP the element descriptor of
        the cell. @Param[in] modelRef indicates the model to validate the cell
        range against. ACTIVEMODEL is typically used. @Remarks The
        Cell.SetRange function must be called to update the range block
        diagonal in the header of a cell library element descriptor. The range
        block diagonal is the range of the un-rotated cell, so this function
        must be called after the cell definition is complete (immediately
        before Cell.AddLibDescr is called). The cell range is used when
        creating cell handles.
        
        See also:
        Cell.AddLibDescr Cell.SetOriginAndRange
        
        Remark:
        """
        ...
    
    @staticmethod
    def UpgradeLibrary(*args, **kwargs):
        """
        UpgradeLibrary(libraryFileName: MSPyBentley.WString, backupFileName: str, haveUnits: bool, uorPerStorage: float, unitNumerator: float, unitDenominator: float, unitLabel: str, unitFlags: MSPyDgnPlatform.UnitFlags, libraryFlag: int, feedbackFunc: std.function<void __cdecl(wchar_t const * __ptr64,int)>) -> int
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class CellAddType:
    """
    Members:
    
    eFronContext
    
    eNormalCell
    
    ePointCell
    """

    def __init__(self: MSPyMstnPlatform.CellAddType, value: int) -> None:
        ...
    
    eFronContext: CellAddType
    
    eNormalCell: CellAddType
    
    ePointCell: CellAddType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.CellAddType) -> int:
        ...
    
class ChamferEdgeSettings:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.ChamferEdgeSettings) -> None
        
        2. __init__(self: MSPyMstnPlatform.ChamferEdgeSettings, dgnModel: MSPyDgnPlatform.DgnModel) -> None
        """
        ...
    
    @property
    def angle(self: MSPyMstnPlatform.ChamferEdgeSettings) -> float:
        ...
    @angle.setter
    def angle(self: MSPyMstnPlatform.ChamferEdgeSettings, arg0: float) -> None:
        ...
    
    @property
    def distance(self: MSPyMstnPlatform.ChamferEdgeSettings) -> float:
        ...
    @distance.setter
    def distance(self: MSPyMstnPlatform.ChamferEdgeSettings, arg0: float) -> None:
        ...
    
    @property
    def distance2(self: MSPyMstnPlatform.ChamferEdgeSettings) -> float:
        ...
    @distance2.setter
    def distance2(self: MSPyMstnPlatform.ChamferEdgeSettings, arg0: float) -> None:
        ...
    
    @property
    def length(self: MSPyMstnPlatform.ChamferEdgeSettings) -> float:
        ...
    @length.setter
    def length(self: MSPyMstnPlatform.ChamferEdgeSettings, arg0: float) -> None:
        ...
    
    @property
    def maxChamferDistance(self: MSPyMstnPlatform.ChamferEdgeSettings) -> float:
        ...
    @maxChamferDistance.setter
    def maxChamferDistance(self: MSPyMstnPlatform.ChamferEdgeSettings, arg0: float) -> None:
        ...
    
    @property
    def method(arg0: MSPyMstnPlatform.ChamferEdgeSettings) -> int:
        ...
    @method.setter
    def method(arg0: MSPyMstnPlatform.ChamferEdgeSettings, arg1: int) -> None:
        ...
    
    @property
    def propogateToSmoothEdges(arg0: MSPyMstnPlatform.ChamferEdgeSettings) -> bool:
        ...
    @propogateToSmoothEdges.setter
    def propogateToSmoothEdges(arg0: MSPyMstnPlatform.ChamferEdgeSettings, arg1: bool) -> None:
        ...
    
    @property
    def reversed(arg0: MSPyMstnPlatform.ChamferEdgeSettings) -> bool:
        ...
    @reversed.setter
    def reversed(arg0: MSPyMstnPlatform.ChamferEdgeSettings, arg1: bool) -> None:
        ...
    
class ChooseMasterFileStatus:
    """
    Members:
    
    eCHOOSEMASTERFILE_STATUS_Invalid
    
    eCHOOSEMASTERFILE_STATUS_Handled
    
    eCHOOSEMASTERFILE_STATUS_Canceled
    """

    def __init__(self: MSPyMstnPlatform.ChooseMasterFileStatus, value: int) -> None:
        ...
    
    eCHOOSEMASTERFILE_STATUS_Canceled: ChooseMasterFileStatus
    
    eCHOOSEMASTERFILE_STATUS_Handled: ChooseMasterFileStatus
    
    eCHOOSEMASTERFILE_STATUS_Invalid: ChooseMasterFileStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.ChooseMasterFileStatus) -> int:
        ...
    
class ClashCollectStatus:
    """
    Members:
    
    eCLASHCOLLECT_Success
    
    eCLASHCOLLECT_Error
    
    eCLASHCOLLECT_NoGeometry
    """

    def __init__(self: MSPyMstnPlatform.ClashCollectStatus, value: int) -> None:
        ...
    
    eCLASHCOLLECT_Error: ClashCollectStatus
    
    eCLASHCOLLECT_NoGeometry: ClashCollectStatus
    
    eCLASHCOLLECT_Success: ClashCollectStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.ClashCollectStatus) -> int:
        ...
    
class ClashDetector:
    """
    None
    """

    def Clear(self: MSPyMstnPlatform.ClashDetector) -> None:
        ...
    
    def CollectGeometry(*args, **kwargs):
        """
        Overloaded function.
        
        1. CollectGeometry(self: MSPyMstnPlatform.ClashDetector, displayPath: MSPyDgnPlatform.DisplayPath, offset: float = 0) -> tuple
        
        2. CollectGeometry(self: MSPyMstnPlatform.ClashDetector, eh: MSPyDgnPlatform.ElementHandle, offset: float = 0) -> tuple
        """
        ...
    
    def ComputeClosestApproach(self: MSPyMstnPlatform.ClashDetector, object1: MSPyMstnPlatform.IClashData, object2: MSPyMstnPlatform.IClashData, maxClearance: float) -> tuple:
        ...
    
    def ComputeClosestApproachToPosition(self: MSPyMstnPlatform.ClashDetector, object1: MSPyMstnPlatform.IClashData, positionUOR: MSPyBentleyGeom.DPoint3d, maxClearance: float) -> tuple:
        ...
    
    @staticmethod
    def CreateClashDetector(viewport: MSPyDgnPlatform.Viewport) -> MSPyMstnPlatform.ClashDetector:
        ...
    
    @staticmethod
    def NoClearance() -> float:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ClashStatus:
    """
    Members:
    
    eCLASHSTATUS_NotInRange
    
    eCLASHSTATUS_Collision
    
    eCLASHSTATUS_Clearance
    
    eCLASHSTATUS_Error
    """

    def __init__(self: MSPyMstnPlatform.ClashStatus, value: int) -> None:
        ...
    
    eCLASHSTATUS_Clearance: ClashStatus
    
    eCLASHSTATUS_Collision: ClashStatus
    
    eCLASHSTATUS_Error: ClashStatus
    
    eCLASHSTATUS_NotInRange: ClashStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.ClashStatus) -> int:
        ...
    
class Constraint2dData:
    """
    None
    """

    def AddCurveIdentifier(self: MSPyMstnPlatform.Constraint2dData, id: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        """
        @description Add curve identifier
        
        Parameter ``id``:
        The id to be added
        """
        ...
    
    @property
    def ConstraintStatus(arg0: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dStatus:
        ...
    @ConstraintStatus.setter
    def ConstraintStatus(arg0: MSPyMstnPlatform.Constraint2dData, arg1: MSPyMstnPlatform.Constraint2dStatus) -> None:
        ...
    
    @property
    def ConstraintType(arg0: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dType:
        ...
    @ConstraintType.setter
    def ConstraintType(arg0: MSPyMstnPlatform.Constraint2dData, arg1: MSPyMstnPlatform.Constraint2dType) -> None:
        ...
    
    def GetConstraintStatus(self: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dStatus:
        """
        @description Get the constraint status
        
        Returns:
        The constraint status
        """
        ...
    
    def GetConstraintType(self: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dType:
        """
        @description Get the constraint type
        
        Returns:
        The constraint type
        """
        ...
    
    def SetConstraintStatus(self: MSPyMstnPlatform.Constraint2dData, status: MSPyMstnPlatform.Constraint2dStatus) -> None:
        """
        @description Set the constraint status
        
        Parameter ``status``:
        A new constraint status to set
        """
        ...
    
    def SetConstraintType(self: MSPyMstnPlatform.Constraint2dData, type: MSPyMstnPlatform.Constraint2dType) -> None:
        """
        @description Set the constraint type
        
        Parameter ``type``:
        The constraint type
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.Constraint2dData) -> None
        
        2. __init__(self: MSPyMstnPlatform.Constraint2dData, constraintType: MSPyMstnPlatform.Constraint2dType) -> None
        """
        ...
    
class Constraint2dDataArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.Constraint2dDataArray) -> None
        
        2. __init__(self: MSPyMstnPlatform.Constraint2dDataArray, arg0: MSPyMstnPlatform.Constraint2dDataArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyMstnPlatform.Constraint2dDataArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyMstnPlatform.Constraint2dDataArray, x: MSPyMstnPlatform.Constraint2dData) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyMstnPlatform.Constraint2dDataArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyMstnPlatform.Constraint2dDataArray, x: MSPyMstnPlatform.Constraint2dData) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyMstnPlatform.Constraint2dDataArray, L: MSPyMstnPlatform.Constraint2dDataArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyMstnPlatform.Constraint2dDataArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyMstnPlatform.Constraint2dDataArray, i: int, x: MSPyMstnPlatform.Constraint2dData) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyMstnPlatform.Constraint2dDataArray) -> MSPyMstnPlatform.Constraint2dData
        
        Remove and return the last item
        
        2. pop(self: MSPyMstnPlatform.Constraint2dDataArray, i: int) -> MSPyMstnPlatform.Constraint2dData
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyMstnPlatform.Constraint2dDataArray, x: MSPyMstnPlatform.Constraint2dData) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Constraint2dManager:
    """
    None
    """

    @staticmethod
    def AddConstraint(constraintedElements: MSPyDgnPlatform.ElementAgenda, constraintType: MSPyMstnPlatform.Constraint2dType, primitiveId1: int = 0, defaultSubIndex1: int = 0, primitiveId2: int = 0, defaultSubIndex2: int = 0, dimValue: float = 0.0, varName: MSPyBentley.WString = '') -> bool:
        ...
    
    @staticmethod
    def AddSolverData(eh: MSPyDgnPlatform.ElementHandle, solverData: MSPyMstnPlatform.Constraint2dSolverData) -> int:
        """
        @description Store constraints data.
        
        Parameter ``[in]``:
        eh An element handle to specify where to store the data. *eh* can
        be any of the member elements that are constructing the profile.
        
        Parameter ``[in]``:
        solverData A Constraint2dSolverData object holding constraint
        model data to store.
        
        Returns:
        SUCCESS if implemented successfully; otherwise an error code
        indicating the failing reason.
        
        Remark:
        s This method will merge the passed-in *solverData* with the
        previous constraints if any.
        
        See also:
        GetSolverData, Constraint2dSolverData
        
        Remark:
        Required Library:Constraint2dElement.lib
        """
        ...
    
    @staticmethod
    def EvaluateAndUpdate(solverData: MSPyMstnPlatform.Constraint2dSolverData, dgnModel: MSPyDgnPlatform.DgnModel, directChanges: MSPyDgnPlatform.ElementRefPArray, isDynamic: bool = False, results: MSPyDgnPlatform.ElementAgenda = None, inconsistentConstraints: MSPyMstnPlatform.Constraint2dDataArray = None) -> bool:
        ...
    
    @staticmethod
    def GetSolverData(solverData: MSPyMstnPlatform.Constraint2dSolverData, eh: MSPyDgnPlatform.ElementHandle, includingDeleted: bool = False) -> int:
        """
        @description Get constraint data of the specified profile.
        
        Parameter ``[out]``:
        solverData A Constraint2dSolverData object receiving constraint
        model data.
        
        Parameter ``[in]``:
        eh An element handle to specify where to get the data. *eh* can be
        any element of the members constructing the profile.
        
        Parameter ``[in]``:
        includingDeleted A boolean to specify whether to include being-
        deleted elements. If set to **True**, this method will check and
        try to resolve members if they are deleted; otherwise if set to
        **False**(by default) deleted elements will be left unresolved.
        
        Returns:
        SUCCESS if implemented successfully; otherwise an error code
        indicating the failing reason.
        
        See also:
        AddSolverData, Constraint2dSolverData
        
        Remark:
        Required Library:Constraint2dElement.lib
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Constraint2dSolver:
    """
    None
    """

    def Evaluate(*args, **kwargs):
        """
        Evaluate(self: MSPyMstnPlatform.Constraint2dSolver, dragInfos: Bentley.Bstdcxx.bvector<Bentley.DgnPlatform.Constraint2d.Drag2dInfo,Bentley.BentleyAllocator<Bentley.DgnPlatform.Constraint2d.Drag2dInfo> >, isDynamic: bool) -> MSPyDgnPlatform.BentleyStatus
        
        @description Perform a evaluation
        
        Parameter ``[in]``:
        dragInfos An array of dragging information representing direct
        changes.
        
        Parameter ``[in]``:
        isDynamic A boolean indicating whether for " dynamic " purpose.
        
        Returns:
        SUCCESS if implemented successfully; otherwise ERROR if failed.
        """
        ...
    
    def GetData(self: MSPyMstnPlatform.Constraint2dSolver, data: Bentley.DgnPlatform.Constraint2d.Constraint2dSolverData) -> None:
        """
        @description Initialize model
        
        Parameter ``[in]``:
        data The 2d constraint model to evaluate.
        
        Remark:
        s The curvevector in *data* must have CurvePrimitiveIds; scale is
        equal to the solid's scale, i.e., DCube(parasolid)=>Uor. It should
        more than 1.0
        """
        ...
    
    def GetResultCurveVector(self: MSPyMstnPlatform.Constraint2dSolver, elemRef: MSPyDgnPlatform.ElementRefBase) -> tuple:
        """
        @description Get results for the given element
        
        Parameter ``[out]``:
        resultCurve A curve vector reference to receive the result
        
        Parameter ``[in]``:
        elementRef A reference to element to specify what element is to
        query
        """
        ...
    
    def SetData(self: MSPyMstnPlatform.Constraint2dSolver, data: Bentley.DgnPlatform.Constraint2d.Constraint2dSolverData, uorPerMaster: float = 1.0) -> bool:
        """
        @description Initialize model
        
        Parameter ``[in]``:
        data The 2d constraint model to evaluate.
        
        Parameter ``[in]``:
        uorPerMaster A float-point value to specify the UOR unit in master
        unit
        
        Remark:
        s The curvevector must have CurvePrimitiveIds; scale is equal to
        the solid's scale, i.e., DCube(parasolid)=>Uor. It should more
        than 1.0
        """
        ...
    
    def __init__(self: MSPyMstnPlatform.Constraint2dSolver, localToWorldScale: float, isAutoConstraining: bool = False) -> None:
        ...
    
class Constraint2dSolverData:
    """
    None
    """

    def Clear(self: MSPyMstnPlatform.Constraint2dSolverData) -> None:
        """
        @description Clear all data and set to empty
        """
        ...
    
    def CollateByElement(self: MSPyMstnPlatform.Constraint2dSolverData, childGroups: MSPyMstnPlatform.Constraint2dSolverDataArray) -> int:
        """
        @description Check and divide this constraint model into child per
        links among elements.
        
        Parameter ``[out]``:
        childGroups Separate child constraint model whose member elements
        have links with each other.
        
        Returns:
        The number of child constraint models.
        """
        ...
    
    def GetElementRefs(*args, **kwargs):
        """
        GetElementRefs(self: MSPyMstnPlatform.Constraint2dSolverData, elemRefs: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >) -> int
        
        @description Query all member elements.
        
        Parameter ``[out]``:
        elementRefs A set receiving member elements.
        
        Returns:
        The number of member elements.
        """
        ...
    
    def IsComplete(self: MSPyMstnPlatform.Constraint2dSolverData) -> bool:
        """
        @description Determine if it is complete, i.e., its actual topology is
        identical to the datum description used.
        
        Returns:
        True if it is complete; otherwise False.
        """
        ...
    
    def IsCurvePlaneConstrained(self: MSPyMstnPlatform.Constraint2dSolverData, curveId: MSPyMstnPlatform.CurveEntityIdentifier) -> bool:
        """
        A curve plane is constrained if is by a plane distance dimension.
        """
        ...
    
    def IsCurvePlaneFixed(self: MSPyMstnPlatform.Constraint2dSolverData, curveId: MSPyMstnPlatform.CurveEntityIdentifier) -> bool:
        """
        A curve plane is considered to be fixed if any portion of the curve is
        fixed.
        """
        ...
    
    def IsEmpty(self: MSPyMstnPlatform.Constraint2dSolverData) -> bool:
        """
        @description Determine if it is empty.
        
        Returns:
        True if it is empty; otherwise False.
        """
        ...
    
    def IsResolved(self: MSPyMstnPlatform.Constraint2dSolverData) -> bool:
        """
        @description Determine if it is resolved, i.e., all member elements
        are available
        
        Returns:
        True if it is resolved; otherwise False.
        """
        ...
    
    def Merge(self: MSPyMstnPlatform.Constraint2dSolverData, rhs: MSPyMstnPlatform.Constraint2dSolverData) -> bool:
        """
        @description Merge another constraint model into this one. Identital
        data items will be excluded while merging.
        
        Parameter ``[in]``:
        rhs A data instance to merge into.
        
        Returns:
        True if there are some items being merged into; otherwise False if
        nothing being merged.
        """
        ...
    
    def RemoveElementRef(self: MSPyMstnPlatform.Constraint2dSolverData, elemRef: MSPyDgnPlatform.ElementRefBase) -> bool:
        """
        @description Remove all constraint data which are correlated to the
        the given element.
        
        Parameter ``[in]``:
        elementRef Specify an element ref whose constraints will be
        removed
        
        Returns:
        True if any removal occurred; otherwise false.
        """
        ...
    
    def RemoveInvalidConstraints(self: MSPyMstnPlatform.Constraint2dSolverData, elemRef: MSPyDgnPlatform.ElementRefBase) -> int:
        """
        @description Remove all invalid constraint data which are correlated
        to the the given element.
        
        Parameter ``[out]``:
        invalidCount An integer to receive the number of invalid
        constraints
        
        Parameter ``[in]``:
        elementRef Specify an element ref whose constraints will be
        removed
        """
        ...
    
    def RemoveUnresolvedElementRefs(self: MSPyMstnPlatform.Constraint2dSolverData) -> None:
        """
        @description Remove all constraint data whose target elements are not
        resolved.
        """
        ...
    
    def Replace(self: MSPyMstnPlatform.Constraint2dSolverData, oldElemRef: MSPyDgnPlatform.ElementRefBase, newElemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def Reverse(self: MSPyMstnPlatform.Constraint2dSolverData, elemRef: MSPyDgnPlatform.ElementRefBase, curveVector: MSPyBentleyGeom.CurveVector = None) -> bool:
        """
        @description Update constraint data assuming the curve's direction was
        reversed.
        
        Parameter ``[in]``:
        elementRef A element to specify what curve's direction was
        reversed
        
        Parameter ``[in]``:
        curveVector An optional update-to-date curve vector to set
        specific to *elementRef*
        
        Returns:
        True if any change was made, or false if not
        """
        ...
    
    def __init__(self: MSPyMstnPlatform.Constraint2dSolverData) -> None:
        ...
    
class Constraint2dSolverDataArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.Constraint2dSolverDataArray) -> None
        
        2. __init__(self: MSPyMstnPlatform.Constraint2dSolverDataArray, arg0: MSPyMstnPlatform.Constraint2dSolverDataArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyMstnPlatform.Constraint2dSolverDataArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyMstnPlatform.Constraint2dSolverDataArray, x: MSPyMstnPlatform.Constraint2dSolverData) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyMstnPlatform.Constraint2dSolverDataArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyMstnPlatform.Constraint2dSolverDataArray, L: MSPyMstnPlatform.Constraint2dSolverDataArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyMstnPlatform.Constraint2dSolverDataArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyMstnPlatform.Constraint2dSolverDataArray, i: int, x: MSPyMstnPlatform.Constraint2dSolverData) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyMstnPlatform.Constraint2dSolverDataArray) -> MSPyMstnPlatform.Constraint2dSolverData
        
        Remove and return the last item
        
        2. pop(self: MSPyMstnPlatform.Constraint2dSolverDataArray, i: int) -> MSPyMstnPlatform.Constraint2dSolverData
        
        Remove and return the item at index ``i``
        """
        ...
    
class Constraint2dStatus:
    """
    Members:
    
    eUnknown
    
    eBetween_Fixed
    
    eBetween_Set_Members
    
    eOver_Defined
    
    eNon_Algebraic
    
    eNot_Consistent
    
    eNot_Consistent_Dimensions
    
    eNot_Consistent_Other
    
    eNot_Consistent_Unknown
    
    eNot_Solved
    
    eNot_Changed
    
    eSolved
    """

    def __init__(self: MSPyMstnPlatform.Constraint2dStatus, value: int) -> None:
        ...
    
    eBetween_Fixed: Constraint2dStatus
    
    eBetween_Set_Members: Constraint2dStatus
    
    eNon_Algebraic: Constraint2dStatus
    
    eNot_Changed: Constraint2dStatus
    
    eNot_Consistent: Constraint2dStatus
    
    eNot_Consistent_Dimensions: Constraint2dStatus
    
    eNot_Consistent_Other: Constraint2dStatus
    
    eNot_Consistent_Unknown: Constraint2dStatus
    
    eNot_Solved: Constraint2dStatus
    
    eOver_Defined: Constraint2dStatus
    
    eSolved: Constraint2dStatus
    
    eUnknown: Constraint2dStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.Constraint2dStatus) -> int:
        ...
    
class Constraint2dType:
    """
    Members:
    
    eDistance
    
    eAngle
    
    eConcentric
    
    eRadius
    
    eParallel
    
    ePerpendicular
    
    eCoincident
    
    eTangent
    
    eIdentical
    
    eSymmetric
    
    eMajor_Radius
    
    eMinor_Radius
    
    eEqual_Radius
    
    eEqual_Distance
    
    eMidpoint
    
    eDependence
    
    ePatterned
    
    eEqual_Parameter
    
    eNormal
    
    eEqual_Direction
    
    eEqual_Curvature
    
    eEqual_First_Derivative
    
    eEqual_Second_Derivative
    
    eOffset
    
    eSimple_Dependence
    
    eCurve_Length
    
    ePatterned_2d
    
    ePattern_Value
    
    ePattern_2d_value_1
    
    ePattern_2d_value_2
    
    eEqual_Relative_Transform
    
    eArc_length
    
    eOffset_Dimension
    
    eArea
    
    ePerimeter
    
    eFix
    
    eHorizontal
    
    eVertical
    
    eEqual
    
    ePlanar_Distance
    
    eDistanceLL
    
    eDistancePL
    
    eDistancePP
    
    eDistanceCL
    
    eDistanceCP
    
    eDistanceCC
    
    eDummy
    """

    def __init__(self: MSPyMstnPlatform.Constraint2dType, value: int) -> None:
        ...
    
    eAngle: Constraint2dType
    
    eArc_length: Constraint2dType
    
    eArea: Constraint2dType
    
    eCoincident: Constraint2dType
    
    eConcentric: Constraint2dType
    
    eCurve_Length: Constraint2dType
    
    eDependence: Constraint2dType
    
    eDistance: Constraint2dType
    
    eDistanceCC: Constraint2dType
    
    eDistanceCL: Constraint2dType
    
    eDistanceCP: Constraint2dType
    
    eDistanceLL: Constraint2dType
    
    eDistancePL: Constraint2dType
    
    eDistancePP: Constraint2dType
    
    eDummy: Constraint2dType
    
    eEqual: Constraint2dType
    
    eEqual_Curvature: Constraint2dType
    
    eEqual_Direction: Constraint2dType
    
    eEqual_Distance: Constraint2dType
    
    eEqual_First_Derivative: Constraint2dType
    
    eEqual_Parameter: Constraint2dType
    
    eEqual_Radius: Constraint2dType
    
    eEqual_Relative_Transform: Constraint2dType
    
    eEqual_Second_Derivative: Constraint2dType
    
    eFix: Constraint2dType
    
    eHorizontal: Constraint2dType
    
    eIdentical: Constraint2dType
    
    eMajor_Radius: Constraint2dType
    
    eMidpoint: Constraint2dType
    
    eMinor_Radius: Constraint2dType
    
    eNormal: Constraint2dType
    
    eOffset: Constraint2dType
    
    eOffset_Dimension: Constraint2dType
    
    eParallel: Constraint2dType
    
    ePattern_2d_value_1: Constraint2dType
    
    ePattern_2d_value_2: Constraint2dType
    
    ePattern_Value: Constraint2dType
    
    ePatterned: Constraint2dType
    
    ePatterned_2d: Constraint2dType
    
    ePerimeter: Constraint2dType
    
    ePerpendicular: Constraint2dType
    
    ePlanar_Distance: Constraint2dType
    
    eRadius: Constraint2dType
    
    eSimple_Dependence: Constraint2dType
    
    eSymmetric: Constraint2dType
    
    eTangent: Constraint2dType
    
    eVertical: Constraint2dType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.Constraint2dType) -> int:
        ...
    
class Constraint3dBase:
    """
    None
    """

    @staticmethod
    def Create(*args, **kwargs):
        """
        Overloaded function.
        
        1. Create(type: MSPyMstnPlatform.Constraint3dType) -> MSPyMstnPlatform.Constraint3dBase
        
        2. Create(type: MSPyMstnPlatform.Constraint3dType, geometryIds: MSPyMstnPlatform.GeometryIdPtrArray, flags: int) -> MSPyMstnPlatform.Constraint3dBase
        """
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_SurfaceOrientation
        
        eFlagMask_GroupLock
        
        eFlagMask_HalfSpace1
        
        eFlagMask_HalfSpace2
        """
    
        def __init__(self: MSPyMstnPlatform.Constraint3dBase.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_GroupLock: FlagMasks
        
        eFlagMask_HalfSpace1: FlagMasks
        
        eFlagMask_HalfSpace2: FlagMasks
        
        eFlagMask_SurfaceOrientation: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.Constraint3dBase.FlagMasks) -> int:
            ...
        
    @property
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    @Flags.setter
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: int) -> None:
        ...
    
    def GetElementRefs(*args, **kwargs):
        """
        GetElementRefs(self: MSPyMstnPlatform.Constraint3dBase, elemRefs: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >) -> None
        """
        ...
    
    def GetFlags(self: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    
    def GetGroupLock(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def GetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.Constraint3dBase, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    
    def GetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    
    def GetType(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    @property
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    @GroupLock.setter
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: bool) -> None:
        ...
    
    @property
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace1.setter
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    @property
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace2.setter
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def HasBoundVariable(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def HasElementRef(self: MSPyMstnPlatform.Constraint3dBase, elemRef: MSPyDgnPlatform.ElementRefBase) -> bool:
        ...
    
    def IsRedundant(self: MSPyMstnPlatform.Constraint3dBase, other: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def SetFlags(self: MSPyMstnPlatform.Constraint3dBase, flags: int) -> None:
        ...
    
    def SetGeometryIds(self: MSPyMstnPlatform.Constraint3dBase, geometryIds: MSPyMstnPlatform.GeometryIdPtrArray) -> None:
        ...
    
    def SetGroupLock(self: MSPyMstnPlatform.Constraint3dBase, groupLock: bool) -> None:
        ...
    
    def SetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.Constraint3dBase, status: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    def SetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase, orientation: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    @property
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    @SurfaceOrientation.setter
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eDCM3_D_BETWEEN_FIXED: Status
    
    eDCM3_D_BETWEEN_SET_MEMBERS: Status
    
    eDCM3_D_NOT_CHANGED: Status
    
    eDCM3_D_NOT_CONSISTENT: Status
    
    eDCM3_D_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_D_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_D_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_D_NOT_SOLVED: Status
    
    eDCM3_D_OVER_DEFINED: Status
    
    eDCM3_D_SOLVED: Status
    
    eDCM3_D_UNKNOWN: Status
    
    eFlagMask_GroupLock: FlagMasks
    
    eFlagMask_HalfSpace1: FlagMasks
    
    eFlagMask_HalfSpace2: FlagMasks
    
    eFlagMask_SurfaceOrientation: FlagMasks
    
    eRedundant: Status
    
class Constraint3dDisplay:
    """
    None
    """

    @staticmethod
    def DrawConstraints(eh: MSPyDgnPlatform.ElementHandle, viewContext: MSPyDgnPlatform.ViewContext, drawConstraintMarkers: bool, drawDimensions: bool) -> None:
        ...
    
    @staticmethod
    def DrawPath(path: MSPyDgnPlatform.DisplayPath, viewContext: MSPyDgnPlatform.ViewContext) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Constraint3dElement:
    """
    None
    """

    @staticmethod
    def Create(eeh: MSPyDgnPlatform.EditElementHandle, destinationModelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    @staticmethod
    def GetConstraintDescription(description: MSPyBentley.WString, type: MSPyMstnPlatform.Constraint3dType, geometryStatus: MSPyMstnPlatform.GeometryId.Status) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    @staticmethod
    def GetConstraints(constraints: MSPyMstnPlatform.Constraint3dPtrArray, hostEh: MSPyDgnPlatform.ElementHandle) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    @staticmethod
    def GetDegreesOfFreedom(constraints: MSPyMstnPlatform.Constraint3dPtrArray, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        ...
    
    @staticmethod
    def GetExistingConstraints(*args, **kwargs):
        """
        GetExistingConstraints(hosts: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >, constraints: MSPyMstnPlatform.Constraint3dPtrArray, elemRefs: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >, modelRef: MSPyDgnPlatform.DgnModelRef, doGroups: bool) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    @staticmethod
    def GetHostElement(hostEeh: MSPyDgnPlatform.EditElementHandle, eh: MSPyDgnPlatform.ElementHandle, searchGroup: bool = False) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    @staticmethod
    def HasConstraints(eh: MSPyDgnPlatform.ElementHandle) -> bool:
        ...
    
    @staticmethod
    def IsConstraintElement(eh: MSPyDgnPlatform.ElementHandle) -> bool:
        ...
    
    @staticmethod
    def IsGroupedToConstraint(eh: MSPyDgnPlatform.ElementHandle) -> bool:
        ...
    
    @staticmethod
    def ReevaluateAndUpdate(dependentEh: MSPyDgnPlatform.ElementHandle, constraints: MSPyMstnPlatform.Constraint3dPtrArray, constraintsModified: bool, rootSet: MSPyDgnPlatform.ElementRefPArray) -> tuple:
        ...
    
    @staticmethod
    def RemoveElementConstraints(eh: MSPyDgnPlatform.ElementHandle) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    @staticmethod
    def SaveConstraints(eeh: MSPyDgnPlatform.EditElementHandle, constraints: MSPyMstnPlatform.Constraint3dPtrArray) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Constraint3dGUI:
    """
    None
    """

    @staticmethod
    def CloseDimensionDialog() -> None:
        ...
    
    @staticmethod
    def OpenAngleDialog(dimensionValue: float, variableAccess: MSPyBentley.WString, modelRef: MSPyDgnPlatform.DgnModelRef, viewport: MSPyDgnPlatform.Viewport, origin: MSPyBentleyGeom.DPoint3d) -> float:
        ...
    
    @staticmethod
    def OpenDimensionDialog(dimensionValue: float, variableAccess: MSPyBentley.WString, modelRef: MSPyDgnPlatform.DgnModelRef, viewport: MSPyDgnPlatform.Viewport, origin: MSPyBentleyGeom.DPoint3d) -> float:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Constraint3dHalfSpace:
    """
    Members:
    
    eNotSpecified
    
    ePositive
    
    eNegative
    """

    def __init__(self: MSPyMstnPlatform.Constraint3dHalfSpace, value: int) -> None:
        ...
    
    eNegative: Constraint3dHalfSpace
    
    eNotSpecified: Constraint3dHalfSpace
    
    ePositive: Constraint3dHalfSpace
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.Constraint3dHalfSpace) -> int:
        ...
    
class Constraint3dPtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.Constraint3dPtrArray) -> None
        
        2. __init__(self: MSPyMstnPlatform.Constraint3dPtrArray, arg0: MSPyMstnPlatform.Constraint3dPtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyMstnPlatform.Constraint3dPtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyMstnPlatform.Constraint3dPtrArray, x: MSPyMstnPlatform.Constraint3dBase) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyMstnPlatform.Constraint3dPtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyMstnPlatform.Constraint3dPtrArray, x: MSPyMstnPlatform.Constraint3dBase) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyMstnPlatform.Constraint3dPtrArray, L: MSPyMstnPlatform.Constraint3dPtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyMstnPlatform.Constraint3dPtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyMstnPlatform.Constraint3dPtrArray, i: int, x: MSPyMstnPlatform.Constraint3dBase) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyMstnPlatform.Constraint3dPtrArray) -> MSPyMstnPlatform.Constraint3dBase
        
        Remove and return the last item
        
        2. pop(self: MSPyMstnPlatform.Constraint3dPtrArray, i: int) -> MSPyMstnPlatform.Constraint3dBase
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyMstnPlatform.Constraint3dPtrArray, x: MSPyMstnPlatform.Constraint3dBase) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Constraint3dSolver:
    """
    None
    """

    def DynamicEvaluate(*args, **kwargs):
        """
        Overloaded function.
        
        1. DynamicEvaluate(self: MSPyMstnPlatform.Constraint3dSolver, elemRefs: MSPyDgnPlatform.ElementRefPArray, transform: MSPyBentleyGeom.Transform) -> tuple
        
        2. DynamicEvaluate(self: MSPyMstnPlatform.Constraint3dSolver, transformInMap: dict) -> tuple
        """
        ...
    
    def Evaluate(*args, **kwargs):
        """
        Overloaded function.
        
        1. Evaluate(self: MSPyMstnPlatform.Constraint3dSolver) -> tuple
        
        2. Evaluate(self: MSPyMstnPlatform.Constraint3dSolver, softReferenceId: MSPyMstnPlatform.GeometryId) -> tuple
        
        3. Evaluate(self: MSPyMstnPlatform.Constraint3dSolver, elemRefs: MSPyDgnPlatform.ElementRefPArray) -> tuple
        """
        ...
    
    def GetDegreesOfFreedom(self: MSPyMstnPlatform.Constraint3dSolver) -> tuple:
        ...
    
    def Initialize(self: MSPyMstnPlatform.Constraint3dSolver, constraints: MSPyMstnPlatform.Constraint3dPtrArray, modelRef: MSPyDgnPlatform.DgnModelRef, modifiedElements: dict = None, debugJournal: str = None) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def __init__(self: MSPyMstnPlatform.Constraint3dSolver) -> None:
        ...
    
class Constraint3dStorageVersion:
    """
    Members:
    
    eInitial
    
    eLatest
    """

    def __init__(self: MSPyMstnPlatform.Constraint3dStorageVersion, value: int) -> None:
        ...
    
    eInitial: Constraint3dStorageVersion
    
    eLatest: Constraint3dStorageVersion
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.Constraint3dStorageVersion) -> int:
        ...
    
class Constraint3dType:
    """
    Members:
    
    eDCM3_DISTANCE
    
    eDCM3_ANGLE
    
    eDCM3_CONCENTRIC
    
    eDCM3_RADIUS
    
    eDCM3_PARALLEL
    
    eDCM3_PERPENDICULAR
    
    eDCM3_COINCIDENT
    
    eDCM3_TANGENT
    
    eDCM3_MAJOR_RADIUS
    
    eDCM3_MINOR_RADIUS
    
    eDCM3_EQUAL_RADIUS
    
    eDCM3_MIDPOINT
    
    eDCM3_DEPENDENCE
    
    eDCM3_EQUAL_PARAMETER
    
    eDCM3_EQUAL_DIRECTION
    
    eDCM3_EQUAL_CURVATURE
    
    eDCM3_EQUAL_FIRST_DERIVATIVE
    
    eDCM3_EQUAL_SECOND_DERIVATIVE
    
    eDCM3_CURVE_LENGTH
    
    eDCM3_SYMMETRIC
    
    eDCM3_HALF_ANGLE
    
    eDCM3_COINCIDENT_AROUND_SPINE
    
    eDCM3_COINCIDENT_WITH_SPINE
    
    eDCM3_EQUAL_HALF_ANGLE
    
    eDCM3_EQUAL_CURVATURE_VECTOR
    
    eFixed
    
    eUnspecified
    """

    def __init__(self: MSPyMstnPlatform.Constraint3dType, value: int) -> None:
        ...
    
    eDCM3_ANGLE: Constraint3dType
    
    eDCM3_COINCIDENT: Constraint3dType
    
    eDCM3_COINCIDENT_AROUND_SPINE: Constraint3dType
    
    eDCM3_COINCIDENT_WITH_SPINE: Constraint3dType
    
    eDCM3_CONCENTRIC: Constraint3dType
    
    eDCM3_CURVE_LENGTH: Constraint3dType
    
    eDCM3_DEPENDENCE: Constraint3dType
    
    eDCM3_DISTANCE: Constraint3dType
    
    eDCM3_EQUAL_CURVATURE: Constraint3dType
    
    eDCM3_EQUAL_CURVATURE_VECTOR: Constraint3dType
    
    eDCM3_EQUAL_DIRECTION: Constraint3dType
    
    eDCM3_EQUAL_FIRST_DERIVATIVE: Constraint3dType
    
    eDCM3_EQUAL_HALF_ANGLE: Constraint3dType
    
    eDCM3_EQUAL_PARAMETER: Constraint3dType
    
    eDCM3_EQUAL_RADIUS: Constraint3dType
    
    eDCM3_EQUAL_SECOND_DERIVATIVE: Constraint3dType
    
    eDCM3_HALF_ANGLE: Constraint3dType
    
    eDCM3_MAJOR_RADIUS: Constraint3dType
    
    eDCM3_MIDPOINT: Constraint3dType
    
    eDCM3_MINOR_RADIUS: Constraint3dType
    
    eDCM3_PARALLEL: Constraint3dType
    
    eDCM3_PERPENDICULAR: Constraint3dType
    
    eDCM3_RADIUS: Constraint3dType
    
    eDCM3_SYMMETRIC: Constraint3dType
    
    eDCM3_TANGENT: Constraint3dType
    
    eFixed: Constraint3dType
    
    eUnspecified: Constraint3dType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.Constraint3dType) -> int:
        ...
    
class Constraint3dUtil:
    """
    None
    """

    @staticmethod
    def GetConstrainedElements(*args, **kwargs):
        """
        GetConstrainedElements(elements: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >, constraints: MSPyMstnPlatform.Constraint3dPtrArray, modelRef: MSPyDgnPlatform.DgnModelRef) -> None
        """
        ...
    
    @staticmethod
    def GetEdgeArcAxis(axis: MSPyBentleyGeom.DRay3d, edge: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    @staticmethod
    def GetFaceAxis(face: MSPyDgnPlatform.ISubEntity) -> tuple:
        ...
    
    @staticmethod
    def GetNamedGroupMembers(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetNamedGroupMembers(members: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >, namedGroup: MSPyDgnPlatform.NamedGroup) -> MSPyDgnPlatform.BentleyStatus
        
        2. GetNamedGroupMembers(members: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >, elemRef: MSPyDgnPlatform.ElementRefBase, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus
        """
        ...
    
    @staticmethod
    def RemoveInvalidConstraints(constraints: MSPyMstnPlatform.Constraint3dPtrArray, changed: MSPyDgnPlatform.ElementRefBase, hostEh: MSPyDgnPlatform.ElementHandle) -> int:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Constraint3dXAttributeIndex:
    """
    Members:
    
    eData
    
    eVariableDependency
    """

    def __init__(self: MSPyMstnPlatform.Constraint3dXAttributeIndex, value: int) -> None:
        ...
    
    eData: Constraint3dXAttributeIndex
    
    eVariableDependency: Constraint3dXAttributeIndex
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.Constraint3dXAttributeIndex) -> int:
        ...
    
class CurveArcAxisGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, curvePrimitiveId: MSPyBentleyGeom.CurvePrimitiveId) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class CurveEntityIdentifier:
    """
    None
    """

    @property
    def EdgeId(arg0: MSPyMstnPlatform.CurveEntityIdentifier) -> MSPyBentleyGeom.CurvePrimitiveId:
        ...
    @EdgeId.setter
    def EdgeId(arg0: MSPyMstnPlatform.CurveEntityIdentifier, arg1: MSPyBentleyGeom.CurvePrimitiveId) -> None:
        ...
    
    @staticmethod
    def ElementToCurveVector(eh: MSPyDgnPlatform.ElementHandle) -> tuple:
        """
        @cond DONTINCLUDEINDOC @endcond @description Get an editable curve
        vector of a given element
        
        Parameter ``[out]``:
        curveVector The resultant curve vector
        
        Parameter ``[in]``:
        eh An ElementHandle to specify a curve element
        """
        ...
    
    def GetEdgeId(self: MSPyMstnPlatform.CurveEntityIdentifier) -> MSPyBentleyGeom.CurvePrimitiveId:
        """
        @description Get the edge id @retval NULL if failing to get
        """
        ...
    
    def GetPointIndex(self: MSPyMstnPlatform.CurveEntityIdentifier) -> int:
        """
        @description Get the point index
        
        Returns:
        The point index
        """
        ...
    
    def GetSubEdgeIndex(self: MSPyMstnPlatform.CurveEntityIdentifier) -> int:
        """
        @description Get the sub edge index
        
        Returns:
        The sub edge index
        """
        ...
    
    def GetVertexType(self: MSPyMstnPlatform.CurveEntityIdentifier) -> MSPyMstnPlatform.VertexType:
        """
        @description Get the vertex type
        
        Returns:
        The vertex type
        """
        ...
    
    def IsValid(self: MSPyMstnPlatform.CurveEntityIdentifier) -> bool:
        """
        @description Test the CurveEntityIdentifier is valid or not
        
        Returns:
        True if it is valid, or False if not
        """
        ...
    
    @property
    def PointIndex(arg0: MSPyMstnPlatform.CurveEntityIdentifier) -> int:
        ...
    @PointIndex.setter
    def PointIndex(arg0: MSPyMstnPlatform.CurveEntityIdentifier, arg1: int) -> None:
        ...
    
    def SetEdgeId(self: MSPyMstnPlatform.CurveEntityIdentifier, edgeId: MSPyBentleyGeom.CurvePrimitiveId) -> None:
        """
        @description Set the edge id
        
        Parameter ``edgeId``:
        the edge id @note edgeId cannot be NULL
        """
        ...
    
    def SetPointIndex(self: MSPyMstnPlatform.CurveEntityIdentifier, pointIndex: int) -> None:
        """
        @description Set the point index in linestring
        
        Parameter ``pointIndex``:
        the point index
        """
        ...
    
    def SetSubEdgeIndex(self: MSPyMstnPlatform.CurveEntityIdentifier, subEdgeIndex: int) -> None:
        """
        @description Set the sub edge index
        
        Parameter ``subEdgeIndex``:
        the sub edge index
        """
        ...
    
    def SetVertexType(self: MSPyMstnPlatform.CurveEntityIdentifier, vertexType: MSPyMstnPlatform.VertexType) -> None:
        """
        @description Set new vertex type
        
        Parameter ``vertexType``:
        A new vertex type to set
        """
        ...
    
    @property
    def SubEdgeIndex(arg0: MSPyMstnPlatform.CurveEntityIdentifier) -> int:
        ...
    @SubEdgeIndex.setter
    def SubEdgeIndex(arg0: MSPyMstnPlatform.CurveEntityIdentifier, arg1: int) -> None:
        ...
    
    @property
    def VertexType(arg0: MSPyMstnPlatform.CurveEntityIdentifier) -> MSPyMstnPlatform.VertexType:
        ...
    @VertexType.setter
    def VertexType(arg0: MSPyMstnPlatform.CurveEntityIdentifier, arg1: MSPyMstnPlatform.VertexType) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.CurveEntityIdentifier) -> None
        
        2. __init__(self: MSPyMstnPlatform.CurveEntityIdentifier, curve: MSPyBentleyGeom.CurveVector, edgeId: MSPyBentleyGeom.CurvePrimitiveId, subIndex: int, vertexType: MSPyMstnPlatform.VertexType, elemRef: MSPyDgnPlatform.ElementRefBase) -> None
        
        3. __init__(self: MSPyMstnPlatform.CurveEntityIdentifier, curve: MSPyBentleyGeom.CurveVector, location: MSPyBentleyGeom.CurveLocationDetail, vertexType: MSPyMstnPlatform.VertexType, elemRef: MSPyDgnPlatform.ElementRefBase) -> None
        """
        ...
    
class CurveEntityIdentifierArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.CurveEntityIdentifierArray) -> None
        
        2. __init__(self: MSPyMstnPlatform.CurveEntityIdentifierArray, arg0: MSPyMstnPlatform.CurveEntityIdentifierArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyMstnPlatform.CurveEntityIdentifierArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyMstnPlatform.CurveEntityIdentifierArray, x: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyMstnPlatform.CurveEntityIdentifierArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyMstnPlatform.CurveEntityIdentifierArray, x: MSPyMstnPlatform.CurveEntityIdentifier) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyMstnPlatform.CurveEntityIdentifierArray, L: MSPyMstnPlatform.CurveEntityIdentifierArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyMstnPlatform.CurveEntityIdentifierArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyMstnPlatform.CurveEntityIdentifierArray, i: int, x: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyMstnPlatform.CurveEntityIdentifierArray) -> MSPyMstnPlatform.CurveEntityIdentifier
        
        Remove and return the last item
        
        2. pop(self: MSPyMstnPlatform.CurveEntityIdentifierArray, i: int) -> MSPyMstnPlatform.CurveEntityIdentifier
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyMstnPlatform.CurveEntityIdentifierArray, x: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class CurveGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, curveLocationDetail: MSPyBentleyGeom.CurveLocationDetail) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class CurvePointGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, curveLocationDetail: MSPyBentleyGeom.CurveLocationDetail) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class DgnFile:
    """
    None
    """

    @staticmethod
    def CheckRights(dgnFileObj: MSPyDgnPlatform.DgnFile, rights: int, displayError: MSPyMstnPlatform.MessageDestination) -> int:
        """
        @Description Check if the specified rights are granted to the current
        user for the specified file.
        
        Remark:
        s The rights parameter can be one or more of the following values
        OR'd together:
        
        * DgnPlatform.DGNFILE_RIGHT_Print -- Print, print preview, e-plot,
        etc.
        
        * DgnPlatform.DGNFILE_RIGHT_Export -- SaveAs, Export, Copy to
        clipboard, File Fence, etc.
        
        * DgnPlatform.DGNFILE_RIGHT_Edit -- Modify file contents (implies not
        read-only)
        
        * DgnPlatform.DGNFILE_RIGHT_Unlimited -- All rights, present and
        future
        
        Parameter ``DgnFile``:
        the DgnFile of interest. @Param[in] rights the rights to query
        @Param[in] displayError display error message in message center if
        rights not granted? Else return ERROR silently @Return SUCCESS if
        all of the rights are granted.
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateModel(dgnFileObj: MSPyDgnPlatform.DgnFile, seedModelRef: MSPyDgnPlatform.DgnModelRef, modelName: str, modelDescr: str, FromSeedForModelAndIs3d: bool, modelType: MSPyDgnPlatform.DgnModelType, Is3d: bool) -> tuple:
        ...
    
    @staticmethod
    def FindElemByID(dgnFile: MSPyDgnPlatform.DgnFile, elemId: int, dictionaryOnly: bool) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindModelIDByName(dgnFileObj: MSPyDgnPlatform.DgnFile, name: str) -> tuple:
        ...
    
    @staticmethod
    def GetMasterFile() -> MSPyDgnPlatform.DgnFile:
        """
        @Description Get the DgnFile for the current master file. @Return
        The DgnFileP for the current master file.
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetModelCount(dgnFileObj: MSPyDgnPlatform.DgnFile) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetModelItemById(dgnFileObj: MSPyDgnPlatform.DgnFile, modelId: int) -> MSPyDgnPlatform.ModelIndexItem:
        """
        Retrieve the model index item using a model ID.
        
        Parameter ``pDgnFile``:
        The file containing the model.
        
        Parameter ``modelID``:
        The ID of the model to retreive.
        
        Returns:
        NULL if the indicated model does not exist in the file, otherwise
        a pointer to the model index item. @Group " DgnFile Functions "
        @See ModelItem.GetData ModelItem.GetName
        ModelItem.GetDescription
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetModelItemByName(dgnFileObj: MSPyDgnPlatform.DgnFile, modelName: str) -> MSPyDgnPlatform.ModelIndexItem:
        """
        Retrieve the model index item using a model name.
        
        Parameter ``pDgnFile``:
        The file containing the model.
        
        Parameter ``modelName``:
        The name of the model to retreive.
        
        Returns:
        NULL if the indicated model does not exist in the file, otherwise
        a pointer to the model index item. @Group " DgnFile Functions "
        @See ModelItem.GetData ModelItem.GetName
        ModelItem.GetDescription
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetModelRefList(dgnFileObj: MSPyDgnPlatform.DgnFile) -> MSPyDgnPlatform.DgnModelRefList:
        """
        Create a DgnModelRefList containing an entry for each of the loaded
        models in the specified design file. Note, any DgnModelRefList created
        with this function must be freed by calling <a
        href=" usmthModelRefList.Free htm ">ModelRefList.Free</a>.
        
        Parameter ``DgnFile``:
        Is a reference to the design file containing the models to add to
        the list. @Remarks The returned model ref must be freed by the
        caller.
        
        Returns:
        A pointer to the DgnModelRefList that has an entry for each model
        in the design file. @Group " DgnFile Functions "
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetVersion(dgnFilebj: MSPyDgnPlatform.DgnFile) -> tuple:
        ...
    
    @staticmethod
    def HasPendingChanges(DgnFile: MSPyDgnPlatform.DgnFile) -> bool:
        """
        @Description Determines if a design file has pending chages.
        @Param[in] DgnFile is a reference to the design file of interest
        @Return true if the design file has changes that have not been saved;
        false otherwise.
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsProtected(dgnFileObj: MSPyDgnPlatform.DgnFile) -> bool:
        """
        @Description Check if the specified file is encrypted (e.g., for
        digital rights management)
        
        Parameter ``file``:
        the DgnFile of interest. @Return true if file is encrypted
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DialogIds:
    """
    Members:
    
    eDIALOGID_Locks
    
    eDIALOGID_ToolBoxDummy
    
    eDIALOGID_ElementAttributes
    
    eDIALOGID_CoordReadout
    
    eDIALOGID_MainWindow
    
    eDIALOGID_ReferenceFile
    
    eDIALOGID_FileProperties
    
    eDIALOGID_AuxCoordSystems
    
    eDIALOGID_GetSecurityKey
    
    eDIALOGID_StandardAlert
    
    eDIALOGID_ElementQuickInfo
    
    eDIALOGID_UstnMgr
    
    eDIALOGID_AcademicAdvisory
    
    eDIALOGID_PaletteItems
    
    eDIALOGID_Snaps
    
    eDIALOGID_AccuSnap
    
    eDIALOGID_GraphicsFileExport
    
    eDIALOGID_LineStyleSelect
    
    eDIALOGID_DefineNamedLevelsSort
    
    eDIALOGID_NamedLevelsTargetGroup
    
    eDIALOGID_AdvisoryDisplay
    
    eDIALOGID_CloseToolBoxes
    
    eDIALOGID_TaskNavigation
    
    eDIALOGID_WorkingUnits
    
    eDIALOGID_DefineNamedLevels
    
    eDIALOGID_DBSettings
    
    eDIALOGID_ViewRotation
    
    eDIALOGID_CellMaintenance
    
    eDIALOGID_CellEdit
    
    eDIALOGID_CellCreate
    
    eDIALOGID_DesignFileSettings
    
    eDIALOGID_ActiveAngle
    
    eDIALOGID_ReferenceAttach
    
    eDIALOGID_UserPreference
    
    eDIALOGID_V7DesignFileAlert
    
    eDIALOGID_AboutDigitalRights
    
    eDIALOGID_CustomScale
    
    eDIALOGID_ViewSettings
    
    eDIALOGID_ViewLevels
    
    eDIALOGID_CmdBrowser
    
    eDIALOGID_ActiveScale
    
    eDIALOGID_PatternSettings
    
    eDIALOGID_ColorSquare
    
    eDIALOGID_StdFileSeedCreate
    
    eDIALOGID_KeyinSettings
    
    eDIALOGID_Font
    
    eDIALOGID_ColorPalette
    
    eDIALOGID_LevSymb
    
    eDIALOGID_GridSettings
    
    eDIALOGID_DesignOptions
    
    eDIALOGID_CustomSheetSize
    
    eDIALOGID_Camera
    
    eDIALOGID_AboutConfiguration
    
    eDIALOGID_FunctionKeys
    
    eDIALOGID_TextStyleEditor
    
    eDIALOGID_OptionalInfoBox
    
    eDIALOGID_MDL
    
    eDIALOGID_MDLDetail
    
    eDIALOGID_CmdBrowserApp
    
    eDIALOGID_StdFileOpen
    
    eDIALOGID_Digitizing
    
    eDIALOGID_ExtendedFileOpen
    
    eDIALOGID_PreviewPrint
    
    eDIALOGID_OptionalOKCancelBox
    
    eDIALOGID_AboutWorkmode
    
    eDIALOGID_Display
    
    eDIALOGID_MainFrame
    
    eDIALOGID_FenceFrame
    
    eDIALOGID_FileListDirSingle
    
    eDIALOGID_ToolSettings
    
    eDIALOGID_Image
    
    eDIALOGID_ReferenceRotate
    
    eDIALOGID_ReferenceScale
    
    eDIALOGID_ImageSave
    
    eDIALOGID_TextFileDisplay
    
    eDIALOGID_AboutUstn
    
    eDIALOGID_FileList
    
    eDIALOGID_BasicLocks
    
    eDIALOGID_FileListDirMultiple
    
    eDIALOGID_FileListMultiple
    
    eDIALOGID_FileListDDSingle
    
    eDIALOGID_FileListDDMultiple
    
    eDIALOGID_LevelEdit
    
    eDIALOGID_GroupEdit
    
    eDIALOGID_DialogMessages
    
    eDIALOGID_WindowManMenu
    
    eDIALOGID_ViewToggles
    
    eDIALOGID_StandardInfoBox
    
    eDIALOGID_Help
    
    eDIALOGID_HelpFind
    
    eDIALOGID_LargeAlert
    
    eDIALOGID_ButtonAssignment
    
    eDIALOGID_ButtonMap
    
    eDIALOGID_ShowClipboard
    
    eDIALOGID_DrawComp
    
    eDIALOGID_CompletionBar
    
    eDIALOGID_AboutUstnMore
    
    eDIALOGID_GraphicsFileOpen
    
    eDIALOGID_GraphicsFileSaveAs
    
    eDIALOGID_ReferenceFullSettings
    
    eDIALOGID_ColorInterpolate
    
    eDIALOGID_MediumAlert
    
    eDIALOGID_YesNoCancelAlert
    
    eDIALOGID_ColorPalInfo
    
    eDIALOGID_NamedLevels
    
    eDIALOGID_Igen
    
    eDIALOGID_SetHiliteColor
    
    eDIALOGID_SetVectorCursorColor
    
    eDIALOGID_MediumInfoBox
    
    eDIALOGID_LargeInfoBox
    
    eDIALOGID_MsgBoxYesNo
    
    eDIALOGID_MsgBoxOK
    
    eDIALOGID_MsgBoxYesNoCancel
    
    eDIALOGID_MsgBoxOKCancel
    
    eDIALOGID_View
    
    eDIALOGID_AboutUstnLicenseMore
    
    eDIALOGID_MsgBoxMediumYesNoCancel
    
    eDIALOGID_MoreWindows
    
    eDIALOGID_ElementPreviewDialog
    
    eDIALOGID_UpdateSequence
    
    eDIALOGID_HLineSettings
    
    eDIALOGID_SnapButtonResizable
    
    eDIALOGID_TrackBar
    
    eDIALOGID_BusyBar
    
    eDIALOGID_DesignLinksCreate
    
    eDIALOGID_SelectImagePreview
    
    eDIALOGID_ModelManager
    
    eDIALOGID_V7CellLibConvert
    
    eDIALOGID_YesAllNoCancelAlert
    
    eDIALOGID_ReferenceFileOpen
    
    eDIALOGID_MsgBoxYesAllNoCancel
    
    eDIALOGID_SubEditor
    
    eDIALOGID_ReferenceFileBrowse
    
    eDIALOGID_FileSaveAsOptions
    
    eDIALOGID_ModelChoose
    
    eDIALOGID_CfgVars
    
    eDIALOGID_DockableTemplate
    
    eDIALOGID_FramedTemplate
    
    eDIALOGID_RefColorAdjust
    
    eDIALOGID_AcceleratorPrefs
    
    eDIALOGID_ReferenceDragDrop
    
    eDIALOGID_MultiSnap
    
    eDIALOGID_AdvancedColors
    
    eDIALOGID_ViewAreaBackground
    
    eDIALOGID_TransparencyPriority
    
    eDIALOGID_NamedFences
    
    eDIALOGID_ToolBoxTemplate
    
    eDIALOGID_Customize
    
    eDIALOGID_ColorBookEditor
    
    eDIALOGID_CreateColorBook
    
    eDIALOGID_CellSelectorFileOpen
    
    eDIALOGID_CellSelectorFileCreate
    
    eDIALOGID_MsgBoxYesAllNo
    
    eDIALOGID_ResetMenuOptions
    
    eDIALOGID_RefPresentation
    
    eDIALOGID_ViewBrightness
    
    eDIALOGID_YesAllNoAllCancelAlert
    
    eDIALOGID_MsgBoxMediumYesNo
    
    eDIALOGID_HiddenLineSettings
    
    eDIALOGID_CommonItems
    
    eDIALOGID_PointCloudFileBrowse
    
    eDIALOGID_CellSelect
    
    eDIALOGID_OptionalOKCancelBoxWide
    
    eDIALOGID_InputManager
    
    eDIALOGID_Transparency
    
    eDIALOGID_RasterFileBrowse
    
    eDIALOGID_SavedViewDragDrop
    
    eDIALOGID_CachedVisibleEdgeSettings
    
    eDIALOGID_MsgBoxLargeYesNo
    
    eDIALOGID_DWGAecFileAlert
    
    eDIALOGID_DeletingUsedStyles
    
    eDIALOGID_KeyboardShortcuts
    
    eDIALOGID_BothValidAndDifferent
    
    eDIALOGID_UnassociatedFile_ValidActiveWorkSet
    
    eDIALOGID_FileWorkSetNotFound_InvalidActiveWorkSet
    
    eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet
    
    eDIALOGID_Preprocessor
    
    eDIALOGID_PropertyBinding
    
    eDIALOGID_FileWorkSetFound_InvalidActiveWorkSet
    
    eDIALOGID_UnassociatedFile_Product_Mismatch
    
    eDIALOGID_UnsignedAppWarning
    
    eDIALOGID_VariableDialog
    
    eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet_ValidConfig
    """

    def __init__(self: MSPyMstnPlatform.DialogIds, value: int) -> None:
        ...
    
    eDIALOGID_AboutConfiguration: DialogIds
    
    eDIALOGID_AboutDigitalRights: DialogIds
    
    eDIALOGID_AboutUstn: DialogIds
    
    eDIALOGID_AboutUstnLicenseMore: DialogIds
    
    eDIALOGID_AboutUstnMore: DialogIds
    
    eDIALOGID_AboutWorkmode: DialogIds
    
    eDIALOGID_AcademicAdvisory: DialogIds
    
    eDIALOGID_AcceleratorPrefs: DialogIds
    
    eDIALOGID_AccuSnap: DialogIds
    
    eDIALOGID_ActiveAngle: DialogIds
    
    eDIALOGID_ActiveScale: DialogIds
    
    eDIALOGID_AdvancedColors: DialogIds
    
    eDIALOGID_AdvisoryDisplay: DialogIds
    
    eDIALOGID_AuxCoordSystems: DialogIds
    
    eDIALOGID_BasicLocks: DialogIds
    
    eDIALOGID_BothValidAndDifferent: DialogIds
    
    eDIALOGID_BusyBar: DialogIds
    
    eDIALOGID_ButtonAssignment: DialogIds
    
    eDIALOGID_ButtonMap: DialogIds
    
    eDIALOGID_CachedVisibleEdgeSettings: DialogIds
    
    eDIALOGID_Camera: DialogIds
    
    eDIALOGID_CellCreate: DialogIds
    
    eDIALOGID_CellEdit: DialogIds
    
    eDIALOGID_CellMaintenance: DialogIds
    
    eDIALOGID_CellSelect: DialogIds
    
    eDIALOGID_CellSelectorFileCreate: DialogIds
    
    eDIALOGID_CellSelectorFileOpen: DialogIds
    
    eDIALOGID_CfgVars: DialogIds
    
    eDIALOGID_CloseToolBoxes: DialogIds
    
    eDIALOGID_CmdBrowser: DialogIds
    
    eDIALOGID_CmdBrowserApp: DialogIds
    
    eDIALOGID_ColorBookEditor: DialogIds
    
    eDIALOGID_ColorInterpolate: DialogIds
    
    eDIALOGID_ColorPalInfo: DialogIds
    
    eDIALOGID_ColorPalette: DialogIds
    
    eDIALOGID_ColorSquare: DialogIds
    
    eDIALOGID_CommonItems: DialogIds
    
    eDIALOGID_CompletionBar: DialogIds
    
    eDIALOGID_CoordReadout: DialogIds
    
    eDIALOGID_CreateColorBook: DialogIds
    
    eDIALOGID_CustomScale: DialogIds
    
    eDIALOGID_CustomSheetSize: DialogIds
    
    eDIALOGID_Customize: DialogIds
    
    eDIALOGID_DBSettings: DialogIds
    
    eDIALOGID_DWGAecFileAlert: DialogIds
    
    eDIALOGID_DefineNamedLevels: DialogIds
    
    eDIALOGID_DefineNamedLevelsSort: DialogIds
    
    eDIALOGID_DeletingUsedStyles: DialogIds
    
    eDIALOGID_DesignFileSettings: DialogIds
    
    eDIALOGID_DesignLinksCreate: DialogIds
    
    eDIALOGID_DesignOptions: DialogIds
    
    eDIALOGID_DialogMessages: DialogIds
    
    eDIALOGID_Digitizing: DialogIds
    
    eDIALOGID_Display: DialogIds
    
    eDIALOGID_DockableTemplate: DialogIds
    
    eDIALOGID_DrawComp: DialogIds
    
    eDIALOGID_ElementAttributes: DialogIds
    
    eDIALOGID_ElementPreviewDialog: DialogIds
    
    eDIALOGID_ElementQuickInfo: DialogIds
    
    eDIALOGID_ExtendedFileOpen: DialogIds
    
    eDIALOGID_FenceFrame: DialogIds
    
    eDIALOGID_FileList: DialogIds
    
    eDIALOGID_FileListDDMultiple: DialogIds
    
    eDIALOGID_FileListDDSingle: DialogIds
    
    eDIALOGID_FileListDirMultiple: DialogIds
    
    eDIALOGID_FileListDirSingle: DialogIds
    
    eDIALOGID_FileListMultiple: DialogIds
    
    eDIALOGID_FileProperties: DialogIds
    
    eDIALOGID_FileSaveAsOptions: DialogIds
    
    eDIALOGID_FileWorkSetFound_InvalidActiveWorkSet: DialogIds
    
    eDIALOGID_FileWorkSetNotFound_InvalidActiveWorkSet: DialogIds
    
    eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet: DialogIds
    
    eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet_ValidConfig: DialogIds
    
    eDIALOGID_Font: DialogIds
    
    eDIALOGID_FramedTemplate: DialogIds
    
    eDIALOGID_FunctionKeys: DialogIds
    
    eDIALOGID_GetSecurityKey: DialogIds
    
    eDIALOGID_GraphicsFileExport: DialogIds
    
    eDIALOGID_GraphicsFileOpen: DialogIds
    
    eDIALOGID_GraphicsFileSaveAs: DialogIds
    
    eDIALOGID_GridSettings: DialogIds
    
    eDIALOGID_GroupEdit: DialogIds
    
    eDIALOGID_HLineSettings: DialogIds
    
    eDIALOGID_Help: DialogIds
    
    eDIALOGID_HelpFind: DialogIds
    
    eDIALOGID_HiddenLineSettings: DialogIds
    
    eDIALOGID_Igen: DialogIds
    
    eDIALOGID_Image: DialogIds
    
    eDIALOGID_ImageSave: DialogIds
    
    eDIALOGID_InputManager: DialogIds
    
    eDIALOGID_KeyboardShortcuts: DialogIds
    
    eDIALOGID_KeyinSettings: DialogIds
    
    eDIALOGID_LargeAlert: DialogIds
    
    eDIALOGID_LargeInfoBox: DialogIds
    
    eDIALOGID_LevSymb: DialogIds
    
    eDIALOGID_LevelEdit: DialogIds
    
    eDIALOGID_LineStyleSelect: DialogIds
    
    eDIALOGID_Locks: DialogIds
    
    eDIALOGID_MDL: DialogIds
    
    eDIALOGID_MDLDetail: DialogIds
    
    eDIALOGID_MainFrame: DialogIds
    
    eDIALOGID_MainWindow: DialogIds
    
    eDIALOGID_MediumAlert: DialogIds
    
    eDIALOGID_MediumInfoBox: DialogIds
    
    eDIALOGID_ModelChoose: DialogIds
    
    eDIALOGID_ModelManager: DialogIds
    
    eDIALOGID_MoreWindows: DialogIds
    
    eDIALOGID_MsgBoxLargeYesNo: DialogIds
    
    eDIALOGID_MsgBoxMediumYesNo: DialogIds
    
    eDIALOGID_MsgBoxMediumYesNoCancel: DialogIds
    
    eDIALOGID_MsgBoxOK: DialogIds
    
    eDIALOGID_MsgBoxOKCancel: DialogIds
    
    eDIALOGID_MsgBoxYesAllNo: DialogIds
    
    eDIALOGID_MsgBoxYesAllNoCancel: DialogIds
    
    eDIALOGID_MsgBoxYesNo: DialogIds
    
    eDIALOGID_MsgBoxYesNoCancel: DialogIds
    
    eDIALOGID_MultiSnap: DialogIds
    
    eDIALOGID_NamedFences: DialogIds
    
    eDIALOGID_NamedLevels: DialogIds
    
    eDIALOGID_NamedLevelsTargetGroup: DialogIds
    
    eDIALOGID_OptionalInfoBox: DialogIds
    
    eDIALOGID_OptionalOKCancelBox: DialogIds
    
    eDIALOGID_OptionalOKCancelBoxWide: DialogIds
    
    eDIALOGID_PaletteItems: DialogIds
    
    eDIALOGID_PatternSettings: DialogIds
    
    eDIALOGID_PointCloudFileBrowse: DialogIds
    
    eDIALOGID_Preprocessor: DialogIds
    
    eDIALOGID_PreviewPrint: DialogIds
    
    eDIALOGID_PropertyBinding: DialogIds
    
    eDIALOGID_RasterFileBrowse: DialogIds
    
    eDIALOGID_RefColorAdjust: DialogIds
    
    eDIALOGID_RefPresentation: DialogIds
    
    eDIALOGID_ReferenceAttach: DialogIds
    
    eDIALOGID_ReferenceDragDrop: DialogIds
    
    eDIALOGID_ReferenceFile: DialogIds
    
    eDIALOGID_ReferenceFileBrowse: DialogIds
    
    eDIALOGID_ReferenceFileOpen: DialogIds
    
    eDIALOGID_ReferenceFullSettings: DialogIds
    
    eDIALOGID_ReferenceRotate: DialogIds
    
    eDIALOGID_ReferenceScale: DialogIds
    
    eDIALOGID_ResetMenuOptions: DialogIds
    
    eDIALOGID_SavedViewDragDrop: DialogIds
    
    eDIALOGID_SelectImagePreview: DialogIds
    
    eDIALOGID_SetHiliteColor: DialogIds
    
    eDIALOGID_SetVectorCursorColor: DialogIds
    
    eDIALOGID_ShowClipboard: DialogIds
    
    eDIALOGID_SnapButtonResizable: DialogIds
    
    eDIALOGID_Snaps: DialogIds
    
    eDIALOGID_StandardAlert: DialogIds
    
    eDIALOGID_StandardInfoBox: DialogIds
    
    eDIALOGID_StdFileOpen: DialogIds
    
    eDIALOGID_StdFileSeedCreate: DialogIds
    
    eDIALOGID_SubEditor: DialogIds
    
    eDIALOGID_TaskNavigation: DialogIds
    
    eDIALOGID_TextFileDisplay: DialogIds
    
    eDIALOGID_TextStyleEditor: DialogIds
    
    eDIALOGID_ToolBoxDummy: DialogIds
    
    eDIALOGID_ToolBoxTemplate: DialogIds
    
    eDIALOGID_ToolSettings: DialogIds
    
    eDIALOGID_TrackBar: DialogIds
    
    eDIALOGID_Transparency: DialogIds
    
    eDIALOGID_TransparencyPriority: DialogIds
    
    eDIALOGID_UnassociatedFile_Product_Mismatch: DialogIds
    
    eDIALOGID_UnassociatedFile_ValidActiveWorkSet: DialogIds
    
    eDIALOGID_UnsignedAppWarning: DialogIds
    
    eDIALOGID_UpdateSequence: DialogIds
    
    eDIALOGID_UserPreference: DialogIds
    
    eDIALOGID_UstnMgr: DialogIds
    
    eDIALOGID_V7CellLibConvert: DialogIds
    
    eDIALOGID_V7DesignFileAlert: DialogIds
    
    eDIALOGID_VariableDialog: DialogIds
    
    eDIALOGID_View: DialogIds
    
    eDIALOGID_ViewAreaBackground: DialogIds
    
    eDIALOGID_ViewBrightness: DialogIds
    
    eDIALOGID_ViewLevels: DialogIds
    
    eDIALOGID_ViewRotation: DialogIds
    
    eDIALOGID_ViewSettings: DialogIds
    
    eDIALOGID_ViewToggles: DialogIds
    
    eDIALOGID_WindowManMenu: DialogIds
    
    eDIALOGID_WorkingUnits: DialogIds
    
    eDIALOGID_YesAllNoAllCancelAlert: DialogIds
    
    eDIALOGID_YesAllNoCancelAlert: DialogIds
    
    eDIALOGID_YesNoCancelAlert: DialogIds
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.DialogIds) -> int:
        ...
    
class Dimension2dData:
    """
    None
    """

    def AddCurveIdentifier(self: MSPyMstnPlatform.Constraint2dData, id: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        """
        @description Add curve identifier
        
        Parameter ``id``:
        The id to be added
        """
        ...
    
    @property
    def AngleSectorIndex(arg0: MSPyMstnPlatform.Dimension2dData) -> int:
        ...
    @AngleSectorIndex.setter
    def AngleSectorIndex(arg0: MSPyMstnPlatform.Dimension2dData, arg1: int) -> None:
        ...
    
    @property
    def ConstraintStatus(arg0: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dStatus:
        ...
    @ConstraintStatus.setter
    def ConstraintStatus(arg0: MSPyMstnPlatform.Constraint2dData, arg1: MSPyMstnPlatform.Constraint2dStatus) -> None:
        ...
    
    @property
    def ConstraintType(arg0: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dType:
        ...
    @ConstraintType.setter
    def ConstraintType(arg0: MSPyMstnPlatform.Constraint2dData, arg1: MSPyMstnPlatform.Constraint2dType) -> None:
        ...
    
    @property
    def DiaType(arg0: MSPyMstnPlatform.Dimension2dData) -> int:
        ...
    @DiaType.setter
    def DiaType(arg0: MSPyMstnPlatform.Dimension2dData, arg1: int) -> None:
        ...
    
    @property
    def DimensionAlignmentType(arg0: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.DimensionAlignmentType:
        ...
    @DimensionAlignmentType.setter
    def DimensionAlignmentType(arg0: MSPyMstnPlatform.Dimension2dData, arg1: MSPyMstnPlatform.DimensionAlignmentType) -> None:
        ...
    
    @property
    def DimensionFraction(arg0: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    @DimensionFraction.setter
    def DimensionFraction(arg0: MSPyMstnPlatform.Dimension2dData, arg1: float) -> None:
        ...
    
    @property
    def DimensionHeight(arg0: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    @DimensionHeight.setter
    def DimensionHeight(arg0: MSPyMstnPlatform.Dimension2dData, arg1: float) -> None:
        ...
    
    @property
    def DimensionValue(arg0: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    @DimensionValue.setter
    def DimensionValue(arg0: MSPyMstnPlatform.Dimension2dData, arg1: float) -> None:
        ...
    
    @property
    def DimensionXOffset(arg0: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    @DimensionXOffset.setter
    def DimensionXOffset(arg0: MSPyMstnPlatform.Dimension2dData, arg1: float) -> None:
        ...
    
    def GetAngleSectorIndex(self: MSPyMstnPlatform.Dimension2dData) -> int:
        ...
    
    def GetConstraintStatus(self: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dStatus:
        """
        @description Get the constraint status
        
        Returns:
        The constraint status
        """
        ...
    
    def GetConstraintType(self: MSPyMstnPlatform.Constraint2dData) -> MSPyMstnPlatform.Constraint2dType:
        """
        @description Get the constraint type
        
        Returns:
        The constraint type
        """
        ...
    
    def GetDiaType(self: MSPyMstnPlatform.Dimension2dData) -> int:
        ...
    
    def GetDimensionAlignmentType(self: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.DimensionAlignmentType:
        ...
    
    def GetDimensionFraction(self: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    
    def GetDimensionHeight(self: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    
    def GetDimensionValue(self: MSPyMstnPlatform.Dimension2dData) -> float:
        """
        @description Get dimension value
        
        Returns:
        Dimension value
        """
        ...
    
    def GetDimensionXOffset(self: MSPyMstnPlatform.Dimension2dData) -> float:
        ...
    
    def GetHalfSpace1(self: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.DimensionHalfSpace:
        ...
    
    def GetHalfSpace2(self: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.DimensionHalfSpace:
        ...
    
    def GetSectorAngleType(self: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.SectorAngleType:
        ...
    
    def GetVariableName(self: MSPyMstnPlatform.Dimension2dData) -> MSPyBentley.WString:
        """
        @description Get variable name
        
        Returns:
        A WString reference to the variable name
        """
        ...
    
    @property
    def HalfSpace1(arg0: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.DimensionHalfSpace:
        ...
    @HalfSpace1.setter
    def HalfSpace1(arg0: MSPyMstnPlatform.Dimension2dData, arg1: MSPyMstnPlatform.DimensionHalfSpace) -> None:
        ...
    
    @property
    def HalfSpace2(arg0: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.DimensionHalfSpace:
        ...
    @HalfSpace2.setter
    def HalfSpace2(arg0: MSPyMstnPlatform.Dimension2dData, arg1: MSPyMstnPlatform.DimensionHalfSpace) -> None:
        ...
    
    @property
    def SectorAngleType(arg0: MSPyMstnPlatform.Dimension2dData) -> MSPyMstnPlatform.SectorAngleType:
        ...
    @SectorAngleType.setter
    def SectorAngleType(arg0: MSPyMstnPlatform.Dimension2dData, arg1: MSPyMstnPlatform.SectorAngleType) -> None:
        ...
    
    def SetAngleSectorIndex(self: MSPyMstnPlatform.Dimension2dData, sectorIndex: int) -> None:
        ...
    
    def SetConstraintStatus(self: MSPyMstnPlatform.Constraint2dData, status: MSPyMstnPlatform.Constraint2dStatus) -> None:
        """
        @description Set the constraint status
        
        Parameter ``status``:
        A new constraint status to set
        """
        ...
    
    def SetConstraintType(self: MSPyMstnPlatform.Constraint2dData, type: MSPyMstnPlatform.Constraint2dType) -> None:
        """
        @description Set the constraint type
        
        Parameter ``type``:
        The constraint type
        """
        ...
    
    def SetDiaType(self: MSPyMstnPlatform.Dimension2dData, value: int) -> None:
        ...
    
    def SetDimensionAlignmentType(self: MSPyMstnPlatform.Dimension2dData, type: MSPyMstnPlatform.DimensionAlignmentType) -> None:
        ...
    
    def SetDimensionFraction(self: MSPyMstnPlatform.Dimension2dData, value: float) -> None:
        ...
    
    def SetDimensionHeight(self: MSPyMstnPlatform.Dimension2dData, value: float) -> None:
        ...
    
    def SetDimensionValue(self: MSPyMstnPlatform.Dimension2dData, value: float) -> None:
        """
        @description Set a new dimension value
        
        Parameter ``value``:
        A new dimension value to set
        """
        ...
    
    def SetDimensionXOffset(self: MSPyMstnPlatform.Dimension2dData, value: float) -> None:
        ...
    
    def SetHalfSpace1(self: MSPyMstnPlatform.Dimension2dData, halfSpace: MSPyMstnPlatform.DimensionHalfSpace) -> None:
        ...
    
    def SetHalfSpace2(self: MSPyMstnPlatform.Dimension2dData, halfSpace: MSPyMstnPlatform.DimensionHalfSpace) -> None:
        ...
    
    def SetSectorAngleType(self: MSPyMstnPlatform.Dimension2dData, type: MSPyMstnPlatform.SectorAngleType) -> None:
        ...
    
    def SetVariableName(self: MSPyMstnPlatform.Dimension2dData, name: MSPyBentley.WString) -> None:
        """
        @description Set variable name
        
        Parameter ``name``:
        Variable name
        """
        ...
    
    @property
    def VariableName(arg0: MSPyMstnPlatform.Dimension2dData) -> MSPyBentley.WString:
        ...
    @VariableName.setter
    def VariableName(arg0: MSPyMstnPlatform.Dimension2dData, arg1: MSPyBentley.WString) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.Dimension2dData) -> None
        
        2. __init__(self: MSPyMstnPlatform.Dimension2dData, constraintType: MSPyMstnPlatform.Constraint2dType) -> None
        """
        ...
    
class Dimension3dBase:
    """
    None
    """

    def Create(*args, **kwargs):
        """
        Overloaded function.
        
        1. Create(type: MSPyMstnPlatform.Constraint3dType) -> MSPyMstnPlatform.Constraint3dBase
        
        2. Create(type: MSPyMstnPlatform.Constraint3dType, geometryIds: MSPyMstnPlatform.GeometryIdPtrArray, flags: int) -> MSPyMstnPlatform.Constraint3dBase
        """
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_SurfaceOrientation
        
        eFlagMask_GroupLock
        
        eFlagMask_HalfSpace1
        
        eFlagMask_HalfSpace2
        """
    
        def __init__(self: MSPyMstnPlatform.Constraint3dBase.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_GroupLock: FlagMasks
        
        eFlagMask_HalfSpace1: FlagMasks
        
        eFlagMask_HalfSpace2: FlagMasks
        
        eFlagMask_SurfaceOrientation: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.Constraint3dBase.FlagMasks) -> int:
            ...
        
    @property
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    @Flags.setter
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: int) -> None:
        ...
    
    def GetElementRefs(*args, **kwargs):
        """
        GetElementRefs(self: MSPyMstnPlatform.Constraint3dBase, elemRefs: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >) -> None
        """
        ...
    
    def GetFlags(self: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    
    def GetGroupLock(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def GetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.Constraint3dBase, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    
    def GetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    
    def GetType(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    @property
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    @GroupLock.setter
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: bool) -> None:
        ...
    
    @property
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace1.setter
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    @property
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace2.setter
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def HasBoundVariable(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def HasElementRef(self: MSPyMstnPlatform.Constraint3dBase, elemRef: MSPyDgnPlatform.ElementRefBase) -> bool:
        ...
    
    def IsRedundant(self: MSPyMstnPlatform.Constraint3dBase, other: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def SetFlags(self: MSPyMstnPlatform.Constraint3dBase, flags: int) -> None:
        ...
    
    def SetGeometryIds(self: MSPyMstnPlatform.Constraint3dBase, geometryIds: MSPyMstnPlatform.GeometryIdPtrArray) -> None:
        ...
    
    def SetGroupLock(self: MSPyMstnPlatform.Constraint3dBase, groupLock: bool) -> None:
        ...
    
    def SetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.Constraint3dBase, status: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    def SetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase, orientation: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    @property
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    @SurfaceOrientation.setter
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eDCM3_D_BETWEEN_FIXED: Status
    
    eDCM3_D_BETWEEN_SET_MEMBERS: Status
    
    eDCM3_D_NOT_CHANGED: Status
    
    eDCM3_D_NOT_CONSISTENT: Status
    
    eDCM3_D_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_D_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_D_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_D_NOT_SOLVED: Status
    
    eDCM3_D_OVER_DEFINED: Status
    
    eDCM3_D_SOLVED: Status
    
    eDCM3_D_UNKNOWN: Status
    
    eFlagMask_GroupLock: FlagMasks
    
    eFlagMask_HalfSpace1: FlagMasks
    
    eFlagMask_HalfSpace2: FlagMasks
    
    eFlagMask_SurfaceOrientation: FlagMasks
    
    eRedundant: Status
    
class DimensionAlignmentType:
    """
    Members:
    
    eDimAlign_Unknown
    
    eDimAlign_Drawing_X
    
    eDimAlign_Drawing_X_Reversed
    
    eDimAlign_Drawing_Y
    
    eDimAlign_Drawing_Y_Reversed
    """

    def __init__(self: MSPyMstnPlatform.DimensionAlignmentType, value: int) -> None:
        ...
    
    eDimAlign_Drawing_X: DimensionAlignmentType
    
    eDimAlign_Drawing_X_Reversed: DimensionAlignmentType
    
    eDimAlign_Drawing_Y: DimensionAlignmentType
    
    eDimAlign_Drawing_Y_Reversed: DimensionAlignmentType
    
    eDimAlign_Unknown: DimensionAlignmentType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.DimensionAlignmentType) -> int:
        ...
    
class DimensionHalfSpace:
    """
    Members:
    
    eUnspecified
    
    eLeft
    
    eRight
    """

    def __init__(self: MSPyMstnPlatform.DimensionHalfSpace, value: int) -> None:
        ...
    
    eLeft: DimensionHalfSpace
    
    eRight: DimensionHalfSpace
    
    eUnspecified: DimensionHalfSpace
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.DimensionHalfSpace) -> int:
        ...
    
class DistanceDimension3d:
    """
    None
    """

    @staticmethod
    def Create(geometryIds: MSPyMstnPlatform.GeometryIdPtrArray, flags: int, value: float, variableAccess: MSPyBentley.WString) -> MSPyMstnPlatform.Constraint3dBase:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_SurfaceOrientation
        
        eFlagMask_GroupLock
        
        eFlagMask_HalfSpace1
        
        eFlagMask_HalfSpace2
        """
    
        def __init__(self: MSPyMstnPlatform.Constraint3dBase.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_GroupLock: FlagMasks
        
        eFlagMask_HalfSpace1: FlagMasks
        
        eFlagMask_HalfSpace2: FlagMasks
        
        eFlagMask_SurfaceOrientation: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.Constraint3dBase.FlagMasks) -> int:
            ...
        
    @property
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    @Flags.setter
    def Flags(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: int) -> None:
        ...
    
    def GetElementRefs(*args, **kwargs):
        """
        GetElementRefs(self: MSPyMstnPlatform.Constraint3dBase, elemRefs: Bentley.bset<Bentley.DgnPlatform.ElementRefBase * __ptr64,std.less<Bentley.DgnPlatform.ElementRefBase * __ptr64>,32,Bentley.BentleyAllocator<Bentley.DgnPlatform.ElementRefBase * __ptr64> >) -> None
        """
        ...
    
    def GetFlags(self: MSPyMstnPlatform.Constraint3dBase) -> int:
        ...
    
    def GetGroupLock(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def GetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.Constraint3dBase, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    
    def GetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    
    def GetType(self: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    @property
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    @GroupLock.setter
    def GroupLock(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: bool) -> None:
        ...
    
    @property
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace1.setter
    def HalfSpace1(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    @property
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dHalfSpace:
        ...
    @HalfSpace2.setter
    def HalfSpace2(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def HasBoundVariable(self: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def HasElementRef(self: MSPyMstnPlatform.Constraint3dBase, elemRef: MSPyDgnPlatform.ElementRefBase) -> bool:
        ...
    
    def IsRedundant(self: MSPyMstnPlatform.Constraint3dBase, other: MSPyMstnPlatform.Constraint3dBase) -> bool:
        ...
    
    def SetFlags(self: MSPyMstnPlatform.Constraint3dBase, flags: int) -> None:
        ...
    
    def SetGeometryIds(self: MSPyMstnPlatform.Constraint3dBase, geometryIds: MSPyMstnPlatform.GeometryIdPtrArray) -> None:
        ...
    
    def SetGroupLock(self: MSPyMstnPlatform.Constraint3dBase, groupLock: bool) -> None:
        ...
    
    def SetHalfSpace1(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetHalfSpace2(self: MSPyMstnPlatform.Constraint3dBase, halfSpace: MSPyMstnPlatform.Constraint3dHalfSpace) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.Constraint3dBase, status: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    def SetSurfaceOrientation(self: MSPyMstnPlatform.Constraint3dBase, orientation: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dBase.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.Constraint3dBase.Status) -> None:
        ...
    
    @property
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.SurfaceOrientation:
        ...
    @SurfaceOrientation.setter
    def SurfaceOrientation(arg0: MSPyMstnPlatform.Constraint3dBase, arg1: MSPyMstnPlatform.SurfaceOrientation) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.Constraint3dBase) -> MSPyMstnPlatform.Constraint3dType:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eDCM3_D_BETWEEN_FIXED: Status
    
    eDCM3_D_BETWEEN_SET_MEMBERS: Status
    
    eDCM3_D_NOT_CHANGED: Status
    
    eDCM3_D_NOT_CONSISTENT: Status
    
    eDCM3_D_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_D_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_D_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_D_NOT_SOLVED: Status
    
    eDCM3_D_OVER_DEFINED: Status
    
    eDCM3_D_SOLVED: Status
    
    eDCM3_D_UNKNOWN: Status
    
    eFlagMask_GroupLock: FlagMasks
    
    eFlagMask_HalfSpace1: FlagMasks
    
    eFlagMask_HalfSpace2: FlagMasks
    
    eFlagMask_SurfaceOrientation: FlagMasks
    
    eRedundant: Status
    
class Drag2dInfo:
    """
    None
    """

    def Clear(self: MSPyMstnPlatform.Drag2dInfo) -> None:
        ...
    
    @property
    def CurveEntityIdentifier(arg0: MSPyMstnPlatform.Drag2dInfo) -> MSPyMstnPlatform.CurveEntityIdentifier:
        ...
    @CurveEntityIdentifier.setter
    def CurveEntityIdentifier(arg0: MSPyMstnPlatform.Drag2dInfo, arg1: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        ...
    
    @property
    def DraggingTransform(arg0: MSPyMstnPlatform.Drag2dInfo) -> MSPyMstnPlatform.DragTransformType:
        ...
    @DraggingTransform.setter
    def DraggingTransform(arg0: MSPyMstnPlatform.Drag2dInfo, arg1: MSPyMstnPlatform.DragTransformType) -> None:
        ...
    
    def GetCurveEntityIdentifier(self: MSPyMstnPlatform.Drag2dInfo) -> MSPyMstnPlatform.CurveEntityIdentifier:
        """
        @description Get curve identifier
        
        Returns:
        Curve identifier
        """
        ...
    
    def GetDraggingTransform(self: MSPyMstnPlatform.Drag2dInfo) -> MSPyMstnPlatform.DragTransformType:
        """
        @description Get dragging transform type
        
        Returns:
        Dragging transform type
        """
        ...
    
    def GetMoveValue(self: MSPyMstnPlatform.Drag2dInfo) -> MSPyBentleyGeom.DVec3d:
        """
        @description Get moving value
        
        Returns:
        A vector representing the moving value.
        """
        ...
    
    def GetRadius(self: MSPyMstnPlatform.Drag2dInfo) -> float:
        """
        @description Get radius
        
        Returns:
        Radius value
        """
        ...
    
    @property
    def MoveValue(arg0: MSPyMstnPlatform.Drag2dInfo) -> MSPyBentleyGeom.DVec3d:
        ...
    @MoveValue.setter
    def MoveValue(arg0: MSPyMstnPlatform.Drag2dInfo, arg1: MSPyBentleyGeom.DVec3d) -> None:
        ...
    
    @property
    def Radius(arg0: MSPyMstnPlatform.Drag2dInfo) -> float:
        ...
    @Radius.setter
    def Radius(arg0: MSPyMstnPlatform.Drag2dInfo, arg1: float) -> None:
        ...
    
    def SetCurveEntityIdentifier(self: MSPyMstnPlatform.Drag2dInfo, identifier: MSPyMstnPlatform.CurveEntityIdentifier) -> None:
        """
        @description Set curve identifier
        
        Parameter ``identifer``:
        Curve identifier
        """
        ...
    
    def SetDraggingTransform(self: MSPyMstnPlatform.Drag2dInfo, transformType: MSPyMstnPlatform.DragTransformType) -> None:
        """
        @description Set dragging transform type
        
        Parameter ``transformType``:
        Dragging transform type
        """
        ...
    
    def SetMoveValue(self: MSPyMstnPlatform.Drag2dInfo, value: MSPyBentleyGeom.DVec3d) -> None:
        """
        @description Set moving value
        
        Parameter ``value``:
        Moving value
        """
        ...
    
    def SetRadius(self: MSPyMstnPlatform.Drag2dInfo, radius: float) -> None:
        """
        @description Set radius
        
        Parameter ``radius``:
        Radius
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.Drag2dInfo) -> None
        
        2. __init__(self: MSPyMstnPlatform.Drag2dInfo, identifier: MSPyMstnPlatform.CurveEntityIdentifier, transformType: MSPyMstnPlatform.DragTransformType = <DragTransformType.eTranslation: 1>) -> None
        """
        ...
    
class DragTransformType:
    """
    Members:
    
    eGeneral
    
    eTranslation
    
    eRadius
    
    eMajor_Radius
    
    eMinor_Radius
    
    eOffset_Distance
    """

    def __init__(self: MSPyMstnPlatform.DragTransformType, value: int) -> None:
        ...
    
    eGeneral: DragTransformType
    
    eMajor_Radius: DragTransformType
    
    eMinor_Radius: DragTransformType
    
    eOffset_Distance: DragTransformType
    
    eRadius: DragTransformType
    
    eTranslation: DragTransformType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.DragTransformType) -> int:
        ...
    
class EdgeArcAxisGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, edgeId: MSPyBentleyGeom.EdgeId) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class EdgeGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class ElementPropertyUtils:
    """
    None
    """

    @staticmethod
    def ApplyActiveAreaFill(eeh: MSPyDgnPlatform.EditElementHandle, fillMode: int) -> bool:
        """
        Apply the active solid or gradient fill to the supplied element.
        
        Parameter ``eeh``:
        The element to modify.
        
        Parameter ``fillMode``:
        0 = none, 1 = opaque fill, -1 to use the active fill settings.
        
        Returns:
        true if element was updated.
        
        See also:
        AddSolidFill AddGradientFill Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def ApplyActiveAreaSettings(eeh: MSPyDgnPlatform.EditElementHandle, fillMode: int) -> None:
        """
        Update the supplied element to the current active fill and area
        settings using IAreaFillPropertiesEdit. @note:Does nothing if model
        of EditElementHandle is not ACTIVEMODEL. *
        
        Remark:
        """
        ...
    
    @staticmethod
    def ApplyActiveGradientFill(eeh: MSPyDgnPlatform.EditElementHandle) -> bool:
        """
        Apply the active gradient fill to the supplied element.
        
        Parameter ``eeh``:
        The element to modify.
        
        Returns:
        true if element was updated.
        
        See also:
        AddGradientFill Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def ApplyActivePattern(eeh: MSPyDgnPlatform.EditElementHandle, params: MSPyDgnPlatform.PatternParams, hatchDefLines: MSPyDgnPlatform.DwgHatchDefLine, option: int, origin: MSPyBentleyGeom.DPoint3d, rMatrix: MSPyBentleyGeom.RotMatrix, line1: int, line2: int, index: int = 0) -> bool:
        """
        Apply the active pattern type and settings to the supplied element.
        
        Parameter ``eeh``:
        The element to modify.
        
        Parameter ``paramsP``:
        pattern params or NULL.
        
        Parameter ``hatchDefLinesP``:
        DWG hatch definition or NULL.
        
        Parameter ``option``:
        pattern type:PATTERN_HATCH, PATTERN_CROSSHATCH, or PATTERN_AREA,
        used if paramsP is NULL.
        
        Parameter ``originP``:
        pattern origin or NULL.
        
        Parameter ``rMatrix``:
        pattern rotation or NULL.
        
        Parameter ``line1``:
        Multiline specific profile index if patterning between specific
        profile lines.
        
        Parameter ``line2``:
        Multiline specific profile index if patterning between specific
        profile lines.
        
        Parameter ``index``:
        Pattern index (only for multilines).
        
        Returns:
        true if element was updated.
        
        See also:
        AddPattern Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def ApplyActiveSettings(eeh: MSPyDgnPlatform.EditElementHandle) -> None:
        """
        Update the supplied element to the current active settings. Sets
        level, color, style, weight, class, transparency, and display priority
        (2d only). @note:Does nothing if model of EditElementHandle is not
        ACTIVEMODEL. *
        
        Remark:
        """
        ...
    
    @staticmethod
    def ApplyActiveSolidFill(eeh: MSPyDgnPlatform.EditElementHandle) -> bool:
        """
        Apply the active solid fill to the supplied element.
        
        Parameter ``eeh``:
        The element to modify.
        
        Returns:
        true if element was updated.
        
        See also:
        AddSolidFill Bentley Systems
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ExtrudeAlongProfileSetting:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.ExtrudeAlongProfileSetting) -> None
        
        2. __init__(self: MSPyMstnPlatform.ExtrudeAlongProfileSetting, dgnModel: MSPyDgnPlatform.DgnModel) -> None
        """
        ...
    
class ExtrudeSettings:
    """
    None
    """

    def SetDistance(self: MSPyMstnPlatform.ExtrudeSettings, distance: float) -> None:
        ...
    
    def SetSpinAngle(self: MSPyMstnPlatform.ExtrudeSettings, spinAngle: float) -> None:
        ...
    
    def SetThickness(self: MSPyMstnPlatform.ExtrudeSettings, thickness: float) -> None:
        ...
    
    def SetXScale(self: MSPyMstnPlatform.ExtrudeSettings, scale: float) -> None:
        ...
    
    def SetYScale(self: MSPyMstnPlatform.ExtrudeSettings, scale: float) -> None:
        ...
    
    def Validate(self: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.ExtrudeSettings) -> None
        
        2. __init__(self: MSPyMstnPlatform.ExtrudeSettings, hitPoint: MSPyBentleyGeom.DPoint3d, createSheet: bool, skewed: bool, distance: Optional[float], xScale: float, yScale: float, spinAngle: float, bothWays: bool, thicknessMode: int, thickness: float, ev: MSPyDgnView.DgnButtonEvent, curveVector: MSPyBentleyGeom.CurveVector) -> None
        
        3. __init__(self: MSPyMstnPlatform.ExtrudeSettings, hitPoint: MSPyBentleyGeom.DPoint3d, createSheet: bool, skewed: bool, distance: Optional[float], xScale: float, yScale: float, spinAngle: float, bothWays: bool, thicknessMode: int, thickness: float, origin: MSPyBentleyGeom.DPoint3d, vp: MSPyDgnPlatform.Viewport, curveVector: MSPyBentleyGeom.CurveVector) -> None
        """
        ...
    
    @property
    def basePoint(self: MSPyMstnPlatform.ExtrudeSettings) -> MSPyBentleyGeom.DPoint3d:
        ...
    @basePoint.setter
    def basePoint(self: MSPyMstnPlatform.ExtrudeSettings, arg0: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @property
    def basePresent(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @basePresent.setter
    def basePresent(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def bothWays(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @bothWays.setter
    def bothWays(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def createSheet(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @createSheet.setter
    def createSheet(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def distance(self: MSPyMstnPlatform.ExtrudeSettings) -> float:
        ...
    @distance.setter
    def distance(self: MSPyMstnPlatform.ExtrudeSettings, arg0: float) -> None:
        ...
    
    @property
    def doScale(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @doScale.setter
    def doScale(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def doSkew(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @doSkew.setter
    def doSkew(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def doSpin(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @doSpin.setter
    def doSpin(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def isNormalized(arg0: MSPyMstnPlatform.ExtrudeSettings) -> bool:
        ...
    @isNormalized.setter
    def isNormalized(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: bool) -> None:
        ...
    
    @property
    def normal(self: MSPyMstnPlatform.ExtrudeSettings) -> MSPyBentleyGeom.DVec3d:
        ...
    @normal.setter
    def normal(self: MSPyMstnPlatform.ExtrudeSettings, arg0: MSPyBentleyGeom.DVec3d) -> None:
        ...
    
    @property
    def spinAngle(self: MSPyMstnPlatform.ExtrudeSettings) -> float:
        ...
    @spinAngle.setter
    def spinAngle(self: MSPyMstnPlatform.ExtrudeSettings, arg0: float) -> None:
        ...
    
    @property
    def thickness(self: MSPyMstnPlatform.ExtrudeSettings) -> float:
        ...
    @thickness.setter
    def thickness(self: MSPyMstnPlatform.ExtrudeSettings, arg0: float) -> None:
        ...
    
    @property
    def thicknessMode(arg0: MSPyMstnPlatform.ExtrudeSettings) -> int:
        ...
    @thicknessMode.setter
    def thicknessMode(arg0: MSPyMstnPlatform.ExtrudeSettings, arg1: int) -> None:
        ...
    
    @property
    def xScale(self: MSPyMstnPlatform.ExtrudeSettings) -> float:
        ...
    @xScale.setter
    def xScale(self: MSPyMstnPlatform.ExtrudeSettings, arg0: float) -> None:
        ...
    
    @property
    def yScale(self: MSPyMstnPlatform.ExtrudeSettings) -> float:
        ...
    @yScale.setter
    def yScale(self: MSPyMstnPlatform.ExtrudeSettings, arg0: float) -> None:
        ...
    
class FaceAxisGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, faceId: MSPyBentleyGeom.FaceId) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class FaceGeometryId:
    """
    None
    """

    @staticmethod
    def Create(eh: MSPyDgnPlatform.ElementHandle, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyMstnPlatform.GeometryId:
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class FeatureCreate:
    """
    None
    """

    @staticmethod
    def CreateBlendFeature(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateBlendFeature(edges: MSPyBentleyGeom.EdgeIdArray, radius: float, isSmooth: bool) -> MSPyMstnPlatform.SmartFeatureNode
        
        Obsoleted! Please use the another API named as CreateBlendFeature()
        from this class itself.
        
        2. CreateBlendFeature(edges: MSPyDgnPlatform.ISubEntityPtrArray, radius: float, propogateSmooth: bool) -> tuple
        
        Obsoleted! Please use the another API named as CreateBlendFeature()
        from this class itself.
        """
        ...
    
    @staticmethod
    def CreateChamferFeature(edges: MSPyDgnPlatform.ISubEntityPtrArray, settings: MSPyMstnPlatform.ChamferEdgeSettings) -> tuple:
        """
        Obsoleted! Please use the another API named as CreateChamferFeature()
        from this class itself.
        """
        ...
    
    @staticmethod
    def CreateCutFeature(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateCutFeature(depthMode: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode, directionMode: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode, outsideProfile: bool, depth: float, defaultNormal: MSPyBentleyGeom.DVec3d) -> tuple
        
        Create Cut Smart Feature node
        
        Parameter ``cutNode``:
        Newly created cut feature node
        
        Parameter ``depthMode``:
        Various depth options
        
        Parameter ``directionMode``:
        The cut direction
        
        Parameter ``outsideProfile``:
        With respect to profile
        
        Parameter ``depth``:
        Depth distance (not applicable for depthMode = ALL.
        
        Parameter ``defaultNormal``:
        The normal
        
        Returns:
        SUCCESS if Cut creation is successful
        
        2. CreateCutFeature(depthMode: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode, directionMode: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode, outsideProfile: bool, depth: float, defaultNormal: MSPyBentleyGeom.DVec3d, cutDirection: MSPyBentleyGeom.DVec3d) -> tuple
        
        Create Cut Smart Feature node
        
        Parameter ``cutNode``:
        Newly created cut feature node
        
        Parameter ``depthMode``:
        Various depth options
        
        Parameter ``directionMode``:
        The cut direction
        
        Parameter ``outsideProfile``:
        With respect to profile
        
        Parameter ``depth``:
        Depth distance (not applicable for depthMode = ALL.
        
        Parameter ``defaultNormal``:
        The normal
        
        Returns:
        SUCCESS if Cut creation is successful
        """
        ...
    
    @staticmethod
    def CreateDifferenceFeature(subtractionPoint: MSPyBentleyGeom.DPoint3d = None) -> tuple:
        """
        Create Boolean-Difference Smart Feature node
        
        Parameter ``booleanNode``:
        Difference feature node
        
        Parameter ``subtractionPoint``:
        Subtraction point. The default argument with nullptr value
        
        Returns:
        SUCCESS if feature is created successfully
        """
        ...
    
    @staticmethod
    def CreateExtrudeAlongFeature(lockDirection: MSPyBentleyGeom.DVec3d, scalePoint: MSPyBentleyGeom.DPoint3d, settings: Bentley.DgnPlatform.SmartFeature.ExtrudeAlongSettings, createSheet: bool) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Create Extrude Along Smart Feature node
        
        Parameter ``lockDirection``:
        If profile orientation needs to be locked in particular direction.
        
        Parameter ``scalePoint``:
        If extrusion needs scaling about some input point. Please refer
        the structure ExtrudeAlongSetting. User need to specify m_doscale
        and m_scale value in it.
        
        Parameter ``settings``:
        Extrude along setting used to generatate extrusion
        
        Parameter ``createSheet``:
        If true extrusion output will be sheet body in case of false it
        will be solid body.
        
        Returns:
        successfully created ExtrudeAlong parametric feature
        """
        ...
    
    @staticmethod
    def CreateExtrudeFeature(settings: MSPyMstnPlatform.ExtrudeSettings) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Create Extrude parametric Feature.
        
        Parameter ``settings``:
        Input data for Extrude creation
        
        Returns:
        Extrude feature node
        """
        ...
    
    @staticmethod
    def CreateIntersectionFeature() -> tuple:
        """
        Create Boolean-Intersection Smart Feature node
        
        Parameter ``booleanNode``:
        Intersection feature node
        
        Returns:
        SUCCESS if feature is created successfully
        """
        ...
    
    @staticmethod
    def CreateRevolveFeature(settings: MSPyMstnPlatform.RevolveSettings) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Create Revolve parametric Feature.
        
        Parameter ``settings``:
        Input data for Revolve creation
        
        Returns:
        Revolve feature node
        """
        ...
    
    @staticmethod
    def CreateSizeFilter(settings: Bentley.DgnPlatform.SmartFeature.SizeFilterSettings) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Create Size Filter Smart Feature Node.
        
        Parameter ``settings``:
        Input data for Size Filter creation.
        
        Returns:
        Size Filter feature node
        """
        ...
    
    @staticmethod
    def CreateSolidNode(eh: MSPyDgnPlatform.ElementHandle) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Create Parametric Solid Node
        
        Parameter ``Input``:
        element expected to be of type smart solid. Application need to
        ensure that element handle should of type smart solid
        
        Returns:
        Solid feature node
        """
        ...
    
    @staticmethod
    def CreateTrimFeature(face: MSPyDgnPlatform.ISubEntity) -> tuple:
        """
        Create Trim Smart Feature node
        
        Parameter ``trimNode``:
        Trim feature node
        
        Parameter ``face``:
        Face to trim from
        
        Returns:
        SUCCESS if feature is created successfully
        """
        ...
    
    @staticmethod
    def CreateUnionFeature() -> tuple:
        """
        Create Boolean-Union Smart Feature node
        
        Parameter ``booleanNode``:
        Union feature node
        
        Returns:
        SUCCESS if feature is created successfully
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class FileListAttr:
    """
    Members:
    
    eOPEN
    
    eCREATE
    
    eCREATEFROMSEED
    
    eOPENCREATE
    
    eDEFAULT
    """

    def __init__(self: MSPyMstnPlatform.FileListAttr, value: int) -> None:
        ...
    
    eCREATE: FileListAttr
    
    eCREATEFROMSEED: FileListAttr
    
    eDEFAULT: FileListAttr
    
    eOPEN: FileListAttr
    
    eOPENCREATE: FileListAttr
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.FileListAttr) -> int:
        ...
    
class FileOpenExtAttr:
    """
    Members:
    
    eNONE
    
    eCENTERONSCREEN
    
    eDONTDEFAULTTODEFFILE
    """

    def __init__(self: MSPyMstnPlatform.FileOpenExtAttr, value: int) -> None:
        ...
    
    eCENTERONSCREEN: FileOpenExtAttr
    
    eDONTDEFAULTTODEFFILE: FileOpenExtAttr
    
    eNONE: FileOpenExtAttr
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.FileOpenExtAttr) -> int:
        ...
    
class GeometryId:
    """
    None
    """

    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class GeometryIdPtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.GeometryIdPtrArray) -> None
        
        2. __init__(self: MSPyMstnPlatform.GeometryIdPtrArray, arg0: MSPyMstnPlatform.GeometryIdPtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyMstnPlatform.GeometryIdPtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyMstnPlatform.GeometryIdPtrArray, x: MSPyMstnPlatform.GeometryId) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyMstnPlatform.GeometryIdPtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyMstnPlatform.GeometryIdPtrArray, x: MSPyMstnPlatform.GeometryId) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyMstnPlatform.GeometryIdPtrArray, L: MSPyMstnPlatform.GeometryIdPtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyMstnPlatform.GeometryIdPtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyMstnPlatform.GeometryIdPtrArray, i: int, x: MSPyMstnPlatform.GeometryId) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyMstnPlatform.GeometryIdPtrArray) -> MSPyMstnPlatform.GeometryId
        
        Remove and return the last item
        
        2. pop(self: MSPyMstnPlatform.GeometryIdPtrArray, i: int) -> MSPyMstnPlatform.GeometryId
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyMstnPlatform.GeometryIdPtrArray, x: MSPyMstnPlatform.GeometryId) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class GlobalPositionData:
    """
    None
    """

    @property
    def HDOP(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @HDOP.setter
    def HDOP(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    @property
    def PDOP(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @PDOP.setter
    def PDOP(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    @property
    def UTCTicks(self: MSPyMstnPlatform.GlobalPositionData) -> int:
        ...
    @UTCTicks.setter
    def UTCTicks(self: MSPyMstnPlatform.GlobalPositionData, arg0: int) -> None:
        ...
    
    @property
    def VDOP(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @VDOP.setter
    def VDOP(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    def __init__(self: MSPyMstnPlatform.GlobalPositionData) -> None:
        ...
    
    @property
    def elevation(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @elevation.setter
    def elevation(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    @property
    def fixDimension(self: MSPyMstnPlatform.GlobalPositionData) -> int:
        ...
    @fixDimension.setter
    def fixDimension(self: MSPyMstnPlatform.GlobalPositionData, arg0: int) -> None:
        ...
    
    @property
    def heading(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @heading.setter
    def heading(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    @property
    def latitude(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @latitude.setter
    def latitude(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    @property
    def longitude(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @longitude.setter
    def longitude(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
    @property
    def velocity(self: MSPyMstnPlatform.GlobalPositionData) -> float:
        ...
    @velocity.setter
    def velocity(self: MSPyMstnPlatform.GlobalPositionData, arg0: float) -> None:
        ...
    
class GraphicsFileType:
    """
    Members:
    
    eGRAPHICSFILE_WildCard
    
    eGRAPHICSFILE_UStn
    
    eGRAPHICSFILE_Sheet
    
    eGRAPHICSFILE_HLine
    
    eGRAPHICSFILE_DWG
    
    eGRAPHICSFILE_DXF
    
    eGRAPHICSFILE_DXB
    
    eGRAPHICSFILE_IGES
    
    eGRAPHICSFILE_CGM
    
    eGRAPHICSFILE_RDL
    
    eGRAPHICSFILE_TriForma
    
    eGRAPHICSFILE_UStnV7
    
    eGRAPHICSFILE_CAD
    
    eGRAPHICSFILE_CEL
    
    eGRAPHICSFILE_3DStudio
    
    eGRAPHICSFILE_DgnLib
    
    eGRAPHICSFILE_OBJ
    
    eGRAPHICSFILE_SKP
    """

    def __init__(self: MSPyMstnPlatform.GraphicsFileType, value: int) -> None:
        ...
    
    eGRAPHICSFILE_3DStudio: GraphicsFileType
    
    eGRAPHICSFILE_CAD: GraphicsFileType
    
    eGRAPHICSFILE_CEL: GraphicsFileType
    
    eGRAPHICSFILE_CGM: GraphicsFileType
    
    eGRAPHICSFILE_DWG: GraphicsFileType
    
    eGRAPHICSFILE_DXB: GraphicsFileType
    
    eGRAPHICSFILE_DXF: GraphicsFileType
    
    eGRAPHICSFILE_DgnLib: GraphicsFileType
    
    eGRAPHICSFILE_HLine: GraphicsFileType
    
    eGRAPHICSFILE_IGES: GraphicsFileType
    
    eGRAPHICSFILE_OBJ: GraphicsFileType
    
    eGRAPHICSFILE_RDL: GraphicsFileType
    
    eGRAPHICSFILE_SKP: GraphicsFileType
    
    eGRAPHICSFILE_Sheet: GraphicsFileType
    
    eGRAPHICSFILE_TriForma: GraphicsFileType
    
    eGRAPHICSFILE_UStn: GraphicsFileType
    
    eGRAPHICSFILE_UStnV7: GraphicsFileType
    
    eGRAPHICSFILE_WildCard: GraphicsFileType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.GraphicsFileType) -> int:
        ...
    
class IBeginPrintPageParam:
    """
    None
    """

    def GetIsPartOfPrintSet(self: MSPyMstnPlatform.IBeginPrintPageParam) -> bool:
        ...
    
    def GetIsPreview(self: MSPyMstnPlatform.IBeginPrintPageParam) -> bool:
        ...
    
    def GetPrintEngine(self: MSPyMstnPlatform.IBeginPrintPageParam) -> Bentley.MstnPlatform.Print.IPrintEngine:
        ...
    
    def GetPrintEnginePlotter(self: MSPyMstnPlatform.IBeginPrintPageParam) -> Bentley.MstnPlatform.Print.IPlotter:
        ...
    
    def __init__(self: MSPyMstnPlatform.IBeginPrintPageParam) -> None:
        ...
    
class IClashData:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IEndPrintPageParam:
    """
    None
    """

    def GetIsPartOfPrintSet(self: MSPyMstnPlatform.IEndPrintPageParam) -> bool:
        ...
    
    def GetIsPreview(self: MSPyMstnPlatform.IEndPrintPageParam) -> bool:
        ...
    
    def GetIsSuccess(self: MSPyMstnPlatform.IEndPrintPageParam) -> bool:
        ...
    
    def GetPrintEngine(self: MSPyMstnPlatform.IEndPrintPageParam) -> Bentley.MstnPlatform.Print.IPrintEngine:
        ...
    
    def GetPrintEnginePlotter(self: MSPyMstnPlatform.IEndPrintPageParam) -> Bentley.MstnPlatform.Print.IPlotter:
        ...
    
    def __init__(self: MSPyMstnPlatform.IEndPrintPageParam) -> None:
        ...
    
class IEventHandlerPrioritized:
    """
    None
    """

    def __init__(self: MSPyMstnPlatform.IEventHandlerPrioritized) -> None:
        ...
    
class IGlobalPositionSource:
    """
    None
    """

    def GPSAvailable(self: MSPyMstnPlatform.IGlobalPositionSource) -> bool:
        ...
    
    @staticmethod
    def GetGlobalPositionSource() -> MSPyMstnPlatform.IGlobalPositionSource:
        ...
    
    def GetLatestPositionData(self: MSPyMstnPlatform.IGlobalPositionSource, data: MSPyMstnPlatform.GlobalPositionData) -> int:
        ...
    
    def __init__(self: MSPyMstnPlatform.IGlobalPositionSource) -> None:
        ...
    
class IMouseWheelHandler:
    """
    None
    """

    def __init__(self: MSPyMstnPlatform.IMouseWheelHandler) -> None:
        ...
    
class IPopupMenuManager:
    """
    None
    """

    def AddTentativePopUpMenuProvider(self: MSPyMstnPlatform.IPopupMenuManager, provider: MSPyMstnPlatform.IPopupMenuProvider) -> None:
        """
        Remark:
        Required Library:mdlbltin.lib
        """
        ...
    
    def AddViewPopUpMenuProvider(self: MSPyMstnPlatform.IPopupMenuManager, provider: MSPyMstnPlatform.IPopupMenuProvider) -> None:
        """
        Remark:
        Required Library:mdlbltin.lib
        """
        ...
    
    def DropTentativePopUpMenuProvider(self: MSPyMstnPlatform.IPopupMenuManager, provider: MSPyMstnPlatform.IPopupMenuProvider) -> None:
        """
        Remark:
        Required Library:mdlbltin.lib
        """
        ...
    
    def DropViewPopUpMenuProvider(self: MSPyMstnPlatform.IPopupMenuManager, provider: MSPyMstnPlatform.IPopupMenuProvider) -> None:
        """
        Remark:
        Required Library:mdlbltin.lib
        """
        ...
    
    @staticmethod
    def GetManager() -> MSPyMstnPlatform.IPopupMenuManager:
        """
        Remark:
        Required Library:mdlbltin.lib
        """
        ...
    
    Manager: IPopupMenuManager
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IPopupMenuProvider:
    """
    None
    """

    def __init__(self: MSPyMstnPlatform.IPopupMenuProvider) -> None:
        ...
    
class IPrintEventHandler:
    """
    None
    """

    def BeginPrintPage(self: MSPyMstnPlatform.IPrintEventHandler, param: MSPyMstnPlatform.IBeginPrintPageParam) -> None:
        ...
    
    def EndPrintPage(self: MSPyMstnPlatform.IPrintEventHandler, param: MSPyMstnPlatform.IEndPrintPageParam) -> None:
        ...
    
    def __init__(self: MSPyMstnPlatform.IPrintEventHandler) -> None:
        ...
    
class IPyModalDialogEvents:
    """
    None
    """

    def OnDialogClosed(self: MSPyMstnPlatform.IPyModalDialogEvents, arg0: str, arg1: MSPyMstnPlatform.PyMsdDialogBoxResult) -> None:
        ...
    
    def OnDialogOpened(self: MSPyMstnPlatform.IPyModalDialogEvents, arg0: str) -> int:
        ...
    
    def __init__(self: MSPyMstnPlatform.IPyModalDialogEvents) -> None:
        ...
    
class ISessionMgr:
    """
    None
    """

    ActiveDgnFile: DgnFile
    
    ActiveDgnModel: DgnModel
    
    ActiveDgnModelRef: DgnModelRef
    
    @staticmethod
    def AddSessionMonitor(monitor: MSPyMstnPlatform.SessionMonitor) -> None:
        """
        Add a new SessionMonitor.
        
        Parameter ``mon``:
        the new SessionMonitor object. This object will be notified when
        session-related events occur until it is dropped using
        DropSessionMonitor. Ownership of the monitor object is *not*
        transferred to the SessionMgr. The caller must ensure this object
        remains valid until it is dropped.
        
        See also:
        DropSessionMonitor.
        """
        ...
    
    def CreateNewDgnFile(self: MSPyMstnPlatform.ISessionMgr, newName: MSPyBentley.WString, defaultDir: str, switchToNewFile: bool) -> int:
        """
        Prompts the user to create a new DGN file and then optionally makes it
        the Master DGN.
        
        Returns:
        SUCCESS if a file was created; otherwise, a non-zero error status
        if the user cancelled, or an error status code based on
        DGNOPEN_STATUS_BASE if the file creation failed.
        
        Parameter ``newName``:
        The file path of the newly created file if successful
        
        Parameter ``defaultDir``:
        Optional:The default directory.
        
        Parameter ``switchToNewFile``:
        Make the new file the Master DGN?
        
        Remark:
        s This function works with MSDocumentManager to locate and manage
        files. In stand-alone MicroStation, the default directory is
        _DGNDIR, if *defaultDir* is not specified. The default seed file
        is MS_DESIGNSEED or the previously selected seed file and the
        default seed file directory is MS_SEEDFILES.
        
        Remark:
        s If *switchToNewFile* is <code>true</code>, then this function
        will call #FindDesignFile (*allowCancel=<code>true</code>)*
        followed by #SwitchToNewFile.
        
        See also:
        SwitchToNewFile
        """
        ...
    
    @staticmethod
    def DropSessionMonitor(monitor: MSPyMstnPlatform.SessionMonitor) -> None:
        """
        Drop an existing SessionMonitor.
        
        Parameter ``mon``:
        the SessionMonitor object to remove and deactivate.
        
        Remark:
        s SessionMonitors are automatically removed when MDL applications
        are unloaded.
        
        See also:
        AddSessionMonitor.
        """
        ...
    
    def FindDesignFile(self: MSPyMstnPlatform.ISessionMgr, inFileName: str, inModelName: str, fileType: int, allowCancel: bool) -> tuple:
        """
        Opens a file from a specified file name or path.
        
        Parameter ``inFileName``:
        The name or path of the file to be opened.
        
        Parameter ``inModelName``:
        Will be non-NULL if a specific model will be opened.
        
        Parameter ``fileType``:
        The format of the file.
        
        Parameter ``allowCancel``:
        Pass <code>true</code> if MicroStation should prompt the user to
        accept or cancel if the file cannot be opened read-write because
        of a sharing violation. If *allowCancel* is <code>false</code>,
        the file is opened read-only without prompting the user.
        
        Remark:
        s This function works with MSDocumentManager to locate and manage
        files. In stand-alone MicroStation, if *inFilename* is not a
        complete file path, this function will look for it in the
        directories defined by MS_DEF.
        
        Remark:
        s The newly opened file does *not* become the MasterDGN. Call
        #SwitchToNewFile to make the resulting document the MasterDGN.
        
        Remark:
        s If the file is read-only on disk, then it will be opened read-
        only. Otherwise, this function will try to open the file read-
        write. If the file cannot be opened read-write because of a
        sharing violation, then it is opened read-only. If the file is not
        in a native MicroStation file format, then it will be opened read-
        only.
        
        Remark:
        s If the file is the same as the MasterDGN, it is first closed and
        the current session is ended.
        
        See also:
        SwitchToNewFile
        
        
        
        Returns (Tuple, 0):
        A pointer to the newly opened file if successful, or NULL if the
        file could not be found or opened. See *status.*
        
        Returns (Tuple, 1):
        status.
        SUCCESS if the file was opened
        """
        ...
    
    @staticmethod
    def GetActiveDgnFile() -> MSPyDgnPlatform.DgnFile:
        """
        Get the DgnFileP for the current active model
        
        Returns:
        The DgnFileP for the current active model.
        """
        ...
    
    @staticmethod
    def GetActiveDgnModel() -> MSPyDgnPlatform.DgnModel:
        ...
    
    @staticmethod
    def GetActiveDgnModelRef() -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    @staticmethod
    def GetManager() -> MSPyMstnPlatform.ISessionMgr:
        ...
    
    def GetMaster(self: MSPyMstnPlatform.ISessionMgr) -> MSPyDgnPlatform.DgnDocument:
        """
        Get the Document for the Master DGN
        
        Returns:
        The document for the current Master DGN file, or NULL.
        """
        ...
    
    @staticmethod
    def GetMasterDgnFile() -> MSPyDgnPlatform.DgnFile:
        """
        Get the DgnFileP for the current Master DGN file
        
        Returns:
        The DgnFileP for the current Master DGN file.
        """
        ...
    
    def GetUIItemMenuMarkState(*args, **kwargs):
        """
        GetUIItemMenuMarkState(self: MSPyMstnPlatform.ISessionMgr, key: str, defaultIfKeyNotFound: MSPyMstnPlatform.MenuMarkType = <MenuMarkType.eMARK_NONE: 0>) -> MSPyMstnPlatform.MenuMarkType
        
        Get the MenuMarkType defined by key.
        
        Parameter ``key``:
        The key used to retrieve UIItem state values.
        
        Parameter ``defaultIfKeyNotFound``:
        The value to return if state value has not been specified.
        
        Returns:
        MenuMarkType associated with key, or defaultIfKeyNotFound if no
        entry is found matching the key.
        """
        ...
    
    def GetUIItemState(self: MSPyMstnPlatform.ISessionMgr, key: str, itemState: MSPyMstnPlatform.UIItemStateType, defaultIfKeyNotFound: bool) -> bool:
        """
        Get the boolean value defined by key and itemState.
        
        Parameter ``key``:
        The key used to retrieve UIItem state values.
        
        Parameter ``itemState``:
        The UIItemStateType that specifies which state value to get.
        
        Parameter ``defaultIfKeyNotFound``:
        The value to return if state value has not been specified.
        
        Returns:
        bool value associated with key, or defaultIfKeyNotFound if no
        entry is found matching the key.
        """
        ...
    
    def GetWriteableFiles(self: MSPyMstnPlatform.ISessionMgr) -> MSPyDgnPlatform.DgnFilePtrArray:
        """
        Returns the list of all writeable files, including any activated
        references.
        """
        ...
    
    @staticmethod
    def InActiveFile(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Is this modelRef from the same file as the active model.
        """
        ...
    
    @staticmethod
    def InMasterFile(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Is this modelRef from the master file.
        """
        ...
    
    @staticmethod
    def InTransactableFile(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Is this modelRef from a transactable file.
        """
        ...
    
    @staticmethod
    def IsActiveDgnFile(dgnFile: MSPyDgnPlatform.DgnFile) -> bool:
        """
        Is this the file of the active model.
        """
        ...
    
    @staticmethod
    def IsActiveModel(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Is this modelRef the active model.
        """
        ...
    
    @staticmethod
    def IsActiveModelLocked() -> bool:
        ...
    
    def IsActiveWorkSetAssociatedToCONNECTProject(self: MSPyMstnPlatform.ISessionMgr) -> bool:
        ...
    
    def IsActiveWorkSetAssociatedToCONNECTProjectAndDGNMode(self: MSPyMstnPlatform.ISessionMgr) -> bool:
        ...
    
    def IsActiveWorkSetNoWorkSet(self: MSPyMstnPlatform.ISessionMgr) -> bool:
        ...
    
    @staticmethod
    def IsDesignFileInitialized() -> bool:
        """
        Return true if Session is active and design file has been initailized.
        Populating of model specific UI items should not happen until this
        method returns true.
        """
        ...
    
    @staticmethod
    def IsMasterDgnFile(dgnFile: MSPyDgnPlatform.DgnFile) -> bool:
        """
        Is this the master file.
        """
        ...
    
    @staticmethod
    def IsMasterFileClosing() -> bool:
        """
        Return true if Session is closing, This allows UI items to ignore
        window close events.
        """
        ...
    
    def IsReadyForUIProcessing(self: MSPyMstnPlatform.ISessionMgr) -> bool:
        """
        Return true if Session's active model has been initialized and is
        available to populate of model specific data in UI.
        """
        ...
    
    Manager: ISessionMgr
    
    @property
    def Master(arg0: MSPyMstnPlatform.ISessionMgr) -> MSPyDgnPlatform.DgnDocument:
        ...
    
    MasterDgnFile: DgnFile
    
    def OpenDgnFileDialog(self: MSPyMstnPlatform.ISessionMgr) -> tuple:
        """
        Prompts the user to select a file.
        
        
        Remark:
        s This function works with MSDocumentManager to locate and manage
        files. In stand-alone MicroStation, the standard File Open dialog
        is used. The default directory is MS_DEF or the previously
        selected directory.
        
        Remark:
        s The returned DgnDocument object is not open.
        
        See also:
        SwitchToNewFile
        
        
        
        Returns  (Tuple, 0):
        NULL, if the user hit Cancel; else, a pointer to a document object
        that stores the path to the file that was chosen.
        
        Returns (Tuple, 1) :
        status.  SUCCESS if a file was chosen; otherwise, the error status returned
        by the document manager.
        """
        ...
    
    def RemoveUIItemStateEntry(self: MSPyMstnPlatform.ISessionMgr, key: str) -> None:
        """
        Remove UIItemState entry that matches specified key if one exist.
        
        Parameter ``key``:
        The key used to store UIItem state values.
        """
        ...
    
    def SaveDgnFileChanges(self: MSPyMstnPlatform.ISessionMgr, dgnFileVector: MSPyDgnPlatform.DgnFilePtrArray) -> bool:
        """
        Write all in-memory changes to the disk for each DgnFile in the list.
        """
        ...
    
    @staticmethod
    def SetActiveModelLocked(locked: bool) -> None:
        ...
    
    @staticmethod
    def SetAutoLockActiveModel(value: bool) -> None:
        ...
    
    def SetUIItemMenuMarkState(*args, **kwargs):
        """
        SetUIItemMenuMarkState(self: MSPyMstnPlatform.ISessionMgr, key: str, value: MSPyMstnPlatform.MenuMarkType = <MenuMarkType.eMARK_NONE: 0>, sendimmediateMessage: bool = False) -> None
        
        Set the menu mark value for a menu item. This will trigger a
        SystemEvent.ApplicationSyncUIItem event.
        
        Parameter ``key``:
        The key that defines the name of the entry to modify or create.
        
        Parameter ``value``:
        The MenuMarkType value.
        
        Parameter ``sendImmediateMessage``:
        If true send immediate sync message, if false the sync message
        will be sent in the next UISync timer cycle.
        """
        ...
    
    def SetUIItemState(self: MSPyMstnPlatform.ISessionMgr, key: str, itemState: MSPyMstnPlatform.UIItemStateType, value: bool, sendImmediateMessage: bool = False) -> None:
        """
        Set the boolean value that defines the state of a UI item. This will
        trigger a SystemEvent.ApplicationSyncUIItem event.
        
        Parameter ``key``:
        The key that defines the name of the entry to modify or create.
        
        Parameter ``itemState``:
        The UIItemStateType that specifies which state value to set.
        
        Parameter ``value``:
        The boolean value.
        
        Parameter ``sendImmediateMessage``:
        If true send immediate sync message, if false the sync message
        will be sent in the next UISync timer cycle.
        """
        ...
    
    def SwitchToNewFile(self: MSPyMstnPlatform.ISessionMgr, doc: MSPyDgnPlatform.DgnDocument, inoutModelName: str, fileType: int, doUpdate: bool, releaseReferences: bool, reopeningAfterSave: bool = False, runInitUCM: bool = False) -> MSPyDgnPlatform.DgnFileStatus:
        """
        Makes the specified file the Master DGN, opening it if necessary.
        
        Returns:
        SUCCESS if *doc* was opened (if necessary) and has become the new
        Master DGN. See #FindDesignFile for errors that can result from a
        failed attempt to open a file.
        
        Parameter ``doc``:
        Identifies the DGN to become the new master.
        
        Parameter ``inputModelName``:
        The model in *doc* to become active
        
        Parameter ``fileType``:
        The format of the file. Should be one of the GRAPHICSFILE_...
        values.
        
        Parameter ``doUpdate``:
        Pass <code>true</code> if MicroStation should issue the UPDATE ALL
        command after making this file master.
        
        Parameter ``releaseReferences``:
        Pass <code>true</code> to disable reference file load
        optimization. If <code>true</code>, the new master DGN will be
        forced to load all of its references, even those that are already
        loaded by the current master DGN. Normally, you should pass pass
        <code><code>false</code></code> for this parameter.
        
        Parameter ``reopeningAfterSave``:
        Is this open being peformed after a save?
        
        Parameter ``runInitUCM``:
        Runs the user command specified by MS_IT.
        
        Remark:
        s Call #FindDesignFile or #OpenDgnFileDialog to open a file and
        obtain a Document.
        
        Remark:
        s This function closes the current Master DGN, if any, and ends
        the previous session. It then begins a new session. See
        SessionManager for a description of what happens when a session
        ends and starts.
        
        Remark:
        s If *doc* is not open, then this function will try to open it
        from the file path of the document. See FindDesignFile for when a
        file is opened read-only or read-write.
        
        Remark:
        s If *doc* is not open and if its file format can be inferred from
        the file extension, then *fileType* will be inferred from the file
        extension. Specifically, if the file extension is found in the
        MS_DESIGNFILTER list, then GRAPHICSFILE_UStn will be inferred.
        File extensions such as DGNLIB, IGES, DXF, CGM, and DWG map to
        like-named GRAPHICSFILE_... values.
        
        Remark:
        s See #FindDesignFile for the case where *fileType* is
        GRAPHICSFILE_IGES or GRAPHICSFILE_CGM.
        
        See also:
        FindDesignFile
        """
        ...
    
    @property
    def WriteableFiles(arg0: MSPyMstnPlatform.ISessionMgr) -> MSPyDgnPlatform.DgnFilePtrArray:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class InputQueueSourceEnum:
    """
    Members:
    
    eFROM_KEYBOARD
    
    eFROM_CMDFILE
    
    eFROM_APP
    
    eFROM_UCM
    
    eTABLET_MENU
    
    eSCREEN_MENU
    
    eFUNCKEY_MENU
    
    eCURSOR_BUTTON_MENU
    
    ePULLDOWN_MENU
    
    eCONTROL_STRIP_MENU
    
    eHIERARCHICAL_MENU
    
    eWINDOW_ICON
    
    ePALETTE_MENU
    
    eFROM_STARTUP
    
    eFROM_DIALOG
    
    eFROM_PROCESS
    
    eFROM_MDL
    
    eFROM_PRDFPI
    
    eFROM_OPER_SYSTEM
    """

    def __init__(self: MSPyMstnPlatform.InputQueueSourceEnum, value: int) -> None:
        ...
    
    eCONTROL_STRIP_MENU: InputQueueSourceEnum
    
    eCURSOR_BUTTON_MENU: InputQueueSourceEnum
    
    eFROM_APP: InputQueueSourceEnum
    
    eFROM_CMDFILE: InputQueueSourceEnum
    
    eFROM_DIALOG: InputQueueSourceEnum
    
    eFROM_KEYBOARD: InputQueueSourceEnum
    
    eFROM_MDL: InputQueueSourceEnum
    
    eFROM_OPER_SYSTEM: InputQueueSourceEnum
    
    eFROM_PRDFPI: InputQueueSourceEnum
    
    eFROM_PROCESS: InputQueueSourceEnum
    
    eFROM_STARTUP: InputQueueSourceEnum
    
    eFROM_UCM: InputQueueSourceEnum
    
    eFUNCKEY_MENU: InputQueueSourceEnum
    
    eHIERARCHICAL_MENU: InputQueueSourceEnum
    
    ePALETTE_MENU: InputQueueSourceEnum
    
    ePULLDOWN_MENU: InputQueueSourceEnum
    
    eSCREEN_MENU: InputQueueSourceEnum
    
    eTABLET_MENU: InputQueueSourceEnum
    
    eWINDOW_ICON: InputQueueSourceEnum
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.InputQueueSourceEnum) -> int:
        ...
    
LIBRARY_AutoConvertToV8: int

LIBRARY_AutoConvertToV8NoBackup: int

LIBRARY_IgnoreV7Libraries: int

LIBRARY_PromptForConvertToV8: int

class Level:
    """
    None
    """

    @staticmethod
    def CompareLevelData(compareAttributesOut: MSPyDgnPlatform.BitMask, modelRef1: MSPyDgnPlatform.DgnModelRef, levelId1: int, modelRef2: MSPyDgnPlatform.DgnModelRef, levelId2: int, compareAttributesIn: MSPyDgnPlatform.BitMask) -> bool:
        """
        @Description Compare level related data between level1 and level2. The
        function will compare only those attributes as specified in
        pCompareAttributesMaskIn. If pCompareAttributesMaskIn is NULL, then
        all the attributes will be compared.
        
        Parameter ``compareAttributesOut``:
        if non-null, then return a set of bits that represent the
        attributes of the levels that are not the same.
        
        Parameter ``modelRef1In``:
        model 1
        
        Parameter ``levelId1In``:
        level id of model 1
        
        Parameter ``modelRef2In``:
        model 2
        
        Parameter ``levelId2In``:
        level id of model 2
        
        Parameter ``compareAttributesIn``:
        mask of attributes to compare
        
        Returns:
        true if the level data of the two levels matches for attributes
        specified in pCompareAttributesMaskIn
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CopyElement(destModelRef: MSPyDgnPlatform.DgnModelRef, destLevelId: int, sourceModelRef: MSPyDgnPlatform.DgnModelRef, sourceLevelId: int, inEntireFile: bool) -> tuple:
        """
        @Description Copy elements in source level to destination level.
        
        Parameter ``numElementCopiedOut``:
        number of elements copied
        
        Parameter ``destModelRefIn``:
        destination model to copy elements to
        
        Parameter ``destLevelIdIn``:
        destination level to copy elements to
        
        Parameter ``sourceModelRefIn``:
        source model ref whose elements to copy
        
        Parameter ``sourceLevelIdIn``:
        source level from which to copy elements from
        
        Parameter ``inEntireFileIn``:
        if true, then move elements in entire file of sourceModelRefIn,
        else copy elements only in the specified model
        
        Returns:
        ERROR if the model-ref or the level ids are invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CopyLevel(destModelRef: MSPyDgnPlatform.DgnModelRef, sourceModelRef: MSPyDgnPlatform.DgnModelRef, sourceLevelId: int, newLevelNameIn: str, setExternal: bool) -> tuple:
        """
        @Description Copy a level from source model into destination model.
        Creates a new level in the destination model with the same level-name
        & level-code as the source level.
        
        Parameter ``levelIdOut``:
        id of new level in pDestModelRefIn
        
        Parameter ``destModelRefIn``:
        destination model-ref to copy into
        
        Parameter ``sourceModelRefIn``:
        source model ref
        
        Parameter ``sourceLevelIdIn``:
        id of library level to copy
        
        Parameter ``setExternalIn``:
        if true, then set the imported level as " external ". Should be true
        only if pSourceModelRef is LEVEL_LIBRARY_MODELREF.
        
        Returns:
        SUCCESS if the level data is successfully copied.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table of the
        destination model-ref is in a read-only state <DT>
        **MSGID_errorTableIsOfAttachment** <DD> the destination model-ref
        is for an attachment <DT> **ERROR** <DD> if model-ref or level id
        is invalid or the copy failed for some unspecified reason </DL>
        
        Remark:
        s A successful level copy set raises a LEVEL_CHANGE_ATTRIBUTE
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table.
        
        See also:
        LevelTable.Rewrite
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CopyLevelData(destModelRef: MSPyDgnPlatform.DgnModelRef, destLevelId: int, sourceModelRef: MSPyDgnPlatform.DgnModelRef, sourceLevelId: int) -> int:
        """
        @Description Copy all level related data from source level into
        destination level. This function does not copy the level-name & level-
        code.
        
        Parameter ``destModelRefIn``:
        destination model
        
        Parameter ``destLevelIdIn``:
        destination level id
        
        Parameter ``sourceModelRefIn``:
        source model
        
        Parameter ``sourceLevelIdIn``:
        source level id
        
        Returns:
        SUCCESS if the level data is successfully copied.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table of the
        destination model-ref is in a read-only state <DT>
        **MSGID_errorLevelIsReadOnly** <DD> the specified destination
        level is in a read-only state <DT> **ERROR** <DD> if
        source/destination model-ref or level id is invalid or the copy
        failed for some unspecified reason </DL>
        
        Remark:
        s A successful level copy raises a LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table.
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CopyLevelDataByAttributeMask(destModelRef: MSPyDgnPlatform.DgnModelRef, destLevelId: int, sourceModelRef: MSPyDgnPlatform.DgnModelRef, sourceLevelId: int, copyAttributesMask: MSPyDgnPlatform.BitMask) -> int:
        """
        @Description Copy level related data as specified by the level-
        attributes mask from source level into destination level. This
        function does not copy the level-name & level-code.
        
        Parameter ``destModelRefIn``:
        destination model
        
        Parameter ``destLevelIdIn``:
        destination level id
        
        Parameter ``sourceModelRefIn``:
        source model
        
        Parameter ``sourceLevelIdIn``:
        source level id
        
        Parameter ``copyAttributesMaskIn``:
        mask of attributes to copy - will never copy level name
        
        Returns:
        SUCCESS if the level data is successfully copied.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table of the
        destination model-ref is in a read-only state <DT>
        **MSGID_errorLevelIsReadOnly** <DD> the specified destination
        level is in a read-only state <DT> **ERROR** <DD> if
        source/destination model-ref or level id is invalid or the copy
        failed for some unspecified reason </DL>
        
        Remark:
        s A successful level copy raises a LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table.
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Create(modelRef: MSPyDgnPlatform.DgnModelRef, levelName: str, levelCode: int) -> tuple:
        """
        @Description Create a new level.
        
        Remark:
        s A new level can be created only in the context of the current
        file (i.e. specified model-ref should be a root-model of the
        current file).
        
        Remark:
        s The specified level-name should be unique in the context of the
        all other root levels of the level-table. Otherwise the level is
        not created.
        
        Remark:
        s The specified level-code should be unique in the context of the
        entire level-table. Otherwise the level is not created.
        LEVEL_NULL_CODE can be specified for the level-code, in which
        case, Level.Create will automatically generate a unique level-
        code and assign it to the new level. Such a level-code will be
        termed as a " system - assigned " level-code.
        
        Parameter ``levelIdOut``:
        level id of new level
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelNameIn``:
        level name of new level
        
        Parameter ``levelCodeIn``:
        level code of new level - maybe LEVEL_NULL_CODE.
        
        Returns:
        SUCCESS if level is successfully created.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorCannotCreateNewAttachmentLevel** <DD>
        the specified model-ref is for an attachment <DT>
        **MSGID_errorLevelNameIsDuplicate** <DD> the specified level-name
        is duplicate <DT> **MSGID_errorLevelCodeIsDuplicate** <DD> the
        specified level-code is duplicate <DT> **ERROR** <DD> if the
        model-ref is invalid or the new level cannot be created for some
        unspecified reason </DL>
        
        Remark:
        s A successful level create raises a LEVEL_CREATE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.Delete LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateFromSeed(modelRef: MSPyDgnPlatform.DgnModelRef, levelName: str, levelCode: int, seedLevelId: int, copyAttributeMask: MSPyDgnPlatform.BitMask) -> tuple:
        """
        @Description Create a new level. The new level takes its attributes as
        specified " copyAttributeMaskIn " from the " seed " level. Typically,
        " copyAttributeMaskIn " is got by calling function
        <i>LevelAttribute.GetMask
        (MS_LEVEL_CREATE_FROM_SEED_ATTRIBUTE_MASK)</i>
        
        Parameter ``levelIdOut``:
        level id of new level
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelNameIn``:
        level name of new level
        
        Parameter ``levelCodeIn``:
        level code of new level - maybe LEVEL_NULL_CODE.
        
        Parameter ``seedLevelIdIn``:
        seed level
        
        Parameter ``copyAttributeMaskIn``:
        seed level
        
        Returns:
        SUCCESS if level is successfully created.
        
        Remark:
        s A successful level create raises a LEVEL_CREATE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.Create usmtnLevel.GetSeedLevelC LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Delete(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> int:
        """
        @Description Delete a level.
        
        Remark:
        s A level can be deleted only in the context of the current file
        (i.e. modelRefIn should be a root-model of the current file).
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id to delete
        
        Returns:
        SUCCESS if the level is successfully deleted.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorCannotDeleteAttachmentLevel** <DD>
        the specified model-ref is for an attachment <DT>
        **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
        read-only state <DT> **MSGID_errorLevelIsUsed** <DD> the specified
        level is used by some element in the file <DT>
        **MSGID_errorCannotDeleteExternalLevel** <DD> the specified level
        is a library level <DT> **MSGID_errorCannotDeleteDefaultLevel**
        <DD> the specified level is the default level <DT>
        **MSGID_errorCannotDeleteDefpointsLevel** <DD> the specified level
        is the DWG DEFPOINTS level <DT> **ERROR** <DD> if model-ref or
        level-id is invalid or the level cannot be deleted for some
        unspecified reason </DL>
        
        Remark:
        s A successful level delete raises a LEVEL_DELETE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.Create LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def DeleteElement(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, inEntireFile: bool, updateView: bool) -> tuple:
        """
        @Description Delete elements on specified level.
        
        Parameter ``numElementDeletedOut``:
        number of elements deleted
        
        Parameter ``modelRefIn``:
        source model ref whose elements to delete
        
        Parameter ``levelIdIn``:
        source level from which to delete elements
        
        Parameter ``inEntireFileIn``:
        if true, then delete elements in entire file that contains
        modelRefIn, else delete elements only in the specified model
        
        Parameter ``updateViewIn``:
        if true, then update the views
        
        Returns:
        ERROR if the model-ref or the level ids are invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Draw(viewDraw: List[bool[8]], incremental: bool, drawMode: MSPyDgnPlatform.DgnDrawMode, modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, startEndMsg: bool, drawShared: bool) -> int:
        """
        @Description Draw all elements on specified level
        
        @Param[in] viewDrawIn views to update. Should point to an array
        dimensioned to DgnPlatform.MAX_VIEWS, and viewDraw[i] controls
        whether view i is drawn. If NULL, all views are drawn.
        
        Parameter ``incrementalIn``:
        if false, don't erase before drawing
        
        Parameter ``drawModeIn``:
        erasing portion of drawing
        
        Parameter ``modelRefIn``:
        model ref
        
        Parameter ``levelIdIn``:
        level to draw
        
        Parameter ``startEndMsgIn``:
        if true then want in prog/complete msg
        
        Parameter ``drawSharedIn``:
        if true, then draw all models/attachments which use the same level
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.Draw Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetActive() -> tuple:
        """
        @Description Get the current active level.
        
        Parameter ``levelIdOut``:
        active level id
        
        Returns:
        SUCCESS
        
        See also:
        Level.IsActive Level.SetActive Level.SetActiveByName
        Params.SetActive Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetAttributesDifferFromSource(differencesMask: MSPyDgnPlatform.BitMask, modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the 'level's attributes differ from source' flag.
        
        Parameter ``levelDifferOut``:
        true if the level differs from its source
        
        Parameter ``differencesMaskOut``:
        list of attributes which differ.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetCode(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level code.
        
        Parameter ``levelCodeOut``:
        level code
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetCode Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetColor(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level color and color-override flag. An element is
        displayed with this color in a view when the color-override flag is
        true and when level-symbology for the view is turned ON.
        
        Parameter ``colorOut``:
        level color
        
        Parameter ``colorOverrideOut``:
        level color override - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetColor Level.GetSymbology Level.SetSymbology
        
        See also:
        Level.GetSymbology Level.SetSymbology Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetCreateTimeStamp(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level create time stamp
        
        Parameter ``createTimeStampOut``:
        level create time stamp
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetDescription Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDescription(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level description.
        
        Parameter ``descriptionOut``:
        level description
        
        Parameter ``stringSizeIn``:
        number of characters pLevelDescriptionOut can hold
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetDescription Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDisplay(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the display flag.
        
        Parameter ``levelDisplayOut``:
        level display flag - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetDisplayMask Level.GetDisplayMask
        Level.SetDisplay Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDisplayPriority(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level display priority
        
        Parameter ``priorityOut``:
        level display priority
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetDisplayPriority Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementAccess(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the element access mode.
        
        Parameter ``elementAccessOut``:
        element access - one of <TT>LEVEL_ELEMENT_ACCESS_</TT>... (defined
        in leveltypes.h)
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetElementAccess Level.IsElementLocked
        Level.IsElementReadOnly Level.IsElementViewOnly Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementColor(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level element color. This color value is applied
        on an element when the element's color is set to BYLEVEL.
        
        Parameter ``colorOut``:
        element color
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetElementColor Level.GetElementSymbology
        Level.SetElementSymbology
        
        See also:
        Level.GetElementSymbology Level.SetElementSymbology Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementCount(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the the number of elements of specified model-ref
        that use specified level.
        
        Parameter ``usageCountOut``:
        number of elements that use the level
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.GetUsageMask Level.IsUsed Level.GetUsage
        Level.ReportUsage Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementMaterialId(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level element material id associated with the level.
        
        Parameter ``materialIdOut``:
        element material id
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetElementMaterialId Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementStyle(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level element style and custom-line style
        override info. This style value is applied on an element when the
        element's style is set to BYLEVEL.
        
        Parameter ``styleOut``:
        element style
        
        Parameter ``styleParamsOut``:
        custom line style modifiers
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetElementStyle Level.GetElementSymbology
        Level.SetElementSymbology
        
        See also:
        Level.GetElementSymbology Level.SetElementSymbology Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementSymbology(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the element symbology.
        
        Parameter ``elementColorOut``:
        element color
        
        Parameter ``elementStyleOut``:
        element style
        
        Parameter ``elementStyleParamsOut``:
        custom line style modifiers
        
        Parameter ``elementWeightOut``:
        element weight
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetElementSymbology Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetElementWeight(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level element weight. This weight value is
        applied on an element when the the element's weight is set to BYLEVEL.
        
        Parameter ``weightOut``:
        element weight
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetElementWeight Level.GetElementSymbology
        Level.SetElementSymbology
        
        See also:
        Level.GetElementSymbology Level.SetElementSymbology Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetFrozen(modelRef: MSPyDgnPlatform.DgnModelRef, levelIdIn: int, frozenTypeIn: MSPyMstnPlatform.LevelFrozenType) -> tuple:
        """
        @Description Get the frozen flag
        
        Parameter ``levelFrozenOut``:
        level frozen flag
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``frozenTypeIn``:
        one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        LevelTable.GetFrozenMask LevelTable.SetFrozenMask
        LevelTable.GetDisplayFrozenMask Level.IsFrozen
        Level.SetFrozen Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetHidden(modelRef: MSPyDgnPlatform.DgnModelRef, levelIdIn: int) -> tuple:
        """
        @Description Get the hidden flag.
        
        Parameter ``levelHiddenOut``:
        level hidden flag
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        LevelTable.GetHiddenMask Level.IsHidden Level.SetHidden
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetIdFromCode(modelRef: MSPyDgnPlatform.DgnModelRef, levelCode: int) -> tuple:
        """
        @Description Given a level-code, get its level-id.
        
        Parameter ``levelIdOut``:
        level id
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelCodeIn``:
        level code
        
        Returns:
        SUCCESS if the level-id is successfully returned.
        
        Remark:
        s This function does not look in level libraries.
        
        See also:
        Level.GetIdFromCodeIncludingLibraries
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorLevelCodeIsInvalid** <DD> the level-code is not valid
        <DT> **ERROR** <DD> if the model-ref is invalid or the level
        cannot be returned for some unspecified reason </DL>
        
        See also:
        Level.GetIdFromName Level.GetIdFromElementId
        Level.GetIdFromElementRef Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetIdFromCodeIncludingLibraries(modelRef: MSPyDgnPlatform.DgnModelRef, levelCode: int) -> tuple:
        """
        @Description Given a level-code, get its level-id, including levels
        that are in level libraries.
        
        Parameter ``levelIdOut``:
        level id
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelCodeIn``:
        level code
        
        Returns:
        SUCCESS if the level-id is successfully returned.
        
        See also:
        Level.GetIdFromCode
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorLevelCodeIsInvalid** <DD> the level-code is not valid
        <DT> **ERROR** <DD> if the model-ref is invalid or the level
        cannot be returned for some unspecified reason </DL>
        
        See also:
        Level.GetIdFromName Level.GetIdFromElementId
        Level.GetIdFromElementRef Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetIdFromName(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, levelName: str) -> tuple:
        """
        @Description Given a level-name, get its level-id.
        
        Parameter ``levelIdOut``:
        level id
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelNameIn``:
        level name
        
        Returns:
        SUCCESS if the level-id is successfully returned.
        
        Remark:
        s This function does not look in level libraries.
        
        See also:
        Level.GetIdFromNameIncludingLibraries
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorLevelNameIsInvalid** <DD> the level-name is not valid
        <DT> **ERROR** <DD> if the model-ref is invalid or the level
        cannot be returned for some unspecified reason </DL>
        
        See also:
        Level.GetIdFromCode Level.GetIdFromElementId
        Level.GetIdFromElementRef Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetIdFromNameIncludingLibraries(modelRef: MSPyDgnPlatform.DgnModelRef, levelName: str) -> tuple:
        """
        @Description Given a level-name, get its level-id, including levels
        that are in level libraries.
        
        Parameter ``levelIdOut``:
        level id
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelNameIn``:
        level name
        
        Returns:
        SUCCESS if the level-id is successfully returned.
        
        See also:
        Level.GetIdFromName
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorLevelNameIsInvalid** <DD> the level-name is not valid
        <DT> **ERROR** <DD> if the model-ref is invalid or the level
        cannot be returned for some unspecified reason </DL>
        
        See also:
        Level.GetIdFromCode Level.GetIdFromElementId
        Level.GetIdFromElementRef Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetMaterialId(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get material id associated with the level.
        
        Parameter ``materialIdOut``:
        level material id
        
        Parameter ``materialOverrideOut``:
        level material override
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetMaterialId Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetName(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level name.
        
        Parameter ``levelNameOut``:
        level name
        
        Parameter ``stringSizeIn``:
        number of (WChar) characters pLevelNameOut can hold
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetName Level.GetPathName Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetPlot(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the plot flag.
        
        Parameter ``levelPlotOut``:
        level plot flag
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        LevelTable.GetPlotMask Level.SetPlot Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetSeedLevel(modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Get level-id of seed level. When a new level is created,
        then the user designated seed level whose attributes need to be
        applied on the newly created level.
        
        Remark:
        s <i>Level.CreateLevel</i> does not apply the attributes of the
        seed level. <i>Level.CreateLevel</i> will only create a newly
        allocated level. The attributes of the seed level can then be
        applied using <i>Level.CopyLevelData</i>. To create a level &
        apply the seed in one step, call the function
        <i>Level.CreateFromSeed</i>
        
        Parameter ``modelRefIn``:
        model ref
        
        Returns:
        DgnPlatform.LevelId of seed level
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetStyle(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level style, custom-line style override info and
        style-override flag. An element is displayed with this style in a view
        when the style-override flag is true and when level-symbology for the
        view is turned ON.
        
        Parameter ``styleOut``:
        level style
        
        Parameter ``styleParamsOut``:
        custom line style modifiers
        
        Parameter ``styleOverrideOut``:
        level style override - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetStyle Level.GetSymbology Level.SetSymbology
        
        See also:
        Level.GetSymbology Level.SetSymbology Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetSymbology(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level symbology and symbology-override flags.
        
        Parameter ``colorOut``:
        color
        
        Parameter ``colorOverrideOut``:
        color override - true or false
        
        Parameter ``styleOut``:
        style
        
        Parameter ``styleParamsOut``:
        custom line style modifiers
        
        Parameter ``styleOverrideOut``:
        style override - true or false
        
        Parameter ``weightOut``:
        weight
        
        Parameter ``weightOverrideOut``:
        weight override - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetSymbology Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetTransparency(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get level display transparency
        
        Parameter ``transparencyOut``:
        level display transparency (value between 0.0 & 1.0)
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetTransparency Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetUniqueID(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level element's unique ID. The level element's
        unique id is assigned by the system and cannot be modified. This
        unique ID should not be confused with the level id returned by
        Level.GetIdFromName (or Level.GetIdFromCode or
        LevelIterator.GetFirst ..). The unique ID is an Int64 is stored at
        element->ehdr.uniqueId and is unique in the context of a file-object.
        The level-id is also system assigned, but is a UInt and is unique in
        the context of a level-table.
        
        Parameter ``uniqueIDOut``:
        unique ID
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetUsage(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, inFile: bool) -> tuple:
        """
        @Description Get the level usage flag.
        
        Parameter ``usageOut``:
        usage flag - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``inFile``:
        if true, then check the level is used in the entire file
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        Remark:
        s <UL> <LI> If *pUsageOut is true, then the level is used. <LI> If
        *pUsageOut is false, then the level is not used. </UL>
        
        See also:
        Level.GetUsageMask Level.IsUsed Level.ReportUsage
        Level.GetElementCount Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetWeight(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get the level weight and weight-override flag. An element
        is displayed with this style in a view when the weight-override flag
        is true and when level-symbology for the view is turned ON.
        
        Parameter ``weightOut``:
        level weight
        
        Parameter ``weightOverrideOut``:
        level weight override - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetWeight Level.GetSymbology Level.SetSymbology
        
        See also:
        Level.GetSymbology Level.SetSymbology Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsActive(levelId: int) -> bool:
        """
        @Description Check if a level of the current-file is the active level.
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if iLevelIdIn is the active level, else false
        
        See also:
        Level.GetActive Level.SetActive Level.SetActiveByName
        Params.SetActive Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsCodeAutoGenerated(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Get if the level code is auto generated (that means
        generated by MicroStation) or is manually set by the user
        
        Parameter ``isAutoGeneratedOut``:
        true if the level code is auto generated
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.SetCode Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsElementLocked(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if elements on the specified level are locked.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level's element-access is atleast locked, else false,
        else SUCCESS
        
        See also:
        Level.SetElementAccess Level.GetElementAccess Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsElementReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if elements on the specified level are read-only
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level's element-access is atleast read-only, else
        false
        
        See also:
        Level.SetElementAccess Level.GetElementAccess Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsElementViewOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsElementViewOnly(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool
        
        @Description Check if elements on the specified level are view-only
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level's element-access is view-only, else false
        
        See also:
        Level.SetElementAccess Level.GetElementAccess
        
        Bentley Systems
        
        Remark:
        
        
        2. IsElementViewOnly(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool
        
        @Description Check if elements on the specified level are view-only
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level's element-access is view-only, else false
        
        See also:
        Level.SetElementAccess Level.GetElementAccess
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsExternal(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if a level is an external (library) level or not.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level is external, else false
        
        See also:
        LevelTable.GetExternalMask Level.GetExternal
        Level.GetLibraryRef Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsFrozen(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, frozenType: MSPyMstnPlatform.LevelFrozenType) -> bool:
        """
        @Description Check if a level is frozen.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``frozenTypeIn``:
        one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)
        
        Returns:
        true if the level is frozen, else false
        
        See also:
        LevelTable.GetFrozenMask LevelTable.SetFrozenMask
        LevelTable.GetDisplayFrozenMask Level.GetFrozen
        Level.SetFrozen Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsHidden(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if a level is hidden.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level is hidden, else false
        
        See also:
        LevelTable.GetHiddenMask Level.GetHidden Level.SetHidden
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if a level is read-only.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level is read-only, else false
        
        See also:
        LevelTable.GetReadOnlyMask Level.GetReadOnly
        Level.SetReadOnly Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsUsed(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, inFile: bool) -> bool:
        """
        @Description Check if a level is used. A level is used if there is an
        element on the level.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``inFile``:
        if false, then check if a level is used in the context of
        modelRefIn only. if true, then returns if a level is used in the
        entire file of modelRefIn.
        
        Returns:
        true if the level is used, else false
        
        See also:
        Level.GetUsageMask Level.GetUsage Level.ReportUsage
        Level.GetElementCount Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsValid(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if the specified level id is a valid existing
        level.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        true if the level is valid, else false. Returns false if
        modelRefIn is invalid.
        
        See also:
        Level.IsValidByName Level.IsValidByCode
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsValidByCode(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> bool:
        """
        @Description Check if level with specified code is a valid existing
        level.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level code
        
        Returns:
        true if the level is valid, else false. Returns false if
        modelRefIn is invalid.
        
        See also:
        Level.IsValid Level.IsValidByName Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsValidByName(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, levelName: str) -> bool:
        """
        @Description Check if level with specified name is a valid existing
        level.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelNameIn``:
        level name
        
        Returns:
        true if the level is valid, else false. Returns false if
        modelRefIn is invalid.
        
        See also:
        Level.IsValid Level.IsValidByCode Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def MoveElementLevel(destLevelId: int, modelRef: MSPyDgnPlatform.DgnModelRef, sourceLevelId: int, inEntireFile: bool) -> tuple:
        """
        @Description Move elements of source level to destination level. The
        model-refs of both the source level and destination level are the
        same.
        
        Parameter ``numElementMovedOut``:
        number of elements moved
        
        Parameter ``destLevelIdIn``:
        destination level to move elements to
        
        Parameter ``modelRefIn``:
        model ref
        
        Parameter ``sourceLevelIdIn``:
        source level from which to elements from
        
        Parameter ``inEntireFileIn``:
        if true, then move elements in entire file of modelRefIn, else
        move elements only in the specified model
        
        Returns:
        ERROR if the model-ref or the level ids are invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def ReportUsage(reportString: MSPyBentley.WString, modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> int:
        """
        @Description Generate a report that describes where a level is used in
        the context of the file of specified model-ref
        
        Parameter ``reportStringOut``:
        report string
        
        Parameter ``modelRefIn``:
        model ref
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the model-ref or level id is invalid, else SUCCESS
        
        See also:
        Level.GetUsageMask Level.IsUsed Level.GetUsage
        Level.GetElementCount Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SelectElement(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> tuple:
        """
        @Description Select elements on specified level.
        
        Parameter ``numElementSelectedOut``:
        number of elements selected
        
        Parameter ``modelRefIn``:
        source model ref whose elements to copy
        
        Parameter ``levelIdIn``:
        source level from which to copy elements from
        
        Returns:
        ERROR if the model-ref or the level ids are invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetActive(levelId: int) -> int:
        """
        @Description Set level as active.
        
        Parameter ``levelIdIn``:
        level id
        
        Returns:
        ERROR if the level id is invalid or the level cannot be set as
        active
        
        Remark:
        s Returns **MSGID_errorElementAccessIsReadOnly** if element-access
        mode of the level is set to LevelElementAccess.ReadOnly or
        LevelElementAccess.ViewOnly
        
        See also:
        Level.IsActive Level.GetActive Level.SetActiveByName
        Params.SetActive Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetActiveByCode(levelCode: int) -> int:
        """
        @Description Set level with specified code as active. This function
        handles setting a library level as active. If the level with specified
        code is a library level, then, if necessary, the library level is
        copied into the current-file before setting the level active.
        
        Parameter ``levelCodeIn``:
        level code
        
        Returns:
        ERROR if the level code is invalid or the level cannot be set as
        active, else SUCCESS
        
        See also:
        Level.IsActive Level.GetActive Level.SetActive
        Params.SetActive Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetActiveByName(levelId: int, levelName: str) -> int:
        """
        @Description Set level with specified name as active. This function
        handles setting a library level as active. If the level with specified
        name is a library level, then, if necessary, the library level is
        copied into the current-file before setting the level active.
        
        Parameter ``levelNameIn``:
        level name
        
        Returns:
        ERROR if the level name is invalid or the level cannot be set as
        active, else SUCCESS
        
        See also:
        Level.IsActive Level.GetActive Level.SetActive
        Params.SetActive Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetCode(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, levelCode: int) -> int:
        """
        @Description Set level code. A level's code should be unique in the
        context of all the levels in a level-table i.e. all level codes in the
        context of a level-table should be unique.
        
        Remark:
        s A level code is displayed under the " Number " column of the
        level-manager.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``levelCodeIn``:
        level code
        
        Returns:
        SUCCESS if the level code is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorCannotChangeAttachmentLevelCode**
        <DD> the specified model-ref is for an attachment <DT>
        **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
        read-only state <DT> **MSGID_errorCannotChangeExternalLevel** <DD>
        the specified level is a library level <DT>
        **MSGID_errorCannotChangeDefaultLevelCode** <DD> the specified
        level is the default level <DT> **MSGID_errorLevelCodeIsNull**
        <DD> the specified level code is LEVEL_NULL_CODE <DT>
        **MSGID_errorLevelCodeIsDuplicate** <DD> the specified level code
        is duplicate <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level code cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level code set raises a LEVEL_CHANGE_CODE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetCode LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetColor(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, color: int, colorOverride: bool) -> int:
        """
        @Description Set level color. This sets the color to apply on an
        element of the level, when " level symbology " is turned on for the
        view. This is also termed as the level's OVERRIDE color. Note that
        this function has an additional " override " flag. The " override " flag
        has to be ON in order to use the color.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``colorIn``:
        level color - may be NULL
        
        Parameter ``colorOverrideIn``:
        level color override (true or false) - may be NULL
        
        Returns:
        SUCCESS if the level color is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level color cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level color set raises a LEVEL_CHANGE_ATTRIBUTE
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, then colorIn (if
        defined) is assumed to identify a color in the referenced file.
        
        See also:
        Level.GetColor Level.GetSymbology Level.SetSymbology
        LevelTable.Rewrite
        
        See also:
        Level.GetSymbology Level.SetSymbology LevelTable.Rewrite
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDescription(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, description: str) -> int:
        """
        @Description Set level description
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``descriptionIn``:
        level name
        
        Returns:
        SUCCESS if the level description is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorCannotChangeAttachmentLevelCode**
        <DD> the specified model-ref is for an attachment <DT>
        **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
        read-only state <DT> **MSGID_errorCannotChangeExternalLevel** <DD>
        the specified level is a library level <DT> **ERROR** <DD> if
        model-ref or level id is invalid or the level description cannot
        be set for some unspecified reason </DL>
        
        Remark:
        s A successful level description set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetDescription LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDisplay(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, display: bool) -> int:
        """
        @Description Set level display on/off. Turning off the display makes
        all the elements on the level invisible in all the views.
        
        Remark:
        s Call View.SetLevelDisplay to control the level display in a
        specific view.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``displayIn``:
        display flag - true or false
        
        Returns:
        SUCCESS if the level display flag is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **ERROR** <DD> if model-ref or level id is invalid
        or the level display cannot be set for some unspecified reason
        </DL>
        
        Remark:
        s A successful level display flag raises a LEVEL_CHANGE_DISPLAY
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.SetDisplayMask Level.GetDisplayMask
        Level.GetDisplay Level.Rewrite View.SetLevelDisplay
        View.GetLevelDisplay
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDisplayPriority(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, priority: int) -> int:
        """
        @Description Set level display priority
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``priorityIn``:
        level priority - may be NULL
        
        Returns:
        SUCCESS if the level priority is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level color cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful priority set raises a LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetDisplayPriority LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementAccess(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, elementAccess: MSPyDgnPlatform.LevelElementAccess) -> int:
        """
        @Description Set the level's element access mode. This can take one of
        4 values - LevelElementAccess.All, LevelElementAccess.Locked,
        LevelElementAccess.ReadOnly & LevelElementAccess.ViewOnly. The mode
        applies to elements on the level. The meaning attached to each of the
        modes is:<TABLE border=" 1 " cellspacing=" 3 " cellpadding=" 3 "> <TR>
        <TH>Access Mode</TH> <TH>Meaning</TH> </TR> <TR>
        <TD><TT>LevelElementAccess.All</TT></TD> <TD>Elements on the level
        have all access. This is the default mode.</TD> </TR> <TR>
        <TD><TT>LevelElementAccess.Locked</TT></TD> <TD>Elements on the level
        are locked. They can be copied, but cannot be modified or deleted. New
        elements can be added to the level - once added they are immediately
        locked. The level can be set active.</TD> </TR> <TR>
        <TD><TT>LevelElementAccess.ReadOnly</TT></TD> <TD>Elements on the
        level are for read-only purposes. They cannot be modified or deleted.
        The elements may be copied into another level. The level cannot be set
        active.</TD> </TR> <TR> <TD><TT>LevelElementAccess.ViewOnly</TT></TD>
        <TD>Elements on the level can only be viewed. They cannot be copied,
        modified or deleted. The level cannot be set active.</TD> </TR>
        </TABLE>
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``elementAccessIn``:
        element access - one of <TT>LEVEL_ELEMENT_ACCESS_</TT>... (defined
        in leveltypes.h)
        
        Returns:
        SUCCESS if the level element access is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorTableIsOfAttachment** <DD> the specified model-ref is
        for an attachment <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level element access cannot be set for some
        unspecified reason </DL>
        
        Remark:
        s A successful level element access raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetElementAccess LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementByLevel(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, elementAttributeString: MSPyDgnPlatform.BitMask, inEntireFile: bool, isSetByLevel: bool) -> tuple:
        """
        @Description set or unset elements symbology to that of BYLEVEL.
        
        Parameter ``numElementChangedOut``:
        number of elements changed
        
        Parameter ``modelRefIn``:
        model ref
        
        Parameter ``levelIdIn``:
        level to change elements symbology
        
        Parameter ``elementAttributeStringIn``:
        mask of attributes, 1:color, 2:style, 3:weight
        
        Parameter ``inEntireFileIn``:
        if true, then set elements symbology in entire file of modelrefIn,
        else set elements symbology only in the specified model
        
        Parameter ``isSetByLevel``:
        if true, then set elements symbology to that of BYLEVEL, else
        unset elements symbology to that of BYLEVEL.
        
        Returns:
        ERROR if the model-ref or the level ids are invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementColor(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, color: int) -> int:
        """
        @Description Set element color. This sets the color to apply on an
        element of the level, when the element has its color set to BYLEVEL.
        This is also be termed as the level's BYLEVEL color.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``colorIn``:
        element color
        
        Returns:
        SUCCESS if the level element color is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
        <DD> the element-access for the level is atleast
        LevelElementAccess.ReadOnly <DT> **ERROR** <DD> if model-ref or
        level id is invalid or the element color cannot be set for some
        unspecified reason </DL>
        
        Remark:
        s A successful level element color set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table *
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, then colorIn (if
        defined) is assumed to identify a color in the referenced file.
        
        See also:
        Level.GetElementColor Level.GetElementSymbology
        Level.SetElementSymbology LevelTable.Rewrite
        
        See also:
        Level.GetElementSymbology Level.SetElementSymbology
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementMaterialId(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, materialId: int) -> int:
        """
        @Description Set level element material id.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``materialIdIn``:
        material id
        
        Returns:
        SUCCESS if the level color is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level color cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level material id set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, materialIdIn is
        assumed to identify a material in the referenced file.
        
        See also:
        Level.GetElementMaterialId Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementStyle(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, style: int, styleParams: MSPyDgnPlatform.LineStyleParams) -> int:
        """
        @Description Set element style. This sets the style to apply on an
        element of the level, when the element has its style set to BYLEVEL.
        This is also be termed as the level's BYLEVEL style.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``styleIn``:
        element style - maybe NULL
        
        Parameter ``styleParamsIn``:
        custom line style modifiers - maybe NULL
        
        Returns:
        SUCCESS if the level element style is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
        <DD> the element-access for the level is atleast
        LevelElementAccess.ReadOnly <DT> **ERROR** <DD> if model-ref or
        level id is invalid or the element style cannot be set for some
        unspecified reason </DL>
        
        Remark:
        s A successful level element style set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, then styleIn (if
        defined) is assumed to identify a style in the referenced file.
        
        See also:
        Level.GetElementStyle Level.GetElementSymbology
        Level.SetElementSymbology LevelTable.Rewrite
        
        See also:
        Level.GetElementSymbology Level.SetElementSymbology
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementSymbology(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, color: int, style: int, styleParams: MSPyDgnPlatform.LineStyleParams, weight: int) -> int:
        """
        @Description Set element symbology. This functions allows setting the
        one or more of the element color, style, weight & fill color
        simultaneously.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``colorIn``:
        element color - maybe NULL
        
        Parameter ``styleIn``:
        element style - maybe NULL
        
        Parameter ``styleParamsIn``:
        custom line style modifiers - maybe NULL
        
        Parameter ``weightIn``:
        element weight - maybe NULL
        
        Returns:
        SUCCESS if the level element fill color is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
        <DD> the element-access for the level is atleast
        LevelElementAccess.ReadOnly <DT> **ERROR** <DD> if model-ref or
        level id is invalid or the level element symbology cannot be set
        for some unspecified reason </DL>
        
        Remark:
        s A successful level element symbology set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, then colorIn and
        styleIn (if defined) *must* identify color and style in the
        referenced file.
        
        See also:
        Level.GetElementSymbology LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetElementWeight(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, weight: int) -> int:
        """
        @Description Set element weight. This sets the style to apply on an
        element of the level, when the element has its weight set to BYLEVEL.
        This is also be termed as the level's BYLEVEL weight.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``weightIn``:
        element weight
        
        Returns:
        SUCCESS if the level element weight is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
        <DD> the element-access for the level is atleast
        LevelElementAccess.ReadOnly <DT> **ERROR** <DD> if model-ref or
        level id is invalid or the element weight cannot be set for some
        unspecified reason </DL>
        
        Remark:
        s A successful level element weight set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetElementWeight Level.GetElementSymbology
        Level.SetElementSymbology LevelTable.Rewrite
        
        See also:
        Level.GetElementSymbology Level.SetElementSymbology
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetFrozen(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, frozenType: MSPyMstnPlatform.LevelFrozenType, frozen: bool) -> int:
        """
        @Description Set level frozen on/off. Turning on the frozen makes all
        the elements on the level invisible. This is like turning off the
        display flag of a level with the following differences:<UL> <LI> If a
        cell-instance is on a frozen level, then all the elements of the cell-
        instance are not displayed, irrespective of the contained element's
        level. <LI> If an attachment is on a frozen level, then the attachment
        is not displayed. </UL>
        
        Remark:
        s There are two types of frozen controls described as follows:<DL
        COMPACT> <DT> <TT>LEVEL_FROZEN_TYPE_GLOBAL</TT> <DD>Turning on the
        global frozen flag makes an element on the level invisible across
        every use of the element in the file. <DT>
        <TT>LEVEL_FROZEN_TYPE_VP_FREEZE</TT> <DD>Turning on the viewport
        frozen flag makes an element on the level invisible only in the
        context of the model-ref. The specified model-ref should be either
        a layout model-ref, or a viewport model-ref or an attachment
        model-ref of a layout or a viewport. If the specified model-ref is
        an attachment model-ref, then the global frozen flag is propagated
        to all the model-refs (within the layout or viewport) with same
        file-object as the specified model-ref. </DL>
        
        Parameter ``modelRefIn``:
        model
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``frozenTypeIn``:
        one of <TT>LEVEL_FROZEN_TYPE_GLOBAL</TT> or
        <TT>LEVEL_FROZEN_TYPE_VP_FREEZE</TT> (defined in leveltable.h)
        
        Parameter ``frozenIn``:
        frozen flag - true or false
        
        Returns:
        SUCCESS if the level freeze flag is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **ERROR** <DD> if model-ref or level id is invalid
        or the level freeze cannot be set for some unspecified reason
        </DL>
        
        Remark:
        s A successful level freeze flag raises a LEVEL_CHANGE_DISPLAY
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        LevelTable.GetFrozenMask LevelTable.SetFrozenMask
        LevelTable.GetDisplayFrozenMask Level.IsFrozen
        Level.GetFrozen Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetHidden(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, hidden: bool) -> int:
        """
        @Description Set level hidden on/off. A Hidden Level will not be
        visible in the User Interface i.e. none of the Level Controls will
        display such a level. Applications can use this together with Element
        Access set to READ_ONLY/VIEW_ONLY to throw elements into the design
        file that can only be viewed. Using regular Microstation, the user has
        no control over such elements. By default Hidden is OFF
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``hiddenIn``:
        hidden flag - true or false
        
        Returns:
        SUCCESS if the level hidden flag is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorTableIsOfAttachment** <DD> the specified model-ref is
        for an attachment <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level hidden cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level hidden flag set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        LevelTable.GetHiddenMask Level.GetHidden Level.IsHidden
        Level.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetMaterialId(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, matrialId: int, materialOverride: bool) -> int:
        """
        @Description Set level material id.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``materialIdIn``:
        material id - may be NULL
        
        Parameter ``materialOverrideIn``:
        material override (true or false) - may be NULL
        
        Returns:
        SUCCESS if the level color is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level color cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level material id set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, materialIdIn is
        assumed to identify a material in the referenced file.
        
        See also:
        Level.GetMaterialId Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetName(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, name: str) -> int:
        """
        @Description Set level name. A level's name should be unique in the
        level table.
        
        Remark:
        
        Remark:
        s A space character is valid character, though leading and
        trailing spaces are disallowed. This function will strip off
        leading and trailing spaces from the specified name.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``nameIn``:
        level name
        
        Returns:
        SUCCESS if the level is successfully renamed.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorCannotChangeAttachmentLevelName**
        <DD> the specified model-ref is for an attachment <DT>
        **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
        read-only state <DT> **MSGID_errorCannotChangeExternalLevel** <DD>
        the specified level is a library level <DT>
        **MSGID_errorCannotChangeDefaultLevelName** <DD> the specified
        level is the default level <DT> **MSGID_errorLevelNameIsNull**
        <DD> the specified level name is null <DT>
        **MSGID_errorLevelNameIsInvalid** <DD> the specified level name
        has invalid characters <DT> **MSGID_errorLevelNameIsDuplicate**
        <DD> the specified level name is duplicate <DT> **ERROR** <DD> if
        model-ref or level id is invalid or the level name cannot be set
        for some unspecified reason </DL>
        
        Remark:
        s A successful level name set raises a LEVEL_CHANGE_NAME event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetName Level.GetPathName
        LevelName.HasValidCharacters
        LevelName.ReplaceInvalidCharacters LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetPlot(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, plot: bool) -> int:
        """
        @Description Set level plot on/off. Turning off the plot disables
        plotting of all elements on the level.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``plotIn``:
        plot flag - true or false
        
        Returns:
        SUCCESS if the level plot flag is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT> **ERROR** <DD> if model-ref or
        level id is invalid or the level plot cannot be set for some
        unspecified reason </DL>
        
        Remark:
        s A successful level plot flag set raises a LEVEL_CHANGE_ATTRIBUTE
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        LevelTable.GetPlotMask Level.GetPlot Level.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, isReadOnly: bool) -> int:
        """
        @Description Set level read-only on/off. Setting a level as read-only
        means that its attributes cannot be changed. (exception:setting the
        level's display on/off is not affected by this setting). A read-only
        level cannot be deleted.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``isReadOnlyIn``:
        read-only flag - true or false
        
        Returns:
        SUCCESS if the level read-only flag is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorTableIsOfAttachment** <DD> the
        specified model-ref is for an attachment <DT>
        **MSGID_errorLevelIsActive** <DD> the specified level is active
        and if setting the level to read-only <DT> **ERROR** <DD> if
        model-ref or level id is invalid or the level read-only flag
        cannot be set for some unspecified reason </DL>
        
        Remark:
        s A successful level read-only flag set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table.
        
        See also:
        LevelTable.GetReadOnlyMask Level.GetReadOnly
        Level.IsReadOnly Level.Rewrite
        
        See also:
        LevelTable.Rewrite
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetStyle(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, style: int, styleParams: MSPyDgnPlatform.LineStyleParams, styleOverride: bool) -> int:
        """
        @Description Set level style. This sets the style to apply on an
        element of the level, when " level symbology " is turned on for the
        view. This is also termed as the level's OVERRIDE style. Note that
        this function has an additional " override " flag. The " override " flag
        has to be ON in order to use the style.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``styleIn``:
        level style - may be NULL
        
        Parameter ``styleParamsIn``:
        custom line style modifiers - may be NULL
        
        Parameter ``styleOverrideIn``:
        level style override (true or false) - may be NULL
        
        Returns:
        SUCCESS if the level style is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level style cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level style set raises a LEVEL_CHANGE_ATTRIBUTE
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        Remark:
        s If modelRefIn is a DgnPlatform.DgnAttachment, then piStyleIn
        (if defined) is assumed to identify a style in the referenced
        file.
        
        See also:
        Level.GetStyle Level.GetSymbology
        msmthLevel.SetSymbologyC LevelTable.Rewrite
        
        See also:
        Level.GetSymbology Level.SetSymbology LevelTable.Rewrite
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetTransparency(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, transparency: float) -> int:
        """
        @Description Set level display transparency. This sets the display
        transparency to apply on an element of the level.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``transparencyIn``:
        level transparency (value between 0.0 & 1.0)
        
        Returns:
        SUCCESS if the level transparency is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level color cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level transparency set raises a
        LEVEL_CHANGE_ATTRIBUTE event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetTransparency LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetWeight(modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int, weight: int, weightOverride: bool) -> int:
        """
        @Description Set level weight. This sets the weight to apply on an
        element of the level, when " level symbology " is turned on for the
        view. This is also termed as the level's OVERRIDE weight. Note that
        this function has an additional " override " flag. The " override " flag
        has to be ON in order to use the weight.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelIdIn``:
        level id
        
        Parameter ``weightIn``:
        level weight
        
        Parameter ``weightOverrideIn``:
        level weight override - true or false
        
        Returns:
        SUCCESS if the level weight is successfully set.
        
        Remark:
        s Possible return failure codes are:<DL COMPACT> <DT>
        **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
        only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
        level is in a read-only state <DT>
        **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
        is a library level <DT> **ERROR** <DD> if model-ref or level id is
        invalid or the level weight cannot be set for some unspecified
        reason </DL>
        
        Remark:
        s A successful level weight set raises a LEVEL_CHANGE_ATTRIBUTE
        event.
        
        Remark:
        s Call LevelTable.Rewrite to save the updated level-table
        
        See also:
        Level.GetWeight Level.GetSymbology Level.SetSymbology
        LevelTable.Rewrite
        
        See also:
        LevelTable.Rewrite Bentley Systems
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class LevelAttribute:
    """
    None
    """

    @staticmethod
    def GetMask(attribyteType: LevelAttributeMaskType) -> MSPyDgnPlatform.BitMask:
        """
        Return the level-attribute bit-mask for a given attribute list type.
        
        Parameter ``attributeTypeIn``:
        level attribute mask type to get
        
        Returns:
        level attribute bit-mask for given type.
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class LevelChangeType:
    """
    Members:
    
    eLEVEL_TABLE_REWRITE
    
    eLEVEL_CREATE
    
    eLEVEL_DELETE
    
    eLEVEL_CHANGE_NAME
    
    eLEVEL_CHANGE_CODE
    
    eLEVEL_CHANGE_PARENT
    
    eLEVEL_CHANGE_DISPLAY
    
    eLEVEL_CHANGE_ATTRIBUTE
    
    eLEVEL_CHANGE_ACTIVE
    
    eLEVEL_LIBRARY_ATTACH
    
    eLEVEL_LIBRARY_DETACH
    
    eLEVEL_CHANGE_USAGE
    
    eLEVEL_CHANGE_ELEMENT_COUNT
    
    eLEVEL_TABLE_UNDO
    
    eLEVEL_TABLE_REDO
    
    eLEVEL_TABLE_IMPORT
    
    eLEVEL_PRE_CHANGE_ACTIVE
    
    eLEVEL_PRE_DELETE
    
    eLEVEL_REWRITE
    """

    def __init__(self: MSPyMstnPlatform.LevelChangeType, value: int) -> None:
        ...
    
    eLEVEL_CHANGE_ACTIVE: LevelChangeType
    
    eLEVEL_CHANGE_ATTRIBUTE: LevelChangeType
    
    eLEVEL_CHANGE_CODE: LevelChangeType
    
    eLEVEL_CHANGE_DISPLAY: LevelChangeType
    
    eLEVEL_CHANGE_ELEMENT_COUNT: LevelChangeType
    
    eLEVEL_CHANGE_NAME: LevelChangeType
    
    eLEVEL_CHANGE_PARENT: LevelChangeType
    
    eLEVEL_CHANGE_USAGE: LevelChangeType
    
    eLEVEL_CREATE: LevelChangeType
    
    eLEVEL_DELETE: LevelChangeType
    
    eLEVEL_LIBRARY_ATTACH: LevelChangeType
    
    eLEVEL_LIBRARY_DETACH: LevelChangeType
    
    eLEVEL_PRE_CHANGE_ACTIVE: LevelChangeType
    
    eLEVEL_PRE_DELETE: LevelChangeType
    
    eLEVEL_REWRITE: LevelChangeType
    
    eLEVEL_TABLE_IMPORT: LevelChangeType
    
    eLEVEL_TABLE_REDO: LevelChangeType
    
    eLEVEL_TABLE_REWRITE: LevelChangeType
    
    eLEVEL_TABLE_UNDO: LevelChangeType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelChangeType) -> int:
        ...
    
class LevelCountType:
    """
    Members:
    
    eLEVEL_COUNT_TYPE_ALL
    
    eLEVEL_COUNT_TYPE_USED
    
    eLEVEL_COUNT_TYPE_UNUSED
    
    eLEVEL_COUNT_TYPE_HIDDEN
    """

    def __init__(self: MSPyMstnPlatform.LevelCountType, value: int) -> None:
        ...
    
    eLEVEL_COUNT_TYPE_ALL: LevelCountType
    
    eLEVEL_COUNT_TYPE_HIDDEN: LevelCountType
    
    eLEVEL_COUNT_TYPE_UNUSED: LevelCountType
    
    eLEVEL_COUNT_TYPE_USED: LevelCountType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelCountType) -> int:
        ...
    
class LevelFrozenType:
    """
    Members:
    
    eLEVEL_FROZEN_TYPE_GLOBAL
    
    eLEVEL_FROZEN_TYPE_VP_FREEZE
    
    eLEVEL_FROZEN_TYPE_EFFECTIVE
    """

    def __init__(self: MSPyMstnPlatform.LevelFrozenType, value: int) -> None:
        ...
    
    eLEVEL_FROZEN_TYPE_EFFECTIVE: LevelFrozenType
    
    eLEVEL_FROZEN_TYPE_GLOBAL: LevelFrozenType
    
    eLEVEL_FROZEN_TYPE_VP_FREEZE: LevelFrozenType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelFrozenType) -> int:
        ...
    
class LevelIterateType:
    """
    Members:
    
    eLEVEL_ITERATE_TYPE_ALL_LEVELS
    
    eLEVEL_ITERATE_TYPE_USED_LEVELS
    
    eLEVEL_ITERATE_TYPE_UNUSED_LEVELS
    """

    def __init__(self: MSPyMstnPlatform.LevelIterateType, value: int) -> None:
        ...
    
    eLEVEL_ITERATE_TYPE_ALL_LEVELS: LevelIterateType
    
    eLEVEL_ITERATE_TYPE_UNUSED_LEVELS: LevelIterateType
    
    eLEVEL_ITERATE_TYPE_USED_LEVELS: LevelIterateType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelIterateType) -> int:
        ...
    
class LevelLibraryCountType:
    """
    Members:
    
    eLEVEL_LIBRARY_COUNT_TYPE_ALL
    
    eLEVEL_LIBRARY_COUNT_TYPE_MANUAL_ATTACHED
    
    eLEVEL_LIBRARY_COUNT_TYPE_AUTO_ATTACHED
    """

    def __init__(self: MSPyMstnPlatform.LevelLibraryCountType, value: int) -> None:
        ...
    
    eLEVEL_LIBRARY_COUNT_TYPE_ALL: LevelLibraryCountType
    
    eLEVEL_LIBRARY_COUNT_TYPE_AUTO_ATTACHED: LevelLibraryCountType
    
    eLEVEL_LIBRARY_COUNT_TYPE_MANUAL_ATTACHED: LevelLibraryCountType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelLibraryCountType) -> int:
        ...
    
class LevelLibraryFormat:
    """
    Members:
    
    eLEVEL_LIBRARY_FORMAT_ANY
    
    eLEVEL_LIBRARY_FORMAT_DGN
    
    eLEVEL_LIBRARY_FORMAT_CSV
    
    eLEVEL_LIBRARY_FORMAT_XML
    
    eLEVEL_LIBRARY_FORMAT_V7_LVL
    
    eLEVEL_LIBRARY_FORMAT_DWG
    """

    def __init__(self: MSPyMstnPlatform.LevelLibraryFormat, value: int) -> None:
        ...
    
    eLEVEL_LIBRARY_FORMAT_ANY: LevelLibraryFormat
    
    eLEVEL_LIBRARY_FORMAT_CSV: LevelLibraryFormat
    
    eLEVEL_LIBRARY_FORMAT_DGN: LevelLibraryFormat
    
    eLEVEL_LIBRARY_FORMAT_DWG: LevelLibraryFormat
    
    eLEVEL_LIBRARY_FORMAT_V7_LVL: LevelLibraryFormat
    
    eLEVEL_LIBRARY_FORMAT_XML: LevelLibraryFormat
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelLibraryFormat) -> int:
        ...
    
class LevelLibraryImportMethod:
    """
    Members:
    
    eLEVEL_LIBRARY_IMPORT_BY_ANY
    
    eLEVEL_LIBRARY_IMPORT_BY_NAME
    
    eLEVEL_LIBRARY_IMPORT_BY_CODE
    """

    def __init__(self: MSPyMstnPlatform.LevelLibraryImportMethod, value: int) -> None:
        ...
    
    eLEVEL_LIBRARY_IMPORT_BY_ANY: LevelLibraryImportMethod
    
    eLEVEL_LIBRARY_IMPORT_BY_CODE: LevelLibraryImportMethod
    
    eLEVEL_LIBRARY_IMPORT_BY_NAME: LevelLibraryImportMethod
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.LevelLibraryImportMethod) -> int:
        ...
    
class LevelName:
    """
    None
    """

    @staticmethod
    def HasValidCharacters(nameString: str) -> bool:
        """
        @Description Check if specified Name String is valid
        
        Parameter ``nameStringIn``:
        level name
        
        Returns:
        true if the Name String is valid, else false
        
        See also:
        LevelName.SetName LevelName.ReplaceInvalidCharacters Bentley
        Systems
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class LevelTable:
    """
    None
    """

    @staticmethod
    def DrawLevels(viewDraw: List[bool[8]], incremental: bool, drawMode: MSPyDgnPlatform.DgnDrawMode, modelRef: MSPyDgnPlatform.DgnModelRef, levelBitMask: MSPyDgnPlatform.BitMask, startEndMsg: bool, startShared: bool) -> int:
        """
        @Description Draw all elements on a list of specified levels
        
        Parameter ``viewDraw``:
        views to update. Should point to an array dimensioned to
        DgnPlatform.MAX_VIEWS, and viewDraw[i] controls whether view i is
        drawn. If NULL, all views are drawn.
        
        Parameter ``incrementalIn``:
        if false, don't erase before drawing
        
        Parameter ``drawModeIn``:
        erasing portion of drawing
        
        Parameter ``modelRefIn``:
        model ref
        
        Parameter ``levelBitMaskIn``:
        bitmask representing the list of levels to draw
        
        Parameter ``startEndMsgIn``:
        if true then want in prog/complete msg
        
        Parameter ``drawSharedIn``:
        if true, then draw all models/attachments which use the same level
        
        Returns:
        ERROR if the input level bit-mask is NULL or the model-ref is
        invalid, else SUCCESS
        
        See also:
        Level.Draw Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDisplayFrozenMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the effective combined display + frozen mask for
        level-table. Returns in a bit-mask form a represention of whether is
        level is displayed or not frozen (each bit is represented as:display-
        bit & inverse frozen-bit).
        
        @Remarks The bit-mask is 1 based. For example to get the display-
        frozen flag for a level with the function BitMask.TestBit, your
        call should look like:BitMask.TestBit(pDisplayFrozenBitMask,
        levelid -1) @Remarks Note the " const "ness of the returned bit-mask. It
        is important not to cast into a non-const bit-mask. This bit-mask
        should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The display + frozen mask as a BitMask. Returns NULL if modelRefIn
        is invalid. @Group " Level Tables "
        
        See also:
        usmthLevelTable.GetFrozenMaskC
        usmthLevelTable.GetDisplayMaskC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetDisplayMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the display mask for level-table. Returns a bit-mask
        that represents which level's display is turned on or off.
        
        @Remarks The bit-mask is 1 based. For example to get the display flag
        for a level with the function BitMask.TestBit, your call should
        look like:BitMask.TestBit(pDisplayBitMask, levelid -1) @Remarks
        Note the " const "ness of the returned bit-mask. It is important not to
        cast into a non-const bit-mask. This bit-mask should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The display mask as a BitMask. Returns NULL if modelRefIn is
        invalid. @Group " Level Tables "
        
        See also:
        usmthLevel.SetDisplayMaskC
        usmthLevelTable.GetDisplayFrozenMaskC usmthLevel.GetDisplayC
        usmthLevel.SetDisplayC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetExternalMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the external mask for level-table. Returns a bit-mask
        that represents whether a level is external or not. A level is
        external, if it is associated with a library level.
        
        @Remarks The bit-mask is 1 based. For example to get the external flag
        for a level with the function BitMask.TestBit, your call should
        look like:BitMask.TestBit(pExternalBitMask, levelid -1) @Remarks
        Note the " const "ness of the returned bit-mask. It is important not to
        cast into a non-const bit-mask. This bit-mask should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The external mask as a BitMask. Returns NULL if modelRefIn is
        invalid. @Group " Level Tables "
        
        See also:
        usmthLevel.GetExternalC usmthLevel.IsExternalC
        usmthLevel.GetLibraryRefC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetFrozenMask(modelRef: MSPyDgnPlatform.DgnModelRef, frozenType: MSPyMstnPlatform.LevelFrozenType) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the frozen mask for level-table. Returns a bit-mask
        that represents whether a level is frozen or not.
        
        @Remarks The bit-mask is 1 based. For example to get the frozen flag
        for a level with the function BitMask.TestBit, your call should
        look like:BitMask.TestBit(pFrozenBitMask, levelid -1) @Remarks
        Note the " const "ness of the returned bit-mask. It is important not to
        cast into a non-const bit-mask. This bit-mask should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``frozenTypeIn``:
        one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)
        
        Returns:
        The frozen mask as a BitMask. Returns NULL if modelRefIn is
        invalid. @Group " Level Tables "
        
        See also:
        usmthLevelTable.SetFrozenMaskC
        usmthLevelTable.GetDisplayFrozenMaskC usmthLevel.GetFrozenC
        usmthLevel.IsFrozenC usmthLevel.SetFrozenC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetHiddenMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the hidden mask for level-table. Returns a bit-mask
        that represents whether a level is hidden or not. If a level is
        hidden, then it is not displayed in the level manager.
        
        @Remarks The bit-mask is 1 based. For example to get the hidden flag
        for a level with the function BitMask.TestBit, your call should
        look like:BitMask.TestBit(pHiddenBitMask, levelid -1) @Remarks
        Note the " const "ness of the returned bit-mask. It is important not to
        cast into a non-const bit-mask. This bit-mask should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The hidden mask as a BitMask. Returns NULL if modelRefIn is
        invalid. @Group " Level Tables "
        
        See also:
        usmthLevel.GetHiddenC usmthLevel.IsHiddenC
        usmthLevel.SetHiddenC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetHighestLevelCode(modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        @Description Get the value of highest used level code in level-table.
        
        Parameter ``highestLevelCodeOut``:
        highest level code
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        ERROR if the model-ref is invalid or pHighestLevelCode is NULL,
        else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetHighestLevelId(modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        @Description Get the value of highest used level id in level-table.
        
        Parameter ``highestLevelIdOut``:
        highest level id
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        ERROR if the model-ref is invalid or highestLevelIdOut is NULL,
        else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetLevelCount(modelRef: MSPyDgnPlatform.DgnModelRef, levelCountType: int) -> tuple:
        """
        @Description Get the number of levels in level-table.
        
        Parameter ``levelCountOut``:
        level count in level-table
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``levelCountTypeIn``:
        one of <TT>LEVEL_COUNT_TYPE_</TT>... (defined in leveltable.h)
        
        Remark:
        s The return value of levelCountOut will depend on value of
        levelCountTypeIn as follows:<TABLE border=" 1 " cellspacing=" 3 "
        cellpadding=" 3 "> <TR> <TH>levelCountTypeIn</TH>
        <TH>levelCountOut</TH> </TR> <TR>
        <TD><TT>LEVEL_COUNT_TYPE_ALL</TT></TD> <TD>The number of levels in
        level table</TD> </TR> <TR>
        <TD><TT>LEVEL_COUNT_TYPE_USED</TT></TD> <TD>The number of used
        levels in level table</TD> </TR> <TR>
        <TD><TT>LEVEL_COUNT_TYPE_UNUSED</TT></TD> <TD>The number of un-
        used levels in level table</TD> </TR> </TABLE>
        
        Returns:
        ERROR if the model-ref is invalid or levelCountOut is NULL, else
        SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetPlotMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the plot mask for level-table. Returns a bit-mask
        that represents which level's plot is turned on or off.
        
        @Remarks The bit-mask is 1 based. For example to get the plot flag for
        a level with the function BitMask.TestBit, your call should look
        like:BitMask.TestBit(pPlotBitMask, levelid -1) @Remarks Note the
        " const "ness of the returned bit-mask. It is important not to cast into
        a non-const bit-mask. This bit-mask should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The plot mask as a BitMask. Returns NULL if modelRefIn is invalid
        @Group " Level Tables "
        
        See also:
        usmthLevel.GetPlotC usmthLevel.SetPlotC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        @Description Get read-only flag of level-table.
        
        Parameter ``isReadOnlyOut``:
        read-only flag - true or false
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        ERROR if the model-ref is invalid or isReadOnlyOut is NULL, else
        SUCCESS
        
        See also:
        LevelTable.IsReadOnly LevelTable.SetReadOnly Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetReadOnlyMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the read-only mask for level-table. Returns a bit-
        mask that represents whether a level is read-only or not. If a level
        is readonly, then its attributes cannot be changed.
        
        @Remarks The bit-mask is 1 based. For example to get the read-only
        flag for a level with the function BitMask.TestBit, your call
        should look like:BitMask.TestBit(pReadOnlyBitMask, levelid -1)
        @Remarks Note the " const "ness of the returned bit-mask. It is
        important not to cast into a non-const bit-mask. This bit-mask should
        not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The read-only mask as a BitMask. Returns NULL if modelRefIn is
        invalid. @Group " Level Tables "
        
        See also:
        usmthLevel.GetReadOnlyC usmthLevel.IsReadOnlyC
        usmthLevel.SetReadOnlyC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetUsageMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BitMask:
        """
        @Description Get the level usage mask for level-table. Returns a bit-
        mask that represents whether a level is used or not.
        
        @Remarks The bit-mask is 1 based. For example to get the used flag for
        a level with the function BitMask.TestBit, your call should look
        like:BitMask.TestBit(pUsedBitMask, levelid -1) @Remarks Note the
        " const "ness of the returned bit-mask. It is important not to cast into
        a non-const bit-mask. This bit-mask should not be changed.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        The usage mask as a BitMask. Returns NULL if modelRefIn is
        invalid. @Group " Level Tables "
        
        See also:
        usmthLevel.GetUsageC usmthLevel.IsUsedC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Check if level-table is read-only.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        true if the level-table is read-only, else false
        
        Remark:
        s If modelRefIn is invalid, then the function returns false.
        
        See also:
        LevelTable.GetReadOnly LevelTable.SetReadOnly Bentley
        Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Rewrite(modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Rewrite the level-table data into current-file. This
        action has one of the following effects:<UL> <LI> If the level-table
        does not exist in the file, then it is added into the file. <LI> If
        the level-table already exists in the file, then the information in
        this level-table is updated based on changes made to the level-data.
        <LI> For an attachment's level-table, if there are no more any
        override levels, then this function will remove the attachment's
        override level-table from file. </UL>
        
        <p> This function should be called whenever any of the level-table's
        data is changed by calls to any of the Level.Set... or
        LevelTable.Set... functions. The call to LevelTable.Rewrite will
        make the changes permanent. Otherwise, the changes will be valid only
        in the current session. The call to LevelTable.Rewrite is
        accumalative, i.e. it writes all the changes made to level data. In
        other words, multiple changes in the context of a single model-ref can
        be made before calling LevelTable.Rewrite. The rewrite function
        will rewrite all the changes made to levels of the specified model-
        ref. </p>
        
        @Remarks A successful write to file raises a LEVEL_TABLE_REWRITE
        event.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Returns:
        ERROR if the model-ref is invalid, else SUCCESS
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDisplayMask(modelRef: MSPyDgnPlatform.DgnModelRef, displayMask: MSPyDgnPlatform.BitMask, updateView: bool) -> int:
        """
        @Description Set the display flag for all levels of level-table.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``displayMaskIn``:
        level display mask to set
        
        Parameter ``updateViewIn``:
        if true, then update the views
        
        Returns:
        ERROR if the model-ref is invalid or the level-table is READ-ONLY,
        else SUCCESS @Group " Level Tables "
        
        See also:
        usmthLevel.GetDisplayMaskC usmthLevel.GetDisplayC
        usmthLevel.SetDisplayC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetFrozenMask(modelRef: MSPyDgnPlatform.DgnModelRef, frozenMask: MSPyDgnPlatform.BitMask, frozenType: MSPyMstnPlatform.LevelFrozenType, updateView: bool) -> int:
        """
        @Description Set the frozen flag for all levels of level-table.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``frozenMaskIn``:
        level frozen mask to set
        
        Parameter ``frozenTypeIn``:
        one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)
        
        Parameter ``updateViewIn``:
        if true, then update the views
        
        Returns:
        ERROR if the model-ref is invalid or the level-table is READ-ONLY,
        else SUCCESS @Group " Level Tables "
        
        See also:
        usmthLevelTable.GetFrozenMaskC
        usmthLevelTable.GetDisplayFrozenMaskC usmthLevel.GetFrozenC
        usmthLevel.IsFrozenC usmthLevel.SetFrozenC Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef, isReadOnly: bool) -> int:
        """
        @Description Set read-only flag of level-table. Setting a level-table
        as read-only has the following implications:<UL> <LI>No new levels
        can be created in the level-table. <LI>None of the exisiting levels
        can be deleted from the level-table. <LI>None of the level attributes
        can be modified. <LI>No new level library can be attached to the
        level-table. <LI>None of the existing level libraries can be detached
        from the level-table. </UL> By default, read-only is OFF.
        
        Parameter ``modelRefIn``:
        model-ref of level-table
        
        Parameter ``isReadOnlyIn``:
        read-only flag - true or false
        
        Returns:
        ERROR if the model-ref is invalid, else SUCCESS
        
        See also:
        LevelTable.IsReadOnly LevelTable.GetReadOnly Bentley Systems
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MSDocumentManager:
    """
    None
    """

    def CompareDocumentWorkspaces(self: MSPyMstnPlatform.MSDocumentManager, document1: MSPyDgnPlatform.DgnDocumentMoniker, document2: MSPyDgnPlatform.DgnDocumentMoniker, generatorArgs: str) -> tuple:
        """
        Compares workspace of two documents
        
        
        
        
        Parameter ``document1``:
        Moniker to first document of which workspace is to be compared
        with that of second document.
        
        Parameter ``document2``:
        Moniker to second document of which workspace is to be compared
        with that of first document.
        
        Parameter ``generatorArgs``:
        Arguments for worker process *
        
        Returns (Tuple, 0):
        SUCCESS if comparison is done successfully.
        
        
        Returns (Tuple, 1):
        profilesEqual. Reference to a bool. Its value will be true if workspaces are
        equal.
        """
        ...
    
    def CreateDgnBaseMonikerList(self: MSPyMstnPlatform.MSDocumentManager) -> MSPyDgnPlatform.DgnBaseMonikerList:
        ...
    
    def CreateFolderMonikerList(self: MSPyMstnPlatform.MSDocumentManager) -> MSPyDgnPlatform.DgnFolderMonikerList:
        ...
    
    def CreateMonikerList(self: MSPyMstnPlatform.MSDocumentManager) -> MSPyDgnPlatform.DgnDocumentMonikerList:
        ...
    
    def CreateNewDocumentDialog(self: MSPyMstnPlatform.MSDocumentManager, params: MSPyMstnPlatform.PyDocumentOpenDialogParams, overwriteMode: MSPyDgnPlatform.DgnDocument.OverwriteMode) -> tuple:
        """
        Create a new document, using a dialog to browse for the file name and
        location. Optionally, test for the existence of the file, and
        optionally prompt the user for whether to overwrite the file or not.
        
        
        
        Parameter ``params``:
        A structure containing file open parameters. The entire structure
        should be memset to 0 and then individual fields set as necessary.
        
        Parameter ``overwriteMode``:
        Sepcifies what to do if the document already exists *
        
        Returns(Tuple, 0):
        An DgnDocument that represents the file. On failure, NULL is
        Returned.
        
        Returns (Tuple, 1):
        status.  this gives an indication of why.
        """
        ...
    
    def DeleteDocument(*args, **kwargs):
        """
        DeleteDocument(self: MSPyDgnPlatform.DgnDocumentManager, doc: MSPyDgnPlatform.DgnDocument, options: MSPyDgnPlatform.DgnDocumentManager.DeleteOptions = <DeleteOptions.eDefault: 0>) -> int
        
        @name Methods to manage documents in the DMS repository Remove the
        document from the DMS.
        
        Remark:
        s If the DMS is the native file system, this method deletes the
        disk file.
        """
        ...
    
    def DeleteFolder(*args, **kwargs):
        """
        DeleteFolder(self: MSPyDgnPlatform.DgnDocumentManager, folderMoniker: MSPyDgnPlatform.DgnFolderMoniker, options: MSPyDgnPlatform.DgnDocumentManager.DeleteOptions = <DeleteOptions.eDefault: 0>) -> int
        
        Remove the folder from the DMS.
        """
        ...
    
    class DeleteOptions:
        """
        Members:
        
        eDefault
        
        eAllowRestore
        
        eIncludeSubItems
        """
    
        def __init__(self: MSPyDgnPlatform.DgnDocumentManager.DeleteOptions, value: int) -> None:
            ...
        
        eAllowRestore: DeleteOptions
        
        eDefault: DeleteOptions
        
        eIncludeSubItems: DeleteOptions
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnPlatform.DgnDocumentManager.DeleteOptions) -> int:
            ...
        
    class DgnBrowserStatus:
        """
        Members:
        
        eSuccess
        
        eCancel
        
        eNoIntegrationLoaded
        """
    
        def __init__(self: MSPyDgnPlatform.DgnDocumentManager.DgnBrowserStatus, value: int) -> None:
            ...
        
        eCancel: DgnBrowserStatus
        
        eNoIntegrationLoaded: DgnBrowserStatus
        
        eSuccess: DgnBrowserStatus
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyDgnPlatform.DgnDocumentManager.DgnBrowserStatus) -> int:
            ...
        
    @staticmethod
    def GetManager() -> MSPyMstnPlatform.MSDocumentManager:
        """
        Obtain a reference to MicroStation's document manager. To call methods
        on the document manager, use MSDocumentManager.GetManager().Method
        
        Returns:
        The document manager *
        """
        ...
    
    def OpenDocumentDialog(self: MSPyMstnPlatform.MSDocumentManager, params: MSPyMstnPlatform.PyDocumentOpenDialogParams, attributes: MSPyMstnPlatform.FileOpenExtAttr, openMode: MSPyDgnPlatform.DgnDocument.FetchMode) -> tuple:
        """
        Browse for a document. This will browse the current repository, if one
        is active, and the file system if the current session of MicroStation
        is not integrated with a document management system.
        
        
        Parameter ``params``:
        A structure containing file open parameters. The entire structure
        should be memset to 0 and then individual fields set as necessary.
        
        Parameter ``attributes``:
        MicroStation file open dialog attribues (FILEOPENEXTATTR flagword)
        
        Parameter ``openMode``:
        With what access the DgnDocument should be fetched from the DMS,
        if integrated, or what file access is required of the local file,
        if not integrated.. *
        
        Returns (Tuple, 0):
        An DgnDocument that represents the file. If the file cannot be
        found or cannot be accessed, NULL is returned.
        
        Returns (Tuple, 1):
        status. this gives an indication of why.
        """
        ...
    
    def OpenFolderBrowser(self: MSPyDgnPlatform.DgnDocumentManager, status: MSPyDgnPlatform.DgnDocumentManager.DgnBrowserStatus, defaults: Bentley.DgnPlatform.DgnFolderBrowserDefaults) -> MSPyDgnPlatform.DgnFolderMoniker:
        """
        Browse for a folder in the DMS
        """
        ...
    
    def OpenFolderDialog(self: MSPyMstnPlatform.MSDocumentManager, params: MSPyMstnPlatform.PyDocumentOpenDialogParams, attributes: int, basePath: str, fetchMode: MSPyDgnPlatform.DgnDocument.FetchMode) -> tuple:
        """
        Parameter ``attributes``:
        MicroStation file list attribues (FILELISTATTR flagword) *
        
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        status.
        """
        ...
    
    def PortableNameFromFullPath(portableName: MSPyBentley.WString, fullPath: str, basePath: str, dirCfgVar: str, relative: MSPyDgnPlatform.RelativePathPreference) -> None:
        """
        Creates a portable file name given the data that is returned from the
        File Open dialog. A portable name never includes explicit disk drive
        and path information.
        
        Parameter ``portableName``:
        A portable file name that can be used in a moniker that is to be
        persisted in a design file.
        
        Parameter ``fullPath``:
        The full file path to the file for which the portableName is
        generated.
        
        Parameter ``basePath``:
        The full file path to the file in which the portableName will be
        persisted.
        
        Parameter ``dirCfgVar``:
        If not NULL, this is a configuration variable whose value is the
        directory in fullPath.
        
        Parameter ``relative``:
        The preference for relative paths. If Allow or CreateIfPossible,
        and dirCfgVar is NULL, attempts to make the portableName a
        relative path from basePath to fullPath. @note If dirCfgVar is not
        NULL, the portable name will consist of the dirCfgVar and the
        filename and extension from fullPath. @note If fullPath and
        basePath are not on the same physical drive, it is not possible to
        create a relative path between them.
        """
        ...
    
    def PortableNameFromUserEnteredFileName(portableName: MSPyBentley.WString, userEnteredPath: str, fullPath: str, basePath: str, relativePref: MSPyDgnPlatform.RelativePathPreference) -> None:
        """
        Creates a portable file name given the data that is keyed in by a
        user. A portable name never includes explicit disk drive and path
        information.
        
        Parameter ``portableName``:
        A portable file name that can be used in a moniker that is to be
        persisted in a design file.
        
        Parameter ``userEnteredPath``:
        The file name that the user keyed in. If not NULL, as much as
        possible of it is used to generate portableName.
        
        Parameter ``fullPath``:
        Identifies the disk file to which the portable moniker should
        point. This is often the full file name as returned from the File
        Open dialog box.
        
        Parameter ``basePath``:
        The base path that the caller will use relative searches for the
        file represented by the portable moniker. If the portable moniker
        is to be persisted in a DgnFile, basePath is usually the path of
        that DgnFile.
        
        Parameter ``relativePref``:
        The preference for relative paths. If Allow, accepts relative
        paths that are in userEnteredPath. If CreateIfPossible, attempts
        to create a relative path. If Never, discards relative paths.
        @note If userEnteredPath does not contain an extension, but
        fullPath does contain an extension, the extension in fullPath will
        be the extension in portableName. @note If userEnteredPath starts
        with a configuration variable name followed by a colon, that
        configuration variable and any path information following it is
        retained, and relativePref is ignored. @note If fullPath and
        basePath are not on the same physical drive, it is not possible to
        create a relative path between them.
        """
        ...
    
    def PutDocumentList(self: MSPyMstnPlatform.MSDocumentManager, docs: Bentley.MstnPlatform.DgnDocumentList, putAction: MSPyDgnPlatform.DgnDocument.PutAction, putOptions: MSPyDgnPlatform.DgnDocument.PutOptions, comment: str = None) -> int:
        """
        commit the local copies of this DgnDocumentList to the DMS *
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eAllowRestore: DeleteOptions
    
    eCancel: DgnBrowserStatus
    
    eDefault: DeleteOptions
    
    eIncludeSubItems: DeleteOptions
    
    eNoIntegrationLoaded: DgnBrowserStatus
    
    eSuccess: DgnBrowserStatus
    
class MSInputQueuePos:
    """
    Members:
    
    eINPUTQ_HEAD
    
    eINPUTQ_EOQ
    """

    def __init__(self: MSPyMstnPlatform.MSInputQueuePos, value: int) -> None:
        ...
    
    eINPUTQ_EOQ: MSInputQueuePos
    
    eINPUTQ_HEAD: MSInputQueuePos
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.MSInputQueuePos) -> int:
        ...
    
class MdlErrorValues:
    """
    Members:
    
    eMDLERR_NOTRANSFORM
    
    eMDLERR_BADVIEWNUMBER
    
    eMDLERR_INSFINFO
    
    eMDLERR_FILE2SUB3
    
    eMDLERR_BADELEMENT
    
    eMDLERR_INVREGEX
    
    eMDLERR_BADMODELREF
    
    eMDLERR_BADFILENUMBER
    
    eMDLERR_BADSLOT
    
    eMDLERR_FILEREADONLY
    
    eMDLERR_DISKFULL
    
    eMDLERR_WRITEINHIBIT
    
    eMDLERR_WRITEFAILED
    
    eMDLERR_MODIFYCOMPLEX
    
    eMDLERR_CANNOTOPENFILE
    
    eMDLERR_ENDOFFILE
    
    eMDLERR_BADSCANLIST
    
    eMDLERR_INSFMEMORY
    
    eMDLERR_NOTCMPLXHDR
    
    eMDLERR_ALREADYLOADED
    
    eMDLERR_BADFILETYPE
    
    eMDLERR_READFAILED
    
    eMDLERR_NOSUCHAPPLICATION
    
    eMDLERR_REJECTED
    
    eMDLERR_NOMATCH
    
    eMDLERR_AMBIGUOUS
    
    eMDLERR_BADARG
    
    eMDLERR_BADCOPYPARALLEL
    
    eMDLERR_RESOURCENOTFOUND
    
    eMDLERR_NOCELLLIBRARY
    
    eMDLERR_VIEWNOTDISPLAYED
    
    eMDLERR_CELLNOTFOUND
    
    eMDLERR_CELLEXISTS
    
    eMDLERR_INVALIDCELL
    
    eMDLERR_BADINDEX
    
    eMDLERR_CELLTOOLARGE
    
    eMDLERR_INVALIDLIBRARY
    
    eMDLERR_BADLINKERINFO
    
    eMDLERR_NOTAVAILABLE
    
    eMDLERR_CELLLIB2DGN3
    
    eMDLERR_MAXMCSLTASKS
    
    eMDLERR_SYSTEMERROR
    
    eMDLERR_TIMEOUT
    
    eMDLERR_PROGRAMTERMINATED
    
    eMDLERR_USERABORT
    
    eMDLERR_ELEMENTFROZEN
    
    eMDLERR_NOEXTPGMSTACK
    
    eMDLERR_REJECTEDBYINIT
    
    eMDLERR_TOOLARGE
    
    eMDLERR_NOKEYS
    
    eMDLERR_SHMEMNOTFOUND
    
    eMDLERR_DUPTASKID
    
    eMDLERR_BADSCREENNUMBER
    
    eMDLERR_NULLOUTPUTBUFFER
    
    eMDLERR_BADRASTERFORMAT
    
    eMDLERR_NOTSUPPORTED
    
    eMDLERR_DLMNOTALLOWED
    
    eMDLERR_TOOMANYSURFACEELMS
    
    eMDLERR_ELEMTOOLARGE
    
    eMDLERR_LINKAGENOTFOUND
    
    eMDLERR_NAMENOTUNIQUE
    
    eMDLERR_MODELNOTEMPTY
    
    eMDLERR_NOCHANGE
    
    eMDLERR_OPERVIOLATESCONSTRAINTS
    
    eMDLERR_RELATIVECELLLEVELNOTFOUND
    
    eMDLERR_FILENOTFOUND
    
    eMDLERR_NOFENCE
    
    eMDLERR_NOCLIPVOLUME
    
    eMDLERR_NAMETOOLONG
    
    eMDLERR_BADMODELID
    
    eMDLERR_MODELNAMEEXISTS
    
    eMDLERR_MODELIDEXISTS
    
    eMDLERR_NOMODELINFO
    
    eMDLERR_NOPARENTMODEL
    
    eMDLERR_CANTCREATEFILE
    
    eMDLERR_CANTSAVEFILE
    
    eMDLERR_V7CELLLIBRARY
    
    eMDLERR_FILEEXISTS
    
    eMDLERR_V8B2CELLLIBRARY
    
    eMDLERR_FARASSOCREQUIRED
    
    eMDLERR_ELMENTNOTFOUND
    
    eMDLERR_IDNOTFOUND
    
    eMDLERR_IDEXISTS
    
    eMDLERR_CACHENOTENABLED
    
    eMDLERR_WRONGELEMID
    
    eMDLERR_CACHEINUSE
    
    eMDLERR_CACHENOTFOUND
    
    eMDLERR_BADNAME
    
    eMDLERR_NOTOPEN
    
    eMDLERR_SHARINGVIOLATION
    
    eMDLERR_ACCESSVIOLATION
    
    eMDLERR_ALREADYOPEN
    
    eMDLERR_BADWORDSTOFOLLOW
    
    eMDLERR_ALREADYEXISTS
    
    eMDLERR_BADFORMAT
    
    eMDLERR_BADVERSION
    
    eMDLERR_TOOMANYOPENFILES
    
    eMDLERR_OPERATIONCANCELED
    
    eMDLERR_UNKNOWNERROR
    
    eMDLERR_BADFILE
    
    eMDLERR_CANNOTOPENSEED
    
    eMDLERR_INVALIDOPERATIONFORNESTED
    
    eMDLERR_INVALIDOPERATIONFORNONNESTED
    
    eMDLERR_NOTLOADED
    
    eMDLERR_NOMODEL
    
    eMDLERR_HASCHANGES
    
    eMDLERR_LOADINGINTERFACE
    
    eMDLERR_COMPRESSIONERROR
    
    eMDLERR_UNKNOWNFORMAT
    
    eMDLERR_NOSUCHMODEL
    
    eMDLERR_NOTLOCKED
    
    eMDLERR_CANNOTIMPORTSEED
    
    eMDLERR_CACHELOADERROR
    
    eMDLERR_RENAMEERROR
    
    eMDLERR_COPYERROR
    
    eMDLERR_CACHENOTFILLED
    
    eMDLERR_ACCUDRAWNOTENABLED
    
    eMDLERR_MUNOTLARGERTHANSU
    
    eMDLERR_NOTSAMEUNITBASE
    
    eMDLERR_NOTCOMPLEXHEADER
    
    eMDLERR_ADDINGCOMPLEXELEMENT
    
    eMDLERR_2D3D_MISMATCH
    
    eMDLERR_REPLACING_DELETED
    
    eMDLERR_OVERSIZE_ELEMENT
    
    eMDLERR_UNDERSIZE_ELEMENT
    
    eMDLERR_BADELEMENTTYPE
    
    eMDLERR_STYLENOTFOUND
    
    eMDLERR_TOOMANYITERATIONS
    
    eMDLERR_ANONYMOUS_SHAREDCELL
    
    eMDLERR_STYLEISUSED
    
    eMDLERR_CAPABILITYRESTRICTION
    
    eMDLERR_INVALIDFORNEUTRALMDL
    
    eMDLERR_ALLMODELSFILTEREDOUT
    
    eMDLERR_NONPLANARELEMENT
    
    eMDLERR_NOASSOCIATEDTEMPLATE
    
    eMDLERR_HISTORYREVISIONNOTFOUND
    
    eMDLERR_MISSINGIMAGEBAND
    
    eMDLERR_NOMASTERFILE
    
    eMDLERR_NOTSUPPORTEDACTIVATEDREF
    
    eMDLERR_GEOCOORD_REFTRANSFORMDISABLED
    
    eMDLERR_GEOCOORD_NOMASTERGCS
    
    eMDLERR_GEOCOORD_NOREFGCS
    
    eMDLERR_GEOCOORD_NOGEOCODE
    
    eMDLERR_GEOCOORD_NOTGEOTRANSFORMED
    
    eMDLERR_GEOCOORD_NEEDSRECALCULATION
    
    eMDLERR_GEOCOORD_UNITSWRONG
    
    eMDLERR_NOPOLES
    
    eMDLERR_NOKNOTS
    
    eMDLERR_NOWEIGHTS
    
    eMDLERR_NOBOUNDS
    
    eMDLERR_NONUMBOUNDS
    
    eMDLERR_NOBSPHEADER
    
    eMDLERR_TOOFEWPOLES
    
    eMDLERR_TOOMANYPOLES
    
    eMDLERR_BADBSPELM
    
    eMDLERR_BADPARAMETER
    
    eMDLERR_BADORDER
    
    eMDLERR_BADPERIODICITY
    
    eMDLERR_BADPOLES
    
    eMDLERR_BADKNOTS
    
    eMDLERR_BADWEIGHTS
    
    eMDLERR_BADSPIRALDEFINITION
    
    eMDLERR_TOOMANYKNOTS
    
    eMDLERR_NOOFFSETINTERSECTION
    
    eMDLERR_BADCONTINUITY
    
    eMDLERR_RECURSELIMIT
    
    eMDLERR_CANNOTDELETEDEFAULTMODEL
    
    eMDLERR_SYMBOLTOOLONG
    
    eMDLERR_INVALID_FOR_RESTRICTED_PRODUCT
    
    eMDLERR_FIRSTEXPRERROR
    
    eMDLERR_ALREADYINUSE
    
    eMDLERR_BADTYPE
    
    eMDLERR_NEEDINT
    
    eMDLERR_STRUCTNEEDED
    
    eMDLERR_RIGHT_NOT_GRANTED_FOR_OPERATION
    
    eMDLERR_BADHEX
    
    eMDLERR_NEEDEXPONENT
    
    eMDLERR_BADOCTAL
    
    eMDLERR_BADFLOAT
    
    eMDLERR_BADSTRING
    
    eMDLERR_BADCHARCONS
    
    eMDLERR_ILLEGALCHAR
    
    eMDLERR_UNSUPPORTED
    
    eMDLERR_NOSYMBOL
    
    eMDLERR_SYNTAXERROR
    
    eMDLERR_INVALIDSYMBOL
    
    eMDLERR_TYPESINCOMPATIBLE
    
    eMDLERR_CANNOTDEREF
    
    eMDLERR_NOTSTRUCT
    
    eMDLERR_NOTMEMBER
    
    eMDLERR_ADDRNOTKNOWN
    
    eMDLERR_TOOCOMPLEX
    
    eMDLERR_INVALIDFORSTRUCT
    
    eMDLERR_INVALIDFORFLOAT
    
    eMDLERR_DIVIDEBYZERO
    
    eMDLERR_ADDRNOTVALID
    
    eMDLERR_INVALIDFORTYPE
    
    eMDLERR_INTEGRALNEEDED
    
    eMDLERR_NOTVALIDEXPRESS
    
    eMDLERR_NOTFUNCTION
    
    eMDLERR_TOOMANYARGUMENTS
    
    eMDLERR_TOOFEWARGUMENTS
    
    eMDLERR_BADRSCTYPE
    
    eMDLERR_INVALIDFORFUNC
    
    eMDLERR_LASTEXPRERROR
    
    eMDLERR_INVALIDACSTYPE
    
    eMDLERR_INVALIDBUTTON
    
    eMDLERR_NOTDESIGNFILE
    
    eMDLERR_3DREF2DMASTER
    
    eMDLERR_DUPLICATELOGICAL
    
    eMDLERR_NOTSINGLEVIEW
    
    eMDLERR_INVALIDREFORG
    
    eMDLERR_INVALIDMASTERORG
    
    eMDLERR_INVALIDREF
    
    eMDLERR_INVALIDCLIP
    
    eMDLERR_INVALIDPATSPACE
    
    eMDLERR_NONCLOSEDPATELM
    
    eMDLERR_NONSOLIDPATELM
    
    eMDLERR_NONCLOSEDELM
    
    eMDLERR_ELMFILLED
    
    eMDLERR_ELMNOTFILLED
    
    eMDLERR_ELMTOOLARGE
    
    eMDLERR_ELMNOTPLANAR
    
    eMDLERR_NULLSOLUTION
    
    eMDLERR_UNBOUNDEDSOLUTION
    
    eMDLERR_NONCOPLANARSHAPES
    
    eMDLERR_OLDMATERIALTABLE
    
    eMDLERR_NOSELECTIONSET
    
    eMDLERR_NOREFSLOTS
    
    eMDLERR_NOACSDEFINED
    
    eMDLERR_ACSREPLACED
    
    eMDLERR_ACSNOTFOUND
    
    eMDLERR_VIEWNOTFOUND
    
    eMDLERR_NOGRAPHICGROUP
    
    eMDLERR_VIEWGROUPNOTFOUND
    
    eMDLERR_NOLEVELMASK
    
    eMDLERR_NOTDIRECTATTACHMENT
    
    eMDLERR_MODELNOTFOUND
    
    eMDLERR_RELOADNOTNEEDED
    
    eMDLERR_COINCIDENTSELFREF
    
    eMDLERR_REDUNDANTREF
    
    eMDLERR_BADFONT
    
    eMDLERR_BADTEXTSTYLE
    
    eMDLERR_NOINTERNALMATERIALS
    
    eMDLERR_COMMANDRECEIVED
    
    eMDLERR_RSCERROR
    
    eMDLERR_RSCFILEERROR
    
    eMDLERR_RSCHANDLEINVALID
    
    eMDLERR_RSCFILENOTFOUND
    
    eMDLERR_RSCINSFMEM
    
    eMDLERR_RSCWRITEERROR
    
    eMDLERR_RSCWRITEVIOLATION
    
    eMDLERR_RSCADDRINVALID
    
    eMDLERR_RSCTYPEINVALID
    
    eMDLERR_RSCALREADYEXISTS
    
    eMDLERR_RSCBADVERSION
    
    eMDLERR_RSCINUSE
    
    eMDLERR_RSCNOTFOUND
    
    eMDLERR_RSCSTRINGNOTFOUND
    
    eMDLERR_RSCQRYIDINVALID
    
    eMDLERR_RSCDIRECTADDPEND
    
    eMDLERR_RSCBADRANGETREE
    
    eMDLERR_RSCFILENOTOPEN
    
    eMDLERR_RSCBADRSCSIZE
    
    eMDLERR_RSCINVALIDFILEHANDLE
    
    eMDLERR_RSCALIASREQUIRED
    
    eMDLERR_RSCFILECORRUPT
    
    eMDLERR_RSCFOPENFAILURE
    
    eMDLERR_RSCFILEHANDLETABLEFULL
    
    eMDLERR_RSCCONDITIONFALSE
    
    eMDLERR_LICHANDLENOTFOUND
    
    eMDLERR_NOLICENSEAVAILABLE
    
    eMDLERR_BADVRBLARRAYSIZE
    
    eMDLERR_NOTCONVRULES
    
    eMDLERR_BADDATADEF
    
    eMDLERR_DATADEFNOTFOUND
    
    eMDLERR_BUFFERALIGNMENTSDIFFER
    
    eMDLERR_OUTPUTBUFFERWRONGALIGNMENT
    
    eMDLERR_INVALIDPLATFORMID
    
    eMDLERR_VOIDDATATYPE
    
    eMDLERR_INPUTBUFFERWRONGALIGNMENT
    
    eMDLERR_BADCOLORPALETTE
    
    eMDLERR_BADCOLORPALETTEINDEX
    
    eMDLERR_BADCOLORPALETTEDATA
    
    eMDLERR_BADSETMETHODID
    
    eMDLERR_PALETTEWRONGSIZE
    
    eMDLERR_BADCOLORTABLE
    
    eMDLERR_COLORMGRNOTINITIALIZED
    
    eMDLERR_BADCOLORDESCR
    
    eMDLERR_NOQUEUEENTRIES
    
    eMDLERR_QUEUEFULL
    
    eMDLERR_QUEUEERROR
    
    eMDLERR_NOMESSAGE
    
    eMDLERR_ATTRUNDEFTYPE
    
    eMDLERR_ATTRSETNAMELONG
    
    eMDLERR_ATTRSETNOTFOUND
    
    eMDLERR_ATTRNOTINSET
    
    eMDLERR_ATTRSETPREVDEFINED
    
    eMDLERR_ATTRSETTOOBIG
    
    eMDLERR_ATTRBADRPTFILE
    
    eMDLERR_ATTRBADRPTKEYWORD
    
    eMDLERR_ATTRBADASSOC
    
    eMDLERR_ATTRNOTARGET
    
    eMDLERR_ATTRPREVDEFINED
    
    eMDLERR_ATTRNOTFOUND
    
    eMDLERR_NOMDLPLOTDRIVERINPLT
    
    eMDLERR_MACROSTILLRUNNING
    
    eMDLERR_MACRONOTSTARTED
    
    eMDLERR_CANNOTLOADMACROHOST
    
    eMDLERR_CANNOTFINDMACRO
    
    eMDLERR_MACROVARNOTDEFINED
    
    eMDLERR_NOTATOMICDATATYPE
    
    eMDLERR_VARWRONGSIZE
    
    eMDLERR_CANNOTSETVALUE
    
    eMDLERR_ARRAYWRONGSIZE
    
    eMDLERR_THREADUNKNOWN
    
    eMDLERR_SYMBOLNOTRESOLVED
    
    eMDLERR_MODELERNOTLOADED
    
    eMDLERR_PARASOLID_ERROR
    
    eMDLERR_CIRCULARDEPENDENCY
    
    eMDLERR_INVALIDDEPENDENCY
    
    eMDLERR_EXCEPTION
    
    eMDLERR_DGNFILEOBJINUSE
    
    eMDLERR_SIGNATURE_NOT_FOUND
    
    eMDLERR_SIGNATURE_NOT_VERIFIED
    
    eMDLERR_SIGNATURE_NOT_RECOGNIZED
    
    eMDLERR_RIGHT_NOT_GRANTED
    
    eMDLERR_SIGNATURE_SILENT
    
    eMDLERR_NOTAVALIDSHAPEFILE
    
    eMDLERR_SHAPEFILEFULL
    
    eMDLERR_SHAPEALREADYEXISTS
    
    eMDLERR_CLOSEDGROUP
    
    eMDLERR_DUPLICATEMEMBER
    
    eMDLERR_FARREFERENCE
    
    eMDLERR_GROUPOPINPROGRESS
    
    eMDLERR_INVALIDCOLORMODE
    
    eMDLERR_NO_TRANSPARENCY
    
    eMDLERR_INVALID_COLOR
    
    eMDLERR_MULTIPLE_TRANSPARENCY
    
    eMDLERR_BADRASTER
    
    eMDLERR_INVALIDACCESSMODE
    
    eMDLERR_NO_GEOCODINGELM
    
    eMDLERR_SERVER_MAX_USER_REACHED
    
    eMDLERR_INTERSECTSITSELF
    
    eMDLERR_ELEMENTISHOLED
    
    eMDLERR_INVALIDLOGICALNAME
    
    eMDLERR_CONNECTIONERROR
    
    eMDLERR_INVALIDPAGE
    
    eMDLERR_EMPTYSOURCE
    
    eMDLERR_INVALIDPASSWORD
    
    eMDLERR_MSELEMENTDESCRCOLLECTOR_TERMINATE_COLLECTION
    
    eMDLERR_DOCMGR_CREATE_FAILED
    """

    def __init__(self: MSPyMstnPlatform.MdlErrorValues, value: int) -> None:
        ...
    
    eMDLERR_2D3D_MISMATCH: MdlErrorValues
    
    eMDLERR_3DREF2DMASTER: MdlErrorValues
    
    eMDLERR_ACCESSVIOLATION: MdlErrorValues
    
    eMDLERR_ACCUDRAWNOTENABLED: MdlErrorValues
    
    eMDLERR_ACSNOTFOUND: MdlErrorValues
    
    eMDLERR_ACSREPLACED: MdlErrorValues
    
    eMDLERR_ADDINGCOMPLEXELEMENT: MdlErrorValues
    
    eMDLERR_ADDRNOTKNOWN: MdlErrorValues
    
    eMDLERR_ADDRNOTVALID: MdlErrorValues
    
    eMDLERR_ALLMODELSFILTEREDOUT: MdlErrorValues
    
    eMDLERR_ALREADYEXISTS: MdlErrorValues
    
    eMDLERR_ALREADYINUSE: MdlErrorValues
    
    eMDLERR_ALREADYLOADED: MdlErrorValues
    
    eMDLERR_ALREADYOPEN: MdlErrorValues
    
    eMDLERR_AMBIGUOUS: MdlErrorValues
    
    eMDLERR_ANONYMOUS_SHAREDCELL: MdlErrorValues
    
    eMDLERR_ARRAYWRONGSIZE: MdlErrorValues
    
    eMDLERR_ATTRBADASSOC: MdlErrorValues
    
    eMDLERR_ATTRBADRPTFILE: MdlErrorValues
    
    eMDLERR_ATTRBADRPTKEYWORD: MdlErrorValues
    
    eMDLERR_ATTRNOTARGET: MdlErrorValues
    
    eMDLERR_ATTRNOTFOUND: MdlErrorValues
    
    eMDLERR_ATTRNOTINSET: MdlErrorValues
    
    eMDLERR_ATTRPREVDEFINED: MdlErrorValues
    
    eMDLERR_ATTRSETNAMELONG: MdlErrorValues
    
    eMDLERR_ATTRSETNOTFOUND: MdlErrorValues
    
    eMDLERR_ATTRSETPREVDEFINED: MdlErrorValues
    
    eMDLERR_ATTRSETTOOBIG: MdlErrorValues
    
    eMDLERR_ATTRUNDEFTYPE: MdlErrorValues
    
    eMDLERR_BADARG: MdlErrorValues
    
    eMDLERR_BADBSPELM: MdlErrorValues
    
    eMDLERR_BADCHARCONS: MdlErrorValues
    
    eMDLERR_BADCOLORDESCR: MdlErrorValues
    
    eMDLERR_BADCOLORPALETTE: MdlErrorValues
    
    eMDLERR_BADCOLORPALETTEDATA: MdlErrorValues
    
    eMDLERR_BADCOLORPALETTEINDEX: MdlErrorValues
    
    eMDLERR_BADCOLORTABLE: MdlErrorValues
    
    eMDLERR_BADCONTINUITY: MdlErrorValues
    
    eMDLERR_BADCOPYPARALLEL: MdlErrorValues
    
    eMDLERR_BADDATADEF: MdlErrorValues
    
    eMDLERR_BADELEMENT: MdlErrorValues
    
    eMDLERR_BADELEMENTTYPE: MdlErrorValues
    
    eMDLERR_BADFILE: MdlErrorValues
    
    eMDLERR_BADFILENUMBER: MdlErrorValues
    
    eMDLERR_BADFILETYPE: MdlErrorValues
    
    eMDLERR_BADFLOAT: MdlErrorValues
    
    eMDLERR_BADFONT: MdlErrorValues
    
    eMDLERR_BADFORMAT: MdlErrorValues
    
    eMDLERR_BADHEX: MdlErrorValues
    
    eMDLERR_BADINDEX: MdlErrorValues
    
    eMDLERR_BADKNOTS: MdlErrorValues
    
    eMDLERR_BADLINKERINFO: MdlErrorValues
    
    eMDLERR_BADMODELID: MdlErrorValues
    
    eMDLERR_BADMODELREF: MdlErrorValues
    
    eMDLERR_BADNAME: MdlErrorValues
    
    eMDLERR_BADOCTAL: MdlErrorValues
    
    eMDLERR_BADORDER: MdlErrorValues
    
    eMDLERR_BADPARAMETER: MdlErrorValues
    
    eMDLERR_BADPERIODICITY: MdlErrorValues
    
    eMDLERR_BADPOLES: MdlErrorValues
    
    eMDLERR_BADRASTER: MdlErrorValues
    
    eMDLERR_BADRASTERFORMAT: MdlErrorValues
    
    eMDLERR_BADRSCTYPE: MdlErrorValues
    
    eMDLERR_BADSCANLIST: MdlErrorValues
    
    eMDLERR_BADSCREENNUMBER: MdlErrorValues
    
    eMDLERR_BADSETMETHODID: MdlErrorValues
    
    eMDLERR_BADSLOT: MdlErrorValues
    
    eMDLERR_BADSPIRALDEFINITION: MdlErrorValues
    
    eMDLERR_BADSTRING: MdlErrorValues
    
    eMDLERR_BADTEXTSTYLE: MdlErrorValues
    
    eMDLERR_BADTYPE: MdlErrorValues
    
    eMDLERR_BADVERSION: MdlErrorValues
    
    eMDLERR_BADVIEWNUMBER: MdlErrorValues
    
    eMDLERR_BADVRBLARRAYSIZE: MdlErrorValues
    
    eMDLERR_BADWEIGHTS: MdlErrorValues
    
    eMDLERR_BADWORDSTOFOLLOW: MdlErrorValues
    
    eMDLERR_BUFFERALIGNMENTSDIFFER: MdlErrorValues
    
    eMDLERR_CACHEINUSE: MdlErrorValues
    
    eMDLERR_CACHELOADERROR: MdlErrorValues
    
    eMDLERR_CACHENOTENABLED: MdlErrorValues
    
    eMDLERR_CACHENOTFILLED: MdlErrorValues
    
    eMDLERR_CACHENOTFOUND: MdlErrorValues
    
    eMDLERR_CANNOTDELETEDEFAULTMODEL: MdlErrorValues
    
    eMDLERR_CANNOTDEREF: MdlErrorValues
    
    eMDLERR_CANNOTFINDMACRO: MdlErrorValues
    
    eMDLERR_CANNOTIMPORTSEED: MdlErrorValues
    
    eMDLERR_CANNOTLOADMACROHOST: MdlErrorValues
    
    eMDLERR_CANNOTOPENFILE: MdlErrorValues
    
    eMDLERR_CANNOTOPENSEED: MdlErrorValues
    
    eMDLERR_CANNOTSETVALUE: MdlErrorValues
    
    eMDLERR_CANTCREATEFILE: MdlErrorValues
    
    eMDLERR_CANTSAVEFILE: MdlErrorValues
    
    eMDLERR_CAPABILITYRESTRICTION: MdlErrorValues
    
    eMDLERR_CELLEXISTS: MdlErrorValues
    
    eMDLERR_CELLLIB2DGN3: MdlErrorValues
    
    eMDLERR_CELLNOTFOUND: MdlErrorValues
    
    eMDLERR_CELLTOOLARGE: MdlErrorValues
    
    eMDLERR_CIRCULARDEPENDENCY: MdlErrorValues
    
    eMDLERR_CLOSEDGROUP: MdlErrorValues
    
    eMDLERR_COINCIDENTSELFREF: MdlErrorValues
    
    eMDLERR_COLORMGRNOTINITIALIZED: MdlErrorValues
    
    eMDLERR_COMMANDRECEIVED: MdlErrorValues
    
    eMDLERR_COMPRESSIONERROR: MdlErrorValues
    
    eMDLERR_CONNECTIONERROR: MdlErrorValues
    
    eMDLERR_COPYERROR: MdlErrorValues
    
    eMDLERR_DATADEFNOTFOUND: MdlErrorValues
    
    eMDLERR_DGNFILEOBJINUSE: MdlErrorValues
    
    eMDLERR_DISKFULL: MdlErrorValues
    
    eMDLERR_DIVIDEBYZERO: MdlErrorValues
    
    eMDLERR_DLMNOTALLOWED: MdlErrorValues
    
    eMDLERR_DOCMGR_CREATE_FAILED: MdlErrorValues
    
    eMDLERR_DUPLICATELOGICAL: MdlErrorValues
    
    eMDLERR_DUPLICATEMEMBER: MdlErrorValues
    
    eMDLERR_DUPTASKID: MdlErrorValues
    
    eMDLERR_ELEMENTFROZEN: MdlErrorValues
    
    eMDLERR_ELEMENTISHOLED: MdlErrorValues
    
    eMDLERR_ELEMTOOLARGE: MdlErrorValues
    
    eMDLERR_ELMENTNOTFOUND: MdlErrorValues
    
    eMDLERR_ELMFILLED: MdlErrorValues
    
    eMDLERR_ELMNOTFILLED: MdlErrorValues
    
    eMDLERR_ELMNOTPLANAR: MdlErrorValues
    
    eMDLERR_ELMTOOLARGE: MdlErrorValues
    
    eMDLERR_EMPTYSOURCE: MdlErrorValues
    
    eMDLERR_ENDOFFILE: MdlErrorValues
    
    eMDLERR_EXCEPTION: MdlErrorValues
    
    eMDLERR_FARASSOCREQUIRED: MdlErrorValues
    
    eMDLERR_FARREFERENCE: MdlErrorValues
    
    eMDLERR_FILE2SUB3: MdlErrorValues
    
    eMDLERR_FILEEXISTS: MdlErrorValues
    
    eMDLERR_FILENOTFOUND: MdlErrorValues
    
    eMDLERR_FILEREADONLY: MdlErrorValues
    
    eMDLERR_FIRSTEXPRERROR: MdlErrorValues
    
    eMDLERR_GEOCOORD_NEEDSRECALCULATION: MdlErrorValues
    
    eMDLERR_GEOCOORD_NOGEOCODE: MdlErrorValues
    
    eMDLERR_GEOCOORD_NOMASTERGCS: MdlErrorValues
    
    eMDLERR_GEOCOORD_NOREFGCS: MdlErrorValues
    
    eMDLERR_GEOCOORD_NOTGEOTRANSFORMED: MdlErrorValues
    
    eMDLERR_GEOCOORD_REFTRANSFORMDISABLED: MdlErrorValues
    
    eMDLERR_GEOCOORD_UNITSWRONG: MdlErrorValues
    
    eMDLERR_GROUPOPINPROGRESS: MdlErrorValues
    
    eMDLERR_HASCHANGES: MdlErrorValues
    
    eMDLERR_HISTORYREVISIONNOTFOUND: MdlErrorValues
    
    eMDLERR_IDEXISTS: MdlErrorValues
    
    eMDLERR_IDNOTFOUND: MdlErrorValues
    
    eMDLERR_ILLEGALCHAR: MdlErrorValues
    
    eMDLERR_INPUTBUFFERWRONGALIGNMENT: MdlErrorValues
    
    eMDLERR_INSFINFO: MdlErrorValues
    
    eMDLERR_INSFMEMORY: MdlErrorValues
    
    eMDLERR_INTEGRALNEEDED: MdlErrorValues
    
    eMDLERR_INTERSECTSITSELF: MdlErrorValues
    
    eMDLERR_INVALIDACCESSMODE: MdlErrorValues
    
    eMDLERR_INVALIDACSTYPE: MdlErrorValues
    
    eMDLERR_INVALIDBUTTON: MdlErrorValues
    
    eMDLERR_INVALIDCELL: MdlErrorValues
    
    eMDLERR_INVALIDCLIP: MdlErrorValues
    
    eMDLERR_INVALIDCOLORMODE: MdlErrorValues
    
    eMDLERR_INVALIDDEPENDENCY: MdlErrorValues
    
    eMDLERR_INVALIDFORFLOAT: MdlErrorValues
    
    eMDLERR_INVALIDFORFUNC: MdlErrorValues
    
    eMDLERR_INVALIDFORNEUTRALMDL: MdlErrorValues
    
    eMDLERR_INVALIDFORSTRUCT: MdlErrorValues
    
    eMDLERR_INVALIDFORTYPE: MdlErrorValues
    
    eMDLERR_INVALIDLIBRARY: MdlErrorValues
    
    eMDLERR_INVALIDLOGICALNAME: MdlErrorValues
    
    eMDLERR_INVALIDMASTERORG: MdlErrorValues
    
    eMDLERR_INVALIDOPERATIONFORNESTED: MdlErrorValues
    
    eMDLERR_INVALIDOPERATIONFORNONNESTED: MdlErrorValues
    
    eMDLERR_INVALIDPAGE: MdlErrorValues
    
    eMDLERR_INVALIDPASSWORD: MdlErrorValues
    
    eMDLERR_INVALIDPATSPACE: MdlErrorValues
    
    eMDLERR_INVALIDPLATFORMID: MdlErrorValues
    
    eMDLERR_INVALIDREF: MdlErrorValues
    
    eMDLERR_INVALIDREFORG: MdlErrorValues
    
    eMDLERR_INVALIDSYMBOL: MdlErrorValues
    
    eMDLERR_INVALID_COLOR: MdlErrorValues
    
    eMDLERR_INVALID_FOR_RESTRICTED_PRODUCT: MdlErrorValues
    
    eMDLERR_INVREGEX: MdlErrorValues
    
    eMDLERR_LASTEXPRERROR: MdlErrorValues
    
    eMDLERR_LICHANDLENOTFOUND: MdlErrorValues
    
    eMDLERR_LINKAGENOTFOUND: MdlErrorValues
    
    eMDLERR_LOADINGINTERFACE: MdlErrorValues
    
    eMDLERR_MACRONOTSTARTED: MdlErrorValues
    
    eMDLERR_MACROSTILLRUNNING: MdlErrorValues
    
    eMDLERR_MACROVARNOTDEFINED: MdlErrorValues
    
    eMDLERR_MAXMCSLTASKS: MdlErrorValues
    
    eMDLERR_MISSINGIMAGEBAND: MdlErrorValues
    
    eMDLERR_MODELERNOTLOADED: MdlErrorValues
    
    eMDLERR_MODELIDEXISTS: MdlErrorValues
    
    eMDLERR_MODELNAMEEXISTS: MdlErrorValues
    
    eMDLERR_MODELNOTEMPTY: MdlErrorValues
    
    eMDLERR_MODELNOTFOUND: MdlErrorValues
    
    eMDLERR_MODIFYCOMPLEX: MdlErrorValues
    
    eMDLERR_MSELEMENTDESCRCOLLECTOR_TERMINATE_COLLECTION: MdlErrorValues
    
    eMDLERR_MULTIPLE_TRANSPARENCY: MdlErrorValues
    
    eMDLERR_MUNOTLARGERTHANSU: MdlErrorValues
    
    eMDLERR_NAMENOTUNIQUE: MdlErrorValues
    
    eMDLERR_NAMETOOLONG: MdlErrorValues
    
    eMDLERR_NEEDEXPONENT: MdlErrorValues
    
    eMDLERR_NEEDINT: MdlErrorValues
    
    eMDLERR_NOACSDEFINED: MdlErrorValues
    
    eMDLERR_NOASSOCIATEDTEMPLATE: MdlErrorValues
    
    eMDLERR_NOBOUNDS: MdlErrorValues
    
    eMDLERR_NOBSPHEADER: MdlErrorValues
    
    eMDLERR_NOCELLLIBRARY: MdlErrorValues
    
    eMDLERR_NOCHANGE: MdlErrorValues
    
    eMDLERR_NOCLIPVOLUME: MdlErrorValues
    
    eMDLERR_NOEXTPGMSTACK: MdlErrorValues
    
    eMDLERR_NOFENCE: MdlErrorValues
    
    eMDLERR_NOGRAPHICGROUP: MdlErrorValues
    
    eMDLERR_NOINTERNALMATERIALS: MdlErrorValues
    
    eMDLERR_NOKEYS: MdlErrorValues
    
    eMDLERR_NOKNOTS: MdlErrorValues
    
    eMDLERR_NOLEVELMASK: MdlErrorValues
    
    eMDLERR_NOLICENSEAVAILABLE: MdlErrorValues
    
    eMDLERR_NOMASTERFILE: MdlErrorValues
    
    eMDLERR_NOMATCH: MdlErrorValues
    
    eMDLERR_NOMDLPLOTDRIVERINPLT: MdlErrorValues
    
    eMDLERR_NOMESSAGE: MdlErrorValues
    
    eMDLERR_NOMODEL: MdlErrorValues
    
    eMDLERR_NOMODELINFO: MdlErrorValues
    
    eMDLERR_NONCLOSEDELM: MdlErrorValues
    
    eMDLERR_NONCLOSEDPATELM: MdlErrorValues
    
    eMDLERR_NONCOPLANARSHAPES: MdlErrorValues
    
    eMDLERR_NONPLANARELEMENT: MdlErrorValues
    
    eMDLERR_NONSOLIDPATELM: MdlErrorValues
    
    eMDLERR_NONUMBOUNDS: MdlErrorValues
    
    eMDLERR_NOOFFSETINTERSECTION: MdlErrorValues
    
    eMDLERR_NOPARENTMODEL: MdlErrorValues
    
    eMDLERR_NOPOLES: MdlErrorValues
    
    eMDLERR_NOQUEUEENTRIES: MdlErrorValues
    
    eMDLERR_NOREFSLOTS: MdlErrorValues
    
    eMDLERR_NOSELECTIONSET: MdlErrorValues
    
    eMDLERR_NOSUCHAPPLICATION: MdlErrorValues
    
    eMDLERR_NOSUCHMODEL: MdlErrorValues
    
    eMDLERR_NOSYMBOL: MdlErrorValues
    
    eMDLERR_NOTATOMICDATATYPE: MdlErrorValues
    
    eMDLERR_NOTAVAILABLE: MdlErrorValues
    
    eMDLERR_NOTAVALIDSHAPEFILE: MdlErrorValues
    
    eMDLERR_NOTCMPLXHDR: MdlErrorValues
    
    eMDLERR_NOTCOMPLEXHEADER: MdlErrorValues
    
    eMDLERR_NOTCONVRULES: MdlErrorValues
    
    eMDLERR_NOTDESIGNFILE: MdlErrorValues
    
    eMDLERR_NOTDIRECTATTACHMENT: MdlErrorValues
    
    eMDLERR_NOTFUNCTION: MdlErrorValues
    
    eMDLERR_NOTLOADED: MdlErrorValues
    
    eMDLERR_NOTLOCKED: MdlErrorValues
    
    eMDLERR_NOTMEMBER: MdlErrorValues
    
    eMDLERR_NOTOPEN: MdlErrorValues
    
    eMDLERR_NOTRANSFORM: MdlErrorValues
    
    eMDLERR_NOTSAMEUNITBASE: MdlErrorValues
    
    eMDLERR_NOTSINGLEVIEW: MdlErrorValues
    
    eMDLERR_NOTSTRUCT: MdlErrorValues
    
    eMDLERR_NOTSUPPORTED: MdlErrorValues
    
    eMDLERR_NOTSUPPORTEDACTIVATEDREF: MdlErrorValues
    
    eMDLERR_NOTVALIDEXPRESS: MdlErrorValues
    
    eMDLERR_NOWEIGHTS: MdlErrorValues
    
    eMDLERR_NO_GEOCODINGELM: MdlErrorValues
    
    eMDLERR_NO_TRANSPARENCY: MdlErrorValues
    
    eMDLERR_NULLOUTPUTBUFFER: MdlErrorValues
    
    eMDLERR_NULLSOLUTION: MdlErrorValues
    
    eMDLERR_OLDMATERIALTABLE: MdlErrorValues
    
    eMDLERR_OPERATIONCANCELED: MdlErrorValues
    
    eMDLERR_OPERVIOLATESCONSTRAINTS: MdlErrorValues
    
    eMDLERR_OUTPUTBUFFERWRONGALIGNMENT: MdlErrorValues
    
    eMDLERR_OVERSIZE_ELEMENT: MdlErrorValues
    
    eMDLERR_PALETTEWRONGSIZE: MdlErrorValues
    
    eMDLERR_PARASOLID_ERROR: MdlErrorValues
    
    eMDLERR_PROGRAMTERMINATED: MdlErrorValues
    
    eMDLERR_QUEUEERROR: MdlErrorValues
    
    eMDLERR_QUEUEFULL: MdlErrorValues
    
    eMDLERR_READFAILED: MdlErrorValues
    
    eMDLERR_RECURSELIMIT: MdlErrorValues
    
    eMDLERR_REDUNDANTREF: MdlErrorValues
    
    eMDLERR_REJECTED: MdlErrorValues
    
    eMDLERR_REJECTEDBYINIT: MdlErrorValues
    
    eMDLERR_RELATIVECELLLEVELNOTFOUND: MdlErrorValues
    
    eMDLERR_RELOADNOTNEEDED: MdlErrorValues
    
    eMDLERR_RENAMEERROR: MdlErrorValues
    
    eMDLERR_REPLACING_DELETED: MdlErrorValues
    
    eMDLERR_RESOURCENOTFOUND: MdlErrorValues
    
    eMDLERR_RIGHT_NOT_GRANTED: MdlErrorValues
    
    eMDLERR_RIGHT_NOT_GRANTED_FOR_OPERATION: MdlErrorValues
    
    eMDLERR_RSCADDRINVALID: MdlErrorValues
    
    eMDLERR_RSCALIASREQUIRED: MdlErrorValues
    
    eMDLERR_RSCALREADYEXISTS: MdlErrorValues
    
    eMDLERR_RSCBADRANGETREE: MdlErrorValues
    
    eMDLERR_RSCBADRSCSIZE: MdlErrorValues
    
    eMDLERR_RSCBADVERSION: MdlErrorValues
    
    eMDLERR_RSCCONDITIONFALSE: MdlErrorValues
    
    eMDLERR_RSCDIRECTADDPEND: MdlErrorValues
    
    eMDLERR_RSCERROR: MdlErrorValues
    
    eMDLERR_RSCFILECORRUPT: MdlErrorValues
    
    eMDLERR_RSCFILEERROR: MdlErrorValues
    
    eMDLERR_RSCFILEHANDLETABLEFULL: MdlErrorValues
    
    eMDLERR_RSCFILENOTFOUND: MdlErrorValues
    
    eMDLERR_RSCFILENOTOPEN: MdlErrorValues
    
    eMDLERR_RSCFOPENFAILURE: MdlErrorValues
    
    eMDLERR_RSCHANDLEINVALID: MdlErrorValues
    
    eMDLERR_RSCINSFMEM: MdlErrorValues
    
    eMDLERR_RSCINUSE: MdlErrorValues
    
    eMDLERR_RSCINVALIDFILEHANDLE: MdlErrorValues
    
    eMDLERR_RSCNOTFOUND: MdlErrorValues
    
    eMDLERR_RSCQRYIDINVALID: MdlErrorValues
    
    eMDLERR_RSCSTRINGNOTFOUND: MdlErrorValues
    
    eMDLERR_RSCTYPEINVALID: MdlErrorValues
    
    eMDLERR_RSCWRITEERROR: MdlErrorValues
    
    eMDLERR_RSCWRITEVIOLATION: MdlErrorValues
    
    eMDLERR_SERVER_MAX_USER_REACHED: MdlErrorValues
    
    eMDLERR_SHAPEALREADYEXISTS: MdlErrorValues
    
    eMDLERR_SHAPEFILEFULL: MdlErrorValues
    
    eMDLERR_SHARINGVIOLATION: MdlErrorValues
    
    eMDLERR_SHMEMNOTFOUND: MdlErrorValues
    
    eMDLERR_SIGNATURE_NOT_FOUND: MdlErrorValues
    
    eMDLERR_SIGNATURE_NOT_RECOGNIZED: MdlErrorValues
    
    eMDLERR_SIGNATURE_NOT_VERIFIED: MdlErrorValues
    
    eMDLERR_SIGNATURE_SILENT: MdlErrorValues
    
    eMDLERR_STRUCTNEEDED: MdlErrorValues
    
    eMDLERR_STYLEISUSED: MdlErrorValues
    
    eMDLERR_STYLENOTFOUND: MdlErrorValues
    
    eMDLERR_SYMBOLNOTRESOLVED: MdlErrorValues
    
    eMDLERR_SYMBOLTOOLONG: MdlErrorValues
    
    eMDLERR_SYNTAXERROR: MdlErrorValues
    
    eMDLERR_SYSTEMERROR: MdlErrorValues
    
    eMDLERR_THREADUNKNOWN: MdlErrorValues
    
    eMDLERR_TIMEOUT: MdlErrorValues
    
    eMDLERR_TOOCOMPLEX: MdlErrorValues
    
    eMDLERR_TOOFEWARGUMENTS: MdlErrorValues
    
    eMDLERR_TOOFEWPOLES: MdlErrorValues
    
    eMDLERR_TOOLARGE: MdlErrorValues
    
    eMDLERR_TOOMANYARGUMENTS: MdlErrorValues
    
    eMDLERR_TOOMANYITERATIONS: MdlErrorValues
    
    eMDLERR_TOOMANYKNOTS: MdlErrorValues
    
    eMDLERR_TOOMANYOPENFILES: MdlErrorValues
    
    eMDLERR_TOOMANYPOLES: MdlErrorValues
    
    eMDLERR_TOOMANYSURFACEELMS: MdlErrorValues
    
    eMDLERR_TYPESINCOMPATIBLE: MdlErrorValues
    
    eMDLERR_UNBOUNDEDSOLUTION: MdlErrorValues
    
    eMDLERR_UNDERSIZE_ELEMENT: MdlErrorValues
    
    eMDLERR_UNKNOWNERROR: MdlErrorValues
    
    eMDLERR_UNKNOWNFORMAT: MdlErrorValues
    
    eMDLERR_UNSUPPORTED: MdlErrorValues
    
    eMDLERR_USERABORT: MdlErrorValues
    
    eMDLERR_V7CELLLIBRARY: MdlErrorValues
    
    eMDLERR_V8B2CELLLIBRARY: MdlErrorValues
    
    eMDLERR_VARWRONGSIZE: MdlErrorValues
    
    eMDLERR_VIEWGROUPNOTFOUND: MdlErrorValues
    
    eMDLERR_VIEWNOTDISPLAYED: MdlErrorValues
    
    eMDLERR_VIEWNOTFOUND: MdlErrorValues
    
    eMDLERR_VOIDDATATYPE: MdlErrorValues
    
    eMDLERR_WRITEFAILED: MdlErrorValues
    
    eMDLERR_WRITEINHIBIT: MdlErrorValues
    
    eMDLERR_WRONGELEMID: MdlErrorValues
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.MdlErrorValues) -> int:
        ...
    
class MenuMarkType:
    """
    Members:
    
    eMARK_NONE
    
    eMARK_TOGGLE_OUT
    
    eMARK_TOGGLE_IN
    
    eMARK_RADIO_OUT
    
    eMARK_RADIO_IN
    
    eMARK_RIGHT_ARROW
    """

    def __init__(self: MSPyMstnPlatform.MenuMarkType, value: int) -> None:
        ...
    
    eMARK_NONE: MenuMarkType
    
    eMARK_RADIO_IN: MenuMarkType
    
    eMARK_RADIO_OUT: MenuMarkType
    
    eMARK_RIGHT_ARROW: MenuMarkType
    
    eMARK_TOGGLE_IN: MenuMarkType
    
    eMARK_TOGGLE_OUT: MenuMarkType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.MenuMarkType) -> int:
        ...
    
class Mesh:
    """
    None
    """

    @staticmethod
    def BooleanDifference(mesh1: MSPyBentleyGeom.PolyfaceHeader, mesh2: MSPyBentleyGeom.PolyfaceHeader, model: MSPyDgnPlatform.DgnModelRef) -> tuple:
        ...
    
    @staticmethod
    def BooleanIntersection(mesh1: MSPyBentleyGeom.PolyfaceHeader, mesh2: MSPyBentleyGeom.PolyfaceHeader, model: MSPyDgnPlatform.DgnModelRef) -> tuple:
        ...
    
    @staticmethod
    def BooleanUnion(mesh1: MSPyBentleyGeom.PolyfaceHeader, mesh2: MSPyBentleyGeom.PolyfaceHeader, model: MSPyDgnPlatform.DgnModelRef) -> tuple:
        ...
    
    @staticmethod
    def ExtrudeToTarget(results: MSPyBentleyGeom.PolyfaceHeaderPtrArray, roofAgenda: MSPyDgnPlatform.ElementAgenda, targetAgenda: MSPyDgnPlatform.ElementAgenda) -> bool:
        ...
    
    @staticmethod
    def ExtrudeVolume(results: MSPyBentleyGeom.PolyfaceHeaderPtrArray, agenda: MSPyDgnPlatform.ElementAgenda, extrusionVec: MSPyBentleyGeom.DVec3d) -> bool:
        ...
    
    @staticmethod
    def ExtrudeVolumeAlongGlobalZ(results: MSPyBentleyGeom.PolyfaceHeaderPtrArray, agenda: MSPyDgnPlatform.ElementAgenda, length: float) -> bool:
        ...
    
    @staticmethod
    def Healholes(mesh: MSPyBentleyGeom.PolyfaceHeader) -> tuple:
        ...
    
    @staticmethod
    def SubdivideKeepSharp(mesh: MSPyBentleyGeom.PolyfaceHeader, subdivisionLevel: int, model: MSPyDgnPlatform.DgnModelRef) -> tuple:
        ...
    
    @staticmethod
    def SubdivideSmoothly(mesh: MSPyBentleyGeom.PolyfaceHeader, subdivisionLevel: int, model: MSPyDgnPlatform.DgnModelRef) -> tuple:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MessageCenter:
    """
    None
    """

    @staticmethod
    def ShowDebugMessage(briefMessage: str, detailedMessage: str, openAlertBox: bool) -> None:
        ...
    
    @staticmethod
    def ShowErrorMessage(briefMessage: str, detailedMessage: str, openAlertBox: bool) -> None:
        ...
    
    @staticmethod
    def ShowInfoMessage(briefMessage: str, detailedMessage: str, openAlertBox: bool) -> None:
        ...
    
    @StatusCommand.setter
    def StatusCommand(arg0: object, arg1: str) -> None:
        ...
    
    @StatusMessage.setter
    def StatusMessage(arg0: object, arg1: str) -> None:
        ...
    
    @StatusPrompt.setter
    def StatusPrompt(arg0: object, arg1: str) -> None:
        ...
    
    @StatusWarning.setter
    def StatusWarning(arg0: object, arg1: str) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MessageDestination:
    """
    Members:
    
    eMESSAGE_DEST_None
    
    eMESSAGE_DEST_MessageCenter
    
    eMESSAGE_DEST_WarningDialog
    """

    def __init__(self: MSPyMstnPlatform.MessageDestination, value: int) -> None:
        ...
    
    eMESSAGE_DEST_MessageCenter: MessageDestination
    
    eMESSAGE_DEST_None: MessageDestination
    
    eMESSAGE_DEST_WarningDialog: MessageDestination
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.MessageDestination) -> int:
        ...
    
class ModelRef:
    """
    None
    """

    @staticmethod
    def ActivateAndDisplay(newModelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Activates and displays the specified modelRef. The
        function checks if the model is displayed in the current views and, if
        not, new views are opened with the modelRef as their root. @Param[in]
        newModelRef the model to activate. The modelRef must be from the
        current master file. @Return SUCCESS if the model is found and
        activated successfully; otherwise, ERROR.
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def AreSame(modelRef1: MSPyDgnPlatform.DgnModelRef, modelRef2: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether two specified modelRefs are actually
        the same. @Param[in] modelRef1 the first modelRef. @Param[in]
        modelRef2 the second modelRef. @Return true if the two modelRefs the
        same.
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CheckAllRights(modelRef: MSPyDgnPlatform.DgnModelRef, rights: int, diaplayError: MessageDestination) -> int:
        """
        @Description Check if the specified rights are granted to the current
        user for the given model and all references @Param[in] modelRef The
        modelRef to check. @Param[in] rights the rights to query. See
        DgnFileObj.CheckRights for a description of the rights values.
        @Param[in] displayError Determines whether an error should be
        displayed in the message center, a pop-up dialog, or the function
        should return silently. @Return SUCCESS if all of the rights are
        granted for all files.
        
        See also:
        digitalRights_checkRights
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CheckAllRightsIfDisplayed(modelRef: MSPyDgnPlatform.DgnModelRef, rights: int, view: int, diaplayError: MessageDestination) -> int:
        """
        @Description Check if the specified rights are granted to the current
        user for the given model and all references that are displayed in the
        selected view(s). @Param[in] modelRef The modelRef to check.
        @Param[in] rights the rights to query. See DgnFileObj.CheckRights
        for a description of the rights values. @Param[in] view the view to
        query or ANY_VIEW. @Param[in] displayError Determines whether an error
        should be displayed in the message center, a pop-up dialog, or the
        function should return silently. @Return SUCCESS if all of the rights
        are granted for all files in the specified view.
        
        See also:
        ModelRef.CheckAllRights
        
        See also:
        digitalRights_checkRights
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CheckAllRightsIncludingProtectedRefs(modelRef: MSPyDgnPlatform.DgnModelRef, rights: int, diaplayError: MessageDestination) -> int:
        """
        @Description Check if the specified rights are granted to the current
        user for the given model and all references, including the references
        that could not be opened because the user lacked viewing access.
        @Param[in] modelRef The modelRef to check. @Param[in] rights the
        rights to query. See DgnFileObj.CheckRights for a description of
        the rights values. @Param[in] displayError Determines whether an error
        should be displayed in the message center, a pop-up dialog, or the
        function should return silently. @Return SUCCESS if all of the rights
        are granted for all files. MDLERR_RIGHT_NOT_GRANTED if any of the
        opened references do not have the specified rights, or if there were
        references that could not be opened because the user did not have any
        access rights to the file.
        
        See also:
        digitalRights_checkRights
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CopyModel(sourceModelRef: MSPyDgnPlatform.DgnModelRef, destFile: MSPyDgnPlatform.DgnFile, destModelName: str, destModelDescr: str) -> tuple:
        """
        @Description Copy a model from one location to another. This function
        handles copying levels, styles, etc. necessary for elements in the
        model. @Remarks Export rights for the source modelRef and edit rights
        for the destination file are checked. @Param[out] returnDestModelRef
        Working model ref for resulting model. If NULL is not passed for this
        parameter, the resulting modelRef must be freed using
        ModelRef.FreeWorking. @Param[in] sourceModelRef Model to copy.
        @Param[in] destFile File in which the model should be written.
        @Param[in] pDestModelName Name for the copied model. @Param[in]
        pDestModelDescr Description for the copied model; may be NULL. @Return
        SUCCESS if the model was copied successfully; error returns are
        defined in mdlerrs.r.h. @See DgnFileObj.CreateModel
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateCacheSpecificWorking(dgnFile: MSPyDgnPlatform.DgnFile, modelId: int, fillCache: bool, loadRefs: bool, includeUndisplayedRefs: bool, sectionsToFill: MSPyDgnPlatform.DgnModelSections) -> tuple:
        """
        @Description Creates a " working " DgnModelRefP containing the specified
        cache sections that can be passed to functions that take DgnModelRefP
        arguments. The ModelRef created must be freed using
        ~mModelRef.FreeWorking. If the file specified as dgnFileP is read-
        only, then the modelRef will be read-only also. @Param dgnModelRefP
        OUT modelRef referring to the model created @Param dgnFileP IN the
        file object to search for the model @Param modelID IN the ID of the
        model to load @Param fillCache IN true if the cache for the model
        should be filled. Operations like changing name, description, etc.,
        can be performed even if the cache is not filled. @Param loadRefs IN
        true if the caches for the model's attached references should also be
        loaded. The fillCache argument must be true for this to work. @Param
        includeUndisplayedRefs IN If true, load the caches for references that
        are not displayed. The fillCache and loadRefs arguments must be true
        for this to work. @Param sectionsToFill IN Specific cache sections to
        fill. @Return SUCCESS if the modelRef is returned and filled as
        requested. @ALinkJoin usmthModelRef.CreateWorkingC
        """
        ...
    
    @staticmethod
    def CreateWorking(dgnFile: MSPyDgnPlatform.DgnFile, modelId: int, fillCache: bool, loadRefs: bool) -> tuple:
        """
        @Description Creates a " working " DgnModelRefP that can be passed to
        functions that take DgnModelRefP arguments. The ModelRef created must
        be freed using ModelRef.FreeWorking. If the file specified as
        dgnFileP is read-only, then the modelRef will be read-only also.
        @Param[out] dgnModelRefP modelRef referring to the model created
        @Param[in] dgnFileP the file object to search for the model @Param[in]
        modelID the ID of the model to load @Param[in] fillCache true if the
        cache for the model should be filled. Operations like changing name,
        description, etc., can be performed even if the cache is not filled.
        @Param[in] loadRefs true if the caches for the model's attached
        references should also be loaded. The fillCache argument must be true
        for this to work. @Return SUCCESS if the modelRef is returned and
        filled as requested.
        
        See also:
        ModelRef.CreateWorkingByName
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def CreateWorkingByName(dgnFile: MSPyDgnPlatform.DgnFile, modelName: str, fillCache: bool, loadRefs: bool) -> tuple:
        """
        @Description Creates a " working " DgnModelRefP that can be passed to
        functions that take DgnModelRefP arguments. The ModelRef created must
        be freed using ModelRef.FreeWorking. If the file specified as
        dgnFileP is read-only, then the modelRef will be read-only also.
        @Param[out] dgnModelRefP modelRef referring to the model created
        @Param[in] dgnFileP the file object to search for the model @Param[in]
        modelNameP the name of the model to find in the design file.
        @Param[in] fillCache true if the cache for the model should be filled.
        Operations like changing name, description, etc., can be performed
        even if the cache is not filled. @Param[in] loadRefs true if the
        caches for the model's attached references should also be loaded. The
        fillCache argument must be true for this to work. @Return SUCCESS if
        the modelRef is returned and filled as requested.
        
        See also:
        ModelRef.CreateWorking
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def DeleteModel(modelRef: MSPyDgnPlatform.DgnModelRef, deleteElements: bool) -> int:
        """
        @Description Deletes the specified model from the file that contains
        it. @Param[in] modelRef the model to delete. @Param[in] deleteElements
        If true, the model will not be deleted unless it is empty. If false,
        all elements assigned to the model are also deleted. @Return SUCCESS
        if the model is found and deleted successfully; otherwise, ERROR.
        @Remarks This action is undoable if the model is deleted from the
        master file
        
        See also:
        ModelRef.IsReadOnly
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def FreeWorking(modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Frees modelRef's created using ModelRef.CreateWorking
        or ModelRef.CreateWorkingByName. @Param[in] modelRef the modelRef
        to free. @Return SUCCESS if the model ref is freed, MDLERR_BADMODELREF
        if the modelRef specified is not a working modelRef. @Remarks Only
        modelRefs created with ModelRef.CreateWorking or
        ModelRef.CreateWorkingByName can be freed using this function. An
        attempt to free other modelRefs causes a returns value of
        MDLERR_BADMODELREF.
        
        See also:
        ModelRef.CreateWorking ModelRef.CreateWorkingByName
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetAttachmentID(modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetChildCount(modelRef: MSPyDgnPlatform.DgnModelRef, childTypeMask: int) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetDgnFile(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.DgnFile:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetDgnModel(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.DgnModel:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetDisplayName(modelRef: MSPyDgnPlatform.DgnModelRef, displayName: MSPyBentley.WString, separator: str) -> int:
        """
        @Description Gets the string that MicroStation uses to display the
        name of the modelRef in its user interface. If the modelRef is a
        reference, the string consists of the logical name (if there is any),
        followed by the file name, followed by the model name (if there is
        more than one model in the file). @Param[in] modelRef the model for
        which to retrieve the name @Param[out] displayName the display name.
        @Param[in] maxChars the size of displayName, in MSWChars. @Param[in]
        separator the separator to use. Maximum size allowed is 10 wide chars.
        If NULL is passed in, ", " will be used by default. @Return
        MDLERR_NAMETOOLONG if name does not fit, MDLERR_BADMODELREF if invalid
        modelRef. @Remarks To ensure that displayName is large enough, supply
        a buffer that holds MAX_MODEL_DISPLAY_LENGTH MSWChars.
        
        See also:
        RefFile.GetInfo Bentley Systems
        """
        ...
    
    @staticmethod
    def GetElementRef(modelRef: MSPyDgnPlatform.DgnModelRef, filePos: int) -> MSPyDgnPlatform.ElementRefBase:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetEof(modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetFileName(modelRef: MSPyDgnPlatform.DgnModelRef, fileName: MSPyBentley.WString) -> int:
        """
        @Description Gets the name of the file that contains the data for the
        specified model. @Param[in] modelRef the model to query. @Param[out]
        fileName buffer to hold the file name. @Param[in] fileNameBufSize size
        of the buffer (in characters) pointed to by fileName. @Return SUCCESS
        if the name is obtained without error; MDLERR_BADARG if modelRef was
        invalid; MDLERR_BADMODELREF if the file could not be obtained.
        @Remarks This function requires that the element cache exists for the
        specified modelRef. For example, this function can fail if the
        specified modelRef is a reference model that is not displayed, or is
        not found. In this case, RefFile.GetRefParameter can be used to get
        the file name stored in the reference attachment. @Remarks A more
        modern version that returns a WString is
        modelRef->GetDgnFileP()->GetFileName().
        
        See also:
        ModelRef.GetDgnFile
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetModelType(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.DgnModelType:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetParent(modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.DgnModelRef:
        """
        @Description Gets the DgnModelRefP for the model that is the parent of
        the specified modelRef. @Param[in] modelRef The model to get the
        parent of. @Return The modelRef for the parent model of the specified
        modelRef if a parent exists; otherwise, NULL. @Remarks Reference
        attachments have a parent, but the active model does not. The parent
        of a directly attached reference is the active model. The parent of a
        nested reference is the model to which it is attached.
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetRange(modelRef: MSPyDgnPlatform.DgnModelRef, outRange: MSPyBentleyGeom.DRange3d, viewIndex: int, transform: MSPyBentleyGeom.Transform, includeChildren: bool) -> int:
        """
        @Description Gets the range for the specified modelRef. This
        calculates the range for all geometry in a model - it does not ignore
        elements that are not displayed in the input view. This function is
        relatively fast. It does not iterate through the model but uses a
        range that is stored internally. @Param[in] modelRef the model to get
        the range for. @Param[out] pRange the model range
        
        Parameter ``viewIndex``:
        index of view, used to get the clip volume of the view.
        
        Parameter ``transformP``:
        NULL or transform to apply before calculating range.
        
        Parameter ``includeChildren``:
        true to include the range of child references. @Return SUCCESS if
        the requested params were acceptable, otherwise ERROR
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def GetTransient() -> MSPyDgnPlatform.DgnModelRef:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetUorPerMaster(modelRef: MSPyDgnPlatform.DgnModelRef) -> float:
        ...
    
    @staticmethod
    def GetUorScaleBetweenModels(srcModelRef: MSPyDgnPlatform.DgnModelRef, dstModelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetViewMask(modelRef: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Gets a bitmask representing the views that display the
        specified modelRef. @Param[in] modelRef the model to get the view
        bitmask for. @Return An integer value that is has one bit for each of
        views 1 through 8 whether the modelRef is displayed in the
        corresponding view. Bit 0 corresponds to " View 1 ".
        
        See also:
        ModelRef.IsDisplayedInView Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def InMasterFile(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether the specified modelRef is contained in
        the master file. @Param[in] modelRef the model to test. @Return true,
        if the modelRef is valid and its data is stored in the current master
        file.
        
        See also:
        ModelRef.IsReference ModelRef.GetDgnFile
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Is3D(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def IsActiveModel(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether the specified modelRef is the active
        model. @Param[in] modelRef the model to test. @Return true, if the
        modelRef is the currently active model.
        
        See also:
        ModelRef.IsReference ustmthModelRef.IsNestedReferenceC
        """
        ...
    
    @staticmethod
    def IsDefault(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def IsDisplayedInView(modelRef: MSPyDgnPlatform.DgnModelRef, viewIndex: int) -> bool:
        """
        @Description Determines whether the specified DgnPlatform.DgnModelRef
        is displayed in the specified view. @Param[in] modelRef the the model
        to query. @Param[in] viewIndex the view index to test. This value
        should be in the range of 0 - (DgnPlatform.MAX_VIEWS-1), or the value
        ANY_VIEW if the test is to see whether it is displayed in any view.
        @Return true if the specified modelRef is currently displayed in the
        given view. @Remarks A model is not displayed in a view if it is not
        the root model for that view or one of its descendants. @Remarks If
        the modelRef is a reference modelRef, it is not displayed in any view
        if its display flag is turned off, or if the file or model referenced
        could not be found. It is also not displayed in a particular view if
        the level of its reference attachment element is turned off in that
        view.
        
        See also:
        ModelRef.GetViewMask
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsEmpty(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def IsNestedReference(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether the specified reference model is
        attached to another reference model. @Param[in] modelRef the model to
        test. @Return true if the specified modelRef is referenced from
        another referenced model.
        
        See also:
        ModelRef.IsReference ModelRef.IsActiveModel
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsReadOnly(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether a modelRef is read-only. @Param[in]
        modelRef the modelRef to test. @Return true if the specified model is
        read-only.
        
        See also:
        ModelRef.IsReference
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsReference(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether the specified modelRef is a reference
        model. @Param[in] modelRef The model to test. @Return true if the
        specified modelRef represents a reference model.
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def IsSheet(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def IsTransient(modelRef: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def LoadReferenceModels(modelRef: MSPyDgnPlatform.DgnModelRef, loadCache: bool, loadRasterRefs: bool, loadUndisplayedRefs: bool) -> int:
        """
        Loads the reference models attached to the specified modelRef. By
        default, reference models are loaded only for the active modelRef (and
        its descendants), and child DgnModelRefP's for other modelRefs are not
        created. When this function is called, the child DgnModelRefPs will be
        created so they can be iterated using ModelRefIterator.Create.
        
        Parameter ``modelRef``:
        The modelRef for which the reference DgnModelRefPs are to be
        created.
        
        Parameter ``loadCache``:
        true if caches should be loaded for reference models, false if
        only modelRefs should be created.
        
        Parameter ``loadRasterRefs``:
        true if raster reference files should be loaded, false if not.
        
        Parameter ``loadUndisplayedRefs``:
        true if even undisplayed reference files should be loaded.
        
        Returns:
        SUCCESS or a nonzero error code. @Group " Models "
        
        Remark:
        """
        ...
    
    @staticmethod
    def SetDefaultBackgroundColor(modelRef: MSPyDgnPlatform.DgnModelRef) -> None:
        """
        @Description Sets the model background color to the default value for
        that model type. This has an effect only on sheet models, because
        there is no default background color for normal models.. @Param[in]
        modelRefP the modelRef for which the default background color is set.
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ModelRefList:
    """
    None
    """

    @staticmethod
    def Add(modelRefList: MSPyDgnPlatform.DgnModelRefList, entry: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def Clone(modelRefList: MSPyDgnPlatform.DgnModelRefList) -> MSPyDgnPlatform.DgnModelRefList:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def CopyContents(modelRefList: MSPyDgnPlatform.DgnModelRefList, srcModelRefList: MSPyDgnPlatform.DgnModelRefList) -> None:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def Create() -> tuple:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def Empty(modelRefList: MSPyDgnPlatform.DgnModelRefList) -> None:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def Find(modelRefList: MSPyDgnPlatform.DgnModelRefList, entry: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        @Description Gets the index of the specified modelRef in the list.
        @Param[in] modelRefList the list to search for the modelRef.
        @Param[in] entry the model to find in the list. @Return The index of
        the modelRef in the list if it is found; the value -1 if the entry
        isn't found.
        
        See also:
        ModelRefList.GetCount ModelRefList.Get
        ModelRefList.IsFound
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Free(modelRefList: MSPyDgnPlatform.DgnModelRefList) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def Get(modelRefList: MSPyDgnPlatform.DgnModelRefList, index: int) -> MSPyDgnPlatform.DgnModelRef:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def GetCount(modelRefList: MSPyDgnPlatform.DgnModelRefList) -> int:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def Insert(modelRefList: MSPyDgnPlatform.DgnModelRefList, insertBefore: int, entry: MSPyDgnPlatform.DgnModelRef) -> None:
        """
        Remark:
        """
        ...
    
    @staticmethod
    def IsFound(modelRefList: MSPyDgnPlatform.DgnModelRefList, entry: MSPyDgnPlatform.DgnModelRef) -> bool:
        """
        @Description Determines whether the specified modelRef is a member of
        the list. @Param[in] modelRefList the list to search. @Param[in] entry
        the modelRef to find in the list. @Return true if the specified entry
        is found in the list.
        
        See also:
        ModelRefList.Find
        
        Bentley Systems
        
        Remark:
        """
        ...
    
    @staticmethod
    def Remove(modelRefList: MSPyDgnPlatform.DgnModelRefList, entry: MSPyDgnPlatform.DgnModelRef) -> int:
        """
        Remark:
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MstnEventManager:
    """
    None
    """

    def AddEditActionSource(self: MSPyMstnPlatform.MstnEventManager, source: Bentley.DgnPlatform.IEditActionSource) -> None:
        """
        Add a new DgnPlatform.IEditActionSource to MicroStation's list of
        installed EditActionSources. After this call, handler will be notified
        of all future EditActionSource events.
        
        Parameter ``[in]``:
        source New DgnPlatform.IEditActionSource to add
        """
        ...
    
    def AddMouseWheelHandler(self: MSPyMstnPlatform.MstnEventManager, handler: MSPyMstnPlatform.IMouseWheelHandler) -> None:
        """
        Add a new IMouseWheelHandler to MicroStation's list of installed
        MouseWheelHandlers.
        
        Parameter ``[in]``:
        mwHandler New IMouseWheelHandler to add
        """
        ...
    
    def AddPrintEventHandler(self: MSPyMstnPlatform.MstnEventManager, handler: MSPyMstnPlatform.IPrintEventHandler) -> None:
        """
        Add a new IPrintEventHandler to MicroStation's list of installed
        PrintEventHandlers.
        
        Parameter ``[in]``:
        handler New handler to add
        """
        ...
    
    def DropEditActionSource(self: MSPyMstnPlatform.MstnEventManager, source: Bentley.DgnPlatform.IEditActionSource) -> None:
        """
        Drop an DgnPlatform.IEditActionSource from list of installed
        EditActionSources. After this call, handler will not be notified of
        future EditActionSource events.
        
        Parameter ``[in]``:
        source the DgnPlatform.IEditActionSource to drop.
        """
        ...
    
    def DropMouseWheelHandler(self: MSPyMstnPlatform.MstnEventManager, handler: MSPyMstnPlatform.IMouseWheelHandler) -> None:
        """
        Drop an IMouseWheelHandler from list of installed MouseWheelHandlers.
        After this call, handler will not be notified of future MouseWheel
        events.
        
        Parameter ``[in]``:
        mwHandler the IMouseWheelHandler to drop.
        """
        ...
    
    def DropPrintEventHandler(self: MSPyMstnPlatform.MstnEventManager, handler: MSPyMstnPlatform.IPrintEventHandler) -> None:
        """
        Drop an IPrintEventHandler from list of installed PrintEventHandlers.
        After this call, handler will not be notified of future print events.
        
        Parameter ``[in]``:
        handler to drop.
        """
        ...
    
    @staticmethod
    def GetManager() -> MSPyMstnPlatform.MstnEventManager:
        """
        Get the MstnEventManager instance.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MstnImage:
    """
    None
    """

    @staticmethod
    def RGBSeparateToBGR(rgb: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, colorMode: MSPyDgnPlatform.ImageColorMode) -> tuple:
        ...
    
    @staticmethod
    def RGBSeparateToRGBInPlace(rgb: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, colorMode: MSPyDgnPlatform.ImageColorMode) -> int:
        ...
    
    @staticmethod
    def RGBToRGBSeparate(rgbInterlacedR: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, colorMode: MSPyDgnPlatform.ImageColorMode) -> tuple:
        ...
    
    @staticmethod
    def RGBToRGBSeparateInPlace(rgb: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, colorMode: MSPyDgnPlatform.ImageColorMode) -> int:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    @staticmethod
    def applyGamma(rgb: bytearray, sizeR: MSPyBentleyGeom.Point2d, gamma: float) -> None:
        ...
    
    @staticmethod
    def extCreateFileFromRGB(name: str, type: MSPyDgnPlatform.ImageFileFormat, colorMode: MSPyDgnPlatform.ImageColorMode, sizeR: MSPyBentleyGeom.Point2d, imageBufferR: bytearray, compressType: MSPyDgnPlatform.CompressionType, compressRatio: MSPyDgnPlatform.CompressionRatio, transparencyR: bytearray) -> int:
        ...
    
    @staticmethod
    def extractSubImage(outSizeR: MSPyBentleyGeom.Point2d, inR: bytearray, inSizeR: MSPyBentleyGeom.Point2d, rectR: MSPyDgnPlatform.BSIRect, imageFormat: int) -> tuple:
        ...
    
    @staticmethod
    def fileType(fileType: MSPyDgnPlatform.ImageFileFormat, fileNameP: str) -> MSPyDgnPlatform.ImageFileFormat:
        ...
    
    @staticmethod
    def getExportFormatString(formatId: MSPyDgnPlatform.ImageFileFormat) -> tuple:
        ...
    
    @staticmethod
    def getExportSupport(type: MSPyDgnPlatform.ImageFileFormat) -> tuple:
        ...
    
    @staticmethod
    def getExtension(type: MSPyDgnPlatform.ImageFileFormat) -> tuple:
        ...
    
    @staticmethod
    def getImportFormatString(formatId: MSPyDgnPlatform.ImageFileFormat) -> tuple:
        ...
    
    @staticmethod
    def memorySize(sizeP: MSPyBentleyGeom.Point2d, imageFormat: int) -> int:
        ...
    
    @staticmethod
    def mirror(rgb: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, imageFormat: int, vertical: bool) -> int:
        ...
    
    @staticmethod
    def negate(rgb: bytearray, sizeR: MSPyBentleyGeom.Point2d) -> None:
        ...
    
    @staticmethod
    def readFileInfo(fileName: str, fileType: MSPyDgnPlatform.ImageFileFormat) -> tuple:
        ...
    
    @staticmethod
    def readFileToRGB(fileName: str, fileType: MSPyDgnPlatform.ImageFileFormat, requestedSize: Optional[MSPyBentleyGeom.Point2d]) -> tuple:
        ...
    
    @staticmethod
    def resize(outputsize: MSPyBentleyGeom.Point2d, inputImageR: bytearray, inputsize: MSPyBentleyGeom.Point2d) -> tuple:
        ...
    
    @staticmethod
    def rotate(inpBufferR: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, imageFormat: int, rotation: int) -> tuple:
        ...
    
    @staticmethod
    def saveView(fileNameP: str, imageSizeR: MSPyBentleyGeom.Point2d, renderMode: int, imageFormat: MSPyDgnPlatform.ImageFileFormat, stereo: bool, antialias: bool, view: int) -> int:
        ...
    
    @staticmethod
    def saveViewToRGB(imageSizeR: MSPyBentleyGeom.Point2d, renderMode: int, stereo: bool, antialias: bool, view: int) -> tuple:
        ...
    
    @staticmethod
    def saveViewToRGBA(imageSizeR: MSPyBentleyGeom.Point2d, renderMode: int, stereo: bool, antialias: bool, view: int) -> tuple:
        ...
    
    @staticmethod
    def tintImage(imageR: bytearray, imageSizeR: MSPyBentleyGeom.Point2d, tintRGBP: MSPyDgnPlatform.RgbColorDef) -> None:
        ...
    
    @staticmethod
    def typeFromExtension(fileName: str) -> MSPyDgnPlatform.ImageFileFormat:
        ...
    
    @staticmethod
    def typeFromFile(fileNameP: str) -> MSPyDgnPlatform.ImageFileFormat:
        ...
    
class PyCExprValue:
    """
    None
    """

    def GetDoubleValue(self: MSPyMstnPlatform.PyCExprValue) -> float:
        ...
    
    def GetLongValue(self: MSPyMstnPlatform.PyCExprValue) -> int:
        ...
    
    def GetUtf8StringValue(self: MSPyMstnPlatform.PyCExprValue) -> MSPyBentley.Utf8String:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.PyCExprValue) -> MSPyMstnPlatform.PyCExprValueType:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.PyCExprValue, arg0: float) -> None
        
        2. __init__(self: MSPyMstnPlatform.PyCExprValue, arg0: int) -> None
        
        3. __init__(self: MSPyMstnPlatform.PyCExprValue, arg0: str) -> None
        """
        ...
    
class PyCExprValueType:
    """
    Members:
    
    ePy_CEXPR_TYPE_POINTER
    
    ePy_CEXPR_TYPE_LONG
    
    ePy_CEXPR_TYPE_ULONG
    
    ePy_CEXPR_TYPE_DOUBLE
    
    ePy_CEXPR_TYPE_LONG64
    """

    def __init__(self: MSPyMstnPlatform.PyCExprValueType, value: int) -> None:
        ...
    
    ePy_CEXPR_TYPE_DOUBLE: PyCExprValueType
    
    ePy_CEXPR_TYPE_LONG: PyCExprValueType
    
    ePy_CEXPR_TYPE_LONG64: PyCExprValueType
    
    ePy_CEXPR_TYPE_POINTER: PyCExprValueType
    
    ePy_CEXPR_TYPE_ULONG: PyCExprValueType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.PyCExprValueType) -> int:
        ...
    
class PyCExpression:
    """
    None
    """

    @staticmethod
    def GetCExpressionValue(expression: str, taskId: str, value: MSPyMstnPlatform.PyCExprValue) -> int:
        ...
    
    @staticmethod
    def SetCExpressionValue(expression: str, value: MSPyMstnPlatform.PyCExprValue, taskId: str) -> int:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PyCadInputMessage:
    """
    None
    """

    def GetCommandKeyin(self: MSPyMstnPlatform.PyCadInputMessage) -> MSPyBentley.WString:
        ...
    
    def GetCursorButton(self: MSPyMstnPlatform.PyCadInputMessage) -> int:
        ...
    
    def GetInputType(self: MSPyMstnPlatform.PyCadInputMessage) -> MSPyMstnPlatform.CadInputType:
        ...
    
    def GetKeyin(self: MSPyMstnPlatform.PyCadInputMessage) -> MSPyBentley.WString:
        ...
    
    def GetPoint(self: MSPyMstnPlatform.PyCadInputMessage) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def GetScreenPoint(self: MSPyMstnPlatform.PyCadInputMessage) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def GetView(self: MSPyMstnPlatform.PyCadInputMessage) -> MSPyDgnPlatform.ViewInfo:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PyCadInputQueue:
    """
    None
    """

    @staticmethod
    def AttachQtToolSetting(hQtWin: int) -> None:
        ...
    
    @staticmethod
    def AttachTkinterToolSetting(hTkWin: int) -> None:
        ...
    
    @staticmethod
    def GetInput(type1: MSPyMstnPlatform.CadInputType, type2: MSPyMstnPlatform.CadInputType, type3: MSPyMstnPlatform.CadInputType, type4: MSPyMstnPlatform.CadInputType) -> Bentley.MstnPlatform.PyCadInputMessage:
        ...
    
    @staticmethod
    def PythonMainLoop() -> None:
        ...
    
    @staticmethod
    def SendCommand(commandStr: str) -> None:
        ...
    
    @staticmethod
    def SendDataPoint(point: MSPyBentleyGeom.DPoint3d, view: int) -> None:
        ...
    
    @staticmethod
    def SendDataPointForLocate(element: MSPyDgnPlatform.ElementRefBase, point: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    @staticmethod
    def SendKeyin(keyinStr: str) -> None:
        ...
    
    @staticmethod
    def SendKeyinToPython(keyinStr: str) -> None:
        ...
    
    @staticmethod
    def SendReset() -> None:
        ...
    
    @staticmethod
    def SequeueLastInput(position: MSPyMstnPlatform.MSInputQueuePos) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PyCommandState:
    """
    None
    """

    @staticmethod
    def StartDefaultCommand() -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PyDocumentOpenDialogParams:
    """
    None
    """

    @staticmethod
    def Create() -> MSPyMstnPlatform.PyDocumentOpenDialogParams:
        ...
    
    @property
    def DefFileId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @DefFileId.setter
    def DefFileId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def DefRscFileHandle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @DefRscFileHandle.setter
    def DefRscFileHandle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def DefSeedDir(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DefSeedDir.setter
    def DefSeedDir(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def DefSeedFileId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @DefSeedFileId.setter
    def DefSeedFileId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def DefSeedFileName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DefSeedFileName.setter
    def DefSeedFileName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def DefSeedFilter(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DefSeedFilter.setter
    def DefSeedFilter(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def DefaultDir(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DefaultDir.setter
    def DefaultDir(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def DefaultFilter(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DefaultFilter.setter
    def DefaultFilter(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def DialogId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @DialogId.setter
    def DialogId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def DialogTitle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DialogTitle.setter
    def DialogTitle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def DirCfgVar(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @DirCfgVar.setter
    def DirCfgVar(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def FilterInfoString(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @FilterInfoString.setter
    def FilterInfoString(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def FilterRscFileHandle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @FilterRscFileHandle.setter
    def FilterRscFileHandle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def FilterStringListId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @FilterStringListId.setter
    def FilterStringListId(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    def GetDefFileId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetDefRscFileHandle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetDefSeedDir(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetDefSeedFileId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetDefSeedFileName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetDefSeedFilter(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetDefaultDir(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetDefaultFilter(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetDialogId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetDialogTitle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetDirCfgVar(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetFilterInfoString(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetFilterRscFileHandle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetFilterStringListId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetOpenCreate(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetPostIncludeCADFileOpenFilters(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> bool:
        ...
    
    def GetPreIncludeCADFileOpenFilters(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> bool:
        ...
    
    def GetRequiredRights(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetRscFileHandle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    
    def GetSuggestedFileName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetWorkSetName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    def GetWorkSpaceName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    
    @property
    def OpenCreate(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @OpenCreate.setter
    def OpenCreate(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def PostIncludeCADFileOpenFilters(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> bool:
        ...
    @PostIncludeCADFileOpenFilters.setter
    def PostIncludeCADFileOpenFilters(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: bool) -> None:
        ...
    
    @property
    def PreIncludeCADFileOpenFilters(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> bool:
        ...
    @PreIncludeCADFileOpenFilters.setter
    def PreIncludeCADFileOpenFilters(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: bool) -> None:
        ...
    
    @property
    def RequiredRights(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @RequiredRights.setter
    def RequiredRights(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    @property
    def RscFileHandle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> int:
        ...
    @RscFileHandle.setter
    def RscFileHandle(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: int) -> None:
        ...
    
    def SetDefFileId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, fileId: int) -> None:
        ...
    
    def SetDefRscFileHandle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, fileHandle: int) -> None:
        ...
    
    def SetDefSeedDir(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, seedDir: MSPyBentley.WString) -> None:
        ...
    
    def SetDefSeedFileId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, fileId: int) -> None:
        ...
    
    def SetDefSeedFileName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, fileName: MSPyBentley.WString) -> None:
        ...
    
    def SetDefSeedFilter(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, seedFilter: MSPyBentley.WString) -> None:
        ...
    
    def SetDefaultDir(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, defDir: MSPyBentley.WString) -> None:
        ...
    
    def SetDefaultFilter(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, filter: MSPyBentley.WString) -> None:
        ...
    
    def SetDialogId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, dlgId: int) -> None:
        ...
    
    def SetDialogTitle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, title: MSPyBentley.WString) -> None:
        ...
    
    def SetDirCfgVar(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, cfgVar: MSPyBentley.WString) -> None:
        ...
    
    def SetFilterInfoString(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, infoString: MSPyBentley.WString) -> None:
        ...
    
    def SetFilterRscFileHandle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, fileHandle: int) -> None:
        ...
    
    def SetFilterStringListId(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, listId: int) -> None:
        ...
    
    def SetOpenCreate(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, openCreate: int) -> None:
        ...
    
    def SetPostIncludeCADFileOpenFilters(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, isOn: bool) -> None:
        ...
    
    def SetPreIncludeCADFileOpenFilters(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, isOn: bool) -> None:
        ...
    
    def SetRequiredRights(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, rights: int) -> None:
        ...
    
    def SetRscFileHandle(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, h: int) -> None:
        ...
    
    def SetSuggestedFileName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, fileName: MSPyBentley.WString) -> None:
        ...
    
    def SetWorkSetName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, name: MSPyBentley.WString) -> None:
        ...
    
    def SetWorkSpaceName(self: MSPyMstnPlatform.PyDocumentOpenDialogParams, name: MSPyBentley.WString) -> None:
        ...
    
    @property
    def SuggestedFileName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @SuggestedFileName.setter
    def SuggestedFileName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def WorkSetName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @WorkSetName.setter
    def WorkSetName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def WorkSpaceName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams) -> MSPyBentley.WString:
        ...
    @WorkSpaceName.setter
    def WorkSpaceName(arg0: MSPyMstnPlatform.PyDocumentOpenDialogParams, arg1: MSPyBentley.WString) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PyEventsHandler:
    """
    None
    """

    @staticmethod
    def AddModalDialogEventsHandler(eventHandler: MSPyMstnPlatform.IPyModalDialogEvents) -> None:
        ...
    
    @staticmethod
    def RemoveModalDialogEventsHandler(eventHandler: MSPyMstnPlatform.IPyModalDialogEvents) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PyMsdDialogBoxResult:
    """
    Members:
    
    ePyMsdDialogBoxResultApply
    
    ePyMsdDialogBoxResultReset
    
    ePyMsdDialogBoxResultOK
    
    ePyMsdDialogBoxResultCancel
    
    ePyMsdDialogBoxResultDefault
    
    ePyMsdDialogBoxResultYes
    
    ePyMsdDialogBoxResultNo
    
    ePyMsdDialogBoxResultRetry
    
    ePyMsdDialogBoxResultStop
    
    ePyMsdDialogBoxResultHelp
    
    ePyMsdDialogBoxResultYesToAll
    """

    def __init__(self: MSPyMstnPlatform.PyMsdDialogBoxResult, value: int) -> None:
        ...
    
    ePyMsdDialogBoxResultApply: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultCancel: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultDefault: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultHelp: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultNo: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultOK: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultReset: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultRetry: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultStop: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultYes: PyMsdDialogBoxResult
    
    ePyMsdDialogBoxResultYesToAll: PyMsdDialogBoxResult
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.PyMsdDialogBoxResult) -> int:
        ...
    
class PythonKeyinManager:
    """
    None
    """

    @staticmethod
    def GetManager() -> MSPyMstnPlatform.PythonKeyinManager:
        ...
    
    def LoadCommandTableFromXml(self: MSPyMstnPlatform.PythonKeyinManager, pythonFilePath: MSPyBentley.WString, keyInXmlFileName: MSPyBentley.WString) -> int:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class RegionPlaneId:
    """
    None
    """

    @staticmethod
    def Create(*args, **kwargs):
        """
        Overloaded function.
        
        1. Create(eh: MSPyDgnPlatform.ElementHandle, pep: MSPyDgnPlatform.PersistentElementPath, status: MSPyMstnPlatform.GeometryId.Status) -> MSPyMstnPlatform.GeometryId
        
        2. Create(eh: MSPyDgnPlatform.ElementHandle) -> MSPyMstnPlatform.GeometryId
        """
        ...
    
    class DimensionToComponent:
        """
        Members:
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED
        
        eDCM3_DIMENSION_TO_EXTERIOR
        
        eDCM3_DIMENSION_TO_CENTRE_POINT
        
        eDCM3_DIMENSION_TO_AXIS
        
        eDCM3_DIMENSION_TO_PLANE
        
        eDCM3_DIMENSION_TO_SPINE
        
        eDCM3_DIMENSION_TO_APEX
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.DimensionToComponent, value: int) -> None:
            ...
        
        eDCM3_DIMENSION_TO_APEX: DimensionToComponent
        
        eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
        
        eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
        
        eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
        
        eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
        
        eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
        
        eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.DimensionToComponent) -> int:
            ...
        
    @property
    def Element(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    @ElementRef.setter
    def ElementRef(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    @property
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId) -> int:
        ...
    @EntityIndex.setter
    def EntityIndex(arg0: MSPyMstnPlatform.GeometryId, arg1: int) -> None:
        ...
    
    class FlagMasks:
        """
        Members:
        
        eFlagMask_ParamX
        
        eFlagMask_ParamY
        
        eFlagMask_EntityIndex
        """
    
        def __init__(self: MSPyMstnPlatform.GeometryId.FlagMasks, value: int) -> None:
            ...
        
        eFlagMask_EntityIndex: FlagMasks
        
        eFlagMask_ParamX: FlagMasks
        
        eFlagMask_ParamY: FlagMasks
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyMstnPlatform.GeometryId.FlagMasks) -> int:
            ...
        
    def GetElement(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetElementRef(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def GetEntityIndex(self: MSPyMstnPlatform.GeometryId) -> int:
        ...
    
    def GetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetParameter(self: MSPyMstnPlatform.GeometryId) -> float
        
        2. GetParameter(self: MSPyMstnPlatform.GeometryId, param: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def GetRootPep(self: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    
    def GetRootRange(self: MSPyMstnPlatform.GeometryId, range: MSPyBentleyGeom.DRange3d) -> MSPyDgnPlatform.BentleyStatus:
        ...
    
    def GetStatus(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    
    def GetType(self: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    @property
    def RootPep(arg0: MSPyMstnPlatform.GeometryId) -> MSPyDgnPlatform.PersistentElementPath:
        ...
    @RootPep.setter
    def RootPep(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetElementRef(self: MSPyMstnPlatform.GeometryId, elemRef: MSPyDgnPlatform.ElementRefBase) -> None:
        ...
    
    def SetEntityIndex(self: MSPyMstnPlatform.GeometryId, entityIndex: int) -> None:
        ...
    
    def SetParameter(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetParameter(self: MSPyMstnPlatform.GeometryId, param: float) -> None
        
        2. SetParameter(self: MSPyMstnPlatform.GeometryId, arg0: MSPyBentleyGeom.DPoint2d) -> None
        """
        ...
    
    def SetRootPep(self: MSPyMstnPlatform.GeometryId, pep: MSPyDgnPlatform.PersistentElementPath) -> None:
        ...
    
    def SetStatus(self: MSPyMstnPlatform.GeometryId, status: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Status(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Status:
        ...
    @Status.setter
    def Status(arg0: MSPyMstnPlatform.GeometryId, arg1: MSPyMstnPlatform.GeometryId.Status) -> None:
        ...
    
    @property
    def Type(arg0: MSPyMstnPlatform.GeometryId) -> MSPyMstnPlatform.GeometryId.Type:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBCurve: Type
    
    eBRepVertex: Type
    
    eCurve: Type
    
    eCurveArcAxis: Type
    
    eCurvePoint: Type
    
    eDCM3_DIMENSION_TO_APEX: DimensionToComponent
    
    eDCM3_DIMENSION_TO_AXIS: DimensionToComponent
    
    eDCM3_DIMENSION_TO_CENTRE_POINT: DimensionToComponent
    
    eDCM3_DIMENSION_TO_EXTERIOR: DimensionToComponent
    
    eDCM3_DIMENSION_TO_NOT_SPECIFIED: DimensionToComponent
    
    eDCM3_DIMENSION_TO_PLANE: DimensionToComponent
    
    eDCM3_DIMENSION_TO_SPINE: DimensionToComponent
    
    eDCM3_G_FIXED: Status
    
    eDCM3_G_NOT_CHANGED: Status
    
    eDCM3_G_NOT_CONSISTENT: Status
    
    eDCM3_G_NOT_CONSISTENT_DIMENSIONS: Status
    
    eDCM3_G_NOT_CONSISTENT_OTHER: Status
    
    eDCM3_G_NOT_CONSISTENT_UNKNOWN: Status
    
    eDCM3_G_OVER_DEFINED: Status
    
    eDCM3_G_UNDER_DEFINED: Status
    
    eDCM3_G_UNKNOWN: Status
    
    eDCM3_G_WELL_DEFINED: Status
    
    eDCM3_G_WITHIN_BOUNDS: Status
    
    eEdge: Type
    
    eEdgeArcAxis: Type
    
    eElement: Type
    
    eFace: Type
    
    eFaceAxis: Type
    
    eFlagMask_EntityIndex: FlagMasks
    
    eFlagMask_ParamX: FlagMasks
    
    eFlagMask_ParamY: FlagMasks
    
    eInvalidElement: Type
    
    eRegionPlane: Type
    
class RevolveSettings:
    """
    None
    """

    def SetAngle(self: MSPyMstnPlatform.RevolveSettings, angle: float) -> None:
        ...
    
    def SetAxis(self: MSPyMstnPlatform.RevolveSettings, axis: MSPyBentleyGeom.DRay3d) -> None:
        ...
    
    def SetAxisDirection(self: MSPyMstnPlatform.RevolveSettings, axisDirection: MSPyBentleyGeom.DVec3d) -> None:
        ...
    
    def SetAxisOrigin(self: MSPyMstnPlatform.RevolveSettings, axisOrigin: MSPyBentleyGeom.DPoint3d) -> None:
        ...
    
    def SetThickness(self: MSPyMstnPlatform.RevolveSettings, thickness: float) -> None:
        ...
    
    def Validate(self: MSPyMstnPlatform.RevolveSettings) -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.RevolveSettings) -> None
        
        2. __init__(self: MSPyMstnPlatform.RevolveSettings, hitPoint: MSPyBentleyGeom.DPoint3d, createSheet: bool, angle: float, axisMode: int, ev: MSPyDgnView.DgnButtonEvent, axisPoint: MSPyDgnView.DgnButtonEvent, curveVector: MSPyBentleyGeom.CurveVector, thicknessMode: int, thickness: float) -> None
        
        3. __init__(self: MSPyMstnPlatform.RevolveSettings, hitPoint: MSPyBentleyGeom.DPoint3d, createSheet: bool, angle: float, axisMode: int, origin: MSPyBentleyGeom.DPoint3d, axisPoint: MSPyBentleyGeom.DPoint3d, curveVector: MSPyBentleyGeom.CurveVector, thicknessMode: int, thickness: float, vp: MSPyDgnPlatform.Viewport) -> None
        """
        ...
    
    @property
    def angle(self: MSPyMstnPlatform.RevolveSettings) -> float:
        ...
    @angle.setter
    def angle(self: MSPyMstnPlatform.RevolveSettings, arg0: float) -> None:
        ...
    
    @property
    def axis(self: MSPyMstnPlatform.RevolveSettings) -> MSPyBentleyGeom.DRay3d:
        ...
    @axis.setter
    def axis(self: MSPyMstnPlatform.RevolveSettings, arg0: MSPyBentleyGeom.DRay3d) -> None:
        ...
    
    @property
    def createSheet(arg0: MSPyMstnPlatform.RevolveSettings) -> bool:
        ...
    @createSheet.setter
    def createSheet(arg0: MSPyMstnPlatform.RevolveSettings, arg1: bool) -> None:
        ...
    
    @property
    def numRules(arg0: MSPyMstnPlatform.RevolveSettings) -> int:
        ...
    @numRules.setter
    def numRules(arg0: MSPyMstnPlatform.RevolveSettings, arg1: int) -> None:
        ...
    
    @property
    def thickness(self: MSPyMstnPlatform.RevolveSettings) -> float:
        ...
    @thickness.setter
    def thickness(self: MSPyMstnPlatform.RevolveSettings, arg0: float) -> None:
        ...
    
    @property
    def thicknessMode(arg0: MSPyMstnPlatform.RevolveSettings) -> int:
        ...
    @thicknessMode.setter
    def thicknessMode(arg0: MSPyMstnPlatform.RevolveSettings, arg1: int) -> None:
        ...
    
class SectorAngleType:
    """
    Members:
    
    eParallel_AntiClockwise
    
    eParallel_Clockwise
    
    eAntiParallel_AntiClockwise
    
    eAntiParallel_Clockwise
    """

    def __init__(self: MSPyMstnPlatform.SectorAngleType, value: int) -> None:
        ...
    
    eAntiParallel_AntiClockwise: SectorAngleType
    
    eAntiParallel_Clockwise: SectorAngleType
    
    eParallel_AntiClockwise: SectorAngleType
    
    eParallel_Clockwise: SectorAngleType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.SectorAngleType) -> int:
        ...
    
class SessionMonitor:
    """
    None
    """

    def __init__(self: MSPyMstnPlatform.SessionMonitor) -> None:
        ...
    
class SmartFeatureElement:
    """
    None
    """

    @staticmethod
    def AddFeature(eeh: MSPyDgnPlatform.EditElementHandle, feature: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Add parametric feature
        
        Parameter ``out]``:
        eeh Parametric Feature element
        
        Parameter ``feature``:
        Feature node to add
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def CollapseHistory(eeh: MSPyDgnPlatform.EditElementHandle, featureTree: MSPyMstnPlatform.SmartFeatureNode, featureNode: MSPyMstnPlatform.SmartFeatureNode) -> tuple:
        """
        Collapse feature tree
        
        Parameter ``eeh``:
        Parametric solid element
        
        Parameter ``featureTree``:
        Feature tree
        
        Parameter ``featureNode``:
        Feature node to collapse
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def CreateAndWriteSmartFeatureElement(newFeatureEeh: MSPyDgnPlatform.EditElementHandle, targetEh: MSPyDgnPlatform.ElementHandle, destinationModelRef: MSPyDgnPlatform.DgnModelRef, node: MSPyMstnPlatform.SmartFeatureNode, childElementToControlFlagsMap: dict, mergeParametrics: bool = False) -> int:
        ...
    
    @staticmethod
    def CreateSingleChildSmartFeature(newFeatureEeh: MSPyDgnPlatform.EditElementHandle, templateEh: MSPyDgnPlatform.ElementHandle, destinationModelRef: MSPyDgnPlatform.DgnModelRef, oldFeatureEh: MSPyDgnPlatform.ElementHandle, node: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Create parametric feature having a single child.
        
        Parameter ``newFeatureEeh``:
        Parametric solid element
        
        Parameter ``templateEh``:
        Template element
        
        Parameter ``destinationModelRef``:
        Model ref to create parametric feature
        
        Parameter ``oldFeatureEh``:
        existing element handle on which parametric feature has to create
        
        Parameter ``node``:
        Feature node
        
        Returns:
        SUCCESS if the operation is successful.
        
        Remark:
        Chamfer, Blend Feature can be created using it.
        """
        ...
    
    @staticmethod
    def DoRollBack(eeh: MSPyDgnPlatform.EditElementHandle) -> int:
        """
        Rollback feature
        
        Parameter ``out]``:
        eeh Parametric Feature element
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def DropToLegacy(agenda: MSPyDgnPlatform.ElementAgenda, featureEh: MSPyDgnPlatform.ElementHandle) -> int:
        """
        Drop parametric feature to smart solid state
        
        Parameter ``agenda``:
        Dropped elements
        
        Parameter ``featureEh``:
        Parametric solid element to drop
        
        Returns:
        SUCCESS if the drop is successful.
        """
        ...
    
    @staticmethod
    def DumpFeatureTree(label: MSPyBentley.WString, eh: MSPyDgnPlatform.ElementHandle) -> int:
        """
        Print feature tree information for debug purpose
        
        Parameter ``label``:
        E.g. WPrintfString(L" Element:% d ", eh.GetElementId()
        
        Parameter ``eh``:
        Parametric Feature element
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def ExtractTree(eh: MSPyDgnPlatform.ElementHandle) -> tuple:
        """
        Get smart feature tree of supplied element.
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def GetFeatureName(subEntity: MSPyDgnPlatform.ISubEntity, hostEh: MSPyDgnPlatform.ElementHandle) -> MSPyBentley.WString:
        """
        Get feature name
        
        Parameter ``subEntity``:
        subEntity used to precisely locate feature
        
        Parameter ``hostEh``:
        Parametric Solid element
        
        Returns:
        Feature name
        """
        ...
    
    @staticmethod
    def GetFeaturesFromNodeIds(features: MSPyMstnPlatform.SmartFeatureNodePtrArray, featureEh: MSPyDgnPlatform.ElementHandle, nodeIdsSet: MSPyBentley.UInt32Array) -> tuple:
        """
        Get feature by using node id
        
        Parameter ``featureTree``:
        Feature tree
        
        Parameter ``features``:
        Features to be returned
        
        Parameter ``featureEh``:
        Parametric Feature element
        
        Parameter ``nodeIdsSet``:
        Features nodes
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def GetFeaturesFromNodeName(features: MSPyMstnPlatform.SmartFeatureNodePtrArray, featureEh: MSPyDgnPlatform.ElementHandle, nodeName: MSPyBentley.WString) -> tuple:
        """
        Get feature by using node name
        
        Parameter ``featureTree``:
        Feature tree
        
        Parameter ``features``:
        Features to be returned
        
        Parameter ``featureEh``:
        Parametric Feature element
        
        Parameter ``nodeName``:
        Feature node name
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def GetFeaturesFromSubEntities(features: MSPyMstnPlatform.SmartFeatureNodePtrArray, featureEh: MSPyDgnPlatform.ElementHandle, subEntities: MSPyDgnPlatform.ISubEntityPtrArray) -> tuple:
        """
        Get feature by supplying sub entities captured by UI
        
        Parameter ``featureTree``:
        Feature tree
        
        Parameter ``features``:
        Features to be returned
        
        Parameter ``featureEh``:
        Parametric Feature element
        
        Parameter ``subEntities``:
        Subentity to get feature from
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def GetOrCreateSmartFeature(newFeatureEeh: MSPyDgnPlatform.EditElementHandle, templateEh: MSPyDgnPlatform.ElementHandle, destinationModelRef: MSPyDgnPlatform.DgnModelRef, oldFeatureEh: MSPyDgnPlatform.ElementHandle, mergeParametrics: bool, visible: bool, temporary: bool, profile: bool) -> int:
        """
        Get existing parametric feature otherwise create a new one.
        
        Parameter ``newFeatureEeh``:
        Parametric solid element
        
        Parameter ``templateEh``:
        Template element
        
        Parameter ``destinationModelRef``:
        Model ref to create parametric feature
        
        Parameter ``oldFeatureEh``:
        existing element handle on which parametric feature has to create
        
        Parameter ``mergeParametrics``:
        Merge Parameter option
        
        Parameter ``visible``:
        Visible
        
        Parameter ``temporary``:
        Temporary
        
        Parameter ``profile``:
        Whether element is profile or not
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def HideExternalLeaf(featureEeh: MSPyDgnPlatform.EditElementHandle, leafElemRef: MSPyDgnPlatform.ElementRefBase) -> int:
        """
        Hide external leaf
        
        Parameter ``featureEeh``:
        Parametric solid element
        
        Parameter ``leaf``:
        Element ref of leaf
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def IsSmartFeature(eh: MSPyDgnPlatform.ElementHandle) -> bool:
        """
        Confirm whether supplied element is parametric feature.
        
        Parameter ``eh``:
        Element to test
        
        Parameter ``templateEh``:
        Template element
        """
        ...
    
    @staticmethod
    def RemoveFeature(eh: MSPyDgnPlatform.ElementHandle, tree: MSPyMstnPlatform.SmartFeatureNode, nodeToDelete: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Delete parametric feature
        
        Parameter ``eh``:
        Parametric Feature element
        
        Parameter ``tree``:
        Feature tree to use
        
        Parameter ``nodeToDelete``:
        Feature node to delete
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def SaveTree(featureEeh: MSPyDgnPlatform.EditElementHandle, teatureTree: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Save smart feature tree on supplied element.
        
        Parameter ``out]``:
        featureEeh Parametric Feature element
        
        Parameter ``featureTree``:
        the tree to save on element
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def ShowExternalLeaf(featureEeh: MSPyDgnPlatform.EditElementHandle, leafElemRef: MSPyDgnPlatform.ElementRefBase) -> int:
        """
        Show external leaf
        
        Parameter ``featureEeh``:
        Parametric solid element
        
        Parameter ``leaf``:
        Element ref of leaf
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    @staticmethod
    def WriteSmartFeature(newFeatureEeh: MSPyDgnPlatform.EditElementHandle, featureTree: MSPyMstnPlatform.SmartFeatureNode, oldFeatureEh: MSPyDgnPlatform.ElementHandle) -> int:
        """
        Write Smart Feature into the file.
        
        Parameter ``newFeatureEeh``:
        Parametric solid element
        
        Parameter ``featureTree``:
        Feature tree
        
        Parameter ``oldFeatureEeh``:
        Old feature element or Template element
        
        Returns:
        SUCCESS if the operation is successful.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SmartFeatureHandlerId:
    """
    Members:
    
    eUnspecified
    
    eExternalSolid
    
    eBoolean
    
    eBlend
    
    eChamfer
    
    eHollow
    
    eCut
    
    eThicken
    
    eOffsetFace
    
    eTranslateFace
    
    eImprintElement
    
    eImprintOffset
    
    eExternalProfile
    
    eTaperFace
    
    eSpinFace
    
    eEAP1Hole
    
    eProtrusion
    
    eRectangularArray
    
    ePolarArray
    
    eFenceStretch
    
    eFenceClip
    
    eExtrude
    
    eRevolve
    
    eLoftSurface
    
    eModifyVertex
    
    eModifyEdge
    
    eHole
    
    eTrim
    
    eDeleteFace
    
    eDeleteLump
    
    eExternalEdgeProfile
    
    eCopyFeature
    
    eSweepEdge
    
    eEllipticalCone
    
    eEllipsoid
    
    eSizeFilter
    
    eArrayAlongPath
    
    eAssociativeElement
    
    eExtrudeAlongProfile
    
    eAssociativeElementSymbology
    """

    def __init__(self: MSPyMstnPlatform.SmartFeatureHandlerId, value: int) -> None:
        ...
    
    eArrayAlongPath: SmartFeatureHandlerId
    
    eAssociativeElement: SmartFeatureHandlerId
    
    eAssociativeElementSymbology: SmartFeatureHandlerId
    
    eBlend: SmartFeatureHandlerId
    
    eBoolean: SmartFeatureHandlerId
    
    eChamfer: SmartFeatureHandlerId
    
    eCopyFeature: SmartFeatureHandlerId
    
    eCut: SmartFeatureHandlerId
    
    eDeleteFace: SmartFeatureHandlerId
    
    eDeleteLump: SmartFeatureHandlerId
    
    eEAP1Hole: SmartFeatureHandlerId
    
    eEllipsoid: SmartFeatureHandlerId
    
    eEllipticalCone: SmartFeatureHandlerId
    
    eExternalEdgeProfile: SmartFeatureHandlerId
    
    eExternalProfile: SmartFeatureHandlerId
    
    eExternalSolid: SmartFeatureHandlerId
    
    eExtrude: SmartFeatureHandlerId
    
    eExtrudeAlongProfile: SmartFeatureHandlerId
    
    eFenceClip: SmartFeatureHandlerId
    
    eFenceStretch: SmartFeatureHandlerId
    
    eHole: SmartFeatureHandlerId
    
    eHollow: SmartFeatureHandlerId
    
    eImprintElement: SmartFeatureHandlerId
    
    eImprintOffset: SmartFeatureHandlerId
    
    eLoftSurface: SmartFeatureHandlerId
    
    eModifyEdge: SmartFeatureHandlerId
    
    eModifyVertex: SmartFeatureHandlerId
    
    eOffsetFace: SmartFeatureHandlerId
    
    ePolarArray: SmartFeatureHandlerId
    
    eProtrusion: SmartFeatureHandlerId
    
    eRectangularArray: SmartFeatureHandlerId
    
    eRevolve: SmartFeatureHandlerId
    
    eSizeFilter: SmartFeatureHandlerId
    
    eSpinFace: SmartFeatureHandlerId
    
    eSweepEdge: SmartFeatureHandlerId
    
    eTaperFace: SmartFeatureHandlerId
    
    eThicken: SmartFeatureHandlerId
    
    eTranslateFace: SmartFeatureHandlerId
    
    eTrim: SmartFeatureHandlerId
    
    eUnspecified: SmartFeatureHandlerId
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.SmartFeatureHandlerId) -> int:
        ...
    
class SmartFeatureNode:
    """
    None
    """

    def CanBeDisabled(self: MSPyMstnPlatform.SmartFeatureNode) -> bool:
        """
        Whether node can be disabled?
        """
        ...
    
    @property
    def ChildCount(arg0: MSPyMstnPlatform.SmartFeatureNode) -> int:
        ...
    
    @property
    def Children(arg0: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureNodePtrArray:
        ...
    
    def ClearColorOverride(self: MSPyMstnPlatform.SmartFeatureNode) -> None:
        """
        Clear the color
        """
        ...
    
    def ClearMaterialOverride(self: MSPyMstnPlatform.SmartFeatureNode) -> None:
        """
        Clear material
        """
        ...
    
    def ClearTransparencyOverride(self: MSPyMstnPlatform.SmartFeatureNode) -> None:
        """
        Clear transparency
        """
        ...
    
    @property
    def CustomName(arg0: MSPyMstnPlatform.SmartFeatureNode) -> MSPyBentley.WString:
        ...
    @CustomName.setter
    def CustomName(arg0: MSPyMstnPlatform.SmartFeatureNode, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def Disabled(arg0: MSPyMstnPlatform.SmartFeatureNode) -> bool:
        ...
    @Disabled.setter
    def Disabled(arg0: MSPyMstnPlatform.SmartFeatureNode, arg1: bool) -> None:
        ...
    
    def GetAllChildrenRecursively(self: MSPyMstnPlatform.SmartFeatureNode, allChildren: MSPyMstnPlatform.SmartFeatureNodePtrArray) -> None:
        """
        Get all children recursively
        
        Parameter ``allChildren``:
        All children
        """
        ...
    
    def GetBasisTransform(self: MSPyMstnPlatform.SmartFeatureNode, transform: MSPyBentleyGeom.Transform, hostEh: MSPyDgnPlatform.ElementHandle, applyTransform: bool = True) -> MSPyDgnPlatform.BentleyStatus:
        """
        Get basis transform of feature
        """
        ...
    
    def GetBody(self: MSPyMstnPlatform.SmartFeatureNode, hostEh: MSPyDgnPlatform.ElementHandle, getSolids: bool, getSheets: bool, applyHostTransform: bool, displayError: bool) -> tuple:
        """
        Acquire body of parametric feature.
        
        Parameter ``body``:
        Output body
        
        Parameter ``hostEh``:
        Parametric Feature Element
        
        Parameter ``getSolids``:
        solid output is required
        
        Parameter ``getSheets``:
        sheet output is required
        
        Parameter ``applyHostTransform``:
        Apply Host tansform
        
        Parameter ``displayError``:
        Display error
        """
        ...
    
    def GetChild(self: MSPyMstnPlatform.SmartFeatureNode, index: int) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Get child
        
        Parameter ``index``:
        Child index
        
        Returns:
        SmartFeatureNodePtr of child node
        """
        ...
    
    def GetChildCount(self: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Get child count
        
        Returns:
        Child count
        """
        ...
    
    def GetChildren(self: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureNodePtrArray:
        """
        Get all children
        
        Returns:
        Smart Feature node vector of children
        """
        ...
    
    def GetColorOverride(self: MSPyMstnPlatform.SmartFeatureNode) -> tuple:
        """
        Get color of the body
        """
        ...
    
    def GetCustomName(self: MSPyMstnPlatform.SmartFeatureNode) -> MSPyBentley.WString:
        """
        Get custom name
        """
        ...
    
    def GetDisabled(self: MSPyMstnPlatform.SmartFeatureNode) -> bool:
        """
        Query the disable status of smart feature node.
        """
        ...
    
    def GetHandlerId(self: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureHandlerId:
        """
        Get paramtric feature type. Should be compared with
        SmartFeatureHandlerId enum.
        """
        ...
    
    def GetHighestNodeId(self: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Get highest node id in smart feature tree
        """
        ...
    
    def GetLeaf(self: MSPyMstnPlatform.SmartFeatureNode, eh: MSPyDgnPlatform.ElementHandle) -> int:
        """
        Get leaf
        
        Parameter ``eh``:
        leaf element handle
        
        Returns:
        SUCCESS if the operation is successful
        """
        ...
    
    def GetLowestNodeId(self: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Get lowest node id in smart feature tree
        """
        ...
    
    def GetMaterialOverride(self: MSPyMstnPlatform.SmartFeatureNode) -> tuple:
        """
        Get material of body
        """
        ...
    
    def GetNodeId(self: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Get node id
        
        Returns:
        Node id
        """
        ...
    
    def GetParent(self: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Get parent
        
        Returns:
        SmartFeatureNodePtr of parent node
        """
        ...
    
    def GetParentOfHiddenExternalLeaf(self: MSPyMstnPlatform.SmartFeatureNode) -> tuple:
        """
        Get parent of hidden external leaf. E.g. Extrude feature is returned;
        in case of hidden profile
        
        Parameter ``externalLeafParent``:
        Parent node of external leaf
        
        Returns:
        SUCCESS if the operation is successful
        """
        ...
    
    def GetSingleChild(self: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureNode:
        """
        Returns immediate single child.
        """
        ...
    
    def GetSingleChildBody(self: MSPyMstnPlatform.SmartFeatureNode, hostEh: MSPyDgnPlatform.ElementHandle, getSolids: bool, getSheets: bool, applyHostTransform: bool, displayError: bool) -> tuple:
        """
        Get body of immediate single child.
        """
        ...
    
    def GetTransparencyOverride(self: MSPyMstnPlatform.SmartFeatureNode) -> tuple:
        """
        Get transparency
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureHandlerId:
        ...
    
    @property
    def HighestNodeId(arg0: MSPyMstnPlatform.SmartFeatureNode) -> int:
        ...
    
    @property
    def LowestNodeId(arg0: MSPyMstnPlatform.SmartFeatureNode) -> int:
        ...
    
    @property
    def NodeId(arg0: MSPyMstnPlatform.SmartFeatureNode) -> int:
        ...
    
    @property
    def Parent(arg0: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureNode:
        ...
    
    @staticmethod
    def RelocateFeature(node: MSPyMstnPlatform.SmartFeatureNode, target: MSPyMstnPlatform.SmartFeatureNode, hostEh: MSPyDgnPlatform.ElementHandle, errorStringId: MSPyBentley.WString) -> tuple:
        """
        Relocate feature node
        """
        ...
    
    def SetColorOverride(self: MSPyMstnPlatform.SmartFeatureNode, color: int) -> None:
        """
        Set color on the body
        """
        ...
    
    def SetCustomName(self: MSPyMstnPlatform.SmartFeatureNode, name: MSPyBentley.WString) -> None:
        """
        Set custom name
        """
        ...
    
    def SetDisabled(self: MSPyMstnPlatform.SmartFeatureNode, disable: bool) -> None:
        """
        Disable the smart feature node.
        
        Parameter ``disabled``:
        Boolean value to disable
        """
        ...
    
    def SetMaterialOverride(self: MSPyMstnPlatform.SmartFeatureNode, materialOverride: MSPyDgnPlatform.MaterialId) -> None:
        """
        Set material on the body
        """
        ...
    
    def SetTransparencyOverride(self: MSPyMstnPlatform.SmartFeatureNode, transparencyOverride: float) -> None:
        """
        Set transparency
        """
        ...
    
    @property
    def SingleChild(arg0: MSPyMstnPlatform.SmartFeatureNode) -> MSPyMstnPlatform.SmartFeatureNode:
        ...
    
    def TransformFeatureAndDependents(self: MSPyMstnPlatform.SmartFeatureNode, transform: MSPyBentleyGeom.Transform) -> int:
        """
        Transform a feature and its dependents
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SmartFeatureNodePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyMstnPlatform.SmartFeatureNodePtrArray) -> None
        
        2. __init__(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, arg0: MSPyMstnPlatform.SmartFeatureNodePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, x: MSPyMstnPlatform.SmartFeatureNode) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyMstnPlatform.SmartFeatureNodePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, x: MSPyMstnPlatform.SmartFeatureNode) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, L: MSPyMstnPlatform.SmartFeatureNodePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, i: int, x: MSPyMstnPlatform.SmartFeatureNode) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyMstnPlatform.SmartFeatureNodePtrArray) -> MSPyMstnPlatform.SmartFeatureNode
        
        Remove and return the last item
        
        2. pop(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, i: int) -> MSPyMstnPlatform.SmartFeatureNode
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyMstnPlatform.SmartFeatureNodePtrArray, x: MSPyMstnPlatform.SmartFeatureNode) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class SmartFeatureUtil:
    """
    None
    """

    @staticmethod
    def DrawDynamicSpinAxis(axis: MSPyBentleyGeom.DRay3d, range: MSPyBentleyGeom.DRange3d, normal: MSPyBentleyGeom.DVec3d, viewport: MSPyDgnPlatform.Viewport) -> None:
        """
        Draw dynamic spin axis.
        
        Parameter ``axis``:
        axis
        
        Parameter ``range``:
        range
        
        Parameter ``normal``:
        normal
        
        Parameter ``viewport``:
        viewport
        """
        ...
    
    @staticmethod
    def GetCurveVector(eh: MSPyDgnPlatform.ElementHandle, regionsOnly: bool) -> tuple:
        """
        Get CurveVector using elementHandle.
        
        Parameter ``curveVector``:
        Output curve vector
        
        Parameter ``eh``:
        Element used to get curve vector
        
        Parameter ``regionsOnly``:
        only regions
        """
        ...
    
    @staticmethod
    def GetCurveVectorPlane(plane: MSPyBentleyGeom.DPlane3d, curveVector: MSPyBentleyGeom.CurveVector, point: MSPyBentleyGeom.DPoint3d = None, parallelIfLinear: bool = True) -> None:
        """
        Get plane of supplied CurveVector.
        
        Parameter ``plane``:
        output plane
        
        Parameter ``curveVector``:
        of which plane has to retrieve
        
        Parameter ``point``:
        Point used on curve vector
        
        Parameter ``parallelIfLinear``:
        Parallel option be used in case of linear
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SolidUtil:
    """
    None
    """

    @staticmethod
    def ClosestPoint(entity: MSPyDgnPlatform.ISolidKernelEntity, testPt: MSPyBentleyGeom.DPoint3d) -> tuple:
        """
        Get the closest point on body to a given point.
        
        Parameter ``entity``:
        The entity to pick sub-entities for.
        
        Parameter ``testPt``:
        The space point.
        
        Parameter ``subEntity``:
        The face, edge, or vertext sub-entity that contains the closest
        point.
        
        Parameter ``point``:
        The closest point on the body.
        
        Returns:
        true if closest point was found.
        """
        ...
    
    @staticmethod
    def ClosestPointToEdge(subEntity: MSPyDgnPlatform.ISubEntity, testPt: MSPyBentleyGeom.DPoint3d) -> tuple:
        """
        Get the closest point on an edge to a given point.
        
        Parameter ``subEntity``:
        The edge to test.
        
        Parameter ``testPt``:
        The space point.
        
        Parameter ``point``:
        The closest point on the edge.
        
        Parameter ``param``:
        The u parameter at the closest point.
        
        Returns:
        true if closest point was found.
        """
        ...
    
    @staticmethod
    def ClosestPointToFace(subEntity: MSPyDgnPlatform.ISubEntity, testPt: MSPyBentleyGeom.DPoint3d, point: MSPyBentleyGeom.DPoint3d, normal: MSPyBentleyGeom.DVec3d, param: MSPyBentleyGeom.DPoint2d) -> bool:
        """
        Get the closest point on a face to a given point.
        
        Parameter ``subEntity``:
        The face to test.
        
        Parameter ``testPt``:
        The space point.
        
        Parameter ``point``:
        The closest point on the face.
        
        Parameter ``normal``:
        The surface normal at the closest point.
        
        Parameter ``param``:
        The uv parameter at the closest point.
        
        Returns:
        true if closest point was found.
        """
        ...
    
    class Convert:
        """
        None
        """
    
        @staticmethod
    def BodyToElement(eeh: MSPyDgnPlatform.EditElementHandle, entity: MSPyDgnPlatform.ISolidKernelEntity, templateEh: MSPyDgnPlatform.ElementHandle, modelRef: MSPyDgnPlatform.DgnModelRef) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        @staticmethod
    def ElementToBodies(out: MSPyDgnPlatform.ISolidKernelEntityPtrArray, eh: MSPyDgnPlatform.ElementHandle, getSolids: bool = True, getSheets: bool = True, getWires: bool = True) -> tuple:
            """
            Create bodies from an element that represents one or more wire, sheet,
            or solid bodies.
            
            Parameter ``out``:
            The collection of new bodies.
            
            Parameter ``hasMissingGeom``:
            Will be set to true if not all geometry for the element is
            included in the output body collection.
            
            Parameter ``eh``:
            The element to convert.
            
            Parameter ``getSolids``:
            Collect solid bodies.
            
            Parameter ``getSheets``:
            Collect sheet bodies.
            
            Parameter ``getWires``:
            Collect wire bodies.
            
            Returns:
            SUCCESS if at least one body of the requested type was created.
            """
            ...
        
        @staticmethod
    def ElementToBody(eh: MSPyDgnPlatform.ElementHandle, getSolid: bool = True, getSheet: bool = True, getWire: bool = True) -> tuple:
            """
            Create a body from an element that can represent a single wire, sheet,
            or solid body.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``eh``:
            The element to convert.
            
            Parameter ``getSolid``:
            Accept element that can be converted to a single solid body.
            
            Parameter ``getSheet``:
            Accept element that can be converted to a single sheet body.
            
            Parameter ``getWire``:
            Accept element that can be converted to a single wire body.
            
            Returns:
            SUCCESS if a body of the requested type was created.
            """
            ...
        
        @staticmethod
    def SubEntityToCurveVector(subEntity: MSPyDgnPlatform.ISubEntity) -> tuple:
            """
            Create a simplified CurveVector representation of the given sub-
            entity.
            
            Parameter ``curves``:
            A CurveVector representing the sub-entity.
            
            Parameter ``subEntity``:
            The planar face, edge, or vertex to convert. @note A planar face,
            edge, or vertex can be represented by a CurveVector. Non-planar
            faces will return ERROR.
            
            Returns:
            SUCCESS if a CurveVector could be created to represent the sub-
            entity.
            """
            ...
        
        @staticmethod
    def SubEntityToGeometry(subEntity: MSPyDgnPlatform.ISubEntity, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
            """
            Create a simplified IGeometryPtr representation of the given sub-
            entity (non-BRep geometry).
            
            Parameter ``geom``:
            A reference counted pointer to the new geometry type.
            
            Parameter ``subEntity``:
            The face, edge, or vertex to convert.
            
            Parameter ``modelRef``:
            The destination modelRef. @note A planar face, edge, or vertex can
            be represented by a CurveVector. Non-planar faces can be
            represented by a MSBsplineSurface or ISolidPrimitive.
            
            Returns:
            SUCCESS if a IGeometryPtr could be created to represent the sub-
            entity.
            """
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    @staticmethod
    def CopyEntity(*args, **kwargs):
        """
        CopyEntity(in: MSPyDgnPlatform.ISolidKernelEntity) -> tuple
        
        Create a new ISolidKernelEntityPtr by copying the input body.
        
        Parameter ``out``:
        The new body.
        
        Parameter ``in``:
        The body to copy.
        
        Returns:
        SUCCESS if copy is valid.
        """
        ...
    
    class Create:
        """
        None
        """
    
        @staticmethod
    def BodyFromBSurface(surface: MSPyBentleyGeom.MSBsplineSurface, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
            """
            Create a new sheet body from a MSBsplineSurface.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``surface``:
            The surface to create a body from.
            
            Parameter ``model``:
            Used to get the solid to uor scale. (ModelInfo.GetSolidExtent)
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        @staticmethod
    def BodyFromCurveVector(curve: MSPyBentleyGeom.CurveVector, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
            """
            Create a new wire or planar sheet body from a CurveVector that
            represents an open path, closed path, region with holes, or union
            region.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``curve``:
            The curve vector to create a body from.
            
            Parameter ``model``:
            Used to get the solid to uor scale. (ModelInfo.GetSolidExtent)
            @note The CurvePrimitives that define an open path or closed loop
            are expected to be connected head-to-tail and may not intersect
            except at a vertex. A vertex can be shared by at most 2 edges.
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        @staticmethod
    def BodyFromExtrusionToBody(extrudeTo: MSPyDgnPlatform.ISolidKernelEntity, profile: MSPyDgnPlatform.ISolidKernelEntity, reverseDirection: bool) -> tuple:
            """
            Create a new body by extruding a planar sheet body up to another body.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``extrudeTo``:
            The body to trim the extruded body to.
            
            Parameter ``profile``:
            The planar sheet body to extrude.
            
            Parameter ``reverseDirection``:
            To specify if extrusion is in the same direction or opposite
            direction to the surface normal of the profile sheet body.
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        @staticmethod
    def BodyFromLoft(profiles: MSPyBentleyGeom.CurveVectorPtrArray, guides: MSPyBentleyGeom.CurveVectorPtrArray, modelRef: MSPyDgnPlatform.DgnModelRef, periodic: bool = False, segment: bool = False) -> tuple:
            """
            Create a new sheet or solid body from surfaces created by lofting
            through a set of cross section profiles.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``profiles``:
            The cross sections profiles.
            
            Parameter ``nProfiles``:
            The profile count.
            
            Parameter ``guides``:
            An optional set of guide curves for constrolling the loft.
            
            Parameter ``nGuides``:
            The guide curve count.
            
            Parameter ``model``:
            Used to get the solid to uor scale. (ModelInfo.GetSolidExtent)
            
            Parameter ``periodic``:
            If true, a closed surface is constructed in which the first
            section curve is used as the last section curve.
            
            Parameter ``segment``:
            If true, surfaces are created linearly between each section curve,
            with no smoothing.
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        @staticmethod
    def BodyFromPolyface(meshData: MSPyBentleyGeom.PolyfaceQuery, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
            """
            Create a new sheet or solid body from a Polyface.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``meshData``:
            The surface or solid to create a body from.
            
            Parameter ``model``:
            Used to get the solid to uor scale. (ModelInfo.GetSolidExtent)
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        @staticmethod
    def BodyFromSolidPrimitive(primitive: MSPyBentleyGeom.ISolidPrimitive, modelRef: MSPyDgnPlatform.DgnModelRef) -> tuple:
            """
            Create a new sheet or solid body from an ISolidPrimitive.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``primitive``:
            The surface or solid to create a body from.
            
            Parameter ``model``:
            Used to get the solid to uor scale. (ModelInfo.GetSolidExtent)
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        @staticmethod
    def BodyFromSweep(profile: MSPyBentleyGeom.CurveVector, path: MSPyBentleyGeom.CurveVector, modelRef: MSPyDgnPlatform.DgnModelRef, alignParallel: bool, selfRepair: bool, createSheet: bool, lockDirection: MSPyBentleyGeom.DVec3d = None, twistAngle: Optional[float] = None, scale: Optional[float] = None, scalePoint: MSPyBentleyGeom.DPoint3d = None) -> tuple:
            """
            Create a new sheet or solid body by sweeping a cross section profile
            along a path.
            
            Parameter ``out``:
            The new body.
            
            Parameter ``profile``:
            The cross section profile. (open, closed, or region with holes)
            
            Parameter ``path``:
            The path to sweep along.
            
            Parameter ``model``:
            Used to get the solid to uor scale. (ModelInfo.GetSolidExtent)
            
            Parameter ``alignParallel``:
            true to keep profile at a fixed angle to global axis instead of
            path tangent (and lock direction).
            
            Parameter ``selfRepair``:
            true to attempt repair of self-intersections.
            
            Parameter ``createSheet``:
            true to force a sheet body to be created from a closed profile
            which would normally produce a solid body. (Similiar behavior to
            ISolidPrimitive.GetCapped)
            
            Parameter ``lockDirection``:
            Optionally keep profile at a fixed angle relative to the path
            tangent projected into a plane perpendicular to the lock
            direction. Only valid when alignParallel is false.
            
            Parameter ``twistAngle``:
            Optionally spin profile as it moves along the path.
            
            Parameter ``scale``:
            Optionally scale profile as it moves along the path.
            
            Parameter ``scalePoint``:
            The profile point to scale about, required when applying scale.
            
            Returns:
            SUCCESS if body was created.
            """
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    class Debug:
        """
        None
        """
    
        @staticmethod
    def DumpEntity(entity: MSPyDgnPlatform.ISolidKernelEntity, label: str) -> None:
            ...
        
        @staticmethod
    def DumpSubEntity(subEntity: MSPyDgnPlatform.ISubEntity, label: str) -> None:
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    @staticmethod
    def DisjoinBody(*args, **kwargs):
        """
        DisjoinBody(out: MSPyDgnPlatform.ISolidKernelEntityPtrArray, in: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Create separate bodies from a single multi-region body.
        
        Parameter ``out``:
        The collection of new bodies.
        
        Parameter ``in``:
        The body to separate.
        
        Returns:
        SUCCESS if input body could be separated, ERROR if input body is
        already a single region.
        """
        ...
    
    @staticmethod
    def Draw(subEntity: MSPyDgnPlatform.ISubEntity, context: MSPyDgnPlatform.ViewContext) -> MSPyDgnPlatform.BentleyStatus:
        """
        Draw geometry for the given face, edge, or vertex to the specified
        ViewContext.
        
        Parameter ``subEntity``:
        The face, edge, or vertex sub-entity to display.
        
        Parameter ``context``:
        The ViewContext to output geometry to. @note Uses the current
        ElemMatSymb, caller is expected to setup symbology beforehand.
        """
        ...
    
    @staticmethod
    def EvaluateEdge(subEntity: MSPyDgnPlatform.ISubEntity, point: MSPyBentleyGeom.DPoint3d, uDir: MSPyBentleyGeom.DVec3d, uParam: float) -> MSPyDgnPlatform.BentleyStatus:
        """
        Evaluate point and tangent at a u parameter on the curve of the given
        edge sub-entity.
        
        Parameter ``subEntity``:
        The edge sub-entity to query.
        
        Parameter ``point``:
        The coordinates of the point on the curve at the u parameter.
        
        Parameter ``uDir``:
        The normalized curve tangent at the u parameter.
        
        Parameter ``uParam``:
        The u parameter to evaluate.
        
        Returns:
        SUCCESS if the parameter could be evaluated.
        """
        ...
    
    @staticmethod
    def EvaluateFace(subEntity: MSPyDgnPlatform.ISubEntity, point: MSPyBentleyGeom.DPoint3d, normal: MSPyBentleyGeom.DVec3d, uDir: MSPyBentleyGeom.DVec3d, vDir: MSPyBentleyGeom.DVec3d, uvParam: MSPyBentleyGeom.DPoint2d) -> MSPyDgnPlatform.BentleyStatus:
        """
        Evaluate point, normal, and derivatives at a uv parameter on the
        surface of the given face sub-entity.
        
        Parameter ``subEntity``:
        The face sub-entity to query.
        
        Parameter ``point``:
        The coordinates of the point on the surface at the uv parameter.
        
        Parameter ``normal``:
        The normalized surface normal at the uv parameter.
        
        Parameter ``uDir``:
        The first derivative with respect to u at the uv parameter.
        
        Parameter ``vDir``:
        The first derivative with respect to v at the uv parameter.
        
        Parameter ``uvParam``:
        The uv parameter pair to evaluate.
        
        Returns:
        SUCCESS if the parameter could be evaluated.
        """
        ...
    
    @staticmethod
    def EvaluateVertex(subEntity: MSPyDgnPlatform.ISubEntity, point: MSPyBentleyGeom.DPoint3d) -> MSPyDgnPlatform.BentleyStatus:
        """
        Evaluate point of the given vertex sub-entity.
        
        Parameter ``subEntity``:
        The vertex sub-entity to query.
        
        Parameter ``point``:
        The coordinates of the point at the given vertex.
        
        Returns:
        SUCCESS if vertex point exists.
        """
        ...
    
    @staticmethod
    def GetBodyEdges(*args, **kwargs):
        """
        GetBodyEdges(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISolidKernelEntity) -> int
        
        Query the set of edges of the input body.
        
        Parameter ``subEntities``:
        An optional vector to hold the sub-entities of type
        SubEntityType_Edge, pass NULL if just interested in count.
        
        Parameter ``in``:
        The entity to query.
        
        Returns:
        A count of the number of edges.
        """
        ...
    
    @staticmethod
    def GetBodyFaces(*args, **kwargs):
        """
        GetBodyFaces(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISolidKernelEntity) -> int
        
        Query the set of faces of the input body.
        
        Parameter ``subEntities``:
        An optional vector to hold the sub-entities of type
        SubEntityType_Face, pass NULL if just interested in count.
        
        Parameter ``in``:
        The entity to query.
        
        Returns:
        A count of the number of faces.
        """
        ...
    
    @staticmethod
    def GetBodyVertices(*args, **kwargs):
        """
        GetBodyVertices(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISolidKernelEntity) -> int
        
        Query the set of vertices of the input body.
        
        Parameter ``subEntities``:
        An optional vector to hold the sub-entities of type
        SubEntityType_Vertex, pass NULL if just interested in count.
        
        Parameter ``in``:
        The entity to query.
        
        Returns:
        A count of the number of vertices.
        """
        ...
    
    @staticmethod
    def GetEdgeFaces(*args, **kwargs):
        """
        GetEdgeFaces(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Query the set of faces for the input edge sub-entity.
        
        Parameter ``subEntities``:
        A vector to hold the sub-entities of type SubEntityType_Face.
        
        Parameter ``subEntity``:
        The edge sub-entity to query.
        
        Returns:
        SUCCESS if input entity was the correct type and output vector was
        populated.
        """
        ...
    
    @staticmethod
    def GetEdgeParameterRange(subEntities: MSPyDgnPlatform.ISubEntity, uRange: MSPyBentleyGeom.DRange1d) -> MSPyDgnPlatform.BentleyStatus:
        """
        Get u edge parameter range for the given edge sub-entity.
        
        Parameter ``subEntity``:
        The edge sub-entity to query.
        
        Parameter ``uRange``:
        The u parameter range of the edge.
        
        Returns:
        SUCCESS if edge parameter range was computed.
        """
        ...
    
    @staticmethod
    def GetEdgeVertices(*args, **kwargs):
        """
        GetEdgeVertices(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Query the set of vertices for the input edge sub-entity.
        
        Parameter ``subEntities``:
        A vector to hold the sub-entities of type SubEntityType_Vertex.
        
        Parameter ``subEntity``:
        The edge sub-entity to query.
        
        Returns:
        SUCCESS if input entity was the correct type and output vector was
        populated.
        """
        ...
    
    @staticmethod
    def GetEntityRange(range: MSPyBentleyGeom.DRange3d, entity: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus:
        """
        Get an axis aligned bounding box for the given body.
        
        Parameter ``range``:
        The bounding box.
        
        Parameter ``entity``:
        The entity to query.
        
        Returns:
        SUCCESS if bounding box could be computed.
        """
        ...
    
    @staticmethod
    def GetFaceEdges(*args, **kwargs):
        """
        GetFaceEdges(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Query the set of edges for the input face sub-entity.
        
        Parameter ``subEntities``:
        A vector to hold the sub-entities of type SubEntityType_Edge.
        
        Parameter ``subEntity``:
        The face sub-entity to query.
        
        Returns:
        SUCCESS if input entity was the correct type and output vector was
        populated.
        """
        ...
    
    @staticmethod
    def GetFaceParameterRange(subEntities: MSPyDgnPlatform.ISubEntity, uRange: MSPyBentleyGeom.DRange1d, vRange: MSPyBentleyGeom.DRange1d) -> MSPyDgnPlatform.BentleyStatus:
        """
        Get uv face parameter range for the given face sub-entity.
        
        Parameter ``subEntity``:
        The face sub-entity to query.
        
        Parameter ``uRange``:
        The u parameter range of the face.
        
        Parameter ``vRange``:
        The v parameter range of the face.
        
        Returns:
        SUCCESS if face parameter range was computedx.
        """
        ...
    
    @staticmethod
    def GetFaceVertices(*args, **kwargs):
        """
        GetFaceVertices(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Query the set of vertices for the input face sub-entity.
        
        Parameter ``subEntities``:
        A vector to hold the sub-entities of type SubEntityType_Vertex.
        
        Parameter ``subEntity``:
        The face sub-entity to query.
        
        Returns:
        SUCCESS if input entity was the correct type and output vector was
        populated.
        """
        ...
    
    @staticmethod
    def GetLoopEdgesFromEdge(loopEdges: MSPyDgnPlatform.ISubEntityPtrArray, edge: MSPyDgnPlatform.ISubEntity, face: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus:
        """
        Query the set of edges that comprise a single face loop containing the
        given edge sub-entity.
        
        Parameter ``loopEdges``:
        A vector to hold the sub-entities of type SubEntityType_Edge.
        
        Parameter ``edge``:
        The edge sub-entity that is part of the loop.
        
        Parameter ``face``:
        The face sub-entity that has the loop as part of it's bounds.
        
        Returns:
        SUCCESS if the output vector was populated.
        """
        ...
    
    @staticmethod
    def GetPlanarFaceData(point: MSPyBentleyGeom.DPoint3d, normal: MSPyBentleyGeom.DVec3d, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus:
        """
        Evaluate point and normal at center of face parameter range for the
        given face sub-entity.
        
        Parameter ``point``:
        The coordinates of the point on the surface at the center of the
        face parameter range. Can be NULL.
        
        Parameter ``normal``:
        The normalized surface normal at the center of the face parameter
        range. Can be NULL.
        
        Parameter ``subEntity``:
        The face sub-entity to query.
        
        Returns:
        SUCCESS if face is planar. The point and normal are still returned
        when non-planar if the face sub-entity is valid.
        """
        ...
    
    @staticmethod
    def GetSmoothBlendEdges(smoothEdges: MSPyDgnPlatform.ISubEntityPtrArray, edge: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus:
        """
        Query the set of edges that are connected and tangent to the given
        edge sub-entity.
        
        Parameter ``smoothEdges``:
        A vector to hold the sub-entities of type SubEntityType_Edge.
        
        Parameter ``edge``:
        The edge sub-entity to query smoothly connected edges for.
        
        Returns:
        SUCCESS if the output vector was populated. @note These are the
        edges that would be included by the propagateSmooth option of
        SolidUtil.Modify.BlendEdges and SolidUtil.Modify.ChamferEdges.
        """
        ...
    
    @staticmethod
    def GetSubEntityRange(range: MSPyBentleyGeom.DRange3d, subEntity: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus:
        """
        Get an axis aligned bounding box for the given face or edge.
        
        Parameter ``range``:
        The bounding box.
        
        Parameter ``subEntity``:
        The face or edge sub-entity to query.
        
        Returns:
        SUCCESS if bounding box could be computed.
        """
        ...
    
    @staticmethod
    def GetVertexEdges(*args, **kwargs):
        """
        GetVertexEdges(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Query the set of edges for the input vertex sub-entity.
        
        Parameter ``subEntities``:
        A vector to hold the sub-entities of type SubEntityType_Edge.
        
        Parameter ``subEntity``:
        The vertex sub-entity to query.
        
        Returns:
        SUCCESS if input entity was the correct type and output vector was
        populated.
        """
        ...
    
    @staticmethod
    def GetVertexFaces(*args, **kwargs):
        """
        GetVertexFaces(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, in: MSPyDgnPlatform.ISubEntity) -> MSPyDgnPlatform.BentleyStatus
        
        Query the set of faces for the input vertex sub-entity.
        
        Parameter ``subEntities``:
        A vector to hold the sub-entities of type SubEntityType_Face.
        
        Parameter ``subEntity``:
        The vertex sub-entity to query.
        
        Returns:
        SUCCESS if input entity was the correct type and output vector was
        populated.
        """
        ...
    
    @staticmethod
    def IsPointInsideBody(entity: MSPyDgnPlatform.ISolidKernelEntity, testPt: MSPyBentleyGeom.DPoint3d) -> bool:
        """
        Test if a point is inside or on the boundary of the given body.
        
        Parameter ``entity``:
        The entity to test.
        
        Parameter ``testPt``:
        The space point.
        
        Returns:
        true if point is not outside the body.
        """
        ...
    
    @staticmethod
    def Locate(entity: MSPyDgnPlatform.ISolidKernelEntity, boresite: MSPyBentleyGeom.DRay3d, intersectEntities: MSPyDgnPlatform.ISubEntityPtrArray, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray, maxFace: int, maxEdge: int, maxVertex: int, maxDistance: float) -> bool:
        """
        Pick face, edge, and vertex sub-entities of a body by their proximity
        to a ray.
        
        Parameter ``entity``:
        The entity to pick sub-entities for.
        
        Parameter ``boresite``:
        The ray origin and direction.
        
        Parameter ``intersectEntities``:
        The selected sub-entities.
        
        Parameter ``intersectPts``:
        The hit points on the selected sub-entities.
        
        Parameter ``intersectParams``:
        The parameters on the selected sub-entities. For edge hits x is
        the u parameter (y always 0). Not meaningful for vertex hits
        (always 0,0).
        
        Parameter ``maxFace``:
        The maximum number of face hits to return. Pass 0 to not pick
        faces.
        
        Parameter ``maxEdge``:
        The maximum number of edge hits to return. Pass 0 to not pick
        edges.
        
        Parameter ``maxVertex``:
        The maximum number of vertex hits to return. Pass 0 to not pick
        vertices.
        
        Parameter ``maxDistance``:
        An edge or vertex will be picked if it is within this distance
        from the ray. Not used for face picking. @note The returned
        entities are ordered by increasing distance from ray origin to hit
        point on entity.
        
        Returns:
        true if ray intersected a requested entity type.
        """
        ...
    
    class Modify:
        """
        None
        """
    
        @staticmethod
    def BlendEdges(target: MSPyDgnPlatform.ISolidKernelEntity, edges: MSPyDgnPlatform.ISubEntityPtrArray, radii: MSPyBentley.DoubleArray, propagateSmooth: bool = True) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the specified edges of the given body by changing them into
            faces having the requested blending surface geometry.
            
            Parameter ``target``:
            The target body to blend.
            
            Parameter ``edges``:
            The array of edge sub-entities to attach blends to.
            
            Parameter ``radii``:
            The array of blend radius values for each edge.
            
            Parameter ``nEdges``:
            Count of edge sub-entities.
            
            Parameter ``propagateSmooth``:
            Whether to automatically continue blend along connected and
            tangent edges that aren't explicitly specified in edges array.
            
            Returns:
            SUCCESS if blends could be created.
            """
            ...
        
        @staticmethod
    def BooleanCut(*args, **kwargs):
            """
            Overloaded function.
            
            1. BooleanCut(target: MSPyDgnPlatform.ISolidKernelEntity, planarTool: MSPyBentleyGeom.CurveVector, directionMode: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode, depthMode: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode, distance: float, invert: bool, defaultNormal: MSPyBentleyGeom.DVec3d, nodeId: int) -> MSPyDgnPlatform.BentleyStatus
            
            Modify the target body by subtracting a cut body produced from
            sweeping the sheet tool body according to the specified cut direction
            and depth.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``planarTool``:
            The planar sheet body for the cut profile.
            
            Parameter ``directionMode``:
            The sweep direction relative to the sheet body normal of the cut
            profile.
            
            Parameter ``depthMode``:
            To specify if the cut should extended through the entire body or
            only create a pocket of fixed depth.
            
            Parameter ``distance``:
            To specify the cut depth for CutDepthMode.Blind.
            
            Parameter ``invert``:
            Set true to reverse the sense of the tool (outside rather than
            inside if closed).
            
            Parameter ``defaultNormal``:
            If not NULL, uused to to determine the cut direction only if the
            tool is a line segment.
            
            Parameter ``nodeId``:
            The node id of the entity.
            
            Returns:
            SUCCESS if cut operation was completed.
            
            2. BooleanCut(target: MSPyDgnPlatform.ISolidKernelEntity, planarTool: MSPyBentleyGeom.CurveVector, directionMode: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode, depthMode: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode, distance: float, invert: bool, defaultNormal: MSPyBentleyGeom.DVec3d, nodeId: int, cutDirection: MSPyBentleyGeom.DVec3d) -> MSPyDgnPlatform.BentleyStatus
            
            Modify the target body by subtracting a cut body produced from
            sweeping the sheet tool body according to the specified cut direction
            and depth.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``planarTool``:
            The planar sheet body for the cut profile.
            
            Parameter ``directionMode``:
            The sweep direction relative to the sheet body normal of the cut
            profile.
            
            Parameter ``depthMode``:
            To specify if the cut should extended through the entire body or
            only create a pocket of fixed depth.
            
            Parameter ``distance``:
            To specify the cut depth for CutDepthMode.Blind.
            
            Parameter ``invert``:
            Set true to reverse the sense of the tool (outside rather than
            inside if closed).
            
            Parameter ``defaultNormal``:
            If not NULL, uused to to determine the cut direction only if the
            tool is a line segment.
            
            Parameter ``nodeId``:
            The node id of the entity.
            
            Returns:
            SUCCESS if cut operation was completed.
            """
            ...
        
        @staticmethod
    def BooleanIntersect(target: MSPyDgnPlatform.ISolidKernelEntity, tools: MSPyDgnPlatform.ISolidKernelEntityPtrArray) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by intersecting with one or more tool bodies.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``tools``:
            A list of one or more tool bodies (consumed in boolean).
            
            Parameter ``nTools``:
            Count of tool bodies.
            
            Returns:
            SUCCESS if boolean operation was completed.
            """
            ...
        
        @staticmethod
    def BooleanSubtract(target: MSPyDgnPlatform.ISolidKernelEntity, tools: MSPyDgnPlatform.ISolidKernelEntityPtrArray) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by subtracting one or more tool bodies.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``tools``:
            Array of one or more tool bodies (consumed in boolean).
            
            Parameter ``nTools``:
            Count of tool bodies.
            
            Returns:
            SUCCESS if boolean operation was completed.
            """
            ...
        
        @staticmethod
    def BooleanUnion(target: MSPyDgnPlatform.ISolidKernelEntity, tools: MSPyDgnPlatform.ISolidKernelEntityPtrArray) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by uniting with one or more tool bodies.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``tools``:
            Array of one or more tool bodies (consumed in boolean).
            
            Parameter ``nTools``:
            Count of tool bodies.
            
            Returns:
            SUCCESS if boolean operation was completed.
            """
            ...
        
        @staticmethod
    def ChamferEdges(target: MSPyDgnPlatform.ISolidKernelEntity, edges: MSPyDgnPlatform.ISubEntityPtrArray, values1: MSPyBentley.DoubleArray, values2: MSPyBentley.DoubleArray, mode: MSPyMstnPlatform.SolidUtil.Modify.ChamferMode, propagateSmooth: bool = True) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the specified edges of the given body by changing them into
            faces having the requested chamfer surface geometry.
            
            Parameter ``target``:
            The target body to chamfer.
            
            Parameter ``edges``:
            The array of edge sub-entities to attach chamfers to.
            
            Parameter ``values1``:
            The array of chamfer values for each edge, value meaning varies by
            ChamferMode.
            
            Parameter ``values2``:
            The array of chamfer values for each edge, value meaning varies by
            ChamferMode. (Unused for ChamferMode.Length)
            
            Parameter ``nEdges``:
            Count of edge sub-entities.
            
            Parameter ``mode``:
            Specifies chamfer type and determines how values1 and values2 are
            interpreted and used.
            
            Parameter ``propagateSmooth``:
            Whether to automatically continue chamfer along connected and
            tangent edges that aren't explicitly specified in edges array.
            
            Returns:
            SUCCESS if chamfers could be created.
            """
            ...
        
        class ChamferMode:
            """
            Members:
            
            eRanges
            
            eLength
            
            eDistances
            
            eDistanceAngle
            
            eAngleDistance
            """
        
            def __init__(self: MSPyMstnPlatform.SolidUtil.Modify.ChamferMode, value: int) -> None:
                ...
            
            eAngleDistance: ChamferMode
            
            eDistanceAngle: ChamferMode
            
            eDistances: ChamferMode
            
            eLength: ChamferMode
            
            eRanges: ChamferMode
            
            @property
            def name(self: handle) -> str:
                ...
            
            @property
            def value(arg0: MSPyMstnPlatform.SolidUtil.Modify.ChamferMode) -> int:
                ...
            
        @staticmethod
    def ClashDetectionBetweenTargetAndTool(target: MSPyDgnPlatform.ISolidKernelEntity, planarTool: MSPyBentleyGeom.CurveVector, directionMode: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode, depthMode: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode, distance: float, defaultNormal: MSPyBentleyGeom.DVec3d, cutDirection: MSPyBentleyGeom.DVec3d) -> MSPyDgnPlatform.BentleyStatus:
            """
            Get clash result between target and tool from the list of targets
            
            Parameter ``clashTool``:
            List of target tool causing clashes with the target
            
            Parameter ``target``:
            The target body
            
            Parameter ``planarTool``:
            The planar sheet body for the cut profile.
            
            Parameter ``directionMode``:
            The sweep direction relative to the sheet body normal of the cut
            profile.
            
            Parameter ``depthMode``:
            To specify if the cut should extended through the entire body or
            only create a pocket of fixed depth.
            
            Parameter ``distance``:
            To specify the cut depth for CutDepthMode.Blind.
            
            Parameter ``invert``:
            Set true to reverse the sense of the tool (outside rather than
            inside if closed).
            
            Parameter ``defaultNormal``:
            If not NULL, uused to to determine the cut direction only if the
            tool is a line segment.
            
            Parameter ``cutDirection``:
            Cut direction
            
            Returns:
            SUCCESS if there occur clash between given vector and target
            """
            ...
        
        class CutDepthMode:
            """
            Members:
            
            eAll
            
            eBlind
            """
        
            def __init__(self: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode, value: int) -> None:
                ...
            
            eAll: CutDepthMode
            
            eBlind: CutDepthMode
            
            @property
            def name(self: handle) -> str:
                ...
            
            @property
            def value(arg0: MSPyMstnPlatform.SolidUtil.Modify.CutDepthMode) -> int:
                ...
            
        class CutDirectionMode:
            """
            Members:
            
            eForward
            
            eBackward
            
            eBoth
            """
        
            def __init__(self: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode, value: int) -> None:
                ...
            
            eBackward: CutDirectionMode
            
            eBoth: CutDirectionMode
            
            eForward: CutDirectionMode
            
            @property
            def name(self: handle) -> str:
                ...
            
            @property
            def value(arg0: MSPyMstnPlatform.SolidUtil.Modify.CutDirectionMode) -> int:
                ...
            
        @staticmethod
    def DeleteFaces(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target solid or sheet body by removing selected faces and
            healing.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``faces``:
            The array of faces to be delted.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Returns:
            SUCCESS if faces could be deleted.
            """
            ...
        
        @staticmethod
    def DeleteRedundantTopology(target: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by removing redundant topology. An example of
            redundant topololgy would be an edge where the faces on either side
            have identical surface geometry.
            
            Parameter ``target``:
            The target body to modify.
            
            Returns:
            SUCCESS if operation was completed.
            """
            ...
        
        @staticmethod
    def Emboss(target: MSPyDgnPlatform.ISolidKernelEntity, tool: MSPyDgnPlatform.ISolidKernelEntity, reverseDirection: bool) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by adding a protrusion constructed from the
            sheet tool body and its imprint on the target body.
            
            Parameter ``target``:
            The target body to modify, can be a sheet or solid.
            
            Parameter ``tool``:
            The planar sheet body for the emboss profile.
            
            Parameter ``reverseDirection``:
            To specify if material is to be added in the same direction or
            opposite direction to the surface normal of the tool sheet body.
            
            Returns:
            SUCCESS if emboss operation was completed.
            """
            ...
        
        @staticmethod
    def HollowFaces(*args, **kwargs):
            """
            HollowFaces(target: MSPyDgnPlatform.ISolidKernelEntity, defaultDistance: float, faces: MSPyDgnPlatform.ISubEntityPtrArray, distances: MSPyBentley.DoubleArray, addStep: MSPyMstnPlatform.SolidUtil.Modify.StepFacesOption = <StepFacesOption.eADD_STEP_NonCoincident: 2>) -> MSPyDgnPlatform.BentleyStatus
            
            Modify the target solid body by hollowing using specified face
            offsets.
            
            Parameter ``target``:
            The target body to hollow.
            
            Parameter ``defaultDistance``:
            The offset distance to apply to any face not specifically included
            in the faces array.
            
            Parameter ``faces``:
            The array of faces to be offset by other than the default offset
            distance.
            
            Parameter ``distances``:
            The array of offsets for each face.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Parameter ``addStep``:
            The option for how to handle the creation of step faces. @note A
            positive offset goes outwards (in the direction of the surface
            normal), a negative offset is inwards, and a face with zero offset
            will be pierced/removed.
            
            Returns:
            SUCCESS if hollow could be created.
            """
            ...
        
        @staticmethod
    def ImprintCurveVectorOnBody(target: MSPyDgnPlatform.ISolidKernelEntity, curveVector: MSPyBentleyGeom.CurveVector, direction: MSPyBentleyGeom.DVec3d, extendOpenCurvesToEdge: bool = True) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by imprinting new edges from the specified
            curve vector.
            
            Parameter ``target``:
            The target body to imprint.
            
            Parameter ``curveVector``:
            The curve geometry to imprint.
            
            Parameter ``direction``:
            The project direction for imprinting the curve.
            
            Parameter ``extendOpenCurvesToEdge``:
            The option to extend an open curve to ensure that it splits the
            face.
            
            Returns:
            SUCCESS if imprint created.
            """
            ...
        
        @staticmethod
    def ImprintWiresOnFace(face: MSPyDgnPlatform.ISubEntity, wires: MSPyDgnPlatform.ISolidKernelEntityPtrArray, extendToEdge: bool) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify a face of a body by imprinting the specified wire bodies.
            
            Parameter ``face``:
            The target face sub-entity to imprint.
            
            Parameter ``wires``:
            The vector of wire bodies to imprint the curves of onto the face.
            
            Parameter ``extendToEdge``:
            The option to extend an open wire body to ensure that it splits
            the face.
            
            Returns:
            SUCCESS if face imprint created.
            """
            ...
        
        @staticmethod
    def OffsetFaces(*args, **kwargs):
            """
            OffsetFaces(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray, distances: MSPyBentley.DoubleArray, addStep: MSPyMstnPlatform.SolidUtil.Modify.StepFacesOption = <StepFacesOption.eADD_STEP_NonCoincident: 2>) -> MSPyDgnPlatform.BentleyStatus
            
            Modify the target solid or sheet body by offsetting selected faces.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``faces``:
            The array of faces to be offset.
            
            Parameter ``distances``:
            The array of offsets for each face.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Parameter ``addStep``:
            The option for how to handle the creation of step faces.
            
            Returns:
            SUCCESS if faces could be offset.
            """
            ...
        
        @staticmethod
    def OffsetFacesWithStatus(*args, **kwargs):
            """
            OffsetFacesWithStatus(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray, distances: MSPyBentley.DoubleArray, addStep: MSPyMstnPlatform.SolidUtil.Modify.StepFacesOption, offsetStatus: int = <StepFacesOption.eADD_STEP_NonCoincident: 2>) -> tuple
            """
            ...
        
        @staticmethod
    def OffsetThroughHole(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray, distances: MSPyBentley.DoubleArray) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target solid by offsetting face through body. It will punch
            hole .
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``faces``:
            The array of faces to be offset.
            
            Parameter ``distances``:
            The array of offsets for each face.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Returns:
            SUCCESS if hole cutting is successfull.
            """
            ...
        
        @staticmethod
    def SewBodies(sewn: MSPyDgnPlatform.ISolidKernelEntityPtrArray, unsewn: MSPyDgnPlatform.ISolidKernelEntityPtrArray, tools: MSPyDgnPlatform.ISolidKernelEntityPtrArray, gapWidthBound: float, nIterations: int = 1) -> MSPyDgnPlatform.BentleyStatus:
            """
            Sew the given set of sheet bodies together by joining those that share
            edges in common.
            
            Parameter ``sewn``:
            The new bodies produced by sewing.
            
            Parameter ``unsewn``:
            The bodies that were not able to be sewn.
            
            Parameter ``tools``:
            The array of sheet bodies. (invalidated after sew).
            
            Parameter ``nTools``:
            Count of tool bodies.
            
            Parameter ``gapWidthBound``:
            Defines a limit on the width of the gap between sheet body edges
            that will be allowed to remain.
            
            Parameter ``nIterations``:
            To request repeated sew attempts that automatically increase gap
            up to limit set by gapWidthBound.
            
            Returns:
            SUCCESS if some bodies were able to be sewn together.
            """
            ...
        
        @staticmethod
    def SpinBody(target: MSPyDgnPlatform.ISolidKernelEntity, axis: MSPyBentleyGeom.DRay3d, angle: float) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by spinning along an arc specified by a revolve
            axis and sweep angle.
            
            Parameter ``target``:
            The target body to spin. A wire body becomes a sheet, and a sheet
            body becomes a solid.
            
            Parameter ``axis``:
            The revolve axis.
            
            Parameter ``angle``:
            The sweep angle. (value in range of -2pi to 2pi)
            
            Returns:
            SUCCESS if spin could be completed.
            """
            ...
        
        @staticmethod
    def SpinFaces(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray, axis: MSPyBentleyGeom.DRay3d, angle: float) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target solid or sheet body by spinning selected faces along
            an arc specified by a revolve axis and sweep angle.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``faces``:
            The array of faces to be spun.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Parameter ``axis``:
            The revolve axis.
            
            Parameter ``angle``:
            The sweep angle. (value in range of -2pi to 2pi)
            
            Returns:
            SUCCESS if faces could be spun.
            """
            ...
        
        class StepFacesOption:
            """
            Members:
            
            eADD_STEP_No
            
            eADD_STEP_Smooth
            
            eADD_STEP_NonCoincident
            
            eADD_STEP_All
            """
        
            def __init__(self: MSPyMstnPlatform.SolidUtil.Modify.StepFacesOption, value: int) -> None:
                ...
            
            eADD_STEP_All: StepFacesOption
            
            eADD_STEP_No: StepFacesOption
            
            eADD_STEP_NonCoincident: StepFacesOption
            
            eADD_STEP_Smooth: StepFacesOption
            
            @property
            def name(self: handle) -> str:
                ...
            
            @property
            def value(arg0: MSPyMstnPlatform.SolidUtil.Modify.StepFacesOption) -> int:
                ...
            
        @staticmethod
    def SweepBody(target: MSPyDgnPlatform.ISolidKernelEntity, path: MSPyBentleyGeom.DVec3d) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target body by sweeping along a path vector.
            
            Parameter ``target``:
            The target body to sweep. A wire body becomes a sheet, and a sheet
            body becomes a solid.
            
            Parameter ``path``:
            A scaled vector to define the sweep direction and distance.
            
            Returns:
            SUCCESS if sweep could be completed.
            """
            ...
        
        @staticmethod
    def SweepFaces(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray, path: MSPyBentleyGeom.DVec3d) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target solid or sheet body by sweeping selected faces along
            a path vector.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``faces``:
            The array of faces to be swept.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Parameter ``path``:
            A scaled vector to define the sweep direction and distance.
            
            Returns:
            SUCCESS if faces could be swept.
            """
            ...
        
        @staticmethod
    def ThickenSheet(target: MSPyDgnPlatform.ISolidKernelEntity, frontDistance: float, backDistance: float) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the target sheet body by thickening to create a solid body.
            
            Parameter ``target``:
            The target sheet body to thicken.
            
            Parameter ``frontDistance``:
            The offset distance in the direction of the sheet body face
            normal.
            
            Parameter ``backDistance``:
            The offset distance in the opposite direction of the sheet body
            face normal.
            
            Returns:
            SUCCESS if thicken could be completed.
            """
            ...
        
        @staticmethod
    def ThickenSheetWithStatus(target: MSPyDgnPlatform.ISolidKernelEntity, frontDistance: float, backDistance: float, status: int) -> tuple:
            ...
        
        @staticmethod
    def TransformBody(entity: MSPyDgnPlatform.ISolidKernelEntity, transform: MSPyBentleyGeom.Transform) -> MSPyDgnPlatform.BentleyStatus:
            """
            Modify the entity transform for the given body by pre-multiplying the
            current entity transform with the input transform.
            
            Parameter ``entity``:
            The body whose body to uor transform is to be updated.
            
            Parameter ``transform``:
            The transform to apply to the body. @note This method does not
            change the BRep data in any way, it only changes it's body to uor
            transform. This is a helper method added for discoverabiliy that
            is the same as calling
            ISolidKernelEntity.PreMultiplyEntityTransformInPlace.
            
            Returns:
            SUCCESS if transform was updated.
            """
            ...
        
        @staticmethod
    def TransformFaces(*args, **kwargs):
            """
            TransformFaces(target: MSPyDgnPlatform.ISolidKernelEntity, faces: MSPyDgnPlatform.ISubEntityPtrArray, translations: MSPyBentleyGeom.TransformArray, addStep: MSPyMstnPlatform.SolidUtil.Modify.StepFacesOption = <StepFacesOption.eADD_STEP_NonCoincident: 2>) -> MSPyDgnPlatform.BentleyStatus
            
            Modify the target solid or sheet body by transforming selected faces.
            
            Parameter ``target``:
            The target body to modify.
            
            Parameter ``faces``:
            The array of faces to be transformed.
            
            Parameter ``translations``:
            The array of transforms for each face.
            
            Parameter ``nFaces``:
            Count of face sub-entities.
            
            Parameter ``addStep``:
            The option for how to handle the creation of step faces.
            
            Returns:
            SUCCESS if faces could be transformed.
            """
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
        eADD_STEP_All: StepFacesOption
        
        eADD_STEP_No: StepFacesOption
        
        eADD_STEP_NonCoincident: StepFacesOption
        
        eADD_STEP_Smooth: StepFacesOption
        
        eAll: CutDepthMode
        
        eAngleDistance: ChamferMode
        
        eBackward: CutDirectionMode
        
        eBlind: CutDepthMode
        
        eBoth: CutDirectionMode
        
        eDistanceAngle: ChamferMode
        
        eDistances: ChamferMode
        
        eForward: CutDirectionMode
        
        eLength: ChamferMode
        
        eRanges: ChamferMode
        
    @staticmethod
    def RayTestFace(subEntity: MSPyDgnPlatform.ISubEntity, boresite: MSPyBentleyGeom.DRay3d, intersectPts: MSPyBentleyGeom.DPoint3dArray, intersectParams: MSPyBentleyGeom.DPoint2dArray) -> bool:
        """
        Get the ray intersection with a face.
        
        Parameter ``subEntity``:
        The face to intersect.
        
        Parameter ``boresite``:
        The ray origin and direction.
        
        Parameter ``intersectPts``:
        The hit points on the face.
        
        Parameter ``intersectParams``:
        The uv parameters on the face.
        
        Returns:
        true if ray intersects face.
        """
        ...
    
    class TopologyID:
        """
        None
        """
    
        @staticmethod
    def AddNodeIdAttributes(entity: MSPyDgnPlatform.ISolidKernelEntity, nodeId: int, overrideExisting: bool) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        @staticmethod
    def DeleteNodeIdAttributes(entity: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        @staticmethod
    def EdgesFromId(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, edgeId: MSPyBentleyGeom.EdgeId, entity: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        @staticmethod
    def FacesFromId(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, faceId: MSPyBentleyGeom.FaceId, entity: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        @staticmethod
    def FindNodeIdRange(entity: MSPyDgnPlatform.ISolidKernelEntity) -> tuple:
            """
            Find the highest and lowest nodeId values from the topology ids
            currently assigned to the faces of the given body. Used to avoid
            nodeId conflicts between target and tool bodies.
            
            Parameter ``entity``:
            The solid or sheet body to inspect.
            
            Parameter ``highestNodeId``:
            The highest nodeId currently assigned.
            
            Parameter ``lowestNodeId``:
            The lowest nodeId currently assigned.
            
            Returns:
            SUCCESS if face ids are assigned to the body.
            """
            ...
        
        @staticmethod
    def IdFromEdge(subEntity: MSPyDgnPlatform.ISubEntity, useHighestId: bool) -> tuple:
            """
            Get the EdgeId currently assigned to a given edge sub-entity.
            
            Parameter ``edgeId``:
            The requested nodeId-entityId pairs.
            
            Parameter ``subEntity``:
            The edge sub-entity to query.
            
            Parameter ``useHighestId``:
            true to return the highest nodeId-entityId pairs for this face,
            false to return the lowest. Typically true.
            
            Returns:
            SUCCESS if an EdgeId was assigned.
            """
            ...
        
        @staticmethod
    def IdFromFace(subEntity: MSPyDgnPlatform.ISubEntity, useHighestId: bool) -> tuple:
            """
            Get the FaceId currently assigned to a given face sub-entity.
            
            Parameter ``faceId``:
            The requested nodeId-entityId pair.
            
            Parameter ``subEntity``:
            The face sub-entity to query.
            
            Parameter ``useHighestId``:
            true to return the highest nodeId-entityId pair for this face,
            false to return the lowest. Typically true.
            
            Returns:
            SUCCESS if a FaceId was assigned.
            """
            ...
        
        @staticmethod
    def IdFromVertex(subEntity: MSPyDgnPlatform.ISubEntity, useHighestId: bool) -> tuple:
            """
            Get the VertexId currently assigned to a given vertex sub-entity.
            
            Parameter ``vertexId``:
            The requested nodeId-entityId triple.
            
            Parameter ``subEntity``:
            The vertex sub-entity to query.
            
            Parameter ``useHighestId``:
            true to return the highest nodeId-entityId triple for this face,
            false to return the lowest. Typically true.
            
            Returns:
            SUCCESS if a VertexId was assigned.
            """
            ...
        
        @staticmethod
    def IncrementNodeIdAttributes(entity: MSPyDgnPlatform.ISolidKernelEntity, increment: int) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        @staticmethod
    def VerticesFromId(subEntities: MSPyDgnPlatform.ISubEntityPtrArray, vertexId: MSPyBentleyGeom.VertexId, entity: MSPyDgnPlatform.ISolidKernelEntity) -> MSPyDgnPlatform.BentleyStatus:
            ...
        
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SolverGeometry:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class StringUtility:
    """
    None
    """

    @staticmethod
    def FromDirection(angle_str: MSPyBentley.WString, abs_angle: float, format: MSPyDgnPlatform.AngleFormatVals, igdsChars: bool, addTrueNorth: bool, angleMode: int, precision: int, leadingZero: bool, trailingZeros: bool, modelRef: MSPyDgnPlatform.DgnModelRef) -> None:
        ...
    
    @staticmethod
    def FromUors(uor_string: MSPyBentley.WString, uors: float) -> None:
        ...
    
    @staticmethod
    def ToDirection(arg0: MSPyBentley.WString) -> float:
        ...
    
    @staticmethod
    def ToUors(arg0: MSPyBentley.WString) -> float:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SurfaceOrientation:
    """
    Members:
    
    eNotSpecified
    
    eAligned
    
    eAntiAligned
    """

    def __init__(self: MSPyMstnPlatform.SurfaceOrientation, value: int) -> None:
        ...
    
    eAligned: SurfaceOrientation
    
    eAntiAligned: SurfaceOrientation
    
    eNotSpecified: SurfaceOrientation
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.SurfaceOrientation) -> int:
        ...
    
class UIItemStateType:
    """
    Members:
    
    eNone_
    
    eVisible
    
    eEnabled
    
    eChecked
    """

    def __init__(self: MSPyMstnPlatform.UIItemStateType, value: int) -> None:
        ...
    
    eChecked: UIItemStateType
    
    eEnabled: UIItemStateType
    
    eNone_: UIItemStateType
    
    eVisible: UIItemStateType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.UIItemStateType) -> int:
        ...
    
class VertexType:
    """
    Members:
    
    eEdge
    
    eStart
    
    eEnd
    
    eCenter
    
    eParameter
    
    ePointIndex
    
    eEllipseMajor1
    
    eEllipseMajor2
    
    eEllipseMinor1
    
    eEllipseMinor2
    
    eArcPoint
    
    eEllipseMajorEdge
    
    eEllipseMinorEdge
    
    ePlanarFace
    """

    def __init__(self: MSPyMstnPlatform.VertexType, value: int) -> None:
        ...
    
    eArcPoint: VertexType
    
    eCenter: VertexType
    
    eEdge: VertexType
    
    eEllipseMajor1: VertexType
    
    eEllipseMajor2: VertexType
    
    eEllipseMajorEdge: VertexType
    
    eEllipseMinor1: VertexType
    
    eEllipseMinor2: VertexType
    
    eEllipseMinorEdge: VertexType
    
    eEnd: VertexType
    
    eParameter: VertexType
    
    ePlanarFace: VertexType
    
    ePointIndex: VertexType
    
    eStart: VertexType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyMstnPlatform.VertexType) -> int:
        ...
    
eACTIONBUTTON_APPLY: ActionButtonValue

eACTIONBUTTON_CANCEL: ActionButtonValue

eACTIONBUTTON_DEFAULT: ActionButtonValue

eACTIONBUTTON_HELP: ActionButtonValue

eACTIONBUTTON_NO: ActionButtonValue

eACTIONBUTTON_NOTOALL: ActionButtonValue

eACTIONBUTTON_OK: ActionButtonValue

eACTIONBUTTON_OPEN: ActionButtonValue

eACTIONBUTTON_RESET: ActionButtonValue

eACTIONBUTTON_RETRY: ActionButtonValue

eACTIONBUTTON_STOP: ActionButtonValue

eACTIONBUTTON_YES: ActionButtonValue

eACTIONBUTTON_YESTOALL: ActionButtonValue

eAligned: SurfaceOrientation

eAngle: Constraint2dType

eAntiAligned: SurfaceOrientation

eAntiParallel_AntiClockwise: SectorAngleType

eAntiParallel_Clockwise: SectorAngleType

eArcPoint: VertexType

eArc_length: Constraint2dType

eArea: Constraint2dType

eArrayAlongPath: SmartFeatureHandlerId

eAssociativeElement: SmartFeatureHandlerId

eAssociativeElementSymbology: SmartFeatureHandlerId

eBetween_Fixed: Constraint2dStatus

eBetween_Set_Members: Constraint2dStatus

eBlend: SmartFeatureHandlerId

eBoolean: SmartFeatureHandlerId

eCENTERONSCREEN: FileOpenExtAttr

eCHOOSEMASTERFILE_STATUS_Canceled: ChooseMasterFileStatus

eCHOOSEMASTERFILE_STATUS_Handled: ChooseMasterFileStatus

eCHOOSEMASTERFILE_STATUS_Invalid: ChooseMasterFileStatus

eCLASHCOLLECT_Error: ClashCollectStatus

eCLASHCOLLECT_NoGeometry: ClashCollectStatus

eCLASHCOLLECT_Success: ClashCollectStatus

eCLASHSTATUS_Clearance: ClashStatus

eCLASHSTATUS_Collision: ClashStatus

eCLASHSTATUS_Error: ClashStatus

eCLASHSTATUS_NotInRange: ClashStatus

eCREATE: FileListAttr

eCREATEFROMSEED: FileListAttr

eCenter: VertexType

eChamfer: SmartFeatureHandlerId

eChecked: UIItemStateType

eCoincident: Constraint2dType

eConcentric: Constraint2dType

eCopyFeature: SmartFeatureHandlerId

eCurve_Length: Constraint2dType

eCut: SmartFeatureHandlerId

eDCM3_ANGLE: Constraint3dType

eDCM3_COINCIDENT: Constraint3dType

eDCM3_COINCIDENT_AROUND_SPINE: Constraint3dType

eDCM3_COINCIDENT_WITH_SPINE: Constraint3dType

eDCM3_CONCENTRIC: Constraint3dType

eDCM3_CURVE_LENGTH: Constraint3dType

eDCM3_DEPENDENCE: Constraint3dType

eDCM3_DISTANCE: Constraint3dType

eDCM3_EQUAL_CURVATURE: Constraint3dType

eDCM3_EQUAL_CURVATURE_VECTOR: Constraint3dType

eDCM3_EQUAL_DIRECTION: Constraint3dType

eDCM3_EQUAL_FIRST_DERIVATIVE: Constraint3dType

eDCM3_EQUAL_HALF_ANGLE: Constraint3dType

eDCM3_EQUAL_PARAMETER: Constraint3dType

eDCM3_EQUAL_RADIUS: Constraint3dType

eDCM3_EQUAL_SECOND_DERIVATIVE: Constraint3dType

eDCM3_HALF_ANGLE: Constraint3dType

eDCM3_MAJOR_RADIUS: Constraint3dType

eDCM3_MIDPOINT: Constraint3dType

eDCM3_MINOR_RADIUS: Constraint3dType

eDCM3_PARALLEL: Constraint3dType

eDCM3_PERPENDICULAR: Constraint3dType

eDCM3_RADIUS: Constraint3dType

eDCM3_SYMMETRIC: Constraint3dType

eDCM3_TANGENT: Constraint3dType

eDEFAULT: FileListAttr

eDIALOGID_AboutConfiguration: DialogIds

eDIALOGID_AboutDigitalRights: DialogIds

eDIALOGID_AboutUstn: DialogIds

eDIALOGID_AboutUstnLicenseMore: DialogIds

eDIALOGID_AboutUstnMore: DialogIds

eDIALOGID_AboutWorkmode: DialogIds

eDIALOGID_AcademicAdvisory: DialogIds

eDIALOGID_AcceleratorPrefs: DialogIds

eDIALOGID_AccuSnap: DialogIds

eDIALOGID_ActiveAngle: DialogIds

eDIALOGID_ActiveScale: DialogIds

eDIALOGID_AdvancedColors: DialogIds

eDIALOGID_AdvisoryDisplay: DialogIds

eDIALOGID_AuxCoordSystems: DialogIds

eDIALOGID_BasicLocks: DialogIds

eDIALOGID_BothValidAndDifferent: DialogIds

eDIALOGID_BusyBar: DialogIds

eDIALOGID_ButtonAssignment: DialogIds

eDIALOGID_ButtonMap: DialogIds

eDIALOGID_CachedVisibleEdgeSettings: DialogIds

eDIALOGID_Camera: DialogIds

eDIALOGID_CellCreate: DialogIds

eDIALOGID_CellEdit: DialogIds

eDIALOGID_CellMaintenance: DialogIds

eDIALOGID_CellSelect: DialogIds

eDIALOGID_CellSelectorFileCreate: DialogIds

eDIALOGID_CellSelectorFileOpen: DialogIds

eDIALOGID_CfgVars: DialogIds

eDIALOGID_CloseToolBoxes: DialogIds

eDIALOGID_CmdBrowser: DialogIds

eDIALOGID_CmdBrowserApp: DialogIds

eDIALOGID_ColorBookEditor: DialogIds

eDIALOGID_ColorInterpolate: DialogIds

eDIALOGID_ColorPalInfo: DialogIds

eDIALOGID_ColorPalette: DialogIds

eDIALOGID_ColorSquare: DialogIds

eDIALOGID_CommonItems: DialogIds

eDIALOGID_CompletionBar: DialogIds

eDIALOGID_CoordReadout: DialogIds

eDIALOGID_CreateColorBook: DialogIds

eDIALOGID_CustomScale: DialogIds

eDIALOGID_CustomSheetSize: DialogIds

eDIALOGID_Customize: DialogIds

eDIALOGID_DBSettings: DialogIds

eDIALOGID_DWGAecFileAlert: DialogIds

eDIALOGID_DefineNamedLevels: DialogIds

eDIALOGID_DefineNamedLevelsSort: DialogIds

eDIALOGID_DeletingUsedStyles: DialogIds

eDIALOGID_DesignFileSettings: DialogIds

eDIALOGID_DesignLinksCreate: DialogIds

eDIALOGID_DesignOptions: DialogIds

eDIALOGID_DialogMessages: DialogIds

eDIALOGID_Digitizing: DialogIds

eDIALOGID_Display: DialogIds

eDIALOGID_DockableTemplate: DialogIds

eDIALOGID_DrawComp: DialogIds

eDIALOGID_ElementAttributes: DialogIds

eDIALOGID_ElementPreviewDialog: DialogIds

eDIALOGID_ElementQuickInfo: DialogIds

eDIALOGID_ExtendedFileOpen: DialogIds

eDIALOGID_FenceFrame: DialogIds

eDIALOGID_FileList: DialogIds

eDIALOGID_FileListDDMultiple: DialogIds

eDIALOGID_FileListDDSingle: DialogIds

eDIALOGID_FileListDirMultiple: DialogIds

eDIALOGID_FileListDirSingle: DialogIds

eDIALOGID_FileListMultiple: DialogIds

eDIALOGID_FileProperties: DialogIds

eDIALOGID_FileSaveAsOptions: DialogIds

eDIALOGID_FileWorkSetFound_InvalidActiveWorkSet: DialogIds

eDIALOGID_FileWorkSetNotFound_InvalidActiveWorkSet: DialogIds

eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet: DialogIds

eDIALOGID_FileWorkSetNotFound_ValidActiveWorkSet_ValidConfig: DialogIds

eDIALOGID_Font: DialogIds

eDIALOGID_FramedTemplate: DialogIds

eDIALOGID_FunctionKeys: DialogIds

eDIALOGID_GetSecurityKey: DialogIds

eDIALOGID_GraphicsFileExport: DialogIds

eDIALOGID_GraphicsFileOpen: DialogIds

eDIALOGID_GraphicsFileSaveAs: DialogIds

eDIALOGID_GridSettings: DialogIds

eDIALOGID_GroupEdit: DialogIds

eDIALOGID_HLineSettings: DialogIds

eDIALOGID_Help: DialogIds

eDIALOGID_HelpFind: DialogIds

eDIALOGID_HiddenLineSettings: DialogIds

eDIALOGID_Igen: DialogIds

eDIALOGID_Image: DialogIds

eDIALOGID_ImageSave: DialogIds

eDIALOGID_InputManager: DialogIds

eDIALOGID_KeyboardShortcuts: DialogIds

eDIALOGID_KeyinSettings: DialogIds

eDIALOGID_LargeAlert: DialogIds

eDIALOGID_LargeInfoBox: DialogIds

eDIALOGID_LevSymb: DialogIds

eDIALOGID_LevelEdit: DialogIds

eDIALOGID_LineStyleSelect: DialogIds

eDIALOGID_Locks: DialogIds

eDIALOGID_MDL: DialogIds

eDIALOGID_MDLDetail: DialogIds

eDIALOGID_MainFrame: DialogIds

eDIALOGID_MainWindow: DialogIds

eDIALOGID_MediumAlert: DialogIds

eDIALOGID_MediumInfoBox: DialogIds

eDIALOGID_ModelChoose: DialogIds

eDIALOGID_ModelManager: DialogIds

eDIALOGID_MoreWindows: DialogIds

eDIALOGID_MsgBoxLargeYesNo: DialogIds

eDIALOGID_MsgBoxMediumYesNo: DialogIds

eDIALOGID_MsgBoxMediumYesNoCancel: DialogIds

eDIALOGID_MsgBoxOK: DialogIds

eDIALOGID_MsgBoxOKCancel: DialogIds

eDIALOGID_MsgBoxYesAllNo: DialogIds

eDIALOGID_MsgBoxYesAllNoCancel: DialogIds

eDIALOGID_MsgBoxYesNo: DialogIds

eDIALOGID_MsgBoxYesNoCancel: DialogIds

eDIALOGID_MultiSnap: DialogIds

eDIALOGID_NamedFences: DialogIds

eDIALOGID_NamedLevels: DialogIds

eDIALOGID_NamedLevelsTargetGroup: DialogIds

eDIALOGID_OptionalInfoBox: DialogIds

eDIALOGID_OptionalOKCancelBox: DialogIds

eDIALOGID_OptionalOKCancelBoxWide: DialogIds

eDIALOGID_PaletteItems: DialogIds

eDIALOGID_PatternSettings: DialogIds

eDIALOGID_PointCloudFileBrowse: DialogIds

eDIALOGID_Preprocessor: DialogIds

eDIALOGID_PreviewPrint: DialogIds

eDIALOGID_PropertyBinding: DialogIds

eDIALOGID_RasterFileBrowse: DialogIds

eDIALOGID_RefColorAdjust: DialogIds

eDIALOGID_RefPresentation: DialogIds

eDIALOGID_ReferenceAttach: DialogIds

eDIALOGID_ReferenceDragDrop: DialogIds

eDIALOGID_ReferenceFile: DialogIds

eDIALOGID_ReferenceFileBrowse: DialogIds

eDIALOGID_ReferenceFileOpen: DialogIds

eDIALOGID_ReferenceFullSettings: DialogIds

eDIALOGID_ReferenceRotate: DialogIds

eDIALOGID_ReferenceScale: DialogIds

eDIALOGID_ResetMenuOptions: DialogIds

eDIALOGID_SavedViewDragDrop: DialogIds

eDIALOGID_SelectImagePreview: DialogIds

eDIALOGID_SetHiliteColor: DialogIds

eDIALOGID_SetVectorCursorColor: DialogIds

eDIALOGID_ShowClipboard: DialogIds

eDIALOGID_SnapButtonResizable: DialogIds

eDIALOGID_Snaps: DialogIds

eDIALOGID_StandardAlert: DialogIds

eDIALOGID_StandardInfoBox: DialogIds

eDIALOGID_StdFileOpen: DialogIds

eDIALOGID_StdFileSeedCreate: DialogIds

eDIALOGID_SubEditor: DialogIds

eDIALOGID_TaskNavigation: DialogIds

eDIALOGID_TextFileDisplay: DialogIds

eDIALOGID_TextStyleEditor: DialogIds

eDIALOGID_ToolBoxDummy: DialogIds

eDIALOGID_ToolBoxTemplate: DialogIds

eDIALOGID_ToolSettings: DialogIds

eDIALOGID_TrackBar: DialogIds

eDIALOGID_Transparency: DialogIds

eDIALOGID_TransparencyPriority: DialogIds

eDIALOGID_UnassociatedFile_Product_Mismatch: DialogIds

eDIALOGID_UnassociatedFile_ValidActiveWorkSet: DialogIds

eDIALOGID_UnsignedAppWarning: DialogIds

eDIALOGID_UpdateSequence: DialogIds

eDIALOGID_UserPreference: DialogIds

eDIALOGID_UstnMgr: DialogIds

eDIALOGID_V7CellLibConvert: DialogIds

eDIALOGID_V7DesignFileAlert: DialogIds

eDIALOGID_VariableDialog: DialogIds

eDIALOGID_View: DialogIds

eDIALOGID_ViewAreaBackground: DialogIds

eDIALOGID_ViewBrightness: DialogIds

eDIALOGID_ViewLevels: DialogIds

eDIALOGID_ViewRotation: DialogIds

eDIALOGID_ViewSettings: DialogIds

eDIALOGID_ViewToggles: DialogIds

eDIALOGID_WindowManMenu: DialogIds

eDIALOGID_WorkingUnits: DialogIds

eDIALOGID_YesAllNoAllCancelAlert: DialogIds

eDIALOGID_YesAllNoCancelAlert: DialogIds

eDIALOGID_YesNoCancelAlert: DialogIds

eDONTDEFAULTTODEFFILE: FileOpenExtAttr

eData: Constraint3dXAttributeIndex

eDeleteFace: SmartFeatureHandlerId

eDeleteLump: SmartFeatureHandlerId

eDependence: Constraint2dType

eDimAlign_Drawing_X: DimensionAlignmentType

eDimAlign_Drawing_X_Reversed: DimensionAlignmentType

eDimAlign_Drawing_Y: DimensionAlignmentType

eDimAlign_Drawing_Y_Reversed: DimensionAlignmentType

eDimAlign_Unknown: DimensionAlignmentType

eDistance: Constraint2dType

eDistanceCC: Constraint2dType

eDistanceCL: Constraint2dType

eDistanceCP: Constraint2dType

eDistanceLL: Constraint2dType

eDistancePL: Constraint2dType

eDistancePP: Constraint2dType

eDummy: Constraint2dType

eEAP1Hole: SmartFeatureHandlerId

eEdge: VertexType

eEllipseMajor1: VertexType

eEllipseMajor2: VertexType

eEllipseMajorEdge: VertexType

eEllipseMinor1: VertexType

eEllipseMinor2: VertexType

eEllipseMinorEdge: VertexType

eEllipsoid: SmartFeatureHandlerId

eEllipticalCone: SmartFeatureHandlerId

eEnabled: UIItemStateType

eEnd: VertexType

eEqual: Constraint2dType

eEqual_Curvature: Constraint2dType

eEqual_Direction: Constraint2dType

eEqual_Distance: Constraint2dType

eEqual_First_Derivative: Constraint2dType

eEqual_Parameter: Constraint2dType

eEqual_Radius: Constraint2dType

eEqual_Relative_Transform: Constraint2dType

eEqual_Second_Derivative: Constraint2dType

eExternalEdgeProfile: SmartFeatureHandlerId

eExternalProfile: SmartFeatureHandlerId

eExternalSolid: SmartFeatureHandlerId

eExtrude: SmartFeatureHandlerId

eExtrudeAlongProfile: SmartFeatureHandlerId

eFenceClip: SmartFeatureHandlerId

eFenceStretch: SmartFeatureHandlerId

eFix: Constraint2dType

eFixed: Constraint3dType

eFronContext: CellAddType

eGRAPHICSFILE_3DStudio: GraphicsFileType

eGRAPHICSFILE_CAD: GraphicsFileType

eGRAPHICSFILE_CEL: GraphicsFileType

eGRAPHICSFILE_CGM: GraphicsFileType

eGRAPHICSFILE_DWG: GraphicsFileType

eGRAPHICSFILE_DXB: GraphicsFileType

eGRAPHICSFILE_DXF: GraphicsFileType

eGRAPHICSFILE_DgnLib: GraphicsFileType

eGRAPHICSFILE_HLine: GraphicsFileType

eGRAPHICSFILE_IGES: GraphicsFileType

eGRAPHICSFILE_OBJ: GraphicsFileType

eGRAPHICSFILE_RDL: GraphicsFileType

eGRAPHICSFILE_SKP: GraphicsFileType

eGRAPHICSFILE_Sheet: GraphicsFileType

eGRAPHICSFILE_TriForma: GraphicsFileType

eGRAPHICSFILE_UStn: GraphicsFileType

eGRAPHICSFILE_UStnV7: GraphicsFileType

eGRAPHICSFILE_WildCard: GraphicsFileType

eGeneral: DragTransformType

eHole: SmartFeatureHandlerId

eHollow: SmartFeatureHandlerId

eHorizontal: Constraint2dType

eIdentical: Constraint2dType

eImprintElement: SmartFeatureHandlerId

eImprintOffset: SmartFeatureHandlerId

eInitial: Constraint3dStorageVersion

eLEVEL_CHANGE_ACTIVE: LevelChangeType

eLEVEL_CHANGE_ATTRIBUTE: LevelChangeType

eLEVEL_CHANGE_CODE: LevelChangeType

eLEVEL_CHANGE_DISPLAY: LevelChangeType

eLEVEL_CHANGE_ELEMENT_COUNT: LevelChangeType

eLEVEL_CHANGE_NAME: LevelChangeType

eLEVEL_CHANGE_PARENT: LevelChangeType

eLEVEL_CHANGE_USAGE: LevelChangeType

eLEVEL_COUNT_TYPE_ALL: LevelCountType

eLEVEL_COUNT_TYPE_HIDDEN: LevelCountType

eLEVEL_COUNT_TYPE_UNUSED: LevelCountType

eLEVEL_COUNT_TYPE_USED: LevelCountType

eLEVEL_CREATE: LevelChangeType

eLEVEL_DELETE: LevelChangeType

eLEVEL_FROZEN_TYPE_EFFECTIVE: LevelFrozenType

eLEVEL_FROZEN_TYPE_GLOBAL: LevelFrozenType

eLEVEL_FROZEN_TYPE_VP_FREEZE: LevelFrozenType

eLEVEL_ITERATE_TYPE_ALL_LEVELS: LevelIterateType

eLEVEL_ITERATE_TYPE_UNUSED_LEVELS: LevelIterateType

eLEVEL_ITERATE_TYPE_USED_LEVELS: LevelIterateType

eLEVEL_LIBRARY_ATTACH: LevelChangeType

eLEVEL_LIBRARY_COUNT_TYPE_ALL: LevelLibraryCountType

eLEVEL_LIBRARY_COUNT_TYPE_AUTO_ATTACHED: LevelLibraryCountType

eLEVEL_LIBRARY_COUNT_TYPE_MANUAL_ATTACHED: LevelLibraryCountType

eLEVEL_LIBRARY_DETACH: LevelChangeType

eLEVEL_LIBRARY_FORMAT_ANY: LevelLibraryFormat

eLEVEL_LIBRARY_FORMAT_CSV: LevelLibraryFormat

eLEVEL_LIBRARY_FORMAT_DGN: LevelLibraryFormat

eLEVEL_LIBRARY_FORMAT_DWG: LevelLibraryFormat

eLEVEL_LIBRARY_FORMAT_V7_LVL: LevelLibraryFormat

eLEVEL_LIBRARY_FORMAT_XML: LevelLibraryFormat

eLEVEL_LIBRARY_IMPORT_BY_ANY: LevelLibraryImportMethod

eLEVEL_LIBRARY_IMPORT_BY_CODE: LevelLibraryImportMethod

eLEVEL_LIBRARY_IMPORT_BY_NAME: LevelLibraryImportMethod

eLEVEL_PRE_CHANGE_ACTIVE: LevelChangeType

eLEVEL_PRE_DELETE: LevelChangeType

eLEVEL_REWRITE: LevelChangeType

eLEVEL_TABLE_IMPORT: LevelChangeType

eLEVEL_TABLE_REDO: LevelChangeType

eLEVEL_TABLE_REWRITE: LevelChangeType

eLEVEL_TABLE_UNDO: LevelChangeType

eLatest: Constraint3dStorageVersion

eLeft: DimensionHalfSpace

eLoftSurface: SmartFeatureHandlerId

eMARK_NONE: MenuMarkType

eMARK_RADIO_IN: MenuMarkType

eMARK_RADIO_OUT: MenuMarkType

eMARK_RIGHT_ARROW: MenuMarkType

eMARK_TOGGLE_IN: MenuMarkType

eMARK_TOGGLE_OUT: MenuMarkType

eMDLERR_2D3D_MISMATCH: MdlErrorValues

eMDLERR_3DREF2DMASTER: MdlErrorValues

eMDLERR_ACCESSVIOLATION: MdlErrorValues

eMDLERR_ACCUDRAWNOTENABLED: MdlErrorValues

eMDLERR_ACSNOTFOUND: MdlErrorValues

eMDLERR_ACSREPLACED: MdlErrorValues

eMDLERR_ADDINGCOMPLEXELEMENT: MdlErrorValues

eMDLERR_ADDRNOTKNOWN: MdlErrorValues

eMDLERR_ADDRNOTVALID: MdlErrorValues

eMDLERR_ALLMODELSFILTEREDOUT: MdlErrorValues

eMDLERR_ALREADYEXISTS: MdlErrorValues

eMDLERR_ALREADYINUSE: MdlErrorValues

eMDLERR_ALREADYLOADED: MdlErrorValues

eMDLERR_ALREADYOPEN: MdlErrorValues

eMDLERR_AMBIGUOUS: MdlErrorValues

eMDLERR_ANONYMOUS_SHAREDCELL: MdlErrorValues

eMDLERR_ARRAYWRONGSIZE: MdlErrorValues

eMDLERR_ATTRBADASSOC: MdlErrorValues

eMDLERR_ATTRBADRPTFILE: MdlErrorValues

eMDLERR_ATTRBADRPTKEYWORD: MdlErrorValues

eMDLERR_ATTRNOTARGET: MdlErrorValues

eMDLERR_ATTRNOTFOUND: MdlErrorValues

eMDLERR_ATTRNOTINSET: MdlErrorValues

eMDLERR_ATTRPREVDEFINED: MdlErrorValues

eMDLERR_ATTRSETNAMELONG: MdlErrorValues

eMDLERR_ATTRSETNOTFOUND: MdlErrorValues

eMDLERR_ATTRSETPREVDEFINED: MdlErrorValues

eMDLERR_ATTRSETTOOBIG: MdlErrorValues

eMDLERR_ATTRUNDEFTYPE: MdlErrorValues

eMDLERR_BADARG: MdlErrorValues

eMDLERR_BADBSPELM: MdlErrorValues

eMDLERR_BADCHARCONS: MdlErrorValues

eMDLERR_BADCOLORDESCR: MdlErrorValues

eMDLERR_BADCOLORPALETTE: MdlErrorValues

eMDLERR_BADCOLORPALETTEDATA: MdlErrorValues

eMDLERR_BADCOLORPALETTEINDEX: MdlErrorValues

eMDLERR_BADCOLORTABLE: MdlErrorValues

eMDLERR_BADCONTINUITY: MdlErrorValues

eMDLERR_BADCOPYPARALLEL: MdlErrorValues

eMDLERR_BADDATADEF: MdlErrorValues

eMDLERR_BADELEMENT: MdlErrorValues

eMDLERR_BADELEMENTTYPE: MdlErrorValues

eMDLERR_BADFILE: MdlErrorValues

eMDLERR_BADFILENUMBER: MdlErrorValues

eMDLERR_BADFILETYPE: MdlErrorValues

eMDLERR_BADFLOAT: MdlErrorValues

eMDLERR_BADFONT: MdlErrorValues

eMDLERR_BADFORMAT: MdlErrorValues

eMDLERR_BADHEX: MdlErrorValues

eMDLERR_BADINDEX: MdlErrorValues

eMDLERR_BADKNOTS: MdlErrorValues

eMDLERR_BADLINKERINFO: MdlErrorValues

eMDLERR_BADMODELID: MdlErrorValues

eMDLERR_BADMODELREF: MdlErrorValues

eMDLERR_BADNAME: MdlErrorValues

eMDLERR_BADOCTAL: MdlErrorValues

eMDLERR_BADORDER: MdlErrorValues

eMDLERR_BADPARAMETER: MdlErrorValues

eMDLERR_BADPERIODICITY: MdlErrorValues

eMDLERR_BADPOLES: MdlErrorValues

eMDLERR_BADRASTER: MdlErrorValues

eMDLERR_BADRASTERFORMAT: MdlErrorValues

eMDLERR_BADRSCTYPE: MdlErrorValues

eMDLERR_BADSCANLIST: MdlErrorValues

eMDLERR_BADSCREENNUMBER: MdlErrorValues

eMDLERR_BADSETMETHODID: MdlErrorValues

eMDLERR_BADSLOT: MdlErrorValues

eMDLERR_BADSPIRALDEFINITION: MdlErrorValues

eMDLERR_BADSTRING: MdlErrorValues

eMDLERR_BADTEXTSTYLE: MdlErrorValues

eMDLERR_BADTYPE: MdlErrorValues

eMDLERR_BADVERSION: MdlErrorValues

eMDLERR_BADVIEWNUMBER: MdlErrorValues

eMDLERR_BADVRBLARRAYSIZE: MdlErrorValues

eMDLERR_BADWEIGHTS: MdlErrorValues

eMDLERR_BADWORDSTOFOLLOW: MdlErrorValues

eMDLERR_BUFFERALIGNMENTSDIFFER: MdlErrorValues

eMDLERR_CACHEINUSE: MdlErrorValues

eMDLERR_CACHELOADERROR: MdlErrorValues

eMDLERR_CACHENOTENABLED: MdlErrorValues

eMDLERR_CACHENOTFILLED: MdlErrorValues

eMDLERR_CACHENOTFOUND: MdlErrorValues

eMDLERR_CANNOTDELETEDEFAULTMODEL: MdlErrorValues

eMDLERR_CANNOTDEREF: MdlErrorValues

eMDLERR_CANNOTFINDMACRO: MdlErrorValues

eMDLERR_CANNOTIMPORTSEED: MdlErrorValues

eMDLERR_CANNOTLOADMACROHOST: MdlErrorValues

eMDLERR_CANNOTOPENFILE: MdlErrorValues

eMDLERR_CANNOTOPENSEED: MdlErrorValues

eMDLERR_CANNOTSETVALUE: MdlErrorValues

eMDLERR_CANTCREATEFILE: MdlErrorValues

eMDLERR_CANTSAVEFILE: MdlErrorValues

eMDLERR_CAPABILITYRESTRICTION: MdlErrorValues

eMDLERR_CELLEXISTS: MdlErrorValues

eMDLERR_CELLLIB2DGN3: MdlErrorValues

eMDLERR_CELLNOTFOUND: MdlErrorValues

eMDLERR_CELLTOOLARGE: MdlErrorValues

eMDLERR_CIRCULARDEPENDENCY: MdlErrorValues

eMDLERR_CLOSEDGROUP: MdlErrorValues

eMDLERR_COINCIDENTSELFREF: MdlErrorValues

eMDLERR_COLORMGRNOTINITIALIZED: MdlErrorValues

eMDLERR_COMMANDRECEIVED: MdlErrorValues

eMDLERR_COMPRESSIONERROR: MdlErrorValues

eMDLERR_CONNECTIONERROR: MdlErrorValues

eMDLERR_COPYERROR: MdlErrorValues

eMDLERR_DATADEFNOTFOUND: MdlErrorValues

eMDLERR_DGNFILEOBJINUSE: MdlErrorValues

eMDLERR_DISKFULL: MdlErrorValues

eMDLERR_DIVIDEBYZERO: MdlErrorValues

eMDLERR_DLMNOTALLOWED: MdlErrorValues

eMDLERR_DOCMGR_CREATE_FAILED: MdlErrorValues

eMDLERR_DUPLICATELOGICAL: MdlErrorValues

eMDLERR_DUPLICATEMEMBER: MdlErrorValues

eMDLERR_DUPTASKID: MdlErrorValues

eMDLERR_ELEMENTFROZEN: MdlErrorValues

eMDLERR_ELEMENTISHOLED: MdlErrorValues

eMDLERR_ELEMTOOLARGE: MdlErrorValues

eMDLERR_ELMENTNOTFOUND: MdlErrorValues

eMDLERR_ELMFILLED: MdlErrorValues

eMDLERR_ELMNOTFILLED: MdlErrorValues

eMDLERR_ELMNOTPLANAR: MdlErrorValues

eMDLERR_ELMTOOLARGE: MdlErrorValues

eMDLERR_EMPTYSOURCE: MdlErrorValues

eMDLERR_ENDOFFILE: MdlErrorValues

eMDLERR_EXCEPTION: MdlErrorValues

eMDLERR_FARASSOCREQUIRED: MdlErrorValues

eMDLERR_FARREFERENCE: MdlErrorValues

eMDLERR_FILE2SUB3: MdlErrorValues

eMDLERR_FILEEXISTS: MdlErrorValues

eMDLERR_FILENOTFOUND: MdlErrorValues

eMDLERR_FILEREADONLY: MdlErrorValues

eMDLERR_FIRSTEXPRERROR: MdlErrorValues

eMDLERR_GEOCOORD_NEEDSRECALCULATION: MdlErrorValues

eMDLERR_GEOCOORD_NOGEOCODE: MdlErrorValues

eMDLERR_GEOCOORD_NOMASTERGCS: MdlErrorValues

eMDLERR_GEOCOORD_NOREFGCS: MdlErrorValues

eMDLERR_GEOCOORD_NOTGEOTRANSFORMED: MdlErrorValues

eMDLERR_GEOCOORD_REFTRANSFORMDISABLED: MdlErrorValues

eMDLERR_GEOCOORD_UNITSWRONG: MdlErrorValues

eMDLERR_GROUPOPINPROGRESS: MdlErrorValues

eMDLERR_HASCHANGES: MdlErrorValues

eMDLERR_HISTORYREVISIONNOTFOUND: MdlErrorValues

eMDLERR_IDEXISTS: MdlErrorValues

eMDLERR_IDNOTFOUND: MdlErrorValues

eMDLERR_ILLEGALCHAR: MdlErrorValues

eMDLERR_INPUTBUFFERWRONGALIGNMENT: MdlErrorValues

eMDLERR_INSFINFO: MdlErrorValues

eMDLERR_INSFMEMORY: MdlErrorValues

eMDLERR_INTEGRALNEEDED: MdlErrorValues

eMDLERR_INTERSECTSITSELF: MdlErrorValues

eMDLERR_INVALIDACCESSMODE: MdlErrorValues

eMDLERR_INVALIDACSTYPE: MdlErrorValues

eMDLERR_INVALIDBUTTON: MdlErrorValues

eMDLERR_INVALIDCELL: MdlErrorValues

eMDLERR_INVALIDCLIP: MdlErrorValues

eMDLERR_INVALIDCOLORMODE: MdlErrorValues

eMDLERR_INVALIDDEPENDENCY: MdlErrorValues

eMDLERR_INVALIDFORFLOAT: MdlErrorValues

eMDLERR_INVALIDFORFUNC: MdlErrorValues

eMDLERR_INVALIDFORNEUTRALMDL: MdlErrorValues

eMDLERR_INVALIDFORSTRUCT: MdlErrorValues

eMDLERR_INVALIDFORTYPE: MdlErrorValues

eMDLERR_INVALIDLIBRARY: MdlErrorValues

eMDLERR_INVALIDLOGICALNAME: MdlErrorValues

eMDLERR_INVALIDMASTERORG: MdlErrorValues

eMDLERR_INVALIDOPERATIONFORNESTED: MdlErrorValues

eMDLERR_INVALIDOPERATIONFORNONNESTED: MdlErrorValues

eMDLERR_INVALIDPAGE: MdlErrorValues

eMDLERR_INVALIDPASSWORD: MdlErrorValues

eMDLERR_INVALIDPATSPACE: MdlErrorValues

eMDLERR_INVALIDPLATFORMID: MdlErrorValues

eMDLERR_INVALIDREF: MdlErrorValues

eMDLERR_INVALIDREFORG: MdlErrorValues

eMDLERR_INVALIDSYMBOL: MdlErrorValues

eMDLERR_INVALID_COLOR: MdlErrorValues

eMDLERR_INVALID_FOR_RESTRICTED_PRODUCT: MdlErrorValues

eMDLERR_INVREGEX: MdlErrorValues

eMDLERR_LASTEXPRERROR: MdlErrorValues

eMDLERR_LICHANDLENOTFOUND: MdlErrorValues

eMDLERR_LINKAGENOTFOUND: MdlErrorValues

eMDLERR_LOADINGINTERFACE: MdlErrorValues

eMDLERR_MACRONOTSTARTED: MdlErrorValues

eMDLERR_MACROSTILLRUNNING: MdlErrorValues

eMDLERR_MACROVARNOTDEFINED: MdlErrorValues

eMDLERR_MAXMCSLTASKS: MdlErrorValues

eMDLERR_MISSINGIMAGEBAND: MdlErrorValues

eMDLERR_MODELERNOTLOADED: MdlErrorValues

eMDLERR_MODELIDEXISTS: MdlErrorValues

eMDLERR_MODELNAMEEXISTS: MdlErrorValues

eMDLERR_MODELNOTEMPTY: MdlErrorValues

eMDLERR_MODELNOTFOUND: MdlErrorValues

eMDLERR_MODIFYCOMPLEX: MdlErrorValues

eMDLERR_MSELEMENTDESCRCOLLECTOR_TERMINATE_COLLECTION: MdlErrorValues

eMDLERR_MULTIPLE_TRANSPARENCY: MdlErrorValues

eMDLERR_MUNOTLARGERTHANSU: MdlErrorValues

eMDLERR_NAMENOTUNIQUE: MdlErrorValues

eMDLERR_NAMETOOLONG: MdlErrorValues

eMDLERR_NEEDEXPONENT: MdlErrorValues

eMDLERR_NEEDINT: MdlErrorValues

eMDLERR_NOACSDEFINED: MdlErrorValues

eMDLERR_NOASSOCIATEDTEMPLATE: MdlErrorValues

eMDLERR_NOBOUNDS: MdlErrorValues

eMDLERR_NOBSPHEADER: MdlErrorValues

eMDLERR_NOCELLLIBRARY: MdlErrorValues

eMDLERR_NOCHANGE: MdlErrorValues

eMDLERR_NOCLIPVOLUME: MdlErrorValues

eMDLERR_NOEXTPGMSTACK: MdlErrorValues

eMDLERR_NOFENCE: MdlErrorValues

eMDLERR_NOGRAPHICGROUP: MdlErrorValues

eMDLERR_NOINTERNALMATERIALS: MdlErrorValues

eMDLERR_NOKEYS: MdlErrorValues

eMDLERR_NOKNOTS: MdlErrorValues

eMDLERR_NOLEVELMASK: MdlErrorValues

eMDLERR_NOLICENSEAVAILABLE: MdlErrorValues

eMDLERR_NOMASTERFILE: MdlErrorValues

eMDLERR_NOMATCH: MdlErrorValues

eMDLERR_NOMDLPLOTDRIVERINPLT: MdlErrorValues

eMDLERR_NOMESSAGE: MdlErrorValues

eMDLERR_NOMODEL: MdlErrorValues

eMDLERR_NOMODELINFO: MdlErrorValues

eMDLERR_NONCLOSEDELM: MdlErrorValues

eMDLERR_NONCLOSEDPATELM: MdlErrorValues

eMDLERR_NONCOPLANARSHAPES: MdlErrorValues

eMDLERR_NONPLANARELEMENT: MdlErrorValues

eMDLERR_NONSOLIDPATELM: MdlErrorValues

eMDLERR_NONUMBOUNDS: MdlErrorValues

eMDLERR_NOOFFSETINTERSECTION: MdlErrorValues

eMDLERR_NOPARENTMODEL: MdlErrorValues

eMDLERR_NOPOLES: MdlErrorValues

eMDLERR_NOQUEUEENTRIES: MdlErrorValues

eMDLERR_NOREFSLOTS: MdlErrorValues

eMDLERR_NOSELECTIONSET: MdlErrorValues

eMDLERR_NOSUCHAPPLICATION: MdlErrorValues

eMDLERR_NOSUCHMODEL: MdlErrorValues

eMDLERR_NOSYMBOL: MdlErrorValues

eMDLERR_NOTATOMICDATATYPE: MdlErrorValues

eMDLERR_NOTAVAILABLE: MdlErrorValues

eMDLERR_NOTAVALIDSHAPEFILE: MdlErrorValues

eMDLERR_NOTCMPLXHDR: MdlErrorValues

eMDLERR_NOTCOMPLEXHEADER: MdlErrorValues

eMDLERR_NOTCONVRULES: MdlErrorValues

eMDLERR_NOTDESIGNFILE: MdlErrorValues

eMDLERR_NOTDIRECTATTACHMENT: MdlErrorValues

eMDLERR_NOTFUNCTION: MdlErrorValues

eMDLERR_NOTLOADED: MdlErrorValues

eMDLERR_NOTLOCKED: MdlErrorValues

eMDLERR_NOTMEMBER: MdlErrorValues

eMDLERR_NOTOPEN: MdlErrorValues

eMDLERR_NOTRANSFORM: MdlErrorValues

eMDLERR_NOTSAMEUNITBASE: MdlErrorValues

eMDLERR_NOTSINGLEVIEW: MdlErrorValues

eMDLERR_NOTSTRUCT: MdlErrorValues

eMDLERR_NOTSUPPORTED: MdlErrorValues

eMDLERR_NOTSUPPORTEDACTIVATEDREF: MdlErrorValues

eMDLERR_NOTVALIDEXPRESS: MdlErrorValues

eMDLERR_NOWEIGHTS: MdlErrorValues

eMDLERR_NO_GEOCODINGELM: MdlErrorValues

eMDLERR_NO_TRANSPARENCY: MdlErrorValues

eMDLERR_NULLOUTPUTBUFFER: MdlErrorValues

eMDLERR_NULLSOLUTION: MdlErrorValues

eMDLERR_OLDMATERIALTABLE: MdlErrorValues

eMDLERR_OPERATIONCANCELED: MdlErrorValues

eMDLERR_OPERVIOLATESCONSTRAINTS: MdlErrorValues

eMDLERR_OUTPUTBUFFERWRONGALIGNMENT: MdlErrorValues

eMDLERR_OVERSIZE_ELEMENT: MdlErrorValues

eMDLERR_PALETTEWRONGSIZE: MdlErrorValues

eMDLERR_PARASOLID_ERROR: MdlErrorValues

eMDLERR_PROGRAMTERMINATED: MdlErrorValues

eMDLERR_QUEUEERROR: MdlErrorValues

eMDLERR_QUEUEFULL: MdlErrorValues

eMDLERR_READFAILED: MdlErrorValues

eMDLERR_RECURSELIMIT: MdlErrorValues

eMDLERR_REDUNDANTREF: MdlErrorValues

eMDLERR_REJECTED: MdlErrorValues

eMDLERR_REJECTEDBYINIT: MdlErrorValues

eMDLERR_RELATIVECELLLEVELNOTFOUND: MdlErrorValues

eMDLERR_RELOADNOTNEEDED: MdlErrorValues

eMDLERR_RENAMEERROR: MdlErrorValues

eMDLERR_REPLACING_DELETED: MdlErrorValues

eMDLERR_RESOURCENOTFOUND: MdlErrorValues

eMDLERR_RIGHT_NOT_GRANTED: MdlErrorValues

eMDLERR_RIGHT_NOT_GRANTED_FOR_OPERATION: MdlErrorValues

eMDLERR_RSCADDRINVALID: MdlErrorValues

eMDLERR_RSCALIASREQUIRED: MdlErrorValues

eMDLERR_RSCALREADYEXISTS: MdlErrorValues

eMDLERR_RSCBADRANGETREE: MdlErrorValues

eMDLERR_RSCBADRSCSIZE: MdlErrorValues

eMDLERR_RSCBADVERSION: MdlErrorValues

eMDLERR_RSCCONDITIONFALSE: MdlErrorValues

eMDLERR_RSCDIRECTADDPEND: MdlErrorValues

eMDLERR_RSCERROR: MdlErrorValues

eMDLERR_RSCFILECORRUPT: MdlErrorValues

eMDLERR_RSCFILEERROR: MdlErrorValues

eMDLERR_RSCFILEHANDLETABLEFULL: MdlErrorValues

eMDLERR_RSCFILENOTFOUND: MdlErrorValues

eMDLERR_RSCFILENOTOPEN: MdlErrorValues

eMDLERR_RSCFOPENFAILURE: MdlErrorValues

eMDLERR_RSCHANDLEINVALID: MdlErrorValues

eMDLERR_RSCINSFMEM: MdlErrorValues

eMDLERR_RSCINUSE: MdlErrorValues

eMDLERR_RSCINVALIDFILEHANDLE: MdlErrorValues

eMDLERR_RSCNOTFOUND: MdlErrorValues

eMDLERR_RSCQRYIDINVALID: MdlErrorValues

eMDLERR_RSCSTRINGNOTFOUND: MdlErrorValues

eMDLERR_RSCTYPEINVALID: MdlErrorValues

eMDLERR_RSCWRITEERROR: MdlErrorValues

eMDLERR_RSCWRITEVIOLATION: MdlErrorValues

eMDLERR_SERVER_MAX_USER_REACHED: MdlErrorValues

eMDLERR_SHAPEALREADYEXISTS: MdlErrorValues

eMDLERR_SHAPEFILEFULL: MdlErrorValues

eMDLERR_SHARINGVIOLATION: MdlErrorValues

eMDLERR_SHMEMNOTFOUND: MdlErrorValues

eMDLERR_SIGNATURE_NOT_FOUND: MdlErrorValues

eMDLERR_SIGNATURE_NOT_RECOGNIZED: MdlErrorValues

eMDLERR_SIGNATURE_NOT_VERIFIED: MdlErrorValues

eMDLERR_SIGNATURE_SILENT: MdlErrorValues

eMDLERR_STRUCTNEEDED: MdlErrorValues

eMDLERR_STYLEISUSED: MdlErrorValues

eMDLERR_STYLENOTFOUND: MdlErrorValues

eMDLERR_SYMBOLNOTRESOLVED: MdlErrorValues

eMDLERR_SYMBOLTOOLONG: MdlErrorValues

eMDLERR_SYNTAXERROR: MdlErrorValues

eMDLERR_SYSTEMERROR: MdlErrorValues

eMDLERR_THREADUNKNOWN: MdlErrorValues

eMDLERR_TIMEOUT: MdlErrorValues

eMDLERR_TOOCOMPLEX: MdlErrorValues

eMDLERR_TOOFEWARGUMENTS: MdlErrorValues

eMDLERR_TOOFEWPOLES: MdlErrorValues

eMDLERR_TOOLARGE: MdlErrorValues

eMDLERR_TOOMANYARGUMENTS: MdlErrorValues

eMDLERR_TOOMANYITERATIONS: MdlErrorValues

eMDLERR_TOOMANYKNOTS: MdlErrorValues

eMDLERR_TOOMANYOPENFILES: MdlErrorValues

eMDLERR_TOOMANYPOLES: MdlErrorValues

eMDLERR_TOOMANYSURFACEELMS: MdlErrorValues

eMDLERR_TYPESINCOMPATIBLE: MdlErrorValues

eMDLERR_UNBOUNDEDSOLUTION: MdlErrorValues

eMDLERR_UNDERSIZE_ELEMENT: MdlErrorValues

eMDLERR_UNKNOWNERROR: MdlErrorValues

eMDLERR_UNKNOWNFORMAT: MdlErrorValues

eMDLERR_UNSUPPORTED: MdlErrorValues

eMDLERR_USERABORT: MdlErrorValues

eMDLERR_V7CELLLIBRARY: MdlErrorValues

eMDLERR_V8B2CELLLIBRARY: MdlErrorValues

eMDLERR_VARWRONGSIZE: MdlErrorValues

eMDLERR_VIEWGROUPNOTFOUND: MdlErrorValues

eMDLERR_VIEWNOTDISPLAYED: MdlErrorValues

eMDLERR_VIEWNOTFOUND: MdlErrorValues

eMDLERR_VOIDDATATYPE: MdlErrorValues

eMDLERR_WRITEFAILED: MdlErrorValues

eMDLERR_WRITEINHIBIT: MdlErrorValues

eMDLERR_WRONGELEMID: MdlErrorValues

eMESSAGE_DEST_MessageCenter: MessageDestination

eMESSAGE_DEST_None: MessageDestination

eMESSAGE_DEST_WarningDialog: MessageDestination

eMajor_Radius: DragTransformType

eMidpoint: Constraint2dType

eMinor_Radius: DragTransformType

eModifyEdge: SmartFeatureHandlerId

eModifyVertex: SmartFeatureHandlerId

eNONE: FileOpenExtAttr

eNegative: Constraint3dHalfSpace

eNon_Algebraic: Constraint2dStatus

eNone_: UIItemStateType

eNormal: Constraint2dType

eNormalCell: CellAddType

eNotSpecified: Constraint3dHalfSpace

eNot_Changed: Constraint2dStatus

eNot_Consistent: Constraint2dStatus

eNot_Consistent_Dimensions: Constraint2dStatus

eNot_Consistent_Other: Constraint2dStatus

eNot_Consistent_Unknown: Constraint2dStatus

eNot_Solved: Constraint2dStatus

eOPEN: FileListAttr

eOPENCREATE: FileListAttr

eOffset: Constraint2dType

eOffsetFace: SmartFeatureHandlerId

eOffset_Dimension: Constraint2dType

eOffset_Distance: DragTransformType

eOver_Defined: Constraint2dStatus

eParallel: Constraint2dType

eParallel_AntiClockwise: SectorAngleType

eParallel_Clockwise: SectorAngleType

eParameter: VertexType

ePattern_2d_value_1: Constraint2dType

ePattern_2d_value_2: Constraint2dType

ePattern_Value: Constraint2dType

ePatterned: Constraint2dType

ePatterned_2d: Constraint2dType

ePerimeter: Constraint2dType

ePerpendicular: Constraint2dType

ePlanarFace: VertexType

ePlanar_Distance: Constraint2dType

ePointCell: CellAddType

ePointIndex: VertexType

ePolarArray: SmartFeatureHandlerId

ePositive: Constraint3dHalfSpace

eProtrusion: SmartFeatureHandlerId

eRadius: DragTransformType

eRectangularArray: SmartFeatureHandlerId

eRevolve: SmartFeatureHandlerId

eRight: DimensionHalfSpace

eSimple_Dependence: Constraint2dType

eSizeFilter: SmartFeatureHandlerId

eSolved: Constraint2dStatus

eSpinFace: SmartFeatureHandlerId

eStart: VertexType

eSweepEdge: SmartFeatureHandlerId

eSymmetric: Constraint2dType

eTangent: Constraint2dType

eTaperFace: SmartFeatureHandlerId

eThicken: SmartFeatureHandlerId

eTranslateFace: SmartFeatureHandlerId

eTranslation: DragTransformType

eTrim: SmartFeatureHandlerId

eUnknown: Constraint2dStatus

eUnspecified: SmartFeatureHandlerId

eVariableDependency: Constraint3dXAttributeIndex

eVertical: Constraint2dType

eVisible: UIItemStateType

