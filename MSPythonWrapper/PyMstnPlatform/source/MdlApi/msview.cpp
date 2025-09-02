/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msview.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msview.fdf>
#include <Mstn/MdlApi/view.h>
#include "CallbackHelper.h"

static const char *__doc_mdlView_defaultCursor = R"doc(@Description Cancel any special cursor behavior for MicroStation views
and return to the default crosshair cursor.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";
static const char *__doc_mdlView_fit = R"doc(@Description Scan the list of models indicated by modelRefList to set
the display extents of view viewNumber to fit all found elements.
@Param[in] viewNumber designates which view to fit (starting with 0
for the view labeled View 1). @Param[in] modelRefList contains the
list of models to include in the view. @Remarks After calling
mdlView_fit, you must update the view to see the changed view extents
using MstnView.updateSingle. @Return SUCCESS if the view extents were
modified, MDLERR_BADVIEWNUMBER if viewNumber is invalid, and ERROR if
no elements were found and the view extents were not modified.

See also:
    MstnView.updateSingle

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_fitEx = R"doc(@Description Extended version of MstnView.fit. @Param[in] viewNumber
designates which view to fit (starting with 0 for the view labeled
View 1). @Param[in] modelRefList contains the list of models to
include in the view. @Param[in] doRasterRefFit if true, include raster
references in fit calculations. @Param[in] options the FitViewOptions
to apply to the view @Remarks After calling MstnView.fitEx, you must
update the view to see the changed view extents using
mdlView_updateSingle. @Return SUCCESS if the view extents were
modified, MDLERR_BADVIEWNUMBER if viewNumber is invalid, and ERROR if
no elements were found and the view extents were not modified.

See also:
    MstnView.updateSingle
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_isModelActive = R"doc(@Description Determine whether the model displayed in the specified
view window is the currently active model. @Param[in] viewIndex the
view number for which the displayed model is found and tested against
the currently active model. @Return true if the model is active model.

See also:
    MstnView.setModel
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_is3d = R"doc(Parameter ``viewNum``:
    view to test. @Return true if the view is active and its root
    model is 3d.
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getRootModel = R"doc(@Description Get the DgnModelRefP of the root model that is currently
displayed in a specific view. @Param[in] viewIndex the view number for
which the model number is returned. @Return the DgnModelRefP of the
root model for this view. NULL if the view is invalid or not
displayed.

See also:
    MstnView.setModel
   

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setModel = R"doc(@Description Set the given view's model ID. @Param[in] modelRef model
ref to apply @Param[in] viewIndex index of view @Return SUCCESS if the
model is found, ERROR otherwise.
    

Bentley Systems +-----------------------------------------------------
-----------------)doc";

static const char *__doc_mdlView_getCamera = R"doc(@Description Get the camera settings for a view. <p>All settings other
than viewNumber are returned in the current coordinate system. If any
settings are NULL, MicroStation does not fill them in. @Param[out]
position a Dpoint3d to receive the camera position. @Param[out] target
a Dpoint3d to receive the camera target. @Param[out] angle a double to
contain the camera field of vision angle in degrees. @Param[out]
focalLength alternative way to express the camera angle in parameters
that correspond to the standard 35 millimeter camera. focalLength
points to a double to contain the focal length in millimeters.
@Param[out] lensNumber an integer specifying standard 35 mm lense
@Param[in] view index of view @Remarks MicroStation allows 3D design
files to be viewed using either a parallel (orthographic) or
perspective projection. The perspective projection mimics a physical
camera in which light rays pass through a lens, converge at a focal
point and focus on an image plane. The distance from the camera to the
image plane is referred to as the focal length. @Remarks In
orthographic (non-camera) views, the view is specified by a
transformation matrix to the view coordinate system and a rectangular
clipping volume. In camera views, the view volume is a pyramid with
the apex at the camera and the cross section increasing with distance
from the camera. In specifying a camera view, it is more convenient to
think in terms of the camera location, orientation, focal length and
fore and aft clipping planes. Camera views are derived from the view
settings, the camera position, and the camera focal length in the
following manner: The view transformation matrix specifies the camera
orientation; the virtual camera points along the negative view Z-axis;
the camera X and Y axis coincide with view axes. The front and back
clipping planes are identical to the clipping planes for an
orthographic view, and the camera image plane is parallel to the view
and is offset from the camera position by the focal length. The
portion of the image displayed is determined by the intersection of
the orthographic view volume with the camera image plane. @Remarks
Several important aspects of MicroStation's camera views should be
noted: <p> Obviously, it is not possible to display items that are
behind the camera,and items that are very close to the camera also
cause problems as they end up being magnified excessively.
MicroStation therefore truncates views at a fixed fraction of the
focal length (approximately 1/50), effectively ignoring the tip of the
viewing pyramid. @Remarks Unlike most conventional cameras, the camera
location is not necessarily centered in the view. This makes it
possible to set the camera position and then "pan" within the image.
MicroStation's window, pan and zoom commands do not alter the camera
settings, instead altering only the view settings to control the
portion of the image plane being displayed. This is analogous to
taking a picture and then panning, zooming or windowing within the
photograph. This makes it possible to simulate the output of a bellows
camera by selecting a camera position that produces the desired
perspective and then windowing to the desired portion of the image
plane. @Remarks If the camera position has never been set, the camera
information is invalidated by initializing the focal length to -1. If
a negative focal length is encountered when a camera view is updated,
a camera position centered in the view with the image plane centered
between the front and back clipping planes is calculated
automatically. When the FIT command is executed, the current camera
position is invalidated by negating the focal length and the update
automatically re-centers the camera. @Remarks The camera viewing
volume does not coincide with orthographic viewing volume. The viewing
area coincides at the image plane only, with the camera viewing area
smaller than the orthographic view area at depths in front of the
image plane and larger at depths beyond the image plane. @Remarks The
camera lens angle is stored for each view, but is not necessary for
the camera specification and is never used during an update. The angle
is used for automatically calculating the focal length from the view
extents when a camera view is first updated or the SET CAMERA command
is executed. @Return SUCCESS if the requested information is valid,
MDLERR_BADVIEWNUMBER if viewNumber is invalid, and
MDLERR_VIEWNOTDISPLAYED if the view is not displayed.
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getParameters = R"doc(@Description Get the view settings for a view. <p>All settings other
than viewNumber are returned in the current coordinate system. If any
settings are NULL, MicroStation does not fill them in. @Param[out]
origin a Dpoint3d to receive the view's origin. The view origin is the
point on the back clipping plane's lower left corner. @Param[out]
center a Dpoint3d to receive the view's center, which is the center of
the volume contained by the front and back clipping planes.
@Param[out] delta a Dpoint3d to receive the size of the view in the
view's X, Y and Z directions. @Param[out] rMatrix a RotMatrix to
receive the view's rotation matrix. @Param[out] activeZ a double to
receive the active depth. Active depth is defined as the positive
distance from the back clipping plane to the active depth plane.
@Param[in] view view number of interest. @Return SUCCESS if the
information requested is valid. MDLERR_BADVIEWNUMBER is returned if
viewNumber is invalid (not in the range 0-7). MDLERR_VIEWNOTDISPLAYED
if viewNumber is valid, but the view is not currently displayed.


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getParametersWithExpandedDepth = R"doc(@Description Identical to MstnView.getParameters, excep that it has an
additional argument that will optionally expand the depth for a 3D
view with front or back clipping turned off to encompass all of the
geometry in the view. <p>All settings other than viewNumber are
returned in the current coordinate system. If any settings are NULL,
MicroStation does not fill them in. @Param[out] origin a Dpoint3d to
receive the view's origin. The view origin is the point on the back
clipping plane's lower left corner. @Param[out] center a Dpoint3d to
receive the view's center, which is the center of the volume contained
by the front and back clipping planes. @Param[out] delta a Dpoint3d to
receive the size of the view in the view's X, Y and Z directions.
@Param[out] rMatrix a RotMatrix to receive the view's rotation matrix.
@Param[out] activeZ a double to receive the active depth. Active depth
is defined as the positive distance from the back clipping plane to
the active depth plane. @Param[in] view view number of interest.
@Param[in] expandDepth if true and the the front and back clipping is
disabled, then the origin and delta are expanded to include the
geometry. @Return SUCCESS if the information requested is valid.
MDLERR_BADVIEWNUMBER is returned if viewNumber is invalid (not in the
range 0-7). MDLERR_VIEWNOTDISPLAYED if viewNumber is valid, but the
view is not currently displayed.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getStandard2 = R"doc(@Description Get one of the standard rotation matrices, relative to
the active coordinate system of the specified model. @Param[out]
rMatrixP rotation matrix for given view @Param[in] stdViewNum standard
view number. Possible values are defined in msdefs.h. For example,
StandardView::Top, StandardView::Bottom, etc. @Param modelRef in model
from which to get the ACS @Return SUCCESS if the matrix is acquired
and ERROR otherwise.

See also:
    MstnView.getStandard MstnView.isStandard MstnView.isStandard2

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getStandard = R"doc(@Description Get one of the standard rotation matrices. @Param[out]
rMatrixP rotation matrix for given view @Param[in] stdViewNum standard
view number. Possible values are defined in msdefs.h. For example,
StandardView::Top, StandardView::Bottom, etc.

See also:
    MstnView.getStandard2 MstnView.isStandard MstnView.isStandard2

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getStandardCameraLens = R"doc(@Description Return the camera angle and focal length for the standard
camera lenses supported by MicroStation. The standard lens is
specified by lensNumber in the following manner:

```
0 20    FishEye
1 28    ExtraWide
2 35    Wide
3 50    Normal
4 85    Portrait
5 200   Telephoto
6 1000  Telescopic
```

@Param[out] angle lens angle in radians. @Param[out] focalLength focal
length of lens (mm). @Param[in] lensNumber standard lens number.
@Return SUCCESS if a valid lensNumber is specified and ERROR
otherwise.

See also:
    MstnView.setCameraLens MstnView.getCamera


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_isActive = R"doc(@Description Determine whether a view is "active" (turned on).
@Param[in] viewNumber view to check @Return true if the view is on. If
viewNumber is invalid, this routime will return false.
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_isVisible = R"doc(@Description Determine whether a view is visible. Views will always be
"visible" if they are turned on, so this function and MstnView.isActive
will always return the same value. The distinction is historical, and
they are both maintained for compatibility. @Param[in] viewNumber view
to check @Return true if the view is on. If viewNumber is invalid,
this routime will return false.
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_isStandard = R"doc(@Description Determine whether a rotation matrix matches a standard
view rotation matrix. This function helps identify whether a view is
currently displaying a standard view. @Param[in] trans rotation matrix
to test @Return The standard view number defined in msdefs.h or -1 if
trans does not match a standard view.

