#pragma once

#include <iostream>

namespace Utils
{
	template<typename Base, typename T>
	bool InstanceOf(const T*)
	{
		return std::is_base_of<Base, T>::value;
	}
}
