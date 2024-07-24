//---------------------------------------------------------------------------------------------
//  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
//  See LICENSE.md in the repository root for full copyright notice.
//---------------------------------------------------------------------------------------------
#include "checkers.h"
#include <windows.h>
#include <GeomSerialization/GeomSerializationApi.h>
#include <Bentley/BeTest.h>
static double s_simpleZeroTol = 1.0e-12;

struct ScopedPrintState
{
int m_savedVolume;
ScopedPrintState (int volume = 10000) : m_savedVolume (Check::SetMaxVolume (volume)) {}
~ScopedPrintState (){Check::SetMaxVolume (m_savedVolume);}
};
static bvector<WString> s_stack;
int __setDefaultPrint ()
    {
    printf (" ACCESSING VERBOSE flag\n");
#ifdef BENTLEY_WIN32
// PUSH_DISABLE_DEPRECATION_WARNINGS
    auto s = getenv("GTEST_GEOMLIBS_VERBOSE");
    if (s == nullptr)
        return 0;
    printf (" string form: (%s)\n", s);
    int value;
    if (1 == sscanf (s, "%d", &value))
        {
        printf ("GTEST_GEOMLIBS_VERBSOSE=%d\n", value);
        return value;
        }
    // not recognized format  . . . call it noisy
    return 100;
// POP_DISABLE_DEPRECATION_WARNINGS
#else
    return 0;
#endif
    }
int Check::s_maxVolume = __setDefaultPrint ();
void Check::StartScope (char const *string)
    {
    s_stack.push_back (WString (string, false));
    }

void Check::StartScope (char const *name, double value)
    {
    char buffer[2048];
    sprintf (buffer, "(%s %.15lg)", name, value);
    StartScope (buffer);
    }

void Check::StartScope (char const *name, size_t value)
    {
    char buffer[2048];
    sprintf (buffer, "(%s %u)", name, (unsigned int)value);
    StartScope (buffer);
    }



void Check::StartScope (char const *name, DPoint3dCR value)
    {
    char buffer[2048];
    sprintf (buffer, "(%s %.15lg %.15lg %.15lg)", name, value.x, value.y, value.z);
    StartScope (buffer);
    }

void Check::StartScope (char const *name, DRay3dCR value)
    {
    char buffer[2048];
    sprintf (buffer, "(%s (origin %.15lg %.15lg %.15lg) (dir %.15lg %.15lg %.15lg))",
            name,
            value.origin.x, value.origin.y, value.origin.z,
            value.direction.x, value.direction.y, value.direction.z
            );
    StartScope (buffer);
    }

void Check::StartScope (char const *name, RotMatrixCR value)
    {
    char buffer[2048];
    sprintf (buffer, "(%s \n  (RowX %.15lg %.15lg %.15lg)\n  (RowY %.15lg %.15lg %.15lg)\n  (RowY %.15lg %.15lg %.15lg))",
            name,
            value.form3d[0][0], value.form3d[0][1], value.form3d[0][2],
            value.form3d[1][0], value.form3d[1][1], value.form3d[1][2],
            value.form3d[2][0], value.form3d[2][1], value.form3d[2][2]
            );
    StartScope (buffer);
    }

void Check::StartScope (char const *name, DPlane3dCR value)
    {
    char buffer[2048];
    sprintf (buffer, "(%s \n  (origin %.15lg %.15lg %.15lg)  (normal %.15lg %.15lg %.15lg))",
            name,
            value.origin.x, value.origin.y, value.origin.z,
            value.normal.x, value.normal.y, value.normal.z
            );
    StartScope (buffer);
    }

void Check::EndScope ()
    {
    s_stack.pop_back ();
    }

void Check::PrintScope ()
    {

    if (s_stack.size () == 0)
        return;
    printf ("(");
    for (size_t i = 0; i < s_stack.size (); i++)
        {
        wprintf (L" %s", s_stack[i].data ());
        }
    printf (")\n");
    }
double Check::Tol (double a)
    {
    return m_tolerance.Evaluate (a);
    }

double Check::Tol (double a, double b)
    {
    return m_tolerance.Evaluate (a, b);
    }

double Check::Tol (double a, double b, double c, double d)
    {
    return m_tolerance.Evaluate (a, b, c, d);
    }


double Check::Tol (DPoint4dCR Q)
    {
    return m_tolerance.Evaluate (Q.MagnitudeXYZW ());
    }

double Check::Tol (DPoint3dCR Q)
    {
    return m_tolerance.Evaluate (Q.Magnitude ());
    }

double Check::Tol (DPoint3dCR Q, DPoint3dCR R)
    {
    return m_tolerance.Evaluate (Q.Magnitude (), R.Magnitude ());
    }

double Check::Tol (DPoint4dCR Q, DPoint4dCR R)
    {
    return m_tolerance.Evaluate (Q.MagnitudeXYZW (), R.MagnitudeXYZW ());
    }


double Check::Tol (DPoint2dCR Q)
    {
    return m_tolerance.Evaluate (Q.Magnitude ());
    }

double Check::Tol (DPoint2dCR Q, DPoint2dCR R)
    {
    return m_tolerance.Evaluate (Q.Magnitude (), R.Magnitude ());
    }

