#include <iostream>
#include <functional>

template<typename K, typename V>
class HashTable
{
private:
	std::hash<K> hash;
public:
	V& operator[](const K& key)
	{
		std::cout << hash(key) % 64;

		return 0;
	}
};

#include <map>
int main()
{
	std::hash<std::string> hash_fn;
	int buckets = 5;

	auto hash = hash_fn("Vika") % buckets;

	std::cout << hash;

	/*std::map<std::string, int> map;

	map["Alex"] = 42;
	map["John"] = 90;
	map["Sabina"] = 10;
	map["Javid"] = 40;

	std::cout << map["Alex"] << '\n';
	std::cout << map["John"] << '\n';*/

	//HashTable<std::string, int> table;

	//table["John"] = 90; // 90

	/*

	std::string name = "John";

	auto h1 = hash(name);

	std::cout << h1;*/
}