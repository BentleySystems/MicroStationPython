/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\configurationmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Tools/ConfigurationManager.h>



static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_MonitorString =R"doc(Get and update a string ConfigurationVariable.

Parameter ``monitor``:
    A reference to a static IVariableMonitorP variable that is used
    both to hold the IVariableMonitorP in case it is needed by the
    caller, and to detect whether the monitor has been initialized on
    subsequent calls.

Parameter ``string``:
    A reference to the string that will be set and updated by this
    method. After the initial call, the variable is set to the value
    stored in the configuration variable. If the configuration
    variable is subsequently changed, either by changing projects or
    directly by the user, the boolean variable referenced is updated.

Parameter ``cfgVarName``:
    The configuration variable to monitor.

Returns:
    The method returns the value reference by the " value " parameter.
    @note You must ensure that both the value and monitor parameters
    references static variables, or make sure that you call
    ConfigurationManager::StopMonitor with the IVariableMonitor
    returned when the variable ceases to exist (for example in the
    destructor of a class if they are class members).)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_MonitorInteger =R"doc(Get and update a ConfigurationVariable that represents an integer
value.

Parameter ``monitor``:
    A reference to a static IVariableMonitorP variable that is used
    both to hold the IVariableMonitorP in case it is needed by the
    caller, and to detect whether the monitor has been initialized on
    subsequent calls.

Parameter ``value``:
    A reference to the integer that will be set and updated by this
    method. After the initial call, the variable is set to the value
    stored in the configuration variable. If the configuration
    variable is subsequently changed, either by changing projects or
    directly by the user, the boolean variable referenced is updated.

Parameter ``cfgVarName``:
    The configuration variable to monitor.

Parameter ``defaultValue``:
    The default that value is set to if the configuration variable is
    not defined.

Parameter ``minimumValue``:
    The minimum that value can be set to.

Parameter ``maximumValue``:
    The maximum that value can be set to.

Returns:
    The method returns the value reference by the " value " parameter.
    @note You must ensure that both the value and monitor parameters
    references static variables, or make sure that you call
    ConfigurationManager::StopMonitor with the IVariableMonitor
    returned when the variable ceases to exist (for example in the
    destructor of a class if they are class members).)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_MonitorBoolean =R"doc(Get and update a ConfigurationVariable that represents a boolean
value.

Parameter ``monitor``:
    A reference to a static IVariableMonitorP variable that is used
    both to hold the IVariableMonitorP in case it is needed by the
    caller, and to detect whether the monitor has been initialized on
    subsequent calls.

Parameter ``value``:
    A reference to the boolean that will be set and updated by this
    method. After the initial call, the variable is set to the value
    stored in the configuration variable. If the configuration
    variable is subsequently changed, either by changing projects or
    directly by the user, the boolean variable referenced is updated.

Parameter ``cfgVarName``:
    The configuration variable to monitor.

Parameter ``defaultValue``:
    The default that value is set to if the configuration variable is
    not defined.

Returns:
    The method returns the value reference by the " value " parameter.
    @note The value of a configuration variable is considered true if
    the it translates to " 1 ", " true ", or " on " (case insensitive).
    @note You must ensure that both the value and monitor parameters
    references static variables, or make sure that you call
    ConfigurationManager::RemoveMonitor with the IVariableMonitor
    returned when the variable ceases to exist (for example in the
    destructor of a class if they are class members). @note After the
    first calls to MonitorBoolean, subsequent calls are very fast. The
    program can either)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_RemoveMonitor =R"doc(Remove a ConfigurationVariable Monitor.

Parameter ``cfgVarName``:
    The configuration variable to monitor.

Parameter ``monitor``:
    The instance of the class that implements IVariableMonitor that is
    to be removed as a monitor.

Returns:
    The method will fail if the configuration variable is not defined,
    or if the implementation of ConfigurationManager cannot monitor
    variables. The Macro system ConfigurationManager is able to
    monitor variables. @note When this method is called, the
    IVariableMonitor::_VariableChanged method is called with the
    current configuration variable value, and with reason set to
    VariableChangeReason::Initiated.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_MonitorVariable =R"doc(Monitor a ConfigurationVariable for changes.

Parameter ``cfgVarName``:
    The configuration variable to monitor.

Parameter ``monitor``:
    An instance of a class that implements IVariableMonitor.

Returns:
    The method will fail if the configuration variable is not defined,
    or if the implementation of ConfigurationManager cannot monitor
    variables. The Macro system ConfigurationManager is able to
    monitor variables. @note When this method is called, the
    IVariableMonitor::_VariableChanged method is called with the
    current configuration variable value, and with reason set to
    VariableChangeReason::Initiated.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_IterateThroughVariables =R"doc(Iterate through all config variables and call the delegate for each.