int Check::s_failureCount = 0;
Check::FailureMode Check::s_failureMode = Check::FailureMode::Fail;
void Check::Fail (const char *pString)
    {
    s_failureCount++;
    if (s_failureMode == FailureMode::Count)
        {
        GEOMAPI_PRINTF (" Check::Fail quiet failure (%d)", s_failureCount);
        if (nullptr != pString)
            GEOMAPI_PRINTF ("%s", pString);
        GEOMAPI_PRINTF ("\n");
        }
    else
        {
        if (nullptr == pString)
            ASSERT_TRUE (false);
        else
            ASSERT_TRUE (false) << pString;
        }

    }
// ASSERT failure will return void to caller !!!
static void DoAssert (bool b, char const*pString)
    {
    if (b)
        return;
    Check::PrintScope ();
    Check::Fail (pString);
    }

static void DoAssert (int a, int b, char const*pString)
    {
    if (a == b)
        return;
    Check::PrintScope ();
    Check::Fail (pString);
    }

static void DoAssertP (ptrdiff_t a, ptrdiff_t b, char const*pString)
    {
    if (a == b)
        return;
    Check::PrintScope ();
    Check::Fail (pString);
    }

static void DoAssert (size_t a, size_t b, char const*pString)
    {
    if (a == b)
        return;
    Check::PrintScope ();
    Check::Fail (pString);
    }

static void AssertNear (double a, double b, double tol, char const*pString)
    {
    if (fabs (a-b) > tol)
        Check::PrintScope ();
    EXPECT_NEAR (a, b, tol) << pString;
    }
bool Check::LessThanOrEqual (double a, double b, char const*pString)
    {
    if (a <= b)
        return true;
    char message[2048];
    sprintf (message, "(fail %.17g <= %.17g) %s\n", a, b, pString ? pString : "");
    Check::PrintScope ();
    Check::Fail (message);
    return false;
    }
bool Check::True (bool a, char const*pString)
    {
    if (a)
        return true;
    DoAssert (a, pString);
    return false;
    }

bool Check::False (bool a, char const*pString)
    {
    if (!a)
        return true;
    DoAssert (!a, pString);
    return false;
    }

bool Check::NearZero (double a, char const*pString, double refValue)
    {
    if (fabs (a) < s_simpleZeroTol)
        return true;
    StartScope (pString);
    StartScope ("nearZero", a);
    DoAssert (fabs (a) < s_simpleZeroTol, "");
    EndScope ();
    EndScope ();
    return false;
    }

bool Check::Contains (DRange1dCR a, double b, char const*pName)
    {
    if (a.Contains (b))
        return true;
    StartScope ("InRange");
    StartScope("low", a.Low ());
    StartScope("high", a.High ());
    StartScope ("value", b);
    DoAssert (false, pName);
    EndScope ();
    EndScope ();
    EndScope ();
    EndScope ();
    return false;
    }
bool Check::Int (int a, int b, char const*pString)
    {
    if (a == b)
        return true;
    DoAssert (a, b, pString);
    return false;
    }

bool  Check::Size (size_t a, size_t b, char const*pString)
    {
    if (a == b)
        return true;
    StartScope ("size_t a", a);
    StartScope ("size_t b", b);
    DoAssert (a, b, pString);
    EndScope ();
    EndScope ();
    return false;
    }

bool Check::Ptrdiff(ptrdiff_t a, ptrdiff_t b, char const*pString)
    {
    if (a == b)
        return true;
    DoAssertP (a, b, pString);
    return false;
    }

bool Check::ExactDouble (double a, double b, char const*pString)
    {
    if (a == b)
        return true;

    PrintScope ();
    PrintIndent (2);Print (a, "a");
    PrintIndent (2);Print (b, "b");

    Fail (pString);
    return false;
    }

bool Check::Exact (DPoint3dCR a, DPoint3dCR b, char const*pString)
    {
    if (a.IsEqual (b))
        return true;

    PrintScope ();
    ScopedPrintState printState;
    PrintIndent (2);Print (a, "a");
    PrintIndent (2);Print (b, "b");

    Fail (pString);
    return false;
    }

bool Check::ExactRange (DRange3dCR a, DRange3dCR b, char const*pString)
    {
    return Check::Exact(a.low, b.low, pString) &&
           Check::Exact(a.high, b.high, pString);
    }

bool Check::Near (double a, double b, char const*pString, double refValue)
    {
    double tol = Tol (a,b, refValue);
    double d = fabs (a-b);
    if (d <= tol)
        return true;
    Check::PrintScope ();
    EXPECT_NEAR (a, b, tol) << pString;
    return false;
    }

void Check::LE_Toleranced (double a, double b)
    {
    double c = b + Tol(a,b);
    DoAssert (a < c, "LE Toleranced");
    }

void Check::Near (DConic4dCR a, DConic4dCR b, char const*pString, double refValue)
    {
    //double tol = Tol (a.center, b.center);
    Check::Near (a.center, b.center, pString, refValue);
    Check::Near (a.vector0, b.vector0, pString, refValue);
    Check::Near (a.vector90, b.vector90, pString, refValue);
    Check::Near (a.sweep, b.sweep, pString, refValue);
    Check::Near (a.start, b.start, pString, refValue);
    }

bool Check::NearPeriodic (double thetaA, double thetaB, char const*pString)
    {

    if (Angle::NearlyEqualAllowPeriodShift (thetaA, thetaB))
        return true;
    Check::Near (thetaA, thetaB, pString);
    return false;
    }

bool Check::NearPeriodic (Angle thetaA, Angle thetaB, char const*pString)
    {
    return Check::NearPeriodic (thetaA.Radians (), thetaB.Radians (), pString);
    }

