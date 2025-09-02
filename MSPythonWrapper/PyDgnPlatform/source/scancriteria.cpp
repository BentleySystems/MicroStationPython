/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ScanCriteria.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ScanCriteria.h>
#include <pybind11/functional.h>

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_CheckElement =R"doc(Check one particular element agains this ScanCriteria

Parameter ``elHandle``:
    The element to test.

Parameter ``doRangeTest``:
    Check the range.

Parameter ``doAttrTest``:
    Check attributes.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_Scan =R"doc(Perform the scan, filtering elements as dictated by this ScanCriteria,
calling the callbackFunc specified in #SetElemRefCallback.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetRangeTest =R"doc(Sets the range testing for the scan. If scanRange is NULL, then no
range testing is performed.

Parameter ``scanRange``:
    The range to test. An element whose range overlaps any part of
    scanRange is returned by the scan.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetPriorityTest =R"doc(Sets the element priority testing. If maxPriority is less than
minPriority, priorty testing is disabled.

Parameter ``minPriority``:
    The minimum priority value.

Parameter ``maxPriority``:
    The maximum priority value.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetElementTypeTest =R"doc(Sets a type mask of elements to return.

Parameter ``typeMask``:
    An array of unsigned shorts with one bit representing each element
    type. Bit 0 of the first member of the array corresponds to
    element type 1, etc. If this argument is NULL then all element
    types are scanned. The maximum size of elements in the array is 8 shorts.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetDrawnElements =R"doc(Sets the Scan to return only elements that are drawn, eliminating
control element types.

Remark:
    s Do not use #SetElementTypeTest if this method is called.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetPropertiesTest =R"doc(Sets the Element properties test. If the propertiesVal argument is set
to 0, then properties testing is disabled. @Param[in] propertiesVal
The value part of the properties test. @Param[in] propertiesMask The
mask part of the properties test.

Remark:
    s The scanner checks the element's properties by ANDing
    propertiesMask with the element's properties bits and then
    comparing the result with propertiesVal. If these values do not
    match, the element is rejected.)doc";

static const char* __doc_Bentley_DgnPlatform_ScanCriteria_SetElemRefCallback = R"doc(Sets the function that is to be called for each acceptable element
when the #Scan method is called.

Parameter ``callbackFunc``:
    The user function that is to be called for each accepted element.

Parameter ``callbackArg``:
    A user-specified argument passed to the callbackFunc.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetModelSections =R"doc(Sets the model sections or sections that are to be traversed during
the the scan. Before calling this method, call #SetModelRef.

Parameter ``sections``:
    The target sections for the scan. Valid values for the sections
    are OR'ed combinations of the DgnModelSection values, except the
    combination DgnModelSections::Dictionary |
    DgnModelSections::GraphicElements is invalid. If SetModelSections
    is not called, all model sections are scanned.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetModelRef =R"doc(Sets the DgnModelRef that is to be scanned.

Parameter ``modelRef``:
    The modelRef to be scanned.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_AddSingleLevelTest =R"doc(Add the specified level to the Levels filter. Elements on that level
will be returned by the scan.

Parameter ``level``:
    The level to add to the Levels filter.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_RemoveSingleLevelTest =R"doc(Remove the specified level from the Levels filter. Elements on that
level will not be returned by the scan.

Parameter ``level``:
    The level to remove from the Levels filter.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetLevelTest =R"doc(Set the Levels filter. Only elements on levels that pass the level
test will be returned by the scan.

Parameter ``levelBitMask``:
    The bitmask indicating the acceptable levels. It is formed by
    setting bit (LevelId-1) in the bitmask for each LevelId that is
    desired.

Parameter ``owned``:
    If true, ownership of the levelBitMask and responsibility for
    freeing it is passed to the ScanCriteria. If false, the
    ScanCriteria keeps a pointer to the levelBitMask and the caller is
    responsible for ensuring that the levelBitMask is not freed before
    the ScanCriteria.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_ClearLevelMask =R"doc(Clears the Levels filter. Elements from all levels will be returned by
the scan.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_SetClassTest =R"doc(Set the Element Class filter.

Parameter ``classMask``:
    A mask with a bit set for each class. This is formed as an OR of
    the desired classes, using (1 << class) for the desired classes
    from the enum.

