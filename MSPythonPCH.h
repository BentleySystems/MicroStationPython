/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonPCH.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#define BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE     namespace Bentley { namespace MstnPlatform { namespace MSPython {
#define END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE       } } }
#define USING_NAMESPACE_BENTLEY_MSTNPLATFORM_MSPYTHON     using namespace Bentley::MstnPlatform::MSPython;

#define NOMINMAX

#include <windows.h>

// Avoid windows name mangling.
#undef GetClassName
#undef FindText
#undef ReplaceText
#undef GetCurrentTime

#include <memory>
#include <wtypes.h>
#include <ObjIdl.h>

#include <boost/optional/optional.hpp>

#undef ERROR
#undef true
#undef false

#include <Bentley/Bentley.h>
#include <Bentley/bvector.h>
#include <Bentley/WString.h>
#include <Bentley/BeFileName.h>
#include <Bentley/bmap.h>
#include <Bentley/RefCounted.h>
#include <Geom/GeomApi.h>
#include <Geom/msgeomstructs_typedefs.h>
#include <DgnPlatform/DgnPlatformAPI.h>
#include <Mstn/MstnPlatformAPI.h>
#include <ECObjects/ECObjectsAPI.h>

#include <Pybind11/pybind11.h>
#include <Pybind11/embed.h>
#include <Pybind11/cast.h>
#include <Pybind11/operators.h>
#include <Pybind11/stl_bind.h>
#include <Pybind11/stl.h>

USING_NAMESPACE_BENTLEY
USING_NAMESPACE_BENTLEY_MSTNPLATFORM
USING_NAMESPACE_BENTLEY_MSTNPLATFORM_ELEMENT
USING_NAMESPACE_BENTLEY_DGNPLATFORM
USING_NAMESPACE_BENTLEY_ECOBJECT

namespace py = pybind11;
using namespace py::literals;

#include <MSPython.h>
#include <ScriptEngineManager.h>
#include <MsPythonConsole.h>
#include <MSPythonEngine.h>

#include <MSPyBindTemplates.h>
#include <MSPyCommon.h>
#include <OpqueTypes_Bentley.h>
#include <OpqueTypes_Geom.h>
#include <OpqueTypes_DgnPlatform.h>
#include <OpqueTypes_ECObject.h>

USING_NAMESPACE_BENTLEY_MSTNPLATFORM_MSPYTHON
