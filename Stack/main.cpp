#include <iostream>
#include <functional>
#include <vector>


class Foo
{
public:
	Foo()
	{

	}
	Foo(const Foo&)
	{
		std::cout << "Foo(const Foo&)" << '\n';
	}

	Foo(Foo&&) noexcept
	{
		std::cout << "Foo(Foo&&)" << '\n';
	}

	Foo& operator=(const Foo&)
	{
		std::cout << "operator=(const Foo&)" << '\n';
	}
	
	Foo& operator=(Foo&&) noexcept
	{
		std::cout << "operator=(Foo&&)" << '\n';
	}
};

template<typename T>
void foo(T&& v)
{
	std::cout << "void foo(T&& v)" << '\n';
	
}

template<typename T>
void foo(const T& v)
{
	std::cout << "void foo(const T& v)" << '\n';
	foo(std::forward<T>(v));
}
enum class open_braces
{
	BRACE = '(',
	SQUARE_BRACKET = '['
};
int main()
{
	Foo sample;

	foo(sample);
}