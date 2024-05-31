/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\OpqueTypes_Geom.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/

#pragma once

#include "OpqueTypes_Bentley.h"

// Opaque types
DEFINE_BVECTOR_TYPE(DPoint2d, DPoint2dArray);
DEFINE_BVECTOR_TYPE(Point2d, Point2dArray);
DEFINE_BVECTOR_TYPE(DPoint3d, DPoint3dArray);
DEFINE_BVECTOR_TYPE(Point3d, Point3dArray);
DEFINE_BVECTOR_TYPE(DPoint4d, DPoint4dArray);
DEFINE_BVECTOR_TYPE(DVec2d, DVec2dArray);
DEFINE_BVECTOR_TYPE(DVec3d, DVec3dArray);
DEFINE_BVECTOR_TYPE(GraphicsPoint, GraphicsPointVec);
DEFINE_BVECTOR_TYPE(DPoint2dArray, DPoint2dVecArray);
DEFINE_BVECTOR_TYPE(DPoint3dArray, DPoint3dVecArray);
DEFINE_BVECTOR_TYPE(DPoint3dVecArray, DPoint3dVecVecArray);
DEFINE_BVECTOR_TYPE(DVec3dArray, DVec3dVecArray);
DEFINE_BVECTOR_TYPE(ICurvePrimitivePtr, ICurvePrimitiveArray);
DEFINE_BVECTOR_TYPE(DSegment1d, DSegment1dArray);
DEFINE_BVECTOR_TYPE(DSegment3d, DSegment3dArray);
DEFINE_BVECTOR_TYPE(CurveLocationDetail, CurveLocationDetailArray);
DEFINE_BVECTOR_TYPE(CurveLocationDetailPair, CurveLocationDetailPairArray);
DEFINE_BVECTOR_TYPE(CurveAndSolidLocationDetail, CurveAndSolidLocationDetailArray);
DEFINE_BVECTOR_TYPE(CurveCurve::FilletDetail, FilletDetailArray);
DEFINE_BVECTOR_TYPE(BlendDetail, BlendDetailArray);
DEFINE_BVECTOR_TYPE(DRange1d, DRange1dArray);
DEFINE_BVECTOR_TYPE(DPlane3d, DPlane3dArray);
DEFINE_BVECTOR_TYPE(CurveVectorPtr, CurveVectorArray);
DEFINE_BVECTOR_TYPE(DTriangle3d, DTriangle3dArray);
DEFINE_BVECTOR_TYPE(MSBsplineCurvePtr, MSBsplineCurvePtrArray);
DEFINE_BVECTOR_TYPE(MSBsplineSurfacePtr, MSBsplineSurfacePtrArray);
DEFINE_BVECTOR_TYPE(MSBsplineCurve, MSBsplineCurveArray);
DEFINE_BVECTOR_TYPE(SolidLocationDetail, SolidLocationDetailArray);
DEFINE_BVECTOR_TYPE(SolidLocationDetail::FaceIndices, FaceIndicesArray);
DEFINE_BVECTOR_TYPE(ConvexClipPlaneSet, ConvexClipPlaneSetArray);
DEFINE_BVECTOR_TYPE(MeshAnnotation, MeshAnnotationArray);
DEFINE_BVECTOR_TYPE(PolyfaceHeaderPtr, PolyfaceHeaderArray);
DEFINE_BVECTOR_TYPE(FacetLocationDetail, FacetLocationDetailArray);
DEFINE_BVECTOR_TYPE(DSegment3dSizeSize, DSegment3dSizeSizeArray);
DEFINE_BVECTOR_TYPE(CurveTopologyId, CurveTopologyIdArray);
DEFINE_BVECTOR_TYPE(FloatRgb, FloatRgbArray);
DEFINE_BVECTOR_TYPE(RgbFactor, RgbFactorArray);
DEFINE_BVECTOR_TYPE(FacetFaceData, FacetFaceDataArray);
DEFINE_BVECTOR_TYPE(PolyfaceEdgeChain, PolyfaceEdgeChainArray);
