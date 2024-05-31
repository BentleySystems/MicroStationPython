#pragma once
#include <vector>
#include <Geom/GeomApi.h>
#ifdef UseTestList
#define TEST(Name1,Name2) TEST_FRAGMENT(Name1,Name2)
#else
#include <Bentley/BeTest.h>
#endif

#include <algorithm>
#include <sstream>
#include <ctime>
#include <fstream>
#include <iostream>

#include <Bentley/BeConsole.h>
struct CheckBSIBaseGeomMemory
    {
    int64_t counter0;
    WString name;
    CheckBSIBaseGeomMemory (char const *string)
        : name (string, true)
        {
        counter0 = BSIBaseGeom::GetAllocationDifference ();
        }
    ~CheckBSIBaseGeomMemory ()
        {
        int64_t counter1 = BSIBaseGeom::GetAllocationDifference ();
        if (counter1 != counter0)
            printf (" BSIBaseGeomMemory difference %d\n", (int)(counter1 - counter0));
        }
    };
//! A Tolerance structure carries an absolute tolerance and a relative tolerance, and
//! has methods inspect real data and determine the appropriate final tolerance.
struct Tolerance
{
double m_abstol;
double m_reltol;
//! Initialize with given absolute and relative tolerances.
Tolerance (double abstol, double reltol);
//! Return the appropriate tolerance for data magnitude {a}.
double Evaluate (double a);
//! Return the appropriate tolerance for data magnitude {a}, {b}.
double Evaluate (double a, double b);
//! Return the appropriate tolerance for data magnitude {a}, {b}, {c}
double Evaluate (double a, double b, double c);
//! Return the appropriate tolerance for data magnitude {a}, {b}, {c}, {d}
double Evaluate (double a, double b, double c, double d);

};

//! Enumeration of qualitative loose, medium, and tight tolerances.
enum ToleranceSelect
    {
    ToleranceSelect_default = 0,
    ToleranceSelect_Loose   = 1,
    ToleranceSelect_Tight   = 2,
    ToleranceSelect_Medium  = 3,
    ToleranceSelect_NearMachine  = 4,
    };

#define PRIMITIVE_PRINT_VOLUME 5
// single fixed size structure
#define STRUCTURE_PRINT_VOLUME 10
// array, curve vector
#define MULTI_STRUCTURE_PRINT_VOLUME 20
// mesh, vu, mtg
#define LARGE_PRINT_VOLUME 100

