#include <iostream>

int foo() //no loger inside of main()
{
    std::cout << "foo!\n";
    return 0;
}

int main()
{
    foo();
    return 0;
}