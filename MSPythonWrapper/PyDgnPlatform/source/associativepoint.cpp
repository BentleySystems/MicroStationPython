/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\associativepoint.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/AssociativePoint.h>



static const char * __doc_Bentley_DgnPlatform_AssociativePoint_RegisterExtensions =R"doc(Register roots changed extension for known handlers.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_RemoveAllAssociations =R"doc(Removes all association points from an element.

Parameter ``element``:
    IN The element to remove the associative points on.

Returns:
    SUCCESS if associative points were removed.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_RemovePoint =R"doc(Remove a single associative point from an element.

Parameter ``element``:
    IN The element to remove the associative point on.

Parameter ``pointNum``:
    IN The point number to remove.

Parameter ``maxPoints``:
    IN The total number of points on element.

Returns:
    SUCCESS if associative point was removed.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_GetPoint =R"doc(Uses the information in assocPoint to create a 3D data point that is
returned in outPoint.

Parameter ``outPoint``:
    OUT The point location of the evaluated associative point.

Parameter ``assocPoint``:
    IN The associative point to query.

Parameter ``modelRef``:
    IN The model that contains the associative point dependent
    element.

Returns:
    SUCCESS if associative point was extracted.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InsertPoint =R"doc(Insert an association point to the specified element.

Parameter ``element``:
    IN The element to add the associative point to.

Parameter ``assocPoint``:
    IN The associative point to insert.

Parameter ``pointNum``:
    IN The index of point to insert.

Parameter ``maxPoints``:
    IN The maximum number of associative points on the element.

Returns:
    SUCCESS if associative point was inserted. @note An element that
    supports associative points has a dependency callback that is
    responsible for updating the element when the root elements
    change.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_ExtractPoint =R"doc(Extracts the association information from the specified point on the
given element.

Parameter ``assocPoint``:
    OUT The associative point to query.

Parameter ``element``:
    IN The element to extract the point from.

Parameter ``pointNum``:
    IN The index of point to extract.

Parameter ``maxPoints``:
    IN The maximum number of associative points on the element.

Returns:
    SUCCESS if associative point was extracted.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitIntersection =R"doc(Initialize the data in the associative point for an association that
represents the intersection of 2 curve paths.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``index``:
    IN The index of the intersection between the two elements where
    the association will be created. The number of intersections
    between two elements can be found via the
    mdlIntersect_allBetweenElms function.

Parameter ``seg1``:
    IN The index of the segment of element 1 where the intersection
    occurs.

Parameter ``seg2``:
    IN The index of the segment of element 2 where the intersection
    occurs.

Parameter ``nSeg1``:
    IN The number of vertices of element 1. This parameter is
    optional, you can pass zero. If non-zero this value is used to
    avoid the association jumping as vertices are inserted/deleted.

Parameter ``nSeg2``:
    IN The number of vertices of element 2. This parameter is
    optional, you can pass zero. If non-zero this value is used to
    avoid the association jumping as vertices are inserted/deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitMeshVertex =R"doc(Initialize the data in the associative point for an association that
represents a mesh vertex.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``vertexIndex``:
    IN he index of the vertex for the association point.

Parameter ``nVertex``:
    IN The total number of vertices of the mesh element.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitMeshEdge =R"doc(Initialize the data in the associative point for an association that
represents a point on a mesh edge.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``edgeIndex``:
    IN The index of the edge for the association point.

Parameter ``nEdge``:
    IN The total number of edges of the mesh element.

Parameter ``uParam``:
    IN The parameter along the mesh edge representing the associative
    point.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitBSurface =R"doc(Initialize the data in the associative point for an association that
represents a point on a bspline surface.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``uParam``:
    IN The u parameter along the B-spline surface representing the
    associative point.

Parameter ``vParam``:
    IN The v parameter along the B-spline surface representing the
    associative point.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitBCurve =R"doc(Initialize the data in the associative point for an association that
represents a point on a bspline curve.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``uParam``:
    IN The parameter along the B-spline curve representing the
    associative point.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitMline =R"doc(Initialize the data in the associative point for an association that
represents a point on a multiline element.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``vertex``:
    IN The index of the vertex directly preceding the association
    point.

Parameter ``nVertex``:
    IN The total number of vertices of the multiline element. This is
    optional, but if supplied the association can be adjusted for
    insert/delete vertex on the root/target multiline.

Parameter ``lineNo``:
    IN Indicates which profile line in the multiline the association
    is to.

Parameter ``offset``:
    IN The distance from the specified vertex to the association
    point, measured along the work line and divided by the work line
    length. Not used if joint is true.

Parameter ``joint``:
    IN If true, the association point is at the intersection of the
    line specified by lineNo and the joint bvector at vertex. In other
    words, the association point will always be on the joint.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitProjection =R"doc(Initialize the data in the associative point for an association that
represents a point on a linear element.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``vertex``:
    IN The index of the vertex directly preceding the association
    point.

Parameter ``nVertex``:
    IN The total number of vertices of the linear element. This is
    optional, but if supplied the association can be adjusted for
    insert/delete vertex on the root/target.

Parameter ``ratio``:
    IN Fraction parameter along segment defined by vertex number.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitArc =R"doc(Initialize the data in the associative point for an association that
represents a point on an arc or ellipse element.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``keyPoint``:
    IN The location on the arc to create the association to. \li
    ARC_ANGLE angle radians from the primary axis \li ARC_CENTER
    center of the arc or ellipse \li ARC_START arc start point \li
    ARC_END arc end point <p>

Parameter ``angle``:
    IN The angle (radians) from the primary axis of the arc or ellipse
    to the association point. This argument is used only when the
    value of *keyPoint* is <PRE>ARC_ANGLE</PRE>.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitOrigin =R"doc(Initialize the data in the associative point for an association that
represents the origin of an element.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``option``:
    IN Origin association option flag.

See also:
    DisplayHandler::GetSnapOrigin)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_InitKeypoint =R"doc(Initialize the data in the associative point for an association that
