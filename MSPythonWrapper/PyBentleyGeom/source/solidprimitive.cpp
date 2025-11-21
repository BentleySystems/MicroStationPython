/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\solidprimitive.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_ISolidPrimitive_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:param (input):
    eyePoint For flat view, the view direction with weight=0. For
    perspective, the eye point with weight=1.

:param (input):
    curves silhouette curves.

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ComputeFacetedPrincipalAreaMoments =R"doc(Return the volume, centroid, orientation, and principal momentsof the
surface area (shell), using a faceted approximation.

Remark:
    This method only attempts faceted computations. Use
    ComputePrincipalMoments to get exact moments.

:param (input):
    options optional controls for facets

:param (input):
    options optional controls for facet density.

:param (output):
    area surface area

:param (output):
    centroid centroid

:param (output):
    axes columns of this matrix are the principal directions.

:param (output):
    momentxyz moments (yy+zz,xx+zz,xx+yy) around the principal
    directions.

:returns:
    false if (a) solid primitive is not capped or (b) facets failed.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ComputePrincipalAreaMoments =R"doc(Return the volume, centroid, orientation, and principal moments of the
surface area (shell) using most accurate (possibly exact) formulas.

Remark:
    This method only attempts " exact " computations. Use
    ComputeFacetedPrincipalMoments to get approximate moments.

:param (output):
    area surface area

:param (output):
    centroid centroid

:param (output):
    axes columns of this matrix are the principal directions.

:param (output):
    momentxyz moments (yy+zz,xx+zz,xx+yy) around the principal
    directions.

:returns:
    false if (a) solid primitive is not capped or (b) high accuracy
    moments are not supported for this type.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ComputeFacetedPrincipalMoments =R"doc(Return the volume, centroid, orientation, and principal moments, using
a faceted approximation.

Remark:
    This method only attempts faceted computations. Use
    ComputePrincipalMoments to get exact moments.

:param (input):
    options optional controls for facets

:param (input):
    options optional controls for facet density.

:param (output):
    volume volume

:param (output):
    centroid centroid

:param (output):
    axes columns of this matrix are the principal directions.

:param (output):
    momentxyz moments (yy+zz,xx+zz,xx+yy) around the principal
    directions.

:returns:
    false if (a) solid primitive is not capped or (b) facets failed.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ComputePrincipalMoments =R"doc(Return the volume, centroid, orientation, and principal moments using
most accurate (possibly exact) formulas.

Remark:
    This method only attempts " exact " computations. Use
    ComputeFacetedPrincipalMoments to get approximate moments.

:param (output):
    volume volume

:param (output):
    centroid centroid

:param (output):
    axes columns of this matrix are the principal directions.

:param (output):
    momentxyz moments (yy+zz,xx+zz,xx+yy) around the principal
    directions.

:returns:
    false if (a) solid primitive is not capped or (b) high accuracy
    moments are not supported for this type.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_HasCurvedFaceOrEdge =R"doc(Return true if solid primitve has a non-linear edge or non-planar
face.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_Simplify =R"doc(Detect a solid primitive that could be represented as a simpler type
and change it to the simple type. Tests for rotational sweeps that are
a sphere or torus as well as ruled sweeps that are a box, cone, or
extrusion.

:returns:
    true if input primitive was simplified.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_Clone =R"doc(Deep copy.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive. This is usually a single primitive, but can have a
disjoint, multi-component child for cut of non-convex cap,

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive. This is usually a single primitive, but can have a
disjoint, multi-component child for cut of non-convex cap.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetFaceIndices =R"doc(Fill an array containing all the valid face indices for this
primitive.

:param (output):
    indices array of FaceIndices of all faces of the solid.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetFace =R"doc(Copy a single face to a new object.

:param (input):
    indices indices of face.

