#include <iostream>
#include "Array.h"

class A
{
private:
	int* m_data;
public:
	A(const A& that)
	{
		m_data = new int[120];

		
	}
};

void b();
void c();


void a()
{
	b();
	std::cout << "a" << '\n';
}

void b() 
{
	std::cout << "b" << '\n';
	c();
}

void c() noexcept
{
	throw 0;
}


int main()
{
	Array<int> arr{ 10, 20, 30, 42, 50 };

	/*try
	{
		std::cout << arr.at(-5);
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what();
	}
	catch (negative_index_error& ex)
	{
		std::cout << ex.what();
	}*/

	/*try
	{
		std::cout << arr.at(-5);
	}
	catch (...)
	{
		std::cout << "Error" << '\n';
	}*/

	try
	{
		a();
	}
	catch (int)
	{
		std::cout << "caught" << '\n';
	}

	
}