represents a point on a linear element.

Parameter ``assocPoint``:
    OUT The associative point to setup.

Parameter ``vertex``:
    IN The index of the vertex directly preceding the association
    point.

Parameter ``nVertex``:
    IN The total number of vertices of the linear element. This is
    optional, but if supplied the association can be adjusted for
    insert/delete vertex on the root/target.

Parameter ``numerator``:
    IN The distance from vertex number vertex in units of divisor as
    described below. Its range must be between 0 and 32767.

Parameter ``divisor``:
    IN The number of units (segments) to be considered between the
    points at vertex and vertex+1. The values of numerator and divisor
    are used together as the fraction of the distance between the
    points at vertex and vertex+1, where the association point will be
    located. The denominator must be between 1 and 32767.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_GetRoot =R"doc(Populate a seed DisplayPath for a root of an associative point
dependency.

Parameter ``path``:
    IN OUT The seed DisplayPath that is to be populated.

Parameter ``nRootsP``:
    OUT The number of roots for this associative point, an
    intersection association will return 2, all other types return 1.

Parameter ``assocPoint``:
    IN The associative point to query.

Parameter ``modelRef``:
    IN The model that contains the associative point dependent
    element.

Parameter ``rootIndex``:
    IN Which root to get, an intersection association has 2 roots.

Returns:
    A DisplayPath to associative point root or NULL. Caller needs to
    call Release on path.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_SetRoot =R"doc(Complete setup of a new associative point by setting the target/root
element for the dependency by a pair of element ids.

Parameter ``assocPoint``:
    IN The associative point being created.

Parameter ``elemId``:
    IN ElementId of the target/root of the associative point
    dependency.

Parameter ``refAttId``:
    IN ElementId of a top-level reference, an un-nested shared cell
    instance, far path element, or 0. Only needed if elemId is a
    component of a shared cell definition or in a reference, if elemId
    is from the same model as the element the association is being
    added to pass 0.

