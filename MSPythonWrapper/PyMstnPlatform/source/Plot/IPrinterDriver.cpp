
/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\IPrinterDriver.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>



static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputRaster_OutputRaster =R"doc(Output raster.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputPath_OutputPath =R"doc(Output path composed of lines and cubic bezier curves.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_OutputPolygonSet =R"doc(Output one or more filled polygons as a set.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_OutputLinestring =R"doc(Output linestring.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_SetLineCap =R"doc(Set output line cap.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_SetLineJoin =R"doc(Set output line join.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_SetLineStyleIndex =R"doc(Set output line style index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_SetWidth =R"doc(Set output width in dots.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverOutputVector_SetColor =R"doc(Set output color in RGBA.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_BorderText =R"doc(Draw border text.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_PopClip =R"doc(Restore the previous device clipping boundary.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_PushClip =R"doc(Push a new device clipping boundary.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_CheckStop =R"doc(Periodically called to give the driver the opportunity to abort print
processing.

Returns:
    false to continue processing; true to abort.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_DriverEndPlot =R"doc(Last IPrinterDriver method called before finishing print processing.

Remark:
    s The output file is still open and the driver may still write to
    it. Note that this method is called regardless of whether the job
    succeeded or failed.

Returns:
    SUCCESS to continue print processing; ERROR to abort.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_DriverBeginPlot =R"doc(Called just before print processing begins.

Returns:
    SUCCESS to continue print processing; ERROR to abort.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_DriverPreBeginPlot =R"doc(Called for each plot, before DriverBeginPlot, just before
IPrintEventHandler.PrePenChart.

Remark:
    s The print engine has not yet been completely initialized.

Returns:
    SUCCESS to continue print processing; ERROR to abort.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_DriverUnload =R"doc(Called when the printer driver configuration file is closed.

Remark:
    s May be called more than once during the lifespan of the DLL.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_DriverLoad =R"doc(Called after the printer driver configuration file is opened and all
.pltcfg commands have been executed.

Remark:
    s May be called more than once during the lifespan of the DLL.

Returns:
    SUCCESS to continue loading the driver; ERROR to abort.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrinterDriverBase_DriverPreLoad =R"doc(Called after the printer driver configuration file is opened, but
before any .pltcfg commands have been executed. Drivers are expected
to initialize all options configurable via .pltcfg commands to default
values.

Remark:
    s May be called more than once during the lifespan of the DLL.

Returns:
    SUCCESS to continue loading the driver; ERROR to abort.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IDriverEndPlotParam_IsSuccess =R"doc(True if print successful.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IDriverEndPlotParam_GetPrintEngine =R"doc(Gets the print engine interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IDriverBeginPlotParam_GetPrintEngine =R"doc(Gets the print engine interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IDriverPreBeginPlotParam_GetPrintEngine =R"doc(Gets the print engine interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetGlobalTransparency =R"doc(Raster global transparency.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetTransparentColor =R"doc(Raster transparency color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetTransparentIndex =R"doc(Raster transparency index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetTransparencyMode =R"doc(Raster transparency mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetIsGrayscale =R"doc(True if raster is to be printed in grayscale mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetPlotterRect =R"doc(Gets the raster output rectangle in dots.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetImageRect =R"doc(Gets the raster image rectangle in pixels.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetImageSize =R"doc(Gets the raster image size in pixels.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetPaletteSize =R"doc(Gets the raster palette size.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterParam_GetFormat =R"doc(Gets the raster format.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBorderTextParam_GetBackgroundColor =R"doc(Gets the plot background color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBorderTextParam_GetBorderColor =R"doc(Gets the border color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBorderTextParam_GetBorderWidth =R"doc(Gets the border width in dots.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBorderTextParam_GetIsLicenseLabelNeeded =R"doc(True if license label needed.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBorderTextParam_GetString =R"doc(Gets the border text string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotClipParam_ComputeRange =R"doc(Compute the clip range.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotClipParam_GetBorderWidth =R"doc(Gets the plot border width.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotClipParam_GetIsPlotBorder =R"doc(True if this clip boundary is for the plot border.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetTextBoundaryColor =R"doc(Gets the text boundary color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetIsTextBoundaryColorValid =R"doc(True if the text boundary color is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_IsTextGlyph =R"doc(True if this path is for a text glyph.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetOperators =R"doc(Get a pointer to the path operator buffer.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetTotalDPoints =R"doc(Gets a pointer to the path point buffer.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetTotalNumPoints =R"doc(Gets the total number of points across all operators.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_ContainsDisconnects =R"doc(True if the path contains disconnects.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_ContainsCurves =R"doc(True if the path contains bezier curves.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_IsFilled =R"doc(True if the path is filled.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_ResetCurrentOperator =R"doc(Resets the current operator to the beginning of the path.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetNextOperator =R"doc(Gets the next operator and optionally its vertices.

Parameter ``operatorVerticesP``:
    Vertices for next operator. May be NULL.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPathParam_GetNumOperators =R"doc(Gets the number of operators in this path.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPolygonSetParam_GetTextBoundaryColor =R"doc(Gets the text boundary color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPolygonSetParam_GetIsTextBoundaryColorValid =R"doc(True if the text boundary color is defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPolygonSetParam_IsTextGlyph =R"doc(True if this polygon set is for a text glyph.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPolygonSetParam_GetPolygon =R"doc(Gets the polygon for the given index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPolygonSetParam_GetTotalNumPoints =R"doc(Gets the total number of points across all polygons.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPolygonSetParam_GetNumPolygons =R"doc(Gets the number of polygons in this polygon set.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotDPoints_GetDPoints =R"doc(Gets the array of points.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotDPoints_GetNumPoints =R"doc(Gets the number of points.)doc";

//=======================================================================================
// Trampoline class for IPlotDPoints.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotDPoints : IPlotDPoints
{
public:
    using IPlotDPoints::IPlotDPoints;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumPoints() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotDPoints, GetNumPoints, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2dCP GetDPoints() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(DPoint2dCP, IPlotDPoints, GetDPoints, nullptr,);
    }

};


//=======================================================================================
// Trampoline class for IPlotPolygonSetParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPolygonSetParam : IPlotPolygonSetParam
{
public:
    using IPlotPolygonSetParam::IPlotPolygonSetParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumPolygons() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotPolygonSetParam, GetNumPolygons,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetTotalNumPoints() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotPolygonSetParam, GetTotalNumPoints, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotDPointsP GetPolygon(int polygonIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotDPointsP, IPlotPolygonSetParam, GetPolygon, nullptr, polygonIndex);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsTextGlyph() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPolygonSetParam, IsTextGlyph, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsTextBoundaryColorValid() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPolygonSetParam, GetIsTextBoundaryColorValid, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetTextBoundaryColor() override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotPolygonSetParam, GetTextBoundaryColor, );
    }
};

//=======================================================================================
// Trampoline class for IPlotPathParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct TransitPlotDpoints : IPlotDPoints
{
    bvector<DPoint2d> m_plotDpt;

   ~TransitPlotDpoints() { m_plotDpt.clear(); }
    TransitPlotDpoints(DPoint2dCP ptArray, int num)
        {
        for (int i = 0; i < num; i++)
            m_plotDpt.push_back(ptArray[i]);
        }

    virtual int GetNumPoints() const override
        {
        return (int)m_plotDpt.size();
        }

    virtual DPoint2dCP GetDPoints() const override
        {
        if (m_plotDpt.size() > 0)
            return (DPoint2dCP)(m_plotDpt.data());

        return nullptr;
        }
};

struct IPyPlotPathParam : IPlotPathParam
{
public:
    using IPlotPathParam::IPlotPathParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumOperators() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotPathParam, GetNumOperators, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPathOperator GetNextOperator(IPlotDPointsP* operatorVerticesP) override
    {
        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetNextOperator");
            if (func)
                {
                auto obj = func();
                auto tuple = obj.cast<py::tuple>();

                if (!py::isinstance<PlotPathOperator>(tuple[0]) || !py::isinstance<IPlotDPoints>(tuple[1]))
                    return PlotPathOperator::Undefined;

                auto pathOpera = tuple[0].cast<PlotPathOperator>();
                auto plotDPointsP = tuple[1].cast<IPlotDPointsP>(); 
                if (plotDPointsP)
                    {
                    static TransitPlotDpoints* plotPtsP = nullptr; //Use static to keep consistent with the behavior of PYBIND11_OVERRIDE_*
                    if (plotPtsP)
                        delete plotPtsP;
                    
                    plotPtsP = new TransitPlotDpoints(plotDPointsP->GetDPoints(), plotDPointsP->GetNumPoints());
                    operatorVerticesP = (IPlotDPointsP*)(&plotPtsP); //Caller needs to release
                    }

                return pathOpera;
                }
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        return PlotPathOperator::Undefined;
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void ResetCurrentOperator() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotPathParam, ResetCurrentOperator,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsFilled() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPathParam, IsFilled, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool ContainsCurves() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPathParam, ContainsCurves, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool ContainsDisconnects() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPathParam, ContainsDisconnects, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetTotalNumPoints() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotPathParam, GetTotalNumPoints, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2dCP GetTotalDPoints() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(DPoint2dCP, IPlotPathParam, GetTotalDPoints, nullptr,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual CharCP GetOperators() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(CharCP, IPlotPathParam, GetOperators, nullptr, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsTextGlyph() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPathParam, IsTextGlyph, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsTextBoundaryColorValid() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPathParam, GetIsTextBoundaryColorValid, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetTextBoundaryColor() override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotPathParam, GetTextBoundaryColor, );
    }
};

//=======================================================================================
// Trampoline class for IPlotClipParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotClipParam : IPlotClipParam
{
public:
    using IPlotClipParam::IPlotClipParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumPolygons() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotClipParam, GetNumPolygons, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetTotalNumPoints() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotClipParam, GetTotalNumPoints, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotDPointsP GetPolygon(int polygonIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotDPointsP, IPlotClipParam, GetPolygon, nullptr, polygonIndex);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsTextGlyph() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotClipParam, IsTextGlyph, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsTextBoundaryColorValid() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotClipParam, GetIsTextBoundaryColorValid, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetTextBoundaryColor() override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotClipParam, GetTextBoundaryColor, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPlotBorder() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotClipParam, GetIsPlotBorder, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetBorderWidth() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotClipParam, GetBorderWidth, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DRange2d ComputeRange() const override
    {
        PYBIND11_OVERRIDE_PURE(DRange2d, IPlotClipParam, ComputeRange, );
    }
};

//=======================================================================================
// Trampoline class for IPlotBorderTextParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotBorderTextParam : IPlotBorderTextParam
{
public:
    using IPlotBorderTextParam::IPlotBorderTextParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual WCharCP GetString() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IPlotBorderTextParam, GetString, nullptr,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsLicenseLabelNeeded() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotBorderTextParam, GetIsLicenseLabelNeeded, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetBorderWidth() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotBorderTextParam, GetBorderWidth, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbaColorDef GetBorderColor() const override
    {
        PYBIND11_OVERRIDE_PURE(RgbaColorDef, IPlotBorderTextParam, GetBorderColor, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbaColorDef GetBackgroundColor() const override
    {
        PYBIND11_OVERRIDE_PURE(RgbaColorDef, IPlotBorderTextParam, GetBackgroundColor, );
    }
};

//=======================================================================================
// Trampoline class for IPlotRasterParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotRasterParam : IPlotRasterParam
{
private:

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    byte* GetByteCache(std::string methodName)
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, methodName.c_str());
            if (func)
                {
                py::bytes outData = func();
                std::string strData = outData.cast<std::string>();
                size_t imageSize = strData.size();
                if (imageSize < 1)
                    return nullptr;

                static byte* imageP = nullptr; //Use static to keep consistent with the behavior of PYBIND11_OVERRIDE_*
                if (imageP)
                    delete[] imageP;
                
                imageP = new byte[imageSize]; //Caller needs to release cache
                memcpy(imageP, (const void*)strData.data(), imageSize);

                return imageP;
                }
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        return nullptr;
        }

public:
    using IPlotRasterParam::IPlotRasterParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotRasterFormat GetFormat() override
    {
        PYBIND11_OVERRIDE_PURE(PlotRasterFormat, IPlotRasterParam, GetFormat, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual byte* GetImage() override
    {
        return GetByteCache("GetImage");
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetPaletteSize() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotRasterParam, GetPaletteSize, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual byte* GetRedMap() override
    {
        return GetByteCache("GetRedMap");
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual byte* GetGreenMap() override
    {
        return GetByteCache("GetGreenMap");
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual byte* GetBlueMap() override
    {
        return GetByteCache("GetBlueMap");
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Point2dCR GetImageSize() override
    {
        PYBIND11_OVERRIDE_PURE(Point2dCR, IPlotRasterParam, GetImageSize, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DRange2dCR GetImageRect() override
    {
        PYBIND11_OVERRIDE_PURE(DRange2dCR, IPlotRasterParam, GetImageRect, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DRange2dCR GetPlotterRect() override
    {
        PYBIND11_OVERRIDE_PURE(DRange2dCR, IPlotRasterParam, GetPlotterRect, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsGrayscale() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotRasterParam, GetIsGrayscale, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotRasterTransparency GetTransparencyMode() override
    {
        PYBIND11_OVERRIDE_PURE(PlotRasterTransparency, IPlotRasterParam, GetTransparencyMode, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetTransparentIndex() override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotRasterParam, GetTransparentIndex, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbColorDef GetTransparentColor() override
    {
        PYBIND11_OVERRIDE_PURE(RgbColorDef, IPlotRasterParam, GetTransparentColor, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UShort** GetTransparentMask() override
    {
        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetTransparentMask");
            if (func)
                {
                auto outData = func();
                if (!py::isinstance<UInt16Array>(outData))
                    return nullptr;

                UInt16Array transMask = outData.cast<UInt16Array>();
                size_t mskSize = transMask.size();

                if (mskSize < 1) 
                    return nullptr;

                static UShort* mskP = nullptr; //Use static to keep consistent with the behavior of PYBIND11_OVERRIDE_*
                if (mskP)
                    delete[] mskP;
                
                mskP = new UShort[mskSize]; //Caller needs to release cache
                memcpy(mskP, (const void*)transMask.data(), mskSize);

                return &mskP;
                }
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        return nullptr;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetGlobalTransparency() override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotRasterParam, GetGlobalTransparency, );
    }
};

//=======================================================================================
// Trampoline class for IDriverPreBeginPlotParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyDriverPreBeginPlotParam : IDriverPreBeginPlotParam
{
public:
    using IDriverPreBeginPlotParam::IDriverPreBeginPlotParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineP GetPrintEngine() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineP, IDriverPreBeginPlotParam, GetPrintEngine, nullptr,);
    }
};

//=======================================================================================
// Trampoline class for IDriverBeginPlotParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyDriverBeginPlotParam : IDriverBeginPlotParam
{
public:
    using IDriverBeginPlotParam::IDriverBeginPlotParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineP GetPrintEngine() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineP, IDriverBeginPlotParam, GetPrintEngine, nullptr, );
    }
};

//=======================================================================================
// Trampoline class for IDriverEndPlotParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyDriverEndPlotParam : IDriverEndPlotParam
{
public:
    using IDriverEndPlotParam::IDriverEndPlotParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineP GetPrintEngine() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineP, IDriverEndPlotParam, GetPrintEngine, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsSuccess() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IDriverEndPlotParam, IsSuccess, );
    }
};


//=======================================================================================
// Trampoline class for IPrinterDriverBase.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrinterDriverBase : IPrinterDriverBase
{
public:
    using IPrinterDriverBase::IPrinterDriverBase;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt DriverPreLoad() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrinterDriverBase, DriverPreLoad, ERROR,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt DriverLoad(IPlotterP plotter) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrinterDriverBase, DriverLoad, ERROR, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void DriverUnload() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverBase, DriverUnload, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt DriverPreBeginPlot(IDriverPreBeginPlotParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrinterDriverBase, DriverPreBeginPlot, ERROR, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt DriverBeginPlot(IDriverBeginPlotParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrinterDriverBase, DriverBeginPlot, ERROR, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt DriverEndPlot(IDriverEndPlotParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrinterDriverBase, DriverEndPlot, ERROR, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool CheckStop() override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrinterDriverBase, CheckStop,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PushClip(IPlotClipParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverBase, PushClip, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PopClip() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverBase, PopClip,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void BorderText(IPlotBorderTextParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverBase, BorderText, param);
    }
};

//=======================================================================================
// Trampoline class for IPrinterDriverOutputVector.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrinterDriverOutputVector : IPrinterDriverOutputVector
{
public:
    using IPrinterDriverOutputVector::IPrinterDriverOutputVector;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetColor(RgbaColorDef color) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, SetColor, color);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetWidth(int widthDots) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, SetWidth, widthDots);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineStyleIndex(int lineStyleIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, SetLineStyleIndex, lineStyleIndex);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineJoin(PlotLineJoin lineJoin) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, SetLineJoin, lineJoin);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineCap(PlotLineCap lineCap) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, SetLineCap, lineCap);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OutputLinestring(IPlotDPointsP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, OutputLinestring, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OutputPolygonSet(IPlotPolygonSetParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputVector, OutputPolygonSet, param);
    }
};

//=======================================================================================
// Trampoline class for IPrinterDriverOutputPath.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrinterDriverOutputPath : IPrinterDriverOutputPath
{
public:
    using IPrinterDriverOutputPath::IPrinterDriverOutputPath;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetColor(RgbaColorDef color) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, SetColor, color);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetWidth(int widthDots) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, SetWidth, widthDots);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineStyleIndex(int lineStyleIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, SetLineStyleIndex, lineStyleIndex);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineJoin(PlotLineJoin lineJoin) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, SetLineJoin, lineJoin);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineCap(PlotLineCap lineCap) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, SetLineCap, lineCap);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OutputLinestring(IPlotDPointsP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, OutputLinestring, param);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OutputPolygonSet(IPlotPolygonSetParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, OutputPolygonSet, param);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OutputPath(IPlotPathParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputPath, OutputPath, param);
    }
};

//=======================================================================================
// Trampoline class for IPrinterDriverOutputRaster.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrinterDriverOutputRaster : IPrinterDriverOutputRaster
{
public:
    using IPrinterDriverOutputRaster::IPrinterDriverOutputRaster;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OutputRaster(IPlotRasterParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrinterDriverOutputRaster, OutputRaster, param);
    }
};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPrinterDriver(py::module_& m)
    {
    //===================================================================================
    // enum class PlotPathOperator
    py::enum_<PlotPathOperator>(m, "PlotPathOperator")
      .value("eUndefined", PlotPathOperator::Undefined)
      .value("eMoveTo", PlotPathOperator::MoveTo)
      .value("eLineTo", PlotPathOperator::LineTo)
      .value("eBezierTo", PlotPathOperator::BezierTo)
      .export_values();

    //===================================================================================
    // enum class PlotRasterFormat    
    py::enum_<PlotRasterFormat>(m, "PlotRasterFormat")
      .value("eBitMap", PlotRasterFormat::BitMap)
      .value("eByteMap", PlotRasterFormat::ByteMap)
      .value("eRGBSeparate", PlotRasterFormat::RGBSeparate)
      .value("eRGBA", PlotRasterFormat::RGBA)
      .export_values();

    //===================================================================================
    // enum class PlotRasterTransparency    
    py::enum_<PlotRasterTransparency>(m, "PlotRasterTransparency")
      .value("eNone", PlotRasterTransparency::None)
      .value("eColor", PlotRasterTransparency::Color)
      .value("eMask", PlotRasterTransparency::Mask)
     .export_values();

    //===================================================================================
    //class IPlotDPoints
    py::class_<IPlotDPoints, IPyPlotDPoints> c0(m, "IPlotDPoints");
    c0.def(py::init<>());

    c0.def("GetNumPoints", &IPlotDPoints::GetNumPoints, DOC(Bentley, MstnPlatform, Print, IPlotDPoints, GetNumPoints));
    c0.def("GetDPoints", &IPlotDPoints::GetDPoints, DOC(Bentley, MstnPlatform, Print, IPlotDPoints, GetDPoints));

    //===================================================================================
    //class IPlotPolygonSetParam
    py::class_<IPlotPolygonSetParam, IPyPlotPolygonSetParam> c1(m, "IPlotPolygonSetParam");
    c1.def(py::init<>());

    c1.def("GetNumPolygons", &IPlotPolygonSetParam::GetNumPolygons, DOC(Bentley, MstnPlatform, Print, IPlotPolygonSetParam, GetNumPolygons));
    c1.def("GetTotalNumPoints", &IPlotPolygonSetParam::GetTotalNumPoints, DOC(Bentley, MstnPlatform, Print, IPlotPolygonSetParam, GetTotalNumPoints));
    c1.def("GetPolygon", &IPlotPolygonSetParam::GetPolygon, "polygonIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotPolygonSetParam, GetPolygon));
    c1.def("IsTextGlyph", &IPlotPolygonSetParam::IsTextGlyph, DOC(Bentley, MstnPlatform, Print, IPlotPolygonSetParam, IsTextGlyph));
    c1.def("GetIsTextBoundaryColorValid", &IPlotPolygonSetParam::GetIsTextBoundaryColorValid, DOC(Bentley, MstnPlatform, Print, IPlotPolygonSetParam, GetIsTextBoundaryColorValid));
    c1.def("GetTextBoundaryColor", &IPlotPolygonSetParam::GetTextBoundaryColor, DOC(Bentley, MstnPlatform, Print, IPlotPolygonSetParam, GetTextBoundaryColor));

    //===================================================================================
    //class IPlotPathParam
    py::class_<IPlotPathParam, IPyPlotPathParam> c2(m, "IPlotPathParam");
    c2.def(py::init<>());

    c2.def("GetNumOperators", &IPlotPathParam::GetNumOperators, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetNumOperators));
    c2.def("GetNextOperator", [](IPlotPathParam const& self)->py::tuple
        {
        py::tuple outVal;
        outVal = py::cast(std::make_tuple(PlotPathOperator::Undefined, (IPlotDPointsP)nullptr));
        return outVal;
        }, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetNextOperator));

    c2.def("ResetCurrentOperator", &IPlotPathParam::ResetCurrentOperator, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, ResetCurrentOperator));
    c2.def("IsFilled", &IPlotPathParam::IsFilled, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, IsFilled));
    c2.def("ContainsCurves", &IPlotPathParam::ContainsCurves, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, ContainsCurves));
    c2.def("ContainsDisconnects", &IPlotPathParam::ContainsDisconnects, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, ContainsDisconnects));
    c2.def("GetTotalNumPoints", &IPlotPathParam::GetTotalNumPoints, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetTotalNumPoints));
    c2.def("GetTotalDPoints", &IPlotPathParam::GetTotalDPoints, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetTotalDPoints));
    c2.def("GetOperators", &IPlotPathParam::GetOperators, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetOperators));
    c2.def("IsTextGlyph", &IPlotPathParam::IsTextGlyph, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, IsTextGlyph));
    c2.def("GetIsTextBoundaryColorValid", &IPlotPathParam::GetIsTextBoundaryColorValid, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetIsTextBoundaryColorValid));
    c2.def("GetTextBoundaryColor", &IPlotPathParam::GetTextBoundaryColor, DOC(Bentley, MstnPlatform, Print, IPlotPathParam, GetTextBoundaryColor));

    //===================================================================================
    //class IPlotClipParam
    py::class_<IPlotClipParam, IPlotPolygonSetParam, IPyPlotClipParam> c3(m, "IPlotClipParam");
    c3.def(py::init<>());

    c3.def("GetIsPlotBorder", &IPlotClipParam::GetIsPlotBorder, DOC(Bentley, MstnPlatform, Print, IPlotClipParam, GetIsPlotBorder));
    c3.def("GetBorderWidth", &IPlotClipParam::GetBorderWidth, DOC(Bentley, MstnPlatform, Print, IPlotClipParam, GetBorderWidth));
    c3.def("ComputeRange", &IPlotClipParam::ComputeRange, DOC(Bentley, MstnPlatform, Print, IPlotClipParam, ComputeRange));

    //===================================================================================
    //class IPlotBorderTextParam
    py::class_<IPlotBorderTextParam, IPyPlotBorderTextParam> c4(m, "IPlotBorderTextParam");
    c4.def(py::init<>());

    c4.def("GetString", &IPlotBorderTextParam::GetString, DOC(Bentley, MstnPlatform, Print, IPlotBorderTextParam, GetString));
    c4.def("GetIsLicenseLabelNeeded", &IPlotBorderTextParam::GetIsLicenseLabelNeeded, DOC(Bentley, MstnPlatform, Print, IPlotBorderTextParam, GetIsLicenseLabelNeeded));
    c4.def("GetBorderWidth", &IPlotBorderTextParam::GetBorderWidth, DOC(Bentley, MstnPlatform, Print, IPlotBorderTextParam, GetBorderWidth));
    c4.def("GetBorderColor", &IPlotBorderTextParam::GetBorderColor, DOC(Bentley, MstnPlatform, Print, IPlotBorderTextParam, GetBorderColor));
    c4.def("GetBackgroundColor", &IPlotBorderTextParam::GetBackgroundColor, DOC(Bentley, MstnPlatform, Print, IPlotBorderTextParam, GetBackgroundColor));

    //===================================================================================
    //class IPlotRasterParam
    py::class_<IPlotRasterParam, IPyPlotRasterParam> c5(m, "IPlotRasterParam");
    c5.def(py::init<>());

    c5.def("GetFormat", &IPlotRasterParam::GetFormat, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetFormat));
    c5.def("GetImage", [](IPlotRasterParam const& self)->py::bytes {return py::bytes();});
    c5.def("GetPaletteSize", &IPlotRasterParam::GetPaletteSize, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetPaletteSize));
    c5.def("GetRedMap", [](IPlotRasterParam const& self)->py::bytes {return py::bytes();});
    c5.def("GetGreenMap", [](IPlotRasterParam const& self)->py::bytes {return py::bytes(); });
    c5.def("GetBlueMap", [](IPlotRasterParam const& self)->py::bytes {return py::bytes(); });
    c5.def("GetImageSize", &IPlotRasterParam::GetImageSize, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetImageSize));
    c5.def("GetImageRect", &IPlotRasterParam::GetImageRect, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetImageRect));
    c5.def("GetPlotterRect", &IPlotRasterParam::GetPlotterRect, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetPlotterRect));
    c5.def("GetIsGrayscale", &IPlotRasterParam::GetIsGrayscale, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetIsGrayscale));
    c5.def("GetTransparencyMode", &IPlotRasterParam::GetTransparencyMode, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetTransparencyMode));
    c5.def("GetTransparentIndex", &IPlotRasterParam::GetTransparentIndex, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetTransparentIndex));
    c5.def("GetTransparentColor", &IPlotRasterParam::GetTransparentColor, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetTransparentColor));
    c5.def("GetTransparentMask", [](IPlotRasterParam const& self)->UInt16Array {return UInt16Array(); });
    c5.def("GetGlobalTransparency", &IPlotRasterParam::GetGlobalTransparency, DOC(Bentley, MstnPlatform, Print, IPlotRasterParam, GetGlobalTransparency));

    //===================================================================================
    //class IDriverPreBeginPlotParam
    py::class_<IDriverPreBeginPlotParam, IPyDriverPreBeginPlotParam> c6(m, "IDriverPreBeginPlotParam");
    c6.def(py::init<>());

    c6.def("GetPrintEngine", &IDriverPreBeginPlotParam::GetPrintEngine, DOC(Bentley, MstnPlatform, Print, IDriverPreBeginPlotParam, GetPrintEngine));

    //===================================================================================
    //class IDriverPreBeginPlotParam
    py::class_<IDriverBeginPlotParam, IPyDriverBeginPlotParam> c7(m, "IDriverBeginPlotParam");
    c7.def(py::init<>());

    c7.def("GetPrintEngine", &IDriverBeginPlotParam::GetPrintEngine, DOC(Bentley, MstnPlatform, Print, IDriverBeginPlotParam, GetPrintEngine));

    //===================================================================================
    //class IDriverEndPlotParam
    py::class_<IDriverEndPlotParam, IPyDriverEndPlotParam> c8(m, "IDriverEndPlotParam");
    c8.def(py::init<>());

    c8.def("GetPrintEngine", &IDriverEndPlotParam::GetPrintEngine, DOC(Bentley, MstnPlatform, Print, IDriverEndPlotParam, GetPrintEngine));
    c8.def("IsSuccess", &IDriverEndPlotParam::IsSuccess, DOC(Bentley, MstnPlatform, Print, IDriverEndPlotParam, IsSuccess));

    //===================================================================================
    //class IPrinterDriverBase
    py::class_<IPrinterDriverBase, IPyPrinterDriverBase> c9(m, "IPrinterDriverBase");
    c9.def(py::init<>());

    c9.def("DriverPreLoad", &IPrinterDriverBase::DriverPreLoad, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, DriverPreLoad));
    c9.def("DriverLoad", &IPrinterDriverBase::DriverLoad, "plotter"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, DriverLoad));
    c9.def("DriverUnload", &IPrinterDriverBase::DriverUnload, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, DriverUnload));
    c9.def("DriverPreBeginPlot", &IPrinterDriverBase::DriverPreBeginPlot, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, DriverPreBeginPlot));
    c9.def("DriverBeginPlot", &IPrinterDriverBase::DriverBeginPlot, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, DriverBeginPlot));
    c9.def("DriverEndPlot", &IPrinterDriverBase::DriverEndPlot, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, DriverEndPlot));
    c9.def("CheckStop", &IPrinterDriverBase::CheckStop, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, CheckStop));
    c9.def("PushClip", &IPrinterDriverBase::PushClip, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, PushClip));
    c9.def("PopClip", &IPrinterDriverBase::PopClip, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, PopClip));
    c9.def("BorderText", &IPrinterDriverBase::BorderText, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverBase, BorderText));

    //===================================================================================
    //class IPrinterDriverOutputVector
    py::class_<IPrinterDriverOutputVector, IPyPrinterDriverOutputVector> c10(m, "IPrinterDriverOutputVector");
    c10.def(py::init<>());

    c10.def("SetColor", &IPrinterDriverOutputVector::SetColor, "color"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, SetColor));
    c10.def("SetWidth", &IPrinterDriverOutputVector::SetWidth, "widthDots"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, SetWidth));
    c10.def("SetLineStyleIndex", &IPrinterDriverOutputVector::SetLineStyleIndex, "lineStyleIndex"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, SetLineStyleIndex));
    c10.def("SetLineJoin", &IPrinterDriverOutputVector::SetLineJoin, "lineJoin"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, SetLineJoin));
    c10.def("SetLineCap", &IPrinterDriverOutputVector::SetLineCap, "lineCap"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, SetLineCap));
    c10.def("OutputLinestring", &IPrinterDriverOutputVector::OutputLinestring, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, OutputLinestring));
    c10.def("OutputPolygonSet", &IPrinterDriverOutputVector::OutputPolygonSet, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputVector, OutputPolygonSet));

    //===================================================================================
    //class IPrinterDriverOutputVector
    py::class_<IPrinterDriverOutputPath, IPrinterDriverOutputVector, IPyPrinterDriverOutputPath> c11(m, "IPrinterDriverOutputPath");
    c11.def(py::init<>());

    c11.def("OutputPath", &IPrinterDriverOutputPath::OutputPath, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputPath, OutputPath));

    //===================================================================================
    //class IPrinterDriverOutputVector
    py::class_<IPrinterDriverOutputRaster, IPyPrinterDriverOutputRaster> c12(m, "IPrinterDriverOutputRaster");
    c12.def(py::init<>());

    c12.def("OutputRaster", &IPrinterDriverOutputRaster::OutputRaster, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrinterDriverOutputRaster, OutputRaster));

    m.def("RegisterIPrinterDriver", &mdlPlot_registerIPrinterDriver, "printerDriver"_a);
    }
