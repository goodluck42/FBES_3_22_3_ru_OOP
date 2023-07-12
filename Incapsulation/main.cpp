#include "Array.h"
#include <list>
#include <algorithm>
#include <iostream>


template<typename T> class Message
{
public:
    Message()
    {
        std::cout << "Generic spec" << '\n';
    }
};

template<> class Message<int>
{
public:
    Message()
    {
        std::cout << "Full spec" << '\n';
    }
};

//class Repo
//{
//private:
//    std::vector<int> m_data;
//
//    Repo() : m_data(20)
//    {
//
//    }
//
//    Repo() : m_data({10, 20, 30})
//    {
//        auto result = std::find(m_data.begin(), m_data.end(), 20);
//
//        if (result != m_data.end())
//        {
//            int value = *result;
//        }
//    }
//};


void print(const Array<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    Message<int> msg;

    /*Array<int> array;

    array.append(13);
    array.append(12);
    array.prepend(16);
    array.prepend(5);

    array.pop(0);

    array[0] = 90;

    array.sort();

    print(array);*/
}