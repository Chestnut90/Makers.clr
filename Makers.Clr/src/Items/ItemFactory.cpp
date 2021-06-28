#include "pch.h"
#include "ItemFactory.h"


#include "ItemBase.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemFactory.h"
#include "../Conversions/Converter.h"

#include "../Properties/PropertyBase.h"

using Strings_ = Conversion::Strings;

//@ instance getter
Makers::Net::Items::ItemFactory^ Makers::Net::Items::ItemFactory::Instance()
{
	if (instance_ == nullptr)
	{
		instance_ = gcnew ItemFactory();
	}

	return instance_;
}

//@ destrotyer
void Makers::Net::Items::ItemFactory::Destory()
{
	delete instance_;
	instance_ = nullptr;
}

//@ protected constructor
Makers::Net::Items::ItemFactory::ItemFactory()
{
	item_factory_ = new Makers::Items::ItemFactory();
}

//@ protected destructor
Makers::Net::Items::ItemFactory::~ItemFactory()
{
	delete item_factory_;
}

//@ TODO : hide
void Makers::Net::Items::ItemFactory::IDHandle(Makers::Net::Items::ItemBase ^ itemBase, System::String ^ id)
{
	std::string std_id = Strings_::ToString(id);
	auto item_base = itemBase->Export();
	item_factory_->IDHandle(*item_base, std_id);
}

//@ TODO : hide
void Makers::Net::Items::ItemFactory::IDHandle(Makers::Net::Properties::PropertyBase ^ propertyBase, System::String ^ id)
{
	std::string std_id = Strings_::ToString(id);
	auto property_base = propertyBase->Export();
	item_factory_->IDHandle(*property_base, std_id);
}

//@ create item
Makers::Net::Items::ItemBase^ Makers::Net::Items::ItemFactory::Create(System::String^ itemName)
{
	std::string std_item_name = Strings_::ToString(itemName);
	auto item = item_factory_->Create(std_item_name);
	return gcnew ItemBase(*item);
}

//@ dictionary of list
System::Collections::Generic::Dictionary<System::String^, System::Collections::Generic::List<System::String^>^>^
	Makers::Net::Items::ItemFactory::ContainingItems()
{
	auto dict = gcnew System::Collections::Generic::Dictionary<
		System::String^, System::Collections::Generic::List<System::String^>^>();
	auto items = item_factory_->ContainingItems();
	
	for (auto pair : items)
	{
		auto group_name = Strings_::ToString(pair.first);
		auto names = pair.second;
		
		auto list = gcnew System::Collections::Generic::List<System::String^>();
		for (auto name : names)
		{
			list->Add(Conversion::ConvertString(name));
		}
		dict->Add(group_name, list);
	}

	return dict;
}
