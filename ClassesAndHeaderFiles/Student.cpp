#include "Student.h"
#include <cstdlib>
#include <cstring>

Student::~Student()
{
	delete[] m_name;
}

Student::Student() : m_id(0)
{
	m_name = new char[32];
	m_coins = 0;
	m_age = 0;
}

Student::Student(const char* a_name, int a_coins, int a_age) : 
	m_id(rand() % 1000 * (s_id + 1))
{
	m_name = new char[32];

	set_name(a_name);
	set_coins(a_coins);
	set_age(a_age);

	s_id += 2;
}

int Student::get_age()
{
	return this->m_age;
}

int Student::get_coins()
{
	return m_coins;
}

void Student::set_coins(int a_coins)
{
	if (a_coins < 0)
	{
		return;
	}

	m_coins = a_coins;
}

void Student::set_age(int a_age)
{
	if (a_age >= 0 && a_age <= 128)
	{
		m_age = a_age;
	}
}

const char* Student::get_name()
{
	return m_name;
}

void Student::set_name(const char* a_login)
{
	strcpy_s(m_name, 32, a_login);
}

int Student::get_id()
{
	return m_id;
}

int Student::s_id = 0;