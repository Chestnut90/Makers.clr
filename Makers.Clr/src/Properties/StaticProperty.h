#pragma once

#include "PropertyBase.h"

namespace Makers
{
	namespace Net
	{
		namespace Properties
		{
			public ref class StaticProperty :
				public PropertyBase
			{

			public: 
				StaticProperty();
				~StaticProperty();
				!StaticProperty();

			public:
				// TODO : toData overriding

			};
		}
	}
}