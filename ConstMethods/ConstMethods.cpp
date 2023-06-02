#include <iostream>



class Number
{
private:
	int* m_value;
	bool m_is_negative;
public:
	~Number()
	{
		delete m_value;
	}

	Number(const Number& target)
	{
		m_value = new int{ *target.m_value };
		m_is_negative = target.m_is_negative;
	}

	Number(int a_value)
	{
		m_value = new int{ a_value };
		m_is_negative = *m_value < 0;
	}

	int get() const
	{
		return *m_value;
	}
};



void foo(Number* ptr);
void foo(Number& ref);
void foo2(Number val);

Number foo3();

int main()
{
	Number num = 42;

	foo(&num);
	foo(num);
	foo2(num);
}


void foo(Number* ptr) {}
void foo(Number& ref) {}
void foo2(Number val) {}
Number foo3()
{
	Number a = 90;

	return a;
}