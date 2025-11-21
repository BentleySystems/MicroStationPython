/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\MSPyCommon.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once
#include "ScriptEngineManager.h"

using namespace std;

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
PYBIND11_DECLARE_HOLDER_TYPE(T, TempObjectOwner<T>, false);

// Non-delete smart pointer
#define DEFINE_NODELETE_HOLDER_TYPE(type) using type##Ptr = std::unique_ptr<type, py::nodelete>

namespace std {
    template <typename _Ty1, typename _Ty2>
    struct tuple_size<Bentley::Bstdcxx::bpair<_Ty1, _Ty2>> : std::integral_constant<size_t, 2> {};

    template<class _Ty1,class _Ty2>
    struct tuple_element<0, Bentley::Bstdcxx::bpair<_Ty1, _Ty2> >
        {	// struct to determine type of element 0 in pair
        typedef _Ty1 type;
        };

    template<class _Ty1, class _Ty2>
    struct tuple_element<1, Bentley::Bstdcxx::bpair<_Ty1, _Ty2> >
        {	// struct to determine type of element 1 in pair
        typedef _Ty2 type;
        };

    template <typename _Rtype, typename _Ty1, typename _Ty2>
    constexpr _Rtype _Pair_get(Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr, std::integral_constant<size_t, 0>) noexcept {
        return _Pr.first;
    }

    template <typename _Rtype, typename _Ty1, typename _Ty2>
    constexpr _Rtype _Pair_get(Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr, std::integral_constant<size_t, 1>) noexcept {
        return _Pr.second;
    }

    template<size_t _Idx,
        class _Ty1,
        class _Ty2> inline
        constexpr typename tuple_element<_Idx, Bentley::Bstdcxx::bpair<_Ty1, _Ty2> >::type&
        get (Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr) noexcept
        {	// get reference to element at _Idx in pair _Pr
        typedef typename tuple_element<_Idx, pair<_Ty1, _Ty2> >::type& _Rtype;
        return (_Pair_get<_Rtype>(_Pr, integral_constant<size_t, _Idx>()));
        };

    template<class _Ty1,
        class _Ty2> inline
        constexpr _Ty1& get(Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr) noexcept
        {	// get reference to element _Ty1 in pair _Pr
        return (_STD get<0>(_Pr));
        };

    template<class _Ty2,
        class _Ty1> inline
        constexpr _Ty2& get(Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr) noexcept
        {	// get reference to element _Ty2 in pair _Pr
        return (_STD get<1>(_Pr));
        };

    template<size_t _Idx,
        class _Ty1,
        class _Ty2> inline
        constexpr typename tuple_element<_Idx, Bentley::Bstdcxx::bpair<_Ty1, _Ty2> >::type&&
        get (Bentley::Bstdcxx::bpair<_Ty1, _Ty2>&& _Pr) noexcept
        {	// get rvalue reference to element at _Idx in pair _Pr
        typedef typename tuple_element<_Idx, pair<_Ty1, _Ty2> >::type&& _RRtype;
        return (_STD forward<_RRtype>(_STD get<_Idx>(_Pr)));
        };

    template<class _Ty1,
        class _Ty2> inline
        constexpr _Ty1&& get(Bentley::Bstdcxx::bpair<_Ty1, _Ty2>&& _Pr) noexcept
        {	// get rvalue reference to element _Ty1 in pair _Pr
        return (_STD get<0>(_STD move(_Pr)));
        };

    template<class _Ty2,
        class _Ty1> inline
        constexpr _Ty2&& get(Bentley::Bstdcxx::bpair<_Ty1, _Ty2>&& _Pr) noexcept
        {	// get rvalue reference to element _Ty2 in pair _Pr
        return (_STD get<1>(_STD move(_Pr)));
        };

    template<size_t _Idx,
        class _Ty1,
        class _Ty2> inline
        constexpr const typename tuple_element<_Idx, Bentley::Bstdcxx::bpair<_Ty1, _Ty2> >::type&
        get (const Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr) noexcept
        {	// get const reference to element at _Idx in pair _Pr
        typedef const typename tuple_element<_Idx, pair<_Ty1, _Ty2> >::type&
            _Ctype;
        return (_Pair_get<_Ctype>(_Pr, integral_constant<size_t, _Idx>()));
        };

