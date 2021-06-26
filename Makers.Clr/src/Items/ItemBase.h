#pragma once

namespace Makers
{
	namespace Items { class ItemBase; }
	namespace Net
	{
		namespace Items
		{
			public ref class ItemBase 
			{

			private: 
				//@ pure item base object
				Makers::Items::ItemBase* item_base_;
					 
			public: 
				//@ ID
				property System::String^ ID
				{
					System::String^ get();
				}

				//@ Item Name
				property System::String^ ItemName
				{
					System::String^ get();
				}

				//@ Custom Name
				property System::String^ CustomName
				{
					System::String^ get();
					void set(System::String^ _customName);
				}

				//@ Last Computed Time
				property System::Int64^ LastComputedTime
				{
					System::Int64^ get();
				}

				//@ Input Properties
				property Makers::Net::Properties::PropertyGroup^ InputProperties
				{
					Makers::Net::Properties::PropertyGroup^ get();
				}

				//@ Static Properties
				property Makers::Net::Properties::PropertyGroup^ StaticProperties
				{
					Makers::Net::Properties::PropertyGroup^ get();
				}

				//@ Output Properties
				property Makers::Net::Properties::PropertyGroup^ OutputProperties
				{
					Makers::Net::Properties::PropertyGroup^ get();
				}

			
			internal: 
				//@ internal constructor
				//@ access from item factory
				ItemBase(ItemBase_* _item_base) ;

			public: 
				//@ destructor
				~ItemBase();

				//@ finalizer
				!ItemBase();
			
			
			internal: 
				//@ internal function
				//@ export pure object
				Makers::Items::ItemBase* Export();

			};
		}
	}
}