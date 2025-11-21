/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dellipse3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Pybind11/numpy.h>



static const char * __doc_Bentley_Geom_DEllipse3d_Construct_Point_Direction_TangentXY =R"doc(Construct circular arc(s) with given start point and tangent, tangent
to a given ray.

:param (output):
    ellipse constructed ellipses.

:param (output):
    fractionB parameters on the ray.

:param (input):
    pointA start ponit

:param (input):
    directionA start tangent

:param (input):
    rayB ray for tangency. The tangency can occur anywhere on the ray.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_TryConstruct_EdgePoint_XPoint_EdgePoint_XAngle =R"doc(Construct an ellipse (it is unique if it exists) with given x axis,
start point, x axis point, and end point.

:param (output):
    ellipse constructed ellipse.

:param (input):
    edgePoint0 start point

:param (input):
    xPoint x axis extrema

:param (input):
    edgePoint1 end point

:param (input):
    xAngle angle from global x axis to ellipse x axis)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_Construct_XPoint_EdgePoint_EdgePoint_XRadius =R"doc(Construct (up to 3) ellipses defined by known primary radius, primary
axis point, and two other edge points

:param (output):
    ellipses computed ellipses.

:param (input):
    xPoint x axis point

:param (input):
    edgePoint0 any other point on the ellipse.

:param (input):
    edgePoint1 any other point on the ellipse.

:param (input):
    a x axis radius.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_Construct_XRadius_YRadius_XPoint_EdgePoint =R"doc(Construct (up to 4) ellipses defined by known primary radii, primary
axis point, and another edge point.

:param (output):
    ellipses computed ellipses.

:param (input):
    a x axis radius.

:param (input):
    b y axis radius.

:param (input):
    xPoint x axis point

:param (input):
    edgePoint any other point on the ellipse.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_WireCentroid =R"doc(Compute the length (unit density) and wire centroid. Note that an
ellipse with zero sweephas zero length but the (single) coordinate is
a well defined centroid.

:param (output):
    length length.

:param (output):
    centroid centroid point.

:param (input):
    fraction0 start fraction of active part of sweep.

:param (input):
    fraction1 end fraction of active part of sweep.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ClosestPointBoundedXY =R"doc(Find the closest point (projection or end), as viewed in xy plane,
after applying optional transformation.

:param (output):
    closePoint closest point, in coordinates of the input segment.

:param (output):
    closeParam parameter at closest point

:param (output):
    distanceXY distance in transformed coordinates

:param (input):
    spacePoint world coordinates of test point.

:param (input):
    worldToLocal optional transformation.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_AlignedRange =R"doc(:param (output):
    localToGlobal coordinate frame with origin at lower right of local
    range.

:param (output):
    globalToLocal transformation from world to local

:param (output):
    range ellipse range in the local coordinates.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetDGNFields2d =R"doc()doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetDGNFields3d =R"doc(@description Fill in ellipse data from data fields in DGN 3d ellipse
element.

:param (output):
    centerOUT center of ellipse.

:param (output):
    pQuatWXYZ quaternion for orthogonal frame. As per DGN convention,
    ordered WXYZ. If this is NULL, major and minor directions must be
    supplied as pDirection0 and pDirection90;

:param (output):
    directionX unit vector in ellipse x direction.

:param (output):
    directionY unit vector in ellipse y direction.

:param (output):
    rx scale factor (usually a true distance) for x direction.

:param (output):
    ry scale factor (usually a true distance) for y direction.

:param (output):
    startAngle start angle.

:param (output):
    sweepAngle sweep angle.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InitFromDGNFields2d =R"doc(@description Fill in ellipse data from data fields in DGN 2d ellipse
element.

:param (input):
    centerIN center of ellipse.

:param (input):
    direction0 ellipse x axis direction.

:param (input):
    rX scale factor for ellipse x direction.

:param (input):
    rY scale factor for ellipse y direction.

:param (input):
    startAngle start angle.

:param (input):
    sweepAngle sweep angle.

:param (input):
    zDepth z value for ellipse.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InitFromDGNFields3d =R"doc(@description Fill in ellipse data from data fields in DGN 3d ellipse
element.

:param (input):
    centerIN center of ellipse.

:param (input):
    directionX vector in the x axis direction. This is scaled by rX.
    (It is NOT normalized before scaling. In common use, it will be a
    unit vector.)

:param (input):
    directionY vector in the y axis direction. This is scaled by rY.
    (It is NOT normalized before scaling. In common use, it will be a
    unit vector.)

:param (input):
    rX scale factor (usually a true distance) for x direction.

:param (input):
    rY scale factor (usually a true distance) for y direction.

:param (input):
    startAngle start angle

:param (input):
    sweepAngle sweep angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InitFromCenterMajorAxisPointAndThirdPoint =R"doc(@description Initialize an ellipse from center, primary axis point,
and additional pass-though point.

:param (input):
    centerIN center point of ellipse.

:param (input):
    point0 point to appear at the zero degree point. The ellipse must
    pass through this point as a major or minor axis point, i.e. its
    tangent must be perpendicular to the vector from the center to
    this point.

:param (input):
    point1 additional pass-through point.

:returns:
    false if center, point0 and point1 are not independent, or if
    point1 is too far away from center to allow ellipse constrution.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_XySweepProperties =R"doc(@description Compute area and swept angle as seen from given point.

:param (output):
    area swept area

:param (output):
    sweepOUT swept angle (in radians)

:param (input):
    point base point for sweep line.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ClosestPointBounded =R"doc(@description Find the closest point on a bounded ellipse, considering
both endpoints and perpendicular projections.

:param (output):
    minAngle angular parameter at closest point

:param (output):
    minDistanceSquared squared distance to closest point

:param (output):
    minPoint closest point

:param (input):
    point space point

:returns:
    always true)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ClosestPointXYBounded =R"doc(@description Find the closest point on a bounded ellipse, considering
both endpoints and perpendicular projections, and ignoring z of both
the ellipse and space point.

:param (output):
    minAngle angular parameter at closest point

:param (output):
    minDistanceSquared squared distance to closest point

:param (output):
    minPoint closest point

:param (input):
    point space point

:returns:
    always true)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsCCWSweepXY =R"doc(@description Test if the XY projection of the ellipse is CCW when
considering both the sweep sign and the vector directions.

:returns:
    true if circular)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsCircularXY =R"doc(@description Test if the XY projection of the ellipse is circular.

:returns:
    true if circular)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsCircular =R"doc(@description Test if the ellipse is circular.

:returns:
    true if circular)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_SolveTangentsPerpendicularToVector =R"doc(@description Find angles at which the ellipse tangent vector is
perpendicular to given vector.

:param (output):
    angles 0,1, or 2 angles. This is an array that must be allocated
    by the caller.

:param (input):
    vector perpendicular vector.

:returns:
    The number of solutions, i.e. 0, 1, or 2)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IntersectPlane =R"doc(@description Find intersections of a (full) ellipse with a plane.

Remark:
    s Return value n=1 is a single tangency point returned in
    trigPoints[0]; n=2 is two simple intersections returned in
    trigPoints[0..1]

Remark:
    s The three component values in trigPoints are:<UL> <LI>x ==
    cosine of angle <LI>y == sine of angle <LI>z == angle in radians
    </UL>

:param (output):
    trigPoints 2 points:cosine, sine, theta values of plane
    intersection

:param (input):
    plane homogeneous plane equation

