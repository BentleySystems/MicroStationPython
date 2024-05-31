/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msbitmask.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msbitmask.fdf>



static const char * __doc_MstnPlatform_BitMask_Dump =R"doc(@Description Dump specified bit-mask data into specified file

Parameter ``pFileNameIn``:
    IN file name to dump into

Parameter ``pBitMaskIn``:
    IN bit mask array

Returns:
    SUCCESS

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_GetNumBitsSet =R"doc(@Description Get the number of bits set to 1 in the bit mask.

Parameter ``pBitMaskIn``:
    IN bit-mask for which to get number valid bits

Returns:
    The number of bits set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_GetNumValidBits =R"doc(@Description Get the number of valid bits in the bit mask.

Parameter ``pBitMaskIn``:
    IN bit-mask for which to get number valid bits

Returns:
    the number of valid bits.

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_AnyBitSet =R"doc(@Description Check if specified bit-mask has any bit set to true

Parameter ``pBitMaskIn``:
    IN bit mask array

Returns:
    true if any bit is set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_TestBitMask =R"doc(@Description Check if two specified bit-masks have any bits which have
the same value

Parameter ``pBitMask1In``:
    IN first bit mask

Parameter ``pBitMask2In``:
    IN second bit mask

Returns:
    true if the bit-masks have any bit in common

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_TestBit =R"doc(@Description Check if specified bit of bit-mask is set to true

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``bitPositionIn``:
    IN bit position to test

Returns:
    true if the bit at specified position is ON (true), false if not

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_Equal =R"doc(@Description Check if two specified bit-masks are equal

Parameter ``pBitMask1In``:
    IN first bit mask

Parameter ``pBitMask2In``:
    IN second bit mask

Returns:
    true if the bit-masks are equal, false if not

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_GetHighestBit =R"doc(@Description Get the position of the highest possible bit in specified
bit-mask that can be set without expanding the bit-mask

Parameter ``pHighestPositionOut``:
    OUT highest bit position possible without requiring an expansion

Parameter ``pBitMaskIn``:
    IN bit-mask array

Returns:
    ERROR if the highest bit cannot be got

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_InvertAll =R"doc(@Description Invert value of all bits in specified bit-mask

Parameter ``pBitMaskIn``:
    IN bit-mask array

Returns:
    ERROR if the bits cannot be inverted

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_InvertBit =R"doc(@Description Invert value of specified bit in specified bit-mask

Parameter ``pBitMaskIn``:
    IN bit-mask array

Parameter ``bitIndexIn``:
    IN bit index to invert

Returns:
    ERROR if the specified bit cannot be inverted

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetAll =R"doc(@Description Set all bits in specified bit-mask to either true or
false

Parameter ``pBitMaskIn``:
    IN bit-mask array

Parameter ``bitFlagIn``:
    IN bit flag, if false then set all bits off, else set all bits ON

Returns:
    ERROR if the bits cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_LogicalOperation =R"doc(@Description Apply " pBitMask " on " pBitMaskOut " using specified logical
operation. The logical operation may be BitMaskOperation::And,
BitMaskOperation::Or, BitMaskOperation::Xor, BitMaskOperation::OrNot,
BitMaskOperation::AndNot.

Parameter ``pBitMaskOut``:
    OUT destination bit-mask array and first operand

Parameter ``pBitMaskIn``:
    IN second operand

Parameter ``operation``:
    IN operation code (see above)

Returns:
    ERROR if the bits from specified string cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_GetAsString =R"doc(@Description Get a string which represents the bit-mask. The string
will a ", " delimited set of bit indices which are set to ON. Ranges of
ON bit-indices will be returned in a range form (such as n1-n2). An
example return string:1,10-15,20,31-35

Parameter ``pStringOut``:
    OUT pre-allocated string in which the bit-mask will be outputted

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``indexOriginIn``:
    IN index corresponding to lowest order bit (1 or 0)

Returns:
    ERROR if the bits from specified string cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetFromString =R"doc(@Description Set bit-mask from specified string. Set bit-mask from a
