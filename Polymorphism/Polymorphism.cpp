#include <iostream>
#include <vector>
#define abstract

abstract class Item
{
private:
	std::string m_name;
	double m_weight;
public:
	Item(const std::string& a_name, double a_weight) : m_name(a_name), m_weight(a_weight) {}
	virtual void use() = 0; // pure virtual function
	const std::string& get_name() const
	{
		return m_name;
	}
};

class Medkit : public Item
{
public:
	Medkit(const std::string& a_name, double a_weight) : Item(a_name, a_weight) { }
	void use() override {
		std::cout << "Using medkit" << '\n';
	}
};

class Key : public Item
{
public:
	Key(const std::string& a_name, double a_weight) : Item(a_name, a_weight) { }
	void use() override {
		std::cout << "Using key" << '\n';
	}
};

class Beer : public Item
{
public:
	Beer(const std::string& a_name, double a_weight) : Item(a_name, a_weight) { }
	void use() override {
		std::cout << "Drinking the beer" << '\n';
	}
};

class Energizer : public Item
{
public:
	Energizer(const std::string& a_name, double a_weight) : Item(a_name, a_weight) { }
	void use() override {
		std::cout << "Drinking the energizer" << '\n';
	}
};

class Inventory final
{
private:
	std::vector<Item*> m_items;
public:
	~Inventory() {}
	void add_item(Item* a_item)
	{
		m_items.push_back(a_item);
	}

	Item* get_item(size_t a_index)
	{
		return m_items[a_index];
	}
};

//////////

class Base
{
private:
	void* _vfptr; // {0x42, 0x50}
public:
	Base()
	{
		_vfptr = malloc(24);
	}
	virtual ~Base()
	{
		free(_vfptr);
		std::cout << "Base::~Base()" << '\n';
	}
	virtual void foo() // 0x42
	{
		std::cout << "Base::foo()" << '\n';
	}

	virtual void bar() // 0x50
	{
		std::cout << "Base::bar()" << '\n';
	}
};

class Derived final : public Base
{
private:
	void* _vfptr; // {0x50, 0x90}
public:
	Derived()
	{
		_vfptr = malloc(32);
	}
	~Derived()
	{
		free(_vfptr);
		std::cout << "Derived::~Derived()" << '\n';
	}
	void foo() override // 0x90
	{
		// Base::foo(); // call parent's method
		std::cout << "Derived::foo()" << '\n';
	}
};


//////////

class Person
{
protected:
	std::string m_name;
public:
	void print_info()
	{
		std::cout << "Person:" << m_name << '\n';
	}
};

class Student : public virtual Person
{
public:
	void print_info()
	{
		std::cout << "Student:" << m_name << '\n';
	}
};

class Teacher : public virtual Person
{
public:
	void print_info()
	{
		std::cout << "Teacher:" << m_name << '\n';
	}
};

class SuperStudent : public Student, public Teacher
{
public:
	SuperStudent(const std::string& a_name)
	{
		m_name = a_name;
	}
	void print()
	{
		std::cout << "SuperStudent: " << '\n';

		Teacher::print_info();
	}
};


// interface
template<typename T>
struct ICollection
{
	virtual void add(const T& a_value) = 0;
	virtual void get(size_t index) = 0;
};

// implementation 1
template<typename T>
class Array : public ICollection<T>
{
public:
	void add(const T& a_value) override
	{

	}
	void get(size_t index) override
	{

	}
};


// implementation 2
template<typename T>
class LinkedList : public ICollection<T>
{
public:
	void add(const T& a_value) override
	{

	}
	void get(size_t index) override
	{

	}
};


int main()
{
	/*SuperStudent ss{ "Farhad" };

	ss.print();*/


	//Base** values = new Base*[2] { new Derived, new Base }; // {0x0000, 0xfff2}

	//for (size_t i = 0; i < 2; ++i)
	//{
	//	values[i]->foo();
	//}

	//Base* obj = new Derived;


	////obj->foo();

	//delete obj;

	// delete obj;

	//std::cout << sizeof(Base) << '\n';
	//std::cout << sizeof(Derived) << '\n';

	/* {
		Inventory inventory;

		inventory.add_item(new Medkit{ "Aptechka", 1 }); // 0
		inventory.add_item(new Key{ "klych ot tualeta", 0.1 }); // 1
		inventory.add_item(new Beer{ "Garage", 0.5 }); // 2
		inventory.add_item(new Energizer{ "Redbull", 0.45 }); // 3

		Item* item = inventory.get_item(0);

		item->use();
	}*/
}