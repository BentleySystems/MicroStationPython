/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementgraphics.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementGraphics.h>



static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__OutputGraphics =R"doc(Allow processor to output graphics to it's process methods.

Parameter ``context``:
    The current view context.

Remark:
    s Processor is responsible for setting path root,
    attaching/detaching viewports, etc. if model wasn't supplied to
    Process method.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__GetDrawPurpose =R"doc(Allow processor to override the default draw purpose.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__GetFacetOptionsP =R"doc(Allow processor to override the default facet options.

Returns:
    A pointer to facet option structure to use or NULL to use default
    options.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessFacets =R"doc(Collect output for surfaces and solids as facets.

Parameter ``meshData``:
    The indexed polyface data.

Parameter ``isFilled``:
    The wireframe display of the mesh has opaque fill.

Remark:
    s Only called if _ProcessAsFacets returns true.

Returns:
    SUCCESS if handled.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessBody =R"doc(Collect output for surfaces and solids using a solid kernel entity.

Parameter ``entity``:
    The solid kernel entity.

Parameter ``attachments``:
    Optional face color/material attachment information. @note
    Requires host implementation of SolidsKernelAdmin methods that
    take or return a ISolidKernelEntity.

Remark:
    s Only called if _ProcessAsBody returns true.

Returns:
    SUCCESS if handled.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessSurface =R"doc(Collect output as a bspline surface.

Parameter ``surface``:
    The bspline surface data.

Returns:
    SUCCESS if handled, return ERROR to output according to
    _ProcessBody, _ProcessFacets, and _ProcessCurveVector rules.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessSolidPrimitive =R"doc(Collect output as a solid primitive.

Parameter ``primitive``:
    The solid primitive data.

Returns:
    SUCCESS if handled, return ERROR to output according to
    _ProcessBody, _ProcessFacets, and _ProcessCurveVector rules.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessCurveVector =R"doc(Collect output as a CurveVector.

Parameter ``curves``:
    The curve data.

Parameter ``isFilled``:
    A closed path or region should have opaque fill.

Returns:
    SUCCESS if handled, ERROR to output individual curves through
    _ProcessCurvePrimitive.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessCurvePrimitive =R"doc(Collect output as a single curve component.

Parameter ``curve``:
    The curve data.

Parameter ``isClosed``:
    The data is from a closed path or region instead of a physically
    closed path.

Parameter ``isFilled``:
    A closed path or region should have opaque fill.

Remark:
    s All curve geometry can be handled through _ProcessCurveVector.

See also:
    _ProcessCurveVector.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessTextString =R"doc(Collect output as text.

Parameter ``text``:
    The text data.

Returns:
    SUCCESS if handled, ERROR to output glyph graphics through
    _ProcessCurveVector.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__AnnounceElemDisplayParams =R"doc(Supply the current symbology used to generate the ElemMatSym values.

Parameter ``displayParams``:
    The symbology to apply to subsequent process calls.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__AnnounceElemMatSymb =R"doc(Supply the current symbology that subsequent geometry is displayed
with.

Parameter ``matSymb``:
    The symbology to apply to subsequent process calls.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__AnnounceTransform =R"doc(Supply the current transform that subsequent geometry is displayed
through.

Parameter ``trans``:
    The transform to apply to subsequent process calls.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__AnnounceContext =R"doc(Supply the current context that is processing the geometry.

Parameter ``context``:
    The current view context.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessAsBody =R"doc(Process surfaces and solids not handled directly or are clipped
through _ProcessBody.

Parameter ``isCurved``:
    Graphics output would contain non-linear edge and/or non-planar
    face geometry.

Returns:
    true to output solid kernel entities for surface and solid
    geometry. If returning false, facets will be output if
    _ProcessAsFacets returns true, otherwise edge and face isoline
    curves will be output through _ProcessCurveVector.

Remark:
    s Requires host implementation of SolidsKernelAdmin methods that
    take or return a ISolidKernelEntity. @note When returning true you
    also need to implement _ProcessBody.

See also:
    DgnPlatformLib::Host::SolidsKernelAdmin)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ProcessAsFacets =R"doc(Process surfaces and solids not handled directly or are clipped