:returns:
    The number of intersections, i.e. 0, 1, or 2)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ProjectedParameterRange =R"doc(:returns:
    range when projected to fraction space of the ray

:param (input):
    ray)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetLocalRange =R"doc(@description Compute the range of the ellipse in its own coordinate
system.

Remark:
    s This depends on the start and sweep angles but not the center or
    axis coordinates.

:param (output):
    range computed range)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetRange =R"doc(@description Compute the xyz range limits of a 3D ellipse.

:param (output):
    range computed range)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FractionToLength =R"doc(@description Compute the (signed) arc length between specified
fractional parameters.

Remark:
    s Fractions outside [0,1] return error.

:param (output):
    arcLength computed arc length. Negative if fraction1<fraction0.

:param (input):
    fraction0 start fraction for interval to measure

:param (input):
    fraction1 end fraction for interval to measure

:returns:
    true if the arc length was computed.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InverseArcLength =R"doc(@description Return the sweep angle corresponding to an arc length.

Remark:
    s Negative returned sweep angle corresponds to arclength traversed
    in the opposite direction of the ellipse sweep.

:param (input):
    arcLength arc length to invert

:returns:
    sweep angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ArcLength =R"doc(@description Return arc length of ellipse.

:returns:
    arc length of ellipse.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_TangentMagnitude =R"doc(@description Compute the magnitude of the tangent vector to the
ellipse at the specified angle.

:param (input):
    theta angular parameter

:returns:
    tangent magnitude)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetMajorMinorRangeMidlines =R"doc(@description Compute the range box of the ellipse in its major-minor
axis coordinate system. Compute line segments that are the horizontal
and vertical midlines in that system. Return those line segments
ordered with the longest first, and return the shorter length.

Remark:
    s The typical use of this is that if the shorter length is less
    than some tolerance the points swept out by the ellipse are the
    longer segment. (But beware that the start and end points of the
    segment can be other than the start and end points of the
    ellipse.)

:param (output):
    longSegment longer axis of local conic range box

:param (output):
    shortSegment shorter axis of local conic range box

:returns:
    size of the shorter dimension)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InitWithPerpendicularAxes =R"doc(@description Make a copy of the source ellipse, altering the axis
vectors and angular limits so that the revised ellipse has
perpendicular axes in the conventional major/minor axis form.

Remark:
    s Inputs may be the same.

:param (input):
    source ellipse with unconstrained axes)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_SetSweep =R"doc(@description Set the start and sweep angles of the ellipse.

:param (input):
    startAngle start angle

:param (input):
    sweepIN sweep angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_SetLimits =R"doc(@description Set the start and end angles of the ellipse.

:param (input):
    startAngle start angle

:param (input):
    endAngle end angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetSweep =R"doc(@description Get the start and sweep angles of the ellipse.

:param (output):
    startAngle start angle

:param (output):
    sweepAngle sweep angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetLimits =R"doc(@description Get the start and end angles of the ellipse.

:param (output):
    startAngle start angle

:param (output):
    endAngle end angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_AngleToFraction =R"doc(@description Convert an angular parameter to a fraction of bounded arc
length.

:param (input):
    angle angle (radians) to convert

:returns:
    fractional parameter)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsAngleInSweep =R"doc(@description Test if a specified angle is within the sweep of the
ellipse.

:param (input):
    angle angle (radians) to test

:returns:
    true if angle is within the sweep angle of the elliptical arc.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_TestAndEvaluateTrigPairs =R"doc(@description Evaluate an ellipse at a number of (cosine, sine) pairs,
removing pairs whose corresponding angle is not in range.

:param (output):
    point array of cartesian points

:param (input):
    trig array of local coords

:param (input):
    numPoint number of pairs

:returns:
    number of points found to be in the angular range of the ellipse.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_EvaluateTrigPairs =R"doc(@description Evaluate an ellipse using given coefficients for the
axes.

Remark:
    s If the x,y components of the coefficients define a unit vector,
    the point is " on " the ellipse.

:param (output):
    point array of cartesian points

:param (input):
    trig array of local coords (e.g., (cos, sin)).

:param (input):
    numPoint number of pairs)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetStrokeCount =R"doc(@description Compute an estimated number of points needed to stroke a
full ellipse to within the given chord height tolerance.

:param (input):
    nDefault default number of points on full ellipse

:param (input):
    nMax max number of points on full ellipse

:param (input):
    chordTol distance tolerance

:param (input):
    angleTol turning angle tolerance

:returns:
    number of strokes required on the full ellipse)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ProjectPointToPlane =R"doc(@description Project a point onto the plane of the ellipse.

:param (output):
    xYZNear projection of point onto ellipse plane

:param (output):
    coff0 coefficient on vector towards 0 degree point

:param (output):
    coff90 coefficient on vector towards 90 degree point

:param (input):
    xYZ point to project onto plane

:returns:
    true if the plane is well defined.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_PointToAngle =R"doc(@description Compute the angular position of the point relative to the
ellipse's local coordinates.

Remark:
    s If the point is on the ellipse, this is the inverse of
    evaluating the ellipse at the angle.

:param (input):
    point point to evaluate

:returns:
    angle in ellipse parameterization)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_PointToXYLocal =R"doc(@description Compute the local coordinates of a point in the skewed
coordinates of the ellipse, using only xy parts of both the ellipse
and starting point.

Remark:
    s This is equivalent to computing the intersection of the ellipse
    plane with a line through the point and parallel to the z axis,
    and returning the coordinates of the intersection relative to the
    skewed axes of the ellipse.

:param (output):
    localPoint evaluated point. Coordinates x,y are multipliers for
    the ellipse axes. Coordinate z is height of the initial point from
    the plane of the ellipse.

:param (input):
    point point to convert to local coordinates

:returns:
    true if ellipse axes are independent.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetXYLocalFrame =R"doc(@description Get the coordinate frame and inverse of an ellipse as
viewed along the global z axis.

:param (output):
    frame transformation from (cosine, sine, z) coordinates to global
    xyz.

:param (output):
    inverse inverse of frame.

:returns:
    true if the requested frames were returned.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetLocalFrame =R"doc(@description Get the coordinate frame for an ellipse. X,Y axes are at
0 and 90 degrees. Z axis is perpendicular with magnitude equal to the
geometric mean of the other two.

:param (output):
    frame transformation from (cosine, sine, z) coordinates to global
    xyz.

:param (output):
    inverse inverse of frame.

:returns:
    true if the requested frames were returned.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_DeterminantJXY =R"doc(@description Compute the determinant of the Jacobian matrix for the
transformation from local coordinates (cosine, sine) to global xy-
coordinates.

:returns:
    determinant of Jacobian.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FractionToAngle =R"doc(@description Convert a fractional parameter to ellipse
parameterization angle.

:param (input):
    fraction fraction of angular range

:returns:
    angular parameter)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FractionParameterToDerivatives =R"doc(@description Compute the ellipse xyz point and derivatives at a given
fraction of the angular parametric range.

:param (output):
    point3dX point on ellipse

:param (output):
    dX second derivative vector

:param (output):
    ddX second derivative vector

:param (input):
    fraction fractional parameter for evaluation)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FractionToPoint =R"doc(return ellipse point at fractional position in its angular sweep.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FractionParameterToPoint =R"doc(@description Compute the ellipse xyz point at a given fraction of the
angular parametric range.

:param (output):
    point3dX point on ellipse

:param (input):
    fraction fractional parameter for evaluation)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_EvaluateEndPoints =R"doc(@description Compute the ellipse start and end points.

