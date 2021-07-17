#pragma once

#include "../IXmlNodeAble.h"

namespace Makers
{
	namespace Computables { class IComputable; }
	namespace Properties { class PropertyBase; }
	namespace Net
	{
		namespace Computables { ref class Computable; }
		namespace Items { ref class ItemBase; }
		namespace Properties
		{
			// non memory hold
			public ref class PropertyBase : 
				public IXmlNodeAble
			{

			protected:
				//@ pure property base object
				Makers::Properties::PropertyBase* property_base_;

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
				//@ Data object
				property Makers::Net::Computables::Computable^ DataObject
				{
					Makers::Net::Computables::Computable^ get();
				}

#pragma endregion

#pragma region ctors
			internal:
				//@ default constructor
				//PropertyBase();
				//@ constructor with property base handle
				PropertyBase(Makers::Properties::PropertyBase* propertyBase);
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
				//@ To xml node
				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^ xmlDocument) override;
				//@ parse data using xml node
				virtual void LoadFromXml(System::Xml::XmlNode^ xmlNode) override;

#pragma endregion
			};
		}
	}
}