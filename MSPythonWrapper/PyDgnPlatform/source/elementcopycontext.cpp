/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementcopycontext.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementCopyContext.h>



static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetDisableAnnotationScaling =R"doc(Direct that annotation scale should not be transformed during the
copy.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetDisableAnnotationScaling =R"doc(Get current value of annotation scaling option.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetDontPlaceTagsInGG =R"doc(Set the option to control whether tag elements in a graphic group are
copied to a new graphic group.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetDontPlaceTagsInGG =R"doc(Get the current value of the option for tags and graphic groups.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetSharedCellNameConflicts =R"doc(Specify what to do when a name conflict is encountered when deep-
copying a shared cell definition. This defaults to
SharedCellNameConflicts::HasDefId.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetSharedCellNameConflicts =R"doc(Get the current value of the option that controls how shared cell name
conflicts are resolved.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetKeepRefColorIndexOnCopy =R"doc(Set to control how 0-255 color indices are remapped. Set to true to
preserve color index instead of searching for a matching RGB.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetKeepRefColorIndexOnCopy =R"doc(Get the current value of the reference color index remap option.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetViewport =R"doc(Get the current viewport used for a flatten direction when copying
from a 3d source model to a 2d destination model.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetAssignNewGGs =R"doc(Get the current value of the assign new graphic group option.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetTransformToDestination =R"doc(Get the current value of transform to destination option.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetScaleReferenceDimensions =R"doc(Set to control how the value of a dimension in a reference is scaled
when copied to the destination model.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetScaleReferenceDimensions =R"doc(Get the current value of the scale reference dimensions option.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetMatchDimToDestination =R"doc(Get the current value of the match element dimension to destination
model option.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_DropHandler =R"doc(Un-register a handler.

:param handler:
    the handler to un-register. This function calls Release on
    *handler.*)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_AddHandler =R"doc(Register a handler to react when DoCopy is called.

:param handler:
    the handler to register. This function calls AddRef on *handler.*)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetModelFromElmdscr =R"doc(@DotNetMethodExclude)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_IsSameFile =R"doc(Query if the copy starts and ends in the same file (possibly different
models).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_IsSameCache =R"doc(Query if the copy starts and ends in the same model (possibly going
through a reference transform).)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_IsCopyFromReference =R"doc(Query if the source model is a reference attachment of the destination
model. (Returns ``False`` if the destination model is itself a
reference attachment to some other model.))doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetSourceCache =R"doc(Query the model that is the source of the copy.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetSourceModelRef =R"doc(Query the model or reference attachment that is the source of the
copy.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetSourceModelRef =R"doc(Identify the model that is the source of the copy. The source may be a
reference attachment.

Remark:
    s If the source modelRef is changing, this function will
    invalidate existing remap info.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetDestinationModel =R"doc(Query the model that is the destination of the copy.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_SetDestinationModelRef =R"doc(Identify the model that is the destination of the copy.

Remark:
    s In order to ensure that all changes are written to the
    destination file, this ElementCopyContext object must be destroyed
    or you must call SetDestinationModelRef(NULL) before you call
    ProcessChanges on the destination file.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_GetDestinationModelRef =R"doc(Query the model that is the destination of the copy.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementCopyContext_DoCopy =R"doc(Turn the specified element into a copy of the original. Units and ids
are remapped from the source to the destination model.

:param eh:
    The element that is to be transformed.

:returns:
    non-zero error status if remapping failed or write to cache
    failed.

Remark:
    s See GetWriteElements for whether the transformed element is
    actually written to the destination model.

Remark:
    s Invokes the following handler methods:
    Bentley::DgnPlatform::Handler::ChangetUnits 
    Bentley::DgnPlatform::Handler::ApplyTransform 
    Bentley::DgnPlatform::Handler::ConvertTo2d 
    Bentley::DgnPlatform::Handler::ConvertTo3d 
    Bentley::DgnPlatform::Handler::PreprocessCopy 
    Bentley::DgnPlatform::Handler::PostProcessCopy 
    Bentley::DgnPlatform::Handler::EditProperties 
    Bentley::DgnPlatform::Handler::_OnPreProcessDeepCopy 
    Bentley::DgnPlatform::XAttributeHandler::_PreprocessCopy  Bentl
    ey::DgnPlatform::IXAttributePointerContainerHandler::PreprocessCop
    yRemapIds See ElementCopyingAlgorithm

Remark:
    s The model of *eh* will be used as the source modelref.

Remark:
    s In order to ensure that all changes are written to the
    destination file, this ElementCopyContext object must be destroyed
    or you must call SetDestinationModelRef(NULL) before you call
    ProcessChanges on the destination file.

See also:
    IEventHandler)doc";

//=======================================================================================
// Trampoline class for ElementCopyContext::IEventHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyEventHandler : ElementCopyContext::IEventHandler
    {
    using IRefCounted::operator new;
    using IRefCounted::operator delete;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnElementCopied(EditElementHandleR eh, ElementCopyContext& cc, bool isPre) override
        { PYBIND11_OVERRIDE_PURE_EX(void, ElementCopyContext::IEventHandler, OnElementCopied, eh, cc, isPre); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnLevelCloned(ULong destLevelId, ULong sourceLevelId, bool uniqueName, ElementCopyContext& cc) override
        { PYBIND11_OVERRIDE_PURE_EX(void, ElementCopyContext::IEventHandler, OnLevelCloned, destLevelId, sourceLevelId, uniqueName, cc); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnProcessDatabaseLinkages(EditElementHandleR eh, ElementCopyContext& cc) override
        { PYBIND11_OVERRIDE_EX(void, ElementCopyContext::IEventHandler, OnProcessDatabaseLinkages, eh, cc); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 AddRef() const override
        { PYBIND11_OVERRIDE_PURE_EXR(UInt32, ElementCopyContext::IEventHandler, AddRef, 0, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 Release() const override
        { PYBIND11_OVERRIDE_PURE_EXR(UInt32, ElementCopyContext::IEventHandler, Release, 0, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementCopyContext(py::module_& m)
    {
    //===================================================================================
    // enum class CopyContextLevelOption
    py::enum_< CopyContextLevelOption>(m, "CopyContextLevelOption")
        .value("eByUserPreference", CopyContextLevelOption::ByUserPreference)
        .value("eCopyIfNotFound", CopyContextLevelOption::CopyIfNotFound)
        .value("eCopyIfDifferent", CopyContextLevelOption::CopyIfDifferent)
        .value("eCopyAlways", CopyContextLevelOption::CopyAlways)
        .value("eAlreadyRemapped", CopyContextLevelOption::AlreadyRemapped)
        .value("eCopyByNumber", CopyContextLevelOption::CopyByNumber)
        .export_values();
        
    //===================================================================================
    // struct ElementCopyContext
    py::class_< ElementCopyContext> c1(m, "ElementCopyContext");

    if (true)
        {
        //===================================================================================
        // enum class SharedCellNameConflicts
        py::enum_< ElementCopyContext::SharedCellNameConflicts>(c1, "SharedCellNameConflictsEnum")
            .value("eUndefined", ElementCopyContext::SharedCellNameConflicts::Undefined)
            .value("eNone", ElementCopyContext::SharedCellNameConflicts::None)
            .value("eHasDefId", ElementCopyContext::SharedCellNameConflicts::HasDefId)
            .value("eAll", ElementCopyContext::SharedCellNameConflicts::All)
            .export_values();

        //===================================================================================
        // struct IEventHandler
        py::class_< ElementCopyContext::IEventHandler, RefCountedPtr<ElementCopyContext::IEventHandler>, IPyEventHandler> c1_1(c1, "IEventHandler");

        c1_1.def(py::init<>());
        c1_1.def("OnElementCopied", &ElementCopyContext::IEventHandler::OnElementCopied, "eh"_a, "cc"_a, "isPre"_a);
        c1_1.def("OnLevelCloned", &ElementCopyContext::IEventHandler::OnLevelCloned, "destLevelId"_a, "sourceLevelId"_a, "uniqueName"_a, "cc"_a);
        c1_1.def("OnProcessDatabaseLinkages", &ElementCopyContext::IEventHandler::OnProcessDatabaseLinkages, "eeh"_a, "cc"_a);
        }

    c1.def(py::init<DgnModelRefP>(), "dest"_a);
    c1.def("DoCopy", &ElementCopyContext::DoCopy, "eh"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, DoCopy));
    
    c1.def_property("DestinationModelRef", &ElementCopyContext::GetDestinationModelRef, py::cpp_function(&ElementCopyContext::SetDestinationModelRef, py::keep_alive<1, 2>()));
    c1.def("GetDestinationModelRef", &ElementCopyContext::GetDestinationModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementCopyContext, GetDestinationModelRef));
    c1.def("SetDestinationModelRef", &ElementCopyContext::SetDestinationModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ElementCopyContext, SetDestinationModelRef));
    
    c1.def_property_readonly("DestinationModel", &ElementCopyContext::GetDestinationModel);
    c1.def("GetDestinationModel", &ElementCopyContext::GetDestinationModel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementCopyContext, GetDestinationModel));
    
    c1.def("SetSourceModelRef", &ElementCopyContext::SetSourceModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ElementCopyContext, SetSourceModelRef));
    c1.def("GetSourceModelRef", &ElementCopyContext::GetSourceModelRef, "el"_a = nullptr, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementCopyContext, GetSourceModelRef));
    c1.def("GetSourceCache", &ElementCopyContext::GetSourceCache, "el"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementCopyContext, GetSourceCache));    
    c1.def("IsCopyFromReference", &ElementCopyContext::IsCopyFromReference, DOC(Bentley, DgnPlatform, ElementCopyContext, IsCopyFromReference));    
    c1.def("IsSameCache", &ElementCopyContext::IsSameCache, "eh"_a = nullptr, DOC(Bentley, DgnPlatform, ElementCopyContext, IsSameCache));
    c1.def("IsSameFile", &ElementCopyContext::IsSameFile, "eh"_a = nullptr, DOC(Bentley, DgnPlatform, ElementCopyContext, IsSameFile));
    
    c1.def("GetModels", [] (ElementCopyContext& self, ElementHandleCP elemHandle)
           {
           DgnModelRefP srcModelRef = nullptr, destModelRef = nullptr;
           bool sameCache = false, sameFile = false;
           self.GetModels(&srcModelRef, &destModelRef, &sameCache, &sameFile, elemHandle);
           return py::make_tuple(srcModelRef, destModelRef, sameCache, sameFile);
           }, "elemHandle"_a = nullptr);

    c1.def_property("ModelFromElmdscr", &ElementCopyContext::GetModelFromElmdscr, &ElementCopyContext::SetModelFromElmdscr);
    c1.def("GetModelFromElmdscr", &ElementCopyContext::GetModelFromElmdscr, DOC(Bentley, DgnPlatform, ElementCopyContext, GetModelFromElmdscr));
    c1.def("SetModelFromElmdscr", &ElementCopyContext::SetModelFromElmdscr, "useElmdscr"_a);

    c1.def_static("AddHandler", &ElementCopyContext::AddHandler, "handler"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ElementCopyContext, AddHandler));
    c1.def_static("DropHandler", &ElementCopyContext::DropHandler, "handler"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, DropHandler));
    c1.def_property("WriteAllElements", &ElementCopyContext::GetWriteElements, &ElementCopyContext::SetWriteElements);
    c1.def("GetWriteAllElements", &ElementCopyContext::GetWriteElements);
    c1.def("SetWriteAllElements", &ElementCopyContext::SetWriteElements, "writeAllElements"_a);

    c1.def_property("MatchDimToDestination", &ElementCopyContext::GetMatchDimToDestination, &ElementCopyContext::SetMatchDimToDestination);
    c1.def("GetMatchDimToDestination", &ElementCopyContext::GetMatchDimToDestination, DOC(Bentley, DgnPlatform, ElementCopyContext, GetMatchDimToDestination));
    c1.def("SetMatchDimToDestination", &ElementCopyContext::SetMatchDimToDestination, "value"_a);
    
    c1.def_property("ScaleReferenceDimensions", &ElementCopyContext::GetScaleReferenceDimensions, &ElementCopyContext::SetScaleReferenceDimensions);
    c1.def("GetScaleReferenceDimensions", &ElementCopyContext::GetScaleReferenceDimensions, DOC(Bentley, DgnPlatform, ElementCopyContext, GetScaleReferenceDimensions));
    c1.def("SetScaleReferenceDimensions", &ElementCopyContext::SetScaleReferenceDimensions, "value"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, SetScaleReferenceDimensions));
    
    c1.def_property("TransformToDestination", &ElementCopyContext::GetTransformToDestination, &ElementCopyContext::SetTransformToDestination);
    c1.def("GetTransformToDestination", &ElementCopyContext::GetTransformToDestination, DOC(Bentley, DgnPlatform, ElementCopyContext, GetTransformToDestination));
    c1.def("SetTransformToDestination", &ElementCopyContext::SetTransformToDestination, "value"_a);
    
    c1.def_property("AssignNewGGs", &ElementCopyContext::GetAssignNewGGs, &ElementCopyContext::SetAssignNewGGs);    
    c1.def("GetAssignNewGGs", &ElementCopyContext::GetAssignNewGGs, DOC(Bentley, DgnPlatform, ElementCopyContext, GetAssignNewGGs));
    c1.def("SetAssignNewGGs", &ElementCopyContext::SetAssignNewGGs, "value"_a);
    
    c1.def_property("Viewport", &ElementCopyContext::GetViewport, py::cpp_function(&ElementCopyContext::SetViewport, py::keep_alive<1, 2>()));
    c1.def("GetViewport", &ElementCopyContext::GetViewport, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElementCopyContext, GetViewport));
    c1.def("SetViewport", &ElementCopyContext::SetViewport, "vp"_a, py::keep_alive<1, 2>());

    c1.def("SetLevelHandling", &ElementCopyContext::SetLevelHandling, "levelOption"_a);

    c1.def_property("KeepRefColorIndexOnCopy", &ElementCopyContext::GetKeepRefColorIndexOnCopy, &ElementCopyContext::SetKeepRefColorIndexOnCopy);
    c1.def("GetKeepRefColorIndexOnCopy", &ElementCopyContext::GetKeepRefColorIndexOnCopy, DOC(Bentley, DgnPlatform, ElementCopyContext, GetKeepRefColorIndexOnCopy));
    c1.def("SetKeepRefColorIndexOnCopy", &ElementCopyContext::SetKeepRefColorIndexOnCopy, "value"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, SetKeepRefColorIndexOnCopy));
    
    c1.def_property("SharedCellNameConflicts", &ElementCopyContext::GetSharedCellNameConflicts, &ElementCopyContext::SetSharedCellNameConflicts);
    c1.def("GetSharedCellNameConflicts", &ElementCopyContext::GetSharedCellNameConflicts, DOC(Bentley, DgnPlatform, ElementCopyContext, GetSharedCellNameConflicts));
    c1.def("SetSharedCellNameConflicts", &ElementCopyContext::SetSharedCellNameConflicts, "value"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, SetSharedCellNameConflicts));
    
    c1.def_property("DontPlaceTagsInGG", &ElementCopyContext::GetDontPlaceTagsInGG, &ElementCopyContext::SetDontPlaceTagsInGG);
    c1.def("GetDontPlaceTagsInGG", &ElementCopyContext::GetDontPlaceTagsInGG, DOC(Bentley, DgnPlatform, ElementCopyContext, GetDontPlaceTagsInGG));
    c1.def("SetDontPlaceTagsInGG", &ElementCopyContext::SetDontPlaceTagsInGG, "value"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, SetDontPlaceTagsInGG));
    
    c1.def_property("DisableAnnotationScaling", &ElementCopyContext::GetDisableAnnotationScaling, &ElementCopyContext::SetDisableAnnotationScaling);
    c1.def("GetDisableAnnotationScaling", &ElementCopyContext::GetDisableAnnotationScaling, DOC(Bentley, DgnPlatform, ElementCopyContext, GetDisableAnnotationScaling));
    c1.def("SetDisableAnnotationScaling", &ElementCopyContext::SetDisableAnnotationScaling, "value"_a, DOC(Bentley, DgnPlatform, ElementCopyContext, SetDisableAnnotationScaling));

    }