#pragma once

#include "Computable.h"

namespace Makers
{
	namespace Net
	{
		namespace Computables
		{
#pragma region TODO : generic real

			//@ Do not use
			generic <typename T>
			public ref class Real :
				public Computable
			{
			public:

			public:
				Real();
				~Real();
				!Real();

			internal:
				Real(Makers::Computables::IComputable* real);

			};

#pragma endregion

#pragma region Real Float

			public ref class RealFloat :
				public Computable
			{
			public:

				property float Value
				{
					float get();
					void set(float value);
				}

			public:
				RealFloat(Makers::Computables::IComputable* computable);
				~RealFloat();
				!RealFloat();

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
#pragma region Real Int

			public ref class RealInt :
				public Computable
			{
			public:

				property int Value
				{
					int get();
					void set(int value);
				}

			public:
				RealInt(Makers::Computables::IComputable* computable);
				~RealInt();
				!RealInt();

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
#pragma region Real Long

			public ref class RealLong :
				public Computable
			{
			public:

				property long Value
				{
					long get();
					void set(long value);
				}

			public:
				RealLong(Makers::Computables::IComputable* computable);
				~RealLong();
				!RealLong();

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
#pragma region Real bool

			public ref class RealBool :
				public Computable
			{
			public:

				property bool Value
				{
					bool get();
					void set(bool value);
				}

			public:
				RealBool(Makers::Computables::IComputable* computable);
				~RealBool();
				!RealBool();

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