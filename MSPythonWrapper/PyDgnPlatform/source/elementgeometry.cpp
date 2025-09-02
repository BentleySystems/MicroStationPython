/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementgeometry.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementGeometry.h>



static const char * __doc_Bentley_DgnPlatform_IBRepEdit_SetBRepDataEntity =R"doc(Update element from bRep data.

:param eeh:
    Source element

:param entity:
    solid kernel entity data.

:returns:
    SUCCESS if the element was updated.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementGeometry(py::module_& m)
    {
    //===================================================================================
    // struct ICurvePathQuery
    py::class_< ICurvePathQuery, std::unique_ptr< ICurvePathQuery, py::nodelete> > c1(m, "ICurvePathQuery");

    c1.def("GetCurveVector", [] (ICurvePathQuery& self, ElementHandleCR eh)
           {
           CurveVectorPtr curves;
           auto retVal = self.GetCurveVector(eh, curves);
           return py::make_tuple(retVal, curves);
           }, "eh"_a);

    c1.def_static("ElementToCurveVector", &ICurvePathQuery::ElementToCurveVector, "eh"_a);
    c1.def_static("ElementToCurveVectors", &ICurvePathQuery::ElementToCurveVectors, "eh"_a, "curves"_a);
      
    //===================================================================================
    // struct ICurvePathEdit
    py::class_< ICurvePathEdit, std::unique_ptr< ICurvePathEdit, py::nodelete>, ICurvePathQuery> c2(m, "ICurvePathEdit");

    c2.def("SetCurveVector", &ICurvePathEdit::SetCurveVector, "eeh"_a, "path"_a);

    //===================================================================================
    // struct IBsplineSurfaceQuery
    py::class_< IBsplineSurfaceQuery, std::unique_ptr< IBsplineSurfaceQuery, py::nodelete> > c3(m, "IBsplineSurfaceQuery");

    c3.def("GetBsplineSurface", [] (IBsplineSurfaceQuery& self, ElementHandleCR eh)
           {
           MSBsplineSurfacePtr surface;
           auto retVal = self.GetBsplineSurface(eh, surface);
           return py::make_tuple(retVal, surface);
           }, "eh"_a);

    //===================================================================================
    // struct IBsplineSurfaceEdit
    py::class_< IBsplineSurfaceEdit, std::unique_ptr< IBsplineSurfaceEdit, py::nodelete>, IBsplineSurfaceQuery> c4(m, "IBsplineSurfaceEdit");

    c4.def("SetBsplineSurface", &IBsplineSurfaceEdit::SetBsplineSurface, "eeh"_a, "surface"_a);

    //===================================================================================
    // struct ISolidPrimitiveQuery
    py::class_< ISolidPrimitiveQuery, std::unique_ptr< ISolidPrimitiveQuery, py::nodelete> > c5(m, "ISolidPrimitiveQuery");

    c5.def("GetSolidPrimitive", [] (ISolidPrimitiveQuery& self, ElementHandleCR eh)
           {
           ISolidPrimitivePtr primitive;
           auto retVal = self.GetSolidPrimitive(eh, primitive);
           return py::make_tuple(retVal, primitive);
           }, "eh"_a);

    c5.def_static("ElementToSolidPrimitive", &ISolidPrimitiveQuery::ElementToSolidPrimitive, "eh"_a, "simplify"_a = true);

    //===================================================================================
    // struct ISolidPrimitiveEdit
    py::class_< ISolidPrimitiveEdit, std::unique_ptr< ISolidPrimitiveEdit, py::nodelete>, ISolidPrimitiveQuery> c6(m, "ISolidPrimitiveEdit");

    c6.def("SetSolidPrimitive", &ISolidPrimitiveEdit::SetSolidPrimitive, "eeh"_a, "primitive"_a);

    //===================================================================================
    // struct IMeshQuery
    py::class_< IMeshQuery, std::unique_ptr< IMeshQuery, py::nodelete> > c7(m, "IMeshQuery");

    c7.def("GetMeshData", [] (IMeshQuery& self, ElementHandleCR eh)
           {
           PolyfaceHeaderPtr meshData;
           auto retVal = self.GetMeshData(eh, meshData);
           return py::make_tuple(retVal, meshData);
           }, "eh"_a);

    //===================================================================================
    // struct IMeshEdit
    py::class_< IMeshEdit, std::unique_ptr< IMeshEdit, py::nodelete>, IMeshQuery> c8(m, "IMeshEdit");

    c8.def("SetMeshData", &IMeshEdit::SetMeshData, "eeh"_a, "meshData"_a);

    //===================================================================================
    // struct IBRepQuery
    py::class_< IBRepQuery, std::unique_ptr< IBRepQuery, py::nodelete> > c9(m, "IBRepQuery");

    c9.def("GetBRepDataEntity", [] (IBRepQuery& self, ElementHandleCR eh, bool useCache)
           {
           ISolidKernelEntityPtr entity;
           auto retVal = self.GetBRepDataEntity(eh, entity, useCache);
           return py::make_tuple(retVal, entity);
           }, "eh"_a, "useCache"_a = false);

    c9.def_static("GetSolidKernelToUORScale", &IBRepQuery::GetSolidKernelToUORScale, "dgnCache"_a);

    //===================================================================================
    // struct IBRepEdit
    py::class_< IBRepEdit, std::unique_ptr< IBRepEdit, py::nodelete>, IBRepQuery> c10(m, "IBRepEdit");

    c10.def("SetBRepDataEntity", &IBRepEdit::SetBRepDataEntity, "eeh"_a, "entity"_a, DOC(Bentley, DgnPlatform, IBRepEdit, SetBRepDataEntity));

    //===================================================================================
    // struct ICellQuery
    py::class_< ICellQuery, std::unique_ptr< ICellQuery, py::nodelete> > c11(m, "ICellQuery");

    c11.def("IsNormalCell", &ICellQuery::IsNormalCell, "eh"_a);
    c11.def("IsSharedCell", &ICellQuery::IsSharedCell, "eh"_a);
    c11.def("IsSharedCellDefinition", &ICellQuery::IsSharedCellDefinition, "eh"_a);
    c11.def("IsPointCell", &ICellQuery::IsPointCell, "eh"_a);
    c11.def("IsAnnotation", &ICellQuery::IsAnnotation, "eh"_a);
    c11.def("IsAnonymous", &ICellQuery::IsAnonymous, "eh"_a);
    c11.def("ExtractScale", &ICellQuery::ExtractScale, "scale"_a, "eh"_a);
    
    c11.def("ExtractName", [] (ICellQuery& self, ElementHandleCR eh)
            {
            WChar szName[1024] = {0};
            auto retVal = self.ExtractName(szName, _countof(szName), eh);
            return py::make_tuple(retVal, szName);
            }, "eh"_a);

    c11.def("ExtractDescription", [] (ICellQuery& self, ElementHandleCR eh)
            {
            WChar szName[2048] = {0};
            auto retVal = self.ExtractDescription(szName, _countof(szName), eh);
            return py::make_tuple(retVal, szName);
            }, "eh"_a);

    //===================================================================================
    // struct ISharedCellQuery
    py::class_< ISharedCellQuery, std::unique_ptr< ISharedCellQuery, py::nodelete>, ICellQuery> c12(m, "ISharedCellQuery");

    c12.def("GetMlineScaleOption", &ISharedCellQuery::GetMlineScaleOption, "eh"_a);
    c12.def("GetDimScaleOption", &ISharedCellQuery::GetDimScaleOption, "eh"_a);
    c12.def("GetDimRotationOption", &ISharedCellQuery::GetDimRotationOption, "eh"_a);
    c12.def("GetDefinition", &ISharedCellQuery::GetDefinition, "eh"_a, "dgnFile"_a, py::return_value_policy::reference_internal);
    
    c12.def("GetDefinitionId", [] (ISharedCellQuery& self, ElementHandleCR eh)
            {
            ElementId elemId = -1;
            auto retVal = self.GetDefinitionId(eh, elemId);
            return py::make_tuple(retVal, elemId);
            }, "eh"_a);

    c12.def("GetSharedCellOverrides", &ISharedCellQuery::GetSharedCellOverrides, "eh"_a, py::return_value_policy::reference_internal);
    c12.def_static("FindDefinitionByName", &ISharedCellQuery::FindDefinitionByName, "name"_a, "dgnFile"_a, py::return_value_policy::reference_internal);

    }