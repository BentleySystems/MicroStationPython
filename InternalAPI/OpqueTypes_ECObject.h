/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\OpqueTypes_ECObject.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once

#include "OpqueTypes_DgnPlatform.h"

DEFINE_BVECTOR_TYPE(ECSchemaPtr, ECSchemaPtrArray);
DEFINE_BVECTOR_TYPE(ECN::ECSchemaP, ECSchemaPArray);
DEFINE_BVECTOR_TYPE(ECN::ECSchemaCP, ECSchemaCPArray);
DEFINE_BMAP_TYPE_COMPARE(SchemaKey, ECSchemaPtr, SchemaKeyLessThan<SCHEMAMATCHTYPE_Exact>, KeySchemaMap);
