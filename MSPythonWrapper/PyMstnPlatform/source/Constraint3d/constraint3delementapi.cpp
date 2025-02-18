/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Constraint3d\constraint3delementapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/Constraint3dElement/Constraint3dElementApi.h>
#include <PSolid/PSolidCoreAPI.h>
#include <DgnPlatform/DisplayHandler.h>


USING_NAMESPACE_CONSTRAINT3D;

/// <summary>
/// This is a help class to create 3D constraint. Exposed function AddConstraint call into this class to make it easy to create 3D constraint from python side 
/// </summary>
class Constraint3dManager
{
public:
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                  12/24
    +---------------+---------------+---------------+---------------+---------------+------*/
    static bool AddConstraint(Constraint3dBase::Status& constraintStatus, ElementAgendaR constrainedElements, bvector<ISubEntityPtr>& subEntities, Constraint3dType consType, UInt32 flags, double dimValue, WCharCP varName)
    {
        size_t elementCount = constrainedElements.GetCount();
        if (consType != Constraint3dType::Fixed && (elementCount != 2 || elementCount != subEntities.size()))
        {
            return false;
        }
        if (consType == Constraint3dType::Fixed && (elementCount != 1 || 1 < subEntities.size()))
        {
            return false;
        }

        T_StdElementRefSet    hosts;
        T_Constraints         constraints;
        T_ElementTransformMap transformMap;
        if (!addConstraintAndSolve(constraintStatus, transformMap, constraints, hosts, constrainedElements, subEntities, consType, flags, dimValue, varName))
        {
            return false;
        }

        for (auto const& curr : transformMap)
        {
            EditElementHandle   eeh(curr.first, curr.first->GetDgnModelP());

            if (SUCCESS == eeh.GetHandler().ApplyTransform(eeh, TransformInfo(curr.second)))
                eeh.ReplaceInModel(curr.first);
        }
        return saveConstraintsToHost(constraints, hosts, constrainedElements[0].GetModelRef());
    }
private:
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                  12/24
    +---------------+---------------+---------------+---------------+---------------+------*/
    static GeometryIdPtr getGeometryIdPtr(EditElementHandleR eeh, ISubEntityCR subEntity)
    {
        GeometryIdPtr geometryId;
        switch (subEntity.GetSubEntityType())
        {
        case ISubEntity::SubEntityType_Vertex:
            return BRepVertexGeometryId::Create(eeh, subEntity);

        case ISubEntity::SubEntityType_Face:
            geometryId = FaceGeometryId::Create(eeh, subEntity);
            if (!geometryId.IsValid())
            {
                geometryId = RegionPlaneId::Create(eeh);;
            }
            return geometryId;

        case ISubEntity::SubEntityType_Edge:
            return EdgeGeometryId::Create(eeh, subEntity);
        }

        return nullptr;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                  12/24
    +---------------+---------------+---------------+---------------+---------------+------*/
    static bool getGeometryIdPtrs(T_GeometryIds& geometryIds, ElementAgendaR constrainedElements, bvector<ISubEntityPtr>& subEntities, Constraint3dType consType)
    {
        GeometryIdPtr geometryId;
        // Handle fixed constraint for whole element, this case doesn't need a face, edge or vertex
        if (consType == Constraint3dType::Fixed && subEntities.size() == 0)
        {
            assert(1 == constrainedElements.GetCount());
            geometryId = FixedElementId::Create(constrainedElements[0]);
            if (!geometryId.IsValid())
            {
                return false;
            }
            geometryIds.push_back(geometryId);
        }
        // Handle other constraint for faces, edges or vertexes
        else
        {
            for (int i = 0; i < constrainedElements.GetCount(); i++)
            {
                GeometryIdPtr geometryId = getGeometryIdPtr(constrainedElements[i], *subEntities[i]);
                if (!geometryId.IsValid())
                {
                    return false;
                }
                geometryIds.push_back(geometryId);
            }
        }

        T_StdElementRefSet  elementRefs;
        for (auto& geometryId : geometryIds)
        {
            ElementRefP elementRef = geometryId->GetElementRef();
            if (elementRefs.find(elementRef) == elementRefs.end())
            {
                elementRefs.insert(elementRef);
                ElementHandle eh(elementRef, elementRef->GetDgnModelP());
                Constraint3dTargetHostExtension* hostExtension;
                Handler& handler = eh.GetHandler();
                if (&handler != NULL && NULL != (hostExtension = Constraint3dTargetHostExtension::Cast(handler)))
                {
                    WString     cantAcceptReason;
                    hostExtension->ValidateConstraint3dTargets(cantAcceptReason, geometryIds, eh, true);
                }
            }
        }
        return true;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                  12/24
    +---------------+---------------+---------------+---------------+---------------+------*/
    static Constraint3dPtr createConstraint(T_GeometryIds& geometryIds, Constraint3dType consType, UInt32 flags, double dimValue, WCharCP varName, DgnModel& dgnModel)
    {
        WCharCP accessString = L"";
        if (nullptr != varName && wcslen(varName) != 0)
        {
            accessString = varName;
            IParameterDefinitionsPtr defs = IParameterDefinitions::GetForModel(dgnModel);
            if (defs.IsValid())
            {
                ParameterDefinition paramDef;
                if (ParameterStatus::Success == defs->FindByLabel(paramDef, varName))
                {
                    accessString = paramDef.GetAccessString();
                    ECValue ecValue;
                    defs->GetValue(ecValue, accessString);
                    if (ecValue.IsDouble())
                    {
                        ModelInfoCR modelInfo = dgnModel.GetModelInfo();
                        dimValue = ecValue.GetDouble() * modelInfo.GetUorPerStorage();
                    }
                }
            }
        }
        if (Constraint3dType::DCM3_DISTANCE == consType)
        {
            return DistanceDimension3d::Create(geometryIds, flags, dimValue, accessString);
        }
        else if (Constraint3dType::DCM3_ANGLE == consType)
        {
            DRay3d axis = DRay3d::FromOriginAndVector(DPoint3d::From(0, 0, 0), DVec3d::From(0, 0, 0));
            return Angle3dConstraint::Create(geometryIds, axis, flags, dimValue, accessString, Angle3dConstraint::AngleSettings::INVERTED_AXIS);
        }
        else
        {
            return Constraint3dBase::Create(consType, geometryIds, flags);
        }
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                  12/24
    +---------------+---------------+---------------+---------------+---------------+------*/
    static bool addConstraintAndSolve(Constraint3dBase::Status& constraintStatus, T_ElementTransformMap& transformMap, T_Constraints& constraints, T_StdElementRefSet& hosts, ElementAgendaR constrainedElements, bvector<ISubEntityPtr>& subEntities, Constraint3dType consType, UInt32 flags, double dimValue, WCharCP varName)
    {
        T_GeometryIds geometryIds;
        if (!getGeometryIdPtrs(geometryIds, constrainedElements, subEntities, consType))
        {
            return false;
        }

        DgnModelRefP modelRef = constrainedElements[0].GetModelRef();
        Constraint3dPtr newConstraint = createConstraint(geometryIds, consType, flags, dimValue, varName, *modelRef->GetDgnModelP());
        if (!newConstraint.IsValid())
        {
            return false;
        }

        T_StdElementRefSet      elementRefs;
        for (auto const& geometryId : geometryIds)
            elementRefs.insert(geometryId->GetElementRef());

        if (SUCCESS != Constraint3dElement::GetExistingConstraints(hosts, constraints, elementRefs, modelRef, false))
        {
            return false;
        }

        for (auto const& constraint : constraints)
        {
            if (constraint->IsRedundant(*newConstraint))
            {
                constraintStatus = Constraint3dBase::Status::Redundant;
                return false;
            }
        }

        constraints.push_back(newConstraint);
        Constraint3dSolver constraintSolver;
        if (SUCCESS != constraintSolver.Initialize(constraints, *modelRef) ||
            SUCCESS != constraintSolver.Evaluate(transformMap, *geometryIds.front()))
        {
            return false;
        }

        switch (constraintStatus = newConstraint->GetStatus())
        {
        case Constraint3dBase::Status::DCM3_D_OVER_DEFINED:
        case Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT:
        case Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT_DIMENSIONS:
        case Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT_OTHER:
        case Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT_UNKNOWN:
        case Constraint3dBase::Status::DCM3_D_NOT_SOLVED:
        case Constraint3dBase::Status::DCM3_D_BETWEEN_SET_MEMBERS:
            return false;

        case Constraint3dBase::Status::DCM3_D_UNKNOWN:
            if (Constraint3dType::Fixed != newConstraint->GetType())
            {
                return false;
            }
            break;
        default:
            break;
        }
        return true;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                  12/24
    +---------------+---------------+---------------+---------------+---------------+------*/
    static bool saveConstraintsToHost(T_Constraints& constraints, T_StdElementRefSet& hosts, DgnModelRefP modelRef)
    {
        EditElementHandle   hostEh;

        if (hosts.empty())
        {
            Constraint3dElement::Create(hostEh, *modelRef);
        }
        else
        {
            for (auto const& curr : hosts)
            {
                if (NULL == hostEh.GetElementRef())
                {
                    hostEh.SetElementRef(curr, modelRef);
                }
                else
                {
                    EditElementHandle eeh(curr, modelRef);
                    eeh.DeleteFromModel();
                }
            }
        }

        ElementRefP hostElementRef = hostEh.GetElementRef();

        if (hosts.size() > 1) // is merging
            Constraint3dElement::InitializeLocalIds(constraints);

        Constraint3dElement::SaveConstraints(hostEh, constraints);

        // Weird code below to call CreateSharedCellComplete, here we only want to call ValidateElementRange.
        // But ValidateElementRange is not published, it will cause compiling error when build PowerPlatformSDK:MstnExample-Python.
        // Call CreateSharedCellComplete instead as it only calls ValidateElementRange in it.
        //hostEh.GetDisplayHandler()->ValidateElementRange(hostEh, true);
        SharedCellHandler::CreateSharedCellComplete(hostEh);

        if (NULL == hostElementRef)
            hostEh.AddToModel();
        else
            hostEh.ReplaceInModel(hostElementRef);

        return true;
    }
};

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

    //===================================================================================
    // struct Constraint3dManager
    py::class_<Constraint3dManager> c4(m, "Constraint3dManager");

    c4.def_static("AddConstraint", [](ElementAgendaR constrainedElements, bvector<ISubEntityPtr>& subEntities, Constraint3dType consType, UInt32 flags, double dimValue, WCharCP varName)
        {
            Constraint3dBase::Status constraintStatus = Constraint3dBase::Status::DCM3_D_UNKNOWN;
            bool retVal = Constraint3dManager::AddConstraint(constraintStatus, constrainedElements, subEntities, consType, flags, dimValue, varName);
            return py::make_tuple(retVal, constraintStatus);
        }, "constrainedElements"_a, "subEntities"_a, "consType"_a, "flags"_a = 0, "dimValue"_a = 0.0, "varName"_a = L"");
    }