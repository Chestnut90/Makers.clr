#pragma once

#include "PropertyBase.h"

namespace Makers
{
	namespace Properties { class InputProperty; }
	namespace Net
	{
		namespace Properties
		{
			public ref class InputProperty :
				public PropertyBase,
				public IXmlNodeAble
			{
			public: 
				//@ connected property
				property PropertyBase^ ConnectedProperty
				{
					PropertyBase^ get();
					void set(PropertyBase^ connectedProperty);
				}

			public: 
				//@ constructor
				InputProperty(Makers::Properties::InputProperty* inputProperty);
				//@ destructor
				~InputProperty();
				//@ finalizer
				!InputProperty();

			public: 
				//@ to data
				System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData() override;

				//@ export pure data
				//Makers::Properties::PropertyBase* Export() override;

#pragma region implement IXmlNodeAble
			public:

				System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) override;

				void LoadFromXml(System::Xml::XmlNode^) override;

#pragma endregion
			};
		}
	}
}