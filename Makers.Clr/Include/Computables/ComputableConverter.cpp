#include "pch.h"
#include "ComputableConverter.h"

// pure instance
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/IComputable.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/Image.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/Real.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/ROI.h"
#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/Enum.h"

// ref class
#include "Computable.h"
#include "Image.h"
#include "Real.h"
#include "ROI.h"
#include "Enum.h"


Makers::Net::Computables::Computable ^ Makers::Net::Computables::ComputableConverter::Cast(Makers::Computables::IComputable * computable)
{
	if (computable == nullptr)
	{
		throw gcnew System::Exception("Error Occured in Casting Computable. object is null.");
	}

#pragma region Image

	// image float
	auto image_float = dynamic_cast<Makers::Computables::Image<float>*>(computable);
	if (image_float != nullptr)
	{
		return gcnew Makers::Net::Computables::ImageFloat(computable);
	}

	// image byte
	auto image_byte = dynamic_cast<Makers::Computables::Image<unsigned char>*>(computable);
	if (image_byte != nullptr)
	{
		return gcnew Makers::Net::Computables::ImageByte(computable);
	}

#pragma endregion

#pragma region Real

	// real float
	auto real_float = dynamic_cast<Makers::Computables::Real<float>*>(computable);
	if (real_float != nullptr)
	{
		return gcnew Makers::Net::Computables::RealFloat(computable);
	}

	// real int
	auto real_int = dynamic_cast<Makers::Computables::Real<int>*>(computable);
	if (real_int != nullptr)
	{
		return gcnew Makers::Net::Computables::RealInt(computable);
	}

	// real long
	auto real_long = dynamic_cast<Makers::Computables::Real<long>*>(computable);
	if (real_long != nullptr)
	{
		return gcnew Makers::Net::Computables::RealLong(computable);
	}

	// real bool
	auto real_bool = dynamic_cast<Makers::Computables::Real<bool>*>(computable);
	if (real_bool != nullptr)
	{
		return gcnew Makers::Net::Computables::RealBool(computable);
	}

#pragma endregion
#pragma region ROI

	// roi
	auto roi = dynamic_cast<Makers::Computables::ROI*>(computable);
	if (roi != nullptr)
	{
		return gcnew Makers::Net::Computables::ROIs(computable);
	}

#pragma endregion

#pragma region Enum
	auto enum_object = dynamic_cast<Makers::Computables::Enum*>(computable);
	if (enum_object != nullptr)
	{
		return gcnew Makers::Net::Computables::Enum(computable);
	}

#pragma endregion

	throw gcnew System::Exception("Error Occured in Computable converting");
}
