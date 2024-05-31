/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\bsiquadrature.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/BSIQuadrature.h>



static const char * __doc_Bentley_Geom_BSITriangleQuadraturePoints_GetNumEval =R"doc(@description Return the number of points in the quadrature rule.)doc";

static const char * __doc_Bentley_Geom_BSITriangleQuadraturePoints_GetEval =R"doc(@description Get the coordinates and weight of the i'th quadrature
point

Parameter ``[in]``:
    i index of evaluation point.

Parameter ``[out]``:
    u evaluation coordinate.

Parameter ``[out]``:
    v evaluation coordinate.

Parameter ``[out]``:
    w weight.

Returns:
    false if index is out of range.)doc";

static const char * __doc_Bentley_Geom_BSITriangleQuadraturePoints_InitStrang =R"doc(@description Setup for a " Strang " rule as defined in http://people.sc.
fsu.edu/~jburkardt/datasets/quadrature_rules_tri/quadrature_rules_tri.
html

Parameter ``[in]``:
    selector rule selector.

Remark:
    s; Selectors are:(1 --- centroid; exact degree 1) (2 --- 3
    midsides; exact degree 2) (3 --- centroid and one towards each
    vertex; exact degree 3) (4 --- 6 points, vertices and midsides of
    an inset triangle; exact degree 3) (5 --- 6 points, 2 inset from
    each edge; exact degree 4) (6 --- 7 points, centroid and 2 insets
    from each edge -- insets equally weighted; exact degree 4) (7 ---
    7 points, centroid, one towards each vertex, one towards each
    edge; exact degree 5) (8 --- 9 points; exact degree 6) (9 --- 12
    points; exact degree 6) (10 --- 13 points -- negative weight at
    centroid; exact degree 7))doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_IntegrateWithRombergExtrapolation =R"doc(@description Integrate over an interval.

* In each interval, form gauss sums with one and then two
subintervals.

* Apply 1 step Romberg (Richardson) extrapolation.

* Accept the extrapolation as that interval's contribution.

* Accumulate the max extrapolation as error bound.

* The ongoing integration at the end of each interval,

* exit if the announcement function returns false

* The caller is can capture sums as announced

Parameter ``[in]``:
    function function object that can be called as often as needed.

Parameter ``[in]``:
    t0 start of interval.

Parameter ``[in]``:
    t1 end of interval.

Parameter ``[in]``:
    numInterval number of intervals to use within t0..t1.

Parameter ``[out]``:
    totalErrorBound

Returns:
    false if function.AnnounceIntermediateIntergral () returned false.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+------)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_AccumulateWeightedSums =R"doc(@description Evaluate and accumulate function values over an interval.

Parameter ``[in]``:
    function function object that can be called as often as needed.

Parameter ``[in]``:
    t0 start of interval.

Parameter ``[in]``:
    t1 end of interval.

Parameter ``[in,out]``:
    pSums accumulating sums.

Parameter ``[in]``:
    numInterval number of intervals to use within t0..t1.)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_GetConvergencePower =R"doc(@description Return the exponent for the convergence rate of the rule.)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_GetNumEval =R"doc(@description Return the number of points in the quadrature rule.)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_GetXYEval =R"doc(Get the coordinates and weight of quarature point (i,j) in a 2D
rectangular domain with specified quadrature for each direction.

Parameter ``[in]``:
    xRule x direction quadrature rule

Parameter ``[in]``:
    ix point index in x rule.

Parameter ``[in]``:
    x0 started of x mapped interval

Parameter ``[in]``:
    x1 end of x mapped interval

Parameter ``[in]``:
    yRule y direction quadrature rule.

Parameter ``[in]``:
    iy point index in y rule.

Parameter ``[in]``:
    y0 start of y mapped interval

Parameter ``[in]``:
    y1 end of y mapped interval

Parameter ``[out]``:
    x x coordinate to evaluate.

Parameter ``[out]``:
    y y coordinate to evaluate.

Parameter ``[out]``:
    w weight for sums)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_GetEval =R"doc(@description Get the coordinate a weight of the i'th quadrature point,
mapped to interval a0..a1

Parameter ``[in]``:
    i index of evaluation point.

Parameter ``[in]``:
    a0 start of mapped interval.

Parameter ``[in]``:
    a1 end of mapped interval.

Parameter ``[out]``:
    a evaluation coordinate.

Parameter ``[out]``:
    w weight. Both the local quadrature weight and the interval length
    are incorporated in the returned weight.

Returns:
    false if index is out of range.)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_InitGaussKronrod =R"doc(@description Setup for a " Kronrod " part of Gauss-Kronrad quadrature.
The simple Gauss x values appear (in order) at the odd positions of
the Kronrod rule.

Parameter ``numEval``:
    IN requested number of points. ONLY 7 IS SUPPORTED

Parameter ``gaussPartner``:
    IN corresponding simple Gauss rule.

Returns:
    Number of points actually to be used.)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_InitGaussLobatto =R"doc(@description Setup for " Gauss - Lobatto " quadrature. This uses endpoints
plus gauss-like interior points.

Parameter ``[in]``:
    numEval requested number of points.

Remark:
    s numEval may be 3, 4, and 5.

Remark:
    s numEval == 3 is the same as " Simpson ")doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_InitGauss =R"doc(@description Setup for a " Gaussian " quadrature.

Parameter ``[in]``:
    numEval requested number of points.

Returns:
    Number of points actually to be used. max is 5)doc";

static const char * __doc_Bentley_Geom_BSIQuadraturePoints_InitUniform =R"doc(@description Setup for a " Newton - Cotes " regularly spaced quadrature.

Remark:
    Gaussian quadrature points are usually more effective. numEval ==
    1 is " rectangle rule " numEval == 2 is " trapezoid rule " numEval ==
    3 is " Simpson s rule "

Parameter ``[in]``:
    numEval requested number of points.

Returns:
    Number of points actually to be used. max is 4)doc";

USING_NAMESPACE_BENTLEY_MSTNPLATFORM_MSPYTHON

//=======================================================================================
// Trampoline class for BSIVectorIntegrand.
// @bsiclass                                                                   02/23
//=======================================================================================
class PyBSIVectorIntegrand : public BSIVectorIntegrand
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void EvaluateVectorIntegrand(double t, double* pF) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "EvaluateVectorIntegrand");
                if (func)
                    {
                    int nItem = GetVectorIntegrandCount();
                    if (nItem > 0)
                        {
                        DoubleArray pF_(nItem, 0);
                        func(t, pF_);
                        memcpy((void*) pF, (const void*) pF_.data(), sizeof(double) * nItem);
                        }
                    }
                else
                    pybind11::pybind11_fail("Tried to call pure virtual function BSIVectorIntegrand::EvaluateVectorIntegrand");
                }
            catch (std::exception& err)
                {
                ScriptEngineManager::Get().InjectException(err);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int GetVectorIntegrandCount() override
            { PYBIND11_OVERRIDE_PURE_EXR(int, BSIVectorIntegrand, GetVectorIntegrandCount, 0, ); }
    };

//=======================================================================================
// Trampoline class for BSIIncrementalVectorIntegrand.
// @bsiclass                                                                   02/23
//=======================================================================================
class PyBSIIncrementalVectorIntegrand : public BSIIncrementalVectorIntegrand
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void EvaluateVectorIntegrand(double t, double* pF) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "EvaluateVectorIntegrand");
                if (func)
                    {
                    int nItem = GetVectorIntegrandCount();
                    if (nItem > 0)
                        {
                        DoubleArray pF_(nItem, 0);
                        func(t, pF_);
                        memcpy((void*) pF, (const void*) pF_.data(), sizeof(double) * nItem);
                        }
                    }
                else
                    pybind11::pybind11_fail("Tried to call pure virtual function BSIIncrementalVectorIntegrand::EvaluateVectorIntegrand");
                }
            catch (std::exception& err)
                {
                ScriptEngineManager::Get().InjectException(err);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int GetVectorIntegrandCount() override
            { PYBIND11_OVERRIDE_PURE_EXR(int, BSIIncrementalVectorIntegrand, GetVectorIntegrandCount, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool AnnounceIntermediateIntegral(double t, double* pIntegrals) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "AnnounceIntermediateIntegral");
                bool retVal = false;
                if (func)
                    {
                    int nItem = GetVectorIntegrandCount();
                    if (nItem > 0)
                        {
                        DoubleArray pIntegrals_(nItem, 0);
                        auto obj = func(t, pIntegrals_);
                        retVal = obj.cast<bool>();
                        memcpy((void*) pIntegrals, (const void*) pIntegrals_.data(), sizeof(double) * nItem);
                        }
                    }
                else
                    pybind11::pybind11_fail("Tried to call pure virtual function BSIIncrementalVectorIntegrand::AnnounceIntermediateIntegral");

                return retVal;
                }
            catch (std::exception& err)
                {
                ScriptEngineManager::Get().InjectException(err);
                return false;
                }
            }
    };

