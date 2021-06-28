#pragma once

namespace Makers 
{
	namespace Properties 
	{
		class PropertyBase;
		class PropertyGroup; 
	}
	namespace Net 
	{
		namespace Items { ref class ItemBase; }
		namespace Properties
		{
			ref class PropertyBase;
			//@ property group
			//@ subordinated class in itembase
			public ref class PropertyGroup
			{
			private: 
				//@ pure property group object
				Makers::Properties::PropertyGroup* property_group_;

				Makers::Net::Items::ItemBase^ ownerItem = nullptr;

			public:
				//@ count
				property System::Int32^ Count
				{
					System::Int32^ get();
				}

			internal: 
				//@ constructor
				PropertyGroup(
					Makers::Net::Items::ItemBase^ ownerItem, 
					Makers::Properties::PropertyGroup& _property_group);
				//@ destructor
				~PropertyGroup();

			public:
				//@ TODO : how to imple?
				//@ finalizer
				!PropertyGroup();

			public: 
			
				//@ [name] operator
				//operator

				//@ query with name
				PropertyBase^ QueryPropertyName(System::String^ name);

				//@ query with id
				PropertyBase^ QueryPropertyID(System::String^ id);
			
				//@ To List
				System::Collections::Generic::List<PropertyBase^>^ ToList();

			private:
				//@ cast to ref
				PropertyBase^ Cast(Makers::Properties::PropertyBase* _property_base);

			};
		}
	}
}