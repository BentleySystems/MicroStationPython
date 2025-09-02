/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\multilinehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/MultilineHandler.h>



static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetPlacementOffset =R"doc(Set the offset distance stored on the multi-line element. It
represents the distance between the Work Line (profile offset of zero)
and the line that the user drew to place the multi-line. This value is
only used if the Offset Mode is MlineOffsetMode::Custom. This distance
will be used if the style is reapplied; it does not modify the current
profile locations.

:param element:
    multiline element

:param placementOffset:
    distance for multiline)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetOffsetMode =R"doc(Set the Offset Mode stored on the multi-line element. This mode will
be used if the style is reapplied. Note that this does not modify the
current profile locations.

:param element:
    multiline element

:param offsetMode:
    for multiline)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_ApplyStyle =R"doc(Apply a multiline style to a given multiline element.

:param element:
    The element to update.

:param mlineStyle:
    The style to apply

:param styleScale:
    The scale for the style. Scale applies to the multi-line profile
    offsets.

:returns:
    true if eeh is the correct type and the element was updated. @note
    To query the multiline element's Z bvector use
    DisplayHandler::IsPlanar)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetProfile =R"doc(Replace a multiline profile

:param element:
    The element to update.

:param index:
    The index of the profile to replace. The multiline must already
    have a profile at this index.

:param profile:
    The new profile

:returns:
    SUCCESS if element is the correct type, the profile index is
    within range, and the element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetMidCap =R"doc(Replace the symbology of the multiline middle or joint cap geometry.

:param element:
    The element to update.

:param capSymbology:
    The new symbology

:returns:
    SUCCESS if element is the correct type and the element was
    updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetEndCap =R"doc(Replace the symbology of the multiline end cap geometry.

:param element:
    The element to update.

:param capSymbology:
    The new symbology

:returns:
    SUCCESS if element is the correct type and the element was
    updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetOriginCap =R"doc(Replace the symbology of the multiline origin cap geometry.

:param element:
    The element to update.

:param capSymbology:
    The new symbology

:returns:
    SUCCESS if element is the correct type and the element was
    updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetClosed =R"doc(Set the closed property of a multiline element.

:param element:
    The element to update.

:param isClosed:
    new closure status.

:returns:
    SUCCESS if element's closure status was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetZVector =R"doc(Set the z axis of a 3d multiline element. The element is planar, and
this bvector defines that plane.

:param element:
    The element to update.

:param normal:
    new z axis of multiline element.

:returns:
    SUCCESS if element is the correct type and the element was
    updated. @note To query the multiline element's Z bvector use
    DisplayHandler::IsPlanar)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_DeleteBreak =R"doc(Delete a break from the multiline definition.

:param element:
    source element

:param segment:
    which segment the break is on

:param breakNo:
    which break on the segment it is

:returns:
    SUCCESS if the element is a multiline and the break currently
    exists.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_InsertBreak =R"doc(Replace a break in the multiline definition.

:param element:
    source element

:param mlbreak:
    break to replace

:param segment:
    which segment the break is on

:returns:
    SUCCESS if the element is a multiline and the break currently
    exists.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetEndAngle =R"doc(Set the end cap angle for the multiline. PI/2 is perpindicular.

:param element:
    source element

:param angle:
    New angle in radians

:returns:
    SUCCESS if the element is a multiline.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_SetOriginAngle =R"doc(Set the origin or start cap angle for the multiline. PI/2 is
perpindicular.

:param element:
    source element

:param angle:
    New angle in radians

:returns:
    SUCCESS if the element is a multiline.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_DeletePoint =R"doc(Delete point in the multiline definition.

:param element:
    source element

:param pointNum:
    index to delete point.

:returns:
    SUCCESS if the element is a multiline and the point was deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_InsertPoint =R"doc(Insert point in the multiline definition.

:param element:
    source element

:param newPoint:
    point to add

