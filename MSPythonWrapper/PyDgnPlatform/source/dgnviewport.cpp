/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnviewport.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnViewport.h>

static const char * __doc_Bentley_DgnPlatform_Viewport_ComputeDisplayedModelRefRange =R"doc(Compute range of a model ref when display in the viewport)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_ComputeFittedElementRange =R"doc(Compute the range of the element when displayed in the viewport)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_SynchWithViewInfo =R"doc(Synchronizes the view information that is displayed with this
viewport. Optionally add an entry in the view undo stack and update
the view title.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_Scroll =R"doc(@name Changing Viewport Frustum Scroll the Viewport by a given number
of pixels in the view's X and/or Y direction. This method will move
the Viewport's frustum in the indicated direction, but does *not*
update the screen (even if the Viewport happens to be a visible View.)
This method does change the ViewInfo associated with the Viewport.

:param viewDist:
    The distance to scroll, in pixels. @note To update the view, see
    IViewManager::UpdateView or IViewManager::UpdateViewDynamic. To
    save the change to the ViewInfo in the view undo buffer, see
    SynchWithViewInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetPixelSizeAtPoint =R"doc(Get the size of a single pixel at a given point as a distance along
the view-x axis. The size of a pixel will only differ at different
points within the same Viewport if the camera is on for this Viewport
(in which case, points closer to the eye return larger values than
ones further from the eye.)

:param rootPt:
    The point in DgnCoordSystem::Root for determining pixel size. If
    NULL, use the center of the Viewport.

:param coordSys:
    The coordinate system for the returned distance.

:returns:
    the size of the pixel at point ``rootPt.``)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetViewFlags =R"doc(Get the current View Flags for this Viewport.

:returns:
    the View flags for this Viewport.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetViewDelta =R"doc(Get the View Delta (size) of this Viewport in root coordinate
distances.

:returns:
    the view delta in root coordinate distances.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetViewOrigin =R"doc(Get View Origin for this Viewport.

:returns:
    the root coordinates of the lower left back corner of the
    Viewport.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetScreenNumber =R"doc(Get the screen number on which this Viewport resides.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetViewNumber =R"doc(Get the view number of this Viewport. If this Viewport is one of the 8
MicroStation numbered views (i.e. " View 1 " through " View 8 "), then
return the index of view number (e.g. " View 1 " is view index 0, " View 8 " is view index 7). If the Viewport is not one of the 8 MicroStation
numbered views, this method will return -1.

:returns:
    the view index of this Viewport, or -1 if it is not one of the
    numbered views.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_SetNeedsRefresh =R"doc(Sets the flag indicating that the Viewport needs to be refreshed from
the backing store at the next opportunity. When the Viewport is
refreshed, the view decorators are redrawn.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetICachedDraw =R"doc(Gets the object required for advanced cached drawing to the Viewport.
Cached Drawing is seldom required by applications.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetIViewOutput =R"doc(Gets the object required for advanced immediate drawing to the
Viewport. IViewOutput is a subclass of IViewDraw, and generally only
IViewDraw is needed.)doc";

static const char * __doc_Bentley_DgnPlatform_Viewport_GetIViewDraw =R"doc(Gets the object required for immediate drawing to the Viewport. The
methods on IViewDraw can be used to draw View Decorators.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyAnnotationAttachment =R"doc(Sets whether to apply an Annotation Attachment.

:param state:
    True to apply the source view annotation attachment.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetAnnotationAttachmentDrawingIndex =R"doc(Sets the Drawing Index for an Annotation Attachment.

