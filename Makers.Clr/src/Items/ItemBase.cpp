#include "pch.h"
#include "ItemBase.h"


#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemBase.h"

// props
#include "../Properties/PropertyGroup.h"

#include "../Conversions/Converter.h"

//@ ID getter
System::String^ Makers::Net::Items::ItemBase::ID::get()
{
	return Conversion::ConvertString(item_base_->id());
}

//@ Item Name getter
System::String^ Makers::Net::Items::ItemBase::Name::get()
{
	return Conversion::ConvertString(item_base_->item_name());
}

//@ Custom Name getter
System::String^ Makers::Net::Items::ItemBase::CustomName::get()
{
	return Conversion::ConvertString(item_base_->custom_name());
}

//@ Custom Name setter
void Makers::Net::Items::ItemBase::CustomName::set(System::String^ _customName)
{
	std::string custom_name;
	Conversion::ConvertString(_customName, custom_name);
	item_base_->set_custom_name(custom_name);
}

//@ Last Computed Time
System::Int64^ Makers::Net::Items::ItemBase::LastComputedTime::get()
{
	return item_base_->last_computed_time();
}

//@ Input Properties getter
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::InputProperties::get()
{
	// TODO : how to change property group 

	return nullptr;
}

//@ Static Properties getter
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::StaticProperties::get()
{
	// TODO : how to change property group 

	return nullptr;
}

//@ Output Properties
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::OutputProperties::get()
{
	// TODO : how to change property group 

	return nullptr;
}

//@ internal constructor
//@ access from item factory
Makers::Net::Items::ItemBase::ItemBase(ItemBase_* _item_base) 
{
	item_base_ = _item_base;
}

Makers::Net::Items::ItemBase::~ItemBase() 
{
	// TODO : 
}

Makers::Net::Items::ItemBase::!ItemBase() 
{
	// TODO :
}


//@ internal function
//@ export pure object
Makers::Items::ItemBase_* Makers::Net::Items::ItemBase::Export()
{
	return item_base_;
}
