#include <iostream>
int main()
{
    int foo()//ilegal:esta funcion esta funcion anidada dentro de la funcion main()
    {
        std::cout<<"¡foo \n";
        return 0;
    }
    foo(); //llamada de funcion a foo()
    return 0;
}