bool Check::Near (Angle thetaA, Angle thetaB, char const*pString)
    {
    return Check::Near (thetaA.Radians (), thetaB.Radians (), pString);
    }




bool Check::Parallel (DVec3dCR a, DVec3dCR b, char const*pString, double refValue)
    {
    bool stat = a.IsParallelTo (b);
    if (stat)
        return true;
    double theta = a.AngleTo (b);
    double tol = Tol (theta, refValue);
    if (fabs (theta) < tol)
        return true;
    char string[1024];
    sprintf (string, " Parallel actual %le %s", theta, pString);
    Check::True (stat, string);
    return false;
    }

bool Check::Perpendicular (DVec3dCR a, DVec3dCR b, char const*pString, double refValue)
    {
    bool stat = a.IsPerpendicularTo (b);
    if (stat)
        return true;
    char string[1024];
    double theta = a.AngleTo (b);
    sprintf (string, " Perpendicular actual %le %s", theta, pString);
    Check::True (stat, string);
    return false;
    }



bool Check::Near (DPoint3dCR a, DPoint3dCR b, char const*pString, double refValue)
    {
    double tol = Tol (a.Magnitude (), b.Magnitude (), refValue);
    double d = a.Distance (b);
    if (d <= tol)
        return true;
    Check::PrintScope ();
    char message[1024];
    sprintf (message, "%s Point distance (%.16g,%.16g,%.16g)(%.16g,%.16g,%.16g)",
                    pString,
                    a.x, a.y, a.z, b.x, b.y, b.z);
    EXPECT_NEAR (d, 0.0, tol) << message;
    return false;
    }

void Check::Near (DPoint2dCP a, DPoint2dCP b, int n, char const*pName, double refValue)
    {
    char longName[2048];
    for (int i = 0; i < n; i++)
        {
        sprintf (longName, "DPoint2d[%d]%s", i, pName ? pName : "");
        Check::Near (a[i], b[i], longName, refValue);
        }
    }

void Check::Near (DPoint3dCP a, DPoint3dCP b, int n, char const*pName, double refValue)
    {
    char longName[2048];
    for (int i = 0; i < n; i++)
        {
        sprintf (longName, "DPoint3d[%d]%s", i, pName ? pName : "");
        Check::Near (a[i], b[i], longName, refValue);
        }
    }


void Check::Near (DSegment3dCR a, DSegment3dCR b, char const*pString, double refValue)
    {
    Check::Near (a.point[0], b.point[0], pString, refValue);
    Check::Near (a.point[1], b.point[1], pString, refValue);
    }

void Check::Near (DEllipse3dCR a, DEllipse3dCR b, char const*pString, double refValue)
    {
    Check::Near (a.center, b.center, pString, refValue);
    Check::Near (a.vector0, b.vector0, pString, refValue);
    Check::Near (a.vector90, b.vector90, pString, refValue);
    Check::Near (a.start, b.start, pString, 10.0);
    Check::Near (a.sweep, b.sweep, pString, 10.0);
    }

void Check::Near (DRange3dCR a, DRange3dCR b, char const*pString, double refValue)
    {
    Check::Near (a.low, b.low, pString, refValue);
    Check::Near (a.high, b.high, pString, refValue);
    }

bool Check::NearMoments (RotMatrixCR axes0, DVec3dCR moment0, RotMatrixCR axes1, DVec3dCR moment1)
    {
    if (Check::Near (moment0, moment1, "Scalar Part of moments"))
        {
        DVec3d U0, V0, W0;
        DVec3d U1, V1, W1;
        axes0.GetColumns (U0, V0, W0);
        axes1.GetColumns (U1, V1, W1);
        if (DoubleOps::AlmostEqual (moment0.x, moment0.y)
            && DoubleOps::AlmostEqual (moment0.x, moment0.z)
            )
            return true;   // Fulll symmetry -- axes can spin arbitrarily.

        if (DoubleOps::AlmostEqual (moment0.x, moment0.y))
            return Check::Near (W0, W1, "XY spin moments");
        else if (DoubleOps::AlmostEqual (moment0.x, moment0.z))
            return Check::Near (V0, V1, "XZ spin moments");
        else if (DoubleOps::AlmostEqual (moment0.y, moment0.z))
            return Check::Near (U0, U1, "YZ spin moments");
        return Check::Near (axes0, axes1, "Independent moment system");
        }
    return false;
    }
bool Check::Near (RotMatrixCR A, RotMatrixCR B, char const*pString, double refValue)
    {
    double d = A.MaxDiff (B);
    double a = A.MaxAbs () + B.MaxAbs ();
    return Check::Near (a, a+d, pString, refValue);
    }

bool Check::TrueZero (double a, char const*pString)
    {
    return Check::True (a == 0.0, pString);
    }


void Check::Near (TransformCR a, TransformCR b, char const*pString, double refValue)
    {
    Check::Near (a.form3d[0][0], b.form3d[0][0], pString, refValue);
    Check::Near (a.form3d[0][1], b.form3d[0][1], pString, refValue);
    Check::Near (a.form3d[0][2], b.form3d[0][2], pString, refValue);

    Check::Near (a.form3d[1][0], b.form3d[1][0], pString, refValue);
    Check::Near (a.form3d[1][1], b.form3d[1][1], pString, refValue);
    Check::Near (a.form3d[1][2], b.form3d[1][2], pString, refValue);

    Check::Near (a.form3d[2][0], b.form3d[2][0], pString, refValue);
    Check::Near (a.form3d[2][1], b.form3d[2][1], pString, refValue);
    Check::Near (a.form3d[2][2], b.form3d[2][2], pString, refValue);

    Check::Near (a.form3d[0][3], b.form3d[0][3], pString, refValue);
    Check::Near (a.form3d[1][3], b.form3d[1][3], pString, refValue);
    Check::Near (a.form3d[2][3], b.form3d[2][3], pString, refValue);
    }

