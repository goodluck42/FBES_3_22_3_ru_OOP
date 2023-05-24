#include <iostream>

class Student
{
public:
	~Student()
	{
		delete[] m_name;

		std::cout << "student destroyed" << '\n';
	}

	Student() : m_id(0)
	{
		// m_id = 0;
		m_name = new char[32];
		m_coins = 0;
		m_age = 0;

		std::cout << "student created()" << '\n';
	}

	Student(const char* a_name, int a_coins, int a_age) : m_id(rand() % 1000 * (s_id + 1))
	{
		// m_id = rand() % 1000 * (s_id + 1);
		m_name = new char[32];

		set_name(a_name);
		set_coins(a_coins);
		set_age(a_age);



		s_id += 2;

		std::cout << "student created(const char*, int, int)" << '\n';
	}

	int get_age()
	{
		return this->m_age;
	}

	int get_coins()
	{
		return m_coins;
	}

	void set_coins(int a_coins)
	{
		if (a_coins < 0)
		{
			return;
		}

		m_coins = a_coins;
	}

	void set_age(int a_age)
	{
		if (a_age >= 0 && a_age <= 128)
		{
			m_age = a_age;
		}
	}

	const char* get_name()
	{
		return m_name;
	}

	void set_name(const char* a_login)
	{
		strcpy_s(m_name, 32, a_login);
	}

	int get_id()
	{
		return m_id;
	}

private:
	static int s_id;
	char* m_name;
	int m_coins;
	int m_age;
	const int m_id;
};


class Classroom
{
public:
	~Classroom()
	{
		for (size_t i = 0; i < m_student_count; ++i)
		{
			delete m_students[i];
		}

		delete[] m_students;
	}
	Classroom() : Classroom(10) { }

	Classroom(size_t a_places)
	{
		m_students = new Student*[a_places] {};
		m_last_place = 0;
		m_student_count = a_places;
	}

	void add_student(Student* a_student)
	{
		if (m_last_place < m_student_count)
		{
			m_students[m_last_place++] = a_student;
		}
	}

	Student* get_student_by_name(const char* name)
	{
		for (size_t i = 0; i < m_student_count; ++i)
		{
			if (m_students[i] == nullptr)
			{
				continue;
			}

			const char* current_name = m_students[i]->get_name();

			if (!_strcmpi(current_name, name))
			{
				return m_students[i];
			}
		}

		return nullptr;
	}

private:
	size_t m_last_place;
	size_t m_student_count;
	Student** m_students;
};

int Student::s_id = 0;


void print_Student(Student* student)
{
	std::cout << "name = " << student->get_name() << '\n';
	std::cout << "age = " << student->get_age() << '\n';
	std::cout << "coins = " << student->get_coins() << '\n';
	std::cout << "id = " << student->get_id() << '\n';
}

int main()
{
	
	Classroom room{ 4 };

	room.add_student(new Student{ "Vadim", 25, 20});
	room.add_student(new Student{ "Ivan", 75, 19 });
	room.add_student(new Student{ "Sergey", 50, 18 });

	Student* stud1 = room.get_student_by_name("Vadim");
	
	if (stud1 == nullptr)
	{
		std::cout << "Student not found" << '\n';
	}
	else
	{
		print_Student(stud1);
	}


	/*Student* stud1 = nullptr;

	stud1->get_name();*/

	/////////////////////////////////////////////
	/*size_t len = 4;

	Student** students = new Student*[len] {};

	*students = new Student{ "Vadick", 90, 20 };
	*(students + 1) = new Student{ "Ivan", 25, 16 };
	*(students + 2) = new Student{ "Vasya", 50, 14 };

	std::cout << students[0]->get_age() << '\n';

	for (size_t i = 0; i < len; ++i)
	{
		delete students[i];
	}

	delete[] students;*/
	/////////////////////////////////////////////
	/*Student* students = new Student[12];

	std::cout << students[0].get_age();

	delete[] students;*/
	/////////////////////////////////////////////
}
