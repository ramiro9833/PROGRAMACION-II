#include <iostream>

int returnFive()
{
    return 5;
}

int main()
{
    std::cout << returnFive << '\n'; // retorna el valor uno por que falto añadirle "()" a returnFive

    return 0;
}