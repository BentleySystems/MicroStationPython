from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyBentley

class AString:
    """
    A string class that has many of the same capabilities as std.string, plus
    additional functions such as conversion
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.AString) -> None
        
        2. __init__(self: MSPyBentley.AString, str: str) -> None
        
        3. __init__(self: MSPyBentley.AString, __s: str, __n: int) -> None
        
        4. __init__(self: MSPyBentley.AString, __n: int, __c: str) -> None
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.AString) -> None
        """
        ...
    
class AStringArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.AStringArray) -> None
        
        2. __init__(self: MSPyBentley.AStringArray, arg0: MSPyBentley.AStringArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.AStringArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.AStringArray, x: MSPyBentley.AString) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.AStringArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.AStringArray, x: MSPyBentley.AString) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.AStringArray, L: MSPyBentley.AStringArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.AStringArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.AStringArray, i: int, x: MSPyBentley.AString) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.AStringArray) -> MSPyBentley.AString
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.AStringArray, i: int) -> MSPyBentley.AString
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.AStringArray, x: MSPyBentley.AString) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Base64Utilities:
    """
    None
    """

    def Alphabet(*args, **kwargs):
        """
        Alphabet() -> MSPyBentley.Utf8String
        """
        ...
    
    def Decode(*args, **kwargs):
        """
        Decode(encodedString: MSPyBentley.Utf8String) -> MSPyBentley.Utf8String
        """
        ...
    
    def Encode(*args, **kwargs):
        """
        Encode(stringToEncode: MSPyBentley.Utf8String) -> MSPyBentley.Utf8String
        """
        ...
    
    def MatchesAlphabet(*args, **kwargs):
        """
        MatchesAlphabet(input: str) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class BeDateTime:
    """
    Represents an instant in time, typically expressed as a date and time of day
    A DateTime also holds additional metadata about the actual date time in its DateTime.Info member.
    A DateTime's accuracy is 100's of nanoseconds (i.e hecto-nanoseconds, i.e. 1e-7 seconds)
    """

    def CommonEraTicksToJulianDay(*args, **kwargs):
        """
        CommonEraTicksToJulianDay(commonEraTicks: int) -> int
        
        Computes the Julian Day number from the given Common Era ticks. The
        Common Era begins at 0001-01-01 00:00:00 UTC.
        
        Parameter `` in ``:
        commonEraTicks Common Era ticks in hecto-nanoseconds
        
        Returns:
        Julian Day number in hecto-nanoseconds
        """
        ...
    
    def Compare(*args, **kwargs):
        """
        Compare(lhs: MSPyBentley.BeDateTime, rhs: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTime.CompareResult
        
        Compares two DateTimes. This method internally converts the DateTime
        objects to Julian Days and compares those. As the conversion can fail,
        this method can return an error (see DateTime.CompareResult). This is
        also the reason why the class does not provide comparison operators
        other than equality and inequality.
        
        Parameter `` in ``:
        lhs Left-hand side DateTime
        
        Parameter `` in ``:
        rhs Right-hand side DateTime
        
        Returns:
        A CompareResult value.
        """
        ...
    
    class CompareResult:
        """
        Members:
        
        eEarlierThan
        
        eEquals
        
        eLaterThan
        
        eError
        """
    
        def __init__(self: MSPyBentley.BeDateTime.CompareResult, value: int) -> None:
            ...
        
        eEarlierThan: CompareResult
        
        eEquals: CompareResult
        
        eError: CompareResult
        
        eLaterThan: CompareResult
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyBentley.BeDateTime.CompareResult) -> int:
            ...
        
    class Component:
        """
        Members:
        
        eDate
        
        eDateAndTime
        """
    
        def __init__(self: MSPyBentley.BeDateTime.Component, value: int) -> None:
            ...
        
        eDate: Component
        
        eDateAndTime: Component
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyBentley.BeDateTime.Component) -> int:
            ...
        
    def ComputeOffsetToUtcInHns(*args, **kwargs):
        """
        ComputeOffsetToUtcInHns(self: MSPyBentley.BeDateTime) -> tuple
        """
        ...
    
    CurrentTime: BeDateTime
    
    CurrentTimeUtc: BeDateTime
    
    @property
    def Day(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    @property
    def DayOfWeek(arg0: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTime.DayOfWeek:
        ...
    
    @property
    def DayOfYear(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    def EqualTo(*args, **kwargs):
        """
        EqualTo(self: MSPyBentley.BeDateTime, rhs: MSPyBentley.BeDateTime, ignoreDateTimeInfo: bool = False) -> bool
        """
        ...
    
    def FromCommonEraTicks(*args, **kwargs):
        """
        FromCommonEraTicks(dateTime: MSPyBentley.BeDateTime, commonEraTicks: int, targetInfo: MSPyBentley.BeDateTimeInfo) -> Bentley.BentleyStatus
        
        Computes the DateTime from the given Common Era ticks. The Common Era
        begins at 0001-01-01 00:00:00 UTC.
        
        Parameter `` out ``:
        dateTime Resulting DateTime object (on the proleptic Gregorian
        calendar)
        
        Parameter `` in ``:
        commonEraTicks Common Era ticks in hecto-nanoseconds
        
        Parameter `` in ``:
        targetInfo DateTime.Info the resulting DateTime should have
        
        Returns:
        SUCCESS if computation was successful. ERROR in case of errors,
        e.g. if computation of local time zone offset failed.
        """
        ...
    
    def FromJulianDay(*args, **kwargs):
        """
        FromJulianDay(dateTime: MSPyBentley.BeDateTime, julianDay: float, targetInfo: MSPyBentley.BeDateTimeInfo) -> Bentley.BentleyStatus
        """
        ...
    
    def FromJulianDayInHns(*args, **kwargs):
        """
        FromJulianDayInHns(dateTime: MSPyBentley.BeDateTime, julianDayInHns: int, targetInfo: MSPyBentley.BeDateTimeInfo) -> Bentley.BentleyStatus
        """
        ...
    
    def FromString(*args, **kwargs):
        """
        FromString(dateTime: MSPyBentley.BeDateTime, dateTimeIso8601: str) -> Bentley.BentleyStatus
        
        Parses an ISO 8601 date time string into a DateTime instance.
        
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
        SUCCESS, if parsing was successful. ERROR, otherwise
        """
        ...
    
    def FromUnixMilliseconds(*args, **kwargs):
        """
        FromUnixMilliseconds(dateTime: MSPyBentley.BeDateTime, unixMilliseconds: int) -> Bentley.BentleyStatus
        
        Creates a DateTime in UTC from the given Unix epoch milliseconds
        
        Parameter `` out ``:
        dateTime The resulting DateTime object on the proleptic Gregorian
        calendar (in UTC).
        
        Parameter `` in ``:
        unixMilliseconds The Unix epoch milliseconds. Negative if they
        refer to a date before the Unix epoch (1970-01-01 00:00:00 UTC)
        
        Returns:
        SUCCESS if conversion was successful. ERROR otherwise
        """
        ...
    
    def GetCurrentTime(*args, **kwargs):
        """
        GetCurrentTime() -> MSPyBentley.BeDateTime
        
        Gets the current system time in local time.
        
        Returns:
        Current system time in local time
        """
        ...
    
    def GetCurrentTimeUtc(*args, **kwargs):
        """
        GetCurrentTimeUtc() -> MSPyBentley.BeDateTime
        
        Gets the current system time in UTC.
        
        Returns:
        Current system time in UTC
        """
        ...
    
    def GetDay(*args, **kwargs):
        """
        GetDay(self: MSPyBentley.BeDateTime) -> int
        
        Gets the day component of this DateTime object.
        
        Returns:
        Day in the month (1 through the number in GetMonth)
        """
        ...
    
    def GetDayOfWeek(*args, **kwargs):
        """
        GetDayOfWeek(self: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTime.DayOfWeek
        
        Gets the day of the week of this DateTime object.
        
        Remark:
        s Only call this method if the DateTime is valid (see
        DateTime.IsValid)
        
        Returns:
        Day of the week
        """
        ...
    
    def GetDayOfYear(*args, **kwargs):
        """
        GetDayOfYear(self: MSPyBentley.BeDateTime) -> int
        
        Gets the day of the year of this DateTime object.
        
        Returns:
        Day of the year or 0 if the DateTime object is not valid (see
        DateTime.IsValid)
        """
        ...
    
    def GetHectoNanosecond(*args, **kwargs):
        """
        GetHectoNanosecond(self: MSPyBentley.BeDateTime) -> int
        
        Gets the hecto-nanosecond component of this DateTime object.
        
        Remark:
        s 1 hecto-nanosecond is 1e-7 seconds.
        
        Returns:
        Hecto-nanoseconds (0 through 9,999,999)
        """
        ...
    
    def GetHour(*args, **kwargs):
        """
        GetHour(self: MSPyBentley.BeDateTime) -> int
        
        Gets the hour component of this DateTime object.
        
        Returns:
        Hours (0 through 59)
        """
        ...
    
    def GetInfo(*args, **kwargs):
        """
        GetInfo(self: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTimeInfo
        
        Gets meta data about this DateTime object.
        
        Returns:
        DateTime.Info of this DateTime object.
        """
        ...
    
    def GetMillisecond(*args, **kwargs):
        """
        GetMillisecond(self: MSPyBentley.BeDateTime) -> int
        
        Gets the milliseconds component of this DateTime object.
        
        Remark:
        s The hecto-nanoseconds are truncated (not rounded) at the
        millisecond position.
        
        Returns:
        Milliseconds (0 through 999)
        """
        ...
    
    def GetMinute(*args, **kwargs):
        """
        GetMinute(self: MSPyBentley.BeDateTime) -> int
        
        Gets the minute component of this DateTime object.
        
        Returns:
        Minutes (0 through 59)
        """
        ...
    
    def GetMonth(*args, **kwargs):
        """
        GetMonth(self: MSPyBentley.BeDateTime) -> int
        
        Gets the month component of this DateTime object.
        
        Returns:
        Month (1 through 12).
        """
        ...
    
    def GetSecond(*args, **kwargs):
        """
        GetSecond(self: MSPyBentley.BeDateTime) -> int
        
        Gets the second component of this DateTime object.
        
        Returns:
        Seconds (0 through 59)
        """
        ...
    
    def GetYear(*args, **kwargs):
        """
        GetYear(self: MSPyBentley.BeDateTime) -> int
        
        Gets the year component of this DateTime object.
        
        Returns:
        Year (negative if BCE, positive otherwise).
        """
        ...
    
    @property
    def HectoNanosecond(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    @property
    def Hour(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    @property
    def Info(arg0: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTimeInfo:
        ...
    
    def IsLeapYear(*args, **kwargs):
        """
        IsLeapYear(year: int) -> bool
        
        Indicates whether the specified year is a leap year or not
        
        Returns:
        true, if ``year`` is a leap year. false, otherwise.
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyBentley.BeDateTime) -> bool
        
        Indicates whether this DateTime instance is a valid date/time or not.
        
        Remark:
        s Using the default constructor creates an invalid date time as
        none of the components have been set.
        
        Returns:
        true, if the DateTime instance is valid, false otherwise
        """
        ...
    
    def JulianDayToCommonEraTicks(*args, **kwargs):
        """
        JulianDayToCommonEraTicks(julianDayInHectoNanoseconds: int) -> int
        
        Computes Common Era ticks from the given the Julian Day number. The
        Common Era begins at 0001-01-01 00:00:00 UTC.
        
        Parameter `` in ``:
        julianDayInHectoNanoseconds Julian Day number
        
        Returns:
        Common Era ticks in hecto-nanoseconds
        """
        ...
    
    def JulianDayToUnixMilliseconds(*args, **kwargs):
        """
        JulianDayToUnixMilliseconds(julianDayInHectoNanoseconds: int) -> int
        
        Computes the Unix milliseconds from the given Julian Day number.
        
        Parameter `` in ``:
        julianDayInHectoNanoseconds Julian day in hecto-
        nanoseconds.unixMilliseconds Unix milliseconds.
        
        Returns:
        Unix milliseconds. Negative numbers indicate dates before the Unix
        epoch.
        """
        ...
    
    class Kind:
        """
        Specifies whether a DateTime represents a local time, a Coordinated Universal Time (UTC),  or is not specified as either local time or UTC.
        
        Members:
        
        eUnspecified
        
        eUtc
        
        eLocal
        """
    
        def __init__(self: MSPyBentley.BeDateTime.Kind, value: int) -> None:
            ...
        
        eLocal: Kind
        
        eUnspecified: Kind
        
        eUtc: Kind
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyBentley.BeDateTime.Kind) -> int:
            ...
        
    @property
    def Millisecond(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    @property
    def Minute(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    @property
    def Month(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    @property
    def Second(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    def ToCommonEraTicks(*args, **kwargs):
        """
        ToCommonEraTicks(self: MSPyBentley.BeDateTime) -> tuple
        """
        ...
    
    def ToJulianDay(*args, **kwargs):
        """
        ToJulianDay(self: MSPyBentley.BeDateTime) -> tuple
        """
        ...
    
    def ToJulianDayInHns(*args, **kwargs):
        """
        ToJulianDayInHns(self: MSPyBentley.BeDateTime) -> tuple
        """
        ...
    
    def ToLocalTime(*args, **kwargs):
        """
        ToLocalTime(self: MSPyBentley.BeDateTime, localDateTime: MSPyBentley.BeDateTime) -> Bentley.BentleyStatus
        
        Converts this UTC DateTime to local time
        
        Parameter `` out ``:
        localDateTime Resulting DateTime object in local time
        
        Returns:
        SUCCESS if successful. ERROR in case of errors, e.g. if this date
        time instance is invalid (see DateTime.IsValid) or if computation
        of local time zone offset failed.
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyBentley.BeDateTime) -> MSPyBentley.WString
        
        Converts the value of this DateTime into a string representation.
        
        Remark:
        s The resulting string is formatted according to the ISO8601
        standard. Second fractions are rounded to milliseconds.
        
        Returns:
        String representation of this DateTime object. An empty string is
        returned if this date time info object is not valid (see
        DateTime.IsValid )
        """
        ...
    
    def ToUnixMilliseconds(*args, **kwargs):
        """
        ToUnixMilliseconds(self: MSPyBentley.BeDateTime) -> tuple
        """
        ...
    
    def ToUtc(*args, **kwargs):
        """
        ToUtc(self: MSPyBentley.BeDateTime, utcDateTime: MSPyBentley.BeDateTime) -> Bentley.BentleyStatus
        
        Converts this local DateTime to UTC
        
        Parameter `` out ``:
        utcDateTime Resulting DateTime object in UTC
        
        Returns:
        SUCCESS if successful. ERROR in case of errors, e.g. if this date
        time instance is invalid (see DateTime.IsValid) or if computation
        of local time zone offset failed.
        """
        ...
    
    def ToUtf8String(*args, **kwargs):
        """
        ToUtf8String(self: MSPyBentley.BeDateTime) -> MSPyBentley.Utf8String
        
        Converts the value of this DateTime into a string representation.
        
        Remark:
        s The resulting string is formatted according to the ISO8601
        standard. Second fractions are rounded to milliseconds.
        
        Returns:
        String representation of this DateTime object. An empty string is
        returned if this date time info object is not valid (see
        DateTime.IsValid )
        """
        ...
    
    def UnixMillisecondsToJulianDay(*args, **kwargs):
        """
        UnixMillisecondsToJulianDay(unixMilliseconds: int) -> int
        
        Computes the Julian Day number from the given Unix milliseconds.
        
        Parameter `` in ``:
        unixMilliseconds Unix milliseconds. Negative numbers indicate
        dates before the Unix epoch.
        
        Returns:
        Julian Day number in hecto-nanoseconds
        """
        ...
    
    @property
    def Year(arg0: MSPyBentley.BeDateTime) -> int:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.BeDateTime) -> None
        
        Initializes a new empty instance of the DateTime struct.
        
        2. __init__(self: MSPyBentley.BeDateTime, year: int, month: int, day: int) -> None
        
        3. __init__(self: MSPyBentley.BeDateTime, kind: MSPyBentley.BeDateTime.Kind, year: int, month: int, day: int, hour: int, minute: int, second: int = 0, hectoNansecond: int = 0) -> None
        """
        ...
    
    eDate: Component
    
    eDateAndTime: Component
    
    eEarlierThan: CompareResult
    
    eEquals: CompareResult
    
    eError: CompareResult
    
    eFriday: DayOfWeek
    
    eLaterThan: CompareResult
    
    eLocal: Kind
    
    eMonday: DayOfWeek
    
    eSaturday: DayOfWeek
    
    eSunday: DayOfWeek
    
    eThursday: DayOfWeek
    
    eTuesday: DayOfWeek
    
    eUnspecified: Kind
    
    eUtc: Kind
    
    eWednesday: DayOfWeek
    
class BeDateTimeInfo:
    """
    Provides the metadata portion of a DateTime object.
    """

    @property
    def Component(arg0: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Component:
        ...
    
    def ComponentToString(*args, **kwargs):
        """
        ComponentToString(component: MSPyBentley.BeDateTime.Component) -> MSPyBentley.WString
        """
        ...
    
    def GetComponent(*args, **kwargs):
        """
        GetComponent(self: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Component
        """
        ...
    
    def GetKind(*args, **kwargs):
        """
        GetKind(self: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Kind
        
        Gets the DateTime kind.
        """
        ...
    
    @property
    def Kind(arg0: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Kind:
        ...
    
    def KindToString(*args, **kwargs):
        """
        KindToString(kind: MSPyBentley.BeDateTime.Kind) -> MSPyBentley.WString
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.BeDateTimeInfo) -> None
        
        Initializes a new instance of the Info class.
        
        2. __init__(self: MSPyBentley.BeDateTimeInfo, kind: MSPyBentley.BeDateTime.Kind, component: MSPyBentley.BeDateTime.Component) -> None
        """
        ...
    
class BeFile:
    """
    BeFile provides a way to open a file and methods to access its contents and attributes.
    """

    @property
    def Access(arg0: MSPyBentley.BeFile) -> MSPyBentley.BeFileAccess:
        ...
    
    def Close(*args, **kwargs):
        """
        Close(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus
        
        Closes the disk file.
        """
        ...
    
    def Create(*args, **kwargs):
        """
        Create(self: MSPyBentley.BeFile, fileName: str, createAlways: bool = True, attribute: MSPyBentley.BeFileAttributes = <BeFileAttributes.eNormal: 0>) -> MSPyBentley.BeFileStatus
        
        Creates a new disk file
        
        Parameter ``filename``:
        The full path of the file to create.
        
        Parameter ``createAlways``:
        If false, returns a status other than BeFileStatus.Success, and
        does not create a new file if *filename* already exists. If true,
        deletes any existing file before creating a new one by the same
        name.
        
        Parameter ``attributes``:
        File attributes.
        
        Returns:
        BeFileStatus.Success if the file was created or non-zero if
        create failed.
        """
        ...
    
    def Flush(*args, **kwargs):
        """
        Flush(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus
        
        Flushes all pending writes to the file
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def GetAccess(*args, **kwargs):
        """
        GetAccess(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileAccess
        
        Gets the access mode used to open the disk file.
        """
        ...
    
    def GetLastError(*args, **kwargs):
        """
        GetLastError(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus
        
        Gets the status returned by the last operation that failed.
        """
        ...
    
    def GetPointer(*args, **kwargs):
        """
        GetPointer(self: MSPyBentley.BeFile) -> tuple
        
        Gets the file read/write position
        
        Parameter ``position``:
        the current read/write position
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def GetShareMode(*args, **kwargs):
        """
        GetShareMode(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileSharing
        
        Gets the sharing option used to open the disk file.
        """
        ...
    
    def GetSize(*args, **kwargs):
        """
        GetSize(self: MSPyBentley.BeFile) -> tuple
        
        Gets the size of the file.
        
        Parameter ``length``:
        The size of the file in bytes
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    @property
    def HasOpen(arg0: MSPyBentley.BeFile) -> bool:
        ...
    
    def IsOpen(*args, **kwargs):
        """
        IsOpen(self: MSPyBentley.BeFile) -> bool
        
        Query whether the disk file is open.
        """
        ...
    
    @property
    def LastError(arg0: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus:
        ...
    
    def Open(*args, **kwargs):
        """
        Open(self: MSPyBentley.BeFile, fileName: str, mode: MSPyBentley.BeFileAccess, shareOptions: MSPyBentley.BeFileSharing, attribute: MSPyBentley.BeFileAttributes = <BeFileAttributes.eNormal: 0>, numRetries: int = 0) -> MSPyBentley.BeFileStatus
        
        Opens an existing file.
        
        Parameter ``filename``:
        The full path the file to open.
        
        Parameter ``mode``:
        The file open mode.
        
        Parameter ``shareOptions``:
        The file sharing options.
        
        Parameter ``attributes``:
        The file attributes.
        
        Parameter ``numRetries``:
        The number of times to retry the open in the event of a sharing
        violation.
        
        Returns:
        BeFileStatus.Success if the file was opened or non-zero if open
        failed.
        """
        ...
    
    def Read(*args, **kwargs):
        """
        Read(self: MSPyBentley.BeFile, numBytes: int) -> tuple
        """
        ...
    
    def ReadEntireFile(*args, **kwargs):
        """
        ReadEntireFile(*args, **kwargs)
        Overloaded function.
        
        1. ReadEntireFile(self: MSPyBentley.BeFile, buffer: MSPyBentley.UInt8Array) -> MSPyBentley.BeFileStatus
        
        Reads entire file to a byte vector.
        
        2. ReadEntireFile(self: MSPyBentley.BeFile, byteStream: Bentley.ByteStream) -> MSPyBentley.BeFileStatus
        
        Reads entire file to a byte vector.
        """
        ...
    
    def SetPointer(*args, **kwargs):
        """
        SetPointer(self: MSPyBentley.BeFile, position: int, origin: MSPyBentley.BeFileSeekOrigin) -> MSPyBentley.BeFileStatus
        
        Moves the file read/write position.
        
        Parameter ``position``:
        The new read/write position.
        
        Parameter ``origin``:
        The origin mode for the move.
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def SetSize(*args, **kwargs):
        """
        SetSize(self: MSPyBentley.BeFile, length: int) -> MSPyBentley.BeFileStatus
        
        Sets the size of the file.
        
        Parameter ``length``:
        The new size of the file in bytes.
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    @property
    def ShareMode(arg0: MSPyBentley.BeFile) -> MSPyBentley.BeFileSharing:
        ...
    
    def Swap(*args, **kwargs):
        """
        Swap(self: MSPyBentley.BeFile, other: MSPyBentley.BeFile) -> None
        
        Swap file handles between two BeFile instances.
        
        Parameter ``other``:
        The other file.
        """
        ...
    
    def Write(*args, **kwargs):
        """
        Write(self: MSPyBentley.BeFile, data: bytes) -> tuple
        """
        ...
    
    def __init__(self: MSPyBentley.BeFile) -> None:
        ...
    
class BeFileAccess:
    """
    Members:
    
    eRead
    
    eWrite
    
    eReadWrite
    """

    def __init__(self: MSPyBentley.BeFileAccess, value: int) -> None:
        ...
    
    eRead: BeFileAccess
    
    eReadWrite: BeFileAccess
    
    eWrite: BeFileAccess
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileAccess) -> int:
        ...
    
class BeFileAttributes:
    """
    Members:
    
    eNormal
    
    eRandomIO
    
    eDeleteOnClose
    """

    def __init__(self: MSPyBentley.BeFileAttributes, value: int) -> None:
        ...
    
    eDeleteOnClose: BeFileAttributes
    
    eNormal: BeFileAttributes
    
    eRandomIO: BeFileAttributes
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileAttributes) -> int:
        ...
    
class BeFileListIterator:
    """
    None
    """

    def GetNextFileName(*args, **kwargs):
        """
        GetNextFileName(self: MSPyBentley.BeFileListIterator, fileName: Bentley.BeFileName) -> Bentley.BentleyStatus
        
        Retrieve the next filename found from the path list.
        
        Parameter ``name``:
        The name of the next valid file from the path list.
        
        Returns:
        SUCCESS if the name returned is valid, ERROR if there are no more
        files.
        """
        ...
    
    def __init__(self: MSPyBentley.BeFileListIterator, filePathList: str, recursive: bool) -> None:
        ...
    
class BeFileName:
    """
    Represents a filename and provides functions to manipulate the filename and to work with files on disk by name.
    See DgnFile for a class that works with open files.
    @remarks This implementation handles filenames up to MAX_PATH-1 in length, and it
    guarantees to hold the name in a fixed-length buffer of MAX_PATH chars (including the 0-terminator).
    """

    def Abbreviate(*args, **kwargs):
        """
        Abbreviate(self: MSPyBentley.BeFileName, maxLength: int) -> None
        """
        ...
    
    def AddQuotes(*args, **kwargs):
        """
        AddQuotes(self: MSPyBentley.WString) -> None
        
        Put quotes around a string.
        """
        ...
    
    def AppendA(*args, **kwargs):
        """
        AppendA(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Append a null-terminated multibyte, locale-encoded character array to
        this WString. This will create a WString internally, so if you are
        appending a character constant it is more efficient to use append
        (L"string to append").
        
        Parameter ``in``:
        The multibyte string
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AppendExtension(*args, **kwargs):
        """
        AppendExtension(self: MSPyBentley.BeFileName, extension: str) -> MSPyBentley.BeFileName
        
        Append *extension* to this filepath. A period is inserted, if
        necessary, before *extension.*
        """
        ...
    
    def AppendSeparator(*args, **kwargs):
        """
        AppendSeparator(self: MSPyBentley.BeFileName) -> None
        
        Make sure *dir* ends with a directory separator
        """
        ...
    
    def AppendSeparatorS(*args, **kwargs):
        """
        AppendSeparatorS(arg0: MSPyBentley.WString) -> None
        
        Make sure *dir* ends with a directory separator
        """
        ...
    
    def AppendString(*args, **kwargs):
        """
        AppendString(self: MSPyBentley.BeFileName, string: str) -> None
        
        Append string.
        """
        ...
    
    def AppendToPath(*args, **kwargs):
        """
        AppendToPath(self: MSPyBentley.BeFileName, additionalComponent: str) -> MSPyBentley.BeFileName
        
        Append *additionComponent* to this filepath. A directory separator
        character is inserted, if necessary, before *additionComponent.*
        """
        ...
    
    def AppendUtf8(*args, **kwargs):
        """
        AppendUtf8(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Append a Utf8 character array to this WString. This will create a
        WString internally, so if you are appending a character constant it is
        more efficient to use append (L"string to append").
        
        Parameter ``in``:
        The multibyte string
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AreSameFile(*args, **kwargs):
        """
        AreSameFile(file1: str, file2: str) -> bool
        
        Are two filenames equivalent?
        
        Parameter ``file1``:
        name of a file
        
        Parameter ``file2``:
        name of another file
        
        Returns:
        true if the two strings are aliases for the same (existing)
        physical file.
        """
        ...
    
    def AssignA(*args, **kwargs):
        """
        AssignA(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Define the contents of this WString from a CharCP using the current
        system locale
        
        Parameter ``in``:
        The ASCII string
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AssignOrClear(*args, **kwargs):
        """
        AssignOrClear(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        """
        ...
    
    def AssignUtf16(*args, **kwargs):
        """
        AssignUtf16(self: MSPyBentley.WString, in: int) -> MSPyBentley.WString
        
        Define the contents of this WString from a Utf8CP
        
        Parameter ``in``:
        The Utf8 string. May be NULL.
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AssignUtf8(*args, **kwargs):
        """
        AssignUtf8(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Define the contents of this WString from a Utf8CP
        
        Parameter ``in``:
        The Utf8 string. May be NULL.
        
        Returns:
        Reference to this string.
        """
        ...
    
    def BeCompactPath(*args, **kwargs):
        """
        BeCompactPath(shortened: MSPyBentley.WString, path: str, length: int) -> Bentley.BentleyStatus
        
        Shortens a file path to be no longer than the specified number of
        characters.
        
        Parameter ``shortened``:
        the string shortened to the specified length
        
        Parameter ``path``:
        the original path
        
        Parameter ``length``:
        the number of characters to display in the shortened string
        @Return non-zero error status if not successful
        """
        ...
    
    def BeCopyFile(*args, **kwargs):
        """
        BeCopyFile(existingFileName: str, newFileName: str, failIfFileExists: bool = False) -> MSPyBentley.BeFileNameStatus
        
        Copy an existing file. If a file with the new name already exists, it
        is overwritten.
        
        Parameter ``newFileName``:
        The name for the newly copied file.
        
        Parameter ``existingFileName``:
        The name for the source file.
        
        Parameter ``failIfFileExists``:
        Do not copy and return error if the destination file already
        exists.
        
        Returns:
        DGNFILE_STATUS_Success if the file was successfully copied.
        """
        ...
    
    def BeDeleteFile(*args, **kwargs):
        """
        BeDeleteFile(fileName: str, removeReadOnlyAttribute: bool = False) -> MSPyBentley.BeFileNameStatus
        
        Delete an existing file.
        
        Parameter ``fileNameP``:
        The name of an existing file.
        
        Parameter ``removeReadOnlyAttribute``:
        Remove read-only attribute for the file before making an
        attempting to delete it.
        
        Returns:
        BeFileNameStatus.Success if the file was successfully deleted or
        BeFileNameStatus.CantDeleteFile if not.
        """
        ...
    
    def BeGetDiskFreeSpace(*args, **kwargs):
        """
        BeGetDiskFreeSpace(dirName: str) -> tuple
        
        Get free space on disk
        
        Parameter ``freeBytes``:
        The amount of free space on the storage device, in bytes
        
        Parameter ``dirName``:
        The name of a file or directory on the device to check
        
        Returns:
        BeFileNameStatus.Success, if the query succeeded. Non-zero if the
        directory is invalid or refers to a storage device that does not
        exist.
        """
        ...
    
    def BeGetFullPathName(*args, **kwargs):
        """
        BeGetFullPathName(path: MSPyBentley.WString, src: str) -> MSPyBentley.BeFileNameStatus
        
        Get the full name of a file
        
        Remark:
        s this function does not check that the file or path exists
        """
        ...
    
    def BeGetTempFileName(*args, **kwargs):
        """
        BeGetTempFileName(tempFileName: MSPyBentley.BeFileName, pathName: MSPyBentley.BeFileName, prefixString: str) -> MSPyBentley.BeFileNameStatus
        
        Generate a unique name for a temporary file.
        
        Parameter ``tempFileName``:
        The name for a temporary file.
        
        Parameter ``pathName``:
        The path to contain the temp file. If NULL, the result of
        BeGetTempPath is used.
        
        Parameter ``prefixString``:
        up to 3 chars of this will be used in the generated filename
        
        Returns:
        BeFileNameStatus.Success, if the directory for the temporary file
        exists or was created. @note This method does not create a
        temporary file, it merely returns a name that can be used to
        create a temporary file.
        """
        ...
    
    def BeGetTempPath(*args, **kwargs):
        """
        BeGetTempPath(tempFileName: MSPyBentley.BeFileName) -> MSPyBentley.BeFileNameStatus
        
        Retrieves the path of the directory for temporary files.
        
        Parameter ``tempFileName``:
        The name for a temporary file.
        
        Returns:
        BeFileNameStatus.Success, if the directory for the temporary file
        exists or was created.
        """
        ...
    
    def BeMoveFile(*args, **kwargs):
        """
        BeMoveFile(oldFileName: str, newFileName: str, numRetries: int = 0) -> MSPyBentley.BeFileNameStatus
        
        Move or rename an existing file.
        
        Parameter ``oldFileName``:
        The name of an existing file.
        
        Parameter ``newFileName``:
        The new name for the file.
        
        Parameter ``numRetries``:
        the number of times to retry the open in the event of a sharing
        violation
        
        Returns:
        BeFileNameStatus.Success if the file was successfully moved or
        BeFileNameStatus.UnknownError if not.
        """
        ...
    
    def BuildName(*args, **kwargs):
        """
        BuildName(self: MSPyBentley.BeFileName, dev: str, dir: str, name: str, ext: str) -> None
        
        Build a BeFileName from parts of a pathname. Any values that are NULL
        are omitted.
        """
        ...
    
    def CheckAccess(*args, **kwargs):
        """
        CheckAccess(fileName: str, access: MSPyBentley.BeFileNameAccess) -> MSPyBentley.BeFileNameStatus
        
        Check user's access to a file
        
        Parameter ``fileName``:
        The name of an existing file.
        
        Parameter ``accs``:
        The kinds of access to check for
        
        Returns:
        BeFileNameStatus.Success if all of the specified access rights
        are granted; non-zero if the file does not exist or some of the
        specified rights are not granted.
        """
        ...
    
    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyBentley.BeFileName) -> None
        
        Clear the value of this BeFileName.
        """
        ...
    
    def CloneDirectory(*args, **kwargs):
        """
        CloneDirectory(sourceDir: str, destDir: str, includeSubDirs: bool = True) -> MSPyBentley.BeFileNameStatus
        
        Clone the contents of an existing directory, and optionally its
        subdirectories, into a new directory.
        
        Parameter ``destDir``:
        The name for the new directory.
        
        Parameter ``sourceDir``:
        The source directory to clone.
        
        Parameter ``includeSubDirs``:
        If true, also clone all subdirectories, recursively.
        
        Returns:
        DGNFILE_STATUS_Success if the directory was successfully cloned.
        """
        ...
    
    def CompareTo(*args, **kwargs):
        """
        CompareTo(*args, **kwargs)
        Overloaded function.
        
        1. CompareTo(self: MSPyBentley.WString, other: str) -> int
        
        Perform a (case-sensitive) comparison.
        
        Returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        Parameter ``other``:
        The other string.
        
        2. CompareTo(self: MSPyBentley.WString, other: MSPyBentley.WString) -> int
        
        Perform a (case-sensitive) comparison.
        
        Returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def CompareToI(*args, **kwargs):
        """
        CompareToI(*args, **kwargs)
        Overloaded function.
        
        1. CompareToI(self: MSPyBentley.WString, other: str) -> int
        
        Perform a case-insensitive comparison.
        
        Returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        Parameter ``other``:
        The other string.
        
        2. CompareToI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> int
        
        Perform a case-insensitive comparison.
        
        Returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def Contains(*args, **kwargs):
        """
        Contains(*args, **kwargs)
        Overloaded function.
        
        1. Contains(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        
        2. Contains(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for whether this string contains another string.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        """
        ...
    
    def ContainsI(*args, **kwargs):
        """
        ContainsI(*args, **kwargs)
        Overloaded function.
        
        1. ContainsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        
        2. ContainsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        """
        ...
    
    def CreateNewDirectory(*args, **kwargs):
        """
        CreateNewDirectory(path: str) -> MSPyBentley.BeFileNameStatus
        
        Create a new directory.
        
        Parameter ``path``:
        The pathname for the new directory.
        
        Returns:
        DGNFILE_STATUS_Success if the directory was successfully created.
        @note this method will return an error if the directory already
        exists.
        """
        ...
    
    def DoesPathExist(*args, **kwargs):
        """
        DoesPathExist(path: str) -> bool
        
        Test whether a pathname refers to an existing file or directory.
        
        Parameter ``path``:
        The pathname to test.
        
        Returns:
        true if the pathname refers to an existing file or directory.
        """
        ...
    
    def DropQuotes(*args, **kwargs):
        """
        DropQuotes(self: MSPyBentley.WString) -> None
        
        Remove quotes from around a string.
        """
        ...
    
    def EmptyAndRemoveDirectory(*args, **kwargs):
        """
        EmptyAndRemoveDirectory(path: str) -> MSPyBentley.BeFileNameStatus
        
        Recursively empty all of the contents of an existing directory and
        then remove it.
        
        Parameter ``path``:
        The pathname for the directory to remove.
        
        Returns:
        DGNFILE_STATUS_Success if the directory was successfully removed.
        """
        ...
    
    def EndsWith(*args, **kwargs):
        """
        EndsWith(self: MSPyBentley.WString, endChars: str) -> bool
        
        Determines if this instance ends with the provided string.
        """
        ...
    
    def EndsWithI(*args, **kwargs):
        """
        EndsWithI(self: MSPyBentley.WString, endChars: str) -> bool
        
        Determines if this instance ends with the provided string, ignoring
        case.
        """
        ...
    
    def Equals(*args, **kwargs):
        """
        Equals(*args, **kwargs)
        Overloaded function.
        
        1. Equals(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string.
        
        Returns:
        true if the strings are equal.
        
        Parameter ``other``:
        The other string.
        
        2. Equals(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for equality with another string.
        
        Returns:
        true if the strings are equal.
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def EqualsI(*args, **kwargs):
        """
        EqualsI(*args, **kwargs)
        Overloaded function.
        
        1. EqualsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        
        2. EqualsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    class FileNameParts:
        """
        Members:
        
        eDevice
        
        eDirectory
        
        eBasename
        
        eExtension
        
        eDevAndDir
        
        eNameAndExt
        
        eAll
        """
    
        def __init__(self: MSPyBentley.BeFileName.FileNameParts, value: int) -> None:
            ...
        
        eAll: FileNameParts
        
        eBasename: FileNameParts
        
        eDevAndDir: FileNameParts
        
        eDevice: FileNameParts
        
        eDirectory: FileNameParts
        
        eExtension: FileNameParts
        
        eNameAndExt: FileNameParts
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyBentley.BeFileName.FileNameParts) -> int:
            ...
        
    def FindI(*args, **kwargs):
        """
        FindI(self: MSPyBentley.WString, findString: str) -> int
        
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def FindRelativePath(*args, **kwargs):
        """
        FindRelativePath(relativePath: MSPyBentley.WString, targetFileName: str, rootFileName: str) -> None
        
        Finds the relative path from a root file to the target file. If the
        files are on different devices, targetFileName is copied to
        relativePath.
        
        Parameter ``relativePath``:
        OUT the relative path to the target file
        
        Parameter ``targetFileName``:
        IN the full file specification of the file the relative path is
        needed for.
        
        Parameter ``rootFileName``:
        IN the full file specification of the root for the relative path.
        """
        ...
    
    def FixPathName(*args, **kwargs):
        """
        FixPathName(path: MSPyBentley.WString, original: str) -> MSPyBentley.BeFileNameStatus
        
        Perform any platform-specific fixes of an input pathname into a
        " canonical " pathname. On Windows, this includes converting forward
        slashes to backslashes and removing double backslashes. It also
        removes " \ " and " \ " notation. On other platforms those rules may be
        different.
        
        Parameter ``path``:
        The " fixed " version of the pathname.
        
        Parameter ``original``:
        The " raw " pathname.
        
        Returns:
        DGNFILE_STATUS_Success if the pathname was successfully " fixed "
        (whether any changes were made or not), or PATH_IllegalName if the
        pathname is invalid for any reason.
        """
        ...
    
    def GetDevice(*args, **kwargs):
        """
        GetDevice(path: str) -> MSPyBentley.WString
        
        Returns the device letter from path - Empty if the path doesn't start
        with a device. Always empty on unix.
        """
        ...
    
    def GetDirectoryName(*args, **kwargs):
        """
        GetDirectoryName(path: str) -> MSPyBentley.WString
        
        Returns the complete directory (including drive, if any) from path.
        Has terminating separator.
        """
        ...
    
    def GetDirectoryWithoutDevice(*args, **kwargs):
        """
        GetDirectoryWithoutDevice(path: str) -> MSPyBentley.WString
        
        Returns the directory (excluding drive) from path. Has terminating
        separator.
        """
        ...
    
    def GetExtension(*args, **kwargs):
        """
        GetExtension(path: str) -> MSPyBentley.WString
        
        Returns the filename extension from path (everything following the
        last dot non-inclusive), or empty if there is none.
        """
        ...
    
    def GetFileNameAndExtension(*args, **kwargs):
        """
        GetFileNameAndExtension(path: str) -> MSPyBentley.WString
        
        Returns the filename from path, including extension, but not
        directory.
        """
        ...
    
    def GetFileNameWithoutExtension(*args, **kwargs):
        """
        GetFileNameWithoutExtension(path: str) -> MSPyBentley.WString
        
        Returns the base filename from path, with no directory or extension.
        """
        ...
    
    def GetFileSize(*args, **kwargs):
        """
        GetFileSize(fileName: str) -> tuple
        
        Get file size
        @param in  fileName The name of an existing file.
        @return the file size
        """
        ...
    
    def GetFullPathName(*args, **kwargs):
        """
        GetFullPathName(self: MSPyBentley.BeFileName) -> MSPyBentley.BeFileNameStatus
        """
        ...
    
    def GetMaxLocaleCharBytes(*args, **kwargs):
        """
        GetMaxLocaleCharBytes(self: MSPyBentley.WString) -> int
        
        Get the number of bytes required to hold the current string. This is
        the value to use to allocate a buffer (e.g. via _alloca) to to call
        #ConvertToLocaleChars.
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyBentley.BeFileName) -> str
        
        Copy name into WChar buffer.
        """
        ...
    
    def GetTargetOfSymbolicLink(*args, **kwargs):
        """
        GetTargetOfSymbolicLink(*args, **kwargs)
        Overloaded function.
        
        1. GetTargetOfSymbolicLink(targetFileName: MSPyBentley.BeFileName, path: str) -> Bentley.BentleyStatus
        
        Determines a symbolic link's target. This recurses, meaning that it
        keeps evaluating each incremental target until it reaches a concrete
        file, or the target does not exist.
        
        2. GetTargetOfSymbolicLink(targetFileName: MSPyBentley.BeFileName, path: str, shouldRecurse: bool) -> Bentley.BentleyStatus
        
        Determines a symbolic link's target. This recurses, meaning that it
        keeps evaluating each incremental target until it reaches a concrete
        file, or the target does not exist.
        """
        ...
    
    def GetUri(*args, **kwargs):
        """
        GetUri(self: MSPyBentley.BeFileName) -> MSPyBentley.Utf8String
        
        Get the URI for this BeFileName.
        """
        ...
    
    def GetWCharCP(*args, **kwargs):
        """
        GetWCharCP(self: MSPyBentley.WString) -> str
        
        Equivalent to c_str
        """
        ...
    
    def IsAbsolutePath(*args, **kwargs):
        """
        IsAbsolutePath(self: MSPyBentley.BeFileName) -> bool
        
        Test if a filename is an absolute path.
        """
        ...
    
    def IsDirectory(*args, **kwargs):
        """
        IsDirectory(path: str) -> bool
        
        Test whether a pathname refers to an existing directory.
        
        Parameter ``path``:
        The pathname to test.
        
        Returns:
        true if the pathname refers to an existing directory.
        """
        ...
    
    def IsEmpty(*args, **kwargs):
        """
        IsEmpty(self: MSPyBentley.BeFileName) -> bool
        
        Determines if the value of this BeFileName is empty (blank).
        """
        ...
    
    def IsNullOrEmpty(*args, **kwargs):
        """
        IsNullOrEmpty(str: str) -> bool
        
        True if the provided string is NULL or contains no character data.
        """
        ...
    
    def IsRemovableMedia(*args, **kwargs):
        """
        IsRemovableMedia(fileName: str) -> bool
        
        Check if path is located on a removable storage device.
        
        Parameter ``fn``:
        The name of a file or directory on the device to check
        
        Returns:
        true if the storage device is removable
        """
        ...
    
    def IsSymbolicLink(*args, **kwargs):
        """
        IsSymbolicLink(path: str) -> bool
        
        Determines if the path is a symbolic link. If the path does not exist,
        also returns false.
        """
        ...
    
    def IsUrl(*args, **kwargs):
        """
        IsUrl(self: MSPyBentley.BeFileName) -> bool
        
        Test if a filename is an URL.
        """
        ...
    
    def MoveToRecycleBin(*args, **kwargs):
        """
        MoveToRecycleBin(path: str) -> MSPyBentley.BeFileNameStatus
        
        Move an existing file or an existing directory to Recycle Bin (on
        Windows).
        
        Parameter ``path``:
        The pathname for the file or directory to remove.
        
        Returns:
        DGNFILE_STATUS_Success if the target was successfully removed.
        """
        ...
    
    @property
    def Name(arg0: MSPyBentley.BeFileName) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyBentley.BeFileName, arg1: str) -> None:
        ...
    
    def OverrideNameParts(*args, **kwargs):
        """
        OverrideNameParts(self: MSPyBentley.BeFileName, overrideName: str) -> None
        
        Override values for parts of a file name. If the override name
        includes a value for a part of the name, that value is used. Otherwise
        the current value is preserved.
        """
        ...
    
    def PadLeft(*args, **kwargs):
        """
        PadLeft(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None
        
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the left side.
        """
        ...
    
    def PadRight(*args, **kwargs):
        """
        PadRight(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None
        
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the right side.
        """
        ...
    
    def ParseName(*args, **kwargs):
        """
        ParseName(self: MSPyBentley.BeFileName, dev: MSPyBentley.WString, dir: MSPyBentley.WString, name: MSPyBentley.WString, ext: MSPyBentley.WString) -> None
        
        Parse a full filename into WStrings for the device, directory,
        filename, and extension.
        
        Parameter ``dev``:
        The device part of this filename. May be NULL.
        
        Parameter ``dir``:
        The directory part of this filename. May be NULL.
        
        Parameter ``name``:
        The filename part of this filename. May be NULL.
        
        Parameter ``ext``:
        The extension part of this filename. May be NULL.
        
        Parameter ``fullFileName``:
        The filename to parse.
        """
        ...
    
    def ParseNameNoClear(*args, **kwargs):
        """
        ParseNameNoClear(self: MSPyBentley.BeFileName, dev: MSPyBentley.WString, dir: MSPyBentley.WString, name: MSPyBentley.WString, ext: MSPyBentley.WString) -> None
        
        Parse a full filename into WStrings for the device, directory,
        filename, and extension. If the input does not contain a file part,
        the output is not changed.
        
        Parameter ``dev``:
        The device part of this filename. May be NULL.
        
        Parameter ``dir``:
        The directory part of this filename. May be NULL.
        
        Parameter ``name``:
        The filename part of this filename. May be NULL.
        
        Parameter ``ext``:
        The extension part of this filename. May be NULL.
        
        Parameter ``fullFileName``:
        The filename to parse.
        """
        ...
    
    def PopDir(*args, **kwargs):
        """
        PopDir(self: MSPyBentley.BeFileName) -> None
        
        Remove the right-most component from the path. If this BeFileName
        contains a single dirctory (or otherwise contains no directory
        separators), it becomes empty as a result of this function.
        """
        ...
    
    def RemoveQuotes(*args, **kwargs):
        """
        RemoveQuotes(self: MSPyBentley.BeFileName) -> None
        
        Remove enclosing quotes
        """
        ...
    
    def ReplaceAll(*args, **kwargs):
        """
        ReplaceAll(self: MSPyBentley.WString, subStringToReplace: str, replacement: str) -> int
        
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def ReplaceI(*args, **kwargs):
        """
        ReplaceI(self: MSPyBentley.WString, findString: str, replaceString: str) -> bool
        
        Replace first occurrence of findString with replaceString, ignoring
        case.
        
        Parameter ``findString``:
        The substring to find.
        
        Parameter ``replaceString``:
        The replacement string.
        
        Returns:
        true is a replacement is made.
        """
        ...
    
    def ResolveRelativePath(*args, **kwargs):
        """
        ResolveRelativePath(fullPath: MSPyBentley.WString, relativeFileName: str, basePath: str) -> Bentley.BentleyStatus
        
        Generates a fullpath by resolving relativeFileName relative to
        basePath.
        
        Parameter ``fullPath``:
        OUT the full path resolved from the inputs.
        
        Parameter ``relativeFileName``:
        IN the relative file name to resolve.
        
        Parameter ``basePath``:
        IN used as a root for the expansion. @Return non-zero error status
        if not successful @Remarks This function only performs a string
        manipulation. It does not require or make any use of an actual
        file.
        """
        ...
    
    def SetFileReadOnly(*args, **kwargs):
        """
        SetFileReadOnly(fileName: str, readOnly: bool) -> MSPyBentley.BeFileNameStatus
        
        Set the read-only status of an existing file
        
        Parameter ``fileName``:
        The name of an existing file.
        
        Parameter ``readOnly``:
        the desired read-only status
        
        Returns:
        BeFileNameStatus.Success if the operation was successful or non-
        zero if not
        """
        ...
    
    def SetName(*args, **kwargs):
        """
        SetName(self: MSPyBentley.BeFileName, name: str) -> None
        
        Change the value of this BeFileName.
        
        Parameter ``name``:
        The new value for this BeFileName. If NULL, the value is cleared.
        """
        ...
    
    def StartsWith(*args, **kwargs):
        """
        StartsWith(self: MSPyBentley.WString, startChars: str) -> bool
        
        Determines if this instance starts with the provided string.
        """
        ...
    
    def StartsWithI(*args, **kwargs):
        """
        StartsWithI(self: MSPyBentley.WString, startChars: str) -> bool
        
        Determines if this instance starts with the provided string, ignoring
        case.
        """
        ...
    
    def StripSeparatorAtEnd(*args, **kwargs):
        """
        StripSeparatorAtEnd(self: MSPyBentley.BeFileName) -> None
        
        Strip all separators at the end
        """
        ...
    
    def StripSeparatorAtEndS(*args, **kwargs):
        """
        StripSeparatorAtEndS(arg0: MSPyBentley.WString) -> None
        
        Strip all separators at the end
        """
        ...
    
    def StripWhiteSpace(*args, **kwargs):
        """
        StripWhiteSpace(self: MSPyBentley.BeFileName) -> None
        
        Remove white space
        """
        ...
    
    def SupplyDefaultNameParts(*args, **kwargs):
        """
        SupplyDefaultNameParts(self: MSPyBentley.BeFileName, defaultName: str) -> None
        
        Supply default values for parts of a file name. If the existing name
        includes a value for a part of the name, that value is preserved.
        Otherwise the default is used.
        """
        ...
    
    def ToLower(*args, **kwargs):
        """
        ToLower(self: MSPyBentley.WString) -> None
        
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def ToUpper(*args, **kwargs):
        """
        ToUpper(self: MSPyBentley.WString) -> None
        
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def Trim(*args, **kwargs):
        """
        Trim(*args, **kwargs)
        Overloaded function.
        
        1. Trim(self: MSPyBentley.WString, trimCharacters: str) -> None
        
        Removes all whitespace from the left and right sides. Whitespace
        includes space, line feed, carriage return, and tab (e.g. iswspace).
        
        2. Trim(self: MSPyBentley.WString) -> None
        
        Removes all instances of any of the given characters from the left and
        right sides.
        """
        ...
    
    @property
    def Uri(arg0: MSPyBentley.BeFileName) -> MSPyBentley.Utf8String:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.BeFileName) -> None
        
        Construct a blank BeFileName
        
        2. __init__(self: MSPyBentley.BeFileName, name: str) -> None
        
        Construct a BeFileName from a null-terminated string.
        
        3. __init__(self: MSPyBentley.BeFileName, mask: MSPyBentley.BeFileName.FileNameParts, fullName: str) -> None
        
        Construct a BeFileName from parts of another full filename. Only the parts of the name where the corresponding argument is true are copied.
        @param in  mask     Mask of the parts of fullName that will used to construct this BeFileName
        @param in  fullName The full pathname from which this BeFileName is to be constructed.
        
        4. __init__(self: MSPyBentley.BeFileName, dev: str, dir: str, name: str, ext: str) -> None
        
        Construct a BeFileName from parts of a pathname. Any values that are NULL are omitted.
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.WString) -> None
        """
        ...
    
    eAll: FileNameParts
    
    eBasename: FileNameParts
    
    eDevAndDir: FileNameParts
    
    eDevice: FileNameParts
    
    eDirectory: FileNameParts
    
    eExtension: FileNameParts
    
    eNameAndExt: FileNameParts
    
    def substr(*args, **kwargs):
        """
        substr(self: MSPyBentley.WString, pos: int = 0, n: int = 18446744073709551615) -> MSPyBentley.WString
        
        Get a substring.
        
        Parameter ``__pos``:
        Index of first character (default 0).
        
        Parameter ``__n``:
        Number of characters in substring (default remainder).
        
        Returns:
        The new string.
        
        Throws:
        std.out_of_range If pos > size().
        
        Construct and return a new string using the *__n* characters starting
        at *__pos.* If the string is too short, use the remainder of the
        characters. If *__pos* is beyond the end of the string, out_of_range
        is thrown.
        """
        ...
    
class BeFileNameAccess:
    """
    Members:
    
    eExists
    
    eRead
    
    eWrite
    
    eReadWrite
    """

    def __init__(self: MSPyBentley.BeFileNameAccess, value: int) -> None:
        ...
    
    eExists: BeFileNameAccess
    
    eRead: BeFileNameAccess
    
    eReadWrite: BeFileNameAccess
    
    eWrite: BeFileNameAccess
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileNameAccess) -> int:
        ...
    
class BeFileNameStatus:
    """
    Members:
    
    eSuccess
    
    eIllegalName
    
    eAlreadyExists
    
    eCantCreate
    
    eFileNotFound
    
    eCantDeleteFile
    
    eAccessViolation
    
    eCantDeleteDir
    
    eUnknownError
    """

    def __init__(self: MSPyBentley.BeFileNameStatus, value: int) -> None:
        ...
    
    eAccessViolation: BeFileNameStatus
    
    eAlreadyExists: BeFileNameStatus
    
    eCantCreate: BeFileNameStatus
    
    eCantDeleteDir: BeFileNameStatus
    
    eCantDeleteFile: BeFileNameStatus
    
    eFileNotFound: BeFileNameStatus
    
    eIllegalName: BeFileNameStatus
    
    eSuccess: BeFileNameStatus
    
    eUnknownError: BeFileNameStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileNameStatus) -> int:
        ...
    
class BeFileSeekOrigin:
    """
    Members:
    
    eBegin
    
    eCurrent
    
    eEnd
    """

    def __init__(self: MSPyBentley.BeFileSeekOrigin, value: int) -> None:
        ...
    
    eBegin: BeFileSeekOrigin
    
    eCurrent: BeFileSeekOrigin
    
    eEnd: BeFileSeekOrigin
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileSeekOrigin) -> int:
        ...
    
class BeFileSharing:
    """
    Members:
    
    eNone
    
    eRead
    
    eWrite
    
    eReadWrite
    """

    def __init__(self: MSPyBentley.BeFileSharing, value: int) -> None:
        ...
    
    eNone: BeFileSharing
    
    eRead: BeFileSharing
    
    eReadWrite: BeFileSharing
    
    eWrite: BeFileSharing
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileSharing) -> int:
        ...
    
class BeFileStatus:
    """
    Members:
    
    eSuccess
    
    eFileNotFoundError
    
    eAccessViolationError
    
    eSharingViolationError
    
    eTooManyOpenFilesError
    
    eFileNotOpenError
    
    eNotLockedError
    
    eReadError
    
    eUnknownError
    """

    def __init__(self: MSPyBentley.BeFileStatus, value: int) -> None:
        ...
    
    eAccessViolationError: BeFileStatus
    
    eFileNotFoundError: BeFileStatus
    
    eFileNotOpenError: BeFileStatus
    
    eNotLockedError: BeFileStatus
    
    eReadError: BeFileStatus
    
    eSharingViolationError: BeFileStatus
    
    eSuccess: BeFileStatus
    
    eTooManyOpenFilesError: BeFileStatus
    
    eUnknownError: BeFileStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.BeFileStatus) -> int:
        ...
    
def BeGetComputerName(*args, **kwargs):
    """
    BeGetComputerName(arg0: MSPyBentley.WString) -> Bentley.BentleyStatus
    """
    ...

def BeGetComputerNameA(*args, **kwargs):
    """
    BeGetComputerNameA(arg0: MSPyBentley.AString) -> Bentley.BentleyStatus
    """
    ...

def BeGetUserName(*args, **kwargs):
    """
    BeGetUserName(arg0: MSPyBentley.WString) -> Bentley.BentleyStatus
    """
    ...

def BeGetUserNameA(*args, **kwargs):
    """
    BeGetUserNameA(arg0: MSPyBentley.AString) -> Bentley.BentleyStatus
    """
    ...

class BeStringUtilities:
    """
    None
    """

    AsManyAsPossible: int
    
    def FormatUInt64(*args, **kwargs):
        """
        FormatUInt64(dest: MSPyBentley.WString, val: int, opts: MSPyBentley.HexFormatOptions, width: int = 0, precision: int = 1) -> int
        
        Formats an unsigned 64-bit integer using the same options supported by
        printf's " % x " and " % X " specifiers.
        
        Parameter ``dest``:
        The buffer which will hold the string representation of the
        integer. Must not be NULL.
        
        Parameter ``numCharsInBuffer``:
        The maximum number of characters which can be written to *dest,*
        including the null terminator. Must be at least 1.
        
        Parameter ``val``:
        The value to format
        
        Parameter ``opts``:
        Flags indicating how formatting should be applied
        
        Parameter ``width``:
        The minimum number of characters in the formatted string.
        Additional characters will be added according to *opts.* Width >
        18 will be truncated to 18.
        
        Parameter ``precision``:
        The minimum number of digits in the formatted string. Leading
        zeros will be prepended to match the precision. Precision> 16
        will be truncated to 16.
        
        Returns:
        Returns the number of characters written to *dest,* not including
        the null terminator
        
        Remark:
        s If the length of the formatted string exceeds
        *numCharsInBuffer,* the string is truncated (i.e.,
        dest\[numCharsInBuffer-1\] = 0;)
        
        Remark:
        s This method is provided to produce the same hexadecimal
        formatting as Snwprintf(), but much more efficiently.
        
        Remark:
        s Typical usage:FormatUInt64(dest, count, val,
        HexFormatOptions.None) to produce the minimal representation or
        FormatUInt64(dest, count, val, HexFormatOptions.LeadingZeros, n)
        to produce fixed width (e.g. n=8 or 16) with leading zeros.
        """
        ...
    
    def Join(*args, **kwargs):
        """
        Join(strings: MSPyBentley.WStringArray, delimiter: str) -> MSPyBentley.WString
        
        Joins a list of strings into a single string, optionally separated by
        a delimiter.
        
        Parameter ``strings``:
        The list of strings to join
        
        Parameter ``delimiter``:
        The delimiter to be inserted between each string
        
        Returns:
        Returns a string comprised of all strings in the list in input
        order, separated by the supplied delimiter.
        """
        ...
    
    def LexicographicCompare(*args, **kwargs):
        """
        LexicographicCompare(value0: MSPyBentley.WString, value1: MSPyBentley.WString) -> int
        
        Do a lexicographic comparison of specified strings. This is an
        alphabetical sort that also takes numbers into account, such that
        " file9 " will come before " file11 " in the sort order (even though
        alphabetically 1 is before 9). This method always ignores case.
        param in  pszName1 IN first string param in  pszName2 IN second string
        return 0 if strings are equal,<0 if pszName1 is less than pszName2,
        else> 0
        """
        ...
    
    NPOS: int
    
    def ParseArguments(*args, **kwargs):
        """
        ParseArguments(subStrings: MSPyBentley.WStringArray, inString: MSPyBentley.WString, auxDelimiters: MSPyBentley.WString) -> None
        
        Default logic for parsing a user supplied argument list. Tokenizes
        based on whitespace and does not tokenize within double-quoted
        substrings.
        
        Parameter ``subStrings``:
        The resulting sub strings will be added to this collection
        
        Parameter ``inString``:
        The string to tokenize; cannot be NULL or empty
        
        Parameter ``auxDelimiters``:
        (optional) Each character in the string Will be used as a
        delimiter in addition to whitespace.
        """
        ...
    
    def ParseUInt64(*args, **kwargs):
        """
        ParseUInt64(value: int, string: MSPyBentley.WString) -> tuple
        
        Parses a string containing an integer number in decimal format
        
        Parameter ``value``:
        The resulting integer number
        
        Parameter ``string``:
        A string representation of a decimal value.
        
        Remark:
        s ``string`` must not contain any extra characters or whitespace.
        This function does not skip leading whitespace or stop at trailing
        characters, as a function like strtoul would do. That kind of
        parsing is for the higher level caller to do.
        """
        ...
    
    def Split(*args, **kwargs):
        """
        Split(*args, **kwargs)
        Overloaded function.
        
        1. Split(str: MSPyBentley.WString, delimiters: MSPyBentley.WString, tokens: MSPyBentley.WStringArray) -> None
        
        Tokenizes a string based on the provided delimiters, and adds a
        WString for each token into the provided collection. This essentially
        wraps wcstok for more convenient access.
        
        Parameter ``str``:
        The string to tokenize; cannot be NULL or empty
        
        Parameter ``delimiters``:
        One or more delimiters; cannot be NULL or empty
        
        Parameter ``tokens``:
        One or more tokens
        
        2. Split(str: MSPyBentley.WString, delimiters: MSPyBentley.WString, escapeChars: MSPyBentley.WString, tokens: MSPyBentley.WStringArray) -> None
        
        Tokenizes a string based on the provided delimiters, and adds a
        WString for each token into the provided collection. This essentially
        wraps wcstok for more convenient access.
        
        Parameter ``str``:
        The string to tokenize; cannot be NULL or empty
        
        Parameter ``delimiters``:
        One or more delimiters; cannot be NULL or empty
        
        Parameter ``tokens``:
        One or more tokens
        """
        ...
    
    def WCharToUtf8(*args, **kwargs):
        """
        WCharToUtf8(outStr: MSPyBentley.Utf8String, inStr: str, _count: int = 18446744073709551615) -> Bentley.BentleyStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class BeTextFile:
    """
    Reads and Writes Text Files regardless of whether they are encoded on disk as locale-encoded ASCII, UTF8, or UTF16.
    """

    def Close(*args, **kwargs):
        """
        Close(self: MSPyBentley.BeTextFile) -> None
        
        Closes the text file.
        
        Remark:
        s This call is not usually necessary, as the file is closed
        automatically when the reference-counted pointer is released.
        """
        ...
    
    def GetChar(*args, **kwargs):
        """
        GetChar(self: MSPyBentley.BeTextFile) -> str
        
        Reads the next character from the file.
        
        Returns:
        The next character or WEOF.
        """
        ...
    
    def GetLine(*args, **kwargs):
        """
        GetLine(self: MSPyBentley.BeTextFile, textLine: MSPyBentley.WString) -> MSPyBentley.TextFileReadStatus
        
        Reads a line from the file.
        
        Parameter ``textLine``:
        The buffer to read the line into.
        
        Remark:
        s The line is always converted to Unicode in UTF-16.
        
        Remark:
        s The handling of newlines is controlled by the options when
        opening the file.
        
        Returns:
        TextFileReadStatus.Success if the line was read successfully;
        otherwise TextFileReadStatus.Eof or an error code.
        """
        ...
    
    def GetPointer(*args, **kwargs):
        """
        GetPointer(self: MSPyBentley.BeTextFile) -> tuple
        
        Gets the file read/write position.
        
        Parameter ``position``:
        the current read/write position
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def Open(*args, **kwargs):
        """
        Open(fullFileSpec: str, openType: MSPyBentley.TextFileOpenType, options: MSPyBentley.TextFileOptions, encoding: MSPyBentley.TextFileEncoding = <TextFileEncoding.eCurrentLocale: 0>) -> tuple
        
        Opens a text file for reading or writing.
        
        Parameter ``status``:
        BeFileStatus.Success on success or the file open error.
        
        Parameter ``fullFileSpec``:
        Name of the file to open.
        
        Parameter ``openType``:
        Whether to open the file for read, write or append.
        
        Parameter ``options``:
        Options controlling how newline characters are treated on read.
        
        Parameter ``encoding``:
        Encoding for the file; use TextFileEncoding.CurrentLocale for
        ASCII. This parameter is used only when openType is
        TextFileOpenType.Write.
        
        Remark:
        s When opened for read or append, the text file encoding will be
        read from the beginning of the file (if it is there) and the
        contents will be read and converted from its encoding to Unicode.
        
        Remark:
        s When opened for write, the *encoding* argument indicates how the
        output is to be written. If there is an existing file with the
        same name, that file is replaced by a new file.
        
        Returns:
        A pointer to the file. If status is not BeFileStatus.Success then
        the pointer will fail the IsValid() check.
        """
        ...
    
    def PutLine(*args, **kwargs):
        """
        PutLine(self: MSPyBentley.BeTextFile, textLine: str, addCR: bool) -> MSPyBentley.TextFileWriteStatus
        
        Writes a line to the file.
        
        Parameter ``textLine``:
        The buffer to read the line into.
        
        Parameter ``addCarriageReturn``:
        If true, appends a newline character to the input *textLine.*
        
        Remark:
        s The data will be converted to the encoding specified when
        opening the file.
        
        Returns:
        TextFileWriteStatus.Success if the line was written successfully;
        otherwise an error code.
        """
        ...
    
    def Rewind(*args, **kwargs):
        """
        Rewind(self: MSPyBentley.BeTextFile) -> MSPyBentley.BeFileStatus
        
        Rewinds the file and prepare for reading from the beginning of the
        text data (i.e., just past the encoding signature, if there is one).
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def SetPointer(*args, **kwargs):
        """
        SetPointer(self: MSPyBentley.BeTextFile, position: int, origin: MSPyBentley.BeFileSeekOrigin) -> MSPyBentley.BeFileStatus
        
        Moves the file read/write position
        
        Parameter ``position``:
        The new read/write position.
        
        Parameter ``origin``:
        The origin mode for the move.
        
        Returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        
        Remark:
        s Use Rewind to go to the beginning of rthe text data (rather than
        SetPointer (0, BeFileSeekOrigin.Begin) because Rewind accounts
        for the encoding signature that might be at the beginning of the
        file.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class BoolArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.BoolArray) -> None
        
        2. __init__(self: MSPyBentley.BoolArray, arg0: MSPyBentley.BoolArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.BoolArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.BoolArray, x: bool) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.BoolArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.BoolArray, x: bool) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.BoolArray, L: MSPyBentley.BoolArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.BoolArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.BoolArray, i: int, x: bool) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.BoolArray) -> bool
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.BoolArray, i: int) -> bool
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.BoolArray, x: bool) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class DoubleArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.DoubleArray) -> None
        
        2. __init__(self: MSPyBentley.DoubleArray, arg0: MSPyBentley.DoubleArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.DoubleArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.DoubleArray, x: float) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.DoubleArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.DoubleArray, x: float) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.DoubleArray, L: MSPyBentley.DoubleArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.DoubleArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.DoubleArray, i: int, x: float) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.DoubleArray) -> float
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.DoubleArray, i: int) -> float
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.DoubleArray, x: float) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class DoubleFormatter:
    """
    None
    """

    def Clone(*args, **kwargs):
        """
        Clone(self: MSPyBentley.DoubleFormatter) -> MSPyBentley.DoubleFormatter
        
        Construct a formatter which is a duplicate of an existing formatter.
        """
        ...
    
    def Create(*args, **kwargs):
        """
        Create() -> MSPyBentley.DoubleFormatter
        
        Construct a formatter with default settings.
        """
        ...
    
    @property
    def DecimalSeparator(arg0: MSPyBentley.DoubleFormatterBase) -> str:
        ...
    @DecimalSeparator.setter
    def DecimalSeparator(arg0: MSPyBentley.DoubleFormatterBase, arg1: str) -> None:
        ...
    
    def GetDecimalSeparator(*args, **kwargs):
        """
        GetDecimalSeparator(self: MSPyBentley.DoubleFormatterBase) -> str
        
        Get the decimal separator used by this formatter.
        """
        ...
    
    def GetInsertThousandsSeparator(*args, **kwargs):
        """
        GetInsertThousandsSeparator(self: MSPyBentley.DoubleFormatterBase) -> bool
        
        Get the value indicating if the thousands separator is inserted by
        this formatter.
        """
        ...
    
    def GetLeadingZero(*args, **kwargs):
        """
        GetLeadingZero(self: MSPyBentley.DoubleFormatterBase) -> bool
        
        Test if this formatter will include a leading zero.  A leading zero is only
        included for values less than 1.0.  Ex. "0.5" vs. ".5"
        """
        ...
    
    def GetPrecision(*args, **kwargs):
        """
        GetPrecision(self: MSPyBentley.DoubleFormatterBase) -> Bentley.PrecisionFormat
        
        Get the precision used by this formatter.
        """
        ...
    
    def GetThousandsSeparator(*args, **kwargs):
        """
        GetThousandsSeparator(self: MSPyBentley.DoubleFormatterBase) -> str
        
        Get the thousands separator used by this formatter.
        """
        ...
    
    def GetTrailingZeros(*args, **kwargs):
        """
        GetTrailingZeros(self: MSPyBentley.DoubleFormatterBase) -> bool
        
        Test if this formatter will include trailing zeros.  Trailing zeros are only included
        up to the requested precision.  Ex. "30.500" vs. "30.5"
        """
        ...
    
    def GetTypeFromPrecision(*args, **kwargs):
        """
        GetTypeFromPrecision(format: Bentley.PrecisionFormat) -> Bentley.PrecisionType
        
        Categorize a precision value.
        """
        ...
    
    @property
    def InsertThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase) -> bool:
        ...
    @InsertThousandsSeparator.setter
    def InsertThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase, arg1: bool) -> None:
        ...
    
    @property
    def LeadingZero(arg0: MSPyBentley.DoubleFormatterBase) -> bool:
        ...
    @LeadingZero.setter
    def LeadingZero(arg0: MSPyBentley.DoubleFormatterBase, arg1: bool) -> None:
        ...
    
    @property
    def Precision(arg0: MSPyBentley.DoubleFormatterBase) -> Bentley.PrecisionFormat:
        ...
    @Precision.setter
    def Precision(arg0: MSPyBentley.DoubleFormatterBase, arg1: Bentley.PrecisionFormat) -> None:
        ...
    
    def SetDecimalSeparator(*args, **kwargs):
        """
        SetDecimalSeparator(self: MSPyBentley.DoubleFormatterBase, newVal: str) -> None
        
        Set the formatter's decimal separator.
        """
        ...
    
    def SetInsertThousandsSeparator(*args, **kwargs):
        """
        SetInsertThousandsSeparator(self: MSPyBentley.DoubleFormatterBase, newVal: bool) -> None
        
        Specify if the thousands separator should be inserted or not.
        """
        ...
    
    def SetLeadingZero(*args, **kwargs):
        """
        SetLeadingZero(self: MSPyBentley.DoubleFormatterBase, newVal: bool) -> None
        
        Set the formatter's leading zero behavior. A leading zero is only
        included for values less than 1.0. Ex. " 0.5 " vs. " .5 "
        
        Parameter ``newVal``:
        pass true to include a leading zero for values less than 1.0
        """
        ...
    
    def SetPrecision(*args, **kwargs):
        """
        SetPrecision(self: MSPyBentley.DoubleFormatterBase, newVal: Bentley.PrecisionFormat) -> None
        
        Set the formatter's precision.
        """
        ...
    
    def SetThousandsSeparator(*args, **kwargs):
        """
        SetThousandsSeparator(self: MSPyBentley.DoubleFormatterBase, newVal: str) -> None
        
        Set the formatter's thousands separator.
        """
        ...
    
    def SetTrailingZeros(*args, **kwargs):
        """
        SetTrailingZeros(self: MSPyBentley.DoubleFormatterBase, newVal: bool) -> None
        
        Set the formatter's trailing zeros behavior.  Trailing zeros are only included
        up to the requested precision.  Ex. "30.500" vs. "30.5"
        @param in  newVal pass true to zero pad the output string to the requested precision.
        """
        ...
    
    @property
    def ThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase) -> str:
        ...
    @ThousandsSeparator.setter
    def ThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase, arg1: str) -> None:
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyBentley.DoubleFormatter, value: float) -> MSPyBentley.WString
        
        Use the settings defined in this formatter to convert a double value
        to a string.
        
        Parameter ``value``:
        value to format.
        """
        ...
    
    @property
    def TrailingZeros(arg0: MSPyBentley.DoubleFormatterBase) -> bool:
        ...
    @TrailingZeros.setter
    def TrailingZeros(arg0: MSPyBentley.DoubleFormatterBase, arg1: bool) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DoubleFormatterBase:
    """
    None
    """

    @property
    def DecimalSeparator(arg0: MSPyBentley.DoubleFormatterBase) -> str:
        ...
    @DecimalSeparator.setter
    def DecimalSeparator(arg0: MSPyBentley.DoubleFormatterBase, arg1: str) -> None:
        ...
    
    def GetDecimalSeparator(*args, **kwargs):
        """
        GetDecimalSeparator(self: MSPyBentley.DoubleFormatterBase) -> str
        
        Get the decimal separator used by this formatter.
        """
        ...
    
    def GetInsertThousandsSeparator(*args, **kwargs):
        """
        GetInsertThousandsSeparator(self: MSPyBentley.DoubleFormatterBase) -> bool
        
        Get the value indicating if the thousands separator is inserted by
        this formatter.
        """
        ...
    
    def GetLeadingZero(*args, **kwargs):
        """
        GetLeadingZero(self: MSPyBentley.DoubleFormatterBase) -> bool
        
        Test if this formatter will include a leading zero.  A leading zero is only
        included for values less than 1.0.  Ex. "0.5" vs. ".5"
        """
        ...
    
    def GetPrecision(*args, **kwargs):
        """
        GetPrecision(self: MSPyBentley.DoubleFormatterBase) -> Bentley.PrecisionFormat
        
        Get the precision used by this formatter.
        """
        ...
    
    def GetThousandsSeparator(*args, **kwargs):
        """
        GetThousandsSeparator(self: MSPyBentley.DoubleFormatterBase) -> str
        
        Get the thousands separator used by this formatter.
        """
        ...
    
    def GetTrailingZeros(*args, **kwargs):
        """
        GetTrailingZeros(self: MSPyBentley.DoubleFormatterBase) -> bool
        
        Test if this formatter will include trailing zeros.  Trailing zeros are only included
        up to the requested precision.  Ex. "30.500" vs. "30.5"
        """
        ...
    
    @property
    def InsertThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase) -> bool:
        ...
    @InsertThousandsSeparator.setter
    def InsertThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase, arg1: bool) -> None:
        ...
    
    @property
    def LeadingZero(arg0: MSPyBentley.DoubleFormatterBase) -> bool:
        ...
    @LeadingZero.setter
    def LeadingZero(arg0: MSPyBentley.DoubleFormatterBase, arg1: bool) -> None:
        ...
    
    @property
    def Precision(arg0: MSPyBentley.DoubleFormatterBase) -> Bentley.PrecisionFormat:
        ...
    @Precision.setter
    def Precision(arg0: MSPyBentley.DoubleFormatterBase, arg1: Bentley.PrecisionFormat) -> None:
        ...
    
    def SetDecimalSeparator(*args, **kwargs):
        """
        SetDecimalSeparator(self: MSPyBentley.DoubleFormatterBase, newVal: str) -> None
        
        Set the formatter's decimal separator.
        """
        ...
    
    def SetInsertThousandsSeparator(*args, **kwargs):
        """
        SetInsertThousandsSeparator(self: MSPyBentley.DoubleFormatterBase, newVal: bool) -> None
        
        Specify if the thousands separator should be inserted or not.
        """
        ...
    
    def SetLeadingZero(*args, **kwargs):
        """
        SetLeadingZero(self: MSPyBentley.DoubleFormatterBase, newVal: bool) -> None
        
        Set the formatter's leading zero behavior. A leading zero is only
        included for values less than 1.0. Ex. " 0.5 " vs. " .5 "
        
        Parameter ``newVal``:
        pass true to include a leading zero for values less than 1.0
        """
        ...
    
    def SetPrecision(*args, **kwargs):
        """
        SetPrecision(self: MSPyBentley.DoubleFormatterBase, newVal: Bentley.PrecisionFormat) -> None
        
        Set the formatter's precision.
        """
        ...
    
    def SetThousandsSeparator(*args, **kwargs):
        """
        SetThousandsSeparator(self: MSPyBentley.DoubleFormatterBase, newVal: str) -> None
        
        Set the formatter's thousands separator.
        """
        ...
    
    def SetTrailingZeros(*args, **kwargs):
        """
        SetTrailingZeros(self: MSPyBentley.DoubleFormatterBase, newVal: bool) -> None
        
        Set the formatter's trailing zeros behavior.  Trailing zeros are only included
        up to the requested precision.  Ex. "30.500" vs. "30.5"
        @param in  newVal pass true to zero pad the output string to the requested precision.
        """
        ...
    
    @property
    def ThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase) -> str:
        ...
    @ThousandsSeparator.setter
    def ThousandsSeparator(arg0: MSPyBentley.DoubleFormatterBase, arg1: str) -> None:
        ...
    
    @property
    def TrailingZeros(arg0: MSPyBentley.DoubleFormatterBase) -> bool:
        ...
    @TrailingZeros.setter
    def TrailingZeros(arg0: MSPyBentley.DoubleFormatterBase, arg1: bool) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DsigAnnotationData:
    """
    Signature annotation data.
    @Remarks Annotation data is not certified> by any outside party.
    The identity and trustworthiness of the signer should be based solely on the certificate stored in the signature.
    """

    @property
    def Location(arg0: MSPyBentley.DsigAnnotationData) -> str:
        ...
    @Location.setter
    def Location(arg0: MSPyBentley.DsigAnnotationData, arg1: str) -> None:
        ...
    
    @property
    def Name(arg0: MSPyBentley.DsigAnnotationData) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyBentley.DsigAnnotationData, arg1: str) -> None:
        ...
    
    @property
    def Purpose(arg0: MSPyBentley.DsigAnnotationData) -> str:
        ...
    @Purpose.setter
    def Purpose(arg0: MSPyBentley.DsigAnnotationData, arg1: str) -> None:
        ...
    
    def __init__(self: MSPyBentley.DsigAnnotationData) -> None:
        ...
    
    @property
    def expiryDate(self: MSPyBentley.DsigAnnotationData) -> float:
        ...
    @expiryDate.setter
    def expiryDate(self: MSPyBentley.DsigAnnotationData, arg0: float) -> None:
        ...
    
    @property
    def signDate(self: MSPyBentley.DsigAnnotationData) -> float:
        ...
    @signDate.setter
    def signDate(self: MSPyBentley.DsigAnnotationData, arg0: float) -> None:
        ...
    
class DsigQuery:
    """
    None
    """

    @property
    def CommonName(arg0: MSPyBentley.DsigQuery) -> str:
        ...
    
    @property
    def Email(arg0: MSPyBentley.DsigQuery) -> str:
        ...
    
    def GetAnnotationData(*args, **kwargs):
        """
        GetAnnotationData(self: MSPyBentley.DsigQuery) -> MSPyBentley.DsigAnnotationData
        """
        ...
    
    def GetCertificate(*args, **kwargs):
        """
        GetCertificate(self: MSPyBentley.DsigQuery, x509Cert: MSPyBentley.UInt8Array) -> int
        """
        ...
    
    def GetCertificateChain(*args, **kwargs):
        """
        GetCertificateChain(self: MSPyBentley.DsigQuery, pkcs7: MSPyBentley.UInt8Array) -> int
        """
        ...
    
    def GetCommonName(*args, **kwargs):
        """
        GetCommonName(self: MSPyBentley.DsigQuery) -> str
        """
        ...
    
    def GetEmail(*args, **kwargs):
        """
        GetEmail(self: MSPyBentley.DsigQuery) -> str
        """
        ...
    
    def GetPublicKey(*args, **kwargs):
        """
        GetPublicKey(self: MSPyBentley.DsigQuery, x509PublicKeyInfo: MSPyBentley.UInt8Array) -> int
        """
        ...
    
    def IncludesEntireFile(*args, **kwargs):
        """
        IncludesEntireFile(self: MSPyBentley.DsigQuery) -> bool
        """
        ...
    
    def IncludesReferences(*args, **kwargs):
        """
        IncludesReferences(self: MSPyBentley.DsigQuery) -> bool
        """
        ...
    
    def IsValid(*args, **kwargs):
        """
        IsValid(self: MSPyBentley.DsigQuery) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class FloatArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.FloatArray) -> None
        
        2. __init__(self: MSPyBentley.FloatArray, arg0: MSPyBentley.FloatArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.FloatArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.FloatArray, x: float) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.FloatArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.FloatArray, x: float) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.FloatArray, L: MSPyBentley.FloatArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.FloatArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.FloatArray, i: int, x: float) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.FloatArray) -> float
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.FloatArray, i: int) -> float
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.FloatArray, x: float) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class HeapZone:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class HexFormatOptions:
    """
    Members:
    
    eNone
    
    eLeftJustify
    
    eIncludePrefix
    
    eUppercase
    
    eLeadingZeros
    
    eUsePrecision
    """

    def __init__(self: MSPyBentley.HexFormatOptions, value: int) -> None:
        ...
    
    eIncludePrefix: HexFormatOptions
    
    eLeadingZeros: HexFormatOptions
    
    eLeftJustify: HexFormatOptions
    
    eNone: HexFormatOptions
    
    eUppercase: HexFormatOptions
    
    eUsePrecision: HexFormatOptions
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.HexFormatOptions) -> int:
        ...
    
class Int16Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Int16Array) -> None
        
        2. __init__(self: MSPyBentley.Int16Array, arg0: MSPyBentley.Int16Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.Int16Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.Int16Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Int16Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.Int16Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.Int16Array, L: MSPyBentley.Int16Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Int16Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.Int16Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.Int16Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Int16Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.Int16Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Int32Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Int32Array) -> None
        
        2. __init__(self: MSPyBentley.Int32Array, arg0: MSPyBentley.Int32Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.Int32Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.Int32Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Int32Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.Int32Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.Int32Array, L: MSPyBentley.Int32Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Int32Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.Int32Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.Int32Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Int32Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.Int32Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Int64Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Int64Array) -> None
        
        2. __init__(self: MSPyBentley.Int64Array, arg0: MSPyBentley.Int64Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.Int64Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.Int64Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Int64Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.Int64Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.Int64Array, L: MSPyBentley.Int64Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Int64Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.Int64Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.Int64Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Int64Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.Int64Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Int64VecArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Int64VecArray) -> None
        
        2. __init__(self: MSPyBentley.Int64VecArray, arg0: MSPyBentley.Int64VecArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.Int64VecArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.Int64VecArray, x: MSPyBentley.Int64Array) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Int64VecArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.Int64VecArray, x: MSPyBentley.Int64Array) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.Int64VecArray, L: MSPyBentley.Int64VecArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Int64VecArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.Int64VecArray, i: int, x: MSPyBentley.Int64Array) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.Int64VecArray) -> MSPyBentley.Int64Array
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Int64VecArray, i: int) -> MSPyBentley.Int64Array
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.Int64VecArray, x: MSPyBentley.Int64Array) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Int8Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Int8Array) -> None
        
        2. __init__(self: MSPyBentley.Int8Array, arg0: MSPyBentley.Int8Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.Int8Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.Int8Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Int8Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.Int8Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.Int8Array, L: MSPyBentley.Int8Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Int8Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.Int8Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.Int8Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Int8Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.Int8Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ItemsView[WStringWCharMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ItemsView[WStringWStringMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class KeysView[WStringWCharMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class KeysView[WStringWStringMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class LangCodePage:
    """
    Members:
    
    eUnknown
    
    eNone
    
    eOEM_US
    
    eTransparent_ASMO
    
    eOEM_Greek
    
    eOEM_Baltic
    
    eOEM_Multilingual
    
    eOEM_LatinII
    
    eOEM_Cryllic
    
    eOEM_Turkish
    
    eOEM_LatinI
    
    eOEM_Hebrew
    
    eOEM_Russian
    
    eOEM_Thai
    
    eJapanese
    
    eSimplified_Chinese
    
    eKorean
    
    eTraditional_Chinese
    
    eUnicode
    
    eUNICODE_UCS2_Little_Endian
    
    eUNICODE_UCS2_Big_Endian
    
    eCentral_European
    
    eCyrillic
    
    eLatinI
    
    eGreek
    
    eTurkish
    
    eHebrew
    
    eArabic
    
    eBaltic
    
    eVietnamese
    
    eJohab
    
    eISO_8859_1
    
    eISO_8859_2
    
    eISO_8859_3
    
    eISO_8859_4
    
    eISO_8859_5
    
    eISO_8859_6
    
    eISO_8859_7
    
    eISO_8859_8
    
    eISO_8859_9
    
    eISO_8859_15
    
    eISCII_UNICODE_UTF_7
    
    eISCII_UNICODE_UTF_8
    """

    def __init__(self: MSPyBentley.LangCodePage, value: int) -> None:
        ...
    
    eArabic: LangCodePage
    
    eBaltic: LangCodePage
    
    eCentral_European: LangCodePage
    
    eCyrillic: LangCodePage
    
    eGreek: LangCodePage
    
    eHebrew: LangCodePage
    
    eISCII_UNICODE_UTF_7: LangCodePage
    
    eISCII_UNICODE_UTF_8: LangCodePage
    
    eISO_8859_1: LangCodePage
    
    eISO_8859_15: LangCodePage
    
    eISO_8859_2: LangCodePage
    
    eISO_8859_3: LangCodePage
    
    eISO_8859_4: LangCodePage
    
    eISO_8859_5: LangCodePage
    
    eISO_8859_6: LangCodePage
    
    eISO_8859_7: LangCodePage
    
    eISO_8859_8: LangCodePage
    
    eISO_8859_9: LangCodePage
    
    eJapanese: LangCodePage
    
    eJohab: LangCodePage
    
    eKorean: LangCodePage
    
    eLatinI: LangCodePage
    
    eNone: LangCodePage
    
    eOEM_Baltic: LangCodePage
    
    eOEM_Cryllic: LangCodePage
    
    eOEM_Greek: LangCodePage
    
    eOEM_Hebrew: LangCodePage
    
    eOEM_LatinI: LangCodePage
    
    eOEM_LatinII: LangCodePage
    
    eOEM_Multilingual: LangCodePage
    
    eOEM_Russian: LangCodePage
    
    eOEM_Thai: LangCodePage
    
    eOEM_Turkish: LangCodePage
    
    eOEM_US: LangCodePage
    
    eSimplified_Chinese: LangCodePage
    
    eTraditional_Chinese: LangCodePage
    
    eTransparent_ASMO: LangCodePage
    
    eTurkish: LangCodePage
    
    eUNICODE_UCS2_Big_Endian: LangCodePage
    
    eUNICODE_UCS2_Little_Endian: LangCodePage
    
    eUnicode: LangCodePage
    
    eUnknown: LangCodePage
    
    eVietnamese: LangCodePage
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.LangCodePage) -> int:
        ...
    
class PrecisionFormat:
    """
    Members:
    
    eDecimalWhole
    
    eDecimal1Place
    
    eDecimal2Places
    
    eDecimal3Places
    
    eDecimal4Places
    
    eDecimal5Places
    
    eDecimal6Places
    
    eDecimal7Places
    
    eDecimal8Places
    
    eFractionalWhole
    
    eFractionalHalf
    
    eFractionalQuarter
    
    eFractionalEighth
    
    eFractionalSixteenth
    
    eFractional1_Over_32
    
    eFractional1_Over_64
    
    eFractional1_Over_128
    
    eFractional1_Over_256
    
    eScientificWhole
    
    eScientific1Place
    
    eScientific2Places
    
    eScientific3Places
    
    eScientific4Places
    
    eScientific5Places
    
    eScientific6Places
    
    eScientific7Places
    
    eScientific8Places
    """

    def __init__(self: MSPyBentley.PrecisionFormat, value: int) -> None:
        ...
    
    eDecimal1Place: PrecisionFormat
    
    eDecimal2Places: PrecisionFormat
    
    eDecimal3Places: PrecisionFormat
    
    eDecimal4Places: PrecisionFormat
    
    eDecimal5Places: PrecisionFormat
    
    eDecimal6Places: PrecisionFormat
    
    eDecimal7Places: PrecisionFormat
    
    eDecimal8Places: PrecisionFormat
    
    eDecimalWhole: PrecisionFormat
    
    eFractional1_Over_128: PrecisionFormat
    
    eFractional1_Over_256: PrecisionFormat
    
    eFractional1_Over_32: PrecisionFormat
    
    eFractional1_Over_64: PrecisionFormat
    
    eFractionalEighth: PrecisionFormat
    
    eFractionalHalf: PrecisionFormat
    
    eFractionalQuarter: PrecisionFormat
    
    eFractionalSixteenth: PrecisionFormat
    
    eFractionalWhole: PrecisionFormat
    
    eScientific1Place: PrecisionFormat
    
    eScientific2Places: PrecisionFormat
    
    eScientific3Places: PrecisionFormat
    
    eScientific4Places: PrecisionFormat
    
    eScientific5Places: PrecisionFormat
    
    eScientific6Places: PrecisionFormat
    
    eScientific7Places: PrecisionFormat
    
    eScientific8Places: PrecisionFormat
    
    eScientificWhole: PrecisionFormat
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.PrecisionFormat) -> int:
        ...
    
class PrecisionType:
    """
    Members:
    
    eDecimal
    
    eFractional
    
    eScientific
    """

    def __init__(self: MSPyBentley.PrecisionType, value: int) -> None:
        ...
    
    eDecimal: PrecisionType
    
    eFractional: PrecisionType
    
    eScientific: PrecisionType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.PrecisionType) -> int:
        ...
    
class PyNameSpaceManager:
    """
    None
    """

    def ClearNameSpaceUsing(*args, **kwargs):
        """
        ClearNameSpaceUsing() -> None
        """
        ...
    
    def DelNameSpaceUsing(*args, **kwargs):
        """
        DelNameSpaceUsing(namespaceID: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> int
        """
        ...
    
    def IsNameSpaceUsing(*args, **kwargs):
        """
        IsNameSpaceUsing(namespaceID: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> bool
        """
        ...
    
    class NameSpaceID:
        """
        Members:
        
        eBentley_DgnPlatform
        
        eBentley_DgnPlatform_Raster
        
        eBentley_Geometry
        
        eBentley_GeoCoordinates
        """
    
        def __init__(self: MSPyBentley.PyNameSpaceManager.NameSpaceID, value: int) -> None:
            ...
        
        eBentley_DgnPlatform: NameSpaceID
        
        eBentley_DgnPlatform_Raster: NameSpaceID
        
        eBentley_GeoCoordinates: NameSpaceID
        
        eBentley_Geometry: NameSpaceID
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> int:
            ...
        
    def SetDefaultNameSpaceList(*args, **kwargs):
        """
        SetDefaultNameSpaceList() -> None
        """
        ...
    
    def UsingNameSpace(*args, **kwargs):
        """
        UsingNameSpace(namespaceID: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> int
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eBentley_DgnPlatform: NameSpaceID
    
    eBentley_DgnPlatform_Raster: NameSpaceID
    
    eBentley_GeoCoordinates: NameSpaceID
    
    eBentley_Geometry: NameSpaceID
    
class TextFileEncoding:
    """
    Members:
    
    eCurrentLocale
    
    eUtf8
    
    eUtf16
    """

    def __init__(self: MSPyBentley.TextFileEncoding, value: int) -> None:
        ...
    
    eCurrentLocale: TextFileEncoding
    
    eUtf16: TextFileEncoding
    
    eUtf8: TextFileEncoding
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.TextFileEncoding) -> int:
        ...
    
class TextFileOpenType:
    """
    Members:
    
    eRead
    
    eWrite
    
    eAppend
    """

    def __init__(self: MSPyBentley.TextFileOpenType, value: int) -> None:
        ...
    
    eAppend: TextFileOpenType
    
    eRead: TextFileOpenType
    
    eWrite: TextFileOpenType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.TextFileOpenType) -> int:
        ...
    
class TextFileOptions:
    """
    Members:
    
    eNone_
    
    eKeepNewLine
    
    eNewLinesToSpace
    """

    def __init__(self: MSPyBentley.TextFileOptions, value: int) -> None:
        ...
    
    eKeepNewLine: TextFileOptions
    
    eNewLinesToSpace: TextFileOptions
    
    eNone_: TextFileOptions
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.TextFileOptions) -> int:
        ...
    
class TextFileReadStatus:
    """
    Members:
    
    eSuccess
    
    eEof
    
    eBadParameter
    """

    def __init__(self: MSPyBentley.TextFileReadStatus, value: int) -> None:
        ...
    
    eBadParameter: TextFileReadStatus
    
    eEof: TextFileReadStatus
    
    eSuccess: TextFileReadStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.TextFileReadStatus) -> int:
        ...
    
class TextFileWriteStatus:
    """
    Members:
    
    eSuccess
    
    eError
    
    eBadParameter
    """

    def __init__(self: MSPyBentley.TextFileWriteStatus, value: int) -> None:
        ...
    
    eBadParameter: TextFileWriteStatus
    
    eError: TextFileWriteStatus
    
    eSuccess: TextFileWriteStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyBentley.TextFileWriteStatus) -> int:
        ...
    
