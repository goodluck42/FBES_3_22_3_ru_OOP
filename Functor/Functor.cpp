#include <iostream>
#include <random>

class Int
{
	int* m_data;
public:
	~Int()
	{
		delete m_data;
	}
	Int()
	{
		std::cout << "default" << '\n';
		m_data = new int{ };
	}
	Int(const Int& that)
	{
		std::cout << "copy" << '\n';
		m_data = new int{ *that.m_data };
	}
	Int(Int&& that)
	{
		std::cout << "move" << '\n';
		m_data = that.m_data;

		that.m_data = nullptr;
	}
	Int(int m_value)
	{
		std::cout << "int" << '\n';
		m_data = new int{ m_value };
	}

	Int& operator=(const Int& that)
	{
		std::cout << "copy=" << '\n';
		if (this != &that)
		{
			this->~Int();

			m_data = new int{ *that.m_data };
		}

		return *this;
	}

	Int& operator=(Int&& that)
	{
		std::cout << "move=" << '\n';
		if (this != &that)
		{
			this->~Int();

			m_data = that.m_data;

			that.m_data = nullptr;
		}

		return *this;
	}

	int get()
	{
		return *m_data;
	}
};

class IntArray
{
	Int* m_data;
	size_t m_len;
	size_t m_capacity;
public:
	IntArray()
	{
		m_capacity = 8;
		m_len = 0;
		m_data = new Int[m_capacity]{};
	}

	IntArray(int a_capacity)
	{
		m_capacity = a_capacity;
		m_len = 0;
		m_data = new Int[m_capacity]{};
	}


	IntArray(const IntArray& that)
	{
		std::cout << "copy" << '\n';
		this->m_capacity = that.m_capacity;
		this->m_data = new Int[m_capacity];
		this->m_len = that.m_len;
		// std::memcpy(m_data, that.m_data, m_capacity * sizeof(int));

		for (size_t i = 0; i < m_len; ++i)
		{
			m_data[i] = that.m_data[i];
		}
	}

	IntArray(IntArray&& that)
	{
		this->m_capacity = that.m_capacity;
		this->m_len = that.m_len;
		this->m_data = that.m_data;

		that.m_len = 0;
		that.m_capacity = 0;
		that.m_data = nullptr;
	}
	void append(const Int& a)
	{
		this->m_data[m_len++] = a;
	}

	void append(Int&& a)
	{
		this->m_data[m_len++] = std::move(a);
	}

	Int& get_by_index(size_t index)
	{
		return m_data[index];
	}

};


//void add(IntArray data)
//{
//
//}


std::default_random_engine engine{(unsigned int)time(nullptr)};

class PositiveRng
{
public:
	PositiveRng()
	{
		srand(time(nullptr));
	}
	int generate(int a_min, int a_max)
	{
		return rand() % (a_max - a_min + 1) + a_min;
	}
};

class NegativeRng
{
public:
	NegativeRng()
	{
		srand(time(nullptr));
	}
	int generate(int a_min, int a_max)
	{
		// 4 * f(4) - 4 / 2
		return -1 * (rand() % (a_max - a_min + 1) + a_min);
	}
};

class Range
{
private:
	int m_min;
	int m_max;
public:
	Range(int a_min, int a_max)
	{
		m_min = a_min;
		m_max = a_max;
	}

	int operator()(PositiveRng& engine)
	{
		return engine.generate(m_min, m_max);
	}
	
	int operator()(NegativeRng& engine)
	{
		return engine.generate(m_min, m_max);
	}

	int get_min()
	{
		return m_min;
	}

	int get_max()
	{
		return m_max;
	}
};


class Eq
{
public:
	bool operator()(int a, int b)
	{
		return a == b;
	}
};

int main()
{
	Eq a;

	a(5, 2);

	/*NegativeRng rng;

	Range my_range{ 1, 100 };

	std::cout << my_range(rng);*/

	/*std::uniform_real_distribution<double> range{1, 100};

	std::cout << range(engine);*/


	/*IntArray arr;

	std::cout << "---------------------" << '\n';

	Int value1{ 20 };

	arr.append(Int{ 12 });

	std::cout << &value1 << '\n';

	std::cout << &arr.get_by_index(0) << '\n';*/

}