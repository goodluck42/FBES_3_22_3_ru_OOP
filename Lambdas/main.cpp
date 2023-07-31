#include <iostream>
#include <vector>
#include <algorithm>

/*class __123
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}

	std::string operator()(std::string a, std::string b)
	{
		return a + b;
	}
};*/


class Object
{
public:
	Object()
	{

	}
	Object(const Object&) = delete;
	Object(Object&&) = delete;
	int data = 42;
};


class Item
{
public:
	std::string name;
	size_t quantity;
};

int main()
{
	/*{


		//auto lambda = __123{};

		std::string debug = "Debug info";
		std::string text = "C# is incoming";
		Object o;

		auto lambda = [=, &o](auto a, auto b) -> auto
		{
			std::cout << o.data << '\n';

			std::cout << debug << '\n';
			std::cout << text << '\n';

			return a + b;
		};

		std::cout << lambda(2, 5) << '\n';
		std::cout << lambda(std::string{ "Hello " }, std::string{ "C#" }) << '\n';
	}*/


	std::vector<Item> items;

	items.push_back({"Bread", 20});
	items.push_back({"Water", 10});
	items.push_back({"Garage", 5});

	auto it = std::find_if(items.begin(), items.end(), [](Item& value)\
	{
		return value.name == "Garage";
	});

	if (it != items.end())
	{
		std::cout << it->name << '\n';
		std::cout << it->quantity << '\n';

		items.erase(it);
	}
}