#include <iostream>
#define LESSON 2


// Access modifiers
// public
// private
// protected

// struct (public)
// class (private)


class Account
{
public:
	Account(const char* a_login, const char* a_password, int a_age)
	{
		m_login = new char[32];
		m_password = new char[32];

		set_login(a_login);
		set_password(a_password);
		set_age(a_age);

		m_id = rand() % 1000 * (s_id + 1);

		s_id += 2;
	}

	int get_age()
	{
		return m_age;
	}

	void set_age(int a_age)
	{
		if (a_age >= 0 && a_age <= 128)
		{
			m_age = a_age;
		}
	}

	const char* get_login()
	{
		return m_login;
	}
	
	void set_login(const char* a_login)
	{
		strcpy_s(m_login, 32, a_login);
	}

	const char* get_password()
	{
		return m_password;
	}

	void set_password(const char* a_password)
	{
		strcpy_s(m_password, 32, a_password);
	}

	int get_id()
	{
		return m_id;
	}

private:
	static int s_id;
	char* m_login;
	char* m_password;
	int m_age;
	int m_id;
};

int Account::s_id = 0;

class Car
{
public:

	~Car()
	{
		std::cout << "~Car()" << '\n';
		delete[] model;
	}
	Car()
	{
		model = nullptr;
		price = 0;
	}

	Car(int price, const char* model)
	{
		std::cout << "Car()" << '\n';
		this->price = price;
		this->model = new char[32];

		strcpy_s(this->model, 32, model);
	}



	int price;
	char* model;
};

void print(Car* const car)
{
	std::cout << "model = " << car->model << '\n';
	std::cout << "price = " << car->price << '\n';
}
void print(Account* acc)
{
	std::cout << "Login = " << acc->get_login() << '\n';
	std::cout << "Password = " << acc->get_password() << '\n';
	std::cout << "Age = " << acc->get_age() << '\n';
	std::cout << "Id = " << acc->get_id() << '\n';
}
//Car* create_Car(int price, const char* model)
//{
//	Car* car = new Car;
//
//	car->price = price;
//
//	return car;
//}


#if defined(LESSON) && LESSON == 1

int main()
{
	//{


	//	// DESCTRUCTORS
	//	/* {
	//		std::cout << "scope begin: " << '\n';
	//		{
	//			Car car1(90000, "BMW");
	//			Car car2(90000, "BMW");
	//		}
	//		std::cout << "scope end " << '\n';


	//		std::cout << "scope begin: " << '\n';
	//		{
	//			Car car1(90000, "BMW");
	//		}
	//		std::cout << "scope end " << '\n';
	//	}*/

	//	// STACK OBJECT VS HEAP OBJECT
	//	// HEAP
	//	{
	//		Car* car1 = new Car{ 90000, "BMW" };
	//		Car* car2 = new Car{ 9000, "Mercedes" };

	//		print(car1);
	//		print(car2);

	//		delete car1;
	//		delete car2;
	//	}




	//	// STACK

	//	Car car2{ 8000, "Honda" };

	//	print(&car2);

	//	std::cout << "SIZEOF = " << sizeof(Car) << '\n';


	//}
}

#elif defined(LESSON) && LESSON == 2

int main()
{

	Account acc1{ "vadimka", "vadik_super123", 16 };

	acc1.set_login("vadick");

	acc1.set_password("im_super123");

	print(&acc1);

	Account acc2{ "yaroslave", "slave123", 19 };

	print(&acc2);

	//const char* login = acc1.get_login();

	// login[0] = '1';
	// login[0] = '1';

	//std::cout << login << '\n';

	// std::cout << acc1.get_login() << '\n';
	// std::cout << acc1.m_password << '\n';
}

#endif