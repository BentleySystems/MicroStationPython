/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\PythonCore\ScriptEngineManager\source\ScriptEngineManager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptObject::ScriptObject()
    : m_scriptType(new WString())
    , m_content(new WString())
    {
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptObject::ScriptObject(WCharCP scriptType, WCharCP content)
    : m_scriptType(new WString())
    , m_content(new WString())
    {
    if (scriptType && *scriptType)
        m_scriptType->assign(scriptType);

    if (content && *content)
        m_content->assign(content);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptObject::~ScriptObject()
    {
    delete m_scriptType;
    m_scriptType = nullptr;

    delete m_content;
    m_content = nullptr;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
WCharCP ScriptObject::scriptType() const
    {
    if (m_scriptType->empty())
        return L"";

    return m_scriptType->c_str();
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptObject::setScriptType(WCharCP scriptType)
    {
    if (scriptType && *scriptType)
        m_scriptType->assign(scriptType);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
WCharCP ScriptObject::content() const
    {
    if (m_content->empty())
        return L"";

    return m_content->c_str();
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptObject::setContent(WCharCP content)
    {
    if (content && *content)
        m_content->assign(content);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptValuePtr ScriptObject::eval(ScriptContext* global, ScriptContext* locals) const
    {
    ScriptValuePtr retVal;

    if (!m_scriptType->empty() && !m_content->empty())
        {
        auto engine = ScriptEngineManager::Get().GetScriptEngineP(m_scriptType->c_str());
        if (nullptr != engine)
            retVal = engine->eval(m_content->c_str(), global, locals);
        }

    return retVal;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptObject::exec(WCharCP funcName, ScriptContext* global, ScriptContext* locals) const
    {
    if (!m_scriptType->empty() && !m_content->empty())
        {
        auto engine = ScriptEngineManager::Get().GetScriptEngineP(m_scriptType->c_str());
        if (nullptr != engine)
            engine->exec(m_content->c_str(), funcName, global, locals);
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptEngineManager* ScriptEngineManager::s_EngineManager = nullptr;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptEngineManager::ScriptEngineManager()
    : m_engineList(new bmap<WString, ScriptEngine*>())
    , m_sinkList(new bvector<ScriptNotifierP>())
    , m_lastException(new std::exception())
    , m_hasException(false)
    {    
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptEngineManager::~ScriptEngineManager()
    {
    UnregisterAll();

    if (nullptr != m_engineList)
        {
        delete m_engineList;
        m_engineList = nullptr;
        }

    if (nullptr != m_sinkList)
        {
        if (!m_sinkList->empty())
            {
            for (auto& it : *m_sinkList)
                {
                if (nullptr != it)
                    it->Release();
                }
            }

        delete m_sinkList;
        m_sinkList = nullptr;
        }

    if (nullptr != m_lastException)
        {
        delete m_lastException;
        m_lastException = nullptr;
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptEngineManager& ScriptEngineManager::Get()
    {
    if (nullptr == s_EngineManager)
        s_EngineManager = new ScriptEngineManager();

    return *s_EngineManager;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::RegisterAll()
    {
    // Load Plugins
    PythonScriptEngine::install();
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::Shutdown()
    {
    if (nullptr != s_EngineManager)
        {
        delete s_EngineManager;
        s_EngineManager = nullptr;
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
int ScriptEngineManager::GetAllEngines(bvector<WString>& engines)
    {
    int nItem = 0;
    if (nullptr != m_engineList && !m_engineList->empty())
        {
        for (auto it = m_engineList->begin(); it != m_engineList->end(); ++it, ++nItem)
            engines.push_back(it->first);
        }
    return nItem;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool ScriptEngineManager::RegisterScriptEngine(ScriptEngine& engine)
    {
    auto it = m_engineList->find(engine.scriptType());
    if (it != m_engineList->end())
        return false;

    (*m_engineList)[engine.scriptType()] = &engine;

    return true;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::UnregisterScriptEngine(ScriptEngine& engine)
    {
    if (m_engineList->empty())
        return;

    auto it = m_engineList->find(engine.scriptType());
    if (it != m_engineList->end())
        {
        it->second->shutdown();
        m_engineList->erase(it);
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::UnregisterAll()
    {
    if (nullptr != m_engineList && !m_engineList->empty())
        {
        for (auto it : *m_engineList)
            it.second->shutdown();

        m_engineList->clear();
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptContextPtr ScriptEngineManager::CreateScriptContext(WCharCP scriptType, bool global)
    {
    auto engine = GetScriptEngineP(scriptType);
    if (nullptr != engine)
        return engine->createContext(global);

    return nullptr;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptEngine& ScriptEngineManager::GetScriptEngine(WCharCP scriptType)
    {
    return *GetScriptEngineP(scriptType);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
ScriptEngine* ScriptEngineManager::GetScriptEngineP(WCharCP scriptType)
    {
    ScriptEngine* retVal = nullptr;
    if (scriptType && *scriptType && !m_engineList->empty())
        {
        auto it = m_engineList->find(scriptType);
        if (it != m_engineList->end())
            retVal = it->second;
        }

    return retVal;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool ScriptEngineManager::AddNotifier(ScriptNotifierP notifier)
    {
    if (nullptr == notifier)
        return false;

    auto it = std::find(m_sinkList->begin(), m_sinkList->end(), notifier);
    if (it != m_sinkList->end())
        return true;

    UstnScriptNotifier* beConsole = dynamic_cast<UstnScriptNotifier*> (notifier);
    bool isBeConsole = (nullptr != beConsole) ? true : false;

    if (isBeConsole)
        {
        notifier->SetActive(true);
        }
    else
        {
        for (auto& it0 : *m_sinkList)
             {
             beConsole = dynamic_cast<UstnScriptNotifier*> (it0);
             if (nullptr == beConsole)
                it0->SetActive(false);
             }

        notifier->SetActive(true);
        }

    notifier->AddRef();
    m_sinkList->push_back(notifier);

    return true;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::DropNotifier(ScriptNotifierP notifier)
    {
    if (nullptr == notifier)
        return;

    auto it = std::find(m_sinkList->begin(), m_sinkList->end(), notifier);
    if (it == m_sinkList->end())
        return;

    UstnScriptNotifier* beConsole = dynamic_cast<UstnScriptNotifier*> (notifier);
    bool isBeConsole = (nullptr != beConsole) ? true : false;
    bool isActive = (*it)->GetActive();

    notifier->Release();
    m_sinkList->erase(it);

    if (!isBeConsole && isActive)
        {
        for (ScriptNotifierP &it0 : *m_sinkList)
            {
            beConsole = dynamic_cast<UstnScriptNotifier*> (it0);
            if (nullptr != beConsole)
                {
                it0->SetActive(true);
                break;
                }
            }
        }
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::InjectException(std::exception& ex)
    {
    *m_lastException = ex;
    m_hasException = true;
    for (auto& it : *m_sinkList)
        if (it->GetActive())
            it->OnException(ex);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::InjectError(std::string const& msg)
    {
    for (auto& it : *m_sinkList)
        if (it->GetActive())
            it->OnError(msg);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::InjectOutput(std::string const& msg)
    {
    for (auto& it : *m_sinkList)
        if (it->GetActive())
            it->OnOutput(msg);
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
std::exception const& ScriptEngineManager::GetLastException()
    {
    return *m_lastException;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
bool ScriptEngineManager::HasException()
    {
    return m_hasException;
    }

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void ScriptEngineManager::ClearException()
    {
    *m_lastException = std::exception();
    m_hasException = false;
    }