void Check::Near (DMatrix4d a, DMatrix4d b, char const*pString, double refValue)
    {
    for (int i = 0; i < 4; i++)
        {
        for (int j = 0; j < 4; j++)
            {
            char message[128];
            sprintf (message, "[%d][%d]", i, j);
            Check::StartScope (message);
            Check::Near (a.coff[i][j], b.coff[i][j], pString, refValue);
            Check::EndScope ();
            }
        }
    }


void Check::Near (DPoint4dCR a, DPoint4dCR b, char const*pString, double refValue)
    {
    double tol = Tol (a,b);
    EXPECT_NEAR (a.x, b.x, tol);
    EXPECT_NEAR (a.y, b.y, tol);
    EXPECT_NEAR (a.z, b.z, tol);
    EXPECT_NEAR (a.w, b.w, tol);
    }



void Check::Near (DPoint2dCR a, DPoint2dCR b, char const*pString, double refValue)
    {
    double tol = Tol (a,b);
    AssertNear (a.x, b.x, tol, pString);
    AssertNear (a.y, b.y, tol, pString);
    }

void Check::Near (DRange2dCR a, DRange2dCR b, char const*pString, double refValue)
    {
    if (a.IsNull () && b.IsNull ())
        return;
    double tol = Tol (a.low.Magnitude (), a.high.Magnitude (), b.low.Magnitude (), b.high.Magnitude ());
    AssertNear (a.low.x, b.low.x, tol, pString);
    AssertNear (a.low.y, b.low.y, tol, pString);

    AssertNear (a.high.x, b.high.x, tol, pString);
    AssertNear (a.high.y, b.high.y, tol, pString);
    }

void Check::Near (DPoint3dCR a, double xx, double yy, double zz, char const*pString, double refValue)
    {
    double tol = Tol (a.Magnitude (), xx, yy, zz);
    AssertNear (a.x, xx, tol, pString);
    AssertNear (a.y, yy, tol, pString);
    AssertNear (a.z, zz, tol, pString);
    }

void Check::Near (DPoint2dCR a, double xx, double yy, char const*pString, double refValue)
    {
    double tol = Tol (a.Magnitude (), xx, yy);
    AssertNear (a.x, xx, tol, pString);
    AssertNear (a.y, yy, tol, pString);
    }


bool Check::Bool (bool a, bool b, char const*pString)
    {
    if (a == b)
        return true;
    DoAssert (a == b, pString);
    return false;
    }

Tolerance::Tolerance (double abstol, double reltol)
    {
    m_abstol = abstol;
    m_reltol = reltol;
    }

double Tolerance::Evaluate (double refValue)
    {
    return fabs (m_abstol) + fabs (m_reltol * refValue);
    }

double Tolerance::Evaluate (double a, double b)
    {
    double x = fabs (a);
    b = fabs (b);
    if (b > x)
        x = b;
    return Evaluate (x);
    }

double Tolerance::Evaluate (double a, double b, double c)
    {
    double x = fabs (a);
    b = fabs (b);
    c = fabs (c);
    if (b > x)
        x = b;
    if (c > x)
        x = c;
    return Evaluate (x);
    }

double Tolerance::Evaluate (double a, double b, double c, double d)
    {
    double x = fabs (a);
    b = fabs (b);
    c = fabs (c);
    d = fabs (d);
    if (b > x)
        x = b;
    if (c > x)
        x = c;
    if (d > x)
        x = d;
    return Evaluate (x);
    }

Tolerance Check::m_defaultTolerance (1.0e-12, 1.0e-12);
Tolerance Check::m_tolerance (1.0e-12, 1.0e-12);

std::vector <Tolerance> Check::m_toleranceStack =std::vector<Tolerance> ();

Tolerance Check::m_toleranceBundle [] =
    {
    Tolerance (1.0e-12, 1.0e-12),
    Tolerance (1.0e-6,   1.0e-6),
    Tolerance (1.0e-14,   1.0e-14),
    Tolerance (1.0e-12,  1.0e-12),
    Tolerance (4.0e-16, 4.0e-16),
    };

void Check::PushTolerance (ToleranceSelect select)
    {
    m_toleranceStack.push_back (m_tolerance);
    m_tolerance = m_toleranceBundle[select];
    }

void Check::PopTolerance ()
    {
    if (m_toleranceStack.size () > 0)
        {
        m_tolerance = m_toleranceStack.back ();
        m_toleranceStack.pop_back ();
        }
    else
        m_tolerance = m_defaultTolerance;
    }

// Test harness list activities ...
// The singleton list ...
std::vector<TestInstanceData> s_testList;

// Run the whole list ...
void TestList::RunAll ()
    {
    for (size_t i = 0; i < s_testList.size (); i++)
        {
        printf ("<%ls>\n", s_testList[i].m_name.c_str());
        s_testList[i].m_instance->go ();
        printf ("</%ls>\n", s_testList[i].m_name.c_str());
        }
    }