    template<class _Ty1,
        class _Ty2> inline
        constexpr const _Ty1& get(const Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr) noexcept
        {	// get const reference to element _Ty1 in pair _Pr
        return (_STD get<0>(_Pr));
        }

    template<class _Ty2,
        class _Ty1> inline
        constexpr const _Ty2& get(const Bentley::Bstdcxx::bpair<_Ty1, _Ty2>& _Pr) noexcept
        {	// get const reference to element _Ty2 in pair _Pr
        return (_STD get<1>(_Pr));
        }
}

namespace PYBIND11_NAMESPACE {
    namespace detail {
        template <typename T>
        struct type_caster<boost::optional<T>> : optional_caster<boost::optional<T>> {};

        template <typename T1, typename T2>
        class type_caster<Bentley::Bstdcxx::bpair<T1, T2>> : public tuple_caster<Bentley::Bstdcxx::bpair, T1, T2> {};   

        template <typename Key, typename Compare, typename Alloc>
        struct type_caster<Bentley::bset<Key, Compare, 32, Alloc>>
            : set_caster<Bentley::bset<Key, Compare, 32, Alloc>, Key> {};
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

template <typename T>
T ConvertItemFromPyObject(const py::handle& item) {
    if (!py::isinstance<T>(item)) {
        throw std::invalid_argument("All items in the list must be of the correct item type");
    }
    return item.cast<T>();
}

inline double ConvertItemFromPyObject(const py::handle& item) {
    if (!PyFloat_Check(item.ptr()) && !PyLong_Check(item.ptr())) {
        throw std::invalid_argument("Expected all items to be convertible to double");
    }
    return item.cast<double>();
}

template <typename T>
py::object ConvertItemToPyObject(const T& item) {
    return py::cast(item);
}

inline py::object ConvertItemToPyObject(const double& item) {
    return py::float_(item);
}

//Convert Python list to an existing C++ array
template <typename arrayType, typename itemType>
void ConvertPyListToCppArray(const py::list& pyList, arrayType& cppArray) {
    cppArray.clear();
    for (const auto& item : pyList) {
        itemType cppItem = ConvertItemFromPyObject<itemType>(item);
        cppArray.push_back(cppItem);
    }
}

// Convert Python list to a new C++ array
template <typename arrayType, typename itemType>
arrayType ConvertPyListToCppArray(const py::list& pyList) {
    arrayType cppArray;
    for (const auto& item : pyList) {
        itemType cppItem = ConvertItemFromPyObject<itemType>(item);
        cppArray.push_back(cppItem);
    }
    return cppArray;
}

// Convert C++ array to an existing Python list
template <typename arrayType, typename itemType>
void ConvertCppArrayToPyList(py::list& pyList, const arrayType& cppArray) {
    pyList.attr("clear")();
    for (const itemType& item : cppArray) {
        pyList.append(ConvertItemToPyObject(item));
    }
}

// Convert C++ array to a new Python list
template <typename arrayType, typename itemType>
py::list ConvertCppArrayToPyList(const arrayType& cppArray) {
    py::list pyList;
    for (const itemType& item : cppArray) {
        pyList.append(ConvertItemToPyObject(item));
    }
    return pyList;
}

// Macros
#define CONVERT_PYLIST_TO_CPPARRAY(pyList, cppArray, cppArrayType, cppItemType) \
    ConvertPyListToCppArray<cppArrayType, cppItemType>(pyList, cppArray);

#define CONVERT_PYLIST_TO_NEW_CPPARRAY(pyList, cppArray, cppArrayType, cppItemType) \
    cppArrayType cppArray = ConvertPyListToCppArray<cppArrayType, cppItemType>(pyList);

#define CONVERT_CPPARRAY_TO_PYLIST(pyList, cppArray, cppArrayType, cppItemType) \
    ConvertCppArrayToPyList<cppArrayType, cppItemType>(pyList, cppArray);

#define CONVERT_CPPARRAY_TO_NEW_PYLIST(pyList, cppArray, cppArrayType, cppItemType) \
    py::list pyList = ConvertCppArrayToPyList<cppArrayType, cppItemType>(cppArray);