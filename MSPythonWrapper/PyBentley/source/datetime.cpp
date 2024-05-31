/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\datetime.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Bentley/DateTime.h>



static const char * __doc_Bentley_DateTime_IsLeapYear = R"doc(Indicates whether the specified year is a leap year or not

Returns:
    true, if ``year`` is a leap year. false, otherwise.)doc";

static const char * __doc_Bentley_DateTime_GetDayOfYear = R"doc(Gets the day of the year of this DateTime object.

Returns:
    Day of the year or 0 if the DateTime object is not valid (see
    DateTime::IsValid))doc";

static const char * __doc_Bentley_DateTime_GetDayOfWeek = R"doc(Gets the day of the week of this DateTime object.

Remark:
    s Only call this method if the DateTime is valid (see
    DateTime::IsValid)

Returns:
    Day of the week)doc";

static const char * __doc_Bentley_DateTime_GetHectoNanosecond = R"doc(Gets the hecto-nanosecond component of this DateTime object.

Remark:
    s 1 hecto-nanosecond is 1e-7 seconds.

Returns:
    Hecto-nanoseconds (0 through 9,999,999))doc";

static const char * __doc_Bentley_DateTime_GetMillisecond = R"doc(Gets the milliseconds component of this DateTime object.

Remark:
    s The hecto-nanoseconds are truncated (not rounded) at the
    millisecond position.

Returns:
    Milliseconds (0 through 999))doc";

static const char * __doc_Bentley_DateTime_GetMinute = R"doc(Gets the minute component of this DateTime object.

Returns:
    Minutes (0 through 59))doc";

static const char * __doc_Bentley_DateTime_GetHour = R"doc(Gets the hour component of this DateTime object.

Returns:
    Hours (0 through 59))doc";

static const char * __doc_Bentley_DateTime_GetDay = R"doc(Gets the day component of this DateTime object.

Returns:
    Day in the month (1 through the number in GetMonth))doc";

static const char * __doc_Bentley_DateTime_GetMonth = R"doc(Gets the month component of this DateTime object.

Returns:
    Month (1 through 12).)doc";

static const char * __doc_Bentley_DateTime_GetYear = R"doc(Gets the year component of this DateTime object.

Returns:
    Year (negative if BCE, positive otherwise).)doc";

static const char * __doc_Bentley_DateTime_GetInfo = R"doc(Gets meta data about this DateTime object.

Returns:
    DateTime::Info of this DateTime object.)doc";

static const char * __doc_Bentley_DateTime_FromString = R"doc(Parses an ISO 8601 date time string into a DateTime instance.

Remark:
    s This method supports T and a space as delimiter of the date and
    time component, e.g. both <c>2013-09-15T12:05:39</c> and
    <c>2013-09-15 12:05:39</c> can be parsed into a DateTime object.
    This is a minor deviation from the ISO standard (specifies the T
    delimiter), which allows to parse SQL-99 date time literals
    (specifies the space delimiter)

Parameter ``dateTime``:
    the resulting DateTime instance

Parameter ``dateTimeIso8601``:
    the ISO 8601 date time string to parse

Returns:
    SUCCESS, if parsing was successful. ERROR, otherwise)doc";

static const char * __doc_Bentley_DateTime_ToString = R"doc(Converts the value of this DateTime into a string representation.

Remark:
    s The resulting string is formatted according to the ISO8601
    standard. Second fractions are rounded to milliseconds.

Returns:
    String representation of this DateTime object. An empty string is
    returned if this date time info object is not valid (see
    DateTime::IsValid ))doc";

static const char * __doc_Bentley_DateTime_ToUtf8String = R"doc(Converts the value of this DateTime into a string representation.

Remark:
    s The resulting string is formatted according to the ISO8601
    standard. Second fractions are rounded to milliseconds.

Returns:
    String representation of this DateTime object. An empty string is
    returned if this date time info object is not valid (see
    DateTime::IsValid ))doc";

static const char * __doc_Bentley_DateTime_CommonEraTicksToJulianDay = R"doc(Computes the Julian Day number from the given Common Era ticks. The
Common Era begins at 0001-01-01 00:00:00 UTC.

