/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dependencymanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DependencyManager.h>



static const char * __doc_Bentley_DgnPlatform_DependencyManager_SetProcessingDisabled =R"doc(Remark:
    s Call #SetTrackingDisabled to suppress change-tracking. (Without
    change-tracking, there is no post-processing.))doc";

static const char * __doc_Bentley_DgnPlatform_DependencyManager_SatisfyDependencyGraph =R"doc(Call SatisfyConstraints on the global DependencyGraph)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DependencyManager(py::module_& m)
    {
    //===================================================================================
    // struct DependencyManager
    py::class_< DependencyManager> c1(m, "DependencyManager");

    c1.def_static("ProcessAffected", &DependencyManager::ProcessAffected);
    c1.def_static("SatisfyDependencyGraph", &DependencyManager::SatisfyDependencyGraph, DOC(Bentley, DgnPlatform, DependencyManager, SatisfyDependencyGraph));
    c1.def_static("RootChanged", &DependencyManager::RootChanged, "root"_a);
    c1.def_static("WasAdded", &DependencyManager::WasAdded, "ref"_a);
    c1.def_static("IsInCurrentChangeSet", &DependencyManager::IsInCurrentChangeSet, "ref"_a);
    c1.def_static("SetProcessingDisabled", &DependencyManager::SetProcessingDisabled, "bSuppress"_a, DOC(Bentley, DgnPlatform, DependencyManager, SetProcessingDisabled));
    c1.def_static("GetProcessingDisabled", &DependencyManager::GetProcessingDisabled);
    c1.def_static("GetTrackingDisabled", &DependencyManager::GetTrackingDisabled);
    c1.def_static("SetTraceLevel", &DependencyManager::SetTraceLevel, "traceLevel"_a);
    c1.def_static("IsUnsupportedDependency", &DependencyManager::IsUnsupportedDependency, "targetElement"_a, "dependentCache"_a);
    c1.def_static("IsGraphSatisfyInProgress", &DependencyManager::IsGraphSatisfyInProgress, "startTime"_a);        
    }