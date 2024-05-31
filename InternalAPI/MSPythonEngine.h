/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\PythonEngine.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
//__BENTLEY_INTERNAL_ONLY__

#pragma once

BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct PythonScriptValue : public ScriptValue
    {
 private:
     py::object m_obj;

 public:
     PythonScriptValue(const py::object&);

     virtual ~PythonScriptValue();

     virtual bool asInt8(char& outVal);
     virtual bool asInt16(short& outVal);
     virtual bool asInt32(int& outVal);
     virtual bool asInt64(long long& outVal);

     virtual bool asUInt8(unsigned char& outVal);
     virtual bool asUInt16(unsigned short& outVal);
     virtual bool asUInt32(unsigned int& outVal);
     virtual bool asUInt64(unsigned long long& outVal);

     virtual bool asFloat(float& outVal);
     virtual bool asDouble(double& outVal);
     virtual bool asBool(bool& outVal);

     virtual bool asString(Utf8StringR outVal);
     virtual bool asWString(WStringR outVal);
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct PythonScriptContext : public ScriptContext
    {
    friend struct PythonScriptEngine;

protected:
    py::dict m_dict;

public:
    PythonScriptContext(bool global);

    virtual void set(WCharCP key, char value);
    virtual void set(WCharCP key, short value);
    virtual void set(WCharCP key, int value);
    virtual void set(WCharCP key, long long value);

    virtual void set(WCharCP key, unsigned char value);
    virtual void set(WCharCP key, unsigned short value);
    virtual void set(WCharCP key, unsigned int value);
    virtual void set(WCharCP key, unsigned long long value);

    virtual void set(WCharCP key, float value);
    virtual void set(WCharCP key, double value);
    virtual void set(WCharCP key, bool value);

    virtual void set(WCharCP key, Utf8CP value);
    virtual void set(WCharCP key, WCharCP value);

    virtual bool getAs(WCharCP key, char& outVal);
    virtual bool getAs(WCharCP key, short& outVal);
    virtual bool getAs(WCharCP key, int& outVal);
    virtual bool getAs(WCharCP key, long long& outVal);

    virtual bool getAs(WCharCP key, unsigned char& outVal);
    virtual bool getAs(WCharCP key, unsigned short& outVal);
    virtual bool getAs(WCharCP key, unsigned int& outVal);
    virtual bool getAs(WCharCP key, unsigned long long& outVal);

    virtual bool getAs(WCharCP key, float& outVal);
    virtual bool getAs(WCharCP key, double& outVal);
    virtual bool getAs(WCharCP key, bool& outVal);

    virtual bool getAs(WCharCP key, Utf8StringR outVal);
    virtual bool getAs(WCharCP key, WStringR outVal);

public:
    virtual ~PythonScriptContext() {}
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct PythonScriptEngine : public ScriptEngine
    {
private:
    static PythonScriptEngine* m_sEngine;
    WCharCP s_ScriptType = L"Python";
    WCharCP s_Verson = L"1.0";
    WCharCP s_Extension = L".py";
    bool    m_engineProcessing;

    PythonScriptEngine();

protected:
    virtual void shutdown();

public:
    ~PythonScriptEngine();

    static void                 install();
    static void                 uninstall();
    void                        setDontWriteByteCode(bool bEnable);
    bool                        getDontWriteByteCode();
    bool                        IsPythonEngineProcessing () {return m_engineProcessing;}
    void                        SetPythonEngineProcessing (bool processing) {m_engineProcessing = processing;}
    
    virtual WCharCP             scriptType() const { return s_ScriptType; }
    virtual WCharCP             version() const { return s_Verson; }
    virtual WCharCP             fileExtension() const { return s_Extension; }
    virtual bool                AddSearchPaths(bvector<WString> const& paths);
    virtual bool                AddSearchPath(WStringCR path);
    virtual bool                GetSearchPaths(bvector<WString>& paths);
    virtual bool                AddCmdLineArgs(bvector<WString>& args);
    virtual ScriptContextPtr    createContext(bool global);
    virtual ScriptValuePtr      eval(WCharCP expr, ScriptContext* global = nullptr, ScriptContext* locals = nullptr);
    virtual void                exec(WCharCP stms, WCharCP funcName, ScriptContext* global = nullptr, ScriptContext* locals = nullptr);
    virtual void                eval_file(WCharCP fileName, WCharCP funcName, ScriptContext* global = nullptr, ScriptContext* locals = nullptr);

private:
    void                        InitSearchPath();
    };


//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct PythonScopeHolder
    {
    ScriptContextPtr m_global;
    ScriptContextPtr m_local;
    };

typedef bmap<WString, PythonScopeHolder>  PythonScopeMap;

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct ScopeMapManager
{
private:
    static PythonScopeMap *m_scopeMap;

public:

    MSPYTHONDLL_EXPORT static PythonScopeMap& GetScopeMapInstance();
    MSPYTHONDLL_EXPORT static void ReleaseScopeMapInstance();
};

END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
