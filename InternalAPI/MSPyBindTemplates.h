/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\MSPyBindTemplates.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once

template <typename T>
struct TypeWrapper
{
public:
    T value;
    TypeWrapper()
    {
    }
    TypeWrapper(T val)
    {
        value = val;
    }
};

template <typename T>
py::class_<TypeWrapper<T>> bind_TypeWrapper(py::handle scope, std::string const& name)
{
    py::class_<TypeWrapper<T>> cl(scope, name.c_str());

    cl.def(py::init<>());
    cl.def(py::init<T>());
    cl.def_readwrite("value", &TypeWrapper<T>::value);

    return cl;
};

typedef TypeWrapper<int> IntWrapper;
typedef TypeWrapper<double> DoubleWrapper;
typedef TypeWrapper<bool> BoolWrapper;
typedef TypeWrapper<MSElementDescrP> MSElementDescrReceiver;
typedef TypeWrapper<DgnModelStatus> DgnModelStatusWrapper;
typedef TypeWrapper<ParameterStatus> ParameterStatusWrapper;

// template<typename T> struct ValueSizeSize
template <typename ValueType, typename holder_type = std::unique_ptr< ValueSizeSize<ValueType> >, typename... Args>
py::class_<ValueSizeSize<ValueType>, holder_type> bind_ValueSizeSize(py::handle scope, std::string const& name, Args &&...args)
    {
    using Container = ValueSizeSize<ValueType>;
    using Class_ = py::class_<Container, holder_type>;

    auto* vtype_info = py::detail::get_type_info(typeid(ValueType));
    bool local = !vtype_info || vtype_info->module_local;

    Class_ cl(scope, name.c_str(), py::module_local(local), std::forward<Args>(args)...);

    cl.def(py::init<>());
    cl.def(py::init<ValueType const&, size_t, size_t>(), "value"_a, "tagA"_a, "tagB"_a);

    cl.def("GetTagA", &Container::GetTagA);
    cl.def("GetTagB", &Container::GetTagB);
    cl.def("GetTag", &Container::GetTag, "tagA"_a);
    cl.def("SetTagA", &Container::SetTagA, "tag"_a);
    cl.def("SetTagB", &Container::SetTagB, "tag"_a);

    cl.def("Get", &Container::Get);
    cl.def("GetCR", &Container::GetCR, py::keep_alive<1, 0>());
    cl.def("Set", &Container::Set, "value"_a);
    cl.def("SwapTags", &Container::SwapTags);

    return cl;
    }

// template<typename T> struct OrderedValueSizeSize
template <typename ValueType, typename holder_type = std::unique_ptr< OrderedValueSizeSize<ValueType> >, typename... Args>
py::class_<OrderedValueSizeSize<ValueType>, holder_type> bind_OrderedValueSizeSize(py::handle scope, std::string const& name, Args &&...args)
    {
    using Container = OrderedValueSizeSize<ValueType>;
    using Class_ = py::class_<Container, holder_type, ValueSizeSize<ValueType>>;

    auto* vtype_info = py::detail::get_type_info(typeid(ValueType));
    bool local = !vtype_info || vtype_info->module_local;

    Class_ cl(scope, name.c_str(), py::module_local(local), std::forward<Args>(args)...);

    cl.def(py::init<ValueType const&, ptrdiff_t, ptrdiff_t>(), "value"_a, "tagA"_a, "tagB"_a);

    return cl;
    }

// template<typename T> struct ValidatedValue
template <typename ValueType, typename holder_type = std::unique_ptr< ValidatedValue<ValueType> >, typename... Args>
py::class_<ValidatedValue<ValueType>, holder_type> bind_ValidatedValue(py::handle scope, std::string const& name, Args &&...args)
    {
    using Container = ValidatedValue<ValueType>;
    using Class_ = py::class_<Container, holder_type>;

    auto* vtype_info = py::detail::get_type_info(typeid(ValueType));
    bool local = !vtype_info || vtype_info->module_local;

    Class_ cl(scope, name.c_str(), py::module_local(local), std::forward<Args>(args)...);

    cl.def(py::init<>());
    cl.def(py::init<ValueType const&>(), "value"_a);
    cl.def(py::init<ValueType const&, bool>(), "value"_a, "isValid"_a);
    cl.def("Value", py::overload_cast<>(&Container::Value), py::return_value_policy::reference, py::keep_alive<1, 0>());
    cl.def("IsValid", py::overload_cast<>(&Container::IsValid, py::const_));
    cl.def("IsValid", py::overload_cast<ValueType&>(&Container::IsValid, py::const_), "value"_a);
    cl.def("SetIsValid", &Container::SetIsValid, "value"_a);

    return cl;
    }

