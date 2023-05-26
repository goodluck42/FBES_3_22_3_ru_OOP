#include "Student.h"
#include <iostream>


void print_Student(const Student& student)
{
	std::cout << "addr: " << &student << '\n';
	std::cout << "name = " << student.get_name() << '\n';
	std::cout << "age = " << student.get_age() << '\n';
	std::cout << "coins = " << student.get_coins() << '\n';
	std::cout << "id = " << student.get_id() << '\n';
}

Student create_Student()
{
	Student student;

	char name[128];
	std::cout << "Enter name -> ";
	std::cin.getline(name, 128);

	int age;
	int coins;

	std::cout << "Enter age -> ";

	std::cin >> age;

	std::cout << "Enter coins -> ";

	std::cin >> coins;

	student.set_name(name);
	student.set_age(age);
	student.set_coins(coins);

	return student; // copied
}

int main()
{/*
	{


		Student student{ "Vadim", 100, 20 };


		print_Student(student);



		std::cout << "main: " << '\n';
		std::cout << "addr: " << &student << '\n';
		std::cout << "age = " << student.get_name() << '\n';
	}*/

	{
		/*std::cout << "-------------\n";

		Student stud = create_Student();

		Student stud2{ stud };

		print_Student(stud);
		print_Student(stud2);*/

		Student stud42{};
	}
	/*char* m_name = new char[32];

	std::cout << (void*)m_name << '\n';

	delete[] m_name;

	m_name = nullptr;

	std::cout << (void*)m_name << '\n';


	delete[] m_name;*/
}