#pragma once

#include "PropertyBase.h"

namespace Makers
{
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
				InputProperty();
				~InputProperty();
				!InputProperty();

			public: 
				System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData() override;
			};
		}
	}
}