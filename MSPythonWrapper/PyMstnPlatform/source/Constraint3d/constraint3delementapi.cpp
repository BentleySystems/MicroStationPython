/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Constraint3d\constraint3delementapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/Constraint3dElement/Constraint3dElementApi.h>



USING_NAMESPACE_CONSTRAINT3D;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Constraint3dElementApi(py::module_& m)
    {
    //===================================================================================
    // struct Constraint3dElement
    py::class_<Constraint3dElement> c1(m, "Constraint3dElement");

    c1.def_static("Create", &Constraint3dElement::Create, "eeh"_a, "destinationModelRef"_a);
    c1.def_static("GetHostElement", &Constraint3dElement::GetHostElement, "hostEeh"_a, "eh"_a, "searchGroup"_a = false);
    c1.def_static("HasConstraints", &Constraint3dElement::HasConstraints, "eh"_a);
    c1.def_static("IsGroupedToConstraint", &Constraint3dElement::IsGroupedToConstraint, "eh"_a);
    c1.def_static("GetExistingConstraints", &Constraint3dElement::GetExistingConstraints, "hosts"_a, "constraints"_a, "elemRefs"_a, "modelRef"_a, "doGroups"_a);

    c1.def_static("GetConstraints", py::overload_cast<T_Constraints&, ElementHandleCR>(&Constraint3dElement::GetConstraints), "constraints"_a, "hostEh"_a);
    c1.def_static("SaveConstraints", py::overload_cast<EditElementHandleR, T_Constraints&>(&Constraint3dElement::SaveConstraints), "eeh"_a, "constraints"_a);
    c1.def_static("IsConstraintElement", &Constraint3dElement::IsConstraintElement, "eh"_a);
    c1.def_static("GetConstraintDescription", &Constraint3dElement::GetConstraintDescription, "description"_a, "type"_a, "geometryStatus"_a);

    c1.def_static("ReevaluateAndUpdate", [] (ElementHandleCR dependentEh, T_Constraints& constraints, bool constraintsModified, bvector<ElementRefP>* rootSet)
                  {
                  bool anyUpdated = false;
                  bool rootsUpdated = false;
                  T_StdElementRefSet rootSet_;

                  if (nullptr != rootSet && !rootSet->empty())
                      {
                      for (auto& it : *rootSet)
                          rootSet_.insert(it);
                      }

                  auto retVal = Constraint3dElement::ReevaluateAndUpdate(anyUpdated, dependentEh, constraints, constraintsModified, &rootsUpdated, &rootSet_);
                  return py::make_tuple(retVal, anyUpdated, rootsUpdated);
                  }, "dependentEh"_a, "constraints"_a, "constraintsModified"_a, "rootSet"_a);

    c1.def_static("RemoveElementConstraints", &Constraint3dElement::RemoveElementConstraints, "eh"_a);

    c1.def_static("GetDegreesOfFreedom", [] (T_Constraints const& constraints, DgnModelRefR modelRef)
                  {
                  int dof = 0;
                  int removedDof = 0;
                  int rigidDof = 0;
                  auto retVal = Constraint3dElement::GetDegreesOfFreedom(dof, removedDof, rigidDof, constraints, modelRef);
                  return py::make_tuple(retVal, dof, removedDof, rigidDof);
                  }, "constraints"_a, "modelRef"_a);    

    //===================================================================================
    // struct Constraint3dGUI
    py::class_< Constraint3dGUI> c2(m, "Constraint3dGUI");

    c2.def_static("OpenDimensionDialog", [] (double& dimensionValue, WStringR variableAccess, DgnModelRefR modelRef, ViewportP viewport, DPoint3dCP origin)
                  {
                  double dimensionValue_ {dimensionValue};
                  Constraint3dGUI::OpenDimensionDialog(dimensionValue_, variableAccess, modelRef, viewport, origin);
                  return dimensionValue_;
                  }, "dimensionValue"_a, "variableAccess"_a, "modelRef"_a, "viewport"_a, "origin"_a);

    c2.def_static("OpenAngleDialog", [] (double& dimensionValue, WStringR variableAccess, DgnModelRefR modelRef, ViewportP viewport, DPoint3dCP origin)
                  {
                  double dimensionValue_ {dimensionValue};
                  Constraint3dGUI::OpenAngleDialog(dimensionValue_, variableAccess, modelRef, viewport, origin);
                  return dimensionValue_;
                  }, "dimensionValue"_a, "variableAccess"_a, "modelRef"_a, "viewport"_a, "origin"_a);

    c2.def_static("CloseDimensionDialog", &Constraint3dGUI::CloseDimensionDialog);

    //===================================================================================
    // struct Constraint3dDisplay
    py::class_< Constraint3dDisplay> c3(m, "Constraint3dDisplay");

    c3.def_static("DrawConstraints", &Constraint3dDisplay::DrawConstraints, "eh"_a, "viewContext"_a, "drawConstraintMarkers"_a, "drawDimensions"_a);
    c3.def_static("DrawPath", &Constraint3dDisplay::DrawPath, "path"_a, "viewContext"_a);
    }