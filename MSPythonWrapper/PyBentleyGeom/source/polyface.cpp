/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\polyface.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryRecomputeNormals =R"doc(Recompute the (coordinate) normal data based on the point coordinates.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryAddVertexByReadIndex =R"doc(Go to the source mesh at specified readIndex. Bring all it's data into
a new vertex in the visitor.

:returns:
    false if not a valid readIndex for the client array, or if the
    client array has a zero (terminator) there, or if the client is
    not fully indexed.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClearFacet =R"doc(Clear all arrays in the visitor. This is used before
AddVertexByReadIndex.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetDistanceParameter =R"doc(get a distance based parameter at an index within the current facet)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetNormalizedParameter =R"doc(get a normalized (0-1) parameter at an index within the current facet)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetEdgePoint =R"doc(interpolate a point on an edge. Edge index is interpretted cyclically
(within the current face))doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetFacetAreaMomentProducts =R"doc(return true if products of inertia for an AREA integral over the facet
can be computed.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetFacetCentroidNormalAndArea =R"doc(return true if centroid, area, and normal can be calculated for the
current facet.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryFindCloseFacetPoint =R"doc(Test if a point is close to a facet.

:param (input):
    spacePoint test point.

:param (input):
    tolerance tolerance for identifying a hit.

:param (output):
    facetPoint point on facet.

return true if a hit was found.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryFindFacetRayIntersection =R"doc(Test if ray pierces facet or come close to an edge or vertex.

:param (input):
    ray test ray.

:param (input):
    tolerance tolerance for edge/vertex passby

:param (output):
    facetPoint point on facet.

:param (output):
    rayFraction parameter along ray

return true if a hit was found.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TrimFaceData =R"doc(Trim all face data arrays, retaining{count} values starting at
{index0})doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_PushInterpolatedFaceData =R"doc(In source, interpolate between specified indices of face data. Active
state is checked in receiver. Index is not checked.

return the index of new point.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_PushIndexData =R"doc(In source, copy index data (point, normal, param, color) from
specified index of source. Active state is checked in receiver. Index
is not checked.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_PushFaceData =R"doc(Copy face data (point, normal, param, color, visible) from specified
index of source. Active state is checked in receiver. Index is not
checked.

return the index of new point.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_CompressClosePoints =R"doc(Compress adjacent points (including last/first) within tolerance.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TrimData =R"doc(Trim all arrays to newSize.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_CopyData =R"doc(Copy all data from one index to another.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_Attach =R"doc(Save data for traversing the given parentMesh)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_IndexPosition =R"doc(return the (reference to) the array indicating where vertex indices
were read from the attached mesh.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_Visible =R"doc(return the (reference to) the array of per-edge visibility flags.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_SetNumWrap =R"doc(Set the number of wraparound vertices to be added to faces when they
are read.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_GetNumWrap =R"doc(return the number or wraparound vertices that are added to the arrays.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_NumEdgesThisFace =R"doc(return the number of edges on the current face.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_MoveToFacetByReadIndex =R"doc(Focus on facet with specified readIndex.

:param (input):
    readIndex readIndex in facet.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_GetReadIndex =R"doc(Return the readIndex (current position within client facets). This
value can be used to return here via MoveToFacetByReadIndex

:returns:
    readIndex in facet.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetLocalFrameAndRank =R"doc(Like TryGetLocalFrame, but with integer return type to distinguish

* 0 -- really degenerate data -- single point?

* 1 -- degenerate to a line

* 2 -- usual full-rank case.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetLocalFrame =R"doc(Interogate the xy coordinates (NOT THE STORED Param() ARRAY !!!) to
determine a local coordinate frame for the current facet. This is the
same logic used for CurveVector::CloneInLocalCoordinates and
PolygonOps::CoordinateFrame. That is:ul> li>The prefered x axis
direction is parallel to the first edge. li>The prefered z direction
is the outward normal of the xyz loop with CCW direction. li>The
selector parameter chooses among 4 options:

* LOCAL_COORDINATE_SCALE_UnitAxesAtStart -- origin at first point
(even if not lower left!!), local axes have unit length, so local
coordinates are real distances.

* LOCAL_COORDINATE_SCALE_UnitAxesAtLowerLeft -- origin at lower left.
All xy local coordinates are 0 or positive, and local coordinates are
real distances along the local directions

* LOCAL_COORDINATE_SCALE_01RangeBothAxes -- Shift to lower left and
scale to both directions go 0 to 1

* LOCAL_COORDINATE_SCALE_01RangeBothAxes -- Shift to lower left and
scale so one direction goes 0 to 1, the other direction has same scale
and its largest coordinate is positive and 1 or less.

ul> Prefered x axis is parallel to the first edge.

:param (output):
    localToWorld transform from local to world

:param (output):
    worldToLocal transform from world to local

:param (input):
    selector indicates preference for origin and scaling.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_AccumulateScaledData =R"doc(accumualted a (multiple of) all numeric data to a detail. Copy integer
color and table number unchanged.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_IntepolateDataOnEdge =R"doc(interpolate all possible data along an edge of the current facet.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryDRay3dIntersectionToFacetLocationDetail =R"doc(Find a uv location within the facet. Compute all available data there.
returns false if the facet does not have params or if there are not
edges on both sides along the scan lines.

:param (input):
    ray ray to intersect with facet.

:param (input):
    detail all coordinate data at this parametric coordinate.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryParamToFacetLocationDetail =R"doc(Find a uv location within the facet. Compute all available data there.
returns false if the facet does not have params or if there are not
edges on both sides along the scan lines.

:param (input):
    uvParam pick parameter.

:param (input):
    detail all coordinate data at this parametric coordinate.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_AddCoordinatesFromFacetLocationDetail =R"doc(add coordinate data from a vertex described by a facet location
detail.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_LoadVertexData =R"doc(Copy all data from a particular vertex (indexed within the visitor)
into a facet location detail.

:param (output):
    detail destination for copied data.

:param (input):
    index index within data arrays for the visitor.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClearAllArrays =R"doc(Clear all arrays in the visitor.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryParamToScanBrackets =R"doc(Try to locate facet edges before and after a specified param in a
facet. returns false if the facet does not have params or if there are
not edges on both sides along the scan lines.

:param (input):
    uvParam pick parameter.

:param (input):
    horizontalScanBracket edge crossing data to left and right of uv.

:param (input):
    verticalScanBracket edge crossign data below and above.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_AdvanceToFacetBySearchRay =R"doc(Call AdvanceToNextFace repeatedly, returning when a face is found
within tolerance of a pick ray.

:param (input):
    ray ray

:param (input):
    tolerance proximity tolerance.

:param (output):
    facetPoint pierce point on facet.

:param (output):
    rayFraction parameter along ray. return false if all faces have
    been visited.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_AdvanceToFacetBySearchPoint =R"doc(Call AdvanceToNextFace repeatedly, returning when a face is found
within tolerance of search point.

:param (input):
    xyz search point

:param (input):
    tolerance proximity tolerance.

:param (output):
    facetPoint nearest point on facet

return false if all faces have been visited.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_AdvanceToNextFace =R"doc(Read the next face from the attached mesh. return false if all faces
have been visited.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_Reset =R"doc(Reset to beginning of attached mesh, i.e. to read facets again.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetClientZeroBasedColorIndex =R"doc(access zero-based color index for an vertex within the curent face.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetClientZeroBasedParamIndex =R"doc(access zero-based param index for an vertex within the curent face.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetClientZeroBasedNormalIndex =R"doc(access zero-based normal index for an vertex within the curent face.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_TryGetClientZeroBasedPointIndex =R"doc(access zero-based point index and visibility flag for an vertex within
the current face.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClientFaceIndex =R"doc(Get reference to the blocked array of zero-based indices into client
mesh faces.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClientColorIndex =R"doc(Get reference to the blocked array of zero-based indices into client
mesh colors)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClientNormalIndex =R"doc(Get reference to the blocked array of zero-based indices into client
mesh normals.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClientParamIndex =R"doc(Get reference to the blocked array of zero-based indices into client
mesh params.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ClientPointIndex =R"doc(The client indices are zero-based indices into the client mesh data.
Get reference to the blocked array of zero-based indices into client
mesh points.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_IlluminationName =R"doc(Get reference to the illumination name)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_FloatColor =R"doc(Get reference to the FloatRbg array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_ColorTable =R"doc(Get reference to the Point array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_IntColor =R"doc(Get reference to the integer color array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_DoubleColor =R"doc(Get reference to the double color array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_Normal =R"doc(Get reference to the normal array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_Param =R"doc(Get reference to the param array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVisitor_Point =R"doc(Get reference to the Point array with blocking data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ReplicateMissingIndexArrays =R"doc(If (1) param, normal, or color indices are missing and (2) their
respective data arrays have size match with points, fill up the index
array as duplicate of the pointIndex)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CollectEdgeMateData =R"doc(Create segments containing edges of this polyface. The returned array
indicates

* segment coordinates

* a readIndex. Based on the returnSingleEdgeReadIndex value, his can
be either the base readIndex for the whole facet, or the detail read
index for the individual edge.

* clusterIndex. Shared edges will return the same cluster index.

* number of edges in the cluster. If collecting only unmatched edges,
this normally be 1, but can be

:param (output):
    segments array of segment data.

:param (input):
    includeMatched true to include interior segemnts that have mates.

:param (input):
    returnSingleEdgeReadIndex if true, return read index to the base
    of the individual edge. If false, return readIndex for the entire
    facet. (The entire facet index is prefered for calling
    visitor->MoveToReadIndex ()))doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_TryGetMaxSingleFacetLocalXYLength =R"doc(Compute the lengths of the longest horizontal and vertical direction
size of any single facet, using the local coordinate system along the
first edge of the facet for directions.

:param (output):
    xySize sizes in u, v directions.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_TryGetMaxSingleFacetParamLength =R"doc(Compute the lengths of the longest u and v direction size of any
single facet, looking only at the stored param.

:param (output):
    uvLength sizes in u, v directions.

:returns:
    false if the facets do not have params)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SelectBlockedIndices =R"doc(Copy selected blocks of read indices to a new blocked index array.

:param (input):
    blockedReadIndex Array of read indices with -1 as terminator
    between blocks that are to go to the same destination mesh.

:param (input):
    selectedReadIndex Array of read indices for choosing blocks.

:param (input):
    keepIfSelected indicates what to do with a block when it contains
    an index that is in the selectedReadIndexArray.

* true means when a block contains a selected read index it is copied.

* false means when a block contains a selected read indexc it is
ignored.

:param (output):
    blockedReadIndexOut array containing only the accepted blocks)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_IsPlanarWithinSuperfacets =R"doc(Determines if each visible facet (a super facet) is planar within
tolerance.

:param (input):
    tolerance. If a negative number is provided, the tolerance used is
    a small fraction of the diagonal range.

:returns:
    true iff each super facet is planar within tolerance.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SplitByFlood =R"doc(Return blocks of read indices for " islands " of facets surrounded by
" channels " The search process is:

* choose any start facet.

* expand outward from that facet to neighbors.

* repeat the expansion to the level indicated by
optionsA.m_layerThickness

* treat all facets there as an " A " group.

* expand outward from the fringe of the island by
optionsB.m_layerThickness layers.

* treat all facets in this (wide front) expansion there as a " B "
group.

* Seed the next round of " A " facets by a single facet beyond the
fringe of the recent " B " step.

Note that because the " optionsA " step starts with a single seed (plus
its expanding layers) it produces compact " islands ". Becasue
" optionsB " step starts with a wide front of facets it produces larger
layered regions. The " A " and " B " groups are returned under control of
the m_outputSelect part of its options.

* m_outputSelect == 0:leave that group out completely.

* m_outputSelect == 1:collect all groups as a single partition.

* m_outputSelect == 2:collect each group as a small isolated
partition.

* BUT -- if both are zero, both are switched to 1.

:param (output):
    blockedReadIndexArray read indices for individual faces, separated
    by (-1).)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_PartitionReadIndicesByNormal =R"doc(Return indices of subsets with consistent forward and reverse
visibility for given vector.

:param (input):
    vector viewing direction vector

:param (output):
    readIndices read indices for forward, reverse, and perpendicular
    facets

:returns:
    false if vector is 000.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_MarkAllEdgesVisible =R"doc(Mark all edges visible.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_MarkTopologicalBoundariesVisible =R"doc(Expose topological boundaries

:returns:
    true if any edges were changed.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_MarkInvisibleEdges =R"doc(Mark edges invisible (negative index) if dihedral angle between
normals is small. If normals are present they are used. If not
present, per-face normals are computed and used (but then removed))doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_BuildPerFaceFaceData =R"doc(Compute face data for each facet.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_BuildPerFaceNormals =R"doc(Compute a normal vector for each faceet. Install indices.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ClearParameters =R"doc(Clear current param data.

:param (input):
    active active state (true/false) to be applied after clearing.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ClearNormals =R"doc(Clear current normal data.

:param (input):
    active active state (true/false) to be applied after clearing.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_MarkDiagonalEdgesInvisible =R"doc(mark edges invisible by smoothAngle and silhoutte conditions, and
additionally requrie them to be " diagonals ". The conditions for a
diagonal are 1) longer than each other edge of the facet by at least
edgeLengthFactor 2) at most maxEdgesInFacet This is specifically
intended for civil road meshes which have slightly twisted quads that
must be triangulated for calculations. If triangulated, both the
transverse edges and diagonals would get hidden by usual dihedral
angle rules. This hides the diagonals but leaves the simple transverse
edges visible.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_BuildPerFaceParameters =R"doc(Compute local coordinates within each facet.

:returns:
    true if parameters computed.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_AddIfMatchedLayout =R"doc(Add all content of source to this polyface. This does NOT attempt to
recognize duplicate coordinate data.

:returns:
    false if mismatched data -- e.g. arrays present on one but not the
    other.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CopyFrom =R"doc(Clear current data, append data from (readonly) source)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SweepToSolid =R"doc(Sweep the existing mesh promote to a solid

:returns:
    false if the input mesh has inconsistent visibility -- i.e. side
    or mixture of forward and back facing facets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_LocalDecimation =R"doc(:returns:
    number of collapses.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CloneWithTVertexFixup =R"doc(Clone the meshes as a single mesh, inserting vertices along edges
where vertices from other facets create T-Vertex topology)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CloneWithMaximalPlanarFacets =R"doc(Search for adjacent, coplanar facets. Merge to get maximual planar
facets. Optionally remove vertices that have only two incident and
colinear edges. This uses an very tight (Angle::SmallAngle()) angle
tolerance. Use CloneWithMaximalPlanarFacetsExt for looser tolerance.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CloneWithIndexedDuplicatesRemoved =R"doc(Search the mesh for facets that identical sets of point indices.
Return a clone with only one copy of each.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_TranslateSelectedFacets =R"doc(Apply a translation to a subset of facets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CollectAdjacentFacetAndPointIndices =R"doc(Collect indices of (1) adjacent facets and (2) points within the
active facets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ReverseNormals =R"doc(Reverse (negate) all stored normals. Note that this does NOT change
index order.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CompactIndexArrays =R"doc(Revise index structure to minimize array lengths.

:returns:
    true if any changes were made.)doc";

static const char* __doc_Bentley_Geom_PolyfaceHeader_CompactArrays = R"doc(Trim excess capacity from the data and index vectors. No data is removed.

:returns:
    bytes trimmed

:param (input):
    call CompactIndexArrays first)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_AddEdgeChains =R"doc(Add Edge Chains)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SplitByMaxEdgeLength =R"doc(* Find the maximum edge length of each facet.

* Split into two sets of facets with that criteria.

* Note that removal can happen anywhere in the mesh.

* use ExcavateFacetsWithBoundaryEdges to remove only edges reachable
by crossing long edges from a long starting edge on the boundary.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ExcavateFacetsWithLongBoundaryEdges =R"doc(* Find facets with boundary edges longer than maxEdgeLength.

* Remove the facets.

* Continue searching for long edges in the newly exposed facets.

* If the initial facets are an xy triangulation of points (with the
convex hull outer boundary), the first removals creates a non-convex
outer boundary. Later removals can create islands of facets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ConstructOrderingForLongEdgeRemoval =R"doc(Determine a facet order such that the LAST facets are the first to be
removed when applying the logic " Remove the longest exterior edge first " ul> li> If this is applied to facets of a triangulation (whose
outer boundary is convex), the successive outer boundaries are
polygons that contain short edges and have inlets where there are long
edges on the outside. The readIndexSequence contains sequences of
readIndices for the shuffled facets. li> Suppose a facet

* initially has vertices, params, normals, and colors indicated at
(consecutive) readIndices [a b c]

* the edges from b to c is chosen for removal

li> li>That facet will appear as [b c a SIZE_MAX]. ul>)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_OrientAndCollectManifoldComponents =R"doc((output) arrays of read indices within components (output) array of status
messages)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_FixupVertexNormalDirectionToFaceOrientation =R"doc(Inspect and correct the direction of " at vertex " normals relative to
the ordering of vertices around facets. Returns true if any changes
were made. The summary vector will contain entries indicating:ul>
li>Early exit if fails assertion " Mesh should ( but does not ) have both NormalIndex and Normal ( ) data " li>Quiet warning, not a change
trigger:" Ignoring facet whose facet normal cannot be computed from vertex coordinates " li>Quiet warning, not a change trigger:" Ignoring out of range normal index " li>Quiet warning of change trigger:" vertex normal has both positive and negative incident facets A new negated normal is introduced " li>Quiet warning of change trigger:" All incident facets normals are reverse of vertex normal - - normal is negated " li>Quiet warning, not a change trigger:" unused normal coordinates " li> ul>)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateUnifiedIndexMesh =R"doc(Copy all data to a new mesh, reorganizing so that all data arrays have
the same index structure. This is a memory-efficient structure ONLY
for smooth surfaces such as bspline, cylinder, sphere. This is a
highly inefficent structure for any mesh with interior edges.
Unfortunately it is a common mesh structure in exchange formats.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_Triangulate =R"doc(Triangulate faces. return SUCCESS if all faces triangulated.

Remark:
    this should return bool.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SetNewFaceData =R"doc(Set face data for all facets added since last call to SetNewFaceData.
(endIndex = 0 for all facets).)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CopyTo =R"doc(Copy all data to another header.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_VisibleParts =R"doc(Create a polyface containing all visible parts for a flat view of
among multiple meshes.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateFromTaggedPolygons =R"doc(Create a (indexed) polyface containing all polygons from a
TaggedPolygonVector)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateIndexedMesh =R"doc(Create a mesh with (just) point and index data.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateFixedBlockCoordinates =R"doc(Create a (smart pointer to a) new (empty) PolyfaceHeader, with each
facet defined by 3 or 4 unindexed points as indicated by the arg.

:returns:
    invalid if numPerFace is other than 3 or 4.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CloneWithSidePanelsInserted =R"doc(* Input an array of meshes expected to have boundary segments are
separated by " missing side panels " as viewed in a certain direction.

* return a (separate, new) mesh with the side panels added. Additional
midEdge vertices are inserted into the original facets if T vertices
are present.

* CreateSidePanelsForViewDirection creaates the panels

* CloneWithTVertexFixup does touchup for extra vertices.)doc";