class UInt16Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.UInt16Array) -> None
        
        2. __init__(self: MSPyBentley.UInt16Array, arg0: MSPyBentley.UInt16Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.UInt16Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.UInt16Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.UInt16Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.UInt16Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.UInt16Array, L: MSPyBentley.UInt16Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.UInt16Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.UInt16Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.UInt16Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.UInt16Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.UInt16Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class UInt32Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.UInt32Array) -> None
        
        2. __init__(self: MSPyBentley.UInt32Array, arg0: MSPyBentley.UInt32Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.UInt32Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.UInt32Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.UInt32Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.UInt32Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.UInt32Array, L: MSPyBentley.UInt32Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.UInt32Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.UInt32Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.UInt32Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.UInt32Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.UInt32Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class UInt64Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.UInt64Array) -> None
        
        2. __init__(self: MSPyBentley.UInt64Array, arg0: MSPyBentley.UInt64Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.UInt64Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.UInt64Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.UInt64Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.UInt64Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.UInt64Array, L: MSPyBentley.UInt64Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.UInt64Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.UInt64Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.UInt64Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.UInt64Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.UInt64Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class UInt64VecArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.UInt64VecArray) -> None
        
        2. __init__(self: MSPyBentley.UInt64VecArray, arg0: MSPyBentley.UInt64VecArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.UInt64VecArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.UInt64VecArray, x: MSPyBentley.UInt64Array) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.UInt64VecArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.UInt64VecArray, x: MSPyBentley.UInt64Array) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.UInt64VecArray, L: MSPyBentley.UInt64VecArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.UInt64VecArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.UInt64VecArray, i: int, x: MSPyBentley.UInt64Array) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.UInt64VecArray) -> MSPyBentley.UInt64Array
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.UInt64VecArray, i: int) -> MSPyBentley.UInt64Array
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.UInt64VecArray, x: MSPyBentley.UInt64Array) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class UInt8Array:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.UInt8Array) -> None
        
        2. __init__(self: MSPyBentley.UInt8Array, arg0: MSPyBentley.UInt8Array) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.UInt8Array, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.UInt8Array, x: int) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.UInt8Array) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.UInt8Array, x: int) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.UInt8Array, L: MSPyBentley.UInt8Array) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.UInt8Array, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.UInt8Array, i: int, x: int) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.UInt8Array) -> int
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.UInt8Array, i: int) -> int
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.UInt8Array, x: int) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Utf8String:
    """
    Contains a UTF-8 encoded string. This class has many of the capabilities of a python string
    This class also defines utility functions for constructing and manipulating the string
    """

    def Assign(*args, **kwargs):
        """
        Assign(self: MSPyBentley.Utf8String, str: str) -> MSPyBentley.Utf8String
        
        Construct a Utf8String by converting from a wchar_t string.
        """
        ...
    
    def AssignOrClear(*args, **kwargs):
        """
        AssignOrClear(self: MSPyBentley.Utf8String, in: str) -> MSPyBentley.Utf8String
        
        Update this string to be equal to *in.* If *in* is NULL, clear this
        string.
        """
        ...
    
    def CompareTo(*args, **kwargs):
        """
        CompareTo(*args, **kwargs)
        Overloaded function.
        
        1. CompareTo(self: MSPyBentley.Utf8String, other: str) -> int
        
        Perform a (case-sensitive) comparison.
        
        Returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        Parameter ``other``:
        The other string.
        
        2. CompareTo(self: MSPyBentley.Utf8String, other: MSPyBentley.Utf8String) -> int
        
        Perform a (case-sensitive) comparison.
        
        Returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def CompareToI(*args, **kwargs):
        """
        CompareToI(*args, **kwargs)
        Overloaded function.
        
        1. CompareToI(self: MSPyBentley.Utf8String, other: str) -> int
        
        Perform a case-insensitive comparison.
        
        Returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        Parameter ``other``:
        The other string.
        
        2. CompareToI(self: MSPyBentley.Utf8String, other: MSPyBentley.Utf8String) -> int
        
        Perform a case-insensitive comparison.
        
        Returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def Equals(*args, **kwargs):
        """
        Equals(*args, **kwargs)
        Overloaded function.
        
        1. Equals(self: MSPyBentley.Utf8String, other: str) -> bool
        
        Test for equality with another string.
        
        Returns:
        true if the strings are equal.
        
        Parameter ``other``:
        The other string.
        
        2. Equals(self: MSPyBentley.Utf8String, other: MSPyBentley.Utf8String) -> bool
        
        Test for equality with another string.
        
        Returns:
        true if the strings are equal.
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def EqualsI(*args, **kwargs):
        """
        EqualsI(*args, **kwargs)
        Overloaded function.
        
        1. EqualsI(self: MSPyBentley.Utf8String, other: str) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        
        2. EqualsI(self: MSPyBentley.Utf8String, other: MSPyBentley.Utf8String) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def GetNextToken(*args, **kwargs):
        """
        GetNextToken(self: MSPyBentley.Utf8String, next: MSPyBentley.Utf8String, delims: str, offset: int) -> int
        
        Reads the next token delimited by any character in *delims* or \0.
        
        Parameter ``next``:
        set to next token, if found, or cleared if not
        
        Parameter ``delims``:
        the characters that could delimit the tokens
        
        Parameter ``offset``:
        where to start search
        
        Returns:
        1 beyond the end of the current token or npos if token not found
        Example
        
        ``
        Read lines from a string, where each line is delimited by \n. The last line need not have a trailing \n.
        size_t offset = 0;
        Utf8String m;
        while ((offset = m_virtuals.GetNextToken (m, "\n", offset)) != Utf8String.npos)
        {
        printf ("%s\n", m.c_str());
        }
        ``
        
        @Note If this string ends with a delimiter, then the last token
        returned is the one before the trailing delimiter. If this string does
        not end with a delimiter, then the last token is everything following
        the last delimiter (if any) and the end of this string. If this string
        has no delimiters at all, then the first and only token returned is
        the string itself. So, for example, if this string were "abc\n" then
        GetNextToken (next, "\n", 0) would set next to "abc" and return 4, and
        GetNextToken (next, "\n", 4) would return npos. If this string were
        "abc", the two calls would return the same results.
        """
        ...
    
    def IsAscii(*args, **kwargs):
        """
        IsAscii(self: MSPyBentley.Utf8String) -> bool
        
        Test if this string contains only characters less than or equal to
        127.
        """
        ...
    
    def IsAsciiWhiteSpace(*args, **kwargs):
        """
        IsAsciiWhiteSpace(val: str) -> bool
        
        Determine whether the supplied character is a whitespace character in
        the ascii (below 128) code page. This is necessary since the c
        "isspace" function is locale specific and sometimes returns true for
        the non-breaking-space character (0xA0), which is not a valid test for
        a Utf8 string. Note this does not test for VT, or FF as they are
        considered obsolete.
        """
        ...
    
    def IsNullOrEmpty(*args, **kwargs):
        """
        IsNullOrEmpty(value: str) -> bool
        
        Utility function to test if *value* represents the empty string. This
        function interprets NULL to be the empty string.
        """
        ...
    
    def ReplaceAll(*args, **kwargs):
        """
        ReplaceAll(self: MSPyBentley.Utf8String, subStringToReplace: str, replacement: str) -> int
        
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def SizeInBytes(*args, **kwargs):
        """
        SizeInBytes(self: MSPyBentley.Utf8String) -> int
        
        Computes the size, in bytes, of this string's data, including its
        NULL-terminator.
        """
        ...
    
    def StartsWith(*args, **kwargs):
        """
        StartsWith(self: MSPyBentley.Utf8String, startChars: str) -> bool
        
        Determines if this instance starts with the provided string.
        """
        ...
    
    def ToLower(*args, **kwargs):
        """
        ToLower(self: MSPyBentley.Utf8String) -> None
        
        Converts this string, in-place, to all lower case.
        
        Remark:
        s This function can be very slow if the string contains non-ascii
        characters.
        """
        ...
    
    def ToLowerChar(*args, **kwargs):
        """
        ToLowerChar(c: str) -> str
        
        Equivalent to tolower
        """
        ...
    
    def Trim(*args, **kwargs):
        """
        Trim(*args, **kwargs)
        Overloaded function.
        
        1. Trim(self: MSPyBentley.Utf8String) -> None
        
        Removes all whitespace from the left and right sides. Whitespace
        includes space, line feed, carriage return, and tab (e.g. iswspace).
        
        2. Trim(self: MSPyBentley.Utf8String, trimCharacters: str) -> None
        
        Removes all instances of any of the given characters from the left and
        right sides.
        """
        ...
    
    def TrimEnd(*args, **kwargs):
        """
        TrimEnd(self: MSPyBentley.Utf8String) -> MSPyBentley.Utf8String
        
        Removes all whitespace from the end. Whitespace includes space, line
        feed, carriage return, and tab (e.g. iswspace).
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Utf8String) -> None
        
        2. __init__(self: MSPyBentley.Utf8String, str: str) -> None
        
        3. __init__(self: MSPyBentley.Utf8String, __s: str, __n: int) -> None
        
        4. __init__(self: MSPyBentley.Utf8String, __n: int, __c: str) -> None
        
        5. __init__(self: MSPyBentley.Utf8String, str: MSPyBentley.WString) -> None
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Utf8String) -> None
        """
        ...
    
class Utf8StringArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.Utf8StringArray) -> None
        
        2. __init__(self: MSPyBentley.Utf8StringArray, arg0: MSPyBentley.Utf8StringArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.Utf8StringArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.Utf8StringArray, x: MSPyBentley.Utf8String) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.Utf8StringArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.Utf8StringArray, x: MSPyBentley.Utf8String) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.Utf8StringArray, L: MSPyBentley.Utf8StringArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Utf8StringArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.Utf8StringArray, i: int, x: MSPyBentley.Utf8String) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.Utf8StringArray) -> MSPyBentley.Utf8String
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Utf8StringArray, i: int) -> MSPyBentley.Utf8String
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.Utf8StringArray, x: MSPyBentley.Utf8String) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ValuesView[WStringWCharMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ValuesView[WStringWStringMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class WCharArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.WCharArray) -> None
        
        2. __init__(self: MSPyBentley.WCharArray, arg0: MSPyBentley.WCharArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.WCharArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.WCharArray, x: str) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.WCharArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.WCharArray, x: str) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.WCharArray, L: MSPyBentley.WCharArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.WCharArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.WCharArray, i: int, x: str) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.WCharArray) -> str
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.WCharArray, i: int) -> str
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.WCharArray, x: str) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class WString:
    """
    A string class that has many of the same capabilities as std.string,
    plus additional functions such as conversion from UTF-8, UTF-16, and local-encoded strings,
    case-insensitive compare, trimming, padding, and others.
    """

    def AddQuotes(*args, **kwargs):
        """
        AddQuotes(self: MSPyBentley.WString) -> None
        
        Put quotes around a string.
        """
        ...
    
    def AppendA(*args, **kwargs):
        """
        AppendA(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Append a null-terminated multibyte, locale-encoded character array to
        this WString. This will create a WString internally, so if you are
        appending a character constant it is more efficient to use append
        (L"string to append").
        
        Parameter ``in``:
        The multibyte string
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AppendUtf8(*args, **kwargs):
        """
        AppendUtf8(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Append a Utf8 character array to this WString. This will create a
        WString internally, so if you are appending a character constant it is
        more efficient to use append (L"string to append").
        
        Parameter ``in``:
        The multibyte string
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AssignA(*args, **kwargs):
        """
        AssignA(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Define the contents of this WString from a CharCP using the current
        system locale
        
        Parameter ``in``:
        The ASCII string
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AssignOrClear(*args, **kwargs):
        """
        AssignOrClear(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        """
        ...
    
    def AssignUtf16(*args, **kwargs):
        """
        AssignUtf16(self: MSPyBentley.WString, in: int) -> MSPyBentley.WString
        
        Define the contents of this WString from a Utf8CP
        
        Parameter ``in``:
        The Utf8 string. May be NULL.
        
        Returns:
        Reference to this string.
        """
        ...
    
    def AssignUtf8(*args, **kwargs):
        """
        AssignUtf8(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Define the contents of this WString from a Utf8CP
        
        Parameter ``in``:
        The Utf8 string. May be NULL.
        
        Returns:
        Reference to this string.
        """
        ...
    
    def CompareTo(*args, **kwargs):
        """
        CompareTo(*args, **kwargs)
        Overloaded function.
        
        1. CompareTo(self: MSPyBentley.WString, other: str) -> int
        
        Perform a (case-sensitive) comparison.
        
        Returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        Parameter ``other``:
        The other string.
        
        2. CompareTo(self: MSPyBentley.WString, other: MSPyBentley.WString) -> int
        
        Perform a (case-sensitive) comparison.
        
        Returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def CompareToI(*args, **kwargs):
        """
        CompareToI(*args, **kwargs)
        Overloaded function.
        
        1. CompareToI(self: MSPyBentley.WString, other: str) -> int
        
        Perform a case-insensitive comparison.
        
        Returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        Parameter ``other``:
        The other string.
        
        2. CompareToI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> int
        
        Perform a case-insensitive comparison.
        
        Returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def Contains(*args, **kwargs):
        """
        Contains(*args, **kwargs)
        Overloaded function.
        
        1. Contains(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        
        2. Contains(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for whether this string contains another string.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        """
        ...
    
    def ContainsI(*args, **kwargs):
        """
        ContainsI(*args, **kwargs)
        Overloaded function.
        
        1. ContainsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        
        2. ContainsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        """
        ...
    
    def DropQuotes(*args, **kwargs):
        """
        DropQuotes(self: MSPyBentley.WString) -> None
        
        Remove quotes from around a string.
        """
        ...
    
    def EndsWith(*args, **kwargs):
        """
        EndsWith(self: MSPyBentley.WString, endChars: str) -> bool
        
        Determines if this instance ends with the provided string.
        """
        ...
    
    def EndsWithI(*args, **kwargs):
        """
        EndsWithI(self: MSPyBentley.WString, endChars: str) -> bool
        
        Determines if this instance ends with the provided string, ignoring
        case.
        """
        ...
    
    def Equals(*args, **kwargs):
        """
        Equals(*args, **kwargs)
        Overloaded function.
        
        1. Equals(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string.
        
        Returns:
        true if the strings are equal.
        
        Parameter ``other``:
        The other string.
        
        2. Equals(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for equality with another string.
        
        Returns:
        true if the strings are equal.
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def EqualsI(*args, **kwargs):
        """
        EqualsI(*args, **kwargs)
        Overloaded function.
        
        1. EqualsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        
        2. EqualsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def FindI(*args, **kwargs):
        """
        FindI(self: MSPyBentley.WString, findString: str) -> int
        
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def GetMaxLocaleCharBytes(*args, **kwargs):
        """
        GetMaxLocaleCharBytes(self: MSPyBentley.WString) -> int
        
        Get the number of bytes required to hold the current string. This is
        the value to use to allocate a buffer (e.g. via _alloca) to to call
        #ConvertToLocaleChars.
        """
        ...
    
    def GetWCharCP(*args, **kwargs):
        """
        GetWCharCP(self: MSPyBentley.WString) -> str
        
        Equivalent to c_str
        """
        ...
    
    def IsEmpty(*args, **kwargs):
        """
        IsEmpty(self: MSPyBentley.WString) -> bool
        """
        ...
    
    def IsNullOrEmpty(*args, **kwargs):
        """
        IsNullOrEmpty(str: str) -> bool
        
        True if the provided string is NULL or contains no character data.
        """
        ...
    
    def PadLeft(*args, **kwargs):
        """
        PadLeft(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None
        
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the left side.
        """
        ...
    
    def PadRight(*args, **kwargs):
        """
        PadRight(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None
        
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the right side.
        """
        ...
    
    def ReplaceAll(*args, **kwargs):
        """
        ReplaceAll(self: MSPyBentley.WString, subStringToReplace: str, replacement: str) -> int
        
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def ReplaceI(*args, **kwargs):
        """
        ReplaceI(self: MSPyBentley.WString, findString: str, replaceString: str) -> bool
        
        Replace first occurrence of findString with replaceString, ignoring
        case.
        
        Parameter ``findString``:
        The substring to find.
        
        Parameter ``replaceString``:
        The replacement string.
        
        Returns:
        true is a replacement is made.
        """
        ...
    
    def StartsWith(*args, **kwargs):
        """
        StartsWith(self: MSPyBentley.WString, startChars: str) -> bool
        
        Determines if this instance starts with the provided string.
        """
        ...
    
    def StartsWithI(*args, **kwargs):
        """
        StartsWithI(self: MSPyBentley.WString, startChars: str) -> bool
        
        Determines if this instance starts with the provided string, ignoring
        case.
        """
        ...
    
    def ToLower(*args, **kwargs):
        """
        ToLower(self: MSPyBentley.WString) -> None
        
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def ToUpper(*args, **kwargs):
        """
        ToUpper(self: MSPyBentley.WString) -> None
        
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def Trim(*args, **kwargs):
        """
        Trim(*args, **kwargs)
        Overloaded function.
        
        1. Trim(self: MSPyBentley.WString, trimCharacters: str) -> None
        
        Removes all whitespace from the left and right sides. Whitespace
        includes space, line feed, carriage return, and tab (e.g. iswspace).
        
        2. Trim(self: MSPyBentley.WString) -> None
        
        Removes all instances of any of the given characters from the left and
        right sides.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.WString) -> None
        
        2. __init__(self: MSPyBentley.WString, str: str) -> None
        
        3. __init__(self: MSPyBentley.WString, __s: str, __n: int) -> None
        
        4. __init__(self: MSPyBentley.WString, __n: int, __c: str) -> None
        
        5. __init__(self: MSPyBentley.WString, in: int) -> None
        
        Construct a WString from a Utf16 encoded Unicode string
        
        6. __init__(self: MSPyBentley.WString, in: str, isUtf8: bool = False) -> None
        
        Construct a WString from a CharCP using either the current system locale or Utf8
        
        7. __init__(self: MSPyBentley.WString, in: str, encoding: Bentley.BentleyCharEncoding) -> None
        
        Construct a WString from a CharCP string in the specified encoding
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.WString) -> None
        """
        ...
    
    def substr(*args, **kwargs):
        """
        substr(self: MSPyBentley.WString, pos: int = 0, n: int = 18446744073709551615) -> MSPyBentley.WString
        
        Get a substring.
        
        Parameter ``__pos``:
        Index of first character (default 0).
        
        Parameter ``__n``:
        Number of characters in substring (default remainder).
        
        Returns:
        The new string.
        
        Throws:
        std.out_of_range If pos > size().
        
        Construct and return a new string using the *__n* characters starting
        at *__pos.* If the string is too short, use the remainder of the
        characters. If *__pos* is beyond the end of the string, out_of_range
        is thrown.
        """
        ...
    
class WStringArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyBentley.WStringArray) -> None
        
        2. __init__(self: MSPyBentley.WStringArray, arg0: MSPyBentley.WStringArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyBentley.WStringArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyBentley.WStringArray, x: MSPyBentley.WString) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyBentley.WStringArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyBentley.WStringArray, x: MSPyBentley.WString) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyBentley.WStringArray, L: MSPyBentley.WStringArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.WStringArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyBentley.WStringArray, i: int, x: MSPyBentley.WString) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyBentley.WStringArray) -> MSPyBentley.WString
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.WStringArray, i: int) -> MSPyBentley.WString
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyBentley.WStringArray, x: MSPyBentley.WString) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class WStringWCharMap:
    """
    None
    """

    def __init__(self: MSPyBentley.WStringWCharMap) -> None:
        ...
    
    def items(*args, **kwargs):
        """
        items(self: MSPyBentley.WStringWCharMap) -> MSPyBentley.ItemsView[WStringWCharMap]
        """
        ...
    
    def keys(*args, **kwargs):
        """
        keys(self: MSPyBentley.WStringWCharMap) -> MSPyBentley.KeysView[WStringWCharMap]
        """
        ...
    
    def values(*args, **kwargs):
        """
        values(self: MSPyBentley.WStringWCharMap) -> MSPyBentley.ValuesView[WStringWCharMap]
        """
        ...
    
