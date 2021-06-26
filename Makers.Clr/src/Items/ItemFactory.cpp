#include "pch.h"
#include "ItemFactory.h"


#include "ItemBase.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemFactory.h"
#include "../Conversions/Converter.h"

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
	item_factory_ = new ItemFactory_();
}

//@ protected destructor
Makers::Net::Items::ItemFactory::~ItemFactory()
{
	delete item_factory_;
}

//@ create item
Makers::Net::Items::ItemBase^ Makers::Net::Items::ItemFactory::Create(System::String^ itemName)
{
	std::string a = "";
	Conversion::ConvertString(itemName, a);
	//a = Conversion::ConvertString(itemName);
	std::cout << a << std::endl;

	System::String^ net = Conversion::ConvertString(a);
	System::Console::WriteLine(net);

	std::string std_item_name;
	Conversion::ConvertString(itemName, std_item_name);
	auto item = item_factory_->Create(std_item_name);

	return gcnew ItemBase(item);
}