:param (output):
    startPoint start point of ellipse

:param (output):
    endPoint end point of ellipse)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_Evaluate =R"doc(@description Compute the ellipse xyz point at a given parametric (xy)
coordinate.

:param (output):
    point evaluated point

:param (input):
    xx local x coordinate:cos(theta)

:param (input):
    yy local y coordinate:sin(theta))doc";

static const char * __doc_Bentley_Geom_DEllipse3d_RadiansToPoint =R"doc(@description return the point on the ellipse at parameteric angle.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_ComplementSweep =R"doc(@description Set the ellipse sweep to the complement of its current
angular range.

Remark:
    s Full ellipse is left unchanged.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_MakeFullSweep =R"doc(@description Set the ellipse sweep to a full 360 degrees (2pi
radians), preserving direction of sweep.

Remark:
    s Start angle is left unchanged.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsAlmostEqual =R"doc(:returns:
    true if AlmostEqual center, vectors, and angles.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsNearZeroRadius =R"doc(@description Test whether both vectors are near zero length.

:returns:
    true if both radii are near zero.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_IsFullEllipse =R"doc(@description Test whether the ellipse is complete (2pi range).

:returns:
    true if the ellipse is complete)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetScaledTransforms =R"doc(@description Extract major minor axis form of the ellipse.

:param (output):
    localToWorld orthogonal frame with origin at center, xy axes n
    major and minor axes.

:param (output):
    r0 scale factor for column 0

:param (output):
    r1 scale factor for column 1

:param (output):
    theta0 start angle

:param (output):
    sweep sweep angle

:param (output):
    worldToLocal inverse of localToWorld.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_GetScaledRotMatrix =R"doc(@description Extract major minor axis form of the ellipse.

:param (output):
    center ellipse center

:param (output):
    matrix columns 0, 1 are normalized ellipse basis vectors, column 2
    is their cross product

:param (output):
    r0 scale factor for column 0

:param (output):
    r1 scale factor for column 1

:param (output):
    theta0 start angle

:param (output):
    sweep sweep angle)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_SetStartEnd =R"doc(@description Set angular parameters to have given start and end
points.

Remark:
    s If the given points are really on the ellipse, this does the
    expected thing.

Remark:
    s If the given points are not on the ellipse, here's exactly what
    happens. The start/end points are placed on the original ellipse
    at the point where the ellipse intersects the plane formed by the
    ellipse axis and the given point. This leaves the problem that the
    ellipse defines two paths from the given start to end. This is
    resolved as follows. The ellipse's existing 0 and 90 degree
    vectors define a coordinate system. In that system, the short
    sweep from the 0 degree vector to the 90 degree vector is
    considered " counterclockwise ".

Remark:
    s Beware that the relation of supposed start/end points to the
    ellipse is ambiguous.

:param (input):
    startPoint new start point

:param (input):
    endPoint new end point

:param (input):
    ccw true to force counterclockwise direction, false for clockwise.

:returns:
    true if the ellipse axes are independent. false if the ellipse is
    degenerate.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InitArcFromPointTangentPoint =R"doc(@description Initialize a circular arc from start point, start
tangent, and end point.

:param (input):
    startIN start point

:param (input):
    tangent start tangent

:param (input):
    end end point

:returns:
    true if circular arc computed. false if start, end and tangent are
    colinear.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_InitArcFromPointPointArcLength =R"doc(@description Initialize a circlular arc from start point, end point,
another vector which determines the plane, and the arc length.

:param (input):
    startIN start point

:param (input):
    end end point

:param (input):
    arcLength required arc length

:param (input):
    planeVector vector to be used to determine the plane of the arc.
    The plane is chosen so that it contains both the start-to-end
    vector and the plane vector, and the arc bulge is in the direction
    of the plane vector (rather than opposite).

:returns:
    true if the arc length exceeds the chord length and the 2 points
    and plane vector determine a clear plane.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromRotatedAxes =R"doc(Return an ellipse that traverses the same points in space but has its
vector0 and vector90 axes shifted so that the parametric start takes
on specified value.

:param (input):
    source original ellipse.

:param (input):
    newStart the angle value that should be the start in the new
    ellispe.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromCopyWithPositiveSweep =R"doc(Return an ellipse that sweeps the same points in space (with identical
fraction-to-point results) but is driven by a positive sweep angle.

Remark:
    If the source ellipse has positive sweep it is simply copied back
    out. If it has a negative sweep, the start angle, sweep angle, and
    vector90 are negated. If a point is on the ellipse, its angular
    coordinate will be negated, but its fractional position is
    maintained.

:param (input):
    source original ellipse)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromNegateVector90 =R"doc(Return an ellipse that sweeps the same points in space (with identical
fraction-to-point results) but has negated vector90 (and hence negated
normal))doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromReversed =R"doc(Return an ellipse that sweeps the same points in space but in the
reversed direction.

:param (input):
    source original ellipse)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromPerpendicularAxes =R"doc(Return an ellispe that sweeps the same points as source but has axes
adjusted so vectors to parametric 0 and 90 degree points are
perpendicular. This may choose a " small " adjustment of the axes even
if the 90 degree axis ends up longer. Use FromMajorMinor to force the
0 degree direction to be the larger axis.

:param (input):
    source original ellipse, in which vectors might be non
    perpendicular.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromCenterNormalRadius =R"doc(Return an (full 360 degree) circular arc with given center, plane
normal, and radius.

:param (input):
    center ellipse center.

:param (input):
    normal plane normal.

:param (input):
    radius circle radius.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromMajorMinor =R"doc(Return an ellispe that sweeps the same points as source but has axes
adjusted so vectors to parametric 0 and 90 degree points are
perpendicular and the 0 degree vector is the customary major (larger)
direction.

:param (input):
    source original ellipse, in which vectors might be non
    perpendicular.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromScaledVectors =R"doc(Return an (arc of an) ellipse with axes defined directly by scaled
vectors.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromScaledRotMatrix =R"doc(Return an (arc of an) ellipse, with axes defined by a RotMatrix XY
columns and scale factors.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromVectors =R"doc(Return a (arc of an) ellipse with given 0 and 90 degree vectors.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromArcCenterStartEnd =R"doc(Return a circular arc with gven center and start. Endpoint is on the
vector to given endTarget. Sweep angle is the smaller of the two
possible sweeps.

:param (input):
    center circle center

:param (input):
    startPoint arc start point. This point determines the circle
    radius.

:param (input):
    endTarget Target point for end of circle. If it is at a different
    radius, the actual end point will be at the same radius as the
    start point.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromPointsOnArc =R"doc(@description Initialize an elliptical arc from 3 points.

:param (input):
    start start point

:param (input):
    middle mid point

:param (input):
    end end point)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromStartTangentNormalRadiusSweep =R"doc(Construct an arc from start point, start tangent, radius and sweep
(and plane normal))doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromPoints =R"doc(@description Returns a DEllipse3d with fill in ellipse data from
center, 0 degree, and 90 degree points.

:param (input):
    center ellipse center

:param (input):
    point0 0 degree point

:param (input):
    point90 90 degree point

:param (input):
    theta0 start angle

:param (input):
    sweep sweep angle

:returns:
    DEllipse3d object.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromXYMajorMinor =R"doc(@description Returns a DEllipse3d with fill in ellipse data from 2D
