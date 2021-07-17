#include "pch.h"
#include "PropertyException.h"

#include "PropertyBase.h"

Makers::Net::Properties::PropertyException::PropertyException() :
	System::Exception()
{

}

Makers::Net::Properties::PropertyException::PropertyException(System::String ^ message) :
	System::Exception(message)
{
}

Makers::Net::Properties::PropertyException::~PropertyException()
{
}

Makers::Net::Properties::PropertyException::!PropertyException()
{
}
