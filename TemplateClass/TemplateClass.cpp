#include <iostream>
#include <initializer_list>
#include <vector>
#include <array>
#include <functional>

class Person
{
private:
	char* m_name;

public:
	~Person()
	{
		delete[] m_name;
		std::cout << "dtor" << '\n';
	}
	Person()
	{
		m_name = new char[32] {};
		std::cout << "ctor" << '\n';
	}

	Person(const Person& that)
	{
		m_name = new char[32] {};

		strcpy_s(m_name, 32, that.m_name);

		std::cout << "cctor" << '\n';
	}

	Person(Person&& that) noexcept
	{
		m_name = that.m_name;
		that.m_name = nullptr;

		std::cout << "mctor" << '\n';
	}

	Person& operator=(const Person& that)
	{

		if (this != &that)
		{
			this->~Person();
			m_name = new char[32];
			strcpy_s(m_name, 32, that.m_name);
			std::cout << "cass" << '\n';
		}

		return *this;
	}

	Person& operator=(Person&& that) noexcept
	{
		if (this != &that)
		{
			this->~Person();
			m_name = that.m_name;
			that.m_name = nullptr;

			std::cout << "mass" << '\n';
		}

		return *this;
	}
};

namespace Collections
{
	template<typename T = long> class List
	{
	private:
		size_t m_length;
		size_t m_capacity;
		T* m_data;
	public:
		~List()
		{
			for (size_t i = 0; i < m_length; ++i)
			{
				m_data[i].~T();
			}

			::operator delete(m_data);
		}
		List(const std::initializer_list<T>& list) : List((list.size() * 2))
		{
			for (auto& value : list)
			{
				append(value);
			}
		}
		List() : List(15) { }

		List(size_t a_capacity) : m_length(0), m_capacity(a_capacity)
		{
			m_data = reinterpret_cast<T*>(::operator new(sizeof(T) * m_capacity));
		}

		void append(const T& value)
		{
			if (m_length < m_capacity)
			{
				new (m_data + m_length) T{ value };

				m_length++;
			}			
		}
		T& operator[](size_t index)
		{
			return m_data[index];
		}
		size_t capacity()
		{
			return m_capacity;
		}
	};
}

template<typename T, size_t size> class FixedList
{
	T m_data[size];
	size_t m_length = 0;
public:
	void append(const T& value)
	{
		if (m_length < size)
		{
			m_data[m_length] = value;
		}
	}
};

using Collections::List;
using VoidList = List<>;
using std::string;
using std::cout;
using std::cin;


//template<typename K, typename V>
//struct Pair {
//	K key;
//	V value;
//};

template<typename K, typename V>
class Dictinary {

	struct Pair {
		K key;
		V value;
	};

	Pair* m_data;
};


int main()
{
	Dictinary<float, int> f;
	std::hash<std::string> hash_f;

	std::cout << hash_f("hello") << '\n';

	// std::cout << foo(12, 2.5) << '\n';
	//std::initializer_list<int> list{ 1, 2, 3, 4, 5, 6 };

	//// range based for
	//for (auto& val : list)
	//{
	//	std::cout << val << '\n';
	//}

	//constexpr size_t len = 5;

	//auto arr = new FixedList<int, len>; // class FixedList_int_5;
	//auto arr2 = new FixedList<int, 6>; // class FixedList_int_6;

	//arr->append(5);
	//arr->append(15);
	//arr->append(42);

	//delete arr;


	// std::array<int, 5> arr;

	// char str[20];

	// strcpy_s(str, "Helloo");
	/*string str;

	cout << str;
	List<> void_list;

	List<int> list;
	List<float> list2;*/


	
	/*{
		List<Person> persons;

		Person p1;
		Person p2;

		persons.append(p1);
		persons.append(p2);

		std::cout << persons.capacity() << '\n';
	}*/

	/*{
		List<> values(10);

		std::cout << values[0] << '\n';
		std::cout << values[1] << '\n';
		std::cout << values[2] << '\n';
	}*/
}