major and minor axis lengths and the angle from the global to the
local x-axis.

:param (input):
    cx center x coordinate

:param (input):
    cy center y coordinate

:param (input):
    cz z coordinate of all points on the ellipse

:param (input):
    rx radius along local x axis

:param (input):
    ry radius along local y axis

:param (input):
    thetaX angle from global x to local x

:param (input):
    theta0 start angle in parameter space

:param (input):
    sweep sweep angle

:returns:
    DEllipse3d object.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromFractionInterval =R"doc(@description Return an ellipse defined by fractional start and end on
a parent ellipse

:param (input):
    parent existing ellipse.

:param (input):
    startFraction fractional coordiante of new ellipse start on
    parent.

:param (input):
    endFraction fractional coordiante of new ellipse end on parent.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_FromCenterRadiusXY =R"doc(Return an xy-plane full circle with center and radius.)doc";

static const char * __doc_Bentley_Geom_DEllipse3d_From =R"doc(@description Returns a DEllipse3d with given fields.

:param (input):
    cx center x coordinate

:param (input):
    cy center y coordinate

:param (input):
    cz center z coordinate

:param (input):
    ux x part of 0 degree vector

:param (input):
    uy y part of 0 degree vector

:param (input):
    uz z part of 0 degree vector

:param (input):
    vx x part of 90 degree vector

:param (input):
    vy y part of 90 degree vector

:param (input):
    vz z part of 90 degree vector

:param (input):
    theta0 start angle in parameter space

:param (input):
    sweep sweep angle

