#include "pch.h"
#include "InputProperty.h"


// pures
//@ To casting
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/InputProperty.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/OutputProperty.h"

// refs
#include "../Properties/OutputProperty.h"
#include "../Items/ItemBase.h"	// ref itembase

//@ connected property getter
Makers::Net::Properties::PropertyBase^ Makers::Net::Properties::InputProperty::ConnectedProperty::get()
{
	auto input_property = dynamic_cast<Makers::Properties::InputProperty*>(property_base_);
	if (input_property->connected_property_ == nullptr) return nullptr;

	auto output_property = dynamic_cast<Makers::Properties::OutputProperty*>(input_property->connected_property());
	return gcnew Makers::Net::Properties::OutputProperty(output_property);
}

//@ connected property setter
void Makers::Net::Properties::InputProperty::ConnectedProperty::set(Makers::Net::Properties::PropertyBase^ connectedProperty)
{
	auto this_property = dynamic_cast<Makers::Properties::InputProperty*>(property_base_);
	this_property->connected_property_ = connectedProperty == nullptr ? nullptr : connectedProperty->Export();
}

Makers::Net::Properties::InputProperty::InputProperty(Makers::Properties::InputProperty* inputProperty) :
PropertyBase(inputProperty)
{

}

Makers::Net::Properties::InputProperty::~InputProperty()
{

}

Makers::Net::Properties::InputProperty::!InputProperty()
{

}

System::Collections::Generic::Dictionary<System::String^, System::String^>^ Makers::Net::Properties::InputProperty::ToData()
{
	auto data = PropertyBase::ToData();

	// add connected property infos
	data["ConnectedPropertyID"] = ConnectedProperty == nullptr ? "" : ConnectedProperty->ID;
	data["ConnectedPropertyOwnerID"] = ConnectedProperty == nullptr ? "" : ConnectedProperty->OwnerItem->ID;

	return data;
}

System::Xml::XmlNode ^ Makers::Net::Properties::InputProperty::ToXml(System::Xml::XmlDocument^ xmlDocument)
{
	auto xmlNode = PropertyBase::ToXml(xmlDocument);
	//auto xmlNode = xmlDocument->CreateElement("Property");
	for each (auto pair in ToData())
	{
		auto xmlAttribute = xmlDocument->CreateAttribute(pair.Key);
		xmlAttribute->Value = pair.Value;
		xmlNode->Attributes->Append(xmlAttribute);
	}
	return xmlNode;
}

void Makers::Net::Properties::InputProperty::LoadFromXml(System::Xml::XmlNode^ xmlNode)
{
	PropertyBase::LoadFromXml(xmlNode);
	// TODO : connection => 
	return;
	auto connectedPropertyID = xmlNode->Attributes["ConnectedPropertyID"]->Value;
	auto connectedPropertyOwnerID = xmlNode->Attributes["ConnectedPropertyOwnerID"]->Value;

	if (connectedPropertyID->Equals(System::String::Empty)) { return; }
}

