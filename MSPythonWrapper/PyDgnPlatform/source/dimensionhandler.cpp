/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dimensionhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DimensionHandler.h>



static const char * __doc_Bentley_DgnPlatform_DimensionTextPartId_Create =R"doc(Create a new dimension text part. Will fail if partType or partSubType
are not valid text parts.

:param partSegment:
    (input) segment number

:param partType:
    (input) part type

:param partSubType:
    (input) part subtype)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionTextPartId_GetPartSubType =R"doc(Queries the part sub type associated with this part.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionTextPartId_GetPartType =R"doc(Queries the part type associated with this part.)doc";

static const char * __doc_Bentley_DgnPlatform_DimensionTextPartId_GetPartSegment =R"doc(Queries the segment associated with this part.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetAnnScaleAllowed =R"doc(If true, the dimension will be assigned the model's annotation scale
if appropriate given the style and model settings.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetViewRMatrix =R"doc(Supplies a rotation matrix that determines the orientation of text
within the dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetDimRMatrix =R"doc(Supplies a rotation matrix that determines the orientation of the
dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetViewNumber =R"doc(Supplies a view number which is stored on the dimension. The value
will be ignored.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetDirFormat =R"doc(Supplies direction formatting information for the new dimension. Only
called when creating label lines.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetLevelID =R"doc(Supplies the level for the new dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetSymbology =R"doc(Supplies color, linestyle and weight information for the new
dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetTextStyle =R"doc(Supplies text style information for the new dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_IDimCreateData__GetDimStyle =R"doc(Supplies style information for the new dimension.)doc";

//=======================================================================================
// Trampoline class for IDimCreateData.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyDimCreateData : IDimCreateData
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DimensionStyleCR _GetDimStyle() const override
            { PYBIND11_OVERRIDE_PURE(DimensionStyleCR, IDimCreateData, _GetDimStyle, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DgnTextStyleCR _GetTextStyle() const override
            { PYBIND11_OVERRIDE_PURE(DgnTextStyleCR, IDimCreateData, _GetTextStyle, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual Symbology _GetSymbology() const override
            { PYBIND11_OVERRIDE_PURE(Symbology, IDimCreateData, _GetSymbology, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual LevelId _GetLevelID() const override
            { PYBIND11_OVERRIDE_PURE(LevelId, IDimCreateData, _GetLevelID, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DirectionFormatterCR _GetDirFormat() const override
            { PYBIND11_OVERRIDE(DirectionFormatterCR, IDimCreateData, _GetDirFormat, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int _GetViewNumber() const override
            { PYBIND11_OVERRIDE_PURE(int, IDimCreateData, _GetViewNumber, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RotMatrixCR _GetDimRMatrix() const override
            { PYBIND11_OVERRIDE_PURE(RotMatrixCR, IDimCreateData, _GetDimRMatrix, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RotMatrixCR _GetViewRMatrix() const override
            { PYBIND11_OVERRIDE_PURE(RotMatrixCR, IDimCreateData, _GetViewRMatrix, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetAnnScaleAllowed() const override
            { PYBIND11_OVERRIDE(bool, IDimCreateData, _GetAnnScaleAllowed, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DimensionHandler(py::module_& m)
    {
    //===================================================================================
    // struct IDimCreateData
    py::class_< IDimCreateData, std::unique_ptr<IDimCreateData, py::nodelete>, IPyDimCreateData> c1(m, "IDimCreateData");

    c1.def(py::init<>());
    c1.def("_GetDimStyle", &IDimCreateData::_GetDimStyle, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDimCreateData, _GetDimStyle));
    c1.def("_GetTextStyle", &IDimCreateData::_GetTextStyle, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDimCreateData, _GetTextStyle));
    c1.def("_GetSymbology", &IDimCreateData::_GetSymbology, DOC(Bentley, DgnPlatform, IDimCreateData, _GetSymbology));
    c1.def("_GetLevelID", &IDimCreateData::_GetLevelID, DOC(Bentley, DgnPlatform, IDimCreateData, _GetLevelID));
    c1.def("_GetDirFormat", &IDimCreateData::_GetDirFormat, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDimCreateData, _GetDirFormat));
    c1.def("_GetViewNumber", &IDimCreateData::_GetViewNumber, DOC(Bentley, DgnPlatform, IDimCreateData, _GetViewNumber));
    c1.def("_GetDimRMatrix", &IDimCreateData::_GetDimRMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDimCreateData, _GetDimRMatrix));
    c1.def("_GetViewRMatrix", &IDimCreateData::_GetViewRMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDimCreateData, _GetViewRMatrix));
    c1.def("_GetAnnScaleAllowed", &IDimCreateData::_GetAnnScaleAllowed, DOC(Bentley, DgnPlatform, IDimCreateData, _GetAnnScaleAllowed));

    //===================================================================================
    // struct IDimensionQuery
    py::class_< IDimensionQuery, std::unique_ptr<IDimensionQuery, py::nodelete> > c2(m, "IDimensionQuery");

    c2.def("GetDimensionType", &IDimensionQuery::GetDimensionType, "dimEh"_a);
    c2.def("GetDimensionStyle", &IDimensionQuery::GetDimensionStyle, "dimEh"_a);
    c2.def("GetOverrideFlags", py::overload_cast<ElementHandleCR>(&IDimensionQuery::GetOverrideFlags, py::const_), "dimEh"_a);
    c2.def("GetNumPoints", &IDimensionQuery::GetNumPoints, "dimEh"_a);
    c2.def("GetNumSegments", &IDimensionQuery::GetNumSegments, "dimEh"_a);
    c2.def("ExtractPoint", &IDimensionQuery::ExtractPoint, "dimEh"_a, "point"_a, "iPoint"_a);

    c2.def("GetHeight", [] (IDimensionQuery const& self, ElementHandleCR eh)
           {
           double height = 0;
           auto retVal = self.GetHeight(eh, height);
           return py::make_tuple(retVal, height);
           }, "eh"_a);

    c2.def("GetJustification", [] (IDimensionQuery const& self, ElementHandleCR eh, int segmentNo)
           {
           DimStyleProp_Text_Justification just;
           auto retVal = self.GetJustification(eh, segmentNo, just);
           return py::make_tuple(retVal, just);
           }, "eh"_a, "segmentNo"_a);

    c2.def("GetWitnessVisibility", [] (IDimensionQuery const& self, ElementHandleCR eh, int pointNo)
           {
           bool value;
           auto retVal = self.GetWitnessVisibility(eh, pointNo, value);
           return py::make_tuple(retVal, value);
           }, "eh"_a, "pointNo"_a);

    c2.def("GetWitnessUseAltSymbology", [] (IDimensionQuery const& self, ElementHandleCR eh, int pointNo)
           {
           bool value;
           auto retVal = self.GetWitnessUseAltSymbology(eh, pointNo, value);
           return py::make_tuple(retVal, value);
           }, "eh"_a, "pointNo"_a);

    c2.def("GetRotationMatrix", &IDimensionQuery::GetRotationMatrix, "dimEh"_a, "rMatrix"_a);

    c2.def("GetProxyCell", [] (IDimensionQuery const& self, ElementHandleCR dimElement, DPoint3dP origin, RotMatrixP rotMatrix)
           {
           ElementId proxyCellId = -1;
           auto retVal = self.GetProxyCell(dimElement, proxyCellId, origin, rotMatrix);
           return py::make_tuple(retVal, proxyCellId);
           }, "dimEh"_a, "origin"_a, "rotMatrix"_a);

    c2.def("GetTextOffset", &IDimensionQuery::GetTextOffset, "dimEh"_a, "segmentNo"_a, "offset"_a);
    c2.def("GetViewRotation", &IDimensionQuery::GetViewRotation, "dimEh"_a, "rotMatrix"_a);
    c2.def("GetAngularDimensionClockWiseSweep", &IDimensionQuery::GetAngularDimensionClockWiseSweep, "dimEh"_a);

    //===================================================================================
    // struct IDimensionEdit
    py::class_< IDimensionEdit, std::unique_ptr< IDimensionEdit, py::nodelete>, IDimensionQuery> c3(m, "IDimensionEdit");

    c3.def("ApplyDimensionStyle", &IDimensionEdit::ApplyDimensionStyle, "eeh"_a, "dimStyle"_a, "retainOverrides"_a);
    c3.def("SetPoint", &IDimensionEdit::SetPoint, "eeh"_a, "point"_a, "assocPt"_a, "iPoint"_a);
    c3.def("InsertPoint", &IDimensionEdit::InsertPoint, "eeh"_a, "point"_a, "assocPt"_a, "dimStyle"_a, "iPoint"_a);
    c3.def("SetHeight", &IDimensionEdit::SetHeight, "eeh"_a, "height"_a);
    c3.def("SetJustification", &IDimensionEdit::SetJustification, "eeh"_a, "segmentNo"_a, "just"_a);
    c3.def("SetWitnessVisibility", &IDimensionEdit::SetWitnessVisibility, "eeh"_a, "pointNo"_a, "value"_a);
    c3.def("SetWitnessUseAltSymbology", &IDimensionEdit::SetWitnessUseAltSymbology, "eeh"_a, "pointNo"_a, "value"_a);
    c3.def("SetRotationMatrix", &IDimensionEdit::SetRotationMatrix, "eeh"_a, "rotMatrix"_a);
    c3.def("DeletePoint", &IDimensionEdit::DeletePoint, "eeh"_a, "pointNo"_a);
    c3.def("SetProxyCell", &IDimensionEdit::SetProxyCell, "eeh"_a, "proxyCellId"_a, "origin"_a, "rotMatrix"_a);
    c3.def("SetTextOffset", &IDimensionEdit::SetTextOffset, "eeh"_a, "segmentNo"_a, "offset"_a);
    c3.def("SetViewRotation", &IDimensionEdit::SetViewRotation, "eeh"_a, "rotMatrix"_a);
    c3.def("SetAngularDimensionClockWiseSweep", &IDimensionEdit::SetAngularDimensionClockWiseSweep, "eeh"_a, "value"_a);
    c3.def("SetPointsForLabelLine", &IDimensionEdit::SetPointsForLabelLine, "eeh"_a, "segment"_a, "hitPath"_a, "offset"_a, "viewRMatrix"_a, "dimStyle"_a);

    //===================================================================================
    // struct DimensionTextPartId
    py::class_< DimensionTextPartId, RefCountedPtr<DimensionTextPartId>, ITextPartId> c4(m, "DimensionTextPartId");

    c4.def_property_readonly("PartSegment", &DimensionTextPartId::GetPartSegment);
    c4.def("GetPartSegment", &DimensionTextPartId::GetPartSegment, DOC(Bentley, DgnPlatform, DimensionTextPartId, GetPartSegment));
    
    c4.def_property_readonly("PartType", &DimensionTextPartId::GetPartType);
    c4.def("GetPartType", &DimensionTextPartId::GetPartType, DOC(Bentley, DgnPlatform, DimensionTextPartId, GetPartType));
    
    c4.def_property_readonly("PartSubType", &DimensionTextPartId::GetPartSubType);
    c4.def("GetPartSubType", &DimensionTextPartId::GetPartSubType, DOC(Bentley, DgnPlatform, DimensionTextPartId, GetPartSubType));

    c4.def_static("Create",
                  py::overload_cast<UInt32, DimensionPartType, DimensionPartSubType>(&DimensionTextPartId::Create),
                  "partSegment"_a, "partType"_a, "partSubType"_a, DOC(Bentley, DgnPlatform, DimensionTextPartId, Create));

    c4.def_static("Create",
                  py::overload_cast<UInt32, DimensionTextPartType, DimensionTextPartSubType>(&DimensionTextPartId::Create),
                  "partSegment"_a, "partType"_a, "partSubType"_a, DOC(Bentley, DgnPlatform, DimensionTextPartId, Create));

    //===================================================================================
    // struct DimensionHandler
    py::class_< DimensionHandler, DisplayHandler, IDimensionEdit, ITransactionHandler, IAnnotationHandler, ITextEdit> c5(m, "DimensionHandler");

    c5.def_static("GetTextPointNo", [] (ElementHandleCR element, int segmentNo)
                  {
                  int pointNo = 0;
                  auto retVal = DimensionHandler::GetTextPointNo(pointNo, element, segmentNo);
                  return py::make_tuple(retVal, pointNo);
                  }, "dimElement"_a, "segmentNo"_a);

    c5.def_static("CreateDimensionElement", &DimensionHandler::CreateDimensionElement, "dimEeh"_a, "createData"_a, "dimType"_a, "is3d"_a, "modelRef"_a);
    c5.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<DimensionHandler, py::nodelete>(&DimensionHandler::GetInstance()); });
    c5.def_static("GetInstance", &DimensionHandler::GetInstance, py::return_value_policy::reference);
    }