set of " " or ", " delimited in a string. The string may contain ranges
too. e.g. string:1,10-15,3,20,25-28,31-35 If the largest bit-position
implied in the specified string is larger than the bit-mask size, then
the bit-mask will expand to fit-in the largest bit-position.
" maxIndexIn " is used if you have/want a bitmask of a predetermined
size & do not want its size to exceed the specified value.
" maxIndexIn " can be set to -1, in which case the argument is ignored.

Parameter ``pBitMaskOut``:
    OUT bit mask array

Parameter ``pSourceStringIn``:
    IN source string from which to parse the bit-mask information

Parameter ``indexOriginIn``:
    IN index corresponding to lowest order bit (1 or 0)

Parameter ``maxIndexIn``:
    IN maximum index to set

Returns:
    ERROR if the bits from specified string cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetFromBitMask =R"doc(@Description Set bit-mask from specified source bit-mask. The
resultant bit-mask will be of the same size as the specified source
bit-mask. The default value of the resultant bit-mask will be set to
be the same as that of the source bit-mask.

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``pSourceBitMaskIn``:
    IN source bit mask array

Returns:
    ERROR if the bits from specified bit-mask cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetFromBitArray =R"doc(@Description Set bit-mask from specified bit-array. The resultant bit-
mask will be of the same size as the specified bit-array.

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``numValidBitsIn``:
    IN number of bits that are valid in pBitArrayIn

Parameter ``pBitArrayIn``:
    IN bit array as an array of short-words

Returns:
    ERROR if the bit from bit-array cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetBitAtPositions =R"doc(@Description Set bit at specified array-position (bitIndexIn / 16) &
bit-position in array (bitIndexIn % 16)

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``arrayPositionIn``:
    IN internal array position of bit index

Parameter ``bitPositionIn``:
    IN internal bit position of bit index

Parameter ``bitFlagIn``:
    IN bit value to set

Returns:
    ERROR if the bit at specified position cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetBits =R"doc(@Description Set the value of an array of specified bit-positions in
bit-mask. If any of the specified bit-positions are outside the size
of the bit-mask, then this function will expand the size of the input
bit-mask to fit-in for the maximum possible bit-position.

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``numBitInArray``:
    IN number of bits in array

Parameter ``pBitIndexArrayIn``:
    IN bit index array

Parameter ``bitFlagIn``:
    IN bit flag, if true then bit as on, else as off

Returns:
    ERROR if the bits at specified positions cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetBit =R"doc(@Description Set value at specified bit-position in bit-mask. If the
specified bit-position is outside the size of the bit-mask, then this
function will expand the size of the input bit-mask to fit in the bit-
position.

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``bitIndexIn``:
    IN bit index to set

Parameter ``bitFlagIn``:
    IN bit flag, if true then bit as on, else as off

Returns:
    ERROR if the bit at specified position cannot be set

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_GetBit =R"doc(@Description Get value at specified bit-position in bit-mask.

Parameter ``pBitFlagOut``:
    OUT bit flag, true then bit is on, else false

Parameter ``pBitMaskIn``:
    IN bit mask array

Parameter ``bitIndexIn``:
    IN bit index to get

Returns:
    ERROR if the bit-position is outside the size of bit-mask

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_GetDefaultBitValue =R"doc(@Description Get the default value for bits beyond the allocated
number of bits in the bit mask.

Parameter ``pBitMaskIn``:
    IN bit-mask for which to get defaultBitValue

Returns:
    the default bit value for pBitMaskIn

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_SetDefaultBitValue =R"doc(@Description Set the default value for bits beyond the allocated
number of bits in the bit mask.

Parameter ``pBitMaskIn``:
    IN bit-mask for which to set defaultBitValue

Parameter ``defaultBitValueIn``:
    IN the default value for bits in the mask.

Returns:
    ERROR if pBitMaskIn is NULL

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_EnsureCapacity =R"doc(@Description Ensure that if the specified bit-mask can carry the
specified number of bits. This function will only expand the specified
the bit-mask to specified number of bits (conversely, will never
contract the specified bit-mask)