See also:
    MstnView.getStandard

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_rotateToRMatrix = R"doc(@Description Rotate a view to the rotation matrix given by rMatrix.
@Param[in] rMatrix rotation matrix @Param[in] view view to rotate
@Remarks The view is rotated around its center point and the view
extents are unchanged. @Remarks After MstnView.rotateToRMatrix is
called, the view needs to be updated with MstnView.updateSingle so the
changed view extents can be seen. @Return SUCCESS if the view is
changed, MDLERR_BADVIEWNUMBER if viewNumber is invalid, and
MDLERR_VIEWNOTDISPLAYED if the view is not currently displayed.

See also:
    MstnView.updateSingle

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setActiveDepth = R"doc(@Description Change the active depth for a view. The parameters are
given in the current coordinate system. @Param[in] viewNumber view to
set active depth @Param[in] depth active depth distance. This value is
a distance from the back clipping plane. It must be greater than zero
and less than the current display depth. @Return SUCCESS if the active
depth plane is changed, MDLERR_BADVIEWNUMBER if viewNumber is invalid,
and MDLERR_VIEWNOTDISPLAYED if the view is not currently displayed.

See also:
    MstnView.setDisplayDepth MstnView.setActiveDepthPoint


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setActiveDepthPoint = R"doc(@Description Change the active depth for a view using a point on the
new active depth plane. @Param[in] viewNumber view to set active depth
@Param[in] points point on active depth plane. @Return SUCCESS if the
active depth plane is changed, MDLERR_BADVIEWNUMBER if viewNumber is
invalid, and MDLERR_VIEWNOTDISPLAYED if the view is not currently
displayed.

See also:
    MstnView.setDisplayDepthmdl MstnView.setActiveDepth

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setArea = R"doc(@Description Set the viewing area for a view. All parameters are in
the current coordinate system. @Param[in] viewNumber the view number
to change. @Param[in] pt an array of two points that, combined with
the rotation matrix rMatrix, define the viewing rectangle.
MicroStation adjusts the rectangle to match the view's actual aspect
ratio. @Param[in] zOrg a point that lies on the view's back clipping
plane. If zOrigin is NULL, MicroStation uses (0, 0, 0) in the current
coordinate system. @Param[in] zDelta the distance from the back
clipping plane to the front clipping plane. zDelta must be greater
than zero. @Param[in] actZdepth the distance from the back clipping
plane to the view's active depth. actZDepth must be greater than zero
and less than zDelta. @Param[in] rotMatrix the view's rotation. If
rMatrix is NULL, MicroStation uses the identity matrix (top view).
@Remarks After calling this function, you need to update the view to
see the changed view extents using MstnView.updateSingle. @Return
SUCCESS if the viewing area is set, MDLERR_BADVIEWNUMBER if viewNumber
is invalid, and MDLERR_VIEWNOTDISPLAYED if the view is not currently
displayed.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setCameraLens = R"doc(@Description Set the camera lens angle for a view. @Param[in] angle
lens angle in radians. @Param[in] view view number. @Return SUCCESS if
the lens angle is set successfully and an appropriate error status
otherwise.

See also:
    MstnView.getStandardCameraLens MstnView.getCamera

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getDisplayControl = R"doc(@Description Get view display control attributes. @Param[in] paramNum
specifies the view attribute is get. Any of the VIEWCONTROL_ values in
mdl.h @Param[in] viewNum specifies the view. @Return The value of the
parameter specified by paramNum or false if paramNum or viewNum are
invalid. Use MstnView.isValidIndex to test the view index. Valid
paramNum values are in the range [0..MAX_VIEWCONTROL].

See also:
    MstnView.setDisplayControl
    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setDisplayControl = R"doc(@Description Set view display control attributes. @Param[in] paramNum
number of attribute to set. Any of the VIEWCONTROL_ values in mdl.h
@Param[in] viewNum view number @Param[in] value new value to set view
attribute to. @Return MDLERR_BADVIEWNUMBER if viewNum is invalid,
MDLERR_BADARG for invalid paramNum, ERROR for general failure, or
SUCCESS if operation completes. Use MstnView.isValidIndex to test the
view index. Valid paramNum values are in the range
[0..MAX_VIEWCONTROL].

See also:
    MstnView.getDisplayControl

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setDisplayDepth = R"doc(@Description Change the front and back clipping planes for a view. All
parameters are given in the current coordinate system. @Param[in]
viewNumber view to set display depth. @Param[in] frontDepth front
display depth @Param[in] backDepth back display depth @Remarks
<code>frontDepth</code> and <code>backDepth</code> to define the
positions of the front and back clipping planes. These values are
signed distances from the <i>current</i> front clipping plane.
@Remarks After this function is called, the view needs to be updated
with MstnView.updateSingle, so the changed clipping planes can be seen.
@Return SUCCESS if the view clipping planes are changed,
MDLERR_BADVIEWNUMBER if viewNumber is invalid, and
MDLERR_VIEWNOTDISPLAYED if the view is not currently displayed.

See also:
    MstnView.updateSingle

See also:
    MstnView.setDisplayDepthPoints


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setDisplayDepthPoints = R"doc(@Description Change the front and back clipping planes for a view
using two points. @Param[in] viewNumber the index of the view being
changed. @Param[in] points an array of two points that define the
clipping planes. @Remarks After this function is called, the view
needs to be updated with MstnView.updateSingle, so the changed clipping
planes can be seen. @Return SUCCESS if the view clipping planes are
changed, MDLERR_BADVIEWNUMBER if viewNumber is invalid, and
MDLERR_VIEWNOTDISPLAYED if the view is not currently displayed.

See also:
    MstnView.updateSingle

See also:
    MstnView.setDisplayDepth

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setPopupMenu = R"doc(@Description Set the menu that pops up when the user presses
&lt;shift-reset&gt; inside a MicroStation view. The view popup can be
used for quick access to command-specific options or parameters. The
view popup is automatically reset to the default MicroStation popup
whenever mdlState_startPrimitive is called. @Param[in] menuType the
resource type for the menu. If menuType is 0 it defaults to
RTYPE_PulldownMenu. @Param[in] menuId the resource ID for the popup
menu. @Param[in] ownerMD MDL taskid of the owner of the menu. This
parameter is usually NULL, meaning the the current task. @Return A
pointer to the installed popup menu, or NULL if it fails to find the
desired menu.

See also:
    mdlState_startPrimitiveAndSetPopupMenu


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_synchWithTCB = R"doc(@Description Synchronizes the private view information that
MicroStation maintains separately for each view with the "public" view
information that is maintained in the TCB. The reason that the private
information is separated from the TCB information is that the private
information reflects what is currently drawn on the screen. Elements
will be undrawn in the same mode in which they were originally drawn,
regardless of the current drawing mode. <p>For example, suppose that
the state of the Fast Text Display is on when an element is originally
drawn, and the user subsequently turns Fast Text Display off for a
particular view and does not immediately update. Those text elements
will be undrawn in Fast display mode until the next update. An
application can override this normal behavior using
mdlView_synchWithTCB. This allows an application to specify a draw
mode in the TCB, and force MicroStation to immediately adopt this draw
mode for the given view. @Param[in] viewNumber view to synchronize
with the TCB.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_turnOff = R"doc(@Description Turn off a MicroStation view. @Param[in] viewNumber view
to turn off @Return The MstnView.turnOff function returns SUCCESS if
the view is turned off, MDLERR_BADVIEWNUMBER if viewNumber is invalid,
and MDLERR_VIEWNOTDISPLAYED if the view is not currently displayed.

 See also:
    MstnView.turnOn Bentley Systems +---------------+---------------+--
    -------------+---------------+---------------+------)doc";

static const char *__doc_mdlView_turnOn = R"doc(@Description Turn on a MicroStation View using the current view
parameters. The function does not return until the view is initially
painted. @Param[in] viewNumber view to turn on @Return SUCCESS if the
view is turned on (or already on) and MDLERR_BADVIEWNUMBER if
viewNumber is invalid.

