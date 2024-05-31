/*--------------------------------------------------------------------------------------+
|
|  $Source: Tests/Published/DgnHandlers/ECTestHelpers.h $
|
|  $Copyright: (c) 2015 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once

#include <ECObjects/ECObjectsAPI.h>
#include <DgnPlatform/DgnECManager.h>

#define EXPECT_TRUE(statement) assert (statement);
#define EXPECT_NOT_NULL(statement)  EXPECT_TRUE (NULL != (statement))
#define EXPECT_NULL(statement)      EXPECT_TRUE (NULL == (statement))
#define EXPECT_SUCCESS(statement)   EXPECT_TRUE (SUCCESS == (statement))
#define EXPECT_ERROR(statement)     EXPECT_TRUE (SUCCESS != (statement))

USING_NAMESPACE_EC
using namespace std;


/*---------------------------------------------------------------------------------**//**
* @bsistruct                                                    Paul.Connelly   06/15
+---------------+---------------+---------------+---------------+---------------+------*/
struct ECTestHelpers
    {
public:
    // Return the number of DgnECInstances contained in the iterable
    static size_t CountInstances (DgnECInstanceIterableCR instances)
        {
        size_t count = 0;
        auto end = instances.end();
        for (auto iter = instances.begin(); iter != end; ++iter)
            ++count;

        return count;
        }

    static DgnECInstancePtr FindInstance (FindInstancesScopeR scope, ECQueryCR query)
        {
        DgnECInstancePtr foundInstance;
        for (auto const& instance : DgnECManager::GetManager().FindInstances (scope, query))
            {
            EXPECT_NULL (foundInstance.get());
            foundInstance = instance;
            }

        return foundInstance;
        }

    // Obtain the specified property value from the IECInstance. Pass -1 as the array index if it's not an array member
    static ECObjectsStatus GetValue (ECValueR v, DgnECInstanceCR instance, WCharCP accessString, int arrayIndex = -1)
        {
        uint32_t uArrayIndex = arrayIndex;
        return -1 == uArrayIndex ? instance.GetValue (v, accessString) : instance.GetValue (v, accessString, uArrayIndex);
        }

    // Set the specified property value to the IECInstance. Pass -1 as the array index if it's not an array member
    static ECObjectsStatus SetValue (ECValueCR v, DgnECInstanceR instance, WCharCP accessString, int arrayIndex = -1)
        {
        uint32_t uArrayIndex = arrayIndex;
        return -1 == uArrayIndex ? instance.SetValue (accessString, v) : instance.SetValue (accessString, v, uArrayIndex);
        }

    // Compare two primitive or null ECValues
    static bool ValuesAreEqual (ECValueCR a, ECValueCR b)
        {
        if (a.IsNull() || b.IsNull())
            return a.IsNull() == b.IsNull();
        else if (!a.IsPrimitive() || !b.IsPrimitive() || a.GetPrimitiveType() != b.GetPrimitiveType())
            return false;
        else if (a.IsDouble())
            return DoubleOps::AlmostEqual (a.GetDouble(), b.GetDouble());
        else if (a.IsPoint2D())
            {
            auto pa = a.GetPoint2D(), pb = b.GetPoint2D();
            return DoubleOps::AlmostEqual (pa.x, pb.x) && DoubleOps::AlmostEqual (pa.y, pb.y);
            }
        else if (a.IsPoint3D())
            {
            auto pa = a.GetPoint3D(), pb = b.GetPoint3D();
            return DoubleOps::AlmostEqual (pa.x, pb.x) && DoubleOps::AlmostEqual (pa.y, pb.y) && DoubleOps::AlmostEqual (pa.z, pb.z);
            }
        else
            return a.Equals (b);
        }

    // Return true if specified property expected value
    static bool InstanceHasValue (DgnECInstanceCR instance, ECValueCR expectedValue, WCharCP accessString, int arrayIndex = -1)
        {
        uint32_t uArrayIndex = arrayIndex;
        ECValue actualValue;
        return ECOBJECTS_STATUS_Success == GetValue (actualValue, instance, accessString, uArrayIndex) && ValuesAreEqual (actualValue, expectedValue);
        }
    };

