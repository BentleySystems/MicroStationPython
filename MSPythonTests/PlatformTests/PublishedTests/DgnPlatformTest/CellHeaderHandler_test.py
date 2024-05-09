import os
import sys
import pytest
import math


from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

EPSILON = 0.000000001

def isDPoint3dNear(left, right , Epsilon):

    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)

def GeneratePoints(points, sz):
    SCALE = 1000.0
    
    for i in range(0,sz):
        # x = SCALE * i
        # y = SCALE * i
        # z = SCALE * i
        # points.append(DPoint3d(x,y,z))
        points[i].x= SCALE * i 
        points[i].y= SCALE * i 
        points[i].z= SCALE * i
        
def insertElement (existingElement, element):
    header = existingElement.h.myHeader
    assert header!=None
    
    tElDescr = MSElementDescr.Allocate (element, None, header)
    
    prevElement = existingElement.h.previous
    tElDescr.h.next = existingElement
    existingElement.h.previous = tElDescr
        
    #special case if this is to be the first element in chain
    tElDescr.h.previous=prevElement
    if tElDescr.h.previous == header:
        header.h.firstElem     = tElDescr
    else:
        prevElement.h.next     = tElDescr

    header.h.isValid = False
    return  BentleyStatus.eSUCCESS
        
m_eeh= EditElementHandle ()

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])  
def test_CreateCellElement(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    NormalCellHeaderHandler.CreateOrphanCellElement (m_eeh, "test", ret[0].Is3d(), ret[0])
    
    NUM_LINES = 3
    NUM_POINTS = 2
    
    segmentList = [DSegment3d() for _ in range(NUM_LINES)]
            
    for i in range( 0 ,NUM_LINES):
        start = i * 1000.0
        end   = (i+1) * 1000.0
        segmentList[i].point = [(start,start,start),(end,end,end)]

    m_eehLines = EditElementHandle ()
        
    for j in range(0,NUM_LINES):
        LineHandler.CreateLineElement (m_eehLines, None, segmentList[j], ret[0].Is3d(), ret[0])
        assert BentleyStatus.eSUCCESS == NormalCellHeaderHandler.AddChildElement (m_eeh, m_eehLines)
        

    assert BentleyStatus.eSUCCESS == NormalCellHeaderHandler.AddChildComplete (m_eeh)
    
    child = ChildElemIter(m_eeh)
    print(child,child.IsValid())
    numChildren = 0
    while(child.IsValid()):
        elm = child.GetElement ()
        assert True == isDPoint3dNear (segmentList[numChildren].StartPoint, elm.line_3d.start, EPSILON)
        assert True == isDPoint3dNear (segmentList[numChildren].EndPoint, elm.line_3d.end, EPSILON)
        child = child.ToNext()
        numChildren +=1

    print(numChildren)

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])  
def test_InsertChildPreserveExistingElementIds(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    NormalCellHeaderHandler.CreateOrphanCellElement (m_eeh, "test", ret[0].Is3d(), ret[0])
    
    points = [DPoint3d() for _ in range(2)]
    lineSegment = DSegment3d()
    lineSegment.point = [(0.0, 0.0, 0.0),(100.0, 100.0, 100.0)]
    
    line1= EditElementHandle ()
    line2= EditElementHandle ()
    
    LineHandler.CreateLineElement (line1, None, lineSegment, ret[0].Is3d(), ret[0])
    LineHandler.CreateLineElement (line2, None, lineSegment, ret[0].Is3d(), ret[0])
    
    #  Cell
    #      -Line1
    #      -Line2
    assert BentleyStatus.eSUCCESS == NormalCellHeaderHandler.AddChildElement (m_eeh, line1)
    assert BentleyStatus.eSUCCESS == NormalCellHeaderHandler.AddChildElement (m_eeh, line2)
    assert BentleyStatus.eSUCCESS == NormalCellHeaderHandler.AddChildComplete (m_eeh)

    m_eeh.AddToModel ()

    cellRef = m_eeh.GetElementRef()

    v1_l1 = m_eeh.GetElementDescr().h.firstElem.el.ehdr.uniqueId
    v1_l2 = m_eeh.GetElementDescr().h.firstElem.h.next.el.ehdr.uniqueId

    #  Cell
    #      -Line1
    #      -Circle
    #      -Line2
    circle= EditElementHandle ()
    matrix = RotMatrix()
    EllipseHandler.CreateEllipseElement (circle, None, lineSegment.StartPoint, 1,1, matrix, ret[0].Is3d(), ret[0])
    assert BentleyStatus.eSUCCESS == insertElement (m_eeh.GetElementDescr().h.firstElem.h.next, circle.GetElement())
    
    m_eeh.ReplaceInModel (cellRef)

    v2_l1 = m_eeh.GetElementDescr().h.firstElem.el.ehdr.uniqueId
    v2_c  = m_eeh.GetElementDescr().h.firstElem.h.next.el.ehdr.uniqueId
    v2_l2 = m_eeh.GetElementDescr().h.firstElem.h.next.h.next.el.ehdr.uniqueId

    DependencyManager.ProcessAffected ()
    
    assert v1_l1 == v2_l1
    assert v1_l2 == v2_l2
    assert v2_c != v2_l1
    assert v2_c != v2_l2
    

