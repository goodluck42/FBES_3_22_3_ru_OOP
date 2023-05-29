#include<iostream>

//Цеализуйте класс item :
//-пол§ : name, price;
//-значение полей должен вводить пользователь;
//-реализуйте возможность получить количество товаров, которые есть в программе;
//-реализуйте метод, который печатает название, цену и количество товаров.


class Item
{
public:

	~Item()
	{
		delete[] name;
		--count;
	}

	Item()
	{
		name = nullptr;
		price = 0;
		count++;
	}

	Item(int price, const char* name)
	{
		this->price = price;
		this->name = new char[32];
		count++;

		strcpy_s(this->name, 32, name);
	}
private:
	char* name;
	int price;
	static int count;
public:
	static int get_count()
	{
		return count;
	}

	void print()
	{
		std::cout << "Name: " << name << '\n';
		std::cout << "Price: " << price << '\n';
		std::cout << "Count: " << count << '\n';
	}

};

int Item::count = 0;

int main()
{
	Item item{ 20, "Test" };
	Item item2{ 20, "Test2" };


	item.print();
	item2.print();
}