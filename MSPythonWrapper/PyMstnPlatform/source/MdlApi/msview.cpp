/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msview.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msview.fdf>
#include "CallbackHelper.h"


class ViewUpdateCallbackHelper {
public:
    typedef int(*ViewUpdateCallbackPtrType)(bool, DgnPlatform::DgnDrawMode, DgnModelRefListP, int, Asynch_update_view[], ViewContextP, int[], MSDisplayDescr*[]);
    typedef std::function<int(bool, DgnPlatform::DgnDrawMode, DgnModelRefListP, std::vector<Asynch_update_view*>*, ViewContextP, std::vector<int>*, std::vector<MSDisplayDescr*>*)> ViewUpdateFunctionType;

#define DEFINE_FN_POINTER_VIEW_UPDATE_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](bool isPreUpdate, DgnPlatform::DgnDrawMode eraseMode, DgnModelRefListP modelList, int numRegions, Asynch_update_view regions[], ViewContextP context, int numCovers[], MSDisplayDescr* displayDescr[]) -> int\
        { \
            try \
            { \
                std::vector<Asynch_update_view*> regionsVector; \
                for (int iRegion = 0; iRegion < numRegions; iRegion++) \
                { \
                    regionsVector.push_back(&regions[iRegion]); \
                } \
                std::vector<int> numCoversVector; \
                numCoversVector.push_back(numCovers[0]); \
                std::vector<MSDisplayDescr*> displayDescrVector; \
                displayDescrVector.push_back(displayDescr[0]); \
                return m_callbackFuncs[index](isPreUpdate, eraseMode, modelList, &regionsVector, context, &numCoversVector, &displayDescrVector); \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static ViewUpdateCallbackPtrType SetCallback(ViewUpdateFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
         DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_VIEW_UPDATE_CALLBACK);
    }

    static ViewUpdateFunctionType GetOldCallbackFunction(ViewUpdateCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_CALLBACK_COUNT_20);
    }

private:
    static ViewUpdateFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static ViewUpdateCallbackPtrType m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename ViewUpdateCallbackHelper::ViewUpdateFunctionType ViewUpdateCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
typename ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType ViewUpdateCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string ViewUpdateCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];

class ViewSubstituteElemCallbackHelper {
public:
    typedef SubstituteElemStatus(*ViewSubstituteElemCallbackPtrType)(MSElementDescrH, ViewportP, DgnPlatform::DrawPurpose, ViewContextP, ElementHandleCP);
    typedef std::function<SubstituteElemStatus(MSElementDescrReceiver*, ViewportP, DgnPlatform::DrawPurpose, ViewContextP, ElementHandleCP)> ViewSubstituteElemFunctionType;

#define DEFINE_FN_POINTER_VIEW_SUBSTITUTE_ELEM_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](MSElementDescrH newElem, ViewportP viewport, DgnPlatform::DrawPurpose purpose, ViewContextP context, ElementHandleCP elem) -> SubstituteElemStatus\
        { \
            try \
            { \
                MSElementDescrReceiver receiver(nullptr); \
                SubstituteElemStatus returnVal = m_callbackFuncs[0](&receiver, viewport, purpose, context, elem); \
                if (nullptr != receiver.value) \
                { \
                    *newElem = receiver.value; \
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

    static ViewSubstituteElemCallbackPtrType SetCallback(ViewSubstituteElemFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_VIEW_SUBSTITUTE_ELEM_CALLBACK);
    }

    static ViewSubstituteElemFunctionType GetOldCallbackFunction(ViewSubstituteElemCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_CALLBACK_COUNT_20);
    }

private:
    static ViewSubstituteElemFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static ViewSubstituteElemCallbackPtrType m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename ViewSubstituteElemCallbackHelper::ViewSubstituteElemFunctionType ViewSubstituteElemCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
typename ViewSubstituteElemCallbackHelper::ViewSubstituteElemCallbackPtrType ViewSubstituteElemCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string ViewSubstituteElemCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msview(py::module_& m)
{
    py::enum_<SubstituteElemStatus>(m, "SubstituteElemStatus")
        .value("eSUBSTELEM_STATUS_Normal", SubstituteElemStatus::SUBSTELEM_STATUS_Normal)
        .value("eSUBSTELEM_STATUS_Block" , SubstituteElemStatus::SUBSTELEM_STATUS_Block)
        .export_values();

    py::class_<ViewCallback> c1(m, "ViewCallback");
    c1.def_static("SetUpdatePreFunction", [](ViewUpdateCallbackHelper::ViewUpdateFunctionType& newFunc, const std::string& funcID) -> ViewUpdateCallbackHelper::ViewUpdateFunctionType
        {
            ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType oldCallback;
            if (newFunc)
            {
                ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType callback = ViewUpdateCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = ViewCallback::SetUpdatePreFunction(callback);
            }
            else
            {
                oldCallback = ViewCallback::SetUpdatePreFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return ViewUpdateCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetUpdatePostFunction", [](ViewUpdateCallbackHelper::ViewUpdateFunctionType& newFunc, const std::string& funcID) -> ViewUpdateCallbackHelper::ViewUpdateFunctionType
        {
            ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType oldCallback;
            if (newFunc)
            {
                ViewUpdateCallbackHelper::ViewUpdateCallbackPtrType callback = ViewUpdateCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = ViewCallback::SetUpdatePostFunction(callback);
            }
            else
            {
                oldCallback = ViewCallback::SetUpdatePostFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return ViewUpdateCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetMotionFunction", [](std::function<std::remove_pointer_t<ViewFunc_Motion>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<ViewFunc_Motion>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(ViewCallback::SetMotionFunction, MSWindowP, int, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetNoMotionFunction", [](std::function<std::remove_pointer_t<ViewFunc_Motion>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<ViewFunc_Motion>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(ViewCallback::SetNoMotionFunction, MSWindowP, int, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetSubstituteElemFunction", [](ViewSubstituteElemCallbackHelper::ViewSubstituteElemFunctionType& newFunc, const std::string& funcID) -> ViewSubstituteElemCallbackHelper::ViewSubstituteElemFunctionType
        {
            ViewSubstituteElemCallbackHelper::ViewSubstituteElemCallbackPtrType oldCallback;
            if (newFunc)
            {
                ViewSubstituteElemCallbackHelper::ViewSubstituteElemCallbackPtrType callback = ViewSubstituteElemCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = ViewCallback::SetSubstituteElemFunction(callback);
            }
            else
            {
                oldCallback = ViewCallback::SetSubstituteElemFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return ViewSubstituteElemCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a);
}
