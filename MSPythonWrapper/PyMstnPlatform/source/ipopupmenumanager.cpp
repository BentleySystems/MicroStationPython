/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ipopupmenumanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/IPopupMenuManager.h>



static const char * __doc_Bentley_MstnPlatform_IPopupMenuManager_DropTentativePopUpMenuProvider =R"doc(Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IPopupMenuManager_AddTentativePopUpMenuProvider =R"doc(Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IPopupMenuManager_DropViewPopUpMenuProvider =R"doc(Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IPopupMenuManager_AddViewPopUpMenuProvider =R"doc(Remark:
    Required Library:mdlbltin.lib)doc";

static const char * __doc_Bentley_MstnPlatform_IPopupMenuManager_GetManager =R"doc(Remark:
    Required Library:mdlbltin.lib)doc";

//=======================================================================================
// Trampoline class for IPopupMenuProvider
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyPopupMenuProvider : IPopupMenuProvider
	{
	public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
		virtual void _PopulateMenu(DPoint3dCP  point, int view, HitPathCP path, bvector<DgnPlatform::IEditActionPtr>& editActions) override
			{ PYBIND11_OVERRIDE_PURE_EX(void, IPopupMenuProvider, _PopulateMenu, point, view, path, editActions); }
	};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPopupMenuManager(py::module_& m)
    {
	//===================================================================================
	// struct IPopupMenuProvider
	py::class_< IPopupMenuProvider, std::unique_ptr<IPopupMenuProvider, py::nodelete>, IPyPopupMenuProvider> c1(m, "IPopupMenuProvider");

	c1.def(py::init<>());
	c1.def("_PopulateMenu", &IPopupMenuProvider::_PopulateMenu, "point"_a, "view"_a, "path"_a, "editActions"_a);

	//===================================================================================
	// struct IPopupMenuManager
	py::class_< IPopupMenuManager, std::unique_ptr<IPopupMenuManager, py::nodelete> > c2(m, "IPopupMenuManager");

	c2.def_property_readonly_static("Manager", [] (py::object const&) { return std::unique_ptr< IPopupMenuManager, py::nodelete>(&IPopupMenuManager::GetManager()); });
	c2.def_static("GetManager", [] () { return std::unique_ptr< IPopupMenuManager, py::nodelete>(&IPopupMenuManager::GetManager()); }, DOC(Bentley, MstnPlatform, IPopupMenuManager, GetManager));

	c2.def("AddViewPopUpMenuProvider", &IPopupMenuManager::AddViewPopUpMenuProvider, "provider"_a, py::keep_alive<1, 2>(), DOC(Bentley, MstnPlatform, IPopupMenuManager, AddViewPopUpMenuProvider));
	c2.def("DropViewPopUpMenuProvider", &IPopupMenuManager::DropViewPopUpMenuProvider, "provider"_a, DOC(Bentley, MstnPlatform, IPopupMenuManager, DropViewPopUpMenuProvider));
	c2.def("AddTentativePopUpMenuProvider", &IPopupMenuManager::AddTentativePopUpMenuProvider, "provider"_a, py::keep_alive<1, 2>(), DOC(Bentley, MstnPlatform, IPopupMenuManager, AddTentativePopUpMenuProvider));
	c2.def("DropTentativePopUpMenuProvider", &IPopupMenuManager::DropTentativePopUpMenuProvider, "provider"_a, DOC(Bentley, MstnPlatform, IPopupMenuManager, DropTentativePopUpMenuProvider));
    }