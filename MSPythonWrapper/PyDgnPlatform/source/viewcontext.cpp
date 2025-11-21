/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\viewcontext.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ViewContext.h>



static const char * __doc_Bentley_DgnPlatform_ViewContext_CheckStop =R"doc(Check for abort.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawTextBlock =R"doc(Draw a text block with all lines and formatting.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawTextString =R"doc(Draw a text string and any adornments such as background shape,
underline, overline, etc. Sets up current ElemDisplayParams for
TextString symbology.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawScanRange =R"doc(Draw ScanRange box.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledCurveVector2d =R"doc(Draw a 2d curve vector using the current Linestyle. If there is no
current Linestyle, draw a solid curve vector.

:param curve:
    curve geometry

:param zDepth:
    Z depth value.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledCurveVector3d =R"doc(Draw a curve vector using the current Linestyle. If there is no
current Linestyle, draw a solid curve vector.

:param curve:
    curve geometry)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledBSplineCurve3d =R"doc(Draw a BSpline curve using the current Linestyle. If there is no
current Linestyle, draw a solid BSpline.

:param curve:
    bspline curve parameters)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledBSplineCurve2d =R"doc(Draw a 2d BSpline curve using the current Linestyle. If there is no
current Linestyle, draw a solid BSpline.

:param curve:
    bspline curve parameters

:param zDepth:
    Z depth value.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledArc3d =R"doc(Draw a 3D elliptical arc using the current Linestyle. If there is no
current Linestyle, draw a solid arc.

:param ellipse:
    The arc data.

:param isEllipse:
    Treat full sweep as ellipse not arc.

:param range:
    Array of 2 points with the range (min followed by max) of the arc.
    This argument is optional and is only used to speed processing. If
    you do not already have the range, pass NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledArc2d =R"doc(Draw a 2D elliptical arc using the current Linestyle. If there is no
current Linestyle, draw a solid arc.

:param ellipse:
    The arc data.

:param isEllipse:
    Treat full sweep as ellipse not arc.

:param zDepth:
    Z depth value.

:param range:
    Array of 2 points with the range (min followed by max) of the arc.
    This argument is optional and is only used to speed processing. If
    you do not already have the range, pass NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledLineString3d =R"doc(Draw a 3D linestring using the current Linestyle, if any. If there is
no current Linestyle, draw a solid linestring.

:param nPts:
    Number of vertices in ``pts.``

:param pts:
    Array of points in linestring

:param range:
    Array of 2 points with the range (min followed by max) of the
    vertices in ``points.`` This argument is optional and is only used
    to speed processing. If you do not already have the range of your
    points, pass NULL.

:param closed:
    Do point represent a shape or linestring.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_DrawStyledLineString2d =R"doc(Draw a 2D linestring using the current Linestyle, if any. If there is
no current Linestyle, draw a solid linestring.

:param nPts:
    Number of vertices in ``pts.``

:param pts:
    Array of points in linestring.

:param zDepth:
    Display priority for all vertices.

:param range:
    Array of 2 points with the range (min followed by max) of the
    vertices in ``points.`` This argument is optional and is only used
    to speed processing. If you do not already have the range of your
    points, pass NULL.

:param closed:
    Do point represent a shape or linestring.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_CheckICachedDraw =R"doc(Check whether we are creating a cached presentation.

:returns:
    true if we're in the process of creating a cache presentation.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetICachedDraw =R"doc(Get the ICachedDraw interface for this ViewContext.

:returns:
    the ICachedDraw for this context.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetIDrawGeom =R"doc(Get the IDrawGeom interface for this ViewContext. Applications should
use this method to draw geometry in Draw methods.

:returns:
    the IDrawGeom for this context)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetIViewDraw =R"doc(Get the IViewDraw interface for this ViewContext. Usually, but not
always, this will be the IViewDraw from the viewport to which this
context is attached.

:returns:
    the IViewDraw for this context)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetNonSnappable =R"doc(Set geometry displayed to this view to be non-snappable

:param unsnappable:
    The non-snappable status.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetLocatePriority =R"doc(Set the locate priority for displayed geometry.

:param priority:
    Hit Priority)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetIndexedLinePattern =R"doc(Set the line pattern in the given material from the given color index.

:param elemMatSymb:
    ElemMatSymb in which to change the line pattern.

:param index:
    Line style index between 0 and 7. @note This is just a helper
    method that calls ElemMatSymb::SetIndexedRasterPattern.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetIndexedLineWidth =R"doc(Set the line width in the given material from the given color index.

:param elemMatSymb:
    ElemMatSymb in which to change the line width.

:param index:
    Line weight between 0 and 31. @note This is just a helper method
    that calls ElemMatSymb::SetWidth)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetIndexedFillColor =R"doc(Set the fill color in the given material from the given color index.
method instead of modifying ElemMatSymb directly.

:param elemMatSymb:
    ElemMatSymb in which to change the fill color.

:param index:
    Color table index value between 0 and 255. @note This is just a
    helper method that calls ElemMatSymb::SetIndexedFillColorTBGR.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetIndexedLineColor =R"doc(Set the line color in the given material from the given color index.

:param elemMatSymb:
    ElemMatSymb in which to change the line color.

:param index:
    Color table index value between 0 and 255. @note This is just a
    helper method that calls ElemMatSymb::SetIndexedLineColorTBGR.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetIndexedLineWidth =R"doc(Do a line width lookup in the current lineweight to width table.

:param index:
    Line weight between 0 and 31.

:returns:
    line width in pixels)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetIndexedColor =R"doc(Do a color lookup in the current color table.

:param index:
    Color table index value between 0 and 255.

:returns:
    RGBA value for index from current color table.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_ActivateOverrideMatSymb =R"doc(Change the Override ElemMatSymb for this context.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_CookElemDisplayParams =R"doc(Perform the full operation of extracting the ElemDisplayParams from an
element then calling CookDisplayParams and CookDisplayParamsOverrides.

:param element:
    The element to cook and output @note Does not call
    ActivateOverrideMatSymb.

Remark:
    s Called from VisitElemHandle, rarely necessary for applications
    to call directly.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_CookDisplayParamsOverrides =R"doc(Change the current ElemDisplayParams for any context overrides. Cooks
the modified ElemDisplayParams into the current OvrMatSymb. @note Does
not call ActivateOverrideMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_CookDisplayParams =R"doc(Change the current " natural " ElemDisplayParams. Resolves effective
symbology as required by the context and initializes the current
ElemMatSymb. @note Calls ActivateMatSymb on the output.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrentDisplayParams =R"doc(Get the current ElemDisplayParams.

:returns:
    the current ElemDisplayParams.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetOverrideMatSymb =R"doc(Get the current OvrMatSymb .

:returns:
    the current OvrMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetElemMatSymb =R"doc(Get the current ElemMatSymb.

:returns:
    the current ElemMatSymb. )doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetLevelClassMask =R"doc(Get the current LevelClassMask for this context. When a ViewContext is
first attached, the LevelClassMask is initialized from the Viewport.
However, during the course of an operation the LevelClassMask in the
context may be changed from its initial value.

:returns:
    the current LevelClassMask for this ViewContext.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetDisplayPriority =R"doc(Calculate the display priority value for a given element. Display
