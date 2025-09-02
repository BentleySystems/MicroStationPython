/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\valueformat.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ValueFormat.h>



static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_ToString =R"doc(Format the time point value. If no components have been added to the
formatting sequence, uses DATETIME_PART_General.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_Clone =R"doc(Construct a copy of this DateTimeFormatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_Create =R"doc(Construct a new DateTimeFormatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_Reset =R"doc(Reset all options to defaults and remove all components from the
formatting sequence.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_ClearFormatParts =R"doc(Remove all components from the formatting sequence.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_AppendFormatPart =R"doc(Add a component to the ordered formatting sequence.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_SetTrailingZeros =R"doc(Set whether trailing zeros should be included when formatting
fractional seconds in order to match the specified precision.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_GetTrailingZeros =R"doc(Get whether trailing zeros are included when formatting fractional
seconds in order to match the specified precision)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_SetFractionalSecondPrecision =R"doc(Set the precision used when formatting fractional seconds.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_GetFractionalSecondPrecision =R"doc(Get the precision used when formatting fractional seconds)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_SetDateSeparator =R"doc(Set the character used to separate date components.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_GetDateSeparator =R"doc(Get the character used to separate date components. Ex:'/' in
" 4 / 5 / 2012 ")doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_SetTimeSeparator =R"doc(Set the character used to separate time components.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_GetTimeSeparator =R"doc(Get the character used to separate time components. Ex:':' in " 4:50 ")doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_SetDecimalSeparator =R"doc(Set the character used as a decimal separator.)doc";

static const char * __doc_Bentley_DgnPlatform_DateTimeFormatter_GetDecimalSeparator =R"doc(Get the character used as a decimal separator.)doc";

static const char * __doc_Bentley_DgnPlatform_VolumeFormatter_ToString =R"doc(Use the settings defined in this formatter to convert a uor value to a
string.

:param uors:
    uor value.)doc";

static const char * __doc_Bentley_DgnPlatform_VolumeFormatter_Clone =R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_VolumeFormatter_Create =R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaFormatter_ToString =R"doc(Use the settings defined in this formatter to convert a uor value to a
string.

:param uors:
    uor value.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaFormatter_Clone =R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaFormatter_Create =R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_SetLabelDecoratorAsSuffix =R"doc(Set the formatter's unit label to m2 or Sq.m. Pass true for m2 and