See also:
    MstnView.turnOff

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_reopen = R"doc(@Description Close and reopen the view specified by viewNumber. This
function is equivalent to calling MstnView.turnOff followed by
mdlView_turnOn, except that the stacking order of views maintained.
@Param[in] viewNumber view to reopen @Return SUCCESS or
MDLERR_BADVIEWNUMBER if viewNumber is invalid.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_updateMulti = R"doc(@Description Update one or more views. @Param[in] viewDraw views to
update. Should be dimensioned to DgnPlatform::MAX_VIEWS, and
viewDraw[i] controls whether view i is drawn. @Param[in] incremental
incremental update (meaning, don't erase before drawing). @Param[in]
drawMode possible values are DRAW_MODE_Normal, ERASE and HILITE. These
values draw the elements normally, erase elements from the screen, and
highlight elements, respectively. @Param[in] modelRefList a list of
the models to include in the view(s). If modelRefList is NULL, the
master and all references are included. @Param[in] startEndMsg if
true, MicroStation displays the "Update in progress" and "Display
complete" messages before and after the update.

This function returns only after the entire view displays.


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_updateMultiEx = R"doc(@Description Update one or more views. @Param[in] viewDraw views to
update. Should be dimensioned to DgnPlatform::MAX_VIEWS, and
viewDraw[i] controls whether view i is drawn. @Param[in] incremental
incremental update (meaning, don't erase before drawing). @Param[in]
drawMode possible values are DRAW_MODE_Normal, ERASE and HILITE. These
values draw the elements normally, erase elements from the screen, and
highlight elements, respectively. @Param[in] modelRefList a list of
the models to include in the view(s). If modelRefList is NULL, the
master and all references are included. @Param[in] startEndMsg if
true, MicroStation displays the "Update in progress" and "Display
complete" messages before and after the update. @Param[in] updateTitle
if true, will update window title

This function returns only after the entire view displays.
   

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_updateSingle = R"doc(@Description Update a single view. @Param[in] viewNumber the view
number to update. @Remarks This function often needs to be called
after a view's settings are changed. @Return MstnView.updateSingle
returns SUCCESS if the view is updated, MDLERR_BADVIEWNUMBER if
viewNumber is invalid, and MDLERR_VIEWNOTDISPLAYED if the view is not
currently displayed.

This function returns only after the entire view displays.

See also:
    MstnView.updateMulti MstnView.renderSingle

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_zoom = R"doc(@Description Change a view's viewing extents. @Param[in] outView view
to change parameters @Param[in] inView view to get parameters from
(can be the same as outView). @Param[in] centerPoint point to zoom
about @Param[in] zoomFactor zoom ratio; if it is greater than 1.0, the
effect is to zoom out. If zoomFactor is less than 1.0, the effect is
to zoom in. A zoomFactor of 1.0 can be used to center the window.
@Remarks inView and outView can be the same. @Remarks After calling
this function, you need to update the view to see the changed view
extents using MstnView.updateSingle. @Return SUCCESS if the view
extents are changed and MDLERR_BADVIEWNUMBER or
MDLERR_VIEWNOTDISPLAYED if inViewNumber or outViewNumber is invalid or
not displayed.

See also:
    MstnView.updateSingle

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_pointToScreen = R"doc(@Description Calculate a screen position for an input point.
@Param[out] screenPointP a Point2d structure that will hold the output
point on return from the function. (Note: The point returned may be
outside the range that can be displayed in the indicated view,
depending on the input point and the area visible in the view.)
@Param[in] uorPointP the point (in the current coordinate system) for
which screen coordinates are desired. @Param[in] viewNumber view for
screenPointP @Param[in] coordinateSystem must be set to either
DgnCoordSystem::Screen (local) or DgnCoordSystem::View (global). If
DgnCoordSystem::View, screenPointP is relative to the upper left
corner of the window, and if DgnCoordSystem::Screen, screenPointP is
relative to the upper left corner of the screen. In both cases x
increases to the right and y increases down the window. @Return
SUCCESS if the input parameters are valid, MDLERR_BADVIEWNUMBER if
viewIndex is not between 0 and DgnPlatform::MAX_VIEWS, or
MDLERR_VIEWNOTDISPLAYED if the view is not currently displayed.

See also:
    MstnView.screenToPoint

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_screenToPoint = R"doc(@Description Calculates the world coordinates given a point on the
screen. The output is in the current coordinate system. @Param[out]
uorPointP output point (in the current coordinate system) @Param[in]
screenPointP point for in screen coordinates @Param[in] viewNumber
view for screenPointP @Param[in] coordSystem either
DgnCoordSystem::View or DgnCoordSystem::Screen. If
DgnCoordSystem::View, screenPointP is relative to the upper left
corner of the window, with x increasing to the right and y increasing
down the window. If VIEW_INGLOBALCOORDS, screenPointP is relative to
the upper left corner of the screen. @Return SUCCESS if the input
parameters are valid, MDLERR_BADVIEWNUMBER if viewIndex is not between
0 and DgnPlatform::MAX_VIEWS, or MDLERR_VIEWNOTDISPLAYED if the view
is not currently displayed.

See also:
    MstnView.pointToScreen

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getViewRectangle = R"doc(@Description Get the screen area taken up by a view. This does not
include the area used for scrollbars and view control icons. Use
mdlWindow_contentRectGetLocal to get the size of the entire view
window. @Param[out] viewRectP view rectangle. @Param[in] windowP view
window. To get an MSWindow from a view number, use
mdlWindow_viewWindowGet. @Param[in] coordSystem Currently, the only
valid argument is VIEW_GLOBALCOORDS.

See also:
    mdlWindow_contentRectGetLocal mdlWindow_viewWindowGet

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_queuePartialUpdate = R"doc(@Description Update one or more subparts of a MicroStation view.
@Param[in] viewNumber view for which portions are to be updated.
@Param[in] rectsP array of rectangles for which updates are to be
performed. They must be in global coordinates (i.e., relative to the
upper left of the screen). @Param[in] numRects the number of
rectangles in the rectsP array. The maximum number of rectangles is
15. @Remarks If the application wants the updates to happen
immediately, the

 
    s mdlWindow_windowEventsProcessAll should be called following
    MstnView.queuePartialUpdate. @Return SUCCESS if the input
    parameters are valid, MDLERR_BADVIEWNUMBER if viewIndex is not
    between 0 and DgnPlatform::MAX_VIEWS, or MDLERR_VIEWNOTDISPLAYED
    if the view is not currently displayed.

See also:
    MstnView.updateSingle MstnView.updateMulti
    MstnView.updateMultiExtended


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_newWindowCenter = R"doc(@Description Set a new window center without changing the orientation
or scale of the view. @Param[in] viewNumber view for which the new
view center is to be applied. @Param[in] newCenterP new view center
(in current coordinate system). @Return SUCCESS if the input
parameters are valid, MDLERR_BADVIEWNUMBER if viewIndex is not between
0 and DgnPlatform::MAX_VIEWS, or MDLERR_VIEWNOTDISPLAYED if the view
is not currently displayed.

See also:
    MstnView.setArea MstnView.zoom MstnView.rotateToRMatrix

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_pan = R"doc(@Description Move a view by a specified number of pixels, relative to
it's current location. @Param[in] distance distance to pan, in pixels.
@Param[in] viewNumber view to pan @Param[in] doUpdate if true, update
the view after pan.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_indexFromWindow = R"doc(@Description Get the view number from a pointer to the MSWindow of the
view. @Param[in] window pointer to a view of type MSWindow. @Return
view Number from 0 and DgnPlatform::MAX_VIEWS if window is an MSWindow
pointer that points to a view window, and -1 otherwise.


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setCameraParameters = R"doc(@Description Set the camera parameters for a view. Since the camera
parameters are not independent, it is possible to omit many of the
camera parameter arguments. If NULL is passed for an argument, it is
defaulted to the existing value or calculated from the other
parameters as described below. @Param[in] positionP the position of
the camera. @Param[in] targetP the point at which the camera is aimed
@Param[in] upVectorP a vector that sets the y-axis for the camera view
@Param[in] angleP the camera field of view angle. The camera angle can
be derived from the maximum of the view width and height and the
distance from the camera to the image plane. If NULL is passed, the
camera angle is unchanged. @Param[in] aspectRatioP the view aspect
ratio. This represents the view height divided by the view width. If
NULL is passed, the aspect ratio of the view window is used.
@Param[in] screenWindowP defines the portion of the image plane that
is displayed. The screen window coordinates are defined in an image
plane coordinate system with an origin at the camera target. For a
centered view, the screen window coordinates will be (-width/2,
-height/2) (width/2, height/2). This corresponds the design of most
modern cameras as the viewing direction is perpendicular to the camera
plane. In an uncentered window, the image plane is tilted in relation
to the viewing direction. This corresponds to a view, or bellows
camera. If NULL is passed a centered window is calculated with the
size derived from the view angle and distance to the image plane.
@Param[in] frontClipDist the distance from the camera to the front
clipping plane. If NULL is passed for frontClipDist, the front
clipping distance is arbitrarily set to the target distance divided by
300. @Param[in] backClipDist The distance from the camera to the back
clipping plane. If NULL is passed for backClipDist, the back clipping
distance is set to the ten times the target distance. @Param[in] view
the index of the view for which the camera is being set. @Return
mdlView_setCameraParameters returns SUCCESS if the view is
successfully defined. @Remarks The camera position is specified by
positionP, the camera target is specified by targetP. If NULL is
passed for either of these parameters, the camera position or target
is unchanged. The camera direction is always from positionP towards
targetP, this coincides with the negative Z-Axis for the view.
MicroStation's image plane is always coincident with the camera
target, therefore, the target appears the same size in a camera
(perspective) or non-camera (orthographic) view. @Remarks The view
rotation about the camera axis is determined by upVectorP, this is a
normalized direction vector that defines the y-axis for the view. It
is always perpendicular to the camera axis. If NULL is passed for
upVectorP, the camera will be oriented such that the camera horizontal
is parallel to the view X-Y plane. @Remarks The camera field of view
angle (in radians) is specified by angleP. If NULL is passed, the
camera angle is unchanged. The camera angle can be derived from the
maximum of the view width and height and the distance from the camera
to the target in the following manner: cameraAngle = 2 *
arctan(maxDimension/(2*targetDistance));

See also:
    MstnView.setCameraParameters

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_cameraLensLengthFromAngle = R"doc(@Description Get the length in millimeters of a camera lens that
corresponds to the specified field of vision angle in degrees. This
length is useful to users who relate to lens lengths rather than
angles. @Param[in] angle angle (degrees) @Return the camera lens focal
length in millimeters that yields the specified field of vision in
degrees

See also:
    MstnView.setCameraParameters

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_cameraLensAngleFromLength = R"doc(@Description Get the angle of the field of vision in degrees for a
camera lens of the specified focal length in millimeters. @Param[in]
focalLength length (mm) @Return the field of vision angle in degrees

See also:
    MstnView.setCameraParameters

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_computeCameraRotMatrix = R"doc(@Description Compute the rotation matrix of the camera for the view.
@Param[out] rotMatrix the computed rotation matrix @Param[in] viewZ
the Z axis of the view @Param[in] upVector the up vector for the
camera @Return SUCCESS if the rotation matrix was calculated
successfully.

See also:
    MstnView.setCameraParameters Bentley Systems +---------------+-----
    ----------+---------------+---------------+---------------+------)doc";

static const char *__doc_mdlView_getCameraParameters = R"doc(@Description Get the camera parameters for a view. If any of the
parameters are not required, NULL may be specified for the parameter
pointer. @Param[out] positionP the camera position. @Param[out]
targetP the target position. @Param[out] upVectorP is always
perpendicular to the camera axis. @Param[out] angleP camera field of
view angle (in radians). @Param[out] screenWindowP portion of the
image plane that is displayed. @Param[out] frontClipDist distance from
the camera to the front of the clipping plane @Param[out] backClipDist
distance from the camera to the back of the clipping plane @Param[in]
view view number @Return SUCCESS if the view is successfully defined.

 
    s The camera direction is always from positionP towards targetP,
    which coincides with the negative Z-Axis for the view.
    MicroStation's image plane is always coincident with the camera
    target. Therefore, the target appears the same size in a camera
    (perspective) or non-camera (orthographic) view.

 
    s The view rotation about the camera axis is determined by
    upVectorP. This is a normalized direction vector that defines the
    y-axis for the view.

 
    s The camera angle can be derived from the maximum of the view
    width and height and the distance from the camera to the target in
    the following manner: cameraAngle = 2 *
    arctan(maxDimension/(2*targetDistance));

 
    s The screen window coordinates are defined in an image plane
    coordinate system with an origin at the camera target. For a
    centered view, the screen window coordinates will be (-width/2,
    -height/2) (width/2, height/2). This corresponds the design of
    most modern cameras as the viewing direction is perpendicular to
    the camera plane. In an uncentered window, the image plane is
    tilted in relation to the viewing direction. This corresponds to a
    view, or bellows camera.

See also:
    MstnView.setCameraParameters

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getHomogeneousMaps = R"doc(@Description Retrieve various homogeneous maps for a MicroStation view
transform. Any combination of the return parameters may be NULL.
@Param[out] worldEye the eyepoint as a homogeneous point in world
coordinates, i.e. 0 weight if flat view. @Param[out] viewEye the
eyepoint as a homogeneous point in the view frame. @Param[out]
worldToViewMap an invertible map from world coordinates to the local
frame on the view plane. @Param[out] worldToNPCMap an invertible map
from world coordinates to the 01 cube of the view. @Param[out]
worldToFocalPlane a (singular) matrix which collapses geometry from
world coordinates to the focal plane. @Param[out] viewToFocalPlane a
(singular) matrix which collapses geometry in the viewplane coordinate
frame onto the view plane. @Param[out] focalLength the focal length.
Its value is 0 if the view is flat. @Param[out] nPCFocalPlaneDepth the
depth of the focal plane within the NPC box. @Param[in] viewNumber
view the information is retrieved from. @Return SUCCESS if the
operation is completed successfully, otherwise ERROR.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getLevelDisplayMask = R"doc(@Description Get the level-mask for a model and view number. The
level-mask is returned in the form of a bit-mask. It represents if a
level is ON/OFF in the specified view. @Param[in] modelRef model
@Param[in] iViewNum view number @Param[in] levelDisplayType one of
VIEW_LEVEL_DISPLAY_TYPE_... (defined in msdefs.h)

Returns:
    The display mask as a BitMask. Returns NULL if pModelRef or view
    number is invalid. @Remarks The value of "levelDisplayType" can be
    one of ViewLevelDisplayType::Normal or
    ViewLevelDisplayType::Effective. ViewLevelDisplayType::Normal
    refers to the level-display associated with an individual view.
    This value can be either ON or OFF. If this value is OFF, then
    elements on the level will not be visible in the view. If this
    value is ON, then elements on the level may be visible in the
    view, depending on the state of the global-display and global-
    freeze flags for the level. Each level has a "global-display" and
    "global-freeze" flag. Refer to the documentation of level-
    attributes for more information on this. In summary, a level is
    visible in a view, if it is turned ON in the view, if its global-
    display flag is ON and its global-freeze flag is OFF. This
    effective state of a level is returned if "levelDisplayType" is
    set to ViewLevelDisplayType::Effective. @Remarks The bit-mask is 1
    based. For example to get the display flag for a level with the
    function mdlBitMask_testBit, your call should look like:
    mdlBitMask_testBit(pLevelDisplayBitMask, levelid -1) @Remarks Note
    the "const"ness of the returned bit-mask. It is important not to
    cast into a non-const bit-mask. This bit-mask should not be
    changed.

See also:
    MstnView.setLevelDisplayMask MstnView.getLevelDisplay
    MstnView.setLevelDisplay MstnView.changeLevelDisplay
    MstnView.setLevelDisplayMaskMulti
    MstnView.changeLevelDisplayMaskMulti


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setLevelDisplayMask = R"doc(@Description Set the level display mask for the specified model and
view. The level display mask is specified in the form of a bit-mask.
An ON value indicates that the corresponding level is to be turned on
in the view. An OFF value indicates that the corresponding level is to
be turned off in the view. Even if the bit-value is ON, that is no
guarentee that elements on the level will be displayed. Refer to
discussion in function MstnView.getLevelDisplayMask for more details.

@Param[in] modelRef model @Param[in] iViewNum view number @Param[in]
pViewLevelMask the view level bit-mask to be set. @Param[in] doUpdate
if ON, then redraw the view @Return SUCCESS if the operation is
completed successfully, otherwise ERROR.

@Remarks The bit-mask is 1 based. For example to set the display flag
for a level with the function mdlBitMask_setBit, your call should look
like: mdlBitMask_setBit(pLevelDisplayBitMask, levelid -1)

See also:
    MstnView.getLevelDisplayMask MstnView.getLevelDisplay
    MstnView.setLevelDisplay MstnView.changeLevelDisplay
    MstnView.setLevelDisplayMaskMulti
    MstnView.changeLevelDisplayMaskMulti

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_changeLevelDisplayMask = R"doc(@Description Change the level display for specified model and view.
The levels that are to be turned On, Off, or Toggled are specified in
the form of a bit-mask. @Param[in] modelRef model @Param[in] iViewNum
view number. @Param[in] levelMask bit-mask of levels whose display
mode is to be changed as per operation. @Param[in] operation indicates
whether levels specifed in levelMask are to be turned on, off, or
toggled. @Param[in] doUpdate If ON, then redraw the view. @Return
SUCCESS

See also:
    MstnView.setLevelDisplayMask MstnView.getLevelDisplayMask
    MstnView.getLevelDisplay MstnView.setLevelDisplay
    MstnView.setLevelDisplayMaskMulti
    MstnView.changeLevelDisplayMaskMulti


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setLevelDisplayMaskMulti = R"doc(@Description Set the level mask for multiple views from the given
level mask. This function works similar to
mdlView_setLevelDisplayMask, except that it applies the specified
level-mask to the list of specified views. @Param[in] modelRef model
@Param[in] viewList an array of DgnPlatform::MAX_VIEWS bool, each
representing a view. A non-zero value indicates that view is to be
updated from the BitMask given by pViewLevelMask. @Param[in]
viewLevelMask view level bit-mask to set. @Param[in] doUpdate IF ON,
then redraw the views. @Return SUCCESS if the operation is completed
successfully, otherwise ERROR.

See also:
    MstnView.setLevelDisplayMask MstnView.getLevelDisplayMask
    MstnView.getLevelDisplay MstnView.setLevelDisplay
    MstnView.changeLevelDisplay MstnView.changeLevelDisplayMaskMulti

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_changeLevelDisplayMaskMulti = R"doc(@Description Change the display flag. This functions similar to
mdlView_changeLevelDisplayMask, except that it applies the operation
to the levels of the list of specified views.

@Param[in] modelRef model @Param[in] viewList is an array of
DgnPlatform::MAX_VIEWS bool each representing a view. A non-zero value
indicates that view is to be updated from the BitMask given by
"pLevelMask". @Param[in] levelMask bit-mask of levels whose display
mode is to be changed as per operation @Param[in] operation indicates
whether levels specifed in levelMask are to be turned on, off, or
toggled. @Param[in] doUpdate if ON, then redraw the view. @Return
SUCCESS

See also:
    MstnView.setLevelDisplayMask MstnView.getLevelDisplayMask
    MstnView.getLevelDisplay MstnView.setLevelDisplay
    MstnView.changeLevelDisplay MstnView.setLevelDisplayMaskMulti

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getLevelDisplay = R"doc(@Description Determine whether a level is displayed in a view.
@Param[out] viewLevelDisplay true if the level display is on for the
given level in the given view, otherwise false. @Param[in] modelRef
the model containing the level. @Param[in] iViewNum the view number.
@Param[in] iLevelId the id of the level in question. @Param[in]
levelDisplayType one of VIEW_LEVEL_DISPLAY_TYPE_... (defined in
msdefs.h) @Return SUCCESS if the operation completed successfully,
otherwise ERROR.

@Remarks Refer to MstnView.getLevelDisplayMask to get more details on
"levelDisplayType".

See also:
    MstnView.setLevelDisplayMask MstnView.getLevelDisplayMask
    MstnView.setLevelDisplay MstnView.changeLevelDisplay
    MstnView.setLevelDisplayMaskMulti
    MstnView.changeLevelDisplayMaskMulti

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";


static const char *__doc_mdlView_setLevelDisplay = R"doc(@Description Set the display of a level in a view. @Param[in] modelRef
the model containing the level. @Param[in] iViewNum the view number.
@Param[in] iLevelId the id of the level. @Param[in] levelDisplay true
if level display is to be turned on, otherwise false. @Return SUCCESS
if the level flag was set successfully, otherwise ERROR.

See also:
    MstnView.getLevelDisplay

See also:
    MstnView.setLevelDisplayMask MstnView.getLevelDisplayMask
    MstnView.getLevelDisplay MstnView.changeLevelDisplay
    MstnView.setLevelDisplayMaskMulti
    MstnView.changeLevelDisplayMaskMulti Bentley Systems +-------------
    --+---------------+---------------+---------------+---------------
    +------)doc";

