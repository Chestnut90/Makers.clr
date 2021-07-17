#pragma once

namespace Makers
{
	namespace Items { class ItemFactory; }
	namespace Net
	{
		namespace Documents { ref class Document; }
		namespace Properties { ref class PropertyBase; }
		namespace Items
		{
			ref class ItemBase;

			public ref class ItemFactory
			{
			
			private: 
				//@ pure item factory instance
				Makers::Items::ItemFactory* item_factory_;

				//@ this factory instance
				static ItemFactory^ instance_;

			public: 
				//@ instance getter
				static ItemFactory^ Instance();

				//@ destroyer
				static void Destory();

			protected: 
				//@ protected constructor
				ItemFactory();

				//@ protected destructor
				~ItemFactory();

			// TODO : hide this functions into own class
			internal:
				void IDHandle(Makers::Net::Documents::Document^, System::String^ id);
				void IDHandle(Makers::Net::Items::ItemBase^, System::String^);
				void IDHandle(Makers::Net::Properties::PropertyBase^, System::String^);

			public: 

				//@ create item
				ItemBase^ Create(System::String^ itemName);

				//@ destroy item
				void DestoryItem(Makers::Net::Items::ItemBase^);

				//@ containing items
				System::Collections::Generic::Dictionary<System::String^, System::Collections::Generic::List<System::String^>^>^ 
					ContainingItems();

			};
		}
	}
}