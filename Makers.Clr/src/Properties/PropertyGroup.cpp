#include "pch.h"
#include "PropertyGroup.h"

// pures
#include <algorithm>
#include <map>
#include <typeinfo>

#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyGroup.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyBase.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/InputProperty.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/StaticProperty.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/OutputProperty.h"

// refs
#include "PropertyBase.h"
#include "InputProperty.h"
#include "StaticProperty.h"
#include "OutputProperty.h"

// helpers
#include "../Conversions/Converter.h"
#include "../Conversions/Utils.h"

using Strings_ = Conversion::Strings;

//@ count getter
System::Int32^ Makers::Net::Properties::PropertyGroup::Count::get()
{
	return property_group_->Count();
}

//@ internal constructor
//@ created by item base
Makers::Net::Properties::PropertyGroup::PropertyGroup(
	Makers::Net::Items::ItemBase^ ownerItem,
	Makers::Properties::PropertyGroup& _property_group)
{
	this->ownerItem = ownerItem;
	property_group_ = &_property_group;
}

//@ internal destructor
//@ destroy
Makers::Net::Properties::PropertyGroup::~PropertyGroup()
{
	// not release memory -> item base release it
	// delete property_group_;
	// delete ownerItem;
}

//@ finalizer
Makers::Net::Properties::PropertyGroup::!PropertyGroup()
{

}

//Makers::Net::Properties::PropertyBase ^ Makers::Net::Properties::PropertyGroup::operator[](System::String ^ name)
//{
//	std::string std_name = Strings_::ToString(name);
//	auto property_base = (*property_group_)[std_name];
//
//	return Cast(&property_base);
//}

Makers::Net::Properties::PropertyBase ^ Makers::Net::Properties::PropertyGroup::QueryPropertyName(System::String ^ name)
{
	std::string std_name = Strings_::ToString(name);
	auto property_base = property_group_->QueryPropertyName(std_name);
	return Cast(property_base);
}

//@ query with id
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::QueryPropertyID(System::String^ id)
{
	std::string std_id;
	Conversion::ConvertString(id, std_id);
	auto property = property_group_->QueryPropertyID(std_id);

	return Cast(property);
}

Makers::Net::Properties::PropertyBase ^ Makers::Net::Properties::PropertyGroup::Cast(Makers::Properties::PropertyBase* _property_base)
{
	auto input_property = dynamic_cast<Makers::Properties::InputProperty*>(_property_base);
	if (input_property != nullptr)
	{
		return gcnew InputProperty(ownerItem, *input_property);
	}

	auto static_property = dynamic_cast<Makers::Properties::StaticProperty*>(_property_base);
	if (static_property != nullptr)
	{
		return gcnew StaticProperty(ownerItem, *static_property);
	}

	auto output_property = dynamic_cast<Makers::Properties::OutputProperty*>(_property_base);
	if (output_property != nullptr)
	{
		return gcnew OutputProperty(ownerItem, *output_property);
	}

	return nullptr;
}

System::Collections::Generic::List<Makers::Net::Properties::PropertyBase^>^ Makers::Net::Properties::PropertyGroup::ToList()
{
	auto list = gcnew System::Collections::Generic::List<Makers::Net::Properties::PropertyBase^>();

	for (auto it = property_group_->Begin(); it != property_group_->End(); ++it)
	{
		auto property = it->second;
		list->Add(Cast(property));
	}

	return list;
}
