#include <iostream>
#include <string>

class Mouse
{
	char* m_manufacturer;
	char* m_model;
	int m_dpi;
public:
	~Mouse()
	{
		delete[] m_manufacturer;
		delete[] m_model;

		m_manufacturer = nullptr;
		m_model = nullptr;
	}
	Mouse(const char* a_manufacturer, const char* a_model, int a_dpi) : m_dpi(a_dpi)
	{
		m_manufacturer = new char[64] {};
		m_model = new char[64] {};

		std::memcpy(m_manufacturer, a_manufacturer, strlen(a_manufacturer) * sizeof(char));
		std::memcpy(m_model, a_model, strlen(a_model) * sizeof(char));
	}

	Mouse(const Mouse& that)
	{
		m_manufacturer = new char[64] {};
		m_model = new char[64] {};
		m_dpi = that.m_dpi;

		std::memcpy(m_manufacturer, that.m_manufacturer, strlen(that.m_manufacturer) * sizeof(char));

		std::memcpy(m_model, that.m_model, strlen(that.m_model) * sizeof(char));
	}

	void print()
	{
		std::cout << "Manufacturer -> " << m_manufacturer << '\n';
		std::cout << "Model -> " << m_model << '\n';
		std::cout << "DPI -> " << m_dpi << '\n';
	}

	Mouse& operator=(Mouse&& that)
	{

		this->~Mouse();

		m_manufacturer = that.m_manufacturer;
		that.m_manufacturer = nullptr;

		m_model = that.m_model;
		that.m_model = nullptr;

		m_dpi = that.m_dpi;
		that.m_dpi = 0;
	}
};
//class Int_Array
//{
//private:
//	Int_Array(int a_old_size, int a_old_capacity)
//	{
//		m_size = a_old_size;
//		m_capacity = a_old_capacity + 32;
//	}
//public:
//	Int_Array(int a_capacity = 32)
//	{
//		m_data = new int[a_capacity];
//		size = 0;
//		m_capacity = a_capacity;
//	}
//
//	Int_Array operator+(const Int_Array& that)
//	{
//		Int_Array result{ *this };
//
//		for (int i = 0; i < that.m_len; ++i)
//		{
//			result.append(that[i]);
//		}
//
//		return result;
//		/*for ()
//		{
//			result.m_data[i]
//		}*/
//		
//	}
//};
int main()
{
	// {1, 2, 3, 4} = this;
	// {5, 6, 7, 8} = that;
	// 
	// {1, 2, 3, 4, 5, 6, 7, 8} = copy;

	/*{
		Mouse mice{ "Razer", "Basilisk", 20000 };
		Mouse copy{ "Logitech", "GPRO Wireless", 16000 };


		copy = std::move(mice);
	}*/


	/*{
		std::string str1 = "Hello";
		std::string str2 = "C++";
		std::string str3 = str1 + " " + str2;

		std::cout << str3 << '\n';
	}*/

	/*{
		std::string str1;

		str1.push_back(97);
		str1.append("pple");

		std::cout << str1 << '\n';

		std::cout << "begin => " << *(str1.begin()) << '\n';
		std::cout << "end => " << *(str1.end() - 1) << '\n';
		std::cout << "rbegin => " << *(str1.rbegin()) << '\n';
		std::cout << "rend => " << *(str1.rend() - 1) << '\n';


		str1.insert(0, "Hello ");

		std::cout << str1 << '\n';
	}*/
	/*{
		std::string str1 = u8"Hello world";

		int counter = 0;
		int offset = 0;

		while (true)
		{
			size_t new_offset = str1.find('l', offset);

			if (new_offset == std::string::npos)
			{
				break;
			}

			if (counter == 1)
			{
				std::cout << "offset of " << counter + 1 << " l -> " << new_offset << '\n';

				break;
			}

			offset = new_offset + 1;

			++counter;
		}

		std::cout << "index of first l -> " << str1.find('l', 0) << '\n';
		std::cout << "index of last l -> " << str1.rfind('l', str1.length()) << '\n';
		std::cout << "index of world -> " << str1.find("world", 0) << '\n';

		std::cout << str1.length() << '\n';
		std::cout << str1.size() << '\n';

		std::cout << "sizeof(std::string) = " << sizeof(std::string) << '\n';
	}*/

	// copy
	/* {
		std::string s1 = "Hello world!";
		std::string s2 = std::move(s1);

		std::cout << "capacity -> " << s2.capacity() << '\n';
		//std::cout << s2[12] << '\n';
		//std::cout << s2.at(12) << '\n';

		//s2.clear();

		size_t index = s2.find("world", 0);

		if (index != std::string::npos)
		{

		}

		std::string new_str = s2.substr(index, 5);

		std::cout << new_str << '\n';
	}*/

	// ERASE 
	{
		std::string s1 = "Hello world";

		std::string& result = s1.erase(0, 6);

		if (&s1 == &result)
		{
			std::cout << "equals" << '\n';
		}

		std::cout << s1;
	}

}