/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\valueparse.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ValueParse.h>



static const char * __doc_Bentley_DgnPlatform_VolumeParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeParser_ToValue =R"doc(Parse a string into a distance value in uors.


Parameter ``in``:
    input string.

Returns (Tuple, 0):
	retVal. SUCCESS if parsed successfully. ERROR otherwise..

Returns (Tuple, 1) :
	outVal. resulting distance in uors if successfully parsed.

)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeParser_SetScale =R"doc(The value will be scaled by the square of this factor after it is
parsed.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeParser_GetScale =R"doc(The value will be scaled by the square of this factor after it is
parsed.)doc";

static const char * __doc_Bentley_DgnPlatform_AreaOrVolumeParser_SetMasterUnitScale =R"doc(Set Master and Sub Units manually. Normally, use the SetUnits()*
method)doc";

static const char * __doc_Bentley_DgnPlatform_PointParser_SetIs3d =R"doc(If this flag is true, the parse requires three coordinates in the
string.)doc";

static const char * __doc_Bentley_DgnPlatform_PointParser_GetIs3d =R"doc(If this flag is true, the parse requires three coordinates in the
string.)doc";

static const char * __doc_Bentley_DgnPlatform_PointParser_GetDistanceParser =R"doc(Get the distance parser used by this parser for each coordinate of the
point. Changes made to this object will affect the future behavior of
the PointParser.)doc";

static const char * __doc_Bentley_DgnPlatform_PointParser_ToValue =R"doc(Parse a string into a point value in uors.

Parameter ``in``:
    input string. 
Returns (Tuple, 0):
	retVal. SUCCESS if parsed successfully. ERROR otherwise..

Returns (Tuple, 1) :
	outVal.     resulting point if successfully parsed.

)doc";    

static const char * __doc_Bentley_DgnPlatform_PointParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceParser_ToValue =R"doc(Parse a string into a distance value in uors.

Parameter ``out``:
    resulting distance in uors if successfully parsed.

Parameter ``in``:
    input string. 

Returns (Tuple, 0):
	retVal. SUCCESS if parsed successfully. ERROR otherwise..

Returns (Tuple, 1) :
	outVal.     resulting distance in uors if successfully parsed.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DistanceParser_SetScale =R"doc(The value will be scaled by this factor after it is parsed.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceParser_GetScale =R"doc(The value will be scaled by this factor after it is parsed.)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceParser_SetMasterUnitLabel =R"doc(Set Master and Sub Units manually. Normally, use the SetUnits()*
method)doc";

static const char * __doc_Bentley_DgnPlatform_DistanceParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_ToValue =R"doc(Parse a string into a direction value in degrees.


Parameter ``in``:
    input string. 

Returns (Tuple, 0):
	retVal. SUCCESS if parsed successfully. ERROR otherwise..

Returns (Tuple, 1) :
	outVal. resulting direction in degrees if successfully parsed.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DirectionParser_SetBaseDirection =R"doc(Directions can be interpretted with respect to the base direction.
Used only if the direction mode is Azimuth.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_GetBaseDirection =R"doc(Directions can be interpretted with respect to the base direction.
Used only if the direction mode is Azimuth.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_SetClockwise =R"doc(Directions can be interpretted clockwise or counter-clockwise with
respect to the base direction. Used only if the direction mode is
Azimuth.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_GetClockwise =R"doc(Directions can be interpretted clockwise or counter-clockwise with
respect to the base direction. Used only if the direction mode is
Azimuth.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_SetDirectionMode =R"doc(If the direction mode is Azimuth, then the baseDirection and clockwise
flag will be applied.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_GetDirectionMode =R"doc(If the direction mode is Azimuth, then the baseDirection and clockwise
flag will be applied.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_SetTrueNorthValue =R"doc(Set an offset in degrees that will be added to the parsed value before
it is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_GetTrueNorthValue =R"doc(Get the offset in degrees that will be added to the parsed value
before it is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_GetAngleParser =R"doc(Get the angle parser used by this parser for the numeric portion of
the direction. Changes made to this object will affect the future
behavior of the DirectionParser.)doc";

static const char * __doc_Bentley_DgnPlatform_DirectionParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleParser_ToValue =R"doc(Parse a string into an angle value in degrees.


Parameter ``in``:
    input string.

Returns (Tuple, 0):
	retVal. SUCCESS if parsed successfully. ERROR otherwise..

