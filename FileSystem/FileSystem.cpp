#include <iostream>
#include <string>
#include <fstream>


class Person
{
public:
	std::string name;
	int age;
};

class User
{
public:
	std::string login;
	std::string password;
	int age;
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << person.name << '\n';
	os << person.age << '\n';

	return os;
}

std::istream& operator>>(std::istream& is, Person& person)
{
	std::getline(is, person.name);
	is >> person.age;
	is.ignore();

	return is;
}


int main()
{
	/*{
		std::string file_name = "data.txt";
		std::ofstream file;

		file.open(file_name);

		const Person p1{ "Namik", 22 };

		file << p1;

		std::cout << p1;

		file.close();
	}*/

	/*{
		std::ifstream file;

		file.open("data.txt");

		Person p1;
		Person p2;

		file >> p1;
		file >> p2;

		std::cout << p1;
		std::cout << p2;

		file.close();
	}*/


	int size = 42;
	
	char* buffer = new char[sizeof(int)];

	char* s = (char*)size;

	for (int i = 0; i < sizeof(int); ++i)
	{
		buffer[i] = s[i];
	}


	FILE* file;
	fopen_s(&file, "test.bin", "ab");

	std::cout << (void*)s;


	//{
	//	std::fstream file;

	//	file.open("data.bin", std::ios::out | std::ios::binary);

	//	if (file.is_open())
	//	{
	//		User data{ "binary data!", "qwerty", 20 };

	//		int len = data.login.length();

	//		char* len_buffer = new char[sizeof(int)] {};

	//		for (int i = 0; i < sizeof(int); ++i)
	//		{
	//			len_buffer[i] = ???;
	//		}
	//		//file.getline(nullptr, 0);
	//		file.write(len_buffer, sizeof(int));

	//		delete[] len_buffer;

	//		file.close();
	//	}
	//	else
	//	{
	//		std::cout << "failed to open file";
	//	}

	//	// in = 00000010
	//	// binary = 01000000
	//	// 00000010
	//	// |
	//	// 01000000
	//	// 
	//	// 01000010
	//}
	
}