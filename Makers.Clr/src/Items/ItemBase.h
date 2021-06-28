#pragma once

namespace Makers
{
	namespace Items { class ItemBase; }
	namespace Net
	{
		namespace Properties { ref class PropertyGroup; }
		namespace Items
		{
			public ref class ItemBase 
			{

			private: 
				//@ pure item base object
				Makers::Items::ItemBase* item_base_;
				
				//@ input properties
				Makers::Net::Properties::PropertyGroup^ inputProperties = nullptr;
				//@ static properties
				Makers::Net::Properties::PropertyGroup^ staticProperties = nullptr;
				//@ output properties
				Makers::Net::Properties::PropertyGroup^ outputProperties = nullptr;

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
					void set(System::String^ customName);
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
				ItemBase(Makers::Items::ItemBase& _item_base);

				//@ destructor
				~ItemBase();

			public:
				//@ TODO : 
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