static const char *__doc_mdlView_getLevels = R"doc(@Description Get information about the levels that are on for the
master design file for a view. @Param[out] v7LevelMask An array of
short integers with one bit for each level and dimensioned to 4. The
lowest bit of v7LevelMask[0] is set to 1 if level 1 is on in the given
view and to 0 if level 1 is off. Similarly, bit 1 of v7LevelMask[0] is
set to the state of level 2. The highest bit (15) of v7LevelMask[3]
represents the state of the special level reserved for cell headers.
This bit is always on. @Param[in] iViewNumIn view to get information
from @Return SUCCESS if the level information for the specified view
is successfully retrieved, MDLERR_BADVIEWNUMBER if viewNumber is
invalid, and MDLERR_VIEWNOTDISPLAYED if the view is not currently
displayed.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_updateViewInfo = R"doc(@Description Update the global view information to match the data
passed to this function. @Param[in] viewInfoP the view information
with which the global view information will be updated. The view
number is contained within the view info information. @Return SUCCESS
if the operation is completed successfully, otherwise ERROR.

See also:
    MstnView.copyViewInfo


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";
static const char *__doc_mdlView_getMaxCount = R"doc(@Description Get the maximum number of views that can be opened by
MicroStation. @Return Maximum number of allowable views.

See also:
    MstnView.isValidIndex


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_isValidIndex = R"doc(@Description Test whether a value is a valid view index value.
@Param[in] index the index value to test for validity as a view index.
@Return true if the value is a valid view index, false otherwise.

See also:
    MstnView.getMaxCount

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getFlags = R"doc(@Description Get the view settings flags for a view. @Param[out]
viewFlags a copy of the DgnPlatform::ViewFlags structure for the
indicated view. @Param[in] viewIndex the view number for which the
flags information is retrieved. @Return SUCCESS if the information is
retireved successfully, otherwise ERROR.

See also:
    MstnView.setFlags


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setFlags = R"doc(@Description Set the view settings flags for a view. @Param[in]
viewFlags the DgnPlatform::ViewFlags structure holding the view flags
information from which the indicated view's settings will be updated.
@Param[in] viewIndex the view number indicating the view to set.
@Return SUCCESS if the flags on the indicated view are set, otherwise
ERROR.

