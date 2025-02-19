/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MstnTypes.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MstnTypes.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MstnTypes(py::module_& m)
{
    py::class_<Asynch_update_view> c1(m, "Asynch_update_view");
    c1.def(py::init<>());
    c1.def_readwrite("active", &Asynch_update_view::active);
    c1.def_readwrite("viewnum", &Asynch_update_view::viewnum);
    c1.def_readwrite("window", &Asynch_update_view::window);
    c1.def_readwrite("phys_screen", &Asynch_update_view::phys_screen);
    c1.def_readwrite("screen_origin", &Asynch_update_view::screen_origin);
    c1.def_readwrite("screen_corner", &Asynch_update_view::screen_corner);
    c1.def_readwrite("update_origin", &Asynch_update_view::update_origin);
    c1.def_readwrite("update_corner", &Asynch_update_view::update_corner);
    c1.def_readwrite("vieworg", &Asynch_update_view::vieworg);
    c1.def_readwrite("viewdelta", &Asynch_update_view::viewdelta);
    c1.def_property_readonly("rotmatrix",
        [](Asynch_update_view const& self)
        {
            py::list rotmatrixArray;
            for (size_t i = 0; i < std::size(self.rotmatrix); i++)
                rotmatrixArray.append(py::cast(self.rotmatrix[i]));
            return rotmatrixArray;
        });
    c1.def_readwrite("levelClassMask", &Asynch_update_view::levelClassMask);
    c1.def_readwrite("viewFlags", &Asynch_update_view::viewFlags);
    c1.def_readwrite("incremental", &Asynch_update_view::incremental);
    c1.def_property_readonly("gw",
        [](Asynch_update_view const& self)
        {
            return self.gwP;
        });

    py::class_<GuiWAttributes> c2(m, "GuiWAttributes");
    c2.def(py::init<>());
    c2.def_property("modal",
        [](GuiWAttributes const& self) { return self.modal; },
        [](GuiWAttributes& self, UInt32 value) { self.modal = value; });

    c2.def_property("moveable",
        [](GuiWAttributes const& self) { return self.moveable; },
        [](GuiWAttributes& self, UInt32 value) { self.moveable = value; });

    c2.def_property("closeable",
        [](GuiWAttributes const& self) { return self.closeable; },
        [](GuiWAttributes& self, UInt32 value) { self.closeable = value; });

    c2.def_property("sizeable",
        [](GuiWAttributes const& self) { return self.sizeable; },
        [](GuiWAttributes& self, UInt32 value) { self.sizeable = value; });

    c2.def_property("closeOnNew",
        [](GuiWAttributes const& self) { return self.closeOnNew; },
        [](GuiWAttributes& self, UInt32 value) { self.closeOnNew = value; });

    c2.def_property("sinkable",
        [](GuiWAttributes const& self) { return self.sinkable; },
        [](GuiWAttributes& self, UInt32 value) { self.sinkable = value; });

    c2.def_property("nonVideo",
        [](GuiWAttributes const& self) { return self.nonVideo; },
        [](GuiWAttributes& self, UInt32 value) { self.nonVideo = value; });

    c2.def_property("requestBackingStore",
        [](GuiWAttributes const& self) { return self.requestBackingStore; },
        [](GuiWAttributes& self, UInt32 value) { self.requestBackingStore = value; });

    c2.def_property("popup",
        [](GuiWAttributes const& self) { return self.popup; },
        [](GuiWAttributes& self, UInt32 value) { self.popup = value; });

    c2.def_property("alwaysSaveUnder",
        [](GuiWAttributes const& self) { return self.alwaysSaveUnder; },
        [](GuiWAttributes& self, UInt32 value) { self.alwaysSaveUnder = value; });

    c2.def_property("userAllocated",
        [](GuiWAttributes const& self) { return self.userAllocated; },
        [](GuiWAttributes& self, UInt32 value) { self.userAllocated = value; });

    c2.def_property("noWindowControlIcon",
        [](GuiWAttributes const& self) { return self.noWindowControlIcon; },
        [](GuiWAttributes& self, UInt32 value) { self.noWindowControlIcon = value; });

    c2.def_property("isFocusable",
        [](GuiWAttributes const& self) { return self.isFocusable; },
        [](GuiWAttributes& self, UInt32 value) { self.isFocusable = value; });

    c2.def_property("refusesAutoSwitch",
        [](GuiWAttributes const& self) { return self.refusesAutoSwitch; },
        [](GuiWAttributes& self, UInt32 value) { self.refusesAutoSwitch = value; });

    c2.def_property("noRightIcons",
        [](GuiWAttributes const& self) { return self.noRightIcons; },
        [](GuiWAttributes& self, UInt32 value) { self.noRightIcons = value; });

    c2.def_property("noTitleBar",
        [](GuiWAttributes const& self) { return self.noTitleBar; },
        [](GuiWAttributes& self, UInt32 value) { self.noTitleBar = value; });

    c2.def_property("dockable",
        [](GuiWAttributes const& self) { return self.dockable; },
        [](GuiWAttributes& self, UInt32 value) { self.dockable = value; });

    c2.def_property("titleBarDocked",
        [](GuiWAttributes const& self) { return self.titleBarDocked; },
        [](GuiWAttributes& self, UInt32 value) { self.titleBarDocked = value; });

    c2.def_property("dockedByDefault",
        [](GuiWAttributes const& self) { return self.dockedByDefault; },
        [](GuiWAttributes& self, UInt32 value) { self.dockedByDefault = value; });

    c2.def_property("forwardMnemonics",
        [](GuiWAttributes const& self) { return self.forwardMnemonics; },
        [](GuiWAttributes& self, UInt32 value) { self.forwardMnemonics = value; });

    c2.def_property("thinBorders",
        [](GuiWAttributes const& self) { return self.thinBorders; },
        [](GuiWAttributes& self, UInt32 value) { self.thinBorders = value; });

    c2.def_property("maximizable",
        [](GuiWAttributes const& self) { return self.maximizable; },
        [](GuiWAttributes& self, UInt32 value) { self.maximizable = value; });

    c2.def_property("noFullDrag",
        [](GuiWAttributes const& self) { return self.noFullDrag; },
        [](GuiWAttributes& self, UInt32 value) { self.noFullDrag = value; });

    c2.def_property("requestAlternateRaster",
        [](GuiWAttributes const& self) { return self.requestAlternateRaster; },
        [](GuiWAttributes& self, UInt32 value) { self.requestAlternateRaster = value; });

    c2.def_property("outputOnly",
        [](GuiWAttributes const& self) { return self.outputOnly; },
        [](GuiWAttributes& self, UInt32 value) { self.outputOnly = value; });

    c2.def_property("mustStayVisible",
        [](GuiWAttributes const& self) { return self.mustStayVisible; },
        [](GuiWAttributes& self, UInt32 value) { self.mustStayVisible = value; });

    c2.def_property("resizesInward",
        [](GuiWAttributes const& self) { return self.resizesInward; },
        [](GuiWAttributes& self, UInt32 value) { self.resizesInward = value; });

    c2.def_property("motionToItems",
        [](GuiWAttributes const& self) { return self.motionToItems; },
        [](GuiWAttributes& self, UInt32 value) { self.motionToItems = value; });

    c2.def_property("noAutoSelectIcons",
        [](GuiWAttributes const& self) { return self.noAutoSelectIcons; },
        [](GuiWAttributes& self, UInt32 value) { self.noAutoSelectIcons = value; });

    c2.def_property("noBorders",
        [](GuiWAttributes const& self) { return self.noBorders; },
        [](GuiWAttributes& self, UInt32 value) { self.noBorders = value; });

    c2.def_property("noChangeScreen",
        [](GuiWAttributes const& self) { return self.noChangeScreen; },
        [](GuiWAttributes& self, UInt32 value) { self.noChangeScreen = value; });

    c2.def_property("noItemAdjustments",
        [](GuiWAttributes const& self) { return self.noItemAdjustments; },
        [](GuiWAttributes& self, UInt32 value) { self.noItemAdjustments = value; });

    c2.def_property("sizeGrip",
        [](GuiWAttributes const& self) { return self.sizeGrip; },
        [](GuiWAttributes& self, UInt32 value) { self.sizeGrip = value; });

    c2.def_property("noIconCmdSynch",
        [](GuiWAttributes const& self) { return self.noIconCmdSynch; },
        [](GuiWAttributes& self, UInt32 value) { self.noIconCmdSynch = value; });

    c2.def_property("isChild",
        [](GuiWAttributes const& self) { return self.isChild; },
        [](GuiWAttributes& self, UInt32 value) { self.isChild = value; });

    c2.def_property("isViewport",
        [](GuiWAttributes const& self) { return self.isViewport; },
        [](GuiWAttributes& self, UInt32 value) { self.isViewport = value; });

    c2.def_property("netDockable",
        [](GuiWAttributes const& self) { return self.netDockable; },
        [](GuiWAttributes& self, UInt32 value) { self.netDockable = value; });

    c2.def_property("minimizable",
        [](GuiWAttributes const& self) { return self.minimizable; },
        [](GuiWAttributes& self, UInt32 value) { self.minimizable = value; });

    c2.def_property("noTransparency",
        [](GuiWAttributes const& self) { return self.noTransparency; },
        [](GuiWAttributes& self, UInt32 value) { self.noTransparency = value; });

    c2.def_property("focusableNoCheck",
        [](GuiWAttributes const& self) { return self.focusableNoCheck; },
        [](GuiWAttributes& self, UInt32 value) { self.focusableNoCheck = value; });

    c2.def_property("docked",
        [](GuiWAttributes const& self) { return self.docked; },
        [](GuiWAttributes& self, UInt32 value) { self.docked = value; });

    c2.def_property("trackingHelp",
        [](GuiWAttributes const& self) { return self.trackingHelp; },
        [](GuiWAttributes& self, UInt32 value) { self.trackingHelp = value; });

    c2.def_property("alwaysBorderedItems",
        [](GuiWAttributes const& self) { return self.alwaysBorderedItems; },
        [](GuiWAttributes& self, UInt32 value) { self.alwaysBorderedItems = value; });

    c2.def_property("transparentBorderless",
        [](GuiWAttributes const& self) { return self.transparentBorderless; },
        [](GuiWAttributes& self, UInt32 value) { self.transparentBorderless = value; });

    c2.def_property("useAlphaBlend",
        [](GuiWAttributes const& self) { return self.useAlphaBlend; },
        [](GuiWAttributes& self, UInt32 value) { self.useAlphaBlend = value; });

    c2.def_property("doubleBuffer",
        [](GuiWAttributes const& self) { return self.doubleBuffer; },
        [](GuiWAttributes& self, UInt32 value) { self.doubleBuffer = value; });

    c2.def_property("autoUpdateTextItems",
        [](GuiWAttributes const& self) { return self.autoUpdateTextItems; },
        [](GuiWAttributes& self, UInt32 value) { self.autoUpdateTextItems = value; });

    c2.def_property("descartesRequired",
        [](GuiWAttributes const& self) { return self.descartesRequired; },
        [](GuiWAttributes& self, UInt32 value) { self.descartesRequired = value; });

    c2.def_property("unused",
        [](GuiWAttributes const& self) { return self.unused; },
        [](GuiWAttributes& self, UInt32 value) { self.unused = value; });
}
