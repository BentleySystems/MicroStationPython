/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\PSolid\psolidcoreapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <PSolid/PSolidCoreAPI.h>

static const char * __doc_Bentley_DgnPlatform_TopologyID_IdFromVertex =R"doc(Get the VertexId currently assigned to a given vertex sub-entity.

:param vertexId:
    The requested nodeId-entityId triple.

:param subEntity:
    The vertex sub-entity to query.

:param useHighestId:
    true to return the highest nodeId-entityId triple for this face,
    false to return the lowest. Typically true.

:returns:
    SUCCESS if a VertexId was assigned.)doc";

static const char * __doc_Bentley_DgnPlatform_TopologyID_IdFromEdge =R"doc(Get the EdgeId currently assigned to a given edge sub-entity.

:param edgeId:
    The requested nodeId-entityId pairs.

:param subEntity:
    The edge sub-entity to query.

:param useHighestId:
    true to return the highest nodeId-entityId pairs for this face,
    false to return the lowest. Typically true.

:returns:
    SUCCESS if an EdgeId was assigned.)doc";

static const char * __doc_Bentley_DgnPlatform_TopologyID_IdFromFace =R"doc(Get the FaceId currently assigned to a given face sub-entity.

:param faceId:
    The requested nodeId-entityId pair.

:param subEntity:
    The face sub-entity to query.

:param useHighestId:
    true to return the highest nodeId-entityId pair for this face,
    false to return the lowest. Typically true.

:returns:
    SUCCESS if a FaceId was assigned.)doc";

static const char * __doc_Bentley_DgnPlatform_TopologyID_FindNodeIdRange =R"doc(Find the highest and lowest nodeId values from the topology ids
currently assigned to the faces of the given body. Used to avoid
nodeId conflicts between target and tool bodies.

:param entity:
    The solid or sheet body to inspect.

:param highestNodeId:
    The highest nodeId currently assigned.

:param lowestNodeId:
    The lowest nodeId currently assigned.

:returns:
    SUCCESS if face ids are assigned to the body.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_ClashDetectionBetweenTargetAndTool =R"doc(Get clash result between target and tool from the list of targets

:param clashTool:
    List of target tool causing clashes with the target

:param target:
    The target body

:param planarTool:
    The planar sheet body for the cut profile.

:param directionMode:
    The sweep direction relative to the sheet body normal of the cut
    profile.

:param depthMode:
    To specify if the cut should extended through the entire body or
    only create a pocket of fixed depth.

:param distance:
    To specify the cut depth for CutDepthMode::Blind.

:param invert:
    Set true to reverse the sense of the tool (outside rather than
    inside if closed).

:param defaultNormal:
    If not NULL, uused to to determine the cut direction only if the
    tool is a line segment.

:param cutDirection:
    Cut direction

:returns:
    SUCCESS if there occur clash between given vector and target)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_OffsetThroughHole =R"doc(Modify the target solid by offsetting face through body. It will punch
hole .

:param target:
    The target body to modify.

:param faces:
    The array of faces to be offset.

:param distances:
    The array of offsets for each face.

:param nFaces:
    Count of face sub-entities.

:returns:
    SUCCESS if hole cutting is successfull.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_DeleteRedundantTopology =R"doc(Modify the target body by removing redundant topology. An example of
redundant topololgy would be an edge where the faces on either side
have identical surface geometry.

:param target:
    The target body to modify.

:returns:
    SUCCESS if operation was completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_ImprintWiresOnFace =R"doc(Modify a face of a body by imprinting the specified wire bodies.

:param face:
    The target face sub-entity to imprint.

:param wires:
    The vector of wire bodies to imprint the curves of onto the face.

:param extendToEdge:
    The option to extend an open wire body to ensure that it splits
    the face.

:returns:
    SUCCESS if face imprint created.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_ImprintCurveVectorOnBody =R"doc(Modify the target body by imprinting new edges from the specified
curve vector.

:param target:
    The target body to imprint.

:param curveVector:
    The curve geometry to imprint.

:param direction:
    The project direction for imprinting the curve.

:param extendOpenCurvesToEdge:
    The option to extend an open curve to ensure that it splits the
    face.

:returns:
    SUCCESS if imprint created.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_DeleteFaces =R"doc(Modify the target solid or sheet body by removing selected faces and
healing.

:param target:
    The target body to modify.

:param faces:
    The array of faces to be delted.

:param nFaces:
    Count of face sub-entities.

:returns:
    SUCCESS if faces could be deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_SpinFaces =R"doc(Modify the target solid or sheet body by spinning selected faces along
an arc specified by a revolve axis and sweep angle.

:param target:
    The target body to modify.

:param faces:
    The array of faces to be spun.

:param nFaces:
    Count of face sub-entities.

:param axis:
    The revolve axis.

:param angle:
    The sweep angle. (value in range of -2pi to 2pi)

:returns:
    SUCCESS if faces could be spun.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_SweepFaces =R"doc(Modify the target solid or sheet body by sweeping selected faces along
a path vector.

:param target:
    The target body to modify.

:param faces:
    The array of faces to be swept.

:param nFaces:
    Count of face sub-entities.

:param path:
    A scaled vector to define the sweep direction and distance.

:returns:
    SUCCESS if faces could be swept.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_TransformFaces =R"doc(Modify the target solid or sheet body by transforming selected faces.

:param target:
    The target body to modify.

:param faces:
    The array of faces to be transformed.

:param translations:
    The array of transforms for each face.

:param nFaces:
    Count of face sub-entities.

:param addStep:
    The option for how to handle the creation of step faces.

:returns:
    SUCCESS if faces could be transformed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_OffsetFaces =R"doc(Modify the target solid or sheet body by offsetting selected faces.

:param target:
    The target body to modify.

:param faces:
    The array of faces to be offset.

:param distances:
    The array of offsets for each face.

:param nFaces:
    Count of face sub-entities.

:param addStep:
    The option for how to handle the creation of step faces.

:returns:
    SUCCESS if faces could be offset.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_HollowFaces =R"doc(Modify the target solid body by hollowing using specified face
offsets.

:param target:
    The target body to hollow.

:param defaultDistance:
    The offset distance to apply to any face not specifically included
    in the faces array.

:param faces:
    The array of faces to be offset by other than the default offset
    distance.

:param distances:
    The array of offsets for each face.

:param nFaces:
    Count of face sub-entities.

:param addStep:
    The option for how to handle the creation of step faces. @note A
    positive offset goes outwards (in the direction of the surface
    normal), a negative offset is inwards, and a face with zero offset
    will be pierced/removed.

:returns:
    SUCCESS if hollow could be created.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_ChamferEdges =R"doc(Modify the specified edges of the given body by changing them into
faces having the requested chamfer surface geometry.

:param target:
    The target body to chamfer.

:param edges:
    The array of edge sub-entities to attach chamfers to.

:param values1:
    The array of chamfer values for each edge, value meaning varies by
    ChamferMode.

