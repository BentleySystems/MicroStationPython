/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\namedgroup.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/NamedGroup.h>



static const char * __doc_Bentley_DgnPlatform_NamedGroup_AddMember =R"doc(Adds a member to the NamedGroup.

Parameter ``elementID``:
    ElementId of the member to add.

Parameter ``modelRef``:
    ModelRef of the member to add.

Parameter ``memberFlags``:
    MemberFlags that apply to this member.

Returns:
    NG_Success, or one of the NamedGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetGroupsContaining =R"doc(Gets a list of ElementRefs representing NamedGroups that contain the
designated member.

Parameter ``groups``:
    The list of NamedGroups.

Parameter ``memberElementRef``:
    The member to look for.

Returns:
    The number of ElementRefs added to list.

Remark:
    s The method adds ElementRefs of the containing NamedGroups to the
    end of the list passed in.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_CountGroupsContaining =R"doc(Counts the named groups that contain the given elementRef

Parameter ``memberElementRef``:
    The member to look for.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_AnyGroupContains =R"doc(Returns true if any named group contains the given elementRef.

Parameter ``memberElementRef``:
    The member we are looking for.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_IsMemberOf =R"doc(Returns true if the given elementRef / modelRef belongs to the named
group.

Parameter ``elementRef``:
    The elementRef of the tested element.

Parameter ``modelRef``:
    The modelRef of the tested element.

Remark:
    s This method returns true only for directly contained elements.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_TraverseRelatedMembers =R"doc(Traverse elements that are related to a given element through
NamedGroup membership.

Parameter ``memberElementRef``:
    ElementRefP of element for which related members are to be
    traversed.

Parameter ``memberModelRef``:
    The ModelRef containing memberElementRef.

Parameter ``memberOf``:
    The NamedGroup that contains the member. The only use that is made
    of this argument is to pass it to the
    INamedGroupMemberMemberVisitor::VisitMember method when
    VisitMember is called for memberElementRef. It can be NULL if the
    VisitMember method of visitor is prepared for that case.

Parameter ``baseModelRef``:
    The ModelRef at the root of the traversal. Usually the root parent
    of memberModelRef.

Parameter ``visitor``:
    An instance of a class implementing the INamedGroupMemberVisitor
    interface.

Parameter ``traverseType``:
    The type of traversal. See MemberTraverseType.

Parameter ``groupLock``:
    True if groupLock should be considered to be on. This matters for
    MemberTraverseType::Manipulate and MemberTraverseType::Copy only.

Parameter ``startOperation``:
    If true, the method calls #PrepareForOperation / #DoneOperation
    appropriately. Otherwise it is assumed that the caller is
    correctly calling #PrepareForOperation / #DoneOperation.

Remark:
    s The INamedGroupMemberVisitor::VisitMember method on visitor is
    called for each graphic element that meets the traverse criteria
    established by traverseType.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_TraverseMembers =R"doc(Traverse the members of a NamedGroup

Parameter ``visitor``:
    An instance of a class implementing the INamedGroupMemberVisitor
    interface.

Parameter ``traverseType``:
    The type of traversal. See MemberTraverseType.

Parameter ``groupLock``:
    True if groupLock should be considered to be on. This matters for
    MemberTraverseType::Manipulate and MemberTraverseType::Copy only.

Parameter ``startOperation``:
    If true, the method calls #PrepareForOperation / #DoneOperation
    appropriately.

Returns:
    NG_Success, or one of the NamedGroupStatus values if there is an
    error.

Remark:
    s The INamedGroupMemberVisitor::VisitMember method on visitor is
    called for each graphic element that meets the traverse criteria
    established by traverseType.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_DeleteFromFile =R"doc(Delete this NamedGroup from the file.

Returns:
    NG_Success, or one of the NamedGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_WriteToFile =R"doc(Write this NamedGroup to the DgnFile.

Parameter ``overwriteExisting``:
    True if the caller expects there to be a NamedGroup with the same
    name in the file, and wants to overwrite that NamedGroup with this
    one.

Returns:
    NG_Success, or one of the NamedGroupStatus values if there is an
    error.

