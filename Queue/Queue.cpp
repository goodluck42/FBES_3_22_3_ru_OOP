#include <iostream>
#include <queue>

// LIFO - Last In First Out - Stack
// FIFO - First In First Out - Queue
// priority queue

template<typename T> class Queue
{
	template<typename T2> friend std::ostream& operator<<(std::ostream& os, const Queue<T2>& queue);
private:
	T* m_data;
	size_t m_size;
	size_t m_capacity;
public:
	~Queue()
	{
		delete[] m_data;
	}
	Queue()
	{
		m_capacity = 12;
		m_data = new T[m_capacity];
		m_size = 0;
	}
	void enqueue(const T& a_elem) // ýíêüþ
	{
		if (m_size < m_capacity)
		{
			m_data[m_size] = a_elem;
			++m_size;
		}
	}
	
	void enqueue(T&& a_elem) // ýíêüþ
	{
		if (m_size < m_capacity)
		{
			m_data[m_size] = std::move(a_elem);
			++m_size;
		}
	}

	const T& peek()
	{
		return m_data[0];
	}

	T dequeue()
	{
		T copy{ m_data[0] };

		if (m_size > 1)
		{
			for (size_t i = 1; i < m_size; ++i)
			{
				m_data[i - 1] = std::move(m_data[i]);
			}
		}

		--m_size;

		return copy;
	}

	size_t size()
	{
		return m_size;
	}

	size_t capacity()
	{
		return m_capacity;
	}
};

template<typename T2> std::ostream& operator<<(std::ostream& os, const Queue<T2>& queue)
{
	for (size_t i = 0; i < queue.m_size; ++i)
	{
		std::cout << queue.m_data[i] << '\n';
	}

	return os;
}

int main()
{
	Queue<int> values;

	values.enqueue(42);
	values.enqueue(13);
	values.enqueue(10);
	values.enqueue(15);
	values.enqueue(20);

	int value = values.dequeue();

	std::cout << "deleted value " << value << '\n'; // 15

	/*int elem = std::queue<int>::front();

	std::queue<int>::pop();*/

	std::cout << values;
}