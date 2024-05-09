/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementtemplateparamshelper.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementTemplateParamsHelper.h>



static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddDetailSymbolStyleByName =R"doc(Add the name of the detail symbol style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleName``:
    IN the name of the detail symbol style to pass to the default
    instance.

Returns:
    ETSTATUS_Success if a detail symbol style name was successfully
    added to the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddMaterialById =R"doc(Look up material and palette names by ID and then add them to the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``materialId``:
    IN material Id available in modelRef file.

Parameter ``modelRef``:
    IN modelRef use as context to look up material by ID.

Returns:
    ETSTATUS_Success if a material and palette pair was successfully
    added to the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddMaterialNameAndPalette =R"doc(Add the names of the material and palette to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``material``:
    IN the name of the material to pass to the default instance.

Parameter ``palette``:
    IN the name of the palette to pass to the default instance.

Returns:
    ETSTATUS_Success if a material and palette pair was successfully
    added to the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddDimensionStyleById =R"doc(Look up dimension style name by Id and Add the name to the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleId``:
    IN the ID of the dimension style to pass to the default instance.

Parameter ``dgnFile``:
    IN file used to look up style by id.

Returns:
    ETSTATUS_Success if a dimension style was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddDimensionStyleByName =R"doc(Add the name of the dimension style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleName``:
    IN the name of the dimension style to pass to the default
    instance.

Returns:
    ETSTATUS_Success if a dimension style name was successfully added
    to the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddMlineStyleById =R"doc(Use the multiline style ID to look a style name and adds it to the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleId``:
    IN the ID of the multiline style to pass to the default instance.

Parameter ``dgnFile``:
    IN file used to look up style by id.

Returns:
    ETSTATUS_Success if a multiline style was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddMlineStyleByName =R"doc(Add the name of the multiline style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleName``:
    IN the name of the multiline style to pass to the default
    instance.

Returns:
    ETSTATUS_Success if a multiline style name was successfully added
    to the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddHatchAngleValues =R"doc(Add hatch/x-hatch angle values to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``angle1Value``:
    IN the primary angle value to pass to the default instance.

Parameter ``angle2Value``:
    IN the secondary angle value to pass to the default instance.

Returns:
    ETSTATUS_Success if hatch angle values at index are found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddHatchDeltaValues =R"doc(Add the hatch/x-hatch delta values to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``deltaxValue``:
    IN the delta x value to pass to the default instance.

Parameter ``deltayValue``:
    IN the delta y value to pass to the default instance. If this
    value is zero then an hatch value is being defined.

Returns:
    ETSTATUS_Success if hatch delta values at index are found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddPatternScale =R"doc(Add the scale of the pattern cell to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``scale``:
    IN the scale of the pattern cell to pass to the default instance.

Returns:
    ETSTATUS_Success if a pattern cell scale was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddPatternAngle =R"doc(Add the angle of the pattern cell to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``angle``:
    IN the angle of the pattern cell to pass to the default instance.

Returns:
    ETSTATUS_Success if a pattern cell angle was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddPatternDeltaValues =R"doc(Add the pattern delta values to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``deltaxValue``:
    IN the delta x value to pass to the default instance.

Parameter ``deltayValue``:
    IN the delta y value to pass to the default instance.

Returns:
    ETSTATUS_Success if pattern delta values at index are found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddPatternCellName =R"doc(Add the name of the pattern cell to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellName``:
    IN the name of the pattern cell to pass to the default instance.

Returns:
    ETSTATUS_Success if a pattern cell name was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddTextStyleOverride =R"doc(Add text style overrides to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``textScale``:
    IN the defines the text height and width.

Parameter ``textParams``:
    IN defines the text style override values.

Parameter ``lineLength``:
    IN defines the line length for mult-line text.

Parameter ``modelRef``:
    IN reference model used to calculate UORs to meters since template
    stores all distance in meters.

Returns:
    ETSTATUS_Success if a text style was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddTextStyleById =R"doc(Look up text style by Id and add text style name to the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleId``:
    IN the ID of the text style to pass to the default instance.

Parameter ``dgnFile``:
    IN file used to look up style by id.

Returns:
    ETSTATUS_Success if a text style was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddTextStyleByName =R"doc(Add the name of the text style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``textStyleName``:
    IN the name of the text style to pass to the default instance.

Returns:
    ETSTATUS_Success if a text style name was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddActivePointSpecification =R"doc(Add the point type of the active point to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``pointType``:
    IN the point type of the active point to pass to the default
    instance.

Parameter ``cellNameOrCharacter``:
    IN the string value used to define the point.

Returns:
    ETSTATUS_Success if an active point was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddTerminatorScale =R"doc(Add the scale of the terminator cell to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``scale``:
    IN the scale of the terminator cell to pass to the default
    instance.

Returns:
    ETSTATUS_Success if a terminator scale was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddTerminatorCellName =R"doc(Add the name of the terminator cell to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellName``:
    IN the name of the terminator cell to pass to the default
    instance.

Returns:
    ETSTATUS_Success if a terminator cell name was successfully added
    to the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddCellScale =R"doc(Add the scale for the cells to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellScale``:
    IN the scale of the cell to pass to the default instance.

Returns:
    ETSTATUS_Success if a cell scale was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddCellName =R"doc(Add the name of the cell name to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellName``:
    IN the name of the cell to pass to the default instance.

Returns:
    ETSTATUS_Success if a cell name was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddFillMode =R"doc(Add the fill mode setting to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``fillMode``:
    IN the fill mode setting to pass to the default instance.

Returns:
    ETSTATUS_Success if an fill mode was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddGradientFillColor =R"doc(Add the value of the gradient fill color to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``gradientsymb``:
    IN the value of the gradient fill color to pass to the default
    instance.

Returns:
    ETSTATUS_Success if an element color was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddSolidFillColor =R"doc(Add the value of the solid fill color to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``elementColor``:
    IN the value of the solid fill color to pass to the default
    instance.

Parameter ``dgnFile``:
    IN reference file used to set the solid fill color value to the
    associated element color.

Returns:
    ETSTATUS_Success if an element color was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddAreaMode =R"doc(Add the area mode setting to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``isHole``:
    IN the area mode setting to pass to the default instance.

Returns:
    ETSTATUS_Success if an area mode was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddPriority =R"doc(Add the value of the priority to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``priority``:
    IN the value of the priority to pass to the default instance.

Returns:
    ETSTATUS_Success if a priority was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddTransparency =R"doc(Add the value of the transparency to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``transparency``:
    IN the value of the transparency to pass to the default instance.

Returns:
    ETSTATUS_Success if a transparency was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddElementClass =R"doc(Add the value of the element class to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``elementClass``:
    IN the value of the element class to pass to the default instance.

Returns:
    ETSTATUS_Success if an element class was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddLineStyleParams =R"doc(Add the parameters of the line style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``lineStyleParams``:
    IN the parameters of the level to pass to the default instance.

Parameter ``modelRef``:
    IN reference model used to search for the line style from the
    associated DGNLIB file.

Returns:
    ETSTATUS_Success if a line style was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddLineStyleById =R"doc(Add the ID of the line style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``linestyleId``:
    IN the value of the line style/line code to pass to the default
    instance.

Parameter ``dgnFile``:
    IN file used to look up style by id.

Returns:
    ETSTATUS_Success if a line style was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddLineStyleByName =R"doc(Add the name of the line style to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``levelName``:
    IN the name of the line style to pass to the default instance.

Returns:
    ETSTATUS_Success if a line style name was successfully added to
    the etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddLineWeight =R"doc(Add the value of the weight to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``lineWeight``:
    IN the value of the weight to pass to the default instance.

Returns:
    ETSTATUS_Success if a weight was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddElementColor =R"doc(Add the value of the element color to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``elementColor``:
    IN the value of the element color to pass to the default instance.

Parameter ``dgnFile``:
    IN file used to look up color by id.

Returns:
    ETSTATUS_Success if an element color was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddLevelById =R"doc(Look up level name by LevelId and add it to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``levelId``:
    IN the ID of the level to pass to the default instance.

Parameter ``dgnFile``:
    IN reference file used to set the level id to the associated
    level.

Returns:
    ETSTATUS_Success if a level was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_AddLevelByName =R"doc(Add the specified level name to the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``levelName``:
    IN the name of the level to pass to the default instance.

Returns:
    ETSTATUS_Success if a level name was successfully added to the
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetDetailSymbolStyleByName =R"doc(Update the name of an existing detail symbol style stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleName``:
    IN the name of the detail symbol style to pass to the default
    instance.

Parameter ``index``:
    IN the index in the template instance to assign the new detail
    symbol style name.

Returns:
    ETSTATUS_Success if a detail symbol style name at index is found
    in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetMaterialNameAndPalette =R"doc(Update the names of an existing material and palette stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``material``:
    IN the name of the material to pass to the default instance.

Parameter ``palette``:
    IN the name of the palette to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new material
    and palette names.

Returns:
    ETSTATUS_Success if a material and palette pair at index is found
    in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetDimensionStyleById =R"doc(Update the ID of an existing dimension style stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleId``:
    IN the ID of the dimension style to pass to the default instance.

Parameter ``dgnFile``:
    IN reference file used to set the id value to the associated
    dimension style.

Parameter ``index``:
    IN the index in the template instance to assign the new dimension
    style id.

Returns:
    ETSTATUS_Success if a dimension style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetDimensionStyleByName =R"doc(Update the name of an existing dimension style stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleName``:
    IN the name of the dimension style to pass to the default
    instance.

Parameter ``index``:
    IN the index in the template instance to assign the new dimension
    style name.

Returns:
    ETSTATUS_Success if a dimension style name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetMlineStyleById =R"doc(Look up multiline style name by id and update the name currently
stored in the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleId``:
    IN the ID of the multiline style to pass to the default instance.

Parameter ``dgnFile``:
    IN reference file used to set the id value to the associated
    multiline style.

Parameter ``index``:
    IN the index in the template instance to assign the new multiline
    style id.

Returns:
    ETSTATUS_Success if a multiline style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetMlineStyleByName =R"doc(Update the name of an existing multiline style stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleName``:
    IN the name of the multiline style to pass to the default
    instance.

Parameter ``index``:
    IN the index in the template instance to assign the new multiline
    style name.

Returns:
    ETSTATUS_Success if a multiline style name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetHatchAngleValues =R"doc(Update the hatch angle values stored within the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``angle1Value``:
    IN the primary angle value to pass to the default instance.

Parameter ``angle2Value``:
    IN the secondary angle value to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new hatch
    angle values.

Returns:
    ETSTATUS_Success if hatch angle values at index are found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetHatchDeltaValues =R"doc(Update the hatch delta values stored within the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``deltaxValue``:
    IN the delta x value to pass to the default instance.

Parameter ``deltayValue``:
    IN the delta y value to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new hatch
    delta values.

Returns:
    ETSTATUS_Success if hatch delta values at index are found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetPatternScale =R"doc(Update the scale of an existing pattern cell stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``scale``:
    IN the scale of the pattern cell to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new pattern
    cell scale.

Returns:
    ETSTATUS_Success if a pattern cell scale at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetPatternAngle =R"doc(Update the angle of an existing pattern cell stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``angle``:
    IN the angle of the pattern cell to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new pattern
    cell angle.

Returns:
    ETSTATUS_Success if a pattern cell angle at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetPatternDeltaValues =R"doc(Update the pattern delta values stored within the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``deltaxValue``:
    IN the delta x value to pass to the default instance.

Parameter ``deltayValue``:
    IN the delta y value to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new pattern
    delta values.

Returns:
    ETSTATUS_Success if pattern delta values at index are found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetPatternCellName =R"doc(Update the name of an existing pattern cell stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellName``:
    IN the name of the pattern cell to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new pattern
    cell name.

Returns:
    ETSTATUS_Success if a pattern cell name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetTextStyleOverride =R"doc(Update the parameters of an existing text style stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``textScale``:
    IN the scale of the text to pass to the default instance.

Parameter ``textParams``:
    IN the parameters of the text style to pass to the default
    instance.

Parameter ``lineLength``:
    IN the line length to pass to the default instance.

Parameter ``modelRef``:
    IN reference model used to search for the text style from the
    associated DGNLIB file.

Parameter ``index``:
    IN the index in the template instance to assign the new text
    style.

Returns:
    ETSTATUS_Success if a text style at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetTextStyleById =R"doc(Update the text style name stored within the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``styleId``:
    IN the ID of the text style to pass to the default instance.

Parameter ``dgnFile``:
    IN file used to look up style by id.

Parameter ``index``:
    IN the index in the template instance to assign the new text style
    id.

Returns:
    ETSTATUS_Success if a text style at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetTextStyleByName =R"doc(Update the name of an existing text style stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``textStyleName``:
    IN the name of the text style to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new text style
    name.

Returns:
    ETSTATUS_Success if a text style name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetActivePointSpecification =R"doc(Update the point specification within the template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``pointType``:
    IN the point type either zero-length line, cell, character .

Parameter ``cellNameOrCharacter``:
    IN the string value used to define the cell name or character.

Parameter ``index``:
    IN the index in the template instance to assign the new active
    point type.

Returns:
    ETSTATUS_Success if an active point at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetTerminatorScale =R"doc(Update the scale of an existing terminator cell stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``scale``:
    IN the scale of the terminator cell to pass to the default
    instance.

Parameter ``index``:
    IN the index in the template instance to assign the new terminator
    scale.

Returns:
    ETSTATUS_Success if a terminator scale at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetTerminatorCellName =R"doc(Update the name of an existing terminator cell stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellName``:
    IN the name of the terminator cell to pass to the default
    instance.

Parameter ``index``:
    IN the index in the template instance to assign the new terminator
    cell name.

Returns:
    ETSTATUS_Success if a terminator cell name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetCellScale =R"doc(Update the scale of an existing cell stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellScale``:
    IN the scale of the cell to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new cell
    scale.

Returns:
    ETSTATUS_Success if a cell scale at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetCellName =R"doc(Update the name of an existing cell stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``cellName``:
    IN the name of the cell to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new cell name.

Returns:
    ETSTATUS_Success if a cell name at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetFillMode =R"doc(Update an existing fill mode setting stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``fillMode``:
    IN the fill mode setting to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new fill mode.

Returns:
    ETSTATUS_Success if an fill mode at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetElementFillToGradient =R"doc(Update the value of an existing gradient fill color stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``gradientsymb``:
    IN the value of the gradient fill color to pass to the default
    instance.

Parameter ``index``:
    IN the index in the template instance to assign the new gradient
    fill color.

Returns:
    ETSTATUS_Success if an element color at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetElementFillToSolidColor =R"doc(Update the value of an existing solid fill color stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``elementColor``:
    IN the value of the solid fill color to pass to the default
    instance.

Parameter ``dgnFile``:
    IN reference file used to set the solid fill color value to the
    associated element color.

Parameter ``index``:
    IN the index in the template instance to assign the new solid fill
    color.

Returns:
    ETSTATUS_Success if an element color at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetAreaMode =R"doc(Update an existing area mode setting stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``isHole``:
    IN the area mode setting to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new area mode.

Returns:
    ETSTATUS_Success if an area mode at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetPriority =R"doc(Update the value of an existing priority stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``priority``:
    IN the value of the priority to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new priority
    value.

Returns:
    ETSTATUS_Success if a priority at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetTransparency =R"doc(Update the value of an existing transparency stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``transparency``:
    IN the value of the transparency to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new
    transparency value.

Returns:
    ETSTATUS_Success if a transparency at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetElementClass =R"doc(Update the value of an existing element class stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``elementClass``:
    IN the value of the element class to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new element
    class.

Returns:
    ETSTATUS_Success if an element class at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetLineStyleParams =R"doc(Update the parameters of an existing line style stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``lineStyleParams``:
    IN the parameters of the level to pass to the default instance.

Parameter ``modelRef``:
    IN reference model used to search for the line style from the
    associated DGNLIB file.

Parameter ``index``:
    IN the index in the template instance to assign the new line
    style.

Returns:
    ETSTATUS_Success if a line style at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetLineStyleById =R"doc(Update the ID of an existing line style stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``lineWeight``:
    IN the value of the weight to pass to the default instance.

Parameter ``dgnFile``:
    IN reference file used to set the line weight to the associated
    DGNLIB file.

Parameter ``index``:
    IN the index in the template instance to assign the new line style
    id.

Returns:
    ETSTATUS_Success if a line style at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetLineStyleByName =R"doc(Update the name of an existing line style stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``levelName``:
    IN the name of the line style to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new line style
    name.

Returns:
    ETSTATUS_Success if a line style name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetLineWeight =R"doc(Update the value of an existing weight stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``lineWeight``:
    IN the value of the weight to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new weight.

Returns:
    ETSTATUS_Success if a weight at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetElementColor =R"doc(Update the value of an existing element color stored within the
template instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``elementColor``:
    IN the value of the element color to pass to the default instance.

Parameter ``dgnFile``:
    IN reference file used to set the element color value to the
    associated element color.

Parameter ``index``:
    IN the index in the template instance to assign the new element
    color.

Returns:
    ETSTATUS_Success if an element color at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetLevelById =R"doc(Update the ID of an existing level stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``levelId``:
    IN the ID of the level to pass to the default instance.

Parameter ``dgnFile``:
    IN reference file used to set the level id to the associated
    level.

Parameter ``index``:
    IN the index in the template instance to assign the new level id.

Returns:
    ETSTATUS_Success if a level at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_SetLevelByName =R"doc(Update the name of an existing level stored within the template
instance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``levelName``:
    IN the name of the level to pass to the default instance.

Parameter ``index``:
    IN the index in the template instance to assign the new level
    name.

Returns:
    ETSTATUS_Success if a level name at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetDetailSymbolStyleName =R"doc(Get the detail symbol style name stored within the template instance.

Parameter ``styleName``:
    OUT detail symbol style name retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the detail symbol style to retrieve.

Returns:
    ETSTATUS_Success if a detail symbol style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetMaterialId =R"doc(Get the ID of a material stored within the template instance.

Parameter ``matId``:
    OUT id of the level retrieved from etInstance.

Parameter ``modelRef``:
    IN reference model used to get the material id from the associated
    material name.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the material id to retrieve.

Returns:
    ETSTATUS_Success if a material id at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetMaterialNameAndPalette =R"doc(Get the material name and palette stored within the template instance.

Parameter ``material``:
    OUT material name retrieved from etInstance.

Parameter ``palette``:
    OUT palette name retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the material and palette to retrieve.

Returns:
    ETSTATUS_Success if the material and palette at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetDimensionStyle =R"doc(Get the dimension style stored within the template instance.

Parameter ``dimStyle``:
    OUT dimension style of the level retrieved from etInstance.

Parameter ``file``:
    IN reference file used to get the dimension style from the
    associated dimension style name.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the dimension style to retrieve.

Returns:
    ETSTATUS_Success if a dimension style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetDimensionStyleName =R"doc(Get the dimension style name stored within the template instance.

Parameter ``styleName``:
    OUT dimension style name retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the dimension style to retrieve.

Returns:
    ETSTATUS_Success if a dimension style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetMlineStyle =R"doc(Get the multiline style stored within the template instance.

Parameter ``mlineStyle``:
    OUT multiline style of the level retrieved from etInstance.

Parameter ``file``:
    IN reference file used to get the multiline style from the
    associated multiline style name.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the multiline style to retrieve.

Returns:
    ETSTATUS_Success if a multiline style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetMlineStyleName =R"doc(Get the multiline style name stored within the template instance.

Parameter ``styleName``:
    OUT multiline style name retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the multiline style to retrieve.

Returns:
    ETSTATUS_Success if a multiline style at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetHatchAngleValues =R"doc(Get the hatch angle values stored within the template instance.

Parameter ``angle1Value``:
    OUT angle 1 value retrieved from etInstance.

Parameter ``angle2Value``:
    OUT angle 2 value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the hatch angle to retrieve.

Returns:
    ETSTATUS_Success if the hatch angle at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetHatchDeltaValues =R"doc(Get the hatch delta values stored within the template instance.

Parameter ``deltaxValue``:
    OUT delta X value in meters.

Parameter ``deltayValue``:
    OUT delta Y value in meters.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the hatch delta to retrieve.

Returns:
    ETSTATUS_Success if the hatch delta at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetHatchPatternIsAnnotation =R"doc(Get the hatch or pattern's annotation property stored within the
template instance.

Parameter ``isAnnotation``:
    OUT flag indicating whether this hatch or pattern behaves like an
    annotation. This value is retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern angle to retrieve.

Returns:
    ETSTATUS_Success if a pattern's IsAnnotation flat at index is
    found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetPatternAngle =R"doc(Get the pattern angle stored within the template instance.

Parameter ``angle``:
    OUT pattern angle value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern angle to retrieve.

Returns:
    ETSTATUS_Success if a pattern angle at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetPatternScale =R"doc(Get the pattern scale stored within the template instance.

Parameter ``scale``:
    OUT pattern scale value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern scale to retrieve.

Returns:
    ETSTATUS_Success if a pattern scale at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetPatternDeltaValues =R"doc(Get the pattern delta values stored within the template instance.

Parameter ``deltaxValue``:
    OUT delta X value retrieved from etInstance.

Parameter ``deltayValue``:
    OUT delta Y value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern delta to retrieve.

Returns:
    ETSTATUS_Success if the pattern delta at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetPatternCellName =R"doc(Get the pattern cell name stored within the template instance.

Parameter ``cellName``:
    OUT pattern cell name retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern cell to retrieve.

Returns:
    ETSTATUS_Success if a pattern cell at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetHatchParams =R"doc(Get the hatch parameters stored within the template instance.

Parameter ``patternParams``:
    OUT pattern parameters with deltas in uors and angles in radian.

Parameter ``modelRef``:
    IN reference model used to get the pattern parameters and scale.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern parameters to retrieve.

Returns:
    ETSTATUS_Success if the pattern parameters at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetPatternParams =R"doc(Get the pattern or hatch parameters stored within the template
instance. Pattern params are returned if Pattern Cell is defined.

Parameter ``patternParams``:
    OUT pattern parameters with deltas in uors and angles in radian.

Parameter ``modelRef``:
    IN reference model used to get the pattern parameters and scale.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern parameters to retrieve.

Returns:
    ETSTATUS_Success if the pattern parameters at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetTextParamsAndScale =R"doc(Get the text style parameters stored within the template instance.

Parameter ``textParams``:
    OUT pattern style parameter set retrieved from etInstance.

Parameter ``textScale``:
    IN text scale retrieved from etInstance.

Parameter ``lineLength``:
    IN line length value retrieved from etInstance.

Parameter ``modelRef``:
    IN reference model used to get the text parameters and scale.

Parameter ``uorsPerMeter``:
    IN value used to convert pattern params to meters

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the pattern parameters to retrieve.

Returns:
    ETSTATUS_Success if the text parameters at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetTextStyleId =R"doc(Get the text style id stored within the template instance.

Parameter ``styleId``:
    OUT text style id retrieved from etInstance.

Parameter ``modelRef``:
    IN modelRef used to locate text style based on ID.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the text style id to retrieve.

Returns:
    ETSTATUS_Success if a text style id at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetTextStyleName =R"doc(Get the text style name stored within the template instance.

Parameter ``styleName``:
    OUT text style name retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the text style to retrieve.

Returns:
    ETSTATUS_Success if a text style at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetActivePointSpecification =R"doc(Get the point type and point information stored within the template
instance.

Parameter ``pointType``:
    OUT priority value retrieved from etInstance.

Parameter ``cellNameOrCharacter``:
    OUT cell name or character retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the point type and point information to retrieve.

Returns:
    ETSTATUS_Success if a priority at point type and point information
    is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetTerminatorScale =R"doc(Get the scale stored within the template instance.

Parameter ``scale``:
    OUT scale value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the scale to retrieve.

Returns:
    ETSTATUS_Success if a scale at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetTerminatorCellName =R"doc(Get the terminator cell name stored within the template instance.

Parameter ``cellName``:
    OUT terminator cell name string retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the terminator cell name to retrieve.

Returns:
    ETSTATUS_Success if the terminator cell name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetCellScale =R"doc(Get the cell scale stored within the template instance.

Parameter ``cellScale``:
    OUT cell scale value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the cell scale to retrieve.

Returns:
    ETSTATUS_Success if the cell scale at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetAnyCellName =R"doc(Get any kind of cell name stored within the template instance.

Parameter ``cellName``:
    OUT terminator cell name or cell name string retrieved from
    etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the name to retrieve.

Returns:
    ETSTATUS_Success if a name at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetCellName =R"doc(Get the cell name stored within the template instance.

Parameter ``cellName``:
    OUT cell name string retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the cell name to retrieve.

Returns:
    ETSTATUS_Success if a cell name at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetFillMode =R"doc(Get the fill mode stored within the template instance.

Parameter ``fillMode``:
    OUT fill mode value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the fill mode to retrieve.

Returns:
    ETSTATUS_Success if a fill mode at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetFillColorIdOrGradientSpecification =R"doc(Get the solid or gradient fill color stored within the template
instance.

Parameter ``color``:
    OUT solid fill color retrieved from etInstance.

Parameter ``gradientsymb``:
    OUT gradient fill color retrieved from etInstance.

Parameter ``modelRef``:
    IN reference model used to get the solid fill color from the
    associated struct. Not used for gradient.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the solid or gradient fill to retrieve.

Returns:
    ETSTATUS_Success if a solid or gradient fill at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetAreaMode =R"doc(Get the area mode stored within the template instance.

Parameter ``isHole``:
    OUT area mode retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the area mode to retrieve.

Returns:
    ETSTATUS_Success if a area mode at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetPriority =R"doc(Get the priority stored within the template instance.

Parameter ``priority``:
    OUT priority value retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the priority to retrieve.

Returns:
    ETSTATUS_Success if a priority at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetTransparency =R"doc(Get the transparency stored within the template instance.

Parameter ``transparency``:
    OUT transparency retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the transparency to retrieve.

Returns:
    ETSTATUS_Success if a transparency at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetElementClass =R"doc(Get the element class stored within the template instance.

Parameter ``elementClass``:
    OUT element class retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the element class to retrieve.

Returns:
    ETSTATUS_Success if a element class at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetLineStyleParams =R"doc(Get the line style parameters stored within the template instance.

Parameter ``lineStyleParams``:
    OUT line style parameter set retrieved from etInstance.

Parameter ``uorsPerMeter``:
    IN value used to convert line style params to meters.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the line style to retrieve.

Returns:
    ETSTATUS_Success if a level name at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetLineStyleId =R"doc(Get the line style id stored within the template instance. If the
style is a named style in a DGNLIB file, isNamedStyle will be set to
true.

Parameter ``styleId``:
    OUT line style id retrieved from etInstance.

Parameter ``isNamedStyle``:
    OUT boolean value that determines whether or not the line style is
    named.

Parameter ``modelRef``:
    IN reference model used to search for the line style name from the
    associated DGNLIB file.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the line style to retrieve.

Returns:
    ETSTATUS_Success if a line style id at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetLineStyleName =R"doc(Get the line style name stored within the template instance. If the
style is a named style in a DGNLIB file, isNamedStyle will be set to
true.

Parameter ``styleName``:
    OUT line style name retrieved from etInstance.

Parameter ``isNamedStyle``:
    OUT boolean value that determines whether or not the line style is
    named.

Parameter ``modelRef``:
    IN reference model used to search for the line style name from the
    associated DGNLIB file.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the line style to retrieve.

Returns:
    ETSTATUS_Success if a line style name at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetWeight =R"doc(Get the weight stored within the template instance.

Parameter ``weight``:
    OUT weight retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the weight to retrieve.

Returns:
    ETSTATUS_Success if a weight value at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetElementColor =R"doc(Get the element color stored within the template instance.

Parameter ``color``:
    OUT element color retrieved from etInstance.

Parameter ``modelRef``:
    IN reference model used to get the element color from the
    associated struct.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the element color to retrieve.

Returns:
    ETSTATUS_Success if an element color at index is found in
    etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetLevelId =R"doc(Get the ID of a level stored within the template instance.

Parameter ``levelId``:
    OUT id of the level retrieved from etInstance.

Parameter ``modelRef``:
    IN reference model used to get the level id from the associated
    level name.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the level id to retrieve.

Returns:
    ETSTATUS_Success if a level id at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetLevelName =R"doc(Get the name of a level stored within the template instance.

Parameter ``levelName``:
    OUT name of the level retrieved from etInstance.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``index``:
    IN the index of the level name to retrieve.

Returns:
    ETSTATUS_Success if a level name at index is found in etInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetLineStyleIdFromName =R"doc(Convenience method used to get a line style id by name. The strings
" 0 " through " 7 " are assumed to specify line codes.

Parameter ``lineStyleString``:
    IN the string to be processed.

Parameter ``isNamedStyle``:
    OUT if false the the string held a line code 0-7 or StyleByLevel
    or StyleByCell.

Parameter ``modelRef``:
    IN used to get DgnFile to pass to
    LineStyleManager::GetStyleIDForDesignFile.

Returns:
    line style Id. If isNamedStyle is true and 0 is returned then the
    line style name could not be found.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateParamsHelper_GetEntryCount =R"doc(Get the number of property values of a specified type stored within
the template instance. check if point at the given index is a
disconnect (separator) point, if yes and getPreviousIfDisconnect is
true then get the previous point else get the next point.

Parameter ``numEntries``:
    OUT number of values stored for the property defined by the
    specified ElementParameterType.

Parameter ``etInstance``:
    IN the IECInstance that contains the properties used by
    MicroStation to get and set element symbology.

Parameter ``param``:
    IN defines the template property to process.

Returns:
    ETSTATUS_Success if parameter type is found in etInstance.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementTemplateParamsHelper(py::module_& m)
    {
    //===================================================================================
    // enum ElementParameterType
    py::enum_< ElementParameterType>(m, "ElementParameterType", py::arithmetic())
        .value("eELEMENTPARAM_Level", ELEMENTPARAM_Level)
        .value("eELEMENTPARAM_Color", ELEMENTPARAM_Color)
        .value("eELEMENTPARAM_Weight", ELEMENTPARAM_Weight)
        .value("eELEMENTPARAM_LineStyle", ELEMENTPARAM_LineStyle)
        .value("eELEMENTPARAM_LineStyleParam", ELEMENTPARAM_LineStyleParam)
        .value("eELEMENTPARAM_Class", ELEMENTPARAM_Class)
        .value("eELEMENTPARAM_Transparency", ELEMENTPARAM_Transparency)
        .value("eELEMENTPARAM_Priority", ELEMENTPARAM_Priority)
        .value("eELEMENTPARAM_AreaMode", ELEMENTPARAM_AreaMode)
        .value("eELEMENTPARAM_FillColor", ELEMENTPARAM_FillColor)
        .value("eELEMENTPARAM_FillMode", ELEMENTPARAM_FillMode)
        .value("eELEMENTPARAM_CellName", ELEMENTPARAM_CellName)
        .value("eELEMENTPARAM_Scale", ELEMENTPARAM_Scale)
        .value("eELEMENTPARAM_Terminator", ELEMENTPARAM_Terminator)
        .value("eELEMENTPARAM_TerminatorScale", ELEMENTPARAM_TerminatorScale)
        .value("eELEMENTPARAM_ActivePoint", ELEMENTPARAM_ActivePoint)
        .value("eELEMENTPARAM_TextStyle", ELEMENTPARAM_TextStyle)
        .value("eELEMENTPARAM_TextStyleOverride", ELEMENTPARAM_TextStyleOverride)
        .value("eELEMENTPARAM_PatternCell", ELEMENTPARAM_PatternCell)
        .value("eELEMENTPARAM_PatternDelta", ELEMENTPARAM_PatternDelta)
        .value("eELEMENTPARAM_PatternAngle", ELEMENTPARAM_PatternAngle)
        .value("eELEMENTPARAM_PatternScale", ELEMENTPARAM_PatternScale)
        .value("eELEMENTPARAM_AreaPatternDelta", ELEMENTPARAM_AreaPatternDelta)
        .value("eELEMENTPARAM_AreaPatternAngle", ELEMENTPARAM_AreaPatternAngle)
        .value("eELEMENTPARAM_MlineStyle", ELEMENTPARAM_MlineStyle)
        .value("eELEMENTPARAM_DimensionStyle", ELEMENTPARAM_DimensionStyle)
        .value("eELEMENTPARAM_Material", ELEMENTPARAM_Material)
        .value("eELEMENTPARAM_DetailSymbolStyle", ELEMENTPARAM_DetailSymbolStyle)
        .value("eELEMENTPARAM_PatternIsAnnotation", ELEMENTPARAM_PatternIsAnnotation)
        .export_values();
    
    //===================================================================================
    // struct ElementTemplateParamsHelper
    py::class_< ElementTemplateParamsHelper> c1(m, "ElementTemplateParamsHelper");


    c1.def_static("GetEntryCount", [] (ECN::IECInstanceCR etInstance, ElementParameterType param)
                  {
                  UInt32 numEntries = 0;
                  auto retVal = ElementTemplateParamsHelper::GetEntryCount(numEntries, etInstance, param);
                  return py::make_tuple(retVal, numEntries);
                  }, "etInstance"_a, "param"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetEntryCount));

    c1.def_static("GetLineStyleIdFromName", [] (WCharCP lineStyleString, DgnModelRefP modelRef)
                  {
                  bool isNamedStyle = false;
                  auto retVal = ElementTemplateParamsHelper::GetLineStyleIdFromName(lineStyleString, isNamedStyle, modelRef);
                  return py::make_tuple(retVal, isNamedStyle);
                  }, "lineStyleString"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetLineStyleIdFromName));

    c1.def_static("GetLevelName", &ElementTemplateParamsHelper::GetLevelName, "levelName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetLevelName));

    c1.def_static("GetLevelId", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  LevelId levelId = 0;
                  auto retVal = ElementTemplateParamsHelper::GetLevelId(levelId, modelRef, etInstance, index);
                  return py::make_tuple(retVal, levelId);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetLevelId));

    c1.def_static("GetElementColor", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  UInt32 color = 0;
                  auto retVal = ElementTemplateParamsHelper::GetElementColor(color, modelRef, etInstance, index);
                  return py::make_tuple(retVal, color);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetElementColor));

    c1.def_static("GetWeight", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  int weight = 0;
                  auto retVal = ElementTemplateParamsHelper::GetWeight(weight, etInstance, index);
                  return py::make_tuple(retVal, weight);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetWeight));

    c1.def_static("GetLineStyleName", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  WString styleName;
                  bool isNamedStyle = false;
                  auto retVal = ElementTemplateParamsHelper::GetLineStyleName(styleName, isNamedStyle, modelRef, etInstance, index);
                  return py::make_tuple(retVal, styleName, isNamedStyle);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetLineStyleName));

    c1.def_static("GetLineStyleId", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  Int32 styleId;
                  bool isNamedStyle = false;
                  auto retVal = ElementTemplateParamsHelper::GetLineStyleId(styleId, isNamedStyle, modelRef, etInstance, index);
                  return py::make_tuple(retVal, styleId, isNamedStyle);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetLineStyleId));

    c1.def_static("GetLineStyleParams", &ElementTemplateParamsHelper::GetLineStyleParams, "lineStyleParams"_a, "uorsPerMeter"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetLineStyleParams));

    c1.def_static("GetElementClass", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  DgnElementClass elementClass;
                  auto retVal = ElementTemplateParamsHelper::GetElementClass(elementClass, etInstance, index);
                  return py::make_tuple(retVal, elementClass);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetElementClass));

    c1.def_static("GetTransparency", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  double transparency;
                  auto retVal = ElementTemplateParamsHelper::GetTransparency(transparency, etInstance, index);
                  return py::make_tuple(retVal, transparency);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetTransparency));

    c1.def_static("GetPriority", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  int priority;
                  auto retVal = ElementTemplateParamsHelper::GetPriority(priority, etInstance, index);
                  return py::make_tuple(retVal, priority);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetPriority));

    c1.def_static("GetAreaMode", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  bool isHole;
                  auto retVal = ElementTemplateParamsHelper::GetAreaMode(isHole, etInstance, index);
                  return py::make_tuple(retVal, isHole);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetAreaMode));

    c1.def_static("GetFillColorIdOrGradientSpecification", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  UInt32 color;
                  GradientSymbPtr gradientsymb;
                  auto retVal = ElementTemplateParamsHelper::GetFillColorIdOrGradientSpecification(color, gradientsymb, modelRef, etInstance, index);
                  return py::make_tuple(retVal, color, gradientsymb);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetFillColorIdOrGradientSpecification));

    c1.def_static("GetFillMode", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  ElementFillModeType fillMode;
                  auto retVal = ElementTemplateParamsHelper::GetFillMode(fillMode, etInstance, index);
                  return py::make_tuple(retVal, fillMode);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetFillMode));

    c1.def_static("GetCellName", &ElementTemplateParamsHelper::GetCellName, "cellName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetCellName));
    c1.def_static("GetAnyCellName", &ElementTemplateParamsHelper::GetAnyCellName, "cellName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetAnyCellName));
    c1.def_static("GetCellScale", &ElementTemplateParamsHelper::GetCellScale, "cellScale"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetCellScale));
    c1.def_static("GetTerminatorCellName", &ElementTemplateParamsHelper::GetTerminatorCellName, "cellName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetTerminatorCellName));

    c1.def_static("GetTerminatorScale", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  double scale;
                  auto retVal = ElementTemplateParamsHelper::GetTerminatorScale(scale, etInstance, index);
                  return py::make_tuple(retVal, scale);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetTerminatorScale));

    c1.def_static("GetActivePointSpecification", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  ActivePointType pointType;
                  WString cellNameOrCharacter;
                  auto retVal = ElementTemplateParamsHelper::GetActivePointSpecification(pointType, cellNameOrCharacter, etInstance, index);
                  return py::make_tuple(retVal, pointType, cellNameOrCharacter);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetActivePointSpecification));

    c1.def_static("GetTextStyleName", &ElementTemplateParamsHelper::GetTextStyleName, "styleName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetTextStyleName));

    c1.def_static("GetTextStyleId", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  UInt32 styleId = 0;
                  auto retVal = ElementTemplateParamsHelper::GetTextStyleId(styleId, modelRef, etInstance, index);
                  return py::make_tuple(retVal, styleId);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetTextStyleId));

    c1.def_static("GetTextParamsAndScale", [] (DgnModelRefP modelRef, double uorsPerMeter, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  TextParamWide textParams;
                  DPoint2d textScale;
                  short lineLength;
                  auto retVal = ElementTemplateParamsHelper::GetTextParamsAndScale(textParams, textScale, lineLength, modelRef, uorsPerMeter, etInstance, index);
                  return py::make_tuple(retVal, textParams, textScale, lineLength);
                  }, "modelRef"_a, "uorsPerMeter"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetTextParamsAndScale));

    c1.def_static("GetPatternParams", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  auto patternParams = PatternParams::Create();
                  auto retVal = ElementTemplateParamsHelper::GetPatternParams(*patternParams, modelRef, etInstance, index);
                  return py::make_tuple(retVal, patternParams);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetPatternParams));

    c1.def_static("GetHatchParams", [] (DgnModelRefP modelRef, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  auto patternParams = PatternParams::Create();
                  auto retVal = ElementTemplateParamsHelper::GetHatchParams(*patternParams, modelRef, etInstance, index);
                  return py::make_tuple(retVal, patternParams);
                  }, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetHatchParams));

    c1.def_static("GetPatternCellName", &ElementTemplateParamsHelper::GetPatternCellName, "cellName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetPatternCellName));
    c1.def_static("GetPatternDeltaValues", &ElementTemplateParamsHelper::GetPatternDeltaValues, "deltaxValue"_a, "deltayValue"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetPatternDeltaValues));

    c1.def_static("GetPatternScale", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  double scale;
                  auto retVal = ElementTemplateParamsHelper::GetPatternScale(scale, etInstance, index);
                  return py::make_tuple(retVal, scale);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetPatternScale));

    c1.def_static("GetPatternAngle", [] (ECN::IECInstanceCR etInstance, UInt index)
                  {
                  double angle;
                  auto retVal = ElementTemplateParamsHelper::GetPatternAngle(angle, etInstance, index);
                  return py::make_tuple(retVal, angle);
                  }, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetPatternAngle));

    c1.def_static("GetHatchPatternIsAnnotation", &ElementTemplateParamsHelper::GetHatchPatternIsAnnotation, "isAnnotation"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetHatchPatternIsAnnotation));
    c1.def_static("GetHatchDeltaValues", &ElementTemplateParamsHelper::GetHatchDeltaValues, "deltaxValue"_a, "deltayValue"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetHatchDeltaValues));
    c1.def_static("GetHatchAngleValues", &ElementTemplateParamsHelper::GetHatchAngleValues, "angle1Value"_a, "angle2Value"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetHatchAngleValues));
    c1.def_static("GetMlineStyleName", &ElementTemplateParamsHelper::GetMlineStyleName, "styleName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetMlineStyleName));
    
    c1.def_static("GetMlineStyle", [] (DgnFileR file, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  MultilineStylePtr mlineStyle;
                  auto retVal = ElementTemplateParamsHelper::GetMlineStyle(mlineStyle, file, etInstance, index);
                  return py::make_tuple(retVal, mlineStyle);
                  }, "dgnFile"_a, "etInstance"_a, "index"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetMlineStyle));

    c1.def_static("GetDimensionStyleName", &ElementTemplateParamsHelper::GetDimensionStyleName, "styleName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetDimensionStyleName));
    
    c1.def_static("GetDimensionStyle", [] (DgnFileR file, ECN::IECInstanceCR etInstance, UInt index)
                  {
                  DimensionStylePtr dimStyle;
                  auto retVal = ElementTemplateParamsHelper::GetDimensionStyle(dimStyle, file, etInstance, index);
                  return py::make_tuple(retVal, dimStyle);
                  }, "dgnFile"_a, "etInstance"_a, "index"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetDimensionStyle));
    
    c1.def_static("GetMaterialNameAndPalette", &ElementTemplateParamsHelper::GetMaterialNameAndPalette, "material"_a, "palette"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetMaterialNameAndPalette));
    c1.def_static("GetMaterialId", &ElementTemplateParamsHelper::GetMaterialId, "matId"_a, "modelRef"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetMaterialId));
    c1.def_static("GetDetailSymbolStyleName", &ElementTemplateParamsHelper::GetDetailSymbolStyleName, "styleName"_a, "etInstance"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, GetDetailSymbolStyleName));

    c1.def_static("SetLevelByName", &ElementTemplateParamsHelper::SetLevelByName, "etInstance"_a, "levelName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetLevelByName));
    c1.def_static("SetLevelById", &ElementTemplateParamsHelper::SetLevelById, "etInstance"_a, "levelId"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetLevelById));
    c1.def_static("SetElementColor", &ElementTemplateParamsHelper::SetElementColor, "etInstance"_a, "elementColor"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetElementColor));
    c1.def_static("SetLineWeight", &ElementTemplateParamsHelper::SetLineWeight, "etInstance"_a, "lineWeight"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetLineWeight));
    c1.def_static("SetLineStyleByName", &ElementTemplateParamsHelper::SetLineStyleByName, "etInstance"_a, "lineStyleName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetLineStyleByName));
    c1.def_static("SetLineStyleById", &ElementTemplateParamsHelper::SetLineStyleById, "etInstance"_a, "lineStyleId"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetLineStyleById));
    c1.def_static("SetLineStyleParams", &ElementTemplateParamsHelper::SetLineStyleParams, "etInstance"_a, "lineStyleParams"_a, "modelRef"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetLineStyleParams));
    c1.def_static("SetElementClass", &ElementTemplateParamsHelper::SetElementClass, "etInstance"_a, "elementClass"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetElementClass));
    c1.def_static("SetTransparency", &ElementTemplateParamsHelper::SetTransparency, "etInstance"_a, "transparency"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetTransparency));
    c1.def_static("SetPriority", &ElementTemplateParamsHelper::SetPriority, "etInstance"_a, "priority"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetPriority));
    c1.def_static("SetAreaMode", &ElementTemplateParamsHelper::SetAreaMode, "etInstance"_a, "isHole"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetAreaMode));
    c1.def_static("SetElementFillToSolidColor", &ElementTemplateParamsHelper::SetElementFillToSolidColor, "etInstance"_a, "elementColor"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetElementFillToSolidColor));
    c1.def_static("SetElementFillToGradient", &ElementTemplateParamsHelper::SetElementFillToGradient, "etInstance"_a, "gradientsymb"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetElementFillToGradient));
    c1.def_static("SetFillMode", &ElementTemplateParamsHelper::SetFillMode, "etInstance"_a, "fillMode"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetFillMode));
    c1.def_static("SetCellName", &ElementTemplateParamsHelper::SetCellName, "etInstance"_a, "cellName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetCellName));
    c1.def_static("SetCellScale", &ElementTemplateParamsHelper::SetCellScale, "etInstance"_a, "cellScale"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetCellScale));
    c1.def_static("SetTerminatorCellName", &ElementTemplateParamsHelper::SetTerminatorCellName, "etInstance"_a, "cellName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetTerminatorCellName));
    c1.def_static("SetTerminatorScale", &ElementTemplateParamsHelper::SetTerminatorScale, "etInstance"_a, "scale"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetTerminatorScale));
    c1.def_static("SetActivePointSpecification", &ElementTemplateParamsHelper::SetActivePointSpecification, "etInstance"_a, "pointType"_a, "cellNameOrCharacter"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetActivePointSpecification));
    c1.def_static("SetTextStyleByName", &ElementTemplateParamsHelper::SetTextStyleByName, "etInstance"_a, "textStyleName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetTextStyleByName));
    c1.def_static("SetTextStyleById", &ElementTemplateParamsHelper::SetTextStyleById, "etInstance"_a, "styleId"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetTextStyleById));
    c1.def_static("SetTextStyleOverride",
        [](ECN::IECInstanceR etInstance, DPoint2d* textScale, TextParamWide* textParams, boost::optional<short> lineLength, DgnModelRefP modelRef, UInt index)
        {
            return ElementTemplateParamsHelper::SetTextStyleOverride(etInstance, textScale, textParams, lineLength.get_ptr(), modelRef, index);
        },
        "etInstance"_a, "textScale"_a, "textParams"_a, "lineLength"_a, "modelRef"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetTextStyleOverride));
    c1.def_static("SetPatternCellName", &ElementTemplateParamsHelper::SetPatternCellName, "etInstance"_a, "cellName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetPatternCellName));
    c1.def_static("SetPatternDeltaValues", &ElementTemplateParamsHelper::SetPatternDeltaValues, "etInstance"_a, "deltaxValue"_a, "deltayValue"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetPatternDeltaValues));
    c1.def_static("SetPatternAngle", &ElementTemplateParamsHelper::SetPatternAngle, "etInstance"_a, "angle"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetPatternAngle));
    c1.def_static("SetPatternScale", &ElementTemplateParamsHelper::SetPatternScale, "etInstance"_a, "scale"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetPatternScale));
    c1.def_static("SetHatchDeltaValues", &ElementTemplateParamsHelper::SetHatchDeltaValues, "etInstance"_a, "deltaxValue"_a, "deltayValue"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetHatchDeltaValues));
    c1.def_static("SetHatchAngleValues", &ElementTemplateParamsHelper::SetHatchAngleValues, "etInstance"_a, "angle1Value"_a, "angle2Value"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetHatchAngleValues));
    c1.def_static("SetMlineStyleByName", &ElementTemplateParamsHelper::SetMlineStyleByName, "etInstance"_a, "styleName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetMlineStyleByName));
    c1.def_static("SetMlineStyleById", &ElementTemplateParamsHelper::SetMlineStyleById, "etInstance"_a, "styleId"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetMlineStyleById));
    c1.def_static("SetDimensionStyleByName", &ElementTemplateParamsHelper::SetDimensionStyleByName, "etInstance"_a, "styleName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetDimensionStyleByName));
    c1.def_static("SetDimensionStyleById", &ElementTemplateParamsHelper::SetDimensionStyleById, "etInstance"_a, "styleId"_a, "dgnFile"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetDimensionStyleById));
    c1.def_static("SetMaterialNameAndPalette", &ElementTemplateParamsHelper::SetMaterialNameAndPalette, "etInstance"_a, "material"_a, "palette"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetMaterialNameAndPalette));
    c1.def_static("SetDetailSymbolStyleByName", &ElementTemplateParamsHelper::SetDetailSymbolStyleByName, "etInstance"_a, "styleName"_a, "index"_a = 0, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, SetDetailSymbolStyleByName));

    c1.def_static("AddLevelByName", &ElementTemplateParamsHelper::AddLevelByName, "etInstance"_a, "levelName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddLevelByName));
    c1.def_static("AddLevelById", &ElementTemplateParamsHelper::AddLevelById, "etInstance"_a, "levelId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddLevelById));
    c1.def_static("AddElementColor", &ElementTemplateParamsHelper::AddElementColor, "etInstance"_a, "elementColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddElementColor));
    c1.def_static("AddLineWeight", &ElementTemplateParamsHelper::AddLineWeight, "etInstance"_a, "lineWeight"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddLineWeight));
    c1.def_static("AddLineStyleByName", &ElementTemplateParamsHelper::AddLineStyleByName, "etInstance"_a, "lineStyleName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddLineStyleByName));
    c1.def_static("AddLineStyleById", &ElementTemplateParamsHelper::AddLineStyleById, "etInstance"_a, "lineStyleId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddLineStyleById));
    c1.def_static("AddLineStyleParams", &ElementTemplateParamsHelper::AddLineStyleParams, "etInstance"_a, "lineStyleParams"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddLineStyleParams));
    c1.def_static("AddElementClass", &ElementTemplateParamsHelper::AddElementClass, "etInstance"_a, "elementClass"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddElementClass));
    c1.def_static("AddTransparency", &ElementTemplateParamsHelper::AddTransparency, "etInstance"_a, "transparency"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddTransparency));
    c1.def_static("AddPriority", &ElementTemplateParamsHelper::AddPriority, "etInstance"_a, "priority"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddPriority));
    c1.def_static("AddAreaMode", &ElementTemplateParamsHelper::AddAreaMode, "etInstance"_a, "isHole"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddAreaMode));
    c1.def_static("AddSolidFillColor", &ElementTemplateParamsHelper::AddSolidFillColor, "etInstance"_a, "elementColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddSolidFillColor));
    c1.def_static("AddGradientFillColor", &ElementTemplateParamsHelper::AddGradientFillColor, "etInstance"_a, "gradientsymb"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddGradientFillColor));
    c1.def_static("AddFillMode", &ElementTemplateParamsHelper::AddFillMode, "etInstance"_a, "fillMode"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddFillMode));
    c1.def_static("AddCellName", &ElementTemplateParamsHelper::AddCellName, "etInstance"_a, "cellName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddCellName));
    c1.def_static("AddCellScale", &ElementTemplateParamsHelper::AddCellScale, "etInstance"_a, "cellScale"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddCellScale));
    c1.def_static("AddTerminatorCellName", &ElementTemplateParamsHelper::AddTerminatorCellName, "etInstance"_a, "cellName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddTerminatorCellName));
    c1.def_static("AddTerminatorScale", &ElementTemplateParamsHelper::AddTerminatorScale, "etInstance"_a, "cellScale"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddTerminatorScale));
    c1.def_static("AddActivePointSpecification", &ElementTemplateParamsHelper::AddActivePointSpecification, "etInstance"_a, "pointType"_a, "cellNameOrCharacter"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddActivePointSpecification));
    c1.def_static("AddTextStyleByName", &ElementTemplateParamsHelper::AddTextStyleByName, "etInstance"_a, "textStyleName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddTextStyleByName));
    c1.def_static("AddTextStyleById", &ElementTemplateParamsHelper::AddTextStyleById, "etInstance"_a, "textStyleId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddTextStyleById));
    c1.def_static("AddTextStyleOverride",
        [](ECN::IECInstanceR etInstance, DPoint2d* textScale, TextParamWide* textParams, boost::optional<short> lineLength, DgnModelRefP modelRef)
        {
            return ElementTemplateParamsHelper::AddTextStyleOverride(etInstance, textScale, textParams, lineLength.get_ptr(), modelRef);
        }, 
        "etInstance"_a, "textScale"_a, "textParams"_a, "lineLength"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddTextStyleOverride));
    c1.def_static("AddPatternCellName", &ElementTemplateParamsHelper::AddPatternCellName, "etInstance"_a, "cellname"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddPatternCellName));
    c1.def_static("AddPatternDeltaValues", &ElementTemplateParamsHelper::AddPatternDeltaValues, "etInstance"_a, "deltaxValue"_a, "deltayValue"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddPatternDeltaValues));
    c1.def_static("AddPatternAngle", &ElementTemplateParamsHelper::AddPatternAngle, "etInstance"_a, "angle"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddPatternAngle));
    c1.def_static("AddPatternScale", &ElementTemplateParamsHelper::AddPatternScale, "etInstance"_a, "scale"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddPatternScale));
    c1.def_static("AddHatchDeltaValues", &ElementTemplateParamsHelper::AddHatchDeltaValues, "etInstance"_a, "deltaxValue"_a, "deltayValue"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddHatchDeltaValues));
    c1.def_static("AddHatchAngleValues", &ElementTemplateParamsHelper::AddHatchAngleValues, "etInstance"_a, "angle1Value"_a, "angle2Value"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddHatchAngleValues));
    c1.def_static("AddMlineStyleByName", &ElementTemplateParamsHelper::AddMlineStyleByName, "etInstance"_a, "styleName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddMlineStyleByName));
    c1.def_static("AddMlineStyleById", &ElementTemplateParamsHelper::AddMlineStyleById, "etInstance"_a, "styleId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddMlineStyleById));
    c1.def_static("AddDimensionStyleByName", &ElementTemplateParamsHelper::AddDimensionStyleByName, "etInstance"_a, "styleName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddDimensionStyleByName));
    c1.def_static("AddDimensionStyleById", &ElementTemplateParamsHelper::AddDimensionStyleById, "etInstance"_a, "styleId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddDimensionStyleById));
    c1.def_static("AddMaterialNameAndPalette", &ElementTemplateParamsHelper::AddMaterialNameAndPalette, "etInstance"_a, "material"_a, "palette"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddMaterialNameAndPalette));
    c1.def_static("AddMaterialById", &ElementTemplateParamsHelper::AddMaterialById, "etInstance"_a, "materialId"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddMaterialById));
    c1.def_static("AddDetailSymbolStyleByName", &ElementTemplateParamsHelper::AddDetailSymbolStyleByName, "etInstance"_a, "styleName"_a, DOC(Bentley, DgnPlatform, ElementTemplateParamsHelper, AddDetailSymbolStyleByName));
    }