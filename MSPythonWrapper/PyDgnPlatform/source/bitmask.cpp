/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\bitmask.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Tools/BitMask.h>



static const char * __doc_Bentley_DgnPlatform_BitMask_ToString =R"doc(Create a string representing the contents of this BitMask.

Parameter ``outString``:
    The string that is filled in.

Parameter ``indexOrigin``:
    If asString true, this indicates the index value of the lowest
    bit. Must be 0 or 1.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_LogicalOperation =R"doc(Sets this BitMask to the logical operation specified between this
BitMask and the argument.

Parameter ``rhs``:
    The right hand operand of the And operation.

Parameter ``operation``:
    The operation to perform. @note If necessary, the capacity of this
    BitMask is increased.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_AnyBitSet =R"doc(Returns true if any bit in this BitMask is true.

Returns:
    true if any bit is true. @note This tests bits up to the Capacity
    of the BitMask. If Capacity is 0, it returns the DefaultBitValue.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_GetNumBitsSet =R"doc(The count of bits that are true in this BitMask.

Returns:
    The number of true bits.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetFromString =R"doc(Sets this BitMask from a string containing the bits that are true.

Parameter ``sourceString``:
    The string containing integers that are the bits to set to true.
    It is of the form n,m,...p-q,r-s

Parameter ``indexOrigin``:
    Either 0 or 1. The value is subtracted from each integer specified
    in sourceString.

Parameter ``maxIndex``:
    The maximum value that is allowed in sourceString.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetFromBitArray =R"doc(Sets this BitMask from source data.

Parameter ``numValidBits``:
    The number of valid bits in the input bitArray

Parameter ``bitArray``:
    An array of at least (numValidBits+15)%16 UInt16's that contain
    the values. @note If necessary, the capacity of this BitMask is
    increased.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetFromBitMask =R"doc(Copies the contents of the given BitMask to this BitMask.

Parameter ``source``:
    The BitMask to copy the contents of.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetBits =R"doc(Sets the bits specified to the value specified.

Parameter ``arraySize``:
    The number of entries in bitIndexArray.

Parameter ``bitIndexArray``:
    An array of bit indexes.

Parameter ``value``:
    The value to set. @note If necessary, the capacity of this BitMask
    is increased.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_OrNot =R"doc(Sets this BitMask to the logical Or of this Bitmask and the inverse
the argument.

Parameter ``rhs``:
    The right hand operand of the OrNot operation. @note If necessary,
    the capacity of this BitMask is increased to that of rhs.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_AndNot =R"doc(Sets this BitMask to the logical And this Bitmask and the insverse of
the argument.

Parameter ``rhs``:
    The right hand operand of the AndNot operation. @note If
    necessary, the capacity of this BitMask is increased to that of
    rhs.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_XOr =R"doc(Sets this BitMask to the logical Xor of this Bitmask and the argument.

Parameter ``rhs``:
    The right hand operand of the XOr operation. @note If necessary,
    the capacity of this BitMask is increased to that of rhs.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_And =R"doc(Sets this BitMask to the logical And of this Bitmask and the argument.

Parameter ``rhs``:
    The right hand operand of the And operation. @note If necessary,
    the capacity of this BitMask is increased to that of rhs.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_Or =R"doc(Sets this BitMask to the logical Or of this Bitmask and the argument.

