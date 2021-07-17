#include "pch.h"
#include "CTemplate.h"

#include <iostream>
#include <string>
#include <typeinfo>

template<typename T>
Test::CTemaplate<T>::CTemaplate()
{
}

template<typename T>
Test::CTemaplate<T>::~CTemaplate()
{
}

template<typename T>
void Test::CTemaplate<T>::Do()
{
	std::string line = "CTemplate class\n";

	if (typeid(T) == typeid(bool))
	{
		line += "Bool";
	}
	if (typeid(T) == typeid(int))
	{
		line += "Int";
	}

	std::cout << line << std::endl;

}
