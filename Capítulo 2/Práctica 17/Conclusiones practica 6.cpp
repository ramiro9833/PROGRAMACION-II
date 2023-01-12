#include <iostream>

int getNumbers()
{
    return 5;
    return 6;
}

int main()
{
    std::cout<< getNumbers() << '\n';
    std::cout<< getNumbers() << '\n';

    return 0;
}