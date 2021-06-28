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
				public PropertyBase
			{
			public: 
				//@ connected property
				property PropertyBase^ ConnectedProperty;

			public: 
				//@ constructor
				InputProperty(
					Makers::Net::Items::ItemBase^ ownerItem, 
					Makers::Properties::InputProperty& inputProperty);
				//@ destructor
				~InputProperty();
				//@ finalizer
				!InputProperty();

			public: 
				//@ to data
				System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData() override;

				//@ export pure data
				//Makers::Properties::PropertyBase* Export() override;

			};
		}
	}
}