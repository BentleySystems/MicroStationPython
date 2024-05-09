/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\befilelistiterator.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/BeFileListIterator.h>



static const char * __doc_Bentley_BeFileListIterator_GetNextFileName = R"doc(Retrieve the next filename found from the path list.

Parameter ``name``:
    The name of the next valid file from the path list.

Returns:
    SUCCESS if the name returned is valid, ERROR if there are no more
    files.)doc";



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BeFileListIterator(py::module_& m)
    {
    //===================================================================================
    // class BeFileListIterator
    py::class_< BeFileListIterator> c1(m, "BeFileListIterator");

    c1.def(py::init<WCharCP, bool>(), "filePathList"_a, "recursive"_a);
    c1.def("GetNextFileName", &BeFileListIterator::GetNextFileName, "fileName"_a, DOC(Bentley, BeFileListIterator, GetNextFileName));
    }