:param values2:
    The array of chamfer values for each edge, value meaning varies by
    ChamferMode. (Unused for ChamferMode::Length)

:param nEdges:
    Count of edge sub-entities.

:param mode:
    Specifies chamfer type and determines how values1 and values2 are
    interpreted and used.

:param propagateSmooth:
    Whether to automatically continue chamfer along connected and
    tangent edges that aren't explicitly specified in edges array.

:returns:
    SUCCESS if chamfers could be created.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_BlendEdges =R"doc(Modify the specified edges of the given body by changing them into
faces having the requested blending surface geometry.

:param target:
    The target body to blend.

:param edges:
    The array of edge sub-entities to attach blends to.

:param radii:
    The array of blend radius values for each edge.

:param nEdges:
    Count of edge sub-entities.

:param propagateSmooth:
    Whether to automatically continue blend along connected and
    tangent edges that aren't explicitly specified in edges array.

:returns:
    SUCCESS if blends could be created.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_TransformBody =R"doc(Modify the entity transform for the given body by pre-multiplying the
current entity transform with the input transform.

:param entity:
    The body whose body to uor transform is to be updated.

:param transform:
    The transform to apply to the body. @note This method does not
    change the BRep data in any way, it only changes it's body to uor
    transform. This is a helper method added for discoverabiliy that
    is the same as calling
    ISolidKernelEntity::PreMultiplyEntityTransformInPlace.

:returns:
    SUCCESS if transform was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_SewBodies =R"doc(Sew the given set of sheet bodies together by joining those that share
edges in common.

:param sewn:
    The new bodies produced by sewing.

:param unsewn:
    The bodies that were not able to be sewn.

:param tools:
    The array of sheet bodies. (invalidated after sew).

:param nTools:
    Count of tool bodies.

:param gapWidthBound:
    Defines a limit on the width of the gap between sheet body edges
    that will be allowed to remain.

:param nIterations:
    To request repeated sew attempts that automatically increase gap
    up to limit set by gapWidthBound.

:returns:
    SUCCESS if some bodies were able to be sewn together.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_ThickenSheet =R"doc(Modify the target sheet body by thickening to create a solid body.

:param target:
    The target sheet body to thicken.

:param frontDistance:
    The offset distance in the direction of the sheet body face
    normal.

:param backDistance:
    The offset distance in the opposite direction of the sheet body
    face normal.

:returns:
    SUCCESS if thicken could be completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_SpinBody =R"doc(Modify the target body by spinning along an arc specified by a revolve
axis and sweep angle.

:param target:
    The target body to spin. A wire body becomes a sheet, and a sheet
    body becomes a solid.

:param axis:
    The revolve axis.

:param angle:
    The sweep angle. (value in range of -2pi to 2pi)

:returns:
    SUCCESS if spin could be completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_SweepBody =R"doc(Modify the target body by sweeping along a path vector.

:param target:
    The target body to sweep. A wire body becomes a sheet, and a sheet
    body becomes a solid.

:param path:
    A scaled vector to define the sweep direction and distance.

:returns:
    SUCCESS if sweep could be completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_Emboss =R"doc(Modify the target body by adding a protrusion constructed from the
sheet tool body and its imprint on the target body.

:param target:
    The target body to modify, can be a sheet or solid.

:param tool:
    The planar sheet body for the emboss profile.

:param reverseDirection:
    To specify if material is to be added in the same direction or
    opposite direction to the surface normal of the tool sheet body.

:returns:
    SUCCESS if emboss operation was completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_BooleanCut =R"doc(Modify the target body by subtracting a cut body produced from
sweeping the sheet tool body according to the specified cut direction
and depth.

:param target:
    The target body to modify.

:param planarTool:
    The planar sheet body for the cut profile.

:param directionMode:
    The sweep direction relative to the sheet body normal of the cut
    profile.

:param depthMode:
    To specify if the cut should extended through the entire body or
    only create a pocket of fixed depth.

:param distance:
    To specify the cut depth for CutDepthMode::Blind.

:param invert:
    Set true to reverse the sense of the tool (outside rather than
    inside if closed).

:param defaultNormal:
    If not NULL, uused to to determine the cut direction only if the
    tool is a line segment.

:param nodeId:
    The node id of the entity.

:returns:
    SUCCESS if cut operation was completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_BooleanUnion =R"doc(Modify the target body by uniting with one or more tool bodies.

:param target:
    The target body to modify.

:param tools:
    Array of one or more tool bodies (consumed in boolean).

:param nTools:
    Count of tool bodies.

:returns:
    SUCCESS if boolean operation was completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_BooleanSubtract =R"doc(Modify the target body by subtracting one or more tool bodies.

:param target:
    The target body to modify.

:param tools:
    Array of one or more tool bodies (consumed in boolean).

:param nTools:
    Count of tool bodies.

:returns:
    SUCCESS if boolean operation was completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Modify_BooleanIntersect =R"doc(Modify the target body by intersecting with one or more tool bodies.

:param target:
    The target body to modify.

:param tools:
    A list of one or more tool bodies (consumed in boolean).

:param nTools:
    Count of tool bodies.

:returns:
    SUCCESS if boolean operation was completed.)doc";

static const char * __doc_Bentley_DgnPlatform_Convert_SubEntityToCurveVector =R"doc(Create a simplified CurveVector representation of the given sub-
entity.

:param curves:
    A CurveVector representing the sub-entity.

:param subEntity:
    The planar face, edge, or vertex to convert. @note A planar face,
    edge, or vertex can be represented by a CurveVector. Non-planar
    faces will return ERROR.

:returns:
    SUCCESS if a CurveVector could be created to represent the sub-
    entity.)doc";

static const char * __doc_Bentley_DgnPlatform_Convert_SubEntityToGeometry =R"doc(Create a simplified IGeometryPtr representation of the given sub-
entity (non-BRep geometry).

:param geom:
    A reference counted pointer to the new geometry type.

:param subEntity:
    The face, edge, or vertex to convert.

:param modelRef:
    The destination modelRef. @note A planar face, edge, or vertex can
    be represented by a CurveVector. Non-planar faces can be
    represented by a MSBsplineSurface or ISolidPrimitive.

:returns:
    SUCCESS if a IGeometryPtr could be created to represent the sub-
    entity.)doc";

static const char * __doc_Bentley_DgnPlatform_Convert_ElementToBodies =R"doc(Create bodies from an element that represents one or more wire, sheet,
or solid bodies.

:param out:
    The collection of new bodies.

:param hasMissingGeom:
    Will be set to true if not all geometry for the element is
    included in the output body collection.

:param eh:
    The element to convert.

:param getSolids:
    Collect solid bodies.

:param getSheets:
    Collect sheet bodies.

:param getWires:
    Collect wire bodies.

:returns:
    SUCCESS if at least one body of the requested type was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Convert_ElementToBody =R"doc(Create a body from an element that can represent a single wire, sheet,
