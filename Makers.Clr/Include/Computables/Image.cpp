#include "pch.h"
#include "Image.h"

#include "../../../../Makers.Pure/Makers.Pure/Include/Computables/Image.h"

#pragma region TODO : image generic class

generic <typename T>
long Makers::Net::Computables::Image<T>::Width::get()
{
	return -1;
}

generic <typename T>
long Makers::Net::Computables::Image<T>::Height::get()
{
	return -1;
}

generic <typename T>
System::Collections::Generic::List<T>^ Makers::Net::Computables::Image<T>::Source::get()
{
	return gcnew System::Collections::Generic::List<T>();
}

generic<typename T>
Makers::Net::Computables::Image<T>::Image(Makers::Computables::IComputable* computable) : Computable(computable)
{
	System::String^ error = "Cannot convert to Image generice instance.\n";
	
	// check source type
	if (Computable::InstanceType != eInstanceType::Image)
	{
		// TODO :
		throw gcnew System::Exception(error);
	}

	auto data_type = Computable::InstanceType;

}

generic <typename T>
Makers::Net::Computables::Image<T>::~Image()
{
	throw gcnew System::NotImplementedException();
}

generic <typename T>
Makers::Net::Computables::Image<T>::!Image()
{
	throw gcnew System::NotImplementedException();
}

generic <typename T>
void Makers::Net::Computables::Image<T>::SetImage(System::Collections::Generic::List<T>^ image, long width, long height)
{
	throw gcnew System::NotImplementedException();
}

#pragma endregion

long Makers::Net::Computables::ImageFloat::Width::get()
{
	auto floats = dynamic_cast<Makers::Computables::Image<float>*>(computable_);
	if (floats == nullptr) return 0;
	return floats->width();
}

long Makers::Net::Computables::ImageFloat::Height::get()
{
	auto floats = dynamic_cast<Makers::Computables::Image<float>*>(computable_);
	if (floats == nullptr) return 0;
	return floats->height();
}

System::Collections::Generic::List<float>^ Makers::Net::Computables::ImageFloat::Image::get()
{
	auto list = gcnew System::Collections::Generic::List<float>();

	auto floats = dynamic_cast<Makers::Computables::Image<float>*>(computable_);
	if (floats == nullptr) return list;

	auto image = floats->image();
	auto width = floats->width();
	auto height = floats->height();
	for (long y = 0; y < height; ++y)
	{
		for (long x = 0; x < width; ++x)
		{
			long index = y * width + x;
			list->Add(image[index]);
		}
	}

	return list;
}

Makers::Net::Computables::ImageFloat::ImageFloat(Makers::Computables::IComputable * computable) :
	Computable(computable)
{
}

Makers::Net::Computables::ImageFloat::~ImageFloat()
{
}

Makers::Net::Computables::ImageFloat::!ImageFloat()
{
}

void Makers::Net::Computables::ImageFloat::SetImage(
	System::Collections::Generic::List<float>^ image, 
	long width, 
	long height)
{
	auto floats = dynamic_cast<Makers::Computables::Image<float>*>(computable_);
	if (floats == nullptr) return;

	float* float_image = new float[width * height];
	for (long y = 0; y < height; ++y)
	{
		for (long x = 0; x < width; ++x)
		{
			long index = y * width + x;
			float_image[index] = image[index];
		}
	}

	floats->set_image(float_image, width, height);
	delete float_image;
}

long Makers::Net::Computables::ImageByte::Width::get()
{
	auto chars = dynamic_cast<Makers::Computables::Image<unsigned char>*>(computable_);
	if (chars == nullptr) return 0;
	return chars->width();
}

long Makers::Net::Computables::ImageByte::Height::get()
{
	auto chars = dynamic_cast<Makers::Computables::Image<unsigned char>*>(computable_);
	if (chars == nullptr) return 0;
	return chars->height();
}

System::Collections::Generic::List<unsigned char>^ Makers::Net::Computables::ImageByte::Image::get()
{
	auto list = gcnew System::Collections::Generic::List<unsigned char>();

	auto chars = dynamic_cast<Makers::Computables::Image<unsigned char>*>(computable_);
	if (chars == nullptr) return list;

	auto image = chars->image();
	auto width = chars->width();
	auto height = chars->height();
	for (long y = 0; y < height; ++y)
	{
		for (long x = 0; x < width; ++x)
		{
			long index = y * width + x;
			list->Add(image[index]);
		}
	}

	return list;
}

Makers::Net::Computables::ImageByte::ImageByte(Makers::Computables::IComputable * computable) :
	Computable(computable)
{
}

Makers::Net::Computables::ImageByte::~ImageByte()
{
}

Makers::Net::Computables::ImageByte::!ImageByte()
{
}

void Makers::Net::Computables::ImageByte::SetImage(
	System::Collections::Generic::List<unsigned char>^ image,
	long width,
	long height)
{
	auto chars = dynamic_cast<Makers::Computables::Image<unsigned char>*>(computable_);
	if (chars == nullptr) return;

	unsigned char* char_image = new unsigned char[width * height];
	for (long y = 0; y < height; ++y)
	{
		for (long x = 0; x < width; ++x)
		{
			long index = y * width + x;
			char_image[index] = image[index];
		}
	}

	chars->set_image(char_image, width, height);
	delete char_image;
}
