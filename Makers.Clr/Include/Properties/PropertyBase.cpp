#include "pch.h"
#include "PropertyBase.h"

// pures
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyBase.h"

// refs
#include "../Items/ItemBase.h"
#include "../Conversions/Converter.h"
#include "../Items/ItemFactory.h"
#include "../Computables/ComputableConverter.h"
#include "../Computables/Computable.h"

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
	return gcnew Makers::Net::Items::ItemBase(property_base_->owner_item());
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

//@ data object
Makers::Net::Computables::Computable^ Makers::Net::Properties::PropertyBase::DataObject::get()
{
	return Computables::ComputableConverter::Cast(property_base_->data_object());
}


#pragma endregion

//@ constructor
Makers::Net::Properties::PropertyBase::PropertyBase(Makers::Properties::PropertyBase* propertyBase) 
	//: IXmlNodeAble()
{
	// set instance
	this->property_base_ = propertyBase;
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

	return data;
}

Makers::Properties::PropertyBase * Makers::Net::Properties::PropertyBase::Export()
{
	return property_base_;
}

System::Xml::XmlNode ^ Makers::Net::Properties::PropertyBase::ToXml(System::Xml::XmlDocument^ xmlDocument)
{
	auto xmlNode = xmlDocument->CreateElement("Property");

	// set attributes
	for each (auto pair in ToData())
	{
		auto name = pair.Key;
		auto value = pair.Value;

		auto xmlAttribute = xmlDocument->CreateAttribute(name);
		xmlAttribute->Value = value;
		xmlNode->Attributes->Append(xmlAttribute);
	}

	// add computable as child
	xmlNode->AppendChild(DataObject->ToXml(xmlDocument));
	
	return xmlNode;
}

void Makers::Net::Properties::PropertyBase::LoadFromXml(System::Xml::XmlNode^ xmlNode)
{
	// TODO : error
	if (xmlNode == nullptr) { throw std::exception("Erorr in property node"); }
	if (!xmlNode->Name->Equals("Property")) { return; }

	// set id
	auto id = xmlNode->Attributes["ID"]->Value;
	Makers::Net::Items::ItemFactory::Instance()->IDHandle(this, id);

	// set name -> do nothing, default value
	// set owner item -> do nothing, automatically mapped
	// set is optional -> do nothing, default value
	// set is used
	bool isUsed;
	bool try_is_used = System::Boolean::TryParse(xmlNode->Attributes["IsUsed"]->Value, isUsed);
	IsUsed = try_is_used ? isUsed : true;	// default to true
	
	// computable
	auto xmlComputableNode = xmlNode->SelectSingleNode("Computable");
	DataObject->LoadFromXml(xmlComputableNode);
}