// Register one test ...
void TestList::Register (TestInstanceData const &tiData){s_testList.push_back (tiData);}


TestInstanceData::TestInstanceData (TestInstance *instance, WString const &name) :
    m_name(name), m_instance(instance)
    {}

void Check::Start ()
    {
    }

void Check::End ()
    {
    TestList::RunAll ();
    }

void Check::PrintIndent (size_t depth)
    {
    printf ("\n");
    for (size_t i = 0; i < depth; i++)
        printf("  ");
    }
void Check::PrintStructure (ICurvePrimitiveCP primitive, size_t depth)
    {
    if (NULL == primitive)
        {
        printf (" NullCP");
        }
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Line)
        printf (" LINE");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_LineString)
        printf (" (LineStr %d)", (int)primitive->GetLineStringCP ()->size ());
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Arc)
        printf (" ARC");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_BsplineCurve)
        printf (" BCurve");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_InterpolationCurve)
        printf (" ICurve");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_AkimaCurve)
        printf (" Akima");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_PointString)
        printf (" PtStr");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_CurveVector)
        PrintStructure (primitive->GetChildCurveVectorCP(), depth + 1);
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Spiral)
        printf (" Spiral");
    else if (primitive->GetCurvePrimitiveType () == ICurvePrimitive::CURVE_PRIMITIVE_TYPE_PartialCurve)
        printf (" Partial");
    else
        printf (" UNKNOWN");
    }

void Check::PrintStructure (ISolidPrimitiveCP primitive)
    {
    if (NULL == primitive)
        {
        printf (" NullCP");
        }
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnTorusPipe)
        printf (" SolidPrimitiveType_DgnTorusPipe");
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnCone)
        printf (" (SolidPrimitiveType_DgnCone)");
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnBox)
        printf (" SolidPrimitiveType_DgnBox");
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnSphere)
        printf (" SolidPrimitiveType_DgnSphere");
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnExtrusion)
        printf (" SolidPrimitiveType_DgnExtrusion");
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnRotationalSweep)
        printf (" SolidPrimitiveType_DgnRotationalSweep");
    else if (primitive->GetSolidPrimitiveType () == SolidPrimitiveType::SolidPrimitiveType_DgnRuledSweep)
        printf (" SolidPrimitiveType_DgnRuledSweep");
    else
        printf (" UNKNOWN");
    }

void Check::PrintStructure (CurveVectorCP top, size_t depth)
    {
    if (NULL != top)
        {
        printf ("(");
        CurveVector::BoundaryType type = top->GetBoundaryType ();
        if (type == CurveVector::BOUNDARY_TYPE_Outer)
            printf ("Outer");
        else if (type == CurveVector::BOUNDARY_TYPE_Outer)
            printf ("Inner");
        else if (type == CurveVector::BOUNDARY_TYPE_Inner)
            printf ("Open");
        else if (type == CurveVector::BOUNDARY_TYPE_Open)
            printf ("None");
        else if (type == CurveVector::BOUNDARY_TYPE_ParityRegion)
            printf ("Parity");
        else if (type == CurveVector::BOUNDARY_TYPE_UnionRegion)
            printf ("Union");
        else
            printf ("UNKNOWNCV");
        for (size_t i = 0; i < top->size (); i++)
            PrintStructure (top->at(i).get (), depth + 1);
        printf (")");
        }
    else
        {
        printf ("(NullCV)");
        }
    }
void Check::PrintStructure (CurveVectorCP top, char *pName)
    {
    printf ("(%s", pName);
    PrintStructure (top, (size_t)0);
    printf (")\n");
    }



typedef std::pair<int, char const *> IntCharPair;
static bvector<IntCharPair > s_cvTypeName;
static bvector<IntCharPair > s_cpTypeName;

static void InitNameMaps ()
    {
    if (s_cvTypeName.size () == 0)
        {
        s_cvTypeName.push_back (IntCharPair ((int)CurveVector::BOUNDARY_TYPE_Open, "Open"));
        s_cvTypeName.push_back (IntCharPair ((int)CurveVector::BOUNDARY_TYPE_Outer, "Outer"));
        s_cvTypeName.push_back (IntCharPair ((int)CurveVector::BOUNDARY_TYPE_Inner, "Inner"));
        s_cvTypeName.push_back (IntCharPair ((int)CurveVector::BOUNDARY_TYPE_ParityRegion, "ParityRegion"));
        s_cvTypeName.push_back (IntCharPair ((int)CurveVector::BOUNDARY_TYPE_UnionRegion, "UnionRegion"));

        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Invalid, "Invalid"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Line, "Line"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_LineString, "LineString"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Arc, "Arc"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_BsplineCurve, "BsplineCurve"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_InterpolationCurve, "InterpolationCurve"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_AkimaCurve, "AkimaCurve"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_PointString, "PointString"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_CurveVector, "ChildCurveVector"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Spiral, "Spiral"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_PartialCurve, "PartialCurve"));
        s_cpTypeName.push_back (IntCharPair ((int)ICurvePrimitive::CURVE_PRIMITIVE_TYPE_NotClassified, "NotClassified"));

        }
    }

static const char *Find (bvector<IntCharPair> &table, int key, const char *defaultValue)
    {
    InitNameMaps ();
    for (size_t i = 0; i < table.size (); i++)
        if (table[i].first == key)
            return table[i].second;
    return defaultValue;
    }


