#pragma once

namespace Makers
{
	public interface class IXmlNodeAble
	{

	public:
		virtual void LoadFromXml(System::Xml::XmlNode^) = 0;

		virtual System::Xml::XmlNode^ ToXml(System::Xml::XmlDocument^) = 0;
	};
}