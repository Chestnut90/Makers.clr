#pragma once

namespace nXSDK
{
	namespace Net
	{
		public ref class SurfIOException :
			public System::Exception
		{
		public:
			//@ constructor
			SurfIOException(System::String^ error);
			//@ destructor
			~SurfIOException();
			//@ finalizer
			!SurfIOException();

		};
	}
}