#pragma once

#include "../IXmlNodeAble.h"

namespace Makers
{
	namespace Computables { class IComputable; }
	namespace Net
	{
		namespace Computables
		{
			//@ Instance type enum
			enum class eInstanceType : int
			{
				None = -1,

				Image = 0,
				Real = 1,
				ROI = 2,
				Enum = 3,
			};

			//@ Data type enum
			enum class eDataType :int
			{
				None = -1,

				Void = 0,
				Bool = 1,
				Byte = 2,
				Int = 3,
				Long = 4,
				Float = 5,
				Double = 6,
				String = 7,
			};

			//@ Class <Computable>
			//@ copy object -> support interface of pure object
			public ref class Computable :
				public IXmlNodeAble
			{
			public:
				//@ Instance Type 
				property Makers::Net::Computables::eInstanceType InstanceType
				{
					Makers::Net::Computables::eInstanceType get();
				}
				//@ Instance Type to string
				property System::String^ InstanceTypeString
				{
					System::String^ get();
				}
				//@ Data Type
				property Makers::Net::Computables::eDataType DataType
				{
					Makers::Net::Computables::eDataType get();
				}
				//@ Data Type to String
				property System::String^ DataTypeString
				{
					System::String^ get();
				}

			protected:
				//@ pure computable handle
				Makers::Computables::IComputable* computable_;

			public:
				//@ constructor with computable handle
				Computable(Makers::Computables::IComputable* computable);
				//@ destructor
				//@ virtual destructor
				virtual ~Computable();
				//@ finalizer
				!Computable();

			public:
				//@ Can attach input to this
				//@ virtual function
				virtual bool CanAttachInto(Makers::Net::Computables::Computable^ computable);

				// implement <IXmlNodeAble>
			public:
				//@ Load from xml 
				//@ abstract function
				virtual void LoadFromXml(System::Xml::XmlNode^ xmlNode) override;
				//@ To xml
				//@ abstract function
				virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^ xmlDocument) override;

			internal:
				//@ export handle
				Makers::Computables::IComputable* Export();
			};
		}
	}

}

