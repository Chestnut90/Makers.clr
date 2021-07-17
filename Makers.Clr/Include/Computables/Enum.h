#pragma once

#include "Computable.h"

namespace Makers
{
	namespace Computables { class Enum; }
	namespace Net
	{
		namespace Computables
		{
#pragma region ROI

			public ref class Enum :
				public Computable,
				public IXmlNodeAble
			{
			public:

				//@ Name
				property System::String^ Name
				{
					System::String^ get();
				}

				//@ Selected Index
				property int SelectedIndex
				{
					int get();
					void set(int selectedIndex);
				}

				//@ Selected Value
				property System::String^ SelectedValue
				{
					System::String^ get();
				}

				//@ Enumeration list
				property System::Collections::Generic::List<System::String^>^ Enumerations
				{
					System::Collections::Generic::List<System::String^>^ get();
				}

			public:
				//@ Constructor
				Enum(Makers::Computables::IComputable* computable);
				//@ Destructor
				~Enum();
				//@ Finalizer
				!Enum();

				// implement <IXmlNodeAble>
			public:
				//@ Load from xml 
				//@ abstract function
				virtual void LoadFromXml(System::Xml::XmlNode^ xmlNode) override;
				//@ To xml
				//@ abstract function
				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^ xmlDocument) override;

			};

#pragma endregion
		}
	}
}