:param assocPointP:
    associative point for this mline point. NULL to use a normal point
    from newPoint.

:param pointNum:
    index to insert point. -1 means at the end.

:returns:
    SUCCESS if the element is a multiline and the point was inserted.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineEdit_ReplacePoint =R"doc(Replace point in the multiline definition. If you want to replace a
point and drop Association, then specify the
MlineModifyPoint::RemoveAssociations option; otherwise you cannot
replace an Associative Point. To make a point Associative, use
DeletePoint followed by InsertPoint.

:param element:
    source element

:param newPoint:
    point to replace

:param pointNum:
    index to replace

:param options:
    replace option flags - see enum MlineModifyPoint

:returns:
    SUCCESS if the element is a multiline and the point currently
    exists.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetPlacementOffset =R"doc(Get the Offset Distance stored on the multi-line element. Note that
this is only valid for a Offset Mode of MlineOffsetMode::Custom.

:param source:
    multiline element

:returns:
    multiline offset distance)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetOffsetMode =R"doc(Get the Offset Mode stored on the multi-line element

:param source:
    multiline element

:returns:
    multiline offset mode)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetStyleScale =R"doc(Get the style scale stored on the multi-line element

:param source:
    multiline element

:returns:
    multiline style scale)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetStyle =R"doc(Get an object representing the style of a multiline element. In
general, the properties of the returned style object may differ from
the file's version of the same style.

:param source:
    multiline element

:param seedStyle:
    multiline style to use as a seed. This is copied into the new
    style, and then all salient properties from the multi-line are
    applied on top. For example if the multi-line doesn't use a color
    for profile 1 but there is a color in the seed style, then that
    color will appear in the resulting style.

:param options:
    multiline style options - currently 0 or MLINE_MATCH_ENDCAPS.

:returns:
    multiline style)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_ExtractPoints =R"doc(Extract the array of points from a multi-line. These represent the
workline of the multi-line, and may not correspond to anything
displayed.

:param source:
    source element

:param pXYZBuffer:
    (optional) buffer for points.



Returns (Tuple, 0):
    SUCCESS if the element is a multiline.

Returns (Tuple, 1):
	numPoints. number of points

)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_ExtractCapJointDefinition =R"doc(Extract a multiline cap joint definition for a given segment of the
multiline.

:param source:
    source element

:param pts:
    start and end points of line segment.

:param pointNo:
    cap joint, 0 for org and 1 for end.

:returns:
    A joint definition)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_ExtractJointDefinition =R"doc(Extract a multiline joint definition for a given segment of the
multiline.

:param source:
    source element

:param pts:
    base point array from ExtractPoints.

:param pointNo:
    index of first point.

:returns:
    A joint definition)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetBreak =R"doc(Get a pointer to a multiline break based on the segment of the
multiline.

:param source:
    source element

:param segmentNumber:
    Segment to find break

:param segBreakNumber:
    Which break on that segment

:returns:
    A pointer to the a copy of the break. Be sure to check isValid()
    on the return in case the break doesn't exist.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetBreakCount =R"doc(Get the number of breaks on a multline.

:param source:
    source element

:returns:
    The number of breaks)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetPointCount =R"doc(Query the number of points in the multiline element.

:param source:
    source element

:returns:
    multiline point count)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetPoint =R"doc(Get a pointer to the first MlinePoint definition.

:param source:
    source element

:param pointNumber:
    point index to return

:returns:
    A pointer to the first MlinePoint definition)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetEndAngle =R"doc(Get the end cap angle for the multiline

:param source:
    source element

:returns:
    The angle in radians)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetOriginAngle =R"doc(Get the origin or start cap angle for the multiline

:param source:
    source element

:returns:
    The angle in radians)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetMidCap =R"doc(Query the symbology of the multiline middle or joint cap.

:param source:
    source element

:returns:
    A copy of the cap symbology)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetEndCap =R"doc(Query the symbology of the multiline end cap.

:param source:
    source element

