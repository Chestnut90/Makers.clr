#pragma once

#include "../IXmlNodeAble.h"

namespace Makers 
{
	namespace Properties 
	{
		class PropertyBase;
		class PropertyGroup; 
	}
	namespace Net 
	{
		namespace Items { ref class ItemBase; }
		namespace Properties
		{
			ref class PropertyBase;
			//@ property group
			//@ subordinated class in itembase
			//@ key - value = id - property base
			public ref class PropertyGroup :
				//public System::Collections::Generic::Dictionary<System::String^, PropertyBase^>,
				public IXmlNodeAble
			{
#pragma region members

			private: 
				//@ pure property group object
				Makers::Properties::PropertyGroup* property_group_;

#pragma endregion

			public:
				//@ count
				property int Count
				{
					int get();
				}

				//@ owner item
				property Makers::Net::Items::ItemBase^ OwnerItem
				{
					Makers::Net::Items::ItemBase^ get();
				}

			internal: 
				//@ constructor
				PropertyGroup(Makers::Properties::PropertyGroup* _property_group);
				//@ destructor
				~PropertyGroup();

			public:
				//@ TODO : how to imple?
				//@ finalizer
				!PropertyGroup();

			public: 
			
				//@ query with name
				PropertyBase^ QueryPropertyName(System::String^ name);

				//@ query with id
				PropertyBase^ QueryPropertyID(System::String^ id);
			
				//@ To List
				System::Collections::Generic::List<PropertyBase^>^ ToList();

				//PropertyBase^ operator [](System::String^) override;

			private:
				// TODO : to make it efficiently
				//@ cast to ref
				PropertyBase^ _Cast(Makers::Properties::PropertyBase* _property_base);

#pragma region xml, implement IXmlNodeAble

			public:

				//@ from xml node
				//@ xml node as proeprty group
				void LoadFromXml(System::Xml::XmlNode^) override;
				
				//@ to xml
				//@ xml document as root
				System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) override;

#pragma endregion

			};
		}
	}
}