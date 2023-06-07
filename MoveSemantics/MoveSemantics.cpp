#include <iostream>

class Str
{
	char* m_data;
	size_t m_len;
	size_t m_capacity;
public:
	~Str()
	{
		std::cout << "~Str()\n";
		delete[] m_data;
	}
	Str() : m_capacity(32), m_len(0)
	{
		m_data = new char[m_capacity] {};
	}

	Str(const char* a_data)
	{
		std::cout << "Str(const char* a_data)\n";
		size_t len = strlen(a_data) + 1;

		m_capacity = len * 1.5;
		m_data = new char[m_capacity];
		m_len = len - 1;
		std::memcpy(m_data, a_data, len);
	}
	Str(const Str& that)
	{
		std::cout << "Str(const Str& that)\n";
		m_data = new char[that.m_capacity];

		std::memcpy(m_data, that.m_data, that.m_capacity);

		m_len = that.m_len;
		m_capacity = that.m_capacity;
	}

	Str(Str&& that)
	{
		std::cout << "Str(Str&& that)\n";

		m_data = that.m_data;
		m_capacity = that.m_capacity;
		m_len = that.m_len;

		that.m_data = nullptr;
		that.m_capacity = 0;
		that.m_len = 0;
	}

	char* data()
	{
		return m_data;
	}

	size_t len()
	{
		return m_len;
	}

	Str& operator=(const Str& that)
	{
		std::cout << "operator=(const Str& that)\n";

		if (this != &that)
		{
			this->~Str();

			m_data = new char[that.m_capacity];

			std::memcpy(m_data, that.m_data, that.m_capacity);

			m_len = that.m_len;
			m_capacity = that.m_capacity;
		}

		return *this;
	}
	Str& operator=(Str&& that)
	{
		std::cout << "operator=(Str&& that)\n";
		if (this != &that)
		{
			this->~Str();

			m_data = that.m_data;
			m_capacity = that.m_capacity;
			m_len = that.m_len;

			that.m_data = nullptr;
			that.m_capacity = 0;
			that.m_len = 0;
		}

		return *this;
	}
};

class A
{
public:
	A() = default;
	A(const A&) = default;
	A(A&&) = default;

	A& operator=(const A&) = default;
	A& operator=(A&&) = default;
};

int main()
{
	/*Str str1 = "Hello";

	Str str2{ str1 };

	std::cout << str2.data();*/


	// RValue
	// LValue
	Str str1{ "First string" };
	Str str2{ str1 };
	Str str3{ std::move(str1) };
	Str str_target{ "Target string" };

	str2 = str_target;
	str3 = std::move(str2);


	//std::cout << str1.data();
	//std::cout << str1.data();


	//Str str2{ std::move(str1) }; // Str -> Str&&


	std::cout << "-----------\n";
}