:returns:
    A copy of the cap symbology)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetOriginCap =R"doc(Query the symbology of the multiline origin cap.

:param source:
    source element

:returns:
    A copy of the cap symbology)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetProfile =R"doc(Query a profile line definition. The profile definition defines the
offset from the base profile line as well as the symbology of the
profile line.

:param source:
    source element

:param index:
    number of profile line to extract

:returns:
    A pointer to the MlineProfile definition.)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_GetProfileCount =R"doc(Query the number of profile lines in the multiline element.

:param source:
    source element

:returns:
    multiline profile count)doc";

static const char * __doc_Bentley_DgnPlatform_IMultilineQuery_IsClosed =R"doc(Query if the multiline element represents a closed path.

:param source:
    source element

:returns:
    true for a closed multiline)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_ProfileIsMasked =R"doc(Determine if a given profile is affected by this break. This is just a
convenience routine that does the bit comparisons. Profiles are
0-based.

:param profileNum:
    Profile to test.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_SetProfileMask =R"doc(Get the profile mask for the breaks. Each bit represents a profile.
Bits are in profile order, not in any spatial order.

:param lineMask:
    The new mask for the break.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_GetProfileMask =R"doc(Get the profile mask for the breaks. Each bit represents a profile.
Bits are in profile order, not in any spatial order.

:returns:
    The profile mask of the break)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_SetOffset =R"doc(Get the offset from the first point in the segment. The offset is
always along the workline, regardless of angle. This value is ignored
if the the MlineBreakLengthType is MLBREAK_FROM_JOINT or
MLBREAK_BETWEEN_JOINTS.

:param offset:
    The new offset for the break.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_GetOffset =R"doc(Get the offset from the first point in the segment. The offset is
always along the workline, regardless of angle. This value is ignored
if the the MlineBreakLengthType is MLBREAK_FROM_JOINT or
MLBREAK_BETWEEN_JOINTS.

:returns:
    The offset along the segment of the break)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_SetLength =R"doc(Set the length from the multi-line break. This value is ignored if the
the MlineBreakLengthType is MLBREAK_TO_JOINT or
MLBREAK_BETWEEN_JOINTS.

:param length:
    The new length of the break.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_GetLength =R"doc(Get the length from the multi-line break. This value is ignored if the
the MlineBreakLengthType is MLBREAK_TO_JOINT or
MLBREAK_BETWEEN_JOINTS.

:returns:
    The length of the break)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_SetLengthType =R"doc(Set the length flags from the multi-line break. This flag determines
whether the break extends from one or both of the points, or just has
a fixed length.

:param type:
    The new type.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineBreak_GetLengthType =R"doc(Get the length flags from the multi-line break. This flag determines
whether the break extends from one or both of the points, or just has
a fixed length.

:returns:
    The current type)doc";

static const char * __doc_Bentley_DgnPlatform_MultilinePoint_GetNumBreaks =R"doc(Get the number of breaks on the segment that begins witn this point

:returns:
    The number of breaks between this point and the subsequent point)doc";

static const char * __doc_Bentley_DgnPlatform_MultilinePoint_IsAssociative =R"doc(Determine if a MultilinePoint is associative

:returns:
    True if the point is associative.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilinePoint_SetPoint =R"doc(Set the X,Y,Z coordinates for a MultilinePoint

:param point:
    The coordinates of the point)doc";

static const char * __doc_Bentley_DgnPlatform_MultilinePoint_GetPoint =R"doc(Get the X,Y,Z coordinates from a MultilinePoint

:returns:
    The X,Y,Z coordinates)doc";

static const char * __doc_Bentley_DgnPlatform_MultilinePoint_CreateFromPoint =R"doc(Create a multi-line point from X,Y,Z coordinates

:param point:
    The coordinates of the point

