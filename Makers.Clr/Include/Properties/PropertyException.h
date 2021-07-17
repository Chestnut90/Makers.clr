#pragma once

namespace Makers
{
	namespace Net
	{
		namespace Properties
		{
			public ref class PropertyException :
				public System::Exception
			{

			public: 
				//@ constructor
				PropertyException();

				//@ constructor with message
				PropertyException(System::String^ message);

				//@ destructor
				~PropertyException();
				//@ finalizer
				!PropertyException();

			public:
				// TODO : toData overriding

			};
		}
	}
}