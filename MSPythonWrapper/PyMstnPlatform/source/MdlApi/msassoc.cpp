/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msasoc.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msassoc.fdf>



static const char * __doc_MstnPlatform_Assoc_TagElementDescr =R"doc(@Description Get the tag value from an element at the specified offset
within the specified element descriptor. If the specified element does
not have a tag, then it is assigned a tag and the new tag value is
returned in the newTagP argument. This function will return an error
if the element descriptor has the complex bit set.

@Param(output) newTagP is the new tag created by the function.
@Param[in,out] elDscrP is the element descriptor to which the tag is
added. @Param(input) modelRef indicates the model containing the element
receiving the tag. @Return SUCCESS if the operation is completed
successfully, otherwise ERROR

See also:
    Assoc.TagElementValue

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_StripTag =R"doc(@Description Remove an association tag from a single element

@Param(input) elemP element to strip tag from @Return SUCCESS if the
operation is complete successfully, ERROR otherwise

See also:
    Assoc.StripTags

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_GetCurrent =R"doc(@Description Gets the current associative point.

@Param(output) assoc the current association point @Param(output) pointP
location of current association @Param(input) option Option (pass zero)
@Param(input) createMask element categories not to create associations
for, use ASSOC_CREATE_MASK_ defines or pass 0 to not restrict allowed
associations. For example to create an associative dimension you would
want to check that dimension associations are enabled so you would
pass ASSOC_CREATE_MASK_DIMENSION. @Return true if associative point
returned

See also:
    Assoc.ExtractPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateBCurve =R"doc(@Description Creates an association that represents a point along a
B-spline curve.

@Param(output) assoc If a valid association is created, the association
information is returned in assoc. @Param(input) u the parameter along the
B-spline curve representing the associative point. @Param(input) path
display path for the element. @Param(input) elemId used if path is
NULL...i.e. creating assoc to element that has @Return SUCCESS (zero)
if it is able to create a valid association. Otherwise, it returns a
non-zero value.

See also:
    Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateOrigin =R"doc(@Description Creates an association that represents the origin of the
base element. Origin associations can currently be created for cell
headers, shared cells, text nodes and text elements. For elements
other than these, an associative point representing the lower left-
hand corner of the range block for the element is created.

@Param(output) assoc If a valid association is created, the association
information is returned in assoc. @Param(input) option Origin of
association options. @Param(input) path display path for the element.
@Param(input) elemId used if path is NULL...i.e. creating assoc to
element that has @Return SUCCESS (zero) if it is able to create a
valid association. Otherwise, it returns a non-zero value.

See also:
    Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateMline =R"doc(@Description Creates an association that represents a point on a
multi-line element.

@Param(output) assoc If a valid association is created, the association
information is returned in assoc. @Param(input) vertex the index of the
vertex directly preceding or at the association point. @Param(input)
nVertex the total number of vertices of the linear element. This
parameter is optional, you can pass zero. If non-zero this value is
used to avoid the association jumping as vertices are
inserted/deleted. @Param(input) lineNo indicates which line in the multi-
line is the association's object. This value is an index into the
multi-line profile information that was copied into the multi-line
from the tcb when the multi-line was created. @Param(input) offset the
distance from the specified vertex to the association point, measured
along the work line and divided by the work line length. The
information needed to calculate this parameter can be obtained using
the Vec.... functions. offset is not used if joint is set to true.
@Param(input) joint If joint is true, the association point is at the
intersection of the line specified by lineNo and the joint vector is
at vertex. In other words, the association point will always be on the
joint. @Param(input) path display path for the element. @Param(input) elemId
used if path is NULL...i.e. creating assoc to element that has @Return
SUCCESS (zero) if it is able to create a valid association. Otherwise,
it returns a non-zero value.

See also:
    Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateIntersection =R"doc(@Description Create an intersection association between the two
elements identified by the elemId1 and elemId2 parameters.

