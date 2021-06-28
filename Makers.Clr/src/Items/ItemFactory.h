#pragma once

namespace Makers
{
	namespace Items { class ItemFactory; }
	namespace Net
	{
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
				void IDHandle(Makers::Net::Items::ItemBase^ itemBase, System::String^ id);
				void IDHandle(Makers::Net::Properties::PropertyBase^ propertyBase, System::String^ id);

			public: 

				//@ create item
				ItemBase^ Create(System::String^ itemName);

				//@ containing items
				System::Collections::Generic::Dictionary<System::String^, System::Collections::Generic::List<System::String^>^>^ 
					ContainingItems();

			};
		}
	}
}