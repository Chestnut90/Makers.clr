#include "pch.h"
#include "Computable.h"

// pures
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/IComputable.h"

#include "../Conversions/Converter.h"

//@ Instance Type
Makers::Net::Computables::eInstanceType Makers::Net::Computables::Computable::InstanceType::get()
{
	if (computable_ == nullptr) return Makers::Net::Computables::eInstanceType::None;
	return (Makers::Net::Computables::eInstanceType)((int)computable_->instance_type());
}

//@ Instane Type to string
System::String^ Makers::Net::Computables::Computable::InstanceTypeString::get()
{
	return Conversion::Strings::ToString(computable_->InstanceType());
}

//@ Data Type
Makers::Net::Computables::eDataType Makers::Net::Computables::Computable::DataType::get()
{
	if (computable_ == nullptr) return Makers::Net::Computables::eDataType::Void;
	return (Makers::Net::Computables::eDataType)((int)computable_->data_type());
}

// Data Type to string
System::String^ Makers::Net::Computables::Computable::DataTypeString::get()
{
	return Conversion::Strings::ToString(computable_->DataType());
}

//@ Contructor
Makers::Net::Computables::Computable::Computable(Makers::Computables::IComputable * computable)
{
	computable_ = computable;
}

//@ Destructor
Makers::Net::Computables::Computable::~Computable()
{
	// no release memory
	computable_ = nullptr;
}

//@ finalizer
Makers::Net::Computables::Computable::!Computable()
{

}

//@ Can attach input to this
bool Makers::Net::Computables::Computable::CanAttachInto(Makers::Net::Computables::Computable ^ computable)
{
	auto target_computable = computable->Export();
	if (target_computable == nullptr) return false;
	return computable_->CanAttachInto(target_computable);
}

//@ Load from xml
void Makers::Net::Computables::Computable::LoadFromXml(System::Xml::XmlNode^ xmlNode)
{
	System::String^ error = "Error Occured in parsing computable.\n";
	if (xmlNode == nullptr) 
	{ 
		throw gcnew System::Exception(error); 
	}
	if (!xmlNode->Name->Equals("Computable"))
	{
		throw gcnew System::Exception("Not Computable Node.");
	}

	// do not check instance type
	// do not check data type
}

System::Xml::XmlNode ^ Makers::Net::Computables::Computable::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = xmlDocument->CreateElement("Computable");

	// set instance type
	auto instanceTypeAttribute = xmlDocument->CreateAttribute("InstanceType");
	instanceTypeAttribute->Value = InstanceTypeString;
	xmlNode->Attributes->Append(instanceTypeAttribute);

	// set data type
	auto dataTypeAttribute = xmlDocument->CreateAttribute("DataType");
	dataTypeAttribute->Value = DataTypeString;
	xmlNode->Attributes->Append(dataTypeAttribute);

	return xmlNode;
}

//@ export handle
Makers::Computables::IComputable * Makers::Net::Computables::Computable::Export()
{
	return computable_;
}