class WStringWStringMap:
    """
    None
    """

    def __init__(self: MSPyBentley.WStringWStringMap) -> None:
        ...
    
    def items(*args, **kwargs):
        """
        items(self: MSPyBentley.WStringWStringMap) -> MSPyBentley.ItemsView[WStringWStringMap]
        """
        ...
    
    def keys(*args, **kwargs):
        """
        keys(self: MSPyBentley.WStringWStringMap) -> MSPyBentley.KeysView[WStringWStringMap]
        """
        ...
    
    def values(*args, **kwargs):
        """
        values(self: MSPyBentley.WStringWStringMap) -> MSPyBentley.ValuesView[WStringWStringMap]
        """
        ...
    
eAccessViolation: BeFileNameStatus

eAccessViolationError: BeFileStatus

eAlreadyExists: BeFileNameStatus

eAppend: TextFileOpenType

eArabic: LangCodePage

eBadParameter: TextFileWriteStatus

eBaltic: LangCodePage

eBegin: BeFileSeekOrigin

eCantCreate: BeFileNameStatus

eCantDeleteDir: BeFileNameStatus

eCantDeleteFile: BeFileNameStatus

eCentral_European: LangCodePage

eCurrent: BeFileSeekOrigin

eCurrentLocale: TextFileEncoding

