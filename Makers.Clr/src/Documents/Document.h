#pragma once

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
			public ref class Document
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
#pragma endregion
			public: 
				//@ constructor
				Document();
			
				//@ constructor with id
				Document(System::String^ id);

				//@ destructor
				~Document();

				//@ finalizer
				!Document();
			
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

				//@ run with async
				bool RunAsync();

			};
		}
	}
}