See also:
    MstnView.getFlags

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_copyCamera = R"doc(@Description Retrieve a copy of the current camera information from
the specified view. @Param[out] cameraInfo the copied camera
information. @Param[in] index the view number from which the camera
information is copied. @Return SUCCESS if the camera information is
copied successfully, or MDLERR_BADVIEWNUMBER if the index number is
not a valid view number.

See also:
    MstnView.copyViewInfo

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_attachNamed = R"doc(@Description Search for a named view by its name and, if found, attach
the view to the indicated view. @Param[in] inName the name of the
named view element to be searched for. @Param[in] inNameSpace the name
space of the named view element to be searched for, using NULL will
cause the search to go against the user managed named views. Using a
value other than NULL allows applications to attach named views not
available to the user via the saved views application. @Param[in]
viewNumber the view number to which the found view will be attached.
@Return SUCCESS if the named view is found and attached,
MDLERR_OPERVIOLATESCONSTRAINTS if the view is found but incompletely
attached, otherwise ERROR.

See also:
    MstnView.setUpApplyOpts MstnView.attachNamedWithOptions

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setUpApplyOpts = R"doc(@Description Set initial values for viewport info options. @Param[in]
applyOptsP the ApplyViewOptions structure in which the value is set
@Param[in] type the type of the value to set (see view.h for
VIEW_APPLY_OPTS_* constants that can be used in this function)

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_attachNamedWithOptions = R"doc(@Description Search for a named view by its name and, if found, attach
the view to the indicated view using the given options. @Param[in]
inName the name of the named view element to be searched for.
@Param[in] inNameSpace the name space of the named view element to be
searched for, using NULL will cause the search to go against the user
managed named views. Using a value other than NULL allows applications
to attach named views not available to the user via the saved views
application. @Param[in] viewNumber the view number to which the found
view will be attached. @Param[in] applyOptsP NULL for default or the
options to use for the attach process. @Return SUCCESS if the named
view is found and attached, MDLERR_OPERVIOLATESCONSTRAINTS if the view
is found but incompletely attached, otherwise ERROR.

See also:
    MstnView.setUpApplyOpts MstnView.attachNamed

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_saveNamed = R"doc(@Description Save the current settings for one of the view windows to
a named view element using the given name and description. @Param[in]
viewNameP the name to be given to the named view element when it is
saved. @Param[in] descriptionP the description to be given to the
named view element when it is saved. @Param[in] viewNameSpace the name
space of the named view element. Using NULL will make this named view
available to management by the end user via the save views
application. Using a non-null value has the effect of making it a
protected named view, which is only accessed by the API. @Param[in]
view the view number to be saved as a named view element. @Return
SUCCESS if the view element is saved successfully, otherwise
MDLERR_BADARG if the view argument is not a valid view number.

See also:
    MstnView.saveNamedViewElement

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_deleteNamed = R"doc(@Description Find a named view element with the specified name and, if
found, delete it. @Param[in] inName the name of the view element to be
deleted. @Param[in] inNameSpace the name space of the named view
element to be searched for, using NULL will cause the search to go
against the user managed named views. Using a value other than NULL
allows applications to delete named views not available to the user
via the saved views application. @Return SUCCESS if the element is
found and deleted, otherwise ERROR.

See also:
    MstnView.findNamed

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_findNamed = R"doc(@Description Search for a named view of the specified name and, if
found, retrieve the view and viewport information from the view
element. @Param[out] viewInfoP the view information returned in a
DgnPlatform::ViewInfo structure. If this information is not needed,
pass NULL to the function in this argument. @Param[out] viewPortInfoP
the view port information returned in a DgnPlatform::ViewPortInfo
structure. @Param[in] viewName the name of the view to search for in
the master design file. @Param[in] viewNameSpace saved view name
space, NULL means public, user managed save views. @Return SUCCESS if
the element is found and the information is retrieved successfully,
otherwise ERROR.

See also:
    MstnView.locate MstnView.load

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getDefaultFlags = R"doc(@Description Set the flags in the given DgnPlatform::ViewFlags
structure to their default setting. @Param[out] viewFlagsP a
DgnPlatform::ViewFlags structure in which the flags will be set to
their default setting.

See also:
    MstnView.getFlags MstnView.setFlags

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_fitToFence = R"doc(@Description Fit the contents of the current fence in the specified
view. @Param[in] fencePtsP the array of points that are vertices of
the fence @Param[in] viewIndex the view in which the fence contents
are fit @Param[in] numPoints the number of points in the fence @Return
SUCCESS if the operation is completed successfully

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";


static const char *__doc_mdlView_fitViewToRange = R"doc(@Description Fit the contents of the specified range in the given
view. @Param[in] minP the minimum X Y and Z values of the range
@Param[in] maxP the maximum X Y and Z values of the range @Param[in]
optionsP the FitViewOptions to apply to the view when it is redrawn
@Param[in] viewIndex the index of the view to fit the specified range
block in

    Range points need to be in the view coordinate system, see
    mdlRMatrix_multiplyRange.

 
    Unlike many other view functions, this function expects points
    in design file coordinates, so apply the currtrans via
    mdlCurrTrans_transformPointArray. @Return SUCCESS if the view is
    redrawn without error.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_treatAs3D = R"doc(@Description Determine whether the specified view should be treated as
3D. @Param[in] viewIndex the index of the view to query @Return true
if the given view is 3D, false otherwise

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setClipBoundaryElement = R"doc(@Description Set the view's clip volume. @Param[in] viewIndex the
index of the view @Param[in] elementID the element ID of the clip
volume, use 0 to clear the clip volume @Remarks The referenced element
must exist in the active model. @Remarks It must be possible to
extract/generate a single, closed clip volume from the element,
otherwise setting the clip volume will fail. @Remarks Valid elements
include: closed curves, shapes, group holes, simple solids/surfaces,
and cylinders. @Return SUCCESS if the clip volume was set
      

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getClipBoundaryElement = R"doc(@Description Get the view's clip volume. @Param[out] pElementId the
element ID of the clip volume @Param[in] viewIndex the index of the
view @Return SUCCESS if the view had a clip volume set

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";


static const char *__doc_mdlView_setClipMaskElement = R"doc(@Description Set the view's clip mask. @Param[in] viewIndex the index
of the view @Param[in] elementID the element ID of the clip volume,
use 0 to clear the clip volume @Remarks The referenced element must
exist in the active model. @Remarks It must be possible to
extract/generate a single, closed clip mask from the element,
otherwise setting the clip mask will fail. @Remarks Valid elements
include: closed curves, shapes, group holes, simple solids/surfaces,
and cylinders. @Return SUCCESS if the clip mask was set
  

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getClipMaskElement = R"doc(@Description Get the view's clip volume. @Param[out] pElementId the
element ID of the clip mask @Param[in] viewIndex the index of the view
@Return SUCCESS if the view had a clip volume set

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getViewport = R"doc(@Description Get an DgnPlatform::Viewport by view index @Param[in]
viewIndex the index of the view @Return IMSViewportP, or NULL if
viewIndex not valid.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getToolBoxPath = R"doc(@Description Get a path to the view toolbox by view index and toolbox
index @Param[in] viewIndex the index of the view @Param[in]
toolBoxIndex the index of the toolbox @Param[in] b3D whether to
retrieve info about the 2D or 3D toolbox @Return path of the view
toolbox.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setToolBoxPath = R"doc(@Description Set the view toolbox based on path by view index and
toolbox index @Param[in] viewIndex the index of the view @Param[in]
toolBoxIndex the index of the toolbox @Param[in] b3D whether to set
info about the 2D or 3D toolbox @Param[in] pToolBoxPath the path of
the toolbox

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getToolBoxName = R"doc(@Description Get a name to the view toolbox by view index and toolbox
index @Param[in] viewIndex the index of the view @Param[in]
toolBoxIndex the index of the toolbox @Param[in] b3D whether to
retrieve info about the 2D or 3D toolbox @Return name of the view
toolbox.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setToolBoxName = R"doc(@Description Set the view toolbox based on name by view index and
toolbox index @Param[in] viewIndex the index of the view @Param[in]
toolBoxIndex the index of the toolbox @Param[in] b3D whether to set
info about the 2D or 3D toolbox @Param[in] pToolBoxName the name of
the toolbox


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getToolBoxId = R"doc(@Description Get a id to the view toolbox by view index and toolbox
index @Param[in] viewIndex the index of the view @Param[in]
toolBoxIndex the index of the toolbox @Param[in] b3D whether to
retrieve info about the 2D or 3D toolbox @Return id of the view
toolbox.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setToolBoxId = R"doc(@Description Set the view toolbox based on id by view index and
toolbox index @Param[in] viewIndex the index of the view @Param[in]
toolBoxIndex the index of the toolbox @Param[in] b3D whether to set
info about the 2D or 3D toolbox @Param[in] toolBoxId the id of the
toolbox

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_reloadToolBoxes = R"doc(@Description Reload the toolboxes for a given view based on view index
@Param[in] viewIndex the index of the view

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_getViewToolsDisplay = R"doc(@Description Get whether the view toolboxes are displayed for a given
view index @Param[in] viewIndex the index of the view @Return true if
the the view toolboxes are displayed.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_mdlView_setViewToolsDisplay = R"doc(@Description Set whether the view toolboxes are displayed for a given
view index. @Remarks This overrides userPrefsP->flags.viewToolsDisplay
on a per view basis. @Param[in] viewIndex the index of the view
@Param[in] display indicates whether the view toolboxes should display

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_ViewCallback_SetUpdatePreFunction = R"doc(@Description An MDL application can use this to set a function to be
called before a view updates. @Param[in] newFunc The new function to
call, or NULL. @Return The return value is the previous function that
was set for this MdlApp, or NULL.


Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_ViewCallback_SetUpdatePostFunction = R"doc(@Description An MDL application can use this to set a function to be
called after a view updates. @Param[in] newFunc The new function to
call, or NULL. @Return The return value is the previous function that
was set for this MdlApp, or NULL.

   

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_ViewCallback_SetMotionFunction = R"doc(@Description An MDL application can use this to set a function to be
called when the cursor moved in a view. @Param[in] newFunc The new
function to call, or NULL. @Return The return value is the previous
function that was set for this MdlApp, or NULL.

See also:
    SetMotionFunction.SetMotionFunction

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_ViewCallback_SetNoMotionFunction = R"doc(@Description An MDL application can use this to set a function to be
called when the cursor is stopped in a view. @Param[in] newFunc The
new function to call, or NULL. @Return The return value is the
previous function that was set for this MdlApp, or NULL.

See also:
    ViewCallback.SetMotionFunction    

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

