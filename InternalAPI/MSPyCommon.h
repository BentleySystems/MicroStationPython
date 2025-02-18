/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\MSPyCommon.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once
#include "ScriptEngineManager.h"

#define _CRT_SECURE_NO_WARNINGS

#define __EXPAND(x)                                      x
#define __COUNT(_1, _2, _3, _4, _5, _6, _7, COUNT, ...)  COUNT
#define __VA_SIZE(...)                                   __EXPAND(__COUNT(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0))
#define __CAT1(a, b)                                     a ## b
#define __CAT2(a, b)                                     __CAT1(a, b)
#define __DOC1(n1)                                       __doc_##n1
#define __DOC2(n1, n2)                                   __doc_##n1##_##n2
#define __DOC3(n1, n2, n3)                               __doc_##n1##_##n2##_##n3
#define __DOC4(n1, n2, n3, n4)                           __doc_##n1##_##n2##_##n3##_##n4
#define __DOC5(n1, n2, n3, n4, n5)                       __doc_##n1##_##n2##_##n3##_##n4##_##n5
#define __DOC6(n1, n2, n3, n4, n5, n6)                   __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define __DOC7(n1, n2, n3, n4, n5, n6, n7)               __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define DOC(...)                                         __EXPAND(__EXPAND(__CAT2(__DOC, __VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

// Custom deleter for py holder
struct mspydelete {
    void operator()(RefCountedBase* p)
    {
        if (nullptr != p && 0 == p->Release())
        {
            p = nullptr;
        }
    }
};


// Opaque types of bvector
#define DEFINE_BVECTOR_TYPE(ValueT, ArrayT) typedef bvector<ValueT> ArrayT; PYBIND11_MAKE_OPAQUE(ArrayT)

// Opaque types of bmap
#define DEFINE_BMAP_TYPE(KeyT, ValueT, MapT) typedef bmap<KeyT, ValueT> MapT; PYBIND11_MAKE_OPAQUE(MapT)
#define DEFINE_BMAP_TYPE_COMPARE(KeyT, ValueT, CompareT, MapT) typedef bmap<KeyT, ValueT, CompareT> MapT; PYBIND11_MAKE_OPAQUE(MapT)

// Smart pointer declaration
PYBIND11_DECLARE_HOLDER_TYPE(RefCountedBaseT, RefCountedPtr<RefCountedBaseT>, false);

// Non-delete smart pointer
#define DEFINE_NODELETE_HOLDER_TYPE(type) using type##Ptr = std::unique_ptr<type, py::nodelete>

namespace PYBIND11_NAMESPACE {
    namespace detail {
        template <typename T>
        struct type_caster<boost::optional<T>> : optional_caster<boost::optional<T>> {};
    }
}

// PYBIND11_OVERRIDE with exception capture and has return value.
#define PYBIND11_OVERRIDE_EXR(ret_type, cname, fn, error, ...)              \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE(ret_type, cname, fn, __VA_ARGS__);                \
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        return error;                                                       \
        }

// PYBIND11_OVERRIDE with exception capture and no return value.
#define PYBIND11_OVERRIDE_EX(ret_type, cname, fn, ...)                      \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE(ret_type, cname, fn, __VA_ARGS__);                \
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        }

// PYBIND11_OVERRIDE_NAME with exception capture and has return value.
#define PYBIND11_OVERRIDE_NAME_EXR(ret_type, cname, name, fn, error, ...)   \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE_NAME(ret_type, cname, name, fn, __VA_ARGS__);     \
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        return error;                                                       \
        }

// PYBIND11_OVERRIDE_NAME with exception capture and no return value.
#define PYBIND11_OVERRIDE_NAME_EX(ret_type, cname, name, fn, ...)           \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE_NAME(ret_type, cname, name, fn, __VA_ARGS__);     \
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        }

// PYBIND11_OVERRIDE_PURE with exception capture and has return value.
#define PYBIND11_OVERRIDE_PURE_EXR(ret_type, cname, fn, error, ...)         \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE_PURE(ret_type, cname, fn, __VA_ARGS__);           \
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        return error;                                                       \
        }

// PYBIND11_OVERRIDE_PURE with exception capture and no return value.
#define PYBIND11_OVERRIDE_PURE_EX(ret_type, cname, fn, ...)                 \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE_PURE(ret_type, cname, fn, __VA_ARGS__);           \
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        }

// PYBIND11_OVERRIDE_PURE_NAME with exception capture and has return value.
#define PYBIND11_OVERRIDE_PURE_NAME_EXR(ret_type, cname, name, fn, error, ...)    \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE_PURE_NAME(ret_type, cname, name, fn, __VA_ARGS__);\
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        return error;                                                       \
        }

// PYBIND11_OVERRIDE_PURE_NAME with exception capture and no return value.
#define PYBIND11_OVERRIDE_PURE_NAME_EX(ret_type, cname, name, fn, ...)      \
    try                                                                     \
        {                                                                   \
        PYBIND11_OVERRIDE_PURE_NAME(ret_type, cname, name, fn, __VA_ARGS__);\
        }                                                                   \
    catch (std::exception& ex)                                              \
        {                                                                   \
        Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex);    \
        }

// template<typename T> class bvector
template <typename ValueType, typename holder_type = std::unique_ptr<bvector<ValueType>>, typename... Args>
py::class_<bvector<ValueType>, holder_type> bind_PointerVector(py::handle scope, std::string const& name, Args &&...args)
    {
    using Container = bvector<ValueType>;
    using Class_ = py::class_<Container, holder_type>;

    auto* vtype_info = py::detail::get_type_info(typeid(ValueType));
    bool local = !vtype_info || vtype_info->module_local;

    Class_ cls(scope, name.c_str(), py::module_local(local), std::forward<Args>(args)...);

    cls.def(py::init([] () { return holder_type(new Container()); }));
    
    cls.def(py::init([] (size_t n) { return holder_type(new Container(n)); }));
    
    cls.def("__bool__", [] (Container const& self) { return !self.empty(); });
    
    cls.def("__len__", &Container::size);
    
    cls.def("__getitem__", [] (Container const& self, size_t index)
            {
            if (index >= self.size())
                throw py::index_error();
            return self[index];
            }, py::return_value_policy::reference_internal);

    cls.def("__setitem__", [] (Container& self, size_t index, ValueType newItem)
            {
            if (index >= self.size())
                throw py::index_error();
            self[index] = newItem;
            }, py::keep_alive<1, 3>());

    cls.def("__delitem__", [] (Container& self, size_t index)
            {
            if (index >= self.size())
                throw py::index_error();

            auto it = self.begin();
            self.erase(it + index);
            });

    cls.def("__contains__", [] (Container& self, ValueType newItem)
            {
            return std::find(self.begin(), self.end(), newItem) != self.end();
            });

    cls.def("remove", [] (Container& self, ValueType newItem)
            {
            auto it = std::find(self.begin(), self.end(), newItem);
            if (it != self.end())
                self.erase(it);
            else
                throw py::value_error();
            });

    cls.def("__iter__", [] (Container& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    cls.def("resize", [] (Container& self, size_t n) { self.resize(n); }, "newSize"_a);

    cls.def("clear", &Container::clear);

    cls.def("push_back", [] (Container& self, ValueType newItem) { self.push_back(newItem); }, "newItem"_a, py::keep_alive<1, 2>());    

    return cls;
    }
