/*--------------------------------------------------------------------------------------+
//
//  $Source: \MSPython\MSPythonWrapper\PyDgnPlatform\testUtilities\pyViewContextTest.cpp $
//
//  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved.
//
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ViewContext.h>
#include <DgnPlatform/NullContext.h>
#include <Geom/transform.h>

//=======================================================================================
// pyViewContextTest
//=======================================================================================
struct pyViewContextTest : NullContext
{
    DEFINE_T_SUPER(NullContext)

public:
    NullOutput m_output;

    pyViewContextTest() : NullContext(nullptr, false) { SetIViewDraw(m_output); }
    pyViewContextTest(IViewDrawP viewDraw, bool setupScan) : NullContext(viewDraw, setupScan) {}

    virtual void _SetupOutputs() override { SetIViewDraw(m_output); }

    void SetTransformClip(TransformCR transform)
    {
        m_transformClipStack.PushTransform(transform);
    }

    const TransformClipStack& GetTransformClip(){
        return m_transformClipStack;
    }
};

//=======================================================================================
// Trampoline class for pyViewContextTest to enable Python overrides
//=======================================================================================
struct PyViewContextTestTrampoline : pyViewContextTest
{
    using pyViewContextTest::pyViewContextTest;

    void _SetupOutputs() override
    {
        PYBIND11_OVERRIDE(
            void,                  // Return type
            pyViewContextTest,     // Parent class
            _SetupOutputs          // Name of function in C++
        );
    }
};

//=======================================================================================
// Python binding definition
//=======================================================================================
void def_ViewContextTest(py::module_& m)
{
    py::class_<pyViewContextTest, ViewContext, PyViewContextTestTrampoline, std::unique_ptr<pyViewContextTest, py::nodelete>>(m, "pyViewContextTest")
        .def(py::init<>())
        .def(py::init<IViewDrawP, bool>())
        .def("SetTransformClip", &pyViewContextTest::SetTransformClip)
        .def("SetupOutputs", &pyViewContextTest::_SetupOutputs)
        .def("getTransformClip", &pyViewContextTest::GetTransformClip, py::return_value_policy::reference_internal);
}