priority is based on the priority value stored in the element header,
the priority value of the element's level, and the priority value of
the current model.

:returns:
    the display priority for element. For 3D views, display priority
    is always 0.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrWidth =R"doc(Get current raster width accounting for overrides.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrFillColor =R"doc(Get current fill color accounting for overrides.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrLineColor =R"doc(Get current line color accounting for overrides.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetSourceDisplayPath =R"doc(Get the source DisplayPath for this ViewContext. The " source "
DisplayPath will only be non-NULL when the context is being used to
" re - display " an existing path. During Updates, for example, the source
DisplayPath will be NULL.

:returns:
    the DisplayPath for this ViewContext. @note see discussion of
    DisplayPaths in the MDL documentation.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrDisplayPath =R"doc(Get the current DisplayPath for this ViewContext. The current
DisplayPath changes as the ViewContext navigates through a model. It
can be used to tell the path from the Root model through parent
ElementRefs to the current ElementRefP (e.g. for components of shared
cells.)

:returns:
    the current DisplayPath for this ViewContext. @note see discussion
    of DisplayPaths in the MDL documentation.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_IsCameraOn =R"doc(Return true if view is a camera view.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_Is3dView =R"doc(Return true if view is 3d.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetViewport =R"doc(Get the Viewport to which this ViewContext is attached. ViewContext's
do not always have to be attached to an Viewport, so therefore callers
must always test the result of this call for NULL.

:returns:
    the Viewport. NULL if not attached to a Viewport.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetDrawPurpose =R"doc(Get the DrawPurpose specified when this ViewContext was attached to
the current Viewport.

:returns:
    the DrawPurpose specified in the call to DrawContext#Attach
    (drawcontext.h))doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrentModel =R"doc(Get the current DgnModelRefP for this ViewContext. When a ViewContext
is first attached to a Viewport, the current DgnModelRefP is the Root
model of the Viewport. However, traversing the references for a
Viewport the current model changes.

:returns:
    the current DgnModelRefP for this ViewContext)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_SetViewFlags =R"doc(Sets the current state of the ViewFlags for this context's output.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetViewFlags =R"doc(Get the current state of the ViewFlags for this context's output, can
be NULL. When a ViewContext is first attached to a Viewport, the
ViewFlags are initialized from the Viewport's viewflags. However,
during the course of an operation, the viewflags for the output may be
different than those on the Viewport.

:returns:
    the current state of the viewflags for this ViewContext.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_PopTransformClip =R"doc(Remove the most recently pushed coordinate system and clip, restoring
the local coordinate system to its previous state.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_PushActiveTransform =R"doc(Push a Transform in master coordinates, creating a new local
coordinate system and clip region.

:param trans:
    the transform to push. May be NULL.

See also:
    PopTransformClip)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_PushViewIndependentOrigin =R"doc(Push a transform such that the X,Y plane of the new local coordinate
system will be aligned with the X,Y plane of the view coordinate
system, oriented about the given origin.

:param origin:
    Origin for rotation, in the *current* local coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_PushClipPlanes =R"doc(Push a Transform and (optionally) a set of clip planes., creating a
new local coordinate system and clip region.

:param clipPlanes:
    Clipping planes to push. The clip region is the union of all
    convex sets in the set.

See also:
    PopTransformClip)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_PushClip =R"doc(@name Pushing and Popping Cand Clips Push a ClipVector

:param clip:
    A clipping vector to push. The clip region is the intersection of
    all clipPrimitives in the vector.

See also:
    PopTransformClip)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_PushTransform =R"doc(@name Pushing and Popping Tranforms and Clips Push a Transform

:param trans:
    Transform to push.

See also:
    PopTransformClip)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_IsViewIndependent =R"doc(Check whether the current transform is view independent. Several
MicroStation element types can display as " View independent " (e.g.
text, text nodes, point cells). They do this by pushing the inverse of
the current view-to-local transformation via
#PushViewIndependentOrigin.

:returns:
    true if the current local coordinate system is a view independent
    transform.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetPixelSizeAtPoint =R"doc(Calculate the size of a " pixel " at a given point in the current local
coordinate system. This method can be used to approximate how large
geometry in local coordinates will appear in DgnCoordSystem::View
units.

:param origin:
    The point at which the pixel size is calculated. This point is
    only relevant in camera views, where local coordinates closer to
    the eye are larger than those further from the eye. May be NULL,
    in which case the center of the view is used.

:returns:
    the length, in the current coordinate system units, of a unit
    bvector in the x direction in DgnCoordSystem::View, starting at
    ``origin.``)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetLocalToFrustumTrans =R"doc(Retrieve a copy of the transform from the local coordinate system at
the specified index into DgnCoordSystem::Frustum.

:param trans:
    Transform from local coordinate system at the specified index to
    DgnCoordSystem::Frustum

:param index:
    Index into transform stack to return transform for.

:returns:
    SUCCESS if there is a local coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrFrustumToLocalTrans =R"doc(Retrieve a copy of the transform from the DgnCoordSystem::Frustum to
current local coordinate system.

:param trans:
    Transform from DgnCoordSystem::Frustum to current local coordinate
    system

:returns:
    SUCCESS if there is a current local coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_GetCurrLocalToFrustumTrans =R"doc(Retrieve a copy of the transform from the current local coordinate
system into DgnCoordSystem::Frustum.

:param trans:
    Transform from current local coordinate system to
    DgnCoordSystem::Frustum

:returns:
    SUCCESS if there is a current local coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_ViewToFrustum =R"doc(Transfrom an array of points in DgnCoordSystem::View into
DgnCoordSystem::Frustum.

:param frustumPts:
    An array to receive the transformed points. Must be dimensioned to
    hold ``nPts`` points.

:param viewPts:
    Input array in DgnCoordSystem::View.

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_FrustumToView =R"doc(Transfrom an array of points in DgnCoordSystem::Frustum into
DgnCoordSystem::View.

:param viewPts:
    An array to receive the transformed points. Must be dimensioned to
    hold ``nPts`` points.

:param frustumPts:
    Input array in DgnCoordSystem::Frustum.

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_ViewToNpc =R"doc(Transfrom an array of points in DgnCoordSystem::View into
DgnCoordSystem::Npc.

:param npcPts:
    An array to receive the transformed points. Must be dimensioned to
    hold ``nPts`` points.

:param viewPts:
    Input array in DgnCoordSystem::View.

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_NpcToView =R"doc(Transfrom an array of points in DgnCoordSystem::Npc into
DgnCoordSystem::View.

:param viewPts:
    An array to receive the transformed points. Must be dimensioned to
    hold ``nPts`` points.

:param npcPts:
    Input array in DgnCoordSystem::Npc.

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_ViewToLocal =R"doc(Transfrom an array of points in DgnCoordSystem::View into the current
local coordinate system.

:param localPts:
    An array to receive the transformed points. Must be dimensioned to
    hold ``nPts`` points.

:param viewPts:
    Input array in DgnCoordSystem::View.

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_FrustumToLocal =R"doc(Transfrom an array of points in DgnCoordSystem::Frustum into the
current local coordinate system.

:param localPts:
    An array to receive the transformed points. Must be dimensioned to
    hold ``nPts`` points.

:param frustumPts:
    Input array in DgnCoordSystem::Frustum.

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_LocalToView =R"doc(Transfrom an array of points in the current local coordinate system
into DgnCoordSystem::View coordinates.

