/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\mselmdsc.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/mselmdsc.fdf>



static const char * __doc_MstnPlatform_MSElementDescr_Fillet =R"doc(@description Used to create a two dimensional circular fillet between
the specified elements. Optionally, a template element can be
specified from which the symbology settings are copied.

Parameter ``fillet``:
    is the element descriptor for the fillet arc element after it is
    created.

Parameter ``pTemplate``:
    is an element from which the symbology settings are copied to the
    fillet arc.

Parameter ``in0EdP``:
    is the first element to fillet.

Parameter ``in1EdP``:
    is the second element to fillet.

Parameter ``inputRadius``:
    is the desired fillet arc radius.

Parameter ``inputPoint``:
    indicates which fillet is desired by proximity. For example, if
    the elements to fillet include two intersecting lines, there are
    four possible fillets that could be created (assuming the radius
    value does not preclude any of the four). The fillet closest to
    the given point is the fillet that is selected and created.

Parameter ``inputRotMatrix``:
    is the rotation matrix to apply to the fillet. This may be NULL.

Returns:
    SUCCESS if the fillet can be created, otherwise ERROR.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_Show =R"doc(@description Used to print information from the element descriptor
header in a formatted fashion. The printed values include the element
type, its complex status, its 3d status, and if it is a graphic
element the symbology values for color, weight, style, level, graphic
group number and class. If the element is not a graphic element only
its level will be printed.

Parameter ``edP``:
    is the element descriptor to get the information from to print.

Parameter ``currentIndent``:
    is the number of character spaces to indent the information before
    printing.

Returns:
    Always returns SUCCESS

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_HasLineStyle =R"doc(@description Queries if an element descriptor has line style.

Parameter ``lineStyleEdP``:
    is the element descriptor to query.

Returns:
    true if the elements descriptor has line style.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_IsGroupedHole =R"doc(@description Queries if an element descriptor is a grouped hole
element; i.e., an element that has a hole punched in it (such as can
be created with MSElementDescr.CreateShapeWithHoles).

Parameter ``groupEdP``:
    is the element descriptor to query.

Returns:
    true if the elements descriptor is a grouped hole element.

See also:
    MSElementDescr.Open MSElementDescr.Close MSElementDescr.CreateShapeWithHoles

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_IsOpen =R"doc(@description Queries if an element descriptor is an open element;
i.e., a line, line string, curve, open B-Spline curve or complex
chain.

Parameter ``edP``:
    is the element descriptor to query.

Returns:
    true if the element descriptor is an open element.

See also:
    MSElementDescr.Open MSElementDescr.Close MSElementDescr.CreateShapeWithHoles
    MSElementDescr.IsClosed MSElementDescr.IsGroupedHole

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_IsClosed =R"doc(@description Queries if an element descriptor is a closed element;
i.e., a shape, complex shape, ellipse or closed B-spline curve.

Parameter ``edP``:
    is the element descriptor to query.

Returns:
    true if the element descriptor is a closed element.

See also:
    MSElementDescr.Open MSElementDescr.Close MSElementDescr.CreateShapeWithHolesC
    MSElementDescr.IsOpen MSElementDescr.IsGroupedHole

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_ExtractEndPoints =R"doc(@description Returns the start and end points (in start and end) for
the open element, edP. Valid element types include lines, linestrings,
arcs, curves, B-spline curves, multilines, complex chains and complex
shapes.

Parameter ``startP``:
    the starting point for the curve; pass NULL for argument if you do
    not need or want this value.

Parameter ``startTangentP``:
    start tangent

Parameter ``endP``:
    the ending point for the curve; pass NULL for argument if you do
    not need or want this value.

Parameter ``endTangentP``:
    end tangent

Parameter ``edP``:
    element descriptor

Parameter ``modelRef``:
    is used only if the input element is a multiline.

Remark:
    s This function is included in the object library mdllib.ml. This
    library must be linked into any application calling this function.

Returns:
    Returns SUCCESS if the element is successfully reversed and
    MDLERR_BADTYPE if the element type is invalid.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_DisplayInSelectedViews =R"doc(@description This function is identical to MSElementDescr.Display, except
that the viewMask argument determines the views in which element
descriptor is displayed (see Element.DisplayInSelectedViews for a
discussion of viewMask).

Parameter ``elemDescr``:
    pointer to elemDscr displayed

Parameter ``modelRef``:
    element source

Parameter ``drawMode``:
    drawing mode

Parameter ``viewMask``:
    one bit per view

See also:
    MSElementDescr.Display MSElementDescr.DisplayFromFile
    MSElementDescr.DisplayFromFileViews

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_DisplayFromFileViews =R"doc(@description This function is identical to MSElementDescr.DisplayFromFile,
except that the viewMask argument determines the views in which
element descriptor is displayed (see Element.DisplayInSelectedViews
for a discussion of viewMask).

Parameter ``filePos``:
    file position of element

Parameter ``modelRef``:
    element source

Parameter ``elP``:
    optional

Parameter ``drawMode``:
    drawing mode

Parameter ``viewMask``:
    one bit per view

Returns:
    Returns SUCCESS if the element is displayed and ERROR if filePos
    is invalid.

See also:
    MSElementDescr.Display MSElementDescr.DisplayFromFile
    MSElementDescr.DisplayInSelectedViews

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_DeleteByModelRef =R"doc(@description Deletes the element(s) pointed to by elemDscrP at file
position filePos in the model specified by modelRef. The deletion will
be undoable if the model is in the current master file. If it is,
MicroStation needs the element(s) to save in the undo buffer. If the
element descriptor does not exist, pass NULL for elemDscrP and
MicroStation will re-read the elements from the cache. Doing so adds
some overhead, so always pass the element descriptor if it exists.

Parameter ``elemDescr``:
    element descr to delete

Parameter ``filePos``:
    file position

Parameter ``modelRef``:
    the model containing the element(s)

Parameter ``display``:
    If display is true, MicroStation erases the elements from the
    screen as it deletes them. Otherwise, it does not erase them.