static const char *__doc_ViewCallback_SetSubstituteElemFunction = R"doc(@Description Set or clear an "element substitution hook" to modify the
display of elements in MicroStation views. @Param[in] substFunc
function to become the new element substituion hook for this
application. If NULL, then any previous substituion hook is cleared.
@Return SUCCESS if the element substitution hook was set/cleared.
ERROR if the function pointer is invalid.

Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";


BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct MstnView {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

class ViewUpdateCallbackHelper {
public:
    typedef int(*ViewUpdateCallbackPtrType)(bool, DgnPlatform::DgnDrawMode, DgnModelRefListP, int, Asynch_update_view[], ViewContextP, int[], MSDisplayDescr*[]);
    typedef std::function<int(bool, DgnPlatform::DgnDrawMode, DgnModelRefListP, std::vector<Asynch_update_view*>*, ViewContextP, std::vector<int>*, std::vector<MSDisplayDescr*>*)> ViewUpdateFunctionType;

#define DEFINE_FN_POINTER_VIEW_UPDATE_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](bool isPreUpdate, DgnPlatform::DgnDrawMode eraseMode, DgnModelRefListP modelList, int numRegions, Asynch_update_view regions[], ViewContextP context, int numCovers[], MSDisplayDescr* displayDescr[]) -> int\
        { \
            try \
            { \
                std::vector<Asynch_update_view*> regionsVector; \
                for (int iRegion = 0; iRegion < numRegions; iRegion++) \
                { \
                    regionsVector.push_back(&regions[iRegion]); \
                } \
                std::vector<int> numCoversVector; \
                numCoversVector.push_back(numCovers[0]); \
                std::vector<MSDisplayDescr*> displayDescrVector; \
                displayDescrVector.push_back(displayDescr[0]); \
                return m_callbackFuncs[index](isPreUpdate, eraseMode, modelList, &regionsVector, context, &numCoversVector, &displayDescrVector); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static ViewUpdateCallbackPtrType SetCallback(ViewUpdateFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
         DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_VIEW_UPDATE_CALLBACK);
    }

    static ViewUpdateFunctionType GetOldCallbackFunction(ViewUpdateCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_CALLBACK_COUNT_20);
    }

private:
    static ViewUpdateFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static ViewUpdateCallbackPtrType m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename ViewUpdateCallbackHelper::ViewUpdateFunctionType ViewUpdateCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
typename ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType ViewUpdateCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string ViewUpdateCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class ViewSubstituteElemCallbackHelper {
public:
    typedef SubstituteElemStatus(*ViewSubstituteElemCallbackPtrType)(MSElementDescrH, ViewportP, DgnPlatform::DrawPurpose, ViewContextP, ElementHandleCP);
    typedef std::function<SubstituteElemStatus(MSElementDescrReceiver*, ViewportP, DgnPlatform::DrawPurpose, ViewContextP, ElementHandleCP)> ViewSubstituteElemFunctionType;

#define DEFINE_FN_POINTER_VIEW_SUBSTITUTE_ELEM_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](MSElementDescrH newElem, ViewportP viewport, DgnPlatform::DrawPurpose purpose, ViewContextP context, ElementHandleCP elem) -> SubstituteElemStatus\
        { \
            try \
            { \
                MSElementDescrReceiver receiver(nullptr); \
                SubstituteElemStatus returnVal = m_callbackFuncs[0](&receiver, viewport, purpose, context, elem); \
                if (nullptr != receiver.value) \
                { \
                    *newElem = receiver.value; \
                } \
                return returnVal; \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static ViewSubstituteElemCallbackPtrType SetCallback(ViewSubstituteElemFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_VIEW_SUBSTITUTE_ELEM_CALLBACK);
    }

    static ViewSubstituteElemFunctionType GetOldCallbackFunction(ViewSubstituteElemCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_CALLBACK_COUNT_20);
    }

private:
    static ViewSubstituteElemFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static ViewSubstituteElemCallbackPtrType m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename ViewSubstituteElemCallbackHelper::ViewSubstituteElemFunctionType ViewSubstituteElemCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
typename ViewSubstituteElemCallbackHelper::ViewSubstituteElemCallbackPtrType ViewSubstituteElemCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string ViewSubstituteElemCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msview(py::module_& m)
    {
    //===================================================================================
    // Enum SubstituteElemStatus
    py::enum_<SubstituteElemStatus>(m, "SubstituteElemStatus")
        .value("eSUBSTELEM_STATUS_Normal", SubstituteElemStatus::SUBSTELEM_STATUS_Normal)
        .value("eSUBSTELEM_STATUS_Block" , SubstituteElemStatus::SUBSTELEM_STATUS_Block)
        .export_values();

    py::class_<ViewCallback> c1(m, "ViewCallback");
    c1.def_static("SetUpdatePreFunction", [](ViewUpdateCallbackHelper::ViewUpdateFunctionType& newFunc, const std::string& funcID) -> ViewUpdateCallbackHelper::ViewUpdateFunctionType
            {
            ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType oldCallback;
            if (newFunc)
                {
                ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType callback = ViewUpdateCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = ViewCallback::SetUpdatePreFunction(callback);
                }
            else
                {
                oldCallback = ViewCallback::SetUpdatePreFunction(nullptr);
                }
            if (nullptr != oldCallback)
                {
                return ViewUpdateCallbackHelper::GetOldCallbackFunction(oldCallback);
                }
            else
                {
                return nullptr;
                }
            }, "newFunc"_a, "funcID"_a, DOC(ViewCallback, SetUpdatePreFunction));

    c1.def_static("SetUpdatePostFunction", [](ViewUpdateCallbackHelper::ViewUpdateFunctionType& newFunc, const std::string& funcID) -> ViewUpdateCallbackHelper::ViewUpdateFunctionType
            {
            ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType oldCallback;
            if (newFunc)
                {
                ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType callback = ViewUpdateCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = ViewCallback::SetUpdatePostFunction(callback);
                }
            else
                {
                oldCallback = ViewCallback::SetUpdatePostFunction(nullptr);
                }
            if (nullptr != oldCallback)
                {
                return ViewUpdateCallbackHelper::GetOldCallbackFunction(oldCallback);
                }
            else
                {
                return nullptr;
                }
            }, "newFunc"_a, "funcID"_a, DOC(ViewCallback, SetUpdatePostFunction));

    c1.def_static("SetMotionFunction", [](std::function<std::remove_pointer_t<ViewFunc_Motion>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<ViewFunc_Motion>>
            {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(ViewCallback::SetMotionFunction, MSWindowP, int, int, void, newFunc, funcID)
            }, "newFunc"_a, "funcID"_a, DOC(ViewCallback, SetMotionFunction));

    c1.def_static("SetNoMotionFunction", [](std::function<std::remove_pointer_t<ViewFunc_Motion>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<ViewFunc_Motion>>
            {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(ViewCallback::SetNoMotionFunction, MSWindowP, int, int, void, newFunc, funcID)
            }, "newFunc"_a, "funcID"_a, DOC(ViewCallback, SetNoMotionFunction));

    c1.def_static("SetSubstituteElemFunction", [](ViewSubstituteElemCallbackHelper::ViewSubstituteElemFunctionType& newFunc, const std::string& funcID) -> ViewSubstituteElemCallbackHelper::ViewSubstituteElemFunctionType
            {
            ViewSubstituteElemCallbackHelper::ViewSubstituteElemCallbackPtrType oldCallback;
            if (newFunc)
                {
                ViewSubstituteElemCallbackHelper::ViewSubstituteElemCallbackPtrType callback = ViewSubstituteElemCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = ViewCallback::SetSubstituteElemFunction(callback);
                }
            else
                {
                oldCallback = ViewCallback::SetSubstituteElemFunction(nullptr);
                }
            if (nullptr != oldCallback)
                {
                return ViewSubstituteElemCallbackHelper::GetOldCallbackFunction(oldCallback);
                }
            else
                {
                return nullptr;
                }
            }, "newFunc"_a, "funcID"_a, DOC(ViewCallback, SetSubstituteElemFunction));


    //===================================================================================
    // Enum fitViewOptions
    py::class_<fitViewOptions> c2(m, "fitViewOptions");
    c2.def_property("forceActiveZToCenter",
        [](fitViewOptions const& self) {return self.forceActiveZToCenter; },
        [](fitViewOptions& self, UInt16 value) {self.forceActiveZToCenter = value; });
    c2.def_property("expandClippingPlanes",
        [](fitViewOptions const& self) {return self.expandClippingPlanes; },
        [](fitViewOptions& self, UInt16 value) {self.expandClippingPlanes = value; });
    c2.def_property("disableCenterCamera",
        [](fitViewOptions const& self) {return self.disableCenterCamera; },
        [](fitViewOptions& self, UInt16 value) {self.disableCenterCamera = value; });
    c2.def_property("ignoreTransients",
        [](fitViewOptions const& self) {return self.ignoreTransients; },
        [](fitViewOptions& self, UInt16 value) {self.ignoreTransients = value; });
    c2.def_property("dontIncludeParentsOfNestedRefs",
        [](fitViewOptions const& self) {return self.dontIncludeParentsOfNestedRefs; },
        [](fitViewOptions& self, UInt16 value) {self.dontIncludeParentsOfNestedRefs = value; });
    c2.def_property("ignoreCallouts",
        [](fitViewOptions const& self) {return self.ignoreCallouts; },
        [](fitViewOptions& self, UInt16 value) {self.ignoreCallouts = value; });
    c2.def_property("rasterElementsOnly",
        [](fitViewOptions const& self) {return self.rasterElementsOnly; },
        [](fitViewOptions& self, UInt16 value) {self.rasterElementsOnly = value; });
    c2.def_property("optionPadding",
        [](fitViewOptions const& self) {return self.optionPadding; },
        [](fitViewOptions& self, UInt16 value) {self.optionPadding = value; });
    c2.def_property("optionPadding2",
        [](fitViewOptions const& self) {return self.optionPadding2; },
        [](fitViewOptions& self, UInt16 value) {self.optionPadding2 = value; });


    //===================================================================================
    // Enum LevelMaskOperation
    py::enum_<LevelMaskOperation>(m, "LevelMaskOperation")
        .value("eOff", LevelMaskOperation::Off)
        .value("eOn", LevelMaskOperation::On)
        .value("eToggle", LevelMaskOperation::Toggle)
        .export_values();

    //===================================================================================
    // Struct MstnView - mdlView_* functions
    py::class_<MstnView> c10(m, "MstnView");

    c10.def_static("defaultCursor", &mdlView_defaultCursor, DOC(mdlView, defaultCursor));
    c10.def_static("fit", &mdlView_fit, "viewNumber"_a, "modelRefList"_a, DOC(mdlView, fit));
    c10.def_static("fitEx", &mdlView_fitEx, "viewNumber"_a, "modelRefList"_a, "doRasterRefFit"_a, "options"_a, DOC(mdlView, fitEx));
    c10.def_static("isModelActive", &mdlView_isModelActive, "viewIndex"_a, DOC(mdlView, isModelActive));
    c10.def_static("is3d", &mdlView_is3d, "viewNum"_a, DOC(mdlView, is3d));
    c10.def_static("getRootModel", &mdlView_getRootModel, "viewIndex"_a, DOC(mdlView, getRootModel));
    c10.def_static("setModel", &mdlView_setModel, "modelRef"_a, "viewIndex"_a, DOC(mdlView, setModel));

    c10.def_static("getCamera", [](int view)
            {
            Dpoint3d position, target;
            double angle, focalLength;
            int lensNumber;

            int ret = mdlView_getCamera(&position, &target, &angle, &focalLength, &lensNumber, view);
            return py::make_tuple(ret, position, target, angle, focalLength, lensNumber);
            }, "view"_a, DOC(mdlView, getCamera));

    c10.def_static("getParameters", [](int view)
            {
            Dpoint3d origin, center, delta;
            RotMatrix rMatrix;
            double  activeZ;
            int     ret = mdlView_getParameters(&origin, &center, &delta, &rMatrix, &activeZ, view);
            return py::make_tuple(ret, origin, center, delta, rMatrix, activeZ);
            }, "view"_a, DOC(mdlView, getParameters));

    c10.def_static("getParametersWithExpandedDepth", [](int view, bool expandDepth)
        {
        Dpoint3d origin, center, delta;
        RotMatrix   rMatrix;
        double activeZ;

        int ret = mdlView_getParametersWithExpandedDepth(&origin, &center, &delta, &rMatrix, &activeZ, view, expandDepth);
        return py::make_tuple(ret, origin, center, delta, rMatrix, activeZ);
        }, "view"_a, "expandDepth"_a, DOC(mdlView, getParametersWithExpandedDepth));


    c10.def_static("getStandard2", [](DgnPlatform::StandardView stdViewNum, DgnModelRefP  modelRef)
        {
        RotMatrix   rMatrix;
        int ret = mdlView_getStandard2(&rMatrix, stdViewNum, modelRef);
        return py::make_tuple(ret, rMatrix);
        }, "stdViewNum"_a, "modelRef"_a, DOC(mdlView, getStandard2));

    c10.def_static("getStandard", &mdlView_getStandard, "rMatrix"_a, "stdViewNum"_a, DOC(mdlView, getStandard));
    c10.def_static("getStandardCameraLens", [](int lensNumber)
        {
        double angle, focalLength;
        int ret = mdlView_getStandardCameraLens(&angle, &focalLength, lensNumber);
        return py::make_tuple(ret, angle, focalLength);
        }, "lensNumber"_a, DOC(mdlView, getStandardCameraLens));


    c10.def_static("isActive", &mdlView_isActive, "viewNumber"_a, DOC(mdlView, isActive));
    c10.def_static("isVisible", &mdlView_isVisible, "viewNumber"_a, DOC(mdlView, isVisible));
    c10.def_static("isStandard", &mdlView_isStandard, "trans"_a, DOC(mdlView, isStandard));
    c10.def_static("rotateToRMatrix", &mdlView_rotateToRMatrix, "rMatrix"_a, "view"_a, DOC(mdlView, rotateToRMatrix));
    c10.def_static("setActiveDepth", &mdlView_setActiveDepth, "viewNumber"_a, "depth"_a, DOC(mdlView, setActiveDepth));
    c10.def_static("setActiveDepthPoint", &mdlView_setActiveDepthPoint, "viewNumber"_a, "points"_a, DOC(mdlView, setActiveDepthPoint));
    c10.def_static("setArea", &mdlView_setArea, "viewNumber"_a, "pt"_a, "zOrg"_a, "zDelta"_a, "actZdepth"_a, "rotMatrix"_a, DOC(mdlView, setArea));
    c10.def_static("setCameraLens", &mdlView_setCameraLens, "angle"_a, "view"_a, DOC(mdlView, setCameraLens));
    c10.def_static("getDisplayControl", &mdlView_getDisplayControl, "paramNum"_a, "viewNum"_a, DOC(mdlView, getDisplayControl));
    c10.def_static("setDisplayControl", &mdlView_setDisplayControl, "paramNum"_a, "viewNum"_a, "value"_a, DOC(mdlView, setDisplayControl));
    c10.def_static("setDisplayDepth", &mdlView_setDisplayDepth, "viewNumber"_a, "frontDepth"_a, "backDepth"_a, DOC(mdlView, setDisplayDepth));
    c10.def_static("setDisplayDepthPoints", &mdlView_setDisplayDepthPoints, "viewNum"_a, "points"_a, DOC(mdlView, setDisplayDepthPoints));
    c10.def_static("synchWithTCB", &mdlView_synchWithTCB, "viewNumber"_a, DOC(mdlView, synchWithTCB));
    c10.def_static("turnOff", &mdlView_turnOff, "viewNumber"_a, DOC(mdlView, turnOff));
    c10.def_static("turnOn", &mdlView_turnOn, "viewNumber"_a, DOC(mdlView, turnOn));
    c10.def_static("reopen", &mdlView_reopen, "viewNumber"_a, DOC(mdlView, reopen));

    c10.def_static("updateMulti", [](BoolArray viewDraw, bool incremental, DgnPlatform::DgnDrawMode drawMode, 
                                             DgnModelRefListP modelRefList, bool startEndMsg)
        {
        bool isdraw[DgnPlatform::MAX_VIEWS];
        size_t arrlen = viewDraw.size() > DgnPlatform::MAX_VIEWS ? DgnPlatform::MAX_VIEWS : viewDraw.size();
        for (int i = 0; i < arrlen; i++)
            isdraw[i] = viewDraw[i];

        return mdlView_updateMulti (isdraw, incremental, drawMode, modelRefList, startEndMsg);
        }, "viewDraw"_a, "incremental"_a, "drawMode"_a, "modelRefList"_a, "startEndMsg"_a, DOC(mdlView, updateMulti));

    c10.def_static("updateMultiEx", [](BoolArray viewDraw, bool incremental, DgnPlatform::DgnDrawMode drawMode,
                                               DgnModelRefListP modelRefList, bool startEndMsg, bool updateViewTitle)
        {
        bool isdraw[DgnPlatform::MAX_VIEWS];
        size_t arrlen = viewDraw.size() > DgnPlatform::MAX_VIEWS ? DgnPlatform::MAX_VIEWS : viewDraw.size();
        for (int i = 0; i < arrlen; i++)
            isdraw[i] = viewDraw[i];

        return mdlView_updateMultiEx(isdraw, incremental, drawMode, modelRefList, startEndMsg, updateViewTitle);
        }, "viewDraw"_a, "incremental"_a, "drawMode"_a, "modelRefList"_a, "startEndMsg"_a, "updateViewTitle"_a, DOC(mdlView, updateMultiEx));

    c10.def_static("updateSingle", &mdlView_updateSingle, "viewNumber"_a, DOC(mdlView, updateSingle));
    c10.def_static("zoom", &mdlView_zoom, "outView"_a, "inView"_a, "centerPoint"_a, "zoomFactor"_a, DOC(mdlView, zoom));
    c10.def_static("pointToScreen", [](DPoint3dCP uorPoint, int viewNumber, DgnPlatform::DgnCoordSystem  coordinateSystem)
        {
        Point2d  screenPoint;
        int ret = mdlView_pointToScreen(&screenPoint, uorPoint, viewNumber, coordinateSystem);
        return py::make_tuple(ret, screenPoint);
        }, "uorPoint"_a, "viewNumber"_a, "coordinateSystem"_a, DOC(mdlView, pointToScreen));

    c10.def_static("screenToPoint", [](Point2dP screenPoint, int viewNumber, DgnPlatform::DgnCoordSystem  coordSystem)
        {
        DPoint3d  uorPt;
        int ret = mdlView_screenToPoint(&uorPt , screenPoint, viewNumber, coordSystem);
        return py::make_tuple(ret, uorPt);
        }, "screenPoint"_a, "viewNumber"_a, "coordSystem"_a, DOC(mdlView, screenToPoint));

    c10.def_static("getViewRectangle", &mdlView_getViewRectangle, "viewRect"_a, "window"_a, "coordSystem"_a, DOC(mdlView, getViewRectangle));
    c10.def_static("queuePartialUpdate", &mdlView_queuePartialUpdate, "viewNumber"_a, "rects"_a, "numRects"_a, DOC(mdlView, queuePartialUpdate));
    c10.def_static("newWindowCenter", &mdlView_newWindowCenter, "viewNumber"_a, "newCenter"_a, DOC(mdlView, newWindowCenter));
    c10.def_static("pan", &mdlView_pan, "distance"_a, "viewNumber"_a, "doUpdate"_a, DOC(mdlView, pan));
    c10.def_static("indexFromWindow", &mdlView_indexFromWindow, "window"_a, DOC(mdlView, indexFromWindow));
    c10.def_static("setCameraParameters", &mdlView_setCameraParameters, "position"_a, "target"_a, "upVector"_a, "angle"_a, "aspectRatio"_a, 
                                                                        "screenWindow"_a, "frontClipDist"_a, "backClipDist"_a, "view"_a, DOC(mdlView, setCameraParameters));
    c10.def_static("cameraLensLengthFromAngle", &mdlView_cameraLensLengthFromAngle, "angle"_a, DOC(mdlView, cameraLensLengthFromAngle));
    c10.def_static("cameraLensAngleFromLength", &mdlView_cameraLensAngleFromLength, "focalLength"_a, DOC(mdlView, cameraLensAngleFromLength));
    c10.def_static("computeCameraRotMatrix", [](DPoint3dCP viewZ, DPoint3dCP upVector)
        {
        RotMatrix      rotMatrix;
        int ret = mdlView_computeCameraRotMatrix (&rotMatrix, viewZ, upVector);
        return py::make_tuple(ret, rotMatrix);
        }, "viewZ"_a, "upVector"_a, DOC(mdlView, computeCameraRotMatrix));

    c10.def_static("getCameraParameters", [](int view)
        {
        Dpoint3d position, target, upVector;
        double angle, frontClipDist, backClipDist;
        DRange2d    screenWindow;

        int ret = mdlView_getCameraParameters(&position, &target, &upVector, &angle, &screenWindow, &frontClipDist, &backClipDist, view);
        return py::make_tuple(ret, position, target, upVector, angle, screenWindow, frontClipDist, backClipDist);
        }, "view"_a, DOC(mdlView, getCameraParameters));

    c10.def_static("getHomogeneousMaps", [](int viewNumber)
        {
        DPoint4d worldEye, viewEye;
        DMap4d worldToViewMap, worldToNPCMap;
        DMatrix4d worldToFocalPlane, viewToFocalPlane;
        double focalLength, nPCFocalPlaneDepth;
        int ret = mdlView_getHomogeneousMaps(&worldEye, &viewEye, &worldToViewMap, &worldToNPCMap, &worldToFocalPlane, &viewToFocalPlane, &focalLength, &nPCFocalPlaneDepth, viewNumber);
        return py::make_tuple(ret, worldEye, viewEye, worldToViewMap, worldToNPCMap, worldToFocalPlane, viewToFocalPlane, focalLength, nPCFocalPlaneDepth);
        }, "viewNumber"_a, DOC(mdlView, getHomogeneousMaps));

    c10.def_static("getLevelDisplayMask", &mdlView_getLevelDisplayMask, "modelRef"_a, "iViewNum"_a, "levelDisplayType"_a, DOC(mdlView, getLevelDisplayMask));
    c10.def_static("setLevelDisplayMask", &mdlView_setLevelDisplayMask, "modelRef"_a, "iViewNum"_a, "pViewLevelMask"_a, "doUpdate"_a, DOC(mdlView, setLevelDisplayMask));
    c10.def_static("changeLevelDisplayMask", &mdlView_changeLevelDisplayMask, "modelRef"_a, "iViewNum"_a, "levelMask"_a, "operation"_a, "doUpdate"_a, DOC(mdlView, changeLevelDisplayMask));
    c10.def_static("setLevelDisplayMaskMulti", [](DgnModelRefP  modelRef, BoolArray viewList, BitMaskCP  viewLevelMask, bool doUpdate)
        {
        bool isdraw[DgnPlatform::MAX_VIEWS];
        size_t arrlen = viewList.size() > DgnPlatform::MAX_VIEWS ? DgnPlatform::MAX_VIEWS : viewList.size();
        for (int i = 0; i < arrlen; i++)
            isdraw[i] = viewList[i];

        return mdlView_setLevelDisplayMaskMulti(modelRef, isdraw, viewLevelMask, doUpdate);
        }, "modelRef"_a, "viewList"_a, "viewLevelMask"_a, "doUpdate"_a, DOC(mdlView, setLevelDisplayMaskMulti));

    c10.def_static("changeLevelDisplayMaskMulti", [](DgnModelRefP  modelRef, BoolArray viewList, BitMaskCP  levelMask, LevelMaskOperation  operation, bool doUpdate)
        {
        bool isdraw[DgnPlatform::MAX_VIEWS];
        size_t arrlen = viewList.size() > DgnPlatform::MAX_VIEWS ? DgnPlatform::MAX_VIEWS : viewList.size();
        for (int i = 0; i < arrlen; i++)
            isdraw[i] = viewList[i];

        return mdlView_changeLevelDisplayMaskMulti(modelRef, isdraw, levelMask, operation, doUpdate);
        }, "modelRef"_a, "viewList"_a, "levelMask"_a, "operation"_a, "doUpdate"_a, DOC(mdlView, changeLevelDisplayMaskMulti));

    c10.def_static("getLevelDisplay", [](DgnModelRefP modelRef, int iViewNum, DgnPlatform::LevelId iLevelId, DgnPlatform::ViewLevelDisplayType levelDisplayType)
        {
        bool viewLevelDisplay;
        int ret = mdlView_getLevelDisplay(&viewLevelDisplay, modelRef, iViewNum, iLevelId, levelDisplayType);
        return py::make_tuple(ret, viewLevelDisplay);
        }, "modelRef"_a, "iViewNum"_a, "iLevelId"_a, "levelDisplayType"_a, DOC(mdlView, getLevelDisplay));

    c10.def_static("setLevelDisplay", &mdlView_setLevelDisplay, "modelRef"_a, "iViewNum"_a, "iLevelId"_a, "levelDisplay"_a, DOC(mdlView, setLevelDisplay));
    c10.def_static("getLevels", [](int iViewNumIn)
        {
        short v7LevelMask;
        int ret = mdlView_getLevels(&v7LevelMask, iViewNumIn);
        return py::make_tuple(ret, v7LevelMask);
        }, "iViewNumIn"_a, DOC(mdlView, getLevels));

    c10.def_static("updateViewInfo", &mdlView_updateViewInfo, "viewInfo"_a, DOC(mdlView, updateViewInfo));
    c10.def_static("getMaxCount", &mdlView_getMaxCount, DOC(mdlView, getMaxCount));
    c10.def_static("isValidIndex", &mdlView_isValidIndex, "index"_a, DOC(mdlView, isValidIndex));
    c10.def_static("getFlags", [](int viewIndex)
        {
        DgnPlatform::ViewFlags viewFlags;
        int ret = mdlView_getFlags(&viewFlags, viewIndex);
        return py::make_tuple(ret, viewFlags);
        }, "viewIndex"_a, DOC(mdlView, getFlags));

    c10.def_static("setFlags", &mdlView_setFlags, "viewFlags"_a, "viewIndex"_a, DOC(mdlView, setFlags));
    c10.def_static("copyCamera", [](int index)
        {
        DgnPlatform::CameraInfo cameraInfo;
        int ret = mdlView_copyCamera(&cameraInfo, index);
        return py::make_tuple(ret, cameraInfo);
        }, "index"_a, DOC(mdlView, copyCamera));

    c10.def_static("attachNamed", &mdlView_attachNamed, "inName"_a, "inNameSpace"_a, "viewNumber"_a, DOC(mdlView, attachNamed));
    c10.def_static("setUpApplyOpts", &mdlView_setUpApplyOpts, "applyOpts"_a, "type"_a, DOC(mdlView, setUpApplyOpts));
    c10.def_static("attachNamedWithOptions", &mdlView_attachNamedWithOptions, "inName"_a, "inNameSpace"_a, "viewNumber"_a, "applyOpts"_a, DOC(mdlView, attachNamedWithOptions));
    c10.def_static("saveNamed", &mdlView_saveNamed, "viewName"_a, "description"_a, "viewNameSpace"_a, "view"_a, DOC(mdlView, saveNamed));
    c10.def_static("deleteNamed", &mdlView_deleteNamed, "inName"_a, "inNameSpace"_a, DOC(mdlView, deleteNamed));
    c10.def_static("findNamed", [](WCharCP  viewName, WCharCP   viewNameSpace)
        {
        DgnPlatform::ViewInfoPtr viewInfo;
        DgnPlatform::ViewPortInfoPtr viewPortInfo;
        StatusInt ret = mdlView_findNamed(&viewInfo, &viewPortInfo, viewName, viewNameSpace);
        return py::make_tuple(ret, viewInfo, viewPortInfo);
        }, "viewName"_a, "viewNameSpace"_a, DOC(mdlView, findNamed));

    c10.def_static("getDefaultFlags", &mdlView_getDefaultFlags, "viewFlags"_a, DOC(mdlView, getDefaultFlags));
    c10.def_static("fitToFence", [](DPoint2dArray& fencePts, int viewIndex)
    {
    return mdlView_fitToFence(fencePts.data(), viewIndex, (UInt32)fencePts.size());
    }, "fencePts"_a, "viewIndex"_a, DOC(mdlView, fitToFence));

    c10.def_static("fitViewToRange", &mdlView_fitViewToRange, "min"_a, "max"_a, "options"_a, "viewIndex"_a, DOC(mdlView, fitViewToRange));
    c10.def_static("treatAs3D", &mdlView_treatAs3D, "viewIndex"_a, DOC(mdlView, treatAs3D));
    c10.def_static("setClipBoundaryElement", &mdlView_setClipBoundaryElement, "viewIndex"_a, "elementID"_a, DOC(mdlView, setClipBoundaryElement));
    c10.def_static("getClipBoundaryElement", [](int  viewIndex)
        {
        DgnPlatform::ElementId ElementId;
        int ret = mdlView_getClipBoundaryElement(&ElementId, viewIndex);
        return py::make_tuple(ret, ElementId);
        }, "viewIndex"_a, DOC(mdlView, getClipBoundaryElement));

    c10.def_static("setClipMaskElement", &mdlView_setClipMaskElement, "viewIndex"_a, "elementID"_a, DOC(mdlView, setClipMaskElement));
    c10.def_static("getClipMaskElement", [](int  viewIndex)
        {
        DgnPlatform::ElementId ElementId;
        int ret = mdlView_getClipMaskElement(&ElementId, viewIndex);
        return py::make_tuple(ret, ElementId);
        }, "viewIndex"_a, DOC(mdlView, getClipMaskElement));

    c10.def_static("getViewport", &mdlView_getViewport, "viewIndex"_a, DOC(mdlView, getViewport));
    c10.def_static("getToolBoxPath", &mdlView_getToolBoxPath, "viewIndex"_a, "toolBoxIndex"_a, "b3D"_a, DOC(mdlView, getToolBoxPath));
    c10.def_static("setToolBoxPath", &mdlView_setToolBoxPath, "viewIndex"_a, "toolBoxIndex"_a, "b3D"_a, "ToolBoxPath"_a, DOC(mdlView, setToolBoxPath));
    c10.def_static("getToolBoxName", &mdlView_getToolBoxName, "viewIndex"_a, "toolBoxIndex"_a, "b3D"_a, DOC(mdlView, getToolBoxName));
    c10.def_static("setToolBoxName", &mdlView_setToolBoxName, "viewIndex"_a, "toolBoxIndex"_a, "b3D"_a, "ToolBoxName"_a, DOC(mdlView, setToolBoxName));
    c10.def_static("getToolBoxId", &mdlView_getToolBoxId, "viewIndex"_a, "toolBoxIndex"_a, "b3D"_a, DOC(mdlView, getToolBoxId));
    c10.def_static("setToolBoxId", &mdlView_setToolBoxId, "viewIndex"_a, "toolBoxIndex"_a, "b3D"_a, "toolBoxId"_a, DOC(mdlView, setToolBoxId));
    c10.def_static("reloadToolBoxes", &mdlView_reloadToolBoxes, "viewIndex"_a, DOC(mdlView, reloadToolBoxes));
    c10.def_static("getViewToolsDisplay", &mdlView_getViewToolsDisplay, "viewIndex"_a, DOC(mdlView, getViewToolsDisplay));
    c10.def_static("setViewToolsDisplay", &mdlView_setViewToolsDisplay, "viewIndex"_a, "display"_a, DOC(mdlView,setViewToolsDisplay));
    }