:returns:
    a MultilinePoint)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MultilineHandler(py::module_& m)
    {
    //===================================================================================
    // struct MultilinePoint
    py::class_< MultilinePoint, MultilinePointPtr> c1(m, "MultilinePoint");

    c1.def_static("CreateFromPoint", py::overload_cast<DPoint3dCR>(&MultilinePoint::CreateFromPoint), "point"_a, DOC(Bentley, DgnPlatform, MultilinePoint, CreateFromPoint));
    
    c1.def_property("Point", &MultilinePoint::GetPoint, &MultilinePoint::SetPoint);
    c1.def("GetPoint", &MultilinePoint::GetPoint, DOC(Bentley, DgnPlatform, MultilinePoint, GetPoint));
    c1.def("SetPoint", &MultilinePoint::SetPoint, "point"_a, DOC(Bentley, DgnPlatform, MultilinePoint, SetPoint));
    
    c1.def("IsAssociative", &MultilinePoint::IsAssociative, DOC(Bentley, DgnPlatform, MultilinePoint, IsAssociative));
    
    c1.def_property_readonly("NumBreaks", &MultilinePoint::GetNumBreaks);       
    c1.def("GetNumBreaks", &MultilinePoint::GetNumBreaks, DOC(Bentley, DgnPlatform, MultilinePoint, GetNumBreaks));       

    //===================================================================================
    // struct MultilineBreak
    py::class_< MultilineBreak, MultilineBreakPtr> c2(m, "MultilineBreak");

    c2.def(py::init(py::overload_cast<double, MlineBreakLengthType, double, UInt32>(&MultilineBreak::Create)), "offset"_a, "lengthType"_a, "length"_a, "profileMask"_a);
    
    c2.def_property("LengthType", &MultilineBreak::GetLengthType, &MultilineBreak::SetLengthType);
    c2.def("GetLengthType", &MultilineBreak::GetLengthType, DOC(Bentley, DgnPlatform, MultilineBreak, GetLengthType));
    c2.def("SetLengthType", &MultilineBreak::SetLengthType, "type"_a, DOC(Bentley, DgnPlatform, MultilineBreak, SetLengthType));
    
    c2.def_property("Length", &MultilineBreak::GetLength, &MultilineBreak::SetLength);
    c2.def("GetLength", &MultilineBreak::GetLength, DOC(Bentley, DgnPlatform, MultilineBreak, GetLength));
    c2.def("SetLength", &MultilineBreak::SetLength, "length"_a, DOC(Bentley, DgnPlatform, MultilineBreak, SetLength));
    
    c2.def_property("Offset", &MultilineBreak::GetOffset, &MultilineBreak::SetOffset);
    c2.def("GetOffset", &MultilineBreak::GetOffset, DOC(Bentley, DgnPlatform, MultilineBreak, GetOffset));
    c2.def("SetOffset", &MultilineBreak::SetOffset, "offset"_a, DOC(Bentley, DgnPlatform, MultilineBreak, SetOffset));
    
    c2.def_property("ProfileMask", &MultilineBreak::GetProfileMask, &MultilineBreak::SetProfileMask);
    c2.def("GetProfileMask", &MultilineBreak::GetProfileMask, DOC(Bentley, DgnPlatform, MultilineBreak, GetProfileMask));
    c2.def("SetProfileMask", &MultilineBreak::SetProfileMask, "mask"_a, DOC(Bentley, DgnPlatform, MultilineBreak, SetProfileMask));
    
    c2.def("ProfileIsMasked", &MultilineBreak::ProfileIsMasked, "profileNum"_a, DOC(Bentley, DgnPlatform, MultilineBreak, ProfileIsMasked));

    //===================================================================================
    // struct IMultilineQuery
    py::class_< IMultilineQuery, std::unique_ptr< IMultilineQuery, py::nodelete> > c3(m, "IMultilineQuery");

    c3.def("IsClosed", &IMultilineQuery::IsClosed, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, IsClosed));
    c3.def("GetProfileCount", &IMultilineQuery::GetProfileCount, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetProfileCount));
    c3.def("GetProfile", &IMultilineQuery::GetProfile, "source"_a, "index"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetProfile));
    c3.def("GetOriginCap", &IMultilineQuery::GetOriginCap, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetOriginCap));
    c3.def("GetEndCap", &IMultilineQuery::GetEndCap, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetEndCap));
    c3.def("GetMidCap", &IMultilineQuery::GetMidCap, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetMidCap));
    c3.def("GetOriginAngle", &IMultilineQuery::GetOriginAngle, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetOriginAngle));
    c3.def("GetEndAngle", &IMultilineQuery::GetEndAngle, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetEndAngle));
    c3.def("GetPoint", &IMultilineQuery::GetPoint, "source"_a, "pointNumber"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetPoint));
    c3.def("GetPointCount", &IMultilineQuery::GetPointCount, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetPointCount));
    c3.def("GetBreakCount", &IMultilineQuery::GetBreakCount, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetBreakCount));
    c3.def("GetBreak", &IMultilineQuery::GetBreak, "source"_a, "segmentNumber"_a, "segBreakNumber"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetBreak));

    c3.def("ExtractJointDefinition", [] (IMultilineQuery const& self, ElementHandleCR source, DPoint3dArray const& points, int pointNo)
           {
           return self.ExtractJointDefinition(source, points.data(), pointNo);
           }, "source"_a, "points"_a, "pointNo"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, ExtractJointDefinition));

    c3.def("ExtractJointDefinition", [] (IMultilineQuery const& self, ElementHandleCR source, py::list const& points, int pointNo)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
           return self.ExtractJointDefinition(source, cppPoints.data(), pointNo);
           }, "source"_a, "points"_a, "pointNo"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, ExtractJointDefinition));

    c3.def("ExtractCapJointDefinition", [] (IMultilineQuery const& self, ElementHandleCR source, DPoint3dArray const& points, int pointNo)
           {
           return self.ExtractCapJointDefinition(source, points.data(), pointNo);
           }, "source"_a, "points"_a, "pointNo"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, ExtractCapJointDefinition));

    c3.def("ExtractCapJointDefinition", [] (IMultilineQuery const& self, ElementHandleCR source, py::list const& points, int pointNo)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
           return self.ExtractCapJointDefinition(source, cppPoints.data(), pointNo);
           }, "source"_a, "points"_a, "pointNo"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, ExtractCapJointDefinition));

    c3.def("ExtractPoints", [] (IMultilineQuery const& self, ElementHandleCR source, DPoint3dArray& points)
           {
           size_t numPoints = 0;
           auto retVal = self.ExtractPoints(source, points.data(), numPoints, points.size());
           return py::make_tuple(retVal, numPoints);
           }, "source"_a, "points"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, ExtractPoints));

    c3.def("ExtractPoints", [] (IMultilineQuery const& self, ElementHandleCR source, py::list& points)
           {
           size_t numPoints = 0;
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
           auto retVal = self.ExtractPoints(source, cppPoints.data(), numPoints, cppPoints.size());
           CONVERT_CPPARRAY_TO_PYLIST(points, cppPoints, DPoint3dArray, DPoint3d);
           return py::make_tuple(retVal, numPoints);
           }, "source"_a, "points"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, ExtractPoints));

    c3.def("GetStyle", &IMultilineQuery::GetStyle, "source"_a, "seedStyle"_a, "options"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetStyle));
    c3.def("GetStyleScale", &IMultilineQuery::GetStyleScale, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetStyleScale));
    c3.def("GetOffsetMode", &IMultilineQuery::GetOffsetMode, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetOffsetMode));
    c3.def("GetPlacementOffset", &IMultilineQuery::GetPlacementOffset, "source"_a, DOC(Bentley, DgnPlatform, IMultilineQuery, GetPlacementOffset));

    //===================================================================================
    // struct IMultilineEdit
    py::class_< IMultilineEdit, std::unique_ptr< IMultilineEdit, py::nodelete>, IMultilineQuery> c4(m, "IMultilineEdit");

    c4.def("ReplacePoint", &IMultilineEdit::ReplacePoint, "eeh"_a, "newPoint"_a, "pointNum"_a, "options"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, ReplacePoint));
    c4.def("InsertPoint", &IMultilineEdit::InsertPoint, "eeh"_a, "newPoint"_a, "assocPoint"_a, "pointNum"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, InsertPoint));
    c4.def("DeletePoint", &IMultilineEdit::DeletePoint, "eeh"_a, "pointNum"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, DeletePoint));
    c4.def("SetOriginAngle", &IMultilineEdit::SetOriginAngle, "eeh"_a, "angle"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetOriginAngle));
    c4.def("SetEndAngle", &IMultilineEdit::SetEndAngle, "eeh"_a, "angle"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetEndAngle));
    c4.def("InsertBreak", &IMultilineEdit::InsertBreak, "eeh"_a, "mlBreak"_a, "segment"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, InsertBreak));
    c4.def("DeleteBreak", &IMultilineEdit::DeleteBreak, "eeh"_a, "segment"_a, "breakNo"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, DeleteBreak));
    c4.def("SetZVector", &IMultilineEdit::SetZVector, "eeh"_a, "normal"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetZVector));
    c4.def("SetClosed", &IMultilineEdit::SetClosed, "eeh"_a, "isClosed"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetClosed));
    c4.def("SetOriginCap", &IMultilineEdit::SetOriginCap, "eeh"_a, "capSymbology"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetOriginCap));
    c4.def("SetEndCap", &IMultilineEdit::SetEndCap, "eeh"_a, "capSymbology"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetEndCap));
    c4.def("SetMidCap", &IMultilineEdit::SetMidCap, "eeh"_a, "capSymbology"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetMidCap));
    c4.def("SetProfile", &IMultilineEdit::SetProfile, "eeh"_a, "index"_a, "profile"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetProfile));
    c4.def("ApplyStyle", &IMultilineEdit::ApplyStyle, "eeh"_a, "mlineStyle"_a, "styleScale"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, ApplyStyle));
    c4.def("SetOffsetMode", &IMultilineEdit::SetOffsetMode, "eeh"_a, "offsetMode"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetOffsetMode));
    c4.def("SetPlacementOffset", &IMultilineEdit::SetPlacementOffset, "eeh"_a, "placementOffset"_a, DOC(Bentley, DgnPlatform, IMultilineEdit, SetPlacementOffset));

    //===================================================================================
    // struct MultilineHandler
    py::class_< MultilineHandler, std::unique_ptr< MultilineHandler, py::nodelete>, DisplayHandler, IMultilineEdit, IAreaFillPropertiesEdit> c5(m, "MultilineHandler");

    c5.def_static("CreateMultilineElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, MultilineStyleCR mlineStyle, double styleScale, DVec3dCR normal, DPoint3dArray const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  return MultilineHandler::CreateMultilineElement(eeh, templateEh, mlineStyle, styleScale, normal, points.data(), (int) points.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "mlineStyle"_a, "styleScale"_a, "normal"_a, "points"_a, "is3d"_a, "modelRef"_a);

    c5.def_static("CreateMultilineElement", [] (EditElementHandleR eeh, ElementHandleCP templateEh, MultilineStyleCR mlineStyle, double styleScale, DVec3dCR normal, py::list const& points, bool is3d, DgnModelRefR modelRef)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
                  return MultilineHandler::CreateMultilineElement(eeh, templateEh, mlineStyle, styleScale, normal, cppPoints.data(), (int) cppPoints.size(), is3d, modelRef);
                  }, "eeh"_a, "templateEh"_a, "mlineStyle"_a, "styleScale"_a, "normal"_a, "points"_a, "is3d"_a, "modelRef"_a);
    }