Returns (Tuple, 1) :
	outVal. resulting angle in degrees if successfully parsed.

)doc";    

static const char * __doc_Bentley_DgnPlatform_AngleParser_SetAngleMode =R"doc(Sets the angle mode for parsing the input string. AngleMode::Degrees,
AngleMode::DegMin, and AngleMode::DegMinSec, are all treated the same.

Parameter ``mode``:
    The mode to set.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleParser_GetAngleMode =R"doc(Gets the angle mode for parsing the input string. AngleMode::Degrees,
AngleMode::DegMin, and AngleMode::DegMinSec, are all treated the same.)doc";

static const char * __doc_Bentley_DgnPlatform_AngleParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

static const char * __doc_Bentley_DgnPlatform_DoubleParser_ToValue =R"doc(Parse a string into a numeric value.


Parameter ``in``:
    input string.

Returns (Tuple, 0):
	retVal. SUCCESS if parsed successfully. ERROR otherwise..

Returns (Tuple, 1) :
	outVal.  resulting value if successfully parsed.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DoubleParser_Clone =R"doc(Construct a parser which is a duplicate of an existing parser.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ValueParse(py::module_& m)
    {
    //===================================================================================
    // struct DoubleParser
    py::class_< DoubleParser, DoubleParserPtr> c1(m, "DoubleParser");

    c1.def(py::init(py::overload_cast<>(&DoubleParser::Create)));
    c1.def("Clone", &DoubleParser::Clone, DOC(Bentley, DgnPlatform, DoubleParser, Clone));
    c1.def("ToValue", [] (DoubleParser const& self, WCharCP in)
           {
           double outVal = 0;
           auto retVal = self.ToValue(outVal, in);
           return py::make_tuple(retVal, outVal);
           }, "in"_a, DOC(Bentley, DgnPlatform, DoubleParser, ToValue));        

    //===================================================================================
    // struct AngleParser
    py::class_< AngleParser, AngleParserPtr> c2(m, "AngleParser");

    c2.def(py::init(py::overload_cast<>(&AngleParser::Create)));
    c2.def(py::init(py::overload_cast<DgnModelCR>(&AngleParser::Create)), "dgnModel"_a);
    c2.def("Clone", &AngleParser::Clone, DOC(Bentley, DgnPlatform, AngleParser, Clone));
    c2.def_property("AngleMode", &AngleParser::GetAngleMode, &AngleParser::SetAngleMode);
    c2.def("GetAngleMode", &AngleParser::GetAngleMode, DOC(Bentley, DgnPlatform, AngleParser, GetAngleMode));
    c2.def("SetAngleMode", &AngleParser::SetAngleMode, "AngleMode"_a, DOC(Bentley, DgnPlatform, AngleParser, SetAngleMode));

    c2.def("ToValue", [] (AngleParser const& self, WCharCP in)
           {
           double outVal = 0;
           auto retVal = self.ToValue(outVal, in);
           return py::make_tuple(retVal, outVal);
           }, "in"_a, DOC(Bentley, DgnPlatform, AngleParser, ToValue));        

    //===================================================================================
    // struct DirectionParser
    py::class_< DirectionParser, DirectionParserPtr> c3(m, "DirectionParser");

    c3.def(py::init(py::overload_cast<>(&DirectionParser::Create)));
    c3.def(py::init(py::overload_cast<DgnModelCR>(&DirectionParser::Create)), "dgnModel"_a);
    c3.def("Clone", &DirectionParser::Clone, DOC(Bentley, DgnPlatform, DirectionParser, Clone));

    c3.def_property_readonly("AngleParser", &DirectionParser::GetAngleParser);
    c3.def("GetAngleParser", &DirectionParser::GetAngleParser, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DirectionParser, GetAngleParser));
    
    c3.def_property("TrueNorthValue", &DirectionParser::GetTrueNorthValue, &DirectionParser::SetTrueNorthValue);
    c3.def("GetTrueNorthValue", &DirectionParser::GetTrueNorthValue, DOC(Bentley, DgnPlatform, DirectionParser, GetTrueNorthValue));
    c3.def("SetTrueNorthValue", &DirectionParser::SetTrueNorthValue, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionParser, SetTrueNorthValue));
    
    c3.def_property("DirectionMode", &DirectionParser::GetDirectionMode, &DirectionParser::SetDirectionMode);
    c3.def("GetDirectionMode", &DirectionParser::GetDirectionMode, DOC(Bentley, DgnPlatform, DirectionParser, GetDirectionMode));
    c3.def("SetDirectionMode", &DirectionParser::SetDirectionMode, "mode"_a, DOC(Bentley, DgnPlatform, DirectionParser, SetDirectionMode));
    
    c3.def_property("Clockwise", &DirectionParser::GetClockwise, &DirectionParser::SetClockwise);
    c3.def("GetClockwise", &DirectionParser::GetClockwise, DOC(Bentley, DgnPlatform, DirectionParser, GetClockwise));
    c3.def("SetClockwise", &DirectionParser::SetClockwise, "cw"_a, DOC(Bentley, DgnPlatform, DirectionParser, SetClockwise));
    
    c3.def_property("BaseDirection", &DirectionParser::GetBaseDirection, &DirectionParser::SetBaseDirection);
    c3.def("GetBaseDirection", &DirectionParser::GetBaseDirection, DOC(Bentley, DgnPlatform, DirectionParser, GetBaseDirection));
    c3.def("SetBaseDirection", &DirectionParser::SetBaseDirection, "newVal"_a, DOC(Bentley, DgnPlatform, DirectionParser, SetBaseDirection));

    c3.def("ToValue", [] (DirectionParser& self, WCharCP in)
           {
           double outVal = 0;
           auto retVal = self.ToValue(outVal, in);
           return py::make_tuple(retVal, outVal);
           }, "in"_a, DOC(Bentley, DgnPlatform, DirectionParser, ToValue));

    //===================================================================================
    // struct DistanceParser
    py::class_< DistanceParser, DistanceParserPtr> c4(m, "DistanceParser");

    c4.def(py::init(py::overload_cast<>(&DistanceParser::Create)));
    c4.def(py::init(py::overload_cast<DgnModelCR>(&DistanceParser::Create)), "dgnModel"_a);
    c4.def(py::init(py::overload_cast<ViewportR>(&DistanceParser::Create)), "vp"_a);
    c4.def(py::init(py::overload_cast<DgnModelCR, IAuxCoordSysCR>(&DistanceParser::Create)), "dgnModel"_a, "acs"_a);
    c4.def("Clone", &DistanceParser::Clone, DOC(Bentley, DgnPlatform, DistanceParser, Clone));

    c4.def_property("MasterUnitLabel", &DistanceParser::GetMasterUnitLabel, &DistanceParser::SetMasterUnitLabel);
    c4.def("GetMasterUnitLabel", &DistanceParser::GetMasterUnitLabel, py::return_value_policy::reference_internal);
    c4.def("SetMasterUnitLabel", &DistanceParser::SetMasterUnitLabel, "label"_a, DOC(Bentley, DgnPlatform, DistanceParser, SetMasterUnitLabel));
    
    c4.def_property("SubUnitLabel", &DistanceParser::GetSubUnitLabel, &DistanceParser::SetSubUnitLabel);
    c4.def("GetSubUnitLabel", &DistanceParser::GetSubUnitLabel, py::return_value_policy::reference_internal);
    c4.def("SetSubUnitLabel", &DistanceParser::SetSubUnitLabel, "label"_a);
    
    c4.def_property("MasterUnitScale", &DistanceParser::GetMasterUnitScale, &DistanceParser::SetMasterUnitScale);
    c4.def("GetMasterUnitScale", &DistanceParser::GetMasterUnitScale);
    c4.def("SetMasterUnitScale", &DistanceParser::SetMasterUnitScale, "scale"_a);
    
    c4.def_property("SubUnitScale", &DistanceParser::GetSubUnitScale, &DistanceParser::SetSubUnitScale);
    c4.def("GetSubUnitScale", &DistanceParser::GetSubUnitScale);
    c4.def("SetSubUnitScale", &DistanceParser::SetSubUnitScale, "scale"_a);
    
    c4.def_property("Scale", &DistanceParser::GetScale, &DistanceParser::SetScale);
    c4.def("GetScale", &DistanceParser::GetScale, DOC(Bentley, DgnPlatform, DistanceParser, GetScale));
    c4.def("SetScale", &DistanceParser::SetScale, "scale"_a, DOC(Bentley, DgnPlatform, DistanceParser, SetScale));

    c4.def("ToValue", [] (DistanceParser& self, WCharCP in)
           {
           double outVal = 0;
           auto retVal = self.ToValue(outVal, in);
           return py::make_tuple(retVal, outVal);
           }, "in"_a, DOC(Bentley, DgnPlatform, DistanceParser, ToValue));

    //===================================================================================
    // struct PointParser
    py::class_< PointParser, PointParserPtr> c5(m, "PointParser");

    c5.def(py::init(py::overload_cast<>(&PointParser::Create)));
    c5.def(py::init(py::overload_cast<DgnModelCR>(&PointParser::Create)), "dgnModel"_a);
    c5.def(py::init(py::overload_cast<ViewportR>(&PointParser::Create)), "vp"_a);
    c5.def(py::init(py::overload_cast<DgnModelCR, IAuxCoordSysCR>(&PointParser::Create)), "dgnModel"_a, "acs"_a);
    c5.def("Clone", &PointParser::Clone, DOC(Bentley, DgnPlatform, PointParser, Clone));
    c5.def("ToValue", py::overload_cast<DPoint3dR, WCharCP>(&PointParser::ToValue), "outPoint"_a, "in"_a, DOC(Bentley, DgnPlatform, PointParser, ToValue));
    
    c5.def_property_readonly("DistanceParser", &PointParser::GetDistanceParser);
    c5.def("GetDistanceParser", &PointParser::GetDistanceParser, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointParser, GetDistanceParser));
    
    c5.def_property("Is3d", &PointParser::GetIs3d, &PointParser::SetIs3d);
    c5.def("GetIs3d", &PointParser::GetIs3d, DOC(Bentley, DgnPlatform, PointParser, GetIs3d));
    c5.def("SetIs3d", &PointParser::SetIs3d, "is3d"_a, DOC(Bentley, DgnPlatform, PointParser, SetIs3d));

    //===================================================================================
    // struct AreaOrVolumeParser
    py::class_< AreaOrVolumeParser, RefCountedPtr<AreaOrVolumeParser> > c6(m, "AreaOrVolumeParser");

    c6.def_property("MasterUnitScale", &AreaOrVolumeParser::GetMasterUnitScale, &AreaOrVolumeParser::SetMasterUnitScale);
    c6.def("GetMasterUnitScale", &AreaOrVolumeParser::GetMasterUnitScale);
    c6.def("SetMasterUnitScale", &AreaOrVolumeParser::SetMasterUnitScale, "scale"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeParser, SetMasterUnitScale));
    
    c6.def_property("Scale", &AreaOrVolumeParser::GetScale, &AreaOrVolumeParser::SetScale);
    c6.def("GetScale", &AreaOrVolumeParser::GetScale, DOC(Bentley, DgnPlatform, AreaOrVolumeParser, GetScale));
    c6.def("SetScale", &AreaOrVolumeParser::SetScale, "scale"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeParser, SetScale));

    c6.def("ToValue", [] (AreaOrVolumeParser& self, WCharCP in)
           {
           double outVal = 0;
           auto retVal = self.ToValue(outVal, in);
           return py::make_tuple(retVal, outVal);
           }, "in"_a, DOC(Bentley, DgnPlatform, AreaOrVolumeParser, ToValue));

    //===================================================================================
    // struct AreaParser
    py::class_< AreaParser, AreaParserPtr, AreaOrVolumeParser> c7(m, "AreaParser");

    c7.def(py::init(py::overload_cast<>(&AreaParser::Create)));
    c7.def(py::init(py::overload_cast<DgnModelCR>(&AreaParser::Create)), "dgnModel"_a);
    c7.def(py::init(py::overload_cast<ViewportR>(&AreaParser::Create)), "vp"_a);
    c7.def("Clone", &AreaParser::Clone, DOC(Bentley, DgnPlatform, AreaParser, Clone));

    //===================================================================================
    // struct VolumeParser
    py::class_< VolumeParser, VolumeParserPtr, AreaOrVolumeParser> c8(m, "VolumeParser");

    c8.def(py::init(py::overload_cast<>(&VolumeParser::Create)));
    c8.def(py::init(py::overload_cast<DgnModelCR>(&VolumeParser::Create)), "dgnModel"_a);
    c8.def(py::init(py::overload_cast<ViewportR>(&VolumeParser::Create)), "vp"_a);
    c8.def("Clone", &VolumeParser::Clone, DOC(Bentley, DgnPlatform, VolumeParser, Clone));
    }