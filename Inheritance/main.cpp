#include <iostream>

enum class Color
{
	Black,
	White,
	Gray
};

class Vehicle // base class / parent class / base
{
private:
	void* m_data;
protected:
	int m_speed;
public:
	~Vehicle()
	{
		std::cout << "~Vehicle()" << '\n';
	}
	Vehicle(Color a_color) : m_speed(0), color(a_color) {}
	Vehicle() : m_speed(0), color(Color::Gray) 
	{
		std::cout << "Vehicle()" << '\n';
	}

	const Color color;

	void move()
	{
		m_speed = 60;
		std::cout << "Vehicle is moving" << '\n';
	}
	void stop()
	{
		m_speed = 0;
		std::cout << "Vehicle has stopped" << '\n';
	}
};


class Car : public Vehicle // child class / derived / child
{
private:
	int m_acceleration;
public:
	~Car()
	{
		std::cout << "~Car()" << '\n';
	}
	Car(int a_acceleration)
	{
		std::cout << "Car(int a_acceleration)" << '\n';

		init(a_acceleration);
	}

	Car(Color a_color, int a_acceleration) : Vehicle(a_color)
	{
		init(a_acceleration);
	}

	void start_engine()
	{
		std::cout << "Vehicle engine is started" << '\n';
	}
private:
	void init(int a_acceleration)
	{
		m_acceleration = a_acceleration;
		// malloc()
		// memset
	}
};

class FlyingCar : public Car
{
public:
	~FlyingCar()
	{
		std::cout << "~FlyingCar()" << '\n';
	}
	FlyingCar(int a_acceleration) : Car(a_acceleration)
	{
		std::cout << "FlyingCar(int a_acceleration)" << '\n';
	}
	void fly()
	{
		std::cout << "Vehicle started flying" << '\n';
	}
};


#include <vector>

class Repo
{
private:
	std::vector<int>* m_data;
public:
	Repo(std::vector<int>* a_data)
	{

	}
};



int main()
{
	std::vector<int> data;

	data.push_back(42);

	Repo* repo = new Repo{&data};

	delete repo;

	std::cout << data[0];

	return 0;
}