static const char* __doc_Bentley_Geom_PolyfaceHeader_CreateDRange3dFaces = R"doc(* Create a mesh with the faces of a DRange3d, optionally transformed and triangulated
If the transform has negative determinant, indices are shuffled to get outward normals.

:returns:
    a mesh with the faces of a DRange3d. 

:param (input):
    points to triangulate

:param (input):
    if true, add a (hidden) diagonal in each face.

:param (input):
    optional transform to apply.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateSidePanelsForViewDirection =R"doc(Input an array of meshes expected to have boundary segments are
separated by " missing side panels " as viewed in a certain direction.
return a (separate, new) mesh with only the side panels.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateRegularPolyhedron =R"doc(Create a classic polyhedron, i.e. one of

* 0 = Tetrahedron

* 1 = Cube

* 2 = Octahedron

* 3 = Dodecahedron

* 4 = Icosahedron

The polyhedron is " in a sphere ", with measurement indicated by

* 0 = measure radius to vertices

* 1 = radius to midedge, orient with x axis to mid-edge (see 101)

* 2 = radius to midface

* 100 = radius to vertex, but orient cube and octahedron with square
cross section in xy plane.

* 101 = radius to midedge, but orient cube and octahedron with square
cross section in xy plane.

* 102 = radius to midface, but orient cube and octahedron with square
cross section in xy plane.

The orientation is as follows:

* For selection 100, 101 and 102 for cube and octahedron, a square
cross section is parallel to the xy plane.

* For all other cases (0,1,2 for all polyhedra, and 101,101,102 for
other than cube and octahedron)

* A vertex, mid-edge, or centroid point (respective to the
measurement) is on the positive x axis

* Another edge of an incident face is in the y direction.

* Hence when viewed from positive x towards center, there will be a
horizontal edge

* on a face with a vertex on the x axis.

:param (input):
    radius radius of sphere

:param (input):
    polyhedronSelect integer selector, as enumerated above.

:param (input):
    radiusSelect control of sphere radius, as enumerated above.

:param (input):
    transform optional transform to place the sphere.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateXYTriangulation =R"doc(Create a triangulation of points as viewed in xy. Add the triangles to
the polyface. (Other than sharing vertices with matched xy, this does
not coordinate in any way with prior mesh contents.)

:param (input):
    points candidate points

:param (input):
    fringeExpansionFactor fractional factor (usually 0.10 to 0.20) for
    defining a surrounding rectangle. The z of this triangle is at the
    low z of all the points.

:param (input):
    retainFringeTriangles true to keep the fringe triangles. If false,
    any edge that reaches the outer rectangle is deleted.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateTriangleGrid =R"doc(Create a (smart pointer to a) new (empty) PolyfaceHeader, with
quadrilaterals defined by points in a grid, and then each quad is
split to triangle.

:returns:
    invalid if numPerRow<2.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateQuadGrid =R"doc(Create a (smart pointer to a) new (empty) PolyfaceHeader, with
quadrilaterals defined by points in a grid.

:returns:
    invalid if numPerRow<2.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateFixedBlockIndexed =R"doc(Create a (smart pointer to a) new (empty) PolyfaceHeader, with fixed
number of indices per face

:returns:
    invalid if numPerBlock is less than 3.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_CreateVariableSizeIndexed =R"doc(Create a (smart pointer to a) new (empty) PolyfaceHeader, with
variable length faces. This is the most common mesh style.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_RemoveTwoEdgeFacesFromVariableSizeOneBasedMesh =R"doc(Find and remove faces with 2 or fewer edges. This operates only on
VariableSizeOneBasedMeshes -- caller responsible for converting to
that if needed.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ConvertTableColorToColorIndices =R"doc(Build color indices as face loops (as needed) Return false if no
conversion or if point index tables asked for more table indices than
present in the TableColor arrays.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ConvertToVariableSizeSignedOneBasedIndexedFaceLoops =R"doc(Convert the mesh indexing to signed, one-based, variable size face
loops.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SetActiveFlagsByAvailableData =R"doc(Make each active flag true/false according to available data. Point,
Normal, Param, DoubleColor, FloatColor, IntColor, and ColorTable,
FaceIndex, FaceData look only at their own data. Indices look at their
own size and that of respective indexed arrays.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ActivateVectorsForPolylineIndexing =R"doc(Set active flags so this polyface carries data and indices for
polylines compatible with source.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ActivateVectorsForIndexing =R"doc(Set active flags so this polyface carries data and indices for all the
data in source.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_TerminateAllActiveIndexVectors =R"doc(Add terminator to all active index vectors.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ClearAllVectors =R"doc(Clear all facets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ClearAllIndexVectors =R"doc(Clear all index vectors.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_EdgeChain =R"doc(Return a reference to the edge chain index vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_FaceData =R"doc(Return a reference to the face information.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_FaceIndex =R"doc(Return a reference to the face index vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_IlluminationName =R"doc(Return a reference to the illumination name string.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ColorIndex =R"doc(Return a reference to the color index vector. Completion of color
dereference depends on additional data in DoubleColor, IntColor, or
ColorTable)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_NormalIndex =R"doc(Return a reference to the normal index vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ParamIndex =R"doc(Return a reference to the param index vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_PointIndex =R"doc(Return a reference to the point (vertex) index vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_FloatColor =R"doc(Return a reference to the array of float rgb colors.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ColorTable =R"doc(Return a reference to the array of color table as integer table
select.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_IntColor =R"doc(Return a reference to the array of color as integers.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_DoubleColor =R"doc(Return a reference to the vector of color-via-RgbFactor structs.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_Normal =R"doc(Return a reference to the normal vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_Param =R"doc(Return a reference to the param (texture space) coordinate vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_Point =R"doc(Copy all contents to destination vectors Return a reference to the
point (vertex) coordinate vector.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SetTextureId =R"doc(Set the texture id.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_SetIlluminationName =R"doc(Set the illumination name string)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_ClearTags =R"doc(Initial setup for tag data in blocked vectors. Points are active.
Point indices are active if style is MESH_ELM_STYLE_INDEXED_FACE_LOOPS
All other coordinate and index arrays are NOT active. TwoSided is
true.)doc";

static const char * __doc_Bentley_Geom_PolyfaceHeader_Compress =R"doc(Compress duplicate coordinate data, with default realtive tolerances.)doc";

static const char * __doc_Bentley_Geom_IndexedParameterMap_ConstructMapping =R"doc(Find any 3 non-colinear points and construct world-to-barycentric map.
Return false (with identity transforms) if no independent triple
found.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_FindOrAddColorTable =R"doc(Find or add a color table. * Activate if needed. * This is a linear
search !)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_SetMeshStyle =R"doc(Set the facet data style.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_SetNumPerRow =R"doc(Set the row count for gridded facets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_SetNumPerFace =R"doc(Set the index blocking count)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_SetTwoSided =R"doc(Set the flag for twosided facets)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_CopyAllActiveFlagsFromQuery =R"doc(In PolyfaceQuery, determine active status from pointers. This is only
valid if the PolyfaceQuery has already been filled !!!)doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_ClearAllArrays =R"doc(clear all arrays (but flags stay unchanged))doc";

static const char * __doc_Bentley_Geom_PolyfaceVectors_CopyAllActiveFlagsFrom =R"doc(Copy active flags from the various arrays of the source.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_HasIndexErrors =R"doc(Apply various checks for indexing structure.

:returns:
    true if any errors were found.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_IsSameStructureAndGeometry =R"doc(Test for AlmostEqual () conditions.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_PickFacetsByStroke =R"doc(Search for facets that are touched by a stroke. returns true if valid
point data and one or more facets selected.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_DirectionalAreaAndVolume =R"doc(Compute areas, centroids, volumes of projections onto principal
planes.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_DirectionalVolumeIntegrals =R"doc(@description Compute (many) integrals of volume properties, using
directional formulas that will give correct results (and confidence
indicators) when " some " facets are missing

:param (input):
    polyface facets for integration

:param (output):
    pData array (allocated by caller) of various integrals:

* pData[0], pData[1], pData[2] = view along respective axes. Use
signed area, so result should be zero if all facets are present to
cancel.

* pData[0], pData[1], pData[2] = view along respective axes. Use
absolute area, so result should be useful for setting tolerances.

* pData[6] = full 3d area.

:param (output):
    directionalProducts array of products integrals wrt origin.
    Allocated by caller.

:param (output):
    origin origin used for directonal integrals. (Directional
    integrals are " from the principal " planes through this origin.))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_HealVerticalPanels =R"doc(Attempt to heal vertical gaps in a mesh.

:param (input):
    polyface original polyface

:param (input):
    tryVerticalPanels true to seek pure vertical panels

:param (input):
    trySpaceTriangulation true to seek triangulation of any missing
    faces, as viewed from any direction found useful.

:param (output):
    healedPolyface modified polyface. This is NOT constructed if no
    panels can be added.

:returns:
    number of facets added)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ComputePunchXYByPlaneSets =R"doc((input) each facet of this is used as a " punch " (input) facets to be split
by the punch. (output) (target intersect punch) (output) (target outsideOf
punch) (output) optional meshes for debugging)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ComputePunch =R"doc(@description " Punch " through target polygons.

:param (input):
    punch punch polygons

:param (input):
    target target polygons

:param (input):
    keepInside true to return the target mesh parts that are inside
    the punch, false to return outside parts.

:param (output):
    result punched mesh)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ComputeUndercut =R"doc(@description Compute volumes where polyfaceB undercuts polyfaceA)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ClusteredVertexDecimate =R"doc(@description Fas clustered vertex decimator - used during tile
generation.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ClipToPlaneSetIntersection =R"doc(@description Clip polyface to intersection of an array of plane sets.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_SweepLinestringToMesh =R"doc(@description Compute intersections (line strings) of this mesh with a
swept linestring

:param (output):
    xyzOut array of points on the intersection linestrings.
    DISCONNECTS separate multiple linestrings.

:param (output):
    linestringIndexOut for each xyzOut[i], the index of the input
    segment that it came from.

:param (output):
    meshIndexOut for each xyzOut[i], the mesh read index it came from.

:param (input):
    linestringPoints points to sweep.

:param (input):
    sweepDirection sweep direction)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_TryEvaluateEdge =R"doc(Try to convert the index and edge fraction of a
FacetEdgeLocationDetail to a point.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_EnsureFloatColor =R"doc(If float colors are not already present, build them from double
colors. Returns false if the implementing class is read only.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_LargestCoordinate =R"doc(Query largest absolute coordinate)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_HasConvexFacets =R"doc(Check convexity)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_IsTriangulated =R"doc(Test if all facets are 3 sided)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_HasFacets =R"doc(Test if any facets are defined (Specifically, true if the point index
set is nonempty).)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_IsClosedByEdgePairing =R"doc(Test if vertex indices around faces indicate watertight closure.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_DrapeLinestring =R"doc(Project linestring in given direction to intersection with facets.
Return as a curve vector.

:param (input):
    spacePoints points to project onto the polyface

:param (input):
    direction direction to project.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_PlaneSlice =R"doc(Cut with a plane. (Prototype) Return as a curve vector. Optionally
structure as area-bounding loops.

:param (input):
    sectionPlane plane to cut the mesh.

:param (input):
    formRegions true to look for closed loops and structure the return
    as a loop or parity CurveVector.

:param (input):
    markEdgeFractions true to attache FacetEdgeLocationDetailVector to
    the linestrings.

:param (input): skipOnPlaneFacets whether output lacks facets coplanar with sectionPlane.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_CollectSegments =R"doc(Collect individual segments for each distinct edge.

:param (output):
    segments array to receive segments.

:param (input):
    omitInvisibles true to hide segments that are not visible (due to
    negated indices))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ReverseIndicesOneFace =R"doc(Reverse a single face loop in parallel index arrays.

Remark:
    s A face loop is reversed after the 1st index:the 2nd/last
    indices are swapped, the 3rd/penultimate indices are swapped, etc.

:param (input):
    iFirst 0-based offset to the first index in the face loop

:param (input):
    iLast 0-based offset to the last index of the face loop.

:param (input):
    normalArrayIndexAction selects action in normal array. This can be

* IndexAction::None -- leave the index value unchanged

* IndexAction::ForcePositive -- change to positive

* IndexAction::ForceNegative -- change to negative

* IndexAction::Negate -- change to negative of its current sign)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ParamRange =R"doc(Return range of the parameters.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetMediumTolerance =R"doc(Return a tolerance appropriate for medium accuracy calculations (8
digits relative))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetTightTolerance =R"doc(Return a tolerance appropriate for high accuracy calculations (12 or
more digits relative))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_PointRange =R"doc(Return range of the points.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_SumFacetSecondAreaMomentProducts =R"doc(Return the sum of facet areas. Return moment products with respect to
origin.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_SumFacetFirstAreaMoments =R"doc(Return the sum of facet areas. Return moment with respect to origin.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_SumFacetAreas =R"doc(Return the sum of facet areas. There is no check for planarity.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_SumTetrahedralFirstMoments =R"doc(Return the sum of tetrahedral moments from the specified origin. If
the mesh is closed and all facets are simply connected planar, this is
the moment around the origin. (The facets and volume are not require
to be convex.)

:param (input):
    origin origin for tetrahedra.

:param (output):
    moments sum of (x,y,z) dV

:returns:
    summed volume)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_SumTetrahedralVolumes =R"doc(Return the sum of tetrahedral volumes from the specified origin. If
the mesh is closed and all facets are simply connected planar, this is
the signed enclosed volume. (The facets and volume are not require to
be convex.))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_ValidatedVolume =R"doc(Test if the mesh passes IsClosedByEdgePairing, and compute volume if
so.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_CloneAsVariableSizeIndexed =R"doc(Return a PolyfaceHeader, with variable length faces.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_Clone =R"doc(Return a PolyfaceHeader with the same contents.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_TryGetParamAtReadIndex =R"doc(Try to access param coordinates through a readIndex in the paramIndex
array.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_TryGetNormalAtReadIndex =R"doc(Try to access normal coordinates through a readIndex in the
normalIndex array.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_TryGetPointAtReadIndex =R"doc(Try to access point coordinates through a readIndex in the pointIndex
array.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetMeshStyle =R"doc(Query the mesh style (MESH_ELM_STYLE_INDEXED_FACE_LOOPS etc))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetNumPerRow =R"doc(Query the row size for gridded mesh (quad or triangular))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetNumPerFace =R"doc(Query the nominal number of facets per face. If this is 0 or 1, facets
are variable size and separated by 0 as terminator. If larger the
indices are blocked (with 0 as pad if needed))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetTwoSided =R"doc(Query if facets are considered two sided. (If not, outward normal can
be used to cull backfaces))doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetTextureId =R"doc(Return a pointer to contiguous texture id.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetEdgeChainCount =R"doc(Return the number of edge chains.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetFaceIndexCount =R"doc(Return the number of face data indices)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetPointIndexCount =R"doc(Return the number of point indices.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetFaceCount =R"doc(Return the number of faces. Note that this is not a " facet " count --
many facets can reference the same containing face in the parent
geometry.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetColorCount =R"doc(Return the number of colors.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetParamCount =R"doc(Return the number of parameters.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetNormalCount =R"doc(Return the number of normals.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_GetPointCount =R"doc(Return the number of points.)doc";

static const char * __doc_Bentley_Geom_PolyfaceQuery_IsVariableSizeIndexed =R"doc(Test if this mesh is vaiable sized indexed.)doc";

static const char * __doc_Bentley_Geom_FacetCutFillHandler_Reset =R"doc(Called to reset the computation. This is important:The FastCutFill
caller may decide to throw away partially completed results and
restart.)doc";

static const char * __doc_Bentley_Geom_FacetCutFillHandler_ProcessCutFillFacet =R"doc(Announce coordinates in paired dtm and road loops.

* both loops are oriented CCW.

* Hence when building closed meshes, the lower of the two must be
reversed to get the downward directed surface properly oriented

* points are in corresponding order -- dtm[i] and road[i] have
identical xy coordinates, different z

* isCut is true when the dtm is above the road

* isCut is false for road above dtm.

* isCut (or comparison of corresponding z coordinates) is consistent
around the entire facet.)doc";

static const char * __doc_Bentley_Geom_FacetCutFillHandler_ContinueSearch =R"doc(Test if the handler object is still interested in the calls. This is
not normally implemented)doc";

static const char * __doc_Bentley_Geom_PolyfaceEdgeChain_GetIndexCount =R"doc(Query the number of indices.)doc";

static const char * __doc_Bentley_Geom_PolyfaceEdgeChain_GetId =R"doc(query the CurveTopologyId)doc";

static const char * __doc_Bentley_Geom_PolyfaceEdgeChain_AddZeroBasedIndices =R"doc(add indices)doc";

static const char * __doc_Bentley_Geom_PolyfaceEdgeChain_AddIndex =R"doc(add an index.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_SortUV =R"doc(Sort an array based by CompareUV ...)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_CompareUV =R"doc(lexical compare in u,v coordinates.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_SetNormal =R"doc(Set the normal and record that it is valid.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_SetReadIndex =R"doc(Set read index)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_GetReadIndex =R"doc(Get read index)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_SetIsInterior =R"doc(Set flag as interior point)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_GetIsInterior =R"doc(Get interior point flag)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetColorTable =R"doc(Access a color table index (by index within the facet))doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetIntColor =R"doc(Access (for an index into the tables within the detail) the int color)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetVertexIndex =R"doc(Access (for an index into the tables within the detail) the vertex
index (numbered within the facet))doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetWeight =R"doc(Access (for an index into the tables within the detail) a weight for
contributing data.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_GetNumWeights =R"doc(Return the number of vertices that are weighted together for the
computed values. This (along with the weight fractions, intColor, and
colorTable indices) can be used compute additional data accessed
through the indices. At most 4 weights can be stored. The possible
data is:

