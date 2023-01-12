#include <iostream> // std::cout

void doB()
{
    std::cout <<"En doB() \n";
}

void doA()
{
    std::cout << "En doA() \n";
    doB();
}

// Definición de la función main ()
int main ()
{
    std::cout << "Iniciando main()\n";
    doA();
    doB();
    std::cout << "Finalizando main()\n";
    return 0;
}