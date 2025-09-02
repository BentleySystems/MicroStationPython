/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\PyMstnPlatform.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* STL-liked container instantiation
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void bind_container_PyMstn(py::module_& m)
    {
    // bvector instantiation    
    }

/*---------------------------------------------------------------------------------**//**
* Forward declaration for class definition generators.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DocumentManager(py::module_&);
void def_ElementPropertyUtils(py::module_&);
void def_IEditAction(py::module_&);
void def_IEvent(py::module_&);
void def_IGlobalPosition(py::module_&);
void def_IPopupMenuManager(py::module_&);
void def_ISessionMgr(py::module_&);
void def_IXCommand(py::module_&);
void def_MicroStationApiErrors_r(py::module_&);
void def_XCommand(py::module_&);
void def_XCommandManager(py::module_&);
void def_dlogbox_r(py::module_&);
void def_MessageCenter(py::module_&);
void def_MicroStation_r(py::module_&);
void def_MstnTypes(py::module_&);

void def_MeshAPI(py::module_&);
void def_Constraint2dCoreAPI(py::module_&);
void def_Constraint2dManager(py::module_&);
void def_Constraint3dCoreAPI(py::module_&);
void def_Constraint3dElementApi(py::module_&);
void def_PSolidCoreAPI(py::module_&);
void def_SmartFeature_r(py::module_&);
void def_SmartFeatureAPI(py::module_&);

void def_leveltable(py::module_&);
void def_msacs(py::module_&);
void def_msassoc(py::module_&);
void def_msbitmask(py::module_&);
void def_mscell(py::module_&);
void def_msdgnmodelref(py::module_&);
void def_msdgnobj(py::module_&);
void def_mselmdsc(py::module_&);
void def_msinput(py::module_&);
void def_mscommandstate(py::module_&);
void def_msdialog(py::module_&);
void def_msexpression(py::module_&);
void def_msstring(py::module_& m);
void def_mssystem(py::module_&);
void def_msmodel(py::module_&);
void def_mslocate(py::module_&);
void def_msstate(py::module_&);
void def_msview(py::module_&);
void def_mshistory(py::module_&);
void def_userfnc(py::module_&);
void def_auxsystm_r(py::module_&);
void def_viewgroup(py::module_&);
void def_filtertable(py::module_&);
void def_dgnlib(py::module_&);
void def_changetrack(py::module_&);
void def_global(py::module_&);
void def_dlogitem(py::module_&);
void def_BaseWindow(py::module_&);
void def_MSWindow(py::module_&);

void def_ImageLibAPI(py::module_&);
void def_msplot(py::module_&);
void def_MstnDefs(py::module_& m);

void def_GuiView(py::module_& m);

void def_GeospatialContextAPI(py::module_& m);
void def_GeospatialContextImportServicesAPI(py::module_& m);
void def_GeospatialContextExportServicesAPI(py::module_& m);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyMstnPlatform, m)
    {
    // Document for module
    m.doc() = "The MSPyMstnPlatform library, provides functionality which interacts with the execution of the MicroStation product itself, i.e interaction with the command queue, the active file being manipulated in the current session";

    // class defines
    bind_container_PyMstn(m);
    def_dlogbox_r(m);
    def_DocumentManager(m);
    def_ElementPropertyUtils(m);
    //def_IEditAction(m);
    def_IEvent(m);
    def_IGlobalPosition(m);
    def_IPopupMenuManager(m);
    def_ISessionMgr(m);
    //def_IXCommand(m);
    def_MicroStationApiErrors_r(m);
    //def_XCommand(m);
    //def_XCommandManager(m);
    def_MessageCenter(m);
    def_MicroStation_r(m);
    def_MstnTypes(m);

    def_MeshAPI(m);
    def_Constraint2dCoreAPI(m);
    def_Constraint2dManager(m);
    def_Constraint3dCoreAPI(m);
    def_Constraint3dElementApi(m);
    def_PSolidCoreAPI(m);
    def_SmartFeature_r(m);
    def_SmartFeatureAPI(m);

    def_leveltable(m);
    def_msacs(m);
    def_msassoc(m);
    def_msbitmask(m);
    def_mscell(m);
    def_msdgnmodelref(m);
    def_msdgnobj(m);
    def_msinput(m);
    def_mscommandstate(m);
    def_msdialog(m);
    def_msexpression(m);
    def_msstring(m);
    def_mssystem(m);
    def_msmodel(m);
    def_mslocate(m);
    def_msstate(m);
    def_msview(m);
    def_mshistory(m);
    def_userfnc(m);
    def_auxsystm_r(m);
    def_viewgroup(m);
    def_filtertable(m);
    def_dgnlib(m);
    def_mselmdsc(m);
    def_changetrack(m);
    def_global(m);
    def_dlogitem(m);
    def_BaseWindow(m);
    def_MSWindow(m);
        
    def_ImageLibAPI(m);
    def_msplot(m);
    def_MstnDefs(m);

    def_GuiView(m);

    def_GeospatialContextAPI(m);
    def_GeospatialContextImportServicesAPI(m);
    def_GeospatialContextExportServicesAPI(m);
    }


