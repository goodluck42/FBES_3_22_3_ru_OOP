#include <iostream>
#include <fstream>

class Number
{
	friend std::ostream& operator<<(std::ostream& os, const Number& num); // cout
	friend std::istream& operator>>(std::istream& is, Number& num); // cin
private:
	int m_value;
public:
	Number() : m_value(0) {}
	Number(int a_value) : m_value(a_value)
	{
		std::cout << "object created\n";
	}

	int get()
	{
		return m_value;
	}

	Number operator+()
	{
		return Number{ m_value };
	}

	Number operator+(const Number& rhs)
	{
		// this->m_value - left operand
		// rhs.m_value - right operand
		int sum = this->m_value + rhs.m_value;

		Number result{ sum };

		return result;
	}

	Number& operator+=(const Number& rhs)
	{
		m_value += rhs.m_value;

		return *this;
	}

	Number operator-()
	{
		return Number{ -m_value };
	}

	Number operator%(const Number& rhs)
	{
		return Number{ m_value % rhs.m_value };
	}

	Number& operator++() // prefix
	{
		m_value += 1;

		return *this;
	}

	Number operator++(int) // postfix
	{
		Number copy{ *this };

		m_value += 1;

		return copy;
	}

	bool operator>(const Number& rhs)
	{
		return m_value > rhs.m_value;
	}


};

class String
{
private:
	char m_data[32];
public:
	String(const char* text)
	{
		strcpy_s(m_data, 32, text);
	}

	char& operator[](int index)
	{
		return m_data[index];
	}
};


std::ostream& operator<<(std::ostream& os, const Number& num)
{
	os << "num = " << num.m_value;

	return os;
}

std::istream& operator>>(std::istream& is, Number& num)
{
	is >> num.m_value;

	return is;
}


int main()
{
	{
		String mystr = "Hello world";

		// char& ref = mystr[0];

		//ref = '@';

		mystr[0] = '@';

		std::cout << mystr << '\n';
	}

	/*{
		Number n1 = 42;
		Number n2 = 13;

		if (n1 > n2)
		{
			std::cout << "n1 is greater";
		}
	}*/

	/*{
		Number n1 = 42;

		std::cout << n1++ << '\n';
		std::cout << ++n1 << '\n';


	}*/

	//{
	//	int a = 10;
	//	int b = 42;

	//	// a += b;

	//	std::cout << &(a += b) << '\n';
	//	std::cout << &a << '\n';
	//	std::cout << "----------------" << '\n';
	//}
	/*{
		Number n1 = 42;
		Number n2 = 10;

		std::cout << (n1 += n2) << '\n';
		std::cout << n1 << '\n';
		
		std::cout << &(n1 += n2) << '\n';
		std::cout << &n1 << '\n';
	}*/


	/*{
		Number n1 = 90;
		Number n2 = 42;
		Number n3 = 10;

		Number nr = n1 + n2 + n3;


		std::cout << nr;
	}*/

	/*{
		Number nx;

		std::cout << "enter number -> ";
		std::cin >> nx;

		std::cout << nx << '\n';
	}*/




	/*int a = 90;
	int b = 42;

	int c = a + b;

	std::cout << c << '\n';

	std::cout << a  << '\n';
	std::cout << b  << '\n';*/

}


