#include "pch.h"
#include "Surf.h"

#include "SurfIOException.h"

// pure
#include "../../../../Makers.Pure/Makers.Pure/Include/nxSurfs/Surf.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/nxSurfs/SurfIOException.h"

// conversion
#include "../Conversions/Converter.h"

using String_ = Conversion::Strings;

#pragma region Properties
//@ get width
long nXSDK::Net::Surf::Width::get()
{
	return surf_->width();
}
//@ get height
long nXSDK::Net::Surf::Height::get()
{
	return surf_->height();
}
//@ get float
System::Collections::Generic::List<float>^ nXSDK::Net::Surf::Zmap::get()
{
	auto zmap = gcnew System::Collections::Generic::List<float>();

	long size = surf_->width() * surf_->height();
	for (long i = 0; i < size; ++i)
	{
		zmap->Add(surf_->zmap()[i]);
	}

	return zmap;
}
//@ get mask
System::Collections::Generic::List<byte>^ nXSDK::Net::Surf::Mask::get()
{
	return _ToByteList(surf_->mask());
}
//@ get gray
System::Collections::Generic::List<byte>^ nXSDK::Net::Surf::Gray::get()
{
	return _ToByteList(surf_->gray());
}
//@ get red
System::Collections::Generic::List<byte>^ nXSDK::Net::Surf::Red::get()
{
	return _ToByteList(surf_->red());
}
//@ get green
System::Collections::Generic::List<byte>^ nXSDK::Net::Surf::Green::get()
{
	return _ToByteList(surf_->green());
}
//@ get blue
System::Collections::Generic::List<byte>^ nXSDK::Net::Surf::Blue::get()
{
	return _ToByteList(surf_->blue());
}

#pragma endregion
#pragma region ctors
//@ constructor
nXSDK::Net::Surf::Surf()
{
	surf_ = new nXSDK::Surf();
}
//@ destructor
nXSDK::Net::Surf::~Surf()
{
	if (!is_use_handle_)
	{
		delete surf_;
		surf_ = nullptr;
	}
}
//@ finalizer
nXSDK::Net::Surf::!Surf()
{

}

//@ constructor
//@ internal with nXSDK::Surf pointer
nXSDK::Net::Surf::Surf(nXSDK::Surf& surf)
{
	is_use_handle_ = true;
	surf_ = &surf;
}

#pragma endregion


//@ cpp byte array to csharp list byte
System::Collections::Generic::List<byte>^ nXSDK::Net::Surf::_ToByteList(byte * source)
{
	auto arr = gcnew System::Collections::Generic::List<byte>();

	long size = surf_->width() * surf_->height();
	for (long i = 0; i < size; ++i)
	{
		arr->Add(source[i]);
	}
	return arr;
}

bool nXSDK::Net::Surf::Save(System::String ^ filename)
{
	std::string std_filename = String_::ToString(filename);
	return surf_->Save(std_filename);
}

bool nXSDK::Net::Surf::Save(nXSDK::Net::Surf ^ surf, System::String ^ filename)
{
	return surf->Save(filename);
}

void nXSDK::Net::Surf::Load(System::String ^ filename)
{
	auto std_filename = String_::ToString(filename);
	try
	{
		surf_->Load(std_filename);
	}
	catch (const nXSDK::SurfIOException& ioException)
	{
		auto std_error = std::string(ioException.what());
		throw gcnew nXSDK::Net::SurfIOException(String_::ToString(std_error));
	}
}

nXSDK::Net::Surf ^ nXSDK::Net::Surf::Open(System::String ^ filename)
{
	auto surf = gcnew nXSDK::Net::Surf();
	surf->Load(filename);
	return surf;
}