or solid body.

:param out:
    The new body.

:param eh:
    The element to convert.

:param getSolid:
    Accept element that can be converted to a single solid body.

:param getSheet:
    Accept element that can be converted to a single sheet body.

:param getWire:
    Accept element that can be converted to a single wire body.

:returns:
    SUCCESS if a body of the requested type was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromExtrusionToBody =R"doc(Create a new body by extruding a planar sheet body up to another body.

:param out:
    The new body.

:param extrudeTo:
    The body to trim the extruded body to.

:param profile:
    The planar sheet body to extrude.

:param reverseDirection:
    To specify if extrusion is in the same direction or opposite
    direction to the surface normal of the profile sheet body.

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromSweep =R"doc(Create a new sheet or solid body by sweeping a cross section profile
along a path.

:param out:
    The new body.

:param profile:
    The cross section profile. (open, closed, or region with holes)

:param path:
    The path to sweep along.

:param model:
    Used to get the solid to uor scale. (ModelInfo::GetSolidExtent)

:param alignParallel:
    true to keep profile at a fixed angle to global axis instead of
    path tangent (and lock direction).

:param selfRepair:
    true to attempt repair of self-intersections.

:param createSheet:
    true to force a sheet body to be created from a closed profile
    which would normally produce a solid body. (Similiar behavior to
    ISolidPrimitive::GetCapped)

:param lockDirection:
    Optionally keep profile at a fixed angle relative to the path
    tangent projected into a plane perpendicular to the lock
    direction. Only valid when alignParallel is false.

:param twistAngle:
    Optionally spin profile as it moves along the path.

:param scale:
    Optionally scale profile as it moves along the path.

:param scalePoint:
    The profile point to scale about, required when applying scale.

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromLoft =R"doc(Create a new sheet or solid body from surfaces created by lofting
through a set of cross section profiles.

:param out:
    The new body.

:param profiles:
    The cross sections profiles.

:param nProfiles:
    The profile count.

:param guides:
    An optional set of guide curves for constrolling the loft.

:param nGuides:
    The guide curve count.

:param model:
    Used to get the solid to uor scale. (ModelInfo::GetSolidExtent)

:param periodic:
    If true, a closed surface is constructed in which the first
    section curve is used as the last section curve.

:param segment:
    If true, surfaces are created linearly between each section curve,
    with no smoothing.

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromPolyface =R"doc(Create a new sheet or solid body from a Polyface.

:param out:
    The new body.

:param meshData:
    The surface or solid to create a body from.

:param model:
    Used to get the solid to uor scale. (ModelInfo::GetSolidExtent)

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromBSurface =R"doc(Create a new sheet body from a MSBsplineSurface.

:param out:
    The new body.

:param surface:
    The surface to create a body from.

:param model:
    Used to get the solid to uor scale. (ModelInfo::GetSolidExtent)

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromSolidPrimitive =R"doc(Create a new sheet or solid body from an ISolidPrimitive.

:param out:
    The new body.

:param primitive:
    The surface or solid to create a body from.

:param model:
    Used to get the solid to uor scale. (ModelInfo::GetSolidExtent)

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_Create_BodyFromCurveVector =R"doc(Create a new wire or planar sheet body from a CurveVector that
represents an open path, closed path, region with holes, or union
region.

:param out:
    The new body.

:param curve:
    The curve vector to create a body from.

:param model:
    Used to get the solid to uor scale. (ModelInfo::GetSolidExtent)
    @note The CurvePrimitives that define an open path or closed loop
    are expected to be connected head-to-tail and may not intersect
    except at a vertex. A vertex can be shared by at most 2 edges.

:returns:
    SUCCESS if body was created.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_IsPointInsideBody =R"doc(Test if a point is inside or on the boundary of the given body.

:param entity:
    The entity to test.

:param testPt:
    The space point.

:returns:
    true if point is not outside the body.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_ClosestPointToEdge =R"doc(Get the closest point on an edge to a given point.

:param subEntity:
    The edge to test.

:param testPt:
    The space point.

:param point:
    The closest point on the edge.

:param param:
    The u parameter at the closest point.

:returns:
    true if closest point was found.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_ClosestPointToFace =R"doc(Get the closest point on a face to a given point.

:param subEntity:
    The face to test.

:param testPt:
    The space point.

:param point:
    The closest point on the face.

:param normal:
    The surface normal at the closest point.

:param param:
    The uv parameter at the closest point.

:returns:
    true if closest point was found.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_ClosestPoint =R"doc(Get the closest point on body to a given point.

:param entity:
    The entity to pick sub-entities for.

:param testPt:
    The space point.

:param subEntity:
    The face, edge, or vertext sub-entity that contains the closest
    point.

:param point:
    The closest point on the body.

:returns:
    true if closest point was found.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_RayTestFace =R"doc(Get the ray intersection with a face.

:param subEntity:
    The face to intersect.

:param boresite:
    The ray origin and direction.

:param intersectPts:
    The hit points on the face.

:param intersectParams:
    The uv parameters on the face.

:returns:
    true if ray intersects face.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_Locate =R"doc(Pick face, edge, and vertex sub-entities of a body by their proximity
to a ray.

:param entity:
    The entity to pick sub-entities for.

:param boresite:
    The ray origin and direction.

:param intersectEntities:
    The selected sub-entities.

:param intersectPts:
    The hit points on the selected sub-entities.

:param intersectParams:
    The parameters on the selected sub-entities. For edge hits x is
    the u parameter (y always 0). Not meaningful for vertex hits
    (always 0,0).

:param maxFace:
    The maximum number of face hits to return. Pass 0 to not pick
    faces.

:param maxEdge:
    The maximum number of edge hits to return. Pass 0 to not pick
    edges.

:param maxVertex:
    The maximum number of vertex hits to return. Pass 0 to not pick
    vertices.

:param maxDistance:
    An edge or vertex will be picked if it is within this distance
    from the ray. Not used for face picking. @note The returned
    entities are ordered by increasing distance from ray origin to hit
    point on entity.

:returns:
    true if ray intersected a requested entity type.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_Draw =R"doc(Draw geometry for the given face, edge, or vertex to the specified
ViewContext.

:param subEntity:
    The face, edge, or vertex sub-entity to display.

:param context:
    The ViewContext to output geometry to. @note Uses the current
    ElemMatSymb, caller is expected to setup symbology beforehand.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetSubEntityRange =R"doc(Get an axis aligned bounding box for the given face or edge.

:param range:
    The bounding box.

:param subEntity:
    The face or edge sub-entity to query.

:returns:
    SUCCESS if bounding box could be computed.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetEntityRange =R"doc(Get an axis aligned bounding box for the given body.

:param range:
    The bounding box.

:param entity:
    The entity to query.

:returns:
    SUCCESS if bounding box could be computed.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetEdgeParameterRange =R"doc(Get u edge parameter range for the given edge sub-entity.