Parameter ``rootIndex``:
    IN Which root to set, an intersection association requires 2
    roots.

Returns:
    SUCCESS if assoc point root can be set. @note Must call one of the
    various Init methods before setting roots, ex. InitKeypoint.)doc";

static const char * __doc_Bentley_DgnPlatform_AssociativePoint_IsValid =R"doc(Test if the associative point evaluates to a valid location.

Parameter ``assocPoint``:
    IN The associative point to check.

Parameter ``pathRoot``:
    IN The model that contains an associative point root element (can
    use either root for intersection).

Parameter ``parentModel``:
    IN The model that contains the associative point dependent
    element.

Returns:
    SUCCESS if assoc point data and roots are valid.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_AssociativePoint(py::module_& m)
    {
    //===================================================================================
    // struct AssociativePoint
    py::class_< AssociativePoint> c1(m, "AssociativePoint");

    if (true)
        {
        //===================================================================================
        // enum CreateOptions
        py::enum_< AssociativePoint::CreateOptions>(c1, "CreateOptions", py::arithmetic())
            .value("eCREATE_ASSOC_Normal", AssociativePoint::CREATE_ASSOC_Normal)
            .value("eCREATE_ASSOC_DisallowFarElm", AssociativePoint::CREATE_ASSOC_DisallowFarElm)
            .value("eCREATE_ASSOC_DisallowCustom", AssociativePoint::CREATE_ASSOC_DisallowCustom)
            .value("eCREATE_ASSOC_AllowAdjustedPoints", AssociativePoint::CREATE_ASSOC_AllowAdjustedPoints)
            .export_values();

        //===================================================================================
        // enum CreateMask
        py::enum_< AssociativePoint::CreateMask>(c1, "CreateMask")
            .value("eCREATE_ASSOC_MASK_DIMENSION", AssociativePoint::CREATE_ASSOC_MASK_DIMENSION)
            .value("eCREATE_ASSOC_MASK_MLINE", AssociativePoint::CREATE_ASSOC_MASK_MLINE)
            .value("eCREATE_ASSOC_MASK_CELLS", AssociativePoint::CREATE_ASSOC_MASK_CELLS)
            .value("eCREATE_ASSOC_MASK_LINEAR", AssociativePoint::CREATE_ASSOC_MASK_LINEAR)
            .value("eCREATE_ASSOC_MASK_NOTE", AssociativePoint::CREATE_ASSOC_MASK_NOTE)
            .value("eCREATE_ASSOC_MASK_TEXT", AssociativePoint::CREATE_ASSOC_MASK_TEXT)
            .export_values();

        //===================================================================================
        // enum ArcLocation
        py::enum_<AssociativePoint::ArcLocation>(c1, "ArcLocation")
            .value("eARC_ANGLE", AssociativePoint::ARC_ANGLE)
            .value("eARC_CENTER", AssociativePoint::ARC_CENTER)
            .value("eARC_START", AssociativePoint::ARC_START)
            .value("eARC_END", AssociativePoint::ARC_END)
            .export_values();
        }


    c1.def_static("IsValid", &AssociativePoint::IsValid, "assocPoint"_a, "pathRoot"_a, "parentModel"_a, DOC(Bentley, DgnPlatform, AssociativePoint, IsValid));

    c1.def_static("SetRoot", 
                  py::overload_cast<AssocPointR, ElementId, ElementId, int>(&AssociativePoint::SetRoot),
                  "assocPoint"_a, "elemId"_a, "refAttId"_a, "rootIndex"_a = 0, DOC(Bentley, DgnPlatform, AssociativePoint, SetRoot));

    c1.def_static("SetRoot",
                  py::overload_cast<AssocPointR, DisplayPathCP, DgnModelRefP, bool, int>(&AssociativePoint::SetRoot),
                  "assocPoint"_a, "path"_a, "parentModel"_a, "allowFarElm"_a, "rootIndex"_a = 0, DOC(Bentley, DgnPlatform, AssociativePoint, SetRoot));

    c1.def_static("GetRoot", [] (DisplayPathP path, AssocPointCR assocPoint, DgnModelRefP modelRef, int rootIndex)
                  {
                  int nRootsP = 0;
                  auto retVal = AssociativePoint::GetRoot(path, &nRootsP, assocPoint, modelRef, rootIndex);
                  return py::make_tuple(retVal, nRootsP);
                  }, "path"_a, "assocPoint"_a, "modelRef"_a, "rootIndex"_a = 0, DOC(Bentley, DgnPlatform, AssociativePoint, GetRoot));

    c1.def_static("InitKeypoint", &AssociativePoint::InitKeypoint, "assocPoint"_a, "vertex"_a, "nVertex"_a, "numerator"_a, "divisor"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitKeypoint));    
    c1.def_static("InitOrigin", &AssociativePoint::InitOrigin, "assocPoint"_a, "option"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitOrigin));    
    c1.def_static("InitArc", &AssociativePoint::InitArc, "assocPoint"_a, "keyPoint"_a, "angle"_a = 0.0, DOC(Bentley, DgnPlatform, AssociativePoint, InitArc));    
    c1.def_static("InitProjection", &AssociativePoint::InitProjection, "assocPoint"_a, "vertex"_a, "nVertex"_a, "ratio"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitProjection));    
    c1.def_static("InitMline", &AssociativePoint::InitMline, "assocPoint"_a, "vertex"_a, "nVertex"_a, "lineNo"_a, "offset"_a, "joint"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitMline));    
    c1.def_static("InitBCurve", &AssociativePoint::InitBCurve, "assocPoint"_a, "uParam"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitBCurve));    
    c1.def_static("InitBSurface", &AssociativePoint::InitBSurface, "assocPoint"_a, "uParam"_a, "vParam"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitBSurface));    
    c1.def_static("InitMeshEdge", &AssociativePoint::InitMeshEdge, "assocPoint"_a, "edgeIndex"_a, "nEdge"_a, "uParam"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitMeshEdge));    
    c1.def_static("InitMeshVertex", &AssociativePoint::InitMeshVertex, "assocPoint"_a, "vertexIndex"_a, "nVertex"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitMeshVertex));    
    c1.def_static("InitIntersection", &AssociativePoint::InitIntersection, "assocPoint"_a, "index"_a, "seg1"_a, "seg2"_a, "nSeg1"_a, "nSeg2"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InitIntersection));    
    c1.def_static("ExtractPoint", &AssociativePoint::ExtractPoint, "assocPoint"_a, "element"_a, "pointNum"_a, "maxPoints"_a, DOC(Bentley, DgnPlatform, AssociativePoint, ExtractPoint));    
    c1.def_static("InsertPoint", &AssociativePoint::InsertPoint, "element"_a, "assocPoint"_a, "pointNum"_a, "maxPoints"_a, DOC(Bentley, DgnPlatform, AssociativePoint, InsertPoint));    
    c1.def_static("GetPoint", &AssociativePoint::GetPoint, "outPoint"_a, "assocPoint"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, AssociativePoint, GetPoint));    
    c1.def_static("RemovePoint", &AssociativePoint::RemovePoint, "element"_a, "pointNum"_a, "maxPoints"_a, DOC(Bentley, DgnPlatform, AssociativePoint, RemovePoint));    
    c1.def_static("RemoveAllAssociations", &AssociativePoint::RemoveAllAssociations, "element"_a, DOC(Bentley, DgnPlatform, AssociativePoint, RemoveAllAssociations));    
    c1.def_static("RegisterExtensions", &AssociativePoint::RegisterExtensions, DOC(Bentley, DgnPlatform, AssociativePoint, RegisterExtensions));
    }