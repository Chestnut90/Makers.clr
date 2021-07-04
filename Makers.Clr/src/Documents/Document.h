#pragma once

#include "../IXmlNodeAble.h"

namespace Makers
{
	// forward declaration
	// pure document class
	namespace Documents { class Document; }
	namespace Net
	{
		namespace Items { ref class ItemBase; }

		namespace Documents
		{
			public ref class Document :
				public IXmlNodeAble
			{
#pragma region Member and Properties
			//@ pure document object
			private: 
				Makers::Documents::Document* document_;

			public: 
				//@ ID
				property System::String^ ID
				{
					System::String^ get();
				}

				//@ Title
				property System::String^ Title
				{
					System::String^ get();
					void set(System::String^);
				}

				//@ Item Count
				property System::Int32^ Count
				{
					System::Int32^ get();
				}

				//@ Items
				property System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ Items
				{
					System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ get();
				}

#pragma endregion
			public: 
				//@ constructor
				Document();
			
				//@ destructor
				~Document();

				//@ finalizer
				!Document();
			
#pragma region Items

			public: 
				//@ add item
				void AddItem(Makers::Net::Items::ItemBase^ item);

				//@ remove item with Item
				void RemoveItem(Makers::Net::Items::ItemBase^ item);

				//@ remove item with ID
				void RemoveItem(System::String^ id);

				//@ search item with id
				Makers::Net::Items::ItemBase^ SearchItem(System::String^ id);

				//@ search item with index
				Makers::Net::Items::ItemBase^ SearchItem(System::Int32^ index);

				//@ Search Item Index
				System::Int32^ SearchItemIndex(Makers::Net::Items::ItemBase^ item);

				//@ Search Item Index with id
				System::Int32^ SearchItemIndex(System::String^ id);

				//@ Find root items
				System::Collections::Generic::List<Makers::Net::Items::ItemBase^>^ FindRootItems();

				//@ Clear All Items
				void ClearItems();

#pragma endregion

				//@ todo
				//@ run with async
				bool RunAsync();

				//@ to data
				System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData();

			internal:
				//@ export pure document handle
				Makers::Documents::Document* Export();

#pragma region xml, implement IXmlNodeAble

			public:
				//@ load from xml
				//@ node as document
				virtual void LoadFromXml(System::Xml::XmlNode^) override;

				//@ to xml
				//@ xml document as root
				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) override;

#pragma endregion

			};
		}
	}
}