eCyrillic: LangCodePage

eDecimal: PrecisionType

eDecimal1Place: PrecisionFormat

eDecimal2Places: PrecisionFormat

eDecimal3Places: PrecisionFormat

eDecimal4Places: PrecisionFormat

eDecimal5Places: PrecisionFormat

eDecimal6Places: PrecisionFormat

eDecimal7Places: PrecisionFormat

eDecimal8Places: PrecisionFormat

eDecimalWhole: PrecisionFormat

eDeleteOnClose: BeFileAttributes

eEnd: BeFileSeekOrigin

eEof: TextFileReadStatus

eError: TextFileWriteStatus

eExists: BeFileNameAccess

eFileNotFound: BeFileNameStatus

eFileNotFoundError: BeFileStatus

eFileNotOpenError: BeFileStatus

eFractional: PrecisionType

eFractional1_Over_128: PrecisionFormat

eFractional1_Over_256: PrecisionFormat

eFractional1_Over_32: PrecisionFormat

eFractional1_Over_64: PrecisionFormat

eFractionalEighth: PrecisionFormat

eFractionalHalf: PrecisionFormat

eFractionalQuarter: PrecisionFormat

eFractionalSixteenth: PrecisionFormat

eFractionalWhole: PrecisionFormat

eGreek: LangCodePage

