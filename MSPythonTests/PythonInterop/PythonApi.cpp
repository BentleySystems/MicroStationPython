#include "Python.h"
#include "PythonApi.h"

PyObject* mdlInput_sendKeyIn_PythonImpl (PyObject*, PyObject* o)
    {
    const wchar_t* keyin = NULL;
    int bLiteral = 0;
    int  position = 0;
    const wchar_t* taskId = NULL;
    if (!PyArg_ParseTuple(o, "uiiu", &keyin, &bLiteral, &position, &taskId))
        return NULL;

    mdlInput_sendKeyin (keyin, bLiteral == 0 ? false : true, (MSInputQueuePos)position, taskId);

    PyObject* ret = NULL;
    Py_INCREF(Py_None);
    ret = Py_None;
    return ret;
    }


static PyMethodDef PythonModule_methods[] = {
    // The first property is the name exposed to Python
    // The second is the C++ function with the implementation
    // METH_VARARGS means it takes a tuple PyObject argument

    { "SendKeyIn", (PyCFunction)mdlInput_sendKeyIn_PythonImpl, METH_VARARGS, nullptr},

    // Terminate the array with an object containing nulls.
    { nullptr, nullptr, 0, nullptr }
    };

static PyModuleDef PythonInterop_module = {
    PyModuleDef_HEAD_INIT,
    "PythonInterop",           // Module name to use with Python import statements
    "Python warp for C++",     // Module description
    0,
    PythonModule_methods                   // Structure that defines the methods of the module
    };

PyMODINIT_FUNC PyInit_PythonInterop() 
    {
    PyObject* module = PyModule_Create(&PythonInterop_module);
    return module;
    }