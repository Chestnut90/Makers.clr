#pragma once

// TODO : path to short
#include "../../../../Makers.Pure/Makers.Pure/Include/Documents/Document.h"

#include "../Items/ItemBase.h"

#include "../Conversions/Converter.h"

using Document_ = Makers::Documents::Document;

namespace Makers
{
	namespace Net
	{
		namespace Documents
		{
			public ref class Document
			{
			//@ pure document object
			private: Document_* document_;

			//@ ID
			public: property System::String^ ID
			{
				System::String^ get()
				{
					return Conversion::ConvertString(document_->id());
				}
			}

			//@ Title
			public: property System::String^ Title
			{
				System::String^ get()
				{
					return  Conversion::ConvertString(document_->title());
				}
				void set(System::String^ _title)
				{
					std::string title;
					Conversion::ConvertString(_title, title);
					document_->set_title(title);
				}
			}

			//@ Item Count
			public: property System::Int32^ Count
			{
				System::Int32^ get()
				{
					return document_->Count();
				}
			}

			//@ constructor
			public: Document()
			{
				document_ = new Document_();
			}

			//@ destructor
			public: ~Document()
			{
				delete document_;
			}

			//@ finalizer
			public:!Document()
			{
				bool a = false;
			}

			//@ add item
			public: void AddItem(Makers::Net::Items::ItemBase^ item)
			{
				auto item_base = item->Export();
				document_->AddItem(item_base);
			}

			//@ remove item with Item
			public: void RemoveItem(Makers::Net::Items::ItemBase^ item)
			{
				RemoveItem(item->ID);
			}

			//@ remove item with ID
			public: void RemoveItem(System::String^ id)
			{
				std::string std_id;
				Conversion::ConvertString(id, std_id);
				document_->RemoveItem(std_id);
			}

			//@ search item with id
			public: Makers::Net::Items::ItemBase^ SearchItem(System::String^ id)
			{
				std::string std_id;
				Conversion::ConvertString(id, std_id);
				auto item = document_->SearchItem(std_id);
				// TODO :??????
				return nullptr;
			}

			//@ search item with index
			public: Makers::Net::Items::ItemBase^ SearchItem(System::Int32^ index)
			{
				auto item = document_->SearchItem(*index);
				// TODO : ????
				return nullptr;
			}

			//@ Search Item Index
			public: System::Int32^ SearchItemIndex(Makers::Net::Items::ItemBase^ item)
			{
				return SearchItemIndex(item->ID);
			}

			//@ Search Item Index with id
			public: System::Int32^ SearchItemIndex(System::String^ id)
			{
				std::string std_id;
				Conversion::ConvertString(id, std_id);
				auto item = document_->SearchItemIndex(std_id);
				// TODO: 
				return nullptr;
			}

			//@ Find root items
			public: System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ FindRootItems()
			{
				// TODO : 
				return gcnew System::Collections::Generic::List<Makers::Net::Items::ItemBase^>();
			}

			//@ Clear All Items
			public: void ClearItems()
			{
				document_->ClearItems();
			}

			//@ run with async
			public: bool RunAsync(
			)
			{
				return true;
			}

			};
		}
	}
}