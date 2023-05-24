#include <iostream>
#include "Global.h"
#include "Module.h"

//class A
//{
//public:
//    A()
//    {
//        ++s_counter;
//    }
//
//    static int s_counter;
//
//    static void show_counter()
//    {
//        std::cout << s_counter;
//    }
//
//    void foo()
//    {
//        
//    }
//};
//
//int A::s_counter = 0;

int sum(int a, int b)
{
    std::cout << a + b;

    return a + b;
}

int main()
{
    register int i = 0;

    for (; i < 1'000'000'000; ++i) {}

    std::cout << "Extern.cpp: " << &global_value << '\n';
    show_address();

    std::cout << sum(2, 5) << '\n';
}