//! Class with (static) methods to compare BentleyGeom data types in gtest.
//! The (static) calss maintains the following data:
//! <ul>
//! <li>A current Tolerance structure with absolute and relative tolerances.
//! <li>A stack of saved Tolerance structures (which can be pushed and popped)
//! <li>A default tolerances
//! </ul>
//!
//! The class is initialized with medium tolerances (1.0e-12 for both abstol and reltol)
//!
class Check
{
private:
static int s_maxVolume;

public:
enum class FailureMode
    {
    Fail,
    Count
    };

private: static int s_failureCount;
private: static FailureMode s_failureMode;
private: static const bool s_enableLongTests = false;
public:
static int GetMaxVolume (){return s_maxVolume;}
static bool GetEnableLongTests() { return s_enableLongTests; }
// Large numbers make more output
// bvector output goes on at 10
// restricted output of large structure (vu, mesh) goes on at 20
// voluminous output of large structures goes on at 100
static int SetMaxVolume (int maxVolume){auto a = s_maxVolume; s_maxVolume = maxVolume; return a;}
static bool IsSuppressed (int volume){return volume > s_maxVolume;}
static bool PrintPrimitives (){return s_maxVolume >= PRIMITIVE_PRINT_VOLUME;}
static bool PrintFixedStructs (){return s_maxVolume >= STRUCTURE_PRINT_VOLUME;}
static bool PrintDeepStructs (){return s_maxVolume >= MULTI_STRUCTURE_PRINT_VOLUME;}
// Structure to capture and set Output noise on scope entry, reset on scope exit.
struct EnableOutputInScope
    {
    int m_noisy;
    EnableOutputInScope (int noisy)
        {
        m_noisy = Check::GetMaxVolume ();
        SetMaxVolume (noisy);
        }
    ~EnableOutputInScope ()
        {
        SetMaxVolume (m_noisy);
        }
    };

// Add to the failure count
static int IncrementFailureCount ()
    {
    s_failureCount += 1;
    return s_failureCount;
    }
static void Fail (char const *pString = nullptr);

public:
void ClearCounters ()
    {
    s_failureCount = 0;
    s_failureMode = FailureMode::Fail;
    }

struct QuietFailureScope
  {
  int m_failureCount0;
  FailureMode m_failureMode0;
  QuietFailureScope ()
      {
      m_failureCount0 = Check::s_failureCount;
      m_failureMode0  = Check::s_failureMode;
      Check::s_failureMode = FailureMode::Count;
      }

// the destructor needs to have this wrapped in a method because ASSERT_TRUE tries to return
static void ThrowAssert ()
    {
    ASSERT_TRUE (false) << "(Deferred assertion throw for previous errors)";
    }
  ~QuietFailureScope ()
      {
      if (Check::s_failureCount > m_failureCount0)
          {
          ThrowAssert ();
          }
      Check::s_failureMode = m_failureMode0;
      }
  };
  //  Create a NamedScope("name") var to get begin/end by lifetime of the var.
struct NamedScope
{
NamedScope (char const *name){Check::StartScope (name);}
NamedScope (char const *name, size_t value){Check::StartScope (name, value);}
~NamedScope (){Check::EndScope();}
void KeepAlive (){}
};
private:
static Tolerance m_toleranceBundle[5];


static std::vector<Tolerance> m_toleranceStack;
static Tolerance m_tolerance;
static Tolerance m_defaultTolerance;

public:
static void Start  ();
static void End    ();
//! Return the appropriate tolerance for data of magnitude {a}
static double Tol (double a);
//! Return the appropriate tolerance for data of magnitude {a},{b}
static double Tol (double a, double b);
//! Return the appropriate tolerance for data of magnitude {a},{b},{c},{d}
static double Tol (double a, double b, double c, double d = 0.0);

static void StartScope (char const *name);
static void StartScope (char const *name, double value);
static void StartScope (char const *name, size_t value);
static void StartScope (char const *name, DPoint3dCR value);
static void StartScope (char const *name, DRay3dCR value);
static void StartScope (char const *name, RotMatrixCR value);
static void StartScope (char const *name, DPlane3dCR value);
static void EndScope ();
static void PrintScope ();
static void PrintIndent (size_t depth);
static void PrintStructure (CurveVectorCP top, size_t depth = 0);
static void PrintStructure (ICurvePrimitiveCP prim, size_t depth = 0);
static void PrintStructure (CurveVectorCP top, char *pName);
static void PrintStructure (ISolidPrimitiveCP prim);
static void Print (bvector<double> const &data, const char *callerName = NULL);

static void Print (ICurvePrimitiveCR curve);
static void Print (CurveVectorCR curves, const char *callerName);
static void Print (bvector<DSegment3dSizeSize> const &segments, const char *callerName);
static void Print0TerminatedBlocks (bvector<int> const &segments, const char *callerName);

static void Print (CurveVectorPtr curves, const char *callerName = NULL);
static void Print (DPoint3dCR, const char *name = NULL);
static void Print (bvector<DPoint3d> const &data, const char *name = NULL);
static void Print (DPoint2dCR, const char *name = NULL);
static void Print (DVec3dCR, const char *name = NULL);
static void Print (double data, char const *name = NULL);
//! Return the appropriate tolerance for comparisons involving a DPoint2d.
static double Tol (DPoint2dCR Q);
//! Return the appropriate tolerance for comparisons involving a DPoint3d.
static double Tol (DPoint3dCR Q);
//! Return the appropriate tolerance for comparisons involving a DPoint4d.
static double Tol (DPoint4dCR Q);

//! Return the appropriate tolerance for comparing two DPoint2d.
static double Tol (DPoint2dCR Q, DPoint2dCR R);
//! Return the appropriate tolerance for comparing two DPoint3d.
static double Tol (DPoint3dCR Q, DPoint3dCR R);
//! Return the appropriate tolerance for comparing two DPoint4d.
static double Tol (DPoint4dCR Q, DPoint4dCR R);

//! Test if {a} is near zero.
static bool NearZero (double a, char const*pName = NULL, double refValue = 0.0);

//! Test if {a} is exactly equal to {b}.
static bool ExactDouble (double a, double b, char const*pName = NULL);
//! Test if {a} is exactly equal to {b} in all components xyz
static bool Exact (DPoint3dCR a, DPoint3dCR b, char const*pString = nullptr);
//! Test if {a} is exactly equal to {b} in all components xyz
static bool ExactRange (DRange3dCR a, DRange3dCR b, char const*pString = nullptr);
//! Test if {a} is near {b}.
static bool Near (double a, double b, char const*pName = NULL, double refValue = 0.0);

//! Test if range {a} contains {b}
static bool Contains (DRange1dCR a, double b, char const*pName = NULL);

//! Test if {a} is less than or equal to {b}, with toleranced equality test.
static void LE_Toleranced (double a, double b);


//! Check all components of two DPoint2d.
static void Near (DPoint2dCR a, DPoint2dCR b, char const*pName = NULL, double refValue = 0.0);
//! Check all components of two DPoint3d.
static bool Near (DPoint3dCR a, DPoint3dCR b, char const*pName = NULL, double refValue = 0.0);

//! Check all components of array of DPoint2d.
static void Near (DPoint2dCP a, DPoint2dCP b, int n, char const*pName = NULL, double refValue = 0.0);
//! Check all components of array of DPoint3d.
static void Near (DPoint3dCP a, DPoint3dCP b, int n, char const*pName = NULL, double refValue = 0.0);

//! Compare points, one as DPoint2d and the other as components.
static void Near (DPoint2dCR xyz, double x, double y, char const*pName = NULL, double refVal = 1.0);
//! Compare points, one as DPoint3d and the other as components.
static void Near (DPoint3dCR xyz, double x, double y, double z, char const*pName = NULL, double refVal = 1.0);

//! Compare all components of a pair of DRange2d
static void Near (DRange2dCR a, DRange2dCR b, char const*pName = NULL, double refVal = 1.0);
//! Compare all components of a pair of DRange3d
static void Near (DRange3dCR a, DRange3dCR b, char const*pName = NULL, double refValue = 0.0);

static bool NearMoments (RotMatrixCR axes0, DVec3dCR moment0, RotMatrixCR axes1, DVec3dCR moment1);

//! Check all components of two DPoint4d.
static void Near (DPoint4dCR a, DPoint4dCR b, char const*pName = NULL, double refValue = 0.0);
//! Check all components of two RotMatrix.
static bool Near (RotMatrixCR a, RotMatrixCR b, char const*pName = NULL, double refValue = 0.0);

//! Check for exact zero
static bool TrueZero (double a, char const*pName = NULL);

//! Check all components of two Transform.
static void Near (TransformCR a, TransformCR b, char const*pName = NULL, double refValue = 0.0);
//! Check all components of two DMatrix4d.
static void Near (DMatrix4d a, DMatrix4d b, char const*pName = NULL, double refValue = 0.0);


//! Check all components of a two DSegment3d
static void Near (DSegment3dCR a, DSegment3dCR b, char const*pString = NULL, double refValue = 0.0);
//! Check all components of a two DEllipse3d
static void Near (DEllipse3dCR a, DEllipse3dCR b, char const*pString = NULL, double refValue = 0.0);
//! Check all components of a two DConic4d.
static void Near (DConic4dCR a, DConic4dCR b, char const*pName = NULL, double refValue = 0.0);
//! compare angles, allow shift by multiple of 2pi
static bool NearPeriodic (double thetaA, double thetaB, char const*pString);

//! compare strongly typed angles, allow shift by multiple of 2pi
static bool NearPeriodic (Angle thetaA, Angle thetaB, char const*pString = NULL);
//! compare strongly typed angles, do not allow shift by multiple of 2pi
static bool Near (Angle thetaA, Angle thetaB, char const*pString = NULL);
//! Check if two vectors are parallel.
static bool Parallel (DVec3dCR a, DVec3dCR b, char const*pName = NULL, double refValue = 0.0);
//! Check if two vectors are parallel.
static bool Perpendicular (DVec3dCR a, DVec3dCR b, char const*pName = NULL, double refValue = 0.0);
//! Check matching bool.
static bool Bool (bool a, bool b, char const*pName = NULL);
//! Check matching int.
static bool Int (int a, int b, char const*pName = NULL);
//! Check for false.
static bool False (bool a, char const*pName = NULL);
//! Check for true.
static bool True (bool b, char const*pName = NULL);
static bool LessThanOrEqual (double a, double b, char const*pString = nullptr);

static bool Size (size_t a, size_t b, char const*pName = NULL);
static bool Ptrdiff (ptrdiff_t a, ptrdiff_t b, char const*pName = NULL);

template<typename T>
static bool Near (bvector<T> &a, bvector<T> &b, char const*pName = NULL)
    {
    bool stat = true;
    StartScope (pName);
    if (Check::Size (a.size (), b.size (), "Array size"))
        {
        for (size_t i = 0; stat && i < a.size (); i++)
            {
            char s[1024];
            sprintf (s, "[%ld]", (long int)i);
            if (!Check::Near (a[i], b[i], s))
                stat = false;
            }
        }
    EndScope ();
    return stat;
    }

//! Push the current tolerances on a stack and activate another tolerance.
static void PushTolerance (ToleranceSelect select);
//! Take the top tolerance off the stack and make it active.
static void PopTolerance ();
// Save (clone of) geometry in a cache
static void SaveTransformed(bvector<IGeometryPtr> const &data);
static void SaveTransformed(IGeometryPtr const &data);
static void SaveTransformed(CurveVectorCR data);
static void SaveTransformed(CurveVectorPtr &data);
static void SaveTransformed(ICurvePrimitiveCR data);
static void SaveTransformed(PolyfaceHeaderCR data);
static void SaveTransformed(PolyfaceHeaderPtr &data);
static void SaveTransformed(ISolidPrimitiveCR data);
static void SaveTransformed (bvector<DPoint3d> const &data, bool addClosure = false);
static void SaveTransformed (bvector<DPoint4d> const &data);
static void SaveTransformedMarkers (bvector<DPoint3d> const &data, double markerSize);
static void SaveTransformedMarker (DPoint3dCR data, double markerSize = 0.1);
static void SaveTransformed (DPoint3dCP pData, size_t n);
static void SaveTransformed (bvector<bvector<DPoint3d>> const &data);
static void SaveTransformed (bvector<DTriangle3d> const &data, bool closed = true);
static void SaveTransformed (bvector<DSegment3d> const &data);
static void SaveTransformed (DSegment3dCR data);
static void SaveTransformed (DEllipse3dCR data);
static void SaveTransformed(MSBsplineSurfacePtr const &data);
static void SaveTransformed (MSBsplineCurveCR data);
static void SaveTransformed(MSBsplineCurvePtr const &data, bool savePolygon = false);
static void SaveTransformedEdges (DRange3dCR range);
static void SaveTransformedEdges(DPoint3d corners[8]);
static void Shift (double dx, double dy, double dz = 0.0);
static void Shift (DVec3dCR shift);
static void ShiftToLowerRight (double dx = 0.0);
static Transform GetTransform ();
static void SetTransform (TransformCR transform);

static void ClearGeometry (char const *name, bool saveIModelJson = true);
static bool LoadFileAsString(WCharCP fileName, Utf8String&);
};