static const char *NameString (CurveVectorCR cv)
    {
    return Find (s_cvTypeName, (int)cv.GetBoundaryType (), "UnknownCurveVectorType");
    }

static const char *NameString (ICurvePrimitiveCR cp)
    {
    return Find (s_cpTypeName, (int)cp.GetCurvePrimitiveType (), "UnknownCurveVectorType");
    }



void Check::Print (ICurvePrimitiveCR curve)
    {
    CurveVectorCP child = NULL;
    if (NULL != (child = curve.GetChildCurveVectorCP ()))
        {
        Print (*child, NULL);
        return;
        }


    printf ("      <%s>", NameString (curve));
    bvector<DPoint3d> const *pXYZ;
    DEllipse3d arc;
    MSBsplineCurveCP pCurve;
    DSegment3d segment;
    if (NULL != (pXYZ = curve.GetLineStringCP ()))
        {
        for (size_t i = 0; i < pXYZ->size (); i++)
            {
            DPoint3d xyz = pXYZ->at(i);
            printf ("\n        <xyz>%.16g,%.16g,%.16g</xyz>",
                xyz.x, xyz.y, xyz.z);
            }
        printf ("\n      ");
        }
    else if (curve.TryGetLine (segment))
        {
        printf ("%.16g,%.16g,%.16g,%.16g,%.16g,%.16g",
            segment.point[0].x, segment.point[0].y, segment.point[0].z,
            segment.point[1].x, segment.point[1].y, segment.point[1].z);
        }
    else if(curve.TryGetArc (arc))
        {
        printf ("%.16g,%.16g,%.16g,   %.16g,%.16g,%.16g,   %.16g,%.16g,%.16g,   %.16g,%.16g",
                    arc.center.x, arc.center.y, arc.center.z,
                    arc.vector0.x, arc.vector0.y, arc.vector0.z,
                    arc.vector90.x, arc.vector90.y, arc.vector90.z,
                    arc.start, arc.sweep);
        }
    else if (NULL != (pCurve = curve.GetBsplineCurveCP ()))
        {
        printf ("\n      <poles>");
        for (int i = 0; i < pCurve->NumberAllocatedPoles (); i++)
            {
            DPoint3d xyz = pCurve->GetPole (i);
            printf ("\n        <xyz>%.16g,%.16g,%.16g</xyz>", xyz.x, xyz.y, xyz.z);
            }
        printf ("\n      </poles>\n      ");
        }
    printf ("</%s>\n", NameString (curve));
    }


void Check::Print (CurveVectorCR curves, const char *callerName)
    {
    const char *name = NameString (curves);
    printf ("  <CurveVector type=\"%s\"", name);
    if (callerName != NULL)
        printf (" name=\"%s\"", callerName);
    printf (">\n");
    for (size_t i = 0; i < curves.size (); i++)
        Print (*curves[i]);
    printf ("  </CurveVector>\n");
    }

void Check::Print (CurveVectorPtr curves, const char *callerName)
    {
    if (curves.IsValid ())
        Print (*curves, callerName);
    else
        {
        if (NULL != callerName)
            printf ("<CurveVector name=\"%s\"/>\n", callerName);
        else
            printf ("<CurveVector/>\n");
        }
    }

void Check::Print (bvector<double> const &data, char const *name)
    {
    if (!PrintDeepStructs ())
        return;

    printf ("(%s", name == nullptr ? "doubles" : name);
    char buffer[100];
    size_t numChars = 2 + strlen (name);
    for (size_t i = 0; i < data.size (); i++)
        {
        sprintf (buffer, "  %.17g", data[i]);
        size_t numChars1 = strlen (buffer);
        if (numChars + numChars1 > 70)
            {
            printf ("\n");
            numChars = numChars1;
            }
        printf ("%s",buffer);
        }

    printf (")\n");
    }

void Check::Print (bvector<DSegment3dSizeSize> const &segments, const char *callerName)
    {
    printf (" DSegment3dSizeSize %s\n");
    for (DSegment3dSizeSize data : segments)
        {
        DSegment3d segment = data.Get ();
        printf("  (%.17g,%.17g,%.17g) (%.17g,%.17g,%.17g)\n",
                    segment.point[0].x,
                    segment.point[0].y,
                    segment.point[0].z,
                    segment.point[1].x,
                    segment.point[1].y,
                    segment.point[1].z,
                    data.GetTagA (),
                    data.GetTagB ()
                    );
        }
    }

void Check::Print (DPoint3dCR data, char const *name)
    {
    printf (" (%s %g, %g, %g)", NULL != name ? name : "xyz", data.x, data.y, data.z);
    }

void Check::Print (bvector<DPoint3d> const & data, char const *name)
    {
    printf ("(%s\n", name);
    for (DPoint3d const &xyz : data)
        printf (" (%s %g, %g, %g)\n", NULL != name ? name : "xyz", xyz.x, xyz.y, xyz.z);
    printf (")\n");
    }

void Check::Print0TerminatedBlocks (bvector<int> const & data, char const *name)
    {
    printf ("(%s\n", name);
    for (int const &value : data)
        {
        printf (" %d", value);
        if (value == 0)
          printf ("\n", value);
        }
    printf (")\n");
    }


void Check::Print (double data, char const *name)
    {
    printf (" (%s %g)", NULL != name ? name : "double", data);
    }

void Check::Print (DPoint2dCR data, char const *name)
    {
    printf (" (%s %g, %g)", NULL != name ? name : "xy", data.x, data.y);
    }
