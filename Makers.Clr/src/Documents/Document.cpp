#include "pch.h"
#include "Document.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Documents/Document.h"

#include "../Items/ItemBase.h"

#include "../Conversions/Converter.h"

//@ ID getter
System::String^ Makers::Net::Documents::Document::ID::get()
{
	return Conversion::ConvertString(document_->id());
}

//@ Title getter
System::String^ Makers::Net::Documents::Document::Title::get()
{
	return  Conversion::ConvertString(document_->title());
}


//@ Title setter
void Makers::Net::Documents::Document::Title::set(System::String^ title)
{
	std::string std_title;
	Conversion::ConvertString(title, std_title);
	document_->set_title(std_title);
}

//@ Item Count getter
System::Int32^ Makers::Net::Documents::Document::Count::get()
{
	return document_->Count();
}

//@ constructor
Makers::Net::Documents::Document::Document()
{
	document_ = new Document_();
}

//@ constructor with id
Makers::Net::Documents::Document::Document(System::String^ id)
{
	// TODO : 
}

//@ destructor
Makers::Net::Documents::Document::~Document()
{
	delete document_;
}

//@ finalizer
Makers::Net::Documents::Document::!Document()
{ 
	bool a = false;
}

//@ add item
void Makers::Net::Documents::Document::AddItem(Makers::Net::Items::ItemBase^ item)
{
	auto item_base = item->Export();
	document_->AddItem(item_base);
}

//@ remove item
void Makers::Net::Documents::Document::RemoveItem(Makers::Net::Items::ItemBase^ item)
{
	RemoveItem(item->ID);
}

//@ remove item with ID
void Makers::Net::Documents::Document::RemoveItem(System::String^ id)
{
	std::string std_id;
	Conversion::ConvertString(id, std_id);
	document_->RemoveItem(std_id);
}

//@ search item with id
Makers::Net::Items::ItemBase^ Makers::Net::Documents::Document::SearchItem(System::String^ id)
{
	std::string std_id;
	Conversion::ConvertString(id, std_id);
	auto item = document_->SearchItem(std_id);
	// TODO :??????
	return nullptr;
}

//@ search item with index
Makers::Net::Items::ItemBase^ Makers::Net::Documents::Document::SearchItem(System::Int32^ index)
{
	auto item = document_->SearchItem(*index);
	// TODO : ????
	return nullptr;
}

//@ Search Item Index
System::Int32^ Makers::Net::Documents::Document::SearchItemIndex(Makers::Net::Items::ItemBase^ item)
{
	return SearchItemIndex(item->ID);
}

//@ Search Item Index with id
System::Int32^ Makers::Net::Documents::Document::SearchItemIndex(System::String^ id)
{
	std::string std_id;
	Conversion::ConvertString(id, std_id);
	auto item = document_->SearchItemIndex(std_id);
	// TODO: 
	return nullptr;
}

//@ Find root items
System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ Makers::Net::Documents::Document::FindRootItems()
{
	// TODO : 
	return gcnew System::Collections::Generic::List<Makers::Net::Items::ItemBase^>();
}

//@ Clear All Items
void Makers::Net::Documents::Document::ClearItems()
{
	document_->ClearItems();
}

//@ run with async
bool Makers::Net::Documents::Document::RunAsync(
)
{
	return true;
}