Parameter ``rhs``:
    The right hand operand of the Or operation. @note If necessary,
    the capacity of this BitMask is increased to that of rhs.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_InvertAll =R"doc(Inverts all bits of this BitMask.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_Invert =R"doc(Inverts the specified bit of this BitMask.

Parameter ``bitIndex``:
    The bit to set to invert.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_ClearAll =R"doc(Sets all bits of this BitMask to false.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetAll =R"doc(Sets all bits of this BitMask to true.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetBit =R"doc(Sets a bit of this BitMask to the specified value.

Parameter ``bitIndex``:
    The bit to set.

Parameter ``value``:
    The value to set.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_Test =R"doc(Tests a bit of this BitMask.

Parameter ``bitIndex``:
    The bit to test.

Returns:
    The value of the bit.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetDefaultBitValue =R"doc(Sets this BitMask's default bit value.

Parameter ``value``:
    The default bit value.

See also:
    GetDefaultBitValue.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_GetDefaultBitValue =R"doc(Gets this BitMask's default bit value.

Returns:
    The value of the default bit.

See also:
    SetDefaultBitValue.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_EnsureCapacity =R"doc(Sets this BitMask's capacity to at least the value specified.

Parameter ``numBits``:
    The number of bits required. @note If the current capacity is
    greater than or equal to numBits, the call does nothing. <br>If
    the current capacity is less than numBits, the newly added bits
    are set to the default value.

See also:
    SetCapacity, GetCapacity.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_SetCapacity =R"doc(Sets this BitMasks' capacity to exactly the value specified.

Parameter ``numBits``:
    The number of bits required. @note If the current capacity is less
    than numBits, the newly added bits are set to the default value.

See also:
    EnsureCapacity, GetCapacity.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_GetCapacity =R"doc(Gets the capacity of this BitMask.

Returns:
    The capacity of this BitMask.

See also:
    EnsureCapacity, SetCapacity)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_Free =R"doc(Frees this BitMask)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_FreeAndClear =R"doc(Convenience method to Free a BitMask.

Parameter ``bitMask``:
    A pointer to a BitMask that is is to be freed. The pointer can
    point to a NULL value. The value of the pointer is set to zero
    after the BitMask is freed.)doc";

static const char * __doc_Bentley_DgnPlatform_BitMask_Clone =R"doc(Creates a new BitMask instance from an existing BitMask.

Parameter ``source``:
    The BitMask that is copied.

Returns:
    The copied BitMask. @note The caller is responsible for freeing
    the BitMask using the #Free method.

See also:
    SetFromBitMask.)doc";

