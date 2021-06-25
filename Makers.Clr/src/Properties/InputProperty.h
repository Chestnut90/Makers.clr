#pragma once

#include "PropertyBase.h"

//@ To casting
#include "../../../../Makers.Pure/Makers.Pure/Include/Properties/InputProperty.h"

namespace Makers
{
	namespace Net
	{
		namespace Properties
		{
			public ref class InputProperty :
				public PropertyBase
			{
					//@ connected property
			public: property PropertyBase^ ConnectedProperty;

			public: InputProperty() : PropertyBase()
			{

			}

			public: ~InputProperty()
			{

			}

			public: !InputProperty()
			{

			}

			public: System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData() override
			{
				auto data = PropertyBase::ToData();

				// add connected property infos
				data["ConnectedPropertyID"] = ConnectedProperty == nullptr ? "" : ConnectedProperty->ID;
				data["ConnectedPropertyOwnerID"] = ConnectedProperty == nullptr ? "" : ConnectedProperty->OwnerItem->ID;

				return data;
			}
			};
		}
	}
}