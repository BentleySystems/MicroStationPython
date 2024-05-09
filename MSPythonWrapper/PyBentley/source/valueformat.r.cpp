/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\valueformat.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/ValueFormat.r.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ValueFormat_r(py::module_& m)
    {
    //===================================================================================
    // enum class PrecisionType
    py::enum_< PrecisionType>(m, "PrecisionType")
        .value("eDecimal", PrecisionType::Decimal)
        .value("eFractional", PrecisionType::Fractional)
        .value("eScientific", PrecisionType::Scientific)
        .export_values();

    //===================================================================================
    // enum class PrecisionFormat
    py::enum_< PrecisionFormat>(m, "PrecisionFormat")
        .value("eDecimalWhole", PrecisionFormat::DecimalWhole)
        .value("eDecimal1Place", PrecisionFormat::Decimal1Place)
        .value("eDecimal2Places", PrecisionFormat::Decimal2Places)
        .value("eDecimal3Places", PrecisionFormat::Decimal3Places)
        .value("eDecimal4Places", PrecisionFormat::Decimal4Places)
        .value("eDecimal5Places", PrecisionFormat::Decimal5Places)
        .value("eDecimal6Places", PrecisionFormat::Decimal6Places)
        .value("eDecimal7Places", PrecisionFormat::Decimal7Places)
        .value("eDecimal8Places", PrecisionFormat::Decimal8Places)
        .value("eFractionalWhole", PrecisionFormat::FractionalWhole)
        .value("eFractionalHalf", PrecisionFormat::FractionalHalf)
        .value("eFractionalQuarter", PrecisionFormat::FractionalQuarter)
        .value("eFractionalEighth", PrecisionFormat::FractionalEighth)
        .value("eFractionalSixteenth", PrecisionFormat::FractionalSixteenth)
        .value("eFractional1_Over_32", PrecisionFormat::Fractional1_Over_32)
        .value("eFractional1_Over_64", PrecisionFormat::Fractional1_Over_64)
        .value("eFractional1_Over_128", PrecisionFormat::Fractional1_Over_128)
        .value("eFractional1_Over_256", PrecisionFormat::Fractional1_Over_256)
        .value("eScientificWhole", PrecisionFormat::ScientificWhole)
        .value("eScientific1Place", PrecisionFormat::Scientific1Place)
        .value("eScientific2Places", PrecisionFormat::Scientific2Places)
        .value("eScientific3Places", PrecisionFormat::Scientific3Places)
        .value("eScientific4Places", PrecisionFormat::Scientific4Places)
        .value("eScientific5Places", PrecisionFormat::Scientific5Places)
        .value("eScientific6Places", PrecisionFormat::Scientific6Places)
        .value("eScientific7Places", PrecisionFormat::Scientific7Places)
        .value("eScientific8Places", PrecisionFormat::Scientific8Places)
        .export_values();
    }