// Macros to support older unit test harnesses.  (Deprecated)
#define checkInt Check::Int
#define checkDouble Check::Near
#define checkDPoint3dXYZ(__a,__x,__y,__z,__name) Check::Near (*__a, __x,__y,__z, __name)
#define checkDPoint3d(__a,__b,__name) Check::Near(*__a,*__b,__name)
#define checkDPoint2d(__a,__b,__name) Check::Near(*__a,*__b,__name)
#define checkDRange2d(__a,__b,__name) Check::Near(*__a,*__b,__name)
#define checkDVec3d(__a,__b,__name) Check::Near(*__a,*__b,__name)
#define checkDRang2d(__a,__b,__name) Check::Near(*__a,*__b,__name)
#define checkRotMatrix(__a,__b,__name) Check::Near(*__a,*__b,__name)
#define checkBool Check::Bool
#define checkFalse(__a,__name) Check::False ((__a) ? true : false,__name)
#define checkTrue(__a,__name)  Check::True  ((__a) ? true : false,__name)



//! TestInstance/TestHarness == experiments in escaping gtest.
//! Interface for classes that can act as a test
struct TestInstance
{
virtual void go () = 0;
};

struct TestInstanceData
{
TestInstance *m_instance;
WString m_name;
TestInstanceData (TestInstance *instance, WString const &m_name);
};

