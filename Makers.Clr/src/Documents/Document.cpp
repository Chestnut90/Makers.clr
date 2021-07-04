#include "pch.h"
#include "Document.h"

// pures
#include "../../../../Makers.Pure/Makers.Pure/Include/Documents/Document.h"

// refs
#include "../Items/ItemBase.h"
#include "../Items/ItemFactory.h"

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

//@ Items
System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ 
Makers::Net::Documents::Document::Items::get()
{
	auto list = gcnew System::Collections::Generic::List<Makers::Net::Items::ItemBase^>();

	for (int i = 0; i < document_->Count(); i++)
	{
		auto item = document_->SearchItem(i);
		list->Add(gcnew Makers::Net::Items::ItemBase(item));
	}
	return list;
}

//@ constructor
Makers::Net::Documents::Document::Document() :
	IXmlNodeAble()
{
	document_ = new Makers::Documents::Document();
}

//@ destructor
Makers::Net::Documents::Document::~Document()
{
	delete document_;
}

//@ TODO : 
//@ finalizer
Makers::Net::Documents::Document::!Document()
{ 
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
	return gcnew Makers::Net::Items::ItemBase(item);
}

//@ search item with index
Makers::Net::Items::ItemBase^ Makers::Net::Documents::Document::SearchItem(System::Int32^ index)
{
	auto item = document_->SearchItem(*index);
	return gcnew Makers::Net::Items::ItemBase(item);
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
	return document_->SearchItemIndex(std_id);
}

//@ Find root items
System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ Makers::Net::Documents::Document::FindRootItems()
{
	auto list = gcnew System::Collections::Generic::List<Makers::Net::Items::ItemBase^>();

	for (auto item : document_->FindRootItems())
	{
		list->Add(gcnew Makers::Net::Items::ItemBase(item));
	}
	return list;
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

//@ to data
System::Collections::Generic::Dictionary<System::String^, System::String^>^ Makers::Net::Documents::Document::ToData()
{
	auto data = gcnew System::Collections::Generic::Dictionary<System::String^, System::String^>();

	data->Add("ID", ID);
	data->Add("Title", Title);
	data->Add("ItemCounts", Count->ToString());
	return data;
}

//@ export pure document handle
Makers::Documents::Document * Makers::Net::Documents::Document::Export()
{
	return document_;
}

#pragma region XML

void Makers::Net::Documents::Document::LoadFromXml(System::Xml::XmlNode^ xmlNode)
{
	if (!xmlNode->Name->Equals("Document")) { return; }

	// change id
	auto id = xmlNode->Attributes["ID"]->Value;
	Makers::Net::Items::ItemFactory::Instance()->IDHandle(this, id);

	// set title
	Title = xmlNode->Attributes["Title"]->Value;
	
	// item counts
	// do nothing.
}

System::Xml::XmlNode ^ Makers::Net::Documents::Document::ToXml(System::Xml::XmlDocument^ xmlDocument)
{
	auto xmlNode = xmlDocument->CreateElement("Document");

	// set attribute with document data
	for each (auto pair in ToData())
	{
		auto attribute = xmlDocument->CreateAttribute(pair.Key);	// set name with key
		attribute->Value = pair.Value;	// set value with value
		xmlNode->Attributes->Append(attribute);
	}

	// items node
	for each(auto item in Items)
	{
		auto xmlNodeItem = item->ToXml(xmlDocument);
		xmlNode->AppendChild(xmlNodeItem);
	}

	return xmlNode;
}

#pragma endregion
