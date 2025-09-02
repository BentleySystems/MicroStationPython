/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\isprite.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ISprite.h>



static const char * __doc_Bentley_DgnPlatform_SpriteLocation_GetSprite =R"doc(Get the ISprite value, if this SpriteLocation is active.)doc";

static const char * __doc_Bentley_DgnPlatform_SpriteLocation_GetLocation =R"doc(Get the sprite's location, if this SpriteLocation is active.)doc";

static const char * __doc_Bentley_DgnPlatform_SpriteLocation_IsActive =R"doc(Determine whether this Sprite Location is currently active.

:returns:
    true if this Sprite Location is currently active.)doc";

static const char * __doc_Bentley_DgnPlatform_SpriteLocation_DecorateViewport =R"doc(If this Sprite Location is active for the specified Viewport, draw its
Sprite Definition at the current location. Otherwise, this method does
nothing. @note This method is **ONLY** valid from within an
IViewDecoration::DoDecoration event callback.)doc";

static const char * __doc_Bentley_DgnPlatform_SpriteLocation_Deactivate =R"doc(Deactivate an active Sprite Location. After this call, calls to
#DecorateViewport for this Sprite Location will do nothing until it is
re-Activated.)doc";

static const char * __doc_Bentley_DgnPlatform_SpriteLocation_Activate =R"doc(Activate this Sprite to show a specific Sprite Definition at a
specific location in a Viewport. This call does *not* display the
Sprite Definition in the Viewport. Rather, subsequent calls to
#DecorateViewport from within an IViewDecoration *will* show the
Sprite. This Sprite Location remains active until #Deactivate is
called.

:param sprite:
    The Sprite Definition to draw at this SpriteLocation

:param viewport:
    The Viewport onto which the Sprite Definition is drawn

:param location:
    The x,y posistion in DgnCoordSystem::View

:param transparency:
    The transparency to draw the Sprite (0=opaque, 255=invisible))doc";

static const char * __doc_Bentley_DgnPlatform_ISprite_GetUseAlpha =R"doc(Get whether to use the alpha channel for this Sprite Definition. If
this is not set then the Icon mask bits are used to determine
transparency (which discards the aliasing alpha for Icons which has it
set.)doc";

static const char * __doc_Bentley_DgnPlatform_ISprite_GetSize =R"doc(Get the size (in pixels) of this Sprite Definition.

:param size:
    (output) the size in pixels of this sprite definition.)doc";

static const char * __doc_Bentley_DgnPlatform_ISprite_GetHotSpot =R"doc(Get the X,Y position of the hotspot for this Sprite Definition (0,0 is
the upper left corner). Often this will be the middle of the Sprite.

:param hotspot:
    (output) the hotspot for this sprite definition)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ISprite(py::module_& m)
    {
    //===================================================================================
    // struct ISprite
    py::class_< ISprite, RefCountedPtr<ISprite> > c1(m, "ISprite");

    c1.def("GetHotSpot", &ISprite::GetHotSpot, "hotspot"_a, DOC(Bentley, DgnPlatform, ISprite, GetHotSpot));
    c1.def("GetSize", &ISprite::GetSize, "size"_a, DOC(Bentley, DgnPlatform, ISprite, GetSize));

    c1.def_property_readonly("UseAlpha", &ISprite::GetUseAlpha);
    c1.def("GetUseAlpha", &ISprite::GetUseAlpha, DOC(Bentley, DgnPlatform, ISprite, GetUseAlpha));

    //===================================================================================
    // struct SpriteLocation
    py::class_< SpriteLocation, RefCountedPtr<SpriteLocation> > c2(m, "SpriteLocation");

    c2.def(py::init<>());
    c2.def("Activate", &SpriteLocation::Activate, "sprite"_a, "viewport"_a, "location"_a, "transparency"_a, DOC(Bentley, DgnPlatform, SpriteLocation, Activate));
    c2.def("Deactivate", &SpriteLocation::Deactivate, DOC(Bentley, DgnPlatform, SpriteLocation, Deactivate));
    c2.def("DecorateViewport", &SpriteLocation::DecorateViewport, "viewport"_a, DOC(Bentley, DgnPlatform, SpriteLocation, DecorateViewport));
    c2.def("IsActive", &SpriteLocation::IsActive, DOC(Bentley, DgnPlatform, SpriteLocation, IsActive));
    
    c2.def_property_readonly("Location", &SpriteLocation::GetLocation);
    c2.def("GetLocation", &SpriteLocation::GetLocation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SpriteLocation, GetLocation));
    
    c2.def_property_readonly("Sprite", &SpriteLocation::GetSprite);
    c2.def("GetSprite", &SpriteLocation::GetSprite, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SpriteLocation, GetSprite));
    }