#include "pch.h"
#include "InputProperty.h"


// pures
//@ To casting
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/InputProperty.h"

// refs
#include "../Items/ItemBase.h"	// ref itembase

Makers::Net::Properties::InputProperty::InputProperty(
	Makers::Net::Items::ItemBase^ ownerItem,
	Makers::Properties::InputProperty& inputProperty) :
PropertyBase(ownerItem, inputProperty)
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