// template<typename T> struct BlockedVector
template <typename ValueType, typename holder_type = std::unique_ptr< BlockedVector<ValueType> >, typename... Args>
py::class_<BlockedVector<ValueType>, holder_type> bind_BlockedVector(py::handle scope, std::string const& name, Args &&...args)
    {
    using Container = BlockedVector<ValueType>;
    using BaseType = bvector<ValueType>;
    using Class_ = py::class_<Container, holder_type, BaseType>;

    auto* vtype_info = py::detail::get_type_info(typeid(ValueType));
    bool local = !vtype_info || vtype_info->module_local;

    Class_ cl(scope, name.c_str(), py::module_local(local), std::forward<Args>(args)...);

    cl.def(py::init<>());
    cl.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool>(),
           "numPerStruct"_a, "structsPerRow"_a = 0, "tag"_a = 0, "indexFamily"_a = 0, "indexBy"_a = 0, "active"_a = false);

    cl.def_property_readonly("NumPerStruct", &Container::NumPerStruct);
    cl.def_property("StructsPerRow", &Container::StructsPerRow, &Container::SetStructsPerRow);
    cl.def_property_readonly("Tag", &Container::Tag);
    cl.def_property_readonly("IndexFamily", &Container::IndexFamily);
    cl.def_property_readonly("IndexedBy", &Container::IndexedBy);
    cl.def("SetTags", &Container::SetTags, "numPeStruct"_a, "structsPerRow"_a, "tag"_a, "IndexFamily"_a, "IndexedBy"_a, "active"_a);
    cl.def_property("Active", &Container::Active, &Container::SetActive);
    cl.def("CopyVectorFrom", &Container::CopyVectorFrom, "source"_a);

    cl.def("ClearAndAppendBlock",
           py::overload_cast<Container&, uint32_t, uint32_t, uint32_t>(&Container::ClearAndAppendBlock),
           "source"_a, "i0"_a, "numWrap"_a, "n"_a);

    cl.def("ClearAndAppendBlock",
           py::overload_cast<ValueType const*, size_t, uint32_t, uint32_t, uint32_t>(&Container::ClearAndAppendBlock),
           "source"_a, "sourceSize"_a, "i0"_a, "numWrap"_a, "n"_a);

    cl.def("ClearAndAppend", 
           py::overload_cast<BaseType const&>(&Container::ClearAndAppend), 
           "source"_a);

    cl.def("Append", py::overload_cast<ValueType const*, size_t>(&Container::Append), "pBuffer"_a, "count"_a);
    cl.def("Append", py::overload_cast<Container const&>(&Container::Append), "source"_a);
    cl.def("Append", py::overload_cast<ValueType const&>(&Container::Append), "source"_a);

    cl.def("AppendAndReturnIndex", &Container::AppendAndReturnIndex, "source"_a);

    cl.def("NumCompleteRows", &Container::NumCompleteRows);
    cl.def("GetPtr", &Container::GetPtr, py::return_value_policy::reference);
    cl.def("GetCP", &Container::GetCP, py::return_value_policy::reference);
    cl.def("ReverseInRange", &Container::ReverseInRange, "iFirst"_a, "iLast"_a);
    cl.def("CopyData", &Container::CopyData, "fromIndex"_a, "toIndex"_a);
    cl.def("Trim", &Container::Trim, "index0"_a, "count"_a);

    cl.def("TryGet", [] (Container const& c, size_t index, ValueType const& defaultValue)
           {
           ValueType value {};
           bool bOk = c.TryGetAt(index, defaultValue, value);
           return std::make_pair(bOk, value);
           }, "index"_a, "defaultValue"_a);

    return cl;
    }

