#include "pch.h"
#include "ItemBase.h"


#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemBase.h"

// props
#include "../Properties/PropertyGroup.h"

#include "../Conversions/Converter.h"

using Strings_ = Conversion::Strings;

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
	return inputProperties;
}

//@ Static Properties getter
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::StaticProperties::get()
{
	return staticProperties;
}

//@ Output Properties
Makers::Net::Properties::PropertyGroup^ Makers::Net::Items::ItemBase::OutputProperties::get()
{
	return outputProperties;
}

//@ internal constructor
//@ access from item factory
Makers::Net::Items::ItemBase::ItemBase(Makers::Items::ItemBase& _item_base) 
{
	item_base_ = &_item_base;

	inputProperties = gcnew Makers::Net::Properties::PropertyGroup(this, item_base_->input_properties());
	staticProperties = gcnew Makers::Net::Properties::PropertyGroup(this, item_base_->static_properties());
	outputProperties = gcnew Makers::Net::Properties::PropertyGroup(this, item_base_->output_properties());
}

Makers::Net::Items::ItemBase::~ItemBase() 
{
	// TODO delete using item factory
	//delete item_base_;
}

Makers::Net::Items::ItemBase::!ItemBase() 
{
	// TODO :
}


//@ internal function
//@ export pure object
Makers::Items::ItemBase* Makers::Net::Items::ItemBase::Export()
{
	return item_base_;
}
