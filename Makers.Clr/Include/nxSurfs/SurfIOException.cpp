#include "pch.h"
#include "SurfIOException.h"

nXSDK::Net::SurfIOException::SurfIOException(System::String^ error) :
	System::Exception(error)
{
}

nXSDK::Net::SurfIOException::~SurfIOException()
{
}

nXSDK::Net::SurfIOException::!SurfIOException()
{
}
