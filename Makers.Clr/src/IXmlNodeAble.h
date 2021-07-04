#pragma once

namespace Makers
{
	public ref class IXmlNodeAble
	{
	public:
		IXmlNodeAble();
		~IXmlNodeAble();
		!IXmlNodeAble();

	public:
		virtual void LoadFromXml(System::Xml::XmlNode^) = 0;

		virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) = 0;
	};
}