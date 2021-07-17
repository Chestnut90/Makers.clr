#include "pch.h"
#include "Enum.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/Enum.h"

#include "../Conversions/Converter.h"

using String_ = Conversion::Strings;

//@ get name
System::String^ Makers::Net::Computables::Enum::Name::get()
{
	auto enum_object = dynamic_cast<Makers::Computables::Enum*>(computable_);
	if (enum_object == nullptr)
	{
		throw gcnew System::Exception("Cannot conver Enum class in Name getter");
	}

	return String_::ToString(enum_object->name());
}

//@ get selected index
int Makers::Net::Computables::Enum::SelectedIndex::get()
{
	auto enum_object = dynamic_cast<Makers::Computables::Enum*>(computable_);
	if (enum_object == nullptr)
	{
		throw gcnew System::Exception("Cannot conver Enum class in SelectedIndex getter");
	}

	return enum_object->selected_index();
}

//@ set selected index
void Makers::Net::Computables::Enum::SelectedIndex::set(int selectedIndex)
{
	auto enum_object = dynamic_cast<Makers::Computables::Enum*>(computable_);
	if (enum_object == nullptr)
	{
		throw gcnew System::Exception("Cannot conver Enum class in SelectedIndex setter");
	}

	try
	{
		enum_object->set_selected_index(selectedIndex);
	}
	catch (const std::exception& e)
	{
		System::String^ error = String_::ToString(std::string(e.what()));
		throw gcnew System::Exception(error);
	}
}

//@ get selected value
System::String^ Makers::Net::Computables::Enum::SelectedValue::get()
{
	auto enum_object = dynamic_cast<Makers::Computables::Enum*>(computable_);
	if (enum_object == nullptr)
	{
		throw gcnew System::Exception("Cannot conver Enum class in Name getter");
	}

	try
	{
		return String_::ToString(enum_object->selected_value());
	}
	catch (const std::exception& e)
	{
		System::String^ error = String_::ToString(std::string(e.what()));
		throw gcnew System::Exception(error);
	}
}

//@ get enumeration list
System::Collections::Generic::List<System::String^>^ Makers::Net::Computables::Enum::Enumerations::get()
{
	auto enum_object = dynamic_cast<Makers::Computables::Enum*>(computable_);
	if (enum_object == nullptr)
	{
		throw gcnew System::Exception("Cannot conver Enum class in Enumeration getter");
	}

	auto vector = enum_object->enumeration();
	auto list = gcnew System::Collections::Generic::List<System::String^>();
	for (auto value : vector)
	{
		list->Add(String_::ToString(value));
	}

	return list;
}

//@ constructor
Makers::Net::Computables::Enum::Enum(Makers::Computables::IComputable * computable) : 
	Computable(computable)
{
}

//@ destructor
Makers::Net::Computables::Enum::~Enum()
{
}

// TODO : implement finalizer
//@ finalizer
Makers::Net::Computables::Enum::!Enum()
{
}

//@ load data from xml node
void Makers::Net::Computables::Enum::LoadFromXml(System::Xml::XmlNode ^ xmlNode)
{
	Computable::LoadFromXml(xmlNode);

	// set selected index
	int selectedIndex;
	bool try_get_selected_index = System::Int32::TryParse(xmlNode->Attributes["SelectedIndex"]->Value, selectedIndex);
	SelectedIndex = try_get_selected_index ? selectedIndex : 0;

	// do not parse name
	// do not parse selected value
}

//@ to xml
System::Xml::XmlNode ^ Makers::Net::Computables::Enum::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = Computable::ToXml(xmlDocument);

	// parse selected index
	auto selectedIndexAttribute = xmlDocument->CreateAttribute("SelectedIndex");
	selectedIndexAttribute->Value = SelectedIndex.ToString();
	xmlNode->Attributes->Append(selectedIndexAttribute);

	// do not parse name
	// do not parse selected value


	return xmlNode;
}
