#pragma once

class Student
{
public:
	~Student();
	Student();
	Student(const char* a_name, int a_coins, int a_age);
	Student(const Student& target);
	int get_age() const;
	int get_coins() const;
	void set_coins(int a_coins);
	void set_age(int a_age);
	const char* get_name() const;
	void set_name(const char* a_login);
	int get_id() const;
private:
	static int s_id;
	char* m_name;
	int m_coins;
	int m_age;
	const int m_id;
};