:returns:
    IGeometryPtr with representing a single face. End caps will always
    return as CurveVectorPtr. Planar side faces will return as
    CurveVectorPtr. Cylindrical side faces will return as
    DgnConeDetail with no cap. Other ruled side faces will appear as
    DgnRuledSweepDetail with one swept primitive and no cap.
    Rotational sweeps of arcs will appear as (preferably)
    DgnTorusPipeDetail or DgnRotationalRotationalSweep.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_SetCapped =R"doc(Set flag for cap surface.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetCapped =R"doc(return flag for cap surface. Note that sphere and torus can be closed
without having a cap surface, so this is not a closure test, just a
test if the field for capping is set.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetConstructiveFrame =R"doc(Return a typical coordinate frame)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetRange =R"doc(Compute range of primitive)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnRuledSweepDetail =R"doc(Set DgnRuledSweepDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnRuledSweepDetail =R"doc(Ask if this is a DgnRuledSweep If so, return true with copy of detail
data. If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnRuledSweep =R"doc(Return a new ISolidPrimtive which is a DgnRuledSweep.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnRotationalSweepDetail =R"doc(Set DgnRotationalSweepDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnRotationalSweepDetail =R"doc(Ask if this is a DgnRotationalSweep If so, return true with copy of
detail data. If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnRotationalSweep =R"doc(Return a new ISolidPrimtive which is a DgnRotationalSweep.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnExtrusionDetail =R"doc(Set DgnExtrusionDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnExtrusionDetail =R"doc(Ask if this is a DgnExtrusion If so, return true with copy of detail
data. If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnExtrusion =R"doc(Return a new ISolidPrimtive which is a DgnExtrusion.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnSphereDetail =R"doc(Set DgnSphereDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnSphereDetail =R"doc(Ask if this is a DgnSphere If so, return true with copy of detail
data. If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnSphere =R"doc(Return a new ISolidPrimtive which is a DgnSphere.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnBoxDetail =R"doc(Set DgnBoxDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnBoxDetail =R"doc(Ask if this is a DgnBox If so, return true with copy of detail data.
If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnBox =R"doc(Return a new ISolidPrimtive which is a DgnBox.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnConeDetail =R"doc(Set DgnConeDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnConeDetail =R"doc(Ask if this is a DgnCone If so, return true with copy of detail data.
If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnCone =R"doc(Return a new ISolidPrimtive which is a DgnCone.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TrySetDgnTorusPipeDetail =R"doc(Set DgnTorusPipeDetail content.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_TryGetDgnTorusPipeDetail =R"doc(Ask if this is a DgnTorusPipe If so, return true with copy of detail
data. If not, return false, leave data untouched.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_CreateDgnTorusPipe =R"doc(Return a new ISolidPrimtive which is a DgnTorusPipe.)doc";

static const char * __doc_Bentley_Geom_ISolidPrimitive_GetSolidPrimitiveType =R"doc(Query the primitive type.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face. <remarks>Face orientation
    convention pre> ul> li>There is a natural " forward " direction
    along section curves. li>There is a natural " direction " to the
    (swept) side faces. (e.g. extrusion vector, positive rotation,
    rule line direction) li>The cross product of the curve direction
    and sweep direction is the outward normal for side faces. li>Hence
    base section is REVERSED when used for the Cap0 face. li>Hence the
    base section is NOT reversed when used for the Cap1 face. ul> pre>
    remarks>)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_TryGetConstructiveFrame =R"doc(Return coordinate system (LOCAL_COORDINATES_UnitAxesAtStart) for base
curve vector.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_GetRange =R"doc(Return range.)doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_TryGetCurvePair =R"doc(Get the lower and upper curves of a specified face.

:param (input):
    indices face indices

:param (output):
    curveA lower curve of face

:param (output):
    curveB upper curve of face

:returns:
    false if indices is not a valid ruled face. (Caps return false))doc";

static const char * __doc_Bentley_Geom_DgnRuledSweepDetail_AddSection =R"doc(Add (capture) a section.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_SetRadius =R"doc(:param (input):
    radius

:param (input):
    type of radius.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetRadius =R"doc(Return the radius

:param (output):
    radius

:param (input):
    type of radius.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_ComputeVRuleCount =R"doc(Compute v rule count for a given sweep angle and desired number of v
rules for a full sweep.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_HasRealCaps =R"doc(Return true if capped and incomplete sweep.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_TryGetRotationAxis =R"doc(Get the axis of rotation, negated if necessary to force a positive
sweep angle.

:param center:
    (output) center of rotation.

:param axis:
    (output) axis of rotation.

:param sweepRadians:
    (output) angle of rotation.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_VFractionToProfile =R"doc(Fractional profile curve)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetVFractionTransform =R"doc(Get transform from base cap to fractional v position.

:param (output):
    transform transform to rotate a point.

:param (output):
    derivativeTransform Derivative with respect to vFraction. The
    output of derivativeTransform * xyz is a vector, not a point !!!
    (If viewed as a 4x4 matrix, its ww entry is zero)

:param (input):
    vFraction fraction of sweep angle.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetTransforms =R"doc(return transforms for the coordinate frame with z axis on the line of
rotation.

:param (output):
    localToWorld translation part is is a point on the axis; z
    direction is the rotation axis.

:param (output):
    worldToLocal inverse transform.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_TryGetConstructiveFrame =R"doc(Return coordinate system of 1) Z axis along rotation 2) X towards base
curve extreme point.)doc";

static const char * __doc_Bentley_Geom_DgnRotationalSweepDetail_GetRange =R"doc(Return range.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_TryGetExtrusionFrame =R"doc(Compute coordinate frames aligned with the extrusion vector.

:param (output):
    localToWorld transform with orign at first point of base curve, z
    vector along extrusion direction, xy vectors arbitrary
    perpendiculars.

:param (output):
    worldToLocal inverse of local to world)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_TryGetConstructiveFrame =R"doc(Return coordinate system based on any frenet frame for base curve
vector, with yz reversed if necessary to make z sense match exgtusion
vector.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_GetRange =R"doc(Return range.)doc";

static const char * __doc_Bentley_Geom_DgnExtrusionDetail_FractionToProfile =R"doc(Fractional profile curve)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_SetDetailUVFromUnitSphereCoordinates =R"doc(set point, uv coordinates, and uv derivatives vectors)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IntersectBoundedArc =R"doc(Return all intersection points of an (unbounded) arc with the sphere.
Returned data is the detailed local coordinates, with additional data
to relate it back to world.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_VFractionToUSectionDEllipse3d =R"doc(Return the ellipse on the parallel at fractional position.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_UFractionToVSectionDEllipse3d =R"doc(Return the ellipse on the meridian at fractional position.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_TryGetRotationAxis =R"doc(:param center:
    (output) center of rotation.

:param axis:
    (output) axis of rotation.

:param sweepRadians:
    (output) angle of rotation.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetNonUniformTransforms =R"doc(Return (nonuniform) transforms for normalized system where sphere
radius is 1.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetTransforms =R"doc(Return transforms for unit-axis system.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_VFractionToLatitude =R"doc(Compute the latitude at v fraction.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_LongitudeToUFraction =R"doc(Compute the u fraction of longitude)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_LatitudeToVFraction =R"doc(Compute the v fraction of latitude)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IsRealCap =R"doc(Test if caps are active and the indicated cap is not at a pole)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetSweepLimits =R"doc(:param (output):
    latitude0 latitude at start of sweep.

:param (output):
    latitude1 latitude at end of sweep.

:param (output):
    z0 z coordinate at start of sweep.

:param (output):
    z1 z coordinate at end of sweep.

:param (input):
    forceSweepNorth true to exchange if necessary to make sweep south
    to north.

:returns:
    false if no sweep limits (full sphere))doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IsTrueRotationAroundZ =R"doc(Return true (with supporting local coordinate frame) iff this is a
rotation around the Z axis.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IsTrueSphere =R"doc(Return true (with supporting data) iff this is a (complete) true
sphere.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_ParameterizationSign =R"doc(Return +1 or -1 that matches the volume sign after integration over
the parameter space.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_TryGetConstructiveFrame =R"doc(Return coordinate system with 1) XY plane in equatorial plane, origin
at sphere center. 2) Z perpendicular)doc";

static const char * __doc_Bentley_Geom_DgnSphereDetail_GetRange =R"doc(Return range.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_IsBlock =R"doc(Test if the DgnBox is really a box (aka slab). Return orientation and
size data, using caller-specifed fractional coordinates to indicate
position of origin in reference system.

:param (output):
    origin local coordinates origin

:param (output):
    unitAxes transform (with orthogonal axes)

:param (output):
    localDiagonal the box edge lengths.

:param (input):
    originXFraction fractional position of the unitAxes origin along
    the x edge.

:param (input):
    originYFraction fractional position of the unitAxes origin along
    the y edge.

:param (input):
    originZFraction fractional position of the unitAxes origin along
    the z edge.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetCorners =R"doc(Return 8 corners of the box. x varies fastest, then y then z.

:param (output):
    corners 8 corner coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_ParameterizationSign =R"doc(Return +1 or -1 that matches the volume sign after integration over
the parameter space.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_TryGetConstructiveFrame =R"doc(Return coordinate system with 1) XY in box base plane, origin at
nominal lower left. 2) Z perpendicular)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetRange =R"doc(Return range.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_GetNonUniformTransform =R"doc(Return (nonuniform) placement and rectangle sizes. (ax,ay) rectangle
is on z=0. (bx,by) is on z=1;)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_InitFromCenterAndSize =R"doc(Initialize box detail fields from center and size.

:param (input):
    center center of box in XYZ

:param (input):
    size total range in XYZ

:param (input):
    capped true if closed top and bottom.)doc";

static const char * __doc_Bentley_Geom_DgnBoxDetail_InitFromCenters =R"doc(Initialize box detail fields specifying top/base centers instead of
origins...

:param (input):
    baseCenter center of base rectangle

:param (input):
    topCenter center of Top rectangle

:param (input):
    vectorX X vector of base plane

:param (input):
    vectorY Y vector of base plane

:param (input):
    baseX x size at base

:param (input):
    baseY y size at base

:param (input):
    topX X size at top

:param (input):
    topY y size at top

:param (input):
    capped true if closed top and bottom.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_SetDetailCoordinatesFromFractionalizedConeCoordinates =R"doc(set point, uv coordinates, and uv derivatives vectors)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (input):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_IsCylinder =R"doc(Return true (with supporting data) if the cone is a (constant radius)
cylinder.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_IsCircular =R"doc(Return true (with supporting data) if the cone is circular.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_IsRealCap =R"doc(Test if caps are active and the indicated cap has nonzero radius.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetSilhouettes =R"doc(Return the rule lines which are silhouettes as viewed.

:param (output):
    segmentA first silhouette line

:param (output):
    segmentB second silhouette line

:param (input):
    viewToLocal matrix that positions the cone for viewing along the z
    axis.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_FractionToRule =R"doc(Return the rule line section at a fraction around the circular
sections.

:param (input):
    fraction fractional position around the cone.

:param (output):
    segment rule line)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_FractionToSection =R"doc(Return the ellipse cross section at a fraction along the rotation
axis.

:param (input):
    fraction fractional position alont the z axis.

:param (output):
    ellipse the section ellipse.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetTransforms =R"doc(Try to set up a nonsingular coordinate frame. Returns false if centerB
is in base plane !!!!)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_ParameterizationSign =R"doc(Return +1 or -1 that matches the volume sign after integration over
the parameter space.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_TryGetConstructiveFrame =R"doc(Return coordinate system with 1) XY plane of base circle, origin at
center. 2) Z perpendicular)doc";

static const char * __doc_Bentley_Geom_DgnConeDetail_GetRange =R"doc(Return range.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_SetDetailCoordinatesFromLocalPipeCoordinates =R"doc(set point, uv coordinates, and uv derivatives vectors)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_IntersectCurveLocal =R"doc(Return all intersection points of a curve with the pipe body Returned
data is the detailed local coordinates, with additional data to relate
it back to world.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_SilhouetteCurves =R"doc(Return curves which are silhoutte curves OTHER than hard edges

:returns:
    return false if not implemented. return true if implemented -- but
    curves may still be empty.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_ComputeSecondMomentVolumeProducts =R"doc(Return the various integrated products for moment calculations. The
primitive is treated as a volume

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_ComputeSecondMomentAreaProducts =R"doc(Return the various integrated products for area moment calculations.
The primitive is treated as a thin shell.

:param (output):
    localToWorld transform from preferred system where the products
    are most easily computed to world.

:param (output):
    localProducts integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y
    z 1] dA

:returns:
    false if unable to compute.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_Clone =R"doc(Copy to a new (allocated) solid primitive.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_TryGetMaxUVLength =R"doc(Compute the lengths of the longest u and v direction sections of a
single face of a solid primitive.

:param (input):
    indices selects face.

:param (output):
    uvLength sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_GetConstantUSection =R"doc(Copy a section at constant u of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction u fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_GetConstantVSection =R"doc(Copy a section curve at constant v of a single face to a single
ICurvePrimitive.

:param (input):
    indices selects face

:param (input):
    fraction v fraction for section curve)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_GetFaceIndices =R"doc(Fill a list of all possible face indices.

:param (output):
    indices array of selectors for the faces.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_GetFace =R"doc(Return a single face of the solid primitive

:param indices:
    integer selectors for the face.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_TryUVFractionToXYZ =R"doc(convert u,v fraction on specified face to xyz and derivatives.

:param (input):
    faceIndices face selection indices

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_ClosestPoint =R"doc(:param (input):
    spacePoint search for point close to here and on the solid surface

:param (output):
    pickDetail closest point data.

:returns:
    false if not supported.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_AddCurveIntersections =R"doc(Compute intersections with curves and add to the data array.

:param (input):
    curves

:param [in,out]:
    curvePoints growing array of curve points.

:param [in,out]:
    solidPoints growing array of solid points.

:param [in,out]:
    messages array of error messages)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_AddRayIntersections =R"doc(Compute intersections with a ray and add to the pickData.

:param (input):
    ray origin and direction

:param (input):
    minParameter smallest parameter of pick. (e.g. 0 for picking along
    a positive ray from an eyepoint)

:param [in,out]:
    pickData growing array of picks.

:param (input):
    parentId caller's id for this solid. Will be placed in each
    pickData entry has parentId.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_TryGetFrame =R"doc(:param (output):
    center center of rotation.

:param (output):
    axes coordinate axes, xy in major plane, z through hole.

:param (output):
    radiusA major radius (elbow radius)

:param (output):
    radiusB minor radius (pipe diameter)

:param (output):
    sweepRadians angle of rotation.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_TryGetRotationAxis =R"doc(:param center:
    (output) center of rotation.

:param axis:
    (output) axis of rotation.

:param sweepRadians:
    (output) angle of rotation.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_VFractionToUSectionDEllipse3d =R"doc(Return full ellipse on minor hoop at fractional position along minor
circle.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_UFractionToVSectionDEllipse3d =R"doc(Return full ellipse on minor hoop at fractional position along major
circle.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_HasRealCaps =R"doc(Return true if capped and incomplete major sweep.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_ParameterizationSign =R"doc(Return +1 or -1 that matches the volume sign after integration over
the parameter space.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_IsClosedVolume =R"doc(Test if this is a closed volume.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_IsSameStructureAndGeometry =R"doc(Test for same type, structure and coordinates.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_IsSameStructure =R"doc(Test for same type and structure (but no coordinate comparison))doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_TryGetConstructiveFrame =R"doc(Return coordinate system with origin at major hoop center, X axis
towards starting minor circle center.)doc";

static const char * __doc_Bentley_Geom_DgnTorusPipeDetail_GetRange =R"doc(Return range.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SolidPrimitive(py::module_& m)
    {
    //===================================================================================
    // enum SolidPrimitiveType
    py::enum_<SolidPrimitiveType>(m, "SolidPrimitiveType", py::arithmetic())
        .value("eSolidPrimitiveType_None", SolidPrimitiveType_None)
        .value("eSolidPrimitiveType_DgnTorusPipe", SolidPrimitiveType_DgnTorusPipe)
        .value("eSolidPrimitiveType_DgnCone", SolidPrimitiveType_DgnCone)
        .value("eSolidPrimitiveType_DgnBox", SolidPrimitiveType_DgnBox)
        .value("eSolidPrimitiveType_DgnSphere", SolidPrimitiveType_DgnSphere)
        .value("eSolidPrimitiveType_DgnExtrusion", SolidPrimitiveType_DgnExtrusion)
        .value("eSolidPrimitiveType_DgnRotationalSweep", SolidPrimitiveType_DgnRotationalSweep)
        .value("eSolidPrimitiveType_DgnRuledSweep", SolidPrimitiveType_DgnRuledSweep)
        .export_values();

    //===================================================================================
    // struct DgnTorusPipeDetail
    py::class_<DgnTorusPipeDetail> c1(m, "DgnTorusPipeDetail");
    
    c1.def(py::init<>());
    c1.def(py::init<DPoint3dCR, DVec3dCR, DVec3dCR, double, double, double, bool>(),
           "center"_a, "vectorX"_a, "vectorY"_a, "majorRadius"_a, "minorRadius"_a, "sweepAngle"_a, "capped"_a);

    c1.def("GetRange", py::overload_cast<DRange3dR>(&DgnTorusPipeDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, GetRange));
    c1.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnTorusPipeDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, GetRange));

    c1.def("TryGetConstructiveFrame", &DgnTorusPipeDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TryGetConstructiveFrame));
    c1.def("IsSameStructure", &DgnTorusPipeDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, IsSameStructure));
    c1.def("IsSameStructureAndGeometry", &DgnTorusPipeDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, IsSameStructureAndGeometry));
    c1.def("IsClosedVolume", &DgnTorusPipeDetail::IsClosedVolume, DOC(Bentley, Geom, DgnTorusPipeDetail, IsClosedVolume));
    c1.def("ParameterizationSign", &DgnTorusPipeDetail::ParameterizationSign, DOC(Bentley, Geom, DgnTorusPipeDetail, ParameterizationSign));
    c1.def("HasRealCaps", &DgnTorusPipeDetail::HasRealCaps, DOC(Bentley, Geom, DgnTorusPipeDetail, HasRealCaps));
    c1.def("UFractionToVSectionDEllipse3d", &DgnTorusPipeDetail::UFractionToVSectionDEllipse3d, "fraction"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, UFractionToVSectionDEllipse3d));
    c1.def("VFractionToUSectionDEllipse3d", &DgnTorusPipeDetail::VFractionToUSectionDEllipse3d, "fraction"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, VFractionToUSectionDEllipse3d));

    c1.def("TryGetRotationAxis", [] (DgnTorusPipeDetailCR self, DPoint3dR center, DVec3dR axis)
           {
           double sweepRadians = 0;
           bool bOk = self.TryGetRotationAxis(center, axis, sweepRadians);
           return py::make_tuple(bOk, sweepRadians);
           }, "center"_a, "axis"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TryGetRotationAxis));

    c1.def("TryGetFrame", [] (DgnTorusPipeDetailCR self, DPoint3dR center, RotMatrixR axes)
           {
           double radiusA = 0;
           double radiusB = 0;
           double sweepRadians = 0;
           bool bOk = self.TryGetFrame(center, axes, radiusA, radiusB, sweepRadians);
           return py::make_tuple(bOk, radiusA, radiusB, sweepRadians);
           }, "center"_a, "axis"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TryGetFrame));

    c1.def("TryGetFrame", [] (DgnTorusPipeDetailCR self, TransformR localToWorld, TransformR worldToLocal)
           {
           double radiusA = 0;
           double radiusB = 0;
           double sweepRadians = 0;
           bool bOk = self.TryGetFrame(localToWorld, worldToLocal, radiusA, radiusB, sweepRadians);
           return py::make_tuple(bOk, radiusA, radiusB, sweepRadians);
           }, "center"_a, "axis"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TryGetFrame));

    c1.def("AddRayIntersections", &DgnTorusPipeDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddRayIntersections));

    c1.def("AddCurveIntersections",
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnTorusPipeDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

    c1.def("AddCurveIntersections", [](DgnTorusPipeDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

    c1.def("AddCurveIntersections", [](DgnTorusPipeDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

    c1.def("AddCurveIntersections", [](DgnTorusPipeDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

    c1.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnTorusPipeDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));
    
    c1.def("AddCurveIntersections", [](DgnTorusPipeDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

   c1.def("AddCurveIntersections", [](DgnTorusPipeDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

   c1.def("AddCurveIntersections", [](DgnTorusPipeDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, AddCurveIntersections));

    c1.def("ClosestPoint", &DgnTorusPipeDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, ClosestPoint));
    c1.def("TryUVFractionToXYZ", &DgnTorusPipeDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TryUVFractionToXYZ));

    c1.def("GetFace", &DgnTorusPipeDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, GetFace));
    c1.def("GetFaceIndices", &DgnTorusPipeDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, GetFaceIndices));
    c1.def("GetConstantVSection", &DgnTorusPipeDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, GetConstantVSection));
    c1.def("GetConstantUSection", &DgnTorusPipeDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, GetConstantUSection));
    c1.def("TryGetMaxUVLength", &DgnTorusPipeDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TryGetMaxUVLength));
    c1.def("Clone", &DgnTorusPipeDetail::Clone, DOC(Bentley, Geom, DgnTorusPipeDetail, Clone));
    c1.def("TransformInPlace", &DgnTorusPipeDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, TransformInPlace));
    c1.def("ComputeSecondMomentAreaProducts", &DgnTorusPipeDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, ComputeSecondMomentAreaProducts));
    c1.def("ComputeSecondMomentVolumeProducts", &DgnTorusPipeDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, ComputeSecondMomentVolumeProducts));
    c1.def("SilhouetteCurves", &DgnTorusPipeDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, SilhouetteCurves));

    c1.def("IntersectCurveLocal", [] (DgnTorusPipeDetailCR self, ICurvePrimitiveCR curve, DoubleArray& curveFractions, DPoint3dArray& normalizedConePoints,
                                      TransformR localToWorld, TransformR worldToLocal, bool boundedConeZ)
           {
           double rMajor = 0;
           double rMinor = 0;
           double sweepRadians = 0;
           self.IntersectCurveLocal(curve, curveFractions, normalizedConePoints, localToWorld, worldToLocal, rMajor, rMinor, sweepRadians, boundedConeZ);
           return py::make_tuple(rMajor, rMinor, sweepRadians);
           }, "curve"_a, "curveFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedConeZ"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, IntersectCurveLocal));

    c1.def("IntersectCurveLocal", [] (DgnTorusPipeDetailCR self, ICurvePrimitiveCR curve, DoubleArray& curveFractions, py::list& normalizedConePoints,
                                      TransformR localToWorld, TransformR worldToLocal, bool boundedConeZ)
           {
           double rMajor = 0;
           double rMinor = 0;
           double sweepRadians = 0;
           DPoint3dArray cppNormalizedConePoints;
           self.IntersectCurveLocal(curve, curveFractions, cppNormalizedConePoints, localToWorld, worldToLocal, rMajor, rMinor, sweepRadians, boundedConeZ);
           CONVERT_CPPARRAY_TO_PYLIST(normalizedConePoints, cppNormalizedConePoints, DPoint3dArray, DPoint3d);
           return py::make_tuple(rMajor, rMinor, sweepRadians);
           }, "curve"_a, "curveFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedConeZ"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, IntersectCurveLocal));

    c1.def("IntersectCurveLocal", [] (DgnTorusPipeDetailCR self, ICurvePrimitiveCR curve, py::list& curveFractions, DPoint3dArray& normalizedConePoints,
                                      TransformR localToWorld, TransformR worldToLocal, bool boundedConeZ)
           {
           double rMajor = 0;
           double rMinor = 0;
           double sweepRadians = 0;
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curveFractions, cppCurveFractions, DoubleArray, double);
           self.IntersectCurveLocal(curve, cppCurveFractions, normalizedConePoints, localToWorld, worldToLocal, rMajor, rMinor, sweepRadians, boundedConeZ);
           CONVERT_CPPARRAY_TO_PYLIST(curveFractions, cppCurveFractions, DoubleArray, double);
           return py::make_tuple(rMajor, rMinor, sweepRadians);
           }, "curve"_a, "curveFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedConeZ"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, IntersectCurveLocal));

    c1.def("IntersectCurveLocal", [] (DgnTorusPipeDetailCR self, ICurvePrimitiveCR curve, py::list& curveFractions, py::list& normalizedConePoints,
                                      TransformR localToWorld, TransformR worldToLocal, bool boundedConeZ)
           {
           double rMajor = 0;
           double rMinor = 0;
           double sweepRadians = 0;
           DPoint3dArray cppNormalizedConePoints;
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curveFractions, cppCurveFractions, DoubleArray, double);
           self.IntersectCurveLocal(curve, cppCurveFractions, cppNormalizedConePoints, localToWorld, worldToLocal, rMajor, rMinor, sweepRadians, boundedConeZ);
           CONVERT_CPPARRAY_TO_PYLIST(normalizedConePoints, cppNormalizedConePoints, DPoint3dArray, DPoint3d);
           CONVERT_CPPARRAY_TO_PYLIST(curveFractions, cppCurveFractions, DoubleArray, double);
           return py::make_tuple(rMajor, rMinor, sweepRadians);
           }, "curve"_a, "curveFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedConeZ"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, IntersectCurveLocal));

    c1.def("SetDetailCoordinatesFromLocalPipeCoordinates", [] (DgnTorusPipeDetailCR self, SolidLocationDetail& detail, DPoint3dCR localuvw, TransformCR localToWorld)
           {
           double rMajor = 0;
           double rMinor = 0;
           double sweepRadians = 0;
           self.SetDetailCoordinatesFromLocalPipeCoordinates(detail, localuvw, localToWorld, rMajor, rMinor, sweepRadians);
           return py::make_tuple(rMajor, rMinor, sweepRadians);
           }, "detail"_a, "localuvw"_a, "localToWorld"_a, DOC(Bentley, Geom, DgnTorusPipeDetail, SetDetailCoordinatesFromLocalPipeCoordinates));

    c1.def("__repr__", [] (DgnTorusPipeDetailCR self)
           {
           return "(center:{}, vectorX:{}, vectorY:{}, majorRadius:{}, minorRadius:{}, sweepAngle:{}, capped:{})"_s
               .format(self.m_center, self.m_vectorX, self.m_vectorY, self.m_majorRadius, self.m_minorRadius, self.m_sweepAngle, self.m_capped);
           });

    //===================================================================================
    // struct DgnConeDetail
    py::class_<DgnConeDetail> c2(m, "DgnConeDetail");

    c2.def(py::init<>());
    c2.def(py::init<DPoint3dCR, DPoint3dCR, double, double, bool>(), "centerA"_a, "centerB"_a, "radiusA"_a, "radiusB"_a, "capped"_a);
    c2.def(py::init<DPoint3dCR, DPoint3dCR, RotMatrixCR, double, double, bool>(), "centerA"_a, "centerB"_a, "axes"_a, "radiusA"_a, "radiusB"_a, "capped"_a);
    c2.def(py::init<DPoint3dCR, DPoint3dCR, DVec3dCR, DVec3dCR, double, double, bool>(), "centerA"_a, "centerB"_a, "vectorX"_a, "vectorY"_a, "radiusA"_a, "radiusB"_a, "capped"_a);

    c2.def("GetRange", py::overload_cast<DRange3dR>(&DgnConeDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnConeDetail, GetRange));
    c2.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnConeDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnConeDetail, GetRange));
    c2.def("TryGetConstructiveFrame", &DgnConeDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnConeDetail, TryGetConstructiveFrame));
    c2.def("IsSameStructure", &DgnConeDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnConeDetail, IsSameStructure));
    c2.def("IsSameStructureAndGeometry", &DgnConeDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnConeDetail, IsSameStructureAndGeometry));
    c2.def("IsClosedVolume", &DgnConeDetail::IsClosedVolume, DOC(Bentley, Geom, DgnConeDetail, IsClosedVolume));
    c2.def("ParameterizationSign", &DgnConeDetail::ParameterizationSign, DOC(Bentley, Geom, DgnConeDetail, ParameterizationSign));

    c2.def("GetTransforms", [] (DgnConeDetailCR self, TransformR localToWorld, TransformR worldToLocal, bool fractionRadii)
           {
           double radiusA = 0;
           double radiusB = 0;
           bool bOk = self.GetTransforms(localToWorld, worldToLocal, radiusA, radiusB, fractionRadii);
           return py::make_tuple(bOk, radiusA, radiusB);
           }, "localToWorld"_a, "worldToLocal"_a, "fractionRadii"_a = false, DOC(Bentley, Geom, DgnConeDetail, GetTransforms));

    c2.def("FractionToSection", &DgnConeDetail::FractionToSection, "fraction"_a, "ellipse"_a, DOC(Bentley, Geom, DgnConeDetail, FractionToSection));
    c2.def("FractionToRule", &DgnConeDetail::FractionToRule, "fraction"_a, "segment"_a, DOC(Bentley, Geom, DgnConeDetail, FractionToRule));
    c2.def("GetSilhouettes", &DgnConeDetail::GetSilhouettes, "segmentA"_a, "segmentB"_a, "viewToLocal"_a, DOC(Bentley, Geom, DgnConeDetail, GetSilhouettes));
    c2.def("IsRealCap", &DgnConeDetail::IsRealCap, "select01"_a, DOC(Bentley, Geom, DgnConeDetail, IsRealCap));

    c2.def("IsCircular", [] (DgnConeDetailCR self, DPoint3dR centerA, DPoint3dR centerB, RotMatrixR rotMatrix)
           {
           double radiusA = 0;
           double radiusB = 0;
           bool capped = false;
           bool bOk = self.IsCircular(centerA, centerB, rotMatrix, radiusA, radiusB, capped);
           return py::make_tuple(bOk, radiusA, radiusB, capped);
           }, "centerA"_a, "centerB"_a, "rotMatrix"_a, DOC(Bentley, Geom, DgnConeDetail, IsCircular));

    c2.def("IsCylinder", [] (DgnConeDetailCR self, DPoint3dR centerA, DPoint3dR centerB)
           {
           double radius = 0;
           bool capped = false;
           bool bOk = self.IsCylinder(centerA, centerB, radius, capped);
           return py::make_tuple(bOk, radius, capped);
           }, "centerA"_a, "centerB"_a, DOC(Bentley, Geom, DgnConeDetail, IsCylinder));

    c2.def("AddRayIntersections", &DgnConeDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnConeDetail, AddRayIntersections));

    c2.def("AddCurveIntersections", 
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnConeDetail::AddCurveIntersections, py::const_), 
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

    c2.def("AddCurveIntersections", [](DgnConeDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

   c2.def("AddCurveIntersections", [](DgnConeDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

   c2.def("AddCurveIntersections", [](DgnConeDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

    c2.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnConeDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

    c2.def("AddCurveIntersections", [](DgnConeDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

   c2.def("AddCurveIntersections", [](DgnConeDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

   c2.def("AddCurveIntersections", [](DgnConeDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnConeDetail, AddCurveIntersections));

    c2.def("ClosestPoint", &DgnConeDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnConeDetail, ClosestPoint));
    c2.def("TryUVFractionToXYZ", &DgnConeDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnConeDetail, TryUVFractionToXYZ));
    c2.def("GetFace", &DgnConeDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnConeDetail, GetFace));
    c2.def("GetFaceIndices", &DgnConeDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnConeDetail, GetFaceIndices));
    c2.def("GetConstantVSection", &DgnConeDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnConeDetail, GetConstantVSection));
    c2.def("GetConstantUSection", &DgnConeDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnConeDetail, GetConstantUSection));
    c2.def("TryGetMaxUVLength", &DgnConeDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnConeDetail, TryGetMaxUVLength));
    c2.def("Clone", &DgnConeDetail::Clone, DOC(Bentley, Geom, DgnConeDetail, Clone));
    c2.def("TransformInPlace", &DgnConeDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnConeDetail, TransformInPlace));
    c2.def("ComputeSecondMomentAreaProducts", &DgnConeDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnConeDetail, ComputeSecondMomentAreaProducts));
    c2.def("ComputeSecondMomentVolumeProducts", &DgnConeDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnConeDetail, ComputeSecondMomentVolumeProducts));
    c2.def("SilhouetteCurves", &DgnConeDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnConeDetail, SilhouetteCurves));

    c2.def("IntersectBoundedArc", [](DgnConeDetailCR self,
                                     DEllipse3dCR arc,
                                     bvector<double>& arcFractions,
                                     bvector<DPoint3d>& normalizedConePoints,
                                     TransformR localToWorld,
                                     TransformR worldToLocal,
                                     bool boundedConeZ)
           {
           double radius0 = 0;
           double radius1 = 0;
           self.IntersectBoundedArc(arc, arcFractions, normalizedConePoints, localToWorld, worldToLocal, radius0, radius1, boundedConeZ);
           return py::make_tuple(radius0, radius1);
           }, "arc"_a, "arcFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedConeZ"_a);

    c2.def("IntersectCurveLocal", [](DgnConeDetailCR self,
                                     ICurvePrimitiveCR curve,
                                     bvector<double>& curveFractions,
                                     bvector<DPoint3d>& normalizedConePoints,
                                     TransformR localToWorld,
                                     TransformR worldToLocal,
                                     bool boundedConeZ)
           {
           double radius0 = 0;
           double radius1 = 0;
           self.IntersectCurveLocal(curve, curveFractions, normalizedConePoints, localToWorld, worldToLocal, radius0, radius1, boundedConeZ);
           return py::make_tuple(radius0, radius1);
           }, "curve"_a, "curveFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedConeZ"_a);

    c2.def_static("SetDetailCoordinatesFromFractionalizedConeCoordinates",
                  &DgnConeDetail::SetDetailCoordinatesFromFractionalizedConeCoordinates,
                  "detail"_a, "localuvw"_a, "localToWorld"_a, "r0"_a, "r1"_a, DOC(Bentley, Geom, DgnConeDetail, SetDetailCoordinatesFromFractionalizedConeCoordinates));

    c2.def("__repr__", [] (DgnConeDetailCR self)
           {
           return "(centerA:{}, centerB:{}, vectorX:{}, vectorY:{}, radiusA:{}, radiusB:{}, capped:{})"_s
               .format(self.m_centerA, self.m_centerB, self.m_vector0, self.m_vector90, self.m_radiusA, self.m_radiusB, self.m_capped);
           });

    c2.def("__copy__", [](const DgnConeDetail& self)
        {
        return DgnConeDetail(self);
        });

    //===================================================================================
    // struct DgnBoxDetail
    py::class_<DgnBoxDetail> c3(m, "DgnBoxDetail");

    c3.def(py::init<>());
    c3.def(py::init<DPoint3dCR, DPoint3dCR, DVec3dCR, DVec3dCR, double, double, double, double, bool>(), 
           "baseOrigin"_a, "topOrigin"_a, "vectorX"_a, "vectorY"_a, "baseX"_a, "baseY"_a, "topX"_a, "topY"_a, "capped"_a);

    c3.def_static("InitFromCenters", &DgnBoxDetail::InitFromCenters,
                  "baseOrigin"_a, "topOrigin"_a, "vectorX"_a, "vectorY"_a, "baseX"_a, "baseY"_a, "topX"_a, "topY"_a, "capped"_a, DOC(Bentley, Geom, DgnBoxDetail, InitFromCenters));

    c3.def_static("InitFromCenterAndSize", &DgnBoxDetail::InitFromCenterAndSize, "center"_a, "size"_a, "capped"_a, DOC(Bentley, Geom, DgnBoxDetail, InitFromCenterAndSize));

    c3.def("GetNonUniformTransform", [] (DgnBoxDetailCR self, TransformR localToWorld)
           {
           double ax, ay, bx, by;
           self.GetNonUniformTransform(localToWorld, ax, ay, bx, by);
           return py::make_tuple(ax, ay, bx, by);
           }, "localToWorld"_a, DOC(Bentley, Geom, DgnBoxDetail, GetNonUniformTransform));

    c3.def("GetRange", py::overload_cast<DRange3dR>(&DgnBoxDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnBoxDetail, GetRange));
    c3.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnBoxDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnBoxDetail, GetRange));
    c3.def("TryGetConstructiveFrame", &DgnBoxDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnBoxDetail, TryGetConstructiveFrame));
    c3.def("IsSameStructure", &DgnBoxDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnBoxDetail, IsSameStructure));
    c3.def("IsSameStructureAndGeometry", &DgnBoxDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnBoxDetail, IsSameStructureAndGeometry));
    c3.def("IsClosedVolume", &DgnBoxDetail::IsClosedVolume, DOC(Bentley, Geom, DgnBoxDetail, IsClosedVolume));
    c3.def("ParameterizationSign", &DgnBoxDetail::ParameterizationSign, DOC(Bentley, Geom, DgnBoxDetail, ParameterizationSign));

    c3.def("GetCorners", py::overload_cast<DPoint3dArray&>(&DgnBoxDetail::GetCorners, py::const_), "corners"_a, DOC(Bentley, Geom, DgnBoxDetail, GetCorners));
    c3.def("GetCorners", [] (DgnBoxDetailCR self, py::list& corners)
           {
           DPoint3dArray cppCorners;
           self.GetCorners(cppCorners);
           CONVERT_CPPARRAY_TO_PYLIST(corners, cppCorners, DPoint3dArray, DPoint3d);
           }, "corners"_a, DOC(Bentley, Geom, DgnBoxDetail, GetCorners));
    c3.def("GetCorners", py::overload_cast<DPoint3dP>(&DgnBoxDetail::GetCorners, py::const_), "corners"_a, DOC(Bentley, Geom, DgnBoxDetail, GetCorners));
    c3.def("AddRayIntersections", &DgnBoxDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnBoxDetail, AddRayIntersections));

    c3.def("AddCurveIntersections", 
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnBoxDetail::AddCurveIntersections, py::const_), 
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

    c3.def("AddCurveIntersections", [](DgnBoxDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

   c3.def("AddCurveIntersections", [](DgnBoxDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

   c3.def("AddCurveIntersections", [](DgnBoxDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

    c3.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnBoxDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

    c3.def("AddCurveIntersections", [](DgnBoxDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

   c3.def("AddCurveIntersections", [](DgnBoxDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

   c3.def("AddCurveIntersections", [](DgnBoxDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnBoxDetail, AddCurveIntersections));

    c3.def("ClosestPoint", &DgnBoxDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnBoxDetail, ClosestPoint));
    c3.def("TryUVFractionToXYZ", &DgnBoxDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnBoxDetail, TryUVFractionToXYZ));
    c3.def("GetFace", &DgnBoxDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnBoxDetail, GetFace));
    c3.def("GetFaceIndices", &DgnBoxDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnBoxDetail, GetFaceIndices));
    c3.def("GetConstantVSection", &DgnBoxDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnBoxDetail, GetConstantVSection));
    c3.def("GetConstantUSection", &DgnBoxDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnBoxDetail, GetConstantUSection));
    c3.def("TryGetMaxUVLength", &DgnBoxDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnBoxDetail, TryGetMaxUVLength));
    c3.def("Clone", &DgnBoxDetail::Clone, DOC(Bentley, Geom, DgnBoxDetail, Clone));
    c3.def("TransformInPlace", &DgnBoxDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnBoxDetail, TransformInPlace));
    c3.def("ComputeSecondMomentAreaProducts", &DgnBoxDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnBoxDetail, ComputeSecondMomentAreaProducts));
    c3.def("ComputeSecondMomentVolumeProducts", &DgnBoxDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnBoxDetail, ComputeSecondMomentVolumeProducts));
    c3.def("SilhouetteCurves", &DgnBoxDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnBoxDetail, SilhouetteCurves));
    c3.def("IsBlock", &DgnBoxDetail::IsBlock, 
           "origin"_a, "unitAxes"_a, "localDiagonal"_a, "originXFraction"_a, "originYFraction"_a, "originZFraction"_a, DOC(Bentley, Geom, DgnBoxDetail, IsBlock));

    c3.def("__repr__", [] (DgnBoxDetailCR self)
           {
           return "(baseOrigin:{}, topOrigin:{}, vectorX:{}, vectorY:{}, baseSize:{}, topSize:{}, capped:{})"_s
               .format(self.m_baseOrigin, self.m_topOrigin, self.m_vectorX, self.m_vectorY, DPoint2d::From(self.m_baseX, self.m_baseY), 
                       DPoint2d::From(self.m_topX, self.m_topY), self.m_capped);
           });

    c3.def("__copy__", [](const DgnBoxDetail& self)
        {
        return DgnBoxDetail(self);
        });

    //===================================================================================
    // struct DgnSphereDetail
    py::class_<DgnSphereDetail> c4(m, "DgnSphereDetail");

    c4.def(py::init<>());
    c4.def(py::init<DPoint3dCR, double>(), "center"_a, "radius"_a);
    c4.def(py::init<DPoint3dCR, RotMatrixCR, double>(), "center"_a, "axes"_a, "radius"_a);
    c4.def(py::init<DPoint3dCR, DVec3dCR, DVec3dCR, double, double, double, double, bool>(), 
           "center"_a, "vectorX"_a, "vectorZ"_a, "radiusXY"_a, "radiusZ"_a, "startLatitude"_a, "latitudeSweep"_a, "capped"_a);

    c4.def("GetRange", py::overload_cast<DRange3dR>(&DgnSphereDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnSphereDetail, GetRange));
    c4.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnSphereDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnSphereDetail, GetRange));
    c4.def("TryGetConstructiveFrame", &DgnSphereDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnSphereDetail, TryGetConstructiveFrame));
    c4.def("IsSameStructure", &DgnSphereDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnSphereDetail, IsSameStructure));
    c4.def("IsSameStructureAndGeometry", &DgnSphereDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnSphereDetail, IsSameStructureAndGeometry));
    c4.def("IsClosedVolume", &DgnSphereDetail::IsClosedVolume, DOC(Bentley, Geom, DgnSphereDetail, IsClosedVolume));
    c4.def("ParameterizationSign", &DgnSphereDetail::ParameterizationSign, DOC(Bentley, Geom, DgnSphereDetail, ParameterizationSign));

    c4.def("IsTrueSphere", [] (DgnSphereDetailCR self, DPoint3dR center, RotMatrixR axes)
           {
           double radius = 0;
           bool bOk = self.IsTrueSphere(center, axes, radius);
           return py::make_tuple(bOk, radius);
           }, "center"_a, "axes"_a, DOC(Bentley, Geom, DgnSphereDetail, IsTrueSphere));
        
    c4.def("IsTrueRotationAroundZ", [] (DgnSphereDetailCR self, DPoint3dR center, DVec3dR unitX, DVec3dR unitY, DVec3dR unitZ)
           {
           double equatorRadius = 0;
           double poleRadius = 0;
           bool bOk = self.IsTrueRotationAroundZ(center, unitX, unitY, unitZ, equatorRadius, poleRadius);
           return py::make_tuple(bOk, equatorRadius, poleRadius);
           }, "center"_a, "unitX"_a, "unitY"_a, "unitZ"_a, DOC(Bentley, Geom, DgnSphereDetail, IsTrueRotationAroundZ));

    c4.def("GetSweepLimits", [] (DgnSphereDetailCR self, bool forceSweepNorth)
           {
           double latitude0 = 0;
           double latitude1 = 0;
           double z0 = 0;
           double z1 = 0;
           bool bOk = self.GetSweepLimits(latitude0, latitude1, z0, z1, forceSweepNorth);
           return py::make_tuple(bOk, latitude0, latitude1, z0, z1);
           }, "forceSweepNorth"_a, DOC(Bentley, Geom, DgnSphereDetail, GetSweepLimits));

    c4.def("IsRealCap", &DgnSphereDetail::IsRealCap, "select01"_a, DOC(Bentley, Geom, DgnSphereDetail, IsRealCap));
    c4.def("LatitudeToVFraction", &DgnSphereDetail::LatitudeToVFraction, "latitude"_a, DOC(Bentley, Geom, DgnSphereDetail, LatitudeToVFraction));
    c4.def("LongitudeToUFraction", &DgnSphereDetail::LongitudeToUFraction, "longitude"_a, DOC(Bentley, Geom, DgnSphereDetail, LongitudeToUFraction));
    c4.def("VFractionToLatitude", &DgnSphereDetail::VFractionToLatitude, "v"_a, DOC(Bentley, Geom, DgnSphereDetail, VFractionToLatitude));

    c4.def("GetTransforms", &DgnSphereDetail::GetTransforms, "localTransform"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnSphereDetail, GetTransforms));
    c4.def("GetNonUniformTransforms", &DgnSphereDetail::GetNonUniformTransforms, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnSphereDetail, GetNonUniformTransforms));

    c4.def("TryGetRotationAxis", [] (DgnSphereDetailCR self, DPoint3dR center, DVec3dR axes)
           {
           double sweepRadians = 0;
           bool bOk = self.TryGetRotationAxis(center, axes, sweepRadians);
           return py::make_tuple(bOk, sweepRadians);
           }, "center"_a, "axes"_a, DOC(Bentley, Geom, DgnSphereDetail, TryGetRotationAxis));

    c4.def("UFractionToVSectionDEllipse3d", &DgnSphereDetail::UFractionToVSectionDEllipse3d, "fraction"_a, DOC(Bentley, Geom, DgnSphereDetail, UFractionToVSectionDEllipse3d));
    c4.def("VFractionToUSectionDEllipse3d", &DgnSphereDetail::VFractionToUSectionDEllipse3d, "fraction"_a, DOC(Bentley, Geom, DgnSphereDetail, VFractionToUSectionDEllipse3d));

    c4.def("AddRayIntersections", &DgnSphereDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnSphereDetail, AddRayIntersections));
    c4.def("AddCurveIntersections",
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnSphereDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

    c4.def("AddCurveIntersections", [](DgnSphereDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

   c4.def("AddCurveIntersections", [](DgnSphereDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

   c4.def("AddCurveIntersections", [](DgnSphereDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

    c4.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnSphereDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

    c4.def("AddCurveIntersections", [](DgnSphereDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

   c4.def("AddCurveIntersections", [](DgnSphereDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

   c4.def("AddCurveIntersections", [](DgnSphereDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnSphereDetail, AddCurveIntersections));

    c4.def("ClosestPoint", &DgnSphereDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnSphereDetail, ClosestPoint));
    c4.def("TryUVFractionToXYZ", &DgnSphereDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnSphereDetail, TryUVFractionToXYZ));
    c4.def("GetFace", &DgnSphereDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnSphereDetail, GetFace));
    c4.def("GetFaceIndices", &DgnSphereDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnSphereDetail, GetFaceIndices));
    c4.def("GetConstantVSection", &DgnSphereDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnSphereDetail, GetConstantVSection));
    c4.def("GetConstantUSection", &DgnSphereDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnSphereDetail, GetConstantUSection));
    c4.def("TryGetMaxUVLength", &DgnSphereDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnSphereDetail, TryGetMaxUVLength));
    c4.def("Clone", &DgnSphereDetail::Clone, DOC(Bentley, Geom, DgnSphereDetail, Clone));
    c4.def("TransformInPlace", &DgnSphereDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnSphereDetail, TransformInPlace));
    c4.def("ComputeSecondMomentAreaProducts", &DgnSphereDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnSphereDetail, ComputeSecondMomentAreaProducts));
    c4.def("ComputeSecondMomentVolumeProducts", &DgnSphereDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnSphereDetail, ComputeSecondMomentVolumeProducts));
    c4.def("SilhouetteCurves", &DgnSphereDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnSphereDetail, SilhouetteCurves));

    c4.def("IntersectBoundedArc", 
           &DgnSphereDetail::IntersectBoundedArc, 
           "arc"_a, "arcFractions"_a, "normalizedConePoints"_a, "localToWorld"_a, "worldToLocal"_a, "boundedZ"_a, DOC(Bentley, Geom, DgnSphereDetail, IntersectBoundedArc));

    c4.def_static("SetDetailUVFromUnitSphereCoordinates",
           &DgnSphereDetail::SetDetailUVFromUnitSphereCoordinates,
           "detail"_a, "localuvw"_a, "localToWorld"_a, "startLatitude"_a, "sweepLatitude"_a, DOC(Bentley, Geom, DgnSphereDetail, SetDetailUVFromUnitSphereCoordinates));  

    c4.def("__repr__", [] (DgnSphereDetailCR self)
           {
           return "(localToWorld:{}, startLatitude:{}, latitudeSweep:{}, capped:{})"_s.format(self.m_localToWorld, self.m_startLatitude, self.m_latitudeSweep, self.m_capped);
           });

    c4.def("__copy__", [](const DgnSphereDetail& self)
        {
        return DgnSphereDetail(self);
        });
    
    //===================================================================================
    // struct DgnExtrusionDetail
    py::class_< DgnExtrusionDetail> c5(m, "DgnExtrusionDetail");

    c5.def(py::init<>());
    c5.def(py::init<CurveVectorPtr, DVec3dCR, bool>(), "baseCurve"_a, "extrusionVector"_a, "capped"_a);

    c5.def("FractionToProfile", &DgnExtrusionDetail::FractionToProfile, "fraction"_a, DOC(Bentley, Geom, DgnExtrusionDetail, FractionToProfile));

    c5.def("GetRange", py::overload_cast<DRange3dR>(&DgnExtrusionDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnExtrusionDetail, GetRange));
    c5.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnExtrusionDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnExtrusionDetail, GetRange));
    c5.def("TryGetConstructiveFrame", &DgnExtrusionDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnExtrusionDetail, TryGetConstructiveFrame));
    c5.def("IsSameStructure", &DgnExtrusionDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnExtrusionDetail, IsSameStructure));
    c5.def("IsSameStructureAndGeometry", &DgnExtrusionDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnExtrusionDetail, IsSameStructureAndGeometry));
    c5.def("IsClosedVolume", &DgnExtrusionDetail::IsClosedVolume, DOC(Bentley, Geom, DgnExtrusionDetail, IsClosedVolume));
    
    c5.def("AddRayIntersections", &DgnExtrusionDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddRayIntersections));
    c5.def("AddCurveIntersections",
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnExtrusionDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));
    
    c5.def("AddCurveIntersections", [](DgnExtrusionDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));

   c5.def("AddCurveIntersections", [](DgnExtrusionDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));

   c5.def("AddCurveIntersections", [](DgnExtrusionDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));
           
    c5.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnExtrusionDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));

    c5.def("AddCurveIntersections", [](DgnExtrusionDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));

   c5.def("AddCurveIntersections", [](DgnExtrusionDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));

   c5.def("AddCurveIntersections", [](DgnExtrusionDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnExtrusionDetail, AddCurveIntersections));
           
    c5.def("ClosestPoint", &DgnExtrusionDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnExtrusionDetail, ClosestPoint));
    c5.def("TryUVFractionToXYZ", &DgnExtrusionDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnExtrusionDetail, TryUVFractionToXYZ));
    c5.def("TryGetExtrusionFrame", &DgnExtrusionDetail::TryGetExtrusionFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnExtrusionDetail, TryGetExtrusionFrame));
    c5.def("GetFace", &DgnExtrusionDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnExtrusionDetail, GetFace));
    c5.def("GetFaceIndices", &DgnExtrusionDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnExtrusionDetail, GetFaceIndices));
    c5.def("GetConstantVSection", &DgnExtrusionDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnExtrusionDetail, GetConstantVSection));
    c5.def("GetConstantUSection", &DgnExtrusionDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnExtrusionDetail, GetConstantUSection));
    c5.def("TryGetMaxUVLength", &DgnExtrusionDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnExtrusionDetail, TryGetMaxUVLength));
    c5.def("Clone", &DgnExtrusionDetail::Clone, DOC(Bentley, Geom, DgnExtrusionDetail, Clone));
    c5.def("TransformInPlace", &DgnExtrusionDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnExtrusionDetail, TransformInPlace));
    c5.def("ComputeSecondMomentAreaProducts", &DgnExtrusionDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnExtrusionDetail, ComputeSecondMomentAreaProducts));
    c5.def("ComputeSecondMomentVolumeProducts", &DgnExtrusionDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnExtrusionDetail, ComputeSecondMomentVolumeProducts));
    c5.def("SilhouetteCurves", &DgnExtrusionDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnExtrusionDetail, SilhouetteCurves));

    c5.def("__repr__", [] (DgnExtrusionDetail& self)
           {
           return "(baseCurve:{}, extrusionVector:{}, capped:{})"_s.format(self.m_baseCurve, self.m_extrusionVector, self.m_capped);
           });

    c5.def("__copy__", [](const DgnExtrusionDetail& self)
        {
        return DgnExtrusionDetail(self);
        });

    //===================================================================================
    // struct DgnRotationalSweepDetail
    py::class_< DgnRotationalSweepDetail> c6(m, "DgnRotationalSweepDetail");

    if (true)
        {
        //===================================================================================
        // enum class RadiusType
        py::enum_< DgnRotationalSweepDetail::RadiusType>(c6, "RadiusType")
            .value("eMinimum", DgnRotationalSweepDetail::RadiusType::Minimum)
            .value("eMaximum", DgnRotationalSweepDetail::RadiusType::Maximum)
            .value("eCentroidal", DgnRotationalSweepDetail::RadiusType::Centroidal)
            .export_values();
        }

    c6.def(py::init<>());
    c6.def(py::init<CurveVectorPtr, DPoint3dCR, DVec3dCR, double, bool>(), "baseCurve"_a, "center"_a, "axis"_a, "sweepAngle"_a, "capped"_a);

    c6.def("GetRange", py::overload_cast<DRange3dR>(&DgnRotationalSweepDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetRange));
    c6.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnRotationalSweepDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetRange));
    c6.def("TryGetConstructiveFrame", &DgnRotationalSweepDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, TryGetConstructiveFrame));
    c6.def("IsSameStructure", &DgnRotationalSweepDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, IsSameStructure));
    c6.def("IsSameStructureAndGeometry", &DgnRotationalSweepDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, IsSameStructureAndGeometry));
    c6.def("IsClosedVolume", &DgnRotationalSweepDetail::IsClosedVolume, DOC(Bentley, Geom, DgnRotationalSweepDetail, IsClosedVolume));
    c6.def("GetTransforms", &DgnRotationalSweepDetail::GetTransforms, "localTransform"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetTransforms));
    c6.def("GetVFractionTransform", &DgnRotationalSweepDetail::GetVFractionTransform, "vFraction"_a, "transform"_a, "derivativeTransform"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetVFractionTransform));
    c6.def("VFractionToProfile", &DgnRotationalSweepDetail::VFractionToProfile, "fraction"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, VFractionToProfile));

    c6.def("TryGetRotationAxis", [] (DgnRotationalSweepDetailCR self, DPoint3dR center, DVec3dR axis)
           {
           double sweepRadians = 0;
           bool bOk = self.TryGetRotationAxis(center, axis, sweepRadians);
           return py::make_tuple(bOk, sweepRadians);
           }, "center"_a, "axis"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, TryGetRotationAxis));

    c6.def("AddRayIntersections", &DgnRotationalSweepDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddRayIntersections));
    c6.def("AddCurveIntersections",
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnRotationalSweepDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));
    
    c6.def("AddCurveIntersections", [](DgnRotationalSweepDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

    c6.def("AddCurveIntersections", [](DgnRotationalSweepDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

    c6.def("AddCurveIntersections", [](DgnRotationalSweepDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

    c6.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnRotationalSweepDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

    c6.def("AddCurveIntersections", [](DgnRotationalSweepDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

   c6.def("AddCurveIntersections", [](DgnRotationalSweepDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

   c6.def("AddCurveIntersections", [](DgnRotationalSweepDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, AddCurveIntersections));

    c6.def("ClosestPoint", &DgnRotationalSweepDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, ClosestPoint));
    c6.def("TryUVFractionToXYZ", &DgnRotationalSweepDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, TryUVFractionToXYZ));
    c6.def("GetFace", &DgnRotationalSweepDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetFace));
    c6.def("GetFaceIndices", &DgnRotationalSweepDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetFaceIndices));
    c6.def("GetConstantVSection", &DgnRotationalSweepDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetConstantVSection));
    c6.def("GetConstantUSection", &DgnRotationalSweepDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetConstantUSection));
    c6.def("TryGetMaxUVLength", &DgnRotationalSweepDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, TryGetMaxUVLength));
    c6.def("Clone", &DgnRotationalSweepDetail::Clone, DOC(Bentley, Geom, DgnRotationalSweepDetail, Clone));
    c6.def("TransformInPlace", &DgnRotationalSweepDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, TransformInPlace));
    c6.def("ComputeSecondMomentAreaProducts", &DgnRotationalSweepDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, ComputeSecondMomentAreaProducts));
    c6.def("ComputeSecondMomentVolumeProducts", &DgnRotationalSweepDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, ComputeSecondMomentVolumeProducts));
    c6.def("SilhouetteCurves", &DgnRotationalSweepDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, SilhouetteCurves));

    c6.def("HasRealCaps", &DgnRotationalSweepDetail::HasRealCaps, DOC(Bentley, Geom, DgnRotationalSweepDetail, HasRealCaps));

    c6.def("GetVRuledCount", &DgnRotationalSweepDetail::GetVRuleCount);
    c6.def("SetVRuledCount", &DgnRotationalSweepDetail::SetVRuleCount, "numVRules"_a);
    
    c6.def_static("ComputeVRuleCount", &DgnRotationalSweepDetail::ComputeVRuleCount, "sweepRadians"_a, "numVRulesFullSweep"_a = 4, DOC(Bentley, Geom, DgnRotationalSweepDetail, ComputeVRuleCount));    

    c6.def("GetRadius", [] (DgnRotationalSweepDetailCR self, DgnRotationalSweepDetail::RadiusType type)
           {
           double radius = 0;
           bool bOk = self.GetRadius(radius, type);
           return py::make_tuple(bOk, radius);
           }, "type"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, GetRadius));

    c6.def("SetRadius", &DgnRotationalSweepDetail::SetRadius, "radius"_a, "type"_a, DOC(Bentley, Geom, DgnRotationalSweepDetail, SetRadius));     

    c6.def("__repr__", [] (DgnRotationalSweepDetailCR self)
           {
           return "(baseCurve:{}, axisOfRotation:{}, sweepAngle:{}, capped:{}, numVRules:{})"_s
               .format(self.m_baseCurve, self.m_axisOfRotation, self.m_sweepAngle, self.m_capped, self.m_numVRules);
           });

    c6.def("__copy__", [](const DgnRotationalSweepDetail& self)
        {
        return DgnRotationalSweepDetail(self);
        });

    //===================================================================================
    // struct DgnRuledSweepDetail
    py::class_< DgnRuledSweepDetail> c7(m, "DgnRuledSweepDetail");

    c7.def(py::init<CurveVectorArray&, bool>(), "sectionCurves"_a, "capped"_a);
    c7.def(py::init([](py::list& sectionCurves, bool capped){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(sectionCurves, cppSectionCurves, CurveVectorArray, CurveVectorPtr);
        return DgnRuledSweepDetail(cppSectionCurves, capped);
    }), "sectionCurves"_a, "capped"_a);
    c7.def(py::init<CurveVectorPtr, CurveVectorPtr, bool>(), "sectionA"_a, "sectionB"_a, "capped"_a);
    c7.def(py::init<>());

    c7.def("AddSection", &DgnRuledSweepDetail::AddSection, "section"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddSection));
    c7.def("TryGetCurvePair", &DgnRuledSweepDetail::TryGetCurvePair, "indices"_a, "curveA"_a, "curveB"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, TryGetCurvePair));

    c7.def("GetRange", py::overload_cast<DRange3dR>(&DgnRuledSweepDetail::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, GetRange));
    c7.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&DgnRuledSweepDetail::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, GetRange));
    c7.def("TryGetConstructiveFrame", &DgnRuledSweepDetail::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, TryGetConstructiveFrame));
    c7.def("IsSameStructure", &DgnRuledSweepDetail::IsSameStructure, "other"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, IsSameStructure));
    c7.def("IsSameStructureAndGeometry", &DgnRuledSweepDetail::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, IsSameStructureAndGeometry));
    c7.def("IsClosedVolume", &DgnRuledSweepDetail::IsClosedVolume, DOC(Bentley, Geom, DgnRuledSweepDetail, IsClosedVolume));

    c7.def("AddRayIntersections", &DgnRuledSweepDetail::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddRayIntersections));
    c7.def("AddCurveIntersections",
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnRuledSweepDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

    c7.def("AddCurveIntersections", [](DgnRuledSweepDetailCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

    c7.def("AddCurveIntersections", [](DgnRuledSweepDetailCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

    c7.def("AddCurveIntersections", [](DgnRuledSweepDetailCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

    c7.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&DgnRuledSweepDetail::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

    c7.def("AddCurveIntersections", [](DgnRuledSweepDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

   c7.def("AddCurveIntersections", [](DgnRuledSweepDetailCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

   c7.def("AddCurveIntersections", [](DgnRuledSweepDetailCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, AddCurveIntersections));

    c7.def("ClosestPoint", &DgnRuledSweepDetail::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, ClosestPoint));
    c7.def("TryUVFractionToXYZ", &DgnRuledSweepDetail::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, TryUVFractionToXYZ));
    c7.def("GetFace", &DgnRuledSweepDetail::GetFace, "indices"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, GetFace));
    c7.def("GetFaceIndices", &DgnRuledSweepDetail::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, GetFaceIndices));
    c7.def("GetConstantVSection", &DgnRuledSweepDetail::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, GetConstantVSection));
    c7.def("GetConstantUSection", &DgnRuledSweepDetail::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, GetConstantUSection));
    c7.def("TryGetMaxUVLength", &DgnRuledSweepDetail::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, TryGetMaxUVLength));
    c7.def("Clone", &DgnRuledSweepDetail::Clone, DOC(Bentley, Geom, DgnRuledSweepDetail, Clone));
    c7.def("TransformInPlace", &DgnRuledSweepDetail::TransformInPlace, "transform"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, TransformInPlace));
    c7.def("ComputeSecondMomentAreaProducts", &DgnRuledSweepDetail::ComputeSecondMomentAreaProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, ComputeSecondMomentAreaProducts));
    c7.def("ComputeSecondMomentVolumeProducts", &DgnRuledSweepDetail::ComputeSecondMomentVolumeProducts, "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, ComputeSecondMomentVolumeProducts));
    c7.def("SilhouetteCurves", &DgnRuledSweepDetail::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, DgnRuledSweepDetail, SilhouetteCurves));
    c7.def("__copy__", [](const DgnRuledSweepDetail& self)
        {
        return DgnRuledSweepDetail(self);
        });

    //===================================================================================
    // struct ISolidPrimitive
    py::class_<ISolidPrimitive, ISolidPrimitivePtr> c8(m, "ISolidPrimitive");

    c8.def_property_readonly("SolidPrimitiveType", &ISolidPrimitive::GetSolidPrimitiveType);
    c8.def("GetSolidPrimitiveType", &ISolidPrimitive::GetSolidPrimitiveType, DOC(Bentley, Geom, ISolidPrimitive, GetSolidPrimitiveType));

    c8.def_static("CreateDgnTorusPipe", &ISolidPrimitive::CreateDgnTorusPipe, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnTorusPipe));
    c8.def("TryGetDgnTorusPipeDetail", &ISolidPrimitive::TryGetDgnTorusPipeDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnTorusPipeDetail));
    c8.def("TrySetDgnTorusPipeDetail", &ISolidPrimitive::TrySetDgnTorusPipeDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnTorusPipeDetail));

    c8.def_static("CreateDgnCone", &ISolidPrimitive::CreateDgnCone, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnCone));
    c8.def("TryGetDgnConeDetail", &ISolidPrimitive::TryGetDgnConeDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnConeDetail));
    c8.def("TrySetDgnConeDetail", &ISolidPrimitive::TrySetDgnConeDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnConeDetail));

    c8.def_static("CreateDgnBox", &ISolidPrimitive::CreateDgnBox, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnBox));
    c8.def("TryGetDgnBoxDetail", &ISolidPrimitive::TryGetDgnBoxDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnBoxDetail));
    c8.def("TrySetDgnBoxDetail", &ISolidPrimitive::TrySetDgnBoxDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnBoxDetail));

    c8.def_static("CreateDgnSphere", &ISolidPrimitive::CreateDgnSphere, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnSphere));
    c8.def("TryGetDgnSphereDetail", &ISolidPrimitive::TryGetDgnSphereDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnSphereDetail));
    c8.def("TrySetDgnSphereDetail", &ISolidPrimitive::TrySetDgnSphereDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnSphereDetail));

    c8.def_static("CreateDgnExtrusion", &ISolidPrimitive::CreateDgnExtrusion, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnExtrusion));
    c8.def("TryGetDgnExtrusionDetail", &ISolidPrimitive::TryGetDgnExtrusionDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnExtrusionDetail));
    c8.def("TrySetDgnExtrusionDetail", &ISolidPrimitive::TrySetDgnExtrusionDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnExtrusionDetail));

    c8.def_static("CreateDgnRotationalSweep", &ISolidPrimitive::CreateDgnRotationalSweep, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnRotationalSweep));
    c8.def("TryGetDgnRotationalSweepDetail", &ISolidPrimitive::TryGetDgnRotationalSweepDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnRotationalSweepDetail));
    c8.def("TrySetDgnRotationalSweepDetail", &ISolidPrimitive::TrySetDgnRotationalSweepDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnRotationalSweepDetail));

    c8.def_static("CreateDgnRuledSweep", &ISolidPrimitive::CreateDgnRuledSweep, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, CreateDgnRuledSweep));
    c8.def("TryGetDgnRuledSweepDetail", &ISolidPrimitive::TryGetDgnRuledSweepDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetDgnRuledSweepDetail));
    c8.def("TrySetDgnRuledSweepDetail", &ISolidPrimitive::TrySetDgnRuledSweepDetail, "data"_a, DOC(Bentley, Geom, ISolidPrimitive, TrySetDgnRuledSweepDetail));

    c8.def("GetRange", py::overload_cast<DRange3dR>(&ISolidPrimitive::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, ISolidPrimitive, GetRange));
    c8.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&ISolidPrimitive::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, ISolidPrimitive, GetRange));
    c8.def("TryGetConstructiveFrame", &ISolidPrimitive::TryGetConstructiveFrame, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetConstructiveFrame));
    c8.def("IsSameStructure", &ISolidPrimitive::IsSameStructure, "other"_a, DOC(Bentley, Geom, ISolidPrimitive, IsSameStructure));
    c8.def("IsSameStructureAndGeometry", &ISolidPrimitive::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, ISolidPrimitive, IsSameStructureAndGeometry));
    c8.def("IsClosedVolume", &ISolidPrimitive::IsClosedVolume, DOC(Bentley, Geom, ISolidPrimitive, IsClosedVolume));

    c8.def_property("Capped", &ISolidPrimitive::GetCapped, &ISolidPrimitive::SetCapped);
    c8.def("GetCapped", &ISolidPrimitive::GetCapped, DOC(Bentley, Geom, ISolidPrimitive, GetCapped));
    c8.def("SetCapped", &ISolidPrimitive::SetCapped, "value"_a, DOC(Bentley, Geom, ISolidPrimitive, SetCapped));

    c8.def("AddRayIntersections", &ISolidPrimitive::AddRayIntersections, "pickData"_a, "ray"_a, "parentId"_a, "minParameter"_a = -DBL_MAX, DOC(Bentley, Geom, ISolidPrimitive, AddRayIntersections));
    c8.def("AddCurveIntersections",
           py::overload_cast<CurveVectorCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&ISolidPrimitive::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

    c8.def("AddCurveIntersections", [](ISolidPrimitiveCR self, CurveVectorCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

    c8.def("AddCurveIntersections", [](ISolidPrimitiveCR self, CurveVectorCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

    c8.def("AddCurveIntersections", [](ISolidPrimitiveCR self, CurveVectorCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
            CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
            CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
            }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

    c8.def("AddCurveIntersections",
           py::overload_cast<ICurvePrimitiveCR, CurveLocationDetailArray&, SolidLocationDetailArray&, MeshAnnotationVector&>(&ISolidPrimitive::AddCurveIntersections, py::const_),
           "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

    c8.def("AddCurveIntersections", [](ISolidPrimitiveCR self, ICurvePrimitiveCR curves, py::list& curvePoints, SolidLocationDetailArray& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, solidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

   c8.def("AddCurveIntersections", [](ISolidPrimitiveCR self, ICurvePrimitiveCR curves, CurveLocationDetailArray& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, curvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

   c8.def("AddCurveIntersections", [](ISolidPrimitiveCR self, ICurvePrimitiveCR curves, py::list& curvePoints, py::list& solidPoints, MeshAnnotationVector& messages)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           self.AddCurveIntersections(curves, cppCurvePoints, cppSolidPoints, messages);
           CONVERT_CPPARRAY_TO_PYLIST(curvePoints, cppCurvePoints, CurveLocationDetailArray, CurveLocationDetail);
           CONVERT_CPPARRAY_TO_PYLIST(solidPoints, cppSolidPoints, SolidLocationDetailArray, SolidLocationDetail);
           }, "curves"_a, "curvePoints"_a, "solidPoints"_a, "messages"_a, DOC(Bentley, Geom, ISolidPrimitive, AddCurveIntersections));

    c8.def("ClosestPoint", &ISolidPrimitive::ClosestPoint, "spacePoint"_a, "pickDetail"_a, DOC(Bentley, Geom, ISolidPrimitive, ClosestPoint));
    c8.def("TryUVFractionToXYZ", &ISolidPrimitive::TryUVFractionToXYZ, "faceIndices"_a, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, ISolidPrimitive, TryUVFractionToXYZ));
    c8.def("GetFace", &ISolidPrimitive::GetFace, "indices"_a, DOC(Bentley, Geom, ISolidPrimitive, GetFace));
    c8.def("GetFaceIndices", &ISolidPrimitive::GetFaceIndices, "indices"_a, DOC(Bentley, Geom, ISolidPrimitive, GetFaceIndices));
    c8.def("GetConstantVSection", &ISolidPrimitive::GetConstantVSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, ISolidPrimitive, GetConstantVSection));
    c8.def("GetConstantUSection", &ISolidPrimitive::GetConstantUSection, "indices"_a, "fraction"_a, DOC(Bentley, Geom, ISolidPrimitive, GetConstantUSection));
    c8.def("TryGetMaxUVLength", &ISolidPrimitive::TryGetMaxUVLength, "indices"_a, "uvLength"_a, DOC(Bentley, Geom, ISolidPrimitive, TryGetMaxUVLength));
    c8.def("Clone", &ISolidPrimitive::Clone, DOC(Bentley, Geom, ISolidPrimitive, Clone));
    c8.def("TransformInPlace", &ISolidPrimitive::TransformInPlace, "transform"_a, DOC(Bentley, Geom, ISolidPrimitive, TransformInPlace));

    c8.def_static("Simplify", &ISolidPrimitive::Simplify, "primitive"_a, DOC(Bentley, Geom, ISolidPrimitive, Simplify));
    c8.def("HasCurvedFaceOrEdge", &ISolidPrimitive::HasCurvedFaceOrEdge, DOC(Bentley, Geom, ISolidPrimitive, HasCurvedFaceOrEdge));

    c8.def("ComputePrincipalMoments", [] (ISolidPrimitiveCR self, DVec3dR centroid, RotMatrixR axes, DVec3dR momentxyz)
           {
           double volumn = 0;
           bool bOk = self.ComputePrincipalMoments(volumn, centroid, axes, momentxyz);
           return py::make_tuple(bOk, volumn);
           }, "centroid"_a, "axes"_a, "momentxyz"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputePrincipalMoments));

    c8.def("ComputeFacetedPrincipalMoments", [] (ISolidPrimitiveCR self, IFacetOptionsP options, DVec3dR centroid, RotMatrixR axes, DVec3dR momentxyz)
           {
           double volumn = 0;
           bool bOk = self.ComputeFacetedPrincipalMoments(options, volumn, centroid, axes, momentxyz);
           return py::make_tuple(bOk, volumn);
           }, "options"_a, "centroid"_a, "axes"_a, "momentxyz"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputeFacetedPrincipalMoments));

    c8.def("ComputePrincipalAreaMoments", [] (ISolidPrimitiveCR self, DVec3dR centroid, RotMatrixR axes, DVec3dR momentxyz)
           {
           double area = 0;
           bool bOk = self.ComputePrincipalAreaMoments(area, centroid, axes, momentxyz);
           return py::make_tuple(bOk, area);
           }, "centroid"_a, "axes"_a, "momentxyz"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputePrincipalAreaMoments));

    c8.def("ComputeFacetedPrincipalAreaMoments", [] (ISolidPrimitiveCR self, IFacetOptionsP options, DVec3dR centroid, RotMatrixR axes, DVec3dR momentxyz)
           {
           double area = 0;
           bool bOk = self.ComputeFacetedPrincipalAreaMoments(options, area, centroid, axes, momentxyz);
           return py::make_tuple(bOk, area);
           }, "options"_a, "centroid"_a, "axes"_a, "momentxyz"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputeFacetedPrincipalAreaMoments));

    c8.def("ComputeSecondMomentAreaProducts", 
           py::overload_cast<TransformR, DMatrix4dR>(&ISolidPrimitive::ComputeSecondMomentAreaProducts, py::const_),
           "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputeSecondMomentAreaProducts));

    c8.def("ComputeSecondMomentAreaProducts",
           py::overload_cast<DMatrix4dR>(&ISolidPrimitive::ComputeSecondMomentAreaProducts, py::const_),
           "worldProducts"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputeSecondMomentAreaProducts));

    c8.def("ComputeSecondMomentVolumeProducts",
           py::overload_cast<TransformR, DMatrix4dR>(&ISolidPrimitive::ComputeSecondMomentVolumeProducts, py::const_),
           "localToWorld"_a, "localProducts"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputeSecondMomentVolumeProducts));

    c8.def("ComputeSecondMomentVolumeProducts",
           py::overload_cast<DMatrix4dR>(&ISolidPrimitive::ComputeSecondMomentVolumeProducts, py::const_),
           "worldProducts"_a, DOC(Bentley, Geom, ISolidPrimitive, ComputeSecondMomentVolumeProducts));

    c8.def("SilhouetteCurves", &ISolidPrimitive::SilhouetteCurves, "eyePoint"_a, "curves"_a, DOC(Bentley, Geom, ISolidPrimitive, SilhouetteCurves));

    c8.def("__repr__", [] (ISolidPrimitive& self)
           {
           return "(type:{})"_s.format(self.GetSolidPrimitiveType());
           });
    }