:returns:
    DEllipse3d object.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DEllipse3d(py::module_& m)
    {
    //===================================================================================
    // struct DEllipse3d
    py::class_<DEllipse3d> c1(m, "DEllipse3d");
    bind_ValidatedValue<DEllipse3d>(m, "ValidatedDEllipse3d", py::module_local(false));
    py::bind_vector< bvector<DEllipse3d> >(m, "DEllipse3dArray", py::module_local(false));

    c1.def_readwrite("center", &DEllipse3d::center);
    c1.def_readwrite("vector0", &DEllipse3d::vector0);
    c1.def_readwrite("vector90", &DEllipse3d::vector90);
    c1.def_readwrite("start", &DEllipse3d::start);
    c1.def_readwrite("sweep", &DEllipse3d::sweep);

    c1.def(py::init<>());
    c1.def_static("From", &DEllipse3d::From, "cx"_a, "cy"_a, "cz"_a, "ux"_a, "uy"_a, "uz"_a, "vx"_a, "vy"_a, "vz"_a, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, From));
    c1.def_static("FromCenterRadiusXY", &DEllipse3d::FromCenterRadiusXY, "center"_a, "radius"_a, DOC(Bentley, Geom, DEllipse3d, FromCenterRadiusXY));
    c1.def_static("FromFractionInterval", &DEllipse3d::FromFractionInterval, "parent"_a, "startFraction"_a, "endFraction"_a, DOC(Bentley, Geom, DEllipse3d, FromFractionInterval));
    c1.def_static("FromXYMajorMinor", &DEllipse3d::FromXYMajorMinor, "cx"_a, "cy"_a, "cz"_a, "rx"_a, "ry"_a, "thetaX"_a, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, FromXYMajorMinor));
    c1.def_static("FromPoints", &DEllipse3d::FromPoints, "center"_a, "point0"_a, "point90"_a, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, FromPoints));
    c1.def_static("FromStartTangentNormalRadiusSweep", &DEllipse3d::FromStartTangentNormalRadiusSweep, "pointA"_a, "tangent"_a, "planeNormal"_a, "radius"_a, "sweepRadians"_a, DOC(Bentley, Geom, DEllipse3d, FromStartTangentNormalRadiusSweep));
    c1.def_static("FromPointsOnArc", &DEllipse3d::FromPointsOnArc, "start"_a, "middle"_a, "end"_a, DOC(Bentley, Geom, DEllipse3d, FromPointsOnArc));
    c1.def_static("FromArcCenterStartEnd", &DEllipse3d::FromArcCenterStartEnd, "center"_a, "startPoint"_a, "endTarget"_a, DOC(Bentley, Geom, DEllipse3d, FromArcCenterStartEnd));
    c1.def_static("FromVectors", &DEllipse3d::FromVectors, "center"_a, "vector0"_a, "vector90"_a, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, FromVectors));
    c1.def_static("FromScaledRotMatrix", &DEllipse3d::FromScaledRotMatrix, "center"_a, "matrix"_a, "r0"_a, "r90"_a, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, FromScaledRotMatrix));
    c1.def_static("FromScaledVectors", 
                  py::overload_cast<DPoint3dCR, DVec3dCR, DVec3dCR, double, double, double, double>(&DEllipse3d::FromScaledVectors), 
                  "center"_a, "vector0"_a, "vector90"_a, "r0"_a, "r90"_a, "theta0"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, FromScaledVectors));
    c1.def_static("FromScaledVectors", py::overload_cast<DEllipse3dCR, double>(&DEllipse3d::FromScaledVectors), "source"_a, "factor"_a, DOC(Bentley, Geom, DEllipse3d, FromScaledVectors));
    c1.def_static("FromMajorMinor", &DEllipse3d::FromMajorMinor, "source"_a, DOC(Bentley, Geom, DEllipse3d, FromMajorMinor));
    c1.def_static("FromCenterNormalRadius", &DEllipse3d::FromCenterNormalRadius, "center"_a, "normal"_a, "radius"_a, DOC(Bentley, Geom, DEllipse3d, FromCenterNormalRadius));
    c1.def_static("FromPerpendicularAxes", &DEllipse3d::FromPerpendicularAxes, "source"_a, DOC(Bentley, Geom, DEllipse3d, FromPerpendicularAxes));        
    c1.def_static("FromReversed", &DEllipse3d::FromReversed, "source"_a, DOC(Bentley, Geom, DEllipse3d, FromReversed));
    c1.def("FromNegateVector90", &DEllipse3d::FromNegateVector90, "source"_a, DOC(Bentley, Geom, DEllipse3d, FromNegateVector90));
    c1.def_static("FromCopyWithPositiveSweep", &DEllipse3d::FromCopyWithPositiveSweep, "source"_a, DOC(Bentley, Geom, DEllipse3d, FromCopyWithPositiveSweep));
    c1.def_static("FromRotatedAxes", &DEllipse3d::FromRotatedAxes, "source"_a, "newStart"_a, DOC(Bentley, Geom, DEllipse3d, FromRotatedAxes));

    c1.def("InitArcFromPointPointArcLength", &DEllipse3d::InitArcFromPointPointArcLength, "startIN"_a, "end"_a, "arcLength"_a, "planeVector"_a, DOC(Bentley, Geom, DEllipse3d, InitArcFromPointPointArcLength));
    c1.def("InitArcFromPointTangentPoint", &DEllipse3d::InitArcFromPointTangentPoint, "startIN"_a, "tangent"_a, "end"_a, DOC(Bentley, Geom, DEllipse3d, InitArcFromPointTangentPoint));
    c1.def("SetStartEnd", &DEllipse3d::SetStartEnd, "startPoint"_a, "endPoint"_a, "ccw"_a, DOC(Bentley, Geom, DEllipse3d, SetStartEnd)); 
    c1.def("Init", &DEllipse3d::Init, "cx"_a, "cy"_a, "cz"_a, "ux"_a, "uy"_a, "uz"_a, "vx"_a, "vy"_a, "vz"_a, "theta0"_a, "sweep"_a);
    c1.def("InitFromPoints", &DEllipse3d::InitFromPoints, "center0"_a, "point0"_a, "point90"_a, "startRadiansIn"_a, "sweepIn"_a);
    c1.def("InitFromPointsOnArc", &DEllipse3d::InitFromPointsOnArc, "start"_a, "middle"_a, "end"_a);
    c1.def("InitArcFromPointTangentPoint", &DEllipse3d::InitArcFromPointTangentPoint, "startIn"_a, "tangent"_a, "end"_a);
    c1.def("InitFromArcCenterStartEnd", &DEllipse3d::InitFromArcCenterStartEnd, "centerIn"_a, "startIn"_a, "end"_a);
    c1.def("InitFromVectors", &DEllipse3d::InitFromVectors, "centerIn"_a, "vector01In"_a, "vector90In"_a, "startRadiansIn"_a, "sweepIn"_a);

    c1.def("GetScaledRotMatrix", [] (DEllipse3dCR self)
        {
        DPoint3d center;
        RotMatrix matrix;
        double r0, r1, theta0, sweep;
        self.GetScaledRotMatrix(center, matrix, r0, r1, theta0, sweep);
        return py::make_tuple(center, matrix, r0, r1, theta0, sweep);
        }, DOC(Bentley, Geom, DEllipse3d, GetScaledRotMatrix));

    c1.def("GetScaledTransforms", [] (DEllipse3dCR self)
        {
        Transform localToWorld, worldToLocal;
        double r0, r1, theta0, sweep;
        self.GetScaledTransforms(localToWorld, r0, r1, theta0, sweep, worldToLocal);
        return py::make_tuple(localToWorld, r0, r1, theta0, sweep, worldToLocal);
        }, DOC(Bentley, Geom, DEllipse3d, GetScaledTransforms));    

    c1.def("IsFullEllipse", &DEllipse3d::IsFullEllipse, DOC(Bentley, Geom, DEllipse3d, IsFullEllipse));
    c1.def("IsNearZeroRadius", &DEllipse3d::IsNearZeroRadius, DOC(Bentley, Geom, DEllipse3d, IsNearZeroRadius));
    c1.def("IsAlmostEqual", &DEllipse3d::IsAlmostEqual, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DEllipse3d, IsAlmostEqual));        
    
    c1.def("MakeFullSweep", &DEllipse3d::MakeFullSweep, DOC(Bentley, Geom, DEllipse3d, MakeFullSweep));
    c1.def("ComplementSweep", &DEllipse3d::ComplementSweep, DOC(Bentley, Geom, DEllipse3d, ComplementSweep));
    c1.def("RadiansToPoint", &DEllipse3d::RadiansToPoint, "theta"_a, DOC(Bentley, Geom, DEllipse3d, RadiansToPoint));
        
    c1.def("Evaluate", py::overload_cast<DPoint3dR, double, double>(&DEllipse3d::Evaluate, py::const_), "point"_a, "xx"_a, "yy"_a, DOC(Bentley, Geom, DEllipse3d, Evaluate));
    c1.def("Evaluate", py::overload_cast<DPoint3dR, DVec3dR, DVec3dR, double>(&DEllipse3d::Evaluate, py::const_), "point3dX"_a, "dX"_a, "ddX"_a, "theta"_a, DOC(Bentley, Geom, DEllipse3d, Evaluate));
    c1.def("Evaluate", [] (DEllipse3dCR self, int numDerivative, double theta)
           {
           py::list outVal;
           if (numDerivative >= 0)
               {
               DPoint3dArray pnts(numDerivative + 1);
               self.Evaluate(&pnts[0], numDerivative, theta);
               for (DPoint3d& pt : pnts)
                   outVal.append(py::cast(pt));
               }
           return outVal;
           }, "numDerivative"_a, "theta"_a);
           
    c1.def("EvaluateEndPoints", &DEllipse3d::EvaluateEndPoints, "startPoint"_a, "endPoint"_a, DOC(Bentley, Geom, DEllipse3d, EvaluateEndPoints));

    c1.def("FractionParameterToPoint", &DEllipse3d::FractionParameterToPoint, "point3dX"_a, "fraction"_a, DOC(Bentley, Geom, DEllipse3d, FractionParameterToPoint));
    c1.def("FractionToPoint", &DEllipse3d::FractionToPoint, "fraction"_a, DOC(Bentley, Geom, DEllipse3d, FractionToPoint));
    c1.def("FractionParameterToDerivatives", &DEllipse3d::FractionParameterToDerivatives, "point3dX"_a, "dX"_a, "ddX"_a, "fraction"_a, DOC(Bentley, Geom, DEllipse3d, FractionParameterToDerivatives));
    c1.def("FractionToAngle", &DEllipse3d::FractionToAngle, "fraction"_a, DOC(Bentley, Geom, DEllipse3d, FractionToAngle));

    c1.def("DeterminantJXY", &DEllipse3d::DeterminantJXY, DOC(Bentley, Geom, DEllipse3d, DeterminantJXY));
        
    c1.def("GetLocalFrame", &DEllipse3d::GetLocalFrame, "frame"_a, "inverse"_a, DOC(Bentley, Geom, DEllipse3d, GetLocalFrame));
    c1.def("GetXYLocalFrame", &DEllipse3d::GetXYLocalFrame, "frame"_a, "inverse"_a, DOC(Bentley, Geom, DEllipse3d, GetXYLocalFrame));

    c1.def("PointToXYLocal", &DEllipse3d::PointToXYLocal, "localPoint"_a, "point"_a, DOC(Bentley, Geom, DEllipse3d, PointToXYLocal));
    c1.def("PointToAngle", &DEllipse3d::PointToAngle, "point"_a, DOC(Bentley, Geom, DEllipse3d, PointToAngle));

    c1.def("ProjectPointToPlane", [] (DEllipse3dCR self, DPoint3dCR xyz)
        {
        DPoint3d xyzNear = DPoint3d::FromZero();
        double coff0 = 0;
        double coff90 = 0;
        bool bOk = self.ProjectPointToPlane(xyzNear, coff0, coff90, xyz);
        return py::make_tuple(bOk, xyzNear, coff0, coff90);
        }, "xyz"_a, DOC(Bentley, Geom, DEllipse3d, ProjectPointToPlane));

    c1.def("GetStrokeCount", &DEllipse3d::GetStrokeCount, "nDefault"_a = 12, "nMax"_a = 180, "chordTol"_a = 0.0, "angTol"_a = 0.0, DOC(Bentley, Geom, DEllipse3d, GetStrokeCount));
    //c1.def("EvaluateTrigPairs", &DEllipse3d::EvaluateTrigPairs, "point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, EvaluateTrigPairs));
    c1.def("EvaluateTrigPairs", [](DEllipse3dCR self, DPoint3dArray& point, DPoint2dArray const& trig, int numPoint)
            {            
            self.EvaluateTrigPairs(&point[0], &trig[0], numPoint);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, EvaluateTrigPairs));
    c1.def("EvaluateTrigPairs", [](DEllipse3dCR self, py::list& point, DPoint2dArray const& trig, int numPoint)
            {  
            CONVERT_PYLIST_TO_NEW_CPPARRAY(point, cppPoint, DPoint3dArray, DPoint3d);          
            self.EvaluateTrigPairs(&cppPoint[0], &trig[0], numPoint);
            CONVERT_CPPARRAY_TO_PYLIST(point, cppPoint, DPoint3dArray, DPoint3d);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, EvaluateTrigPairs));
    c1.def("EvaluateTrigPairs", [](DEllipse3dCR self, DPoint3dArray& point, py::list const& trig, int numPoint)
            { 
            CONVERT_PYLIST_TO_NEW_CPPARRAY(trig, cppTrig, DPoint2dArray, DPoint2d);         
            self.EvaluateTrigPairs(&point[0], &cppTrig[0], numPoint);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, EvaluateTrigPairs));
    c1.def("EvaluateTrigPairs", [](DEllipse3dCR self, py::list& point, py::list const& trig, int numPoint)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(point, cppPoint, DPoint3dArray, DPoint3d); 
            CONVERT_PYLIST_TO_NEW_CPPARRAY(trig, cppTrig, DPoint2dArray, DPoint2d);        
            self.EvaluateTrigPairs(&cppPoint[0], &cppTrig[0], numPoint);
            CONVERT_CPPARRAY_TO_PYLIST(point, cppPoint, DPoint3dArray, DPoint3d);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, EvaluateTrigPairs));
    c1.def("TestAndEvaluateTrigPairs", [](DEllipse3dCR self, DPoint3dArray& point, DPoint2dArray const& trig, int numPoint)
            {
            return self.TestAndEvaluateTrigPairs(&point[0], &trig[0], numPoint);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, TestAndEvaluateTrigPairs));
    c1.def("TestAndEvaluateTrigPairs", [](DEllipse3dCR self, py::list& point, DPoint2dArray const& trig, int numPoint)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(point, cppPoint, DPoint3dArray, DPoint3d);    
            return self.TestAndEvaluateTrigPairs(&cppPoint[0], &trig[0], numPoint);    
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, TestAndEvaluateTrigPairs));
    c1.def("TestAndEvaluateTrigPairs", [](DEllipse3dCR self, DPoint3dArray& point, py::list const& trig, int numPoint)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(trig, cppTrig, DPoint2dArray, DPoint2d);
            return self.TestAndEvaluateTrigPairs(&point[0], &cppTrig[0], numPoint);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, TestAndEvaluateTrigPairs));
    c1.def("TestAndEvaluateTrigPairs", [](DEllipse3dCR self, py::list& point, py::list const& trig, int numPoint)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(point, cppPoint, DPoint3dArray, DPoint3d); 
            CONVERT_PYLIST_TO_NEW_CPPARRAY(trig, cppTrig, DPoint2dArray, DPoint2d);
            return self.TestAndEvaluateTrigPairs(&cppPoint[0], &cppTrig[0], numPoint);
            },"point"_a, "trig"_a, "numPoint"_a, DOC(Bentley, Geom, DEllipse3d, TestAndEvaluateTrigPairs));
    c1.def("IsAngleInSweep", &DEllipse3d::IsAngleInSweep, "angle"_a, DOC(Bentley, Geom, DEllipse3d, IsAngleInSweep));        
    c1.def("AngleToFraction", &DEllipse3d::AngleToFraction, "angle"_a, DOC(Bentley, Geom, DEllipse3d, AngleToFraction));

    c1.def("GetLimits", [] (DEllipse3dCR self)
        {
        double startAngle, endAngle;
        self.GetLimits(startAngle, endAngle);
        return py::make_tuple(startAngle, endAngle);
        }, DOC(Bentley, Geom, DEllipse3d, GetLimits));

    c1.def("GetSweep", [] (DEllipse3dCR self)
        {
        double startAngle, sweepAngle;
        self.GetSweep(startAngle, sweepAngle);
        return py::make_tuple(startAngle, sweepAngle);
        }, DOC(Bentley, Geom, DEllipse3d, GetSweep));

        
    c1.def("SetLimits", &DEllipse3d::SetLimits, "startAngle"_a, "endAngle"_a, DOC(Bentley, Geom, DEllipse3d, SetLimits));
    c1.def("SetSweep", &DEllipse3d::SetSweep, "startAngle"_a, "sweep"_a, DOC(Bentley, Geom, DEllipse3d, SetSweep));

    c1.def("InitWithPerpendicularAxes", &DEllipse3d::InitWithPerpendicularAxes, "source"_a, DOC(Bentley, Geom, DEllipse3d, InitWithPerpendicularAxes));
    c1.def("GetMajorMinorRangeMidlines", &DEllipse3d::GetMajorMinorRangeMidlines, "longSegment"_a, "shortSegment"_a, DOC(Bentley, Geom, DEllipse3d, GetMajorMinorRangeMidlines));

    c1.def("TangentMagnitude", &DEllipse3d::TangentMagnitude, "theta"_a, DOC(Bentley, Geom, DEllipse3d, TangentMagnitude));
    c1.def("ArcLength", &DEllipse3d::ArcLength, DOC(Bentley, Geom, DEllipse3d, ArcLength));
    c1.def("InverseArcLength", &DEllipse3d::InverseArcLength, "arcLength"_a, DOC(Bentley, Geom, DEllipse3d, InverseArcLength));

    c1.def("FractionToLength", [] (DEllipse3dCR self, double fraction0, double fraction1)
        {
        double arcLen = 0;
        bool bOK = self.FractionToLength(arcLen, fraction0, fraction1);
        return py::make_tuple(bOK, arcLen);
        }, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, DEllipse3d, FractionToLength));

    c1.def("GetRange", &DEllipse3d::GetRange, "range"_a, DOC(Bentley, Geom, DEllipse3d, GetRange));

    c1.def("GetLocalRange", &DEllipse3d::GetLocalRange, "range"_a, DOC(Bentley, Geom, DEllipse3d, GetLocalRange));

    c1.def("ProjectedParameterRange", &DEllipse3d::ProjectedParameterRange, "ray"_a, DOC(Bentley, Geom, DEllipse3d, ProjectedParameterRange));

    c1.def("IntersectPlane", [] (DEllipse3dCR self, DPoint4dCR plane)
        {
        DPoint3d ip[2];
        py::list outVal;
        int nPnts = self.IntersectPlane(ip, plane);
        for (int i = 0; i < nPnts; i++)
            outVal.append(ip[i]);
        
        return outVal;
        }, "plane"_a, DOC(Bentley, Geom, DEllipse3d, IntersectPlane));

    c1.def("SolveTangentsPerpendicularToVector", [] (DEllipse3dCR self, DVec3dR vector)
        {
        double angles[2] = {0};
        py::list outVal;
        int nVals = self.SolveTangentsPerpendicularToVector(angles, vector);
        for (int i = 0; i < nVals; i++)
            outVal.append(angles[i]);

        return outVal;
        }, "vector"_a, DOC(Bentley, Geom, DEllipse3d, SolveTangentsPerpendicularToVector));

    c1.def("IntersectXYLine", [] (DEllipse3dCR self, DPoint3dCR startPoint, DPoint3dCR endPoint)
        {
        DPoint3d points[2];
        double lineParams[2];
        DPoint3d coffs[2];
        double angles[2];
        py::list outVal;
        int nPnts = self.IntersectXYLine(points, lineParams, coffs, angles, startPoint, endPoint);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], lineParams[i], coffs[i], angles[i]);
            outVal.append(item);
            }
        
        return outVal;
        }, "startPoint"_a, "endPoint"_a);
        
    c1.def("IsCircular", py::overload_cast<>(&DEllipse3d::IsCircular, py::const_), DOC(Bentley, Geom, DEllipse3d, IsCircular));

    c1.def("IsCircular", [] (DEllipse3dCR self)
        {
        double radius = 0;
        return py::make_tuple(self.IsCircular(radius), radius);
        }, DOC(Bentley, Geom, DEllipse3d, IsCircular));

    c1.def("IsCircularXY", py::overload_cast<>(&DEllipse3d::IsCircularXY, py::const_), DOC(Bentley, Geom, DEllipse3d, IsCircularXY));

    c1.def("IsCircularXY", [] (DEllipse3dCR self)
        {
        double radius = 0;
        return py::make_tuple(self.IsCircularXY(radius), radius);
        }, DOC(Bentley, Geom, DEllipse3d, IsCircularXY));        

    c1.def("IsCCWSweepXY", &DEllipse3d::IsCCWSweepXY, DOC(Bentley, Geom, DEllipse3d, IsCCWSweepXY));
        
    c1.def("IntersectXYDEllipse3d", [] (DEllipse3dCR self, DEllipse3dCR ellipse1)
        {
        DPoint3d points[4];
        DPoint3d e0params[4];
        DPoint3d e1params[4];
        py::list outVal;
        int nPnts = self.IntersectXYDEllipse3d(points, e0params, e1params, ellipse1);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], e0params[i], e1params[i]);
            outVal.append(item);
            }

        return outVal;
        }, "ellipse1"_a);

    c1.def("IntersectXYDEllipse3dBounded", [] (DEllipse3dCR self, DEllipse3dCR ellipse1)
        {
        DPoint3d points[4];
        DPoint3d e0coffs[4];
        double e0angles[4];
        DPoint3d e1coffs[4];
        double e1angles[4];        
        py::list outVal;
        int nPnts = self.IntersectXYDEllipse3dBounded(points, e0coffs, e0angles, e1coffs, e1angles, ellipse1);

        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], e0coffs[i], e0angles[i], e1coffs[i], e1angles[i]);
            outVal.append(item);
            }

        return outVal;
        }, "ellipse1"_a);

    c1.def("IntersectSweptDEllipse3d", [] (DEllipse3dCR self, DEllipse3dCR ellipse1)
        {
        DPoint3d points[5];
        DPoint3d e0params[5];
        DPoint3d e1params[5];
        py::list outVal;
        int nPnts = self.IntersectSweptDEllipse3d(points, e0params, e1params, ellipse1);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], e0params[i], e1params[i]);
            outVal.append(item);
            }

        return outVal;
        }, "ellipse1"_a);

    c1.def("IntersectSweptDEllipse3dBounded", [] (DEllipse3dCR self, DEllipse3dCR ellipse1)
        {
        DPoint3d points[5];
        DPoint3d e0coffs[5];
        double e0angles[5];
        DPoint3d e1coffs[5];
        double e1angles[5];
        py::list outVal;
        int nPnts = self.IntersectSweptDEllipse3dBounded(points, e0coffs, e0angles, e1coffs, e1angles, ellipse1);

        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], e0coffs[i], e0angles[i], e1coffs[i], e1angles[i]);
            outVal.append(item);
            }

        return outVal;
        }, "ellipse1"_a);

    c1.def("IntersectSweptDSegment3d", [] (DEllipse3dCR self, DSegment3dCR segment)
        {
        DPoint3d points[5];
        DPoint3d elparams[5];
        double lnparams[5];
        py::list outVal;
        int nPnts = self.IntersectSweptDSegment3d(points, elparams, lnparams, segment);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], elparams[i], lnparams[i]);
            outVal.append(item);
            }

        return outVal;
        }, "segment"_a);

    c1.def("IntersectSweptDSegment3dBounded", [] (DEllipse3dCR self, DSegment3dCR segment)
        {
        DPoint3d points[5];
        DPoint3d elparams[5];
        double lnparams[5];
        py::list outVal;
        int nPnts = self.IntersectSweptDSegment3dBounded(points, elparams, lnparams, segment);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], elparams[i], lnparams[i]);
            outVal.append(item);
            }

        return outVal;
        }, "segment"_a);

    c1.def("ProjectPoint", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        DPoint3d points[4];
        double angles[4];
        py::list outVal;
        int nPnts = self.ProjectPoint(points, angles, point);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], angles[i]);
            outVal.append(item);
            }

        return outVal;
        }, "point"_a);

    c1.def("ProjectPointXY", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        DPoint3d points[4];
        double angles[4];
        py::list outVal;
        int nPnts = self.ProjectPointXY(points, angles, point);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], angles[i]);
            outVal.append(item);
            }

        return outVal;
        }, "point"_a);

    c1.def("ProjectPointXYBounded", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        DPoint3d points[4];
        double angles[4];
        py::list outVal;
        int nPnts = self.ProjectPointXYBounded(points, angles, point);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], angles[i]);
            outVal.append(item);
            }

        return outVal;
        }, "point"_a);

    c1.def("ProjectPointBounded", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        DPoint3d points[4];
        double angles[4];
        py::list outVal;
        int nPnts = self.ProjectPointBounded(points, angles, point);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], angles[i]);
            outVal.append(item);
            }

        return outVal;
        }, "point"_a);

    c1.def("ClosestPointXYBounded", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        double minAngle, minDistanceSquared;
        DPoint3d minPoint;
        bool bOk = self.ClosestPointXYBounded(minAngle, minDistanceSquared, minPoint, point);
        return py::make_tuple(bOk, minAngle, minDistanceSquared, minPoint);
        }, "point"_a, DOC(Bentley, Geom, DEllipse3d, ClosestPointXYBounded));

    c1.def("ClosestPointBounded", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        double minAngle, minDistanceSquared;
        DPoint3d minPoint;
        bool bOk = self.ClosestPointBounded(minAngle, minDistanceSquared, minPoint, point);
        return py::make_tuple(bOk, minAngle, minDistanceSquared, minPoint);
        }, "point"_a, DOC(Bentley, Geom, DEllipse3d, ClosestPointBounded));

    c1.def("IntersectXYLineBounded", [] (DEllipse3dCR self, DPoint3dCR startPoint, DPoint3dCR endPoint)
        {
        DPoint3d points[5];        
        double lnparams[5];
        DPoint3d elcoffs[5];
        double elangles[5];
        bool isTangency[5];
        py::list outVal;
        int nPnts = self.IntersectXYLineBounded(points, lnparams, elcoffs, elangles, isTangency, startPoint, endPoint);

        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(points[i], elcoffs[i], elangles[i], isTangency[i]);
            outVal.append(item);
            }

        return outVal;
        }, "startPoint"_a, "endPoint"_a);
    
    c1.def("XySweepProperties", [] (DEllipse3dCR self, DPoint3dCR point)
        {
        double area, sweepOut;
        self.XySweepProperties(area, sweepOut, point);
        return py::make_tuple(area, sweepOut);
        }, "point"_a, DOC(Bentley, Geom, DEllipse3d, XySweepProperties));
        
    c1.def("InitFromCenterMajorAxisPointAndThirdPoint", &DEllipse3d::InitFromCenterMajorAxisPointAndThirdPoint, "center"_a, "point0"_a, "point1"_a, DOC(Bentley, Geom, DEllipse3d, InitFromCenterMajorAxisPointAndThirdPoint));

    c1.def("ClosestApproach", [] (DEllipse3dCR self, DRay3dCR ray)
        {
        double elangles[4];
        double rayFractions[4];
        DPoint3d elPoints[4];
        DPoint3d rayPoints[4];
        py::list outVal;
        int nPnts = self.ClosestApproach(elangles, rayFractions, elPoints, rayPoints, ray);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(elangles[i], rayFractions[i], elPoints[i], rayPoints[i]);
            outVal.append(item);
            }

        return outVal;
        }, "ray"_a);
    
    c1.def("InitFromDGNFields3d",
           py::overload_cast<DPoint3dCR, DVec3dCR, DVec3dCR, double, double, double, double>(&DEllipse3d::InitFromDGNFields3d), 
           "center"_a, "directionX"_a, "directionY"_a, "rX"_a, "rY"_a, "startAngle"_a, "sweepAngle"_a, DOC(Bentley, Geom, DEllipse3d, InitFromDGNFields3d));

    c1.def("InitFromDGNFields3d", [] (DEllipse3dR ell, DPoint3dCR center, DPoint4dCR quat, double rX, double rY, double startAngle, double sweepAngle)
        {
        ell.InitFromDGNFields3d(center, (double const*) &quat, rX, rY, startAngle, sweepAngle);
        }, "center"_a, "quatWXYZ"_a, "rX"_a, "rY"_a, "startAngle"_a, "sweepAngle"_a, DOC(Bentley, Geom, DEllipse3d, InitFromDGNFields3d));

    c1.def("InitFromDGNFields2d",
           py::overload_cast<DPoint2dCR, DVec2dCR, double, double, double, double, double>(&DEllipse3d::InitFromDGNFields2d),
           "center"_a, "direction0"_a, "rX"_a, "rY"_a, "startAngle"_a, "sweepAngle"_a, "zDepth"_a, DOC(Bentley, Geom, DEllipse3d, InitFromDGNFields2d));

    c1.def("InitFromDGNFields2d",
           py::overload_cast<DPoint2dCR, double, double, double, double, double, double>(&DEllipse3d::InitFromDGNFields2d),
           "center"_a, "xAngle"_a, "rX"_a, "rY"_a, "startAngle"_a, "sweepAngle"_a, "zDepth"_a, DOC(Bentley, Geom, DEllipse3d, InitFromDGNFields2d));

    c1.def("GetDGNFields3d", [] (DEllipse3dCR self)
        {
        DPoint3d center;
        DPoint4d quat;
        DVec3d dirX, dirY;
        double rX, rY, startAngle, sweepAngle;
        self.GetDGNFields3d(center, (double*) &quat, dirX, dirY, rX, rY, startAngle, sweepAngle);
        return py::make_tuple(center, quat, dirX, dirY, rX, rY, startAngle, sweepAngle);
        }, DOC(Bentley, Geom, DEllipse3d, GetDGNFields3d));

    c1.def("GetDGNFields2d", [] (DEllipse3dCR self)
        {
        DPoint2d center;
        double xAngle;
        DVec2d dir0;
        double rX, rY, startAngle, sweepAngle;
        self.GetDGNFields2d(center, xAngle, dir0, rX, rY, startAngle, sweepAngle);
        return py::make_tuple(center, xAngle, dir0, rX, rY, startAngle, sweepAngle);
        }, DOC(Bentley, Geom, DEllipse3d, GetDGNFields2d));

    c1.def("AlignedRange", &DEllipse3d::AlignedRange, "localToGlobal"_a, "globalToLocal"_a, "range"_a, DOC(Bentley, Geom, DEllipse3d, AlignedRange));

    c1.def_property_readonly("MaxAbs", &DEllipse3d::MaxAbs);

    c1.def("ClosestPointBoundedXY", [] (DEllipse3dCR self, DPoint3dCR spacePoint, DMatrix4dCP worldToLocal)
        {
        DPoint3d closePoint = DPoint3d::FromZero();
        double closeParam = 0.0;
        double distanceXY = 0.0;
        bool bOk = self.ClosestPointBoundedXY(closePoint, closeParam, distanceXY, spacePoint, worldToLocal);
        return py::make_tuple(bOk, closePoint, closeParam, distanceXY);
        }, "spacePoint"_a, "worldToLocal"_a, DOC(Bentley, Geom, DEllipse3d, ClosestPointBoundedXY));

    c1.def("ClosestPointBoundedXY", [] (DEllipse3dCR self, DPoint3dCR spacePoint, DMatrix4dCP worldToLocal, bool extend0, bool extend1)
        {
        DPoint3d closePoint = DPoint3d::FromZero();
        double closeParam = 0.0;
        double distanceXY = 0.0;
        bool bOk = self.ClosestPointBoundedXY(closePoint, closeParam, distanceXY, spacePoint, worldToLocal, extend0, extend1);
        return py::make_tuple(bOk, closePoint, closeParam, distanceXY);
        }, "spacePoint"_a, "worldToLocal"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, DEllipse3d, ClosestPointBoundedXY));
        
    
    c1.def("WireCentroid", [] (DEllipse3dCR self, double fraction0, double fraction1)
        {
        double len = 0.0;
        DPoint3d centroid;
        self.WireCentroid(len, centroid, fraction0, fraction1);
        return py::make_tuple(len, centroid);
        }, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, DEllipse3d, WireCentroid));

    c1.def_static("Construct_XRadius_YRadius_XPoint_EdgePoint", &DEllipse3d::Construct_XRadius_YRadius_XPoint_EdgePoint, "ellipses"_a, "a"_a, "b"_a, "xPoint"_a, "edgePoint"_a, DOC(Bentley, Geom, DEllipse3d, Construct_XRadius_YRadius_XPoint_EdgePoint));

    c1.def_static("Construct_XPoint_EdgePoint_EdgePoint_XRadius", 
                  &DEllipse3d::Construct_XPoint_EdgePoint_EdgePoint_XRadius, "ellipses"_a, "xPoint"_a, "edgePoint0"_a, "edgePoint1"_a, "a"_a, DOC(Bentley, Geom, DEllipse3d, Construct_XPoint_EdgePoint_EdgePoint_XRadius));

    c1.def_static("TryConstruct_EdgePoint_XPoint_EdgePoint_XAngle", 
                  &DEllipse3d::TryConstruct_EdgePoint_XPoint_EdgePoint_XAngle, "ellipse"_a, "edgePoint0"_a, "xPoint"_a, "edgePoint1"_a, "xAngle"_a, DOC(Bentley, Geom, DEllipse3d, TryConstruct_EdgePoint_XPoint_EdgePoint_XAngle));

    c1.def_static("Construct_Point_Direction_TangentXY",
                  &DEllipse3d::Construct_Point_Direction_TangentXY, "ellipses"_a, "fractionB"_a, "pointA"_a, "directionA"_a, "ray"_a, DOC(Bentley, Geom, DEllipse3d, Construct_Point_Direction_TangentXY));

    c1.def("__repr__", [] (DEllipse3d& self)
           {
           return "(center:{}, vector0:{}, vector90:{}, start:{}, sweep:{})"_s
               .format(self.center, self.vector0, self.vector90, self.start, self.sweep);
           });

    c1.def("__copy__", [](const DEllipse3d& self)
        {
        return DEllipse3d (self);
        });
    }