through _ProcessFaceta.

Parameter ``isPolyface``:
    facets are from a call to DrawPolyface, ex. mesh element.

Returns:
    true to output facets for surface and solid geometry. If returning
    false, edge and face isoline curves will be output through
    _ProcessCurveVector.

Remark:
    s When both _ProcessAsFacets and _ProcessAsBody return true,
    _ProcessAsBody has precedence. @note When returning true you also
    need to implement _ProcessFacets.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__WantClipping =R"doc(Controls whether to output clipped graphics if any clipping is pushed
by display.

Returns:
    true to output clipped graphics.)doc";

static const char * __doc_Bentley_DgnPlatform_IElementGraphicsProcessor__ExpandPatterns =R"doc(Controls whether pattern graphics will be output.

Returns:
    true to output pattern and hatch graphics, false to skip patterns.)doc";

//=======================================================================================
// Trampoline class for IElementGraphicsProcessor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyElementGraphicsProcessor : IElementGraphicsProcessor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _ExpandPatterns() const override
        { PYBIND11_OVERRIDE_EXR(bool, IElementGraphicsProcessor, _ExpandPatterns, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/    
    virtual bool _WantClipping() const override
        { PYBIND11_OVERRIDE_EXR(bool, IElementGraphicsProcessor, _WantClipping, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _ProcessAsFacets(bool isPolyface) const override
        { PYBIND11_OVERRIDE_EXR(bool, IElementGraphicsProcessor, _ProcessAsFacets, false, isPolyface); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _ProcessAsBody(bool isCurved) const override
        { PYBIND11_OVERRIDE_EXR(bool, IElementGraphicsProcessor, _ProcessAsBody, false, isCurved); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _AnnounceContext(ViewContextR context) override
        { PYBIND11_OVERRIDE_EX(void, IElementGraphicsProcessor, _AnnounceContext, context); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _AnnounceTransform(TransformCP trans) override
        { PYBIND11_OVERRIDE_EX(void, IElementGraphicsProcessor, _AnnounceTransform, trans); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _AnnounceElemMatSymb(ElemMatSymbCR matSymb) override
        { PYBIND11_OVERRIDE_EX(void, IElementGraphicsProcessor, _AnnounceElemMatSymb, matSymb); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _AnnounceElemDisplayParams(ElemDisplayParamsCR displayParams) override
        { PYBIND11_OVERRIDE_EX(void, IElementGraphicsProcessor, _AnnounceElemDisplayParams, displayParams); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessTextString(TextStringCR text) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessTextString, ERROR, text); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessCurvePrimitive(ICurvePrimitiveCR curve, bool isClosed, bool isFilled) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessCurvePrimitive, ERROR, curve, isClosed, isFilled); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessCurveVector(CurveVectorCR curves, bool isFilled) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessCurveVector, ERROR, curves, isFilled); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessSolidPrimitive(ISolidPrimitiveCR primitive) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessSolidPrimitive, ERROR, primitive); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessSurface(MSBsplineSurfaceCR surface) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessSurface, ERROR, surface); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessBody(ISolidKernelEntityCR entity, IFaceMaterialAttachmentsCP attachments) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessBody, ERROR, entity, attachments); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BentleyStatus _ProcessFacets(PolyfaceQueryCR meshData, bool isFilled) override
        { PYBIND11_OVERRIDE_EXR(BentleyStatus, IElementGraphicsProcessor, _ProcessFacets, ERROR, meshData, isFilled); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IFacetOptionsP _GetFacetOptionsP() override
        { PYBIND11_OVERRIDE_EXR(IFacetOptionsP, IElementGraphicsProcessor, _GetFacetOptionsP, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DrawPurpose _GetDrawPurpose() override
        { PYBIND11_OVERRIDE_EXR(DrawPurpose, IElementGraphicsProcessor, _GetDrawPurpose, DrawPurpose::Update, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OutputGraphics(ViewContextR context) override
        { PYBIND11_OVERRIDE_EX(void, IElementGraphicsProcessor, _OutputGraphics, context); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementGraphics(py::module_& m)
    {
    //=======================================================================================
    // struct IElementGraphicsProcessor
    py::class_< IElementGraphicsProcessor, std::unique_ptr< IElementGraphicsProcessor, py::nodelete>, IPyElementGraphicsProcessor> c1(m, "IElementGraphicsProcessor");

    c1.def(py::init<>());
    c1.def("_ExpandPatterns", &IElementGraphicsProcessor::_ExpandPatterns, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ExpandPatterns));
    c1.def("_WantClipping", &IElementGraphicsProcessor::_WantClipping, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _WantClipping));
    c1.def("_ProcessAsFacets", &IElementGraphicsProcessor::_ProcessAsFacets, "isPolyface"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessAsFacets));
    c1.def("_ProcessAsBody", &IElementGraphicsProcessor::_ProcessAsBody, "isCurved"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessAsBody));
    c1.def("_AnnounceContext", &IElementGraphicsProcessor::_AnnounceContext, "context"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _AnnounceContext));
    c1.def("_AnnounceTransform", &IElementGraphicsProcessor::_AnnounceTransform, "trans"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _AnnounceTransform));
    c1.def("_AnnounceElemMatSymb", &IElementGraphicsProcessor::_AnnounceElemMatSymb, "matSymb"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _AnnounceElemMatSymb));
    c1.def("_AnnounceElemDisplayParams", &IElementGraphicsProcessor::_AnnounceElemDisplayParams, "displayParams"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _AnnounceElemDisplayParams));
    c1.def("_ProcessTextString", &IElementGraphicsProcessor::_ProcessTextString, "text"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessTextString));
    c1.def("_ProcessCurvePrimitive", &IElementGraphicsProcessor::_ProcessCurvePrimitive, "curve"_a, "isClosed"_a, "isFilled"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessCurvePrimitive));
    c1.def("_ProcessCurveVector", &IElementGraphicsProcessor::_ProcessCurveVector, "curves"_a, "isFilled"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessCurveVector));
    c1.def("_ProcessSolidPrimitive", &IElementGraphicsProcessor::_ProcessSolidPrimitive, "primitive"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessSolidPrimitive));
    c1.def("_ProcessSurface", &IElementGraphicsProcessor::_ProcessSurface, "surface"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessSurface));
    c1.def("_ProcessBody", &IElementGraphicsProcessor::_ProcessBody, "entity"_a, "attachments"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessBody));
    c1.def("_ProcessFacets", &IElementGraphicsProcessor::_ProcessFacets, "meshData"_a, "isFilled"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _ProcessFacets));
    c1.def("_GetFacetOptionsP", &IElementGraphicsProcessor::_GetFacetOptionsP, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _GetFacetOptionsP));
    c1.def("_GetDrawPurpose", &IElementGraphicsProcessor::_GetDrawPurpose, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _GetDrawPurpose));
    c1.def("_OutputGraphics", &IElementGraphicsProcessor::_OutputGraphics, "context"_a, DOC(Bentley, DgnPlatform, IElementGraphicsProcessor, _OutputGraphics));
    
    //=======================================================================================
    // struct ElementGraphicsOutput
    py::class_< ElementGraphicsOutput> c2(m, "ElementGraphicsOutput");

    c2.def_static("Process",
                  py::overload_cast<ElementHandleCR, IElementGraphicsProcessorR, DgnModelRefP>(&ElementGraphicsOutput::Process),
                  "eh"_a, "processor"_a, "rootParent"_a = nullptr);

    c2.def_static("Process",
                  py::overload_cast<IElementGraphicsProcessorR, DgnModelP>(&ElementGraphicsOutput::Process),
                  "processor"_a, "dgnModel"_a = nullptr);

    }