false for Sq.m.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_GetLabelDecoratorAsSuffix =R"doc(Get the flag which sets unit label to m2 or Sq.m. Returns true for m2
and false for Sq.m.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_SetShowUnitLabel =R"doc(Set the formatter's unit flag.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_GetShowUnitLabel =R"doc(Get the flag which controls the use of unit labels by this formatter.
Ex. " 100 mm ")doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_SetScaleFactor =R"doc(Set the formatter's scale factor.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_GetScaleFactor =R"doc(Get the system scale factor applied by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_SetUorPerStorageUnit =R"doc(Set the formatter's uors per storage.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_GetUorPerStorageUnit =R"doc(Get the uorperstorage value used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_SetStorageUnit =R"doc(Set the formatter's storage unit and uors-per-storage.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_GetStorageUnit =R"doc(Get the Storage UnitFormat used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_SetMasterUnit =R"doc(Set the formatter's working units.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeFormatterBase_GetMasterUnit =R"doc(Get the Master UnitDefinition used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_ToString =R"doc(Use the settings defined in this formatter to convert a point value to
a string.

:param point:
    uor value.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_Clone =R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_Create =R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_SetIs3d =R"doc(Set the formatter's is3d flag.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_GetIs3d =R"doc(Get the is3d value used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_SetAuxCoordSys =R"doc(Set the auxilliary coordinate system used by this formatter. A copy of
the supplied object will be stored by the PointFormatter. To access
the copy, use GetACS.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_GetAuxCoordSys =R"doc(Get the auxilliary coordinate system used by this formatter. Changes
made to this object will affect the future behavior of the
PointFormatter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_SetDistanceFormatter =R"doc(Set the distance formatter used by this formatter for rectangular
coordinates. A copy of the supplied object will be stored by the
PointFormatter. To access the copy, use GetDistanceFormatter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointFormatter_GetDistanceFormatter =R"doc(Get the distance formatter used by this formatter for rectangular
coordinates. Changes made to this object will affect the future
behavior of the PointFormatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_ToString =R"doc(Use the settings defined in this formatter to convert a uor value to a
string.

:param uors:
    uor value.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_Clone =R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_Create =R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetWorkingUnits =R"doc(Set the formatter's working units.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetMinimumResolution =R"doc(Get the displayable resolution of this formatter in uors. This is a
calculated value.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetIsDgnCoordReadOutCapable =R"doc(Set the formatter's IsDgnCoordinateReadoutCapable flag.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetIsDgnCoordReadOutCapable =R"doc(Get the DgnCoorinateReadOutCapable flag used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetSuppressZeroSubUnits =R"doc(Set the formatter's suppress zero sub units flag (only applies if
UnitFormat=DgnUnitFormat::MUSU).)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetSuppressZeroSubUnits =R"doc(Get the suppress zero sub unit flag used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetSuppressZeroMasterUnits =R"doc(Set the formatter's suppress zero master units flag (only applies if
UnitFormat=DgnUnitFormat::MUSU).)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetSuppressZeroMasterUnits =R"doc(Get the suppress zero master unit flag used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetUnitLabelFlag =R"doc(Set the formatter's unit flag.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetUnitLabelFlag =R"doc(Get the unit flag used by this formatter. Ex. " 1 M 0.000 mm ")doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetScaleFactor =R"doc(Set the formatter's scale factor.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetScaleFactor =R"doc(Get the system scale factor applied by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetUorPerStorageUnit =R"doc(Set the formatter's uors per storage.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetUorPerStorageUnit =R"doc(Get the uorperstorage value used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetStorageUnit =R"doc(Set the formatter's storage unit and uors-per-storage.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetStorageUnit =R"doc(Get the Storage UnitFormat used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetSubUnit =R"doc(Get the Sub UnitDefinition used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetMasterUnit =R"doc(Get the Master UnitDefinition used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_SetUnitFormat =R"doc(Set the formatter's UnitFormat.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceFormatter_GetUnitFormat =R"doc(Get the DgnUnitFormat used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_ToStringFromRadians =R"doc(Use the settings defined in this formatter to convert a direction
value to a string.

:param value:
    Direction in radians measured counter clockwise from the positive
    x-axis.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_ToString =R"doc(Use the settings defined in this formatter to convert a direction
value to a string.

:param value:
    Direction in degrees measured counter clockwise from the positive
    x-axis.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_Clone =R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_Create =R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetBearingSpaces =R"doc(Enable or disable additional spaces for bearing directions. Ex. " N 60 E " vs. " N60E ". @Note:Only used when DirectionMode is
DirectionMode::Bearing.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetBearingSpaces =R"doc(Test if bearing directions will use additional spaces. Ex. " N 60 E "
vs. " N60E ". @Note:Only used when DirectionMode is
DirectionMode::Bearing.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetClockwise =R"doc(Set the orientation for azimuth directions. @Note:Only used when
DirectionMode is DirectionMode::Azimuth.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetClockwise =R"doc(Get the orientation for azimuth directions. @Note:Only used when
DirectionMode is DirectionMode::Azimuth. @Return true if directions
are measure clockwise.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetBaseDirection =R"doc(Set the base direction for this formatter. The base direction is
defined as the direction that is formatted as 0.0. @Note:Only used
when DirectionMode is DirectionMode::Azimuth. @Return The base
direction is specified as an angle in degrees measured counter-
clockwise from the positive x-axis. For example, the positive x-axis
is 0.0 and the positive y-axis is 90.0.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetBaseDirection =R"doc(Get the base direction for this formatter. For details see
#SetBaseDirection.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetTrueNorthValue =R"doc(Set the formatter's true north value. If it is enabled, the formatter
will add the true north value to the input value before formatting it.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetTrueNorthValue =R"doc(Get the formatter's true north value. If it is enabled, the formatter
will add the true north value to the input value before formatting it.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetAddTrueNorth =R"doc(Enable or disable the formatter's true north adjustment.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetAddTrueNorth =R"doc(Test if the formatter's true north value will be used.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetDirectionMode =R"doc(Set the DirectionMode used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetDirectionMode =R"doc(Get the DirectionMode used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_SetAngleFormatter =R"doc(Set the angle formatter used by this formatter for the numeric portion
of the direction. A copy of the supplied object will be stored by the
DirectionFormatter. To access the copy, use GetAngleFormatter.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionFormatter_GetAngleFormatter =R"doc(Get the angle formatter used by this formatter for the numeric portion
of the direction. Changes made to this object will affect the future
behavior of the DirectionFormatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_ToStringFromRadians =R"doc(Use the settings defined in this formatter to convert an angle value
to a string.

:param value:
    Angle in radians.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_ToString =R"doc(Use the settings defined in this formatter to convert an angle value
to a string.

:param value:
    Angle in degrees.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_Clone =R"doc(Construct a formatter which is a duplicate of an existing formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_Create =R"doc(Construct a formatter with default settings.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_SetAllowNegative =R"doc(Set the formatter's negative value behavior. If allowed a negative
sign will be included for values less than zero. Ex. " - 30 " vs. " 30 ")doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_GetAllowNegative =R"doc(Test if this formatter will include a negative sign for input values
less than zero. Ex. " - 30 " vs. " 30 ")doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_SetTrailingZeros =R"doc(Set the formatter's trailing zeros behavior. Trailing zeros are only
included up to the requested precision. Ex. " 30.500 " vs. " 30.5 "

:param newVal:
    pass true to zero pad the output string to the requested
    precision.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_GetTrailingZeros =R"doc(Test if this formatter will include trailing zeros. Trailing zeros are
only included up to the requested precision. Ex. " 30.500 " vs. " 30.5 ")doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_SetLeadingZero =R"doc(Set the formatter's leading zero behavior. A leading zero is only
included for values less than 1.0. Ex. " 0.5 " vs. " .5 "

:param newVal:
    pass true to include a leading zero for values less than 1.0)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_GetLeadingZero =R"doc(Test if this formatter will include a leading zero. A leading zero is
only included for values less than 1.0. Ex. " 0.5 " vs. " .5 ")doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_SetDecimalSeparator =R"doc(Set the formatter's decimal separator.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_GetDecimalSeparator =R"doc(Get the decimal separator used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_SetAnglePrecision =R"doc(Change the Precision used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_GetAnglePrecision =R"doc(Get the Precision used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_SetAngleMode =R"doc(Change the AngleMode used by this formatter.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleFormatter_GetAngleMode =R"doc(Get the AngleMode used by this formatter.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ValueFormat(py::module_& m)
    {
    //===================================================================================
    // struct AngleFormatter
    py::class_< AngleFormatter> c1(m, "AngleFormatter");

    c1.def_property("AngleMode", &AngleFormatter::GetAngleMode, &AngleFormatter::SetAngleMode);
    c1.def("GetAngleMode", &AngleFormatter::GetAngleMode, DOC(Bentley, DgnPlatform, AngleFormatter, GetAngleMode));
    c1.def("SetAngleMode", &AngleFormatter::SetAngleMode, "newVal"_a, DOC(Bentley, DgnPlatform, AngleFormatter, SetAngleMode));
    
    c1.def_property("AnglePrecision", &AngleFormatter::GetAnglePrecision, &AngleFormatter::SetAnglePrecision);
    c1.def("GetAnglePrecision", &AngleFormatter::GetAnglePrecision, DOC(Bentley, DgnPlatform, AngleFormatter, GetAnglePrecision));
    c1.def("SetAnglePrecision", &AngleFormatter::SetAnglePrecision, "newVal"_a, DOC(Bentley, DgnPlatform, AngleFormatter, SetAnglePrecision));
    
    c1.def_property("DecimalSeparator", &AngleFormatter::GetDecimalSeparator, &AngleFormatter::SetDecimalSeparator);
    c1.def("GetDecimalSeparator", &AngleFormatter::GetDecimalSeparator, DOC(Bentley, DgnPlatform, AngleFormatter, GetDecimalSeparator));
    c1.def("SetDecimalSeparator", &AngleFormatter::SetDecimalSeparator, "newVal"_a, DOC(Bentley, DgnPlatform, AngleFormatter, SetDecimalSeparator));
    
    c1.def_property("LeadingZero", &AngleFormatter::GetLeadingZero, &AngleFormatter::SetLeadingZero);
    c1.def("GetLeadingZero", &AngleFormatter::GetLeadingZero, DOC(Bentley, DgnPlatform, AngleFormatter, GetLeadingZero));
    c1.def("SetLeadingZero", &AngleFormatter::SetLeadingZero, "newVal"_a, DOC(Bentley, DgnPlatform, AngleFormatter, SetLeadingZero));
    
    c1.def_property("TrailingZeros", &AngleFormatter::GetTrailingZeros, &AngleFormatter::SetTrailingZeros);
    c1.def("GetTrailingZeros", &AngleFormatter::GetTrailingZeros, DOC(Bentley, DgnPlatform, AngleFormatter, GetTrailingZeros));
    c1.def("SetTrailingZeros", &AngleFormatter::SetTrailingZeros, "newVal"_a, DOC(Bentley, DgnPlatform, AngleFormatter, SetTrailingZeros));
    
    c1.def_property("AllowNegative", &AngleFormatter::GetAllowNegative, &AngleFormatter::SetAllowNegative);
    c1.def("GetAllowNegative", &AngleFormatter::GetAllowNegative, DOC(Bentley, DgnPlatform, AngleFormatter, GetAllowNegative));
    c1.def("SetAllowNegative", &AngleFormatter::SetAllowNegative, "newVal"_a, DOC(Bentley, DgnPlatform, AngleFormatter, SetAllowNegative));

    c1.def_static("Create", py::overload_cast<>(&AngleFormatter::Create), DOC(Bentley, DgnPlatform, AngleFormatter, Create));
    c1.def_static("Create", py::overload_cast<DgnModelCR>(&AngleFormatter::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, AngleFormatter, Create));
    c1.def("Clone", &AngleFormatter::Clone, DOC(Bentley, DgnPlatform, AngleFormatter, Clone));
    c1.def("ToString", &AngleFormatter::ToString, "value"_a, DOC(Bentley, DgnPlatform, AngleFormatter, ToString));
    c1.def("ToStringFromRadians", &AngleFormatter::ToStringFromRadians, "value"_a, DOC(Bentley, DgnPlatform, AngleFormatter, ToStringFromRadians));

    c1.def("__repr__", [] (AngleFormatterCR self)
           {
           return "[AngleMode={}, AnglePrecision={}, DecimalSeparator={}, LeadingZero={}, TrailingZeros={}, AllowNegative={}]"_s
               .format(self.GetAngleMode(), 
                       self.GetAnglePrecision(), 
                       self.GetDecimalSeparator(), 
                       self.GetLeadingZero(), 
                       self.GetTrailingZeros(), 
                       self.GetAllowNegative());
           });

    //===================================================================================
    // struct DirectionFormatter
    py::class_< DirectionFormatter> c2(m, "DirectionFormatter");

    c2.def_property("AngleFormatter", &DirectionFormatter::GetAngleFormatter, &DirectionFormatter::SetAngleFormatter);
    c2.def("GetAngleFormatter", &DirectionFormatter::GetAngleFormatter, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DirectionFormatter, GetAngleFormatter));
    c2.def("SetAngleFormatter", &DirectionFormatter::SetAngleFormatter, "formatter"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetAngleFormatter));
    
    c2.def_property("DirectionMode", &DirectionFormatter::GetDirectionMode, &DirectionFormatter::SetDirectionMode);
    c2.def("GetDirectionMode", &DirectionFormatter::GetDirectionMode, DOC(Bentley, DgnPlatform, DirectionFormatter, GetDirectionMode));
    c2.def("SetDirectionMode", &DirectionFormatter::SetDirectionMode, "mode"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetDirectionMode));
    
    c2.def_property("AddTrueNorth", &DirectionFormatter::GetAddTrueNorth, &DirectionFormatter::SetAddTrueNorth);
    c2.def("GetAddTrueNorth", &DirectionFormatter::GetAddTrueNorth, DOC(Bentley, DgnPlatform, DirectionFormatter, GetAddTrueNorth));
    c2.def("SetAddTrueNorth", &DirectionFormatter::SetAddTrueNorth, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetAddTrueNorth));
    
    c2.def_property("TrueNorthValue", &DirectionFormatter::GetTrueNorthValue, &DirectionFormatter::SetTrueNorthValue);
    c2.def("GetTrueNorthValue", &DirectionFormatter::GetTrueNorthValue, DOC(Bentley, DgnPlatform, DirectionFormatter, GetTrueNorthValue));
    c2.def("SetTrueNorthValue", &DirectionFormatter::SetTrueNorthValue, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetTrueNorthValue));
    
    c2.def_property("BaseDirection", &DirectionFormatter::GetBaseDirection, &DirectionFormatter::SetBaseDirection);
    c2.def("GetBaseDirection", &DirectionFormatter::GetBaseDirection, DOC(Bentley, DgnPlatform, DirectionFormatter, GetBaseDirection));
    c2.def("SetBaseDirection", &DirectionFormatter::SetBaseDirection, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetBaseDirection));
    
    c2.def_property("Clockwise", &DirectionFormatter::GetClockwise, &DirectionFormatter::SetClockwise);
    c2.def("GetClockwise", &DirectionFormatter::GetClockwise, DOC(Bentley, DgnPlatform, DirectionFormatter, GetClockwise));
    c2.def("SetClockwise", &DirectionFormatter::SetClockwise, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetClockwise));
    
    c2.def_property("BearingSpaces", &DirectionFormatter::GetBearingSpaces, &DirectionFormatter::SetBearingSpaces);
    c2.def("GetBearingSpaces", &DirectionFormatter::GetBearingSpaces, DOC(Bentley, DgnPlatform, DirectionFormatter, GetBearingSpaces));
    c2.def("SetBearingSpaces", &DirectionFormatter::SetBearingSpaces, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, SetBearingSpaces));

    c2.def_static("Create", py::overload_cast<>(&DirectionFormatter::Create), DOC(Bentley, DgnPlatform, DirectionFormatter, Create));
    c2.def_static("Create", py::overload_cast<DgnModelCR>(&DirectionFormatter::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, Create));
    c2.def("Clone", &DirectionFormatter::Clone, DOC(Bentley, DgnPlatform, DirectionFormatter, Clone));
    c2.def("ToString", &DirectionFormatter::ToString, "value"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, ToString));
    c2.def("ToStringFromRadians", &DirectionFormatter::ToStringFromRadians, "value"_a, DOC(Bentley, DgnPlatform, DirectionFormatter, ToStringFromRadians));

    c2.def("__repr__", [] (DirectionFormatterR self)
           {
           return "[AngleFormatter={}, DirectionMode={}, AddTrueNorth={}, TrueNorthValue={}, BaseDirection={}, Clockwise={}, BearingSpaces={}]"_s
               .format(self.GetAngleFormatter(), 
                       self.GetDirectionMode(), 
                       self.GetAddTrueNorth(), 
                       self.GetTrueNorthValue(), 
                       self.GetBaseDirection(), 
                       self.GetClockwise(), 
                       self.GetBearingSpaces());
           });

    //===================================================================================
    // struct DistanceFormatter
    py::class_< DistanceFormatter, DoubleFormatterBase> c3(m, "DistanceFormatter", py::multiple_inheritance());

    c3.def_property("UnitFormat", &DistanceFormatter::GetUnitFormat, &DistanceFormatter::SetUnitFormat);
    c3.def("GetUnitFormat", &DistanceFormatter::GetUnitFormat, DOC(Bentley, DgnPlatform, DistanceFormatter, GetUnitFormat));
    c3.def("SetUnitFormat", &DistanceFormatter::SetUnitFormat, "newVal"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetUnitFormat));
    
    c3.def_property_readonly("MasterUnit", &DistanceFormatter::GetMasterUnit);
    c3.def("GetMasterUnit", &DistanceFormatter::GetMasterUnit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DistanceFormatter, GetMasterUnit));
    
    c3.def_property_readonly("SubUnit", &DistanceFormatter::GetSubUnit);
    c3.def("GetSubUnit", &DistanceFormatter::GetSubUnit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DistanceFormatter, GetSubUnit));
    
    c3.def_property("StorageUnit", &DistanceFormatter::GetStorageUnit, py::overload_cast<UnitDefinitionCR>(&DistanceFormatter::SetStorageUnit));
    c3.def("GetStorageUnit", &DistanceFormatter::GetStorageUnit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DistanceFormatter, GetStorageUnit));
    c3.def("SetStorageUnit", py::overload_cast<UnitDefinitionCR>(&DistanceFormatter::SetStorageUnit), "newVal"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetStorageUnit));

    c3.def_property("UorPerStorageUnit", &DistanceFormatter::GetUorPerStorageUnit, &DistanceFormatter::SetUorPerStorageUnit);
    c3.def("GetUorPerStorageUnit", &DistanceFormatter::GetUorPerStorageUnit, DOC(Bentley, DgnPlatform, DistanceFormatter, GetUorPerStorageUnit));
    c3.def("SetUorPerStorageUnit", &DistanceFormatter::SetUorPerStorageUnit, "newVal"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetUorPerStorageUnit));
    
    c3.def_property("ScaleFactor", &DistanceFormatter::GetScaleFactor, &DistanceFormatter::SetScaleFactor);
    c3.def("GetScaleFactor", &DistanceFormatter::GetScaleFactor, DOC(Bentley, DgnPlatform, DistanceFormatter, GetScaleFactor));
    c3.def("SetScaleFactor", &DistanceFormatter::SetScaleFactor, "factor"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetScaleFactor));
    
    c3.def_property("UnitLabelFlag", &DistanceFormatter::GetUnitLabelFlag, &DistanceFormatter::SetUnitLabelFlag);
    c3.def("GetUnitLabelFlag", &DistanceFormatter::GetUnitLabelFlag, DOC(Bentley, DgnPlatform, DistanceFormatter, GetUnitLabelFlag));
    c3.def("SetUnitLabelFlag", &DistanceFormatter::SetUnitLabelFlag, "flag"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetUnitLabelFlag));
    
    c3.def_property("SuppressZeroMasterUnits", &DistanceFormatter::GetSuppressZeroMasterUnits, &DistanceFormatter::SetSuppressZeroMasterUnits);
    c3.def("GetSuppressZeroMasterUnits", &DistanceFormatter::GetSuppressZeroMasterUnits, DOC(Bentley, DgnPlatform, DistanceFormatter, GetSuppressZeroMasterUnits));
    c3.def("SetSuppressZeroMasterUnits", &DistanceFormatter::SetSuppressZeroMasterUnits, "newVal"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetSuppressZeroMasterUnits));
    
    c3.def_property("SuppressZeroSubUnits", &DistanceFormatter::GetSuppressZeroSubUnits, &DistanceFormatter::SetSuppressZeroSubUnits);
    c3.def("GetSuppressZeroSubUnits", &DistanceFormatter::GetSuppressZeroSubUnits, DOC(Bentley, DgnPlatform, DistanceFormatter, GetSuppressZeroSubUnits));
    c3.def("SetSuppressZeroSubUnits", &DistanceFormatter::SetSuppressZeroSubUnits, "newVal"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetSuppressZeroSubUnits));
    
    c3.def_property("IsDgnCoordReadOutCapable", &DistanceFormatter::GetIsDgnCoordReadOutCapable, &DistanceFormatter::SetIsDgnCoordReadOutCapable);
    c3.def("GetIsDgnCoordReadOutCapable", &DistanceFormatter::GetIsDgnCoordReadOutCapable, DOC(Bentley, DgnPlatform, DistanceFormatter, GetIsDgnCoordReadOutCapable));
    c3.def("SetIsDgnCoordReadOutCapable", &DistanceFormatter::SetIsDgnCoordReadOutCapable, "newVal"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetIsDgnCoordReadOutCapable));
    
    c3.def_property_readonly("MinimumResolution", &DistanceFormatter::GetMinimumResolution);
    c3.def("GetMinimumResolution", &DistanceFormatter::GetMinimumResolution, DOC(Bentley, DgnPlatform, DistanceFormatter, GetMinimumResolution));

    c3.def("SetWorkingUnits", &DistanceFormatter::SetWorkingUnits, "newMasterUnit"_a, "newSubUnit"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetWorkingUnits));
    c3.def("SetStorageUnit", py::overload_cast<UnitDefinitionCR, double>(&DistanceFormatter::SetStorageUnit), "newStorageUnit"_a, "uorPerStorage"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, SetStorageUnit));
    c3.def_static("Create", py::overload_cast<>(&DistanceFormatter::Create), DOC(Bentley, DgnPlatform, DistanceFormatter, Create));
    c3.def_static("Create", py::overload_cast<DgnModelCR>(&DistanceFormatter::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, Create));
    c3.def_static("Create", py::overload_cast<ViewportR>(&DistanceFormatter::Create), "vp"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, Create));
    c3.def("Clone", &DistanceFormatter::Clone, DOC(Bentley, DgnPlatform, DistanceFormatter, Clone));
    c3.def("ToString", &DistanceFormatter::ToString, "uors"_a, DOC(Bentley, DgnPlatform, DistanceFormatter, ToString));        

    c3.def("__repr__", [] (DistanceFormatterCR self)
           {
           return "[{}, UnitFormat={}, MasterUnit={}, SubUnit={}, StorageUnit={}, UorPerStorageUnit={}, ScaleFactor={}, UnitLabelFlag={}, SuppressZeroMasterUnits={}, SuppressZeroSubUnits={}, IsDgnCoordReadOutCapable={}, MinimumResolution={}]"_s
               .format((DoubleFormatterBase const&)self,
                       self.GetUnitFormat(),
                       self.GetMasterUnit(),
                       self.GetSubUnit(),
                       self.GetStorageUnit(),
                       self.GetUorPerStorageUnit(),
                       self.GetScaleFactor(),
                       self.GetUnitLabelFlag(),
                       self.GetSuppressZeroMasterUnits(),
                       self.GetSuppressZeroSubUnits(),
                       self.GetIsDgnCoordReadOutCapable(),
                       self.GetMinimumResolution());
           });

    //===================================================================================
    // struct PointFormatter
    py::class_< PointFormatter> c4(m, "PointFormatter");

    c4.def_property("DistanceFormatter", &PointFormatter::GetDistanceFormatter, &PointFormatter::SetDistanceFormatter);
    c4.def("GetDistanceFormatter", &PointFormatter::GetDistanceFormatter, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointFormatter, GetDistanceFormatter));
    c4.def("SetDistanceFormatter", &PointFormatter::SetDistanceFormatter, "formatter"_a, DOC(Bentley, DgnPlatform, PointFormatter, SetDistanceFormatter));
    
    c4.def_property("AuxCoordSys", &PointFormatter::GetAuxCoordSys, &PointFormatter::SetAuxCoordSys);
    c4.def("GetAuxCoordSys", &PointFormatter::GetAuxCoordSys, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointFormatter, GetAuxCoordSys));
    c4.def("SetAuxCoordSys", &PointFormatter::SetAuxCoordSys, "acs"_a, DOC(Bentley, DgnPlatform, PointFormatter, SetAuxCoordSys));
    
    c4.def_property("Is3d", &PointFormatter::GetIs3d, &PointFormatter::SetIs3d);
    c4.def("GetIs3d", &PointFormatter::GetIs3d, DOC(Bentley, DgnPlatform, PointFormatter, GetIs3d));
    c4.def("SetIs3d", &PointFormatter::SetIs3d, "newVal"_a, DOC(Bentley, DgnPlatform, PointFormatter, SetIs3d));

    c4.def_static("Create", py::overload_cast<>(&PointFormatter::Create), DOC(Bentley, DgnPlatform, PointFormatter, Create));
    c4.def_static("Create", py::overload_cast<DgnModelCR, bool>(&PointFormatter::Create), "dgnModel"_a, "addGlobalOrigin"_a, DOC(Bentley, DgnPlatform, PointFormatter, Create));
    c4.def_static("Create", py::overload_cast<ViewportR>(&PointFormatter::Create), "vp"_a, DOC(Bentley, DgnPlatform, PointFormatter, Create));
    c4.def_static("Create", py::overload_cast<DistanceFormatterCR>(&PointFormatter::Create), "distanceFormatter"_a, DOC(Bentley, DgnPlatform, PointFormatter, Create));
    c4.def("Clone", &PointFormatter::Clone, DOC(Bentley, DgnPlatform, PointFormatter, Clone));
    c4.def("ToString", &PointFormatter::ToString, "point"_a, DOC(Bentley, DgnPlatform, PointFormatter, ToString));

    c4.def("__repr__", [] (PointFormatterR self)
           {
           return "[DistanceFormatter={}, AuxCoordSys={}, Is3d={}]"_s
               .format(self.GetDistanceFormatter(), self.GetAuxCoordSys(), self.GetIs3d());
           });

    //===================================================================================
    // struct AreaOrVolumeFormatterBase
    py::class_< AreaOrVolumeFormatterBase, DoubleFormatterBase> c5(m, "AreaOrVolumeFormatterBase");

    c5.def_property("MasterUnit", &AreaOrVolumeFormatterBase::GetMasterUnit, &AreaOrVolumeFormatterBase::SetMasterUnit);
    c5.def("GetMasterUnit", &AreaOrVolumeFormatterBase::GetMasterUnit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, GetMasterUnit));
    c5.def("SetMasterUnit", &AreaOrVolumeFormatterBase::SetMasterUnit, "newVal"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetMasterUnit));
    
    c5.def_property("StorageUnit", &AreaOrVolumeFormatterBase::GetStorageUnit, py::overload_cast<UnitDefinitionCR>(&AreaOrVolumeFormatterBase::SetStorageUnit));
    c5.def("GetStorageUnit", &AreaOrVolumeFormatterBase::GetStorageUnit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, GetStorageUnit));
    c5.def("SetStorageUnit", py::overload_cast<UnitDefinitionCR>(&AreaOrVolumeFormatterBase::SetStorageUnit), "newVal"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetStorageUnit));
    
    c5.def_property("UorPerStorageUnit", &AreaOrVolumeFormatterBase::GetUorPerStorageUnit, &AreaOrVolumeFormatterBase::SetUorPerStorageUnit);
    c5.def("GetUorPerStorageUnit", &AreaOrVolumeFormatterBase::GetUorPerStorageUnit, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, GetUorPerStorageUnit));
    c5.def("SetUorPerStorageUnit", &AreaOrVolumeFormatterBase::SetUorPerStorageUnit, "newVal"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetUorPerStorageUnit));
    
    c5.def_property("ScaleFactor", &AreaOrVolumeFormatterBase::GetScaleFactor, &AreaOrVolumeFormatterBase::SetScaleFactor);
    c5.def("GetScaleFactor", &AreaOrVolumeFormatterBase::GetScaleFactor, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, GetScaleFactor));
    c5.def("SetScaleFactor", &AreaOrVolumeFormatterBase::SetScaleFactor, "factor"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetScaleFactor));
    
    c5.def_property("ShowUnitLabel", &AreaOrVolumeFormatterBase::GetShowUnitLabel, &AreaOrVolumeFormatterBase::SetShowUnitLabel);
    c5.def("GetShowUnitLabel", &AreaOrVolumeFormatterBase::GetShowUnitLabel, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, GetShowUnitLabel));
    c5.def("SetShowUnitLabel", &AreaOrVolumeFormatterBase::SetShowUnitLabel, "newVal"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetShowUnitLabel));
    
    c5.def_property("LabelDecoratorAsSuffix", &AreaOrVolumeFormatterBase::GetLabelDecoratorAsSuffix, &AreaOrVolumeFormatterBase::SetLabelDecoratorAsSuffix);
    c5.def("GetLabelDecoratorAsSuffix", &AreaOrVolumeFormatterBase::GetLabelDecoratorAsSuffix, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, GetLabelDecoratorAsSuffix));
    c5.def("SetLabelDecoratorAsSuffix", &AreaOrVolumeFormatterBase::SetLabelDecoratorAsSuffix, "newVal"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetLabelDecoratorAsSuffix));
    
    c5.def("SetStorageUnit", py::overload_cast<UnitDefinitionCR, double>(&AreaOrVolumeFormatterBase::SetStorageUnit), "newStorageUnit"_a, "uorPerStorage"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeFormatterBase, SetStorageUnit));

    c5.def("__repr__", [] (AreaOrVolumeFormatterBase const& self)
           {
           return "[{}, MasterUnit={}, StorageUnit={}, UorPerStorageUnit={}, ScaleFactor={}, ShowUnitLabel={}, LabelDecoratorSuffix={}]"_s
               .format((DoubleFormatterBase const&) self,
                       self.GetMasterUnit(),
                       self.GetStorageUnit(),
                       self.GetUorPerStorageUnit(),
                       self.GetScaleFactor(),
                       self.GetShowUnitLabel(),
                       self.GetLabelDecoratorAsSuffix());
           });

    //===================================================================================
    // struct AreaFormatter
    py::class_< AreaFormatter, AreaOrVolumeFormatterBase> c6(m, "AreaFormatter", py::multiple_inheritance());

    c6.def_static("Create", py::overload_cast<>(&AreaFormatter::Create), DOC(Bentley, DgnPlatform, AreaFormatter, Create));
    c6.def_static("Create", py::overload_cast<DgnModelCR>(&AreaFormatter::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, AreaFormatter, Create));
    c6.def_static("Create", py::overload_cast<ViewportR>(&AreaFormatter::Create), "vp"_a, DOC(Bentley, DgnPlatform, AreaFormatter, Create));
    c6.def("Clone", &AreaFormatter::Clone, DOC(Bentley, DgnPlatform, AreaFormatter, Clone));
    c6.def("ToString", &AreaFormatter::ToString, "uors"_a, DOC(Bentley, DgnPlatform, AreaFormatter, ToString));

    c6.def("__repr__", [] (AreaFormatterCR self)
           {
           return "[{}]"_s.format((AreaOrVolumeFormatterBase const&) self);
           });

    //===================================================================================
    // struct VolumeFormatter
    py::class_< VolumeFormatter, AreaOrVolumeFormatterBase> c7(m, "VolumeFormatter", py::multiple_inheritance());

    c7.def_static("Create", py::overload_cast<>(&VolumeFormatter::Create), DOC(Bentley, DgnPlatform, VolumeFormatter, Create));
    c7.def_static("Create", py::overload_cast<DgnModelCR>(&VolumeFormatter::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, VolumeFormatter, Create));
    c7.def_static("Create", py::overload_cast<ViewportR>(&VolumeFormatter::Create), "vp"_a, DOC(Bentley, DgnPlatform, VolumeFormatter, Create));
    c7.def("Clone", &VolumeFormatter::Clone, DOC(Bentley, DgnPlatform, VolumeFormatter, Clone));
    c7.def("ToString", &VolumeFormatter::ToString, "uors"_a, DOC(Bentley, DgnPlatform, VolumeFormatter, ToString));

    c7.def("__repr__", [] (VolumeFormatterCR self)
           {
           return "[{}]"_s.format((AreaOrVolumeFormatterBase const&) self);
           });

    //===================================================================================
    // struct DateTimeFormatter
    py::class_< DateTimeFormatter> c8(m, "DateTimeFormatter");

    c8.def_property("DecimalSeparator", &DateTimeFormatter::GetDecimalSeparator, &DateTimeFormatter::SetDecimalSeparator);
    c8.def("GetDecimalSeparator", &DateTimeFormatter::GetDecimalSeparator, DOC(Bentley, DgnPlatform, DateTimeFormatter, GetDecimalSeparator));
    c8.def("SetDecimalSeparator", &DateTimeFormatter::SetDecimalSeparator, "newVal"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, SetDecimalSeparator));
    
    c8.def_property("TimeSeparator", &DateTimeFormatter::GetTimeSeparator, &DateTimeFormatter::SetTimeSeparator);
    c8.def("GetTimeSeparator", &DateTimeFormatter::GetTimeSeparator, DOC(Bentley, DgnPlatform, DateTimeFormatter, GetTimeSeparator));
    c8.def("SetTimeSeparator", &DateTimeFormatter::SetTimeSeparator, "newVal"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, SetTimeSeparator));
    
    c8.def_property("DateSeparator", &DateTimeFormatter::GetDateSeparator, &DateTimeFormatter::SetDateSeparator);
    c8.def("GetDateSeparator", &DateTimeFormatter::GetDateSeparator, DOC(Bentley, DgnPlatform, DateTimeFormatter, GetDateSeparator));
    c8.def("SetDateSeparator", &DateTimeFormatter::SetDateSeparator, "newVal"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, SetDateSeparator));
    
    c8.def_property("FractionalSecondPrecision", &DateTimeFormatter::GetFractionalSecondPrecision, &DateTimeFormatter::SetFractionalSecondPrecision);
    c8.def("GetFractionalSecondPrecision", &DateTimeFormatter::GetFractionalSecondPrecision, DOC(Bentley, DgnPlatform, DateTimeFormatter, GetFractionalSecondPrecision));
    c8.def("SetFractionalSecondPrecision", &DateTimeFormatter::SetFractionalSecondPrecision, "newVal"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, SetFractionalSecondPrecision));
    
    c8.def_property("TrailingZeros", &DateTimeFormatter::GetTrailingZeros, &DateTimeFormatter::SetTrailingZeros);
    c8.def("GetTrailingZeros", &DateTimeFormatter::GetTrailingZeros, DOC(Bentley, DgnPlatform, DateTimeFormatter, GetTrailingZeros));
    c8.def("SetTrailingZeros", &DateTimeFormatter::SetTrailingZeros, "newVal"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, SetTrailingZeros));

    c8.def("AppendFormatPart", &DateTimeFormatter::AppendFormatPart, "part"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, AppendFormatPart));
    c8.def("ClearFormatParts", &DateTimeFormatter::ClearFormatParts, DOC(Bentley, DgnPlatform, DateTimeFormatter, ClearFormatParts));
    c8.def("Reset", &DateTimeFormatter::Reset, DOC(Bentley, DgnPlatform, DateTimeFormatter, Reset));
    c8.def_static("Create", &DateTimeFormatter::Create, DOC(Bentley, DgnPlatform, DateTimeFormatter, Create));
    c8.def("Clone", &DateTimeFormatter::Clone, DOC(Bentley, DgnPlatform, DateTimeFormatter, Clone));
    c8.def("ToString", &DateTimeFormatter::ToString, "dateTime"_a, DOC(Bentley, DgnPlatform, DateTimeFormatter, ToString));

    c8.def("__repr__", [] (DateTimeFormatterCR self)
           {
           return "[DecimalSeparator={}, TimeSeparator={}, DateSeparator={}, FractionalSecondPrecision={}, TrailingZeros={}]"_s
               .format(self.GetDecimalSeparator(), self.GetTimeSeparator(), self.GetDateSeparator(), self.GetFractionalSecondPrecision(), self.GetTrailingZeros());
           });
    }