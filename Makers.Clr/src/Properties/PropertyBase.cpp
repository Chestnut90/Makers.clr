#include "pch.h"
#include "PropertyBase.h"


#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyBase.h"

#include "../Items/ItemBase.h"
#include "../Conversions/Converter.h"


//@ ID getter
System::String^ Makers::Net::Properties::PropertyBase::ID::get()
{
	return Conversion::ConvertString(property_base_->id());
}

//@ Name getter
System::String^ Makers::Net::Properties::PropertyBase::Name::get()
{
	return Conversion::ConvertString(property_base_->name());
}

//@ TODO : how to connection 
//@ OwnerItem getter
Makers::Net::Items::ItemBase^ Makers::Net::Properties::PropertyBase::OwnerItem::get()
{
	// TODO: 
	return nullptr;
}

//@ Owner Item setter
void Makers::Net::Properties::PropertyBase::OwnerItem::set(Makers::Net::Items::ItemBase^ item)
{

}

// TODO : dll updated and connection
//@ IsOptional
bool Makers::Net::Properties::PropertyBase::IsOptional::get()
{
	return false;
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

//@ constructor
Makers::Net::Properties::PropertyBase::PropertyBase()
{
//property_base_ = new PropertyBase_();
}

//@ destructor
Makers::Net::Properties::PropertyBase::~PropertyBase()
{
delete property_base_;
}

//@ finalizer
Makers::Net::Properties::PropertyBase::!PropertyBase()
{

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