//! Master list of tests.
struct TestList
{
public:
// Run all tests that have been registered.
static void RunAll ();
// Register a single instance of a testable class.
static void Register (TestInstanceData const &instance);
};

// macro to create and register a TestInstance
// A) Create a subclass of TestInstance
// B) Force an instance to be created and registered at startup time
// C) Capture code immediately following the macro instantiation as the testable body
#define TEST_FRAGMENT(Name1,Name2)  \
class Name1##Name2 : TestInstance { \
private:Name1##Name2 (){}           \
public: static int CreateAndRegister (WString const &name) {TestList::Register (TestInstanceData (new Name1##Name2 (), name)); return 0;}\
virtual void go () override;\
};\
int Name1##Name2##_instantiationVar = Name1##Name2::CreateAndRegister (WString(_CRT_WIDE(#Name1) _CRT_WIDE(#Name2)));\
void Name1##Name2::go ()


#define CHECK_EQ(_MethodName_,_exprA_,_exprB_) Check::_MethodName_ (_exprA_,_exprB_,#_exprA_ "?==?" #_exprB_);

#define CHECK_EXPR(_Method_,_Condition_) Check::_Method_ (_Condition_, #_Method_ "?" #_Condition_)


struct SaveAndRestoreCheckTransform
{
Transform m_baseTransform;
DVec3d m_finalShift;
SaveAndRestoreCheckTransform ()
    {
    m_finalShift.Zero ();
    m_baseTransform = Check::GetTransform ();
    }
SaveAndRestoreCheckTransform (double dxFinal, double dyFinal, double dzFinal = 0.0)
    {
    m_finalShift.Init (dxFinal, dyFinal, dzFinal);
    m_baseTransform = Check::GetTransform ();
    }
void DoShift ()
    {
    Check::SetTransform (m_baseTransform);
    Check::Shift (m_finalShift.x, m_finalShift.y, m_finalShift.z);
    m_baseTransform = Check::GetTransform ();
    }
void SetShift (double dx, double dy, double dz)
    {
    m_finalShift.Init (dx, dy, dz);
    }
~SaveAndRestoreCheckTransform ()
    {
    DoShift ();
    }
};


struct TransformShifter
{
Transform m_baseTransform;
DVec3d    m_shift0, m_shift1;
ValidatedDPoint3d m_origin;
bool m_showBox;
void ShiftOrigin (double a0, double a1)
    {
    m_origin = ValidatedDPoint3d (m_origin + a0 * m_shift0 + a1 * m_shift1, true);
    }

TransformShifter (double dx0, double dy0, double dz0, double dx1, double dy1, double dz1, bool showBox = true, bool centeredBox = true)
    {
    m_origin = ValidatedDPoint3d (DPoint3d::From(0,0,0), showBox);
    m_shift0 = DVec3d::From (dx0, dy0, dz0);
    m_shift1 = DVec3d::From (dx1, dy1, dz1);
    if (centeredBox)
        ShiftOrigin (-0.5, - 0.5);
    m_baseTransform = Check::GetTransform ();
    m_showBox = showBox;
    }
void DoShift (DVec3dCR vector, bool resetBaseTransform = false)
    {
    if (m_origin.IsValid () && m_showBox)
        {
        // Output a box around the prior image space
        DPoint3d origin = m_origin.Value ();
        auto box = ICurvePrimitive::CreateLineString (
                    bvector<DPoint3d>{
                            origin,
                            origin + m_shift0,
                            origin + m_shift0 + m_shift1,
                            origin + m_shift1,
                            origin
                            }
                            );
        Check::SaveTransformed (*box);
        }
    if (resetBaseTransform)
        {
        Check::SetTransform (m_baseTransform);
        Check::Shift (vector.x, vector.y, vector.z);
        m_baseTransform = Check::GetTransform ();
        }
    else
        {
        Check::Shift (vector.x, vector.y, vector.z);
        }
    }
void DoShift0 (bool resetBaseTransform = false)
    {
    DoShift (m_shift0, resetBaseTransform);
    }

void DoShift1 (bool resetBaseTransform = true)
    {
    DoShift (m_shift1, resetBaseTransform);
    }
// Shift the origin to (factor0,factor1) in the grid.  Optionally move the grid origin to this point.
void DoGridShift (double factor0, double factor1, bool resetBaseTransform = false)
    {
    DoShift (factor0 * m_shift0 + factor1 * m_shift1, resetBaseTransform);
    }
};
