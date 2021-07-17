#include "pch.h"
#include "ItemBase.h"

// pures
#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemBase.h"

// refs
#include "../Properties/PropertyGroup.h"

#include "ItemFactory.h"
#include "../Documents/Document.h"

#include "../Conversions/Converter.h"

using Strings_ = Conversion::Strings;
#pragma region properties

//@ ID getter
System::String^ Makers::Net::Items::ItemBase::ID::get()
{
	return Strings_::ToString(item_base_->id());
}

//@ Item Name getter
System::String^ Makers::Net::Items::ItemBase::ItemName::get()
{
	return Strings_::ToString(item_base_->item_name());
}

//@ Custom Name getter
System::String^ Makers::Net::Items::ItemBase::CustomName::get()
{
	return Strings_::ToString(item_base_->custom_name());;
}

//@ Custom Name setter
void Makers::Net::Items::ItemBase::CustomName::set(System::String^ customName)
{
	std::string std_custom_name = Strings_::ToString(customName);
	item_base_->set_custom_name(std_custom_name);
}

//@ Last Computed Time
System::Int64^ Makers::Net::Items::ItemBase::LastComputedTime::get()
{
	return item_base_->last_computed_time();
}

//@ Input Properties getter
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::InputProperties::get()
{
	return gcnew Makers::Net::Properties::PropertyGroup(item_base_->input_properties());
}

//@ Static Properties getter
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::StaticProperties::get()
{
	return gcnew Makers::Net::Properties::PropertyGroup(item_base_->static_properties());
}

//@ Output Properties
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::OutputProperties::get()
{
	return gcnew Makers::Net::Properties::PropertyGroup(item_base_->output_properties());
}

//@ Document
Makers::Net::Documents::Document^ Makers::Net::Items::ItemBase::Document::get()
{
	return gcnew Makers::Net::Documents::Document(item_base_->document());
}

#pragma endregion

//@ internal constructor
//@ access from item factory
Makers::Net::Items::ItemBase::ItemBase(Makers::Items::ItemBase* _item_base) 
{
	item_base_ = _item_base;
}

//@ destructor
Makers::Net::Items::ItemBase::~ItemBase() 
{
	// TODO delete using item factory
	//delete item_base_;
}

//@ finalizer
Makers::Net::Items::ItemBase::!ItemBase() 
{
	// TODO :
}

//@ To data
System::Collections::Generic::Dictionary<System::String^, System::String^>^ Makers::Net::Items::ItemBase::ToData()
{
	auto data = gcnew System::Collections::Generic::Dictionary<System::String^, System::String^>();

	data->Add("ID", ID);
	data->Add("ItemName", ItemName);
	data->Add("CustomName", CustomName);
	return data;
}

//@ internal function
//@ export pure object
Makers::Items::ItemBase* Makers::Net::Items::ItemBase::Export()
{
	return item_base_;
}

//@ load from xml
//@ xml node as item base
void Makers::Net::Items::ItemBase::LoadFromXml(System::Xml::XmlNode^ xmlNode)
{
	if (!xmlNode->Name->Equals("Item")) { return; }

	// set id
	auto id = xmlNode->Attributes["ID"]->Value;
	Makers::Net::Items::ItemFactory::Instance()->IDHandle(this, id);

	// set name -> nothing
	// set custom name
	CustomName = xmlNode->Attributes["CustomName"]->Value;

	// set data properties
	InputProperties->LoadFromXml(xmlNode->SelectSingleNode("InputProperties"));
	StaticProperties->LoadFromXml(xmlNode->SelectSingleNode("StaticProperties"));
	OutputProperties->LoadFromXml(xmlNode->SelectSingleNode("OutputProperties"));
}

//@ to xml node
//@ xml document as root
System::Xml::XmlNode ^ Makers::Net::Items::ItemBase::ToXml(System::Xml::XmlDocument^ xmlDocument)
{
	auto xmlNode = xmlDocument->CreateElement("Item");

	// set attribute with item data
	for each (auto pair in ToData())
	{
		auto xmlAttribute = xmlDocument->CreateAttribute(pair.Key);	// xml attribute name with data key
		xmlAttribute->Value = pair.Value;	// xml attribute value with data value
		xmlNode->Attributes->Append(xmlAttribute);
	}

	// set data properties
	xmlNode->AppendChild(_PropertiesToXml(xmlDocument, InputProperties, "InputProperties"));
	xmlNode->AppendChild(_PropertiesToXml(xmlDocument, StaticProperties, "StaticProperties"));
	xmlNode->AppendChild(_PropertiesToXml(xmlDocument, OutputProperties, "OutputProperties"));

	return xmlNode;
}

//@ TODO : to make it automatically
//@ properties to xml node
//@ xml document as root
//@ name as string
System::Xml::XmlNode ^ Makers::Net::Items::ItemBase::_PropertiesToXml(
	System::Xml::XmlDocument^ xmlDocument, 
	Makers::Net::Properties::PropertyGroup^ propertyGroup,
	System::String^ name)
{
	// properties node
	auto xmlNode = xmlDocument->CreateElement(name);

	// set attribute as count
	auto xmlAttributeCount = xmlDocument->CreateAttribute("Count");
	xmlAttributeCount->Value = (gcnew System::Int32(propertyGroup->Count))->ToString();
	xmlNode->Attributes->Append(xmlAttributeCount);

	// append property group node
	xmlNode->AppendChild(propertyGroup->ToXml(xmlDocument));

	return xmlNode;
}