@Param(output) assoc is the intersection association created by the
operation. @Param(input) index is the index of the intersection between
the two elements where the association will be created. The number of
intersections between two elements can be found via the
Intersect.AllBetweenElms function. @Param(input) seg1 is the index of
the segment of element 1 where the intersection occurs. @Param(input)
seg2 is the index of the segment of element 2 where the intersection
occurs. @Param(input) nSeg1 the number of vertices of element 1. This
parameter is optional, you can pass zero. If non-zero this value is
used to avoid the association jumping as vertices are
inserted/deleted. @Param(input) nSeg2 the number of vertices of element
2. This parameter is optional, you can pass zero. If non-zero this
value is used to avoid the association jumping as vertices are
inserted/deleted. @Param(input) path1 display path for the element1.
@Param(input) path2 display path for the element2. @Param(input) elemId1
used if path1 is NULL...i.e. creating assoc to element that has not
been added to the file yet. No verification on the association can be
done in this case. @Param(input) elemId2 used if path2 is NULL...i.e.
creating assoc to element that has not been added to the file yet. No
verification on the association can be done in this case. @Return
returns SUCCESS if the operation is successful

See also:
    Assoc.GetPoint .CreateIntersection

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateLinear =R"doc(@Description Creates an association that represents a point on a
linear element. This function is similar to Assoc.CreateKeypoint
but has the advantage that it creates associations to multi-line
elements as well as other linear elements. Also, this function does
not require the numerator and divisor parameters as does
Assoc.CreateKeypoint. Instead, this function automatically
calculates the keypoint numerator and divisor based on inPoint and the
specified segment of the linear element.

@Param(output) assoc If a valid association is created, the association
information is returned in assoc. @Param(input) inPoint is the location
on the specified linear element that is converted to an associative
point. @Param(input) vertex is the index of the vertex directly preceding
the associative point. @Param(input) nVertex the total number of vertices
of the linear element. This parameter is optional, you can pass zero.
If non-zero this value is used to avoid the association jumping as
vertices are inserted/deleted. @Param(input) lineNo is a line number used
for multi-lines only. @Param(input) path display path for the element.
@Param(input) elemId used if path is NULL...i.e. creating assoc to
element that has not been added to the file yet. No verification on
the association can be done in this case. @Return SUCCESS if a valid
linear association is created. Otherwise an non-zero error status is
returned.

See also:
    Assoc.CreateKeypoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateKeypoint =R"doc(@Description Creates an association that represents a point on a
linear element.

@Param(output) assoc If a valid association is created, the association
information is returned in assoc. Linear elements are lines, line
strings and shapes. @Param(input) vertex the index of the vertex directly
preceding the association point. @Param(input) nVertex the total number
of vertices of the linear element. This parameter is optional, you can
pass zero. If non-zero this value is used to avoid the association
jumping as vertices are inserted/deleted. @Param(input) numerator the
distance from vertex number vertex in units of divisor as described
below. Its range must be between 0 and 32767. @Param(input) divisor the
number of units (segments) to be considered between the points at
vertex and vertex+1. The values of numerator and divisor are used
together as the fraction of the distance between the points at vertex
and vertex+1, where the association point will be located. The
denominator must be between 1 and 32767. @Param(input) path display path
for the element. @Param(input) elemId used if path is NULL...i.e.
creating assoc to element that has not been added to the file yet. No
verification on the association can be done in this case. @Return
returns SUCCESS (zero) if it is able to create a valid association.
Otherwise, it returns a non-zero value.

See also:
    Assoc.CreateLinear Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_CreateArc =R"doc(@Description Creates an association that represents a point on an arc
or ellipse element.

@Param(output) assoc If a valid association is created, the association
information is returned in assoc. @Param(input) angle the angle (in
radians) from the primary axis of the arc or ellipse to the
association point. This argument is used only when the value of
*keyPoint* is

