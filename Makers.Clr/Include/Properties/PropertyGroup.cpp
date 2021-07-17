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

#include "../Items/ItemBase.h"

#include "PropertyBase.h"
#include "InputProperty.h"
#include "StaticProperty.h"
#include "OutputProperty.h"
#include "PropertyException.h"

// helpers
#include "../Conversions/Converter.h"
#include "../Conversions/Utils.h"

using Strings_ = Conversion::Strings;

//@ count getter
int Makers::Net::Properties::PropertyGroup::Count::get()
{
	return property_group_->Count();
}

//@ OnwerItem getter
Makers::Net::Items::ItemBase^ Makers::Net::Properties::PropertyGroup::OwnerItem::get()
{
	auto owner_item = property_group_->owner_item();
	if (owner_item == nullptr) return nullptr;

	return gcnew Makers::Net::Items::ItemBase(owner_item);
}

//@ internal constructor
//@ created by item base
Makers::Net::Properties::PropertyGroup::PropertyGroup(Makers::Properties::PropertyGroup* _property_group) 
	//:IXmlNodeAble()
{
	property_group_ = _property_group;
}

//@ internal destructor
//@ destroy
Makers::Net::Properties::PropertyGroup::~PropertyGroup()
{
	// * property_group_ memory released by item base
	// delete property_group_;

	// * just pointer
	// delete ownerItem;
}

//@ finalizer
Makers::Net::Properties::PropertyGroup::!PropertyGroup()
{

}

//@ Query property with name
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::QueryPropertyName(System::String ^ name)
{
	std::string std_name = Strings_::ToString(name);
	auto property_base = property_group_->QueryPropertyName(std_name);
	return _Cast(property_base);
}

//@ Query property with id
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::QueryPropertyID(System::String^ id)
{
	std::string std_id;
	Conversion::ConvertString(id, std_id);
	auto property = property_group_->QueryPropertyID(std_id);
	return _Cast(property);
}

//@ Cast property base to each inherited type
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::PropertyGroup::_Cast(
	Makers::Properties::PropertyBase* _property_base)
{
	auto input_property = dynamic_cast<Makers::Properties::InputProperty*>(_property_base);
	if (input_property != nullptr)
	{
		return gcnew InputProperty(input_property);
	}

	auto static_property = dynamic_cast<Makers::Properties::StaticProperty*>(_property_base);
	if (static_property != nullptr)
	{
		return gcnew StaticProperty(static_property);
	}

	auto output_property = dynamic_cast<Makers::Properties::OutputProperty*>(_property_base);
	if (output_property != nullptr)
	{
		return gcnew OutputProperty(output_property);
	}

	return nullptr;
}

//@ To List
System::Collections::Generic::List<Makers::Net::Properties::PropertyBase^>^ Makers::Net::Properties::PropertyGroup::ToList()
{
	auto list = gcnew System::Collections::Generic::List<Makers::Net::Properties::PropertyBase^>();

	for (auto it = property_group_->Begin(); it != property_group_->End(); ++it)
	{
		auto property = *it;
		list->Add(_Cast(property));
	}

	return list;
}

#pragma region xml, implement IXmlNodeAble

//@ from xml node
//@ xml node as proeprty group
void Makers::Net::Properties::PropertyGroup::LoadFromXml(System::Xml::XmlNode^ xmlNode)
{
	System::String^ error = "Property Group parsing error in LoadFromXml\n";
	if (xmlNode == nullptr) 
	{
		error += "Nullable in property group";
		throw gcnew PropertyException(error);
	}

	auto xmlPropertyGroupNode = xmlNode->SelectSingleNode("PropertyGroup");
	if (xmlPropertyGroupNode == nullptr)
	{ 
		error += "Cannot found PropertyGroup node in data.";
		throw gcnew PropertyException(error);
	}

	auto xmlPropertyNodes = xmlPropertyGroupNode->SelectNodes("Property");
	if (xmlPropertyNodes->Count != Count)
	{
		error += "Differenct count of properties.";
		throw gcnew PropertyException(error);
	}
	// TODO : to make it efficiently
	int i = 0;
	for each (auto property in ToList())
	{
		property->LoadFromXml(xmlPropertyNodes->Item(i));
		++i;
	}
}

//@ to xml
//@ xml document as root
System::Xml::XmlNode ^ Makers::Net::Properties::PropertyGroup::ToXml(System::Xml::XmlDocument^ xmlDocument)
{
	auto xmlNode = xmlDocument->CreateElement("PropertyGroup");

	for each (auto property in ToList())
	{
		xmlNode->AppendChild(property->ToXml(xmlDocument));
	}

	return xmlNode;
}

#pragma endregion