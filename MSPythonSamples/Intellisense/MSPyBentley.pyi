from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyBentley

class AString:
    """
    A string class that has many of the same capabilities as std::string, plus
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
    
    def clear(self: MSPyBentley.AString) -> None:
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
    
    def append(self: MSPyBentley.AStringArray, x: MSPyBentley.AString) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyBentley.AStringArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyBentley.AStringArray, x: MSPyBentley.AString) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyBentley.AStringArray, L: MSPyBentley.AStringArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.AStringArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyBentley.AStringArray, i: int, x: MSPyBentley.AString) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyBentley.AStringArray) -> MSPyBentley.AString
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.AStringArray, i: int) -> MSPyBentley.AString
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyBentley.AStringArray, x: MSPyBentley.AString) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class Base64Utilities:
    """
    None
    """

    @staticmethod
    def Alphabet() -> MSPyBentley.Utf8String:
        ...
    
    @staticmethod
    def Decode(encodedString: MSPyBentley.Utf8String) -> MSPyBentley.Utf8String:
        ...
    
    @staticmethod
    def Encode(stringToEncode: MSPyBentley.Utf8String) -> MSPyBentley.Utf8String:
        ...
    
    @staticmethod
    def MatchesAlphabet(input: str) -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class BeDateTime:
    """
    Represents an instant in time, typically expressed as a date and time of day
    A DateTime also holds additional metadata about the actual date time in its DateTime::Info member.
    A DateTime's accuracy is 100's of nanoseconds (i.e hecto-nanoseconds, i.e. 1e-7 seconds)
    """

    @staticmethod
    def CommonEraTicksToJulianDay(commonEraTicks: int) -> int:
        """
        Computes the Julian Day number from the given Common Era ticks. The
        Common Era begins at 0001-01-01 00:00:00 UTC.
        
        :param in :
        commonEraTicks Common Era ticks in hecto-nanoseconds
        
        :returns:
        Julian Day number in hecto-nanoseconds
        """
        ...
    
    @staticmethod
    def Compare(lhs: MSPyBentley.BeDateTime, rhs: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTime.CompareResult:
        """
        Compares two DateTimes. This method internally converts the DateTime
        objects to Julian Days and compares those. As the conversion can fail,
        this method can return an error (see DateTime.CompareResult). This is
        also the reason why the class does not provide comparison operators
        other than equality and inequality.
        
        :param in :
        lhs Left-hand side DateTime
        
        :param in :
        rhs Right-hand side DateTime
        
        :returns:
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
        
    def ComputeOffsetToUtcInHns(self: MSPyBentley.BeDateTime) -> tuple:
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
    
    def EqualTo(self: MSPyBentley.BeDateTime, rhs: MSPyBentley.BeDateTime, ignoreDateTimeInfo: bool = False) -> bool:
        ...
    
    @staticmethod
    def FromCommonEraTicks(dateTime: MSPyBentley.BeDateTime, commonEraTicks: int, targetInfo: MSPyBentley.BeDateTimeInfo) -> BentleyStatus:
        """
        Computes the DateTime from the given Common Era ticks. The Common Era
        begins at 0001-01-01 00:00:00 UTC.
        
        :param out :
        dateTime Resulting DateTime object (on the proleptic Gregorian
        calendar)
        
        :param in :
        commonEraTicks Common Era ticks in hecto-nanoseconds
        
        :param in :
        targetInfo DateTime.Info the resulting DateTime should have
        
        :returns:
        SUCCESS if computation was successful. ERROR in case of errors,
        e.g. if computation of local time zone offset failed.
        """
        ...
    
    @staticmethod
    def FromJulianDay(dateTime: MSPyBentley.BeDateTime, julianDay: float, targetInfo: MSPyBentley.BeDateTimeInfo) -> BentleyStatus:
        ...
    
    @staticmethod
    def FromJulianDayInHns(dateTime: MSPyBentley.BeDateTime, julianDayInHns: int, targetInfo: MSPyBentley.BeDateTimeInfo) -> BentleyStatus:
        ...
    
    @staticmethod
    def FromString(dateTime: MSPyBentley.BeDateTime, dateTimeIso8601: str) -> BentleyStatus:
        """
        Parses an ISO 8601 date time string into a DateTime instance.
        
        Remark:
        s This method supports T and a space as delimiter of the date and
        time component, e.g. both <c>2013-09-15T12:05:39</c> and
        <c>2013-09-15 12:05:39</c> can be parsed into a DateTime object.
        This is a minor deviation from the ISO standard (specifies the T
        delimiter), which allows to parse SQL-99 date time literals
        (specifies the space delimiter)
        
        :param dateTime:
        the resulting DateTime instance
        
        :param dateTimeIso8601:
        the ISO 8601 date time string to parse
        
        :returns:
        SUCCESS, if parsing was successful. ERROR, otherwise
        """
        ...
    
    @staticmethod
    def FromUnixMilliseconds(dateTime: MSPyBentley.BeDateTime, unixMilliseconds: int) -> BentleyStatus:
        """
        Creates a DateTime in UTC from the given Unix epoch milliseconds
        
        :param out :
        dateTime The resulting DateTime object on the proleptic Gregorian
        calendar (in UTC).
        
        :param in :
        unixMilliseconds The Unix epoch milliseconds. Negative if they
        refer to a date before the Unix epoch (1970-01-01 00:00:00 UTC)
        
        :returns:
        SUCCESS if conversion was successful. ERROR otherwise
        """
        ...
    
    @staticmethod
    def GetCurrentTime() -> MSPyBentley.BeDateTime:
        """
        Gets the current system time in local time.
        
        :returns:
        Current system time in local time
        """
        ...
    
    @staticmethod
    def GetCurrentTimeUtc() -> MSPyBentley.BeDateTime:
        """
        Gets the current system time in UTC.
        
        :returns:
        Current system time in UTC
        """
        ...
    
    def GetDay(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the day component of this DateTime object.
        
        :returns:
        Day in the month (1 through the number in GetMonth)
        """
        ...
    
    def GetDayOfWeek(self: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTime.DayOfWeek:
        """
        Gets the day of the week of this DateTime object.
        
        Remark:
        s Only call this method if the DateTime is valid (see
        DateTime.IsValid)
        
        :returns:
        Day of the week
        """
        ...
    
    def GetDayOfYear(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the day of the year of this DateTime object.
        
        :returns:
        Day of the year or 0 if the DateTime object is not valid (see
        DateTime.IsValid)
        """
        ...
    
    def GetHectoNanosecond(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the hecto-nanosecond component of this DateTime object.
        
        Remark:
        s 1 hecto-nanosecond is 1e-7 seconds.
        
        :returns:
        Hecto-nanoseconds (0 through 9,999,999)
        """
        ...
    
    def GetHour(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the hour component of this DateTime object.
        
        :returns:
        Hours (0 through 59)
        """
        ...
    
    def GetInfo(self: MSPyBentley.BeDateTime) -> MSPyBentley.BeDateTimeInfo:
        """
        Gets meta data about this DateTime object.
        
        :returns:
        DateTime.Info of this DateTime object.
        """
        ...
    
    def GetMillisecond(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the milliseconds component of this DateTime object.
        
        Remark:
        s The hecto-nanoseconds are truncated (not rounded) at the
        millisecond position.
        
        :returns:
        Milliseconds (0 through 999)
        """
        ...
    
    def GetMinute(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the minute component of this DateTime object.
        
        :returns:
        Minutes (0 through 59)
        """
        ...
    
    def GetMonth(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the month component of this DateTime object.
        
        :returns:
        Month (1 through 12).
        """
        ...
    
    def GetSecond(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the second component of this DateTime object.
        
        :returns:
        Seconds (0 through 59)
        """
        ...
    
    def GetYear(self: MSPyBentley.BeDateTime) -> int:
        """
        Gets the year component of this DateTime object.
        
        :returns:
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
    
    @staticmethod
    def IsLeapYear(year: int) -> bool:
        """
        Indicates whether the specified year is a leap year or not
        
        :returns:
        true, if ``year`` is a leap year. false, otherwise.
        """
        ...
    
    def IsValid(self: MSPyBentley.BeDateTime) -> bool:
        """
        Indicates whether this DateTime instance is a valid date/time or not.
        
        Remark:
        s Using the default constructor creates an invalid date time as
        none of the components have been set.
        
        :returns:
        true, if the DateTime instance is valid, false otherwise
        """
        ...
    
    @staticmethod
    def JulianDayToCommonEraTicks(julianDayInHectoNanoseconds: int) -> int:
        """
        Computes Common Era ticks from the given the Julian Day number. The
        Common Era begins at 0001-01-01 00:00:00 UTC.
        
        :param in :
        julianDayInHectoNanoseconds Julian Day number
        
        :returns:
        Common Era ticks in hecto-nanoseconds
        """
        ...
    
    @staticmethod
    def JulianDayToUnixMilliseconds(julianDayInHectoNanoseconds: int) -> int:
        """
        Computes the Unix milliseconds from the given Julian Day number.
        
        :param in :
        julianDayInHectoNanoseconds Julian day in hecto-
        nanoseconds.unixMilliseconds Unix milliseconds.
        
        :returns:
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
    
    def ToCommonEraTicks(self: MSPyBentley.BeDateTime) -> tuple:
        ...
    
    def ToJulianDay(self: MSPyBentley.BeDateTime) -> tuple:
        ...
    
    def ToJulianDayInHns(self: MSPyBentley.BeDateTime) -> tuple:
        ...
    
    def ToLocalTime(self: MSPyBentley.BeDateTime, localDateTime: MSPyBentley.BeDateTime) -> BentleyStatus:
        """
        Converts this UTC DateTime to local time
        
        :param out :
        localDateTime Resulting DateTime object in local time
        
        :returns:
        SUCCESS if successful. ERROR in case of errors, e.g. if this date
        time instance is invalid (see DateTime.IsValid) or if computation
        of local time zone offset failed.
        """
        ...
    
    def ToString(self: MSPyBentley.BeDateTime) -> MSPyBentley.WString:
        """
        Converts the value of this DateTime into a string representation.
        
        Remark:
        s The resulting string is formatted according to the ISO8601
        standard. Second fractions are rounded to milliseconds.
        
        :returns:
        String representation of this DateTime object. An empty string is
        returned if this date time info object is not valid (see
        DateTime.IsValid )
        """
        ...
    
    def ToUnixMilliseconds(self: MSPyBentley.BeDateTime) -> tuple:
        ...
    
    def ToUtc(self: MSPyBentley.BeDateTime, utcDateTime: MSPyBentley.BeDateTime) -> BentleyStatus:
        """
        Converts this local DateTime to UTC
        
        :param out :
        utcDateTime Resulting DateTime object in UTC
        
        :returns:
        SUCCESS if successful. ERROR in case of errors, e.g. if this date
        time instance is invalid (see DateTime.IsValid) or if computation
        of local time zone offset failed.
        """
        ...
    
    def ToUtf8String(self: MSPyBentley.BeDateTime) -> MSPyBentley.Utf8String:
        """
        Converts the value of this DateTime into a string representation.
        
        Remark:
        s The resulting string is formatted according to the ISO8601
        standard. Second fractions are rounded to milliseconds.
        
        :returns:
        String representation of this DateTime object. An empty string is
        returned if this date time info object is not valid (see
        DateTime.IsValid )
        """
        ...
    
    @staticmethod
    def UnixMillisecondsToJulianDay(unixMilliseconds: int) -> int:
        """
        Computes the Julian Day number from the given Unix milliseconds.
        
        :param in :
        unixMilliseconds Unix milliseconds. Negative numbers indicate
        dates before the Unix epoch.
        
        :returns:
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
    
    @staticmethod
    def ComponentToString(component: MSPyBentley.BeDateTime.Component) -> MSPyBentley.WString:
        ...
    
    def GetComponent(self: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Component:
        ...
    
    def GetKind(self: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Kind:
        """
        Gets the DateTime kind.
        """
        ...
    
    @property
    def Kind(arg0: MSPyBentley.BeDateTimeInfo) -> MSPyBentley.BeDateTime.Kind:
        ...
    
    @staticmethod
    def KindToString(kind: MSPyBentley.BeDateTime.Kind) -> MSPyBentley.WString:
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
    
    def Close(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus:
        """
        Closes the disk file.
        """
        ...
    
    def Create(*args, **kwargs):
        """
        Create(self: MSPyBentley.BeFile, fileName: str, createAlways: bool = True, attribute: MSPyBentley.BeFileAttributes = <BeFileAttributes.eNormal: 0>) -> MSPyBentley.BeFileStatus
        
        Creates a new disk file
        
        :param filename:
        The full path of the file to create.
        
        :param createAlways:
        If false, returns a status other than BeFileStatus::Success, and
        does not create a new file if *filename* already exists. If true,
        deletes any existing file before creating a new one by the same
        name.
        
        :param attributes:
        File attributes.
        
        :returns:
        BeFileStatus::Success if the file was created or non-zero if
        create failed.
        """
        ...
    
    def Flush(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus:
        """
        Flushes all pending writes to the file
        
        :returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def GetAccess(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileAccess:
        """
        Gets the access mode used to open the disk file.
        """
        ...
    
    def GetLastError(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileStatus:
        """
        Gets the status returned by the last operation that failed.
        """
        ...
    
    def GetPointer(self: MSPyBentley.BeFile) -> tuple:
        """
        Gets the file read/write position
        
        :param position:
        the current read/write position
        
        :returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def GetShareMode(self: MSPyBentley.BeFile) -> MSPyBentley.BeFileSharing:
        """
        Gets the sharing option used to open the disk file.
        """
        ...
    
    def GetSize(self: MSPyBentley.BeFile) -> tuple:
        """
        Gets the size of the file.
        
        :param length:
        The size of the file in bytes
        
        :returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    @property
    def HasOpen(arg0: MSPyBentley.BeFile) -> bool:
        ...
    
    def IsOpen(self: MSPyBentley.BeFile) -> bool:
        """
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
        
        :param filename:
        The full path the file to open.
        
        :param mode:
        The file open mode.
        
        :param shareOptions:
        The file sharing options.
        
        :param attributes:
        The file attributes.
        
        :param numRetries:
        The number of times to retry the open in the event of a sharing
        violation.
        
        :returns:
        BeFileStatus::Success if the file was opened or non-zero if open
        failed.
        """
        ...
    
    def Read(self: MSPyBentley.BeFile, numBytes: int) -> tuple:
        ...
    
    def ReadEntireFile(*args, **kwargs):
        """
        Overloaded function.
        
        1. ReadEntireFile(self: MSPyBentley.BeFile, buffer: List[unsigned char]) -> MSPyBentley.BeFileStatus
        
        Reads entire file to a byte vector.
        
        2. ReadEntireFile(self: MSPyBentley.BeFile, byteStream: ByteStream) -> MSPyBentley.BeFileStatus
        
        Reads entire file to a byte vector.
        """
        ...
    
    def SetPointer(self: MSPyBentley.BeFile, position: int, origin: MSPyBentley.BeFileSeekOrigin) -> MSPyBentley.BeFileStatus:
        """
        Moves the file read/write position.
        
        :param position:
        The new read/write position.
        
        :param origin:
        The origin mode for the move.
        
        :returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    def SetSize(self: MSPyBentley.BeFile, length: int) -> MSPyBentley.BeFileStatus:
        """
        Sets the size of the file.
        
        :param length:
        The new size of the file in bytes.
        
        :returns:
        BeFileStatus.Success if the operation was successful or non-zero
        if it failed.
        """
        ...
    
    @property
    def ShareMode(arg0: MSPyBentley.BeFile) -> MSPyBentley.BeFileSharing:
        ...
    
    def Swap(self: MSPyBentley.BeFile, other: MSPyBentley.BeFile) -> None:
        """
        Swap file handles between two BeFile instances.
        
        :param other:
        The other file.
        """
        ...
    
    def Write(self: MSPyBentley.BeFile, data: bytes) -> tuple:
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

    def GetNextFileName(self: MSPyBentley.BeFileListIterator, fileName: BeFileName) -> BentleyStatus:
        """
        Retrieve the next filename found from the path list.
        
        :param name:
        The name of the next valid file from the path list.
        
        :returns:
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

    def Abbreviate(self: MSPyBentley.BeFileName, maxLength: int) -> None:
        ...
    
    def AddQuotes(self: MSPyBentley.WString) -> None:
        """
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
    
    def AppendExtension(self: MSPyBentley.BeFileName, extension: str) -> MSPyBentley.BeFileName:
        """
        Append *extension* to this filepath. A period is inserted, if
        necessary, before *extension.*
        """
        ...
    
    def AppendSeparator(self: MSPyBentley.BeFileName) -> None:
        """
        Make sure *dir* ends with a directory separator
        """
        ...
    
    @staticmethod
    def AppendSeparatorS(arg0: MSPyBentley.WString) -> None:
        """
        Make sure *dir* ends with a directory separator
        """
        ...
    
    def AppendString(self: MSPyBentley.BeFileName, string: str) -> None:
        """
        Append string.
        """
        ...
    
    def AppendToPath(self: MSPyBentley.BeFileName, additionalComponent: str) -> MSPyBentley.BeFileName:
        """
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
        
        :param in:
        The multibyte string
        
        :returns:
        Reference to this string.
        """
        ...
    
    @staticmethod
    def AreSameFile(file1: str, file2: str) -> bool:
        """
        Are two filenames equivalent?
        
        :param file1:
        name of a file
        
        :param file2:
        name of another file
        
        :returns:
        true if the two strings are aliases for the same (existing)
        physical file.
        """
        ...
    
    def AssignA(*args, **kwargs):
        """
        AssignA(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Define the contents of this WString from a CharCP using the current
        system locale
        
        :param in:
        The ASCII string
        
        :returns:
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
        
        :param in:
        The Utf8 string. May be NULL.
        
        :returns:
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
    
    @staticmethod
    def BeCompactPath(shortened: MSPyBentley.WString, path: str, length: int) -> BentleyStatus:
        """
        Shortens a file path to be no longer than the specified number of
        characters.
        
        :param shortened:
        the string shortened to the specified length
        
        :param path:
        the original path
        
        :param length:
        the number of characters to display in the shortened string
        @Return non-zero error status if not successful
        """
        ...
    
    @staticmethod
    def BeCopyFile(existingFileName: str, newFileName: str, failIfFileExists: bool = False) -> MSPyBentley.BeFileNameStatus:
        """
        Copy an existing file. If a file with the new name already exists, it
        is overwritten.
        
        :param newFileName:
        The name for the newly copied file.
        
        :param existingFileName:
        The name for the source file.
        
        :param failIfFileExists:
        Do not copy and return error if the destination file already
        exists.
        
        :returns:
        DGNFILE_STATUS_Success if the file was successfully copied.
        """
        ...
    
    @staticmethod
    def BeDeleteFile(fileName: str, removeReadOnlyAttribute: bool = False) -> MSPyBentley.BeFileNameStatus:
        """
        Delete an existing file.
        
        :param fileNameP:
        The name of an existing file.
        
        :param removeReadOnlyAttribute:
        Remove read-only attribute for the file before making an
        attempting to delete it.
        
        :returns:
        BeFileNameStatus.Success if the file was successfully deleted or
        BeFileNameStatus.CantDeleteFile if not.
        """
        ...
    
    @staticmethod
    def BeGetDiskFreeSpace(dirName: str) -> tuple:
        """
        Get free space on disk
        
        :param freeBytes:
        The amount of free space on the storage device, in bytes
        
        :param dirName:
        The name of a file or directory on the device to check
        
        :returns:
        BeFileNameStatus.Success, if the query succeeded. Non-zero if the
        directory is invalid or refers to a storage device that does not
        exist.
        """
        ...
    
    @staticmethod
    def BeGetFullPathName(path: MSPyBentley.WString, src: str) -> MSPyBentley.BeFileNameStatus:
        """
        Get the full name of a file
        
        Remark:
        s this function does not check that the file or path exists
        """
        ...
    
    @staticmethod
    def BeGetTempFileName(tempFileName: MSPyBentley.BeFileName, pathName: MSPyBentley.BeFileName, prefixString: str) -> MSPyBentley.BeFileNameStatus:
        """
        Generate a unique name for a temporary file.
        
        :param tempFileName:
        The name for a temporary file.
        
        :param pathName:
        The path to contain the temp file. If NULL, the result of
        BeGetTempPath is used.
        
        :param prefixString:
        up to 3 chars of this will be used in the generated filename
        
        :returns:
        BeFileNameStatus.Success, if the directory for the temporary file
        exists or was created. @note This method does not create a
        temporary file, it merely returns a name that can be used to
        create a temporary file.
        """
        ...
    
    @staticmethod
    def BeGetTempPath(tempFileName: MSPyBentley.BeFileName) -> MSPyBentley.BeFileNameStatus:
        """
        Retrieves the path of the directory for temporary files.
        
        :param tempFileName:
        The name for a temporary file.
        
        :returns:
        BeFileNameStatus.Success, if the directory for the temporary file
        exists or was created.
        """
        ...
    
    @staticmethod
    def BeMoveFile(oldFileName: str, newFileName: str, numRetries: int = 0) -> MSPyBentley.BeFileNameStatus:
        """
        Move or rename an existing file.
        
        :param oldFileName:
        The name of an existing file.
        
        :param newFileName:
        The new name for the file.
        
        :param numRetries:
        the number of times to retry the open in the event of a sharing
        violation
        
        :returns:
        BeFileNameStatus.Success if the file was successfully moved or
        BeFileNameStatus.UnknownError if not.
        """
        ...
    
    def BuildName(self: MSPyBentley.BeFileName, dev: str, dir: str, name: str, ext: str) -> None:
        """
        Build a BeFileName from parts of a pathname. Any values that are NULL
        are omitted.
        """
        ...
    
    @staticmethod
    def CheckAccess(fileName: str, access: MSPyBentley.BeFileNameAccess) -> MSPyBentley.BeFileNameStatus:
        """
        Check user's access to a file
        
        :param fileName:
        The name of an existing file.
        
        :param accs:
        The kinds of access to check for
        
        :returns:
        BeFileNameStatus.Success if all of the specified access rights
        are granted; non-zero if the file does not exist or some of the
        specified rights are not granted.
        """
        ...
    
    def Clear(self: MSPyBentley.BeFileName) -> None:
        """
        Clear the value of this BeFileName.
        """
        ...
    
    @staticmethod
    def CloneDirectory(sourceDir: str, destDir: str, includeSubDirs: bool = True) -> MSPyBentley.BeFileNameStatus:
        """
        Clone the contents of an existing directory, and optionally its
        subdirectories, into a new directory.
        
        :param destDir:
        The name for the new directory.
        
        :param sourceDir:
        The source directory to clone.
        
        :param includeSubDirs:
        If true, also clone all subdirectories, recursively.
        
        :returns:
        DGNFILE_STATUS_Success if the directory was successfully cloned.
        """
        ...
    
    def CompareTo(*args, **kwargs):
        """
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
        
        :returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        :param other:
        The other string.
        """
        ...
    
    def CompareToI(*args, **kwargs):
        """
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
        
        :returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        :param other:
        The other string.
        """
        ...
    
    def Contains(*args, **kwargs):
        """
        Overloaded function.
        
        1. Contains(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string.
        
        :param other:
        The other string.
        
        :returns:
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
        Overloaded function.
        
        1. ContainsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        :param other:
        The other string.
        
        :returns:
        true if this string contains the other string.
        
        2. ContainsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        """
        ...
    
    @staticmethod
    def CreateNewDirectory(path: str) -> MSPyBentley.BeFileNameStatus:
        """
        Create a new directory.
        
        :param path:
        The pathname for the new directory.
        
        :returns:
        DGNFILE_STATUS_Success if the directory was successfully created.
        @note this method will return an error if the directory already
        exists.
        """
        ...
    
    @staticmethod
    def DoesPathExist(path: str) -> bool:
        """
        Test whether a pathname refers to an existing file or directory.
        
        :param path:
        The pathname to test.
        
        :returns:
        true if the pathname refers to an existing file or directory.
        """
        ...
    
    def DropQuotes(self: MSPyBentley.WString) -> None:
        """
        Remove quotes from around a string.
        """
        ...
    
    @staticmethod
    def EmptyAndRemoveDirectory(path: str) -> MSPyBentley.BeFileNameStatus:
        """
        Recursively empty all of the contents of an existing directory and
        then remove it.
        
        :param path:
        The pathname for the directory to remove.
        
        :returns:
        DGNFILE_STATUS_Success if the directory was successfully removed.
        """
        ...
    
    def EndsWith(self: MSPyBentley.WString, endChars: str) -> bool:
        """
        Determines if this instance ends with the provided string.
        """
        ...
    
    def EndsWithI(self: MSPyBentley.WString, endChars: str) -> bool:
        """
        Determines if this instance ends with the provided string, ignoring
        case.
        """
        ...
    
    def Equals(*args, **kwargs):
        """
        Overloaded function.
        
        1. Equals(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string.
        
        :returns:
        true if the strings are equal.
        
        :param other:
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
        Overloaded function.
        
        1. EqualsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string, ignoring case.
        
        :returns:
        true if the strings are equal (ignoring case).
        
        :param other:
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
        
    def FindI(self: MSPyBentley.WString, findString: str) -> int:
        """
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    @staticmethod
    def FindRelativePath(relativePath: MSPyBentley.WString, targetFileName: str, rootFileName: str) -> None:
        """
        Finds the relative path from a root file to the target file. If the
        files are on different devices, targetFileName is copied to
        relativePath.
        
        :param relativePath:
        (output) the relative path to the target file
        
        :param targetFileName:
        (input) the full file specification of the file the relative path is
        needed for.
        
        :param rootFileName:
        (input) the full file specification of the root for the relative path.
        """
        ...
    
    @staticmethod
    def FixPathName(path: MSPyBentley.WString, original: str) -> MSPyBentley.BeFileNameStatus:
        """
        Perform any platform-specific fixes of an input pathname into a
        " canonical " pathname. On Windows, this includes converting forward
        slashes to backslashes and removing double backslashes. It also
        removes " \\ " and " \\ " notation. On other platforms those rules may be
        different.
        
        :param path:
        The " fixed " version of the pathname.
        
        :param original:
        The " raw " pathname.
        
        :returns:
        DGNFILE_STATUS_Success if the pathname was successfully " fixed "
        (whether any changes were made or not), or PATH_IllegalName if the
        pathname is invalid for any reason.
        """
        ...
    
    @staticmethod
    def GetDevice(path: str) -> MSPyBentley.WString:
        """
        Returns the device letter from path - Empty if the path doesn't start
        with a device. Always empty on unix.
        """
        ...
    
    @staticmethod
    def GetDirectoryName(path: str) -> MSPyBentley.WString:
        """
        Returns the complete directory (including drive, if any) from path.
        Has terminating separator.
        """
        ...
    
    @staticmethod
    def GetDirectoryWithoutDevice(path: str) -> MSPyBentley.WString:
        """
        Returns the directory (excluding drive) from path. Has terminating
        separator.
        """
        ...
    
    @staticmethod
    def GetExtension(path: str) -> MSPyBentley.WString:
        """
        Returns the filename extension from path (everything following the
        last dot non-inclusive), or empty if there is none.
        """
        ...
    
    @staticmethod
    def GetFileNameAndExtension(path: str) -> MSPyBentley.WString:
        """
        Returns the filename from path, including extension, but not
        directory.
        """
        ...
    
    @staticmethod
    def GetFileNameWithoutExtension(path: str) -> MSPyBentley.WString:
        """
        Returns the base filename from path, with no directory or extension.
        """
        ...
    
    @staticmethod
    def GetFileSize(fileName: str) -> tuple:
        """
        Get file size
        @param in fileName The name of an existing file.
        @return the file size
        """
        ...
    
    def GetFullPathName(self: MSPyBentley.BeFileName) -> MSPyBentley.BeFileNameStatus:
        ...
    
    def GetMaxLocaleCharBytes(self: MSPyBentley.WString) -> int:
        """
        Get the number of bytes required to hold the current string. This is
        the value to use to allocate a buffer (e.g. via _alloca) to to call
        #ConvertToLocaleChars.
        """
        ...
    
    def GetName(self: MSPyBentley.BeFileName) -> str:
        """
        Copy name into WChar buffer.
        """
        ...
    
    @staticmethod
    def GetTargetOfSymbolicLink(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetTargetOfSymbolicLink(targetFileName: MSPyBentley.BeFileName, path: str) -> BentleyStatus
        
        Determines a symbolic link's target. This recurses, meaning that it
        keeps evaluating each incremental target until it reaches a concrete
        file, or the target does not exist.
        
        2. GetTargetOfSymbolicLink(targetFileName: MSPyBentley.BeFileName, path: str, shouldRecurse: bool) -> BentleyStatus
        
        Determines a symbolic link's target. This recurses, meaning that it
        keeps evaluating each incremental target until it reaches a concrete
        file, or the target does not exist.
        """
        ...
    
    def GetUri(self: MSPyBentley.BeFileName) -> MSPyBentley.Utf8String:
        """
        Get the URI for this BeFileName.
        """
        ...
    
    def GetWCharCP(self: MSPyBentley.WString) -> str:
        """
        Equivalent to c_str
        """
        ...
    
    def IsAbsolutePath(self: MSPyBentley.BeFileName) -> bool:
        """
        Test if a filename is an absolute path.
        """
        ...
    
    @staticmethod
    def IsDirectory(path: str) -> bool:
        """
        Test whether a pathname refers to an existing directory.
        
        :param path:
        The pathname to test.
        
        :returns:
        true if the pathname refers to an existing directory.
        """
        ...
    
    def IsEmpty(self: MSPyBentley.BeFileName) -> bool:
        """
        Determines if the value of this BeFileName is empty (blank).
        """
        ...
    
    def IsNullOrEmpty(str: str) -> bool:
        """
        True if the provided string is NULL or contains no character data.
        """
        ...
    
    @staticmethod
    def IsRemovableMedia(fileName: str) -> bool:
        """
        Check if path is located on a removable storage device.
        
        :param fn:
        The name of a file or directory on the device to check
        
        :returns:
        true if the storage device is removable
        """
        ...
    
    @staticmethod
    def IsSymbolicLink(path: str) -> bool:
        """
        Determines if the path is a symbolic link. If the path does not exist,
        also returns false.
        """
        ...
    
    def IsUrl(self: MSPyBentley.BeFileName) -> bool:
        """
        Test if a filename is an URL.
        """
        ...
    
    @staticmethod
    def MoveToRecycleBin(path: str) -> MSPyBentley.BeFileNameStatus:
        """
        Move an existing file or an existing directory to Recycle Bin (on
        Windows).
        
        :param path:
        The pathname for the file or directory to remove.
        
        :returns:
        DGNFILE_STATUS_Success if the target was successfully removed.
        """
        ...
    
    @property
    def Name(arg0: MSPyBentley.BeFileName) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyBentley.BeFileName, arg1: str) -> None:
        ...
    
    def OverrideNameParts(self: MSPyBentley.BeFileName, overrideName: str) -> None:
        """
        Override values for parts of a file name. If the override name
        includes a value for a part of the name, that value is used. Otherwise
        the current value is preserved.
        """
        ...
    
    def PadLeft(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None:
        """
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the left side.
        """
        ...
    
    def PadRight(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None:
        """
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the right side.
        """
        ...
    
    def ParseName(self: MSPyBentley.BeFileName, dev: MSPyBentley.WString, dir: MSPyBentley.WString, name: MSPyBentley.WString, ext: MSPyBentley.WString) -> None:
        """
        Parse a full filename into WStrings for the device, directory,
        filename, and extension.
        
        :param dev:
        The device part of this filename. May be NULL.
        
        :param dir:
        The directory part of this filename. May be NULL.
        
        :param name:
        The filename part of this filename. May be NULL.
        
        :param ext:
        The extension part of this filename. May be NULL.
        
        :param fullFileName:
        The filename to parse.
        """
        ...
    
    def ParseNameNoClear(self: MSPyBentley.BeFileName, dev: MSPyBentley.WString, dir: MSPyBentley.WString, name: MSPyBentley.WString, ext: MSPyBentley.WString) -> None:
        """
        Parse a full filename into WStrings for the device, directory,
        filename, and extension. If the input does not contain a file part,
        the output is not changed.
        
        :param dev:
        The device part of this filename. May be NULL.
        
        :param dir:
        The directory part of this filename. May be NULL.
        
        :param name:
        The filename part of this filename. May be NULL.
        
        :param ext:
        The extension part of this filename. May be NULL.
        
        :param fullFileName:
        The filename to parse.
        """
        ...
    
    def PopDir(self: MSPyBentley.BeFileName) -> None:
        """
        Remove the right-most component from the path. If this BeFileName
        contains a single dirctory (or otherwise contains no directory
        separators), it becomes empty as a result of this function.
        """
        ...
    
    def RemoveQuotes(self: MSPyBentley.BeFileName) -> None:
        """
        Remove enclosing quotes
        """
        ...
    
    def ReplaceAll(self: MSPyBentley.WString, subStringToReplace: str, replacement: str) -> int:
        """
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def ReplaceI(self: MSPyBentley.WString, findString: str, replaceString: str) -> bool:
        """
        Replace first occurrence of findString with replaceString, ignoring
        case.
        
        :param findString:
        The substring to find.
        
        :param replaceString:
        The replacement string.
        
        :returns:
        true is a replacement is made.
        """
        ...
    
    @staticmethod
    def ResolveRelativePath(fullPath: MSPyBentley.WString, relativeFileName: str, basePath: str) -> BentleyStatus:
        """
        Generates a fullpath by resolving relativeFileName relative to
        basePath.
        
        :param fullPath:
        (output) the full path resolved from the inputs.
        
        :param relativeFileName:
        (input) the relative file name to resolve.
        
        :param basePath:
        (input) used as a root for the expansion. @Return non-zero error status
        if not successful @Remarks This function only performs a string
        manipulation. It does not require or make any use of an actual
        file.
        """
        ...
    
    @staticmethod
    def SetFileReadOnly(fileName: str, readOnly: bool) -> MSPyBentley.BeFileNameStatus:
        """
        Set the read-only status of an existing file
        
        :param fileName:
        The name of an existing file.
        
        :param readOnly:
        the desired read-only status
        
        :returns:
        BeFileNameStatus.Success if the operation was successful or non-
        zero if not
        """
        ...
    
    def SetName(self: MSPyBentley.BeFileName, name: str) -> None:
        """
        Change the value of this BeFileName.
        
        :param name:
        The new value for this BeFileName. If NULL, the value is cleared.
        """
        ...
    
    def StartsWith(self: MSPyBentley.WString, startChars: str) -> bool:
        """
        Determines if this instance starts with the provided string.
        """
        ...
    
    def StartsWithI(self: MSPyBentley.WString, startChars: str) -> bool:
        """
        Determines if this instance starts with the provided string, ignoring
        case.
        """
        ...
    
    def StripSeparatorAtEnd(self: MSPyBentley.BeFileName) -> None:
        """
        Strip all separators at the end
        """
        ...
    
    @staticmethod
    def StripSeparatorAtEndS(arg0: MSPyBentley.WString) -> None:
        """
        Strip all separators at the end
        """
        ...
    
    def StripWhiteSpace(self: MSPyBentley.BeFileName) -> None:
        """
        Remove white space
        """
        ...
    
    def SupplyDefaultNameParts(self: MSPyBentley.BeFileName, defaultName: str) -> None:
        """
        Supply default values for parts of a file name. If the existing name
        includes a value for a part of the name, that value is preserved.
        Otherwise the default is used.
        """
        ...
    
    def ToLower(self: MSPyBentley.WString) -> None:
        """
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def ToUpper(self: MSPyBentley.WString) -> None:
        """
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def Trim(*args, **kwargs):
        """
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
        @param in mask Mask of the parts of fullName that will used to construct this BeFileName
        @param in fullName The full pathname from which this BeFileName is to be constructed.
        
        4. __init__(self: MSPyBentley.BeFileName, dev: str, dir: str, name: str, ext: str) -> None
        
        Construct a BeFileName from parts of a pathname. Any values that are NULL are omitted.
        """
        ...
    
    def clear(self: MSPyBentley.WString) -> None:
        ...
    
    eAll: FileNameParts
    
    eBasename: FileNameParts
    
    eDevAndDir: FileNameParts
    
    eDevice: FileNameParts
    
    eDirectory: FileNameParts
    
    eExtension: FileNameParts
    
    eNameAndExt: FileNameParts
    
    def substr(self: MSPyBentley.WString, pos: int = 0, n: int = 18446744073709551615) -> MSPyBentley.WString:
        """
        Get a substring.
        
        :param __pos:
        Index of first character (default 0).
        
        :param __n:
        Number of characters in substring (default remainder).
        
        :returns:
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
    
def BeGetComputerName(arg0: MSPyBentley.WString) -> BentleyStatus:
    ...

def BeGetComputerNameA(arg0: MSPyBentley.AString) -> BentleyStatus:
    ...

def BeGetUserName(arg0: MSPyBentley.WString) -> BentleyStatus:
    ...

def BeGetUserNameA(arg0: MSPyBentley.AString) -> BentleyStatus:
    ...

class BeStringUtilities:
    """
    None
    """

    AsManyAsPossible: int
    
    @staticmethod
    def FormatUInt64(dest: MSPyBentley.WString, val: int, opts: MSPyBentley.HexFormatOptions, width: int = 0, precision: int = 1) -> int:
        """
        Formats an unsigned 64-bit integer using the same options supported by
        printf's " % x " and " % X " specifiers.
        
        :param dest:
        The buffer which will hold the string representation of the
        integer. Must not be NULL.
        
        :param numCharsInBuffer:
        The maximum number of characters which can be written to *dest,*
        including the null terminator. Must be at least 1.
        
        :param val:
        The value to format
        
        :param opts:
        Flags indicating how formatting should be applied
        
        :param width:
        The minimum number of characters in the formatted string.
        Additional characters will be added according to *opts.* Width >
        18 will be truncated to 18.
        
        :param precision:
        The minimum number of digits in the formatted string. Leading
        zeros will be prepended to match the precision. Precision> 16
        will be truncated to 16.
        
        :returns:
        Returns the number of characters written to *dest,* not including
        the null terminator
        
        Remark:
        s If the length of the formatted string exceeds
        *numCharsInBuffer,* the string is truncated (i.e.,
        dest\\[numCharsInBuffer-1\\] = 0;)
        
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
    
    @staticmethod
    def Join(strings: MSPyBentley.WStringArray, delimiter: str) -> MSPyBentley.WString:
        """
        Joins a list of strings into a single string, optionally separated by
        a delimiter.
        
        :param strings:
        The list of strings to join
        
        :param delimiter:
        The delimiter to be inserted between each string
        
        :returns:
        Returns a string comprised of all strings in the list in input
        order, separated by the supplied delimiter.
        """
        ...
    
    @staticmethod
    def LexicographicCompare(value0: MSPyBentley.WString, value1: MSPyBentley.WString) -> int:
        """
        Do a lexicographic comparison of specified strings. This is an
        alphabetical sort that also takes numbers into account, such that
        " file9 " will come before " file11 " in the sort order (even though
        alphabetically 1 is before 9). This method always ignores case.
        param in pszName1 (input) first string param in pszName2 (input) second string
        return 0 if strings are equal,<0 if pszName1 is less than pszName2,
        else> 0
        """
        ...
    
    NPOS: int
    
    @staticmethod
    def ParseArguments(subStrings: MSPyBentley.WStringArray, inString: MSPyBentley.WString, auxDelimiters: MSPyBentley.WString) -> None:
        """
        Default logic for parsing a user supplied argument list. Tokenizes
        based on whitespace and does not tokenize within double-quoted
        substrings.
        
        :param subStrings:
        The resulting sub strings will be added to this collection
        
        :param inString:
        The string to tokenize; cannot be NULL or empty
        
        :param auxDelimiters:
        (optional) Each character in the string Will be used as a
        delimiter in addition to whitespace.
        """
        ...
    
    @staticmethod
    def ParseUInt64(value: int, string: MSPyBentley.WString) -> tuple:
        """
        Parses a string containing an integer number in decimal format
        
        :param value:
        The resulting integer number
        
        :param string:
        A string representation of a decimal value.
        
        Remark:
        s ``string`` must not contain any extra characters or whitespace.
        This function does not skip leading whitespace or stop at trailing
        characters, as a function like strtoul would do. That kind of
        parsing is for the higher level caller to do.
        """
        ...
    
    @staticmethod
    def Split(*args, **kwargs):
        """
        Overloaded function.
        
        1. Split(str: MSPyBentley.WString, delimiters: MSPyBentley.WString, tokens: MSPyBentley.WStringArray) -> None
        
        Tokenizes a string based on the provided delimiters, and adds a
        WString for each token into the provided collection. This essentially
        wraps wcstok for more convenient access.
        
        :param str:
        The string to tokenize; cannot be NULL or empty
        
        :param delimiters:
        One or more delimiters; cannot be NULL or empty
        
        :param tokens:
        One or more tokens
        
        2. Split(str: MSPyBentley.WString, delimiters: MSPyBentley.WString, escapeChars: MSPyBentley.WString, tokens: MSPyBentley.WStringArray) -> None
        
        Tokenizes a string based on the provided delimiters, and adds a
        WString for each token into the provided collection. This essentially
        wraps wcstok for more convenient access.
        
        :param str:
        The string to tokenize; cannot be NULL or empty
        
        :param delimiters:
        One or more delimiters; cannot be NULL or empty
        
        :param tokens:
        One or more tokens
        """
        ...
    
    @staticmethod
    def WCharToUtf8(outStr: MSPyBentley.Utf8String, inStr: str, _count: int = 18446744073709551615) -> BentleyStatus:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
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
    
class IntIntMap:
    """
    None
    """

    def __init__(self: MSPyBentley.IntIntMap) -> None:
        ...
    
    def items(self: MSPyBentley.IntIntMap) -> MSPyBentley.ItemsView[IntIntMap]:
        ...
    
    def keys(self: MSPyBentley.IntIntMap) -> MSPyBentley.KeysView[IntIntMap]:
        ...
    
    def values(self: MSPyBentley.IntIntMap) -> MSPyBentley.ValuesView[IntIntMap]:
        ...
    
class ItemsView[IntIntMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
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
    
class KeysView[IntIntMap]:
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

    @staticmethod
    def ClearNameSpaceUsing() -> None:
        ...
    
    @staticmethod
    def DelNameSpaceUsing(namespaceID: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> int:
        ...
    
    @staticmethod
    def IsNameSpaceUsing(namespaceID: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> bool:
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
        
    @staticmethod
    def SetDefaultNameSpaceList() -> None:
        ...
    
    @staticmethod
    def UsingNameSpace(namespaceID: MSPyBentley.PyNameSpaceManager.NameSpaceID) -> int:
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
    
class Utf8String:
    """
    Contains a UTF-8 encoded string. This class has many of the capabilities of a python string
    This class also defines utility functions for constructing and manipulating the string
    """

    def Assign(self: MSPyBentley.Utf8String, str: str) -> MSPyBentley.Utf8String:
        """
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
        Overloaded function.
        
        1. CompareTo(self: MSPyBentley.Utf8String, other: str) -> int
        
        Perform a (case-sensitive) comparison.
        
        :returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        :param other:
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
        Overloaded function.
        
        1. CompareToI(self: MSPyBentley.Utf8String, other: str) -> int
        
        Perform a case-insensitive comparison.
        
        :returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        :param other:
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
        Overloaded function.
        
        1. Equals(self: MSPyBentley.Utf8String, other: str) -> bool
        
        Test for equality with another string.
        
        :returns:
        true if the strings are equal.
        
        :param other:
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
        Overloaded function.
        
        1. EqualsI(self: MSPyBentley.Utf8String, other: str) -> bool
        
        Test for equality with another string, ignoring case.
        
        :returns:
        true if the strings are equal (ignoring case).
        
        :param other:
        The other string.
        
        2. EqualsI(self: MSPyBentley.Utf8String, other: MSPyBentley.Utf8String) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def GetNextToken(self: MSPyBentley.Utf8String, next: MSPyBentley.Utf8String, delims: str, offset: int) -> int:
        """
        Reads the next token delimited by any character in *delims* or \0.
        
        :param next:
        set to next token, if found, or cleared if not
        
        :param delims:
        the characters that could delimit the tokens
        
        :param offset:
        where to start search
        
        :returns:
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
    
    def IsAscii(self: MSPyBentley.Utf8String) -> bool:
        """
        Test if this string contains only characters less than or equal to
        127.
        """
        ...
    
    @staticmethod
    def IsAsciiWhiteSpace(val: str) -> bool:
        """
        Determine whether the supplied character is a whitespace character in
        the ascii (below 128) code page. This is necessary since the c
        "isspace" function is locale specific and sometimes returns true for
        the non-breaking-space character (0xA0), which is not a valid test for
        a Utf8 string. Note this does not test for VT, or FF as they are
        considered obsolete.
        """
        ...
    
    @staticmethod
    def IsNullOrEmpty(value: str) -> bool:
        """
        Utility function to test if *value* represents the empty string. This
        function interprets NULL to be the empty string.
        """
        ...
    
    def ReplaceAll(self: MSPyBentley.Utf8String, subStringToReplace: str, replacement: str) -> int:
        """
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def SizeInBytes(self: MSPyBentley.Utf8String) -> int:
        """
        Computes the size, in bytes, of this string's data, including its
        NULL-terminator.
        """
        ...
    
    def StartsWith(self: MSPyBentley.Utf8String, startChars: str) -> bool:
        """
        Determines if this instance starts with the provided string.
        """
        ...
    
    def ToLower(self: MSPyBentley.Utf8String) -> None:
        """
        Converts this string, in-place, to all lower case.
        
        Remark:
        s This function can be very slow if the string contains non-ascii
        characters.
        """
        ...
    
    @staticmethod
    def ToLowerChar(c: str) -> str:
        """
        Equivalent to tolower
        """
        ...
    
    def Trim(*args, **kwargs):
        """
        Overloaded function.
        
        1. Trim(self: MSPyBentley.Utf8String) -> None
        
        Removes all whitespace from the left and right sides. Whitespace
        includes space, line feed, carriage return, and tab (e.g. iswspace).
        
        2. Trim(self: MSPyBentley.Utf8String, trimCharacters: str) -> None
        
        Removes all instances of any of the given characters from the left and
        right sides.
        """
        ...
    
    def TrimEnd(self: MSPyBentley.Utf8String) -> MSPyBentley.Utf8String:
        """
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
    
    def clear(self: MSPyBentley.Utf8String) -> None:
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
    
    def append(self: MSPyBentley.Utf8StringArray, x: MSPyBentley.Utf8String) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyBentley.Utf8StringArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyBentley.Utf8StringArray, x: MSPyBentley.Utf8String) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyBentley.Utf8StringArray, L: MSPyBentley.Utf8StringArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.Utf8StringArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyBentley.Utf8StringArray, i: int, x: MSPyBentley.Utf8String) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyBentley.Utf8StringArray) -> MSPyBentley.Utf8String
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.Utf8StringArray, i: int) -> MSPyBentley.Utf8String
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyBentley.Utf8StringArray, x: MSPyBentley.Utf8String) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ValuesView[IntIntMap]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
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
    
    def append(self: MSPyBentley.WCharArray, x: str) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyBentley.WCharArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyBentley.WCharArray, x: str) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyBentley.WCharArray, L: MSPyBentley.WCharArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.WCharArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyBentley.WCharArray, i: int, x: str) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyBentley.WCharArray) -> str
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.WCharArray, i: int) -> str
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyBentley.WCharArray, x: str) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class WString:
    """
    A string class that has many of the same capabilities as std::string,
    plus additional functions such as conversion from UTF-8, UTF-16, and local-encoded strings,
    case-insensitive compare, trimming, padding, and others.
    """

    def AddQuotes(self: MSPyBentley.WString) -> None:
        """
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
        
        :param in:
        The multibyte string
        
        :returns:
        Reference to this string.
        """
        ...
    
    def AssignA(*args, **kwargs):
        """
        AssignA(self: MSPyBentley.WString, in: str) -> MSPyBentley.WString
        
        Define the contents of this WString from a CharCP using the current
        system locale
        
        :param in:
        The ASCII string
        
        :returns:
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
        
        :param in:
        The Utf8 string. May be NULL.
        
        :returns:
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
        
        :returns:
        0 if the strings are equal, or -1 or 1 if this string should come
        before or after *other.*
        
        :param other:
        The other string.
        """
        ...
    
    def CompareToI(*args, **kwargs):
        """
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
        
        :returns:
        0 if the strings are equal (ignoring case), or -1 or 1 if this
        string should come before or after *other.*
        
        :param other:
        The other string.
        """
        ...
    
    def Contains(*args, **kwargs):
        """
        Overloaded function.
        
        1. Contains(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string.
        
        :param other:
        The other string.
        
        :returns:
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
        Overloaded function.
        
        1. ContainsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        :param other:
        The other string.
        
        :returns:
        true if this string contains the other string.
        
        2. ContainsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for whether this string contains another string, ignoring case.
        
        Parameter ``other``:
        The other string.
        
        Returns:
        true if this string contains the other string.
        """
        ...
    
    def DropQuotes(self: MSPyBentley.WString) -> None:
        """
        Remove quotes from around a string.
        """
        ...
    
    def EndsWith(self: MSPyBentley.WString, endChars: str) -> bool:
        """
        Determines if this instance ends with the provided string.
        """
        ...
    
    def EndsWithI(self: MSPyBentley.WString, endChars: str) -> bool:
        """
        Determines if this instance ends with the provided string, ignoring
        case.
        """
        ...
    
    def Equals(*args, **kwargs):
        """
        Overloaded function.
        
        1. Equals(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string.
        
        :returns:
        true if the strings are equal.
        
        :param other:
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
        Overloaded function.
        
        1. EqualsI(self: MSPyBentley.WString, other: str) -> bool
        
        Test for equality with another string, ignoring case.
        
        :returns:
        true if the strings are equal (ignoring case).
        
        :param other:
        The other string.
        
        2. EqualsI(self: MSPyBentley.WString, other: MSPyBentley.WString) -> bool
        
        Test for equality with another string, ignoring case.
        
        Returns:
        true if the strings are equal (ignoring case).
        
        Parameter ``other``:
        The other string.
        """
        ...
    
    def FindI(self: MSPyBentley.WString, findString: str) -> int:
        """
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def GetMaxLocaleCharBytes(self: MSPyBentley.WString) -> int:
        """
        Get the number of bytes required to hold the current string. This is
        the value to use to allocate a buffer (e.g. via _alloca) to to call
        #ConvertToLocaleChars.
        """
        ...
    
    def GetWCharCP(self: MSPyBentley.WString) -> str:
        """
        Equivalent to c_str
        """
        ...
    
    def IsEmpty(self: MSPyBentley.WString) -> bool:
        ...
    
    @staticmethod
    def IsNullOrEmpty(str: str) -> bool:
        """
        True if the provided string is NULL or contains no character data.
        """
        ...
    
    def PadLeft(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None:
        """
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the left side.
        """
        ...
    
    def PadRight(self: MSPyBentley.WString, totalSize: int, charToPadWidth: str) -> None:
        """
        Pads, if necessary, to the given totalSize by adding charToPadWith to
        the right side.
        """
        ...
    
    def ReplaceAll(self: MSPyBentley.WString, subStringToReplace: str, replacement: str) -> int:
        """
        Replace all instances of a sub string. Returns the number of
        replacements made.
        """
        ...
    
    def ReplaceI(self: MSPyBentley.WString, findString: str, replaceString: str) -> bool:
        """
        Replace first occurrence of findString with replaceString, ignoring
        case.
        
        :param findString:
        The substring to find.
        
        :param replaceString:
        The replacement string.
        
        :returns:
        true is a replacement is made.
        """
        ...
    
    def StartsWith(self: MSPyBentley.WString, startChars: str) -> bool:
        """
        Determines if this instance starts with the provided string.
        """
        ...
    
    def StartsWithI(self: MSPyBentley.WString, startChars: str) -> bool:
        """
        Determines if this instance starts with the provided string, ignoring
        case.
        """
        ...
    
    def ToLower(self: MSPyBentley.WString) -> None:
        """
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def ToUpper(self: MSPyBentley.WString) -> None:
        """
        Remark:
        s A WString can share the string buffer with another WString
        object. Do not try to modify its internal buffer without first
        triggering the copy-on-write mechanism to make sure that this
        object has its own copy.
        """
        ...
    
    def Trim(*args, **kwargs):
        """
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
        
        7. __init__(self: MSPyBentley.WString, in: str, encoding: BentleyCharEncoding) -> None
        
        Construct a WString from a CharCP string in the specified encoding
        """
        ...
    
    def clear(self: MSPyBentley.WString) -> None:
        ...
    
    def substr(self: MSPyBentley.WString, pos: int = 0, n: int = 18446744073709551615) -> MSPyBentley.WString:
        """
        Get a substring.
        
        :param __pos:
        Index of first character (default 0).
        
        :param __n:
        Number of characters in substring (default remainder).
        
        :returns:
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
    
    def append(self: MSPyBentley.WStringArray, x: MSPyBentley.WString) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyBentley.WStringArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyBentley.WStringArray, x: MSPyBentley.WString) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyBentley.WStringArray, L: MSPyBentley.WStringArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyBentley.WStringArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyBentley.WStringArray, i: int, x: MSPyBentley.WString) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyBentley.WStringArray) -> MSPyBentley.WString
        
        Remove and return the last item
        
        2. pop(self: MSPyBentley.WStringArray, i: int) -> MSPyBentley.WString
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyBentley.WStringArray, x: MSPyBentley.WString) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class WStringWCharMap:
    """
    None
    """

    def __init__(self: MSPyBentley.WStringWCharMap) -> None:
        ...
    
    def items(self: MSPyBentley.WStringWCharMap) -> MSPyBentley.ItemsView[WStringWCharMap]:
        ...
    
    def keys(self: MSPyBentley.WStringWCharMap) -> MSPyBentley.KeysView[WStringWCharMap]:
        ...
    
    def values(self: MSPyBentley.WStringWCharMap) -> MSPyBentley.ValuesView[WStringWCharMap]:
        ...
    
class WStringWStringMap:
    """
    None
    """

    def __init__(self: MSPyBentley.WStringWStringMap) -> None:
        ...
    
    def items(self: MSPyBentley.WStringWStringMap) -> MSPyBentley.ItemsView[WStringWStringMap]:
        ...
    
    def keys(self: MSPyBentley.WStringWStringMap) -> MSPyBentley.KeysView[WStringWStringMap]:
        ...
    
    def values(self: MSPyBentley.WStringWStringMap) -> MSPyBentley.ValuesView[WStringWStringMap]:
        ...
    
eAccessViolation: BeFileNameStatus

eAccessViolationError: BeFileStatus

eAlreadyExists: BeFileNameStatus

eArabic: LangCodePage

eBaltic: LangCodePage

eBegin: BeFileSeekOrigin

eCantCreate: BeFileNameStatus

eCantDeleteDir: BeFileNameStatus

eCantDeleteFile: BeFileNameStatus

eCentral_European: LangCodePage

eCurrent: BeFileSeekOrigin

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

eKorean: LangCodePage

eLatinI: LangCodePage

eLeadingZeros: HexFormatOptions

eLeftJustify: HexFormatOptions

eNone: HexFormatOptions

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

eRead: BeFileNameAccess

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

eSuccess: BeFileNameStatus

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

eVietnamese: LangCodePage

eWrite: BeFileNameAccess

