#include <iostream>
#include <string>
#include <cstdlib>

class Str
{
	char* m_data;
	size_t m_len;
	size_t m_capacity;
public:
	~Str()
	{
		delete[] m_data;
	}
	Str() : m_capacity(32), m_len(0)
	{
		m_data = new char[m_capacity] {};
	}

	void append(const char* a_str)
	{
		size_t len = strlen(a_str);

		if (len > m_capacity)
		{
			normalize_capacity(len + 1);
		}

		for (size_t i = 0; i < len; ++i)
		{
			m_data[m_len + i] = a_str[i];
		}
	}
	char* data()
	{
		return m_data;
	}
private:
	void normalize_capacity(size_t a_capacity)
	{
		char* buffer = new char[a_capacity] {};

		strcpy_s(buffer, a_capacity, m_data);

		delete[] m_data;

		m_data = buffer;
		m_capacity = a_capacity;
	}
};


int main()
{
	Str str1;

	str1.append("helloy ");
	str1.append("world");


	std::cout << str1.data();



	/*int* arr = new int[5] { 1, 2, 3, 4, 5 };
	int* arr2 = new int[5] {};

	memcpy_s(arr2, sizeof(int) * 5, arr, sizeof(int) * 5);

	std::cout << arr2[0] << '\n';
	std::cout << arr2[1] << '\n';
	std::cout << arr2[2] << '\n';

	char* buffer = new char[32];

	const char* text = "hello world ";

	strcpy_s(buffer, 32, text);

	std::cout << buffer << '\n';

	strcpy_s(buffer + strlen(text), 32, "goodbye");

	std::cout << buffer << '\n';*/


	// "hello woRLd." -> "Hello world."
	// 
}