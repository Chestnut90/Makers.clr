#include "pch.h"
#include "Real.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/Real.h"

#pragma region TODO : generic real

generic<typename T>
Makers::Net::Computables::Real<T>::Real() : Computable(nullptr)
{
	throw gcnew System::NotImplementedException();
}

generic<typename T>
Makers::Net::Computables::Real<T>::~Real()
{
	throw gcnew System::NotImplementedException();
}

generic<typename T>
Makers::Net::Computables::Real<T>::!Real()
{
	throw gcnew System::NotImplementedException();
}

generic<typename T>
Makers::Net::Computables::Real<T>::Real(Makers::Computables::IComputable * real) : Computable(real)
{
	throw gcnew System::NotImplementedException();
}

#pragma endregion

#pragma region Real Float

float Makers::Net::Computables::RealFloat::Value::get()
{
	auto floats = dynamic_cast<Makers::Computables::Real<float>*>(computable_);
	if (floats == nullptr) return 0;
	return floats->value();
}

void Makers::Net::Computables::RealFloat::Value::set(float value)
{
	auto floats = dynamic_cast<Makers::Computables::Real<float>*>(computable_);
	if (floats == nullptr) return;
	floats->set_value(value);
}

Makers::Net::Computables::RealFloat::RealFloat(Makers::Computables::IComputable* computable) :
	Computable(computable)
{
}

Makers::Net::Computables::RealFloat::~RealFloat()
{
}

Makers::Net::Computables::RealFloat::!RealFloat()
{
}

void Makers::Net::Computables::RealFloat::LoadFromXml(System::Xml::XmlNode ^ xmlNode)
{
	Computable::LoadFromXml(xmlNode);

	// set value
	float value;
	bool try_get_value = System::Single::TryParse(xmlNode->Attributes["Value"]->Value, value);
	Value = try_get_value ? value : 0.f;

}

System::Xml::XmlNode ^ Makers::Net::Computables::RealFloat::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = Computable::ToXml(xmlDocument);

	// set value
	auto valueAttribute = xmlDocument->CreateAttribute("Value");
	valueAttribute->Value = Value.ToString();
	xmlNode->Attributes->Append(valueAttribute);

	return xmlNode;
}

#pragma endregion
#pragma region Real Int

int Makers::Net::Computables::RealInt::Value::get()
{
	auto ints = dynamic_cast<Makers::Computables::Real<int>*>(computable_);
	if (ints == nullptr) return 0;
	return ints->value();
}

void Makers::Net::Computables::RealInt::Value::set(int value)
{
	auto ints = dynamic_cast<Makers::Computables::Real<int>*>(computable_);
	if (ints == nullptr) return;
	ints->set_value(value);
}

Makers::Net::Computables::RealInt::RealInt(Makers::Computables::IComputable* computable) :
	Computable(computable)
{
}

Makers::Net::Computables::RealInt::~RealInt()
{
}

Makers::Net::Computables::RealInt::!RealInt()
{
}

void Makers::Net::Computables::RealInt::LoadFromXml(System::Xml::XmlNode ^ xmlNode)
{
	Computable::LoadFromXml(xmlNode);

	// set value
	int value;
	bool try_get_value = System::Int32::TryParse(xmlNode->Attributes["Value"]->Value, value);
	Value = try_get_value ? value : 0;
}

System::Xml::XmlNode ^ Makers::Net::Computables::RealInt::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = Computable::ToXml(xmlDocument);

	// set value
	auto valueAttribute = xmlDocument->CreateAttribute("Value");
	valueAttribute->Value = Value.ToString();
	xmlNode->Attributes->Append(valueAttribute);

	return xmlNode;
}

#pragma endregion
#pragma region Real long

long Makers::Net::Computables::RealLong::Value::get()
{
	auto longs = dynamic_cast<Makers::Computables::Real<long>*>(computable_);
	if (longs == nullptr) return 0;
	return longs->value();
}

void Makers::Net::Computables::RealLong::Value::set(long value)
{
	auto longs = dynamic_cast<Makers::Computables::Real<long>*>(computable_);
	if (longs == nullptr) return;
	longs->set_value(value);
}

Makers::Net::Computables::RealLong::RealLong(Makers::Computables::IComputable* computable) :
	Computable(computable)
{
}

Makers::Net::Computables::RealLong::~RealLong()
{
}

Makers::Net::Computables::RealLong::!RealLong()
{
}

void Makers::Net::Computables::RealLong::LoadFromXml(System::Xml::XmlNode ^ xmlNode)
{
	Computable::LoadFromXml(xmlNode);

	// set value
	long long value;
	bool try_get_value = System::Int64::TryParse(xmlNode->Attributes["Value"]->Value, value);
	Value = try_get_value ? (long)value : 0;
}

System::Xml::XmlNode ^ Makers::Net::Computables::RealLong::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = Computable::ToXml(xmlDocument);

	// set value
	auto valueAttribute = xmlDocument->CreateAttribute("Value");
	valueAttribute->Value = Value.ToString();
	xmlNode->Attributes->Append(valueAttribute);

	return xmlNode;
}

#pragma endregion
#pragma region Real bool

bool Makers::Net::Computables::RealBool::Value::get()
{
	auto bools = dynamic_cast<Makers::Computables::Real<bool>*>(computable_);
	if (bools == nullptr) return 0;
	return bools->value();
}

void Makers::Net::Computables::RealBool::Value::set(bool value)
{
	auto bools = dynamic_cast<Makers::Computables::Real<bool>*>(computable_);
	if (bools == nullptr) return;
	bools->set_value(value);
}

Makers::Net::Computables::RealBool::RealBool(Makers::Computables::IComputable* computable) :
	Computable(computable)
{
}

Makers::Net::Computables::RealBool::~RealBool()
{
}

Makers::Net::Computables::RealBool::!RealBool()
{
}

void Makers::Net::Computables::RealBool::LoadFromXml(System::Xml::XmlNode ^ xmlNode)
{
	Computable::LoadFromXml(xmlNode);

	// set value
	bool value;
	bool try_get_value = System::Boolean::TryParse(xmlNode->Attributes["Value"]->Value, value);
	Value = try_get_value ? value : true;
}

System::Xml::XmlNode ^ Makers::Net::Computables::RealBool::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = Computable::ToXml(xmlDocument);

	// set value
	auto valueAttribute = xmlDocument->CreateAttribute("Value");
	valueAttribute->Value = Value.ToString();
	xmlNode->Attributes->Append(valueAttribute);

	return xmlNode;
}

#pragma endregion