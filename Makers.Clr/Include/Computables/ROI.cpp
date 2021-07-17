#include "pch.h"
#include "ROI.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/ROI.h"

//@ get roi left
long Makers::Net::Computables::ROIs::Left::get()
{
	auto roi = dynamic_cast<Makers::Computables::ROI*>(computable_);
	if (roi == nullptr) return 0;

	return roi->left();
}

//@ get roi right
long Makers::Net::Computables::ROIs::Right::get()
{
	auto roi = dynamic_cast<Makers::Computables::ROI*>(computable_);
	if (roi == nullptr) return 0;

	return roi->right();
}

//@ get roi top
long Makers::Net::Computables::ROIs::Top::get()
{
	auto roi = dynamic_cast<Makers::Computables::ROI*>(computable_);
	if (roi == nullptr) return 0;

	return roi->top();
}

//@ get roi bottom
long Makers::Net::Computables::ROIs::Bottom::get()
{
	auto roi = dynamic_cast<Makers::Computables::ROI*>(computable_);
	if (roi == nullptr) return 0;

	return roi->bottom();
}

//@ Constructor
Makers::Net::Computables::ROIs::ROIs(Makers::Computables::IComputable * computable) :
	Computable(computable)
{
}

//@ Destructor
Makers::Net::Computables::ROIs::~ROIs()
{
}

//@ Finalizer
Makers::Net::Computables::ROIs::!ROIs()
{
}

//@ Set ROI
void Makers::Net::Computables::ROIs::SetROI(long left, long top, long right, long bottom)
{
	auto roi = dynamic_cast<Makers::Computables::ROI*>(computable_);
	if (roi == nullptr) 
	{
		throw gcnew System::Exception("Cannot convert to ROI instance.\n");
	}

	roi->set_roi(left, top, right, bottom);
}

void Makers::Net::Computables::ROIs::LoadFromXml(System::Xml::XmlNode ^ xmlNode)
{
	Computable::LoadFromXml(xmlNode);

	long long left = 0;
	System::Int64::TryParse(xmlNode->Attributes["Left"]->Value, left);

	long long top = 0;
	System::Int64::TryParse(xmlNode->Attributes["Left"]->Value, top);

	long long right = 0;
	System::Int64::TryParse(xmlNode->Attributes["Left"]->Value, right);

	long long bottom = 0;
	System::Int64::TryParse(xmlNode->Attributes["Left"]->Value, bottom);

	SetROI((long)left, (long)top, (long)right, (long)bottom);
}

System::Xml::XmlNode ^ Makers::Net::Computables::ROIs::ToXml(System::Xml::XmlDocument ^ xmlDocument)
{
	auto xmlNode = Computable::ToXml(xmlDocument);

	// set left 
	auto leftAttribute = xmlDocument->CreateAttribute("Left");
	leftAttribute->Value = Left.ToString();
	xmlNode->Attributes->Append(leftAttribute);
	// set top 
	auto topAttribute = xmlDocument->CreateAttribute("Top");
	topAttribute->Value = Top.ToString();
	xmlNode->Attributes->Append(topAttribute);
	// set right 
	auto rightAttribute = xmlDocument->CreateAttribute("Right");
	rightAttribute->Value = Right.ToString();
	xmlNode->Attributes->Append(rightAttribute);
	// set left top right bottom
	auto bottomAttribute = xmlDocument->CreateAttribute("Bottom");
	bottomAttribute->Value = Bottom.ToString();
	xmlNode->Attributes->Append(bottomAttribute);

	return xmlNode;
}
