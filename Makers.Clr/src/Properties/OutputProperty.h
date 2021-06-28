#pragma once

#include "PropertyBase.h"

namespace Makers
{
	namespace Properties { class OutputProperty; }
	namespace Net
	{
		namespace Properties
		{
			public ref class OutputProperty :
				public PropertyBase
			{

			public: 
				OutputProperty(
					Makers::Net::Items::ItemBase^ ownerItem,
					Makers::Properties::OutputProperty& outputProperty);

				~OutputProperty();

				!OutputProperty();

			};
		}
	}
}