eHebrew: LangCodePage

eISCII_UNICODE_UTF_7: LangCodePage

eISCII_UNICODE_UTF_8: LangCodePage

eISO_8859_1: LangCodePage

eISO_8859_15: LangCodePage

eISO_8859_2: LangCodePage

eISO_8859_3: LangCodePage

eISO_8859_4: LangCodePage

eISO_8859_5: LangCodePage

eISO_8859_6: LangCodePage

eISO_8859_7: LangCodePage

eISO_8859_8: LangCodePage

eISO_8859_9: LangCodePage

eIllegalName: BeFileNameStatus

eIncludePrefix: HexFormatOptions

eJapanese: LangCodePage

eJohab: LangCodePage

eKeepNewLine: TextFileOptions

eKorean: LangCodePage

eLatinI: LangCodePage

eLeadingZeros: HexFormatOptions

eLeftJustify: HexFormatOptions

eNewLinesToSpace: TextFileOptions

eNone: HexFormatOptions

eNone_: TextFileOptions

eNormal: BeFileAttributes

eNotLockedError: BeFileStatus

eOEM_Baltic: LangCodePage

eOEM_Cryllic: LangCodePage

eOEM_Greek: LangCodePage

eOEM_Hebrew: LangCodePage

eOEM_LatinI: LangCodePage

