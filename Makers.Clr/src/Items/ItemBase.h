#pragma once

#include "../../../../Makers.Pure/Makers.Pure/Include/Items/ItemBase.h"

// props
#include "../Properties/PropertyGroup.h"

#include "../Conversions/Converter.h"

using ItemBase_ = Makers::Items::ItemBase;

namespace Makers
{
	namespace Net
	{
		namespace Items
		{
			public ref class ItemBase 
			{
			//@ pure item base object
			private: ItemBase_* item_base_;
					 
			//@ ID
			public: property System::String^ ID
			{
				System::String^ get()
				{
					return Conversion::ConvertString(item_base_->id());
				}
			}

			//@ Item Name
			public: property System::String^ ItemName
			{
				System::String^ get()
				{
					return Conversion::ConvertString(item_base_->item_name());
				}
			}

			//@ Custom Name
			public: property System::String^ CustomName
			{
				System::String^ get()
				{
					return Conversion::ConvertString(item_base_->custom_name());
				}
				void set(System::String^ _customName)
				{
					std::string custom_name;
					Conversion::ConvertString(_customName, custom_name);
					item_base_->set_custom_name(custom_name);
				}
			}

			//@ Last Computed Time
			public: property System::Int64^ LastComputedTime
			{
				System::Int64^ get()
				{
					return item_base_->last_computed_time();
				}
			}

			//@ Input Properties
			public: property Makers::Net::Properties::PropertyGroup^ InputProperties
			{
				Makers::Net::Properties::PropertyGroup^ get()
				{
					// TODO : how to change property group 

					return nullptr;
				}
			}

			//@ Static Properties
			public: property Makers::Net::Properties::PropertyGroup^ StaticProperties
			{
				Makers::Net::Properties::PropertyGroup^ get()
				{
					// TODO : how to change property group 

					return nullptr;
				}
			}

			//@ Output Properties
			public: property Makers::Net::Properties::PropertyGroup^ OutputProperties
			{
				Makers::Net::Properties::PropertyGroup^ get()
				{
					// TODO : how to change property group 

					return nullptr;
				}
			}

			//@ internal constructor
			//@ access from item factory
			internal: ItemBase(ItemBase_* _item_base) 
			{
				item_base_ = _item_base;
			}

			public: ~ItemBase() 
			{
				// TODO : 
			}

			public: !ItemBase() 
			{
				// TODO :
			}
			
			//@ internal function
			//@ export pure object
			internal: ItemBase_* Export()
			{
				return item_base_;
			}

			};
		}
	}
}