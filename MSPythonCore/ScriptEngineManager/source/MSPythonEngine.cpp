/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\PythonCore\ScriptEngineManager\source\PythonEngine.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include "..\\MsPythonCore.r.h"
#include <iostream>
// Default entry point function for script
#define DEFAULT_FUNC_NAME       L"PyMain"

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PythonScriptValue::PythonScriptValue(const py::object& obj) : m_obj(obj)
    {
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PythonScriptValue::~PythonScriptValue()
    {
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
template<typename _OutType>
__inline bool PythonScriptValue__asWrapper(py::object& obj, _OutType& outVal)
    {
    bool bOk = false;

    try
        {
        outVal = obj.cast<_OutType>();
        bOk = true;
        }
    catch (py::cast_error&)
        {
        }

    return bOk;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asInt8(char& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asInt16(short& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asInt32(int& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asInt64(long long& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asUInt8(unsigned char& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asUInt16(unsigned short& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asUInt32(unsigned int& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asUInt64(unsigned long long& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asFloat(float& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asDouble(double& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asBool(bool& outVal)
    {
    return PythonScriptValue__asWrapper(m_obj, outVal);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asWString(WStringR outVal)
    {
    bool bOk = false;

    try
        {
        std::wstring strOutVal = m_obj.cast<std::wstring>();
        if (!strOutVal.empty())
            outVal.assign(strOutVal.c_str());

        bOk = true;
        }
    catch (py::cast_error&)
        {
        }

    return bOk;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptValue::asString(Utf8StringR outVal)
    {
    bool bOk = false;

    try
        {
        std::string strOutVal = m_obj.cast<std::string>();
        if (!strOutVal.empty())
            outVal.assign(strOutVal.c_str());

        bOk = true;
        }
    catch (py::cast_error&)
        {
        }

    return bOk;
    }


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PythonScriptContext::PythonScriptContext(bool global)
    {
    if (global)
        {
        m_dict = py::dict();
        for (auto item : py::globals())
            m_dict[item.first] = item.second;
        }
    else
        m_dict = py::dict();
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
template<typename _InType, typename _WrapperType>
__inline void PythonScriptContext__setWrapper(py::dict& dict, WCharCP key, _InType value)
    {
    if (key && *key)
        {
        try
            {
            dict[py::cast(key)] = _WrapperType(value);
            }
        catch (py::error_already_set&)
            {
            }
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, char value)
    {
    PythonScriptContext__setWrapper<char, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, short value)
    {
    PythonScriptContext__setWrapper<short, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, int value)
    {
    PythonScriptContext__setWrapper<int, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, long long value)
    {
    PythonScriptContext__setWrapper<long long, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, unsigned char value)
    {
    PythonScriptContext__setWrapper<unsigned char, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, unsigned short value)
    {
    PythonScriptContext__setWrapper<unsigned short, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, unsigned int value)
    {
    unsigned short temp = static_cast<unsigned short> (value);
    PythonScriptContext__setWrapper<unsigned short, py::int_>(m_dict, key, temp);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, unsigned long long value)
    {
    PythonScriptContext__setWrapper<unsigned long long, py::int_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, float value)
    {
    PythonScriptContext__setWrapper<float, py::float_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, double value)
    {
    PythonScriptContext__setWrapper<double, py::float_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, bool value)
    {
    PythonScriptContext__setWrapper<bool, py::bool_>(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, Utf8CP value)
    {
    if (key && *key && value && *value)
        {
        try
            {
            m_dict[py::cast(key)] = py::str(value);
            }
        catch (py::error_already_set&)
            {
            }
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptContext::set(WCharCP key, WCharCP value)
    {
    if (key && *key && value && *value)
        {
        try
            {
            Utf8String strVal;
            strVal.Assign(value);
            m_dict[py::cast(key)] = py::str(strVal.c_str());
            }
        catch (py::error_already_set&)
            {
            }
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
template<typename _OutType>
__inline bool PythonScriptContext__getAs(py::dict& dict, WCharCP key, _OutType& value)
    {
    bool bOk = false;
    if (key && *key && dict.contains(key))
        {
        try
            {
            value = dict[py::cast(key)].cast<_OutType>();
            bOk = true;
            }
        catch (py::cast_error&)
            {
            }
        }

    return bOk;
    }

/*---------------------------------------------------------------------------------**//*** 
@bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, char& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//***
@bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, short& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//***
@bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, int& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, long long& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, unsigned char& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, unsigned short& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, unsigned int& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, unsigned long long& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, float& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, double& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, bool& value)
    {
    return PythonScriptContext__getAs(m_dict, key, value);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, Utf8StringR value)
    {
    bool bOk = false;
    if (key && *key && m_dict.contains(key))
        {
        try
            {
            std::string strValue = m_dict[py::cast(key)].cast<std::string>();
            if (!strValue.empty())
                value.assign(strValue.c_str());

            bOk = true;
            }
        catch (py::cast_error&)
            {
            }
        }

    return bOk;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
bool PythonScriptContext::getAs(WCharCP key, WStringR value)
    {
    bool bOk = false;
    if (key && *key && m_dict.contains(key))
        {
        try
            {
            std::string strValue = m_dict[py::cast(key)].cast<std::string>();
            if (!strValue.empty())
                value.AssignUtf8(strValue.c_str());

            bOk = true;
            }
        catch (py::cast_error&)
            {
            }
        }

    return bOk;
    }


/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
PythonScriptEngine* PythonScriptEngine::m_sEngine = nullptr;

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
PythonScriptEngine::PythonScriptEngine() : m_engineProcessing(false)
    {
    py::initialize_interpreter();
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void PythonScriptEngine::shutdown()
    {
    if (nullptr != m_sEngine)
        {
        delete m_sEngine;
        m_sEngine = nullptr;
        }
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
PythonScriptEngine::~PythonScriptEngine()
    {
    py::finalize_interpreter();
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void PythonScriptEngine::setDontWriteByteCode(bool bEnable)
    {
    py::module_::import("sys").attr("dont_write_bytecode") = bEnable;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
bool PythonScriptEngine::getDontWriteByteCode()
    {
    return py::module_::import("sys").attr("dont_write_bytecode").cast<bool>();
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void PythonScriptEngine::install()
    {
    if (nullptr == m_sEngine)
        {
        m_sEngine = new PythonScriptEngine();        
        ScriptEngineManager::Get().RegisterScriptEngine(*m_sEngine);

        // Disable Python engine to write bytecode to make sure we can always reload file-based module.
        m_sEngine->setDontWriteByteCode(true);
        /*  pybind embedded modules hook dllmain and so are loaded when a dll is loaded. The code below is to pull out the embedded module
            into a non python (.pyd) dll such that it can be loaded separately. as each .pyd used to link to MSPythonCore.dll causing problems with pytest.
            Now the embedded module is only required when running MSPy... .pyd files inside of Microstation */
        static HMODULE     s_dllHandle = GetModuleHandle("UstnPython.dll");
        typedef void    *(*PFuncVoidPtr)(bool);

        PFuncVoidPtr funcPtr = (PFuncVoidPtr) GetProcAddress (s_dllHandle, "mspython_createConsole");
        if (funcPtr)
            {
            // Load embedded module to register types contained.
            auto m = py::module_::import("PyInternals");

            // Redirect sys.stdout & sys.stderr to PyRedirector
            auto stdout_Redirector = reinterpret_cast <MSPyConsole*> (funcPtr (false));
            py::module_::import("sys").attr("stdout") = py::cast(stdout_Redirector, py::return_value_policy::take_ownership);

            auto stderr_Redirector = reinterpret_cast <MSPyConsole*> (funcPtr (true));
            py::module_::import("sys").attr("stderr") = py::cast(stderr_Redirector, py::return_value_policy::take_ownership);
            }

        // initialize python import search path
        //
        m_sEngine->InitSearchPath();
        }
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/
void PythonScriptEngine::uninstall()
    {
    if (nullptr != m_sEngine)
        ScriptEngineManager::Get().UnregisterScriptEngine(*m_sEngine);
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
bool PythonScriptEngine::AddSearchPaths(bvector<WString> const& paths)
    {
    py::list pathList = py::module_::import("sys").attr("path");
    if (!pathList || paths.empty())
        return false;

    for (auto& path : paths)
        {
#if 0 // Allow path currently does not exist.
        if (!BeFileName::DoesPathExist(path.c_str()))
            continue;
#endif

        py::str item = py::cast(path.c_str());
        if (!pathList.contains(item))
            pathList.append(item);
        }

    return true;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
bool PythonScriptEngine::AddSearchPath(WStringCR path)
    {
    py::list pathList = py::module_::import("sys").attr("path");
    if (!pathList || path.empty())
        return false;

#if 0 // Allow path current does not exist.
    if (!BeFileName::DoesPathExist(path.c_str()))
        return false;
#endif

    py::str item = py::cast(path.c_str());
    if (!pathList.contains(item))
        pathList.append(item);

    return true;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       6/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
bool PythonScriptEngine::AddCmdLineArgs(bvector<WString>& args)
    {
    py::list argvList = py::module_::import("sys").attr("argv");
    if (!argvList)
        return false;
    if (!argvList.empty())
        argvList.attr("clear")(); // remove last used arguments

    for (auto& it : args)
        {
        py::str item = py::cast(it.c_str());
        argvList.append(item);
        }
    return true;
    }


/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
bool PythonScriptEngine::GetSearchPaths(bvector<WString>& paths)
    {
    py::list pathList = py::module_::import("sys").attr("path");
    if (!pathList || pathList.empty())
        return false;

    for (auto& it : pathList)
        {
        std::string u8Val = it.cast<std::string>();
        WString outVal;
        outVal.AssignUtf8(u8Val.c_str());
        paths.push_back(outVal);
        }

    return true;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
ScriptContextPtr PythonScriptEngine::createContext(bool global)
    {
    return new PythonScriptContext(global);
    }


/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void print_dict(const py::dict& dict) 
    {
    /* Easily interact with Python types */
    for (auto item : dict)
        std::cout << "key=" << std::string(py::str(item.first)) << ", "
                  << "value=" << std::string(py::str(item.second)) << std::endl;
    std::cout << std::endl;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
ScriptValuePtr PythonScriptEngine::eval(WCharCP expr, ScriptContext* global, ScriptContext* locals)
    {
    ScriptValue* outVal = nullptr;
    ScriptContextPtr globalCtx(global), localCtx(locals);
    py::dict globalDict, localDict;

    if (!expr || !*expr)
        return outVal;

    if (m_engineProcessing)
        {
        ScriptEngineManager::Get().InjectError("Cannot have two instances of Python executing at the same time");
        return outVal;
        }
    // Create context when necessary
    if (globalCtx.IsNull())
        globalCtx = createContext(true);
    if (localCtx.IsNull())
        localCtx = createContext(false);

    // Obtain py::dict from context that is specific for PyEngine
    auto pyGlobalDict = dynamic_cast<PythonScriptContext*>(globalCtx.get());
    if (nullptr != pyGlobalDict)
        globalDict = pyGlobalDict->m_dict;

    auto pyLocalDict = dynamic_cast<PythonScriptContext*>(localCtx.get());
    if (nullptr != pyLocalDict)
        localDict = pyLocalDict->m_dict;
    m_engineProcessing = true;
    // Evaluate expression and capture return value.
    ScriptEngineManager::Get().ClearException();
    try
        {
        py::object obj = py::eval(py::cast(expr), globalDict, py::len(localDict) > 0 ? localDict : py::object ());
        outVal = new PythonScriptValue(obj);
        }
    catch (py::error_already_set& err)
        {
        ScriptEngineManager::Get().InjectException(err);
        }

    m_engineProcessing = false;    

    return outVal;
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void PythonScriptEngine::exec(WCharCP stms, WCharCP funcName, ScriptContext* global, ScriptContext* locals)
    {
    ScriptContextPtr globalCtx(global), localCtx(locals);
    py::dict globalDict, localDict;

    if (!stms || !*stms)
        return;

    if (m_engineProcessing)
        {
        ScriptEngineManager::Get().InjectError("Cannot have two instances of Python executing at the same time");
        return;
        }

    // Create context when necessary
    if (globalCtx.IsNull())
        globalCtx = createContext(true);
    if (localCtx.IsNull())
        localCtx = createContext(false);

    // Obtain py::dict from contexts that is specific for PyEngine
    auto pyGlobalDict = dynamic_cast<PythonScriptContext*>(globalCtx.get());
    if (nullptr != pyGlobalDict)
        globalDict = pyGlobalDict->m_dict;

    auto pyLocalDict = dynamic_cast<PythonScriptContext*>(localCtx.get());
    if (nullptr != pyLocalDict)
        localDict = pyLocalDict->m_dict;

    // Execute statements
    ScriptEngineManager::Get().ClearException();
    m_engineProcessing = true;
    try
        {
        py::exec(py::cast(stms), globalDict, py::len(localDict) > 0 ? localDict : py::object ());
        }
    catch (py::error_already_set& err)
        {
        ScriptEngineManager::Get().InjectException(err);
        }
    m_engineProcessing = false;

    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                                                       2/2023 
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void PythonScriptEngine::eval_file(WCharCP scriptFile, WCharCP funcName, ScriptContext* global, ScriptContext* locals)
    {    
    WString strFileOrModule(scriptFile);

    ScriptEngineManager::Get().ClearException();

    if (m_engineProcessing)
        {
        ScriptEngineManager::Get().InjectError("Cannot have two instances of Python executing at the same time");
        return;
        }

    ScriptContextPtr    globalCtx (global), localCtx(locals);
    py::dict            globalDict, localDict;

    if (globalCtx.IsNull())
        globalCtx = createContext(true);
    if (localCtx.IsNull())
        localCtx = createContext(false);

    // Obtain py::dict object from contexts that is specific to PyEngine
    auto pyGlobalDict = dynamic_cast<PythonScriptContext*>(globalCtx.get());
    if (nullptr != pyGlobalDict)
        globalDict = pyGlobalDict->m_dict;

    auto pyLocalDict = dynamic_cast<PythonScriptContext*>(localCtx.get());
    if (nullptr != pyLocalDict)
        localDict = pyLocalDict->m_dict;

    m_engineProcessing = true;
    // User want to run a file directly
    if (strFileOrModule.EndsWithI(L".py"))
        {
        // Run file
        try
            {
            // Python returns errors if the local dictionary is empty
            py::eval_file(py::cast(scriptFile), globalDict, py::len(localDict) > 0 ? localDict : py::object ());
            }
        catch (py::error_already_set& e)
            {
            ScriptEngineManager::Get().InjectError( e.what ());
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        }
    else // User want to run a function inside given module
        {
        try
            {            
            Utf8String u8Name;
            u8Name.Assign(scriptFile);

            // Try to import module
            auto userModule = py::module_::import(u8Name.c_str());

            // Try to reload it in case of has been imported and has been changed outside
            userModule.reload();

            // Prepare function name or use default name
            if (!funcName || !*funcName)
                funcName = DEFAULT_FUNC_NAME;
            
            WString function(funcName);

            function.append (L" ()");

            py::exec(py::cast(function.c_str ()) ,globalDict, localDict);

            }        
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }        
        }
    m_engineProcessing = false;

    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                  
 +---------------+---------------+---------------+---------------+---------------+------*/ 
void PythonScriptEngine::InitSearchPath ()
    {
    BeFileName rootPath(Py_GetProgramFullPath());
    BeAssert(BeFileName::DoesPathExist(rootPath));

    size_t index = rootPath.find_last_of(L"\\");
    BeAssert(WString::npos != index);

    rootPath.SetName(rootPath.substr(0, index).GetWCharCP());
    AddSearchPath(rootPath);

    BeFileName pyPath;
    if (SUCCESS == ConfigurationManager::GetVariable(pyPath, L"MS_PYTHON") && BeFileName::DoesPathExist(pyPath))
        AddSearchPath(pyPath);
    else
        {
        WString  msg;
        mdlResource_loadWString(msg, NULL, STRINGLISTID_MsPythonCorePrompts, PROMPT_FailToFindPythonInterpreter);
        mdlOutput_message(msg.c_str());
        return;
        }

    if (SUCCESS == ConfigurationManager::GetVariable(pyPath, L"MS_PYTHONSEARCHDIRECTORIES") && !WString::IsNullOrEmpty(pyPath))
        {
        bvector<WString> childPaths;
        BeStringUtilities::Split(pyPath.c_str(), L";", NULL, childPaths);
        for (WString childPath : childPaths)
            {
            if (BeFileName::DoesPathExist(childPath.c_str()))
                AddSearchPath(childPath);
            }
        }
    }

/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                   Paul Chater                   03/23
 +---------------+---------------+---------------+---------------+---------------+------*/ 
 HMODULE DgnPlatformFixture_FindUstationDLL (char* envVar, char *subDirPath)
    {
    char envBuf[MAX_PATH], buf[MAX_PATH], currDir[MAX_PATH]={0};

    if (0 != GetEnvironmentVariable (envVar, envBuf, MAX_PATH))
        {
        if (subDirPath)
            strcat_s (envBuf, MAX_PATH, subDirPath);

        if (0 != SearchPath (envBuf, "ustation.dll", nullptr, MAX_PATH, buf, nullptr))
            {
            GetCurrentDirectory (MAX_PATH, currDir);
            SetCurrentDirectory (envBuf);       // set the current directory temporarily so all the dependent dlls can be found
            HMODULE dllHandle = LoadLibrary (buf);
            SetCurrentDirectory (currDir);
            return dllHandle;
            }
        }
    return 0;
    }
/*---------------------------------------------------------------------------------**//*** 
 @bsimethod                                   Paul Chater                   03/23
 +---------------+---------------+---------------+---------------+---------------+------*/ 
 void DgnPlatformFixture_Initialize ()
    {
    static HMODULE     s_dllHandle = 0;
    // load ustation.dll and execute the init code necessary for running dgnplatform tests
    if (!s_dllHandle)
        {
        // SDK sets MS env var to location of product install
        s_dllHandle = DgnPlatformFixture_FindUstationDLL (const_cast <char*>("MS"), nullptr);

        // Bentley output tree
        if (!s_dllHandle)
            s_dllHandle = DgnPlatformFixture_FindUstationDLL (const_cast <char*>("OutRoot"), const_cast <char*>("Winx64\\Product\\Mstn\\MicroStation"));
        }

    if (0 == s_dllHandle)
        {BeAssert (false); return;}

    PFuncVoid funcPtr = (PFuncVoid) GetProcAddress (s_dllHandle, "pytest_initializeTestHost");
    if (NULL != funcPtr)
        (*funcPtr) ();
    }

 /*---------------------------------------------------------------------------------**//***
  @bsimethod                                   Chris Wu                   09/23
  +---------------+---------------+---------------+---------------+---------------+------*/
 bvector<PyNameSpaceManager::NameSpaceID> PyNameSpaceManager::m_namespaceIDArray;

 StatusInt PyNameSpaceManager::UsingNameSpace(PyNameSpaceID namespaceID)
    {
    if (std::find(m_namespaceIDArray.begin(), m_namespaceIDArray.end(), namespaceID) != m_namespaceIDArray.end())
        return SUCCESS;

    m_namespaceIDArray.push_back(namespaceID);
    return SUCCESS;
    }

/*---------------------------------------------------------------------------------**//***
   @bsimethod                                   Chris Wu                   09/23
+---------------+---------------+---------------+---------------+---------------+------*/
 bool PyNameSpaceManager::IsNameSpaceUsing(PyNameSpaceID namespaceID)
    {
     if (std::find(m_namespaceIDArray.begin(), m_namespaceIDArray.end(), namespaceID) != m_namespaceIDArray.end())
         return true;

     return false;
    }

/*---------------------------------------------------------------------------------**//***
   @bsimethod                                   Chris Wu                   09/23
+---------------+---------------+---------------+---------------+---------------+------*/
 StatusInt PyNameSpaceManager::DelNameSpaceUsing(PyNameSpaceID namespaceID)
    {
     bvector<PyNameSpaceID>::iterator iter = std::find(m_namespaceIDArray.begin(), m_namespaceIDArray.end(), namespaceID);
     if (iter != m_namespaceIDArray.end())
         m_namespaceIDArray.erase (iter);

     return SUCCESS;
    }

/*---------------------------------------------------------------------------------**//***
   @bsimethod                                   Chris Wu                   09/23
+---------------+---------------+---------------+---------------+---------------+------*/
 void PyNameSpaceManager::ClearNameSpaceUsing()
    {
     m_namespaceIDArray.clear();
    }

/*---------------------------------------------------------------------------------**//***
   @bsimethod                                   Chris Wu                   09/23
+---------------+---------------+---------------+---------------+---------------+------*/
 void PyNameSpaceManager::SetDefaultNameSpaceList()
    {
    //To do
    m_namespaceIDArray.clear();
    UsingNameSpace(PyNameSpaceManager::Bentley_DgnPlatform_Raster);
    }

/*---------------------------------------------------------------------------------**//***
    @bsimethod                                   Chris Wu                   05/24
+---------------+---------------+---------------+---------------+---------------+------*/
PythonScopeMap* ScopeMapManager::m_scopeMap = nullptr;

PythonScopeMap& ScopeMapManager::GetScopeMapInstance()
    {
    if (nullptr == m_scopeMap)
        m_scopeMap = new PythonScopeMap();

    return *m_scopeMap;
    }

/*---------------------------------------------------------------------------------**//**
    @bsimethod                                   Chris Wu                   05/24
+---------------+---------------+---------------+---------------+---------------+------*/
void ScopeMapManager::ReleaseScopeMapInstance()
    {
    if (nullptr == m_scopeMap)
        return;

    for (PythonScopeMap::iterator iter = m_scopeMap->begin(); iter != m_scopeMap->end();)
        {
        MdlDescP desc = nullptr;
        if (nullptr != (desc = mdlSystem_findMdlDesc(iter->first.c_str())))
            mdlSystem_unloadMdlProgram(iter->first.c_str());

        iter = m_scopeMap->erase(iter);
        }

    m_scopeMap->clear();
    delete m_scopeMap;
    m_scopeMap = nullptr;
    }


