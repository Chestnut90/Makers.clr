#pragma once
#include "pch.h"
#include "Converter.h"

// marshals
#include <msclr/marshal.h>
#include <msclr/marshal_atl.h>

using Marshal_ = System::Runtime::InteropServices::Marshal;

#pragma region temp

//@ convert to CString
//CString Conversion::ConvertCString(System::String^ _string)
//{
//	msclr::interop::marshal_context context;
//	return context.marshal_as<CString>(_string);
//}

//std::string& Conversion::ConvertString(System::String^ string)
//{
//
//
//	//return std::string(CT2CA(ConvertCString(string)));
//	//return msclr::interop::marshal_as<std::string>(string);
//	const char* chars = (const char*)(Marshal_::StringToHGlobalAnsi(string)).ToPointer();
//	std::string result(chars);
//	Marshal_::FreeHGlobal(System::IntPtr((void*)chars));
//	return result;
//	//msclr::interop::marshal_context context;
//	//return context.marshal_as<std::string>(string);
//}
//
/*std::wstring ConvertString(System::String^ string)
{
	return L"d";
}*/


#pragma endregion

//@ deprecated
void Conversion::ConvertString(System::String^ _source, std::string& _target)
{
	const char* chars = (const char*)(Marshal_::StringToHGlobalAnsi(_source)).ToPointer();
	_target = chars;
	Marshal_::FreeHGlobal(System::IntPtr((void*)chars));
}

//@ deprecated
System::String^ Conversion::ConvertString(std::string string)
{
	return gcnew System::String(string.c_str());
}

System::String ^ Conversion::Strings::ToString(std::string _string)
{
	return gcnew System::String(_string.c_str());
}

std::string Conversion::Strings::ToString(System::String ^ _string)
{
	std::string _standard_string;
	_standard_convert_helper(_string, _standard_string);
	return _standard_string;
}

// TODO : check memory leaks
void Conversion::Strings::_standard_convert_helper(System::String^ _system_string, std::string& _standard_string)
{
	const char* chars = (const char*)(Marshal_::StringToHGlobalAnsi(_system_string)).ToPointer();
	_standard_string = chars;
	Marshal_::FreeHGlobal(System::IntPtr((void*)chars));
}
