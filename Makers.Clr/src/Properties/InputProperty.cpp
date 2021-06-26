#include "pch.h"
#include "InputProperty.h"


//@ To casting
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/InputProperty.h"


Makers::Net::Properties::InputProperty::InputProperty() : 
PropertyBase()
{

}

Makers::Net::Properties::InputProperty::~InputProperty()
{

}

Makers::Net::Properties::InputProperty::!InputProperty()
{

}

System::Collections::Generic::Dictionary<System::String^, System::String^>^ Makers::Net::Properties::InputProperty::ToData() override
{
	auto data = PropertyBase::ToData();

	// add connected property infos
	data["ConnectedPropertyID"] = ConnectedProperty == nullptr ? "" : ConnectedProperty->ID;
	data["ConnectedPropertyOwnerID"] = ConnectedProperty == nullptr ? "" : ConnectedProperty->OwnerItem->ID;

	return data;
}