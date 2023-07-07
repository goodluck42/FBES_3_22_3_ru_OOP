#include <iostream>
#include <functional>


template<typename K, typename V>
class HashTable
{
private:
	std::hash<K> hash;
public:
	V operator[](const K& key)
	{
		std::cout << hash(key) % 64;

		return 0;
	}
};


int main()
{
	HashTable<std::string, int> table;

	table["John"]; // 90

	/*

	std::string name = "John";

	auto h1 = hash(name);

	std::cout << h1;*/
}