:param subEntity:
    The edge sub-entity to query.

:param uRange:
    The u parameter range of the edge.

:returns:
    SUCCESS if edge parameter range was computed.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetFaceParameterRange =R"doc(Get uv face parameter range for the given face sub-entity.

:param subEntity:
    The face sub-entity to query.

:param uRange:
    The u parameter range of the face.

:param vRange:
    The v parameter range of the face.

:returns:
    SUCCESS if face parameter range was computedx.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetPlanarFaceData =R"doc(Evaluate point and normal at center of face parameter range for the
given face sub-entity.

:param point:
    The coordinates of the point on the surface at the center of the
    face parameter range. Can be NULL.

:param normal:
    The normalized surface normal at the center of the face parameter
    range. Can be NULL.

:param subEntity:
    The face sub-entity to query.

:returns:
    SUCCESS if face is planar. The point and normal are still returned
    when non-planar if the face sub-entity is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_EvaluateVertex =R"doc(Evaluate point of the given vertex sub-entity.

:param subEntity:
    The vertex sub-entity to query.

:param point:
    The coordinates of the point at the given vertex.

:returns:
    SUCCESS if vertex point exists.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_EvaluateEdge =R"doc(Evaluate point and tangent at a u parameter on the curve of the given
edge sub-entity.

:param subEntity:
    The edge sub-entity to query.

:param point:
    The coordinates of the point on the curve at the u parameter.

:param uDir:
    The normalized curve tangent at the u parameter.

:param uParam:
    The u parameter to evaluate.

:returns:
    SUCCESS if the parameter could be evaluated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_EvaluateFace =R"doc(Evaluate point, normal, and derivatives at a uv parameter on the
surface of the given face sub-entity.

:param subEntity:
    The face sub-entity to query.

:param point:
    The coordinates of the point on the surface at the uv parameter.

:param normal:
    The normalized surface normal at the uv parameter.

:param uDir:
    The first derivative with respect to u at the uv parameter.

:param vDir:
    The first derivative with respect to v at the uv parameter.

:param uvParam:
    The uv parameter pair to evaluate.

:returns:
    SUCCESS if the parameter could be evaluated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetSmoothBlendEdges =R"doc(Query the set of edges that are connected and tangent to the given
edge sub-entity.

:param smoothEdges:
    A vector to hold the sub-entities of type SubEntityType_Edge.

:param edge:
    The edge sub-entity to query smoothly connected edges for.

:returns:
    SUCCESS if the output vector was populated. @note These are the
    edges that would be included by the propagateSmooth option of
    SolidUtil::Modify::BlendEdges and SolidUtil::Modify::ChamferEdges.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetLoopEdgesFromEdge =R"doc(Query the set of edges that comprise a single face loop containing the
given edge sub-entity.

:param loopEdges:
    A vector to hold the sub-entities of type SubEntityType_Edge.

:param edge:
    The edge sub-entity that is part of the loop.

:param face:
    The face sub-entity that has the loop as part of it's bounds.

:returns:
    SUCCESS if the output vector was populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetVertexEdges =R"doc(Query the set of edges for the input vertex sub-entity.

:param subEntities:
    A vector to hold the sub-entities of type SubEntityType_Edge.

:param subEntity:
    The vertex sub-entity to query.

:returns:
    SUCCESS if input entity was the correct type and output vector was
    populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetVertexFaces =R"doc(Query the set of faces for the input vertex sub-entity.

:param subEntities:
    A vector to hold the sub-entities of type SubEntityType_Face.

:param subEntity:
    The vertex sub-entity to query.

:returns:
    SUCCESS if input entity was the correct type and output vector was
    populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetEdgeVertices =R"doc(Query the set of vertices for the input edge sub-entity.

:param subEntities:
    A vector to hold the sub-entities of type SubEntityType_Vertex.

:param subEntity:
    The edge sub-entity to query.

:returns:
    SUCCESS if input entity was the correct type and output vector was
    populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetEdgeFaces =R"doc(Query the set of faces for the input edge sub-entity.

:param subEntities:
    A vector to hold the sub-entities of type SubEntityType_Face.

:param subEntity:
    The edge sub-entity to query.

:returns:
    SUCCESS if input entity was the correct type and output vector was
    populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetFaceVertices =R"doc(Query the set of vertices for the input face sub-entity.

:param subEntities:
    A vector to hold the sub-entities of type SubEntityType_Vertex.

:param subEntity:
    The face sub-entity to query.

:returns:
    SUCCESS if input entity was the correct type and output vector was
    populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetFaceEdges =R"doc(Query the set of edges for the input face sub-entity.

:param subEntities:
    A vector to hold the sub-entities of type SubEntityType_Edge.

:param subEntity:
    The face sub-entity to query.

:returns:
    SUCCESS if input entity was the correct type and output vector was
    populated.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetBodyVertices =R"doc(Query the set of vertices of the input body.

:param subEntities:
    An optional vector to hold the sub-entities of type
    SubEntityType_Vertex, pass NULL if just interested in count.

:param in:
    The entity to query.

:returns:
    A count of the number of vertices.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetBodyEdges =R"doc(Query the set of edges of the input body.

:param subEntities:
    An optional vector to hold the sub-entities of type
    SubEntityType_Edge, pass NULL if just interested in count.

:param in:
    The entity to query.

:returns:
    A count of the number of edges.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_GetBodyFaces =R"doc(Query the set of faces of the input body.

:param subEntities:
    An optional vector to hold the sub-entities of type
    SubEntityType_Face, pass NULL if just interested in count.

:param in:
    The entity to query.

:returns:
    A count of the number of faces.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_DisjoinBody =R"doc(Create separate bodies from a single multi-region body.

:param out:
    The collection of new bodies.

:param in:
    The body to separate.

:returns:
    SUCCESS if input body could be separated, ERROR if input body is
    already a single region.)doc";

static const char * __doc_Bentley_DgnPlatform_SolidUtil_CopyEntity =R"doc(Create a new ISolidKernelEntityPtr by copying the input body.

:param out:
    The new body.

:param in:
    The body to copy.