eOEM_LatinII: LangCodePage

eOEM_Multilingual: LangCodePage

eOEM_Russian: LangCodePage

eOEM_Thai: LangCodePage

eOEM_Turkish: LangCodePage

eOEM_US: LangCodePage

eRandomIO: BeFileAttributes

eRead: TextFileOpenType

eReadError: BeFileStatus

eReadWrite: BeFileNameAccess

eScientific: PrecisionType

eScientific1Place: PrecisionFormat

eScientific2Places: PrecisionFormat

eScientific3Places: PrecisionFormat

eScientific4Places: PrecisionFormat

eScientific5Places: PrecisionFormat

eScientific6Places: PrecisionFormat

eScientific7Places: PrecisionFormat

eScientific8Places: PrecisionFormat

eScientificWhole: PrecisionFormat

eSharingViolationError: BeFileStatus

eSimplified_Chinese: LangCodePage

eSuccess: TextFileWriteStatus

eTooManyOpenFilesError: BeFileStatus

eTraditional_Chinese: LangCodePage

eTransparent_ASMO: LangCodePage

eTurkish: LangCodePage

eUNICODE_UCS2_Big_Endian: LangCodePage

eUNICODE_UCS2_Little_Endian: LangCodePage

eUnicode: LangCodePage

eUnknown: LangCodePage

eUnknownError: BeFileNameStatus

eUppercase: HexFormatOptions

eUsePrecision: HexFormatOptions

eUtf16: TextFileEncoding

eUtf8: TextFileEncoding

eVietnamese: LangCodePage

eWrite: TextFileOpenType