//=======================================================================================
// Trampoline class for BSIVectorIntegrandXY.
// @bsiclass                                                                   02/23
//=======================================================================================
class PyBSIVectorIntegrandXY : public BSIVectorIntegrandXY
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void EvaluateVectorIntegrand(double x, double y, double* pF) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "EvaluateVectorIntegrand");
                if (func)
                    {
                    int nItem = GetVectorIntegrandCount();
                    if (nItem > 0)
                        {
                        DoubleArray pF_(nItem, 0);
                        func(x, y, pF_);
                        memcpy((void*) pF, (const void*) pF_.data(), sizeof(double) * nItem);
                        }
                    }
                else
                    pybind11::pybind11_fail("Tried to call pure virtual function PyBSIVectorIntegrandXY::EvaluateVectorIntegrand");
                }
            catch (std::exception& err)
                {
                ScriptEngineManager::Get().InjectException(err);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int GetVectorIntegrandCount() override
            { PYBIND11_OVERRIDE_PURE_EXR(int, BSIVectorIntegrandXY, GetVectorIntegrandCount, 0, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BSIQuadrature(py::module_& m)
    {
    //===================================================================================
    // class BSIVectorIntegrand
    py::class_<BSIVectorIntegrand, PyBSIVectorIntegrand> c1(m, "BSIVectorIntegrand");
    
    c1.def(py::init<>());
    c1.def("EvaluateVectorIntegrand", [] (BSIVectorIntegrand& self, double t, DoubleArray& pF)
           {
           size_t nItem = (size_t) self.GetVectorIntegrandCount();
           if (pF.size() < nItem)
               pF.resize(nItem);

           self.EvaluateVectorIntegrand(t, pF.data());
           }, "t"_a, "pF"_a, py::call_guard<py::gil_scoped_release>());

    c1.def("VectorIntegrandCount", &BSIVectorIntegrand::GetVectorIntegrandCount);

    //===================================================================================
    // class BSIIncrementalVectorIntegrand
    py::class_<BSIIncrementalVectorIntegrand, PyBSIIncrementalVectorIntegrand, BSIVectorIntegrand> c2(m, "BSIIncrementalVectorIntegrand");
    
    c2.def(py::init<>());
    c2.def("AnnounceIntermediateIntegral", [] (BSIIncrementalVectorIntegrand& self, double t, DoubleArray& pIntegrals)
           {
           size_t nItem = (size_t) self.GetVectorIntegrandCount();
           if (pIntegrals.size() < nItem)
               pIntegrals.resize(nItem);

           return self.AnnounceIntermediateIntegral(t, pIntegrals.data());
           }, "t"_a, "pIntegrals"_a, py::call_guard<py::gil_scoped_release>());
    
    //===================================================================================
    // class BSIVectorIntegrandXY
    py::class_<BSIVectorIntegrandXY, std::unique_ptr<BSIVectorIntegrandXY, py::nodelete>, PyBSIVectorIntegrandXY > c3(m, "BSIVectorIntegrandXY");
    
    c3.def(py::init<>());
    c3.def("EvaluateVectorIntegrand", [] (BSIVectorIntegrandXY& self, double x, double y, DoubleArray& pF)
           {
           size_t nItem = (size_t) self.GetVectorIntegrandCount();
           if (pF.size() < nItem)
               pF.resize(nItem);

           self.EvaluateVectorIntegrand(x, y, pF.data());
           }, "x"_a, "y"_a, "pF"_a, py::call_guard < py::gil_scoped_release>());

    c3.def("VectorIntegrandCount", &BSIVectorIntegrandXY::GetVectorIntegrandCount);

    //===================================================================================
    // struct BSIQuadraturePoints
    py::class_<BSIQuadraturePoints> c4(m, "BSIQuadraturePoints");

    c4.def(py::init<>());
    c4.def("InitUniform", &BSIQuadraturePoints::InitUniform, "numEval"_a, DOC(Bentley, Geom, BSIQuadraturePoints, InitUniform));
    c4.def("InitGauss", &BSIQuadraturePoints::InitGauss, "numEval"_a, DOC(Bentley, Geom, BSIQuadraturePoints, InitGauss));
    c4.def("InitGaussLobatto", &BSIQuadraturePoints::InitGaussLobatto, "numEval"_a, DOC(Bentley, Geom, BSIQuadraturePoints, InitGaussLobatto));
    c4.def("InitGaussKronrod", &BSIQuadraturePoints::InitGaussKronrod, "numEval"_a, "gaussPartner"_a, DOC(Bentley, Geom, BSIQuadraturePoints, InitGaussKronrod));

    c4.def("GetEval", [] (BSIQuadraturePointsCR self, int i, double a0, double a1)
        {
        double a = 0;
        double w = 0;
        bool bOk = self.GetEval(i, a0, a1, a, w);
        return py::make_tuple(bOk, a, w);
        }, "i"_a, "a0"_a, "a1"_a, DOC(Bentley, Geom, BSIQuadraturePoints, GetEval));

    c4.def_static("GetXYEval", [] (BSIQuadraturePoints const &xRule, int ix, double x0, double x1, BSIQuadraturePoints const &yRule, int iy, double y0, double y1)
        {
        double x = 0;
        double y = 0;
        double w = 0;
        bool bOk = BSIQuadraturePoints::GetXYEval(xRule, ix, x0, x1, yRule, iy, y0, y1, x, y, w);
        return py::make_tuple(bOk, x, y, w);
        }, "xRule"_a, "ix"_a, "x0"_a, "x1"_a, "yRule"_a, "iy"_a, "y0"_a, "y1"_a, DOC(Bentley, Geom, BSIQuadraturePoints, GetXYEval));

    c4.def_property_readonly("NumEval", &BSIQuadraturePoints::GetNumEval);
    c4.def("GetNumEval", &BSIQuadraturePoints::GetNumEval, DOC(Bentley, Geom, BSIQuadraturePoints, GetNumEval));

    c4.def_property_readonly("ConvergencePower", &BSIQuadraturePoints::GetConvergencePower);
    c4.def("GetConvergencePower", &BSIQuadraturePoints::GetConvergencePower, DOC(Bentley, Geom, BSIQuadraturePoints, GetConvergencePower));

    c4.def("AccumulateWeightedSums", [] (BSIQuadraturePoints& self, BSIVectorIntegrand& function, double t0, double t1, DoubleArray& pSums, int numInterval)
           {
           size_t nItem = (size_t) function.GetVectorIntegrandCount();
           if (pSums.size() < nItem)
               pSums.resize(nItem);

           self.AccumulateWeightedSums(function, t0, t1, pSums.data(), numInterval);
           }, "function"_a, "t0"_a, "t1"_a, "pSums"_a, "numInterval"_a, DOC(Bentley, Geom, BSIQuadraturePoints, AccumulateWeightedSums));

    c4.def("IntegrateWithRombergExtrapolation", [] (BSIQuadraturePointsR self, BSIIncrementalVectorIntegrand &function, double t0, double t1, uint32_t numInterval)
        {
        double totalErrorBound = 0;
        bool bOk = self.IntegrateWithRombergExtrapolation(function, t0, t1, numInterval, totalErrorBound);
        return py::make_tuple(bOk, totalErrorBound);
        }, "function"_a, "t0"_a, "t1"_a, "numInterval"_a, DOC(Bentley, Geom, BSIQuadraturePoints, IntegrateWithRombergExtrapolation));

    //===================================================================================
    // struct BSITriangleQuadraturePoints
    py::class_<BSITriangleQuadraturePoints> c5(m, "BSITriangleQuadraturePoints");

    c5.def(py::init<>());
    c5.def("InitStrang", &BSITriangleQuadraturePoints::InitStrang, "selector"_a, DOC(Bentley, Geom, BSITriangleQuadraturePoints, InitStrang));

    c5.def("GetEval", [] (BSITriangleQuadraturePoints const& self, int i)
        {
        double u = 0;
        double v = 0;
        double w = 0;
        bool bOk = self.GetEval(i, u, v, w);
        return py::make_tuple(bOk, u, v, w);
        }, "i"_a, DOC(Bentley, Geom, BSITriangleQuadraturePoints, GetEval));

    c5.def_property_readonly("NumEval", &BSITriangleQuadraturePoints::GetNumEval);
    c5.def("GetNumEval", &BSITriangleQuadraturePoints::GetNumEval, DOC(Bentley, Geom, BSITriangleQuadraturePoints, GetNumEval));
    
    c5.def("AccumulateWeightedSums", [] (BSITriangleQuadraturePoints& self, BSIVectorIntegrandXY& function, DoubleArray& pSums)
           {
           int nCount = function.GetVectorIntegrandCount();
           if (nCount > 0)
               {
               if (nCount > (int) pSums.size())
                   pSums.resize((size_t) nCount);

               self.AccumulateWeightedSums(function, pSums.data());
               }
           });

    c5.def("AccumulateWeightedSumsMapped", [] (BSITriangleQuadraturePoints& self, BSIVectorIntegrandXY& function, DoubleArray& pSums, double ax, double ay, double bx, double by, double cx, double cy)
           {
           int nCount = function.GetVectorIntegrandCount();
           if (nCount > 0)
               {
               if (nCount > (int) pSums.size())
                   pSums.resize((size_t) nCount);

               self.AccumulateWeightedSumsMapped(function, pSums.data(), ax, ay, bx, by, cx, cy);
               }
           });
    }