Remark:
    s When a NamedGroup is returned from a NamedGroupCollection or
    instantiated from an existing element using #Create, the
    NamedGroup remembers the source element. To copy a NamedGroup to
    another with the same members, change the name using #SetName
    (make sure the new name is unique using
    NamedGroupCollection::NameUnused or
    NamedGroupCollection::GetUniqueNameFromBase) and call WriteToFile
    with overwriteExisting false. To change the name of a NamedGroup,
    make sure the new name is unique and call WriteToFile with
    overwriteExisting set to true. When writing a newly created
    NamedGroup to the file, overwriteExisting should be false.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetContainedGroups =R"doc(Gets a list of ElementRefs representing NamedGroups contained within
this NamedGroup.

Parameter ``groups``:
    The list of NamedGroups.

Returns:
    The number of ElementRefs added to list.

Remark:
    s The method adds ElementRefs of the contained NamedGroups to the
    end of the list passed in.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetContainedGroupCount =R"doc(Gets the count of NamedGroups contained by this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_SetDefaultMemberFlags =R"doc(Sets the Default NamedGroupMemberFlags for this NamedGroup.

Parameter ``flags``:
    The new default NamedGroupMemberFlags for this NamedGroup.

Remark:
    s The default member flags are used when new members are added
    from the user interface.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetDefaultMemberFlags =R"doc(Gets the Default NamedGroupMemberFlags for this NamedGroup.

Remark:
    s The default member flags are used when new members are added
    from the user interface.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_SetFlags =R"doc(Sets the NamedGroupFlags for this NamedGroup.

Parameter ``flags``:
    The new flags for this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetFlags =R"doc(Gets the NamedGroupFlags for this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_ContainsGroups =R"doc(Returns true if this NamedGroup has any child NamedGroups.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_SetType =R"doc(Set the type of this NamedGroup.

Parameter ``type``:
    The new type for this NamedGroup.

Remark:
    s The NamedGroup type is simply a string set by an application. It
    is displayed in the User Interface, but has no effect on
    NamedGroup traversal or behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetType =R"doc(Gets the type of this NamedGroup.

Remark:
    s The NamedGroup type is simply a string set by an application. It
    is displayed in the User Interface, but has no effect on
    NamedGroup traversal or behavior.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_SetDescription =R"doc(Set the description of this NamedGroup.

Parameter ``description``:
    The new description for this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetDescription =R"doc(Gets the description of this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_SetName =R"doc(Sets the name of this NamedGroup.

Parameter ``name``:
    The new name for this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetName =R"doc(Gets the name of this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_RemoveAllMembers =R"doc(Removes all members from this NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_RemoveMember =R"doc(Removes a member from this NamedGroup.

Parameter ``index``:
    The member to remove.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetMemberCount =R"doc(Gets the member counts for this NamedGroup.

Parameter ``graphicMembers``:
    The number of graphic elements in the NamedGroup. If that
    information isn't needed, pass NULL.

Parameter ``groupMembers``:
    The number of child NamedGroups in the NamedGroup. If that
    information isn't needed, pass NULL.

Remark:
    s The counts do not include deleted elements or named groups.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetElementRef =R"doc(Gets the ElementRefP of this NamedGroup element that holds the
persistent storage of the NamedGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_FindMemberByElementRef =R"doc(Finds a NamedGroupMember from its ElementRefP.

Parameter ``index``:
    The member index. If the index is not needed, pass NULL.

Parameter ``elementRef``:
    The desired member's elementRef.

Parameter ``modelRef``:
    The desired member's modelRef.

Returns:
    The NamedGroupMember or NULL if the the NamedGroup does not
    contain a Member with that ElementRefP.

Remark:
    s The caller does not own the return NamedGroupMember, and should
    not free it.

Remark:
    s The modelRef argument is required because a particular DgnModel
    can be present more than once in the DgnAttachment hierarchy.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetMember =R"doc(Returns a NamedGroupMember by index.

Parameter ``index``:
    The member index.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_GetRootModelRef =R"doc(Gets the model that the NamedGroup came from.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_DoneOperation =R"doc(Inform DgnPlatform that the NamedGroup operation is complete.

See also:
    #PrepareForOperation)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_PrepareForOperation =R"doc(Prepare the host system for an operation that can possibly traverse
NamedGroups members.

Parameter ``rootModel``:
    The root model for the NamedGroups that may be traversed.

Parameter ``traverseType``:
    The type of traversal that will be used, which determines the
    scope of potential members.

Returns:
    NG_Success if the previous call to PrepareForOperation was matched
    by a call to #DoneOperation, otherwise NG_OperationInProgress.

Remark:
    s This method is needed to prevent the same graphics element from
    being visited twice during a NamedGroup traversal, when that
    graphics element is in more than one NamedGroup. DgnPlatform has a
    mechanism for ensuring that elements are visited only once, but it
    needs to know when to 'reset' that mechanism.

Remark:
    s If the call to NG_PrepareForOperation returns NG_Success, the
    caller must make sure that NG_DoneOperation is called when the
    NamedGroup traversal(s) are complete. If the caller fails to call
    NG_DoneOperation, future NamedGroup traversals are blocked.

Remark:
    s PrepareForOperation and DoneOperation are not necessary when
    using TraverseMembers or TraverseRelatedMembers with the
    'startOperation' argument true. These methods are used for more
    complicated operations where multiple groups are traversed.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroup_Create =R"doc(Creates a new instance of NamedGroup from the element that persists
it.

Parameter ``source``:
    ElementHandle referencing the persistent NamedGroup element.

Parameter ``rootModelRef``:
    The model containing the NamedGroup element.

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1)`:
	newGroup.

)doc";

static const char * __doc_Bentley_DgnPlatform_INamedGroupMemberVisitor_VisitMember =R"doc(The method called for each NamedGroup member that meets the traversal
criteria.

Parameter ``member``:
    The current NamedGroupMember.

Parameter ``namedGroup``:
    The NamedGroup.

Parameter ``index``:
    The index of the member within the NamedGroup.

Returns:
    A member of the MemberTraverseStatus enumeration.

Remark:
    s When this method is called as a consequence of
    NamedGroup::TraverseMembers traversal, the NamedGroup passed in is
    a NamedGroup to which member belongs. When called as a consequence
    of NamedGroup::TraverseRelatedGroups, it usually a NamedGroup to
    which member belongs, but it might be the 'memberOf' argument
    passed to TraverseRelatedGroups when member corresponds to the
    'memberElementRef' argument.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupMember_GetElementRef =R"doc(Gets the ElementRef for this NamedGroupMember.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupMember_GetElementId =R"doc(Gets the ElementId for this NamedGroupMember.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupMember_SetFlags =R"doc(Sets the member flags for this NamedGroupMember.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupMember_GetFlags =R"doc(Gets the member flags of this NamedGroupMember.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupMember_IsDirectFarReference =R"doc(Returns true if this NamedGroupMember is a Direct Far Reference.

Parameter ``rootModelRef``:
    The rootModelRef of the NamedGroup. NamedGroupMembers do not keep
    a pointer to the NamedGroup they are a member of, so this argument
    must be supplied by the caller. remarks A direct far reference is
    a reference to an element that is in a DgnAttachment of
    rootModelRef, and not in a nested DgnAttachment.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupMember_IsFarReference =R"doc(Returns true if this NamedGroupMember is a Far Reference.

Parameter ``rootModelRef``:
    The rootModelRef of the NamedGroup. NamedGroupMembers do not keep
    a pointer to the NamedGroup they are a member of, so this argument
    must be supplied by the caller. remarks A far reference is a
    reference to an element that is in a DgnAttachment or any nested
    DgnAttachment.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupCollection_GetUniqueNameFromBase =R"doc(Gets a unique name for a NamedGroup given a " base " name.

Parameter ``uniqueName``:
    The generated uniqueName.

Parameter ``baseName``:
    The base name.

Remark:
    s If the baseName is NULL, uses localized version of " Group ".

Remark:
    s If there is no NamedGroup with baseName, baseName is returned.
    Otherwise returns the next unused name in the sequence baseName-1,
    baseName-2, etc.

Returns:
    NG_Success, or one of the NamedGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupCollection_NameUnused =R"doc(Returns true if the name tested is unique within this
NamedGroupCollection.

Parameter ``name``:
    The name to test)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupCollection_FindByElementId =R"doc(Finds a NamedGroup by the ElementId of the element that stores the
NamedGroup.

Parameter ``elementID``:
    The elementID of the NamedGroup to search for.

Returns:
    The NamedGroupPtr that references the NamedGroup with the given
    name or NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedGroupCollection_FindByName =R"doc(Finds a NamedGroup by name.

Parameter ``name``:
    The name of the NamedGroup to search for.

Returns:
    The NamedGroupPtr that references the NamedGroup with the given
    name or NULL.

Remark:
    s The comparison is case-insensitive.)doc";

//=======================================================================================
// Trampoline class for INamedGroupMemberVisitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyNamedGroupMemberVisitor : INamedGroupMemberVisitor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MemberTraverseStatus VisitMember(NamedGroupMemberCP member, NamedGroupCP namedGroup, UInt32 index) override
        { PYBIND11_OVERRIDE_PURE_EXR(MemberTraverseStatus, INamedGroupMemberVisitor, VisitMember, MemberTraverseStatus::Abort, member, namedGroup, index); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_NamedGroup(py::module_& m)
    {
    //===================================================================================
    // enum NamedGroupStatus
    py::enum_< NamedGroupStatus>(m, "NamedGroupStatus", py::arithmetic())
        .value("eNG_Success", NG_Success)
        .value("eNG_ClosedGroup", NG_ClosedGroup)
        .value("eNG_FarReferenceDisallowed", NG_FarReferenceDisallowed)
        .value("eNG_DuplicateMember", NG_DuplicateMember)
        .value("eNG_BadMember", NG_BadMember)
        .value("eNG_NameTooLong", NG_NameTooLong)
        .value("eNG_NameTooShort", NG_NameTooShort)
        .value("eNG_DescriptionTooLong", NG_DescriptionTooLong)
        .value("eNG_TypeTooLong", NG_TypeTooLong)
        .value("eNG_CircularDependency", NG_CircularDependency)
        .value("eNG_CantCreateSubgroup", NG_CantCreateSubgroup)
        .value("eNG_BadArg", NG_BadArg)
        .value("eNG_NotNamedGroupElement", NG_NotNamedGroupElement)
        .value("eNG_FileReadOnly", NG_FileReadOnly)
        .value("eNG_ExistsNotOverwriting", NG_ExistsNotOverwriting)
        .value("eNG_NameNotUnique", NG_NameNotUnique)
        .value("eNG_NotFound", NG_NotFound)
        .value("eNG_NotPersistent", NG_NotPersistent)
        .value("eNG_OperationInProgress", NG_OperationInProgress)
        .value("eNG_IsFarReference", NG_IsFarReference)
        .export_values();

    //===================================================================================
    // struct NamedGroupCollection
    py::class_< NamedGroupCollection, NamedGroupCollectionPtr> c1(m, "NamedGroupCollection", py::multiple_inheritance());

    c1.def(py::init(&NamedGroupCollection::Create), "modelRef"_a);
    c1.def("FindByName", &NamedGroupCollection::FindByName, "name"_a, DOC(Bentley, DgnPlatform, NamedGroupCollection, FindByName));
    c1.def("FindByElementId", &NamedGroupCollection::FindByElementId, "elementId"_a, DOC(Bentley, DgnPlatform, NamedGroupCollection, FindByElementId));
    c1.def("NameUnused", &NamedGroupCollection::NameUnused, "name"_a, DOC(Bentley, DgnPlatform, NamedGroupCollection, NameUnused));
    c1.def("GetUniqueNameFromBase", &NamedGroupCollection::GetUniqueNameFromBase, "uniqueName"_a, "baseName"_a, DOC(Bentley, DgnPlatform, NamedGroupCollection, GetUniqueNameFromBase));
    
    c1.def_property_readonly("ModelRef", &NamedGroupCollection::GetModelRefR);    
    c1.def("GetModelRef", &NamedGroupCollection::GetModelRefR, py::return_value_policy::reference_internal);

    c1.def("__iter__", [] (NamedGroupCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct NamedGroupMemberFlags
    py::class_< NamedGroupMemberFlags> c2(m, "NamedGroupMemberFlags");

    c2.def_property("ForwardPropagate",
                    [] (NamedGroupMemberFlags const& self) { return self.m_forwardPropagate == 0 ? false : true; },
                    [] (NamedGroupMemberFlags& self, bool value) { self.m_forwardPropagate = value ? 1 : 0; });

    c2.def_property("BackwardPropagate",
                    [] (NamedGroupMemberFlags const& self) { return self.m_backwardPropagate == 0 ? false : true; },
                    [] (NamedGroupMemberFlags& self, bool value) { self.m_backwardPropagate = value ? 1 : 0; });

    c2.def_property("GroupPropagate",
                    [] (NamedGroupMemberFlags const& self) { return self.m_groupPropagate == 0 ? false : true; },
                    [] (NamedGroupMemberFlags& self, bool value) { self.m_groupPropagate = value ? 1 : 0; });

    c2.def(py::init<>());
    c2.def("__eq__", [] (NamedGroupMemberFlagsCR self, NamedGroupMemberFlagsCR other) { return self.IsEqual(other); });

    //===================================================================================
    // struct NamedGroupMember
    py::class_< NamedGroupMember, std::unique_ptr<NamedGroupMember, py::nodelete> > c3(m, "NamedGroupMember");

    c3.def("IsFarReference", &NamedGroupMember::IsFarReference, "rootModelRef"_a, DOC(Bentley, DgnPlatform, NamedGroupMember, IsFarReference));
    c3.def("IsDirectFarReference", &NamedGroupMember::IsDirectFarReference, "rootModelRef"_a, DOC(Bentley, DgnPlatform, NamedGroupMember, IsDirectFarReference));
    
    c3.def_property("Flags", &NamedGroupMember::GetFlags, &NamedGroupMember::SetFlags);
    c3.def("GetFlags", &NamedGroupMember::GetFlags, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroupMember, GetFlags));
    c3.def("SetFlags", &NamedGroupMember::SetFlags, "flags"_a, DOC(Bentley, DgnPlatform, NamedGroupMember, SetFlags));
    
    c3.def_property_readonly("ElementId", &NamedGroupMember::GetElementId);
    c3.def("GetElementId", &NamedGroupMember::GetElementId, DOC(Bentley, DgnPlatform, NamedGroupMember, GetElementId));
    
    c3.def_property_readonly("ElementRef", &NamedGroupMember::GetElementRef);
    c3.def("GetElementRef", &NamedGroupMember::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroupMember, GetElementRef));
    
    c3.def_property_readonly("ModelRef", &NamedGroupMember::GetModelRefP);
    c3.def("GetModelRef", &NamedGroupMember::GetModelRefP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("ElementPath", [] (NamedGroupMember const& self)
                             {
                             py::list outVals;
                             UInt32 numInPath = 0;
                             ElementId* ids = self.GetElementPath(&numInPath);
                             if (numInPath > 0 && nullptr != ids)
                                 {
                                 for (UInt32 i = 0; i < numInPath; i++)
                                     outVals.append(ids[i]);
                                 }
                             return outVals;
                             });
    c3.def("GetElementPath", [] (NamedGroupMember const& self)
           {
           py::list outVals;
           UInt32 numInPath = 0;
           ElementId* ids = self.GetElementPath(&numInPath);
           if (numInPath > 0 && nullptr != ids)
               {
               for (UInt32 i = 0; i < numInPath; i++)
                   outVals.append(ids[i]);
               }
           return outVals;
           });

    //===================================================================================
    // struct NamedGroupFlags
    py::class_< NamedGroupFlags> c4(m, "NamedGroupFlags");

    c4.def_property("AllowDuplicates",
                    [] (NamedGroupFlags const& self) { return (bool) self.m_allowDuplicates; },
                    [] (NamedGroupFlags& self, bool value) { self.m_allowDuplicates = value ? 1 : 0; });

    c4.def_property("ExclusiveMembers",
                    [] (NamedGroupFlags const& self) { return (bool) self.m_exclusiveMembers; },
                    [] (NamedGroupFlags& self, bool value) { self.m_exclusiveMembers = value ? 1 : 0; });

    c4.def_property("AllowFarReferences",
                    [] (NamedGroupFlags const& self) { return (bool) self.m_allowFarReferences; },
                    [] (NamedGroupFlags& self, bool value) { self.m_allowFarReferences = value ? 1 : 0; });

    c4.def_property("Closed",
                    [] (NamedGroupFlags const& self) { return (bool) self.m_closed; },
                    [] (NamedGroupFlags& self, bool value) { self.m_closed = value ? 1 : 0; });

    c4.def_property("SelectMembers",
                    [] (NamedGroupFlags const& self) { return (bool) self.m_selectMembers; },
                    [] (NamedGroupFlags& self, bool value) { self.m_selectMembers = value ? 1 : 0; });

    c4.def_property("Anonymous",
                    [] (NamedGroupFlags const& self) { return (bool) self.m_anonymous; },
                    [] (NamedGroupFlags& self, bool value) { self.m_anonymous = value ? 1 : 0; });

    c4.def(py::init<>());
    c4.def("__eq__", [] (NamedGroupFlagsCR self, NamedGroupFlagsCR other) { return self.IsEqual(other); });

    //===================================================================================
    // enum class MemberTraverseStatus
    py::enum_< MemberTraverseStatus>(m, "MemberTraverseStatus")
        .value("eContinue", MemberTraverseStatus::Continue)
        .value("eSkipElement", MemberTraverseStatus::SkipElement)
        .value("eSkipGroup", MemberTraverseStatus::SkipGroup)
        .value("eAbort", MemberTraverseStatus::Abort)
        .export_values();

    //===================================================================================
    // struct INamedGroupMemberVisitor
    py::class_< INamedGroupMemberVisitor, std::unique_ptr< INamedGroupMemberVisitor, py::nodelete>, IPyNamedGroupMemberVisitor> c5(m, "INamedGroupMemberVisitor");

    c5.def(py::init<>());
    c5.def("VisitMember", &INamedGroupMemberVisitor::VisitMember, "member"_a, "namedGroup"_a, "index"_a, DOC(Bentley, DgnPlatform, INamedGroupMemberVisitor, VisitMember));

    //===================================================================================
    // struct NamedGroup
    py::class_< NamedGroup, NamedGroupPtr> c6(m, "NamedGroup");

    if (true)
        {
        //===================================================================================
        // enum FlagValues
        py::enum_<NamedGroup::FlagValues>(c6, "FlagValues", py::arithmetic())
            .value("eNG_FLAG_GroupLock", NamedGroup::NG_FLAG_GroupLock)
            .value("eNG_FLAG_Never", NamedGroup::NG_FLAG_Never)
            .value("eNG_FLAG_Always", NamedGroup::NG_FLAG_Always)
            .export_values();
        }
    c6.def_static("Create", [] (ElementHandleCR source, DgnModelRefP rootModelRef)
                  {
                  NamedGroupPtr newGroup;
                  auto retVal = NamedGroup::Create(newGroup, source, rootModelRef);
                  return py::make_tuple(retVal, newGroup);
                  }, "source"_a, "rootModelRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, Create));

    c6.def_static("Create", [] (WCharCP name, WCharCP description, NamedGroupFlags flags, DgnModelRefP rootModelRef)
                  {
                  NamedGroupPtr newGroup;
                  auto retVal = NamedGroup::Create(newGroup, name, description, flags, rootModelRef);
                  return py::make_tuple(retVal, newGroup);
                  }, "name"_a, "description"_a, "flags"_a, "rootModelRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, Create));

    c6.def_static("PrepareForOperation", &NamedGroup::PrepareForOperation, "rootModelRef"_a, "traverseType"_a, DOC(Bentley, DgnPlatform, NamedGroup, PrepareForOperation));
    c6.def_static("DoneOperation", &NamedGroup::DoneOperation, DOC(Bentley, DgnPlatform, NamedGroup, DoneOperation));
    
    c6.def_property_readonly("RootModelRef", &NamedGroup::GetRootModelRef);
    c6.def("GetRootModelRef", &NamedGroup::GetRootModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetRootModelRef));
    
    c6.def("GetMember", &NamedGroup::GetMember, "index"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetMember));
    
    c6.def("FindMemberByElementRef", [] (NamedGroupCR self, ElementRefP elementRef, DgnModelRefP modelRef)
           {
           UInt32 index = 0;
           auto retVal = self.FindMemberByElementRef(&index, elementRef, modelRef);
           return py::make_tuple(std::unique_ptr< NamedGroupMember, py::nodelete>(retVal), index);
           }, "elementRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, FindMemberByElementRef));

    c6.def_property_readonly("ElementRef", &NamedGroup::GetElementRef);
    c6.def("GetElementRef", &NamedGroup::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetElementRef));

    c6.def("GetMemberCount", [] (NamedGroupCR self)
           {
           UInt32 graphicsMembers = 0;
           UInt32 groupMembers = 0;
           self.GetMemberCount(&graphicsMembers, &groupMembers);
           return py::make_tuple(graphicsMembers, groupMembers);
           }, DOC(Bentley, DgnPlatform, NamedGroup, GetMemberCount));

    c6.def("RemoveMember", &NamedGroup::RemoveMember, "index"_a, DOC(Bentley, DgnPlatform, NamedGroup, RemoveMember));
    c6.def("RemoveAllMembers", &NamedGroup::RemoveAllMembers, DOC(Bentley, DgnPlatform, NamedGroup, RemoveAllMembers));    
    
    c6.def_property("Name", &NamedGroup::GetName, py::overload_cast<WCharCP>(&NamedGroup::SetName));
    c6.def("GetName", &NamedGroup::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetName));
    c6.def("SetName", py::overload_cast<WCharCP>(&NamedGroup::SetName), "name"_a, DOC(Bentley, DgnPlatform, NamedGroup, SetName));
    
    c6.def_property("Description", &NamedGroup::GetDescription, &NamedGroup::SetDescription);
    c6.def("GetDescription", &NamedGroup::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetDescription));
    c6.def("SetDescription", &NamedGroup::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, NamedGroup, SetDescription));
    
    c6.def_property("Type", &NamedGroup::GetType, &NamedGroup::SetType);    
    c6.def("GetType", &NamedGroup::GetType, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetType));
    c6.def("SetType", &NamedGroup::SetType, "type"_a, DOC(Bentley, DgnPlatform, NamedGroup, SetType));
    
    c6.def("ContainsGroups", &NamedGroup::ContainsGroups, DOC(Bentley, DgnPlatform, NamedGroup, ContainsGroups));    
    
    c6.def_property("Flags", &NamedGroup::GetFlags, &NamedGroup::SetFlags);
    c6.def("GetFlags", &NamedGroup::GetFlags, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetFlags));
    c6.def("SetFlags", &NamedGroup::SetFlags, "flags"_a, DOC(Bentley, DgnPlatform, NamedGroup, SetFlags));
    
    c6.def_property("DefaultMemberFlags", &NamedGroup::GetDefaultMemberFlags, &NamedGroup::SetDefaultMemberFlags);
    c6.def("GetDefaultMemberFlags", &NamedGroup::GetDefaultMemberFlags, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedGroup, GetDefaultMemberFlags));
    c6.def("SetDefaultMemberFlags", &NamedGroup::SetDefaultMemberFlags, "flags"_a, DOC(Bentley, DgnPlatform, NamedGroup, SetDefaultMemberFlags));
    
    c6.def_property_readonly("ContainedGroupCount", &NamedGroup::GetContainedGroupCount);
    c6.def("GetContainedGroupCount", &NamedGroup::GetContainedGroupCount, DOC(Bentley, DgnPlatform, NamedGroup, GetContainedGroupCount));
    
    c6.def("GetContainedGroups", &NamedGroup::GetContainedGroups, "groups"_a, DOC(Bentley, DgnPlatform, NamedGroup, GetContainedGroups));
    c6.def("WriteToFile", &NamedGroup::WriteToFile, "overwriteExisting"_a, DOC(Bentley, DgnPlatform, NamedGroup, WriteToFile));
    c6.def("DeleteFromFile", &NamedGroup::DeleteFromFile, DOC(Bentley, DgnPlatform, NamedGroup, DeleteFromFile));

    c6.def("TraverseMembers", &NamedGroup::TraverseMembers, "visitor"_a, "traverseType"_a, "groupLock"_a, "startOperation"_a, DOC(Bentley, DgnPlatform, NamedGroup, TraverseMembers));

    c6.def_static("TraverseRelatedMembers", &NamedGroup::TraverseRelatedMembers,
                  "memberElementRef"_a, "memberModelRef"_a, "memberOf"_a, "baseModelRef"_a, "visitor"_a, "traverseType"_a, "groupLock"_a, "startOperation"_a, DOC(Bentley, DgnPlatform, NamedGroup, TraverseRelatedMembers));
    c6.def("IsMemberOf", py::overload_cast<ElementRefP, DgnModelRefP>(&NamedGroup::IsMemberOf, py::const_), "elementRef"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, IsMemberOf));
    c6.def_static("AnyGroupContains", &NamedGroup::AnyGroupContains, "memberElementRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, AnyGroupContains));
    c6.def_static("CountGroupsContaining", &NamedGroup::CountGroupsContaining, "memberElementRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, CountGroupsContaining));
    c6.def_static("GetGroupsContaining", &NamedGroup::GetGroupsContaining, "groups"_a, "memberElementRef"_a, DOC(Bentley, DgnPlatform, NamedGroup, GetGroupsContaining));
    c6.def("AddMember", py::overload_cast<ElementId, DgnModelRefP, NamedGroupMemberFlagsCR>(&NamedGroup::AddMember), "elementId"_a, "modelRef"_a, "memberFlags"_a, DOC(Bentley, DgnPlatform, NamedGroup, AddMember));
    }