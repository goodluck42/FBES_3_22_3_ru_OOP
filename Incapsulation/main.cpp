#include "Array.h"
#include <list>

class Repo
{
private:
    std::vector<int> m_data;

    Repo() : m_data(20)
    {

    }

    Repo() : m_data({10, 20, 30})
    {

    }
};


void print(const Array<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    Array<int> array;

    array.append(13);
    array.append(12);
    array.prepend(16);
    array.prepend(5);

    array.pop(0);

    array[0] = 90;

    array.sort();

    print(array);
}