// BitMask deleter for std::unique_ptr
struct BitMask_Deleter { void operator()(BitMask *mask) { if (nullptr != mask) mask->Free(); } };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BitMask(py::module_& m)
    {
    //===================================================================================
    // enum class BitMaskOperation
    py::enum_< BitMaskOperation>(m, "BitMaskOperation")
        .value("eOr", BitMaskOperation::Or)
        .value("eAnd", BitMaskOperation::And)
        .value("eXor", BitMaskOperation::Xor)
        .value("eOrNot", BitMaskOperation::OrNot)
        .value("eAndNot", BitMaskOperation::AndNot)
        .export_values();

    //===================================================================================
    // struct BitMask
    py::class_< BitMask, std::unique_ptr<BitMask, BitMask_Deleter> > c1(m, "BitMask");

    c1.def(py::init(&BitMask::Create), "defaultBitValue"_a);
    c1.def_static("Clone", &BitMask::Clone, "source"_a, DOC(Bentley, DgnPlatform, BitMask, Clone));
    
    c1.def_static("FreeAndClear", [] (BitMaskP bitMask)
                  {
                  BitMaskP bitMask_ {bitMask};
                  BitMask::FreeAndClear(&bitMask_);
                  }, "bitMask"_a, DOC(Bentley, DgnPlatform, BitMask, FreeAndClear));

    c1.def("Free", &BitMask::Free, DOC(Bentley, DgnPlatform, BitMask, Free));

    c1.def_property("Capacity", &BitMask::GetCapacity, &BitMask::SetCapacity);
    c1.def("GetCapacity", &BitMask::GetCapacity, DOC(Bentley, DgnPlatform, BitMask, GetCapacity));
    c1.def("SetCapacity", &BitMask::SetCapacity, "numBits"_a, DOC(Bentley, DgnPlatform, BitMask, SetCapacity));

    c1.def("EnsureCapacity", &BitMask::EnsureCapacity, "numBits"_a, DOC(Bentley, DgnPlatform, BitMask, EnsureCapacity));

    c1.def_property("DefaultBitValue", &BitMask::GetDefaultBitValue, &BitMask::SetDefaultBitValue);
    c1.def("GetDefaultBitValue", &BitMask::GetDefaultBitValue, DOC(Bentley, DgnPlatform, BitMask, GetDefaultBitValue));
    c1.def("SetDefaultBitValue", &BitMask::SetDefaultBitValue, "value"_a, DOC(Bentley, DgnPlatform, BitMask, SetDefaultBitValue));
    
    c1.def("Test", py::overload_cast<UInt32>(&BitMask::Test, py::const_), "bitIndex"_a, DOC(Bentley, DgnPlatform, BitMask, Test));
    c1.def("Test", py::overload_cast<BitMaskCR>(&BitMask::Test, py::const_), "testMask"_a, DOC(Bentley, DgnPlatform, BitMask, Test));
    c1.def("SetBit", &BitMask::SetBit, "bitIndex"_a, "value"_a, DOC(Bentley, DgnPlatform, BitMask, SetBit));
    c1.def("SetAll", py::overload_cast<>(&BitMask::SetAll), DOC(Bentley, DgnPlatform, BitMask, SetAll));
    c1.def("Clear", &BitMask::Clear, "bitIndex"_a);
    c1.def("ClearAll", &BitMask::ClearAll, DOC(Bentley, DgnPlatform, BitMask, ClearAll));
    c1.def("Invert", &BitMask::Invert, "bitIndex"_a, DOC(Bentley, DgnPlatform, BitMask, Invert));
    c1.def("InvertAll", &BitMask::InvertAll, DOC(Bentley, DgnPlatform, BitMask, InvertAll));
    c1.def("Or", &BitMask::Or, "rhs"_a, DOC(Bentley, DgnPlatform, BitMask, Or));
    c1.def("And", &BitMask::And, "rhs"_a, DOC(Bentley, DgnPlatform, BitMask, And));
    c1.def("XOr", &BitMask::XOr, "rhs"_a, DOC(Bentley, DgnPlatform, BitMask, XOr));
    c1.def("AndNot", &BitMask::AndNot, "rhs"_a, DOC(Bentley, DgnPlatform, BitMask, AndNot));
    c1.def("OrNot", &BitMask::OrNot, "rhs"_a, DOC(Bentley, DgnPlatform, BitMask, OrNot));

    c1.def("SetBits", [] (BitMask& self, UInt32Array const& bitIndexArray, bool value)
           {
           return self.SetBits((UInt32) bitIndexArray.size(), bitIndexArray.data(), value);
           }, "bitIndexArray"_a, "value"_a, DOC(Bentley, DgnPlatform, BitMask, SetBits));

    c1.def("SetFromBitMask", &BitMask::SetFromBitMask, "source"_a, DOC(Bentley, DgnPlatform, BitMask, SetFromBitMask));
    c1.def("SetFromBitArray", [] (BitMask& self, UInt16Array const& bitArray)
           {
           return self.SetFromBitArray((UInt32) bitArray.size(), bitArray.data());
           }, "bitArray"_a, DOC(Bentley, DgnPlatform, BitMask, SetFromBitArray));

    c1.def("SetFromString", &BitMask::SetFromString, "sourceString"_a, "indexOrigin"_a, "maxIndex"_a, DOC(Bentley, DgnPlatform, BitMask, SetFromString));
    c1.def("GetNumBitsSet", &BitMask::GetNumBitsSet, DOC(Bentley, DgnPlatform, BitMask, GetNumBitsSet));
    c1.def("__eq__", [] (BitMaskCR self, BitMaskCP other) { return self.IsEqual(other); });
    c1.def("AnyBitSet", &BitMask::AnyBitSet, DOC(Bentley, DgnPlatform, BitMask, AnyBitSet));
    c1.def("LogicalOperation", &BitMask::LogicalOperation, "rhs"_a, "operation"_a, DOC(Bentley, DgnPlatform, BitMask, LogicalOperation));
    c1.def("ToString", &BitMask::ToString, "outString"_a, "indexOrigin"_a, DOC(Bentley, DgnPlatform, BitMask, ToString));
    }
