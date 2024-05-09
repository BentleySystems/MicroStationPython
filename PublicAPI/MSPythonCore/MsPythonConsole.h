/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\PublicAPI\ScriptEngineManager.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
//__BENTLEY_INTERNAL_ONLY__
#pragma once

#include <MsPythonCore\MSPython.h>

#pragma managed(push, off)
#include <pybind11/pybind11.h>
#pragma managed(pop)

struct MSPYTHONDLL_EXPORT MSPyConsole
    {
    private:
        bool m_dumpAsError;

    public:
        MSPyConsole(bool dumpError);

        void write(const char* szMsg);
        void flush();
        pybind11::str read();
        bool isatty();
        void close();
    };

extern "C" MSPYTHONDLL_EXPORT  void DgnPlatformFixture_Initialize();

