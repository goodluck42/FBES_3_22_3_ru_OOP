#pragma once

template<typename T> class ArrayIterator
{
private:
	T* m_current;
public:
	ArrayIterator(T* a_current) : m_current(a_current) {}

	ArrayIterator& operator++()
	{
		++m_current;

		return *this;
	}

	T& operator*()
	{
		return *m_current;
	}

	bool operator!=(const ArrayIterator& iterator)
	{
		return m_current < iterator.m_current;
	}
};