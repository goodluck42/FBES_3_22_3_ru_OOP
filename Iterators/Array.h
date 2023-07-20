#pragma once
#include "ArrayIterator.h"

template<typename T> class Array
{
public:
	Array()
	{
		size = 0;
		capacity = 15;
		array = new T[capacity]{};
	}

	~Array()
	{
		delete[] array;
	}

	Array(const Array& that)
	{
		size = that.size;

		capacity = that.capacity;

		array = new T[capacity];

		memcpy(array, that.array, size * sizeof(T));
	}

	Array(Array&& that)
	{
		size = that.size;

		capacity = that.capacity;

		array = that.array;

		that.size = 0;

		that.capacity = 0;

		that.array = nullptr;
	}

	T* get_array() const
	{
		return array;
	}

	size_t get_size() const
	{
		return size;
	}

	void set_size(int a_size)
	{
		size = a_size;
	}

	size_t get_capacity() const
	{
		return capacity;
	}

	void append(const T& element)
	{
		check_capacity();

		array[size] = element;

		++size;

	}

	void prepend(const T& element)
	{
		check_capacity();

		for (int i = size; i > 0; --i)
		{
			array[i] = array[i - 1];
		}

		array[0] = element;
		++size;
	}

	T& operator[](int index)
	{
		return array[index];
	}

	bool is_empty()
	{
		return size == 0;
	}
	ArrayIterator<T> begin()
	{
		return ArrayIterator<T>{array};
	}
	ArrayIterator<T> end()
	{
		return ArrayIterator<T>{array + size};
	}
private:

	void resize_capacity()
	{
		capacity *= 1.5;

		T* new_arr = new T[capacity];

		for (size_t i{}; i < size; ++i)
		{
			new_arr[i] = array[i];
		}

		delete[] array;

		array = new_arr;
	}

	void check_capacity()
	{
		if (size >= capacity)
		{
			resize_capacity();
		}
	}

	void set_capacity(int a_capacity)
	{
		capacity = a_capacity;
	}

private:
	T* array;
	size_t size;
	size_t capacity;
};