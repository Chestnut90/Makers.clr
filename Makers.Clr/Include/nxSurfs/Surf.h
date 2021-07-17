#pragma once

typedef unsigned char byte;

namespace nXSDK
{
	class Surf;
	
	namespace Net
	{
		public ref class Surf
		{
		private:
			//@ use other handle
			bool is_use_handle_;
			//@ surf handle
			nXSDK::Surf* surf_;
#pragma region Properties
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
			//@ zmap
			property System::Collections::Generic::List<float>^ Zmap
			{
				System::Collections::Generic::List<float>^ get();
			}
			//@ mask
			property System::Collections::Generic::List<byte>^ Mask
			{
				System::Collections::Generic::List<byte>^ get();
			}
			//@ gray
			property System::Collections::Generic::List<byte>^ Gray
			{
				System::Collections::Generic::List<byte>^ get();
			}
			//@ red
			property System::Collections::Generic::List<byte>^ Red
			{
				System::Collections::Generic::List<byte>^ get();
			}
			//@ green
			property System::Collections::Generic::List<byte>^ Green
			{
				System::Collections::Generic::List<byte>^ get();
			}
			// blue
			property System::Collections::Generic::List<byte>^ Blue
			{
				System::Collections::Generic::List<byte>^ get();
			}
#pragma endregion
#pragma region ctors
		public:
			//@ constructor
			Surf();
			//@ destructor
			~Surf();
			//@ finalizer
			!Surf();
		internal:
			Surf(nXSDK::Surf& surf);

#pragma endregion

		private:
			//@ cpp byte array to csharp list byte
			System::Collections::Generic::List<byte>^ _ToByteList(byte* source);

			// I/O
		public:
			//@ Save surf
			bool Save(System::String^ filename);
			//@ Save surf
			//@ static
			static bool Save(nXSDK::Net::Surf^ surf, System::String^ filename);

			//@ Load surf file with path
			void Load(System::String^ filename);
			//@ Open surf file
			static nXSDK::Net::Surf^ Open(System::String^ filename);

		};
	}
}