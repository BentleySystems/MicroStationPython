/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\mshistory.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/mshistory.fdf>
#include "CallbackHelper.h"


class FmtRevisionNumberCallbackHelper {
public:
    typedef std::function<StatusInt(WString*, WCharCP, int, DgnFileP)> FmtRevisionNumberFunctionType;

#define DEFINE_FN_POINTER_FMT_REVISION_NUMBER_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](WCharP buf, WCharCP num, int maxbuf, DgnFileP file) -> StatusInt \
        { \
            try \
            { \
                if(nullptr != buf && maxbuf > 1) \
                { \
                    WString bufString; \
                    StatusInt returnVal = m_callbackFuncs[index](&bufString, num, maxbuf, file); \
                    wcscpy_s(buf, maxbuf, bufString.GetWCharCP()); \
                    return returnVal; \
                } \
                else \
                { \
                    return m_callbackFuncs[index](nullptr, num, maxbuf, file); \
                } \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static HistoryFunc_FmtRevisionNumber* SetCallback(FmtRevisionNumberFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_FMT_REVISION_NUMBER_CALLBACK);
    }

private:
    static FmtRevisionNumberFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static HistoryFunc_FmtRevisionNumber* m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename FmtRevisionNumberCallbackHelper::FmtRevisionNumberFunctionType FmtRevisionNumberCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
HistoryFunc_FmtRevisionNumber* FmtRevisionNumberCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string FmtRevisionNumberCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class CompareElementsCallbackHelper {
public:
    typedef std::function<StatusInt(IntWrapper*, DgnFileP, DgnPlatform::ModelId, MSElementDescrCP, MSElementDescrCP, WCharCP, WCharCP, WCharCP)> CompareElementsFunctionType;

#define DEFINE_FN_POINTER_COMPARE_ELEMENTS_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](int* affinity, DgnFileP file, DgnPlatform::ModelId model, MSElementDescrCP preChange, MSElementDescrCP postChange, WCharCP title, WCharCP preChangeDescription, WCharCP postChangeDescription) -> StatusInt \
        { \
            try \
            { \
                if (nullptr == affinity) \
                { \
                    return m_callbackFuncs[index](nullptr, file, model, preChange, postChange, title, preChangeDescription, postChangeDescription); \
                } \
                else \
                { \
                    return m_callbackFuncs[index]((IntWrapper*)affinity, file, model, preChange, postChange, title, preChangeDescription, postChangeDescription); \
                } \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static HistoryFunc_CompareElements* SetCallback(CompareElementsFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_COMPARE_ELEMENTS_CALLBACK);
    }

private:
    static CompareElementsFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static HistoryFunc_CompareElements* m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename CompareElementsCallbackHelper::CompareElementsFunctionType CompareElementsCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
HistoryFunc_CompareElements* CompareElementsCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string CompareElementsCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class DisplayElementCallbackHelper {
public:
    typedef std::function<StatusInt(IntWrapper*, DgnFileP, DgnPlatform::ModelId, MSElementDescrCP, WCharCP, WCharCP)> DisplayElementFunctionType;

#define DEFINE_FN_POINTER_DISPLAY_ELEMENT_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](int* affinity, DgnFileP file, DgnPlatform::ModelId model, MSElementDescrCP element, WCharCP descriptionString, WCharCP changeTypeString) -> StatusInt \
        { \
            try \
            { \
                if (nullptr == affinity) \
                { \
                    return m_callbackFuncs[index](nullptr, file, model, element, descriptionString, changeTypeString); \
                } \
                else \
                { \
                    return m_callbackFuncs[index]((IntWrapper*)affinity, file, model, element, descriptionString, changeTypeString); \
                } \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static HistoryFunc_DisplayElement* SetCallback(DisplayElementFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_DISPLAY_ELEMENT_CALLBACK);
    }

private:
    static DisplayElementFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static HistoryFunc_DisplayElement* m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename DisplayElementCallbackHelper::DisplayElementFunctionType DisplayElementCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
HistoryFunc_DisplayElement* DisplayElementCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string DisplayElementCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class DescribeElementCallbackHelper {
public:
    typedef std::function<StatusInt(IntWrapper*, WString*, WString*, DgnFileP, DgnPlatform::ModelId, MSElementDescrCP, int, int)> DescribeElementFunctionType;

#define DEFINE_FN_POINTER_DESCRIBE_ELEMENT_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](int* affinity, WCharP type, WCharP name, DgnFileP file, DgnPlatform::ModelId model, MSElementDescrCP element, int maxtype, int maxname) -> StatusInt \
        { \
            try \
            { \
                WString typeString(type); \
                WString nameString(name); \
                StatusInt returnVal; \
                if (nullptr == affinity) \
                { \
                    returnVal = m_callbackFuncs[index](nullptr, &typeString, &nameString, file, model, element, maxtype, maxname); \
                } \
                else \
                { \
                    returnVal = m_callbackFuncs[index]((IntWrapper*)affinity, &typeString, &nameString, file, model, element, maxtype, maxname); \
                } \
                if(maxtype > 1) \
                { \
                    wcscpy_s(type, maxtype, typeString.GetWCharCP()); \
                } \
                if(maxname > 1) \
                { \
                    wcscpy_s(name, maxname, nameString.GetWCharCP()); \
                } \
                return returnVal; \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static HistoryFunc_DescribeElement* SetCallback(DescribeElementFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_DESCRIBE_ELEMENT_CALLBACK);
    }

private:
    static DescribeElementFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static HistoryFunc_DescribeElement* m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename DescribeElementCallbackHelper::DescribeElementFunctionType DescribeElementCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
HistoryFunc_DescribeElement* DescribeElementCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string DescribeElementCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class RestorePreCallbackHelper {
public:
    typedef std::function<StatusInt(DgnFileP, WCharCP)> RestorePreFunctionType;

#define DEFINE_FN_POINTER_RESTORE_PRE_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](DgnFileP file, WCharCP targetRev, BentleyDgnHistoryModelsToElementChangesMapCP elements) -> StatusInt \
        { \
            try \
            { \
                return m_callbackFuncs[index](file, targetRev); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static HistoryFunc_RestorePre* SetCallback(RestorePreFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_RESTORE_PRE_CALLBACK);
    }

private:
    static RestorePreFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static HistoryFunc_RestorePre* m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename RestorePreCallbackHelper::RestorePreFunctionType RestorePreCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
HistoryFunc_RestorePre* RestorePreCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string RestorePreCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class RestorePostCallbackHelper {
public:
    typedef std::function<void(DgnFileP, WCharCP)> RestorePostFunctionType;

#define DEFINE_FN_POINTER_RESTORE_POST_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](DgnFileP file, WCharCP targetRev, BentleyDgnHistoryModelsToElementChangesMapCP elements) \
        { \
            try \
            { \
                return m_callbackFuncs[index](file, targetRev); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static HistoryFunc_RestorePost* SetCallback(RestorePostFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_RESTORE_POST_CALLBACK);
    }

private:
    static RestorePostFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static HistoryFunc_RestorePost* m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename RestorePostCallbackHelper::RestorePostFunctionType RestorePostCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
HistoryFunc_RestorePost* RestorePostCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string RestorePostCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                     10/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_mshistory(py::module_& m)
{
    py::class_<HistoryCommitParms> c1(m, "HistoryCommitParms");
    c1.def_property_readonly("time",
        [](HistoryCommitParms const& self) {return &self.time; });
    c1.def_property_readonly("user",
        [](HistoryCommitParms const& self) {return self.pUser; });
    c1.def_property_readonly("desc",
        [](HistoryCommitParms const& self) {return self.pDesc; });
    c1.def_property_readonly("revisionNumber",
        [](HistoryCommitParms const& self) {return self.pRevisionNumber; });

    py::class_<HistoryRevisionInfo> c2(m, "HistoryRevisionInfo");
    c2.def_property_readonly("user",
        [](HistoryRevisionInfo const& self) {return self.user; });
    c2.def_property_readonly("desc",
        [](HistoryRevisionInfo const& self) {return self.desc; });
    c2.def_property_readonly("time",
        [](HistoryRevisionInfo const& self) {return &self.time; });
    c2.def_property_readonly("num",
        [](HistoryRevisionInfo const& self) {return self.num; });
    c2.def_property_readonly("next",
        [](HistoryRevisionInfo const& self) {return self.next; });
    c2.def_property_readonly("futureUse_Model",
        [](HistoryRevisionInfo const& self) {return self.futureUse_Model; });
    c2.def_property_readonly("isEmpty",
        [](HistoryRevisionInfo const& self) {return self.isEmpty; });
    c2.def_property_readonly("future6",
        [](HistoryRevisionInfo const& self) {return self.future6; });
    c2.def_property_readonly("future1",
        [](HistoryRevisionInfo const& self) {return self.future1; });
    c2.def_property_readonly("future2",
        [](HistoryRevisionInfo const& self) {return self.future2; });
    c2.def_property_readonly("future3",
        [](HistoryRevisionInfo const& self) {return self.future3; });
    c2.def_property_readonly("future4",
        [](HistoryRevisionInfo const& self) {return self.future4; });
    c2.def_property_readonly("future5",
        [](HistoryRevisionInfo const& self) {return self.future5; });

    py::class_<HistoryCallback> c100(m, "HistoryCallback");
    c100.def_static("AddCommitPreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CommitPre>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(HistoryCallback::AddCommitPreFunction, DgnFileP, const HistoryCommitParms*, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCommitPreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CommitPre>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(HistoryCallback::RemoveCommitPreFunction, DgnFileP, const HistoryCommitParms*, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddCommitPostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CommitPost>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(HistoryCallback::AddCommitPostFunction, HistoryRevisionInfo const*, DgnFileP, BentleyDgnHistoryRevisionInfoCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCommitPostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CommitPost>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(HistoryCallback::RemoveCommitPostFunction, HistoryRevisionInfo const*, DgnFileP, BentleyDgnHistoryRevisionInfoCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddCreatePreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CreatePre>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(HistoryCallback::AddCreatePreFunction, DgnFileP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCreatePreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CreatePre>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(HistoryCallback::RemoveCreatePreFunction, DgnFileP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddCreatePostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CreatePost>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(HistoryCallback::AddCreatePostFunction, DgnFileP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCreatePostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CreatePost>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(HistoryCallback::RemoveCreatePostFunction, DgnFileP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddDeletePreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeletePre>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(HistoryCallback::AddDeletePreFunction, DgnFileP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveDeletePreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeletePre>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(HistoryCallback::RemoveDeletePreFunction, DgnFileP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddDeletePostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeletePost>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(HistoryCallback::AddDeletePostFunction, DgnFileP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveDeletePostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeletePost>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(HistoryCallback::RemoveDeletePostFunction, DgnFileP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddCombinePreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CombinePre>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(HistoryCallback::AddCombinePreFunction, DgnFileP, WCharCP, WCharCP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCombinePreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CombinePre>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(HistoryCallback::RemoveCombinePreFunction, DgnFileP, WCharCP, WCharCP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddCombinePostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CombinePost>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(HistoryCallback::AddCombinePostFunction, DgnFileP, WCharCP, WCharCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCombinePostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_CombinePost>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(HistoryCallback::RemoveCombinePostFunction, DgnFileP, WCharCP, WCharCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddDeleteEarlyRevisionsPreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeleteEarlyRevisionsPre>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(HistoryCallback::AddDeleteEarlyRevisionsPreFunction, DgnFileP, WCharCP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveDeleteEarlyRevisionsPreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeleteEarlyRevisionsPre>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(HistoryCallback::RemoveDeleteEarlyRevisionsPreFunction, DgnFileP, WCharCP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddDeleteEarlyRevisionsPostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeleteEarlyRevisionsPost>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(HistoryCallback::AddDeleteEarlyRevisionsPostFunction, DgnFileP, WCharCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveDeleteEarlyRevisionsPostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_DeleteEarlyRevisionsPost>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(HistoryCallback::RemoveDeleteEarlyRevisionsPostFunction, DgnFileP, WCharCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddFmtRevisionNumberFunction", [](FmtRevisionNumberCallbackHelper::FmtRevisionNumberFunctionType& newFunc, const std::string& funcID)
        {
            if (newFunc)
            {
                HistoryFunc_FmtRevisionNumber* callback = FmtRevisionNumberCallbackHelper::SetCallback(newFunc, funcID);
                HistoryCallback::AddFmtRevisionNumberFunction(callback);
            }
            else
            {
                HistoryCallback::AddFmtRevisionNumberFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveFmtRevisionNumberFunction", [](FmtRevisionNumberCallbackHelper::FmtRevisionNumberFunctionType& newFunc, const std::string& funcID) -> bool
        {
            if (newFunc)
            {
                HistoryFunc_FmtRevisionNumber* callback = FmtRevisionNumberCallbackHelper::SetCallback(newFunc, funcID);
                return HistoryCallback::RemoveFmtRevisionNumberFunction(callback);
            }
            else
            {
                return HistoryCallback::RemoveFmtRevisionNumberFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddCompareElementsFunction", [](CompareElementsCallbackHelper::CompareElementsFunctionType& newFunc, const std::string& funcID)
        {
            if (newFunc)
            {
                HistoryFunc_CompareElements* callback = CompareElementsCallbackHelper::SetCallback(newFunc, funcID);
                HistoryCallback::AddCompareElementsFunction(callback);
            }
            else
            {
                HistoryCallback::AddCompareElementsFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveCompareElementsFunction", [](CompareElementsCallbackHelper::CompareElementsFunctionType& newFunc, const std::string& funcID) -> bool
        {
            if (newFunc)
            {
                HistoryFunc_CompareElements* callback = CompareElementsCallbackHelper::SetCallback(newFunc, funcID);
                return HistoryCallback::RemoveCompareElementsFunction(callback);
            }
            else
            {
                return HistoryCallback::RemoveCompareElementsFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddDisplayElementFunction", [](DisplayElementCallbackHelper::DisplayElementFunctionType& newFunc, const std::string& funcID)
        {
            if (newFunc)
            {
                HistoryFunc_DisplayElement* callback = DisplayElementCallbackHelper::SetCallback(newFunc, funcID);
                HistoryCallback::AddDisplayElementFunction(callback);
            }
            else
            {
                HistoryCallback::AddDisplayElementFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveDisplayElementFunction", [](DisplayElementCallbackHelper::DisplayElementFunctionType& newFunc, const std::string& funcID) -> bool
        {
            if (newFunc)
            {
                HistoryFunc_DisplayElement* callback = DisplayElementCallbackHelper::SetCallback(newFunc, funcID);
                return HistoryCallback::RemoveDisplayElementFunction(callback);
            }
            else
            {
                return HistoryCallback::RemoveDisplayElementFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddDescribeElementFunction", [](DescribeElementCallbackHelper::DescribeElementFunctionType& newFunc, const std::string& funcID)
        {
            if (newFunc)
            {
                HistoryFunc_DescribeElement* callback = DescribeElementCallbackHelper::SetCallback(newFunc, funcID);
                HistoryCallback::AddDescribeElementFunction(callback);
            }
            else
            {
                HistoryCallback::AddDescribeElementFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveDescribeElementFunction", [](DescribeElementCallbackHelper::DescribeElementFunctionType& newFunc, const std::string& funcID) -> bool
        {
            if (newFunc)
            {
                HistoryFunc_DescribeElement* callback = DescribeElementCallbackHelper::SetCallback(newFunc, funcID);
                return HistoryCallback::RemoveDescribeElementFunction(callback);
            }
            else
            {
                return HistoryCallback::RemoveDescribeElementFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddRestorePreFunction", [](RestorePreCallbackHelper::RestorePreFunctionType& newFunc, const std::string& funcID)
        {
            if (newFunc)
            {
                HistoryFunc_RestorePre* callback = RestorePreCallbackHelper::SetCallback(newFunc, funcID);
                HistoryCallback::AddRestorePreFunction(callback);
            }
            else
            {
                HistoryCallback::AddRestorePreFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveRestorePreFunction", [](RestorePreCallbackHelper::RestorePreFunctionType& newFunc, const std::string& funcID) -> bool
        {
            if (newFunc)
            {
                HistoryFunc_RestorePre* callback = RestorePreCallbackHelper::SetCallback(newFunc, funcID);
                return HistoryCallback::RemoveRestorePreFunction(callback);
            }
            else
            {
                return HistoryCallback::RemoveRestorePreFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddRestorePostFunction", [](RestorePostCallbackHelper::RestorePostFunctionType& newFunc, const std::string& funcID)
        {
            if (newFunc)
            {
                HistoryFunc_RestorePost* callback = RestorePostCallbackHelper::SetCallback(newFunc, funcID);
                HistoryCallback::AddRestorePostFunction(callback);
            }
            else
            {
                HistoryCallback::AddRestorePostFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveRestorePostFunction", [](RestorePostCallbackHelper::RestorePostFunctionType& newFunc, const std::string& funcID) -> bool
        {
            if (newFunc)
            {
                HistoryFunc_RestorePost* callback = RestorePostCallbackHelper::SetCallback(newFunc, funcID);
                return HistoryCallback::RemoveRestorePostFunction(callback);
            }
            else
            {
                return HistoryCallback::RemoveRestorePostFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddUpdateRevisionUserDescPreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_UpdateRevisionUserDescPre>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(HistoryCallback::AddUpdateRevisionUserDescPreFunction, DgnFileP, WCharCP, WCharCP, WCharCP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveUpdateRevisionUserDescPreFunction", [](std::function<std::remove_pointer_t<HistoryFunc_UpdateRevisionUserDescPre>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(HistoryCallback::RemoveUpdateRevisionUserDescPreFunction, DgnFileP, WCharCP, WCharCP, WCharCP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("AddUpdateRevisionUserDescPostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_UpdateRevisionUserDescPost>>& newFunc, const std::string& funcID)
        {
            ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(HistoryCallback::AddUpdateRevisionUserDescPostFunction, DgnFileP, WCharCP, WCharCP, WCharCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c100.def_static("RemoveUpdateRevisionUserDescPostFunction", [](std::function<std::remove_pointer_t<HistoryFunc_UpdateRevisionUserDescPost>>& newFunc, const std::string& funcID) -> bool
        {
            ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(HistoryCallback::RemoveUpdateRevisionUserDescPostFunction, DgnFileP, WCharCP, WCharCP, WCharCP, StatusInt, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);
}
