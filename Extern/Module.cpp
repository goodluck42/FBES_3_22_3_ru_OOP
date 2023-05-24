#include "Global.h"
#include <iostream>

void show_address()
{
	std::cout << "Module.cpp: " << &global_value << '\n';
}