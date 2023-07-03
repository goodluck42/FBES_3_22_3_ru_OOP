#include <iostream>
#include "LinkedList.h"

int main()
{
	while (true)
	{
		LinkedList<int> list;

		list.push_back(60);
		list.push_back(6);
		list.push_back(102);
		list.push_back(42);
		list.push_back(7);
	}
	

	//std::cout << list.m_head->next->next->value;

	std::cout << 0;
}