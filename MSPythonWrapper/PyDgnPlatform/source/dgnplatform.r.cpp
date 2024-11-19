/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnplatform.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, DefFileId::Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnPlatform.r.h>
#include <Bentley/BeStringUtilities.h>

// Pybind11 does not allow wrapping anonymous enums, so duplicate into an enum class here
enum class DefFileId
    {
    DEFFILE_INFO_SIGNATURE  = 0xff,    /* Resource Signature byte. */
    DEFFILE_FORMAT_VERSION  = 8,       /* Current version of DefaultFileInfo */
    DEFFILE_MAX_SAVED       = 10,      /* Number of most recently used files to save */
    DEFFILE_BASEID          = -100,
    DEFDGNFILE_ID           = (DEFFILE_BASEID-1),
    DEFIMAGEFILE_ID         = (DEFFILE_BASEID-2),
    DEFRECORDFILE_ID        = (DEFFILE_BASEID-3),
    DEFDISPFILE_ID          = (DEFFILE_BASEID-4),
    DEFNODEFILE_ID          = (DEFFILE_BASEID-5),
    DEFREFFILE_ID           = (DEFFILE_BASEID-6),
    DEFCELLFILE_ID          = (DEFFILE_BASEID-7),
    DEFPLTCFGFILE_ID        = (DEFFILE_BASEID-8),
    DEFUCMFILE_ID           = (DEFFILE_BASEID-9),
    DEFFUNCKEYFILE_ID       = (DEFFILE_BASEID-11),
    DEFLVLFILE_ID           = (DEFFILE_BASEID-12),
    DEFCTBLFILE_ID          = (DEFFILE_BASEID-13),
    DEFUCIFILE_ID           = (DEFFILE_BASEID-14),
    DEFDXFFILE_ID           = (DEFFILE_BASEID-15),
    DEFDWGFILE_ID           = (DEFFILE_BASEID-16),
    DEFIGESFILE_ID          = (DEFFILE_BASEID-17),
    DEFMOVIEFILE_ID         = (DEFFILE_BASEID-18),
    DEFMATPALETTE_ID        = (DEFFILE_BASEID-19),
    DEFTEXTURE_ID           = (DEFFILE_BASEID-20),
    DEFMATTABLE_ID          = (DEFFILE_BASEID-21),
    DEFPLAIMAGE_ID          = (DEFFILE_BASEID-22),
    DEFCGMFILE_ID           = (DEFFILE_BASEID-23),
    DEFBUMPMAP_ID           = (DEFFILE_BASEID-24),
    DEFMDLLOAD_ID           = (DEFFILE_BASEID-25),
    DEFLSTYLE_ID            = (DEFFILE_BASEID-26),
    DEFHELPFILE_ID          = (DEFFILE_BASEID-27),
    DEFSEEDFILE_ID          = (DEFFILE_BASEID-28),
    DEFCELLSEED_ID          = (DEFFILE_BASEID-29),
    DEFDRAWCOMPMODEL_ID     = (DEFFILE_BASEID-30),
    DEFDRAWCOMPSHEET_ID     = (DEFFILE_BASEID-31),
    DEFDRAWCOMPSEED_ID      = (DEFFILE_BASEID-32),
    DEFFONTINSTDEST_ID      = (DEFFILE_BASEID-33),
    DEFRASTERREF_ID         = (DEFFILE_BASEID-34),
    DEFSATWRITE_ID          = (DEFFILE_BASEID-35),
    DEFSATREAD_ID           = (DEFFILE_BASEID-36),
    DEFROMULUSREAD_ID       = (DEFFILE_BASEID-37),
    DEFSETTINGSFILE_ID      = (DEFFILE_BASEID-38),
    DEFBORDERFILE_ID        = (DEFFILE_BASEID-39),
    DEFSAVESHEETAS_ID       = (DEFFILE_BASEID-40),
    DEFTAGLIB_ID            = (DEFFILE_BASEID-41),
    DEFCELLSELFILE_ID       = (DEFFILE_BASEID-42),
    DEFPARTFILE_ID          = (DEFFILE_BASEID-43),
    DEFMACROFILE_ID         = (DEFFILE_BASEID-44),
    DEFBUILDERFILE_ID       = (DEFFILE_BASEID-45),
    DEFMODELERREPORT_ID     = (DEFFILE_BASEID-46),
    DEFSTLFILE_ID           = (DEFFILE_BASEID-47),
    DEFEDGESFILE_ID         = (DEFFILE_BASEID-48),
    DEFICONEDITFILE_ID      = (DEFFILE_BASEID-49),
    DEFANIMATORFILE_ID      = (DEFFILE_BASEID-50),
    DEFGLOSSARYFILE_ID      = (DEFFILE_BASEID-51),
    DEFPENTABLEMACRO_ID     = (DEFFILE_BASEID-52),
    DEFPENTABLE_ID          = (DEFFILE_BASEID-53),
    DEFPLOTOUTPUT_ID        = (DEFFILE_BASEID-54),
    DEFGRDFILE_ID           = (DEFFILE_BASEID-55),
    DEFLEVSYMB_ID           = (DEFFILE_BASEID-56),
    DEFRDEFILE_ID           = (DEFFILE_BASEID-57),
    DEFRENDERCONT_ID        = (DEFFILE_BASEID-58),
    DEFDWGWCTBL_ID          = (DEFFILE_BASEID-60),
    DEFDWGC0TBL_ID          = (DEFFILE_BASEID-61),
    DEFDWGCHTBL_ID          = (DEFFILE_BASEID-62),
    DEFDWGWTTBL_ID          = (DEFFILE_BASEID-63),
    DEFDWGLVTBL_ID          = (DEFFILE_BASEID-64),
    DEFDWGLCTBL_ID          = (DEFFILE_BASEID-65),
    DEFDWGEXPSETFILE_ID     = (DEFFILE_BASEID-66),
    DEFDWGIMPSETFILE_ID     = (DEFFILE_BASEID-67),
    DEFDWGMACROFILE_ID      = (DEFFILE_BASEID-68),
    DEFCGMFTTBL_ID          = (DEFFILE_BASEID-69),
    DEFCGMLVTBL_ID          = (DEFFILE_BASEID-70),
    DEFCGMLCTBL_ID          = (DEFFILE_BASEID-71),
    DEFCGMWTTBL_ID          = (DEFFILE_BASEID-72),
    DEFCGMEXPSETFILE_ID     = (DEFFILE_BASEID-73),
    DEFCGMIMPSETFILE_ID     = (DEFFILE_BASEID-74),
    DEFIGSEXPSETFILE_ID     = (DEFFILE_BASEID-75),
    DEFIGSIMPSETFILE_ID     = (DEFFILE_BASEID-76),
    DEFIGSSTARTFILE_ID      = (DEFFILE_BASEID-77),
    DEFSAVEMULTFILE_ID      = (DEFFILE_BASEID-78),
    DEFVRMLIMPORTFILE_ID    = (DEFFILE_BASEID-79),
    DEFAP203INSTARTFILE_ID  = (DEFFILE_BASEID-80),
    DEFAP203OUTSTARTFILE_ID = (DEFFILE_BASEID-81),
    DEFAP214INSTARTFILE_ID  = (DEFFILE_BASEID-82),
    DEFAP214OUTSTARTFILE_ID = (DEFFILE_BASEID-83),
    DEFAP227INSTARTFILE_ID  = (DEFFILE_BASEID-84),
    DEFAP227OUTSTARTFILE_ID = (DEFFILE_BASEID-85),
    DEFRASTCONVINP_ID       = (DEFFILE_BASEID-86),
    DEFRASTCONVOUT_ID       = (DEFFILE_BASEID-87),
    DEFIFCINSTARTFILE_ID    = (DEFFILE_BASEID-88),
    DEFIFCOUTSTARTFILE_ID   = (DEFFILE_BASEID-89),
    DEFANIMASFFILE_ID       = (DEFFILE_BASEID-90),
    DEFANIMQVAFILE_ID       = (DEFFILE_BASEID-91),
    DEFIVRFILE_ID           = (DEFFILE_BASEID-92),
    DEFRADFILE_ID           = (DEFFILE_BASEID-93),
    DEFVCADFILE_ID          = (DEFFILE_BASEID-94),
    DEFMPSETFILE_ID         = (DEFFILE_BASEID-95),
    DEFIESFILE_ID           = (DEFFILE_BASEID-96),
    DEFARCHIVERFILE_ID      = (DEFFILE_BASEID-97),
    DEFXMTWRITE_ID          = (DEFFILE_BASEID-98),
    DEFXMTREAD_ID           = (DEFFILE_BASEID-99),
    DEFDXBFILE_ID           = (DEFFILE_BASEID-100),
    DEFSTEPFILE_ID          = (DEFFILE_BASEID-101),
    DEFDGNLIBFILE_ID        = (DEFFILE_BASEID-102),
    DEFALLPENTABLE_ID       = (DEFFILE_BASEID-103),
    DEFBATPLTJOBSETFILE_ID  = (DEFFILE_BASEID-104),
    DEFBATCVTLOGFILE_ID     = (DEFFILE_BASEID-105),
    DEFPTRACEFILE_ID        = (DEFFILE_BASEID-106),
    DEFSAVEASFILE_ID        = (DEFFILE_BASEID-107),
    DEFPRINTDEFFILE_ID      = (DEFFILE_BASEID-108),
    DEFRPCFILE_ID           = (DEFFILE_BASEID-109),
    DEFVIEWIMPORTFILE_ID    = (DEFFILE_BASEID-110),
    DEFACLINFILE_ID         = (DEFFILE_BASEID-113),
    DEFQTVRFILE_ID          = (DEFFILE_BASEID-114),
    DEFWHTMLFILE_ID         = (DEFFILE_BASEID-115),
    DEFCADFILE_ID           = (DEFFILE_BASEID-116),
    DEFLEVELLIBRARY_ID      = (DEFFILE_BASEID-117),
    DEFSTYLEIMPORT_ID       = (DEFFILE_BASEID-118),
    DEFSRVCFGFILE_ID        = (DEFFILE_BASEID-119),
    DEFPRJFILE_ID           = (DEFFILE_BASEID-120),
    DEFV8DGNFILE_ID         = (DEFFILE_BASEID-121),
    DEFV7DGNFILE_ID         = (DEFFILE_BASEID-122),
    DEFHIDDENLINEFILE_ID    = (DEFFILE_BASEID-123),
    DEFREDLINEFILE_ID       = (DEFFILE_BASEID-124),
    DEFTRIFORMADOCFILE_ID   = (DEFFILE_BASEID-125),
    DEFALLFILES_ID          = (DEFFILE_BASEID-126),
    DEFBATCHCNV_ID          = (DEFFILE_BASEID-127),
    DEFCALSTYPE1_ID         = (DEFFILE_BASEID-128),
    DEFPNG_ID               = (DEFFILE_BASEID-129),
    DEFIMG_ID               = (DEFFILE_BASEID-130),
    DEFIMG24BIT_ID          = (DEFFILE_BASEID-131),
    DEFINGRCIT_ID           = (DEFFILE_BASEID-132),
    DEFINGRCOT_ID           = (DEFFILE_BASEID-133),
    DEFINGRRGB_ID           = (DEFFILE_BASEID-134),
    DEFINGRRLE_ID           = (DEFFILE_BASEID-135),
    DEFINGRTG4_ID           = (DEFFILE_BASEID-136),
    DEFINGRRASTER_ID        = (DEFFILE_BASEID-137),
    DEFPCXFILE_ID           = (DEFFILE_BASEID-138),
    DEFPROCAPPL_ID          = (DEFFILE_BASEID-139),
    DEFRLC_ID               = (DEFFILE_BASEID-140),
    DEFSUNRASTER_ID         = (DEFFILE_BASEID-141),
    DEFTARGA_ID             = (DEFFILE_BASEID-142),
    DEFBMP_ID               = (DEFFILE_BASEID-143),
    DEFREMAPFILE_ID         = (DEFFILE_BASEID-144),
    DEFBATCHCNVFILES_ID     = (DEFFILE_BASEID-145),
    DEFMVBAFILE_ID          = (DEFFILE_BASEID-146),
    DEFEPXFILE_ID           = (DEFFILE_BASEID-147),
    DEFBATCNVJOBSET_ID      = (DEFFILE_BASEID-148),
    DEFBATPRCFILES_ID       = (DEFFILE_BASEID-149),
    DEFBATPRCJOBFILE_ID     = (DEFFILE_BASEID-150),
    DEFBATPRCCMDFILE_ID     = (DEFFILE_BASEID-151),
    DEFJTFILE_ID            = (DEFFILE_BASEID-152),
    DEFMODELIMPORT_ID       = (DEFFILE_BASEID-153),
    DEFDESIGNSEED_ID        = (DEFFILE_BASEID-154),
    DEFSHEETSEED_ID         = (DEFFILE_BASEID-155),
    DEFDWGSHEETSEED_ID      = (DEFFILE_BASEID-156),
    DEFSETTINGSTOV8_ID      = (DEFFILE_BASEID-157),
    DEFBUTTONMENUFILE_ID    = (DEFFILE_BASEID-158),
    DEFPARMSETIMPORT_ID     = (DEFFILE_BASEID-159),
    DEFPARMSETEXPORT_ID     = (DEFFILE_BASEID-160),
    DEFSTDSCHECKER_ID       = (DEFFILE_BASEID-161),
    DEFSTDSDGNLIBS_ID       = (DEFFILE_BASEID-162),
    DEFDWGRECOVER_ID        = (DEFFILE_BASEID-163),
    DEFSTDSREPORT_ID        = (DEFFILE_BASEID-164),
    DEFDWGSETTINGS_ID       = (DEFFILE_BASEID-165),
    DEFLSTOOLS_ID           = (DEFFILE_BASEID-166),
    DEFXCHNGIMPORT_ID       = (DEFFILE_BASEID-167),
    DEFXCHNGEXPORT_ID       = (DEFFILE_BASEID-168),
    DEFU3DEXPORT_ID         = (DEFFILE_BASEID-169),
    DEFRSTFILE_ID           = (DEFFILE_BASEID-170),
    DEFCOLORBOOK_ID         = (DEFFILE_BASEID-172),
    DEFPROJECTINDEX_ID      = (DEFFILE_BASEID-173),
    DEFRENDSOLUTION_ID      = (DEFFILE_BASEID-174),
    DEFEXPORT2D_ID          = (DEFFILE_BASEID-175),
    DEFEXPORT3D_ID          = (DEFFILE_BASEID-176),
    DEFONLYCELLS_ID         = (DEFFILE_BASEID-177),
    DEFLINKTARGET_ID        = (DEFFILE_BASEID-178),
    DEFKMLEXPORT_ID         = (DEFFILE_BASEID-179),
    DEFKMLPLACEMARK_ID      = (DEFFILE_BASEID-180),
    DEFFENCEFILE_ID         = (DEFFILE_BASEID-181),
    DEFMERGESOURCE_ID       = (DEFFILE_BASEID-182),
    DEFMERGEDEST_ID         = (DEFFILE_BASEID-183),
    DEFKMLCAPTURE_ID        = (DEFFILE_BASEID-184),
    DEFSKPEXPORT_ID         = (DEFFILE_BASEID-185),
    DEFCOLLADAEXPORT_ID     = (DEFFILE_BASEID-186),
    DEFMAXWELLEXPORT_ID     = (DEFFILE_BASEID-187),
    DEFMAXWELLMXM_ID        = (DEFFILE_BASEID-188),
    DEFMSPROJECTXMLFILE_ID  = (DEFFILE_BASEID-189),
    DEFMPXFILE_ID           = (DEFFILE_BASEID-190),
    DEFOBJEXPORT_ID         = (DEFFILE_BASEID-191),
    DEFP3TEXTFILE_ID        = (DEFFILE_BASEID-192),
    DEFPRCEXPORT_ID         = (DEFFILE_BASEID-193),
    DEFPRINTSTYLEFILE_ID    = (DEFFILE_BASEID-194),
    DEFGCSFROMFILE_ID       = (DEFFILE_BASEID-195),
    DEFANIMWMVFILE_ID       = (DEFFILE_BASEID-196),
    DEFANIMAVIFILE_ID       = (DEFFILE_BASEID-197),
    DEFPUBLISHDGNFILE_ID    = (DEFFILE_BASEID-198),
    DEFKTEXPORT_ID          = (DEFFILE_BASEID-199),
    DEFLXOEXPORT_ID         = (DEFFILE_BASEID-200),
    DEFMARKUPDGNFILE_ID     = (DEFFILE_BASEID-201),
    DEFOVERLAYDGNFILE_ID    = (DEFFILE_BASEID-202),
    DEFLIGHTPROBEFILE_ID    = (DEFFILE_BASEID-203),
    DEFRenderEnvironment    = (DEFFILE_BASEID-204),
    DEFLUXHISTORYDIR_ID     = (DEFFILE_BASEID-205),
    DEFDRAWINGSEED_ID       = (DEFFILE_BASEID-206),
    DEFCREATEDYNAMICVIEW_ID = (DEFFILE_BASEID-207),
    DEFDESIGNSCRIPTFILE_ID  = (DEFFILE_BASEID-208),
    DEFPOINTCLOUDFILE_ID    = (DEFFILE_BASEID-209),
    DEFINSOLATIONFILE_ID    = (DEFFILE_BASEID-210),
    DEFSCHEDULELINKER_ID    = (DEFFILE_BASEID-211),
    DEFWEATHERFILE_ID       = (DEFFILE_BASEID-212),
    DEFCOMPOSERDGNFILE_ID   = (DEFFILE_BASEID-213),
    DEFGPXFILE_ID           = (DEFFILE_BASEID-214),
    DEFXLSFILE_ID           = (DEFFILE_BASEID-215),
    DEFDESCARTESTHEMATIC_ID = (DEFFILE_BASEID-216),
    DEFPANOSET_ID           = (DEFFILE_BASEID-217),
    DEFFBXEXPORT_ID         = (DEFFILE_BASEID-218),
    DEFSVGFILE_ID           = (DEFFILE_BASEID-219),
    DEFSTMFILE_ID           = (DEFFILE_BASEID-220),
    DEFPSDFILE_ID           = (DEFFILE_BASEID-221),
    DEFINSOLATIONCSVFILE_ID = (DEFFILE_BASEID-222),
    DEFANNOTATIONATTACHMENT_ID = (DEFFILE_BASEID-223),
    DEFXMLFILE_ID           = (DEFFILE_BASEID-224),
    DEFICONDGNFILE_ID       = (DEFFILE_BASEID-225),
    DEFICONBMPFILE_ID       = (DEFFILE_BASEID-226),
    DEFICONAPPFILE_ID       = (DEFFILE_BASEID-227),
    DEFPROPPUBFILTERFILE_ID = (DEFFILE_BASEID-229),
    DEFIMODEMBEDFILE_ID =     (DEFFILE_BASEID-230),
    DEFTAGTEMPLATEFILE_ID   = (DEFFILE_BASEID-231),
    DEFITEMTYPELIB_ID       = (DEFFILE_BASEID-232),
    DEFFBXFILE_ID           = (DEFFILE_BASEID-233),
    DEFU3DJSFILE_ID         = (DEFFILE_BASEID-234),
    DEFMSWORDFILE_ID =        (DEFFILE_BASEID-235),
    DEFMSEXCELFILE_ID =       (DEFFILE_BASEID-236),
    DEFPDFFILE_ID =           (DEFFILE_BASEID-237),
    DEFRASTERLINESTYLE_ID   = (DEFFILE_BASEID-238),
    DEFMRMESHFILE_ID        = (DEFFILE_BASEID-239),
    DEFFILTERLIBRARY_ID     = (DEFFILE_BASEID-240),
    DEFDIALOGCENSUSXML_ID   = (DEFFILE_BASEID-241),
    DEFMRMESHFILEPUBLISH_ID = (DEFFILE_BASEID-242),
    DEFVUEHISTORYDIR_ID     = (DEFFILE_BASEID-243),
    DEFVUEEXPORTDIR_ID      = (DEFFILE_BASEID-244),
    DEFDGNDWGDXF_ID         = (DEFFILE_BASEID-245),
    DEFTPFFILE_ID           = (DEFFILE_BASEID-246),
    DEFDGNSIFILE_ID         = (DEFFILE_BASEID-247),
    DEFSTPFILE_ID           = (DEFFILE_BASEID-248),
    DEFLASTFILETYPE_ID =      (DEFDGNSIFILE_ID),   // change this if you're adding new DEFFILE_IDs

    DEFPARASOLIDFILE_ID     = (DEFFILE_BASEID-1004),
    DEFIMPORTDGNFILE_ID     = (DEFFILE_BASEID-1005),
    DEFSELECTBYRSC_ID       = (DEFFILE_BASEID-1006),
    DEFRASTERFILE_ID        = (DEFFILE_BASEID-1007),
    DEFIMAGESERVERFILE_ID   = (DEFFILE_BASEID-1008),
    DEFPYFILE_ID            = (DEFFILE_BASEID-1009),
    DEFFILE_LOWESTID        = DEFFILE_BASEID-999900,
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnPlatform_r(py::module_& m)
    {
    //===================================================================================
    // struct SPoint2d
    py::class_< SPoint2d>(m, "SPoint2d")
        .def(py::init<>())
        .def_readwrite("x", &SPoint2d::x)
        .def_readwrite("y", &SPoint2d::y)
        .def("__repr__", [] (SPoint2d& self) { return "[{}, {}]"_s.format(self.x, self.y); });

    //===================================================================================
    // struct RgbaColorDef
    py::class_< RgbaColorDef>(m, "RgbaColorDef")
        .def(py::init<>())
        .def_readwrite("red", &RgbaColorDef::red)
        .def_readwrite("green", &RgbaColorDef::green)
        .def_readwrite("blue", &RgbaColorDef::blue)
        .def_readwrite("alpha", &RgbaColorDef::alpha)
        .def("__repr__", [] (RgbaColorDef& self) { return "(red:{}, green:{}, blue:{}, alpha:{})"_s.format(self.red, self.green, self.blue, self.alpha); });

    //===================================================================================
    // struct RgbColorDef
    py::class_< RgbColorDef>(m, "RgbColorDef")
        .def(py::init<>())
        .def_readwrite("red", &RgbColorDef::red)
        .def_readwrite("green", &RgbColorDef::green)
        .def_readwrite("blue", &RgbColorDef::blue)
        .def("__repr__", [] (RgbColorDef& self) { return "(red:{}, green:{}, blue:{})"_s.format(self.red, self.green, self.blue); });
    py::bind_vector< bvector<RgbColorDef> >(m, "RgbColorDefArray", py::module_local(false));

    //===================================================================================
    // enum class RefAttachNestMode
    py::enum_< RefAttachNestMode>(m, "RefAttachNestMode")
        .value("eNone", RefAttachNestMode::None)
        .value("eCopy", RefAttachNestMode::Copy)
        .value("eDisplay", RefAttachNestMode::Display)
        .export_values();

    //===================================================================================
    // enum class DgnModelType
    py::enum_< DgnModelType>(m, "DgnModelType")
        .value("eNormal", DgnModelType::Normal)
        .value("eSheet", DgnModelType::Sheet)
        .value("eExtraction_Deprecated", DgnModelType::Extraction_Deprecated)
        .value("eDrawing", DgnModelType::Drawing)
        .value("eDgnComponentDefinition", DgnModelType::DgnComponentDefinition)
        .export_values();

    //===================================================================================
    // enum class CellLibraryType
    py::enum_< CellLibraryType>(m, "CellLibraryType")
        .value("eInvalid", CellLibraryType::Invalid)
        .value("eGraphic", CellLibraryType::Graphic)
        .value("eMenu", CellLibraryType::Menu)
        .value("eCBMenu", CellLibraryType::CBMenu)
        .value("eMatrixMenu", CellLibraryType::MatrixMenu)
        .value("ePoint", CellLibraryType::Point)
        .value("eParametric", CellLibraryType::Parametric)
        .value("eBlock", CellLibraryType::Block)
        .export_values();

    //===================================================================================
    // enum class StandardView
    py::enum_< StandardView>(m, "StandardView")
        .value("eNotStandard", StandardView::NotStandard)
        .value("eTop", StandardView::Top)
        .value("eBottom", StandardView::Bottom)
        .value("eLeft", StandardView::Left)
        .value("eRight", StandardView::Right)
        .value("eFront", StandardView::Front)
        .value("eBack", StandardView::Back)
        .value("eIso", StandardView::Iso)
        .value("eRightIso", StandardView::RightIso)
        .export_values();        

    //===================================================================================
    // enum class MSRenderMode
    py::enum_< MSRenderMode>(m, "MSRenderMode")
        .value("eInvalid", MSRenderMode::Invalid)
        .value("eWireframe", MSRenderMode::Wireframe)
        .value("eCrossSection", MSRenderMode::CrossSection)
        .value("eWiremesh", MSRenderMode::Wiremesh)
        .value("eHiddenLine", MSRenderMode::HiddenLine)
        .value("eSolidFill", MSRenderMode::SolidFill)
        .value("eConstantShade", MSRenderMode::ConstantShade)
        .value("eSmoothShade", MSRenderMode::SmoothShade)
        .value("ePhong", MSRenderMode::Phong)
        .value("eRayTrace", MSRenderMode::RayTrace)
        .value("eRenderWireframe", MSRenderMode::RenderWireframe)
        .value("eRadiosity", MSRenderMode::Radiosity)
        .value("eParticleTrace", MSRenderMode::ParticleTrace)
        .value("eRenderLuxology", MSRenderMode::RenderLuxology)
        .value("eRenderVue", MSRenderMode::RenderVue)
        .value("eGPUPathTrace", MSRenderMode::GPUPathTrace)
        .export_values();

    //===================================================================================
    // enum class GradientMode
    py::enum_< DgnPlatform::GradientMode>(m, "GradientMode")
        .value("eNone", DgnPlatform::GradientMode::None)
        .value("eLinear", DgnPlatform::GradientMode::Linear)
        .value("eCurved", DgnPlatform::GradientMode::Curved)
        .value("eCylindrical", DgnPlatform::GradientMode::Cylindrical)
        .value("eSpherical", DgnPlatform::GradientMode::Spherical)
        .value("eHemispherical", DgnPlatform::GradientMode::Hemispherical)
        .export_values();

    //===================================================================================
    // enum class AngleFormatVals
    py::enum_< DgnPlatform::AngleFormatVals>(m, "AngleFormatVals")
        .value("eNone", DgnPlatform::AngleFormatVals::None)
        .value("eActive", DgnPlatform::AngleFormatVals::Active)
        .value("eDegrees", DgnPlatform::AngleFormatVals::Degrees)
        .value("eDegMinSec", DgnPlatform::AngleFormatVals::DegMinSec)
        .value("eCentesimal", DgnPlatform::AngleFormatVals::Centesimal)
        .value("eRadians", DgnPlatform::AngleFormatVals::Radians)
        .value("eDegMin", DgnPlatform::AngleFormatVals::DegMin)
        .value("eSurveyor", DgnPlatform::AngleFormatVals::Surveyor)
        .export_values();

    //===================================================================================
    // struct DirFormat
    py::class_< DirFormat> c1(m, "DirFormat");

    c1.def(py::init<>());
    c1.def_readwrite("mode", &DirFormat::mode);
    c1.def_readwrite("baseDir", &DirFormat::baseDir);
    c1.def_property("clockwise",
                    [] (DirFormat const& self) { return (UInt16)self.flags.clockwise; },
                    [] (DirFormat& self, UInt16 clockwise) { self.flags.clockwise = clockwise; });

    //===================================================================================
    // struct Symbology
    py::class_< Symbology>(m, "Symbology")
        .def(py::init<>())
        .def(py::init([](int style, UInt32 weight, UInt32 color) { Symbology sym; sym.style = style; sym.weight = weight; sym.color = color; return sym; }), "style"_a, "weight"_a, "color"_a)
        .def_readwrite("style", &Symbology::style)
        .def_readwrite("weight", &Symbology::weight)
        .def_readwrite("color", &Symbology::color);

    //===================================================================================
    // struct DegreeOfFreedom
    py::class_< DegreeOfFreedom>(m, "DegreeOfFreedom")
        .def_readwrite("locked", &DegreeOfFreedom::locked)
        .def_readwrite("value", &DegreeOfFreedom::value);

    //===================================================================================
    // struct UnitFlags
    py::class_< UnitFlags> c2(m, "UnitFlags");

    c2.def_property("base",
                    [] (UnitFlags const& self){return self.base;},
                    [] (UnitFlags& self, UInt32 base) { self.base = base; });
    c2.def_property("system",
                    [](UnitFlags const& self) {return self.system; },
                    [](UnitFlags& self, UInt32 system) { self.system = system; });
    c2.def_property("reserved",
                    [](UnitFlags const& self) {return self.reserved; },
                    [](UnitFlags& self, UInt32 reserved) { self.reserved = reserved; });

    //===================================================================================
    // struct StoredUnitInfo
    py::class_< StoredUnitInfo> c3(m, "StoredUnitInfo");
    
    c3.def_readwrite("flags", &StoredUnitInfo::flags);
    c3.def_readwrite("numerator", &StoredUnitInfo::numerator);
    c3.def_readwrite("denominator", &StoredUnitInfo::denominator);
    c3.def_property("label",
                    [] (StoredUnitInfo const& self){
                        WString outVal;
                        BeStringUtilities::Utf16ToWChar(outVal, self.label);
                        return outVal;
                    },
                    [] (StoredUnitInfo& self, WStringCR label){
                        BeStringUtilities::WCharToUtf16(self.label, _countof(self.label), label.c_str());
                    });

    //===================================================================================
    // enum class SelectionMode
    py::enum_< SelectionMode>(m, "SelectionMode")
        .value("eNew", SelectionMode::New)
        .value("eAdd", SelectionMode::Add)
        .value("eSubtract", SelectionMode::Subtract)
        .value("eInverse", SelectionMode::Inverse)
        .value("eClear", SelectionMode::Clear)
        .value("eAll", SelectionMode::All)
        .export_values();

    //===================================================================================
    // enum class LocateSurfacesPref
    py::enum_< LocateSurfacesPref>(m, "LocateSurfacesPref")
        .value("eNever", LocateSurfacesPref::Never)
        .value("eByView", LocateSurfacesPref::ByView)
        .value("eAlways", LocateSurfacesPref::Always)
        .export_values();

    //===================================================================================
    // enum class UnitBase
    py::enum_< UnitBase>(m, "UnitBase")
        .value("eNone", UnitBase::None)
        .value("eMeter", UnitBase::Meter)
        .value("eDegree", UnitBase::Degree)
        .export_values();

    //===================================================================================
    // enum class StandardUnit
    py::enum_< StandardUnit>(m, "StandardUnit")
        .value("eNone", StandardUnit::None)

        .value("eEnglishFirst", StandardUnit::EnglishFirst)
        .value("eEnglishMiles", StandardUnit::EnglishMiles)
        .value("eEnglishYards", StandardUnit::EnglishYards)
        .value("eEnglishFeet", StandardUnit::EnglishFeet)
        .value("eEnglishInches", StandardUnit::EnglishInches)
        .value("eEnglishPicas", StandardUnit::EnglishPicas)
        .value("eEnglishPoints", StandardUnit::EnglishPoints)
        .value("eEnglishMils", StandardUnit::EnglishMils)
        .value("eEnglishMicroInches", StandardUnit::EnglishMicroInches)
        .value("eEnglishLast", StandardUnit::EnglishLast)

        .value("eEnglishSurveyMiles", StandardUnit::EnglishSurveyMiles)
        .value("eEnglishFurlongs", StandardUnit::EnglishFurlongs)
        .value("eEnglishChains", StandardUnit::EnglishChains)
        .value("eEnglishRods", StandardUnit::EnglishRods)
        .value("eEnglishFathoms", StandardUnit::EnglishFathoms)
        .value("eEnglishSurveyFeet", StandardUnit::EnglishSurveyFeet)
        .value("eEnglishSurveyInches", StandardUnit::EnglishSurveyInches)

        .value("eMetricFirst", StandardUnit::MetricFirst)
        .value("eMetricPetameters", StandardUnit::MetricPetameters)
        .value("eMetricTerameters", StandardUnit::MetricTerameters)
        .value("eMetricGigameters", StandardUnit::MetricGigameters)
        .value("eMetricMegameters", StandardUnit::MetricMegameters)
        .value("eMetricKilometers", StandardUnit::MetricKilometers)
        .value("eMetricHectometers", StandardUnit::MetricHectometers)
        .value("eMetricDekameters", StandardUnit::MetricDekameters)
        .value("eMetricMeters", StandardUnit::MetricMeters)
        .value("eMetricDecimeters", StandardUnit::MetricDecimeters)
        .value("eMetricCentimeters", StandardUnit::MetricCentimeters)
        .value("eMetricMillimeters", StandardUnit::MetricMillimeters)
        .value("eMetricMicrometers", StandardUnit::MetricMicrometers)
        .value("eMetricNanometers", StandardUnit::MetricNanometers)
        .value("eMetricPicometers", StandardUnit::MetricPicometers)
        .value("eMetricFemtometers", StandardUnit::MetricFemtometers)
        .value("eMetricLast", StandardUnit::MetricLast)

        .value("eNoSystemFirst", StandardUnit::NoSystemFirst)
        .value("eNoSystemParsecs", StandardUnit::NoSystemParsecs)
        .value("eNoSystemLightYears", StandardUnit::NoSystemLightYears)
        .value("eNoSystemAstronomicalUnits", StandardUnit::NoSystemAstronomicalUnits)
        .value("eNoSystemNauticalMiles", StandardUnit::NoSystemNauticalMiles)
        .value("eNoSystemAngstroms", StandardUnit::NoSystemAngstroms)
        .value("eNoSystemLast", StandardUnit::NoSystemLast)

        .value("eUnitlessWhole", StandardUnit::UnitlessWhole)

        .value("eAngleRadians", StandardUnit::AngleRadians)
        .value("eAngleDegrees", StandardUnit::AngleDegrees)
        .value("eAngleGrads", StandardUnit::AngleGrads)
        .value("eAngleMinutes", StandardUnit::AngleMinutes)
        .value("eAngleSeconds", StandardUnit::AngleSeconds)

        .value("eCustom", StandardUnit::Custom)
        .export_values();

    //===================================================================================
    // enum class AngleMode
    py::enum_< AngleMode>(m, "AngleMode")
        .value("eInvalid", AngleMode::Invalid)
        .value("eDegrees", AngleMode::Degrees)
        .value("eDegMin", AngleMode::DegMin)
        .value("eDegMinSec", AngleMode::DegMinSec)
        .value("eCentesimal", AngleMode::Centesimal)
        .value("eRadians", AngleMode::Radians)
        .export_values();

    //===================================================================================
    // enum class AnglePrecision
    py::enum_< AnglePrecision>(m, "AnglePrecision")
        .value("eWhole", AnglePrecision::Whole)
        .value("eUse1Place", AnglePrecision::Use1Place)
        .value("eUse2Places", AnglePrecision::Use2Places)
        .value("eUse3Places", AnglePrecision::Use3Places)
        .value("eUse4Places", AnglePrecision::Use4Places)
        .value("eUse5Places", AnglePrecision::Use5Places)
        .value("eUse6Places", AnglePrecision::Use6Places)
        .value("eUse7Places", AnglePrecision::Use7Places)
        .value("eUse8Places", AnglePrecision::Use8Places)        
        .export_values();

    //===================================================================================
    // enum class DgnUnitFormat
    py::enum_< DgnUnitFormat>(m, "DgnUnitFormat")
        .value("eMUSU", DgnUnitFormat::MUSU)
        .value("eMU", DgnUnitFormat::MU)
        .value("eMUSUPU", DgnUnitFormat::MUSUPU)
        .value("eSU", DgnUnitFormat::SU)
        .export_values();

    //===================================================================================
    // enum class DirectionMode
    py::enum_< DirectionMode>(m, "DirectionMode")
        .value("eInvalid", DirectionMode::Invalid)
        .value("eAzimuth", DirectionMode::Azimuth)
        .value("eBearing", DirectionMode::Bearing)
        .export_values();

    //===================================================================================
    // enum class DirectionMode
    py::enum_< DirectionBase>(m, "DirectionBase")
        .value("eNorth", DirectionBase::North)
        .value("eSouth", DirectionBase::South)
        .value("eEast", DirectionBase::East)
        .value("eWest", DirectionBase::West)
        .value("eCustom", DirectionBase::Custom)
        .export_values();

    //===================================================================================
    // enum class GridConfiguration
    py::enum_< GridConfiguration>(m, "GridConfiguration")
        .value("eOrthogonal", GridConfiguration::Orthogonal)
        .value("eIsometric", GridConfiguration::Isometric)
        .value("eOffset", GridConfiguration::Offset)
        .export_values();

    //===================================================================================
    // enum class IsometricPlane
    py::enum_< IsometricPlane>(m, "IsometricPlane")
        .value("eTop", IsometricPlane::Top)
        .value("eLeft", IsometricPlane::Left)
        .value("eRight", IsometricPlane::Right)
        .value("eAll", IsometricPlane::All)
        .export_values();

    //===================================================================================
    // enum class FenceMode
    py::enum_< FenceMode>(m, "FenceMode")
        .value("eInside", FenceMode::Inside)
        .value("eOverlap", FenceMode::Overlap)
        .value("eClip", FenceMode::Clip)
        .value("eVoid", FenceMode::Void)
        .value("eVoidOverlap", FenceMode::VoidOverlap)
        .value("eVoidClip", FenceMode::VoidClip)
        .export_values();

    //===================================================================================
    // enum class DateTimeFormatPart
    py::enum_< DateTimeFormatPart>(m, "DateTimeFormatPart", py::arithmetic())
        .value("eDATETIME_PART_DayOfWeek", DateTimeFormatPart::DATETIME_PART_DayOfWeek)
        .value("eDATETIME_PART_DoW", DateTimeFormatPart::DATETIME_PART_DoW)

        .value("eDATETIME_PART_D", DateTimeFormatPart::DATETIME_PART_D)
        .value("eDATETIME_PART_DD", DateTimeFormatPart::DATETIME_PART_DD)

        .value("eDATETIME_PART_Month", DateTimeFormatPart::DATETIME_PART_Month)
        .value("eDATETIME_PART_Mon", DateTimeFormatPart::DATETIME_PART_Mon)
        .value("eDATETIME_PART_M", DateTimeFormatPart::DATETIME_PART_M)
        .value("eDATETIME_PART_MM", DateTimeFormatPart::DATETIME_PART_MM)

        .value("eDATETIME_PART_d", DateTimeFormatPart::DATETIME_PART_d)
        .value("eDATETIME_PART_ddd", DateTimeFormatPart::DATETIME_PART_ddd)

        .value("eDATETIME_PART_YYYY", DateTimeFormatPart::DATETIME_PART_YYYY)
        .value("eDATETIME_PART_YY", DateTimeFormatPart::DATETIME_PART_YY)

        .value("eDATETIME_PART_h", DateTimeFormatPart::DATETIME_PART_h)
        .value("eDATETIME_PART_hh", DateTimeFormatPart::DATETIME_PART_hh)
        .value("eDATETIME_PART_H", DateTimeFormatPart::DATETIME_PART_H)
        .value("eDATETIME_PART_HH", DateTimeFormatPart::DATETIME_PART_HH)

        .value("eDATETIME_PART_m", DateTimeFormatPart::DATETIME_PART_m)
        .value("eDATETIME_PART_mm", DateTimeFormatPart::DATETIME_PART_mm)

        .value("eDATETIME_PART_s", DateTimeFormatPart::DATETIME_PART_s)
        .value("eDATETIME_PART_ss", DateTimeFormatPart::DATETIME_PART_ss)

        .value("eDATETIME_PART_FractionalSeconds", DateTimeFormatPart::DATETIME_PART_FractionalSeconds)

        .value("eDATETIME_PART_Comma", DateTimeFormatPart::DATETIME_PART_Comma)
        .value("eDATETIME_PART_DateSeparator", DateTimeFormatPart::DATETIME_PART_DateSeparator)
        .value("eDATETIME_PART_TimeSeparator", DateTimeFormatPart::DATETIME_PART_TimeSeparator)
        .value("eDATETIME_PART_DecimalSeparator", DateTimeFormatPart::DATETIME_PART_DecimalSeparator)
        .value("eDATETIME_PART_Space", DateTimeFormatPart::DATETIME_PART_Space)

        .value("eDATETIME_PART_AMPM", DateTimeFormatPart::DATETIME_PART_AMPM)
        .value("eDATETIME_PART_AP", DateTimeFormatPart::DATETIME_PART_AP)
        .value("eDATETIME_PART_U", DateTimeFormatPart::DATETIME_PART_U)
        .value("eDATETIME_PART_UU", DateTimeFormatPart::DATETIME_PART_UU)
        .value("eDATETIME_PART_U_UU", DateTimeFormatPart::DATETIME_PART_U_UU)
        .value("eDATETIME_PART_UU_UU", DateTimeFormatPart::DATETIME_PART_UU_UU)

        .value("eDATETIME_PART_UTC", DateTimeFormatPart::DATETIME_PART_UTC)

        .value("eDATETIME_PART_h_mm_AMPM", DateTimeFormatPart::DATETIME_PART_h_mm_AMPM)
        .value("eDATETIME_PART_h_mm_ss_AMPM", DateTimeFormatPart::DATETIME_PART_h_mm_ss_AMPM)

        .value("eDATETIME_PART_M_D_YYYY", DateTimeFormatPart::DATETIME_PART_M_D_YYYY)
        .value("eDATETIME_PART_MM_DD_YYYY", DateTimeFormatPart::DATETIME_PART_MM_DD_YYYY)
        .value("eDATETIME_PART_Day_D_Month_YYYY", DateTimeFormatPart::DATETIME_PART_Day_D_Month_YYYY)
        .value("eDATETIME_PART_Day_Month_D_YYYY", DateTimeFormatPart::DATETIME_PART_Day_Month_D_YYYY)

        .value("eDATETIME_PART_Full", DateTimeFormatPart::DATETIME_PART_Full)
        .value("eDATETIME_PART_General", DateTimeFormatPart::DATETIME_PART_General)
        
        .export_values();

    //===================================================================================
    // enum class DgnFileFormatType
    py::enum_< DgnFileFormatType>(m, "DgnFileFormatType")
        .value("eInvalid", DgnFileFormatType::Invalid)
        .value("eCurrent", DgnFileFormatType::Current)
        .value("eV7", DgnFileFormatType::V7)
        .value("eV8", DgnFileFormatType::V8)
        .value("eDWG", DgnFileFormatType::DWG)
        .value("eDXF", DgnFileFormatType::DXF)
        .export_values();

    //===================================================================================
    // enum class DwgUnitFormat
    py::enum_< DwgUnitFormat>(m, "DwgUnitFormat")
        .value("eScientific", DwgUnitFormat::Scientific)
        .value("eDecimal", DwgUnitFormat::Decimal)
        .value("eEngineering", DwgUnitFormat::Engineering)
        .value("eArchitectural", DwgUnitFormat::Architectural)
        .value("eFractional", DwgUnitFormat::Fractional)
        .export_values();

    //===================================================================================
    // enum class DimensionType
    py::enum_< DimensionType>(m, "DimensionType")
        .value("eNone", DimensionType::None)
        .value("eSizeArrow", DimensionType::SizeArrow)
        .value("eSizeStroke", DimensionType::SizeStroke)
        .value("eLocateSingle", DimensionType::LocateSingle)
        .value("eLocateStacked", DimensionType::LocateStacked)
        .value("eAngleSize", DimensionType::AngleSize)
        .value("eArcSize", DimensionType::ArcSize)
        .value("eAngleLocation", DimensionType::AngleLocation)
        .value("eArcLocation", DimensionType::ArcLocation)
        .value("eAngleLines", DimensionType::AngleLines)
        .value("eAngleAxis", DimensionType::AngleAxis)
        .value("eRadius", DimensionType::Radius)
        .value("eDiameter", DimensionType::Diameter)
        .value("eDiameterParallel", DimensionType::DiameterParallel)
        .value("eDiameterPerpendicular", DimensionType::DiameterPerpendicular)
        .value("eCustomLinear", DimensionType::CustomLinear)
        .value("eOrdinate", DimensionType::Ordinate)
        .value("eRadiusExtended", DimensionType::RadiusExtended)
        .value("eDiameterExtended", DimensionType::DiameterExtended)
        .value("eCenter", DimensionType::Center)

        .value("eAngleAxisX", DimensionType::AngleAxisX)
        .value("eAngleAxisY", DimensionType::AngleAxisY)
        .value("eLabelLine", DimensionType::LabelLine)
        .value("eNote", DimensionType::Note)
        .value("eMaxThatHasTemplate", DimensionType::MaxThatHasTemplate)

        .export_values();

    //===================================================================================
    // enum class TextElementJustification
    py::enum_< TextElementJustification>(m, "TextElementJustification")
        .value("eLeftTop", TextElementJustification::LeftTop)
        .value("eLeftMiddle", TextElementJustification::LeftMiddle)
        .value("eLeftBaseline", TextElementJustification::LeftBaseline)
        .value("eLeftDescender", TextElementJustification::LeftDescender)

        .value("eCenterTop", TextElementJustification::CenterTop)
        .value("eCenterMiddle", TextElementJustification::CenterMiddle)
        .value("eCenterBaseline", TextElementJustification::CenterBaseline)
        .value("eCenterDescender", TextElementJustification::CenterDescender)

        .value("eRightTop", TextElementJustification::RightTop)
        .value("eRightMiddle", TextElementJustification::RightMiddle)
        .value("eRightBaseline", TextElementJustification::RightBaseline)
        .value("eRightDescender", TextElementJustification::RightDescender)

        .value("eLeftCap", TextElementJustification::LeftCap)
        .value("eLeftMarginCap", TextElementJustification::LeftMarginCap)
        .value("eCenterCap", TextElementJustification::CenterCap)
        .value("eRightCap", TextElementJustification::RightCap)
        .value("eRightMarginCap", TextElementJustification::RightMarginCap)

        .value("eInvalid", TextElementJustification::Invalid)

        .export_values();

    //===================================================================================
    // enum class MlineOffsetMode
    py::enum_< DgnPlatform::MlineOffsetMode>(m, "MlineOffsetMode")
        .value("eUnknown", DgnPlatform::MlineOffsetMode::Unknown)
        .value("eByWork", DgnPlatform::MlineOffsetMode::ByWork)
        .value("eByCenter", DgnPlatform::MlineOffsetMode::ByCenter)
        .value("eByMax", DgnPlatform::MlineOffsetMode::ByMax)
        .value("eByMin", DgnPlatform::MlineOffsetMode::ByMin)
        .value("eCustom", DgnPlatform::MlineOffsetMode::Custom)
        .export_values();

    //===================================================================================
    // enum class MlineBreakLengthType
    py::enum_< DgnPlatform::MlineBreakLengthType>(m, "MlineBreakLengthType", py::arithmetic())
        .value("eMLBREAK_STD", DgnPlatform::MlineBreakLengthType::MLBREAK_STD)
        .value("eMLBREAK_FROM_JOINT", DgnPlatform::MlineBreakLengthType::MLBREAK_FROM_JOINT)
        .value("eMLBREAK_TO_JOINT", DgnPlatform::MlineBreakLengthType::MLBREAK_TO_JOINT)
        .value("eMLBREAK_BETWEEN_JOINTS", DgnPlatform::MlineBreakLengthType::MLBREAK_BETWEEN_JOINTS)
        .export_values();

    //===================================================================================
    // enum class SnapMode
    py::enum_< DgnPlatform::SnapMode>(m, "SnapMode")
        .value("eInvalid", DgnPlatform::SnapMode::Invalid)
        .value("eFirst", DgnPlatform::SnapMode::First)
        .value("eNone", DgnPlatform::SnapMode::None)
        .value("eNearest", DgnPlatform::SnapMode::Nearest)
        .value("eNearestKeypoint", DgnPlatform::SnapMode::NearestKeypoint)
        .value("eMidPoint", DgnPlatform::SnapMode::MidPoint)
        .value("eCenter", DgnPlatform::SnapMode::Center)
        .value("eOrigin", DgnPlatform::SnapMode::Origin)
        .value("eBisector", DgnPlatform::SnapMode::Bisector)
        .value("eIntersection", DgnPlatform::SnapMode::Intersection)
        .value("eTangency", DgnPlatform::SnapMode::Tangency)
        .value("eTangentPoint", DgnPlatform::SnapMode::TangentPoint)
        .value("ePerpendicular", DgnPlatform::SnapMode::Perpendicular)
        .value("ePerpendicularPoint", DgnPlatform::SnapMode::PerpendicularPoint)
        .value("eParallel", DgnPlatform::SnapMode::Parallel)
        .value("eMulti3", DgnPlatform::SnapMode::Multi3)
        .value("ePointOn", DgnPlatform::SnapMode::PointOn)
        .value("eMulti1", DgnPlatform::SnapMode::Multi1)
        .value("eMulti2", DgnPlatform::SnapMode::Multi2)
        .value("eMultiSnaps", DgnPlatform::SnapMode::MultiSnaps)
        .export_values();   

    //===================================================================================
    // enum class DgnElementClass
    py::enum_< DgnElementClass>(m, "DgnElementClass")
        .value("ePrimary", DgnElementClass::Primary)
        .value("ePatternComponent", DgnElementClass::PatternComponent)
        .value("eConstruction", DgnElementClass::Construction)
        .value("eDimension", DgnElementClass::Dimension)
        .value("ePrimaryRule", DgnElementClass::PrimaryRule)
        .value("eLinearPatterned", DgnElementClass::LinearPatterned)
        .value("eConstructionRule", DgnElementClass::ConstructionRule)
        .export_values();

    //===================================================================================
    // enum class RefUseColorTable
    py::enum_< RefUseColorTable>(m, "RefUseColorTable", py::arithmetic())
        .value("eREFCOLORTABLE_USEPREF", RefUseColorTable::REFCOLORTABLE_USEPREF)
        .value("eREFCOLORTABLE_ALWAYS", RefUseColorTable::REFCOLORTABLE_ALWAYS)
        .value("eREFCOLORTABLE_NEVER", RefUseColorTable::REFCOLORTABLE_NEVER)
        .export_values();

    //===================================================================================
    // enum class RefInitialLevelDisplay
    py::enum_< RefInitialLevelDisplay>(m, "RefInitialLevelDisplay", py::arithmetic())
        .value("eREF_FILE_LEVEL_DISPLAY_DEFAULT", RefInitialLevelDisplay::REF_FILE_LEVEL_DISPLAY_DEFAULT)
        .value("eREF_FILE_LEVEL_DISPLAY_ALL_ON", RefInitialLevelDisplay::REF_FILE_LEVEL_DISPLAY_ALL_ON)
        .value("eREF_FILE_LEVEL_DISPLAY_ALL_OFF", RefInitialLevelDisplay::REF_FILE_LEVEL_DISPLAY_ALL_OFF)
        .export_values();

    //===================================================================================
    // enum class RefLevelOverrides
    py::enum_< RefLevelOverrides>(m, "RefLevelOverrides", py::arithmetic())
        .value("eREFERENCE_LEVEL_OVERRIDES_PER_ATTACHMENT", RefLevelOverrides::REFERENCE_LEVEL_OVERRIDES_PER_ATTACHMENT)
        .value("eREFERENCE_LEVEL_OVERRIDES_AS_REQUIRED", RefLevelOverrides::REFERENCE_LEVEL_OVERRIDES_AS_REQUIRED)
        .value("eREFERENCE_LEVEL_OVERRIDES_NONE", RefLevelOverrides::REFERENCE_LEVEL_OVERRIDES_NONE)
        .export_values();

    //===================================================================================
    // enum class RefNestOverrides
    py::enum_< RefNestOverrides>(m, "RefNestOverrides", py::arithmetic())
        .value("eREF_NESTOVERRIDES_ASREQUIRED", RefNestOverrides::REF_NESTOVERRIDES_ASREQUIRED)
        .value("eREF_NESTOVERRIDES_ALWAYS", RefNestOverrides::REF_NESTOVERRIDES_ALWAYS)
        .value("eREF_NESTOVERRIDES_NEVER", RefNestOverrides::REF_NESTOVERRIDES_NEVER)
        .export_values();

    //===================================================================================
    // enum class RefNewLevelDisplay
    py::enum_< RefNewLevelDisplay>(m, "RefNewLevelDisplay", py::arithmetic())
        .value("eREF_NEWLEVELDISPLAY_FROMCONFIG", RefNewLevelDisplay::REF_NEWLEVELDISPLAY_FROMCONFIG)
        .value("eREF_NEWLEVELDISPLAY_ALWAYS", RefNewLevelDisplay::REF_NEWLEVELDISPLAY_ALWAYS)
        .value("eREF_NEWLEVELDISPLAY_NEVER", RefNewLevelDisplay::REF_NEWLEVELDISPLAY_NEVER)
        .export_values();

    //===================================================================================
    // enum class RefGlobalLinestyleScale
    py::enum_< RefGlobalLinestyleScale>(m, "RefGlobalLinestyleScale", py::arithmetic())
        .value("eREF_GLOBALLINESTYLESCALE_MASTER", RefGlobalLinestyleScale::REF_GLOBALLINESTYLESCALE_MASTER)
        .value("eREF_GLOBALLINESTYLESCALE_NONE", RefGlobalLinestyleScale::REF_GLOBALLINESTYLESCALE_NONE)
        .value("eREF_GLOBALLINESTYLESCALE_BOTH", RefGlobalLinestyleScale::REF_GLOBALLINESTYLESCALE_BOTH)
        .value("eREF_GLOBALLINESTYLESCALE_REFERENCE", RefGlobalLinestyleScale::REF_GLOBALLINESTYLESCALE_REFERENCE)
        .export_values();

    //===================================================================================
    // enum class RefPlotType
    py::enum_< RefPlotType>(m, "RefPlotType", py::arithmetic())
        .value("eREF_PLOTTYPE_AsDisplayed", RefPlotType::REF_PLOTTYPE_AsDisplayed)
        .value("eREF_PLOTTYPE_Wireframe", RefPlotType::REF_PLOTTYPE_Wireframe)
        .value("eREF_PLOTTYPE_Hidden", RefPlotType::REF_PLOTTYPE_Hidden)
        .value("eREF_PLOTTYPE_Rendered", RefPlotType::REF_PLOTTYPE_Rendered)
        .value("eREF_PLOTTYPE_UseDisplayStyle", RefPlotType::REF_PLOTTYPE_UseDisplayStyle)
        .value("eREF_PLOTTYPE_UseRenderingStyle", RefPlotType::REF_PLOTTYPE_UseRenderingStyle)
        .export_values();

    //===================================================================================
    // enum class MSElementTypes
    py::enum_< MSElementTypes>(m, "MSElementTypes", py::arithmetic())
        .value("eCELL_HEADER_ELM", MSElementTypes::CELL_HEADER_ELM)
        .value("eLINE_ELM", MSElementTypes::LINE_ELM)
        .value("eLINE_STRING_ELM", MSElementTypes::LINE_STRING_ELM)
        .value("eGROUP_DATA_ELM", MSElementTypes::GROUP_DATA_ELM)
        .value("eSHAPE_ELM", MSElementTypes::SHAPE_ELM)
        .value("eTEXT_NODE_ELM", MSElementTypes::TEXT_NODE_ELM)
        .value("eDIG_SETDATA_ELM", MSElementTypes::DIG_SETDATA_ELM)
        .value("eDGNFIL_HEADER_ELM", MSElementTypes::DGNFIL_HEADER_ELM)
        .value("eLEV_SYM_ELM", MSElementTypes::LEV_SYM_ELM)
        .value("eCURVE_ELM", MSElementTypes::CURVE_ELM)
        .value("eCMPLX_STRING_ELM", MSElementTypes::CMPLX_STRING_ELM)
        .value("eCMPLX_SHAPE_ELM", MSElementTypes::CMPLX_SHAPE_ELM)
        .value("eELLIPSE_ELM", MSElementTypes::ELLIPSE_ELM)
        .value("eARC_ELM", MSElementTypes::ARC_ELM)
        .value("eTEXT_ELM", MSElementTypes::TEXT_ELM)
        .value("eSURFACE_ELM", MSElementTypes::SURFACE_ELM)
        .value("eSOLID_ELM", MSElementTypes::SOLID_ELM)
        .value("eBSPLINE_POLE_ELM", MSElementTypes::BSPLINE_POLE_ELM)
        .value("ePOINT_STRING_ELM", MSElementTypes::POINT_STRING_ELM)
        .value("eCONE_ELM", MSElementTypes::CONE_ELM)
        .value("eBSPLINE_SURFACE_ELM", MSElementTypes::BSPLINE_SURFACE_ELM)
        .value("eBSURF_BOUNDARY_ELM", MSElementTypes::BSURF_BOUNDARY_ELM)
        .value("eBSPLINE_KNOT_ELM", MSElementTypes::BSPLINE_KNOT_ELM)
        .value("eBSPLINE_CURVE_ELM", MSElementTypes::BSPLINE_CURVE_ELM)
        .value("eBSPLINE_WEIGHT_ELM", MSElementTypes::BSPLINE_WEIGHT_ELM)
        .value("eDIMENSION_ELM", MSElementTypes::DIMENSION_ELM)
        .value("eSHAREDCELL_DEF_ELM", MSElementTypes::SHAREDCELL_DEF_ELM)
        .value("eSHARED_CELL_ELM", MSElementTypes::SHARED_CELL_ELM)
        .value("eMULTILINE_ELM", MSElementTypes::MULTILINE_ELM)
        .value("eATTRIBUTE_ELM", MSElementTypes::ATTRIBUTE_ELM)
        .value("eDGNSTORE_COMP", MSElementTypes::DGNSTORE_COMP)
        .value("eDGNSTORE_HDR", MSElementTypes::DGNSTORE_HDR)
        .value("eTYPE44_ELM", MSElementTypes::TYPE44_ELM)
        .value("eMICROSTATION_ELM", MSElementTypes::MICROSTATION_ELM)
        .value("eRASTER_HDR", MSElementTypes::RASTER_HDR)
        .value("eRASTER_COMP", MSElementTypes::RASTER_COMP)
        .value("eRASTER_REFERENCE_ELM", MSElementTypes::RASTER_REFERENCE_ELM)
        .value("eRASTER_REFERENCE_COMP", MSElementTypes::RASTER_REFERENCE_COMP)
        .value("eRASTER_HIERARCHY_ELM", MSElementTypes::RASTER_HIERARCHY_ELM)
        .value("eRASTER_HIERARCHY_COMP", MSElementTypes::RASTER_HIERARCHY_COMP)
        .value("eRASTER_FRAME_ELM", MSElementTypes::RASTER_FRAME_ELM)
        .value("eTABLE_ENTRY_ELM", MSElementTypes::TABLE_ENTRY_ELM)
        .value("eTABLE_ELM", MSElementTypes::TABLE_ELM)
        .value("eVIEW_GROUP_ELM", MSElementTypes::VIEW_GROUP_ELM)
        .value("eVIEW_ELM", MSElementTypes::VIEW_ELM)
        .value("eLEVEL_MASK_ELM", MSElementTypes::LEVEL_MASK_ELM)
        .value("eREFERENCE_ATTACH_ELM", MSElementTypes::REFERENCE_ATTACH_ELM)
        .export_values();

    //===================================================================================
    // enum TagType
    py::enum_< TagType>(m, "TagType", py::arithmetic())
        .value("eMS_TAGTYPE_CHAR", MS_TAGTYPE_CHAR)
        .value("eMS_TAGTYPE_SINT", MS_TAGTYPE_SINT)
        .value("eMS_TAGTYPE_LINT", MS_TAGTYPE_LINT)
        .value("eMS_TAGTYPE_DOUBLE", MS_TAGTYPE_DOUBLE)
        .value("eMS_TAGTYPE_BINARY", MS_TAGTYPE_BINARY)
        .value("eMS_TAGTYPE_WCHAR", MS_TAGTYPE_WCHAR)
        .export_values();        

    //===================================================================================
    // struct DgnTagValue
    py::class_< DgnTagValue> c4(m, "DgnTagValue");

    c4.def(py::init<>());
    c4.def(py::init<WCharCP>(), "val"_a);
    c4.def(py::init([] (py::bytes const& data)
                    {
                    std::string strVal = (std::string) data;
                    return new DgnTagValue((void*) strVal.data(), (UInt16) strVal.size());
                    }));
    c4.def(py::init<double>(), "val"_a);
    c4.def(py::init<long>(), "val"_a);
    c4.def(py::init<short>(), "val"_a);

    c4.def("SetTagValue", py::overload_cast<CharCP>(&DgnTagValue::SetTagValue), "val"_a);
    c4.def("SetTagValue", py::overload_cast<WCharCP>(&DgnTagValue::SetTagValue), "val"_a);
    c4.def("SetTagValue", py::overload_cast<double>(&DgnTagValue::SetTagValue), "val"_a);
    c4.def("SetTagValue", py::overload_cast<long>(&DgnTagValue::SetTagValue), "val"_a);
    c4.def("SetTagValue", py::overload_cast<short>(&DgnTagValue::SetTagValue), "val"_a);
    c4.def("SetTagValue", [] (DgnTagValue& self, py::bytes const& data)
           {
           std::string strVal = (std::string) data;
           self.SetTagValue((void const*) strVal.data(), (UInt16) strVal.size());
           });

    c4.def_property("TagType", &DgnTagValue::GetTagType, &DgnTagValue::SetTagType);
    c4.def("GetTagType", &DgnTagValue::GetTagType);
    c4.def("SetTagType", &DgnTagValue::SetTagType, "type"_a);
    
    c4.def_property("TagSize", &DgnTagValue::GetTagSize, &DgnTagValue::SetTagSize);
    c4.def("GetTagSize", &DgnTagValue::GetTagSize);
    c4.def("SetTagSize", &DgnTagValue::SetTagSize, "size"_a);
    
    c4.def_property_readonly("CharValue", &DgnTagValue::GetCharValue);
    c4.def("GetCharValue", &DgnTagValue::GetCharValue, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("DoubleValue", &DgnTagValue::GetDoubleValue);
    c4.def("GetDoubleValue", &DgnTagValue::GetDoubleValue);
    
    c4.def_property_readonly("LongValue", &DgnTagValue::GetLongValue);
    c4.def("GetLongValue", &DgnTagValue::GetLongValue);
    
    c4.def_property_readonly("ShortValue", &DgnTagValue::GetShortValue);
    c4.def("GetShortValue", &DgnTagValue::GetShortValue);
    
    c4.def_property_readonly("BinaryValue", [] (DgnTagValue const& self)
           {
           void* pVal = nullptr;
           size_t byteSize = 0;
           BentleyStatus retVal = self.GetBinaryValue(pVal, byteSize);
           auto outVal = py::make_tuple(retVal, py::bytes((const char*) pVal, byteSize));
           if (nullptr != pVal)
               bentleyAllocator_free(pVal, byteSize);
           return outVal;
           });

    c4.def("GetStringValue", py::overload_cast<LangCodePage const*>(&DgnTagValue::GetStringValue, py::const_), "codePage"_a);
    c4.def("IsValid", &DgnTagValue::IsValid);

    //===================================================================================
    // struct DgnTagDefinition
    py::class_< DgnTagDefinition> c5(m, "DgnTagDefinition");
    py::bind_vector<DgnTagDefinitionArray>(m, "DgnTagDefinitionArray", py::module_local(false));

    c5.def(py::init<>());

    c5.def_property("name",
                    [] (DgnTagDefinition const& self) { return self.name; },
                    [] (DgnTagDefinition& self, TagWChar const* szName) { wcsncpy(self.name, szName, DGNPLATFORM_RESOURCE_TAG_NAME_MAX); });

    c5.def_readwrite("id", &DgnTagDefinition::id);

    c5.def_property("prompt",
                    [] (DgnTagDefinition const& self) { return self.prompt; },
                    [] (DgnTagDefinition& self, TagWChar const* szName) { wcsncpy(self.prompt, szName, DGNPLATFORM_RESOURCE_TAG_NAME_MAX); });

    c5.def_readwrite("propsMask", &DgnTagDefinition::propsMask);

    c5.def_property("styleName",
                    [] (DgnTagDefinition const& self) { return self.styleName; },
                    [] (DgnTagDefinition& self, TagWChar const* szName) { wcsncpy(self.styleName, szName, DGNPLATFORM_RESOURCE_TAG_NAME_MAX); });

    c5.def_readwrite("tagValue", &DgnTagDefinition::value);

    //===================================================================================
    // enum TagProperty
    py::enum_< TagProperty>(m, "TagProperty", py::arithmetic())
        .value("eTAG_PROP_DISPOFF", TAG_PROP_DISPOFF)
        .value("eTAG_PROP_DEF", TAG_PROP_DEF)
        .value("eTAG_PROP_CONF", TAG_PROP_CONF)
        .value("eTAG_PROP_CONST", TAG_PROP_CONST)
        .export_values();

    //===================================================================================
    // enum TagExport
    py::enum_< TagExport>(m, "TagExport", py::arithmetic())
        .value("eTAG_EXPORT_TAGGED", TAG_EXPORT_TAGGED)
        .value("eTAG_EXPORT_ALL", TAG_EXPORT_ALL)
        .value("eTAG_EXPORT_TEXT", TAG_EXPORT_TEXT)
        .value("eTAG_EXPORT_XML", TAG_EXPORT_XML)
        .export_values();

    //===================================================================================
    // enum ProxyCachingOption
    py::enum_< ProxyCachingOption>(m, "ProxyCachingOption")
        .value("eLive", ProxyCachingOption::Live)
        .value("eCached", ProxyCachingOption::Cached)
        .value("eStatic", ProxyCachingOption::Static)
        .export_values();

    //===================================================================================
    // enum ProxyCacheSynch
    py::enum_< ProxyCacheSynch>(m, "ProxyCacheSynch")
        .value("eManual", ProxyCacheSynch::Manual)
        .value("eAlert", ProxyCacheSynch::Alert)
        .value("eAutomatic", ProxyCacheSynch::Automatic)
        .value("eDisconnected", ProxyCacheSynch::Disconnected)
        .value("eUnspecified", ProxyCacheSynch::Unspecified)
        .export_values();

    //===================================================================================
    // enum ReferenceSynchOption
    py::enum_< ReferenceSynchOption>(m, "ReferenceSynchOption")
        .value("eNamedViewClip", ReferenceSynchOption::NamedViewClip)
        .value("eNamedViewAllSettings", ReferenceSynchOption::NamedViewAllSettings)
        .value("eNamedViewNotsynced", ReferenceSynchOption::NamedViewNotsynced)
        .value("eNamedViewCameraAndClip", ReferenceSynchOption::NamedViewCameraAndClip)
        .value("eNamedViewPresentation", ReferenceSynchOption::NamedViewPresentation)
        .value("eAllSettingsFromNamedViewRootModel", ReferenceSynchOption::AllSettingsFromNamedViewRootModel)
        .export_values();

    //===================================================================================
    // enum ImageColorMode
    py::enum_< ImageColorMode>(m, "ImageColorMode")
        .value("eUnknown", ImageColorMode::Unknown)
        .value("eAny", ImageColorMode::Any)
        .value("eRGB", ImageColorMode::RGB)
        .value("ePalette16", ImageColorMode::Palette16)
        .value("ePalette256", ImageColorMode::Palette256)
        .value("eGreyScale", ImageColorMode::GreyScale)
        .value("eMonochrome", ImageColorMode::Monochrome)
        .value("eRGBA", ImageColorMode::RGBA)
        .value("ePalette256Alpha", ImageColorMode::Palette256Alpha)
        .value("eGreyScale16", ImageColorMode::GreyScale16)
        .value("ePalette2", ImageColorMode::Palette2)
        .export_values();    

    //===================================================================================
    // enum TagExport
    py::enum_ <DefFileId>(m, "DefFileId")
        .value("eDEFFILE_INFO_SIGNATURE", DefFileId::DEFFILE_INFO_SIGNATURE)
        .value("eDEFFILE_FORMAT_VERSION", DefFileId::DEFFILE_FORMAT_VERSION)
        .value("eDEFFILE_MAX_SAVED", DefFileId::DEFFILE_MAX_SAVED)
        .value("eDEFFILE_BASEID", DefFileId::DEFFILE_BASEID)
        .value("eDEFDGNFILE_ID", DefFileId::DEFDGNFILE_ID)
        .value("eDEFIMAGEFILE_ID", DefFileId::DEFIMAGEFILE_ID)
        .value("eDEFRECORDFILE_ID", DefFileId::DEFRECORDFILE_ID)
        .value("eDEFDISPFILE_ID", DefFileId::DEFDISPFILE_ID)
        .value("eDEFNODEFILE_ID", DefFileId::DEFNODEFILE_ID)
        .value("eDEFREFFILE_ID", DefFileId::DEFREFFILE_ID)
        .value("eDEFCELLFILE_ID", DefFileId::DEFCELLFILE_ID)
        .value("eDEFPLTCFGFILE_ID", DefFileId::DEFPLTCFGFILE_ID)
        .value("eDEFUCMFILE_ID", DefFileId::DEFUCMFILE_ID)
        .value("eDEFFUNCKEYFILE_ID", DefFileId::DEFFUNCKEYFILE_ID)
        .value("eDEFLVLFILE_ID", DefFileId::DEFLVLFILE_ID)
        .value("eDEFCTBLFILE_ID", DefFileId::DEFCTBLFILE_ID)
        .value("eDEFUCIFILE_ID", DefFileId::DEFUCIFILE_ID)
        .value("eDEFDXFFILE_ID", DefFileId::DEFDXFFILE_ID)
        .value("eDEFDWGFILE_ID", DefFileId::DEFDWGFILE_ID)
        .value("eDEFIGESFILE_ID", DefFileId::DEFIGESFILE_ID)
        .value("eDEFMOVIEFILE_ID", DefFileId::DEFMOVIEFILE_ID)
        .value("eDEFMATPALETTE_ID", DefFileId::DEFMATPALETTE_ID)
        .value("eDEFTEXTURE_ID", DefFileId::DEFTEXTURE_ID)
        .value("eDEFMATTABLE_ID", DefFileId::DEFMATTABLE_ID)
        .value("eDEFPLAIMAGE_ID", DefFileId::DEFPLAIMAGE_ID)
        .value("eDEFCGMFILE_ID", DefFileId::DEFCGMFILE_ID)
        .value("eDEFBUMPMAP_ID", DefFileId::DEFBUMPMAP_ID)
        .value("eDEFMDLLOAD_ID", DefFileId::DEFMDLLOAD_ID)
        .value("eDEFLSTYLE_ID", DefFileId::DEFLSTYLE_ID)
        .value("eDEFHELPFILE_ID", DefFileId::DEFHELPFILE_ID)
        .value("eDEFSEEDFILE_ID", DefFileId::DEFSEEDFILE_ID)
        .value("eDEFCELLSEED_ID", DefFileId::DEFCELLSEED_ID)
        .value("eDEFDRAWCOMPMODEL_ID", DefFileId::DEFDRAWCOMPMODEL_ID)
        .value("eDEFDRAWCOMPSHEET_ID", DefFileId::DEFDRAWCOMPSHEET_ID)
        .value("eDEFDRAWCOMPSEED_ID", DefFileId::DEFDRAWCOMPSEED_ID)
        .value("eDEFFONTINSTDEST_ID", DefFileId::DEFFONTINSTDEST_ID)
        .value("eDEFRASTERREF_ID", DefFileId::DEFRASTERREF_ID)
        .value("eDEFSATWRITE_ID", DefFileId::DEFSATWRITE_ID)
        .value("eDEFSATREAD_ID", DefFileId::DEFSATREAD_ID)
        .value("eDEFROMULUSREAD_ID", DefFileId::DEFROMULUSREAD_ID)
        .value("eDEFSETTINGSFILE_ID", DefFileId::DEFSETTINGSFILE_ID)
        .value("eDEFBORDERFILE_ID", DefFileId::DEFBORDERFILE_ID)
        .value("eDEFSAVESHEETAS_ID", DefFileId::DEFSAVESHEETAS_ID)
        .value("eDEFTAGLIB_ID", DefFileId::DEFTAGLIB_ID)
        .value("eDEFCELLSELFILE_ID", DefFileId::DEFCELLSELFILE_ID)
        .value("eDEFPARTFILE_ID", DefFileId::DEFPARTFILE_ID)
        .value("eDEFMACROFILE_ID", DefFileId::DEFMACROFILE_ID)
        .value("eDEFBUILDERFILE_ID", DefFileId::DEFBUILDERFILE_ID)
        .value("eDEFMODELERREPORT_ID", DefFileId::DEFMODELERREPORT_ID)
        .value("eDEFSTLFILE_ID", DefFileId::DEFSTLFILE_ID)
        .value("eDEFEDGESFILE_ID", DefFileId::DEFEDGESFILE_ID)
        .value("eDEFICONEDITFILE_ID", DefFileId::DEFICONEDITFILE_ID)
        .value("eDEFANIMATORFILE_ID", DefFileId::DEFANIMATORFILE_ID)
        .value("eDEFGLOSSARYFILE_ID", DefFileId::DEFGLOSSARYFILE_ID)
        .value("eDEFPENTABLEMACRO_ID", DefFileId::DEFPENTABLEMACRO_ID)
        .value("eDEFPENTABLE_ID", DefFileId::DEFPENTABLE_ID)
        .value("eDEFPLOTOUTPUT_ID", DefFileId::DEFPLOTOUTPUT_ID)
        .value("eDEFGRDFILE_ID", DefFileId::DEFGRDFILE_ID)
        .value("eDEFLEVSYMB_ID", DefFileId::DEFLEVSYMB_ID)
        .value("eDEFRDEFILE_ID", DefFileId::DEFRDEFILE_ID)
        .value("eDEFRENDERCONT_ID", DefFileId::DEFRENDERCONT_ID)
        .value("eDEFDWGWCTBL_ID", DefFileId::DEFDWGWCTBL_ID)
        .value("eDEFDWGC0TBL_ID", DefFileId::DEFDWGC0TBL_ID)
        .value("eDEFDWGCHTBL_ID", DefFileId::DEFDWGCHTBL_ID)
        .value("eDEFDWGWTTBL_ID", DefFileId::DEFDWGWTTBL_ID)
        .value("eDEFDWGLVTBL_ID", DefFileId::DEFDWGLVTBL_ID)
        .value("eDEFDWGLCTBL_ID", DefFileId::DEFDWGLCTBL_ID)
        .value("eDEFDWGEXPSETFILE_ID", DefFileId::DEFDWGEXPSETFILE_ID)
        .value("eDEFDWGIMPSETFILE_ID", DefFileId::DEFDWGIMPSETFILE_ID)
        .value("eDEFDWGMACROFILE_ID", DefFileId::DEFDWGMACROFILE_ID)
        .value("eDEFCGMFTTBL_ID", DefFileId::DEFCGMFTTBL_ID)
        .value("eDEFCGMLVTBL_ID", DefFileId::DEFCGMLVTBL_ID)
        .value("eDEFCGMLCTBL_ID", DefFileId::DEFCGMLCTBL_ID)
        .value("eDEFCGMWTTBL_ID", DefFileId::DEFCGMWTTBL_ID)
        .value("eDEFCGMEXPSETFILE_ID", DefFileId::DEFCGMEXPSETFILE_ID)
        .value("eDEFCGMIMPSETFILE_ID", DefFileId::DEFCGMIMPSETFILE_ID)
        .value("eDEFIGSEXPSETFILE_ID", DefFileId::DEFIGSEXPSETFILE_ID)
        .value("eDEFIGSIMPSETFILE_ID", DefFileId::DEFIGSIMPSETFILE_ID)
        .value("eDEFIGSSTARTFILE_ID", DefFileId::DEFIGSSTARTFILE_ID)
        .value("eDEFSAVEMULTFILE_ID", DefFileId::DEFSAVEMULTFILE_ID)
        .value("eDEFVRMLIMPORTFILE_ID", DefFileId::DEFVRMLIMPORTFILE_ID)
        .value("eDEFAP203INSTARTFILE_ID", DefFileId::DEFAP203INSTARTFILE_ID)
        .value("eDEFAP203OUTSTARTFILE_ID", DefFileId::DEFAP203OUTSTARTFILE_ID)
        .value("eDEFAP214INSTARTFILE_ID", DefFileId::DEFAP214INSTARTFILE_ID)
        .value("eDEFAP214OUTSTARTFILE_ID", DefFileId::DEFAP214OUTSTARTFILE_ID)
        .value("eDEFAP227INSTARTFILE_ID", DefFileId::DEFAP227INSTARTFILE_ID)
        .value("eDEFAP227OUTSTARTFILE_ID", DefFileId::DEFAP227OUTSTARTFILE_ID)
        .value("eDEFRASTCONVINP_ID", DefFileId::DEFRASTCONVINP_ID)
        .value("eDEFRASTCONVOUT_ID", DefFileId::DEFRASTCONVOUT_ID)
        .value("eDEFIFCINSTARTFILE_ID", DefFileId::DEFIFCINSTARTFILE_ID)
        .value("eDEFIFCOUTSTARTFILE_ID", DefFileId::DEFIFCOUTSTARTFILE_ID)
        .value("eDEFANIMASFFILE_ID", DefFileId::DEFANIMASFFILE_ID)
        .value("eDEFANIMQVAFILE_ID", DefFileId::DEFANIMQVAFILE_ID)
        .value("eDEFIVRFILE_ID", DefFileId::DEFIVRFILE_ID)
        .value("eDEFRADFILE_ID", DefFileId::DEFRADFILE_ID)
        .value("eDEFVCADFILE_ID", DefFileId::DEFVCADFILE_ID)
        .value("eDEFMPSETFILE_ID", DefFileId::DEFMPSETFILE_ID)
        .value("eDEFIESFILE_ID", DefFileId::DEFIESFILE_ID)
        .value("eDEFARCHIVERFILE_ID", DefFileId::DEFARCHIVERFILE_ID)
        .value("eDEFXMTWRITE_ID", DefFileId::DEFXMTWRITE_ID)
        .value("eDEFXMTREAD_ID", DefFileId::DEFXMTREAD_ID)
        .value("eDEFDXBFILE_ID", DefFileId::DEFDXBFILE_ID)
        .value("eDEFSTEPFILE_ID", DefFileId::DEFSTEPFILE_ID)
        .value("eDEFDGNLIBFILE_ID", DefFileId::DEFDGNLIBFILE_ID)
        .value("eDEFALLPENTABLE_ID", DefFileId::DEFALLPENTABLE_ID)
        .value("eDEFBATPLTJOBSETFILE_ID", DefFileId::DEFBATPLTJOBSETFILE_ID)
        .value("eDEFBATCVTLOGFILE_ID", DefFileId::DEFBATCVTLOGFILE_ID)
        .value("eDEFPTRACEFILE_ID", DefFileId::DEFPTRACEFILE_ID)
        .value("eDEFSAVEASFILE_ID", DefFileId::DEFSAVEASFILE_ID)
        .value("eDEFPRINTDEFFILE_ID", DefFileId::DEFPRINTDEFFILE_ID)
        .value("eDEFRPCFILE_ID", DefFileId::DEFRPCFILE_ID)
        .value("eDEFVIEWIMPORTFILE_ID", DefFileId::DEFVIEWIMPORTFILE_ID)
        .value("eDEFACLINFILE_ID", DefFileId::DEFACLINFILE_ID)
        .value("eDEFQTVRFILE_ID", DefFileId::DEFQTVRFILE_ID)
        .value("eDEFWHTMLFILE_ID", DefFileId::DEFWHTMLFILE_ID)
        .value("eDEFCADFILE_ID", DefFileId::DEFCADFILE_ID)
        .value("eDEFLEVELLIBRARY_ID", DefFileId::DEFLEVELLIBRARY_ID)
        .value("eDEFSTYLEIMPORT_ID", DefFileId::DEFSTYLEIMPORT_ID)
        .value("eDEFSRVCFGFILE_ID", DefFileId::DEFSRVCFGFILE_ID)
        .value("eDEFPRJFILE_ID", DefFileId::DEFPRJFILE_ID)
        .value("eDEFV8DGNFILE_ID", DefFileId::DEFV8DGNFILE_ID)
        .value("eDEFV7DGNFILE_ID", DefFileId::DEFV7DGNFILE_ID)
        .value("eDEFHIDDENLINEFILE_ID", DefFileId::DEFHIDDENLINEFILE_ID)
        .value("eDEFREDLINEFILE_ID", DefFileId::DEFREDLINEFILE_ID)
        .value("eDEFTRIFORMADOCFILE_ID", DefFileId::DEFTRIFORMADOCFILE_ID)
        .value("eDEFALLFILES_ID", DefFileId::DEFALLFILES_ID)
        .value("eDEFBATCHCNV_ID", DefFileId::DEFBATCHCNV_ID)
        .value("eDEFCALSTYPE1_ID", DefFileId::DEFCALSTYPE1_ID)
        .value("eDEFPNG_ID", DefFileId::DEFPNG_ID)
        .value("eDEFIMG_ID", DefFileId::DEFIMG_ID)
        .value("eDEFIMG24BIT_ID", DefFileId::DEFIMG24BIT_ID)
        .value("eDEFINGRCIT_ID", DefFileId::DEFINGRCIT_ID)
        .value("eDEFINGRCOT_ID", DefFileId::DEFINGRCOT_ID)
        .value("eDEFINGRRGB_ID", DefFileId::DEFINGRRGB_ID)
        .value("eDEFINGRRLE_ID", DefFileId::DEFINGRRLE_ID)
        .value("eDEFINGRTG4_ID", DefFileId::DEFINGRTG4_ID)
        .value("eDEFINGRRASTER_ID", DefFileId::DEFINGRRASTER_ID)
        .value("eDEFPCXFILE_ID", DefFileId::DEFPCXFILE_ID)
        .value("eDEFPROCAPPL_ID", DefFileId::DEFPROCAPPL_ID)
        .value("eDEFRLC_ID", DefFileId::DEFRLC_ID)
        .value("eDEFSUNRASTER_ID", DefFileId::DEFSUNRASTER_ID)
        .value("eDEFTARGA_ID", DefFileId::DEFTARGA_ID)
        .value("eDEFBMP_ID", DefFileId::DEFBMP_ID)
        .value("eDEFREMAPFILE_ID", DefFileId::DEFREMAPFILE_ID)
        .value("eDEFBATCHCNVFILES_ID", DefFileId::DEFBATCHCNVFILES_ID)
        .value("eDEFMVBAFILE_ID", DefFileId::DEFMVBAFILE_ID)
        .value("eDEFEPXFILE_ID", DefFileId::DEFEPXFILE_ID)
        .value("eDEFBATCNVJOBSET_ID", DefFileId::DEFBATCNVJOBSET_ID)
        .value("eDEFBATPRCFILES_ID", DefFileId::DEFBATPRCFILES_ID)
        .value("eDEFBATPRCJOBFILE_ID", DefFileId::DEFBATPRCJOBFILE_ID)
        .value("eDEFBATPRCCMDFILE_ID", DefFileId::DEFBATPRCCMDFILE_ID)
        .value("eDEFJTFILE_ID", DefFileId::DEFJTFILE_ID)
        .value("eDEFMODELIMPORT_ID", DefFileId::DEFMODELIMPORT_ID)
        .value("eDEFDESIGNSEED_ID", DefFileId::DEFDESIGNSEED_ID)
        .value("eDEFSHEETSEED_ID", DefFileId::DEFSHEETSEED_ID)
        .value("eDEFDWGSHEETSEED_ID", DefFileId::DEFDWGSHEETSEED_ID)
        .value("eDEFSETTINGSTOV8_ID", DefFileId::DEFSETTINGSTOV8_ID)
        .value("eDEFBUTTONMENUFILE_ID", DefFileId::DEFBUTTONMENUFILE_ID)
        .value("eDEFPARMSETIMPORT_ID", DefFileId::DEFPARMSETIMPORT_ID)
        .value("eDEFPARMSETEXPORT_ID", DefFileId::DEFPARMSETEXPORT_ID)
        .value("eDEFSTDSCHECKER_ID", DefFileId::DEFSTDSCHECKER_ID)
        .value("eDEFSTDSDGNLIBS_ID", DefFileId::DEFSTDSDGNLIBS_ID)
        .value("eDEFDWGRECOVER_ID", DefFileId::DEFDWGRECOVER_ID)
        .value("eDEFSTDSREPORT_ID", DefFileId::DEFSTDSREPORT_ID)
        .value("eDEFDWGSETTINGS_ID", DefFileId::DEFDWGSETTINGS_ID)
        .value("eDEFLSTOOLS_ID", DefFileId::DEFLSTOOLS_ID)
        .value("eDEFXCHNGIMPORT_ID", DefFileId::DEFXCHNGIMPORT_ID)
        .value("eDEFXCHNGEXPORT_ID", DefFileId::DEFXCHNGEXPORT_ID)
        .value("eDEFU3DEXPORT_ID", DefFileId::DEFU3DEXPORT_ID)
        .value("eDEFRSTFILE_ID", DefFileId::DEFRSTFILE_ID)
        .value("eDEFCOLORBOOK_ID", DefFileId::DEFCOLORBOOK_ID)
        .value("eDEFPROJECTINDEX_ID", DefFileId::DEFPROJECTINDEX_ID)
        .value("eDEFRENDSOLUTION_ID", DefFileId::DEFRENDSOLUTION_ID)
        .value("eDEFEXPORT2D_ID", DefFileId::DEFEXPORT2D_ID)
        .value("eDEFEXPORT3D_ID", DefFileId::DEFEXPORT3D_ID)
        .value("eDEFONLYCELLS_ID", DefFileId::DEFONLYCELLS_ID)
        .value("eDEFLINKTARGET_ID", DefFileId::DEFLINKTARGET_ID)
        .value("eDEFKMLEXPORT_ID", DefFileId::DEFKMLEXPORT_ID)
        .value("eDEFKMLPLACEMARK_ID", DefFileId::DEFKMLPLACEMARK_ID)
        .value("eDEFFENCEFILE_ID", DefFileId::DEFFENCEFILE_ID)
        .value("eDEFMERGESOURCE_ID", DefFileId::DEFMERGESOURCE_ID)
        .value("eDEFMERGEDEST_ID", DefFileId::DEFMERGEDEST_ID)
        .value("eDEFKMLCAPTURE_ID", DefFileId::DEFKMLCAPTURE_ID)
        .value("eDEFSKPEXPORT_ID", DefFileId::DEFSKPEXPORT_ID)
        .value("eDEFCOLLADAEXPORT_ID", DefFileId::DEFCOLLADAEXPORT_ID)
        .value("eDEFMAXWELLEXPORT_ID", DefFileId::DEFMAXWELLEXPORT_ID)
        .value("eDEFMAXWELLMXM_ID", DefFileId::DEFMAXWELLMXM_ID)
        .value("eDEFMSPROJECTXMLFILE_ID", DefFileId::DEFMSPROJECTXMLFILE_ID)
        .value("eDEFMPXFILE_ID", DefFileId::DEFMPXFILE_ID)
        .value("eDEFOBJEXPORT_ID", DefFileId::DEFOBJEXPORT_ID)
        .value("eDEFP3TEXTFILE_ID", DefFileId::DEFP3TEXTFILE_ID)
        .value("eDEFPRCEXPORT_ID", DefFileId::DEFPRCEXPORT_ID)
        .value("eDEFPRINTSTYLEFILE_ID", DefFileId::DEFPRINTSTYLEFILE_ID)
        .value("eDEFGCSFROMFILE_ID", DefFileId::DEFGCSFROMFILE_ID)
        .value("eDEFANIMWMVFILE_ID", DefFileId::DEFANIMWMVFILE_ID)
        .value("eDEFANIMAVIFILE_ID", DefFileId::DEFANIMAVIFILE_ID)
        .value("eDEFPUBLISHDGNFILE_ID", DefFileId::DEFPUBLISHDGNFILE_ID)
        .value("eDEFKTEXPORT_ID", DefFileId::DEFKTEXPORT_ID)
        .value("eDEFLXOEXPORT_ID", DefFileId::DEFLXOEXPORT_ID)
        .value("eDEFMARKUPDGNFILE_ID", DefFileId::DEFMARKUPDGNFILE_ID)
        .value("eDEFOVERLAYDGNFILE_ID", DefFileId::DEFOVERLAYDGNFILE_ID)
        .value("eDEFLIGHTPROBEFILE_ID", DefFileId::DEFLIGHTPROBEFILE_ID)
        .value("eDEFRenderEnvironment", DefFileId::DEFRenderEnvironment)
        .value("eDEFLUXHISTORYDIR_ID", DefFileId::DEFLUXHISTORYDIR_ID)
        .value("eDEFDRAWINGSEED_ID", DefFileId::DEFDRAWINGSEED_ID)
        .value("eDEFCREATEDYNAMICVIEW_ID", DefFileId::DEFCREATEDYNAMICVIEW_ID)
        .value("eDEFDESIGNSCRIPTFILE_ID", DefFileId::DEFDESIGNSCRIPTFILE_ID)
        .value("eDEFPOINTCLOUDFILE_ID", DefFileId::DEFPOINTCLOUDFILE_ID)
        .value("eDEFINSOLATIONFILE_ID", DefFileId::DEFINSOLATIONFILE_ID)
        .value("eDEFSCHEDULELINKER_ID", DefFileId::DEFSCHEDULELINKER_ID)
        .value("eDEFWEATHERFILE_ID", DefFileId::DEFWEATHERFILE_ID)
        .value("eDEFCOMPOSERDGNFILE_ID", DefFileId::DEFCOMPOSERDGNFILE_ID)
        .value("eDEFGPXFILE_ID", DefFileId::DEFGPXFILE_ID)
        .value("eDEFXLSFILE_ID", DefFileId::DEFXLSFILE_ID)
        .value("eDEFDESCARTESTHEMATIC_ID", DefFileId::DEFDESCARTESTHEMATIC_ID)
        .value("eDEFPANOSET_ID", DefFileId::DEFPANOSET_ID)
        .value("eDEFFBXEXPORT_ID", DefFileId::DEFFBXEXPORT_ID)
        .value("eDEFSVGFILE_ID", DefFileId::DEFSVGFILE_ID)
        .value("eDEFSTMFILE_ID", DefFileId::DEFSTMFILE_ID)
        .value("eDEFPSDFILE_ID", DefFileId::DEFPSDFILE_ID)
        .value("eDEFINSOLATIONCSVFILE_ID", DefFileId::DEFINSOLATIONCSVFILE_ID)
        .value("eDEFANNOTATIONATTACHMENT_ID", DefFileId::DEFANNOTATIONATTACHMENT_ID)
        .value("eDEFXMLFILE_ID", DefFileId::DEFXMLFILE_ID)
        .value("eDEFICONDGNFILE_ID", DefFileId::DEFICONDGNFILE_ID)
        .value("eDEFICONBMPFILE_ID", DefFileId::DEFICONBMPFILE_ID)
        .value("eDEFICONAPPFILE_ID", DefFileId::DEFICONAPPFILE_ID)
        .value("eDEFPROPPUBFILTERFILE_ID", DefFileId::DEFPROPPUBFILTERFILE_ID)
        .value("eDEFIMODEMBEDFILE_ID", DefFileId::DEFIMODEMBEDFILE_ID)
        .value("eDEFTAGTEMPLATEFILE_ID", DefFileId::DEFTAGTEMPLATEFILE_ID)
        .value("eDEFITEMTYPELIB_ID", DefFileId::DEFITEMTYPELIB_ID)
        .value("eDEFFBXFILE_ID", DefFileId::DEFFBXFILE_ID)
        .value("eDEFU3DJSFILE_ID", DefFileId::DEFU3DJSFILE_ID)
        .value("eDEFMSWORDFILE_ID", DefFileId::DEFMSWORDFILE_ID)
        .value("eDEFMSEXCELFILE_ID", DefFileId::DEFMSEXCELFILE_ID)
        .value("eDEFPDFFILE_ID", DefFileId::DEFPDFFILE_ID)
        .value("eDEFRASTERLINESTYLE_ID", DefFileId::DEFRASTERLINESTYLE_ID)
        .value("eDEFMRMESHFILE_ID", DefFileId::DEFMRMESHFILE_ID)
        .value("eDEFFILTERLIBRARY_ID", DefFileId::DEFFILTERLIBRARY_ID)
        .value("eDEFDIALOGCENSUSXML_ID", DefFileId::DEFDIALOGCENSUSXML_ID)
        .value("eDEFMRMESHFILEPUBLISH_ID", DefFileId::DEFMRMESHFILEPUBLISH_ID)
        .value("eDEFVUEHISTORYDIR_ID", DefFileId::DEFVUEHISTORYDIR_ID)
        .value("eDEFVUEEXPORTDIR_ID", DefFileId::DEFVUEEXPORTDIR_ID)
        .value("eDEFDGNDWGDXF_ID", DefFileId::DEFDGNDWGDXF_ID)
        .value("eDEFTPFFILE_ID", DefFileId::DEFTPFFILE_ID)
        .value("eDEFDGNSIFILE_ID", DefFileId::DEFDGNSIFILE_ID)
        .value("eDEFSTPFILE_ID", DefFileId::DEFSTPFILE_ID)
        .value("eDEFLASTFILETYPE_ID", DefFileId::DEFLASTFILETYPE_ID)
        .value("eDEFPARASOLIDFILE_ID", DefFileId::DEFPARASOLIDFILE_ID)
        .value("eDEFIMPORTDGNFILE_ID", DefFileId::DEFIMPORTDGNFILE_ID)
        .value("eDEFSELECTBYRSC_ID", DefFileId::DEFSELECTBYRSC_ID)
        .value("eDEFRASTERFILE_ID", DefFileId::DEFRASTERFILE_ID)
        .value("eDEFIMAGESERVERFILE_ID", DefFileId::DEFIMAGESERVERFILE_ID)
        .value("eDEFPYFILE_ID", DefFileId::DEFPYFILE_ID)
        .value("eDEFFILE_LOWESTID", DefFileId::DEFFILE_LOWESTID)
        .export_values();

    }