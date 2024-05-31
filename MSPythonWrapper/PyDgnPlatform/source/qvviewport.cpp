/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\qvviewport.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/QvViewport.h>



//=======================================================================================
// Publicist class for QvViewport.
// @bsiclass                                                                   02/23
//=======================================================================================
struct QvViewportPub : QvViewport
    {
    };

//=======================================================================================
// Trampoline class for QvViewport.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyQvViewport : QvViewport
    {
        using QvViewport::QvViewport;

    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_QvViewport(py::module_& m)
    {
    //===================================================================================
    // struct QvViewport
    py::class_< QvViewport, PyQvViewport, Viewport> c1(m, "QvViewport");

    }