Parameter ``delegate``:
    The delegate to call for each config variable.

Returns:
    SUCCESS if the variables could be iterated through.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_UndefineVariable =R"doc(Undefine (remove) the configuration variable.

Parameter ``cfgVarName``:
    The name of the variable to undefine. @note This method cannot be
    used to remove configuration values that come from operating
    system environment variables.

Returns:
    SUCCESS if the variable is successfully deleted. This method will
    fail if the variable is not defined.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_DefineVariable =R"doc(Define a configuration variable. If the variable already exists, its
value is redefined.

Parameter ``cfgVarName``:
    Name of the configuration variable. Must not be NULL.

Parameter ``cfgValue``:
    The new value. Must not be NULL.

Parameter ``level``:
    level of configuration variable. Typically, use
    #ConfigurationVariableLevel::User.

Returns:
    SUCCESS if the variable is successfully defined.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_GetVariable =R"doc(Get the value for a configuration variable in a WString.

Parameter ``cfgValue``:
    The WString to fill with the fully expanded value of the
    configuration variable.

Parameter ``cfgVarName``:
    The name of the configuration variable to retrieve.

Parameter ``level``:
    level of configuration variable. Typically, use
    #ConfigurationVariableLevel::User.

Returns:
    SUCCESS if the configuration variable was defined and its value is
    in ``cfgValue.`` On failure, ``cfgValue`` will be empty.

Remark:
    s if the variable is defined at a higher level, this function
    returns SUCCESS but cfgValue will be empty.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_IsVariableDefinedAndFalse =R"doc(Check for a configuration variable defined to a " false " value.

Parameter ``cfgVarName``:
    The name of the configuration variable to check.

Returns:
    true if ``cfgVarName`` is defined to " 0 ", " false ", or " off " (case
    insensitive).

Remark:
    s If the ``cfgVarName`` is not defined, returns false.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_IsVariableDefinedAndTrue =R"doc(Check for a configuration variable defined to a " true " value.

Parameter ``cfgVarName``:
    The name of the configuration variable to check.

Returns:
    true if ``cfgVarName`` is defined to " 1 ", " true ", or " on " (case
    insensitive).)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_IsVariableDefined =R"doc(Check for the existence of a configuration variable.

Parameter ``cfgVarName``:
    The name of the configuration variable to check.

Returns:
    true if ``cfgVarName`` is defined.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_GetNameForTempFile =R"doc(Generate a unique name for a temporary file.

Parameter ``tempFileName``:
    The name for a temporary file. Should be MAX_PATH chars in size.

Parameter ``partialPathName``:
    intermediate dirs you want between %tmp% and the filename
    generated.

Parameter ``prefixString``:
    up to 3 chars of this will be used in the generated filename

Returns:
    SUCCESS, if the directory for the temporary file exists or was
    created. @note This method does not create a temporary file, it
    merely returns a name that can be used to create a temporary file.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_GetLocalTempDirectory =R"doc(Return a local directory that can be used to store temporary files.
This directory can optionally be a subdirectory of
#GetLocalTempDirectoryBaseName.

Parameter ``tempDir``:
    The name of temporary directory. This must be MAX_PATH chars in
    size.

Parameter ``subDirName``:
    Optional subdirectory relative to default temp directory. If non-
    NULL, this subdirectory will be created.

Returns:
    NULL if no temporary directory available.)doc";

static const char * __doc_Bentley_DgnPlatform_ConfigurationManager_GetLocalTempDirectoryBaseName =R"doc(Return the root of the local directory that can be used to store
temporary files. This directory must have write access.

Returns:
    NULL if no temporary directory available.)doc";

static const char * __doc_Bentley_DgnPlatform_IConfigVariableIteratorDelegate_EachConfigVariable =R"doc(Called for each configuration variable.)doc";

static const char * __doc_Bentley_DgnPlatform_IVariableMonitor__MonitorStopped =R"doc(Called to inform of the IVariableMonitor that the configuration
monitor has been stopped for the configuraion variable.

Parameter ``variableName``:
    The Configuration Variable name. @note Typical behavior is to
    delete this instance of IVariableMonitor. In the case where one
    IVariableMonitor instance is used to monitor multiple
    configuration variables, use reference counting. Increment the
    reference count for each call to MonitorVariable, and decrement
    the refeerence count for each call to
    IVariableMonitor::_MonitorStopped, deleting the instance when
    reference count hits 0.)doc";

