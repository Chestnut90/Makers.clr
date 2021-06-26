#include "pch.h"
#include "PropertyGroup.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyGroup.h"

#include "PropertyBase.h"
#include "../Conversions/Converter.h"

//@ Count
System::Int32^ Makers::Net::Properties::PropertyGroup::Count::get()
{
	return property_group_->Count();
}

//@ constructor
Makers::Net::Properties::PropertyGroup::PropertyGroup()
{
	property_group_ = new PropertyGroup_();
}

//@ destructor
Makers::Net::Properties::PropertyGroup::~PropertyGroup()
{
	delete property_group_;
}

//@ finalizer
Makers::Net::Properties::PropertyGroup::!PropertyGroup()
{

}

//@ [name] operator
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::operator[] (System::String^ name)
{
	std::string std_name;
	Conversion::ConvertString(name, std_name);

	auto property = (*property_group_)[std_name];
	// TODO : how to change property type
	return nullptr;
}

//@ query with id
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::QueryPropertyID(System::String^ id)
{
	std::string std_id;
	Conversion::ConvertString(id, std_id);

	auto property = property_group_->QueryPropertyID(std_id);
	// TODO: how to change property type
	return nullptr;
}

//@ query with name
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::QueryPropertyName(System::String^ name)
{
	std::string std_name;
	Conversion::ConvertString(name, std_name);

	auto property = (*property_group_)[std_name];
	// TODO: how to change proeprty type
	return nullptr;
}