void Check::Print (DVec3dCR data, char const *name)
    {
    printf (" (%s %g, %g, %g)", NULL != name ? name : "Vxyz", data.x, data.y, data.z);
    }


static bvector<IGeometryPtr> s_cache;
static Transform s_transform = Transform::FromIdentity ();
void Check::SaveTransformed(IGeometryPtr const &data)
    {
    static double s_maxCoordinate = 1.0e12;
    DRange3d range;
    if (!data.IsValid ())
        Check::True (false, "SaveTransformed null pointer");
    else if (!data->TryGetRange (range))
        {
        Check::True (false, "SaveTransformed TryGetRange failed");
        }
    else if (range.IsNull ())
        {
        // Check::True (false, "SaveTransformed null range");
        }
    else if (range.MaxAbs () > s_maxCoordinate)
        {
        Check::True (false, "SaveTransformed huge range");
        }
    else
        {
        s_cache.push_back (data->Clone ());
        s_cache.back ()->TryTransformInPlace (s_transform);
        }
    }

void Check::SaveTransformed(bvector<IGeometryPtr> const &data)
    {
    for (auto &g : data)
        SaveTransformed (g);
    }
// Save (clone of) geometry in a cache
void Check::SaveTransformed(CurveVectorCR data)
    {
    SaveTransformed(IGeometry::Create(data.Clone()));
    }

void Check::SaveTransformed(CurveVectorPtr &data)
    {
    if (data.IsValid ())
        SaveTransformed(IGeometry::Create(data->Clone()));
    }

void Check::SaveTransformed(ICurvePrimitiveCR data)
    {
    SaveTransformed(IGeometry::Create (data.Clone ()));}
void Check::SaveTransformed(PolyfaceHeaderCR data)
    {
    auto clone = data.Clone ();
    clone->ConvertToVariableSizeSignedOneBasedIndexedFaceLoops();
    SaveTransformed(IGeometry::Create (clone));
    }
void Check::SaveTransformed(PolyfaceHeaderPtr &data)
    {
    if (data.IsValid ())
        {
        auto clone = data->Clone();
        clone->ConvertToVariableSizeSignedOneBasedIndexedFaceLoops();
        SaveTransformed(IGeometry::Create(clone));
        }
    }
void Check::SaveTransformed(ISolidPrimitiveCR data)
    {
    SaveTransformed(IGeometry::Create (data.Clone ()));}
void Check::SaveTransformed(DEllipse3dCR data)
    {
    if (data.vector0.Magnitude () + data.vector90.Magnitude () == 0.0)
        SaveTransformedMarker (data.center);
    else
        SaveTransformed(*ICurvePrimitive::CreateArc (data));
    }

void Check::SaveTransformed(MSBsplineSurfacePtr const &data)
    {
    SaveTransformed(IGeometry::Create (data->Clone ()));}
void Check::SaveTransformedEdges(DRange3dCR range)
    {
    DPoint3d corners[8];
    range.Get8Corners (corners);
    return SaveTransformedEdges (corners);
    }
void Check::SaveTransformedEdges(DPoint3d corners[8])
    {
    Check::SaveTransformed (bvector<DPoint3d>{
        corners[0], corners[1], corners[3], corners[2], corners[0],
        corners[4], corners[5], corners[7], corners[6], corners[4]});
    Check::SaveTransformed (DSegment3d::From (corners[1], corners[5]));
    Check::SaveTransformed(DSegment3d::From(corners[2], corners[6]));
    Check::SaveTransformed(DSegment3d::From(corners[3], corners[7]));
    }
void Check::SaveTransformed(MSBsplineCurvePtr const &data, bool savePolygon)
    {
    SaveTransformed(IGeometry::Create (
        ICurvePrimitive::CreateBsplineCurve (data->CreateCopy ())));
    if (savePolygon)
        Check::SaveTransformed (data->poles, data->GetNumPoles ());
    }

void Check::SaveTransformed (bvector<DPoint3d> const &data, bool addClosure)
    {
    auto cv = ICurvePrimitive::CreateLineString (data);
    if (addClosure && data.size () > 0)
        cv->GetLineStringP ()->push_back (data[0]);
    SaveTransformed (IGeometry::Create (cv));
    }
void Check::SaveTransformed (DPoint3dCP pData, size_t n)
    {
    bvector<DPoint3d> data;
    for (size_t i = 0; i < n; i++)
        data.push_back (pData[i]);
    SaveTransformed (data);
    }

void Check::SaveTransformed (bvector<DPoint4d> const &data)
    {
    bvector<DPoint3d> points;
    for (auto & xyzw : data)
        {
        DPoint3d xyz;
        if (xyzw.GetProjectedXYZ (xyz))
            points.push_back (xyz);
        }
    SaveTransformed (points);
    }

void Check::SaveTransformedMarker (DPoint3dCR &xyz, double markerSize)
    {
    ICurvePrimitivePtr cp;
    if (markerSize > 0)
        cp = ICurvePrimitive::CreateLineString
            (
            bvector<DPoint3d>
                {
                DPoint3d::From (xyz.x - markerSize, xyz.y, xyz.z),
                DPoint3d::From (xyz.x + markerSize, xyz.y, xyz.z),
                DPoint3d::From (xyz.x, xyz.y + markerSize, xyz.z),
                DPoint3d::From (xyz.x, xyz.y - markerSize, xyz.z)
                }
            );
    else
        cp = ICurvePrimitive::CreateArc (DEllipse3d::FromCenterRadiusXY (xyz, fabs (markerSize)));

    SaveTransformed (IGeometry::Create (cp));
    }