static const char * __doc_Bentley_DgnPlatform_IVariableMonitor__VariableRootUndefined =R"doc(Called to inform that a Configuration variable this this Configuration
variable depends on was undefined.

Parameter ``variableName``:
    The Configuration Variable name.

Parameter ``rootVariableName``:
    The Configuration Variable name of the undefined root. @note The
    variable that was undefined may be an " ancestor " configuration
    variable, i.e., not a direct root of this configuration variable,
    but a root of one of its roots, etc.)doc";

static const char * __doc_Bentley_DgnPlatform_IVariableMonitor__VariableUndefined =R"doc(Called to inform that a Configuration variable was undefined.

Parameter ``variableName``:
    The Configuration Variable name.)doc";

static const char * __doc_Bentley_DgnPlatform_IVariableMonitor__VariableRootChanged =R"doc(Called to inform that a Configuration variable that this Configuration
variable depends on was redefined.

Parameter ``variableName``:
    The Configuration Variable name.

Parameter ``rootVariableName``:
    The Configuration Variable name of the changed root. @note The
    variable that was changed may be an " ancestor " configuration
    variable, i.e., not a direct root of this configuration variable,
    but a root of one of its roots, etc.)doc";

static const char * __doc_Bentley_DgnPlatform_IVariableMonitor__VariableChanged =R"doc(Called to inform that a Configuration variable was redefined.

Parameter ``variableName``:
    The Configuration Variable name.)doc";

//=======================================================================================
// Trampoline class for IVariableMonitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyVariableMonitor : IVariableMonitor
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _VariableChanged(WCharCP variableName) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IVariableMonitor, _VariableChanged, variableName); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _VariableRootChanged(WCharCP variableName, WCharCP rootVariableName) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IVariableMonitor, _VariableRootChanged, variableName, rootVariableName); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _VariableUndefined(WCharCP variableName) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IVariableMonitor, _VariableUndefined, variableName); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _VariableRootUndefined(WCharCP variableName, WCharCP rootVariableName) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IVariableMonitor, _VariableRootUndefined, variableName, rootVariableName); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _MonitorStopped(WCharCP variableName) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IVariableMonitor, _MonitorStopped, variableName); }
    };