:param index:
    The Drawing Index for the Annotation Attachment.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetAnnotationAttachmentDrawingIndex =R"doc(Gets the Drawing Index for an Annotation Attachment.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyRightIsoCameraPosition =R"doc(Sets whether the viewing angle is to be set to Right Isometric.

:param state:
    True to set destination view root to Right Isometric.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyRightIsoCameraPosition =R"doc(Gets whether the viewing angle is to be set to Right Isometric.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyClipWithoutBoundary =R"doc(Sets whether clipping is to be applied without using the boundary.

:param state:
    True to apply the source view clip without using its clip
    boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyClipWithoutBoundary =R"doc(Gets whether clipping is to be applied without using the boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetCreateNamedViewDisplayableForClipping =R"doc(Sets whether the displayable element for the named view is to be
created and used for clipping.

:param state:
    True to make apply create a named view displayable and use it for
    clippint.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetCreateNamedViewDisplayableForClipping =R"doc(Gets whether the displayable element for the named view is to be
created and used for clipping.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyModel =R"doc(Sets whether the root model from the source view is to be used in the
destination view.

:param state:
    True to make source view root model the root model for the
    destination view.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyModel =R"doc(Gets whether the root model from the source view is to be used in the
destination view.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyClipVolume =R"doc(Sets whether the view clip volume is applied.

:param state:
    True to apply the source view clip volume.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyClipVolume =R"doc(Gets whether the view clip volume is applied.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyRefLevels =R"doc(Sets whether the view level masks are applied to DgnAttachment
reference models.

:param state:
    True to apply the source view DgnAttachment reference level masks.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyRefLevels =R"doc(Gets whether the view level masks are applied to DgnAttachment
reference models.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyLevels =R"doc(Sets whether the view level masks are applied to the root model.

:param state:
    True to apply the source view root model level mask.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyLevels =R"doc(Gets whether the view level masks are applied to the root model.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyAttributes =R"doc(Sets whether the view attributes are applied.

:param state:
    True to apply the source view attributes.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyAttributes =R"doc(Gets whether the view attributes are applied.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetApplyVolume =R"doc(Sets whether the view volume is applied.

:param state:
    True to apply the source view volume.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetApplyVolume =R"doc(Gets whether the view volume is applied.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_SetViewportResizeMode =R"doc(Sets the current ViewportResizeMode.

:param mode:
    The ViewportResizeMode to apply.)doc";

static const char * __doc_Bentley_DgnPlatform_ApplyViewOptions_GetViewportResizeMode =R"doc(Gets the current ViewportResizeMode.)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnViewport(py::module_& m)
    {
    //===================================================================================
    // enum class ViewportResizeMode
    py::enum_< ViewportResizeMode>(m, "ViewportResizeMode")
        .value("eKeepCurrent", ViewportResizeMode::KeepCurrent)
        .value("eRelativeRect", ViewportResizeMode::RelativeRect)
        .value("eAspectRatio", ViewportResizeMode::AspectRatio)
        .value("eSize", ViewportResizeMode::Size)
        .value("eSizeAndPosition", ViewportResizeMode::SizeAndPosition)
        .export_values();
    
    //===================================================================================
    // struct FitViewParams
    py::class_< FitViewParams> c1(m, "FitViewParams");

    if (true)
        {
        //===================================================================================
        // enum FitModes
        py::enum_< FitViewParams::FitModes>(c1, "FitModes", py::arithmetic())
            .value("eFITMODE_All", FitViewParams::FITMODE_All)
            .value("eFITMODE_Active", FitViewParams::FITMODE_Active)
            .value("eFITMODE_Reference", FitViewParams::FITMODE_Reference)
            .value("eFITMODE_Raster", FitViewParams::FITMODE_Raster)
            .export_values();
        }

    c1.def(py::init<ViewportP>(), "vp"_a);
    c1.def("SetupFitList", &FitViewParams::SetupFitList, "fitModes"_a);

    //===================================================================================
    // struct ApplyViewOptions
    py::class_< ApplyViewOptions> c2(m, "ApplyViewOptions");

    c2.def(py::init<bool>(), "initFromActive"_a);

    c2.def_property("ViewportResizeMode", &ApplyViewOptions::GetViewportResizeMode, &ApplyViewOptions::SetViewportResizeMode);
    c2.def("GetViewportResizeMode", &ApplyViewOptions::GetViewportResizeMode, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetViewportResizeMode));
    c2.def("SetViewportResizeMode", &ApplyViewOptions::SetViewportResizeMode, "mode"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetViewportResizeMode));
    
    c2.def_property("ApplyVolume", &ApplyViewOptions::GetApplyVolume, &ApplyViewOptions::SetApplyVolume);
    c2.def("GetApplyVolume", &ApplyViewOptions::GetApplyVolume, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyVolume));
    c2.def("SetApplyVolume", &ApplyViewOptions::SetApplyVolume, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyVolume));
    
    c2.def_property("ApplyAttributes", &ApplyViewOptions::GetApplyAttributes, &ApplyViewOptions::SetApplyAttributes);
    c2.def("GetApplyAttributes", &ApplyViewOptions::GetApplyAttributes, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyAttributes));
    c2.def("SetApplyAttributes", &ApplyViewOptions::SetApplyAttributes, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyAttributes));
    
    c2.def_property("ApplyLevels", &ApplyViewOptions::GetApplyLevels, &ApplyViewOptions::SetApplyLevels);
    c2.def("GetApplyLevels", &ApplyViewOptions::GetApplyLevels, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyLevels));
    c2.def("SetApplyLevels", &ApplyViewOptions::SetApplyLevels, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyLevels));
    
    c2.def_property("ApplyRefLevels", &ApplyViewOptions::GetApplyRefLevels, &ApplyViewOptions::SetApplyRefLevels);
    c2.def("GetApplyRefLevels", &ApplyViewOptions::GetApplyRefLevels, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyRefLevels));
    c2.def("SetApplyRefLevels", &ApplyViewOptions::SetApplyRefLevels, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyRefLevels));
    
    c2.def_property("ApplyClipVolume", &ApplyViewOptions::GetApplyClipVolume, &ApplyViewOptions::SetApplyClipVolume);
    c2.def("GetApplyClipVolume", &ApplyViewOptions::GetApplyClipVolume, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyClipVolume));
    c2.def("SetApplyClipVolume", &ApplyViewOptions::SetApplyClipVolume, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyClipVolume));
    
    c2.def_property("ApplyModel", &ApplyViewOptions::GetApplyModel, &ApplyViewOptions::SetApplyModel);
    c2.def("GetApplyModel", &ApplyViewOptions::GetApplyModel, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyModel));
    c2.def("SetApplyModel", &ApplyViewOptions::SetApplyModel, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyModel));
    
    c2.def_property("CreateNamedViewDisplayableForClipping", &ApplyViewOptions::GetCreateNamedViewDisplayableForClipping, &ApplyViewOptions::SetCreateNamedViewDisplayableForClipping);
    c2.def("GetCreateNamedViewDisplayableForClipping", &ApplyViewOptions::GetCreateNamedViewDisplayableForClipping, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetCreateNamedViewDisplayableForClipping));
    c2.def("SetCreateNamedViewDisplayableForClipping", &ApplyViewOptions::SetCreateNamedViewDisplayableForClipping, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetCreateNamedViewDisplayableForClipping));
    
    c2.def_property("ApplyClipWithoutBoundary", &ApplyViewOptions::GetApplyClipWithoutBoundary, &ApplyViewOptions::SetApplyClipWithoutBoundary);
    c2.def("GetApplyClipWithoutBoundary", &ApplyViewOptions::GetApplyClipWithoutBoundary, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyClipWithoutBoundary));
    c2.def("SetApplyClipWithoutBoundary", &ApplyViewOptions::SetApplyClipWithoutBoundary, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyClipWithoutBoundary));
    
    c2.def_property("ApplyRightIsoCameraPosition", &ApplyViewOptions::GetApplyRightIsoCameraPosition, &ApplyViewOptions::SetApplyRightIsoCameraPosition);
    c2.def("GetApplyRightIsoCameraPosition", &ApplyViewOptions::GetApplyRightIsoCameraPosition, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetApplyRightIsoCameraPosition));
    c2.def("SetApplyRightIsoCameraPosition", &ApplyViewOptions::SetApplyRightIsoCameraPosition, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyRightIsoCameraPosition));
    
    c2.def_property("AnnotationAttachmentDrawingIndex", &ApplyViewOptions::GetAnnotationAttachmentDrawingIndex, &ApplyViewOptions::SetAnnotationAttachmentDrawingIndex);
    c2.def("GetAnnotationAttachmentDrawingIndex", &ApplyViewOptions::GetAnnotationAttachmentDrawingIndex, DOC(Bentley, DgnPlatform, ApplyViewOptions, GetAnnotationAttachmentDrawingIndex));
    c2.def("SetAnnotationAttachmentDrawingIndex", &ApplyViewOptions::SetAnnotationAttachmentDrawingIndex, "index"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetAnnotationAttachmentDrawingIndex));
    
    c2.def("SetApplyAnnotationAttachment", &ApplyViewOptions::SetApplyAnnotationAttachment, "state"_a, DOC(Bentley, DgnPlatform, ApplyViewOptions, SetApplyAnnotationAttachment));
    c2.def("SetApplyAll", &ApplyViewOptions::SetApplyAll, "state"_a);

    //===================================================================================
    // struct Viewport
    py::class_<Viewport> c3(m, "Viewport");


    c3.def_property_readonly("IViewDraw", &Viewport::GetIViewDraw);
    c3.def("GetIViewDraw", &Viewport::GetIViewDraw, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Viewport, GetIViewDraw));

    c3.def_property_readonly("IViewOutput", &Viewport::GetIViewOutput);
    c3.def("GetIViewOutput", &Viewport::GetIViewOutput, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Viewport, GetIViewOutput));

    c3.def_property_readonly("ICachedDraw", &Viewport::GetICachedDraw);
    c3.def("GetICachedDraw", &Viewport::GetICachedDraw, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Viewport, GetICachedDraw));

    c3.def("SetNeedsRefresh", &Viewport::SetNeedsRefresh, DOC(Bentley, DgnPlatform, Viewport, SetNeedsRefresh));
    
    c3.def_property_readonly("RotMatrix", &Viewport::GetRotMatrix);
    c3.def("GetRotMatrix", &Viewport::GetRotMatrix, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("Scale", &Viewport::GetScale);
    c3.def("GetScale", &Viewport::GetScale);
    
    c3.def_property_readonly("ActiveZRoot", &Viewport::GetActiveZRoot);
    c3.def("GetActiveZRoot", &Viewport::GetActiveZRoot);
    
    c3.def("GetCameraView", &Viewport::GetCameraView, "camera"_a);
    c3.def("GetCameraTarget", &Viewport::GetCameraTarget, "target"_a);
    
    c3.def_property_readonly("CameraRoot", &Viewport::GetCameraRoot);
    c3.def("GetCameraRoot", &Viewport::GetCameraRoot, py::return_value_policy::reference_internal);
    
    c3.def("GetClipBoundElemHandle", &Viewport::GetClipBoundElemHandle, "eeh"_a);
    c3.def("GetClipMaskElemHandle", &Viewport::GetClipMaskElemHandle, "eeh"_a);
    
    c3.def_property_readonly("ClipBoundElementRef", &Viewport::GetClipBoundElementRef);
    c3.def("GetClipBoundElementRef", &Viewport::GetClipBoundElementRef, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("ClipMaskElementRef", &Viewport::GetClipMaskElementRef);
    c3.def("GetClipMaskElementRef", &Viewport::GetClipMaskElementRef, py::return_value_policy::reference_internal);
    
    c3.def("SetTemporaryClipElementRef", &Viewport::SetTemporaryClipElementRef, "element"_a);
    c3.def("SetTemporaryClipMaskElementRef", &Viewport::SetTemporaryClipMaskElementRef, "element"_a);
    
    c3.def_property_readonly("RootToViewMap", &Viewport::GetRootToViewMap);
    c3.def("GetRootToViewMap", &Viewport::GetRootToViewMap, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("RootToNpcMap", &Viewport::GetRootToNpcMap);
    c3.def("GetRootToNpcMap", &Viewport::GetRootToNpcMap, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("ActiveToRootMap", &Viewport::GetActiveToRootMap);
    c3.def("GetActiveToRootMap", &Viewport::GetActiveToRootMap, py::return_value_policy::reference_internal);
    
    c3.def("GetIndexedLineWidth", &Viewport::GetIndexedLineWidth, "index"_a);
    c3.def("GetIndexedLinePattern", &Viewport::GetIndexedLinePattern, "index"_a);
    
    c3.def_property_readonly("BackgroundColor", &Viewport::GetBackgroundColor);
    c3.def("GetBackgroundColor", &Viewport::GetBackgroundColor);
    
    c3.def_property_readonly("ContrastToBackgroundColor", &Viewport::GetContrastToBackgroundColor);
    c3.def("GetContrastToBackgroundColor", &Viewport::GetContrastToBackgroundColor);
    
    c3.def("AdjustColorForContrast", &Viewport::AdjustColorForContrast, "thisColor"_a, "againstColor"_a);
    c3.def_static("MakeTrgbColor", &Viewport::MakeTrgbColor, "red"_a, "green"_a, "blue"_a, "transparency"_a);
    c3.def_static("MakeColorTransparency", &Viewport::MakeColorTransparency, "color"_a, "transparency"_a);
    c3.def_static("MakeTransparentIfOpaque", &Viewport::MakeTransparentIfOpaque, "color"_a, "transparency"_a);
    c3.def("ResynchColorMap", &Viewport::ResynchColorMap);

    c3.def_property_readonly("HiliteColor", py::overload_cast<>(&Viewport::GetHiliteColor, py::const_));
    c3.def("GetHiliteColor", py::overload_cast<>(&Viewport::GetHiliteColor, py::const_));
    
    c3.def("GetHiliteColorFromPath", py::overload_cast<DisplayPathCP>(&Viewport::GetHiliteColor, py::const_), "path"_a);
    c3.def("SetSymbologyRgb", &Viewport::SetSymbologyRgb, "lineColorTBGR"_a, "fillColorTBGR"_a, "lineWidth"_a, "lineColorIndex"_a);
    
    c3.def("GetViewBox", [] (Viewport const& self, DPoint3dArray& pts, DgnCoordSystem sys, bool adjustedBox)
           {
           if (pts.size() < 8)
               pts.resize(8);

           self.GetViewBox(&pts[0], sys, adjustedBox);
           }, "points"_a, "sys"_a, "adjustedBox"_a);

    c3.def("GetViewBox", [] (Viewport const& self, py::list& pts, DgnCoordSystem sys, bool adjustedBox)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(pts, cppPts, DPoint3dArray, DPoint3d);
           if (cppPts.size() < 8)
               cppPts.resize(8);
          
           self.GetViewBox(&cppPts[0], sys, adjustedBox);
           CONVERT_CPPARRAY_TO_PYLIST(pts, cppPts, DPoint3dArray, DPoint3d);
           }, "points"_a, "sys"_a, "adjustedBox"_a);

    c3.def("GetViewRect", &Viewport::GetViewRect, "rect"_a);
    c3.def("GetViewCorners", &Viewport::GetViewCorners, "low"_a, "high"_a);
    
    c3.def("NpcToView", [] (Viewport const& self, DPoint3dArray& viewPts, DPoint3dArray const& npcPts)
           {
           if (!npcPts.empty())
               {
               if (viewPts.size() < npcPts.size())
                   viewPts.resize(npcPts.size());
               self.NpcToView(&viewPts[0], &npcPts[0], (int) npcPts.size());
               }
           }, "viewPts"_a, "npcPts"_a);

    c3.def("NpcToView", [] (Viewport const& self, py::list& viewPts, py::list const& npcPts)
           {
           if (!npcPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
               if (cppViewPts.size() < cppNpcPts.size())
                   cppViewPts.resize(cppNpcPts.size());
               self.NpcToView(&cppViewPts[0], &cppNpcPts[0], (int) cppNpcPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);    
               }
           }, "viewPts"_a, "npcPts"_a);

    c3.def("NpcToView", [] (Viewport const& self, DPoint3d& viewPt, DPoint3d const& npcPt)
           {
           self.NpcToView(&viewPt, &npcPt, 1);               
           }, "viewPt"_a, "npcPt"_a);

    c3.def("ViewToNpc", [] (Viewport const& self, DPoint3dArray& npcPts, DPoint3dArray const& viewPts)
           {
           if (!viewPts.empty())
               {
               if (npcPts.size() < viewPts.size())
                   npcPts.resize(viewPts.size());
               self.ViewToNpc(&npcPts[0], &viewPts[0], (int) viewPts.size());
               }
           }, "npcPts"_a, "viewPts"_a);

    c3.def("ViewToNpc", [] (Viewport const& self, py::list& npcPts, py::list const& viewPts)
           {
           if (!viewPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               if (cppNpcPts.size() < cppViewPts.size())
                   cppNpcPts.resize(cppViewPts.size());
               self.ViewToNpc(&cppNpcPts[0], &cppViewPts[0], (int) cppViewPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
               }
           }, "npcPts"_a, "viewPts"_a);

    c3.def("ViewToNpc", [] (Viewport const& self, DPoint3d& npcPt, DPoint3d const& viewPt)
           {
           self.ViewToNpc(&npcPt, &viewPt, 1);
           }, "npcPt"_a, "viewPt"_a);

    c3.def("NpcToRoot", [] (Viewport const& self, DPoint3dArray& rootPts, DPoint3dArray const& npcPts)
           {
           if (!npcPts.empty())
               {
               if (rootPts.size() < npcPts.size())
                   rootPts.resize(npcPts.size());
               self.NpcToRoot(&rootPts[0], &npcPts[0], (int) npcPts.size());
               }
           }, "rootPts"_a, "npcPts"_a);

    c3.def("NpcToRoot", [] (Viewport const& self, py::list& rootPts, py::list const& npcPts)
           {
           if (!npcPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
               if (cppRootPts.size() < cppNpcPts.size())
                    cppRootPts.resize(cppNpcPts.size());
               self.NpcToRoot(&cppRootPts[0], &cppNpcPts[0], (int) cppNpcPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               }
           }, "rootPts"_a, "npcPts"_a);

    c3.def("NpcToRoot", [] (Viewport const& self, DPoint3d& rootPt, DPoint3d const& npcPt)
           {
           self.NpcToRoot(&rootPt, &npcPt, 1);
           }, "rootPt"_a, "npcPt"_a);

    c3.def("RootToNpc", [] (Viewport const& self, DPoint3dArray& npcPts, DPoint3dArray const& rootPts)
           {
           if (!rootPts.empty())
               {
               if (npcPts.size() < rootPts.size())
                   npcPts.resize(rootPts.size());
               self.RootToNpc(&npcPts[0], &rootPts[0], (int) rootPts.size());
               }
           }, "npcPts"_a, "rootPts"_a);

    c3.def("RootToNpc", [] (Viewport const& self, py::list& npcPts, py::list const& rootPts)
           {
           if (!rootPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               if (cppNpcPts.size() < cppRootPts.size())
                   cppNpcPts.resize(cppRootPts.size());
               self.RootToNpc(&cppNpcPts[0], &cppRootPts[0], (int) cppRootPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(npcPts, cppNpcPts, DPoint3dArray, DPoint3d);
               }
           }, "npcPts"_a, "rootPts"_a);

    c3.def("RootToNpc", [] (Viewport const& self, DPoint3d& npcPt, DPoint3d const& rootPt)
           {
           self.RootToNpc(&npcPt, &rootPt, 1);
           }, "npcPt"_a, "rootPt"_a);

    c3.def("RootToView", [] (Viewport const& self, DPoint4dArray& viewPts, DPoint3dArray const& rootPts)
           {
           if (!rootPts.empty())
               {
               if (viewPts.size() < rootPts.size())
                   viewPts.resize(rootPts.size());
               self.RootToView(&viewPts[0], &rootPts[0], (int) rootPts.size());
               }
           }, "viewPts"_a, "rootPts"_a);

    c3.def("RootToView", [] (Viewport const& self, DPoint4dArray& viewPts, py::list const& rootPts)
           {
           if (!rootPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               if (viewPts.size() < cppRootPts.size())
                   viewPts.resize(cppRootPts.size());
               self.RootToView(&viewPts[0], &cppRootPts[0], (int) cppRootPts.size());
               }
           }, "viewPts"_a, "rootPts"_a);

    c3.def("RootToView", [] (Viewport const& self, DPoint4d& viewPt, DPoint3d const& rootPt)
           {
           self.RootToView(&viewPt, &rootPt, 1);
           }, "viewPt"_a, "rootPt"_a);

    c3.def("ViewToRoot", [] (Viewport const& self, DPoint3dArray& rootPts, DPoint4dArray const& viewPts)
           {
           if (!viewPts.empty())
               {
               if (rootPts.size() < viewPts.size())
                   rootPts.resize(viewPts.size());
               self.ViewToRoot(&rootPts[0], &viewPts[0], (int) viewPts.size());
               }
           }, "rootPts"_a, "npcPts"_a);

    c3.def("ViewToRoot", [] (Viewport const& self, py::list& rootPts, DPoint4dArray const& viewPts)
           {
           if (!viewPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               if (cppRootPts.size() < viewPts.size())
                   cppRootPts.resize(viewPts.size());
               self.ViewToRoot(&cppRootPts[0], &viewPts[0], (int) viewPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               }
           }, "rootPts"_a, "npcPts"_a);

    c3.def("ViewToRoot", [] (Viewport const& self, DPoint3d& rootPt, DPoint4d const& viewPt)
           {
           self.ViewToRoot(&rootPt, &viewPt, 1);
           }, "rootPt"_a, "npcPt"_a);

    c3.def("RootToView", [] (Viewport const& self, DPoint3dArray& viewPts, DPoint3dArray const& rootPts)
           {
           if (!rootPts.empty())
               {
               if (viewPts.size() < rootPts.size())
                   viewPts.resize(rootPts.size());
               self.RootToView(&viewPts[0], &rootPts[0], (int) rootPts.size());
               }
           }, "viewPts"_a, "rootPts"_a);

    c3.def("RootToView", [] (Viewport const& self, py::list& viewPts, py::list const& rootPts)
           {
           if (!rootPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               if (cppViewPts.size() < cppRootPts.size())
                   cppViewPts.resize(cppRootPts.size());
               self.RootToView(&cppViewPts[0], &cppRootPts[0], (int) cppRootPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               }
           }, "viewPts"_a, "rootPts"_a);

    c3.def("RootToView", [] (Viewport const& self, DPoint3d& viewPt, DPoint3d const& rootPt)
           {
           self.RootToView(&viewPt, &rootPt, 1);
           }, "viewPt"_a, "rootPt"_a);

    c3.def("RootToView2d", [] (Viewport const& self, DPoint2dArray& viewPts, DPoint3dArray const& rootPts)
           {
           if (!rootPts.empty())
               {
               if (viewPts.size() < rootPts.size())
                   viewPts.resize(rootPts.size());
               self.RootToView2d(&viewPts[0], &rootPts[0], (int) rootPts.size());
               }
           }, "viewPts"_a, "rootPts"_a);

    c3.def("RootToView2d", [] (Viewport const& self, DPoint2dArray& viewPts, py::list const& rootPts)
           {
           if (!rootPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               if (viewPts.size() < cppRootPts.size())
                   viewPts.resize(cppRootPts.size());
               self.RootToView2d(&viewPts[0], &cppRootPts[0], (int) cppRootPts.size());
               }
           }, "viewPts"_a, "rootPts"_a);

    c3.def("RootToView2d", [] (Viewport const& self, DPoint2d& viewPt, DPoint3d const& rootPt)
           {
           self.RootToView2d(&viewPt, &rootPt, 1);
           }, "viewPt"_a, "rootPt"_a);

    c3.def("ViewToRoot", [] (Viewport const& self, DPoint3dArray& rootPts, DPoint3dArray const& viewPts)
           {
           if (!viewPts.empty())
               {
               if (rootPts.size() < viewPts.size())
                   rootPts.resize(viewPts.size());
               self.ViewToRoot(&rootPts[0], &viewPts[0], (int) viewPts.size());
               }
           }, "rootPts"_a, "npcPts"_a);

    c3.def("ViewToRoot", [] (Viewport const& self, py::list& rootPts, py::list const& viewPts)
           {
           if (!viewPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               if (cppRootPts.size() < cppViewPts.size())
                   cppRootPts.resize(cppViewPts.size());
               self.ViewToRoot(&cppRootPts[0], &cppViewPts[0], (int) cppViewPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               }
           }, "rootPts"_a, "npcPts"_a);
    c3.def("ViewToRoot", [] (Viewport const& self, DPoint3d& rootPt, DPoint3d const& viewPt)
           {
           self.ViewToRoot(&rootPt, &viewPt, 1);
           }, "rootPt"_a, "npcPt"_a);

    c3.def("ActiveToView", [] (Viewport const& self, DPoint3dArray& viewPts, DPoint3dArray const& activePts)
           {
           if (!activePts.empty())
               {
               if (viewPts.size() < activePts.size())
                   viewPts.resize(activePts.size());
               self.ActiveToView(&viewPts[0], &activePts[0], (int) activePts.size());
               }
           }, "viewPts"_a, "activePts"_a);

    c3.def("ActiveToView", [] (Viewport const& self, py::list& viewPts, py::list const& activePts)
           {
           if (!activePts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(activePts, cppActivePts, DPoint3dArray, DPoint3d);
               if (cppViewPts.size() < cppActivePts.size())
                   cppViewPts.resize(cppActivePts.size());
               self.ActiveToView(&cppViewPts[0], &cppActivePts[0], (int) cppActivePts.size());
               CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               }
           }, "viewPts"_a, "activePts"_a);

    c3.def("ActiveToView", [] (Viewport const& self, DPoint3d& viewPt, DPoint3d const& activePt)
           {
           self.ActiveToView(&viewPt, &activePt, 1);
           }, "viewPt"_a, "activePt"_a);

    c3.def("ViewToActive", [] (Viewport const& self, DPoint3dArray& activePts, DPoint3dArray const& viewPts)
           {
           if (!viewPts.empty())
               {
               if (activePts.size() < viewPts.size())
                   activePts.resize(viewPts.size());
               self.ViewToActive(&activePts[0], &viewPts[0], (int) viewPts.size());
               }
           }, "activePts"_a, "viewPts"_a);

    c3.def("ViewToActive", [] (Viewport const& self, py::list& activePts, py::list const& viewPts)
           {
           if (!viewPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(activePts, cppActivePts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               if (cppActivePts.size() < cppViewPts.size())
                   cppActivePts.resize(cppViewPts.size());
               self.ViewToActive(&cppActivePts[0], &cppViewPts[0], (int) cppViewPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(activePts, cppActivePts, DPoint3dArray, DPoint3d);
               }
           }, "activePts"_a, "viewPts"_a);

    c3.def("ViewToActive", [] (Viewport const& self, DPoint3d& activePt, DPoint3d const& viewPt)
           {
           self.ViewToActive(&activePt, &viewPt, 1);
           }, "activePt"_a, "viewPt"_a);

    c3.def("ActiveToRoot", [] (Viewport const& self, DPoint3dArray& rootPts, DPoint3dArray const& activePts)
           {
           if (!activePts.empty())
               {
               if (rootPts.size() < activePts.size())
                   rootPts.resize(activePts.size());
               self.ActiveToRoot(&rootPts[0], &activePts[0], (int) activePts.size());
               }
           }, "rootPts"_a, "activePts"_a);

    c3.def("ActiveToRoot", [] (Viewport const& self, py::list& rootPts, py::list const& activePts)
           {
           if (!activePts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(activePts, cppActivePts, DPoint3dArray, DPoint3d);
               if (cppRootPts.size() < cppActivePts.size())
                   cppRootPts.resize(cppActivePts.size());
               self.ActiveToRoot(&cppRootPts[0], &cppActivePts[0], (int) cppActivePts.size());
               CONVERT_CPPARRAY_TO_PYLIST(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               }
           }, "rootPts"_a, "activePts"_a);

    c3.def("ActiveToRoot", [] (Viewport const& self, DPoint3d& rootPt, DPoint3d const& activePt)
           {
           self.ActiveToRoot(&rootPt, &activePt, 1);
           }, "rootPt"_a, "activePt"_a);

    c3.def("RootToActive", [] (Viewport const& self, DPoint3dArray& activePts, DPoint3dArray const& rootPts)
           {
           if (!rootPts.empty())
               {
               if (activePts.size() < rootPts.size())
                   activePts.resize(rootPts.size());
               self.RootToActive(&activePts[0], &rootPts[0], (int) rootPts.size());
               }
           }, "activePts"_a, "rootPts"_a);

    c3.def("RootToActive", [] (Viewport const& self, py::list& activePts, py::list const& rootPts)
           {
           if (!rootPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(activePts, cppActivePts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(rootPts, cppRootPts, DPoint3dArray, DPoint3d);
               if (cppActivePts.size() < cppRootPts.size())
                   cppActivePts.resize(cppRootPts.size());
               self.RootToActive(&cppActivePts[0], &cppRootPts[0], (int) cppRootPts.size());
               }
           }, "activePts"_a, "rootPts"_a);

    c3.def("RootToActive", [] (Viewport const& self, DPoint3d& activePt, DPoint3d const& rootPt)
           {
           self.RootToActive(&activePt, &rootPt, 1);
           }, "activePt"_a, "rootPt"_a);

    c3.def("ActiveToRoot", py::overload_cast<RotMatrixR, RotMatrixCR>(&Viewport::ActiveToRoot, py::const_), "rootRMatrix"_a, "activeRMatrix"_a);
    c3.def("RootToActive", py::overload_cast<RotMatrixR, RotMatrixCR>(&Viewport::RootToActive, py::const_), "activeRMatrix"_a, "rootRMatrix"_a);

    c3.def("ViewToScreen", [] (Viewport const& self, DPoint3dArray& screenPts, DPoint3dArray const& viewPts)
           {
           if (!viewPts.empty())
               {
               if (screenPts.size() < viewPts.size())
                   screenPts.resize(viewPts.size());
               self.ViewToScreen(&screenPts[0], &viewPts[0], (int) viewPts.size());
               }
           }, "screenPts"_a, "viewPts"_a);

    c3.def("ViewToScreen", [] (Viewport const& self, py::list& screenPts, py::list const& viewPts)
           {
           if (!viewPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(screenPts, cppScreenPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               if (cppScreenPts.size() < cppViewPts.size())
                   cppScreenPts.resize(cppViewPts.size());
               self.ViewToScreen(&cppScreenPts[0], &cppViewPts[0], (int) cppViewPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(screenPts, cppScreenPts, DPoint3dArray, DPoint3d);
               }
           }, "screenPts"_a, "viewPts"_a);

    c3.def("ViewToScreen", [] (Viewport const& self, DPoint3d& screenPt, DPoint3d const& viewPt)
           {
           self.ViewToScreen(&screenPt, &viewPt, 1);
           }, "screenPt"_a, "viewPt"_a);

    c3.def("ScreenToView", [] (Viewport const& self, DPoint3dArray& viewPts, DPoint3dArray const& screenPts)
           {
           if (!screenPts.empty())
               {
               if (viewPts.size() < screenPts.size())
                   viewPts.resize(screenPts.size());
               self.ScreenToView(&viewPts[0], &screenPts[0], (int) screenPts.size());
               }
           }, "viewPts"_a, "screenPts"_a);

    c3.def("ScreenToView", [] (Viewport const& self, py::list& viewPts, py::list const& screenPts)
           {
           if (!screenPts.empty())
               {
               CONVERT_PYLIST_TO_NEW_CPPARRAY(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               CONVERT_PYLIST_TO_NEW_CPPARRAY(screenPts, cppScreenPts, DPoint3dArray, DPoint3d);
               if (cppViewPts.size() < cppScreenPts.size())
                   cppViewPts.resize(cppScreenPts.size());
               self.ScreenToView(&cppViewPts[0], &cppScreenPts[0], (int) cppScreenPts.size());
               CONVERT_CPPARRAY_TO_PYLIST(viewPts, cppViewPts, DPoint3dArray, DPoint3d);
               }
           }, "viewPts"_a, "screenPts"_a);

    c3.def("ScreenToView", [] (Viewport const& self, DPoint3d& viewPt, DPoint3d const& screenPt)
           {
           self.ScreenToView(&viewPt, &screenPt, 1);
           }, "viewPt"_a, "screenPt"_a);

    c3.def("SetMinimumLOD", &Viewport::SetMinimumLOD, "minLod"_a);
    c3.def("IsActive", &Viewport::IsActive);
    c3.def("IsCameraOn", &Viewport::IsCameraOn);
    c3.def("IsGridOn", &Viewport::IsGridOn);
    c3.def("Is3dModel", &Viewport::Is3dModel);
    c3.def("IsSheetView", &Viewport::IsSheetView);

    c3.def_property_readonly("RootModel", &Viewport::GetRootModel);
    c3.def("GetRootModel", &Viewport::GetRootModel, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("TargetModel", &Viewport::GetTargetModel);
    c3.def("GetTargetModel", &Viewport::GetTargetModel, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("ViewInfo", &Viewport::GetViewInfoP);
    c3.def("GetViewInfo", &Viewport::GetViewInfoP, py::return_value_policy::reference_internal);
    
    c3.def("GetViewName", &Viewport::GetViewName, "name"_a);
    
    c3.def_property_readonly("ViewNumber", &Viewport::GetViewNumber);
    c3.def("GetViewNumber", &Viewport::GetViewNumber, DOC(Bentley, DgnPlatform, Viewport, GetViewNumber));
    
    c3.def_property_readonly("ScreenNumber", &Viewport::GetScreenNumber);
    c3.def("GetScreenNumber", &Viewport::GetScreenNumber, DOC(Bentley, DgnPlatform, Viewport, GetScreenNumber));
    
    c3.def_property_readonly("ViewOrigin", &Viewport::GetViewOrigin);
    c3.def("GetViewOrigin", &Viewport::GetViewOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Viewport, GetViewOrigin));
    
    c3.def_property_readonly("ViewDelta", &Viewport::GetViewDelta);
    c3.def("GetViewDelta", &Viewport::GetViewDelta, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Viewport, GetViewDelta));
    
    c3.def_property_readonly("ViewFlags", &Viewport::GetViewFlags);
    c3.def("GetViewFlags", &Viewport::GetViewFlags, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Viewport, GetViewFlags));
    
    c3.def("GetPixelSizeAtPoint", &Viewport::GetPixelSizeAtPoint, "rootPt"_a, "coordSys"_a = DgnCoordSystem::Root, DOC(Bentley, DgnPlatform, Viewport, GetPixelSizeAtPoint));
    c3.def("Scroll", &Viewport::Scroll, "viewDist"_a, DOC(Bentley, DgnPlatform, Viewport, Scroll));
    c3.def("Zoom", &Viewport::Zoom, "newCenterPoint"_a, "factor"_a, "normalizeCamera"_a);
    
    c3.def("SetupFromFrustum", [] (Viewport& self, DPoint3dArray const& frustPts)
           {
           if (frustPts.size() < 8)
               throw py::index_error();

           return self.SetupFromFrustum(&frustPts[0]);
           }, "frustPts"_a);

    c3.def("SetupFromFrustum", [] (Viewport& self, py::list const& frustPts)
           {
           if (frustPts.size() < 8)
               throw py::index_error();

           CONVERT_PYLIST_TO_NEW_CPPARRAY(frustPts, cppFrustPts, DPoint3dArray, DPoint3d);
           return self.SetupFromFrustum(&cppFrustPts[0]);
           }, "frustPts"_a);
    
    c3.def("SynchWithViewInfo", &Viewport::SynchWithViewInfo, "saveInUndo"_a, "updateViewTitle"_a, DOC(Bentley, DgnPlatform, Viewport, SynchWithViewInfo));
    c3.def("ComputeFittedElementRange", &Viewport::ComputeFittedElementRange, "range"_a, "elements"_a, "rMatrix"_a, DOC(Bentley, DgnPlatform, Viewport, ComputeFittedElementRange));
    c3.def("ComputeDisplayedModelRefRange", &Viewport::ComputeDisplayedModelRefRange, "range"_a, "modelRef"_a, "includeChildren"_a, "fitParams"_a, DOC(Bentley, DgnPlatform, Viewport, ComputeDisplayedModelRefRange));
    }