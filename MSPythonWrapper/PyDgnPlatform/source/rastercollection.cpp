/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\rastercollection.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <RasterCore/DgnRaster.h>
#include <RasterCore/RasterCollection.h>

static const char* __doc_Bentley_DgnPlatform_Raster_DgnRasterCollection_QueryRastersOrderedList = R"doc(@description The QueryRastersOrderedList function retrieves a list of
all currently used rasters that belong to a specific model and/or its
child models sorted by display order.

Parameter ``rasterOrderedList``:
    OUT the list that will be filled by the query, if not empty, new
    value will be append at end.

Parameter ``pRootModel``:
    IN Root model from which to start the raster extraction

Parameter ``iteratorType``:
    IN MRITERATE_Root, MRITERATE_PrimaryChildRefs or MRITERATE_Root
    MRITERATE_PrimaryChildRefs for root model and children

Parameter ``depth``:
    IN Nesting depth. O for primary reference files or -1 for primary
    references and nested references +---------------+---------------+
    ---------------+---------------+---------------+------)doc";

using namespace Raster;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RasterCollection(py::module_& m)
    {
    py::bind_vector< bvector<DgnRasterP> >(m, "DgnRasterVector", py::module_local(false));
    py::bind_vector< bvector<DgnPlatform::GeoreferencePriority> >(m, "GeoreferencePriorityVector", py::module_local(false));

    //===================================================================================
    // struct  DgnRasterCollection
    py::class_< DgnRasterCollection, std::unique_ptr<DgnRasterCollection, py::nodelete> > c0(m, "DgnRasterCollection");

    if (true)
        {
        //===================================================================================
        // struct  DgnRasterCollection
        py::class_< DgnRasterCollection::DgnRasterCollectionIterator, RefCountedPtr<DgnRasterCollection::DgnRasterCollectionIterator> > c0_1(c0, "DgnRasterCollectionIterator", py::multiple_inheritance());

        c0_1.def("IsDifferent", &DgnRasterCollection::DgnRasterCollectionIterator::IsDifferent, "rhs"_a);
        c0_1.def("MoveToNext", &DgnRasterCollection::DgnRasterCollectionIterator::MoveToNext);
        c0_1.def("GetCurrent", &DgnRasterCollection::DgnRasterCollectionIterator::GetCurrent);
        }

    c0.def("__iter__", [](DgnRasterCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c0.def_static("GetRasters", [](DgnModelRefP modelRef) 
            {
            return std::unique_ptr<DgnRasterCollection, py::nodelete> (&DgnRasterCollection::GetRastersR(modelRef));
            }, "modelRef"_a);

    c0.def_static("QueryRastersOrderedList", &DgnRasterCollection::QueryRastersOrderedList, "rasterOrderedList"_a, "pRootModel"_a,
                                             "iteratorType"_a = (MRITERATE_Root | MRITERATE_PrimaryChildRefs | MRITERATE_IncludeRedundant), "depth"_a = -1,
                                              DOC(Bentley,DgnPlatform_Raster,DgnRasterCollection,QueryRastersOrderedList) );
    c0.def("Find", &DgnRasterCollection::FindP, "elmRefP"_a);
    }

