#pragma once

namespace Makers 
{
	namespace Properties { class PropertyGroup; }
	namespace Net 
	{
		namespace Properties
		{
			public ref class PropertyGroup
			{

			private: 
				//@ pure property group object
				Makers::Properties::PropertyGroup* property_group_;

			public: 
				//@ Count
				property System::Int32^ Count
				{
					System::Int32^ get();
				}

			public: 
				//@ constructor
				PropertyGroup();
				//@ destructor
				~PropertyGroup();
				//@ finalizer
				!PropertyGroup();

			public: 
			
				//@ [name] operator
				PropertyBase^ operator[] (System::String^ name);

				//@ query with id
				PropertyBase^ QueryPropertyID(System::String^ id);

				//@ query with name
				PropertyBase^ QueryPropertyName(System::String^ name);

			};
		}
	}
}