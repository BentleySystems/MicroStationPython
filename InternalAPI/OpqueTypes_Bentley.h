/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\OpqueTypes_Bentley.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once

#include "MSPyCommon.h"

// Commonly used bvectors
DEFINE_BVECTOR_TYPE(int8_t, Int8Array);
DEFINE_BVECTOR_TYPE(uint8_t, UInt8Array);
DEFINE_BVECTOR_TYPE(int16_t, Int16Array);
DEFINE_BVECTOR_TYPE(uint16_t, UInt16Array);
DEFINE_BVECTOR_TYPE(int32_t, Int32Array);
DEFINE_BVECTOR_TYPE(uint32_t, UInt32Array);
DEFINE_BVECTOR_TYPE(int64_t, Int64Array);
DEFINE_BVECTOR_TYPE(Int64Array, Int64VecArray);
DEFINE_BVECTOR_TYPE(uint64_t, UInt64Array);
DEFINE_BVECTOR_TYPE(UInt64Array, UInt64VecArray);
DEFINE_BVECTOR_TYPE(float, FloatArray);
DEFINE_BVECTOR_TYPE(double, DoubleArray);
DEFINE_BVECTOR_TYPE(bool, BoolArray);
DEFINE_BVECTOR_TYPE(AString, AStringArray);
DEFINE_BVECTOR_TYPE(WString, WStringArray);
DEFINE_BVECTOR_TYPE(Utf8String, Utf8StringArray);

// Commonly used bmap
DEFINE_BMAP_TYPE(WString, WString, WStringWStringMap);
DEFINE_BMAP_TYPE(WString, WCharCP, WStringWCharMap);
DEFINE_BMAP_TYPE(int, int, IntIntMap);
