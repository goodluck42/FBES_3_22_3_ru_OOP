#include <iostream>
#include "LinkedList.h"

int main()
{
	while (true)
	{
		LinkedList<int> list;

		list.insert(60);
		list.insert(6);
		list.insert(102);
		list.insert(42);
		list.insert(7);
	}
	

	//std::cout << list.m_head->next->next->value;

	std::cout << 0;
}