:returns:
    SUCCESS if copy is valid.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PSolidCoreAPI(py::module_& m)
    {
    //===================================================================================
    // struct SolidUtil
    py::class_< SolidUtil> c1(m, "SolidUtil");

    c1.def_static("CopyEntity", [] (ISolidKernelEntityCR in)
                  {
                  ISolidKernelEntityPtr out;
                  auto retVal = SolidUtil::CopyEntity(out, in);
                  return py::make_tuple(retVal, out);
                  }, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, CopyEntity));

    c1.def_static("DisjoinBody", &SolidUtil::DisjoinBody, "out"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, DisjoinBody));

    c1.def_static("GetBodyFaces", &SolidUtil::GetBodyFaces, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetBodyFaces));
    c1.def_static("GetBodyEdges", &SolidUtil::GetBodyEdges, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetBodyEdges));
    c1.def_static("GetBodyVertices", &SolidUtil::GetBodyVertices, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetBodyVertices));

    c1.def_static("GetFaceEdges", &SolidUtil::GetFaceEdges, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetFaceEdges));
    c1.def_static("GetFaceVertices", &SolidUtil::GetFaceVertices, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetFaceVertices));
    c1.def_static("GetEdgeFaces", &SolidUtil::GetEdgeFaces, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetEdgeFaces));
    c1.def_static("GetEdgeVertices", &SolidUtil::GetEdgeVertices, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetEdgeVertices));
    c1.def_static("GetVertexFaces", &SolidUtil::GetVertexFaces, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetVertexFaces));
    c1.def_static("GetVertexEdges", &SolidUtil::GetVertexEdges, "subEntities"_a, "in"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetVertexEdges));

    c1.def_static("GetLoopEdgesFromEdge", &SolidUtil::GetLoopEdgesFromEdge, "loopEdges"_a, "edge"_a, "face"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetLoopEdgesFromEdge));
    c1.def_static("GetSmoothBlendEdges", &SolidUtil::GetSmoothBlendEdges, "smoothEdges"_a, "edge"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetSmoothBlendEdges));

    c1.def_static("EvaluateFace", &SolidUtil::EvaluateFace, "subEntity"_a, "point"_a, "normal"_a, "uDir"_a, "vDir"_a, "uvParam"_a, DOC(Bentley, DgnPlatform, SolidUtil, EvaluateFace));
    c1.def_static("EvaluateEdge", &SolidUtil::EvaluateEdge, "subEntity"_a, "point"_a, "uDir"_a, "uParam"_a, DOC(Bentley, DgnPlatform, SolidUtil, EvaluateEdge));
    c1.def_static("EvaluateVertex", &SolidUtil::EvaluateVertex, "subEntity"_a, "point"_a, DOC(Bentley, DgnPlatform, SolidUtil, EvaluateVertex));
    
    c1.def_static("GetPlanarFaceData", &SolidUtil::GetPlanarFaceData, "point"_a, "normal"_a, "subEntity"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetPlanarFaceData));
    
    c1.def_static("GetFaceParameterRange", &SolidUtil::GetFaceParameterRange, "subEntities"_a, "uRange"_a, "vRange"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetFaceParameterRange));
    c1.def_static("GetEdgeParameterRange", &SolidUtil::GetEdgeParameterRange, "subEntities"_a, "uRange"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetEdgeParameterRange));
    c1.def_static("GetEntityRange", &SolidUtil::GetEntityRange, "range"_a, "entity"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetEntityRange));
    c1.def_static("GetSubEntityRange", &SolidUtil::GetSubEntityRange, "range"_a, "subEntity"_a, DOC(Bentley, DgnPlatform, SolidUtil, GetSubEntityRange));
    
    c1.def_static("Draw", &SolidUtil::Draw, "subEntity"_a, "context"_a, DOC(Bentley, DgnPlatform, SolidUtil, Draw));

    c1.def_static("Locate", 
                  &SolidUtil::Locate,
                  "entity"_a, "boresite"_a, "intersectEntities"_a, "intersectPts"_a, "intersectParams"_a, "maxFace"_a, "maxEdge"_a, "maxVertex"_a, "maxDistance"_a, DOC(Bentley, DgnPlatform, SolidUtil, Locate));

    c1.def_static("RayTestFace", &SolidUtil::RayTestFace, "subEntity"_a, "boresite"_a, "intersectPts"_a, "intersectParams"_a, DOC(Bentley, DgnPlatform, SolidUtil, RayTestFace));

    c1.def_static("ClosestPoint", [] (ISolidKernelEntityCR entity, DPoint3dCR testPt)
                  {
                  ISubEntityPtr subEntity;
                  DPoint3d point;
                  auto retVal = SolidUtil::ClosestPoint(entity, testPt, subEntity, point);
                  return py::make_tuple(retVal, subEntity, point);
                  }, "entity"_a, "testPt"_a, DOC(Bentley, DgnPlatform, SolidUtil, ClosestPoint));

    c1.def_static("ClosestPointToFace", &SolidUtil::ClosestPointToFace, "subEntity"_a, "testPt"_a, "point"_a, "normal"_a, "param"_a, DOC(Bentley, DgnPlatform, SolidUtil, ClosestPointToFace));
    
    c1.def_static("ClosestPointToEdge", [] (ISubEntityCR subEntity, DPoint3dCR testPt)
                  {
                  DPoint3d point;
                  double param = 0;
                  auto retVal = SolidUtil::ClosestPointToEdge(subEntity, testPt, point, param);
                  return py::make_tuple(retVal, point, param);
                  }, "subEntity"_a, "testPt"_a, DOC(Bentley, DgnPlatform, SolidUtil, ClosestPointToEdge));

    c1.def_static("IsPointInsideBody", &SolidUtil::IsPointInsideBody, "entity"_a, "testPt"_a, DOC(Bentley, DgnPlatform, SolidUtil, IsPointInsideBody));

    //===================================================================================
    // struct SolidUtil::Create
    py::class_< SolidUtil::Create> c1_1(c1, "Create");

    c1_1.def_static("BodyFromCurveVector", [] (CurveVectorCR curve, DgnModelRefR model)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromCurveVector(out, curve, model);
                    return py::make_tuple(retVal, out);
                    }, "curve"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, Create, BodyFromCurveVector));

    c1_1.def_static("BodyFromSolidPrimitive", [] (ISolidPrimitiveCR primitive, DgnModelRefR model)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromSolidPrimitive(out, primitive, model);
                    return py::make_tuple(retVal, out);
                    }, "primitive"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, Create, BodyFromSolidPrimitive));

    c1_1.def_static("BodyFromBSurface", [] (MSBsplineSurfaceCR surface, DgnModelRefR model)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromBSurface(out, surface, model);
                    return py::make_tuple(retVal, out);
                    }, "surface"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, Create, BodyFromBSurface));

    c1_1.def_static("BodyFromPolyface", [] (PolyfaceQueryCR meshData, DgnModelRefR model)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromPolyface(out, meshData, model);
                    return py::make_tuple(retVal, out);
                    }, "meshData"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, Create, BodyFromPolyface));

    c1_1.def_static("BodyFromLoft", [] (bvector<CurveVectorPtr>& profiles, bvector<CurveVectorPtr>& guides, DgnModelRefR model, bool periodic, bool segment)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromLoft(out, profiles.data(), profiles.size(), guides.data(), guides.size(), model, periodic, segment);
                    return py::make_tuple(retVal, out);
                    }, "profiles"_a, "guides"_a, "modelRef"_a, "periodic"_a = false, "segment"_a = false, DOC(Bentley, DgnPlatform, Create, BodyFromLoft));

    c1_1.def_static("BodyFromSweep", [] (CurveVectorCR profile, CurveVectorCR path, DgnModelRefR model, bool alignParallel, bool selfRepair, bool createSheet, 
                                         DVec3dCP lockDirection, boost::optional<double> twistAngle, boost::optional<double> scale, DPoint3dCP scalePoint)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromSweep(out, profile, path, model, alignParallel, selfRepair, createSheet, lockDirection, twistAngle.get_ptr(),
                                                                   scale.get_ptr(), scalePoint);
                    return py::make_tuple(retVal, out);
                    }, "profile"_a, "path"_a, "modelRef"_a, "alignParallel"_a, "selfRepair"_a, "createSheet"_a, "lockDirection"_a = nullptr, "twistAngle"_a = nullptr,
                    "scale"_a = nullptr, "scalePoint"_a = nullptr, DOC(Bentley, DgnPlatform, Create, BodyFromSweep));

    c1_1.def_static("BodyFromExtrusionToBody", [] (ISolidKernelEntityCR extrudeTo, ISolidKernelEntityCR profile, bool reverseDirection)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Create::BodyFromExtrusionToBody(out, extrudeTo, profile, reverseDirection);
                    return py::make_tuple(retVal, out);
                    }, "extrudeTo"_a, "profile"_a, "reverseDirection"_a, DOC(Bentley, DgnPlatform, Create, BodyFromExtrusionToBody));

    //===================================================================================
    // struct SolidUtil::Convert
    py::class_< SolidUtil::Convert> c1_2(c1, "Convert");

    c1_2.def_static("ElementToBody", [] (ElementHandleCR eh, bool getSolid, bool getSheet, bool getWire)
                    {
                    ISolidKernelEntityPtr out;
                    auto retVal = SolidUtil::Convert::ElementToBody(out, eh, getSolid, getSheet, getWire);
                    return py::make_tuple(retVal, out);
                    }, "eh"_a, "getSolid"_a = true, "getSheet"_a = true, "getWire"_a = true, DOC(Bentley, DgnPlatform, Convert, ElementToBody));

    c1_2.def_static("ElementToBodies", [] (bvector<ISolidKernelEntityPtr>& out, ElementHandleCR eh, bool getSolids = true, bool getSheets = true, bool getWires = true)
                    {
                    bool hasMissingGeom = false;
                    auto retVal = SolidUtil::Convert::ElementToBodies(out, &hasMissingGeom, eh, getSolids, getSheets, getWires);
                    return py::make_tuple(retVal, hasMissingGeom);
                    }, "out"_a, "eh"_a, "getSolids"_a = true, "getSheets"_a = true, "getWires"_a = true, DOC(Bentley, DgnPlatform, Convert, ElementToBodies));

    c1_2.def_static("BodyToElement", &SolidUtil::Convert::BodyToElement, "eeh"_a, "entity"_a, "templateEh"_a, "modelRef"_a);

    c1_2.def_static("SubEntityToGeometry", [] (ISubEntityCR subEntity, DgnModelRefR modelRef)
                    {
                    IGeometryPtr geom;
                    auto retVal = SolidUtil::Convert::SubEntityToGeometry(geom, subEntity, modelRef);
                    return py::make_tuple(retVal, geom);
                    }, "subEntity"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, Convert, SubEntityToGeometry));

    c1_2.def_static("SubEntityToCurveVector", [] (ISubEntityCR subEntity)
                    {
                    CurveVectorPtr curves;
                    auto retVal = SolidUtil::Convert::SubEntityToCurveVector(curves, subEntity);
                    return py::make_tuple(retVal, curves);
                    }, "subEntity"_a, DOC(Bentley, DgnPlatform, Convert, SubEntityToCurveVector));

    //===================================================================================
    // struct SolidUtil::Modify
    py::class_< SolidUtil::Modify> c1_3(c1, "Modify");

    if (true)
        {
        //===================================================================================
        // enum SolidUtil::Modify::StepFacesOption
        py::enum_< SolidUtil::Modify::StepFacesOption>(c1_3, "StepFacesOption", py::arithmetic())
            .value("eADD_STEP_No", SolidUtil::Modify::ADD_STEP_No)
            .value("eADD_STEP_Smooth", SolidUtil::Modify::ADD_STEP_Smooth)
            .value("eADD_STEP_NonCoincident", SolidUtil::Modify::ADD_STEP_NonCoincident)
            .value("eADD_STEP_All", SolidUtil::Modify::ADD_STEP_All)
            .export_values();

        //===================================================================================
        // enum class SolidUtil::Modify::CutDirectionMode
        py::enum_< SolidUtil::Modify::CutDirectionMode>(c1_3, "CutDirectionMode")
            .value("eForward", SolidUtil::Modify::CutDirectionMode::Forward)
            .value("eBackward", SolidUtil::Modify::CutDirectionMode::Backward)
            .value("eBoth", SolidUtil::Modify::CutDirectionMode::Both)
            .export_values();

        //===================================================================================
        // enum class SolidUtil::Modify::CutDepthMode
        py::enum_< SolidUtil::Modify::CutDepthMode>(c1_3, "CutDepthMode")
            .value("eAll", SolidUtil::Modify::CutDepthMode::All)
            .value("eBlind", SolidUtil::Modify::CutDepthMode::Blind)
            .export_values();

        //===================================================================================
        // enum class SolidUtil::Modify::ChamferMode
        py::enum_< SolidUtil::Modify::ChamferMode>(c1_3, "ChamferMode")
            .value("eRanges", SolidUtil::Modify::ChamferMode::Ranges)
            .value("eLength", SolidUtil::Modify::ChamferMode::Length)
            .value("eDistances", SolidUtil::Modify::ChamferMode::Distances)
            .value("eDistanceAngle", SolidUtil::Modify::ChamferMode::DistanceAngle)
            .value("eAngleDistance", SolidUtil::Modify::ChamferMode::AngleDistance)
            .export_values();
        }

    c1_3.def_static("BooleanIntersect", [] (ISolidKernelEntityPtr& target,bvector< ISolidKernelEntityPtr>& tools)
                    {
                    return SolidUtil::Modify::BooleanIntersect(target, tools.data(), tools.size());
                    }, "target"_a, "tools"_a, DOC(Bentley, DgnPlatform, Modify, BooleanIntersect));

    c1_3.def_static("BooleanSubtract", [] (ISolidKernelEntityPtr& target, bvector< ISolidKernelEntityPtr>& tools)
                    {
                    return SolidUtil::Modify::BooleanSubtract(target, tools.data(), tools.size());
                    }, "target"_a, "tools"_a, DOC(Bentley, DgnPlatform, Modify, BooleanSubtract));

    c1_3.def_static("BooleanUnion", [] (ISolidKernelEntityPtr& target, bvector< ISolidKernelEntityPtr>& tools)
                    {
                    return SolidUtil::Modify::BooleanUnion(target, tools.data(), tools.size());
                    }, "target"_a,"tools"_a, DOC(Bentley, DgnPlatform, Modify, BooleanUnion));

    c1_3.def_static("BooleanCut", [] (ISolidKernelEntityP target, CurveVectorCR planarTool, SolidUtil::Modify::CutDirectionMode directionMode, SolidUtil::Modify::CutDepthMode depthMode, double distance, bool invert, DVec3dCP defaultNormal, UInt32 nodeId)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::BooleanCut(target_, planarTool, directionMode, depthMode, distance, invert, defaultNormal, nodeId);                    
                    }, "target"_a, "planarTool"_a, "directionMode"_a, "depthMode"_a, "distance"_a, "invert"_a, "defaultNormal"_a, "nodeId"_a, DOC(Bentley, DgnPlatform, Modify, BooleanCut));

    c1_3.def_static("Emboss", [] (ISolidKernelEntityP target, ISolidKernelEntityCR tool, bool reverseDirection)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::Emboss(target_, tool, reverseDirection);
                    }, "target"_a, "tool"_a, "reverseDirection"_a, DOC(Bentley, DgnPlatform, Modify, Emboss));

    c1_3.def_static("SweepBody", [] (ISolidKernelEntityP target, DVec3dCR path)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::SweepBody(target_, path);
                    }, "target"_a, "path"_a, DOC(Bentley, DgnPlatform, Modify, SweepBody));

    c1_3.def_static("SpinBody", [] (ISolidKernelEntityP target, DRay3dCR axis, double angle)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::SpinBody(target_, axis, angle);
                    }, "target"_a, "axis"_a, "angle"_a, DOC(Bentley, DgnPlatform, Modify, SpinBody));

    c1_3.def_static("ThickenSheet", [] (ISolidKernelEntityP target, double frontDistance, double backDistance)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::ThickenSheet(target_, frontDistance, backDistance);
                    }, "target"_a, "frontDistance"_a, "backDistance"_a, DOC(Bentley, DgnPlatform, Modify, ThickenSheet));

    c1_3.def_static("SewBodies", [] (bvector<ISolidKernelEntityPtr>& sewn, bvector<ISolidKernelEntityPtr>& unsewn, bvector<ISolidKernelEntityPtr>& tools, double gapWidthBound, size_t nIterations = 1)
                    {
                    return SolidUtil::Modify::SewBodies(sewn, unsewn, tools.data(), tools.size(), gapWidthBound, nIterations);
                    }, "sewn"_a, "unsewn"_a, "tools"_a, "gapWidthBound"_a, "nIterations"_a = 1, DOC(Bentley, DgnPlatform, Modify, SewBodies));

    c1_3.def_static("TransformBody", [] (ISolidKernelEntityP entity, TransformCR transform)
                    {
                    ISolidKernelEntityPtr entity_(entity);
                    return SolidUtil::Modify::TransformBody(entity_, transform);
                    }, "entity"_a, "transform"_a, DOC(Bentley, DgnPlatform, Modify, TransformBody));

    c1_3.def_static("BlendEdges", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& edges, DoubleArray& radii, bool propagateSmooth = true)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::BlendEdges(target_, edges.data(), radii.data(), edges.size(), propagateSmooth);
                    }, "target"_a, "edges"_a, "radii"_a, "propagateSmooth"_a = true, DOC(Bentley, DgnPlatform, Modify, BlendEdges));

    c1_3.def_static("ChamferEdges", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& edges, DoubleArray& values1, DoubleArray &values2, SolidUtil::Modify::ChamferMode mode, bool propagateSmooth)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::ChamferEdges(target_, edges.data(), values1.data(), values2.data(), edges.size(), mode, propagateSmooth);
                    }, "target"_a, "edges"_a, "values1"_a, "values2"_a, "mode"_a, "propagateSmooth"_a = true, DOC(Bentley, DgnPlatform, Modify, ChamferEdges));

    c1_3.def_static("HollowFaces", [] (ISolidKernelEntityP target, double defaultDistance, bvector<ISubEntityPtr>& faces, DoubleArray& distances, SolidUtil::Modify::StepFacesOption addStep)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::HollowFaces(target_, defaultDistance, faces.data(), distances.data(), faces.size(), addStep);
                    }, "target"_a, "defaultDistance"_a, "faces"_a, "distances"_a, "addStep"_a = SolidUtil::Modify::StepFacesOption::ADD_STEP_NonCoincident, DOC(Bentley, DgnPlatform, Modify, HollowFaces));

    c1_3.def_static("OffsetFaces", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& faces, DoubleArray& distances, SolidUtil::Modify::StepFacesOption addStep)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::OffsetFaces(target_, faces.data(), distances.data(), faces.size(), addStep);
                    }, "target"_a, "faces"_a, "distances"_a, "addStep"_a = SolidUtil::Modify::StepFacesOption::ADD_STEP_NonCoincident, DOC(Bentley, DgnPlatform, Modify, OffsetFaces));

    c1_3.def_static("TransformFaces", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& faces, bvector<Transform>& translations, SolidUtil::Modify::StepFacesOption addStep)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::TransformFaces(target_, faces.data(), translations.data(), faces.size(), addStep);
                    }, "target"_a, "faces"_a, "translations"_a, "addStep"_a = SolidUtil::Modify::StepFacesOption::ADD_STEP_NonCoincident, DOC(Bentley, DgnPlatform, Modify, TransformFaces));

    c1_3.def_static("SweepFaces", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& faces, DVec3dCR path)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::SweepFaces(target_, faces.data(), faces.size(), path);
                    }, "target"_a, "faces"_a, "path"_a, DOC(Bentley, DgnPlatform, Modify, SweepFaces));

    c1_3.def_static("SpinFaces", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& faces, DRay3dCR axis, double angle)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::SpinFaces(target_, faces.data(), faces.size(), axis, angle);
                    }, "target"_a, "faces"_a, "axis"_a, "angle"_a, DOC(Bentley, DgnPlatform, Modify, SpinFaces));

    c1_3.def_static("DeleteFaces", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& faces)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::DeleteFaces(target_, faces.data(), faces.size());
                    }, "target"_a, "faces"_a, DOC(Bentley, DgnPlatform, Modify, DeleteFaces));

    c1_3.def_static("ImprintCurveVectorOnBody", [] (ISolidKernelEntityP target, CurveVectorCR curveVector, DVec3dCR direction, bool extendOpenCurvesToEdge = true)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::ImprintCurveVectorOnBody(target_, curveVector, direction, extendOpenCurvesToEdge);
                    }, "target"_a, "curveVector"_a, "direction"_a, "extendOpenCurvesToEdge"_a = true, DOC(Bentley, DgnPlatform, Modify, ImprintCurveVectorOnBody));

    c1_3.def_static("ImprintWiresOnFace", [] (ISubEntityP face, bvector<ISolidKernelEntityPtr>& wires, bool extendToEdge)
                    {
                    ISubEntityPtr face_(face);
                    return SolidUtil::Modify::ImprintWiresOnFace(face_, wires, extendToEdge);
                    }, "face"_a, "wires"_a, "extendToEdge"_a, DOC(Bentley, DgnPlatform, Modify, ImprintWiresOnFace));

    c1_3.def_static("DeleteRedundantTopology", [] (ISolidKernelEntityP target)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::DeleteRedundantTopology(target_);
                    }, "target"_a, DOC(Bentley, DgnPlatform, Modify, DeleteRedundantTopology));

    c1_3.def_static("OffsetThroughHole", [] (ISolidKernelEntityP target, bvector<ISubEntityPtr>& faces, DoubleArray& distances)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::OffsetThroughHole(target_, faces.data(), distances.data(), faces.size());
                    }, "target"_a, "faces"_a, "distances"_a, DOC(Bentley, DgnPlatform, Modify, OffsetThroughHole));

    c1_3.def_static("OffsetFacesWithStatus", [] (ISolidKernelEntityPtr& target, bvector<ISubEntityPtr>& faces, DoubleArray& distances, SolidUtil::Modify::StepFacesOption addStep,int& offsetStatus )
                    {
                    ISolidKernelEntityPtr target_(target);
                    auto retVal = SolidUtil::Modify::OffsetFaces(target_, offsetStatus, faces.data(), distances.data(), faces.size(), addStep);
                    return py::make_tuple(retVal, offsetStatus);
                    }, "target"_a, "faces"_a, "distances"_a, "addStep"_a,"offsetStatus"_a = SolidUtil::Modify::StepFacesOption::ADD_STEP_NonCoincident);

    c1_3.def_static("ThickenSheetWithStatus", [] (ISolidKernelEntityP target, double frontDistance, double backDistance, int& status )
                    {
                    ISolidKernelEntityPtr target_(target);
                    auto retVal = SolidUtil::Modify::ThickenSheet(status, target_, frontDistance, backDistance);
                    return py::make_tuple(retVal, status);
                    }, "target"_a, "frontDistance"_a, "backDistance"_a,"status"_a);

    c1_3.def_static("BooleanCut", [] (ISolidKernelEntityP target, CurveVectorCR planarTool, SolidUtil::Modify::CutDirectionMode directionMode, SolidUtil::Modify::CutDepthMode depthMode, double distance, bool invert, DVec3dCP defaultNormal, UInt32 nodeId, DVec3dCP cutDirection)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::BooleanCut(target_, planarTool, directionMode, depthMode, distance, invert, defaultNormal, nodeId, cutDirection);
                    }, "target"_a, "planarTool"_a, "directionMode"_a, "depthMode"_a, "distance"_a, "invert"_a, "defaultNormal"_a, "nodeId"_a, "cutDirection"_a, DOC(Bentley, DgnPlatform, Modify, BooleanCut));

    c1_3.def_static("ClashDetectionBetweenTargetAndTool", [] (ISolidKernelEntityP target, CurveVectorCR planarTool, SolidUtil::Modify::CutDirectionMode directionMode, SolidUtil::Modify::CutDepthMode depthMode, double distance, DVec3dCP defaultNormal, DVec3dCP cutDirection)
                    {
                    ISolidKernelEntityPtr target_(target);
                    return SolidUtil::Modify::ClashDetectionBetweenTargetAndTool(target_, planarTool, directionMode, depthMode, distance, defaultNormal, cutDirection);
                    }, "target"_a, "planarTool"_a, "directionMode"_a, "depthMode"_a, "distance"_a, "defaultNormal"_a, "cutDirection"_a, DOC(Bentley, DgnPlatform, Modify, ClashDetectionBetweenTargetAndTool));

    //===================================================================================
    // struct SolidUtil::TopologyID
    py::class_< SolidUtil::TopologyID> c1_4(c1, "TopologyID");

    c1_4.def_static("AddNodeIdAttributes", &SolidUtil::TopologyID::AddNodeIdAttributes, "entity"_a, "nodeId"_a, "overrideExisting"_a);
    c1_4.def_static("DeleteNodeIdAttributes", &SolidUtil::TopologyID::DeleteNodeIdAttributes, "entity"_a);
    c1_4.def_static("IncrementNodeIdAttributes", &SolidUtil::TopologyID::IncrementNodeIdAttributes, "entity"_a, "increment"_a);
    
    c1_4.def_static("FindNodeIdRange", [] (ISolidKernelEntityCR entity)
                    {
                    UInt32 highestNodeId = 0, lowestNodeId = 0;
                    auto retVal = SolidUtil::TopologyID::FindNodeIdRange(entity, highestNodeId, lowestNodeId);
                    return py::make_tuple(retVal, highestNodeId, lowestNodeId);
                    }, "entity"_a, DOC(Bentley, DgnPlatform, TopologyID, FindNodeIdRange));

    c1_4.def_static("IdFromFace", [] (ISubEntityCR subEntity, bool useHighestId)
                    {
                    FaceId faceId;
                    auto retVal = SolidUtil::TopologyID::IdFromFace(faceId, subEntity, useHighestId);
                    return py::make_tuple(retVal, faceId);
                    }, "subEntity"_a, "useHighestId"_a, DOC(Bentley, DgnPlatform, TopologyID, IdFromFace));

    c1_4.def_static("IdFromEdge", [] (ISubEntityCR subEntity, bool useHighestId)
                    {
                    EdgeId edgeId;
                    auto retVal = SolidUtil::TopologyID::IdFromEdge(edgeId, subEntity, useHighestId);
                    return py::make_tuple(retVal, edgeId);
                    }, "subEntity"_a, "useHighestId"_a, DOC(Bentley, DgnPlatform, TopologyID, IdFromEdge));

    c1_4.def_static("IdFromVertex", [] (ISubEntityCR subEntity, bool useHighestId)
                    {
                    VertexId vertexId;
                    auto retVal = SolidUtil::TopologyID::IdFromVertex(vertexId, subEntity, useHighestId);
                    return py::make_tuple(retVal, vertexId);
                    }, "subEntity"_a, "useHighestId"_a, DOC(Bentley, DgnPlatform, TopologyID, IdFromVertex));

    c1_4.def_static("FacesFromId", &SolidUtil::TopologyID::FacesFromId, "subEntities"_a, "faceId"_a, "entity"_a);
    c1_4.def_static("EdgesFromId", &SolidUtil::TopologyID::EdgesFromId, "subEntities"_a, "edgeId"_a, "entity"_a);
    c1_4.def_static("VerticesFromId", &SolidUtil::TopologyID::VerticesFromId, "subEntities"_a, "vertexId"_a, "entity"_a);

    //===================================================================================
    // struct SolidUtil::Debug
    py::class_< SolidUtil::Debug> c1_5(c1, "Debug");

    c1_5.def_static("DumpEntity", &SolidUtil::Debug::DumpEntity, "entity"_a, "label"_a);
    c1_5.def_static("DumpSubEntity", &SolidUtil::Debug::DumpSubEntity, "subEntity"_a, "label"_a);
    }