* vertex index -- the index of the vertex (numbered within the facet)

* fraction -- (double) the weight used for data at this indexed
vertex.

* intColor -- integer color data.

* colorTable -- color table index)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetDoubleColor =R"doc(Copy doubleColor data. Return false if not available.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetFloatColor =R"doc(Copy floatColor data. Return false if not available.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetNormal =R"doc(Copy normal data. Return false if not available.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetParam =R"doc(Copy parameter data. Return false if not available.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_TryGetPoint =R"doc(Copy point data. Return false if not available.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_AccumulateScaledData =R"doc(accumulate a scaled multiple of all numeric data from source. append
index data and fraction arrays to arrays (if possible within space
restrictions). Fractions from the source are scaled by the new
fraction.)doc";

static const char * __doc_Bentley_Geom_FacetLocationDetail_Zero =R"doc(Zero all contents.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_MinMax =R"doc(Return min and max values in entire vector.

:param (output):
    minValue smallest value, INT_MAX if empty array.

:param (output):
    maxValue largest value, INT_MIN if empty array.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_DelimitFace =R"doc(From given start position, find final (inclusive) position and
position for next start search. Initialize iFirst to zero before first
call. Return false if no more faces.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_NegativeAbsInRange =R"doc(for each k in the inclusive range kFirst<=k<=kLast, set the entry to
the negative of its absolute value.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AllNegativeInRange =R"doc(return true if all entries in the inclusive range kFirst<=k<=kLast are
negative.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_Abs =R"doc(Set each entry to its absolute value)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AbsInRange =R"doc(for each k in the inclusive range kFirst<=k<=kLast, set the entry to
its absolute value.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_ShiftSignsFromCyclicPredecessorsInRange =R"doc(for each k in the inclusive range kFirst<=k<=kLast, set the sign to
the prior value from its)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AddTerminatedGridBlocks =R"doc(Create indices for a rectangular grid.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AddAndTerminate =R"doc(Add one row with terminator or pad.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AddSteppedBlock =R"doc(Add one row with wraparound, optional terminator. NO ACTION if the
array is not active !!!!)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AddSequentialBlock =R"doc(Add one row with wraparound, optional terminator. NO ACTION if the
array is not active !!!!)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_AddTerminatedSequentialBlocks =R"doc(Add numRow blocks of numPerRow sequential values with terminator after
each row.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_CountZeros =R"doc(Count zeros in the vector.)doc";

static const char * __doc_Bentley_Geom_BlockedVectorInt_ConvertBlockedToZeroTerminated =R"doc(If the current array has blocked structsPerRow, expand to variable
length 0-terminated form. (ASSUMES all zeros in blocked form are
placeholders.))doc";

static const char * __doc_Bentley_Geom_FacetFaceData_SetParamDistanceRangeFromNewFaceData =R"doc(To be called just after one or more " one - based, zero terminated "
facets have been added to the polyface. The new facets are identified
as a " face " and the face size data is recorded. Face size is tied to
parameter range by scale factors from simple triangulation of all
facets.)doc";

static const char * __doc_Bentley_Geom_FacetFaceData_ScaleDistances =R"doc(Scale distance parameters)doc";

static const char * __doc_Bentley_Geom_FacetFaceData_ConvertParamToNormalized =R"doc(convert parameter from stored value to normalized (0-1) parameter.)doc";

static const char * __doc_Bentley_Geom_FacetFaceData_ConvertParamToDistance =R"doc(convert parameter from stored value to distance-based parameter.)doc";

static const char * __doc_Bentley_Geom_FacetFaceData_Init =R"doc(restore to constructor state.)doc";

