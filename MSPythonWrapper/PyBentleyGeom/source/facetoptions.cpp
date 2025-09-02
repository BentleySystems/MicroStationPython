/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\facetoptions.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_IPolyfaceConstruction_RemapPseudoDistanceParams =R"doc(Apply the FacetParamMode to an array of parameters. On input, params
are in coordinates that can be scaled independently in x and y to
obtain distances. On ouptut, params are in PARAM_MODE_01BothAxes,
PARAM_MODE_01LargerAxis, or PARAM_MODE_Distance as requested by the
facet options in effect.

:param [in,out]:
    params parameters to remap.

:param (output):
    distanceRange range of parameters when scaled to distance (whether
    or not params are returned as distances)

:param (output):
    paramRange range of parameters as actually returned.

:param (input):
    xDistanceFactor scale factor to turn input x coordinates to
    distance (if distance requested either as final result or for
    larger axis scaling)

:param (input):
    yDistanceFactor scale factor to turn input y coordinates to
    distance (if distance requested either as final result or for
    larger axis scaling)

:param (output):
    transform optional transform (e.g. to be applied later to more
    params in the same parameter space) (May be nullptr))doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSolidPrimitive =R"doc(Add facets for all faces of a solid primitive.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddParamIndexStrip =R"doc(Add parameter quads between same-size indices.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddParamIndexFan =R"doc(Add parameter triangles from a center index to edges of a polyline.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndexPlanarStrip =R"doc(Add quads that share index to the a single normal.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndexPlanarFan =R"doc(Add triangles that share index to the a new normal whose coordinates
are the cross product of given vectors.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndexFan =R"doc(Add normal triangles from a center index to multiple edges.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPointIndexStrip =R"doc(Add point quads between EQUAL LENGTH index vectors.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPointIndexFan =R"doc(Add point triangles from a center index to edges of a polyline. spoke
edges are hidden, outer edges are visible.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddParams =R"doc(Find or add n indices. Return the n indices plus numWrap additional
wraparounds.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddNormals =R"doc(Find or add n indices. Return the n indices plus numWrap additional
wraparounds.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddPoints =R"doc(Find or add n indices. Return the n indices plus numWrap additional
wraparounds.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSweptNGon =R"doc(Sweep a regular polygon (parallel to xy plane) from z0 to z1.

:param (input):
    n number of edges. Must be 3 or greater.

:param (input):
    rOuter outer radius

:param (input):
    z0 start z

:param (input):
    z1 end z

:param (input):
    bottomCap true to include bottom cap

:param (input):
    topCap true to include top cap.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddFullSphere =R"doc(Add complete sphere.

:param (input):
    center ellipse center

:param (input):
    radius ellipse radius

:param (input):
    numPerQuadrantNS if nonzero overrides all option controls.

:param (input):
    numPerQuadrantEW if nonzero overrides all option controls.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddFullDiskTriangles =R"doc(Add complete disk. When options specify maxEdgeLength, triangles are
created without imposed radial edges.

:param (input):
    ellipse arc to stroke

:param (input):
    numPerQuadrant overrides all options controls.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddFullDisk =R"doc(Add complete disk. When options specify maxEdgeLength, radial lines go
full distance from center to edge. (See AddFulLDiskTriangles)

:param (input):
    ellipse arc to stroke

:param (input):
    numPerQuadrant overrides all options controls.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddRotationalSweepLoop =R"doc(Make a Rotational sweep from base points. To indicate a sharp corner,
duplicate the point, using incoming tangent on the first, outgoing on
the second. The zero-length edge will be skipped, and the sweep edge
will be marked visible.

:param (input):
    pointA base curve points

:param (input):
    tangentA base curve tangents

:param (input):
    center center of rotation

:param (input):
    rotationAxis rotation axis

:param (input):
    totalSweepRadians sweep angle

:param (input):
    reverse true to reverse facet orientations.

:param (input):
    nominalBaseCurveLength if nonzero, parameter distances along the
    base curve are scaled to this length

:param (input):
    startCapPointAccumulator optional array to receive fully
    transformed endcap points. This array is NOT cleared (so caller
    can combine over multiple calls.)

:param (input):
    endCapPointAccumulator optional array to receive fully transformed
    endcap points. This array is NOT cleared (so caller can combine
    over multiple calls.))doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddTriangulationPair =R"doc(AddTriangulation on 2 sets of points, optionally reversing each.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddTriangles =R"doc(Add all triangles to mesh. Optionally reverse orientations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddTriangulation =R"doc(Triangulate a space polygon and add to mesh. Disconnect points
separate multiple loops.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_Stroke =R"doc(Stroke with facet options from the PolyfaceConstruction. Return false
if not a simple loop.

Remark:
    points are doubled at hard corners (so the incoming and outgoing
    tangents can be distinguished))doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_StrokeWithDoubledPointsAtCorners =R"doc(Stroke with facet options from the PolyfaceConstruction. Return false
if not a simple loop.

Remark:
    points are doubled at hard corners (so the incoming and outgoing
    tangents can be distinguished))doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddRegion =R"doc(Add (triangulation of) the region bounded by a curve vector.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddRotationalSweep =R"doc(Add rotational sweep from curves)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddLinearSweep =R"doc(Make a linear sweep from base points. To indicate a sharp corner,
duplicate the point, using incoming tangent on the first, outgoing on
the second. Any zero-length edge will be skipped, and the sweep edge
will be marked visible.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddTubeMesh =R"doc(Add facets to a mesh. Facets approximate a tube around a centerline.
The centerline curve (bspline) should be planar or nearly so. (If it
is not, the successive circular sections may pinch in strange ways)

:param (input):
    centerlineCurve tube centerline

:param (input):
    radius tube radius

:param (input):
    numEdgePerSection number of edges around each section circle. If
    zero, determined from builder's facet options.

:param (input):
    numSectionEdge number of edges along curve. If zero, determined
    from builder's facet options.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddTriStrip =R"doc(Add square grid with normal, param at each point.

:param (input):
    points coordinates alternating between bottom and top of strip.

:param (input):
    params corresponding parameters

:param (input):
    normals corresponding normals

:param (input):
    numPoint number of points (2 more than number of triangles)

:param (input):
    firstTriangle012 true if 012 is leading triangle order, false if
    021 is leading triangle order.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddRowMajorQuadGrid =R"doc(Add square grid with normal, param at each point.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSmoothed =R"doc(Add bspline surface mesh, with smoothing effects.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_Add =R"doc(Add bspline surface mesh)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddRuled =R"doc(Add ruled facets between ellipses.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetWorldToLocalScale =R"doc(Get the (average) scale factor of the world to local transform.

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetLocalToWorldScale =R"doc(Get the (average) scale factor of the local to world transform.

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_ToggleIndexOrderAndNormalReversal =R"doc(Toggle both index order and normal)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetLocalToWorldNormals =R"doc(Get the local to world matrix for surface normals.

:param (output):
    matrix returned matrix

:returns:
    false if no local to world transform is in effect.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_SetReverseNewNormals =R"doc(Set the current normal vector reversal state.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_SetReverseNewFacetIndexOrder =R"doc(Set the current facet index reversal state.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_PopState =R"doc(Pop the current transform and revesal state.

:returns:
    true if the stack had a state to pop.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_PushState =R"doc(Push the current transform and revesal state.

:param (input):
    initializeCurrentState controls whether current state is
    reinitialized (true) or left unchanged (false))doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_MultiplyNormalByLocalToWorld =R"doc(Multiply a surface normal by the local to world effects and
renormalize. This also applies the normal reversal flag.

:returns:
    transformed ponit.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_MultiplyByLocalToWorld =R"doc(Multiply the local to world transform times the input point.

:returns:
    transformed point.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_ApplyLocalToWorld =R"doc(Apply (right multiply) the local to world transform.

:returns:
    false if the given transform is not invertible.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_SetLocalToWorld =R"doc(Set the local to world transform.

:returns:
    false if the given transform is not invertible.

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetLocalToWorld =R"doc(Get the local to world placement transform.

:returns:
    false if the transform is an identity.

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_IsTransformed =R"doc(Ask if the local to world transform is nontrivial

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetWorldToLocal =R"doc(Get the world to local placement transform.

:returns:
    false if the transform is an identity.

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetReverseNewNormals =R"doc(Get the current normal vector reversal state.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetReverseNewFacetIndexOrder =R"doc(Ask if facets are to be reversed as received.

Remark:
    s This is affected by PushState/PopState operations.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_InitializeCurrentConstructionState =R"doc(Clear the current construction state, but leave the stack unchanged.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_InitializeConstructionStateAndStack =R"doc(Clear the construction state stack and set current state.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_NeedParams =R"doc(Ask if params are needed.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_NeedNormals =R"doc(Ask if normals are needed.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPolyface =R"doc(Add polyface mesh.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddColorIndexQuad =R"doc(Add a quad to the color index table. Return the (0-based) position in
the ColorIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddParamIndexQuad =R"doc(Add a quad to the param index table. Return the (0-based) position in
the ParamIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndexQuad =R"doc(Add a quad to the normal index table. Return the (0-based) position in
the NormalIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPointIndexQuad =R"doc(Add a quad to the point index table. Return the (0-based) position in
the PointIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddColorIndexTriangle =R"doc(Add a triangle to the color index table. Return the (0-based) position
in the ColorIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddParamIndexTriangle =R"doc(Add a triangle to the param index table. Return the (0-based) position
in the ParamIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndexTriangle =R"doc(Add a triangle to the normal index table. Return the (0-based)
position in the NormalIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPointIndexTriangle =R"doc(Add a triangle to the point index table. Return the (0-based) position
in the PointIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddColorIndexTerminator =R"doc(Add a terminator to the color index table. Return the (0-based)
position in the ColorIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddParamIndexTerminator =R"doc(Add a terminator to the param index table. Return the (0-based)
position in the ParamIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndexTerminator =R"doc(Add a terminator to the normal index table. Return the (0-based)
position in the NormalIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPointIndexTerminator =R"doc(Add a terminator to the point index table. Return the (0-based)
position in the PointIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSignedOneBasedColorIndex =R"doc(Add a color index, directly, i.e. caller is responsible for providing
a one based index)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSignedOneBasedParamIndex =R"doc(Add a param index, directly, i.e. caller is responsible for providing
a one based index)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSignedOneBasedNormalIndex =R"doc(Add a normal index, directly, i.e. caller is responsible for providing
a one based index)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddSignedOneBasedPointIndex =R"doc(Add a point index directly, i.e. caller is responsible for providing a
one based index with optional negation for hidden edges.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddColorIndex =R"doc(Add a color index, adjusted to 1-based indexing Return the (0-based)
position in the ParamIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddParamIndex =R"doc(Add a param index, adjusted to 1-based indexing Return the (0-based)
position in the ParamIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddNormalIndex =R"doc(Add a normal index, adjusted to 1-based indexing. Return the (0-based)
position in the NormalIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_AddPointIndex =R"doc(Add a point index, adjusted to 1-based indexing with visibility in
sign. Return the (0-based) position in the PointIndex array.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddDoubleColor =R"doc(Find or add a color. Return the (0-based) index.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddParam =R"doc(Find or add a param. Return the (0-based) index.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddNormal =R"doc(Find or add a normal. Return the (0-based) index.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_FindOrAddPoint =R"doc(Find or add a point. Return the (0-based) index.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_Clear =R"doc(Clear client mesh and all construction support)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_EndFace =R"doc(Finalize data for the current face.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_CollectCurrentFaceRanges =R"doc(Collect point, param, and normal range data in the current face.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_SetCurrentFaceParamDistanceRange =R"doc(Set (only) the paramDistance range part of the current FacetFacetData.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_IncrementFaceIndex =R"doc(Increment the (modal) face index. (And clear the modal parameter
range) return the (incremented) index.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_SetFaceData =R"doc(Set the current face data.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetFaceData =R"doc(Return the current face data.)doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_SetFaceIndex =R"doc(Set the (modal) face index. (And clear the modal parameter range))doc";

static const char * __doc_Bentley_Geom_IPolyfaceConstruction_GetFaceIndex =R"doc(Get the (modal) face index.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_LineStringStrokeCount =R"doc(Comptue the number of strokes needed for a linestring. This is the sum
of counts on individual segments.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_BsplineCurveStrokeCount =R"doc(Comptue the number of strokes needed for a bspline curve.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_EllipseStrokeCount =R"doc(Compute the number of strokes needed for a partial ellipse.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_FullEllipseStrokeCount =R"doc(Compute the number of strokes needed for a complete ellipse.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_DistanceAndTurnStrokeCount =R"doc(Compute the number of strokes needed for distance with turn.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_DistanceStrokeCount =R"doc(Compute the number of strokes needed for a distance.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SegmentStrokeCount =R"doc(Compute the number of strokes needed for a line segment.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_BezierStrokeCount =R"doc(Compute the number of strokes needed for a (weighted) bezier.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_CreateForCurves =R"doc(Return a (smart pointer) implementation of the interface, with
tolerances set for typical curves.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_CreateForSurfaces =R"doc(Return a (smart pointer) implementation of the interface)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_Clone =R"doc(Create a copy.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetCurveDefaults =R"doc(Set all parameters to default values for curves. (This will have finer
angle tolerance than surfaces))doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetDefaults =R"doc(Set all parameters to default values)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetHideSmoothEdgesWhenGeneratingNormals =R"doc(Set whether smooth edges between facets are marked as hidden when
normals are genereted for a polyface without normals.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetHideSmoothEdgesWhenGeneratingNormals =R"doc(Get whether mooth edges between facets are marked as hidden when
normals are genereted for a polyface without normals.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetIgnoreFaceMaterialAttachments =R"doc(Set whether facets returned for BReps are separated by color/material
when there is per-face symbology attachments.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetIgnoreFaceMaterialAttachments =R"doc(Get whether facets returned for BReps are separated by color/material
when there is per-face symbology attachments.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetToleranceDistanceScale =R"doc(Set the ToleranceDistanceScale facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetToleranceDistanceScale =R"doc(Get the ToleranceDistanceScale facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetParamDistanceScale =R"doc(Set the ParamDistanceScale facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetParamDistanceScale =R"doc(Get the ParamDistanceScale facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetParamMode =R"doc(Set the ParamMode facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetParamMode =R"doc(Get the ParamMode facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetConvexFacetsRequired =R"doc(Set the ConvexFacetsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetConvexFacetsRequired =R"doc(Get the ConvexFacetsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetCombineFacets =R"doc(Set the CombineFacets facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetCombineFacets =R"doc(Get the CombineFacets facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetCurvedSurfaceMaxPerFace =R"doc(Set the CurvedSurfaceMaxPerFace facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetCurvedSurfaceMaxPerFace =R"doc(Get the CurvedSurfaceMaxPerFace facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetSilhouetteToleranceDivisor =R"doc(Set the SilhouetteToleranceDivisor facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetSilhouetteToleranceDivisor =R"doc(Get the SilhouetteToleranceDivisor facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetSilhouetteType =R"doc(Set the SilhouetteType facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetSilhouetteType =R"doc(Get the SilhouetteType facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetSilhouetteOrigin =R"doc(Set the SilhouetteOrigin facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetSilhouetteOrigin =R"doc(Get the SilhouetteOrigin facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetSilhouetteDirection =R"doc(Set the SilhouetteDirection facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetSilhouetteDirection =R"doc(Get the SilhouetteDirection facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetVertexColorsRequired =R"doc(Set the VertexColorsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetVertexColorsRequired =R"doc(Get the VertexColorsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetCurveParameterMapping =R"doc(Set the CurveParameterMapping facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetCurveParameterMapping =R"doc(Get the CurveParameterMapping facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetCurvatureWeightFactor =R"doc(Set the CurvatureWeightFactor facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetCurvatureWeightFactor =R"doc(Get the CurvatureWeightFactor control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetDoSpatialLaplaceSmoothing =R"doc(Set the SmoothTriangleFlow facet control -- bspline surfaces only. A
true unqualified SetSmoothTriangleFlowRequired overrides false for the
Bsurf setting!!)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetDoSpatialLaplaceSmoothing =R"doc(Get the SmoothTriangleFlow facet control -- bspline surfaces only.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetBSurfSmoothTriangleFlowRequired =R"doc(Set the SmoothTriangleFlow facet control -- bspline surfaces only. A
true unqualified SetSmoothTriangleFlowRequired overrides false for the
Bsurf setting!!)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetBSurfSmoothTriangleFlowRequired =R"doc(Get the SmoothTriangleFlow facet control -- bspline surfaces only.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetSmoothTriangleFlowRequired =R"doc(Set the SmoothTriangleFlow facet control. (This can apply to both
bspline and non-bspline. See)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetSmoothTriangleFlowRequired =R"doc(Get the SmoothTriangleFlow facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetEdgeChainsRequired =R"doc(Set the EdgeChainsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetEdgeChainsRequired =R"doc(Get the EdgeChainsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetParamsRequired =R"doc(Set the ParamsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetParamsRequired =R"doc(Get the ParamsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetNormalsRequired =R"doc(Set the NormalsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetNormalsRequired =R"doc(Get the NormalsRequired facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetEdgeHiding =R"doc(Set the EdgeHiding facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetEdgeHiding =R"doc(Get the EdgeHiding facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetMaxPerFace =R"doc(Set the MaxPerFace facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetMaxPerFace =R"doc(Get the MaxPerFace facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetMinPerBezier =R"doc(Set the MinPerBezier facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetMinPerBezier =R"doc(Get the MinPerBezier facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetMaxPerBezier =R"doc(Set the MaxPerBezier facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetMaxPerBezier =R"doc(Get the MaxPerBezier facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetAngleTolerance =R"doc(Set the AngleTolerance facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetAngleTolerance =R"doc(Get the AngleTolerance facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetMaxEdgeLength =R"doc(Set the MaxEdgeLength facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetMaxEdgeLength =R"doc(Get the MaxEdgeLength facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetMaxFacetWidth =R"doc(Sets maximum facet width. As of now, only bodies faceted by Parasolid
use this parameter.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetMaxFacetWidth =R"doc(Gets the maximum facet width.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_SetChordTolerance =R"doc(Set the ChordTolerance facet control.)doc";

static const char * __doc_Bentley_Geom_IFacetOptions_GetChordTolerance =R"doc(Get the ChordTolerance facet control.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_FacetOptions(py::module_& m)
    {
    //===================================================================================
    // Enum FacetParamMode
    py::enum_<FacetParamMode>(m, "FacetParamMode")
        .value("eFACET_PARAM_01BothAxes", FACET_PARAM_01BothAxes)
        .value("eFACET_PARAM_01LargerAxis", FACET_PARAM_01LargerAxis)
        .value("eFACET_PARAM_Distance", FACET_PARAM_Distance)
        .export_values();

    //===================================================================================
    // struct IFacetOptions
    py::class_<IFacetOptions, IFacetOptionsPtr> c1(m, "IFacetOptions");

    c1.def(py::init(&IFacetOptions::Create));    
    
    c1.def_property("ChordTolerance", &IFacetOptions::GetChordTolerance, &IFacetOptions::SetChordTolerance);
    c1.def("GetChordTolerance", &IFacetOptions::GetChordTolerance, DOC(Bentley, Geom, IFacetOptions, GetChordTolerance));
    c1.def("SetChordTolerance", &IFacetOptions::SetChordTolerance, "chordTolerance"_a, DOC(Bentley, Geom, IFacetOptions, SetChordTolerance));

    c1.def_property("MaxFacetWidth", &IFacetOptions::GetMaxFacetWidth, &IFacetOptions::SetMaxFacetWidth);
    c1.def("GetMaxFacetWidth", &IFacetOptions::GetMaxFacetWidth, DOC(Bentley, Geom, IFacetOptions, GetMaxFacetWidth));
    c1.def("SetMaxFacetWidth", &IFacetOptions::SetMaxFacetWidth, "maxWidth"_a, DOC(Bentley, Geom, IFacetOptions, SetMaxFacetWidth));

    c1.def_property("MaxEdgeLength", &IFacetOptions::GetMaxEdgeLength, &IFacetOptions::SetMaxEdgeLength);
    c1.def("GetMaxEdgeLength", &IFacetOptions::GetMaxEdgeLength, DOC(Bentley, Geom, IFacetOptions, GetMaxEdgeLength));
    c1.def("SetMaxEdgeLength", &IFacetOptions::SetMaxEdgeLength, "maxEdgeLength"_a, DOC(Bentley, Geom, IFacetOptions, SetMaxEdgeLength));

    c1.def_property("AngleTolerance", &IFacetOptions::GetAngleTolerance, &IFacetOptions::SetAngleTolerance);
    c1.def("GetAngleTolerance", &IFacetOptions::GetAngleTolerance, DOC(Bentley, Geom, IFacetOptions, GetAngleTolerance));
    c1.def("SetAngleTolerance", &IFacetOptions::SetAngleTolerance, "normalAngleTolerance"_a, DOC(Bentley, Geom, IFacetOptions, SetAngleTolerance));

    c1.def_property("MaxPerBezier", &IFacetOptions::GetMaxPerBezier, &IFacetOptions::SetMaxPerBezier);
    c1.def("GetMaxPerBezier", &IFacetOptions::GetMaxPerBezier, DOC(Bentley, Geom, IFacetOptions, GetMaxPerBezier));
    c1.def("SetMaxPerBezier", &IFacetOptions::SetMaxPerBezier, "maxPerBezier"_a, DOC(Bentley, Geom, IFacetOptions, SetMaxPerBezier));

    c1.def_property("MinPerBezier", &IFacetOptions::GetMinPerBezier, &IFacetOptions::SetMinPerBezier);
    c1.def("GetMinPerBezier", &IFacetOptions::GetMinPerBezier, DOC(Bentley, Geom, IFacetOptions, GetMinPerBezier));
    c1.def("SetMinPerBezier", &IFacetOptions::SetMinPerBezier, "minPerBezier"_a, DOC(Bentley, Geom, IFacetOptions, SetMinPerBezier));

    c1.def_property("MaxPerFace", &IFacetOptions::GetMaxPerFace, &IFacetOptions::SetMaxPerFace);
    c1.def("GetMaxPerFace", &IFacetOptions::GetMaxPerFace, DOC(Bentley, Geom, IFacetOptions, GetMaxPerFace));
    c1.def("SetMaxPerFace", &IFacetOptions::SetMaxPerFace, "maxPerFace"_a, DOC(Bentley, Geom, IFacetOptions, SetMaxPerFace));

    c1.def_property("EdgeHiding", &IFacetOptions::GetEdgeHiding, &IFacetOptions::SetEdgeHiding);
    c1.def("GetEdgeHiding", &IFacetOptions::GetEdgeHiding, DOC(Bentley, Geom, IFacetOptions, GetEdgeHiding));
    c1.def("SetEdgeHiding", &IFacetOptions::SetEdgeHiding, "edgeHiding"_a, DOC(Bentley, Geom, IFacetOptions, SetEdgeHiding));

    c1.def_property("NormalsRequired", &IFacetOptions::GetNormalsRequired, &IFacetOptions::SetNormalsRequired);
    c1.def("GetNormalsRequired", &IFacetOptions::GetNormalsRequired, DOC(Bentley, Geom, IFacetOptions, GetNormalsRequired));
    c1.def("SetNormalsRequired", &IFacetOptions::SetNormalsRequired, "normalIsRequired"_a, DOC(Bentley, Geom, IFacetOptions, SetNormalsRequired));

    c1.def_property("ParamsRequired", &IFacetOptions::GetParamsRequired, &IFacetOptions::SetParamsRequired);
    c1.def("GetParamsRequired", &IFacetOptions::GetParamsRequired, DOC(Bentley, Geom, IFacetOptions, GetParamsRequired));
    c1.def("SetParamsRequired", &IFacetOptions::SetParamsRequired, "paramsRequired"_a, DOC(Bentley, Geom, IFacetOptions, SetParamsRequired));

    c1.def_property("EdgeChainsRequired", &IFacetOptions::GetEdgeChainsRequired, &IFacetOptions::SetEdgeChainsRequired);
    c1.def("GetEdgeChainsRequired", &IFacetOptions::GetEdgeChainsRequired, DOC(Bentley, Geom, IFacetOptions, GetEdgeChainsRequired));
    c1.def("SetEdgeChainsRequired", &IFacetOptions::SetEdgeChainsRequired, "edgeChainRequired"_a, DOC(Bentley, Geom, IFacetOptions, SetEdgeChainsRequired));   

    c1.def_property("SmoothTriangleFlowRequired", &IFacetOptions::GetSmoothTriangleFlowRequired, &IFacetOptions::SetSmoothTriangleFlowRequired);
    c1.def("GetSmoothTriangleFlowRequired", &IFacetOptions::GetSmoothTriangleFlowRequired, DOC(Bentley, Geom, IFacetOptions, GetSmoothTriangleFlowRequired));
    c1.def("SetSmoothTriangleFlowRequired", &IFacetOptions::SetSmoothTriangleFlowRequired, "value"_a, DOC(Bentley, Geom, IFacetOptions, SetSmoothTriangleFlowRequired));

    c1.def_property("BSurfSmoothTriangleFlowRequired", &IFacetOptions::GetBSurfSmoothTriangleFlowRequired, &IFacetOptions::SetBSurfSmoothTriangleFlowRequired);
    c1.def("GetBSurfSmoothTriangleFlowRequired", &IFacetOptions::GetBSurfSmoothTriangleFlowRequired, DOC(Bentley, Geom, IFacetOptions, GetBSurfSmoothTriangleFlowRequired));
    c1.def("SetBSurfSmoothTriangleFlowRequired", &IFacetOptions::SetBSurfSmoothTriangleFlowRequired, "value"_a, DOC(Bentley, Geom, IFacetOptions, SetBSurfSmoothTriangleFlowRequired));

    c1.def_property("DoSpatialLaplaceSmoothing", &IFacetOptions::GetDoSpatialLaplaceSmoothing, &IFacetOptions::SetDoSpatialLaplaceSmoothing);
    c1.def("GetDoSpatialLaplaceSmoothing", &IFacetOptions::GetDoSpatialLaplaceSmoothing, DOC(Bentley, Geom, IFacetOptions, GetDoSpatialLaplaceSmoothing));
    c1.def("SetDoSpatialLaplaceSmoothing", &IFacetOptions::SetDoSpatialLaplaceSmoothing, "value"_a, DOC(Bentley, Geom, IFacetOptions, SetDoSpatialLaplaceSmoothing));

    c1.def_property("CurvatureWeightFactor", &IFacetOptions::GetCurvatureWeightFactor, &IFacetOptions::SetCurvatureWeightFactor);
    c1.def("GetCurvatureWeightFactor", &IFacetOptions::GetCurvatureWeightFactor, DOC(Bentley, Geom, IFacetOptions, GetCurvatureWeightFactor));
    c1.def("SetCurvatureWeightFactor", &IFacetOptions::SetCurvatureWeightFactor, "value"_a, DOC(Bentley, Geom, IFacetOptions, SetCurvatureWeightFactor));

    c1.def_property("CurveParameterMapping", &IFacetOptions::GetCurveParameterMapping, &IFacetOptions::SetCurveParameterMapping);
    c1.def("GetCurveParameterMapping", &IFacetOptions::GetCurveParameterMapping, DOC(Bentley, Geom, IFacetOptions, GetCurveParameterMapping));
    c1.def("SetCurveParameterMapping", &IFacetOptions::SetCurveParameterMapping, "curveParameterMapping"_a, DOC(Bentley, Geom, IFacetOptions, SetCurveParameterMapping));

    c1.def_property("VertexColorsRequired", &IFacetOptions::GetVertexColorsRequired, &IFacetOptions::SetVertexColorsRequired);
    c1.def("GetVertexColorsRequired", &IFacetOptions::GetVertexColorsRequired, DOC(Bentley, Geom, IFacetOptions, GetVertexColorsRequired));
    c1.def("SetVertexColorsRequired", &IFacetOptions::SetVertexColorsRequired, "vertexColorsRequired"_a, DOC(Bentley, Geom, IFacetOptions, SetVertexColorsRequired));

    c1.def_property("SilhouetteDirection", &IFacetOptions::GetSilhouetteDirection, &IFacetOptions::SetSilhouetteDirection);
    c1.def("GetSilhouetteDirection", &IFacetOptions::GetSilhouetteDirection, DOC(Bentley, Geom, IFacetOptions, GetSilhouetteDirection));
    c1.def("SetSilhouetteDirection", &IFacetOptions::SetSilhouetteDirection, "silhouetteDirection"_a, DOC(Bentley, Geom, IFacetOptions, SetSilhouetteDirection));

    c1.def_property("SilhouetteOrigin", &IFacetOptions::GetSilhouetteOrigin, &IFacetOptions::SetSilhouetteOrigin);
    c1.def("GetSilhouetteOrigin", &IFacetOptions::GetSilhouetteOrigin, DOC(Bentley, Geom, IFacetOptions, GetSilhouetteOrigin));
    c1.def("SetSilhouetteOrigin", &IFacetOptions::SetSilhouetteOrigin, "silhouetteOrigin"_a, DOC(Bentley, Geom, IFacetOptions, SetSilhouetteOrigin));

    c1.def_property("SilhouetteType", &IFacetOptions::GetSilhouetteType, &IFacetOptions::SetSilhouetteType);
    c1.def("GetSilhouetteType", &IFacetOptions::GetSilhouetteType, DOC(Bentley, Geom, IFacetOptions, GetSilhouetteType));
    c1.def("SetSilhouetteType", &IFacetOptions::SetSilhouetteType, "silhouetteType"_a, DOC(Bentley, Geom, IFacetOptions, SetSilhouetteType));

    c1.def_property("SilhouetteToleranceDivisor", &IFacetOptions::GetSilhouetteToleranceDivisor, &IFacetOptions::SetSilhouetteToleranceDivisor);
    c1.def("GetSilhouetteToleranceDivisor", &IFacetOptions::GetSilhouetteToleranceDivisor, DOC(Bentley, Geom, IFacetOptions, GetSilhouetteToleranceDivisor));
    c1.def("SetSilhouetteToleranceDivisor", &IFacetOptions::SetSilhouetteToleranceDivisor, "silhouetteToleranceDivisor"_a, DOC(Bentley, Geom, IFacetOptions, SetSilhouetteToleranceDivisor));

    c1.def_property("CurvedSurfaceMaxPerFace", &IFacetOptions::GetCurvedSurfaceMaxPerFace, &IFacetOptions::SetCurvedSurfaceMaxPerFace);
    c1.def("GetCurvedSurfaceMaxPerFace", &IFacetOptions::GetCurvedSurfaceMaxPerFace, DOC(Bentley, Geom, IFacetOptions, GetCurvedSurfaceMaxPerFace));
    c1.def("SetCurvedSurfaceMaxPerFace", &IFacetOptions::SetCurvedSurfaceMaxPerFace, "curvedSurfaceMaxPerFace"_a, DOC(Bentley, Geom, IFacetOptions, SetCurvedSurfaceMaxPerFace));

    c1.def_property("CombineFacets", &IFacetOptions::GetCombineFacets, &IFacetOptions::SetCombineFacets);
    c1.def("GetCombineFacets", &IFacetOptions::GetCombineFacets, DOC(Bentley, Geom, IFacetOptions, GetCombineFacets));
    c1.def("SetCombineFacets", &IFacetOptions::SetCombineFacets, "combineFacets"_a, DOC(Bentley, Geom, IFacetOptions, SetCombineFacets));

    c1.def_property("ConvexFacetsRequired", &IFacetOptions::GetConvexFacetsRequired, &IFacetOptions::SetConvexFacetsRequired);
    c1.def("GetConvexFacetsRequired", &IFacetOptions::GetConvexFacetsRequired, DOC(Bentley, Geom, IFacetOptions, GetConvexFacetsRequired));
    c1.def("SetConvexFacetsRequired", &IFacetOptions::SetConvexFacetsRequired, "convexFacetsRequired"_a, DOC(Bentley, Geom, IFacetOptions, SetConvexFacetsRequired));

    c1.def_property("ParamMode", &IFacetOptions::GetParamMode, &IFacetOptions::SetParamMode);
    c1.def("GetParamMode", &IFacetOptions::GetParamMode, DOC(Bentley, Geom, IFacetOptions, GetParamMode));
    c1.def("SetParamMode", &IFacetOptions::SetParamMode, "paramMode"_a, DOC(Bentley, Geom, IFacetOptions, SetParamMode));

    c1.def_property("ParamDistanceScale", &IFacetOptions::GetParamDistanceScale, &IFacetOptions::SetParamDistanceScale);
    c1.def("GetParamDistanceScale", &IFacetOptions::GetParamDistanceScale, DOC(Bentley, Geom, IFacetOptions, GetParamDistanceScale));
    c1.def("SetParamDistanceScale", &IFacetOptions::SetParamDistanceScale, "paramDistanceScale"_a, DOC(Bentley, Geom, IFacetOptions, SetParamDistanceScale));

    c1.def_property("ToleranceDistanceScale", &IFacetOptions::GetToleranceDistanceScale, &IFacetOptions::SetToleranceDistanceScale);
    c1.def("GetToleranceDistanceScale", &IFacetOptions::GetToleranceDistanceScale, DOC(Bentley, Geom, IFacetOptions, GetToleranceDistanceScale));
    c1.def("SetToleranceDistanceScale", &IFacetOptions::SetToleranceDistanceScale, "toleranceDistanceScale"_a, DOC(Bentley, Geom, IFacetOptions, SetToleranceDistanceScale));

    c1.def_property("IgnoreFaceMaterialAttachments", &IFacetOptions::GetIgnoreFaceMaterialAttachments, &IFacetOptions::SetIgnoreFaceMaterialAttachments);
    c1.def("GetIgnoreFaceMaterialAttachments", &IFacetOptions::GetIgnoreFaceMaterialAttachments, DOC(Bentley, Geom, IFacetOptions, GetIgnoreFaceMaterialAttachments));
    c1.def("SetIgnoreFaceMaterialAttachments", &IFacetOptions::SetIgnoreFaceMaterialAttachments, "inoreFaceAttachments"_a, DOC(Bentley, Geom, IFacetOptions, SetIgnoreFaceMaterialAttachments));

    c1.def_property("HideSmoothEdgesWhenGeneratingNormals", &IFacetOptions::GetHideSmoothEdgesWhenGeneratingNormals, &IFacetOptions::SetHideSmoothEdgesWhenGeneratingNormals);
    c1.def("GetHideSmoothEdgesWhenGeneratingNormals", &IFacetOptions::GetHideSmoothEdgesWhenGeneratingNormals, DOC(Bentley, Geom, IFacetOptions, GetHideSmoothEdgesWhenGeneratingNormals));
    c1.def("SetHideSmoothEdgesWhenGeneratingNormals", &IFacetOptions::SetHideSmoothEdgesWhenGeneratingNormals, "hideSmoothEdgesWhenGeneratingNormals"_a, DOC(Bentley, Geom, IFacetOptions, SetHideSmoothEdgesWhenGeneratingNormals));

    c1.def("SetDefaults", &IFacetOptions::SetDefaults, DOC(Bentley, Geom, IFacetOptions, SetDefaults));
    c1.def("SetCurveDefaults", &IFacetOptions::SetCurveDefaults, DOC(Bentley, Geom, IFacetOptions, SetCurveDefaults));
    c1.def("Clone", &IFacetOptions::Clone, DOC(Bentley, Geom, IFacetOptions, Clone));

    c1.def_static("CreateForSurfaces", 
                  &IFacetOptions::CreateForSurfaces, 
                  "chordTol"_a = 0.0,
                  "angleRadians"_a = msGeomConst_piOver12,
                  "maxEdgeLength"_a = 0.0,
                  "triangulate"_a = false,
                  "normals"_a = false,
                  "params"_a = false, DOC(Bentley, Geom, IFacetOptions, CreateForSurfaces));

    c1.def_static("CreateForCurves", &IFacetOptions::CreateForCurves, DOC(Bentley, Geom, IFacetOptions, CreateForCurves));

    c1.def("BezierStrokeCount", [] (IFacetOptionsCR self, DPoint4dArray const& poles, size_t index0, int order)
           {
           size_t count = 0;
           bool bOk = self.BezierStrokeCount(poles, index0, order, count);
           return py::make_tuple(bOk, count);
           }, "poles"_a, "index0"_a, "order"_a, DOC(Bentley, Geom, IFacetOptions, BezierStrokeCount));

    c1.def("SegmentStrokeCount", &IFacetOptions::SegmentStrokeCount, "segment"_a, DOC(Bentley, Geom, IFacetOptions, SegmentStrokeCount));            
    c1.def("DistanceStrokeCount", &IFacetOptions::DistanceStrokeCount, "distance"_a, DOC(Bentley, Geom, IFacetOptions, DistanceStrokeCount));            
    c1.def("DistanceAndTurnStrokeCount", py::overload_cast<double, double>(&IFacetOptions::DistanceAndTurnStrokeCount, py::const_), "distance"_a, "turnRadians"_a, DOC(Bentley, Geom, IFacetOptions, DistanceAndTurnStrokeCount));            
    c1.def("FullEllipseStrokeCount", &IFacetOptions::FullEllipseStrokeCount, "ellipse"_a, DOC(Bentley, Geom, IFacetOptions, FullEllipseStrokeCount));            
    c1.def("EllipseStrokeCount", &IFacetOptions::EllipseStrokeCount, "ellipse"_a, DOC(Bentley, Geom, IFacetOptions, EllipseStrokeCount));            
    c1.def("BsplineCurveStrokeCount", &IFacetOptions::BsplineCurveStrokeCount, "curve"_a, DOC(Bentley, Geom, IFacetOptions, BsplineCurveStrokeCount));
    c1.def("LineStringStrokeCount", &IFacetOptions::LineStringStrokeCount, "points"_a, DOC(Bentley, Geom, IFacetOptions, LineStringStrokeCount));
    
    //===================================================================================
    // struct IPolyfaceConstruction
    py::class_< IPolyfaceConstruction, IPolyfaceConstructionPtr> c2(m, "IPolyfaceConstruction");

    c2.def(py::init(&IPolyfaceConstruction::Create), "options"_a);

    c2.def_property("FaceIndex", &IPolyfaceConstruction::GetFaceIndex, &IPolyfaceConstruction::SetFaceIndex);
    c2.def("GetFaceIndex", &IPolyfaceConstruction::GetFaceIndex, DOC(Bentley, Geom, IPolyfaceConstruction, GetFaceIndex));
    c2.def("SetFaceIndex", &IPolyfaceConstruction::SetFaceIndex, "index"_a, DOC(Bentley, Geom, IPolyfaceConstruction, SetFaceIndex));

    c2.def_property("FaceData", &IPolyfaceConstruction::GetFaceData, &IPolyfaceConstruction::SetFaceData);
    c2.def("GetFaceData", &IPolyfaceConstruction::GetFaceData, DOC(Bentley, Geom, IPolyfaceConstruction, GetFaceData));
    c2.def("SetFaceData", &IPolyfaceConstruction::SetFaceData, "data"_a, DOC(Bentley, Geom, IPolyfaceConstruction, SetFaceData));

    c2.def("IncrementFaceIndex", &IPolyfaceConstruction::IncrementFaceIndex, DOC(Bentley, Geom, IPolyfaceConstruction, IncrementFaceIndex));            
    c2.def("SetCurrentFaceParamDistanceRange", &IPolyfaceConstruction::SetCurrentFaceParamDistanceRange, "range"_a, DOC(Bentley, Geom, IPolyfaceConstruction, SetCurrentFaceParamDistanceRange));

    c2.def("CollectCurrentFaceRanges", &IPolyfaceConstruction::CollectCurrentFaceRanges, DOC(Bentley, Geom, IPolyfaceConstruction, CollectCurrentFaceRanges));
    c2.def("EndFace", &IPolyfaceConstruction::EndFace, DOC(Bentley, Geom, IPolyfaceConstruction, EndFace));
    c2.def("Clear", &IPolyfaceConstruction::Clear, DOC(Bentley, Geom, IPolyfaceConstruction, Clear));

    c2.def("FindOrAddPoint", &IPolyfaceConstruction::FindOrAddPoint, "point"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddPoint));
    c2.def("FindOrAddNormal", &IPolyfaceConstruction::FindOrAddNormal, "normal"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddNormal));
    c2.def("FindOrAddParam", &IPolyfaceConstruction::FindOrAddParam, "param"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddParam));
    c2.def("FindOrAddDoubleColor", &IPolyfaceConstruction::FindOrAddDoubleColor, "color"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddDoubleColor));

    c2.def("AddPointIndex", &IPolyfaceConstruction::AddPointIndex, "zeroBasedIndex"_a, "visible"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndex));
    c2.def("AddNormalIndex", &IPolyfaceConstruction::AddNormalIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndex));
    c2.def("AddParamIndex", &IPolyfaceConstruction::AddParamIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddParamIndex));
    c2.def("AddColorIndex", &IPolyfaceConstruction::AddColorIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddColorIndex));

    c2.def("AddSignedOneBasedPointIndex", &IPolyfaceConstruction::AddSignedOneBasedPointIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSignedOneBasedPointIndex));
    c2.def("AddSignedOneBasedNormalIndex", &IPolyfaceConstruction::AddSignedOneBasedNormalIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSignedOneBasedNormalIndex));
    c2.def("AddSignedOneBasedParamIndex", &IPolyfaceConstruction::AddSignedOneBasedParamIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSignedOneBasedParamIndex));
    c2.def("AddSignedOneBasedColorIndex", &IPolyfaceConstruction::AddSignedOneBasedColorIndex, "zeroBasedIndex"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSignedOneBasedColorIndex));    

    c2.def("AddPointIndexTerminator", &IPolyfaceConstruction::AddPointIndexTerminator, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndexTerminator));
    c2.def("AddNormalIndexTerminator", &IPolyfaceConstruction::AddNormalIndexTerminator, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexTerminator));
    c2.def("AddParamIndexTerminator", &IPolyfaceConstruction::AddParamIndexTerminator, DOC(Bentley, Geom, IPolyfaceConstruction, AddParamIndexTerminator));
    c2.def("AddColorIndexTerminator", &IPolyfaceConstruction::AddColorIndexTerminator, DOC(Bentley, Geom, IPolyfaceConstruction, AddColorIndexTerminator));            
    
    c2.def_property_readonly("ClientMesh", &IPolyfaceConstruction::GetClientMeshPtr);
    c2.def("GetClientMesh", &IPolyfaceConstruction::GetClientMeshPtr, py::return_value_policy::reference_internal);

    c2.def_property_readonly("FacetOptions", &IPolyfaceConstruction::GetFacetOptionsR);
    c2.def("GetFacetOptions", &IPolyfaceConstruction::GetFacetOptionsR, py::return_value_policy::reference_internal);

    c2.def("AddPointIndexTriangle", &IPolyfaceConstruction::AddPointIndexTriangle, "index0"_a, "visible0"_a, "index1"_a, "visible1"_a, "index2"_a, "visible2"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndexTriangle));
    c2.def("AddNormalIndexTriangle", &IPolyfaceConstruction::AddNormalIndexTriangle, "index0"_a, "index1"_a, "index2"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexTriangle));
    c2.def("AddParamIndexTriangle", &IPolyfaceConstruction::AddParamIndexTriangle, "index0"_a, "index1"_a, "index2"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddParamIndexTriangle));
    c2.def("AddColorIndexTriangle", &IPolyfaceConstruction::AddColorIndexTriangle, "index0"_a, "index1"_a, "index2"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddColorIndexTriangle));

    c2.def("AddPointIndexQuad", &IPolyfaceConstruction::AddPointIndexQuad, "index0"_a, "visible0"_a, "index1"_a, "visible1"_a, "index2"_a, "visible2"_a, "index3"_a, "visible3"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndexQuad));
    c2.def("AddNormalIndexQuad", &IPolyfaceConstruction::AddNormalIndexQuad, "index0"_a, "index1"_a, "index2"_a, "index3"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexQuad));
    c2.def("AddParamIndexQuad", &IPolyfaceConstruction::AddParamIndexQuad, "index0"_a, "index1"_a, "index2"_a, "index3"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddParamIndexQuad));
    c2.def("AddColorIndexQuad", &IPolyfaceConstruction::AddColorIndexQuad, "index0"_a, "index1"_a, "index2"_a, "index3"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddColorIndexQuad));

    c2.def("AddPolyface", &IPolyfaceConstruction::AddPolyface, "polyface"_a, "drawMethodIndex"_a = 0, DOC(Bentley, Geom, IPolyfaceConstruction, AddPolyface));
    c2.def("NeedNormals", &IPolyfaceConstruction::NeedNormals, DOC(Bentley, Geom, IPolyfaceConstruction, NeedNormals));
    c2.def("NeedParams", &IPolyfaceConstruction::NeedParams, DOC(Bentley, Geom, IPolyfaceConstruction, NeedParams));

    c2.def("InitializeConstructionStateAndStack", &IPolyfaceConstruction::InitializeConstructionStateAndStack, DOC(Bentley, Geom, IPolyfaceConstruction, InitializeConstructionStateAndStack));
    c2.def("InitializeCurrentConstructionState", &IPolyfaceConstruction::InitializeCurrentConstructionState, DOC(Bentley, Geom, IPolyfaceConstruction, InitializeCurrentConstructionState));

    c2.def("GetReverseNewFacetIndexOrder", &IPolyfaceConstruction::GetReverseNewFacetIndexOrder, DOC(Bentley, Geom, IPolyfaceConstruction, GetReverseNewFacetIndexOrder));
    c2.def("GetReverseNewNormals", &IPolyfaceConstruction::GetReverseNewNormals, DOC(Bentley, Geom, IPolyfaceConstruction, GetReverseNewNormals));

    c2.def("GetWorldToLocal", &IPolyfaceConstruction::GetWorldToLocal, "transform"_a, DOC(Bentley, Geom, IPolyfaceConstruction, GetWorldToLocal));            
    c2.def("IsTransformed", &IPolyfaceConstruction::IsTransformed, DOC(Bentley, Geom, IPolyfaceConstruction, IsTransformed));

    c2.def("GetLocalToWorld", &IPolyfaceConstruction::GetLocalToWorld, "transform"_a, DOC(Bentley, Geom, IPolyfaceConstruction, GetLocalToWorld));
    c2.def("SetLocalToWorld", &IPolyfaceConstruction::SetLocalToWorld, "transform"_a, DOC(Bentley, Geom, IPolyfaceConstruction, SetLocalToWorld));

    c2.def("ApplyLocalToWorld", &IPolyfaceConstruction::ApplyLocalToWorld, "relativeTransform"_a, DOC(Bentley, Geom, IPolyfaceConstruction, ApplyLocalToWorld));
    c2.def("MultiplyByLocalToWorld", &IPolyfaceConstruction::MultiplyByLocalToWorld, "localPoint"_a, DOC(Bentley, Geom, IPolyfaceConstruction, MultiplyByLocalToWorld));
    c2.def("MultiplyNormalByLocalToWorld", &IPolyfaceConstruction::MultiplyNormalByLocalToWorld, "localNormal"_a, DOC(Bentley, Geom, IPolyfaceConstruction, MultiplyNormalByLocalToWorld));

    c2.def("PushState", &IPolyfaceConstruction::PushState, "initializeCurrentState"_a = false, DOC(Bentley, Geom, IPolyfaceConstruction, PushState));            
    c2.def("PopState", &IPolyfaceConstruction::PopState, DOC(Bentley, Geom, IPolyfaceConstruction, PopState));

    c2.def("SetReverseNewFacetIndexOrder", &IPolyfaceConstruction::SetReverseNewFacetIndexOrder, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, SetReverseNewFacetIndexOrder));            
    c2.def("SetReverseNewNormals", &IPolyfaceConstruction::SetReverseNewNormals, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, SetReverseNewNormals));

    c2.def("GetLocalToWorldNormals", &IPolyfaceConstruction::GetLocalToWorldNormals, "matrix"_a, DOC(Bentley, Geom, IPolyfaceConstruction, GetLocalToWorldNormals));

    c2.def("ToggleIndexOrderAndNormalReversal", &IPolyfaceConstruction::ToggleIndexOrderAndNormalReversal, DOC(Bentley, Geom, IPolyfaceConstruction, ToggleIndexOrderAndNormalReversal));

    c2.def_property_readonly("LocalToWorldScale", &IPolyfaceConstruction::GetLocalToWorldScale);
    c2.def("GetLocalToWorldScale", &IPolyfaceConstruction::GetLocalToWorldScale, DOC(Bentley, Geom, IPolyfaceConstruction, GetLocalToWorldScale));

    c2.def_property_readonly("WorldToLocalScale", &IPolyfaceConstruction::GetWorldToLocalScale);
    c2.def("GetWorldToLocalScale", &IPolyfaceConstruction::GetWorldToLocalScale, DOC(Bentley, Geom, IPolyfaceConstruction, GetWorldToLocalScale));
            
    c2.def("AddRuled", &IPolyfaceConstruction::AddRuled, "ellipse0"_a, "ellipse1"_a, "cap"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddRuled));            
    c2.def("Add", py::overload_cast<MSBsplineSurfaceCR>(&IPolyfaceConstruction::Add), "surface"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));            
    c2.def("AddSmoothed", &IPolyfaceConstruction::AddSmoothed, "surface"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSmoothed));
    
    c2.def("AddRowMajorQuadGrid", [] (IPolyfaceConstructionR self, std::vector<DPoint3d> const& points, std::vector<DVec3d> const& normals, std::vector<DPoint2d> const& params, size_t numPerRow, size_t numRow, bool forceTriangles)
           {
           DPoint3dCP _points = points.empty() ? nullptr : points.data();
           DVec3dCP _normals = normals.empty() ? nullptr : normals.data();
           DPoint2dCP _params = params.empty() ? nullptr : params.data();
           self.AddRowMajorQuadGrid(_points, _normals, _params, numPerRow, numRow, forceTriangles);
           }, "points"_a, "normals"_a, "params"_a, "numPerRow"_a, "numRow"_a, "forceTriangles"_a = false, DOC(Bentley, Geom, IPolyfaceConstruction, AddRowMajorQuadGrid));

    c2.def("AddTriStrip", [] (IPolyfaceConstructionR self, std::vector<DPoint3d> const& points, std::vector<DVec3d> const& normals, std::vector<DPoint2d> const& params, bool firstTriangle012)
           {
           DPoint3dCP _points = points.empty() ? nullptr : points.data();
           DVec3dCP _normals = normals.empty() ? nullptr : normals.data();
           DPoint2dCP _params = params.empty() ? nullptr : params.data();
           size_t numPoint = points.size();
           self.AddTriStrip(_points, _normals, _params, numPoint, firstTriangle012);
           }, "points"_a, "normals"_a, "params"_a, "firstTriangle012"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddTriStrip));

    c2.def("AddTubeMesh", &IPolyfaceConstruction::AddTubeMesh, "centerlineCurve"_a, "radius"_a, "numEdgePerSection"_a, "numSectionEdge"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddTubeMesh));
    c2.def("AddLinearSweep", py::overload_cast<DPoint3dArray&, DVec3dArray&, DVec3dCR>(&IPolyfaceConstruction::AddLinearSweep), "pointA"_a, "tangentA"_a, "step"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddLinearSweep));    

    c2.def("AddLinearSweep", [](IPolyfaceConstructionR self, py::list& pointA, DVec3dArray& tangentA, DVec3dCR step)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(pointA, cppPointA, DPoint3dArray, DPoint3d);
           self.AddLinearSweep(cppPointA, tangentA, step);
           CONVERT_CPPARRAY_TO_PYLIST(pointA, cppPointA, DPoint3dArray, DPoint3d);
           }, "pointA"_a, "tangentA"_a, "step"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddLinearSweep));

    c2.def("AddRotationalSweep", 
           py::overload_cast<CurveVectorPtr, DPoint3dCR, DVec3dCR, double, bool>(&IPolyfaceConstruction::AddRotationalSweep), 
           "curve"_a, "center"_a, "axis"_a, "totalSweep"_a, "capped"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddRotationalSweep));

    c2.def("AddRegion", &IPolyfaceConstruction::AddRegion, "region"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddRegion));
            
    c2.def("StrokeWithDoubledPointsAtCorners", [] (IPolyfaceConstructionR self, CurveVectorCR curves, DPoint3dArray& points, DVec3dArray& tangents)
           {
           size_t numLoop = 0;
           bool bOk = self.StrokeWithDoubledPointsAtCorners(curves, points, tangents, numLoop);
           return py::make_tuple(bOk, numLoop);
           }, "curves"_a, "points"_a, "tangents"_a, DOC(Bentley, Geom, IPolyfaceConstruction, StrokeWithDoubledPointsAtCorners));

    c2.def("StrokeWithDoubledPointsAtCorners", [] (IPolyfaceConstructionR self, CurveVectorCR curves, py::list& points, DVec3dArray& tangents)
           {
           size_t numLoop = 0;
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
           bool bOk = self.StrokeWithDoubledPointsAtCorners(curves, cppPoints, tangents, numLoop);
           CONVERT_CPPARRAY_TO_PYLIST(points, cppPoints, DPoint3dArray, DPoint3d);
           return py::make_tuple(bOk, numLoop);
           }, "curves"_a, "points"_a, "tangents"_a, DOC(Bentley, Geom, IPolyfaceConstruction, StrokeWithDoubledPointsAtCorners));

    c2.def("StrokeWithDoubledPointsAtCorners",
           py::overload_cast<CurveVectorCR, DPoint3dVecArray&, DVec3dVecArray&, DoubleArray&>(&IPolyfaceConstruction::StrokeWithDoubledPointsAtCorners),
           "curves"_a, "points"_a, "tangent"_a, "curveLengths"_a, DOC(Bentley, Geom, IPolyfaceConstruction, StrokeWithDoubledPointsAtCorners));

            
    c2.def("Stroke", [] (IPolyfaceConstructionR self, CurveVectorCR curves, bvector<DPoint3d>& points)
           {
           size_t numLoop = 0;
           bool bOk = self.Stroke(curves, points, numLoop);
           return py::make_tuple(bOk, numLoop);
           }, "curves"_a, "points"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Stroke));

    c2.def("AddTriangulation", &IPolyfaceConstruction::AddTriangulation, "points"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddTriangulation));
    c2.def("AddTriangles", &IPolyfaceConstruction::AddTriangles, "triangles"_a, "reverse"_a = false, "paramTriangles"_a = nullptr, DOC(Bentley, Geom, IPolyfaceConstruction, AddTriangles));
    c2.def("AddTriangulationPair", &IPolyfaceConstruction::AddTriangulationPair, "pointA"_a, "reverseA"_a, "pointB"_a, "reverseB"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddTriangulationPair));    

    c2.def("AddRotationalSweepLoop", &IPolyfaceConstruction::AddRotationalSweepLoop,
           "pointA"_a, 
           "tangentA"_a, 
           "center"_a,  
           "rotationAxis"_a, 
           "totalSweepRadians"_a, 
           "reverse"_a, 
           "nominalBaseCurveLength"_a, 
           "startCapPointAccumulator"_a, 
           "endCapPointAccumulator"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddRotationalSweepLoop));

    c2.def("AddFullDisk", &IPolyfaceConstruction::AddFullDisk, "ellipse"_a, "numPerQuadrant"_a = 0, DOC(Bentley, Geom, IPolyfaceConstruction, AddFullDisk));
    c2.def("AddFullDiskTriangles", &IPolyfaceConstruction::AddFullDiskTriangles, "ellipse"_a, "numPerQuadrant"_a = 0, DOC(Bentley, Geom, IPolyfaceConstruction, AddFullDiskTriangles));
    c2.def("AddFullSphere", &IPolyfaceConstruction::AddFullSphere, "center"_a, "radius"_a, "numPerQuadrantEW"_a = 0, "numPerQuadrantNS"_a = 0, DOC(Bentley, Geom, IPolyfaceConstruction, AddFullSphere));

    c2.def("AddEllipsoidPatch", &IPolyfaceConstruction::AddEllipsoidPatch,
           "center"_a,
           "radiusX"_a,
           "radiusY"_a,
           "radiusPole"_a,
           "numEastWestEdge"_a = 0,
           "numNorthSouthEdge"_a = 0,
           "longitudeStart"_a = 0.0,
           "longitudeSweep"_a = msGeomConst_2pi,
           "latitudeStart"_a = -msGeomConst_piOver2,
           "latitudeSweep"_a = msGeomConst_pi,
           "capped"_a = false,
           "orientationSelect"_a = 1);

    c2.def("AddSweptNGon", &IPolyfaceConstruction::AddSweptNGon, "n"_a, "rOuter"_a, "z0"_a, "z1"_a, "bottomCap"_a, "topCap"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSweptNGon));

    c2.def("FindOrAddPoints", 
           py::overload_cast<DPoint3dArray&, size_t, size_t, UInt64Array&>(&IPolyfaceConstruction::FindOrAddPoints), 
           "point"_a, "n"_a, "numWrap"_a, "index"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddPoints));

    c2.def("FindOrAddPoints", [](IPolyfaceConstructionR self, py::list &point, size_t n, size_t numWrap, UInt64Array& index)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(point, cpppoint, DPoint3dArray, DPoint3d);
           self.FindOrAddPoints(cpppoint, n, numWrap, index);
           CONVERT_CPPARRAY_TO_PYLIST(point, cpppoint, DPoint3dArray, DPoint3d); }, "point"_a, "n"_a, "numWrap"_a, "index"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddPoints));

    c2.def("FindOrAddNormals",
           py::overload_cast<DVec3dArray&, size_t, size_t, UInt64Array&>(&IPolyfaceConstruction::FindOrAddNormals),
           "point"_a, "n"_a, "numWrap"_a, "index"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddNormals));

    c2.def("FindOrAddParams", [] (IPolyfaceConstructionR self, DPoint2dArray const& params, UInt64Array& index)
           {
           self.FindOrAddParams(&params[0], params.size(), index);
           }, "params"_a, "index"_a, DOC(Bentley, Geom, IPolyfaceConstruction, FindOrAddParams));

    c2.def("AddPointIndexFan",
           py::overload_cast<size_t, UInt64Array&, size_t, bool>(&IPolyfaceConstruction::AddPointIndexFan),
           "centerIndex"_a, "index"_a, "numChord"_a, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndexFan));

    c2.def("AddPointIndexFan",
           py::overload_cast<size_t, UInt64Array&, size_t, bool, bool, bool>(&IPolyfaceConstruction::AddPointIndexFan),
           "centerIndex"_a, "index"_a, "numChord"_a, "reverse"_a, "spokesVisible"_a, "visibleBoundary"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndexFan));

    c2.def("AddPointIndexStrip", &IPolyfaceConstruction::AddPointIndexStrip, 
           "visibleLeft"_a, "indexA"_a, "visibleA"_a, "indexB"_a, "visibleB"_a, "visibleRight"_a, "numQuad"_a, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddPointIndexStrip));

    c2.def("AddNormalIndexFan", &IPolyfaceConstruction::AddNormalIndexFan, "centerIndex"_a, "index"_a, "numChord"_a, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexFan));

    c2.def("AddNormalIndexPlanarFan",
           py::overload_cast<DVec3dCR, DVec3dCR, bool, size_t>(&IPolyfaceConstruction::AddNormalIndexPlanarFan),
           "vectorA"_a, "vectorB"_a, "reverse"_a, "numChord"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexPlanarFan));

    c2.def("AddNormalIndexPlanarFan",
           py::overload_cast<size_t, size_t>(&IPolyfaceConstruction::AddNormalIndexPlanarFan),
           "normalIndex"_a, "numChord"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexPlanarFan));

    c2.def("AddNormalIndexPlanarStrip", &IPolyfaceConstruction::AddNormalIndexPlanarStrip, "index"_a, "numQuad"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddNormalIndexPlanarStrip));
    c2.def("AddParamIndexFan", &IPolyfaceConstruction::AddParamIndexFan, "centerIndex"_a, "index"_a, "numChord"_a, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddParamIndexFan));
    c2.def("AddParamIndexStrip", &IPolyfaceConstruction::AddParamIndexStrip, "indexA"_a, "indexB"_a, "numQuad"_a, "reverse"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddParamIndexStrip));
    c2.def("AddSolidPrimitive", &IPolyfaceConstruction::AddSolidPrimitive, "primitive"_a, DOC(Bentley, Geom, IPolyfaceConstruction, AddSolidPrimitive));

    c2.def("Add", py::overload_cast<DgnConeDetailCR>(&IPolyfaceConstruction::Add), "cone"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<DgnSphereDetailCR>(&IPolyfaceConstruction::Add), "sphere"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<DgnBoxDetailCR>(&IPolyfaceConstruction::Add), "box"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<DgnTorusPipeDetailCR>(&IPolyfaceConstruction::Add), "torus"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<DgnExtrusionDetailCR>(&IPolyfaceConstruction::Add), "extrusion"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<DgnRotationalSweepDetailCR>(&IPolyfaceConstruction::Add), "sweep"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<DgnRuledSweepDetailCR>(&IPolyfaceConstruction::Add), "sweep"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));
    c2.def("Add", py::overload_cast<PolyfaceHeaderR>(&IPolyfaceConstruction::Add), "sweep"_a, DOC(Bentley, Geom, IPolyfaceConstruction, Add));

    c2.def("RemapPseudoDistanceParams",
           py::overload_cast<DPoint2dArray&, DRange2dR, DRange2dR, double, double, Transform*>(&IPolyfaceConstruction::RemapPseudoDistanceParams),
           "params"_a, "distanceRange"_a, "paramRange"_a, "xDistanceFactor"_a, "yDistanceFactor"_a, "transform"_a, DOC(Bentley, Geom, IPolyfaceConstruction, RemapPseudoDistanceParams));

    c2.def("RemapPseudoDistanceParams",
           py::overload_cast<DPoint2dArray&, DRange2dR, DRange2dR, double, double>(&IPolyfaceConstruction::RemapPseudoDistanceParams),
           "params"_a, "distanceRange"_a, "paramRange"_a, "xDistanceFactor"_a, "yDistanceFactor"_a, DOC(Bentley, Geom, IPolyfaceConstruction, RemapPseudoDistanceParams));    
    }