Remark:
    s MicroStation remembers the MSElementDescr.UndoableDelete function,
    so the user can undo it.

Returns:
    If the element is deleted, returns SUCCESS. If it fails, it sets
    mdlErrno and returns one of the following:MDLERR_READONLY,
    MDLERR_WRITEINHIBIT, MDLERR_BADELEMENT or MDLERR_MODIFYCOMPLEX.

See also:
    MSElementDescr.UndoableDelete

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_UndoableDelete =R"doc(@description Deletes the element(s) pointed to by elemDscrP at file
position filePos. MicroStation needs the element(s) to save in the
undo buffer. If the element descriptor does not exist, pass NULL for
elemDscrP and MicroStation will re-read the elements from the cache.
Doing so adds some overhead to MSElementDescr.UndoableDelete, so always
pass the element descriptor if it exists.

Parameter ``elemDescrP``:
    element descr to delete

Parameter ``filePos``:
    file position

Parameter ``display``:
    If display is true, MicroStation erases the elements from the
    screen as it deletes them. Otherwise, it does not erase them.

Remark:
    s MicroStation remembers the MSElementDescr.UndoableDelete function,
    so the user can undo it.

Returns:
    If the element is deleted, returns SUCCESS. If it fails, it sets
    mdlErrno and returns one of the following:MDLERR_READONLY,
    MDLERR_WRITEINHIBIT, MDLERR_BADELEMENT or MDLERR_MODIFYCOMPLEX.

See also:
    Element.UndoableDelete

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_Rewrite =R"doc(@description Overwrites the existing MicroStation element(s) pointed
to by oldElemDscrP with the new element(s) pointed to by newElemDscrP
at file position filePos.

Parameter ``newElemDscr``:
    new elements

Parameter ``oldElemDscr``:
    for compatibility with previous releases. Ignored, just pass NULL!

Parameter ``filePos``:
    file position

Remark:
    s If the sizes of the two element descriptors differ, MicroStation
    deletes the old one and appends the new one to the end of the
    file. Otherwise, it overwrites the old element(s) in the same
    position.

Remark:
    s MicroStation saves the old element(s) in the undo buffer. If a
    copy of the old element descriptor does not exist, pass NULL for
    oldElemDscrP and MicroStation will re-read the old element(s) from
    the cache. Unless you are certain that you have the unmodified
    element descriptor, pass NULL for oldElmDscrP.

Remark:
    s MicroStation remembers the MSElementDescr.Rewrite function, so the
    user can undo it.

Returns:
    Returns the file position of the element added to the design file.
    If the two elements are the same size, this file position is the
    same as filePos.

Remark:
    s If an error occurs, the file position is set to zero and the
    global variable mdlErrno is set to the specific error cause.
    Possible values for mdlErrno are MDLERR_READONLY, MDLERR_DISKFULL,
    MDLERR_WRITEINHIBIT, MDLERR_BADELEMENT and MDLERR_WRITEFAILED.

See also:
    MSElementDescr.Add MSElementDescr.Append

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_GetThicknessEdP =R"doc(@description Get a surface or solid element that represents a planar
element with thickness. Element thickness is a new concept introduced
in V8. The presence of a thickness linkage on a planar element implies
that the element is extruded by the thickness distance. The
MSElementDescr.GetThicknessEdP function will return a solid or surface
element that represents an element with thickness

Parameter ``edP``:
    a planar element with a non-zero thickness.

Parameter ``modelRef``:
    the modelRef for the element.

Returns:
    If the element has a non-zero thickness then a surface or solid
    element representing the extrusion, else NULL is returned.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_PointAtDistance =R"doc(@description Returns the point and tangent vector at distance along
the element. All input parameters are specified in the current
coordinate system.

Parameter ``position``:
    point on element

Parameter ``tangent``:
    tangent direction

Parameter ``inputDistance``:
    distance along elm

Parameter ``edP``:
    element

Parameter ``inputTolerance``:
    stroking tolerance

Returns:
    Returns SUCCESS if it functions correctly and a non-zero error
    status otherwise.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_OrientationExt =R"doc(@description return a natural coordinate frame for the element.

Parameter ``pTransform``:
    coordinate frame.

Parameter ``pSourceDescr``:
    source element

Parameter ``modelRef``:
    source model ref.

Returns:
    SUCCESS for graphic elements which allow an orientation.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_ExtractNormalWithTolerance =R"doc(@description Used to find the normal vector of an element, with user-
defined tolerance for planarity test.

Parameter ``normal``:
    is a vector normal to the element.

Parameter ``point``:
    is a point on the element.

Parameter ``edP``:
    is the element to which the normal will be found.

Parameter ``inputDefaultNormal``:
    is a reference vector used only if the element normal is
    ambiguous, as is the case for a line element. In this case,
    inputDefaultNormal is a default vector in the plane of the line
    and the returned normal.

Parameter ``absTol``:
    is a user-defined absTol tolerance.

Parameter ``localRelTol``:
    is a user-defined local tolerance.

Parameter ``globalRelTol``:
    is a user-defined global tolerance.

Returns:
    SUCCESS if the normal vector is returned, MDLERR_NONPLANARELEMENT
    if an average normal vector is returned.

Remark:
    

See also:
    MSElementDescr.ExtractNormal2 MSElementDescr.ExtractNormal)doc";

static const char * __doc_MstnPlatform_MSElementDescr_ExtractNormalTight =R"doc(@description Used to find the normal vector of an element, with tight
tolerance for planarity test.

Parameter ``normal``:
    is a vector normal to the element.

Parameter ``point``:
    is a point on the element.

Parameter ``edP``:
    is the element to which the normal will be found.

Parameter ``inputDefaultNormal``:
    is a reference vector used only if the element normal is
    ambiguous, as is the case for a line element. In this case,
    inputDefaultNormal is a default vector in the plane of the line
    and the returned normal.