//=======================================================================================
// Trampoline class for FacetCutFillHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyFacetCutFillHandler: FacetCutFillHandler
    {
    using FacetCutFillHandler::FacetCutFillHandler;
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool ContinueSearch() override
        { PYBIND11_OVERRIDE_EXR(bool, FacetCutFillHandler, ContinueSearch, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void ProcessCutFillFacet(
        bvector<DPoint3d>& dtm,
        size_t dtmReadIndex,
        bvector<DPoint3d>& road,
        size_t roadReadIndex,
        bvector<bool>& roadBoundaryFlag,
        bool isCut) override
        { PYBIND11_OVERRIDE_EX(void, FacetCutFillHandler, ProcessCutFillFacet, dtm, dtmReadIndex, road, roadReadIndex, roadBoundaryFlag, isCut); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void ProcessSideFacet(bvector<DPoint3d>& points, bool isCut) override
        { PYBIND11_OVERRIDE_EX(void, FacetCutFillHandler, ProcessSideFacet, points, isCut); }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void Reset() override
        { PYBIND11_OVERRIDE_EX(void, FacetCutFillHandler, Reset, ); }
    };

//=======================================================================================
// Trampoline class for PolyfaceQuery::IClipToPlaneSetOutput.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyClipToPlaneSetOutput : PolyfaceQuery::IClipToPlaneSetOutput
    {
    using PolyfaceQuery::IClipToPlaneSetOutput::IClipToPlaneSetOutput;
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt _ProcessUnclippedPolyface(PolyfaceQueryCR polyfaceQuery) override
        { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, PolyfaceQuery::IClipToPlaneSetOutput, _ProcessUnclippedPolyface, ERROR, polyfaceQuery); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt _ProcessClippedPolyface(PolyfaceHeaderR polyfaceHeader) override
        { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, PolyfaceQuery::IClipToPlaneSetOutput, _ProcessClippedPolyface, ERROR, polyfaceHeader); }
    };

//=======================================================================================
// Trampoline class for Bentley::IPolyfaceVisitorFilter.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyPolyfaceVisitorFilter : Bentley::IPolyfaceVisitorFilter
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool TestFacet(PolyfaceVisitorCR visitor) override
        { PYBIND11_OVERRIDE_EXR(bool, Bentley::IPolyfaceVisitorFilter, TestFacet, false, visitor); }
    };

DEFINE_NODELETE_HOLDER_TYPE(PolyfaceQuery);

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Polyface(py::module_& m)
    {
    //===================================================================================
    // struct FacetFaceData
    py::class_<FacetFaceData> c1(m, "FacetFaceData");
    py::bind_vector< FacetFaceDataArray >(m, "FacetFaceDataArray", py::module_local(false));
    bind_BlockedVector<FacetFaceData>(m, "BlockedVectorFacetFaceData", py::module_local(false));

    c1.def_readwrite("paramDistanceRange", &FacetFaceData::m_paramDistanceRange);
    c1.def_readwrite("paramRange", &FacetFaceData::m_paramRange);
    c1.def_readwrite("xyzRange", &FacetFaceData::m_xyzRange);
    c1.def_readwrite("normalRange", &FacetFaceData::m_normalRange);
    c1.def_readwrite("sourceIndex", &FacetFaceData::m_sourceIndex);
    c1.def_readwrite("faceIndices", &FacetFaceData::m_faceIndices);

    c1.def(py::init<>());
    c1.def("Init", &FacetFaceData::Init, DOC(Bentley, Geom, FacetFaceData, Init));
    c1.def("ConvertParamToDistance", &FacetFaceData::ConvertParamToDistance, "distanceParam"_a, "param"_a, DOC(Bentley, Geom, FacetFaceData, ConvertParamToDistance));
    c1.def("ConvertParamToNormalized", &FacetFaceData::ConvertParamToNormalized, "normalizedParam"_a, "param"_a, DOC(Bentley, Geom, FacetFaceData, ConvertParamToNormalized));
    c1.def("ScaleDistances", &FacetFaceData::ScaleDistances, "distanceScale"_a, DOC(Bentley, Geom, FacetFaceData, ScaleDistances));
    c1.def("SetParamDistanceRangeFromNewFaceData", &FacetFaceData::SetParamDistanceRangeFromNewFaceData, "polyface"_a, "endIndex"_a = 0, DOC(Bentley, Geom, FacetFaceData, SetParamDistanceRangeFromNewFaceData));
    
    c1.def("__repr__", [] (FacetFaceData& self)
           {
           return "(paramDistanceRange:{}, paramRange:{}, xyzRange:{}, normalRange:{}, sourceIndex:{}, faceIndices:{})"_s
               .format(self.m_paramDistanceRange, self.m_paramRange, self.m_xyzRange, self.m_normalRange, self.m_sourceIndex, self.m_faceIndices);
           });

    c1.def("__copy__", [](const FacetFaceData& self)
        {
        return FacetFaceData(self);
        });

    //===================================================================================
    // struct BlockedVectorInt
    py::class_<BlockedVectorInt, BlockedVector<int>> c2(m, "BlockedVectorInt");

    c2.def(py::init<>());
    c2.def("ConvertBlockedToZeroTerminated", &BlockedVectorInt::ConvertBlockedToZeroTerminated, DOC(Bentley, Geom, BlockedVectorInt, ConvertBlockedToZeroTerminated));
    c2.def("CountZeros", &BlockedVectorInt::CountZeros, DOC(Bentley, Geom, BlockedVectorInt, CountZeros));
    c2.def("AddTerminatedSequentialBlocks", &BlockedVectorInt::AddTerminatedSequentialBlocks,
           "numRow"_a, "numPerRow"_a, "clearFirst"_a = false, "firstValue"_a = 1, "terminator"_a = 0, DOC(Bentley, Geom, BlockedVectorInt, AddTerminatedSequentialBlocks));

    c2.def("AddSequentialBlock", &BlockedVectorInt::AddSequentialBlock,
           "firstValue"_a, "numValue"_a, "numWrap"_a, "numTrailingZero"_a = 0, "clearFirst"_a = false, DOC(Bentley, Geom, BlockedVectorInt, AddSequentialBlock));

    c2.def("AddSteppedBlock", &BlockedVectorInt::AddSteppedBlock,
           "fierstValue"_a, "valueStep"_a, "numValue"_a, "numWrap"_a, "numTrailingZero"_a = 0, "clearFirst"_a = false, DOC(Bentley, Geom, BlockedVectorInt, AddSteppedBlock));

    c2.def("AddAndTerminate", &BlockedVectorInt::AddAndTerminate, "pValues"_a, "numValues"_a, DOC(Bentley, Geom, BlockedVectorInt, AddAndTerminate));

    c2.def("AddTerminatedGridBlocks", &BlockedVectorInt::AddTerminatedGridBlocks,
           "numRow"_a, "numPerRow"_a, "rowStep"_a, "colStep"_a, "triangulated"_a, "clearFirst"_a, "firstValue"_a, "terminator"_a, DOC(Bentley, Geom, BlockedVectorInt, AddTerminatedGridBlocks));

    c2.def("NegateInRange", &BlockedVectorInt::NegateInRange, "iFirst"_a, "iLast"_a);
    c2.def("ShiftSignsFromCyclicPredecessorsInRange", &BlockedVectorInt::ShiftSignsFromCyclicPredecessorsInRange, "kFirst"_a, "kLast"_a, DOC(Bentley, Geom, BlockedVectorInt, ShiftSignsFromCyclicPredecessorsInRange));
    c2.def("AbsInRange", &BlockedVectorInt::AbsInRange, "iFirst"_a, "iLast"_a, DOC(Bentley, Geom, BlockedVectorInt, AbsInRange));
    c2.def("Abs", &BlockedVectorInt::Abs, DOC(Bentley, Geom, BlockedVectorInt, Abs));
    c2.def("AllNegativeInRange", &BlockedVectorInt::AllNegativeInRange, "iFirst"_a, "iLast"_a, DOC(Bentley, Geom, BlockedVectorInt, AllNegativeInRange));
    c2.def("NegativeAbsInRange", &BlockedVectorInt::NegativeAbsInRange, "iFirst"_a, "iLast"_a, DOC(Bentley, Geom, BlockedVectorInt, NegativeAbsInRange));

    c2.def("DelimitFace", [] (BlockedVectorIntR self, int numPerFace, size_t iFirst)
           {
           size_t iLast, iNext;
           bool bOk = self.DelimitFace(numPerFace, iFirst, iLast, iNext);
           return py::make_tuple(bOk, iLast, iNext);
           }, "numPerFace"_a, "iFirst"_a, DOC(Bentley, Geom, BlockedVectorInt, DelimitFace));

    c2.def("MinMax", [] (BlockedVectorIntCR self)
           {
           int minValue, maxValue;
           bool bOk = self.MinMax(minValue, maxValue);
           return py::make_tuple(bOk, minValue, maxValue);
           }, DOC(Bentley, Geom, BlockedVectorInt, MinMax));

    c2.def("AppendShifted", &BlockedVectorInt::AppendShifted, "source"_a, "shift"_a);

    if (true)
        {
        //===================================================================================
        // Enum BlockedVectorInt::IndexAction
        py::enum_<BlockedVectorInt::IndexAction>(c2, "IndexAction", py::arithmetic())
            .value("eNone", BlockedVectorInt::None)
            .value("eForcePositive", BlockedVectorInt::ForcePositive)
            .value("eForceNegative", BlockedVectorInt::ForceNegative)
            .value("eNegate", BlockedVectorInt::Negate)
            .export_values();
        }

    c2.def("__repr__", [] (BlockedVectorInt& self)
           {
           int minVal = 0, maxVal = 0;
           self.MinMax(minVal, maxVal);

           return "(numItems:{}, numZeros:{}, minValue:{}, maxValue:{})"_s.format(self.size(), self.CountZeros(), minVal, maxVal);
           });

    //===================================================================================
    // struct FacetLocationDetail
    py::class_<FacetLocationDetail> c3(m, "FacetLocationDetail");
    py::bind_vector<FacetLocationDetailArray>(m, "FacetLocationDetailArray", py::module_local(false));

    c3.def(py::init<>());
    c3.def(py::init<size_t, double>(), "readIndex"_a, "a"_a = 0.0);
    c3.def("Zero", &FacetLocationDetail::Zero, DOC(Bentley, Geom, FacetLocationDetail, Zero));

    c3.def("AccumulateScaledData", &FacetLocationDetail::AccumulateScaledData, "source"_a, "fraction"_a, DOC(Bentley, Geom, FacetLocationDetail, AccumulateScaledData));
    c3.def("TryGetPoint", &FacetLocationDetail::TryGetPoint, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetPoint));
    c3.def("TryGetParam", &FacetLocationDetail::TryGetParam, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetParam));
    c3.def("TryGetNormal", &FacetLocationDetail::TryGetNormal, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetNormal));
    c3.def("TryGetFloatColor", &FacetLocationDetail::TryGetFloatColor, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetFloatColor));
    c3.def("TryGetDoubleColor", &FacetLocationDetail::TryGetDoubleColor, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetDoubleColor));

    c3.def_property_readonly("NumWeights", &FacetLocationDetail::GetNumWeights);
    c3.def("GetNumWeights", &FacetLocationDetail::GetNumWeights, DOC(Bentley, Geom, FacetLocationDetail, GetNumWeights));

    c3.def("TryGetWeight", [] (FacetLocationDetailCR self, size_t index)
           {
           double weight = 0;
           bool bOk = self.TryGetWeight(index, weight);
           return py::make_tuple(bOk, weight);
           }, "index"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetWeight));

    c3.def("TryGetVertexIndex", [] (FacetLocationDetailCR self, size_t index)
           {
           size_t data = 0;
           bool bOk = self.TryGetVertexIndex(index, data);
           return py::make_tuple(bOk, data);
           }, "index"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetVertexIndex));

    c3.def("TryGetIntColor", [] (FacetLocationDetailCR self, size_t index)
           {
           uint32_t data = 0;
           bool bOk = self.TryGetIntColor(index, data);
           return py::make_tuple(bOk, data);
           }, "index"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetIntColor));

    c3.def("TryGetColorTable", [] (FacetLocationDetailCR self, size_t index)
           {
           uint32_t data = 0;
           bool bOk = self.TryGetColorTable(index, data);
           return py::make_tuple(bOk, data);
           }, "index"_a, DOC(Bentley, Geom, FacetLocationDetail, TryGetColorTable));

    c3.def_property("IsInterior", &FacetLocationDetail::GetIsInterior, &FacetLocationDetail::SetIsInterior);
    c3.def("GetIsInterior", &FacetLocationDetail::GetIsInterior, DOC(Bentley, Geom, FacetLocationDetail, GetIsInterior));
    c3.def("SetIsInterior", &FacetLocationDetail::SetIsInterior, "value"_a, DOC(Bentley, Geom, FacetLocationDetail, SetIsInterior));

    c3.def_property("ReadIndex", &FacetLocationDetail::GetReadIndex, &FacetLocationDetail::SetReadIndex);
    c3.def("GetReadIndex", &FacetLocationDetail::GetReadIndex, DOC(Bentley, Geom, FacetLocationDetail, GetReadIndex));
    c3.def("SetReadIndex", &FacetLocationDetail::SetReadIndex, "readIndex"_a, DOC(Bentley, Geom, FacetLocationDetail, SetReadIndex));

    c3.def("SetNormal", &FacetLocationDetail::SetNormal, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, SetNormal));
    c3.def("SetParam", &FacetLocationDetail::SetParam, "data"_a);
    c3.def("SetDoubleColor", &FacetLocationDetail::SetDoubleColor, "data"_a);
    c3.def("SetFloatColor", &FacetLocationDetail::SetFloatColor, "data"_a);
    c3.def("CompareUV", &FacetLocationDetail::CompareUV, "other"_a, DOC(Bentley, Geom, FacetLocationDetail, CompareUV));
    c3.def_static("SortUV", &FacetLocationDetail::SortUV, "data"_a, DOC(Bentley, Geom, FacetLocationDetail, SortUV));

    //===================================================================================
    // struct FacetLocationDetailPair
    py::class_< FacetLocationDetailPair> c4(m, "FacetLocationDetailPair");

    c4.def(py::init<>());
    c4.def_readwrite("detailA", &FacetLocationDetailPair::detailA);
    c4.def_readwrite("detailB", &FacetLocationDetailPair::detailB);

    //===================================================================================
    // struct FacetLocationDetailPairWithIndices
    py::class_< FacetLocationDetailPairWithIndices, FacetLocationDetailPair> c5(m, "FacetLocationDetailPairWithIndices");

    c5.def(py::init<size_t>(), "defaultIndex"_a);
    c5.def(py::init<FacetLocationDetailCR, FacetLocationDetailCR, size_t, size_t>(), "detailA"_a, "detailB"_a, "indexA"_a, "indexB"_a);
    c5.def_readwrite("indexA", &FacetLocationDetailPairWithIndices::indexA);
    c5.def_readwrite("indexB", &FacetLocationDetailPairWithIndices::indexB);

    //===================================================================================
    // struct PolyfaceEdgeChain
    py::class_< PolyfaceEdgeChain> c6(m, "PolyfaceEdgeChain");
    py::bind_vector< PolyfaceEdgeChainArray >(m, "PolyfaceEdgeChainArray", py::module_local(false));
    bind_BlockedVector<PolyfaceEdgeChain>(m, "BlockedVectorPolyfaceEdgeChain", py::module_local(false));

    c6.def(py::init<>());
    c6.def(py::init<CurveTopologyIdCR>(), "id"_a);
    c6.def(py::init<CurveTopologyIdCR, int32_t, int32_t>(), "id"_a, "index0"_a, "index1"_a);
    c6.def("AddIndex", &PolyfaceEdgeChain::AddIndex, "index"_a, DOC(Bentley, Geom, PolyfaceEdgeChain, AddIndex));
    c6.def("AddZeroBasedIndices", &PolyfaceEdgeChain::AddZeroBasedIndices, "indices"_a, DOC(Bentley, Geom, PolyfaceEdgeChain, AddZeroBasedIndices));

    c6.def_property_readonly("Id", &PolyfaceEdgeChain::GetId);
    c6.def("GetId", &PolyfaceEdgeChain::GetId, DOC(Bentley, Geom, PolyfaceEdgeChain, GetId));

    c6.def_property_readonly("IndexCount", &PolyfaceEdgeChain::GetIndexCount);
    c6.def("GetIndexCount", &PolyfaceEdgeChain::GetIndexCount, DOC(Bentley, Geom, PolyfaceEdgeChain, GetIndexCount));

    c6.def("GetIndex", [] (PolyfaceEdgeChain& self, Int32Array& indices)
           {
           size_t nItem = self.GetIndexCount();
           if (nItem > 0 && nullptr != self.GetIndexCP())
               {
               indices.resize(nItem);
               std::copy(self.GetIndexCP(), self.GetIndexCP() + nItem, indices.begin());
               }
           return nItem;
           });

    c6.def("__len__", &PolyfaceEdgeChain::GetIndexCount);
    c6.def("__getitem__", [] (PolyfaceEdgeChain& self, size_t iItem)
           {
           if (iItem >= self.GetIndexCount())
               throw py::index_error();
           return self.GetIndexCP()[iItem];
           });

    //===================================================================================
    // struct DirectionalVolumeData
    py::class_< DirectionalVolumeData> c7(m, "DirectionalVolumeData");

    c7.def(py::init<>());
    c7.def_readwrite("volume", &DirectionalVolumeData::volume);
    c7.def_readwrite("areaProducts", &DirectionalVolumeData::areaProducts);

    //===================================================================================
    // struct FacetCutFillHandler
    py::class_< FacetCutFillHandler, PyFacetCutFillHandler> c8(m, "FacetCutFillHandler");

    c8.def(py::init<>());
    c8.def("ContinueSearch", &FacetCutFillHandler::ContinueSearch, DOC(Bentley, Geom, FacetCutFillHandler, ContinueSearch));
    c8.def("ProcessCutFillFacet", &FacetCutFillHandler::ProcessCutFillFacet, "dtm"_a, "dtmReadIndex"_a, "road"_a, "roadReadIndex"_a, "roadBoundaryFlag"_a, "isCut"_a, DOC(Bentley, Geom, FacetCutFillHandler, ProcessCutFillFacet));
    c8.def("ProcessSideFacet", &FacetCutFillHandler::ProcessSideFacet, "points"_a, "isCut"_a);
    c8.def("Reset", &FacetCutFillHandler::Reset, DOC(Bentley, Geom, FacetCutFillHandler, Reset));    

    //===================================================================================
    // struct PolyfaceQuery
    py::class_<PolyfaceQuery, PolyfaceQueryPtr> c9(m, "PolyfaceQuery");

    if (true)
        {
        //===================================================================================
        // struct IClipToPlaneSetOutput
        py::class_<PolyfaceQuery::IClipToPlaneSetOutput, std::unique_ptr<PolyfaceQuery::IClipToPlaneSetOutput, py::nodelete>, IPyClipToPlaneSetOutput> c9_1(c9, "IClipToPlaneSetOutput");
        
        //c9_1.def(py::init<>());
        c9_1.def("_ProcessUnclippedPolyface", &PolyfaceQuery::IClipToPlaneSetOutput::_ProcessUnclippedPolyface, "polyfaceQuery"_a);
        c9_1.def("_ProcessClippedPolyface", &PolyfaceQuery::IClipToPlaneSetOutput::_ProcessClippedPolyface, "polyfaceHeader"_a);
        }

    c9.def("IsVariableSizeIndexed", &PolyfaceQuery::IsVariableSizeIndexed, DOC(Bentley, Geom, PolyfaceQuery, IsVariableSizeIndexed));
    
    c9.def_property_readonly("PointCount", &PolyfaceQuery::GetPointCount);
    c9.def("GetPointCount", &PolyfaceQuery::GetPointCount, DOC(Bentley, Geom, PolyfaceQuery, GetPointCount));
    
    c9.def_property_readonly("NormalCount", &PolyfaceQuery::GetNormalCount);
    c9.def("GetNormalCount", &PolyfaceQuery::GetNormalCount, DOC(Bentley, Geom, PolyfaceQuery, GetNormalCount));
    
    c9.def_property_readonly("ParamCount", &PolyfaceQuery::GetParamCount);
    c9.def("GetParamCount", &PolyfaceQuery::GetParamCount, DOC(Bentley, Geom, PolyfaceQuery, GetParamCount));
    
    c9.def_property_readonly("ColorCount", &PolyfaceQuery::GetColorCount);
    c9.def("GetColorCount", &PolyfaceQuery::GetColorCount, DOC(Bentley, Geom, PolyfaceQuery, GetColorCount));
    
    c9.def_property_readonly("FaceCount", &PolyfaceQuery::GetFaceCount);
    c9.def("GetFaceCount", &PolyfaceQuery::GetFaceCount, DOC(Bentley, Geom, PolyfaceQuery, GetFaceCount));
    
    c9.def_property_readonly("PointIndexCount", &PolyfaceQuery::GetPointIndexCount);
    c9.def("GetPointIndexCount", &PolyfaceQuery::GetPointIndexCount, DOC(Bentley, Geom, PolyfaceQuery, GetPointIndexCount));
    
    c9.def_property_readonly("FaceIndexCount", &PolyfaceQuery::GetFaceIndexCount);
    c9.def("GetFaceIndexCount", &PolyfaceQuery::GetFaceIndexCount, DOC(Bentley, Geom, PolyfaceQuery, GetFaceIndexCount));
    
    c9.def_property_readonly("EdgeChainCount", &PolyfaceQuery::GetEdgeChainCount);
    c9.def("GetEdgeChainCount", &PolyfaceQuery::GetEdgeChainCount, DOC(Bentley, Geom, PolyfaceQuery, GetEdgeChainCount));

    c9.def("__repr__", [] (PolyfaceQuery& self)
           {
           return "(IsVariableSizeIndexed:{}, PointCount:{}, NormalCount:{}, ParamCount:{}, ColorCount:{}, FaceCount:{}, PointIndexCount:{}, FaceIndexCount:{}, EdgeChainCount:{})"_s
               .format(self.IsVariableSizeIndexed(), self.GetPointCount(), self.GetNormalCount(), self.GetParamCount(), self.GetColorCount(), self.GetFaceCount(), 
                       self.GetPointIndexCount(), self.GetFaceIndexCount(), self.GetEdgeChainCount());
           });

    c9.def("GetPointAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           DPoint3d point;
           if (index < self.GetPointCount() && nullptr != self.GetPointCP())
               {
               point = self.GetPointCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, point);
           }, "index"_a);

    c9.def("GetNormalAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           DVec3d normal;
           if (index < self.GetNormalCount() && nullptr != self.GetNormalCP())
               {
               normal = self.GetNormalCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, normal);
           }, "index"_a);

    c9.def("GetParamAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           DPoint2d param;
           if (index < self.GetParamCount() && nullptr != self.GetParamCP())
               {
               param = self.GetParamCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, param);
           }, "index"_a);

    c9.def("GetDoubleColorAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           RgbFactor color;
           if (index < self.GetColorCount() && nullptr != self.GetDoubleColorCP())
               {
               color = self.GetDoubleColorCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, color);
           }, "index"_a);

    c9.def("GetFloatColorAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           FloatRgb color;
           if (index < self.GetColorCount() && nullptr != self.GetFloatColorCP())
               {
               color = self.GetFloatColorCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, color);
           }, "index"_a);

    c9.def("GetIntColorAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           uint32_t color = 0;
           if (index < self.GetColorCount() && nullptr != self.GetIntColorCP())
               {
               color = self.GetIntColorCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, color);
           }, "index"_a);

    c9.def("GetColorTableAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           uint32_t color = 0;
           if (index < self.GetColorCount() && nullptr != self.GetColorTableCP())
               {
               color = self.GetColorTableCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, color);
           }, "index"_a);

    c9.def("GetFaceDataAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           FacetFaceData faceData;
           if (index < self.GetColorCount() && nullptr != self.GetFaceDataCP())
               {
               faceData = self.GetFaceDataCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, faceData);
           }, "index"_a);

    c9.def("GetIlluminationName", &PolyfaceQuery::GetIlluminationNameCP, py::return_value_policy::reference_internal);
    
    c9.def("GetEdgeChainAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           PolyfaceEdgeChain edgeChain;
           if (index < self.GetEdgeChainCount() && nullptr != self.GetEdgeChainCP())
               {
               edgeChain = self.GetEdgeChainCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, edgeChain);
           }, "index"_a);

    c9.def_property_readonly("TextureId", &PolyfaceQuery::GetTextureId);
    c9.def("GetTextureId", &PolyfaceQuery::GetTextureId, DOC(Bentley, Geom, PolyfaceQuery, GetTextureId));
    
    c9.def("GetPointIndexAt", [] (PolyfaceQueryCR self, size_t index)
           {
           bool bOk = false;
           int32_t ptIndex = -1;
           if (index < self.GetPointIndexCount() && nullptr != self.GetPointIndexCP())
               {
               ptIndex = self.GetPointIndexCP()[index];
               bOk = true;
               }
           return py::make_tuple(bOk, ptIndex);
           }, "index"_a);

    c9.def("GetColorIndexAt", [] (PolyfaceQueryCR self, size_t index, bool resolveToDefaults)
           {
           bool bOk = false;
           int32_t ptIndex = -1;
           if (index < self.GetPointIndexCount() && nullptr != self.GetColorIndexCP(resolveToDefaults))
               {
               ptIndex = self.GetColorIndexCP(resolveToDefaults)[index];
               bOk = true;
               }
           return py::make_tuple(bOk, ptIndex);
           }, "index"_a, "resolveToDefaults"_a = false);

    c9.def("GetParamIndexAt", [] (PolyfaceQueryCR self, size_t index, bool resolveToDefaults)
           {
           bool bOk = false;
           int32_t ptIndex = -1;
           if (index < self.GetPointIndexCount() && nullptr != self.GetParamIndexCP(resolveToDefaults))
               {
               ptIndex = self.GetParamIndexCP(resolveToDefaults)[index];
               bOk = true;
               }
           return py::make_tuple(bOk, ptIndex);
           }, "index"_a, "resolveToDefaults"_a = false);

    c9.def("GetNormalIndexAt", [] (PolyfaceQueryCR self, size_t index, bool resolveToDefaults)
           {
           bool bOk = false;
           int32_t ptIndex = -1;
           if (index < self.GetPointIndexCount() && nullptr != self.GetNormalIndexCP(resolveToDefaults))
               {
               ptIndex = self.GetNormalIndexCP(resolveToDefaults)[index];
               bOk = true;
               }
           return py::make_tuple(bOk, ptIndex);
           }, "index"_a, "resolveToDefaults"_a = false);

    c9.def("GetFaceIndexAt", [] (PolyfaceQueryCR self, size_t index, bool resolveToDefaults)
           {
           bool bOk = false;
           int32_t ptIndex = -1;
           if (index < self.GetFaceIndexCount() && nullptr != self.GetFaceIndexCP(resolveToDefaults))
               {
               ptIndex = self.GetFaceIndexCP(resolveToDefaults)[index];
               bOk = true;
               }
           return py::make_tuple(bOk, ptIndex);
           }, "index"_a, "resolveToDefaults"_a = false);

    c9.def_property_readonly("TwoSided", &PolyfaceQuery::GetTwoSided);
    c9.def("GetTwoSided", &PolyfaceQuery::GetTwoSided, DOC(Bentley, Geom, PolyfaceQuery, GetTwoSided));
    
    c9.def_property_readonly("NumPerFace", &PolyfaceQuery::GetNumPerFace);
    c9.def("GetNumPerFace", &PolyfaceQuery::GetNumPerFace, DOC(Bentley, Geom, PolyfaceQuery, GetNumPerFace));
    
    c9.def_property_readonly("NumPerRow", &PolyfaceQuery::GetNumPerRow);
    c9.def("GetNumPerRow", &PolyfaceQuery::GetNumPerRow, DOC(Bentley, Geom, PolyfaceQuery, GetNumPerRow));
    
    c9.def_property_readonly("MeshStyle", &PolyfaceQuery::GetMeshStyle);
    c9.def("GetMeshStyle", &PolyfaceQuery::GetMeshStyle, DOC(Bentley, Geom, PolyfaceQuery, GetMeshStyle));

    c9.def("TryGetPointAtReadIndex", &PolyfaceQuery::TryGetPointAtReadIndex, "readIndex"_a, "data"_a, DOC(Bentley, Geom, PolyfaceQuery, TryGetPointAtReadIndex));
    c9.def("TryGetNormalAtReadIndex", &PolyfaceQuery::TryGetNormalAtReadIndex, "readIndex"_a, "data"_a, DOC(Bentley, Geom, PolyfaceQuery, TryGetNormalAtReadIndex));
    c9.def("TryGetParamAtReadIndex", &PolyfaceQuery::TryGetParamAtReadIndex, "readIndex"_a, "data"_a, DOC(Bentley, Geom, PolyfaceQuery, TryGetParamAtReadIndex));

    c9.def("TryGetFacetFaceDataAtReadIndex", [] (PolyfaceQueryCR self, size_t readIndex, FacetFaceDataR data)
           {
           size_t zeroBasedIndex = 0;
           bool bOk = self.TryGetFacetFaceDataAtReadIndex(readIndex, data, zeroBasedIndex);
           return py::make_tuple(bOk, zeroBasedIndex);
           }, "readIndex"_a, "data"_a);

    c9.def("Clone", &PolyfaceQuery::Clone, DOC(Bentley, Geom, PolyfaceQuery, Clone));
    c9.def("CloneAsVariableSizeIndexed", py::overload_cast<>(&PolyfaceQuery::CloneAsVariableSizeIndexed, py::const_), DOC(Bentley, Geom, PolyfaceQuery, CloneAsVariableSizeIndexed));

    c9.def("InspectFaces", [] (PolyfaceQueryCR self)
           {
           size_t numLoop, minPerLoop, maxPerLoop;
           bool hasNonPlanarFaces, hasNonConvexFaces;
           self.InspectFaces(numLoop, minPerLoop, maxPerLoop, hasNonPlanarFaces, hasNonConvexFaces);
           return py::make_tuple(numLoop, minPerLoop, maxPerLoop, hasNonPlanarFaces, hasNonConvexFaces);
           });

    c9.def("ValidatedVolume", &PolyfaceQuery::ValidatedVolume, DOC(Bentley, Geom, PolyfaceQuery, ValidatedVolume));
    c9.def("SumTetrahedralVolumes", &PolyfaceQuery::SumTetrahedralVolumes, "origin"_a, DOC(Bentley, Geom, PolyfaceQuery, SumTetrahedralVolumes));

    c9.def("SumDirectedAreas", [] (PolyfaceQueryCR self, DVec3dCR vectorToEye)
           {
           size_t numPositive, numPerpendicular, numNegative;
           double area = self.SumDirectedAreas(vectorToEye, numPositive, numPerpendicular, numNegative);
           return py::make_tuple(area, numPositive, numPerpendicular, numNegative);
           }, "vectorToEye"_a);

    c9.def("SumDirectedAreasDetailed", [] (PolyfaceQueryCR self, DVec3dCR vectorToEye)
           {
           size_t numPositive, numPerpendicular, numNegative;
           double forwardProjectedSum, reverseProjectedSum, forwardAbsoluteSum, reverseAbsoluteSum, perpendicularAbsoluteSum;
           double area = self.SumDirectedAreas(vectorToEye, numPositive, numPerpendicular, numNegative,
                                            forwardProjectedSum, reverseProjectedSum, forwardAbsoluteSum, reverseAbsoluteSum, perpendicularAbsoluteSum);
           return py::make_tuple(area, numPositive, numPerpendicular, numNegative,
                                  forwardProjectedSum, reverseProjectedSum, forwardAbsoluteSum, reverseAbsoluteSum, perpendicularAbsoluteSum);
           }, "vectorToEye"_a);

    c9.def("SumTetrahedralFirstMoments", &PolyfaceQuery::SumTetrahedralFirstMoments, "origin"_a, "moments"_a, DOC(Bentley, Geom, PolyfaceQuery, SumTetrahedralFirstMoments));

    c9.def("SumTetrahedralMomentProducts", [] (PolyfaceQueryCR self, TransformCR worldToLocal, DVec3dR moment1, RotMatrixR products)
           {
           double volume = 0;
           self.SumTetrahedralMomentProducts(worldToLocal, volume, moment1, products);
           return volume;
           }, "worldToLocal"_a, "moment1"_a, "products"_a);

    c9.def("ComputePrincipalMoments", [] (PolyfaceQueryCR self, DPoint3dR centroid, RotMatrixR axes, DVec3dR momentxyz, bool forcePositiveVolume)
           {
           double volume = 0;
           bool bOk = self.ComputePrincipalMoments(volume, centroid, axes, momentxyz, forcePositiveVolume);
           return py::make_tuple(bOk, volume);
           }, "centroid"_a, "axes"_a, "momentxyz"_a, "forcePositiveVolume"_a = false);

    c9.def("SumFacetAreas", &PolyfaceQuery::SumFacetAreas, DOC(Bentley, Geom, PolyfaceQuery, SumFacetAreas));
    c9.def("SumFacetFirstAreaMoments", &PolyfaceQuery::SumFacetFirstAreaMoments, "origin"_a, "moments1"_a, DOC(Bentley, Geom, PolyfaceQuery, SumFacetFirstAreaMoments));
    c9.def("SumFacetSecondAreaMomentProducts", &PolyfaceQuery::SumFacetSecondAreaMomentProducts, "origin"_a, "products"_a, DOC(Bentley, Geom, PolyfaceQuery, SumFacetSecondAreaMomentProducts));

    c9.def("ComputePrincipalAreaMoments", [] (PolyfaceQueryCR self, DPoint3dR centroid, RotMatrixR axes, DVec3dR momentxyz)
           {
           double area = 0;
           bool bOk = self.ComputePrincipalAreaMoments(area, centroid, axes, momentxyz);
           return py::make_tuple(bOk, area);
           }, "centroid"_a, "axes"_a, "momentxyz"_a);

    c9.def("PointRange", &PolyfaceQuery::PointRange, DOC(Bentley, Geom, PolyfaceQuery, PointRange));

    c9.def_property_readonly("TightTolerance", &PolyfaceQuery::GetTightTolerance);
    c9.def("GetTightTolerance", &PolyfaceQuery::GetTightTolerance, DOC(Bentley, Geom, PolyfaceQuery, GetTightTolerance));
    
    c9.def_property_readonly("MediumTolerance", &PolyfaceQuery::GetMediumTolerance);
    c9.def("GetMediumTolerance", &PolyfaceQuery::GetMediumTolerance, DOC(Bentley, Geom, PolyfaceQuery, GetMediumTolerance));
    
    c9.def("ParamRange", &PolyfaceQuery::ParamRange, DOC(Bentley, Geom, PolyfaceQuery, ParamRange));
    c9.def("ReverseIndicesOneFace", &PolyfaceQuery::ReverseIndicesOneFace, "iFirst"_a, "iLast"_a, "normalArrayIndexAction"_a = BlockedVectorInt::None, DOC(Bentley, Geom, PolyfaceQuery, ReverseIndicesOneFace));
    c9.def("ReverseIndicesAllFaces", &PolyfaceQuery::ReverseIndicesAllFaces,
           "negateNormals"_a = true, "flipMarked"_a = true, "flipUnMarked"_a = true, "normalIndexAction"_a = BlockedVectorInt::None);

    c9.def("CountSharedEdges", [] (PolyfaceQueryCR self, bool ignoreSliverFaces)
           {
           size_t numPolygonEdge, numMatedPair, num1, num2, num3, num4, numMore, numCollapsed, numWith0Visible, numWith1orMoreVisible;
           self.CountSharedEdges(numPolygonEdge, numMatedPair, num1, num2, num3, num4, numMore, numCollapsed, ignoreSliverFaces, numWith0Visible, numWith1orMoreVisible);
           return py::make_tuple(numPolygonEdge, numMatedPair, num1, num2, num3, num4, numMore, numCollapsed, numWith0Visible, numWith1orMoreVisible);
           }, "ignoreSliverFaces"_a);

    c9.def("CollectCounts", [] (PolyfaceQueryCR self)
           {
           size_t numVertex, numFacet, numQuad, numTriangle, numImplicitTriangle, numVisibleEdges, numInvisibleEdges;
           self.CollectCounts(numVertex, numFacet, numQuad, numTriangle, numImplicitTriangle, numVisibleEdges, numInvisibleEdges);
           return py::make_tuple(numVertex, numFacet, numQuad, numTriangle, numImplicitTriangle, numVisibleEdges, numInvisibleEdges);
           });

    c9.def("CollectPerFaceCounts", [] (PolyfaceQueryCR self)
           {
           size_t minPerFaces, maxPerFace;
           self.CollectPerFaceCounts(minPerFaces, maxPerFace);
           return py::make_tuple(minPerFaces, maxPerFace);
           });

    c9.def("CollectSegments", &PolyfaceQuery::CollectSegments, "segments"_a, "omitInvisible"_a, DOC(Bentley, Geom, PolyfaceQuery, CollectSegments));
    c9.def("PlaneSlice", py::overload_cast<DPlane3dCR, bool, bool >(&PolyfaceQuery::PlaneSlice, py::const_),
        "sectionPlane"_a, "formRegions"_a, "markEdgeFraction"_a = false, DOC(Bentley, Geom, PolyfaceQuery, PlaneSlice));

    c9.def("PlaneSlice", py::overload_cast<DPlane3dCR, bool, bool, bool>(&PolyfaceQuery::PlaneSlice, py::const_),
        "sectionPlane"_a, "formRegions"_a, "markEdgeFractions"_a, "skipOnPlaneFacets"_a, DOC(Bentley, Geom, PolyfaceQuery, PlaneSlice));

    c9.def("DrapeLinestring", &PolyfaceQuery::DrapeLinestring, "spacePoints"_a, "direction"_a, DOC(Bentley, Geom, PolyfaceQuery, DrapeLinestring));
    c9.def("IsClosedByEdgePairing", &PolyfaceQuery::IsClosedByEdgePairing, DOC(Bentley, Geom, PolyfaceQuery, IsClosedByEdgePairing));
    c9.def("HasFacets", &PolyfaceQuery::HasFacets, DOC(Bentley, Geom, PolyfaceQuery, HasFacets));
    c9.def("IsTriangulated", &PolyfaceQuery::IsTriangulated, DOC(Bentley, Geom, PolyfaceQuery, IsTriangulated));

    c9.def("GetNumFacet", [] (PolyfaceQueryCR self)
           {
           size_t maxVertexPerFacet = 0;
           size_t numFacets = self.GetNumFacet(maxVertexPerFacet);
           return py::make_tuple(numFacets, maxVertexPerFacet);
           });

    c9.def("HasConvexFacets", &PolyfaceQuery::HasConvexFacets, DOC(Bentley, Geom, PolyfaceQuery, HasConvexFacets));
    c9.def("LargestCoordinate", &PolyfaceQuery::LargestCoordinate, DOC(Bentley, Geom, PolyfaceQuery, LargestCoordinate));
    c9.def("EnsureFloatColor", &PolyfaceQuery::EnsureFloatColor, DOC(Bentley, Geom, PolyfaceQuery, EnsureFloatColor));
    c9.def("TryEvaluateEdge", &PolyfaceQuery::TryEvaluateEdge, "position"_a, "xyz"_a, DOC(Bentley, Geom, PolyfaceQuery, TryEvaluateEdge));
    c9.def("SweepLinestringToMesh", &PolyfaceQuery::SweepLinestringToMesh, "xyzOut"_a, "linestringIndexOut"_a, "meshIndexOut"_a, "linestringPoints"_a, "sweepDirection"_a, DOC(Bentley, Geom, PolyfaceQuery, SweepLinestringToMesh));

    c9.def("ClipToPlaneSetIntersection", &PolyfaceQuery::ClipToPlaneSetIntersection, "planeSets"_a, "output"_a, "trangulateOutput"_a, DOC(Bentley, Geom, PolyfaceQuery, ClipToPlaneSetIntersection));
    c9.def("ClusteredVertexDecimate", &PolyfaceQuery::ClusteredVertexDecimate, "tolerance"_a, DOC(Bentley, Geom, PolyfaceQuery, ClusteredVertexDecimate));

    c9.def("AddToTaggedPolygons",
           py::overload_cast<TaggedPolygonVectorR, ptrdiff_t, size_t, DRange3dCP>(&PolyfaceQuery::AddToTaggedPolygons, py::const_),
           "polygons"_a, "indexA"_a, "numWrap"_a, "selectRange"_a = nullptr);

    c9.def("AddToTaggedPolygons",
           py::overload_cast<TaggedPolygonVectorR, ptrdiff_t, size_t, Bentley::IPolyfaceVisitorFilter*>(&PolyfaceQuery::AddToTaggedPolygons, py::const_),
           "polygons"_a, "indexA"_a, "numWrap"_a, "filer"_a);

    c9.def_static("ComputeUndercut", &PolyfaceQuery::ComputeUndercut, "polyfaceA"_a, "filterA"_a, "polyfaceB"_a, "filterB"_a, "undercutPolyface"_a, DOC(Bentley, Geom, PolyfaceQuery, ComputeUndercut));

    c9.def_static("ComputeOverAndUnderXY", &PolyfaceQuery::ComputeOverAndUnderXY,
           "polyfaceA"_a, "filterA"_a, "polyfaceB"_a, "filterB"_a, "polyfaceAOverB"_a, "polyfaceBUnderA"_a, "computeAndApplyTransform"_a = true);

    c9.def_static("ComputePunch", &PolyfaceQuery::ComputePunch, "punch"_a, "target"_a, "keepInside"_a, "result"_a, DOC(Bentley, Geom, PolyfaceQuery, ComputePunch));
    c9.def_static("ComputePunchXYByPlaneSets", &PolyfaceQuery::ComputePunchXYByPlaneSets, "punch"_a, "target"_a, "inside"_a, "outside"_a, "debugMesh"_a = nullptr, DOC(Bentley, Geom, PolyfaceQuery, ComputePunchXYByPlaneSets));
    c9.def_static("ClipPolyfaceToClipPlanes", [](PolyfaceHeaderPtr& insideClip,
                                                 PolyfaceHeaderPtr* outsideClip,
                                                 PolyfaceQueryCR targetMesh,
                                                 ClipPlaneSetR clipPlanes,
                                                 bool formNewFacesOnClipPlanes)
           {
           bool resultHasIncompleteCutPlaneFaces = false;
           PolyfaceQuery::ClipPolyfaceToClipPlanes(insideClip, outsideClip, resultHasIncompleteCutPlaneFaces, targetMesh, clipPlanes, formNewFacesOnClipPlanes);
           return resultHasIncompleteCutPlaneFaces;
           }, "insideClip"_a, "outsideClip"_a, "targetMesh"_a, "clipPlanes"_a, "formNewFacesOnClipPlanes"_a);

    c9.def_static("HealVerticalPanels", &PolyfaceQuery::HealVerticalPanels, "polyface"_a, "tryVerticalPanels"_a, "trySpaceTriangulation"_a, "healedPolyface"_a, DOC(Bentley, Geom, PolyfaceQuery, HealVerticalPanels));
    c9.def("DirectionalVolumeIntegrals", &PolyfaceQuery::DirectionalVolumeIntegrals, "polyface"_a, "pData"_a, "directionalProducts"_a, "origin"_a, DOC(Bentley, Geom, PolyfaceQuery, DirectionalVolumeIntegrals));

    c9.def("ComputePrincipalMomentsAllowMissingSideFacets", [](PolyfaceQueryCR self,
                                                               DPoint3dR centroid,
                                                               RotMatrixR axes,
                                                               DVec3dR momentxyz,
                                                               bool forcePositiveVolume,
                                                               double relativeTolerance)
           {
           double volume = 0;
           bool bOk = self.ComputePrincipalMomentsAllowMissingSideFacets(volume, centroid, axes, momentxyz, forcePositiveVolume, relativeTolerance);
           return py::make_tuple(bOk, volume);
           }, "centroid"_a, "axes"_a, "momentxyz"_a, "forcePositiveVolume"_a, "relativeTolerance"_a = 1.0e-8);

    c9.def("DirectionalAreaAndVolume", &PolyfaceQuery::DirectionalAreaAndVolume, "origin"_a, "areaXYZ"_a, "volumeXYZ"_a, "centroidX"_a, "centroidY"_a, "centroidZ"_a, DOC(Bentley, Geom, PolyfaceQuery, DirectionalAreaAndVolume));
    c9.def("PickFacetsByStroke", &PolyfaceQuery::PickFacetsByStroke, "eyePoint"_a, "point0"_a, "point1"_a, "pickDetail"_a, "exitAfterFirstPick"_a, DOC(Bentley, Geom, PolyfaceQuery, PickFacetsByStroke));
     
    c9.def_static("MergeAndCollectVolumes",
                  py::overload_cast<PolyfaceQueryR, PolyfaceQueryR, PolyfaceHeaderArray&>(&PolyfaceQuery::MergeAndCollectVolumes),
                  "meshA"_a, "meshB"_a, "enclosedVolumes"_a);

    c9.def_static("MergeAndCollectVolumes", [](PolyfaceQueryR meshA, PolyfaceQueryR meshB, py::list& enclosedVolumes) {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(enclosedVolumes, cppEnclosedVolumes, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                  PolyfaceQuery::MergeAndCollectVolumes(meshA, meshB, cppEnclosedVolumes);
                  CONVERT_CPPARRAY_TO_PYLIST(enclosedVolumes, cppEnclosedVolumes, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                }, "meshA"_a, "meshB"_a, "enclosedVolumes"_a);
                
    c9.def_static("MergeAndCollectVolumes",
                  py::overload_cast<PolyfaceHeaderArray&, PolyfaceHeaderArray&>(&PolyfaceQuery::MergeAndCollectVolumes),
                  "inputMesh"_a, "enclosedVolumes"_a);

    c9.def_static("MergeAndCollectVolumes", [](py::list& inputMesh, PolyfaceHeaderArray& enclosedVolumes) {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(inputMesh, cppInputMesh, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                  PolyfaceQuery::MergeAndCollectVolumes(cppInputMesh, enclosedVolumes);
                  CONVERT_CPPARRAY_TO_PYLIST(inputMesh, cppInputMesh, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                }, "inputMesh"_a, "enclosedVolumes"_a);

    c9.def_static("MergeAndCollectVolumes", [](PolyfaceHeaderArray& inputMesh, py::list& enclosedVolumes) {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(enclosedVolumes, cppEnclosedVolumes, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                  PolyfaceQuery::MergeAndCollectVolumes(inputMesh, cppEnclosedVolumes);
                  CONVERT_CPPARRAY_TO_PYLIST(enclosedVolumes, cppEnclosedVolumes, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                }, "inputMesh"_a, "enclosedVolumes"_a);

    c9.def_static("MergeAndCollectVolumes", [](py::list& inputMesh, py::list& enclosedVolumes) {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(inputMesh, cppInputMesh, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(enclosedVolumes, cppEnclosedVolumes, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                  PolyfaceQuery::MergeAndCollectVolumes(cppInputMesh, cppEnclosedVolumes);
                  CONVERT_CPPARRAY_TO_PYLIST(enclosedVolumes, cppEnclosedVolumes, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                  CONVERT_CPPARRAY_TO_PYLIST(inputMesh, cppInputMesh, PolyfaceHeaderArray, PolyfaceHeaderPtr);
                }, "inputMesh"_a, "enclosedVolumes"_a);

    c9.def_static("SelectMeshesByVolumeSign", &PolyfaceQuery::SelectMeshesByVolumeSign,
                  "inputVolumes"_a, "negativeVolumeMeshes"_a, "zeroVolumeMeshes"_a, "positiveVolumeMeshes"_a);

    c9.def_static("SearchClosestApproach",
                  py::overload_cast<PolyfaceQueryR, PolyfaceQueryR, double, DSegment3dR>(&PolyfaceQuery::SearchClosestApproach),
                  "polyfaceA"_a, "polyfaceB"_a, "maxDistance"_a, "segment"_a);

    c9.def_static("SearchClosestApproach",
                  py::overload_cast<PolyfaceQueryR, double, DSegment3dR, double>(&PolyfaceQuery::SearchClosestApproach),
                  "polyfaceA"_a, "maxDistance"_a, "segment"_a, "normalTestRadius"_a);

    c9.def_static("SearchClosestApproach",
                  py::overload_cast<PolyfaceQueryR, double, DSegment3dR>(&PolyfaceQuery::SearchClosestApproach),
                  "polyfaceA"_a, "maxDistance"_a, "segment"_a);

    c9.def_static("SearchClosestApproachToLinestring", &PolyfaceQuery::SearchClosestApproachToLinestring,
                  "polyfaceA"_a, "points"_a, "segment"_a);

    c9.def("IsSameStructureAndGeometry", &PolyfaceQuery::IsSameStructureAndGeometry, "other"_a, "tolerance"_a, DOC(Bentley, Geom, PolyfaceQuery, IsSameStructureAndGeometry));
    c9.def("HasIndexErrors", py::overload_cast<MeshAnnotationVector&>(&PolyfaceQuery::HasIndexErrors), "descripton"_a, DOC(Bentley, Geom, PolyfaceQuery, HasIndexErrors));
    c9.def("HasIndexErrors", py::overload_cast<>(&PolyfaceQuery::HasIndexErrors), DOC(Bentley, Geom, PolyfaceQuery, HasIndexErrors));

    //===================================================================================
    // struct PolyfaceQueryCarrier
    py::class_< PolyfaceQueryCarrier, PolyfaceQuery> c10(m, "PolyfaceQueryCarrier");

    //===================================================================================
    // struct PolyfaceVectors
    py::class_<PolyfaceVectors, std::unique_ptr<PolyfaceVectors, py::nodelete>, PolyfaceQuery> c11(m, "PolyfaceVectors");

    c11.def("CopyAllActiveFlagsFrom", &PolyfaceVectors::CopyAllActiveFlagsFrom, "source"_a, DOC(Bentley, Geom, PolyfaceVectors, CopyAllActiveFlagsFrom));
    c11.def("ClearAllArrays", &PolyfaceVectors::ClearAllArrays, DOC(Bentley, Geom, PolyfaceVectors, ClearAllArrays));
    c11.def("CopyAllActiveFlagsFromQuery", &PolyfaceVectors::CopyAllActiveFlagsFromQuery, "source"_a, DOC(Bentley, Geom, PolyfaceVectors, CopyAllActiveFlagsFromQuery));
    c11.def("SetTwoSided", &PolyfaceVectors::SetTwoSided, "twoSided"_a, DOC(Bentley, Geom, PolyfaceVectors, SetTwoSided));
    c11.def("SetNumPerFace", &PolyfaceVectors::SetNumPerFace, "numPerFace"_a, DOC(Bentley, Geom, PolyfaceVectors, SetNumPerFace));
    c11.def("SetNumPerRow", &PolyfaceVectors::SetNumPerRow, "numPerRow"_a, DOC(Bentley, Geom, PolyfaceVectors, SetNumPerRow));
    c11.def("SetMeshStyle", &PolyfaceVectors::SetMeshStyle, "meshStyle"_a, DOC(Bentley, Geom, PolyfaceVectors, SetMeshStyle));
    c11.def("FindOrAddColorTable", &PolyfaceVectors::FindOrAddColorTable, "tableIndex"_a, DOC(Bentley, Geom, PolyfaceVectors, FindOrAddColorTable));

    //===================================================================================
    // struct IndexedParameterMap
    py::class_<IndexedParameterMap> c12(m, "IndexedParameterMap");

    c12.def(py::init<>());
    c12.def_readwrite("index0", &IndexedParameterMap::index0);
    c12.def_readwrite("index1", &IndexedParameterMap::index1);
    c12.def_readwrite("index2", &IndexedParameterMap::index2);
    c12.def_readwrite("worldToLocal", &IndexedParameterMap::worldToLocal);
    c12.def_readwrite("localToWorld", &IndexedParameterMap::localToWorld);

    c12.def("ConstructMapping", &IndexedParameterMap::ConstructMapping, "points"_a, DOC(Bentley, Geom, IndexedParameterMap, ConstructMapping));
    c12.def("MapPoint2d", &IndexedParameterMap::MapPoint2d, "xyz"_a, "params"_a);
    c12.def("MapDVec3d", &IndexedParameterMap::MapDVec3d, "xyz"_a, "normals"_a);

    //===================================================================================
    // struct PolyfaceHeader
    py::class_<PolyfaceHeader, PolyfaceVectors> c13(m, "PolyfaceHeader", py::multiple_inheritance());
    py::bind_vector<bvector< PolyfaceHeaderPtr>>(m, "PolyfaceHeaderPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // Enum FacetTranslationMode
        py::enum_<PolyfaceHeader::FacetTranslationMode>(c13, "FacetTranslationMode", py::arithmetic())
            .value("eJustTranslatePoints", PolyfaceHeader::JustTranslatePoints)
            .value("eTranslatePointsAndAddSweepFaces", PolyfaceHeader::TranslatePointsAndAddSweepFaces)
            .value("eTranslatePointsAndTriangulateFringeFaces", PolyfaceHeader::TranslatePointsAndTriangulateFringeFaces)
            .export_values();

        //===================================================================================
        // struct OffsetOptions
        py::class_<PolyfaceHeader::OffsetOptions>(c13, "OffsetOptions")
            .def(py::init<>())
            .def_readwrite("maxSingleEdgeAngle", &PolyfaceHeader::OffsetOptions::m_maxSingleEdgeAngle)
            .def_readwrite("maxAccumulatedAngle", &PolyfaceHeader::OffsetOptions::m_maxAccumulatedAngle)
            .def_readwrite("maxChamferAngle", &PolyfaceHeader::OffsetOptions::m_maxChamferAngle)
            .def_readwrite("useStoredNormals", &PolyfaceHeader::OffsetOptions::m_useStoredNormals);

        //===================================================================================
        // Enum ComputeSingleSheetOption
        py::enum_<PolyfaceHeader::ComputeSingleSheetOption>(c13, "ComputeSingleSheetOption", py::arithmetic())
            .value("eBoth", PolyfaceHeader::Both)
            .value("eCutMeshOnly", PolyfaceHeader::CutMeshOnly)
            .value("eFillMeshOnly", PolyfaceHeader::FillMeshOnly)
            .export_values();
        }

    c13.def("Compress", py::overload_cast<>(&PolyfaceHeader::Compress), DOC(Bentley, Geom, PolyfaceHeader, Compress));
    c13.def("Compress", py::overload_cast<double, double, double, double>(&PolyfaceHeader::Compress), "pointAbsTol"_a, "normalAbsTol"_a = -1.0, "paramAbsTol"_a = -1.0, "relTol"_a = -1.0, DOC(Bentley, Geom, PolyfaceHeader, Compress));
    c13.def("ClearTags", &PolyfaceHeader::ClearTags, "numPerFace"_a, "meshStyle"_a, DOC(Bentley, Geom, PolyfaceHeader, ClearTags));

    c13.def("AddIndexedFacet",
            py::overload_cast<Int32Array&, Int32Array*, Int32Array*, Int32Array*>(&PolyfaceHeader::AddIndexedFacet),
            "pointIndices"_a, "normalIndices"_a, "paramIndices"_a, "colorIndices"_a);

    c13.def("SetIlluminationName", &PolyfaceHeader::SetIlluminationName, "name"_a, DOC(Bentley, Geom, PolyfaceHeader, SetIlluminationName));
    c13.def("SetTextureId", &PolyfaceHeader::SetTextureId, "id"_a, DOC(Bentley, Geom, PolyfaceHeader, SetTextureId));

    c13.def("Point", &PolyfaceHeader::Point, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, Point));
    c13.def("Param", &PolyfaceHeader::Param, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, Param));
    c13.def("Normal", &PolyfaceHeader::Normal, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, Normal));
    c13.def("DoubleColor", &PolyfaceHeader::DoubleColor, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, DoubleColor));
    c13.def("IntColor", &PolyfaceHeader::IntColor, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, IntColor));
    c13.def("ColorTable", &PolyfaceHeader::ColorTable, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, ColorTable));
    c13.def("FloatColor", &PolyfaceHeader::FloatColor, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, FloatColor));
    c13.def("PointIndex", &PolyfaceHeader::PointIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, PointIndex));
    c13.def("ParamIndex", &PolyfaceHeader::ParamIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, ParamIndex));
    c13.def("NormalIndex", &PolyfaceHeader::NormalIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, NormalIndex));
    c13.def("ColorIndex", &PolyfaceHeader::ColorIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, ColorIndex));
    c13.def("IlluminationName", &PolyfaceHeader::IlluminationName, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, IlluminationName));
    c13.def("FaceIndex", &PolyfaceHeader::FaceIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, FaceIndex));
    c13.def("FaceData", &PolyfaceHeader::FaceData, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, FaceData));
    c13.def("EdgeChain", &PolyfaceHeader::EdgeChain, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceHeader, EdgeChain));

    c13.def("ClearAllIndexVectors", &PolyfaceHeader::ClearAllIndexVectors, DOC(Bentley, Geom, PolyfaceHeader, ClearAllIndexVectors));
    c13.def("ClearAllVectors", &PolyfaceHeader::ClearAllVectors, DOC(Bentley, Geom, PolyfaceHeader, ClearAllVectors));
    c13.def("TerminateAllActiveIndexVectors", &PolyfaceHeader::TerminateAllActiveIndexVectors, DOC(Bentley, Geom, PolyfaceHeader, TerminateAllActiveIndexVectors));
    c13.def("ActivateVectorsForIndexing", &PolyfaceHeader::ActivateVectorsForIndexing, "source"_a, DOC(Bentley, Geom, PolyfaceHeader, ActivateVectorsForIndexing));
    c13.def("ActivateVectorsForPolylineIndexing", &PolyfaceHeader::ActivateVectorsForPolylineIndexing, "source"_a, DOC(Bentley, Geom, PolyfaceHeader, ActivateVectorsForPolylineIndexing));
    c13.def("SetActiveFlagsByAvailableData", &PolyfaceHeader::SetActiveFlagsByAvailableData, DOC(Bentley, Geom, PolyfaceHeader, SetActiveFlagsByAvailableData));
    c13.def("ConvertToVariableSizeSignedOneBasedIndexedFaceLoops", &PolyfaceHeader::ConvertToVariableSizeSignedOneBasedIndexedFaceLoops, DOC(Bentley, Geom, PolyfaceHeader, ConvertToVariableSizeSignedOneBasedIndexedFaceLoops));
    c13.def("ConvertTableColorToColorIndices", &PolyfaceHeader::ConvertTableColorToColorIndices, "faceToTableColor"_a, "vertexToTableColor"_a, DOC(Bentley, Geom, PolyfaceHeader, ConvertTableColorToColorIndices));
    c13.def("RemoveTwoEdgeFacesFromVariableSizeOneBasedMesh", &PolyfaceHeader::RemoveTwoEdgeFacesFromVariableSizeOneBasedMesh, DOC(Bentley, Geom, PolyfaceHeader, RemoveTwoEdgeFacesFromVariableSizeOneBasedMesh));

    c13.def_static("CreateVariableSizeIndexed", &PolyfaceHeader::CreateVariableSizeIndexed, DOC(Bentley, Geom, PolyfaceHeader, CreateVariableSizeIndexed));
    c13.def_static("CreateFixedBlockIndexed", &PolyfaceHeader::CreateFixedBlockIndexed, "numPerBlock"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateFixedBlockIndexed));
    c13.def_static("CreateQuadGrid", &PolyfaceHeader::CreateQuadGrid, "numPerRow"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateQuadGrid));
    c13.def_static("CreateTriangleGrid", &PolyfaceHeader::CreateTriangleGrid, "numPerRow"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateTriangleGrid));
    c13.def_static("CreateXYTriangulation", &PolyfaceHeader::CreateXYTriangulation, "points"_a, "fringeExpansionFactor"_a = 0.10, "retainFringeTriangles"_a = false, DOC(Bentley, Geom, PolyfaceHeader, CreateXYTriangulation));
    c13.def_static("CreateRegularPolyhedron", &PolyfaceHeader::CreateRegularPolyhedron, "radius"_a, "polyhedronSelect"_a, "radiusSelect"_a, "transform"_a = nullptr, DOC(Bentley, Geom, PolyfaceHeader, CreateRegularPolyhedron));
    c13.def_static("CreateRegularPolyhedronWithSubtriangulation", &PolyfaceHeader::CreateRegularPolyhedronWithSubtriangulation,
                   "radius"_a, "polyhedronSelect"_a, "numExtraVerticesInBaseEdges"_a, "transform"_a);
    c13.def_static("CreateVerticalPanelsBetweenSegments", &PolyfaceHeader::CreateVerticalPanelsBetweenSegments, "segments"_a);
    c13.def_static("CreateSidePanelsForViewDirection", &PolyfaceHeader::CreateSidePanelsForViewDirection, "meshes"_a, "viewDirection"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateSidePanelsForViewDirection));
    c13.def_static("CloneWithSidePanelsInserted", &PolyfaceHeader::CloneWithSidePanelsInserted, "meshes"_a, "viewDirection"_a, DOC(Bentley, Geom, PolyfaceHeader, CloneWithSidePanelsInserted));
    c13.def_static("CreateDRange3dFaces", &PolyfaceHeader::CreateDRange3dFaces, "range"_a, "triangulate"_a= false, "placement"_a = nullptr, DOC(Bentley, Geom, PolyfaceHeader, CreateDRange3dFaces));


    c13.def_static("VolumeFromBoreData", [](bvector<DSegment3d>& segments,
                                            bvector<ptrdiff_t>* topFacetReadIndex,
                                            bvector<ptrdiff_t>* bottomFacetReadIndex,
                                            bvector<ptrdiff_t>* sideFacetReadIndex)
                   {
                   bool foldedSurfaces = false;
                   auto retVal = PolyfaceHeader::VolumeFromBoreData(segments, foldedSurfaces, topFacetReadIndex, bottomFacetReadIndex, sideFacetReadIndex);
                   return py::make_tuple(retVal, foldedSurfaces);
                   }, "segments"_a, "topFacetReadIndex"_a, "bottomFacetReadIndex"_a, "sideFacetReadIndex"_a);

    c13.def_static("CreateFixedBlockCoordinates", &PolyfaceHeader::CreateFixedBlockCoordinates, "numPerFaces"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateFixedBlockCoordinates));
    c13.def_static("CreateIndexedMesh", &PolyfaceHeader::CreateIndexedMesh, "numPerFace"_a, "points"_a, "indexData"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateIndexedMesh));
    c13.def_static("CreateFromTaggedPolygons", &PolyfaceHeader::CreateFromTaggedPolygons, "polygons"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateFromTaggedPolygons));
    c13.def_static("VisibleParts", &PolyfaceHeader::VisibleParts, "source"_a, "vectorToEye"_a, "dest"_a, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, PolyfaceHeader, VisibleParts));

    c13.def("CopyTo", py::overload_cast<PolyfaceHeader&>(&PolyfaceHeader::CopyTo, py::const_), "dest"_a, DOC(Bentley, Geom, PolyfaceHeader, CopyTo));
    c13.def("SetNewFaceData", &PolyfaceHeader::SetNewFaceData, "faceData"_a, "endIndex"_a = 0, DOC(Bentley, Geom, PolyfaceHeader, SetNewFaceData));
    c13.def("Triangulate", py::overload_cast<>(&PolyfaceHeader::Triangulate), DOC(Bentley, Geom, PolyfaceHeader, Triangulate));
    c13.def_static("CreateUnifiedIndexMesh", &PolyfaceHeader::CreateUnifiedIndexMesh, "source"_a, DOC(Bentley, Geom, PolyfaceHeader, CreateUnifiedIndexMesh));
    c13.def("FixupVertexNormalDirectionToFaceOrientation", &PolyfaceHeader::FixupVertexNormalDirectionToFaceOrientation, "summary"_a, "makeChanges"_a, DOC(Bentley, Geom, PolyfaceHeader, FixupVertexNormalDirectionToFaceOrientation));
    c13.def("OrientAndCollectManifoldComponents", &PolyfaceHeader::OrientAndCollectManifoldComponents, "componentReadIncices"_a, "messages"_a, DOC(Bentley, Geom, PolyfaceHeader, OrientAndCollectManifoldComponents));
    c13.def("ConstructOrderingForLongEdgeRemoval", &PolyfaceHeader::ConstructOrderingForLongEdgeRemoval, "readIndexSequence"_a, "maxEdgeLength"_a = 0.0, DOC(Bentley, Geom, PolyfaceHeader, ConstructOrderingForLongEdgeRemoval));

    c13.def("ExcavateFacetsWithLongBoundaryEdges", &PolyfaceHeader::ExcavateFacetsWithLongBoundaryEdges, "maxEdgeLength"_a = 0.0, DOC(Bentley, Geom, PolyfaceHeader, ExcavateFacetsWithLongBoundaryEdges));
    c13.def("SplitByMaxEdgeLength", &PolyfaceHeader::SplitByMaxEdgeLength, "splitLength"_a, "splits"_a, DOC(Bentley, Geom, PolyfaceHeader, SplitByMaxEdgeLength));
    c13.def("AddEdgeChains", &PolyfaceHeader::AddEdgeChains, "drawMethodIndex"_a, DOC(Bentley, Geom, PolyfaceHeader, AddEdgeChains));
    c13.def("Triangulate", py::overload_cast<size_t>(&PolyfaceHeader::Triangulate), "maxEdge"_a, DOC(Bentley, Geom, PolyfaceHeader, Triangulate));
    c13.def("Triangulate", py::overload_cast<size_t, bool, Bentley::IPolyfaceVisitorFilter*>(&PolyfaceHeader::Triangulate), "maxEdge"_a, "hideNewEdges"_a, "filter"_a, DOC(Bentley, Geom, PolyfaceHeader, Triangulate));

    c13.def("CompactIndexArrays", &PolyfaceHeader::CompactIndexArrays, DOC(Bentley, Geom, PolyfaceHeader, CompactIndexArrays));
    c13.def("CompactArrays", &PolyfaceHeader::CompactArrays, DOC(Bentley, Geom, PolyfaceHeader, CompactArrays));

    c13.def("Transform", py::overload_cast<TransformCR, bool>(&PolyfaceHeader::Transform), "transform"_a, "reverseIndicesIfMirrored"_a = true);    

    c13.def("ReverseNormals", &PolyfaceHeader::ReverseNormals, DOC(Bentley, Geom, PolyfaceHeader, ReverseNormals));
    c13.def("CollectAdjacentFacetAndPointIndices", &PolyfaceHeader::CollectAdjacentFacetAndPointIndices, "activeReadIndex"_a, "fringeReadIndex"_a, "activePointIndex"_a, DOC(Bentley, Geom, PolyfaceHeader, CollectAdjacentFacetAndPointIndices));

    c13.def("TranslateSelectedFacets", &PolyfaceHeader::TranslateSelectedFacets, "activeReadIndex"_a, "vector"_a, "mode"_a, DOC(Bentley, Geom, PolyfaceHeader, TranslateSelectedFacets));
    c13.def("CloneWithTranslatedFacets", &PolyfaceHeader::CloneWithTranslatedFacets, "activeReadIndex"_a, "vector"_a, "mode"_a);
    c13.def("CloneWithIndexedDuplicatesRemoved", &PolyfaceHeader::CloneWithIndexedDuplicatesRemoved, DOC(Bentley, Geom, PolyfaceHeader, CloneWithIndexedDuplicatesRemoved));
    c13.def("CloneWithDegenerateFacetsRemoved", &PolyfaceHeader::CloneWithDegenerateFacetsRemoved);
    c13.def("CloneWithFacetsInRandomOrder", &PolyfaceHeader::CloneWithFacetsInRandomOrder);
    c13.def("CloneWithMaximalPlanarFacets", &PolyfaceHeader::CloneWithMaximalPlanarFacets, "mergeCoplanarFacets"_a, "mergeColinearEdges"_a, DOC(Bentley, Geom, PolyfaceHeader, CloneWithMaximalPlanarFacets));
    c13.def("CloneWithMaximalPlanarFacetsExt", &PolyfaceHeader::CloneWithMaximalPlanarFacetsExt, "mergeCoplanarFacets"_a, "mergeColinearEdges"_a, "planarityToleranceRadians"_a = 1.0e-8, "maxPass"_a = 1);
    c13.def_static("CloneWithTVertexFixup", &PolyfaceHeader::CloneWithTVertexFixup, "meshes"_a, "options"_a = nullptr, "onEdgeTolerance"_a = 0.0, DOC(Bentley, Geom, PolyfaceHeader, CloneWithTVertexFixup));

    c13.def_static("ComputeSingleSheetCutFill", [] (PolyfaceHeaderCR dtm, PolyfaceHeaderCR road, DVec3dCR viewVector, PolyfaceHeader::ComputeSingleSheetOption option)
                   {
                   PolyfaceHeaderPtr cutMesh, fillMesh;
                   PolyfaceHeader::ComputeSingleSheetCutFill(dtm, road, viewVector, cutMesh, fillMesh, option);
                   return py::make_tuple(cutMesh, fillMesh);
                   }, "dtmMesh"_a, "roadMesh"_a, "viewVector"_a, "option"_a);

    c13.def("LocalDecimation", &PolyfaceHeader::LocalDecimation, "abstol"_a, "rangeFractionTol"_a, DOC(Bentley, Geom, PolyfaceHeader, LocalDecimation));
    c13.def("IdentifyDuplicates", &PolyfaceHeader::IdentifyDuplicates,
            "nonduplicatedFacetReadIndex"_a, "duplicatedFacetFirstReadIndex"_a, "duplicatedFacetAdditionalReadIndex"_a, "baseIndexForAdditionalReadIndex"_a);

    c13.def("AddPolygon",
            py::overload_cast<DPoint3dArray const&, DVec3dArray const*, DPoint2dArray const*>(&PolyfaceHeader::AddPolygon),
            "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, py::list const& xyz, DVec3dArray const* normal, DPoint2dArray const* param)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
            return self.AddPolygon(cppxyz, normal, param);   
            }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);
    c13.def("AddPolygon", [](PolyfaceHeaderR self, DPoint3dArray const& xyz, DVec3dArray const* normal, py::list const* param)
            {
            if (param) {
                CONVERT_PYLIST_TO_NEW_CPPARRAY(*param, cppParam, DPoint2dArray, DPoint2d);
                return self.AddPolygon(xyz, normal, &cppParam);
            } else {
                return self.AddPolygon(xyz, normal, nullptr);
            } 
            }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);
    c13.def("AddPolygon", [](PolyfaceHeaderR self, py::list const& xyz, DVec3dArray const* normal, py::list const* param)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
            if (param) {
                CONVERT_PYLIST_TO_NEW_CPPARRAY(*param, cppParam, DPoint2dArray, DPoint2d);
                return self.AddPolygon(cppxyz, normal, &cppParam);
            } else {
                return self.AddPolygon(cppxyz, normal, nullptr);
            }  
            }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, DPoint3dArray const &xyz, py::list const *normal, DPoint2dArray const *param)
            {
        if (normal) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(*normal, cppNormal, DVec3dArray, DVec3d);
            return self.AddPolygon(xyz, &cppNormal, param);
        } else {
            return self.AddPolygon(xyz, nullptr, param);
        } }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, py::list const &xyz, py::list const *normal, DPoint2dArray const *param)
            {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
        if (normal) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(*normal, cppNormal, DVec3dArray, DVec3d);
            return self.AddPolygon(cppxyz, &cppNormal, param);
        } else {
            return self.AddPolygon(cppxyz, nullptr, param);
        } }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, DPoint3dArray const &xyz, py::list const *normal, py::list const *param)
            {
        DVec3dArray cppNormal;
        DPoint2dArray cppParam;
        DVec3dArray* normalPtr = nullptr;
        DPoint2dArray* paramPtr = nullptr;
    
        if (normal) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(*normal, cppNormal, DVec3dArray, DVec3d);
            normalPtr = &cppNormal;
        }
        if (param) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(*param, cppParam, DPoint2dArray, DPoint2d);
            paramPtr = &cppParam;
        }
        return self.AddPolygon(xyz, normalPtr, paramPtr); }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, py::list const &xyz, py::list const *normal, py::list const *param)
            {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
        DVec3dArray cppNormal;
        DPoint2dArray cppParam;
        DVec3dArray* normalPtr = nullptr;
        DPoint2dArray* paramPtr = nullptr;
    
        if (normal) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(*normal, cppNormal, DVec3dArray, DVec3d);
            normalPtr = &cppNormal;
        }
        if (param) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(*param, cppParam, DPoint2dArray, DPoint2d);
            paramPtr = &cppParam;
        }
        return self.AddPolygon(cppxyz, normalPtr, paramPtr); }, "xyz"_a, "normal"_a = nullptr, "param"_a = nullptr);

    c13.def("AddPolygon",
            py::overload_cast<DPoint3dArray const&, PolyfaceVisitorR, IndexedParameterMap const&>(&PolyfaceHeader::AddPolygon),
            "xyz"_a, "visitor"_a, "mapping"_a);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, py::list const& xyz, PolyfaceVisitorR visitor, IndexedParameterMap const& mapping)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
            return self.AddPolygon(cppxyz, visitor, mapping);   
            }, "xyz"_a, "visitor"_a, "mapping"_a);

    c13.def("AddPolygon",
            py::overload_cast<DPoint3dArray const&, TransformCR, DVec3dCR, bool, bool>(&PolyfaceHeader::AddPolygon),
            "xyz"_a, "worldToParameterSpace"_a, "normal"_a, "compressNormal"_a, "reverseXYZ"_a);

    c13.def("AddPolygon", [](PolyfaceHeaderR self, py::list const& xyz, TransformCR worldToParameterSpace, DVec3dCR normal, bool compressNormal, bool reverseXYZ)
            {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
            return self.AddPolygon(cppxyz, worldToParameterSpace, normal, compressNormal, reverseXYZ);   
            }, "xyz"_a, "worldToParameterSpace"_a, "normal"_a, "compressNormal"_a, "reverseXYZ"_a);

    c13.def("SweepToSolid", &PolyfaceHeader::SweepToSolid, "sweepVector"_a, "triangulateSides"_a, DOC(Bentley, Geom, PolyfaceHeader, SweepToSolid));
    c13.def("CopyFrom", &PolyfaceHeader::CopyFrom, "source"_a, DOC(Bentley, Geom, PolyfaceHeader, CopyFrom));
    c13.def("AddIfMatchedLayout", &PolyfaceHeader::AddIfMatchedLayout, "source"_a, DOC(Bentley, Geom, PolyfaceHeader, AddIfMatchedLayout));
    c13.def("BuildApproximateNormals", &PolyfaceHeader::BuildApproximateNormals,
            "maxSignelEdgeAngle"_a = 0.2, "maxAccumulatedAngle"_a = 0.3, "markAllTransitionsVisible"_a = true);

    c13.def("ComputeOffset", &PolyfaceHeader::ComputeOffset,
            "options"_a, "distance1"_a, "distance2"_a, "outputOffset1"_a = true, "outputOffset2"_a = true, "outputSideFacets"_a = true);

    c13.def("BuildPerFaceParameters", &PolyfaceHeader::BuildPerFaceParameters, "selector"_a, DOC(Bentley, Geom, PolyfaceHeader, BuildPerFaceParameters));

    c13.def("MarkDiagonalEdgesInvisible", &PolyfaceHeader::MarkDiagonalEdgesInvisible, "smoothAngle"_a, "edgeLengthFactor"_a = 1.001, "maxEdgesInFacetForDiagonalRules"_a = 3, DOC(Bentley, Geom, PolyfaceHeader, MarkDiagonalEdgesInvisible));
    c13.def("ClearNormals", &PolyfaceHeader::ClearNormals, "active"_a, DOC(Bentley, Geom, PolyfaceHeader, ClearNormals));
    c13.def("ClearParameters", &PolyfaceHeader::ClearParameters, "active"_a, DOC(Bentley, Geom, PolyfaceHeader, ClearParameters));
    c13.def("BuildPerFaceNormals", &PolyfaceHeader::BuildPerFaceNormals, DOC(Bentley, Geom, PolyfaceHeader, BuildPerFaceNormals));
    c13.def("BuildPerFaceFaceData", &PolyfaceHeader::BuildPerFaceFaceData, DOC(Bentley, Geom, PolyfaceHeader, BuildPerFaceFaceData));
    c13.def("MarkInvisibleEdges", py::overload_cast<double, DVec3dCP>(&PolyfaceHeader::MarkInvisibleEdges), "smoothAngle"_a, "silhouetteVector"_a, DOC(Bentley, Geom, PolyfaceHeader, MarkInvisibleEdges));
    c13.def("MarkInvisibleEdges", py::overload_cast<double>(&PolyfaceHeader::MarkInvisibleEdges), "smoothAngle"_a, DOC(Bentley, Geom, PolyfaceHeader, MarkInvisibleEdges));
    c13.def("MarkTopologicalBoundariesVisible", &PolyfaceHeader::MarkTopologicalBoundariesVisible, "preserveOtherVisibility"_a, DOC(Bentley, Geom, PolyfaceHeader, MarkTopologicalBoundariesVisible));
    c13.def("MarkAllEdgesVisible", &PolyfaceHeader::MarkAllEdgesVisible, DOC(Bentley, Geom, PolyfaceHeader, MarkAllEdgesVisible));

    c13.def("PartitionByXYRange",
            py::overload_cast<size_t, size_t, PolyfaceHeaderArray&>(&PolyfaceHeader::PartitionByXYRange),
            "targetFaceCount"_a, "targetMeshCount"_a, "submeshArray"_a);

    c13.def("PartitionByXYRange", [](PolyfaceHeaderR self, size_t targetFaceCount, size_t targetMeshCount, py::list &submeshArrayList) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(submeshArrayList, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            bool result = self.PartitionByXYRange(targetFaceCount, targetMeshCount, cppSubmeshArray);
            CONVERT_CPPARRAY_TO_PYLIST(submeshArrayList, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            return result; }, "targetFaceCount"_a, "targetMeshCount"_a, "submeshArray"_a);

    c13.def("PartitionByXYRange",
            py::overload_cast<size_t, size_t, Int64Array&>(&PolyfaceHeader::PartitionByXYRange),
            "targetFaceCount"_a, "targetMeshCount"_a, "blockedReadIndexArray"_a);

    c13.def("PartitionMaintainFaceOrder",
            py::overload_cast<size_t, size_t, PolyfaceHeaderArray&>(&PolyfaceHeader::PartitionMaintainFaceOrder),
            "targetFaceCount"_a, "targetMeshCount"_a, "submeshArray"_a);

    c13.def("PartitionMaintainFaceOrder", [](PolyfaceHeaderR self, size_t targetFaceCount, size_t targetMeshCount, py::list &submeshArray) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            bool result = self.PartitionMaintainFaceOrder(targetFaceCount, targetMeshCount, cppSubmeshArray);
            CONVERT_CPPARRAY_TO_PYLIST(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            return result; }, "targetFaceCount"_a, "targetMeshCount"_a, "submeshArray"_a);

    c13.def("PartitionMaintainFaceOrder",
            py::overload_cast<size_t, size_t, Int64Array&>(&PolyfaceHeader::PartitionMaintainFaceOrder),
            "targetFaceCount"_a, "targetMeshCount"_a, "blockedReadIndexArray"_a);

    c13.def("PartitionByConnectivity",
            py::overload_cast<int, PolyfaceHeaderArray&>(&PolyfaceHeader::PartitionByConnectivity, py::const_),
            "connectivityType"_a, "submeshArray"_a);

    c13.def("PartitionByConnectivity", [](PolyfaceHeaderCR self, int connectivityType, py::list& submeshArray){
            CONVERT_PYLIST_TO_NEW_CPPARRAY(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            bool result = self.PartitionByConnectivity(connectivityType, cppSubmeshArray);
            CONVERT_CPPARRAY_TO_PYLIST(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            return result; }, "connectivityType"_a, "submeshArray"_a);

    c13.def("PartitionByConnectivity",
            py::overload_cast<int, Int64Array&>(&PolyfaceHeader::PartitionByConnectivity, py::const_),
            "connectivityType"_a, "submeshArray"_a);

    c13.def("PartitionReadIndicesByNormal", &PolyfaceHeader::PartitionReadIndicesByNormal, "vector"_a, "readIndices"_a, DOC(Bentley, Geom, PolyfaceHeader, PartitionReadIndicesByNormal));
    c13.def("SplitByFlood", &PolyfaceHeader::SplitByFlood, "optionsA"_a, "optionsB"_a, "blockedReadIndexArray"_a, DOC(Bentley, Geom, PolyfaceHeader, SplitByFlood));

    c13.def("CopyPartitions",
            py::overload_cast<Int64Array&, PolyfaceHeaderArray&>(&PolyfaceHeader::CopyPartitions, py::const_),
            "blockedReadIndex"_a, "submeshArray"_a);

    c13.def("CopyPartitions", [](PolyfaceHeaderCR self, Int64Array& blockedReadIndex, py::list& submeshArray) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            bool result = self.CopyPartitions(blockedReadIndex, cppSubmeshArray);
            CONVERT_CPPARRAY_TO_PYLIST(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            return result;
        }, "blockedReadIndex"_a, "submeshList"_a);
            
    c13.def("CopyPartitions",
            py::overload_cast<Int64VecArray&, PolyfaceHeaderArray&>(&PolyfaceHeader::CopyPartitions, py::const_),
            "blockedReadIndex"_a, "submeshArray"_a);

    c13.def("CopyPartitions", [](PolyfaceHeaderCR self, Int64VecArray& blockedReadIndex, py::list& submeshArray) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            bool result = self.CopyPartitions(blockedReadIndex, cppSubmeshArray);
            CONVERT_CPPARRAY_TO_PYLIST(submeshArray, cppSubmeshArray, PolyfaceHeaderArray, PolyfaceHeaderPtr);
            return result;
        }, "blockedReadIndex"_a, "submeshArray"_a);

    c13.def("IsPlanarWithinSuperfacets", &PolyfaceHeader::IsPlanarWithinSuperfacets, "tolerance"_a = -1.0, DOC(Bentley, Geom, PolyfaceHeader, IsPlanarWithinSuperfacets));
    c13.def_static("SelectBlockedIndices", &PolyfaceHeader::SelectBlockedIndices, "blockedReadIndex"_a, "selectedReadIndex"_a, "keepIfSelected"_a, "blockedReadIndexOut"_a, DOC(Bentley, Geom, PolyfaceHeader, SelectBlockedIndices));

    c13.def("TryGetMaxSingleFacetParamLength", &PolyfaceHeader::TryGetMaxSingleFacetParamLength, "uvLength"_a, DOC(Bentley, Geom, PolyfaceHeader, TryGetMaxSingleFacetParamLength));
    c13.def("TryGetMaxSingleFacetLocalXYLength", &PolyfaceHeader::TryGetMaxSingleFacetLocalXYLength, "xySize"_a, DOC(Bentley, Geom, PolyfaceHeader, TryGetMaxSingleFacetLocalXYLength));

    c13.def("ExtractBoundaryStrings", [] (PolyfaceHeaderR self)
            {
            size_t numOpen, numClosed;
            auto retVal = self.ExtractBoundaryStrings(numOpen, numClosed);
            return py::make_tuple(retVal, numOpen, numClosed);
            });
    c13.def("ExtractTopologicalBoundaryStrings", [](PolyfaceHeaderR self)
            {
            size_t numOpen, numClosed;
            auto retVal = self.ExtractTopologicalBoundaryStrings(numOpen, numClosed);
            return py::make_tuple(retVal, numOpen, numClosed);
            });

    c13.def("CollectEdgeMateData", &PolyfaceHeader::CollectEdgeMateData, "segments"_a, "includeMatched"_a = false, "returnSingleEdgeReadIndex"_a = false, DOC(Bentley, Geom, PolyfaceHeader, CollectEdgeMateData));
    c13.def("ReplicateMissingIndexArrays", &PolyfaceHeader::ReplicateMissingIndexArrays, DOC(Bentley, Geom, PolyfaceHeader, ReplicateMissingIndexArrays));

    //===================================================================================
    // struct PolyfaceVisitor
    py::class_<PolyfaceVisitor, PolyfaceVisitorPtr/*, PolyfaceVectors*/> c14(m, "PolyfaceVisitor");

    c14.def("TwoSided", &PolyfaceVisitor::GetTwoSided);    

    c14.def("Point", &PolyfaceVisitor::Point, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, Point));
    c14.def("Param", &PolyfaceVisitor::Param, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, Param));
    c14.def("Normal", &PolyfaceVisitor::Normal, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, Normal));
    c14.def("DoubleColor", &PolyfaceVisitor::DoubleColor, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, DoubleColor));
    c14.def("IntColor", &PolyfaceVisitor::IntColor, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, IntColor));
    c14.def("ColorTable", &PolyfaceVisitor::ColorTable, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, ColorTable));
    c14.def("FloatColor", &PolyfaceVisitor::FloatColor, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, FloatColor));
    c14.def("IlluminationName", &PolyfaceVisitor::IlluminationName, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, IlluminationName));

    c14.def("ClientPointIndex", &PolyfaceVisitor::ClientPointIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, ClientPointIndex));
    c14.def("ClientParamIndex", &PolyfaceVisitor::ClientParamIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, ClientParamIndex));
    c14.def("ClientNormalIndex", &PolyfaceVisitor::ClientNormalIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, ClientNormalIndex));
    c14.def("ClientColorIndex", &PolyfaceVisitor::ClientColorIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, ClientColorIndex));
    c14.def("ClientFaceIndex", &PolyfaceVisitor::ClientFaceIndex, py::return_value_policy::reference_internal, DOC(Bentley, Geom, PolyfaceVisitor, ClientFaceIndex));

    c14.def("TryGetClientZeroBasedPointIndex", [] (PolyfaceVisitorR self, int zeroBasedVisitorIndex)
            {
            int zeroBasedIndex = -1;
            bool visible = false;
            bool bOk = self.TryGetClientZeroBasedPointIndex(zeroBasedVisitorIndex, zeroBasedIndex, visible);
            return py::make_tuple(bOk, zeroBasedIndex, visible);
            }, "zeroBasedVisitorIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetClientZeroBasedPointIndex));

    c14.def("TryGetClientZeroBasedNormalIndex", [] (PolyfaceVisitorR self, int zeroBasedVisitorIndex)
            {
            int zeroBasedIndex = -1;
            bool bOk = self.TryGetClientZeroBasedNormalIndex(zeroBasedVisitorIndex, zeroBasedIndex);
            return py::make_tuple(bOk, zeroBasedIndex);
            }, "zeroBasedVisitorIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetClientZeroBasedNormalIndex));

    c14.def("TryGetClientZeroBasedParamIndex", [] (PolyfaceVisitorR self, int zeroBasedVisitorIndex)
            {
            int zeroBasedIndex = -1;
            bool bOk = self.TryGetClientZeroBasedParamIndex(zeroBasedVisitorIndex, zeroBasedIndex);
            return py::make_tuple(bOk, zeroBasedIndex);
            }, "zeroBasedVisitorIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetClientZeroBasedParamIndex));

    c14.def("TryGetClientZeroBasedColorIndex", [] (PolyfaceVisitorR self, int zeroBasedVisitorIndex)
            {
            int zeroBasedIndex = -1;
            bool bOk = self.TryGetClientZeroBasedColorIndex(zeroBasedVisitorIndex, zeroBasedIndex);
            return py::make_tuple(bOk, zeroBasedIndex);
            }, "zeroBasedVisitorIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetClientZeroBasedColorIndex));

    c14.def("Reset", &PolyfaceVisitor::Reset, DOC(Bentley, Geom, PolyfaceVisitor, Reset));
    c14.def("AdvanceToNextFace", &PolyfaceVisitor::AdvanceToNextFace, DOC(Bentley, Geom, PolyfaceVisitor, AdvanceToNextFace));
    c14.def("AdvanceToFacetBySearchPoint",
            py::overload_cast<DPoint3dCR, double, DPoint3dR>(&PolyfaceVisitor::AdvanceToFacetBySearchPoint),
            "xyz"_a, "tolerance"_a, "facetPoint"_a, DOC(Bentley, Geom, PolyfaceVisitor, AdvanceToFacetBySearchPoint));

    c14.def("AdvanceToFacetBySearchPoint", [] (PolyfaceVisitorR self, DPoint3dCR xyz, double tolerance, DPoint3dR facetPoint)
            {
            ptrdiff_t edgeIndex = 0;
            double edgeFraction = 0;
            bool bOk = self.AdvanceToFacetBySearchPoint(xyz, tolerance, facetPoint, edgeIndex, edgeFraction);
            return py::make_tuple(bOk, edgeIndex, edgeFraction);
            }, "xyz"_a, "tolerance"_a, "facetPoint"_a, DOC(Bentley, Geom, PolyfaceVisitor, AdvanceToFacetBySearchPoint));

    c14.def("AdvanceToFacetBySearchRay", [] (PolyfaceVisitorR self, DRay3dCR ray, double tolerance, DPoint3dR facetPoint)
            {
            double rayFraction = 0;
            bool bOk = self.AdvanceToFacetBySearchRay(ray, tolerance, facetPoint, rayFraction);
            return py::make_tuple(bOk, rayFraction);
            }, "ray"_a, "tolerance"_a, "facetPoint"_a, DOC(Bentley, Geom, PolyfaceVisitor, AdvanceToFacetBySearchRay));

    c14.def("AdvanceToFacetBySearchRay", [] (PolyfaceVisitorR self, DRay3dCR ray, double tolerance, DPoint3dR facetPoint, DPoint3dR edgePoint)
            {
            double rayFraction, edgeFraction, edgeDistance;
            ptrdiff_t edgeIndex;
            bool bOk = self.AdvanceToFacetBySearchRay(ray, tolerance, facetPoint, rayFraction, edgeIndex, edgeFraction, edgePoint, edgeDistance);
            return py::make_tuple(bOk, rayFraction, edgeIndex, edgeFraction, edgeDistance);
            }, "ray"_a, "tolerance"_a, "facetPoint"_a, "edgePoint"_a, DOC(Bentley, Geom, PolyfaceVisitor, AdvanceToFacetBySearchRay));

    c14.def("AdvanceToFacetBySearchRay", py::overload_cast<DRay3dCR, FacetLocationDetailR>(&PolyfaceVisitor::AdvanceToFacetBySearchRay), "ray"_a, "detail"_a, DOC(Bentley, Geom, PolyfaceVisitor, AdvanceToFacetBySearchRay));

    c14.def("TryParamToScanBrackets", &PolyfaceVisitor::TryParamToScanBrackets, "uvParam"_a, "horizontalScanBracket"_a, "verticalScanBracket"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryParamToScanBrackets));
    c14.def("ClearAllArrays", &PolyfaceVisitor::ClearAllArrays, DOC(Bentley, Geom, PolyfaceVisitor, ClearAllArrays));
    c14.def("LoadVertexData", &PolyfaceVisitor::LoadVertexData, "detail"_a, "index"_a, DOC(Bentley, Geom, PolyfaceVisitor, LoadVertexData));
    c14.def("LoadCyclicVertexData", &PolyfaceVisitor::LoadCyclicVertexData, "detail"_a, "index"_a);
    c14.def("AddCoordinatesFromFacetLocationDetail", &PolyfaceVisitor::AddCoordinatesFromFacetLocationDetail, "detail"_a, DOC(Bentley, Geom, PolyfaceVisitor, AddCoordinatesFromFacetLocationDetail));

    c14.def("TryParamToFacetLocationDetail", &PolyfaceVisitor::TryParamToFacetLocationDetail, "uvParam"_a, "detail"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryParamToFacetLocationDetail));
    c14.def("TryDRay3dIntersectionToFacetLocationDetail", &PolyfaceVisitor::TryDRay3dIntersectionToFacetLocationDetail, "ray"_a, "detail"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryDRay3dIntersectionToFacetLocationDetail));
    c14.def("IntepolateDataOnEdge", &PolyfaceVisitor::IntepolateDataOnEdge, "detail"_a, "vertexIndex"_a, "edgeFraction"_a = 0.0, "a"_a = 0.0, DOC(Bentley, Geom, PolyfaceVisitor, IntepolateDataOnEdge));
    c14.def("AccumulateScaledData", &PolyfaceVisitor::AccumulateScaledData, "detail"_a, "vertexIndex"_a, "fraction"_a, DOC(Bentley, Geom, PolyfaceVisitor, AccumulateScaledData));
    c14.def("TryGetLocalFrame", &PolyfaceVisitor::TryGetLocalFrame, "localToWorld"_a, "worldToLocal"_a, "selector"_a = LOCAL_COORDINATE_SCALE_01RangeBothAxes, DOC(Bentley, Geom, PolyfaceVisitor, TryGetLocalFrame));
    c14.def("TryGetLocalFrameAndRank", &PolyfaceVisitor::TryGetLocalFrameAndRank, "localToWorld"_a, "worldToLocal"_a, "selector"_a = LOCAL_COORDINATE_SCALE_01RangeBothAxes, DOC(Bentley, Geom, PolyfaceVisitor, TryGetLocalFrameAndRank));
    c14.def("GetReadIndex", &PolyfaceVisitor::GetReadIndex, DOC(Bentley, Geom, PolyfaceVisitor, GetReadIndex));
    c14.def("MoveToFacetByReadIndex", &PolyfaceVisitor::MoveToFacetByReadIndex, "readIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, MoveToFacetByReadIndex));
    c14.def("NumEdgesThisFace", &PolyfaceVisitor::NumEdgesThisFace, DOC(Bentley, Geom, PolyfaceVisitor, NumEdgesThisFace));

    c14.def_property("NumWrap", &PolyfaceVisitor::GetNumWrap, &PolyfaceVisitor::SetNumWrap);
    c14.def("GetNumWrap", &PolyfaceVisitor::GetNumWrap, DOC(Bentley, Geom, PolyfaceVisitor, GetNumWrap));
    c14.def("SetNumWrap", &PolyfaceVisitor::SetNumWrap, "numWrap"_a, DOC(Bentley, Geom, PolyfaceVisitor, SetNumWrap));
    
    c14.def("Visible", &PolyfaceVisitor::Visible, DOC(Bentley, Geom, PolyfaceVisitor, Visible));
    c14.def("IndexPosition", &PolyfaceVisitor::IndexPosition, DOC(Bentley, Geom, PolyfaceVisitor, IndexPosition));

    c14.def_static("Attach", &PolyfaceVisitor::Attach, "parentMesh"_a, "allData"_a = true, DOC(Bentley, Geom, PolyfaceVisitor, Attach));

    c14.def("GetClientPolyfaceQuery", &PolyfaceVisitor::GetClientPolyfaceQueryCR, py::return_value_policy::reference_internal);
    c14.def("CopyData", &PolyfaceVisitor::CopyData, "fromIndex"_a, "toIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, CopyData));
    c14.def("TrimData", &PolyfaceVisitor::TrimData, "newSize"_a, DOC(Bentley, Geom, PolyfaceVisitor, TrimData));
    c14.def("CompressClosePoints", &PolyfaceVisitor::CompressClosePoints, "tolerance"_a, DOC(Bentley, Geom, PolyfaceVisitor, CompressClosePoints));
    c14.def("PushFaceData", &PolyfaceVisitor::PushFaceData, "source"_a, "i0"_a, DOC(Bentley, Geom, PolyfaceVisitor, PushFaceData));
    c14.def("PushIndexData", &PolyfaceVisitor::PushIndexData, "source"_a, "i0"_a, DOC(Bentley, Geom, PolyfaceVisitor, PushIndexData));
    c14.def("PushInterpolatedFaceData", &PolyfaceVisitor::PushInterpolatedFaceData, "source"_a, "i0"_a, "fraction"_a, "i1"_a, "suppressVisibility"_a = false, DOC(Bentley, Geom, PolyfaceVisitor, PushInterpolatedFaceData));
    c14.def("TrimFaceData", &PolyfaceVisitor::TrimFaceData, "index0"_a, "count"_a, DOC(Bentley, Geom, PolyfaceVisitor, TrimFaceData));

    c14.def("TryFindFacetRayIntersection", [] (PolyfaceVisitorCR self, DRay3dCR ray, double tolerance, DPoint3dR facetPoint)
            {
            double rayFraction = 0;
            bool bOk = self.TryFindFacetRayIntersection(ray, tolerance, facetPoint, rayFraction);
            return py::make_tuple(bOk, rayFraction);
            }, "ray"_a, "tolerance"_a, "facetPoint"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryFindFacetRayIntersection));

    c14.def("TryFindCloseFacetPoint", &PolyfaceVisitor::TryFindCloseFacetPoint, "spacePoint"_a, "tolerance"_a, "fractionPoint"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryFindCloseFacetPoint));

    c14.def("TryGetFacetCentroidNormalAndArea", [] (PolyfaceVisitorCR self, DPoint3dR centroid, DVec3dR normal)
            {
            double area = 0;
            bool bOk = self.TryGetFacetCentroidNormalAndArea(centroid, normal, area);
            return py::make_tuple(bOk, area);
            }, "centroid"_a, "normal"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetFacetCentroidNormalAndArea));

    c14.def("TryGetFacetAreaMomentProducts", &PolyfaceVisitor::TryGetFacetAreaMomentProducts, "origin"_a, "products"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetFacetAreaMomentProducts));
    c14.def("TryGetEdgePoint", &PolyfaceVisitor::TryGetEdgePoint, "edgeIndex"_a, "f"_a, "xyz"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetEdgePoint));
    c14.def("TryGetNormalizedParameter", &PolyfaceVisitor::TryGetNormalizedParameter, "index"_a, "normalizedParam"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetNormalizedParameter));
    c14.def("TryGetDistanceParameter", &PolyfaceVisitor::TryGetDistanceParameter, "index"_a, "distanceParam"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryGetDistanceParameter));    
    c14.def("ClearFacet", &PolyfaceVisitor::ClearFacet, DOC(Bentley, Geom, PolyfaceVisitor, ClearFacet));
    c14.def("TryAddVertexByReadIndex", &PolyfaceVisitor::TryAddVertexByReadIndex, "readIndex"_a, DOC(Bentley, Geom, PolyfaceVisitor, TryAddVertexByReadIndex));
    c14.def("TryRecomputeNormals", &PolyfaceVisitor::TryRecomputeNormals, DOC(Bentley, Geom, PolyfaceVisitor, TryRecomputeNormals));    
    

    //===================================================================================
    // Mesh Styles
    m.attr("MESH_ELM_STYLE_INDEXED_FACE_LOOPS") = MESH_ELM_STYLE_INDEXED_FACE_LOOPS;
    m.attr("MESH_ELM_STYLE_POINT_CLOUD") = MESH_ELM_STYLE_POINT_CLOUD;
    m.attr("MESH_ELM_STYLE_COORDINATE_TRIANGLES") = MESH_ELM_STYLE_COORDINATE_TRIANGLES;
    m.attr("MESH_ELM_STYLE_COORDINATE_QUADS") = MESH_ELM_STYLE_COORDINATE_QUADS;
    m.attr("MESH_ELM_STYLE_TRIANGLE_GRID") = MESH_ELM_STYLE_TRIANGLE_GRID;
    m.attr("MESH_ELM_STYLE_QUAD_GRID") = MESH_ELM_STYLE_QUAD_GRID;
    m.attr("MESH_ELM_STYLE_LARGE_MESH") = MESH_ELM_STYLE_LARGE_MESH;
    m.attr("MESH_ELM_STYLE_QVXLARGE_TRI_MESH") = MESH_ELM_STYLE_QVXLARGE_TRI_MESH;
    

    //===================================================================================
    // Matrix Tags 
    m.attr("MATRIX_ELM_TAG_NONE") = MATRIX_ELM_TAG_NONE;
    m.attr("MESH_ELM_TAG_NONE")   = MATRIX_ELM_TAG_NONE;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_VERTEX_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_VERTEX_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_COORDINATES") = MESH_ELM_TAG_VERTEX_COORDINATES;
    m.attr("MESH_ELM_TAG_NORMAL_COORDINATES") = MESH_ELM_TAG_NORMAL_COORDINATES;
    m.attr("MESH_ELM_TAG_UV_PARAMETERS") = MESH_ELM_TAG_UV_PARAMETERS;
    m.attr("MESH_ELM_TAG_DOUBLE_COLOR") = MESH_ELM_TAG_DOUBLE_COLOR;
    m.attr("MESH_ELM_TAG_FLOAT_COLOR") = MESH_ELM_TAG_FLOAT_COLOR;
    m.attr("MESH_ELM_TAG_INT_COLOR") = MESH_ELM_TAG_INT_COLOR;
    m.attr("MESH_ELM_TAG_TABLE_COLOR") = MESH_ELM_TAG_TABLE_COLOR;
    m.attr("MESH_ELM_TAG_DENSITY") = MESH_ELM_TAG_DENSITY;
    m.attr("MESH_ELM_TAG_PRESSURE") = MESH_ELM_TAG_PRESSURE;
    m.attr("MESH_ELM_TAG_TEMPERATURE") = MESH_ELM_TAG_TEMPERATURE;
    m.attr("MESH_ELM_TAG_DISPLACEMENT") = MESH_ELM_TAG_DISPLACEMENT;
    m.attr("MESH_ELM_TAG_VELOCITY") = MESH_ELM_TAG_VELOCITY;
    
    // auxiliary index arrays: "by face loop"
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_NORMAL_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_NORMAL_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_UV_PARAMETER_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_UV_PARAMETER_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_DOUBLE_COLOR_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_DOUBLE_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_INT_COLOR_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_INT_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_TABLE_COLOR_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_TABLE_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_DENSITY_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_DENSITY_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_PRESSURE_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_PRESSURE_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_TEMPERATURE_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_TEMPERATURE_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_DISPLACEMENT_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_DISPLACEMENT_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_VELOCITY_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_VELOCITY_INDICES;
    m.attr("MESH_ELM_TAG_FACE_LOOP_TO_FACE_INDICES") = MESH_ELM_TAG_FACE_LOOP_TO_FACE_INDICES;
    
    /* auxiliary index arrays: "by face" */
    m.attr("MESH_ELM_TAG_FACE_TO_NORMAL_INDICES") = MESH_ELM_TAG_FACE_TO_NORMAL_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_UV_PARAMETER_INDICES") = MESH_ELM_TAG_FACE_TO_UV_PARAMETER_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_DOUBLE_COLOR_INDICES") = MESH_ELM_TAG_FACE_TO_DOUBLE_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_INT_COLOR_INDICES") = MESH_ELM_TAG_FACE_TO_INT_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_TABLE_COLOR_INDICES") = MESH_ELM_TAG_FACE_TO_TABLE_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_DENSITY_INDICES") = MESH_ELM_TAG_FACE_TO_DENSITY_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_PRESSURE_INDICES") = MESH_ELM_TAG_FACE_TO_PRESSURE_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_TEMPERATURE_INDICES") = MESH_ELM_TAG_FACE_TO_TEMPERATURE_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_DISPLACEMENT_INDICES") = MESH_ELM_TAG_FACE_TO_DISPLACEMENT_INDICES;
    m.attr("MESH_ELM_TAG_FACE_TO_VELOCITY_INDICES") = MESH_ELM_TAG_FACE_TO_VELOCITY_INDICES;
    
    /* auxiliary index arrays: "by vertex" */
    m.attr("MESH_ELM_TAG_VERTEX_TO_NORMAL_INDICES") = MESH_ELM_TAG_VERTEX_TO_NORMAL_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_UV_PARAMETER_INDICES") = MESH_ELM_TAG_VERTEX_TO_UV_PARAMETER_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_DOUBLE_COLOR_INDICES") = MESH_ELM_TAG_VERTEX_TO_DOUBLE_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_INT_COLOR_INDICES") = MESH_ELM_TAG_VERTEX_TO_INT_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_TABLE_COLOR_INDICES") = MESH_ELM_TAG_VERTEX_TO_TABLE_COLOR_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_DENSITY_INDICES") = MESH_ELM_TAG_VERTEX_TO_DENSITY_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_PRESSURE_INDICES") = MESH_ELM_TAG_VERTEX_TO_PRESSURE_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_TEMPERATURE_INDICES") = MESH_ELM_TAG_VERTEX_TO_TEMPERATURE_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_DISPLACEMENT_INDICES") = MESH_ELM_TAG_VERTEX_TO_DISPLACEMENT_INDICES;
    m.attr("MESH_ELM_TAG_VERTEX_TO_VELOCITY_INDICES") = MESH_ELM_TAG_VERTEX_TO_VELOCITY_INDICES;

    //===================================================================================
    //Matrix Index Families 
    m.attr("MATRIX_ELM_INDEX_FAMILY_NONE") = MATRIX_ELM_INDEX_FAMILY_NONE;
    
    //===================================================================================
    // Matrix Index Families (Mesh parents)  
    m.attr("MESH_ELM_INDEX_FAMILY_NONE") = MESH_ELM_INDEX_FAMILY_NONE;
    m.attr("MESH_ELM_INDEX_FAMILY_BY_FACE_LOOP") = MESH_ELM_INDEX_FAMILY_BY_FACE_LOOP;
    m.attr("MESH_ELM_INDEX_FAMILY_BY_FACE") = MESH_ELM_INDEX_FAMILY_BY_FACE;
    m.attr("MESH_ELM_INDEX_FAMILY_BY_VERTEX") = MESH_ELM_INDEX_FAMILY_BY_VERTEX;
    
    //===================================================================================
    // Matrix Int Data Transform Types  
    m.attr("MATRIX_DATA_ELM_INDEX_TYPE_BLOCK_NONE") = MATRIX_DATA_ELM_INDEX_TYPE_BLOCK_NONE;
    m.attr("MATRIX_DATA_ELM_INDEX_TYPE_BLOCK_FIXED") = MATRIX_DATA_ELM_INDEX_TYPE_BLOCK_FIXED;
    m.attr("MATRIX_DATA_ELM_INDEX_TYPE_BLOCK_VARIABLE") = MATRIX_DATA_ELM_INDEX_TYPE_BLOCK_VARIABLE;
    
    //===================================================================================
    // Matrix Double Data Transform Types  
    m.attr("MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_NONE") = MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_NONE;
    m.attr("MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_POINT") = MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_POINT;
    m.attr("MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_VECTOR") = MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_VECTOR;
    m.attr("MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_COVECTOR") = MATRIX_DATA_ELM_TRANSFORM_TYPE_COORD_COVECTOR;
    }