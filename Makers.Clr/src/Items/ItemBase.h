#pragma once

#include "../IXmlNodeAble.h"

namespace Makers
{
	namespace Items { class ItemBase; }
	namespace Net
	{
		namespace Properties { ref class PropertyGroup; }
		namespace Items
		{
			public ref class ItemBase :
				public IXmlNodeAble
			{
#pragma region members

			private: 
				//@ pure item base object
				Makers::Items::ItemBase* item_base_;
				
				//@ input properties
				Makers::Net::Properties::PropertyGroup^ inputProperties = nullptr;
				//@ static properties
				Makers::Net::Properties::PropertyGroup^ staticProperties = nullptr;
				//@ output properties
				Makers::Net::Properties::PropertyGroup^ outputProperties = nullptr;

#pragma endregion
#pragma region properties
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

#pragma endregion

			internal: 
				//@ internal constructor
				//@ access from item factory
				ItemBase(Makers::Items::ItemBase* _item_base);

				//@ destructor
				~ItemBase();

			public:
				//@ TODO : 
				//@ finalizer
				!ItemBase();
			
			public:

				//@ to data
				System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData();
			
			internal: 
				//@ internal function
				//@ export pure object
				Makers::Items::ItemBase* Export();

#pragma region Xml

			public:

				//@ load from xml
				//@ xml node as item base
				virtual void LoadFromXml(System::Xml::XmlNode^) override;

				//@ to xml node
				//@ xml document as root
				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) override;

			private:

				//@ TODO : to make it automatically
				//@ properties to xml node
				//@ xml document as root
				//@ name as string
				System::Xml::XmlNode^ _PropertiesToXml(
					System::Xml::XmlDocument^,
					Makers::Net::Properties::PropertyGroup^,
					System::String^);

#pragma endregion

			};
		}
	}
}