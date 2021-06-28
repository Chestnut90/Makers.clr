#pragma once

#include "../IXmlNodeAble.h"

namespace Makers
{
	namespace Properties { class PropertyBase; }
	namespace Net
	{
		namespace Items { ref class ItemBase; }
		namespace Properties
		{
			// non memory hold
			public ref class PropertyBase : 
				public IXmlNodeAble
			{

			private:
				//@ pure property base object
				Makers::Properties::PropertyBase* property_base_;

				//@ ref ownerItem
				Makers::Net::Items::ItemBase^ ownerItem = nullptr;
#pragma region Properties

			public:

				//@ ID
				property System::String^ ID
				{
					System::String^ get();
				}

				//@ Name
				property System::String^ Name
				{
					System::String^ get();
				}

				//@ OwnerItem
				property Makers::Net::Items::ItemBase^ OwnerItem
				{
					Makers::Net::Items::ItemBase^ get();
				}

				// TODO : computable

				//@ IsOptional
				property bool IsOptional
				{
					bool get();
				}

				//@ IsUsed
				property bool IsUsed
				{
					bool get();
					void set(bool isUsed);
				}
#pragma endregion

#pragma region ctors
			internal:
				//@ constructor
				PropertyBase(
					Makers::Net::Items::ItemBase^ ownerItem,
					Makers::Properties::PropertyBase& propertyBase);

				//@ destructor
				virtual ~PropertyBase();

			public:
				//@ TODO : how to imple?
				//@ finalizer
				!PropertyBase();
#pragma endregion

			public:
				//@ to data
				virtual System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData();

			internal:
				//@ export pure instance
				virtual Makers::Properties::PropertyBase* Export();

#pragma region implement IXmlNodeAble

			public:

				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) override;

				virtual void LoadFromXml(System::Xml::XmlNode^) override;


#pragma endregion

			};
		}
	}
}