Parameter `` in ``:
    commonEraTicks Common Era ticks in hecto-nanoseconds

Returns:
    Julian Day number in hecto-nanoseconds)doc";

static const char * __doc_Bentley_DateTime_JulianDayToCommonEraTicks = R"doc(Computes Common Era ticks from the given the Julian Day number. The
Common Era begins at 0001-01-01 00:00:00 UTC.

Parameter `` in ``:
    julianDayInHectoNanoseconds Julian Day number

Returns:
    Common Era ticks in hecto-nanoseconds)doc";

static const char * __doc_Bentley_DateTime_FromCommonEraTicks = R"doc(Computes the DateTime from the given Common Era ticks. The Common Era
begins at 0001-01-01 00:00:00 UTC.

Parameter `` out ``:
    dateTime Resulting DateTime object (on the proleptic Gregorian
    calendar)

Parameter `` in ``:
    commonEraTicks Common Era ticks in hecto-nanoseconds

Parameter `` in ``:
    targetInfo DateTime::Info the resulting DateTime should have

Returns:
    SUCCESS if computation was successful. ERROR in case of errors,
    e.g. if computation of local time zone offset failed.)doc";

static const char * __doc_Bentley_DateTime_UnixMillisecondsToJulianDay = R"doc(Computes the Julian Day number from the given Unix milliseconds.

Parameter `` in ``:
    unixMilliseconds Unix milliseconds. Negative numbers indicate
    dates before the Unix epoch.

Returns:
    Julian Day number in hecto-nanoseconds)doc";

static const char * __doc_Bentley_DateTime_JulianDayToUnixMilliseconds = R"doc(Computes the Unix milliseconds from the given Julian Day number.

Parameter `` in ``:
    julianDayInHectoNanoseconds Julian day in hecto-
    nanoseconds.unixMilliseconds Unix milliseconds.

Returns:
    Unix milliseconds. Negative numbers indicate dates before the Unix
    epoch.)doc";

static const char * __doc_Bentley_DateTime_FromUnixMilliseconds = R"doc(Creates a DateTime in UTC from the given Unix epoch milliseconds

Parameter `` out ``:
    dateTime The resulting DateTime object on the proleptic Gregorian
    calendar (in UTC).

Parameter `` in ``:
    unixMilliseconds The Unix epoch milliseconds. Negative if they
    refer to a date before the Unix epoch (1970-01-01 00:00:00 UTC)

Returns:
    SUCCESS if conversion was successful. ERROR otherwise)doc";

static const char * __doc_Bentley_DateTime_ToLocalTime = R"doc(Converts this UTC DateTime to local time

Parameter `` out ``:
    localDateTime Resulting DateTime object in local time

Returns:
    SUCCESS if successful. ERROR in case of errors, e.g. if this date
    time instance is invalid (see DateTime::IsValid) or if computation
    of local time zone offset failed.)doc";

static const char * __doc_Bentley_DateTime_ToUtc = R"doc(Converts this local DateTime to UTC

Parameter `` out ``:
    utcDateTime Resulting DateTime object in UTC

Returns:
    SUCCESS if successful. ERROR in case of errors, e.g. if this date
    time instance is invalid (see DateTime::IsValid) or if computation
    of local time zone offset failed.)doc";

static const char * __doc_Bentley_DateTime_GetCurrentTime = R"doc(Gets the current system time in local time.

Returns:
    Current system time in local time)doc";

static const char * __doc_Bentley_DateTime_Compare = R"doc(Compares two DateTimes. This method internally converts the DateTime
objects to Julian Days and compares those. As the conversion can fail,
this method can return an error (see DateTime::CompareResult). This is
also the reason why the class does not provide comparison operators
other than equality and inequality.

Parameter `` in ``:
    lhs Left-hand side DateTime

Parameter `` in ``:
    rhs Right-hand side DateTime

Returns:
    A CompareResult value.)doc";

static const char * __doc_Bentley_DateTime_IsValid = R"doc(Indicates whether this DateTime instance is a valid date/time or not.

