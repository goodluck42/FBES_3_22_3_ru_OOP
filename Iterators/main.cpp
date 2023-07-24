#include <iostream>
#include <vector>
#include "Array.h"



int main()
{
	Array<int> arr;

	arr.append(10);
	arr.append(20);
	arr.append(30);
	arr.prepend(42);

	/*for (int i = 0; i < arr.get_size(); ++i)
	{
		std::cout << arr[i] << '\n';
	}*/

	// range based for
	for (auto& value : arr)
	{
		std::cout << value << '\n';
	}

	/*{
		ArrayIterator<int> it = arr.begin();
		ArrayIterator<int> end = arr.end();

		while (it != end)
		{
			std::cout << *it << '\n';
			++it;
		}
	}*/
}