#include "pch.h"
#include "Document.h"

// pures
#include "../../../../Makers.Pure/Makers.Pure/Include/Documents/Document.h"

// refs
#include "../Items/ItemBase.h"
#include "../Items/ItemFactory.h"
#include "../Properties/PropertyGroup.h"
#include "../Properties/InputProperty.h"

// surf
#include "../nxSurfs/Surf.h"

#include "../Conversions/Converter.h"

//@ Surf getter
nXSDK::Net::Surf^ Makers::Net::Documents::Document::Surf::get()
{
	return gcnew nXSDK::Net::Surf(document_->surf());
}

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
int Makers::Net::Documents::Document::Count::get()
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
Makers::Net::Documents::Document::Document() 
{
	document_ = new Makers::Documents::Document();
}

Makers::Net::Documents::Document::Document(Makers::Documents::Document* document)
{
	document_ = document;
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
	document_->AddItem(*item_base);
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
	if (item == nullptr) return nullptr;
	return gcnew Makers::Net::Items::ItemBase(item);
}

//@ search item with index
Makers::Net::Items::ItemBase^ Makers::Net::Documents::Document::SearchItem(int index)
{
	auto item = document_->SearchItem(index);
	if (item == nullptr) return nullptr;
	return gcnew Makers::Net::Items::ItemBase(item);
}

//@ Search Item Index
int Makers::Net::Documents::Document::SearchItemIndex(Makers::Net::Items::ItemBase^ item)
{
	return SearchItemIndex(item->ID);
}

//@ Search Item Index with id
int Makers::Net::Documents::Document::SearchItemIndex(System::String^ id)
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
	System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ items
)
{
	std::vector<Makers::Items::ItemBase*> items_;
	for each (auto item in items)
	{
		items_.push_back(item->Export());
	}
	return document_->Run_Async(items_);
}

//@ to data
System::Collections::Generic::Dictionary<System::String^, System::String^>^ Makers::Net::Documents::Document::ToData()
{
	auto data = gcnew System::Collections::Generic::Dictionary<System::String^, System::String^>();

	data->Add("ID", ID);
	data->Add("Title", Title);
	data->Add("ItemCounts", (gcnew System::Int32(Count))->ToString());
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

	// load items
	ClearItems();
	auto xmlItemsNode = xmlNode->SelectSingleNode("Items");
	auto xmlItemNodes = xmlItemsNode->SelectNodes("Item");

	// add items
	for (int i = 0; i < xmlItemNodes->Count; i++)
	{
		auto xmlItemNode = xmlItemNodes->Item(i);

		auto itemName = xmlItemNode->Attributes["ItemName"]->Value;

		auto item_base = Makers::Net::Items::ItemFactory::Instance()->Create(itemName);
		AddItem(item_base);
		item_base->LoadFromXml(xmlItemNode);
	}

	// TODO : 
	// set connection
	for (int i = 0; i < xmlItemNodes->Count; ++i)
	{
		auto xmlItemNode = xmlItemNodes->Item(i);
		auto itemId = xmlItemNode->Attributes["ID"]->Value;

		auto xmlInputPropertiesNode = xmlItemNode->SelectSingleNode("InputProperties");
		auto xmlPropertyGroupNode = xmlInputPropertiesNode->SelectSingleNode("PropertyGroup");
		auto xmlInputPropertyNodes = xmlPropertyGroupNode->SelectNodes("Property");
		for (int j = 0; j < xmlInputPropertyNodes->Count; ++j) 
		{
			auto xmlInputPropertyNode = xmlInputPropertyNodes->Item(j);
			
			// check connection and empty
			auto connectedPropertyID = xmlInputPropertyNode->Attributes["ConnectedPropertyID"]->Value;
			auto connectedPropertyOwnerID = xmlInputPropertyNode->Attributes["ConnectedPropertyOwnerID"]->Value;
			if (connectedPropertyID->Equals(System::String::Empty) ||
				connectedPropertyOwnerID->Equals(System::String::Empty)) { continue; }
			

			// find owner
			auto connectedItem = SearchItem(connectedPropertyOwnerID);
			if (connectedItem == nullptr)
			{
				throw gcnew System::Exception("Cannot found connected owner item. in document");
			}
			auto connectedProperty = connectedItem->OutputProperties->QueryPropertyID(connectedPropertyID);

			// current item
			auto currentItem = SearchItem(itemId);
			if (currentItem == nullptr) { continue; }	// error

			// current property
			auto propertyId = xmlInputPropertyNode->Attributes["ID"]->Value;
			auto inputProperty = currentItem->InputProperties->QueryPropertyID(propertyId);
			inputProperty->ToData();
			
			auto casted = dynamic_cast<Makers::Net::Properties::InputProperty^>(inputProperty);
			casted->ConnectedProperty = connectedProperty;
		}
	}
}

System::Xml::XmlNode ^ Makers::Net::Documents::Document::ToXml(System::Xml::XmlDocument^ xmlDocument)
{
	auto xmlDocumentNode = xmlDocument->CreateElement("Document");

	// set attribute with document data
	for each (auto pair in ToData())
	{
		auto attribute = xmlDocument->CreateAttribute(pair.Key);	// set name with key
		attribute->Value = pair.Value;	// set value with value
		xmlDocumentNode->Attributes->Append(attribute);
	}

	// items node
	auto xmlItemsNode = xmlDocument->CreateElement("Items");
	for each(auto item in Items)
	{
		auto xmlNodeItem = item->ToXml(xmlDocument);
		xmlItemsNode->AppendChild(xmlNodeItem);
	}
	xmlDocumentNode->AppendChild(xmlItemsNode);

	return xmlDocumentNode;
}

#pragma endregion
