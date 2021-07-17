#pragma once

#include "PropertyBase.h"

namespace Makers
{
	namespace Properties { class StaticProperty; }
	namespace Net
	{
		namespace Properties
		{
			public ref class StaticProperty :
				public PropertyBase
			{

			public: 
				StaticProperty(Makers::Properties::StaticProperty* staticProperty);
				~StaticProperty();
				!StaticProperty();

			public:
				// TODO : toData overriding

			};
		}
	}
}