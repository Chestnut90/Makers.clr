#pragma once

#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyBase.h"

#include "../Items/ItemBase.h"
#include "../Conversions/Converter.h"

using PropertyBase_ = Makers::Properties::PropertyBase;
using namespace Makers::Net::Items;

namespace Makers
{
	namespace Net
	{
		namespace Properties
		{
			public ref class PropertyBase
			{

			//@ pure property base object
			private: PropertyBase_* property_base_;

#pragma region Properties
			//@ ID
			public: property System::String^ ID
			{
				System::String^ get()
				{
					return Conversion::ConvertString(property_base_->id());
				}
			}

			//@ Name
			public: property System::String^ Name
			{
				System::String^ get()
				{
					return Conversion::ConvertString(property_base_->name());
				}
			}

			//@ TODO : how to connection 
			//@ OwnerItem
			public: property ItemBase^ OwnerItem
			{
				Makers::Net::Items::ItemBase^ get()
				{
					return nullptr;
				}
				private: void set(Makers::Net::Items::ItemBase^ item)
				{

				}
			}

					// TODO : computable

			// TODO : dll updated and connection
			//@ IsOptional
			public: property bool IsOptional
			{
				bool get()
				{
					return false;
				}
			}

			//@ IsUsed
			public: property bool IsUsed
			{
				bool get()
				{
					return property_base_->is_used_;
				}
				void set(bool isUsed)
				{
					property_base_->set_is_used(isUsed);
				}
			}
#pragma endregion

#pragma region ctors
			//@ constructor
			public: PropertyBase()
			{
				//property_base_ = new PropertyBase_();
			}

			//@ destructor
			public: virtual ~PropertyBase()
			{
				delete property_base_;
			}

			//@ finalizer
			public: !PropertyBase()
			{

			}
#pragma endregion

			//@ to data
			public: virtual System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData()
			{
				auto data = gcnew System::Collections::Generic::Dictionary<System::String^, System::String^>();
			
				data["ID"] = ID;
				data["Name"] = Name;
				data["OwnerID"] = OwnerItem->ID;
				data["IsOptional"] = IsOptional.ToString();
				data["IsUsed"] = IsUsed.ToString();
				data["DataType"] = "/TODO";
				// TODO : data object info?

				return data;
			}

			};
		}
	}
}