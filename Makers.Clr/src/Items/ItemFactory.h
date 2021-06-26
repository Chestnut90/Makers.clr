#pragma once

namespace Makers
{
	namespace Items { class ItemFactory; }
	namespace Net
	{
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

			public: 
				//@ create item
				ItemBase^ Create(System::String^ itemName);

			};
		}
	}
}