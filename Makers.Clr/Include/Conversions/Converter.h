#pragma once

#include <iostream>
#include <string>

namespace Conversion
{
	class Strings
	{
	public:

		//@ string converter
		//@ standard to system
		static System::String^ ToString(std::string);

		//@ string converter
		//@ system to standard
		static std::string ToString(System::String^);

	private:

		//@ standard string convert helper
		//@ arg1 : system::String^
		//@ arg2 : reference of standard string
		static void _standard_convert_helper(System::String^, std::string&);

	};

	void ConvertString(System::String^, std::string&);
	System::String^ ConvertString(std::string string);

}
