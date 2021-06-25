#pragma once

#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/PropertyGroup.h"

#include "PropertyBase.h"
#include "../Conversions/Converter.h"

using PropertyGroup_ = Makers::Properties::PropertyGroup;

namespace Makers 
{
	namespace Net 
	{
		namespace Properties
		{
			public ref class PropertyGroup
			{

			//@ pure property group object
			private: PropertyGroup_* property_group_;

			//@ Count
			public: property System::Int32^ Count
			{
				System::Int32^ get()
				{
					return property_group_->Count();
				}
			}

			//@ constructor
			public: PropertyGroup()
			{
				property_group_ = new PropertyGroup_();

			}

			//@ destructor
			public: ~PropertyGroup()
			{
				delete property_group_;
			}

			//@ finalizer
			public: !PropertyGroup()
			{

			}
			
			//@ [name] operator
			public: PropertyBase^ operator[] (System::String^ name)
			{
				std::string std_name;
				Conversion::ConvertString(name, std_name);

				auto property = (*property_group_)[std_name];
				// TODO : how to change property type
				return nullptr;
			}

			//@ query with id
			public: PropertyBase^ QueryPropertyID(System::String^ id)
			{
				std::string std_id;
				Conversion::ConvertString(id, std_id);

				auto property = property_group_->QueryPropertyID(std_id);
				// TODO: how to change property type
				return nullptr;
			}

			//@ query with name
			public: PropertyBase^ QueryPropertyName(System::String^ name)
			{
				std::string std_name;
				Conversion::ConvertString(name, std_name);

				auto property = (*property_group_)[std_name];
				// TODO: how to change proeprty type
				return nullptr;
			}


			};
		}
	}
}