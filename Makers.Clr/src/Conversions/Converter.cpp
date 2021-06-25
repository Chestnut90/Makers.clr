#pragma once
#include "pch.h"
#include "Converter.h"

// marshals
#include <msclr/marshal.h>
#include <msclr/marshal_atl.h>

using Marshal_ = System::Runtime::InteropServices::Marshal;

//@ convert to CString
//CString Conversion::ConvertCString(System::String^ _string)
//{
//	msclr::interop::marshal_context context;
//	return context.marshal_as<CString>(_string);
//}

void Conversion::ConvertString(System::String^ _source, std::string& _target)
{
	const char* chars = (const char*)(Marshal_::StringToHGlobalAnsi(_source)).ToPointer();
	_target = chars;
	Marshal_::FreeHGlobal(System::IntPtr((void*)chars));
}

//return msclr::interop::marshal_as<std::string>(string);

std::string& Conversion::ConvertString(System::String^ string)
{


	//return std::string(CT2CA(ConvertCString(string)));
	//return msclr::interop::marshal_as<std::string>(string);
	const char* chars = (const char*)(Marshal_::StringToHGlobalAnsi(string)).ToPointer();
	std::string result(chars);
	Marshal_::FreeHGlobal(System::IntPtr((void*)chars));
	return result;
	//msclr::interop::marshal_context context;
	//return context.marshal_as<std::string>(string);
}

/*std::wstring ConvertString(System::String^ string)
{
	return L"d";
}*/

System::String^ Conversion::ConvertString(std::string string)
{
	return gcnew System::String(string.c_str());
}