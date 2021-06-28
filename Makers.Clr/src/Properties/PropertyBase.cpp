#include "pch.h"
#include "PropertyBase.h"


#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyBase.h"

#include "../Items/ItemBase.h"
#include "../Conversions/Converter.h"
#include "../Items/ItemFactory.h"

using Strings_ = Conversion::Strings;

#pragma region properties setter and getters

//@ ID getter
System::String^ Makers::Net::Properties::PropertyBase::ID::get()
{
	return Strings_::ToString(property_base_->id());
}

//@ Name getter
System::String^ Makers::Net::Properties::PropertyBase::Name::get()
{
	return Strings_::ToString(property_base_->name());
}

//@ OwnerItem getter
Makers::Net::Items::ItemBase^ Makers::Net::Properties::PropertyBase::OwnerItem::get()
{
	return ownerItem;
}

//@ IsOptional
bool Makers::Net::Properties::PropertyBase::IsOptional::get()
{
	return property_base_->is_optional();
}

//@ IsUsed getter
bool Makers::Net::Properties::PropertyBase::IsUsed::get()
{
	return property_base_->is_used_;
}

//@ IsUsed setter
void Makers::Net::Properties::PropertyBase::IsUsed::set(bool isUsed)
{
	property_base_->set_is_used(isUsed);
}

#pragma endregion

//@ constructor
Makers::Net::Properties::PropertyBase::PropertyBase(
	Makers::Net::Items::ItemBase^ ownerItem, 
	Makers::Properties::PropertyBase& propertyBase) :
	IXmlNodeAble()
{
	// set owner
	this->ownerItem = ownerItem;

	// set instance
	this->property_base_ = &propertyBase;
}

//@ destructor
Makers::Net::Properties::PropertyBase::~PropertyBase()
{
	delete property_base_;
}

//@ finalizer
Makers::Net::Properties::PropertyBase::!PropertyBase()
{
	// TODO : finalizer
}

//@ to data
System::Collections::Generic::Dictionary<System::String^, System::String^>^ Makers::Net::Properties::PropertyBase::ToData()
{
	auto data = gcnew System::Collections::Generic::Dictionary<System::String^, System::String^>();

	data["ID"] = ID;
	data["Name"] = Name;
	data["OwnerID"] = OwnerItem->ID;
	data["IsOptional"] = IsOptional.ToString();
	data["IsUsed"] = IsUsed.ToString();
	data["DataType"] = "/TODO";
	// TODO : data object info?

	return data;
}

Makers::Properties::PropertyBase * Makers::Net::Properties::PropertyBase::Export()
{
	return property_base_;
}

System::Xml::XmlNode ^ Makers::Net::Properties::PropertyBase::ToXml(System::Xml::XmlDocument ^document)
{
	auto xmlNode = document->CreateElement("Property");

	// set attributes
	for each (auto pair in ToData())
	{
		auto name = pair.Key;
		auto value = pair.Value;

		auto xmlAttribute = document->CreateAttribute(name);
		xmlAttribute->Value = value;
		xmlNode->Attributes->Append(xmlAttribute);

		// TODO: computables
	}

	return xmlNode;
}

void Makers::Net::Properties::PropertyBase::LoadFromXml(System::Xml::XmlNode ^node)
{
	// TODO : parsing error

	// id
	auto id = node->Attributes["ID"]->Value;
	Makers::Net::Items::ItemFactory::Instance()->IDHandle(this, id);

	// Is Used
	//..

}
