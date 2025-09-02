/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\PublicAPI\ScriptEngineManager.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
//__BENTLEY_INTERNAL_ONLY__
#pragma once

#include <Bentley/Bentley.h>
#include <Bentley/RefCounted.h>
#include <Bentley/bvector.h>
#include <Bentley/bmap.h>
#include <Bentley/BeConsole.h>
#include <Bentley/stdcxx/rw/bpair.h>
#include <utility>
#include <tuple>

#include <MsPythonCore\MSPython.h>


BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

DEFINE_POINTER_SUFFIX_TYPEDEFS(ScriptValue)
DEFINE_POINTER_SUFFIX_TYPEDEFS(ScriptContext)
DEFINE_POINTER_SUFFIX_TYPEDEFS(ScriptEngine)
DEFINE_POINTER_SUFFIX_TYPEDEFS(ScriptNotifier)
DEFINE_POINTER_SUFFIX_TYPEDEFS(ScriptObject)
DEFINE_POINTER_SUFFIX_TYPEDEFS(ScriptEngineManager)

DEFINE_REF_COUNTED_POINTER(ScriptValue)
DEFINE_REF_COUNTED_POINTER(ScriptContext)
DEFINE_REF_COUNTED_POINTER(ScriptNotifier)

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct ScriptValue : public RefCountedBase
    {
public:
    virtual bool asInt8(char& outVal) = 0;
    virtual bool asInt16(short& outVal) = 0;
    virtual bool asInt32(int& outVal) = 0;
    virtual bool asInt64(long long& outVal) = 0;

    virtual bool asUInt8(unsigned char& outVal) = 0;
    virtual bool asUInt16(unsigned short& outVal) = 0;
    virtual bool asUInt32(unsigned int& outVal) = 0;
    virtual bool asUInt64(unsigned long long& outVal) = 0;

    virtual bool asFloat(float& outVal) = 0;
    virtual bool asDouble(double& outVal) = 0;
    virtual bool asBool(bool& outVal) = 0;

    virtual bool asString(Utf8StringR outVal) = 0;
    virtual bool asWString(WStringR outVal) = 0;

public:
    virtual ~ScriptValue() {}
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct ScriptContext : public RefCountedBase
    {
public:
    virtual void set(WCharCP key, char value) = 0;
    virtual void set(WCharCP key, short value) = 0;
    virtual void set(WCharCP key, int value) = 0;
    virtual void set(WCharCP key, long long value) = 0;
    virtual void set(WCharCP key, unsigned char value) = 0;
    virtual void set(WCharCP key, unsigned short value) = 0;
    virtual void set(WCharCP key, unsigned int value) = 0;
    virtual void set(WCharCP key, unsigned long long value) = 0;
    virtual void set(WCharCP key, float value) = 0;
    virtual void set(WCharCP key, double value) = 0;
    virtual void set(WCharCP key, bool value) = 0;                
    virtual void set(WCharCP key, Utf8CP value) = 0;
    virtual void set(WCharCP key, WCharCP value) = 0;

    virtual bool getAs(WCharCP key, char& value) = 0;
    virtual bool getAs(WCharCP key, short& value) = 0;
    virtual bool getAs(WCharCP key, int& value) = 0;
    virtual bool getAs(WCharCP key, long long& value) = 0;
    virtual bool getAs(WCharCP key, unsigned char& value) = 0;
    virtual bool getAs(WCharCP key, unsigned short& value) = 0;
    virtual bool getAs(WCharCP key, unsigned int& value) = 0;
    virtual bool getAs(WCharCP key, unsigned long long& value) = 0;
    virtual bool getAs(WCharCP key, float& value) = 0;
    virtual bool getAs(WCharCP key, double& value) = 0;
    virtual bool getAs(WCharCP key, bool& value) = 0;
    virtual bool getAs(WCharCP key, Utf8StringR value) = 0;
    virtual bool getAs(WCharCP key, WStringR value) = 0;

public:
    virtual ~ScriptContext() {}
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct ScriptEngine
    {
    friend struct ScriptEngineManager;

 protected:
     virtual void                shutdown() = 0;

 public:
     virtual WCharCP             scriptType() const = 0;
     virtual WCharCP             version() const = 0;
     virtual WCharCP             fileExtension() const = 0;
     virtual bool                AddSearchPaths(bvector<WString> const& paths) = 0;
     virtual bool                AddSearchPath(WStringCR path) = 0;
     virtual bool                GetSearchPaths(bvector<WString>& paths) = 0;
     virtual bool                AddCmdLineArgs(bvector<WString>& args) = 0;
     virtual ScriptContextPtr    createContext(bool global) = 0;
     virtual ScriptValuePtr      eval(WCharCP expr, ScriptContext* global = nullptr, ScriptContext* locals = nullptr) = 0;
     virtual void                exec(WCharCP stms, WCharCP funcName, ScriptContext* global = nullptr, ScriptContext* locals = nullptr) = 0;
     virtual void                eval_file(WCharCP fileName, WCharCP funcName, ScriptContext* global = nullptr, ScriptContext* locals = nullptr) = 0;                
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct MSPYTHONDLL_EXPORT ScriptObject
    {
 private:
     WString* m_scriptType;
     WString* m_content;

 public:
     ScriptObject();
     ScriptObject(WCharCP scriptType, WCharCP content);
    ~ScriptObject();

     WCharCP scriptType() const;
     void setScriptType(WCharCP scriptType);

     WCharCP content() const;
     void setContent(WCharCP content);

     ScriptValuePtr eval(ScriptContext* global = nullptr, ScriptContext* locals = nullptr) const;

     void exec(WCharCP funcName, ScriptContext* global = nullptr, ScriptContext* locals = nullptr) const;
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct ScriptNotifier : public RefCountedBase
    {
protected:
    bool m_active = false;

 public:
     virtual void OnException(std::exception& ex) {}

     virtual void OnError(std::string const& msg) {}

     virtual void OnOutput(std::string const& msg) {}

     void SetActive (bool active) { m_active = active;}
     bool GetActive () { return m_active; }
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
struct MSPYTHONDLL_EXPORT ScriptEngineManager
    {
 private:
     static ScriptEngineManager* s_EngineManager;
     bmap<WString, ScriptEngine*> *m_engineList;
     bvector<ScriptNotifierP> *m_sinkList;
     std::exception *m_lastException;
     bool m_hasException;

     ScriptEngineManager();
    ~ScriptEngineManager();

 public:

     static ScriptEngineManager& Get();
     static void RegisterAll();
     static void Shutdown();
     int GetAllEngines(bvector<WString>& engines);

     bool RegisterScriptEngine(ScriptEngine& engine);
     void UnregisterScriptEngine(ScriptEngine& engine);
     void UnregisterAll();                

     ScriptEngine& GetScriptEngine(WCharCP scriptType);
     ScriptEngine* GetScriptEngineP(WCharCP scriptType);
     ScriptContextPtr CreateScriptContext(WCharCP scriptType, bool global);

     bool AddNotifier(ScriptNotifierP notifier);
     void DropNotifier(ScriptNotifierP notifier);

     void InjectException(std::exception& ex);
     void InjectError(std::string const& msg);
     void InjectOutput(std::string const& msg);

     std::exception const& GetLastException();
     bool HasException();
     void ClearException();
    };

//=======================================================================================
// @bsiclass                                                                   02/23
//=======================================================================================
typedef RefCountedPtr<struct UstnScriptNotifier> UstnScriptNotifierPtr;
struct UstnScriptNotifier : public ScriptNotifier
{
private:
    UstnScriptNotifier() {}
public:
    virtual void OnException(std::exception& ex) override { BeConsole::Printf("%s\n", ex.what()); }

    virtual void OnError(std::string const& msg) override { BeConsole::Printf("%s\n", msg.c_str()); }

    virtual void OnOutput(std::string const& msg) override { BeConsole::Printf("%s\n", msg.c_str()); }

    static UstnScriptNotifierPtr Create() { return new UstnScriptNotifier(); }
};

END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE


