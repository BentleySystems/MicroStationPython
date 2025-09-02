/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\irasterattachment.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IRasterAttachment.h>



static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetClipProperties =R"doc(Change clipProperties set on this raster attachment.

:param eeh:
    The element to modify.

:param clipProperties:
    The clip properties object to set.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGeocoding =R"doc(Change the element handle that describe the geographic coordinate
system (geocoding) for this raster attachment.

:param eeh:
    The element to modify.

:param geocoding:
    The element handle that describe the geographic coordinate system
    (geocoding) to set. Use an invalid elemHandle to remove geocoding.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetWorldFileDefaultUnitFactor =R"doc(Change default unit factor multiplier for world file unit definition.

:param eeh:
    The element to modify.

:param factor:
    The default unit factor multiplier for world file unit definition.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetWorldFileUnit =R"doc(Change default unit definition to use when the georeference is
extracted from a world file that accompanied the raster file. This
represent the unit to use to interpret a world file sister file when
raster file are accompanied by one.

:param eeh:
    The element to modify.

:param WorldFileUnit:
    The unit definition that will be used.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGeotiffUnitPriority =R"doc(Change which geotiff unit definition must be use in a geotiff raster
file.

:param eeh:
    The element to modify.

:param priority:
    The geotiff unit definition that must be use in a geotiff raster
    file.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGeotiffUnitUseUOR =R"doc(Change if geotiff default unit are UOR.

:param eeh:
    The element to modify.

:param useUOR:
    Set to true if geotiff default unit are UOR.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGeotiffDefaultUnitFactor =R"doc(Change default unit factor multiplier for geotiff unit definition.

:param eeh:
    The element to modify.

:param factor:
    The default unit factor multiplier for geotiff unit definition.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGeotiffUnit =R"doc(Change the unit definition to use when interpreting a geotiff raster
file.

:param eeh:
    The element to modify.

:param GeotiffUnit:
    The unit definition that will be set.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetTransparentColors =R"doc(Change transparent color set on this raster attachment.

:param eeh:
    The element to modify.

:param rasterTransparentColors:
    The transparent color collection to set.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetImageTransparencyLevel =R"doc(Change transparency value applied to all raster image at display
[0,255], 0 -> Opaque.

:param eeh:
    The element to modify.

:param transparency:
    The transparency value applied to all raster image at display
    [0,255], 0 -> Opaque.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetBrightness =R"doc(Change brightness apply at display [-128,+127], 0 -> nothing.

:param eeh:
    The element to modify.

:param brightness:
    The brightness apply at display [-128,+127], 0 -> nothing.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetContrast =R"doc(Change contrast apply at display [-128,+127], 0 -> nothing.

:param eeh:
    The element to modify.

:param contrast:
    The contrast apply at display [-128,+127], 0 -> nothing.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetBackgroundColor =R"doc(Change raw color index used as background color.

:param eeh:
    The element to modify.

:param rawColorIndex:
    The raw color index used as background color.

:returns:
    true if element was updated. @See RgbFromColorIndexInModel @See
    ColorIndexFromRgbInModel)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetForegroundColor =R"doc(Change raw color index used as foreground color.

:param eeh:
    The element to modify.

:param rawColorIndex:
    The raw color index used as foreground color.

:returns:
    true if element was updated. @See RgbFromColorIndexInModel @See
    ColorIndexFromRgbInModel)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetTintColor =R"doc(Change raw color index used to tint raster.

:param eeh:
    The element to modify.

:param rawColorIndex:
    The raw color index used to tint raster.

:returns:
    true if element was updated. @See RgbFromColorIndexInModel @See
    ColorIndexFromRgbInModel)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetPrintGamma =R"doc(Change gamma value used to print raster.

:param eeh:
    The element to modify.

:param gamma:
    The new gamma value used to print raster (0 is illegal and no
    gamma = 1.0).

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetViewGamma =R"doc(Change gamma value used to display raster in views.

:param eeh:
    The element to modify.

:param gamma:
    The gamma value used to display raster in views (0 is illegal and
    no gamma = 1.0).

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetLayer =R"doc(Change the layer number of this raster attachment. Raster in back and
front plane are ordered by there layer number. Smaller Layer number
being at the back of the view and stack to front in order. Two raster
might have the same layer number in which case the order in file will
determine the final order. You should try to avoid this situation.

:param eeh:
    The element to modify.

:param layer:
    The new layer number.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetDisplayPriorityPlane =R"doc(Change the RasterDisplayPriorityPlane value.

:param eeh:
    The element to modify.

:param plane:
    The RasterDisplayPriorityPlane value.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetBinaryPrintInvertState =R"doc(Change if background and foreground color should be inverted for
binary raster file during print.

:param eeh:
    The element to modify.

:param state:
    Set to true if background and foreground color should be inverted
    for binary raster file during print.

:returns:
    true if element was updated.

Remark:
    This setting has not effect if the raster file is not binary.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetTransparencyState =R"doc(Change if transparency must be displayed.

:param eeh:
    The element to modify.

:param state:
    Set to true if transparency must be displayed.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetClipState =R"doc(Change if raster clip properties are applied at display time.

:param eeh:
    The element to modify.

:param state:
    Set to true to applied clip properties at display time.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetPrintState =R"doc(Change if raster must be print.

:param eeh:
    The element to modify.

:param state:
    Set to true if raster must be print.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetInvertState =R"doc(Change if raster color must be inverted on display.

:param eeh:
    The element to modify.

:param state:
    Set to true if raster color must be inverted on display.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetViewState =R"doc(Change if the raster is displayed in a specific view.

:param eeh:
    The element to modify.

:param viewNumber:
    The view number to query [0..7].

:param state:
    Set to true if the raster is displayed in the view.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetScanningResolution =R"doc(Change scanning resolution (in dot per inches (DPI), in x and y
directions).

:param eeh:
    The element to modify.

:param scanningResolutionDPI:
    The new scanning resolution (in dot per inches (DPI), in x and y
    directions).

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetColorMode =R"doc(Change color mode stored in this raster attachment.

:param eeh:
    The element to modify.

:param colorMode:
    The color mode value of this raster attachment.

:returns:
    true if element was updated.

Remark:
    This information is mostly used to export to dgn version 7 which
    store raster attachment differently based on the color mode.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetPageNumber =R"doc(Change page number for multi-page file.

:param eeh:
    The element to modify.

:param page:
    The new page number, default is 0.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetTransform =R"doc(Change raster attachment transformation matrix (pixel to UOR) and
compute a new extent base on estimated bitmap size (from previous
transform and extent).

:param eeh:
    The element to modify.

:param matrix:
    The new transformation matrix to set (pixel to UOR).

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGCSInheritedFromModelState =R"doc(Change if raster Geographic Coordinate System is inherited from the
DgnModel or not.

:param eeh:
    The element to modify.

:param state:
    Set to true if raster Geographic Coordinate System is inherited
    from the DgnModel raster is attached to.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetGeoreferencePriority =R"doc(Change which georeference has priority when raster is loaded.

:param eeh:
    The element to modify.

:param priority:
    Set which georeference has priority when raster is loaded.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetOpenReadWrite =R"doc(Change if the raster file should be open in read-write mode or in
read-only.

:param eeh:
    The element to modify.

:param isWritable:
    Set to true if the raster file should be open in read-write mode,
    for read-only set it to false.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetViewIndependentState =R"doc(Change view independent display state for this attachment.

:param eeh:
    The element to modify.

:param state:
    Set to true if this raster display is view independent.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetLockedState =R"doc(Change the lock state for this raster.

:param eeh:
    The element to modify.

:param state:
    The new lock state to set.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetSnappableState =R"doc(Change if snap is enable for this raster.

:param eeh:
    The element to modify.

:param state:
    Set to true if snap is enable for this raster.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetLogicalName =R"doc(Change logical name.

:param eeh:
    The element to modify.

:param logicalName:
    The new logical name.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetAttachDescription =R"doc(Change raster attachment description.

:param eeh:
    The element to modify.

:param description:
    The new description.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetAttachMoniker0 =R"doc(Set the moniker that identifies the raster file; basic not overridable
method.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_SetAttachMoniker =R"doc(Set the moniker that identifies the raster file

:param eeh:
    The element to modify.

:param moniker:
    The moniker that identify that raster file.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentEdit_CreateRasterAttachment =R"doc(Create a new Raster attachment with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Initialize default properties from this template element or NULL.

:param moniker:
    Moniker that identifies the raster file.

:param matrix:
    The new transformation matrix to set (pixel to UOR).

:param extentInUOR:
    The new raster size in UOR.

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
    SUCCESS if a valid element is created and range was successfully
    calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetClipProperties =R"doc(Query clipProperties set on this raster attachment.

:param eh:
    The element to query.

:returns:
    a newly created RasterClipProperties filled from raster attachment
    values.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGeocoding =R"doc(Query the element handle that describe the geographic coordinate
system (geocoding) for this raster attachment.

:param eh:
    The element to query.

:returns:
    the element handle that describe the geographic coordinate system
    (geocoding) for this raster attachment.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetWorldFileDefaultUnitFactor =R"doc(Query default unit factor multiplier for world file unit definition.

:param eh:
    The element to query. Returns default unit factor multiplier for
    world file unit definition.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetWorldFileUnit =R"doc(Query default unit definition to use when the georeference is
extracted from a world file that accompanied the raster file. This
represent the unit to use to interpret a world file sister file when
raster file are accompanied by one.

:param eh:
    The element to query.

:param WorldFileUnit:
    Unit definition that will be filled.

:returns:
    a const reference to input WorldFileUnit filled from raster
    attachment values.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGeotiffUnitPriority =R"doc(Query which geotiff unit definition must be use in a geotiff raster
file.

:param eh:
    The element to query.

:returns:
    which geotiff unit definition must be use in a geotiff raster
    file.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGeotiffUnitUseUOR =R"doc(Query if geotiff default unit are UOR.

:param eh:
    The element to query.

:returns:
    true is geotiff default unit are UOR.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGeotiffDefaultUnitFactor =R"doc(Query default unit factor multiplier for geotiff unit definition.

:param eh:
    The element to query.

:returns:
    default unit factor multiplier)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGeotiffUnit =R"doc(Query the unit definition to use when interpreting a geotiff raster
file.

:param eh:
    The element to query.

:param GeotiffUnit:
    Unit definition that will be filled.

:returns:
    a const reference to input GeotiffUnit filled from raster
    attachment values.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetTransparentColors =R"doc(Query transparent color set on this raster attachment.

:param eh:
    The element to query.

:returns:
    a newly created transparent color collection smart pointer filled
    from raster attachment values.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetImageTransparencyLevel =R"doc(Query transparency value applied to all raster image at display [0,
255], 0 -> Opaque.

:param eh:
    The element to query.

:returns:
    transparency value applied to all raster image at display [0,
    255], 0 -> Opaque.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetBrightness =R"doc(Query brightness apply at display [-128, +127], 0 -> nothing.

:param eh:
    The element to query.

:returns:
    brightness apply at display [-128, +127], 0 -> nothing.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetContrast =R"doc(Query contrast apply at display [-128, +127], 0 -> nothing.

:param eh:
    The element to query.

:returns:
    contrast apply at display [-128, +127], 0 -> nothing.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetBackgroundColor =R"doc(Query raw color index used as background color. @See
RgbFromColorIndexInModel

:param eh:
    The element to query.

:returns:
    raw color index used as background color.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetForegroundColor =R"doc(Query raw color index used as foreground color. @See
RgbFromColorIndexInModel

:param eh:
    The element to query.

:returns:
    raw color index used as foreground color.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetTintColor =R"doc(Query raw color index used to tint raster. @See
RgbFromColorIndexInModel

:param eh:
    The element to query.

:returns:
    raw color index used to tint raster.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetPrintGamma =R"doc(Query gamma value used to print raster.

:param eh:
    The element to query.

:returns:
    gamma value used to print raster. Zero is illegal and no gamma =
    1.0.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetViewGamma =R"doc(Query gamma value used to display raster in views.

:param eh:
    The element to query.

:returns:
    gamma value used to display raster in views. Zero is illegal and
    no gamma = 1.0.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetLayer =R"doc(Query the layer number of this raster attachment. Raster in back and
front plane are ordered by there layer number. Smaller Layer number
being at the back of the view and stack to front in order. Two raster
might have the same layer number in which case the order in file will
determine the final order. You should try to avoid this situation.

:param eh:
    The element to query.

:returns:
    the layer number of this raster attachment.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetDisplayPriorityPlane =R"doc(Query the RasterDisplayPriorityPlane value.

:param eh:
    The element to query.

:returns:
    one of the RasterDisplayPriorityPlane value, or 0 if never
    initialized.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetBinaryPrintInvertState =R"doc(Query if background and foreground color should be inverted for binary
raster file during print.

Remark:
    This setting has not effect if the raster file is not binary.

:param eh:
    The element to query.

:returns:
    true if background and foreground color should be inverted for
    binary raster file during print.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetTransparencyState =R"doc(Query if transparency must be displayed.

:param eh:
    The element to query.

:returns:
    true if transparency must be displayed.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetClipState =R"doc(Query if raster clip properties are applied at display time.

:param eh:
    The element to query.

:returns:
    true if raster clip properties are applied at display time.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetPrintState =R"doc(Query if raster must be print.

:param eh:
    The element to query.

:returns:
    true if raster must be print.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetInvertState =R"doc(Query if raster color must be inverted on display.

:param eh:
    The element to query.

:returns:
    true if raster color must be inverted on display.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetViewState =R"doc(Query if the raster is displayed in a specific view.

:param eh:
    The element to query.

:param viewNumber:
    The view number to query [0..7].

:returns:
    true if the raster is displayed in the view.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetScanningResolution =R"doc(Query scanning resolution (in dot per inches (DPI), in x and y
directions).

:param eh:
    The element to query.

:returns:
    scanning resolution (in x and y directions).)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetExtent =R"doc(Query raster size in UORs

:param eh:
    The element to query.

:returns:
    raster size in UORs)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetColorMode =R"doc(Query last color mode value set in the attachment (will not query the
actual raster file).

Remark:
    It will returns the last value set in the attachment and will not
    query the actual raster file. This information is mostly used to
    export to dgn version 7 which store raster attachment differently
    based on the color mode.

:param eh:
    The element to query.

:returns:
    one of the COLORMODE defines from image.h - returns
    ImageColorMode::Any if unknown)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetPageNumber =R"doc(Returns page number for multi-page file.

:param eh:
    The element to query.

:returns:
    page number for multi-page file. Default is 0.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetTransform =R"doc(Query raster attachment transformation matrix (pixel to UOR).

:param eh:
    The element to query.

:param matrix:
    The matrix that will be filled from the transform stored in that
    raster attachment (pixel to UOR).

:returns:
    BSISUCCESS if matrix that was filled is valid, otherwise BSIERROR.
    Notice that matrix output parameter will be filled even if
    BSIERROR is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGCSInheritedFromModelState =R"doc(Query if raster Geographic Coordinate System is inherited from the
DgnModel raster is attached to.

:param eh:
    The element to query.

:returns:
    true if raster Geographic Coordinate System is inherited from the
    DgnModel raster is attached to.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetGeoreferencePriority =R"doc(Query which georeference has priority when raster is loaded.

:param eh:
    The element to query.

:returns:
    which georeference has priority when raster is loaded.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetOpenReadWrite =R"doc(Query if the raster file should be open in read-write mode, otherwise
open in read-only.

:param eh:
    The element to query.

:returns:
    true if the raster file should be open in read-write mode,
    otherwise open in read-only.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetViewIndependentState =R"doc(Query if this raster display is view independent.

:param eh:
    The element to query.

:returns:
    true if this raster display is view independent.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetLockedState =R"doc(Query if lock is set for this raster.

:param eh:
    The element to query.

:returns:
    true if lock is enable for this raster.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetSnappableState =R"doc(Query if snap is enable for this raster.

:param eh:
    The element to query.

:returns:
    true if snap is enable for this raster.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetLogicalName =R"doc(Query logical name.

:param eh:
    The element to query.

:returns:
    logical name.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetAttachDescription =R"doc(Query raster attachment description.

:param eh:
    The element to query.

:returns:
    description.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetAttachMoniker =R"doc(Get the moniker that identifies the raster file)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_GetSearchPath =R"doc(Return default search path used with the attach moniker to find
attached raster file.

:param modelRef:
    Will search in this model design file folder.

:returns:
    the search string.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_RgbFromColorIndexInModel =R"doc(Query the RGB triplet from a DgnModelRef rawIndex.

:param color:
    the RGB triplet found.

:param modelRef:
    The DgnModelRef to look to for RGB color value.

:param rawIndex:
    The rawIndex of the RGB triplet to extract.

:returns:
    SUCCESS if Successful, ERROR otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_ColorIndexFromRgbInModel =R"doc(Query the raw color index of an RGB triplet from a DgnModelRef color
table, add a color book entry if not found.


:param modelRef:
    The DgnModelRef to look to for color table.

:param rgbColor:
    The RGB triplet to find index in color table.

Returns (Tuple, 0):
    SUCCESS if Successful, ERROR otherwise.

Returns (Tuple, 1):
	index. The raw color index of an RGB triplet from a DgnModelRef color
    table or color book entries.

)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_IsTransform3D =R"doc(Check if the matrix contains 3D transformation.

:param matrix:
    The matrix to check.

:returns:
    true if matrix contain 3D transformation.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterAttachmentQuery_IsValidTransform =R"doc(Check if the matrix is a valid raster transform matrix.

:param matrix:
    The matrix to check

:returns:
    true if matrix is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_AddTransparentColor =R"doc(Add a new indexed transparent color definition at the end of the
collection.

:param index:
    The transparent color index you want to set.

:param transparency:
    The transparency value of the color at this index. [0, 255], 255
    -> Opaque.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_SetTransparentColor =R"doc(Set a new indexed transparent color definition at index.

:param index:
    The index of the indexed transparent color you want to set.

:param value:
    The new value of the indexed transparent color you want to set.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_GetTransparentColor =R"doc(Returns access to indexed transparent color definition at index.

:param index:
    The index of the indexed transparent color you want to access.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_GetMaxTransparentColor =R"doc(Returns the maximum number of valid indexed colors (continuous tones)
this collection can contain.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_AddRgbTransparentColor =R"doc(Add a new RGB transparent color definition at the end of the
collection.

:param colorMin:
    Minimum RGB transparent color of the RGB cube you want to set.

:param colorMax:
    Maximum RGB transparent color of the RGB cube you want to set.

:param transparency:
    The transparency value of this RGB cube. [0, 255], 255 -> Opaque.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_SetRgbTransparentColor =R"doc(Set a new RGB transparent color definition at index.

:param index:
    The index of the RGB transparent color you want to set.

:param value:
    The new value of the RGB transparent color you want to set.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_GetRgbTransparentColor =R"doc(Returns access to RGB transparent color definition at index.

:param index:
    The index of the RGB transparent color you want to access.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_SetCount =R"doc(Set the number of valid colors in this collection.

:param count:
    Number of valid color in the collection.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_GetCount =R"doc(Returns the number of valid colors in this collection.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_SetColorType =R"doc(Set the TransparentColorType of this transparent colors collection.

:param colorType:
    The type of color in the collection.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_GetColorType =R"doc(Returns the TransparentColorType of this transparent colors
collection.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_Init =R"doc(Initialize an empty raster transparent colors collection instance.

:param colorType:
    The type of color in the transparentColor parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterTransparentColorsCollection_Clone =R"doc(Create an empty raster transparent colors collection instance.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClipProperties_SetMaskCollection =R"doc(Set a new clip mask properties.

:param clipMasksP:
    New RasterClipCollectionPtr or NULL to remove all clip masks.

Remark:
    Will take ownership of the clipMasks parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClipProperties_GetMaskCollection =R"doc(Return access to clip mask collection.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClipProperties_SetBoundary =R"doc(Set a new clip boundary property.

:param boundaryP:
    New RasterClipPtr or NULL to remove boundary.

Remark:
    Will take ownership of the boundaryP parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClipProperties_GetBoundary =R"doc(Return access to clip boundary. Might be invalid (empty))doc";

static const char * __doc_Bentley_DgnPlatform_RasterClipProperties_HasBoundary =R"doc(Return true if clip boundary is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClipProperties_Clone =R"doc(Clone the RasterClipProperties.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClip_ComputeStrokePoints =R"doc(Compute and returns the element handle stroke points for the current
raster clip.

:param strokePts:
    Vector that will be filled with computed stroke points (in
    Pixels).)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClip_Invalidate =R"doc(Set an empty (invalid) raster clip.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClip_IsValid =R"doc(Returns true if the current raster clip element handle is valid (will
NOT check the properties of the clip itself).)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClip_SetClipElement =R"doc(Set raster clip element handle.

:param clipEh:
    Element handle to create the clip from. Will be duplicate.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClip_GetClipElement =R"doc(Returns the element handle of the current raster clip.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterClip_Clone =R"doc(Clone the RasterClip.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IRasterAttachment(py::module_& m)
    {
    //===================================================================================
    // enum RasterDisplayPriorityPlane
    py::enum_< RasterDisplayPriorityPlane>(m, "RasterDisplayPriorityPlane", py::arithmetic())
        .value("eDisplayPriority_BackPlane", DisplayPriority_BackPlane)
        .value("eDisplayPriority_DesignPlane", DisplayPriority_DesignPlane)
        .value("eDisplayPriority_FrontPlane", DisplayPriority_FrontPlane)
        .export_values();

    //===================================================================================
    // enum GeoreferencePriority
    py::enum_< GeoreferencePriority>(m, "GeoreferencePriority", py::arithmetic())
        .value("eGeoreferencePriority_Default", GeoreferencePriority_Default)
        .value("eGeoreferencePriority_Attachment", GeoreferencePriority_Attachment)
        .value("eGeoreferencePriority_RasterFile", GeoreferencePriority_RasterFile)
        .value("eGeoreferencePriority_SisterFile", GeoreferencePriority_SisterFile)
        .export_values();        

    //===================================================================================
    // enum GeotiffUnitPriority
    py::enum_< GeotiffUnitPriority>(m, "GeotiffUnitPriority", py::arithmetic())
        .value("eGeotiffUnitPriority_PCS_Default", GeotiffUnitPriority_PCS_Default)
        .value("eGeotiffUnitPriority_PCS_Linear", GeotiffUnitPriority_PCS_Linear)
        .value("eGeotiffUnitPriority_Unknown", GeotiffUnitPriority_Unknown)
        .export_values();

    //===================================================================================
    // enum TransparentColorType
    py::enum_< TransparentColorType>(m, "TransparentColorType", py::arithmetic())
        .value("eTransparentColorType_Colordef", TransparentColorType_Colordef)
        .value("eTransparentColorType_CubeDef", TransparentColorType_CubeDef)
        .export_values();

    //===================================================================================
    // enum GeoCodingType
    py::enum_< GeoCodingType>(m, "GeoCodingType", py::arithmetic())
        .value("eGeoCodingType_None", GeoCodingType_None)
        .value("eGeoCodingType_Type66", GeoCodingType_Type66)
        .export_values();

   
    //===================================================================================
    // struct RasterClip
    py::class_< RasterClip, RasterClipPtr> c1(m, "RasterClip");
    py::bind_vector<bvector< RasterClipPtr>>(m, "RasterClipPtrArray", py::module_local(false));

    c1.def(py::init(py::overload_cast<>(&RasterClip::Create)));
    c1.def(py::init(py::overload_cast<ElementHandleCR>(&RasterClip::Create)), "clipEh"_a);
    c1.def(py::init([] (DPoint3dArray const& points, DgnModelRefR modelRef) { return RasterClip::Create(points.data(), points.size(), modelRef); }), "points"_a, "modelRef"_a);
    c1.def(py::init([](py::list const &points, DgnModelRefR modelRef)
                    {
                    CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d)
                    return RasterClip::Create(cppPoints.data(), cppPoints.size(), modelRef); }), "points"_a, "modelRef"_a);
    c1.def("Clone", &RasterClip::Clone, DOC(Bentley, DgnPlatform, RasterClip, Clone));
    
    c1.def_property("ClipElement",
                    py::cpp_function(&RasterClip::GetClipElement, py::return_value_policy::reference_internal),
                    py::cpp_function(&RasterClip::SetClipElement));
    c1.def("GetClipElement", &RasterClip::GetClipElement, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RasterClip, GetClipElement));
    c1.def("SetClipElement", &RasterClip::SetClipElement, "clipEh"_a, DOC(Bentley, DgnPlatform, RasterClip, SetClipElement));

    c1.def("IsValid", &RasterClip::IsValid, DOC(Bentley, DgnPlatform, RasterClip, IsValid));
    c1.def("Invalidate", &RasterClip::Invalidate, DOC(Bentley, DgnPlatform, RasterClip, Invalidate));
    c1.def("ComputeStrokePoints", &RasterClip::ComputeStrokePoints, "strokePts", py::keep_alive<0, 2>(), DOC(Bentley, DgnPlatform, RasterClip, ComputeStrokePoints));
    c1.def("__eq__", [] (RasterClipCR self, RasterClipCR other) { return self.IsEqual(other); });

    //===================================================================================
    // struct RasterClipCollection
    py::class_< RasterClipCollection, RasterClipCollectionPtr> c2(m, "RasterClipCollection", py::multiple_inheritance());

    c2.def(py::init(&RasterClipCollection::Create));
    c2.def("__len__", [] (RasterClipCollection const& self) { return self.size(); });    
    c2.def("__iter__", [] (RasterClipCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    
    c2.def("__getitem__", [] (RasterClipCollection const& self, size_t index)
           {
           if (index >= self.size())
               throw py::index_error();
           return self[index];
           });

    c2.def("__setitem__", [] (RasterClipCollection& self, size_t index, RasterClipP item)
           {
           if (index >= self.size())
               throw py::index_error();
           self[index] = RasterClipPtr(item);
           });

    c2.def("push_back", [] (RasterClipCollectionR self, RasterClipP item) { self.push_back(RasterClipPtr(item)); }, "item"_a);

    //===================================================================================
    // struct RasterClipProperties
    py::class_< RasterClipProperties, RasterClipPropertiesPtr> c3(m, "RasterClipProperties");

    c3.def(py::init(&RasterClipProperties::Create));
    c3.def("Clone", &RasterClipProperties::Clone, DOC(Bentley, DgnPlatform, RasterClipProperties, Clone));
    c3.def("HasBoundary", &RasterClipProperties::HasBoundary, DOC(Bentley, DgnPlatform, RasterClipProperties, HasBoundary));
    c3.def_property_readonly("Boundary", &RasterClipProperties::GetBoundaryR);
    c3.def("GetBoundary", &RasterClipProperties::GetBoundaryR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RasterClipProperties, GetBoundary));
    
    c3.def("SetBoundary", [] (RasterClipProperties& self, RasterClipP boundary)
           {
           RasterClipPtr boundaryPtr(boundary);
           self.SetBoundary(boundaryPtr);
           }, "boundary"_a, DOC(Bentley, DgnPlatform, RasterClipProperties, SetBoundary));

    c3.def_property_readonly("MaskCollection", &RasterClipProperties::GetMaskCollectionR);
    c3.def("GetMaskCollection", &RasterClipProperties::GetMaskCollectionR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RasterClipProperties, GetMaskCollection));

    c3.def("SetMaskCollection", [] (RasterClipProperties& self, RasterClipCollectionP clipMasks)
           { 
           RasterClipCollectionPtr collPtr(clipMasks);
           self.SetMaskCollection(collPtr); 
           }, "clipMasks"_a, DOC(Bentley, DgnPlatform, RasterClipProperties, SetMaskCollection));



    //===================================================================================
    // struct RasterTransparentColorsCollection
    py::class_< RasterTransparentColorsCollection, RasterTransparentColorsCollectionPtr> c6(m, "RasterTransparentColorsCollection");

    c6.def(py::init(py::overload_cast<>(&RasterTransparentColorsCollection::Create)));

    c6.def(py::init(py::overload_cast<TransparentColorType, long, RasterTransparentColorsCollection::RasterTransparentColorsUnion const&>(&RasterTransparentColorsCollection::Create)), 
           "colorType"_a, "count"_a, "transparentColor"_a);

    c6.def("Clone", &RasterTransparentColorsCollection::Clone, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, Clone));
    c6.def("Init", py::overload_cast<TransparentColorType>(&RasterTransparentColorsCollection::Init), "colorType"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, Init));

    c6.def("Init", py::overload_cast<TransparentColorType, long, RasterTransparentColorsCollection::RasterTransparentColorsUnion const&>(&RasterTransparentColorsCollection::Init), 
           "colorType"_a, "count"_a, "transparentColor"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, Init));

    c6.def_property("ColorType", &RasterTransparentColorsCollection::GetColorType, &RasterTransparentColorsCollection::SetColorType);
    c6.def("GetColorType", &RasterTransparentColorsCollection::GetColorType, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, GetColorType));
    c6.def("SetColorType", &RasterTransparentColorsCollection::SetColorType, "colorType"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, SetColorType));
    
    c6.def_property("Count", &RasterTransparentColorsCollection::GetCount, &RasterTransparentColorsCollection::SetCount);
    c6.def("GetCount", &RasterTransparentColorsCollection::GetCount, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, GetCount));
    c6.def("SetCount", &RasterTransparentColorsCollection::SetCount, "count"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, SetCount));
    
    c6.def_property_readonly("MaxRgbTransparentColor", &RasterTransparentColorsCollection::GetMaxRgbTransparentColor);
    c6.def("GetMaxRgbTransparentColor", &RasterTransparentColorsCollection::GetMaxRgbTransparentColor);
    
    c6.def("GetRgbTransparentColor", &RasterTransparentColorsCollection::GetRgbTransparentColor, "index"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, GetRgbTransparentColor));
    c6.def("SetRgbTransparentColor", &RasterTransparentColorsCollection::SetRgbTransparentColor, "index"_a, "value"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, SetRgbTransparentColor));
    c6.def("AddRgbTransparentColor", &RasterTransparentColorsCollection::AddRgbTransparentColor, "colorMin"_a, "colorMax"_a, "transparency"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, AddRgbTransparentColor));
    
    c6.def_property_readonly("MaxTransparentColor", &RasterTransparentColorsCollection::GetMaxTransparentColor);
    c6.def("GetMaxTransparentColor", &RasterTransparentColorsCollection::GetMaxTransparentColor, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, GetMaxTransparentColor));
    
    c6.def("GetTransparentColor", py::overload_cast<unsigned long>(&RasterTransparentColorsCollection::GetTransparentColor, py::const_), "index"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, GetTransparentColor));
    c6.def("SetTransparentColor", &RasterTransparentColorsCollection::SetTransparentColor, "index"_a, "value"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, SetTransparentColor));
    c6.def("AddTransparentColor", &RasterTransparentColorsCollection::AddTransparentColor, "index"_a, "tranparency"_a, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, AddTransparentColor));
    c6.def("GetTransparentColor", py::overload_cast<>(&RasterTransparentColorsCollection::GetTransparentColor, py::const_), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RasterTransparentColorsCollection, GetTransparentColor));
    c6.def("__eq__", [] (RasterTransparentColorsCollectionCR self, RasterTransparentColorsCollectionCR other) { return self.IsEqual(other); });


    //===================================================================================
    // struct IRasterAttachmentQuery
    py::class_< IRasterAttachmentQuery, std::unique_ptr< IRasterAttachmentQuery, py::nodelete> > c8(m, "IRasterAttachmentQuery");

    c8.def_static("IsValidTransform", &IRasterAttachmentQuery::IsValidTransform, "matrix"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, IsValidTransform));
    c8.def_static("IsTransform3D", &IRasterAttachmentQuery::IsTransform3D, "matrix"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, IsTransform3D));
    
    c8.def_static("ColorIndexFromRgbInModel", [] (DgnModelRefR modelRef, RgbColorDef const& rgbColor)
                  {
                  UInt32 index;
                  auto retVal = IRasterAttachmentQuery::ColorIndexFromRgbInModel(index, modelRef, rgbColor);
                  return py::make_tuple(retVal, index);
                  }, "modelRef"_a, "rgbColor"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, ColorIndexFromRgbInModel));

    c8.def_static("RgbFromColorIndexInModel", &IRasterAttachmentQuery::RgbFromColorIndexInModel, "color"_a, "modelRef"_a, "rawIndex"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, RgbFromColorIndexInModel));
    c8.def_static("GetSearchPath", &IRasterAttachmentQuery::GetSearchPath, "modelRef"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetSearchPath));
    c8.def("GetAttachMoniker", &IRasterAttachmentQuery::GetAttachMoniker, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetAttachMoniker));
    c8.def("GetAttachDescription", &IRasterAttachmentQuery::GetAttachDescription, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetAttachDescription));
    c8.def("GetLogicalName", &IRasterAttachmentQuery::GetLogicalName, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetLogicalName));
    c8.def("GetSnappableState", &IRasterAttachmentQuery::GetSnappableState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetSnappableState));
    c8.def("GetLockedState", &IRasterAttachmentQuery::GetLockedState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetLockedState));
    c8.def("GetViewIndependentState", &IRasterAttachmentQuery::GetViewIndependentState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetViewIndependentState));
    c8.def("GetOpenReadWrite", &IRasterAttachmentQuery::GetOpenReadWrite, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetOpenReadWrite));
    c8.def("GetGeoreferencePriority", &IRasterAttachmentQuery::GetGeoreferencePriority, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGeoreferencePriority));
    c8.def("GetGCSInheritedFromModelState", &IRasterAttachmentQuery::GetGCSInheritedFromModelState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGCSInheritedFromModelState));
    c8.def("GetTransform", &IRasterAttachmentQuery::GetTransform, "eh"_a, "matrix"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetTransform));
    c8.def("GetPageNumber", &IRasterAttachmentQuery::GetPageNumber, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetPageNumber));
    c8.def("GetColorMode", &IRasterAttachmentQuery::GetColorMode, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetColorMode));
    c8.def("GetExtent", &IRasterAttachmentQuery::GetExtent, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetExtent));
    c8.def("GetScanningResolution", &IRasterAttachmentQuery::GetScanningResolution, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetScanningResolution));
    c8.def("GetViewState", &IRasterAttachmentQuery::GetViewState, "eh"_a, "viewNumber"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetViewState));
    c8.def("GetInvertState", &IRasterAttachmentQuery::GetInvertState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetInvertState));
    c8.def("GetPrintState", &IRasterAttachmentQuery::GetPrintState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetPrintState));
    c8.def("GetClipState", &IRasterAttachmentQuery::GetClipState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetClipState));
    c8.def("GetTransparencyState", &IRasterAttachmentQuery::GetTransparencyState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetTransparencyState));
    c8.def("GetBinaryPrintInvertState", &IRasterAttachmentQuery::GetBinaryPrintInvertState, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetBinaryPrintInvertState));
    c8.def("GetDisplayPriorityPlane", &IRasterAttachmentQuery::GetDisplayPriorityPlane, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetDisplayPriorityPlane));
    c8.def("GetLayer", &IRasterAttachmentQuery::GetLayer, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetLayer));
    c8.def("GetViewGamma", &IRasterAttachmentQuery::GetViewGamma, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetViewGamma));
    c8.def("GetPrintGamma", &IRasterAttachmentQuery::GetPrintGamma, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetPrintGamma));
    c8.def("GetTintColor", &IRasterAttachmentQuery::GetTintColor, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetTintColor));
    c8.def("GetForegroundColor", &IRasterAttachmentQuery::GetForegroundColor, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetForegroundColor));
    c8.def("GetBackgroundColor", &IRasterAttachmentQuery::GetBackgroundColor, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetBackgroundColor));
    c8.def("GetContrast", &IRasterAttachmentQuery::GetContrast, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetContrast));
    c8.def("GetBrightness", &IRasterAttachmentQuery::GetBrightness, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetBrightness));
    c8.def("GetImageTransparencyLevel", &IRasterAttachmentQuery::GetImageTransparencyLevel, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetImageTransparencyLevel));
    c8.def("GetTransparentColors", &IRasterAttachmentQuery::GetTransparentColors, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetTransparentColors));
    c8.def("GetGeotiffUnit", &IRasterAttachmentQuery::GetGeotiffUnit, "eh"_a, "GeotiffUnit"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGeotiffUnit));
    c8.def("GetGeotiffDefaultUnitFactor", &IRasterAttachmentQuery::GetGeotiffDefaultUnitFactor, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGeotiffDefaultUnitFactor));
    c8.def("GetGeotiffUnitUseUOR", &IRasterAttachmentQuery::GetGeotiffUnitUseUOR, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGeotiffUnitUseUOR));
    c8.def("GetGeotiffUnitPriority", &IRasterAttachmentQuery::GetGeotiffUnitPriority, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGeotiffUnitPriority));
    c8.def("GetWorldFileUnit", &IRasterAttachmentQuery::GetWorldFileUnit, "eh"_a, "WorldFileUnit"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetWorldFileUnit));
    c8.def("GetWorldFileDefaultUnitFactor", &IRasterAttachmentQuery::GetWorldFileDefaultUnitFactor, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetWorldFileDefaultUnitFactor));
    c8.def("GetGeocoding", &IRasterAttachmentQuery::GetGeocoding, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetGeocoding));
    c8.def("GetClipProperties", &IRasterAttachmentQuery::GetClipProperties, "eh"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentQuery, GetClipProperties));
        
    //===================================================================================
    // struct IRasterAttachmentEdit
    py::class_< IRasterAttachmentEdit, std::unique_ptr< IRasterAttachmentEdit, py::nodelete>, IRasterAttachmentQuery> c9(m, "IRasterAttachmentEdit");

    c9.def_static("CreateRasterAttachment",
           &IRasterAttachmentEdit::CreateRasterAttachment,
           "eeh"_a, "templateEh"_a, "moniker"_a, "matrix"_a, "extentInUOR"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, CreateRasterAttachment));

    c9.def("SetAttachMoniker", &IRasterAttachmentEdit::SetAttachMoniker, "eeh"_a, "moniker"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetAttachMoniker));
    c9.def_static("SetAttachMoniker0", &IRasterAttachmentEdit::SetAttachMoniker0, "eeh"_a, "moniker"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetAttachMoniker0));
    c9.def("SetAttachDescription", &IRasterAttachmentEdit::SetAttachDescription, "eeh"_a, "description"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetAttachDescription));

    c9.def("SetLogicalName", &IRasterAttachmentEdit::SetLogicalName, "eeh"_a, "logicalName"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetLogicalName));
    c9.def("SetSnappableState", &IRasterAttachmentEdit::SetSnappableState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetSnappableState));
    c9.def("SetLockedState", &IRasterAttachmentEdit::SetLockedState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetLockedState));
    c9.def("SetViewIndependentState", py::overload_cast<EditElementHandleR, bool>(&IRasterAttachmentEdit::SetViewIndependentState), "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetViewIndependentState));
    c9.def("SetOpenReadWrite", &IRasterAttachmentEdit::SetOpenReadWrite, "eeh"_a, "isWritable"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetOpenReadWrite));
    c9.def("SetGeoreferencePriority", &IRasterAttachmentEdit::SetGeoreferencePriority, "eeh"_a, "priority"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGeoreferencePriority));
    c9.def("SetGCSInheritedFromModelState", py::overload_cast<EditElementHandleR, bool>(&IRasterAttachmentEdit::SetGCSInheritedFromModelState), "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGCSInheritedFromModelState));
    c9.def("SetTransform", py::overload_cast<EditElementHandleR, TransformCR>(&IRasterAttachmentEdit::SetTransform), "eeh"_a, "matrix"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetTransform));
    c9.def("SetPageNumber", &IRasterAttachmentEdit::SetPageNumber, "eeh"_a, "page"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetPageNumber));
    c9.def("SetColorMode", &IRasterAttachmentEdit::SetColorMode, "eeh"_a, "colorMode"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetColorMode));
    c9.def("SetScanningResolution", &IRasterAttachmentEdit::SetScanningResolution, "eeh"_a, "scanningResolutionDPI"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetScanningResolution));
    c9.def("SetViewState", &IRasterAttachmentEdit::SetViewState, "eeh"_a, "viewNumber"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetViewState));
    c9.def("SetInvertState", &IRasterAttachmentEdit::SetInvertState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetInvertState));
    c9.def("SetPrintState", &IRasterAttachmentEdit::SetPrintState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetPrintState));
    c9.def("SetClipState", &IRasterAttachmentEdit::SetClipState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetClipState));
    c9.def("SetTransparencyState", &IRasterAttachmentEdit::SetTransparencyState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetTransparencyState));
    c9.def("SetBinaryPrintInvertState", &IRasterAttachmentEdit::SetBinaryPrintInvertState, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetBinaryPrintInvertState));
    c9.def("SetDisplayPriorityPlane", &IRasterAttachmentEdit::SetDisplayPriorityPlane, "eeh"_a, "plane"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetDisplayPriorityPlane));
    c9.def("SetLayer", &IRasterAttachmentEdit::SetLayer, "eeh"_a, "layer"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetLayer));
    c9.def("SetViewGamma", &IRasterAttachmentEdit::SetViewGamma, "eeh"_a, "gamma"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetViewGamma));
    c9.def("SetPrintGamma", &IRasterAttachmentEdit::SetPrintGamma, "eeh"_a, "gamma"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetPrintGamma));
    c9.def("SetTintColor", &IRasterAttachmentEdit::SetTintColor, "eeh"_a, "rawColorIndex"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetTintColor));
    c9.def("SetForegroundColor", &IRasterAttachmentEdit::SetForegroundColor, "eeh"_a, "rawColorIndex"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetForegroundColor));
    c9.def("SetBackgroundColor", &IRasterAttachmentEdit::SetBackgroundColor, "eeh"_a, "rawColorIndex"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetBackgroundColor));
    c9.def("SetContrast", &IRasterAttachmentEdit::SetContrast, "eeh"_a, "contrast"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetContrast));
    c9.def("SetBrightness", &IRasterAttachmentEdit::SetBrightness, "eeh"_a, "brightness"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetBrightness));
    c9.def("SetImageTransparencyLevel", &IRasterAttachmentEdit::SetImageTransparencyLevel, "eeh"_a, "transparency"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetImageTransparencyLevel));
    c9.def("SetTransparentColors", &IRasterAttachmentEdit::SetTransparentColors, "eeh"_a, "rasterTransparentColors"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetTransparentColors));
    c9.def("SetGeotiffUnit", &IRasterAttachmentEdit::SetGeotiffUnit, "eeh"_a, "GeotiffUnit"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGeotiffUnit));
    c9.def("SetGeotiffDefaultUnitFactor", &IRasterAttachmentEdit::SetGeotiffDefaultUnitFactor, "eeh"_a, "factor"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGeotiffDefaultUnitFactor));
    c9.def("SetGeotiffUnitUseUOR", &IRasterAttachmentEdit::SetGeotiffUnitUseUOR, "eeh"_a, "useUOR"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGeotiffUnitUseUOR));
    c9.def("SetGeotiffUnitPriority", &IRasterAttachmentEdit::SetGeotiffUnitPriority, "eeh"_a, "priority"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGeotiffUnitPriority));
    c9.def("SetWorldFileUnit", &IRasterAttachmentEdit::SetWorldFileUnit, "eeh"_a, "worldFileUnit"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetWorldFileUnit));
    c9.def("SetWorldFileDefaultUnitFactor", &IRasterAttachmentEdit::SetWorldFileDefaultUnitFactor, "eeh"_a, "factor"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetWorldFileDefaultUnitFactor));
    c9.def("SetGeocoding", py::overload_cast<EditElementHandleR, ElementHandleCR>(&IRasterAttachmentEdit::SetGeocoding), "eeh"_a, "geocoding"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetGeocoding));
    c9.def("SetClipProperties", &IRasterAttachmentEdit::SetClipProperties, "eeh"_a, "clipProperties"_a, DOC(Bentley, DgnPlatform, IRasterAttachmentEdit, SetClipProperties));
    }