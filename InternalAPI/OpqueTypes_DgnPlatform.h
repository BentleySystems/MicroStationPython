/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\OpqueTypes_DgnPlatform.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once

#include "OpqueTypes_Geom.h"

DEFINE_BVECTOR_TYPE(DependencyRoot, DependencyRootArray);
DEFINE_BVECTOR_TYPE(CustomProperty, CustomPropertyArray);

DEFINE_BVECTOR_TYPE(ITextPartIdPtr, TextPartIdVector);

DEFINE_BVECTOR_TYPE(DgnRasterP, DgnRasterVector);
DEFINE_BVECTOR_TYPE(DgnPlatform::GeoreferencePriority, GeoreferencePriorityVector);

DEFINE_BVECTOR_TYPE(DgnECInstancePtr, DgnECInstanceVector);