:param viewPts:
    An array to receive the points in DgnCoordSystem::View. Must be
    dimensioned to hold ``nPts`` points.

:param localPts:
    Input array in current local coordinates,

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewContext_LocalToFrustum =R"doc(Transfrom an array of points in the current local coordinate system
into DgnCoordSystem::Frustum coordinates.

:param frustumPts:
    An array to receive the points in DgnCoordSystem::Frustum. Must be
    dimensioned to hold ``nPts`` points.

:param localPts:
    Input array in current local coordinates,

:param nPts:
    Number of points in both arrays.)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetUserPurpose =R"doc(Set user Purpose for this element MSWCharCP string value to be set as
Purpose for clip element Bentley Systems +---------------+------------
---+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetUserPurpose =R"doc(Get user Purpose

:returns:
    SUCCESS if user Purpose is stored in the clip element Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetUserDiscipline =R"doc(Sets user Discipline for this element. MSWCharCP string value to be
set as discipline for clip element. Bentley Systems +---------------+-
--------------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetUserDiscipline =R"doc(Get user Discipline

:returns:
    SUCCESS if user discipline is stored in the clip element Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetClipMaskElementRef =R"doc(Get ElementRef of clip mask element DgnModelRefP modelRef of the model
of clip object

:returns:
    ElementRef of the clip mask element Bentley Systems +-------------
    --+---------------+---------------+---------------+---------------
    +------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetClipBoundElementRef =R"doc(Get ElementRef of clip boundary element modelRef of the model of clip
object

:returns:
    ElementRef of the Clip element Bentley Systems +---------------+--
    -------------+---------------+---------------+---------------+----
    --)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetClipMaskElemHandle =R"doc(Get %Element handle of clip Mask element EditElemHandleR modelRef of
the target model DgnModelRefP modelRef of the model of clip object

:returns:
    SUCCESS if EditElemHandle is found Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetClipBoundElemHandle =R"doc(Get %Element handle of clip boundary element modelRef of the target
model modelRef of the model of clip object

:returns:
    SUCCESS if EditElemHandle is found Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_Remap =R"doc(Remap Forward, Bacward, Cut, Outside and Overall display styles of the
source modelRef to target modelRef

:param target:
    modelRef of the target model

:param source:
    modelRef of the source model

:returns:
    SUCCESS if Ids are mapped successfully Bentley Systems +----------
    -----+---------------+---------------+---------------+------------
    ---+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_RemapToParent =R"doc(Remap Forward, Bacward, Cut, Outside and Overall display styles of the
Modelref to its parent

:param modelRef:
    of the parent of this model

:returns:
    SUCCESS if Ids are mapped successfully Bentley Systems +----------
    -----+---------------+---------------+---------------+------------
    ---+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_From =R"doc(Create object of DynamicViewSettings from existing object of
DynamicViewSettings

:param source:
    constant reference to source DynamicViewSettings

:param filter:
    PFXAttributeFilter callback function

:param retainUniqueXAttr:
    Pass this value as true if you want XAttributes of source
    DynamicViewSettings object to be copied to destination
    DynamicViewSettings object. Bentley Systems +---------------+-----
    ----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_Init =R"doc(initialize DynamicViewSettings Bentley Systems +---------------+------
---------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetFromParent =R"doc(:param value:
    true if DynamicViewSettings of this modelRef are same as parent's
    DynamicViewSettings Bentley Systems +---------------+-------------
    --+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetFromParent =R"doc(:returns:
    returns true if DynamicViewSettings of this modelRef are same as
    parent's DynamicViewSettings Bentley Systems +---------------+----
    -----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetViewHandlerId =R"doc(sets the view handler Id

:param handlerId:
    XAttributeHandlerId of the view element Bentley Systems +---------
    ------+---------------+---------------+---------------+-----------
    ----+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetViewHandlerId =R"doc(:returns:
    returns the view handler Id Bentley Systems +---------------+-----
    ----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetLevelOfDetail =R"doc(sets level of dtail.

:param levelOfDetail:
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetLevelOfDetail =R"doc(:returns:
    returns level of dtail. Bentley Systems +---------------+---------
    ------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetDisplayStyleIndex =R"doc(sets index into the display style table

:param index:
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetDisplayStyleIndex =R"doc(:returns:
    returns index into the display style table Bentley Systems +------
    ---------+---------------+---------------+---------------+--------
    -------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetClipMaskElementId =R"doc(set ElementID of the clip mask element

:param newId:
    ElementID of the clip mask element Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetClipMaskElementId =R"doc(:returns:
    returns ElementID of the clip mask element Bentley Systems +------
    ---------+---------------+---------------+---------------+--------
    -------+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_SetClipBoundElementId =R"doc(set ElementID of the clip boundary element

:param newId:
    ElementID of the clip boundary element Bentley Systems +----------
    -----+---------------+---------------+---------------+------------
    ---+------)doc";

static const char * __doc_Bentley_DgnPlatform_DynamicViewSettings_GetClipBoundElementId =R"doc(:returns:
    returns ElementID of the clip boundary element Bentley Systems +--
    -------------+---------------+---------------+---------------+----
    -----------+------)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributesHolder_GetXAttribute =R"doc(Find XAttribute on this element with xAttrId

:param pSize:
    size of the XAttribute

:param handlerId:
    XAttributeHandlerId of the XAttribute

:param xAttrId:
    UInt32 ID of the XAttribute

:returns:
    void pointer pointing to XAttribute data Bentley Systems +--------
    -------+---------------+---------------+---------------+----------
    -----+------)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributesHolder_DeleteXAttribute =R"doc(Remove an XAttribute from element

:param handlerId:
    XAttributeHandlerId of the XAttribute

:param xAttrId:
    UInt32 ID of the XAttribute

:returns:
    SUCCESS if XAttribute is added without any error Bentley Systems +
    ---------------+---------------+---------------+---------------+--
    -------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributesHolder_AddXAttribute =R"doc(--------------+---------------+---------------+---------------+-------
