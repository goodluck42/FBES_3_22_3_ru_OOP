#pragma once

class Student
{
public:
	~Student();
	Student();
	Student(const char* a_name, int a_coins, int a_age);
	int get_age();
	int get_coins();
	void set_coins(int a_coins);
	void set_age(int a_age);
	const char* get_name();
	void set_name(const char* a_login);
	int get_id();
private:
	static int s_id;
	char* m_name;
	int m_coins;
	int m_age;
	const int m_id;
};