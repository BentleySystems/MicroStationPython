/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Constraint2d\constraint2dmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/Constraint2dElement/Constraint2dElementAPI.h>
#include <Mstn/Constraint2dElement/Constraint2dManager.h>



static const char * __doc_Bentley_MstnPlatform_Constraint2dManager_GetSolverData =R"doc(@description Get constraint data of the specified profile.

Parameter ``[out]``:
    solverData A Constraint2dSolverData object receiving constraint
    model data.

Parameter ``[in]``:
    eh An element handle to specify where to get the data. *eh* can be
    any element of the members constructing the profile.

Parameter ``[in]``:
    includingDeleted A boolean to specify whether to include being-
    deleted elements. If set to **True**, this method will check and
    try to resolve members if they are deleted; otherwise if set to
    **False**(by default) deleted elements will be left unresolved.

Returns:
    SUCCESS if implemented successfully; otherwise an error code
    indicating the failing reason.

See also:
    AddSolverData, Constraint2dSolverData)doc";

static const char * __doc_Bentley_MstnPlatform_Constraint2dManager_AddSolverData =R"doc(@description Store constraints data.

Parameter ``[in]``:
    eh An element handle to specify where to store the data. *eh* can
    be any of the member elements that are constructing the profile.

Parameter ``[in]``:
    solverData A Constraint2dSolverData object holding constraint
    model data to store.

Returns:
    SUCCESS if implemented successfully; otherwise an error code
    indicating the failing reason.

Remark:
    s This method will merge the passed-in *solverData* with the
    previous constraints if any.

See also:
    GetSolverData, Constraint2dSolverData)doc";

USING_NAMESPACE_CONSTRAINT2D;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Constraint2dManager(py::module_& m)
    {
    //===================================================================================
    // struct Constraint2dManager
    py::class_< Constraint2dManager> c1(m, "Constraint2dManager");

    c1.def_static("AddSolverData", &Constraint2dManager::AddSolverData, "eh"_a, "solverData"_a, DOC(Bentley, MstnPlatform, Constraint2dManager, AddSolverData));

    c1.def_static("GetSolverData", &Constraint2dManager::GetSolverData, "solverData"_a, "eh"_a, "includingDeleted"_a = false, DOC(Bentley, MstnPlatform, Constraint2dManager, GetSolverData));

    c1.def_static("AddConstraint", [](ElementAgendaR constrainedElements, Constraint2dType consType, int primitiveId1,
                                      int defaultSubIndex1, int primitiveId2, int defaultSubIndex2, double dimValue, WCharCP varName)
                                    {
                                        return Constraint2dManager::AddConstraint(constrainedElements, consType, primitiveId1, defaultSubIndex1, primitiveId2, defaultSubIndex2, dimValue, WString(varName));
                                    }, "constraintedElements"_a, "constraintType"_a, "primitiveId1"_a = 0, "defaultSubIndex1"_a = 0, 
                                       "primitiveId2"_a = 0, "defaultSubIndex2"_a = 0, "dimValue"_a = 0.0, "varName"_a = L"");

    c1.def_static("AddConstraint", [](ElementAgendaR constrainedElements, Constraint2dType consType, 
                                      bvector<int> const& primitiveIndexes, bvector<int> const& subIndexes, bvector<VertexType> const& vertexTypes,
                                      double dimValue, WCharCP varName)
        {
            return Constraint2dManager::AddConstraint(constrainedElements, consType, primitiveIndexes, subIndexes, vertexTypes, dimValue, WString(varName));
        }, "constraintedElements"_a, "constraintType"_a, "primitiveIndexes"_a, "subIndexes"_a, "vertexTypes"_a, "dimValue"_a = 0.0, "varName"_a = L"");

    c1.def_static("EvaluateAndUpdate", [] (Constraint2dSolverDataCR solverData, DgnModelR dgnModel, bvector<ElementRefP> const& directChanges, bool isDynamic,
                                           ElementAgendaP results, bvector<Constraint2dData>* inconsistentConstraints)
                  {
                  bset<Constraint2dData> inconsistentConstraints_;

                  auto retVal = Constraint2dManager::EvaluateAndUpdate(solverData, dgnModel, directChanges, isDynamic, results, &inconsistentConstraints_);
                  if (retVal && nullptr != inconsistentConstraints && !inconsistentConstraints_.empty())
                      {
                      for (auto& it : inconsistentConstraints_)
                          inconsistentConstraints->push_back(it);
                      }
                  return retVal;
                  }, "solverData"_a, "dgnModel"_a, "directChanges"_a, "isDynamic"_a = false, "results"_a = nullptr, "inconsistentConstraints"_a = nullptr);
    }