--------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ViewContext(py::module_& m)
    {
    //===================================================================================
    // enum GeomRepresentations
    py::enum_< GeomRepresentations>(m, "GeomRepresentations", py::arithmetic())
        .value("eDISPLAY_INFO_None", DISPLAY_INFO_None)
        .value("eDISPLAY_INFO_Edge", DISPLAY_INFO_Edge)
        .value("eDISPLAY_INFO_Fill", DISPLAY_INFO_Fill)
        .value("eDISPLAY_INFO_Surface", DISPLAY_INFO_Surface)
        .value("eDISPLAY_INFO_Thickness", DISPLAY_INFO_Thickness)
        .value("eDISPLAY_INFO_Pattern", DISPLAY_INFO_Pattern)
        .export_values();

    //===================================================================================
    // enum FilterLODFlags
    py::enum_< FilterLODFlags>(m, "FilterLODFlags", py::arithmetic())
        .value("eFILTER_LOD_Off", FILTER_LOD_Off)
        .value("eFILTER_LOD_ShowRange", FILTER_LOD_ShowRange)
        .value("eFILTER_LOD_ShowNothing", FILTER_LOD_ShowNothing)
        .export_values();


    //===================================================================================
    // struct ClipVolumeOverrides
    py::class_< ClipVolumeOverrides> c1(m, "ClipVolumeOverrides");

    c1.def_property("display",
                    [] (ClipVolumeOverrides const& self) { return (bool) self.m_flags.m_display; },
                    [] (ClipVolumeOverrides& self, bool value) { self.m_flags.m_display = value ? 1 : 0; });

    c1.def_property("disableLocate",
                    [] (ClipVolumeOverrides const& self) { return (bool) self.m_flags.m_disableLocate; },
                    [] (ClipVolumeOverrides& self, bool value) { self.m_flags.m_disableLocate = value ? 1 : 0; });

    c1.def_property("disableSnap",
                    [] (ClipVolumeOverrides const& self) { return (bool) self.m_flags.m_disableSnap; },
                    [] (ClipVolumeOverrides& self, bool value) { self.m_flags.m_disableSnap = value ? 1 : 0; });

    c1.def_property("reflected",
                    [] (ClipVolumeOverrides const& self) { return (bool) self.m_flags.m_reflected; },
                    [] (ClipVolumeOverrides& self, bool value) { self.m_flags.m_reflected = value ? 1 : 0; });

    c1.def_readwrite("styleIndex", &ClipVolumeOverrides::m_styleIndex);


    //===================================================================================
    // struct ClipVolumeFlags
    py::class_< ClipVolumeFlags> c2(m, "ClipVolumeFlags");

    c2.def_property("reflected",
                    [] (ClipVolumeFlags const& self) { return (bool) self.m_reflected; },
                    [] (ClipVolumeFlags& self, bool value) { self.m_reflected = value ? 1 : 0; });

    c2.def_property("ignoreBoundaryClipping",
                    [] (ClipVolumeFlags const& self) { return (bool) self.m_ignoreBoundaryClipping; },
                    [] (ClipVolumeFlags& self, bool value) { self.m_ignoreBoundaryClipping = value ? 1 : 0; });

    c2.def_property("ignoreBoundaryCutPlanes",
                    [] (ClipVolumeFlags const& self) { return (bool) self.m_ignoreBoundaryCutPlanes; },
                    [] (ClipVolumeFlags& self, bool value) { self.m_ignoreBoundaryCutPlanes = value ? 1 : 0; });

    //===================================================================================
    // struct  XAttributesHolder
    py::class_< XAttributesHolder> c3(m, "XAttributesHolder");
    c3.def("AddXAttribute", [] (XAttributesHolder& self, XAttributeHandlerId handlerId, UInt32 xAttrId, py::bytes const& xaData)
           {
           std::string strData = xaData.cast<std::string>();
           return self.AddXAttribute(handlerId, xAttrId, (void const*) strData.data(), (UInt32) strData.size());
           }, "handlerId"_a, "xAttrId"_a, "xaData"_a, DOC(Bentley, DgnPlatform, XAttributesHolder, AddXAttribute));
    
    c3.def("DeleteXAttribute", &XAttributesHolder::DeleteXAttribute, "handlerId"_a, "xAttrId"_a, DOC(Bentley, DgnPlatform, XAttributesHolder, DeleteXAttribute));

    c3.def("GetXAttribute", [] (XAttributesHolder const& self, XAttributeHandlerId handlerId, UInt32 xAttrId)
           {
           py::bytes outData;
           int dataSize = 0;
           auto pData = self.GetXAttribute(&dataSize, handlerId, xAttrId);
           if (nullptr != pData && dataSize > 0)
               outData = py::bytes((const char*) pData, dataSize);
           return outData;
           }, "handlerId"_a, "xAttrId"_a, DOC(Bentley, DgnPlatform, XAttributesHolder, GetXAttribute));


    //===================================================================================
    // struct DynamicViewSettings
    py::class_< DynamicViewSettings> c5(m, "DynamicViewSettings");

    c5.def_property("ClipBoundElementId", &DynamicViewSettings::GetClipBoundElementId, &DynamicViewSettings::SetClipBoundElementId);
    c5.def("GetClipBoundElementId", &DynamicViewSettings::GetClipBoundElementId, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetClipBoundElementId));
    c5.def("SetClipBoundElementId", &DynamicViewSettings::SetClipBoundElementId, "newId"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetClipBoundElementId));
    
    c5.def_property("ClipMaskElementId", &DynamicViewSettings::GetClipMaskElementId, &DynamicViewSettings::SetClipMaskElementId);
    c5.def("GetClipMaskElementId", &DynamicViewSettings::GetClipMaskElementId, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetClipMaskElementId));
    c5.def("SetClipMaskElementId", &DynamicViewSettings::SetClipMaskElementId, "newId"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetClipMaskElementId));
    
    c5.def_property("DisplayStyleIndex", &DynamicViewSettings::GetDisplayStyleIndex, &DynamicViewSettings::SetDisplayStyleIndex);
    c5.def("GetDisplayStyleIndex", &DynamicViewSettings::GetDisplayStyleIndex, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetDisplayStyleIndex));
    c5.def("SetDisplayStyleIndex", &DynamicViewSettings::SetDisplayStyleIndex, "index"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetDisplayStyleIndex));
    
    c5.def_property("LevelOfDetail", &DynamicViewSettings::GetLevelOfDetail, &DynamicViewSettings::SetLevelOfDetail);
    c5.def("GetLevelOfDetail", &DynamicViewSettings::GetLevelOfDetail, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetLevelOfDetail));
    c5.def("SetLevelOfDetail", &DynamicViewSettings::SetLevelOfDetail, "lod"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetLevelOfDetail));
    
    c5.def_property("ViewHandlerId", &DynamicViewSettings::GetViewHandlerId, &DynamicViewSettings::SetViewHandlerId);
    c5.def("GetViewHandlerId", &DynamicViewSettings::GetViewHandlerId, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetViewHandlerId));
    c5.def("SetViewHandlerId", &DynamicViewSettings::SetViewHandlerId, "handlerId"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetViewHandlerId));
    
    c5.def_property_readonly("XAttributesHolder", &DynamicViewSettings::GetXAttributesHolderR);
    c5.def("GetXAttributesHolder", &DynamicViewSettings::GetXAttributesHolderR, py::return_value_policy::reference_internal);
    
    c5.def_property("FromParent", &DynamicViewSettings::GetFromParent, &DynamicViewSettings::SetFromParent);
    c5.def("GetFromParent", &DynamicViewSettings::GetFromParent, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetFromParent));
    c5.def("SetFromParent", &DynamicViewSettings::SetFromParent, "value"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetFromParent));

    c5.def("Init", &DynamicViewSettings::Init, DOC(Bentley, DgnPlatform, DynamicViewSettings, Init));
    //c5.def("From", &DynamicViewSettings::From, "source"_a, "filter"_a = nullptr, "retainUniqueXAttr"_a = false, DOC(Bentley, DgnPlatform, DynamicViewSettings, From));
    c5.def("RemapToParent", &DynamicViewSettings::RemapToParent, "modelRef"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, RemapToParent));
    c5.def("Remap", py::overload_cast<DgnModelRefP, DgnModelRefCP>(&DynamicViewSettings::Remap), "target"_a, "source"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, Remap));
    c5.def("GetClipBoundElemHandle", &DynamicViewSettings::GetClipBoundElemHandle, "eeh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetClipBoundElemHandle));
    c5.def("GetClipMaskElemHandle", &DynamicViewSettings::GetClipMaskElemHandle, "eeh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetClipMaskElemHandle));
    c5.def("GetClipBoundElementRef", &DynamicViewSettings::GetClipBoundElementRef, "modelRef"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetClipBoundElementRef));
    c5.def("GetClipMaskElementRef", &DynamicViewSettings::GetClipMaskElementRef, "modelRef"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetClipMaskElementRef));
    
    c5.def("GetUserDiscipline", &DynamicViewSettings::GetUserDiscipline, "discipline"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetUserDiscipline));
    c5.def("SetUserDiscipline", &DynamicViewSettings::SetUserDiscipline, "discipline"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetUserDiscipline));
    
    c5.def("GetUserPurpose", &DynamicViewSettings::GetUserPurpose, "purpose"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, GetUserPurpose));
    c5.def("SetUserPurpose", &DynamicViewSettings::SetUserPurpose, "purpose"_a, DOC(Bentley, DgnPlatform, DynamicViewSettings, SetUserPurpose));

    //===================================================================================
    // struct ViewContext
    py::class_< ViewContext, std::unique_ptr<ViewContext, py::nodelete> > c6(m, "ViewContext");

    c6.def("VisitElemHandle", &ViewContext::VisitElemHandle, "eh"_a, "checkRange"_a, "checkScanCriteria"_a);
    c6.def("PushPath", &ViewContext::PushPath, "elemRef"_a);
    c6.def("PopPath", &ViewContext::PopPath, py::return_value_policy::reference_internal);

    c6.def("LocalToFrustum", [] (ViewContext const& self, DPoint3dArray& frustumPts, DPoint3dArray const& localPts)
           {
           size_t nPts = localPts.size();
           if (frustumPts.size() < nPts)
               frustumPts.resize(nPts);
           if (nPts > 0)
               self.LocalToFrustum(frustumPts.data(), localPts.data(), (int) nPts);
           }, "frustumPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToFrustum));

    c6.def("LocalToFrustum", [] (ViewContext const& self, py::list& frustumPts, py::list const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppLocalPts.size();
           if (cppFrustumPts.size() < nPts)
               cppFrustumPts.resize(nPts);
           if (nPts > 0)
               self.LocalToFrustum(cppFrustumPts.data(), cppLocalPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           }, "frustumPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToFrustum));

    c6.def("LocalToFrustum", [] (ViewContext const& self, DPoint3dArray& frustumPts, py::list const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppLocalPts.size();
           if (frustumPts.size() < nPts)
               frustumPts.resize(nPts);
           if (nPts > 0)
               self.LocalToFrustum(frustumPts.data(), cppLocalPts.data(), (int) nPts);
           }, "frustumPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToFrustum));

    c6.def("LocalToFrustum", [] (ViewContext const& self, py::list& frustumPts, DPoint3dArray const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = localPts.size();
           if (cppFrustumPts.size() < nPts)
               cppFrustumPts.resize(nPts);
           if (nPts > 0)
               self.LocalToFrustum(cppFrustumPts.data(), localPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           }, "frustumPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToFrustum));

    c6.def("LocalToView", [] (ViewContext const& self, DPoint4dArray& viewPts, DPoint3dArray const& localPts)
           {
           size_t nPts = localPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.LocalToView(viewPts.data(), localPts.data(), (int) nPts);
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, DPoint4dArray& viewPts, py::list const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppLocalPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.LocalToView(viewPts.data(), cppLocalPts.data(), (int) nPts);
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, py::list& viewPts, DPoint3dArray const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           size_t nPts = localPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0){
               self.LocalToView(cppViewPts.data(), localPts.data(), (int) nPts);
               CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           }
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, py::list& viewPts, py::list const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppLocalPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0){
               self.LocalToView(cppViewPts.data(), cppLocalPts.data(), (int) nPts);
               CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           }
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, DPoint3dArray& viewPts, DPoint3dArray const& localPts)
           {
           size_t nPts = localPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.LocalToView(viewPts.data(), localPts.data(), (int) nPts);
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, DPoint3dArray& viewPts, py::list const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppLocalPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.LocalToView(viewPts.data(), cppLocalPts.data(), (int) nPts);
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, py::list& viewPts, DPoint3dArray const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           size_t nPts = localPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0)
               self.LocalToView(cppViewPts.data(), localPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("LocalToView", [] (ViewContext const& self, py::list& viewPts, py::list const& localPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppLocalPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0)
               self.LocalToView(cppViewPts.data(), cppLocalPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           }, "viewPts"_a, "localPts"_a, DOC(Bentley, DgnPlatform, ViewContext, LocalToView));

    c6.def("FrustumToLocal", [] (ViewContext const& self, DPoint3dArray& localPts, DPoint3dArray const& frustumPts)
           {
           size_t nPts = frustumPts.size();
           if (localPts.size() < nPts)
               localPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToLocal(localPts.data(), frustumPts.data(), (int) nPts);
           }, "localPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToLocal));

    c6.def("FrustumToLocal", [] (ViewContext const& self, DPoint3dArray& localPts, py::list const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppFrustumPts.size();
           if (localPts.size() < nPts)
               localPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToLocal(localPts.data(), cppFrustumPts.data(), (int) nPts);
           }, "localPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToLocal));

    c6.def("FrustumToLocal", [] (ViewContext const& self, py::list& localPts, DPoint3dArray const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = frustumPts.size();
           if (cppLocalPts.size() < nPts)
               cppLocalPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToLocal(cppLocalPts.data(), frustumPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           }, "localPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToLocal));

    c6.def("FrustumToLocal", [] (ViewContext const& self, py::list& localPts, py::list const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppFrustumPts.size();
           if (cppLocalPts.size() < nPts)
               cppLocalPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToLocal(cppLocalPts.data(), cppFrustumPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           }, "localPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToLocal));

    c6.def("ViewToLocal", [] (ViewContext const& self, DPoint3dArray& localPts, DPoint4dArray const& viewPts)
           {
           size_t nPts = viewPts.size();
           if (localPts.size() < nPts)
               localPts.resize(nPts);
           if (nPts > 0)
               self.ViewToLocal(localPts.data(), viewPts.data(), (int) nPts);
           }, "localPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToLocal));

    c6.def("ViewToLocal", [] (ViewContext const& self, py::list& localPts, DPoint4dArray const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = viewPts.size();
           if (cppLocalPts.size() < nPts)
               cppLocalPts.resize(nPts);
           if (nPts > 0)
               self.ViewToLocal(cppLocalPts.data(), viewPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           }, "localPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToLocal));

    c6.def("ViewToLocal", [] (ViewContext const& self, DPoint3dArray& localPts, py::list const& viewPts)
           {
           size_t nPts = len(viewPts);
           if (localPts.size() < nPts)
               localPts.resize(nPts);
           if (nPts > 0){
                if (py::isinstance<DPoint3d>(viewPts[0])){
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
                    self.ViewToLocal(localPts.data(), cppViewPts.data(), (int) nPts);
                }
                else if (py::isinstance<DPoint4d>(viewPts[0])){
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
                    self.ViewToLocal(localPts.data(), cppViewPts.data(), (int) nPts);
                }
           }
           }, "localPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToLocal));

    c6.def("ViewToLocal", [] (ViewContext const& self, DPoint3dArray& localPts, DPoint3dArray const& viewPts)
           {
           size_t nPts = viewPts.size();
           if (localPts.size() < nPts)
               localPts.resize(nPts);
           if (nPts > 0)
               self.ViewToLocal(localPts.data(), viewPts.data(), (int) nPts);
           }, "localPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToLocal));

    c6.def("ViewToLocal", [] (ViewContext const& self, py::list& localPts, py::list const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           size_t nPts = len(viewPts);
           if (cppLocalPts.size() < nPts)
               cppLocalPts.resize(nPts);
           if (nPts > 0){
                if (py::isinstance<DPoint3d>(viewPts[0])){
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
                    self.ViewToLocal(cppLocalPts.data(), cppViewPts.data(), (int) nPts);
                }
                else if (py::isinstance<DPoint4d>(viewPts[0])){
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
                    self.ViewToLocal(cppLocalPts.data(), cppViewPts.data(), (int) nPts);
                }
                CONVERT_CPPARRAY_TO_PYLIST(localPts, cppLocalPts, DPoint3dArray, DPoint3d);
           }
           }, "localPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToLocal));

    c6.def("NpcToView", [] (ViewContext const& self, DPoint3dArray& viewPts, DPoint3dArray const& npcPts)
           {
           size_t nPts = npcPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.NpcToView(viewPts.data(), npcPts.data(), (int) nPts);
           }, "viewPts"_a, "npcPts"_a, DOC(Bentley, DgnPlatform, ViewContext, NpcToView));

    c6.def("NpcToView", [] (ViewContext const& self, py::list& viewPts, DPoint3dArray const& npcPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           size_t nPts = npcPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0)
               self.NpcToView(cppViewPts.data(), npcPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           }, "viewPts"_a, "npcPts"_a, DOC(Bentley, DgnPlatform, ViewContext, NpcToView));

    c6.def("NpcToView", [] (ViewContext const& self, DPoint3dArray& viewPts, py::list const& npcPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppNpcPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.NpcToView(viewPts.data(), cppNpcPts.data(), (int) nPts);
           }, "viewPts"_a, "npcPts"_a, DOC(Bentley, DgnPlatform, ViewContext, NpcToView));

    c6.def("NpcToView", [] (ViewContext const& self, py::list& viewPts, py::list const& npcPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppNpcPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0)
               self.NpcToView(cppViewPts.data(), cppNpcPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           }, "viewPts"_a, "npcPts"_a, DOC(Bentley, DgnPlatform, ViewContext, NpcToView));

    c6.def("ViewToNpc", [] (ViewContext const& self, DPoint3dArray& npcPts, DPoint3dArray const& viewPts)
           {
           size_t nPts = viewPts.size();
           if (npcPts.size() < nPts)
               npcPts.resize(nPts);
           if (nPts > 0)
               self.ViewToNpc(npcPts.data(), viewPts.data(), (int) nPts);
           }, "npcPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToNpc));

    c6.def("ViewToNpc", [] (ViewContext const& self, py::list& npcPts, py::list const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppViewPts.size();
           if (cppNpcPts.size() < nPts)
               cppNpcPts.resize(nPts);
           if (nPts > 0)
               self.ViewToNpc(cppNpcPts.data(), cppViewPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
           }, "npcPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToNpc));

    c6.def("ViewToNpc", [] (ViewContext const& self, DPoint3dArray& npcPts, py::list const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppViewPts.size();
           if (npcPts.size() < nPts)
               npcPts.resize(nPts);
           if (nPts > 0)
               self.ViewToNpc(npcPts.data(), cppViewPts.data(), (int) nPts);
           }, "npcPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToNpc));

    c6.def("ViewToNpc", [] (ViewContext const& self, py::list& npcPts, DPoint3dArray const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
           size_t nPts = viewPts.size();
           if (cppNpcPts.size() < nPts)
               cppNpcPts.resize(nPts);
           if (nPts > 0)
               self.ViewToNpc(cppNpcPts.data(), viewPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
           }, "npcPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToNpc));

    c6.def("FrustumToView", [] (ViewContext const& self, DPoint4dArray& viewPts, DPoint3dArray const& frustumPts)
           {
           size_t nPts = frustumPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToView(viewPts.data(), frustumPts.data(), (int) nPts);
           }, "viewPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToView));

    c6.def("FrustumToView", [] (ViewContext const& self, DPoint4dArray& viewPts, py::list const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppFrustumPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToView(viewPts.data(), cppFrustumPts.data(), (int) nPts);
           }, "viewPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToView));

    c6.def("FrustumToView", [] (ViewContext const& self, py::list& viewPts, DPoint3dArray const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           size_t nPts = frustumPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToView(cppViewPts.data(), frustumPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           }, "viewPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToView));

    c6.def("FrustumToView", [] (ViewContext const& self, py::list& viewPts, py::list const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppFrustumPts.size();
           if (cppViewPts.size() < nPts)
               cppViewPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToView(cppViewPts.data(), cppFrustumPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
           }, "viewPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToView));

    c6.def("FrustumToView", [] (ViewContext const& self, bvector<Point2d>& viewPts, DPoint3dArray const& frustumPts)
           {
           size_t nPts = frustumPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToView(viewPts.data(), frustumPts.data(), (int) nPts);
           }, "viewPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToView));    

    c6.def("FrustumToView", [] (ViewContext const& self, bvector<Point2d>& viewPts, py::list const& frustumPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = cppFrustumPts.size();
           if (viewPts.size() < nPts)
               viewPts.resize(nPts);
           if (nPts > 0)
               self.FrustumToView(viewPts.data(), cppFrustumPts.data(), (int) nPts);
           }, "viewPts"_a, "frustumPts"_a, DOC(Bentley, DgnPlatform, ViewContext, FrustumToView));

    c6.def("ViewToFrustum", [] (ViewContext const& self, DPoint3dArray& frustumPts, DPoint4dArray const& viewPts)
           {
           size_t nPts = viewPts.size();
           if (frustumPts.size() < nPts)
               frustumPts.resize(nPts);
           if (nPts > 0)
               self.ViewToFrustum(frustumPts.data(), viewPts.data(), (int) nPts);
           }, "frustumPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToFrustum));

    c6.def("ViewToFrustum", [] (ViewContext const& self, py::list& frustumPts, DPoint4dArray const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = viewPts.size();
           if (cppFrustumPts.size() < nPts)
               cppFrustumPts.resize(nPts);
           if (nPts > 0)
               self.ViewToFrustum(cppFrustumPts.data(), viewPts.data(), (int) nPts);
           CONVERT_CPPARRAY_TO_PYLIST(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           }, "frustumPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToFrustum));

    c6.def("ViewToFrustum", [] (ViewContext const& self, DPoint3dArray& frustumPts, py::list const& viewPts)
           {
           size_t nPts = viewPts.size();
           if (frustumPts.size() < nPts)
               frustumPts.resize(nPts);
           if (nPts > 0){
              if(py::isinstance<DPoint3d>(viewPts[0])){
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
                  self.ViewToFrustum(frustumPts.data(), cppViewPts.data(), (int) nPts);
              }
              else if (py::isinstance<DPoint4d>(viewPts[0])){
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
                  self.ViewToFrustum(frustumPts.data(), cppViewPts.data(), (int) nPts);
              }
            }
           }, "frustumPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToFrustum));

    c6.def("ViewToFrustum", [] (ViewContext const& self, DPoint3dArray& frustumPts, DPoint3dArray const& viewPts)
           {
           size_t nPts = viewPts.size();
           if (frustumPts.size() < nPts)
               frustumPts.resize(nPts);
           if (nPts > 0)
               self.ViewToFrustum(frustumPts.data(), viewPts.data(), (int) nPts);
           }, "frustumPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToFrustum));

    c6.def("ViewToFrustum", [] (ViewContext const& self, py::list& frustumPts, py::list const& viewPts)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
           size_t nPts = len(viewPts);
           if (cppFrustumPts.size() < nPts)
               cppFrustumPts.resize(nPts);
            if (nPts > 0){
                if(py::isinstance<DPoint3d>(viewPts[0])){
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
                    self.ViewToFrustum(cppFrustumPts.data(), cppViewPts.data(), (int) nPts);
                }
                else if (py::isinstance<DPoint4d>(viewPts[0])){
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint4dArray, DPoint4d);
                    self.ViewToFrustum(cppFrustumPts.data(), cppViewPts.data(), (int) nPts);
                }
                CONVERT_CPPARRAY_TO_PYLIST(frustumPts, cppFrustumPts, DPoint3dArray, DPoint3d);
            }
           }, "frustumPts"_a, "viewPts"_a, DOC(Bentley, DgnPlatform, ViewContext, ViewToFrustum));
    
    c6.def_property_readonly("CurrLocalToFrustumTransform", &ViewContext::GetCurrLocalToFrustumTransformCP);
    c6.def("GetCurrLocalToFrustumTransform", &ViewContext::GetCurrLocalToFrustumTransformCP, py::return_value_policy::reference_internal);

    c6.def("GetCurrLocalToFrustumTrans", &ViewContext::GetCurrLocalToFrustumTrans, "transform"_a, DOC(Bentley, DgnPlatform, ViewContext, GetCurrLocalToFrustumTrans));
    c6.def("GetCurrFrustumToLocalTrans", &ViewContext::GetCurrFrustumToLocalTrans, "transform"_a, DOC(Bentley, DgnPlatform, ViewContext, GetCurrFrustumToLocalTrans));
    c6.def("GetLocalToFrustumTrans", &ViewContext::GetLocalToFrustumTrans, "transform"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, GetLocalToFrustumTrans));
    c6.def("GetPixelSizeAtPoint", &ViewContext::GetPixelSizeAtPoint, "origin"_a, DOC(Bentley, DgnPlatform, ViewContext, GetPixelSizeAtPoint));

    c6.def("IsViewIndependent", &ViewContext::IsViewIndependent, DOC(Bentley, DgnPlatform, ViewContext, IsViewIndependent));
    c6.def("PushTransform", &ViewContext::PushTransform, "transform"_a, DOC(Bentley, DgnPlatform, ViewContext, PushTransform));
    c6.def("PushClip", &ViewContext::PushClip, "clip"_a, DOC(Bentley, DgnPlatform, ViewContext, PushClip));
    c6.def("PushClipPlanes", &ViewContext::PushClipPlanes, "clipPlanes"_a, DOC(Bentley, DgnPlatform, ViewContext, PushClipPlanes));
    c6.def("PushViewIndependentOrigin", &ViewContext::PushViewIndependentOrigin, "origin"_a, DOC(Bentley, DgnPlatform, ViewContext, PushViewIndependentOrigin));
    c6.def("PushActiveTransform", &ViewContext::PushActiveTransform, "transform"_a, DOC(Bentley, DgnPlatform, ViewContext, PushActiveTransform));
    c6.def("PopTransformClip", &ViewContext::PopTransformClip, DOC(Bentley, DgnPlatform, ViewContext, PopTransformClip));
    
    c6.def_property("ViewFlags", &ViewContext::GetViewFlags, &ViewContext::SetViewFlags);
    c6.def("GetViewFlags", &ViewContext::GetViewFlags, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetViewFlags));
    c6.def("SetViewFlags", &ViewContext::SetViewFlags, "flags"_a, DOC(Bentley, DgnPlatform, ViewContext, SetViewFlags));
    
    c6.def_property_readonly("CurrentModel", &ViewContext::GetCurrentModel);
    c6.def("GetCurrentModel", &ViewContext::GetCurrentModel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetCurrentModel));
    
    c6.def_property_readonly("DrawPurpose", &ViewContext::GetDrawPurpose);
    c6.def("GetDrawPurpose", &ViewContext::GetDrawPurpose, DOC(Bentley, DgnPlatform, ViewContext, GetDrawPurpose));
    
    c6.def_property_readonly("Viewport", &ViewContext::GetViewport);
    c6.def("GetViewport", &ViewContext::GetViewport, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetViewport));
    
    c6.def("Is3dView", &ViewContext::Is3dView, DOC(Bentley, DgnPlatform, ViewContext, Is3dView));
    c6.def("IsCameraOn", &ViewContext::IsCameraOn, DOC(Bentley, DgnPlatform, ViewContext, IsCameraOn));
    
    c6.def_property_readonly("CurrDisplayPath", &ViewContext::GetCurrDisplayPath);
    c6.def("GetCurrDisplayPath", &ViewContext::GetCurrDisplayPath, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetCurrDisplayPath));
    
    c6.def_property_readonly("SourceDisplayPath", &ViewContext::GetSourceDisplayPath);
    c6.def("GetSourceDisplayPath", &ViewContext::GetSourceDisplayPath, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetSourceDisplayPath));

    c6.def_property_readonly("CurrLineColor", &ViewContext::GetCurrLineColor);
    c6.def("GetCurrLineColor", &ViewContext::GetCurrLineColor, DOC(Bentley, DgnPlatform, ViewContext, GetCurrLineColor));
    
    c6.def_property_readonly("CurrFillColor", &ViewContext::GetCurrFillColor);
    c6.def("GetCurrFillColor", &ViewContext::GetCurrFillColor, DOC(Bentley, DgnPlatform, ViewContext, GetCurrFillColor));
    
    c6.def_property_readonly("CurrWidth", &ViewContext::GetCurrWidth);
    c6.def("GetCurrWidth", &ViewContext::GetCurrWidth, DOC(Bentley, DgnPlatform, ViewContext, GetCurrWidth));
    
    c6.def_property_readonly("DisplayPriority", &ViewContext::GetDisplayPriority);
    c6.def("GetDisplayPriority", &ViewContext::GetDisplayPriority, DOC(Bentley, DgnPlatform, ViewContext, GetDisplayPriority));
    
    c6.def_property_readonly("LevelClassMask", &ViewContext::GetLevelClassMask);
    c6.def("GetLevelClassMask", &ViewContext::GetLevelClassMask, DOC(Bentley, DgnPlatform, ViewContext, GetLevelClassMask));
    
    c6.def_property_readonly("ElemMatSymb", &ViewContext::GetElemMatSymb);
    c6.def("GetElemMatSymb", &ViewContext::GetElemMatSymb, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetElemMatSymb));
    
    c6.def_property_readonly("OverrideMatSymb", &ViewContext::GetOverrideMatSymb);
    c6.def("GetOverrideMatSymb", &ViewContext::GetOverrideMatSymb, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetOverrideMatSymb));
    
    c6.def_property_readonly("CurrentDisplayParams", &ViewContext::GetCurrentDisplayParams);
    c6.def("GetCurrentDisplayParams", &ViewContext::GetCurrentDisplayParams, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetCurrentDisplayParams));
    
    c6.def("CookDisplayParams", py::overload_cast<>(&ViewContext::CookDisplayParams), DOC(Bentley, DgnPlatform, ViewContext, CookDisplayParams));
    c6.def("CookDisplayParamsOverrides", &ViewContext::CookDisplayParamsOverrides, DOC(Bentley, DgnPlatform, ViewContext, CookDisplayParamsOverrides));
    c6.def("CookElemDisplayParams", &ViewContext::CookElemDisplayParams, "eh"_a, DOC(Bentley, DgnPlatform, ViewContext, CookElemDisplayParams));
    c6.def("ActivateOverrideMatSymb", &ViewContext::ActivateOverrideMatSymb, DOC(Bentley, DgnPlatform, ViewContext, ActivateOverrideMatSymb));
    c6.def("GetIndexedColor", &ViewContext::GetIndexedColor, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, GetIndexedColor));
    c6.def("GetIndexedLineWidth", &ViewContext::GetIndexedLineWidth, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, GetIndexedLineWidth));
    c6.def("GetIndexedLinePattern", &ViewContext::GetIndexedLinePattern, "index"_a);
    c6.def("SetIndexedLineColor", py::overload_cast<ElemMatSymbR, int>(&ViewContext::SetIndexedLineColor), "elemMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedLineColor));
    c6.def("SetIndexedFillColor", py::overload_cast<ElemMatSymbR, int>(&ViewContext::SetIndexedFillColor), "elemMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedFillColor));
    c6.def("SetIndexedLineWidth", py::overload_cast<ElemMatSymbR, int>(&ViewContext::SetIndexedLineWidth), "elemMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedLineWidth));
    c6.def("SetIndexedLinePattern", py::overload_cast<ElemMatSymbR, int>(&ViewContext::SetIndexedLinePattern), "elemMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedLinePattern));
    c6.def("SetIndexedLineColor", py::overload_cast<OvrMatSymbR, int>(&ViewContext::SetIndexedLineColor), "ovrMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedLineColor));
    c6.def("SetIndexedFillColor", py::overload_cast<OvrMatSymbR, int>(&ViewContext::SetIndexedFillColor), "ovrMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedFillColor));
    c6.def("SetIndexedLineWidth", py::overload_cast<OvrMatSymbR, int>(&ViewContext::SetIndexedLineWidth), "ovrMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedLineWidth));
    c6.def("SetIndexedLinePattern", py::overload_cast<OvrMatSymbR, int>(&ViewContext::SetIndexedLinePattern), "ovrMatSymb"_a, "index"_a, DOC(Bentley, DgnPlatform, ViewContext, SetIndexedLinePattern));
    c6.def("SetLocatePriority", &ViewContext::SetLocatePriority, "priority"_a, DOC(Bentley, DgnPlatform, ViewContext, SetLocatePriority));
    c6.def("SetNonSnappable", &ViewContext::SetNonSnappable, "unsnappable"_a, DOC(Bentley, DgnPlatform, ViewContext, SetNonSnappable));

    c6.def_property_readonly("IViewDraw", &ViewContext::GetIViewDraw);
    c6.def("GetIViewDraw", &ViewContext::GetIViewDraw, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetIViewDraw));
    
    c6.def_property_readonly("IDrawGeom", &ViewContext::GetIDrawGeom);
    c6.def("GetIDrawGeom", &ViewContext::GetIDrawGeom, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetIDrawGeom));
    
    c6.def_property_readonly("ICachedDraw", &ViewContext::GetICachedDraw);
    c6.def("GetICachedDraw", &ViewContext::GetICachedDraw, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewContext, GetICachedDraw));
    
    c6.def("CheckICachedDraw", &ViewContext::CheckICachedDraw, DOC(Bentley, DgnPlatform, ViewContext, CheckICachedDraw));

    c6.def("DrawStyledLineString2d", [] (ViewContext& self, DPoint2dArray const& pts, double zDepth, DPoint2dCP range, bool closed)
           {
           self.DrawStyledLineString2d((int) pts.size(), pts.data(), zDepth, range, closed);
           }, "pts"_a, "zDepth"_a, "range"_a, "closed"_a = false, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledLineString2d));

    c6.def("DrawStyledLineString2d", [] (ViewContext& self, py::list const& pts, double zDepth, DPoint2dCP range, bool closed)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(pts, cppPts, DPoint2dArray, DPoint2d);
           self.DrawStyledLineString2d((int) cppPts.size(), cppPts.data(), zDepth, range, closed);
           }, "pts"_a, "zDepth"_a, "range"_a, "closed"_a = false, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledLineString2d));

    c6.def("DrawStyledLineString3d", [] (ViewContext& self, DPoint3dArray const& pts, DPoint3dCP range, bool closed)
           {
           self.DrawStyledLineString3d((int) pts.size(), pts.data(), range, closed);
           }, "pts"_a, "range"_a, "closed"_a = false, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledLineString3d));

    c6.def("DrawStyledLineString3d", [] (ViewContext& self, py::list const& pts, DPoint3dCP range, bool closed)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(pts, cppPts, DPoint3dArray, DPoint3d);
           self.DrawStyledLineString3d((int) cppPts.size(), cppPts.data(), range, closed);
           }, "pts"_a, "range"_a, "closed"_a = false, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledLineString3d));

    c6.def("DrawStyledArc2d", &ViewContext::DrawStyledArc2d, "ellipse"_a, "isEllipse"_a, "zDepth"_a, "range"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledArc2d));
    c6.def("DrawStyledArc3d", &ViewContext::DrawStyledArc3d, "ellipse"_a, "isEllipse"_a, "range"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledArc3d));
    c6.def("DrawStyledBSplineCurve2d", &ViewContext::DrawStyledBSplineCurve2d, "curve"_a, "zDepth"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledBSplineCurve2d));
    c6.def("DrawStyledBSplineCurve3d", &ViewContext::DrawStyledBSplineCurve3d, "curve"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledBSplineCurve3d));
    c6.def("DrawStyledCurveVector3d", &ViewContext::DrawStyledCurveVector3d, "curve"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledCurveVector3d));
    c6.def("DrawStyledCurveVector2d", &ViewContext::DrawStyledCurveVector2d, "curve"_a, "zDepth"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawStyledCurveVector2d));
    c6.def("DrawScanRange", &ViewContext::DrawScanRange, "range"_a, "is3d"_a, "color"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawScanRange));
    c6.def("DrawTextString", &ViewContext::DrawTextString, "textString"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawTextString));
    c6.def("DrawTextBlock", py::overload_cast<TextBlockCR>(&ViewContext::DrawTextBlock), "textBlock"_a, DOC(Bentley, DgnPlatform, ViewContext, DrawTextBlock));
    c6.def("CheckStop", &ViewContext::CheckStop, DOC(Bentley, DgnPlatform, ViewContext, CheckStop));

    }