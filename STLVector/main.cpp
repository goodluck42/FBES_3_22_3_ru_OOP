#include <iostream>
#include <vector>
#include <random>

class Object
{
private:
	int m_value{};
	std::string m_data{};
public:
	void print()
	{
		std::cout << m_value << '\n';
		std::cout << m_data << '\n';
	}
};

class Student
{
public:
	std::string name;
	int age;
	Student(const std::string& a_name, int a_age) : name(a_name), age(a_age)
	{

	}
};

class A
{
private:
	int field;
public:
	A(int) {
		std::cout << "A" << '\n';
	}
};

class A1
{
public:
	A1() = delete;
	A1(int) {
		
		std::cout << "A1" << '\n';
	}
};

class B : public A, public A1
{
public:
	B() : A(0), A1(0)
	{
		this->field;
	}
};

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	os << "name = " << obj.name << '\n';
	os << "age = " << obj.age << '\n';

	return os;
}

int main()
{
	/*{
		Object obj;

		int* m_value = (int*)&obj;

		*m_value = 90;

		char* pos = (char*)&obj;

		std::string* m_data = (std::string*)(pos + sizeof(int) + 4);

		m_data->operator=("Hello from main");

		obj.print();
	}*/

	//{
	//	std::vector<Student> vect;

	//	vect.emplace_back("Vadik", 90);
	//	vect.emplace_back("Semen", 13);
	//	vect.emplace_back("Yarik", 20);
	//	vect.emplace_back("Miroslave", 21);
	//	vect.emplace_back("Edik", 25);
	//	vect.emplace_back("Anton", 50);

	//	vect.erase(vect.begin() + 1); // erase at 1 index
	//	vect.erase(vect.end() - 1); // erase last element
	//  vect.pop_back(); // erase last element

	//	Student stud1{ "Egor", 23 };

	//	vect.insert(vect.begin() + 2, std::move(stud1)); // insert Egor at 2 index
	//	vect.emplace(vect.begin(), "Andrey", 16); // insert Andrey at 0 index (creates in-memory)

	//	vect[0].name = "Timofey";

	//	for (size_t i = 0; i < vect.size(); ++i)
	//	{
	//		std::cout << vect[i] << '\n';
	//	}
	//}
	///

	/*{
		std::default_random_engine engine;
		std::uniform_int_distribution<int> range{ 10, 99 };

		std::vector<int> ints;

		for (size_t i = 0; i < 93; ++i)
		{
			ints.push_back(range(engine));
		}

		std::cout << "before = " << ints.capacity() << '\n';

		ints.shrink_to_fit();

		std::cout << "after = " << ints.capacity() << '\n';
	}*/

	{
		B obj{};
	}


}