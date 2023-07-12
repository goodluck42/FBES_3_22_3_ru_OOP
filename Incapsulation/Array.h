#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


template<typename T>
class Array
{
private:
    std::list<T> m_data;
public:
    void append(const T& elem)
    {
        m_data.push_back(elem);
    }

    void prepend(const T& elem)
    {
        m_data.insert(m_data.begin(), elem);
    }
    void pop()
    {
        m_data.pop_back();
    }
    void pop(int index)
    {
        auto it = m_data.begin();

        for (size_t i = 0; i < index; ++it, ++i);

        m_data.erase(it);
    }
    size_t size() const
    {
        return m_data.size();
    }
    size_t capacity() const
    {
        return m_data.size();
    }

    void sort()
    {
        m_data.sort();
    }

    T& operator[](int index)
    {
        auto it = m_data.begin();

        for (size_t i = 0; i < index; ++it, ++i);

        return *it;
    }
    
    const T& operator[](int index) const
    {
        auto it = m_data.begin();

        for (size_t i = 0; i < index; ++it, ++i);

        return *it;
    }
};