```
ASSOC_ARC_ANGLE
```

@Param(input) keyPoint determines the type of association that is
created.  

@Param(input) path display path for the element.
@Param(input) elemId used if path is NULL...i.e. creating assoc to
element that has not been added to the file yet. No verification on
the association can be done in this case. 

@Return SUCCESS (zero) if it
is able to create a valid association. Otherwise, it returns a non-
zero value.

See also:
    Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_ResolveAssociations =R"doc(@Description Removes all association points from an element.

@Param(input) elemP element to remove assoc point from. @Param(input)
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
    

)doc";

static const char * __doc_MstnPlatform_Assoc_RemovePoint =R"doc(@Description Removes from element. An Assoc.Create... function must
create the information in assocPoint.

@Param(input) elemP element to remove assoc point from. @Param(input)
pointNum point number to remove. @Param(input) maxPoints total number of
points on element. @Return SUCCESS (zero) if point was associative and
was removed. If the information is invalid, the function returns a
non-zero value.

See also:
    Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_GetPointFromElement =R"doc(@Description Uses the element and point number to create a 3D data
point that is returned in outPoint. An Assoc.Create... function
must create the information in assocPoint.

@Param(output) outPoint the point created by the function. @Param(input)
elemP element to get the point from. @Param(input) pointNum point number
to get. @Param(input) maxPoints total number of points on element.
@Param(input) modelRef the model that contains the element and the
association. @Return SUCCESS (zero) if a valid point is created in
dPoint. If the information in assocPoint is invalid, the function
returns a non-zero value.

See also:
    Assoc.GetPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_GetPoint =R"doc(@Description Uses the information in assocPoint to create a 3D data
point that is returned in outPoint. An Assoc.Create... function
must create the information in assocPoint.

@Param(output) outPoint the point created by the function. @Param(input)
assoc association information used to create the point. @Param(input)
modelRef the model that contains the element and the association.
@Return SUCCESS (zero) if a valid point is created in dPoint. If the
information in assocPoint is invalid, the function returns a non-zero
value.

See also:
    Assoc.CreateArc Assoc.CreateIntersection
    Assoc.CreateKeypoint Assoc.CreateMline

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_VertexAddedOrRemoved =R"doc(@Description Adjust association point indices for the specified
element.

@Param(input) elemP element to add association information to @Param(input)
pointNum index of point added/removed @Param(input) maxPoints max assoc
pts on element @Param(input) inserted pass true is vertex has been added;
false if it's been removed @Return SUCCESS if the information is
found, ERROR if an error occurs

See also:
    Assoc.ExtractPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_InsertPoint =R"doc(@Description Insert an association point to the specified element.

@Param(input) elemP element to add association information to @Param(input)
assocPointP Association information @Param(input) pointNum index of point
to insert @Param(input) maxPoints max assoc pts on element @Return
SUCCESS if the information is found, ERROR if an error occurs

See also:
    Assoc.ExtractPoint

Bentley Systems

Remark:
    )doc";

static const char * __doc_MstnPlatform_Assoc_ExtractPoint =R"doc(@Description Extracts the association information from the specified
point on the given element

@Param(output) assoc Association information @Param(input) elemP element to
extract point from @Param(input) pointNum index of point to extract
@Param(input) maxPoints max assoc pts on element @Return SUCCESS if the
information is found, ERROR if an error occurs

See also:
    Assoc.InsertPoint

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_TagElementValue =R"doc(@Description Assign a new tag value to the specified element if it
doesn't already have one.

@Param(output) tagValue is the tag value assigned to the element.
@Param(input) elemP is the element that receives the tag. @Param(input)
modelRef inidcates the model containing the element. @Param(input) inTag
is the input tag value, or zero. @Return SUCCESS if the operation
completed successfully, otherwise ERROR.

See also:
    Assoc.TagElementDescr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_GetElementDescr =R"doc(@Description Search for the element with the unique ID specified by