Returns:
    SUCCESS if the normal vector is returned, MDLERR_NONPLANARELEMENT
    if an average normal vector is returned.

Remark:
    

See also:
    MSElementDescr.ExtractNormal2 MSElementDescr.ExtractNormal )doc";

static const char * __doc_MstnPlatform_MSElementDescr_ExtractNormal =R"doc(@description Used to find the normal vector of an element, using the
incredibly coarse classic IGDS/Microstation tolerance of 100 UORS. Use
MSElementDescr.ExtractNormalTight to get a tighter tolerance.

Parameter ``normal``:
    is a vector normal to the element.

Parameter ``point``:
    is a point on the element.

Parameter ``edP``:
    is the element to which the normal will be found.

Parameter ``inputDefaultNormal``:
    is a reference vector used only if the element normal is
    ambiguous, as is the case for a line element. In this case,
    inputDefaultNormal is a default vector in the plane of the line
    and the returned normal.

Returns:
    SUCCESS if the normal vector is returned, MDLERR_NONPLANARELEMENT
    if an average normal vector is returned.

Remark:
    

See also:
    MSElementDescr.ExtractNormal2 MSElementDescr.ExtractNormalTight2 
    )doc";

static const char * __doc_MstnPlatform_MSElementDescr_DisplayFromFile =R"doc(@description This function is similar to ElmDscr.Display, but
operates on elements in the design file rather than from an element
descriptor supplied by the application. el is an optional parameter
that points to the element at position filePos from modelRef. If the
element does not exist, pass NULL.


Parameter ``filePos``:
    file position

Parameter ``modelRef``:
    element source

Parameter ``el``:
    element (or NULL)

Parameter ``drawMode``:
    determines how MicroStation displays the element(s). @Remarks
    Possible values for drawMode are as follows:<table border=" 1 ">
    <caption></caption> <tr> <th>drawMode</th> <th>drawMode field
    meaning</th> </tr> <tr> <td>DRAW_MODE_Normal</td> <td>Draw the
    element(s) in its normal color.</td> </tr> <tr> <td>ERASE</td>
    <td>Erase the element(s).</td> </tr> <tr> <td>HILITE</td> <td>Draw
    the element(s) in the current highlight color.</td> </tr> </table>

Returns:
    Returns SUCCESS if the element is read and displayed and ERROR if
    filePos is invalid.

See also:
    MSElementDescr.DisplaySingle Element.Display
    MSElementDescr.DisplayInSelectedViews MSElementDescr.DisplayFromFileViews

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_DisplaySingle =R"doc(@description This function is identical to MSElementDescr.Display except
that it displays a single element descriptor and will not display the
elements pointed to by elemDescr->next.

Parameter ``elemDescr``:
    element to display

Parameter ``modelRef``:
    element source

Parameter ``drawMode``:
    display mode @Remarks Possible values for drawMode are as follows:
    <table border=" 1 "> <caption></caption> <tr> <th>drawMode</th>
    <th>drawMode field meaning</th> </tr> <tr>
    <td>DRAW_MODE_Normal</td> <td>Draw the element(s) in its normal
    color.</td> </tr> <tr> <td>ERASE</td> <td>Erase the
    element(s).</td> </tr> <tr> <td>HILITE</td> <td>Draw the
    element(s) in the current highlight color.</td> </tr> </table>

See also:
    MSElementDescr.Display

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_DisplayInView =R"doc(@description Used to display the contents of the specified element
descriptor in the specified view window using the given drawing mode.

Parameter ``edP``:
    is the element descriptor indicating the element to draw in the
    given view.

Parameter ``modelRef``:
    indicates the model containing the element.

Parameter ``drawMode``:
    is one of the drawing mode values. @Remarks Possible values for
    drawMode are as follows:<table border=" 1 "> <caption></caption>
    <tr> <th>drawMode</th> <th>drawMode field meaning</th> </tr> <tr>
    <td>DRAW_MODE_Normal</td> <td>Draw the element(s) in its normal
    color.</td> </tr> <tr> <td>ERASE</td> <td>Erase the
    element(s).</td> </tr> <tr> <td>HILITE</td> <td>Draw the
    element(s) in the current highlight color.</td> </tr> </table>

Parameter ``gwP``:
    window to display element in

See also:
    MSElementDescr.Show

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_DisplayAllReferences =R"doc(@description Displays the element descriptor pointed to by elemDscrP
in the views specified by viewMask if the descriptors modelRef can be
reached from the root modelRef of the view. Useful for displaying
changes in dependency callbacks.

Parameter ``elemDescr``:
    elements to display

Parameter ``drawMode``:
    determines how MicroStation displays the element(s).

Parameter ``activeModel``:
    determines the display transformation and clipping to be applied
    to the element(s) as they are drawn.

Parameter ``viewMask``:
    which views to display in @Remarks Possible values for drawMode
    are as follows:<table border=" 1 "> <caption></caption> <tr>
    <th>drawMode</th> <th>drawMode field meaning</th> </tr> <tr>
    <td>DRAW_MODE_Normal</td> <td>Draw the element(s) in its normal
    color.</td> </tr> <tr> <td>ERASE</td> <td>Erase the
    element(s).</td> </tr> <tr> <td>HILITE</td> <td>Draw the
    element(s) in the current highlight color.</td> </tr> </table>

See also:
    MSElementDescr.DisplaySingle Element.Display
    MSElementDescr.DisplayInSelectedViews MSElementDescr.DisplayFromFileViews
    MSElementDescr.DisplayFromFile

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_Display =R"doc(@description Displays the element descriptor pointed to by elemDscrP
in all active views.

Parameter ``elemDescr``:
    elements to display

Parameter ``modelRef``:
    determines the display transformation and clipping to be applied
    to the element(s) as they are drawn.

