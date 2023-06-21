#include <iostream>
#include <initializer_list>
#include <type_traits>

using std::cout;
using std::cin;


template<typename T> struct my_is_void
{
	static constexpr bool value = false;
};

template<> struct my_is_void<void>
{
	static constexpr bool value = true;
};

namespace Collections
{
	template<typename T> class List
	{
		// static_assert(expr, message);
		// Если expr будет false, то будет ошибка компиляции
		static_assert(!my_is_void<T>::value, "Type T cannot be void.");
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
using Collections::List;


class StudentMember
{

};

// T = StudentMember*&

// Общая специализация
template<typename T> class Group
{
public:
	void add_member(const T&)
	{
		cout << "Generic variant" << '\n';
	}
};

// Полная специализация
template<> class Group<StudentMember>
{
public:
	void add_member(const StudentMember& data)
	{
		cout << "StudentMember variant" << '\n';
	}

	void remove_member(int index)
	{
		cout << "StudentMember removed" << '\n';
	}
};

// Частичная специализация
// *, &, &&, [], const, *&
template<typename T> class Group<T*>
{
private:
	T* ptr;
public:
	~Group()
	{
		cout << "data destroyed\n";
		delete ptr;
	}
	void add_member(T* ptr)
	{
		this->ptr = ptr;
		cout << "T pointer variant" << '\n';
	}
};

int main()
{
	/*
	{
	   // Общая
	   Group<int> int_group;

	   int_group.add_member(5);

	   // полная
	   Group<StudentMember> student_group;

	   student_group.add_member(StudentMember{});

	   // частичная

	   int* ptr = new int[32];

	   Group<int*> ptr_group;

	   ptr_group.add_member(ptr);

	   Group<StudentMember*&> test;
   }*/
}
