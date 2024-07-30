#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *

def EvaluateClothoidTerms(s, L, R, terms, minTerm, maxTerm, relTolR):
    if maxTerm > 32:
        maxTerm = 32
    tol = relTolR * R
    terms.clear()
    terms.append(s)
    W = s
    B = s * s / ( 2.0 * L * R) 
    Q = 0.0
    numAccept = 0
    for k in range(1, maxTerm):
        W = B * W / ( k + 0.0 )
        Q = W / (2.0 * k + 1.0)
        terms.append(Q)
        if Q < tol:
            numAccept = numAccept + 1
        if numAccept > 1 and k >= minTerm:
            return
    
def SumClothoidTerms(terms, x, y, lastXTerm, lastYTerm):
    x = 0.0
    y = 0.0
    ix = 0
    iy = 0
    n = 0
    n = len(terms)
    if n & 0x01:
        ix = n - 1
        iy = n - 2
    else:
        iy = n - 1
        ix = n - 2
    sx = 0.0
    sy = 0.0
    if ix & 0x02: 
        sx = -1.0
    else:
        sx = 1.0
    
    if iy & 0x02:
        sy = -1.0
    else:
        sy = 1.0
    
    lastXTerm = terms[ix]
    lastYTerm = terms[iy]
    i = ix
    while i >= 0:
        x += sx * terms[i]
        i -=2
        sx *= -1.0
    
    i = iy
    while i >= 0:
        y += sy * terms[i]
        i -= 2
        sy *= -1.0

def SafeDivide(numerator, denominator, defaultResult, fraction):
    if denominator > fraction * numerator:
        result = numerator / denominator
        return True
    result = defaultResult
    return False


def test_BareTerms():
    L = 100.0
    terms = []
    x = y = dx = dy = 0.0
    for relTol in [1.0e-9, 1.0e-12, 1.0e-13, 1.0e-14, 1.0e-15]:
        rxMax = 0.0
        ryMax = 0.0
        print(" series relTol ", relTol)
        print()
        print(" (f) (terms) (x lastTerm errorX) (y lastTerm errorY\n")
        for rFactor in [4.0, 10.0, 20.0]:
            R = rFactor * L
            T = Transform()
            T.InitIdentity()
            spiral = ICurvePrimitive.CreateSpiralBearingRadiusLengthRadius(
                    DSpiral2dBase.TransitionType_Clothoid,
                    0.0, 0.0,
                    L, R,
                    T,
                    0.0, 1.0
                )
            placement = spiral.GetSpiralPlacement ()
            print("\n Series Clothoid R = ", R  ," L = ", L ," relTol = ", relTol)
            for f in [0.0, 0.1, 0.2, 0.7, 0.8, 0.9, 1.0 ]:
                EvaluateClothoidTerms (f * L, L, R, terms, 2, 20, relTol)
                SumClothoidTerms (terms, x, y, dx, dy)
                xyz = DPoint3d()
                spiral.FractionToPoint(f,xyz)
                delta = DVec2d()
                errorBound = 0.0
                DSpiral2dBase.Stroke(placement.spiral, 0.0, f, 0.01, delta, errorBound)
                ex = 0.0
                ey = 0.0
                SafeDivide(ex, delta.x - x, x, 0.0) 
                SafeDivide(ey, delta.y - y, y, 0.0)
                print('%.14f' %f , " " , len(terms) , "x " , '%.14f' %x , " " , '%8.1f' %dx , " " , '%8.1f' %ex , "y " , '%.14f' %y , " " , '%8.1f' %dy , " " , '%8.1f' %ey)
                assert ex <= relTol
                assert ey <= relTol
                rxMax = max(ex, rxMax)
                ryMax = max(ey, ryMax)
        print("relTol ", relTol , " rxMax ", rxMax , " ryMax " , ryMax)


