/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iviewtransients.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IViewTransients.h>



//=======================================================================================
// Publicist class for IViewTransients.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IViewTransientsPub : IViewTransients
    {
    public:
        using IViewTransients::_DrawTransients;
    };

//=======================================================================================
// Trampoline class for IViewTransients.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyViewTransients : IViewTransients
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DrawTransients(ViewContextR context, bool isPreUpdate) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IViewTransients, _DrawTransients, context, isPreUpdate); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IViewTransients(py::module_& m)
    {
    //===================================================================================
    // struct IViewTransients
    py::class_< IViewTransients, std::unique_ptr< IViewTransients, py::nodelete>, IPyViewTransients> c1(m, "IViewTransients");

    c1.def(py::init<>());
    c1.def("_DrawTransients", &IViewTransientsPub::_DrawTransients, "context"_a, "isPreUpdate"_a);
    c1.def("ComputeRange", &IViewTransients::ComputeRange, "range"_a, "vp"_a);
    }