void Check::SaveTransformedMarkers (bvector<DPoint3d> const &data, double markerSize)
    {
    for (auto &xyz : data)
        SaveTransformedMarker (xyz);
    }



void Check::SaveTransformed (bvector<bvector<DPoint3d>> const &data)
    {
    for (auto a : data)
        SaveTransformed (a);
    }

void Check::SaveTransformed (bvector<DTriangle3d> const &data, bool closed)
    {
    bvector<DPoint3d> points;
    for (auto &t : data)
        {
        points.clear ();
        points.push_back (t.point[0]);
        points.push_back (t.point[1]);
        points.push_back (t.point[2]);
        if (closed)
            {
            points.push_back (t.point[0]);
            auto shape = CurveVector::CreateLinear (points, CurveVector::BOUNDARY_TYPE_Outer);
            SaveTransformed (*shape);
            }
        else
            SaveTransformed (points);
        }
    }

void Check::SaveTransformed (bvector<DSegment3d> const &data)
    {
    for (auto &segment : data)
        {
        auto prim = ICurvePrimitive::CreateLine (segment);
        SaveTransformed (*prim);
        }
    }

void Check::SaveTransformed (DSegment3dCR data)
    {
    auto prim = ICurvePrimitive::CreateLine (data);
    SaveTransformed (*prim);
    }
void Check::SaveTransformed (MSBsplineCurveCR data)
    {
    auto cv = ICurvePrimitive::CreateBsplineCurve (data);
    SaveTransformed (IGeometry::Create (cv));
    }


void Check::Shift (double dx, double dy, double dz)
    {
    s_transform = Transform::From (dx, dy, dz) * s_transform;
    }

void Check::Shift (DVec3dCR shift)
    {
    s_transform = Transform::From (shift.x, shift.y, shift.z) * s_transform;
    }

void Check::ShiftToLowerRight (double dx)
    {
    auto range = DRange3d::NullRange ();
    for (auto g : s_cache)
        {
        DRange3d gRange;
        if (g->TryGetRange (gRange))
            range.Extend (gRange);
        }
    auto frame = Transform::From (range.LocalToGlobal (1,0,0) + DVec3d::From (dx, 0, 0));
    SetTransform (frame);
    }

Transform Check::GetTransform () {return s_transform;}
void Check::SetTransform (TransformCR transform) {s_transform = transform;}


static int s_save = 1;

void Check::ClearGeometry (char const *name, bool saveIModelJson)
    {
    if (s_save == 1)
        {
        // save to the run/output directory, which we expect to under the working directory.
        BeFileName path;
#ifdef UseGetOutputRoot
        BeTest::GetHost ().GetOutputRoot (path);
#else
        WString wpath;
        BeStringUtilities::Utf8ToWChar (wpath, "D:/tmp/");
        path.AppendToPath (wpath.c_str ());
#endif
        WString wname;
        BeStringUtilities::Utf8ToWChar (wname, name);
        path.AppendToPath (wname.c_str ());
        path.AppendExtension (saveIModelJson ? L"imjs" : L"dgnjs");

        //Importing a dgnjs file with the key-in "face import dgnjs" is slow when the file is big.
        //Overwriting a big dgnjs file by a smaller file doesn't reduce its size.
        //JP Wenger - 10/2017
        DWORD dwAttrib = GetFileAttributesW (path.c_str());
        if (dwAttrib != INVALID_FILE_ATTRIBUTES
            && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY))
            ::DeleteFileW (path.c_str ());

        Utf8String string;
        bool haveString = saveIModelJson
            ? IModelJson::TryGeometryToIModelJsonString(string, s_cache)
            : BentleyGeometryJson::TryGeometryToJsonString(string, s_cache, true);

        if (haveString)
            {
            BeFile file;
            if (BeFileStatus::Success == file.Create(path.c_str()))
                {
                uint32_t bytesWritten = 0;
                file.Write(&bytesWritten, string.c_str(), (uint32_t) string.size());
                }
            file.Close();
            }
        }
    else if (s_save == 2)
        {
        Utf8String string;
        BentleyGeometryJson::TryGeometryToJsonString(string, s_cache, true);
        BentleyGeometryJson::DumpJson(string);
        //bvector<IGeometryPtr> g1;
        //BentleyGeometryJson::TryJsonStringToGeometry (string, g1);
        }
    s_cache.clear ();
    s_transform = Transform::FromIdentity ();
    }

/*---------------------------------------------------------------------------------**//**
* @description Handy helper method to load JSON testcase geometry.
* @bsimethod                                                    David.Assaf     06/2022
+---------------+---------------+---------------+---------------+---------------+------*/
bool Check::LoadFileAsString(WCharCP fileName, Utf8String& string)
    {
    string.clear();

    BeFileName fullFileName(fileName);
    fullFileName.BeGetFullPathName();

    BeFile file;
    if (BeFileStatus::Success == file.Open(fullFileName.GetName(), BeFileAccess::Read, BeFileSharing::Read))
        {
        bvector<Byte> buffer;
        if (BeFileStatus::Success == file.ReadEntireFile(buffer))
            {
            for (auto b : buffer)
                string.push_back(b);
            }
        }

    DoAssert(!string.empty(), "LoadFileAsString failure.");
    return !string.empty();
    }