Parameter ``drawMode``:
    determines how MicroStation displays the element(s). @Remarks
    Possible values for drawMode are as follows:<table border=" 1 ">
    <caption></caption> <tr> <th>drawMode</th> <th>drawMode field
    meaning</th> </tr> <tr> <td>DRAW_MODE_Normal</td> <td>Draw the
    element(s) in its normal color.</td> </tr> <tr> <td>ERASE</td>
    <td>Erase the element(s).</td> </tr> <tr> <td>HILITE</td> <td>Draw
    the element(s) in the current highlight color.</td> </tr> </table>

See also:
    MSElementDescr.DisplaySingle Element.Display
    MSElementDescr.DisplayInSelectedViews MSElementDescr.DisplayFromFileViews
    MSElementDescr.DisplayFromFile

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_AppendByModelRef =R"doc(@description This function is identical to MSElementDescr.Append except
for the addition of a modelRef argument that allows elements to be
appended to models other than the active model. If the model specified
is the active model then the two functions are identical. If the
element is from the active design file the various asynch hooks are
called and the element is recorded in the undo buffer. The supplied
modelRef must be open for write access.

Parameter ``elemDescr``:
    appended to file

Parameter ``modelRef``:
    the model to append to.

Returns:
    Returns SUCCESS if the element is appended successfully and ERROR
    otherwise. If an error occurs, the file position is set to zero
    and the global variable mdlErrno is set to the specific error
    cause. Possible values for mdlErrno are MDLERR_READONLY,
    MDLERR_DISKFULL, MDLERR_WRITEINHIBIT, MDLERR_BADELEMENT and
    MDLERR_WRITEFAILED.

See also:
    MSElementDescr.Append

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_Append =R"doc(@description Adds the modified element(s) contained in the element
descriptor pointed to by elemDscr to the design file. You should use
MSElementDescr.Append if you are modifying an element and changing its
size. The MSElementDescr.Rewrite function is also useful for this purpose,
but requires that the old file position be known.

Remark:
    s The MSElementDescr.Add and MSElementDescr.Append functions validate the
    element descriptor before adding it to the file.

Remark:
    s MicroStation remembers the MSElementDescr.Add and MSElementDescr.Append
    functions, so the user can undo them.

Parameter ``elemDescrP``:
    appended to file

Returns:
    Returns the file position of the first element added to the design
    file. If an error occurs, the file position is set to zero and the
    global variable mdlErrno is set to the specific error cause.
    Possible values for mdlErrno are MDLERR_READONLY, MDLERR_DISKFULL,
    MDLERR_WRITEINHIBIT, MDLERR_BADELEMENT and MDLERR_WRITEFAILED.

See also:
    MSElementDescr.Rewrite Element.Add Element.Append MSElementDescr.Add
    MSElementDescr.AppendByModelRef

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MSElementDescr_Add =R"doc(@description Adds the new element(s) contained in the element
descriptor pointed to by elemDescr to the design file. You should use
MSElementDescr.Add when creating new elements. Before writing the element
to the file, MSElementDescr.Add sets the properties bits in the element
header to not locked, new element, and not modified.

Remark:
    s The MSElementDescr.Add and MSElementDescr.Append functions validate the
    element descriptor before adding it to the file.

Remark:
    s MicroStation remembers the MSElementDescr.Add and MSElementDescr.Append
    functions, so the user can undo them.

Parameter ``elemDescr``:
    added to file

Returns:
    Returns the file position of the first element added to the design
    file. If an error occurs, the file position is set to zero and the
    global variable mdlErrno is set to the specific error cause.
    Possible values for mdlErrno are MDLERR_READONLY, MDLERR_DISKFULL,
    MDLERR_WRITEINHIBIT, MDLERR_BADELEMENT and MDLERR_WRITEFAILED.

See also:
    MSElementDescr.Rewrite Element.Add Element.Append

)doc";



BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct MSElementDescr {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_mselmdsc(py::module_& m)
    {

    py::class_<Bentley::MstnPlatform::MSPython::MSElementDescr> c1(m, "MSElementDescr"); 

    c1.def_static("GetFilePos", &mdlElmdscr_getFilePos, "elDscr"_a);
    c1.def_static("IsPersistent", &mdlElmdscr_isPersistent, "elDscr"_a);
    c1.def_static("ClearPersistentInfo", &mdlElmdscr_clearPersistentInfo, "elDscr"_a);

    c1.def_static("ReplaceElement", [] (MSElementDescrP existingDescr, MSElementCP elementP)
          {
          MSElementDescrP existingDescr_ {existingDescr};
          auto retVal = mdlElmdscr_replaceElement(&existingDescr_, elementP);
          return py::make_tuple(retVal, existingDescr_);
          }, "existingDescr"_a, "element"_a);

    c1.def_static("InsertElement", &mdlElmdscr_insertElement, "existingElement"_a, "element"_a);

    c1.def_static("InitOrAddToChain", [] (MSElementDescrP edP, MSElementDescrP newElem)
          {
          MSElementDescrP edP_ {edP};
          mdlElmdscr_initOrAddToChain(&edP_, newElem);
          return edP_;
          }, "edP"_a, "newElem"_a);

    c1.def_static("AddToChain", &mdlElmdscr_addToChain, "chainDscr"_a, "newElem"_a);

    c1.def_static("ReplaceDscr", [] (MSElementDescrP existingDescr, MSElementDescrP newDscr)
          {
          MSElementDescrP existingDescr_ {existingDescr};
          mdlElmdscr_replaceDscr(&existingDescr_, newDscr);
          return existingDescr_;
          }, "existingDescr"_a, "newDscr"_a);

    c1.def_static("FreeAll", [] (MSElementDescrP elemDescr)
          {
          MSElementDescrP elemDescr_ {elemDescr};
          mdlElmdscr_freeAll(&elemDescr_);
          }, "elemDescr"_a);

    c1.def_static("New", [] (MSElementDescrP elDescr, MSElementDescrP elemHeader, MSElementCP element)
          {
          MSElementDescrP elDescr_ {elDescr};
          auto retVal = mdlElmdscr_new(&elDescr_, elemHeader, element);
          return py::make_tuple(retVal, elDescr_);
          }, "elDescr"_a, "elemHeader"_a, "element"_a);

    c1.def_static("RemoveElement", &mdlElmdscr_removeElement, "elemDescr"_a, py::return_value_policy::reference);
    c1.def_static("AppendElement", &mdlElmdscr_appendElement, "existingElmDscr"_a, "element"_a, py::return_value_policy::reference);
    c1.def_static("AppendDscr", &mdlElmdscr_appendDscr, "existingElmDscr"_a, "newDscr"_a);

    c1.def_static("Duplicate", [] (MSElementDescrCP oldDscr)
          {
          MSElementDescrP newDscr = nullptr;
          auto retVal = mdlElmdscr_duplicate(&newDscr, oldDscr);
          return py::make_tuple(retVal, newDscr);
          }, "oldDscr"_a);

    c1.def_static("DuplicateEx", [] (MSElementDescrCP oldDscr, bool copyScheduledXaChanges = true, bool loadPersistentXasAsChanges = true)
          {
          MSElementDescrP newDscr = nullptr;
          auto retVal = mdlElmdscr_duplicateEx(&newDscr, oldDscr, copyScheduledXaChanges, loadPersistentXasAsChanges);
          return py::make_tuple(retVal, newDscr);
          }, "oldDscr"_a, "copyScheduledXaChanges"_a = true, "loadPersistentXasAsChanges"_a = true);

    c1.def_static("DuplicateSingle", [] (MSElementDescrCP oldDscr)
          {
          MSElementDescrP newDscr = nullptr;
          auto retVal = mdlElmdscr_duplicateSingle(&newDscr, oldDscr);
          return py::make_tuple(retVal, newDscr);
          }, "oldDscr"_a);

    c1.def_static("DuplicateSingleEx", [] (MSElementDescrCP oldDscr, bool copyScheduledXaChanges, bool loadPersistentXasAsChanges)
          {
          MSElementDescrP newDscr = nullptr;
          auto retVal = mdlElmdscr_duplicateSingleEx(&newDscr, oldDscr, copyScheduledXaChanges, loadPersistentXasAsChanges);
          return py::make_tuple(retVal, newDscr);
          }, "oldDscr"_a, "copyScheduledXaChanges"_a, "loadPersistentXasAsChanges"_a);

    c1.def_static("Validate", &mdlElmdscr_validate, "p"_a, "modelRef"_a);
    c1.def_static("CopyXAttributes", &mdlElmdscr_copyXAttributes, "toElDscr"_a, "fromElDscr"_a, "copyChildXAttributes"_a);
    c1.def_static("Add", &mdlElmdscr_add, "elemDscr"_a, DOC(MstnPlatform, MSElementDescr, Add));
    
    c1.def_static("AddFill", [] (MSElementDescrP edP)
          {
          MSElementDescrP edP_ {edP};
          auto retVal = mdlElmdscr_addFill(&edP_);
          return py::make_tuple(retVal, edP_);
          }, "edP"_a);

    c1.def_static("InitOrAddToChainWithTail", [] (MSElementDescrP headDescr, MSElementDescrP tailDescr, MSElementDescrP descr)
          {
          MSElementDescrP headDescr_ {headDescr};
          MSElementDescrP tailDescr_ {tailDescr};
          mdlElmdscr_initOrAddToChainWithTail(&headDescr_, &tailDescr_, descr);
          return py::make_tuple(headDescr_, tailDescr_);
          }, "headDescr"_a, "tailDescr"_a, "descr"_a);

    c1.def_static("AssembleChains", [] (MSElementDescrP edP, double closureTolerance, DgnModelRefP modelRef)
          {
          MSElementDescrP edP_ {edP};
          auto retVal = mdlElmdscr_assembleChains(&edP_, closureTolerance, modelRef);
          return py::make_tuple(retVal, edP_);
          }, "edP"_a, "closureTolerance"_a, "modelRef"_a);

    c1.def_static("Append", &mdlElmdscr_append, "elemDscr"_a, DOC(MstnPlatform, MSElementDescr, Append));
    c1.def_static("AppendByModelRef", &mdlElmdscr_appendByModelRef, "elemDscr"_a, "modelRef"_a, DOC(MstnPlatform, MSElementDescr, AppendByModelRef));
    
    c1.def_static("AppendAttributes", [] (MSElementDescrP elDescr, bvector<UInt16>& attributes)
          {
          MSElementDescrP elDescr_ {elDescr};
          mdlElmdscr_appendAttributes(&elDescr_, (int) attributes.size(), attributes.data());
          return elDescr_;
          }, "elDescr"_a, "attributes"_a);

    c1.def_static("ConvertTo2D", [] (MSElementDescrP oldDescr, int view, TransformP transform, DgnModelRefP sourceModelRef, DgnModelRefP destModelRef, bool preserveZRange)
          {
          MSElementDescrP newDescr = nullptr;
          auto retVal = mdlElmdscr_convertTo2D(&newDescr, oldDescr, view, transform, sourceModelRef, destModelRef, preserveZRange);
          return py::make_tuple(retVal, newDescr);
          }, "oldDescr"_a, "view"_a, "transform"_a, "sourceModelRef"_a, "destModelRef"_a, "preserveZRange"_a);

    c1.def_static("ConvertTo3D", [] (MSElementDescrP oldDescr, int elType, double elevation, TransformP transform, DgnModelRefP sourceModelRef, DgnModelRefP destModelRef)
          {
          MSElementDescrP newDescr = nullptr;
          auto retVal = mdlElmdscr_convertTo3D(&newDescr, oldDescr, elType, elevation, transform, sourceModelRef, destModelRef);
          return py::make_tuple(retVal, newDescr);
          }, "oldDescr"_a, "elType"_a, "elevation"_a, "transform"_a, "sourceModelRef"_a, "destModelRef"_a);

    c1.def_static("CopyParallel", [] (MSElementDescrP inDscr, DPoint3dP point, double distance, DPoint3dP normal)
          {
          MSElementDescrP outDscr = nullptr;
          auto retVal = mdlElmdscr_copyParallel(&outDscr, inDscr, point, distance, normal);
          return py::make_tuple(retVal, outDscr);
          }, "inDscr"_a, "point"_a, "distance"_a, "normal"_a);

    c1.def_static("SignedOffset", [] (MSElementDescrCP curveDescr, double distance, DVec3dP normal)
          {
          MSElementDescrP outDscr = nullptr;
          auto retVal = mdlElmdscr_signedOffset(&outDscr, curveDescr, distance, normal);
          return py::make_tuple(retVal, outDscr);
          }, "curveDescr"_a, "distance"_a, "normal"_a);

    c1.def_static("Display", &mdlElmdscr_display, "elemDscr"_a, "modelRef"_a, "drawMode"_a, DOC(MstnPlatform, MSElementDescr, Display));
    c1.def_static("DisplayAllReferences", &mdlElmdscr_displayAllReferences, "elemDscr"_a, "drawMode"_a, "activeModel"_a, "viewMask"_a, DOC(MstnPlatform, MSElementDescr, DisplayAllReferences));
    c1.def_static("DisplayInView", &mdlElmdscr_displayInView, "edP"_a, "modelRef"_a, "drawMode"_a, "gwP"_a, DOC(MstnPlatform, MSElementDescr, DisplayInView));
    c1.def_static("DisplaySingle", &mdlElmdscr_displaySingle, "elemDescr"_a, "modelRef"_a, "drawMode"_a, DOC(MstnPlatform, MSElementDescr, DisplaySingle));
    c1.def_static("DisplayFromFile", &mdlElmdscr_displayFromFile, "filePos"_a, "modelRef"_a, "el"_a, "drawMode"_a, DOC(MstnPlatform, MSElementDescr, DisplayFromFile));
    
    c1.def_static("DisplayToWindow", &mdlElmdscr_displayToWindow,
          "window"_a, "rect"_a, "viewFlags"_a, "elemDescr"_a, "rotMatrix"_a, "origin"_a, "range"_a, "threeD"_a, "menuColor"_a);

    c1.def_static("ExtendedDisplayToWindow", &mdlElmdscr_extendedDisplayToWindow,
          "window"_a, "rect"_a, "viewFlags"_a, "elemDescr"_a, "rotMatrix"_a, "origin"_a, "range"_a, "threeD"_a, "menuColor"_a, "colorMap"_a, "clearFirst"_a, "backgroundImage"_a);

    c1.def_static("DistanceAtPoint", [] (DPoint3dP position, DPoint3dP tangent, MSElementDescrP edP, DPoint3dP inputPoint, double inputTolerance)
          {
          double distance = 0;
          auto retVal = mdlElmdscr_distanceAtPoint(&distance, position, tangent, edP, inputPoint, inputTolerance);
          return py::make_tuple(retVal, distance);
          }, "position"_a, "tangent"_a, "edP"_a, "inputPoint"_a, "inputTolerance"_a);

    c1.def_static("ExtractAttributes", [] (bvector<UInt16>& attributes, MSElementDescrP elDscr)
          {
          UInt16 attrib[MAX_ATTRIBSIZE] = {0};
          int length = 0;
          mdlElmdscr_extractAttributes(&length, attrib, elDscr);

          if ((int) attributes.size() < length)
              attributes.resize(length);
          std::copy(attrib, attrib + length, attributes.begin());
          }, "attributes"_a, "elDscr"_a);

    c1.def_static("ExtractNormal", &mdlElmdscr_extractNormal, "normal"_a, "point"_a, "edP"_a, "inputDefaultNormal"_a, DOC(MstnPlatform, MSElementDescr, ExtractNormal));
    c1.def_static("ExtractNormalTight", &mdlElmdscr_extractNormalTight, "normal"_a, "point"_a, "edP"_a, "inputDefaultNormal"_a, DOC(MstnPlatform, MSElementDescr, ExtractNormalTight));
    c1.def_static("ExtractNormalWithTolerance", &mdlElmdscr_extractNormalWithTolerance, "normal"_a, "point"_a, "edP"_a, "inputDefaultNormal"_a, "absTol"_a, "localRelTol"_a, "globalRelTol"_a, DOC(MstnPlatform, MSElementDescr, ExtractNormalWithTolerance));
    
    c1.def_static("EvaluateCurveSpace", [] (MSElementDescrCP descr, DPoint3dP origin, RotMatrixP matrix)
          {
          int tangentDimensions = 0;
          auto retVal = mdlElmdscr_evaluateCurveSpace(descr, origin, matrix, &tangentDimensions);
          return py::make_tuple(retVal, tangentDimensions);
          }, "descr"_a, "origin"_a, "matrix"_a);

    c1.def_static("OrientationExt", &mdlElmdscr_orientationExt, "transform"_a, "sourceDescr"_a, "modelRef"_a, DOC(MstnPlatform, MSElementDescr, OrientationExt));

    c1.def_static("PartialDelete", [] (MSElementDescrP inEdP, DPoint3dP point1, DPoint3dP point2, DPoint3dP point3, int view)
          {
          MSElementDescrP outEdP1 = nullptr;
          MSElementDescrP outEdP2 = nullptr;
          auto retVal = mdlElmdscr_partialDelete(&outEdP1, &outEdP2, inEdP, point1, point2, point3, view);
          return py::make_tuple(retVal, outEdP1, outEdP2);
          }, "inEdP"_a, "point1"_a, "point2"_a, "point3"_a, "view"_a);

    c1.def_static("PointAtDistance", &mdlElmdscr_pointAtDistance, "position"_a, "tangent"_a, "inputDistance"_a, "edP"_a, "inputTolerance"_a, DOC(MstnPlatform, MSElementDescr, PointAtDistance));

    c1.def_static("Read", [] (UInt32 filePos, DgnModelRefP modelRef, int expendSharedCells)
          {
          MSElementDescrP elemDescr = nullptr;
          UInt32 readFilePos = 0;
          auto retVal = mdlElmdscr_read(&elemDescr, filePos, modelRef, expendSharedCells, &readFilePos);
          return py::make_tuple(retVal, elemDescr, readFilePos);
          }, "filePos"_a, "modelRef"_a, "expendSharedCells"_a);

    c1.def_static("GetByElemRef", [] (ElementRefP elemRef, DgnModelRefP modelRef, int expendSharedCells)
          {
          MSElementDescrP elemDescr = nullptr;
          UInt32 readFilePos = 0;
          auto retVal = mdlElmdscr_getByElemRef(&elemDescr, elemRef, modelRef, expendSharedCells, &readFilePos);
          return py::make_tuple(retVal, elemDescr, readFilePos);
          }, "elemRef"_a, "modelRef"_a, "expendSharedCells"_a);

    c1.def_static("GetThicknessEdP", &mdlElmdscr_getThicknessEdP, "edP"_a, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, MSElementDescr, GetThicknessEdP));

    c1.def_static("ReadToMaster", [] (UInt32 filePos, DgnModelRefP modelRef, int expendSharedCells)
          {
          MSElementDescrP elemDescr = nullptr;
          UInt32 readFilePos = 0;
          auto retVal = mdlElmdscr_readToMaster(&elemDescr, filePos, modelRef, expendSharedCells, &readFilePos);
          return py::make_tuple(retVal, elemDescr, readFilePos);
          }, "filePos"_a, "modelRef"_a, "expendSharedCells"_a);

    c1.def_static("ReadComponentToMaster", [] (DisplayPathCP path, int elementNumber, int expandSharedCells, bool returnNonCellHeader, bool allowGroupHoles, UInt32 *startFilePos)
          {
          MSElementDescrP edP = nullptr;
          auto retVal = mdlElmdscr_readComponentToMaster(&edP, path, elementNumber, expandSharedCells, returnNonCellHeader, allowGroupHoles, startFilePos);
          return py::make_tuple(retVal, edP);
          }, "path"_a, "elementNumber"_a, "expendSharedCells"_a, "returnNonCellHeader"_a, "allowGroupHoles"_a, "startFilePos"_a);

    c1.def_static("Rewrite", &mdlElmdscr_rewrite, "newElemDescr"_a, "oldElemDescr"_a, "filePos"_a, DOC(MstnPlatform, MSElementDescr, Rewrite));

    c1.def_static("StripAttributes", [] (MSElementDescrP elDescr)
          {
          MSElementDescrP elDescr_ {elDescr};
          mdlElmdscr_stripAttributes(&elDescr_);
          return elDescr_;
          }, "elDescr"_a);

    c1.def_static("StripFill", [] (MSElementDescrP elDescr)
          {
          MSElementDescrP elDescr_ {elDescr};
          mdlElmdscr_stripFill(&elDescr_);
          return elDescr_;
          }, "elDescr"_a);

    c1.def_static("Stroke", [] (DPoint3dArray& points, MSElementDescrP edP, double tol)
          {
          DPoint3dP pPnts = nullptr;
          int nPoints = 0;
          auto retVal = mdlElmdscr_stroke(&pPnts, &nPoints, edP, tol);
          if (retVal == SUCCESS && nullptr != pPnts && nPoints > 0)
              {
              points.resize(nPoints);
              std::copy(pPnts, pPnts + nPoints, points.begin());
              dlmSystem_mdlFree(pPnts);
              }
          return retVal;
          }, "points"_a, "edP"_a, "tol"_a);

    c1.def_static("Transform", [] (MSElementDescrP edP, TransformCP userTrans)
          {
          MSElementDescrP edP_ {edP};
          auto retVal = mdlElmdscr_transform(&edP_, userTrans);
          return py::make_tuple(retVal, edP_);
          }, "edP"_a, "userTrans"_a);

    c1.def_static("TransformAllowModification", [] (MSElementDescrP edP, TransformCP userTrans, DgnModelRefP sourceModelRef, DgnModelRefP destModelRef, const UInt32 options)
          {
          MSElementDescrP edP_ {edP};
          mdlElmdscr_transformAllowModification(&edP_, userTrans, sourceModelRef, destModelRef, options);
          return edP_;
          }, "edP"_a, "userTrans"_a, "sourceModelRef"_a, "destModelRef"_a, "options"_a);

    c1.def_static("UndoableDelete", &mdlElmdscr_undoableDelete, "elemDescr"_a, "filePos"_a, "display"_a, DOC(MstnPlatform, MSElementDescr, UndoableDelete));
    c1.def_static("DeleteByModelRef", &mdlElmdscr_deleteByModelRef, "elemDescr"_a, "filePos"_a, "modelRef"_a, "display"_a, DOC(MstnPlatform, MSElementDescr, DeleteByModelRef));
    c1.def_static("DisplayFromFileViews", &mdlElmdscr_displayFromFileViews, "filePos"_a, "modelRef"_a, "elP"_a, "drawMode"_a, "viewMask"_a, DOC(MstnPlatform, MSElementDescr, DisplayFromFileViews));
    c1.def_static("DisplayInSelectedViews", &mdlElmdscr_displayInSelectedViews, "elemDescr"_a, "modelRef"_a, "drawMode"_a, "viewMask"_a, DOC(MstnPlatform, MSElementDescr, DisplayInSelectedViews));
    
    c1.def_static("GeneratePartial", [] (MSElementDescrCP elemDescr, double t1, double t2, bool splineParameters)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_generatePartial(&outEdP, elemDescr, t1, t2, splineParameters);
          return py::make_tuple(retVal, outEdP);
          }, "elemDescr"_a, "t1"_a, "t2"_a, "splineParameters"_a);

    c1.def_static("Reverse", [] (MSElementDescrCP inEdP, DgnModelRefP modelRef)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_reverse(&outEdP, inEdP, modelRef);
          return py::make_tuple(retVal, outEdP);
          }, "inEdP"_a, "modelRef"_a);

    c1.def_static("ReverseNormal", [] (MSElementDescrCP inEdP, DgnModelRefP modelRef)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_reverseNormal(&outEdP, inEdP, modelRef);
          return py::make_tuple(retVal, outEdP);
          }, "inEdP"_a, "modelRef"_a);

    c1.def_static("UnionShapes", [] (MSElementDescrP shape1, MSElementDescrP shape2, double tol)
          {
          MSElementDescrP edP = nullptr;
          MSElementDescrP obsoleteEdP = nullptr;
          auto retVal = mdlElmdscr_unionShapes(&edP, &obsoleteEdP, shape1, shape2, tol);
          return py::make_tuple(retVal, edP, obsoleteEdP);
          }, "shape1"_a, "shape2"_a, "tol"_a);

    c1.def_static("IntersectShapes", [] (MSElementDescrP shape1, MSElementDescrP shape2, double tol)
          {
          MSElementDescrP edP = nullptr;
          MSElementDescrP obsoleteEdP = nullptr;
          auto retVal = mdlElmdscr_intersectShapes(&edP, &obsoleteEdP, shape1, shape2, tol);
          return py::make_tuple(retVal, edP, obsoleteEdP);
          }, "shape1"_a, "shape2"_a, "tol"_a);

    c1.def_static("DifferenceShapes", [] (MSElementDescrP minuend, MSElementDescrP subtrahend, double tol)
          {
          MSElementDescrP edP = nullptr;
          MSElementDescrP obsoleteEdP = nullptr;
          auto retVal = mdlElmdscr_differenceShapes(&edP, &obsoleteEdP, minuend, subtrahend, tol);
          return py::make_tuple(retVal, edP, obsoleteEdP);
          }, "minuend"_a, "subtrahend"_a, "tol"_a);

    c1.def_static("ExtractEndPoints", &mdlElmdscr_extractEndPoints, "startP"_a, "startTangentP"_a, "endP"_a, "endTangentP"_a, "edP"_a, "modelRef"_a, DOC(MstnPlatform, MSElementDescr, ExtractEndPoints));

    c1.def_static("FromCompoundElement", [] (MSElementP elemP, DgnModelRefP modelRef, UInt32 graphicGroup, bool transformToWorld, bool expandNested)
          {
          MSElementDescrP edP = nullptr;
          auto retVal = mdlElmdscr_fromCompoundElement(&edP, elemP, modelRef, graphicGroup, transformToWorld, expandNested);
          return py::make_tuple(retVal, edP);
          }, "elemP"_a, "modelRef"_a, "graphicGroup"_a, "transformToWorld"_a, "expandNested"_a);

    c1.def_static("IsClosed", &mdlElmdscr_isClosed, "edP"_a, DOC(MstnPlatform, MSElementDescr, IsClosed));
    c1.def_static("IsOpen", &mdlElmdscr_isOpen, "edP"_a, DOC(MstnPlatform, MSElementDescr, IsOpen));
    c1.def_static("IsGroupedHole", &mdlElmdscr_isGroupedHole, "groupEdP"_a, DOC(MstnPlatform, MSElementDescr, IsGroupedHole));
    c1.def_static("HasLineStyle", &mdlElmdscr_hasLineStyle, "lineStyleEdP"_a, DOC(MstnPlatform, MSElementDescr, HasLineStyle));

    c1.def_static("CreateShapeWithHoles", [] (MSElementDescrP solidEdP, MSElementDescrP holeEdP)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_createShapeWithHoles(&outEdP, solidEdP, holeEdP);
          return py::make_tuple(retVal, outEdP);
          }, "solidEdP"_a, "holeEdP"_a);

    c1.def_static("Close", [] (MSElementDescrP inEdP, DgnModelRefP modelRef)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_close(&outEdP, inEdP, modelRef);
          return py::make_tuple(retVal, outEdP);
          }, "inEdP"_a, "modelRef"_a);

    c1.def_static("Open", [] (MSElementDescrP inEdP, DgnModelRefP modelRef)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_open(&outEdP, inEdP, modelRef);
          return py::make_tuple(retVal, outEdP);
          }, "inEdP"_a, "modelRef"_a);

    c1.def_static("Show", &mdlElmdscr_show, "edP"_a, "currentIndent"_a, DOC(MstnPlatform, MSElementDescr, Show));

    c1.def_static("FromSelectionSet", [] ()
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_fromSelectionSet(&outEdP);
          return py::make_tuple(retVal, outEdP);
          });

    c1.def_static("Fillet", &mdlElmdscr_fillet, "fillet"_a, "template"_a, "in0EdP"_a, "in1EdP"_a, "inputRadius"_a, "inputPoint"_a, "inputRotMatrix"_a, DOC(MstnPlatform, MSElementDescr, Fillet));

    c1.def_static("SpaceFillet", [] (MSElementP Template, MSElementDescrCP curveA, MSElementDescrCP curveB, double radius, DPoint3dP centerSelect)
          {
          MSElementDescrP outEdP = nullptr;
          auto retVal = mdlElmdscr_spaceFillet(&outEdP, Template, curveA, curveB, radius, centerSelect);
          return py::make_tuple(retVal, outEdP);
          }, "template"_a, "curveA"_a, "curveB"_a, "radius"_a, "centerSelect"_a);

    c1.def_static("GetProperties", [] (MSElementDescrCP edP)
          {
          DgnPlatform::LevelId level = -1;
          UInt32 ggNum = -1;
          DgnElementClass dgnClass = DgnElementClass::Construction;
          bool locked = false;
          bool newElm = false;
          bool modified = false;
          bool viewIndepend = false;
          bool solidHole = false;
          mdlElmdscr_getProperties(&level, &ggNum, &dgnClass, &locked, &newElm, &modified, &viewIndepend, &solidHole, edP);
          return py::make_tuple(level, ggNum, dgnClass, locked, newElm, modified, viewIndepend, solidHole);
          }, "edP"_a);


    }