Remark:
    s Using the default constructor creates an invalid date time as
    none of the components have been set.

Returns:
    true, if the DateTime instance is valid, false otherwise)doc";



static const char * __doc_Bentley_DateTime_GetSecond = R"doc(Gets the second component of this DateTime object.

Returns:
    Seconds (0 through 59))doc";

static const char * __doc_Bentley_DateTime_GetCurrentTimeUtc = R"doc(Gets the current system time in UTC.

Returns:
    Current system time in UTC)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DateTime(py::module_& m)
    {
    //===================================================================================
    // struct DateTime
    py::class_< DateTime> c1(m, "BeDateTime","Represents an instant in time, typically expressed as a date and time of day\nA DateTime also holds additional metadata about the actual date time in its DateTime::Info member.\nA DateTime's accuracy is 100's of nanoseconds (i.e hecto-nanoseconds, i.e. 1e-7 seconds)"); // We have to use another class name due to naming conflictions.

    if (true)
        {
        //===================================================================================
        // enum class Kind
        py::enum_<DateTime::Kind>(c1, "Kind","Specifies whether a DateTime represents a local time, a Coordinated Universal Time (UTC),  or is not specified as either local time or UTC.")
            .value("eUnspecified", DateTime::Kind::Unspecified)
            .value("eUtc", DateTime::Kind::Utc)
            .value("eLocal", DateTime::Kind::Local)
            .export_values();

        //===================================================================================
        // enum class Component
        py::enum_<DateTime::Component>(c1, "Component")
            .value("eDate", DateTime::Component::Date)
            .value("eDateAndTime", DateTime::Component::DateAndTime)
            .export_values();

        //===================================================================================
        // enum class DayOfWeek
        py::enum_<DateTime::DayOfWeek>(c1, "DayOfWeek")
            .value("eSunday", DateTime::DayOfWeek::Sunday)
            .value("eMonday", DateTime::DayOfWeek::Monday)
            .value("eTuesday", DateTime::DayOfWeek::Tuesday)
            .value("eWednesday", DateTime::DayOfWeek::Wednesday)
            .value("eThursday", DateTime::DayOfWeek::Thursday)
            .value("eFriday", DateTime::DayOfWeek::Friday)
            .value("eSaturday", DateTime::DayOfWeek::Saturday)
            .export_values();

        //===================================================================================
        // enum class CompareResult
        py::enum_<DateTime::CompareResult>(c1, "CompareResult")
            .value("eEarlierThan", DateTime::CompareResult::EarlierThan)
            .value("eEquals", DateTime::CompareResult::Equals)
            .value("eLaterThan", DateTime::CompareResult::LaterThan)
            .value("eError", DateTime::CompareResult::Error)
            .export_values();

        //===================================================================================
        // struct Info
        py::class_<DateTime::Info> c1_1(m, "BeDateTimeInfo","Provides the metadata portion of a DateTime object.");

        c1_1.def(py::init<>()," Initializes a new instance of the Info class.");
        c1_1.def(py::init<DateTime::Kind, DateTime::Component>(), "kind"_a, "component"_a);
        c1_1.def(py::self == py::self);
        c1_1.def(py::self != py::self);

        c1_1.def_property_readonly("Kind", &DateTime::Info::GetKind,"Gets the DateTime kind.");        
        c1_1.def("GetKind", &DateTime::Info::GetKind,"Gets the DateTime kind.");

        c1_1.def_property_readonly("Component", &DateTime::Info::GetComponent,"Gets the DateTime component.");        
        c1_1.def("GetComponent", &DateTime::Info::GetComponent);        

        c1_1.def_static("KindToString", &DateTime::Info::KindToString, "kind"_a);
        c1_1.def_static("ComponentToString", &DateTime::Info::ComponentToString, "component"_a);
        }

    c1.def(py::init<>(),"Initializes a new empty instance of the DateTime struct.");
    c1.def(py::init<Int16, UInt8, UInt8>(), "year"_a, "month"_a, "day"_a);
    c1.def(py::init<DateTime::Kind, Int16, UInt8, UInt8, UInt8, UInt8, UInt8, UInt32>(), "kind"_a, "year"_a, "month"_a, "day"_a, "hour"_a, "minute"_a, "second"_a = 0, "hectoNansecond"_a = 0);
    c1.def("IsValid", &DateTime::IsValid, DOC(Bentley, DateTime, IsValid));
    c1.def(py::self == py::self);
    c1.def(py::self != py::self);
    c1.def_static("Compare", &DateTime::Compare, "lhs"_a, "rhs"_a, DOC(Bentley, DateTime, Compare));    
    
    c1.def_property_readonly_static("CurrentTime", [] (py::object const&) { return DateTime::GetCurrentTime(); });
    c1.def_static("GetCurrentTime", &DateTime::GetCurrentTime, DOC(Bentley, DateTime, GetCurrentTime));
    
    c1.def_property_readonly_static("CurrentTimeUtc", [] (py::object const&) { return DateTime::GetCurrentTimeUtc(); });
    c1.def_static("GetCurrentTimeUtc", &DateTime::GetCurrentTimeUtc, DOC(Bentley, DateTime, GetCurrentTimeUtc));

    c1.def("ToJulianDayInHns", [] (DateTimeCR self)
           {
           UInt64 julianDayInHns = 0;
           auto retVal = self.ToJulianDay(julianDayInHns);
           return py::make_tuple(retVal, julianDayInHns);
           });

    c1.def("ToJulianDay", [] (DateTimeCR self)
           {
           double julianDay = 0;
           auto retVal = self.ToJulianDay(julianDay);
           return py::make_tuple(retVal, julianDay);
           });

    c1.def_static("FromJulianDayInHns",
                  py::overload_cast<DateTimeR, UInt64, DateTime::Info const&>(&DateTime::FromJulianDay),
                  "dateTime"_a, "julianDayInHns"_a, "targetInfo"_a);

    c1.def_static("FromJulianDay",
                  py::overload_cast<DateTimeR, double, DateTime::Info const&>(&DateTime::FromJulianDay),
                  "dateTime"_a, "julianDay"_a, "targetInfo"_a);

    c1.def("ToUtc", &DateTime::ToUtc, "utcDateTime"_a, DOC(Bentley, DateTime, ToUtc));
    c1.def("ToLocalTime", &DateTime::ToLocalTime, "localDateTime"_a, DOC(Bentley, DateTime, ToLocalTime));
    
    c1.def("ToUnixMilliseconds", [] (DateTimeCR self)
           {
           Int64 unixMilliseconds = 0;
           auto retVal = self.ToUnixMilliseconds(unixMilliseconds);
           return py::make_tuple(retVal, unixMilliseconds);
           });

    c1.def_static("FromUnixMilliseconds", &DateTime::FromUnixMilliseconds, "dateTime"_a, "unixMilliseconds"_a, DOC(Bentley, DateTime, FromUnixMilliseconds));
    c1.def_static("JulianDayToUnixMilliseconds", &DateTime::JulianDayToUnixMilliseconds, "julianDayInHectoNanoseconds"_a, DOC(Bentley, DateTime, JulianDayToUnixMilliseconds));
    c1.def_static("UnixMillisecondsToJulianDay", &DateTime::UnixMillisecondsToJulianDay, "unixMilliseconds"_a, DOC(Bentley, DateTime, UnixMillisecondsToJulianDay));

    c1.def("ToCommonEraTicks", [] (DateTimeCR self)
           {
           Int64 commonEraTicks = 0;
           auto retVal = self.ToCommonEraTicks(commonEraTicks);
           return py::make_tuple(retVal, commonEraTicks);
           });

    c1.def_static("FromCommonEraTicks", &DateTime::FromCommonEraTicks, "dateTime"_a, "commonEraTicks"_a, "targetInfo"_a, DOC(Bentley, DateTime, FromCommonEraTicks));
    c1.def_static("JulianDayToCommonEraTicks", &DateTime::JulianDayToCommonEraTicks, "julianDayInHectoNanoseconds"_a, DOC(Bentley, DateTime, JulianDayToCommonEraTicks));
    c1.def_static("CommonEraTicksToJulianDay", &DateTime::CommonEraTicksToJulianDay, "commonEraTicks"_a, DOC(Bentley, DateTime, CommonEraTicksToJulianDay));
    c1.def("ToUtf8String", &DateTime::ToUtf8String, DOC(Bentley, DateTime, ToUtf8String));
    c1.def("ToString", &DateTime::ToString, DOC(Bentley, DateTime, ToString));

    c1.def_static("FromString", py::overload_cast<DateTimeR, Utf8CP>(&DateTime::FromString), "dateTime"_a, "dateTimeIso8601"_a, DOC(Bentley, DateTime, FromString));
    
    c1.def_property_readonly("Info", &DateTime::GetInfo);
    c1.def("GetInfo", &DateTime::GetInfo, DOC(Bentley, DateTime, GetInfo));

    c1.def_property_readonly("Year", &DateTime::GetYear);
    c1.def("GetYear", &DateTime::GetYear, DOC(Bentley, DateTime, GetYear));

    c1.def_property_readonly("Month", &DateTime::GetMonth);
    c1.def("GetMonth", &DateTime::GetMonth, DOC(Bentley, DateTime, GetMonth));

    c1.def_property_readonly("Day", &DateTime::GetDay);
    c1.def("GetDay", &DateTime::GetDay, DOC(Bentley, DateTime, GetDay));

    c1.def_property_readonly("Hour", &DateTime::GetHour);
    c1.def("GetHour", &DateTime::GetHour, DOC(Bentley, DateTime, GetHour));

    c1.def_property_readonly("Minute", &DateTime::GetMinute);
    c1.def("GetMinute", &DateTime::GetMinute, DOC(Bentley, DateTime, GetMinute));

    c1.def_property_readonly("Second", &DateTime::GetSecond);
    c1.def("GetSecond", &DateTime::GetSecond, DOC(Bentley, DateTime, GetSecond));

    c1.def_property_readonly("Millisecond", &DateTime::GetMillisecond);
    c1.def("GetMillisecond", &DateTime::GetMillisecond, DOC(Bentley, DateTime, GetMillisecond));

    c1.def_property_readonly("HectoNanosecond", &DateTime::GetHectoNanosecond);
    c1.def("GetHectoNanosecond", &DateTime::GetHectoNanosecond, DOC(Bentley, DateTime, GetHectoNanosecond));

    c1.def_property_readonly("DayOfWeek", &DateTime::GetDayOfWeek);
    c1.def("GetDayOfWeek", &DateTime::GetDayOfWeek, DOC(Bentley, DateTime, GetDayOfWeek));

    c1.def_property_readonly("DayOfYear", &DateTime::GetDayOfYear);
    c1.def("GetDayOfYear", &DateTime::GetDayOfYear, DOC(Bentley, DateTime, GetDayOfYear));
    
    c1.def_static("IsLeapYear", &DateTime::IsLeapYear, "year"_a, DOC(Bentley, DateTime, IsLeapYear));
    
    c1.def("ComputeOffsetToUtcInHns", [] (DateTimeCR self)
           {
           Int64 offset = 0;
           auto retVal = self.ComputeOffsetToUtcInHns(offset);
           return py::make_tuple(retVal, offset);
           });

    c1.def("__repr__", [] (DateTimeCR self)
           {
           return "<Date:{}-{}-{}, Time:{}:{}:{} {}, DayOfWeek:{}, DayOfYear:{}, Kind:{}>"_s
               .format(self.GetYear(), self.GetMonth(), self.GetDay(),
                       self.GetHour(), self.GetMinute(), self.GetSecond(), (double) self.GetMillisecond() * 0.001,
                       self.GetDayOfWeek(), self.GetDayOfYear(), self.GetInfo().GetKind());
           });

    c1.def ("EqualTo", &DateTime::Equals, "rhs"_a, "ignoreDateTimeInfo"_a = false/*, DOC(Bentley, DateTime, Equals)*/);
    }