elemID and, if found, return an element descriptor that contains the
element and any child elements it might have if it is a complex
element.

@Param(output) outElDPP Return element descr or NULL @Param(output) filePosP
Return file position or NULL @Param(input) tagValue Tag value to search
for @Param(input) modelRef source of tagged element @Param(input)
expandShared expand shared cells @Return SUCCESS if the element is
found and an element descriptor was successfully created.
MDLERR_BADFILENUMBER is returned if modelRef is not valid. May return
ERROR if the element descriptor could not be created.

See also:
    Element.GetID

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Assoc_GetElement =R"doc(@Description Attempts to locate the element with the unique ID elemID
in the model specified by modelRef.

@Param(output) outElmP If found, the element is returned in element If
NULL is passed for element or filePos, the corresponding data is not
returned. @Param(output) filePosP If found, the element's file position
is returned in filePos. @Param(input) tagValue the tag (unique ID number)
of the element that is the association's object (or root). @Param(input)
modelRef indicates the model that the element is in. @Return SUCCESS
(zero) if the requested element is located. If the function is unable
to locate the element, it returns a non-zero value.

See also:
    $Remark:



)doc";

struct Assoc {};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msassoc(py::module_& m)
    {

    py::class_<Assoc> c1(m, "Assoc");      

    c1.def_static("GetElement", [] (MSElementP outElemP, ElementId tagValue, DgnModelRefP modelRef)
          {
          UInt32 filePos = 0;
          auto retVal = mdlAssoc_getElement(outElemP, &filePos, tagValue, modelRef);
          return py::make_tuple(retVal, filePos);
          }, "outElem"_a, "tagValue"_a, "modelRef"_a, DOC(MstnPlatform, Assoc, GetElement));

    c1.def_static("GetElementDescr", [] (ElementId tagValue, DgnModelRefP modelRef, bool expandShared)
          {
          MSElementDescrP edP = nullptr;
          UInt32 filePos = 0;
          auto retVal = mdlAssoc_getElementDescr(&edP, &filePos, tagValue, modelRef, expandShared);
          return py::make_tuple(retVal, RefCountedPtr< MSElementDescr>(edP), filePos);
          }, "tagValue"_a, "modelRef"_a, "expandShared"_a, DOC(MstnPlatform, Assoc, GetElementDescr));

    c1.def_static("TagElementValue", [] (MSElementP elemP, DgnModelRefP modelRef, ElementId inTag)
          {
          ElementId tagValue = -1;
          auto retVal = mdlAssoc_tagElementValue(&tagValue, elemP, modelRef, inTag);
          return py::make_tuple(retVal, tagValue);
          }, "elem"_a, "modelRef"_a, "tag"_a, DOC(MstnPlatform, Assoc, TagElementValue));

    c1.def_static("ExtractPoint", &mdlAssoc_extractPoint, "assoc"_a, "elem"_a, "pointNum"_a, "maxPoints"_a, DOC(MstnPlatform, Assoc, ExtractPoint));
    c1.def_static("InsertPoint", &mdlAssoc_insertPoint, "elem"_a, "assocPoint"_a, "pointNum"_a, "maxPoints"_a, DOC(MstnPlatform, Assoc, InsertPoint));
    c1.def_static("VertexAddedOrRemoved", &mdlAssoc_vertexAddedOrRemoved, "elem"_a, "pointNum"_a, "maxPoints"_a, "inserted"_a, DOC(MstnPlatform, Assoc, VertexAddedOrRemoved));
    c1.def_static("GetPoint", &mdlAssoc_getPoint, "outPoint"_a, "assocPoint"_a, "modelRef"_a, DOC(MstnPlatform, Assoc, GetPoint));
    c1.def_static("GetPointFromElement", &mdlAssoc_getPointFromElement, "outPoint"_a, "elem"_a, "pointNum"_a, "maxPoints"_a, "modelRef"_a, DOC(MstnPlatform, Assoc, GetPointFromElement));
    c1.def_static("RemovePoint", &mdlAssoc_removePoint, "elem"_a, "pointNum"_a, "maxPoints"_a, DOC(MstnPlatform, Assoc, RemovePoint));
    c1.def_static("ResolveAssociations", &mdlAssoc_resolveAssociations, "elem"_a, "modelRef"_a, DOC(MstnPlatform, Assoc, ResolveAssociations));

    c1.def_static("GetRoot", [] (AssocPoint* assocPoint, DgnModelRefP modelRef, int rootIndex)
          {
          ElementRefP elemRef = nullptr;
          DgnModelRefP elemModelRef = nullptr;
          Transform elemTransform;
          int nRoots = 0;
          auto retVal = mdlAssoc_getRoot(&elemRef, &elemModelRef, &elemTransform, &nRoots, assocPoint, modelRef, rootIndex);
          return py::make_tuple(retVal,
                                py::cast(elemRef, py::return_value_policy::reference),
                                py::cast(elemModelRef, py::return_value_policy::reference),
                                elemTransform,
                                nRoots);
          }, "assocPoint"_a, "modelRef"_a, "rootIndex"_a);

    c1.def_static("CreateArc", &mdlAssoc_createArc, "assoc"_a, "angle"_a, "keyPoint"_a, "path"_a, "elemId"_a, DOC(MstnPlatform, Assoc, CreateArc));
    c1.def_static("CreateKeypoint", &mdlAssoc_createKeypoint, "assoc"_a, "vertex"_a, "nVertex"_a, "numerator"_a, "divisor"_a, "path"_a, "elemId"_a, DOC(MstnPlatform, Assoc, CreateKeypoint));
    c1.def_static("CreateLinear", &mdlAssoc_createLinear, "assoc"_a, "inPoint"_a, "vertex"_a, "nVertex"_a, "lineNo"_a, "path"_a, "elemId"_a, DOC(MstnPlatform, Assoc, CreateLinear));
    c1.def_static("CreateIntersection", &mdlAssoc_createIntersection, "assoc"_a, "index"_a, "seg1"_a, "seg2"_a, "nSeg1"_a, "nSeg2"_a, "path1"_a, "path2"_a, "elemId1"_a, "elemId2"_a, DOC(MstnPlatform, Assoc, CreateIntersection));
    c1.def_static("CreateMline", &mdlAssoc_createMline, "assoc"_a, "vertex"_a, "nVertex"_a, "lineNo"_a, "offset"_a, "joint"_a, "path"_a, "elemId"_a, DOC(MstnPlatform, Assoc, CreateMline));
    c1.def_static("CreateOrigin", &mdlAssoc_createOrigin, "assoc"_a, "option"_a, "path"_a, "elemId"_a, DOC(MstnPlatform, Assoc, CreateOrigin));
    c1.def_static("CreateBCurve", &mdlAssoc_createBCurve, "assoc"_a, "u"_a, "path"_a, "elemId"_a, DOC(MstnPlatform, Assoc, CreateBCurve));
    c1.def_static("GetCurrent", &mdlAssoc_getCurrent, "assoc"_a, "point"_a, "option"_a, "createMask"_a, DOC(MstnPlatform, Assoc, GetCurrent));
    c1.def_static("StripTag", &mdlAssoc_stripTag, "elem"_a, DOC(MstnPlatform, Assoc, StripTag));

    c1.def_static("TagElementDescr", [] (MSElementDescrP elDescr, DgnModelRefP modelRef)
          {
          ElementId newTag = -1;
          auto retVal = mdlAssoc_tagElementDescr(&newTag, elDescr, modelRef);
          return py::make_tuple(retVal, newTag);
          }, "elDescr"_a, "mnodelRef"_a, DOC(MstnPlatform, Assoc, TagElementDescr));    
    }