Remark:
    If the classMask argument is set to 0, then class testing is
    disabled.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_RemoveSingleElementTypeTest =R"doc(Remove an Element Type from the Type filter.

Parameter ``elType``:
    The element type to remove from the type filter. Elements of that
    element type will not be returned by the Scan.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_AddSingleElementTypeTest =R"doc(Add an Element Type to the Type filter.

Parameter ``elType``:
    The element type to add to the class filter. Elements of that
    element type will be returned by the Scan.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_AddSingleClassTest =R"doc(Add an Element Class to the Class filter.

Parameter ``elementClass``:
    The class to add to the class filter. Elements of that element
    class will be returned by the Scan.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_RemoveSingleClassTest =R"doc(Remove an Element Class from the Class filter.

Parameter ``elementClass``:
    The class to remove from the class filter. Elements of that
    element class will not be returned by the Scan.)doc";

static const char * __doc_Bentley_DgnPlatform_ScanCriteria_Clone =R"doc(Copy an existing ScanCriteria.

Parameter ``source``:
    The existing ScanCriteria to copy.)doc";

//===================================================================================
// ScanCriteria deleter
struct SCDeleter 
    {
    void operator()(ScanCriteriaP scP) const 
        {
        if (scP)
            ScanCriteria::Delete(scP);
        }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       5/2025
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ScanCriteria(py::module_& m)
    {
    //===================================================================================
    // Enum ScanCriteriaConstants
    py::enum_<ScanCriteriaConstants>(m, "ScanCriteriaConstants", py::arithmetic())
        .value("eMSSCANCRIT_RETURN_FILEPOS", ScanCriteriaConstants::MSSCANCRIT_RETURN_FILEPOS)
        .value("eMSSCANCRIT_RETURN_ELEMENTDATA", ScanCriteriaConstants::MSSCANCRIT_RETURN_ELEMENTDATA)
        .value("eMSSCANCRIT_RETURN_POSANDDATA", ScanCriteriaConstants::MSSCANCRIT_RETURN_POSANDDATA)
        .value("eMSSCANCRIT_RETURN_UNIQUEID", ScanCriteriaConstants::MSSCANCRIT_RETURN_UNIQUEID)
        .value("eMSSCANCRIT_ITERATE_ELMDSCR", ScanCriteriaConstants::MSSCANCRIT_ITERATE_ELMDSCR)
        .value("eMSSCANCRIT_ITERATE_ELMREF", ScanCriteriaConstants::MSSCANCRIT_ITERATE_ELMREF)
        .value("eMSSCANCRIT_ITERATE_ELMREF_UNORDERED", ScanCriteriaConstants::MSSCANCRIT_ITERATE_ELMREF_UNORDERED)
        .value("eSCANALL_ABORT_SCAN", ScanCriteriaConstants::SCANALL_ABORT_SCAN)
        .value("eSCANALL_ABORT_CURRENT_MODEL", ScanCriteriaConstants::SCANALL_ABORT_CURRENT_MODEL)
        .value("eEND_OF_DGN", ScanCriteriaConstants::END_OF_DGN)
        .value("eBUFF_FULL", ScanCriteriaConstants::BUFF_FULL)
        .value("eREAD_LIMIT", ScanCriteriaConstants::READ_LIMIT)
        .value("eBAD_FILE", ScanCriteriaConstants::BAD_FILE)
        .value("eBAD_REQUEST", ScanCriteriaConstants::BAD_REQUEST)
        .value("eBAD_ELEMENT", ScanCriteriaConstants::BAD_ELEMENT)
        .value("eBUFF_TOO_SMALL", ScanCriteriaConstants::BUFF_TOO_SMALL)
        .export_values();

    //===================================================================================
    // struct ScanCriteria
    py::class_<ScanCriteria, std::unique_ptr<ScanCriteria, SCDeleter>> c1(m, "ScanCriteria", py::multiple_inheritance());

    c1.def(py::init(&ScanCriteria::Create));

    c1.def_static("Clone", &ScanCriteria::Clone, "source"_a, DOC(Bentley, DgnPlatform, ScanCriteria, Clone));

    c1.def("RemoveSingleClassTest", &ScanCriteria::RemoveSingleClassTest, "elementClass"_a, DOC(Bentley, DgnPlatform, ScanCriteria, RemoveSingleClassTest));
    c1.def("AddSingleClassTest", &ScanCriteria::AddSingleClassTest, "elementClass"_a, DOC(Bentley, DgnPlatform, ScanCriteria, AddSingleClassTest));
    c1.def("AddSingleElementTypeTest", &ScanCriteria::AddSingleElementTypeTest, "elType"_a, DOC(Bentley, DgnPlatform, ScanCriteria, AddSingleElementTypeTest));
    c1.def("RemoveSingleElementTypeTest", &ScanCriteria::RemoveSingleElementTypeTest, "elType"_a, DOC(Bentley, DgnPlatform, ScanCriteria, RemoveSingleElementTypeTest));
    c1.def("SetClassTest", &ScanCriteria::SetClassTest, "classMask"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetClassTest));
    c1.def("ClearLevelMask", &ScanCriteria::ClearLevelMask, DOC(Bentley, DgnPlatform, ScanCriteria, ClearLevelMask));
    c1.def("SetLevelTest", &ScanCriteria::SetLevelTest, "levelBitMask"_a, "owned"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetLevelTest));
    c1.def("RemoveSingleLevelTest", &ScanCriteria::RemoveSingleLevelTest, "level"_a, DOC(Bentley, DgnPlatform, ScanCriteria, RemoveSingleLevelTest));

    c1.def("AddSingleLevelTest", &ScanCriteria::AddSingleLevelTest, "level"_a, DOC(Bentley, DgnPlatform, ScanCriteria, AddSingleLevelTest));
    c1.def("SetModelRef", &ScanCriteria::SetModelRef, "modelRef"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetModelRef));

    typedef std::function<int(ElementRefP, py::bytearray&, ScanCriteriaP)> pyElemRefCallback;

    static pyElemRefCallback g_elemRefCallback = nullptr;
    static size_t g_callbackArgSize = 0;

    c1.def("SetElemRefCallback", [](ScanCriteria& self, pyElemRefCallback& callbackFunc, py::bytearray& callbackArg)
        {
        g_elemRefCallback = callbackFunc;
        g_callbackArgSize = callbackArg.size();

        PFScanElemRefCallback fnPointer = [](ElementRefP refP, CallbackArgP callbackArgP, ScanCriteriaP scP) -> int
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::bytearray pyArg(reinterpret_cast<const char*>(callbackArgP), g_callbackArgSize);
                return g_elemRefCallback(refP, pyArg, scP);
                }
            catch (std::exception& ex)
                {
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);
                return ERROR;
                }
            };

        CallbackArgP argPtr = (CallbackArgP)PyByteArray_AsString(callbackArg.ptr());
        self.SetElemRefCallback(fnPointer, argPtr);
        }, "callbackFunc"_a, "callbackArg"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetElemRefCallback));

    c1.def("SetModelSections", &ScanCriteria::SetModelSections, "sections"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetModelSections));
    c1.def("SetPropertiesTest", &ScanCriteria::SetPropertiesTest, "propertiesVal"_a, "propertiesMask"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetPropertiesTest));
    c1.def("SetDrawnElements", &ScanCriteria::SetDrawnElements, DOC(Bentley, DgnPlatform, ScanCriteria, SetDrawnElements));

    c1.def("SetElementTypeTest", ([](ScanCriteria& self, UInt16Array typeMask)
        {
        self.SetElementTypeTest(typeMask.data(), (int)typeMask.size());
        }), "typeMask"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetElementTypeTest));

    c1.def("SetPriorityTest", &ScanCriteria::SetPriorityTest, "minPriority"_a, "maxPriority"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetPriorityTest));
    c1.def("SetRangeTest", &ScanCriteria::SetRangeTest, "scanRange"_a, DOC(Bentley, DgnPlatform, ScanCriteria, SetRangeTest));
    c1.def("Scan", py::overload_cast<>(&ScanCriteria::Scan), DOC(Bentley, DgnPlatform, ScanCriteria, Scan));
    c1.def("CheckElement", &ScanCriteria::CheckElement, "elHandle"_a, "doRangeTest"_a, "doAttrTest"_a, DOC(Bentley, DgnPlatform, ScanCriteria, CheckElement));
    }