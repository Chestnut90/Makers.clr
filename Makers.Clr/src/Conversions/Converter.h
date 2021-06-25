#pragma once

#include <iostream>
#include <string>

namespace Conversion
{
	//CString ConvertCString(System::String^);

	void ConvertString(System::String^, std::string&);

	std::string& ConvertString(System::String^ string);

	System::String^ ConvertString(std::string string);

}
