#pragma once

namespace Makers
{

	namespace Properties { class PropertyBase; }
	namespace Net
	{
		namespace Items { ref class ItemBase; }
		namespace Properties
		{
			public ref class PropertyBase
			{

			private: 
				//@ pure property base object
				Makers::Properties::PropertyBase* property_base_;

#pragma region Properties
			public: 

				//@ ID
				property System::String^ ID
				{
					System::String^ get();
				}

				//@ Name
				property System::String^ Name
				{
					System::String^ get();
				}

				//@ TODO : how to connection 
				//@ OwnerItem
				property ItemBase^ OwnerItem
				{
					Makers::Net::Items::ItemBase^ get()
					private: // TODO : is this syntax ok?
						void set(Makers::Net::Items::ItemBase^ item);
				}

					// TODO : computable

				// TODO : dll updated and connection
				//@ IsOptional
				property bool IsOptional
				{
					bool get();
				}

				//@ IsUsed
				property bool IsUsed
				{
					bool get();
					void set(bool isUsed);
				}
#pragma endregion

#pragma region ctors
			public: 

				//@ constructor
				PropertyBase();

				//@ destructor
				virtual ~PropertyBase();

				//@ finalizer
				!PropertyBase();
#pragma endregion

			public: 

				//@ to data
				virtual System::Collections::Generic::Dictionary<System::String^, System::String^>^ ToData();

			};
		}
	}
}