//=======================================================================================
// Trampoline class for IConfigVariableIteratorDelegate.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyConfigVariableIteratorDelegate : IConfigVariableIteratorDelegate
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void EachConfigVariable(WCharCP name, WCharCP value, ConfigurationVariableLevel level, bool locked) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IConfigVariableIteratorDelegate, EachConfigVariable, name, value, level, locked); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ConfigurationManager(py::module_& m)
    {
    //===================================================================================
    // struct IVariableMonitor
    py::class_< IVariableMonitor, std::unique_ptr<IVariableMonitor, py::nodelete>, IPyVariableMonitor> c1(m, "IVariableMonitor");

    c1.def(py::init<>());
    c1.def("_VariableChanged", &IVariableMonitor::_VariableChanged, "variableName"_a, DOC(Bentley, DgnPlatform, IVariableMonitor, _VariableChanged));
    c1.def("_VariableRootChanged", &IVariableMonitor::_VariableRootChanged, "variableName"_a, "rootVariableName"_a, DOC(Bentley, DgnPlatform, IVariableMonitor, _VariableRootChanged));
    c1.def("_VariableUndefined", &IVariableMonitor::_VariableUndefined, "variableName"_a, DOC(Bentley, DgnPlatform, IVariableMonitor, _VariableUndefined));
    c1.def("_VariableRootUndefined", &IVariableMonitor::_VariableRootUndefined, "variableName"_a, "rootVariableName"_a, DOC(Bentley, DgnPlatform, IVariableMonitor, _VariableRootUndefined));
    c1.def("_MonitorStopped", &IVariableMonitor::_MonitorStopped, "variableName"_a, DOC(Bentley, DgnPlatform, IVariableMonitor, _MonitorStopped));

    //===================================================================================
    // struct IConfigVariableIteratorDelegate
    py::class_< IConfigVariableIteratorDelegate, std::unique_ptr< IConfigVariableIteratorDelegate, py::nodelete>, IPyConfigVariableIteratorDelegate> c2(m, "IConfigVariableIterator");

    c2.def(py::init<>());
    c2.def("EachConfigVariable", &IConfigVariableIteratorDelegate::EachConfigVariable, "name"_a, "value"_a, "level"_a, "locked"_a, DOC(Bentley, DgnPlatform, IConfigVariableIteratorDelegate, EachConfigVariable));

    //===================================================================================
    // struct ConfigurationManager
    py::class_< ConfigurationManager> c3(m, "ConfigurationManager");

    c3.def_static("GetLocalTempDirectoryBaseName", &ConfigurationManager::GetLocalTempDirectoryBaseName, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, ConfigurationManager, GetLocalTempDirectoryBaseName));

    c3.def_static("GetLocalTempDirectory", [] (WStringR tempDir, WCharCP subDirName)
                  {
                  BeFileName dirName;
                  auto retVal = ConfigurationManager::GetLocalTempDirectory(dirName, subDirName);
                  if (retVal == SUCCESS)
                      tempDir.assign(dirName.c_str());
                  return retVal;
                  }, "tempDir"_a, "subDirName"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, GetLocalTempDirectory));

    c3.def_static("GetNameForTempFile", [] (WStringR tempFileName, WCharCP partialPathName, WCharCP prefixString)
                  {
                  BeFileName fileName;
                  auto retVal = ConfigurationManager::GetNameForTempFile(fileName, partialPathName, prefixString);
                  if (retVal == SUCCESS)
                      tempFileName.assign(fileName.c_str());
                  return retVal;
                  }, "tempFileName"_a, "partialPathName"_a, "prefixString"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, GetNameForTempFile));

    c3.def_static("IsVariableDefined", &ConfigurationManager::IsVariableDefined, "cfgVarName"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, IsVariableDefined));
    c3.def_static("IsVariableDefinedAndTrue", &ConfigurationManager::IsVariableDefinedAndTrue, "cfgVarName"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, IsVariableDefinedAndTrue));
    c3.def_static("IsVariableDefinedAndFalse", &ConfigurationManager::IsVariableDefinedAndFalse, "cfgVarName"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, IsVariableDefinedAndFalse));
    c3.def_static("GetVariable", &ConfigurationManager::GetVariable, "cfgVarValue"_a, "cfgVarName"_a, "level"_a = ConfigurationVariableLevel::User, DOC(Bentley, DgnPlatform, ConfigurationManager, GetVariable));
    c3.def_static("DefineVariable", &ConfigurationManager::DefineVariable, "cfgVarName"_a, "cfgValue"_a, "level"_a = ConfigurationVariableLevel::User, DOC(Bentley, DgnPlatform, ConfigurationManager, DefineVariable));
    c3.def_static("UndefineVariable", &ConfigurationManager::UndefineVariable, "cfgVarName"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, UndefineVariable));
    c3.def_static("IterateThroughVariables", &ConfigurationManager::IterateThroughVariables, "iterator"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, IterateThroughVariables));
    c3.def_static("MonitorVariable", &ConfigurationManager::MonitorVariable, "cfgVarName"_a, "monitor"_a, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, ConfigurationManager, MonitorVariable));
    c3.def_static("RemoveMonitor", &ConfigurationManager::RemoveMonitor, "cfgVarName"_a, "monitor"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, RemoveMonitor));

    c3.def_static("MonitorBoolean", [] (WCharCP cfgVarName, bool defaultValue)
                  {
                  IVariableMonitorP monitor = nullptr;
                  bool value = false;
                  auto retVal = ConfigurationManager::MonitorBoolean(monitor, value, cfgVarName, defaultValue);
                  return py::make_tuple(retVal, std::unique_ptr< IVariableMonitor, py::nodelete>(monitor), value);
                  }, "cfgVarName"_a, "defaultValue"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, MonitorBoolean));

    c3.def_static("MonitorInteger", [] (WCharCP cfgVarName, bool defaultValue, int minimumValue, int maximumValue)
                  {
                  IVariableMonitorP monitor = nullptr;
                  int value = false;
                  auto retVal = ConfigurationManager::MonitorInteger(monitor, value, cfgVarName, defaultValue, minimumValue, maximumValue);
                  return py::make_tuple(retVal, std::unique_ptr< IVariableMonitor, py::nodelete>(monitor), value);
                  }, "cfgVarName"_a, "defaultValue"_a, "minimumValue"_a, "maximumValue"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, MonitorInteger));

    c3.def_static("MonitorString", [] (WCharCP cfgVarName)
                  {
                  IVariableMonitorP monitor = nullptr;
                  WString value = L"";
                  auto retVal = ConfigurationManager::MonitorString(monitor, value, cfgVarName);
                  return py::make_tuple(retVal, std::unique_ptr< IVariableMonitor, py::nodelete>(monitor), value);
                  }, "cfgVarName"_a, DOC(Bentley, DgnPlatform, ConfigurationManager, MonitorString));

    }