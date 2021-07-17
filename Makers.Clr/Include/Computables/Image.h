#pragma once

#include "Computable.h"

namespace Makers
{
	namespace Computables { class IComputable; }
	namespace Net
	{
		namespace Computables
		{
#pragma region TODO : image generic class

			generic <typename T>
			public ref class Image :
				public Computable
			{
			private:
				//@ image handle
				void* image_handle_;

			public:
				//@ width
				property long Width
				{
					long get();
				}
				//@ height
				property long Height
				{
					long get();
				}
				//@ image source
				property System::Collections::Generic::List<T>^ Source
				{
					System::Collections::Generic::List<T>^ get();
				}

			public:
				//@ Constructor
				Image(Makers::Computables::IComputable* computable);
				//@ Destructor
				~Image();
				//@ Finalizer
				!Image();

			public:
				//@ Set Image
				void SetImage(
					System::Collections::Generic::List<T>^ image, 
					long width, 
					long height);

			};

#pragma endregion

#pragma region Image type class / float - byte


			public ref class ImageFloat :
				public Computable
			{
			private:

			public:

				property long Width
				{
					long get();
				}

				property long Height
				{
					long get();
				}

				property System::Collections::Generic::List<float>^ Image
				{
					System::Collections::Generic::List<float>^ get();
				}

			public:
				ImageFloat(Makers::Computables::IComputable* computable);
				~ImageFloat();
				!ImageFloat();

			public:

				void SetImage(
					System::Collections::Generic::List<float>^ image,
					long width,
					long height);
				
			public:
				// TODO : do not implement xml parsing

			};

			public ref class ImageByte :
				public Computable
			{
			private:

			public:

				property long Width
				{
					long get();
				}

				property long Height
				{
					long get();
				}

				property System::Collections::Generic::List<unsigned char>^ Image
				{
					System::Collections::Generic::List<unsigned char>^ get();
				}

			public:
				ImageByte(Makers::Computables::IComputable* computable);
				~ImageByte();
				!ImageByte();

			public:

				void SetImage(
					System::Collections::Generic::List<unsigned char>^ image,
					long width,
					long height);

			};
			#pragma endregion
			

			
}
	}

}