Parameter ``pBitMaskIn``:
    IN bit-mask

Parameter ``numBitIn``:
    IN number of bits to ensure

Returns:
    ERROR if the bit-mask structure cannot be expanded.

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_Free =R"doc(@Description Free specified bit-mask & all its internal memory

Parameter ``ppBitMaskIn``:
    IN bit-mask structure to free

Returns:
    ERROR if the bit-mask structure cannot be freed

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_CreateFromBitArray =R"doc(@Description Create a new bit-mask structure - initializes itself from
input bit-array. Note:This function copies the input bit-array.

Parameter ``ppBitMaskOut``:
    OUT new bit-mask structure

Parameter ``numValidBitsIn``:
    IN number of bits that are valid in pBitArrayIn

Parameter ``pBitArrayIn``:
    IN bit array as an array of short-words

Parameter ``defaultBitValueIn``:
    IN the default value for bits in the mask.

Returns:
    ERROR if the bit-mask structure cannot be created

Remark:
    )doc";

static const char * __doc_MstnPlatform_BitMask_Clone =R"doc(@Description Clone the specified BitMask.

Parameter ``pBitMask``:
    IN the BitMask to copy

Returns:
    a deep copy of the BitMask or NULL if there was an error

Remark:
    )doc";



BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct BitMask {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msbitmask(py::module_& m)
    {

    py::class_<Bentley::MstnPlatform::MSPython::BitMask> c1(m, "BitMask"); 

    c1.def_static("Create", [] (bool defaultBitValue)
          {
          BitMaskP bitMask = nullptr;
          auto retVal = mdlBitMask_create(&bitMask, defaultBitValue);
          return py::make_tuple(retVal, py::cast(bitMask, py::return_value_policy::take_ownership));
          }, "defaultBitValue");

    c1.def_static("Clone", &mdlBitMask_clone, "bitMask"_a, py::return_value_policy::take_ownership, DOC(MstnPlatform, BitMask, Clone));

    c1.def_static("CreateFromBitArray", [] (bvector<UInt16> const& bitArray, bool defaultBitValue)
          {
          BitMaskP bitMask = nullptr;
          auto retVal = mdlBitMask_createFromBitArray(&bitMask, (UInt32) bitArray.size(), bitArray.data(), defaultBitValue);
          return py::make_tuple(retVal, py::cast(bitMask, py::return_value_policy::take_ownership));
          }, "bitArray"_a, "defaultBitValue"_a, DOC(MstnPlatform, BitMask, CreateFromBitArray));

    c1.def_static("Free", [] (BitMaskP bitMask)
          {
          BitMaskP bitMask_ {bitMask};
          return mdlBitMask_free(&bitMask_);
          }, "bitMask"_a, DOC(MstnPlatform, BitMask, Free));

    c1.def_static("EnsureCapacity", &mdlBitMask_ensureCapacity, "bitMask"_a, "numBit"_a, DOC(MstnPlatform, BitMask, EnsureCapacity));
    c1.def_static("SetDefaultBitValue", &mdlBitMask_setDefaultBitValue, "bitMask"_a, "defaultBitValue"_a, DOC(MstnPlatform, BitMask, SetDefaultBitValue));
    c1.def_static("GetDefaultBitValue", &mdlBitMask_getDefaultBitValue, "bitMask"_a, DOC(MstnPlatform, BitMask, GetDefaultBitValue));

    c1.def_static("GetBit", [] (BitMaskCP bitMask, UInt32 bitIndex)
          {
          bool bitFlag = false;
          auto retVal = mdlBitMask_getBit(&bitFlag, bitMask, bitIndex);
          return py::make_tuple(retVal, bitFlag);
          }, "bitMask"_a, "bitIndex"_a, DOC(MstnPlatform, BitMask, GetBit));

    c1.def_static("SetBit", &mdlBitMask_setBit, "bitMask"_a, "bitIndex"_a, "bitFlag"_a, DOC(MstnPlatform, BitMask, SetBit));

    c1.def_static("SetBits", [] (BitMaskP bitMask, bvector<UInt32> const& bitIndexArray, bool bitFlag)
          {
          return mdlBitMask_setBits(bitMask, (UInt32) bitIndexArray.size(), bitIndexArray.data(), bitFlag);
          }, "bitMask"_a, "bitIndexArray"_a, "bitFlag"_a, DOC(MstnPlatform, BitMask, SetBits));

    c1.def_static("SetBitAtPositions", &mdlBitMask_setBitAtPositions, "bitMask"_a, "arrayPosition"_a, "bitPosition"_a, "bitFlag"_a, DOC(MstnPlatform, BitMask, SetBitAtPositions));

    c1.def_static("SetFromBitArray", [] (BitMaskP bitMask, bvector<UInt16> const& bitArray)
          {
          return mdlBitMask_setFromBitArray(bitMask, (UInt32) bitArray.size(), bitArray.data());
          }, "bitMask"_a, "bitArray"_a, DOC(MstnPlatform, BitMask, SetFromBitArray));

    c1.def_static("SetFromBitMask", &mdlBitMask_setFromBitMask, "bitMask"_a, "sourceBitMask"_a, DOC(MstnPlatform, BitMask, SetFromBitMask));
    c1.def_static("SetFromString", &mdlBitMask_setFromString, "bitMask"_a, "sourceString"_a, "indexOrigin"_a, "maxIndex"_a, DOC(MstnPlatform, BitMask, SetFromString));
    c1.def_static("GetAsString", &mdlBitMask_getAsString, "stringOut"_a, "bitMask"_a, "indexOrigin"_a, DOC(MstnPlatform, BitMask, GetAsString));
    c1.def_static("LogicalOperation", &mdlBitMask_logicalOperation, "bitMaskOut"_a, "bitMaskIn"_a, "operation"_a, DOC(MstnPlatform, BitMask, LogicalOperation));
    c1.def_static("SetAll", &mdlBitMask_setAll, "bitMask"_a, "bitFlag"_a, DOC(MstnPlatform, BitMask, SetAll));
    c1.def_static("InvertBit", &mdlBitMask_invertBit, "bitMask"_a, "bitIndex"_a, DOC(MstnPlatform, BitMask, InvertBit));
    c1.def_static("InvertAll", &mdlBitMask_invertAll, "bitMask"_a, DOC(MstnPlatform, BitMask, InvertAll));

    c1.def_static("GetHighestBit", [] (BitMaskCP bitMask)
          {
          UInt pHighestPositionOut = -1;
          auto retVal = mdlBitMask_getHighestBit(&pHighestPositionOut, bitMask);
          return py::make_tuple(retVal, pHighestPositionOut);
          }, "bitMask"_a, DOC(MstnPlatform, BitMask, GetHighestBit));

    c1.def_static("Equal", &mdlBitMask_equal, "bitMask1"_a, "bitMask2"_a, DOC(MstnPlatform, BitMask, Equal));
    c1.def_static("TestBit", &mdlBitMask_testBit, "bitMask"_a, "bitPosition"_a, DOC(MstnPlatform, BitMask, TestBit));
    c1.def_static("TestBitMask", &mdlBitMask_testBitMask, "bitMask1"_a, "bitMask2"_a, DOC(MstnPlatform, BitMask, TestBitMask));
    c1.def_static("AnyBitSet", &mdlBitMask_anyBitSet, "bitMask"_a, DOC(MstnPlatform, BitMask, AnyBitSet));
    c1.def_static("GetNumValidBits", &mdlBitMask_getNumValidBits, "bitMask"_a, DOC(MstnPlatform, BitMask, GetNumValidBits));
    c1.def_static("GetNumBitsSet", &mdlBitMask_getNumBitsSet, "bitMask"_a, DOC(MstnPlatform, BitMask, GetNumBitsSet));
    c1.def_static("Dump", &mdlBitMask_dump, "fileName"_a, "bitMask"_a, DOC(MstnPlatform, BitMask, Dump));    
    }