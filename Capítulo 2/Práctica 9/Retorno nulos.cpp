#include <iostream>

// void significa que la funcion no devuelve un valor a la persona que llama
void returnNothing()
{
    std::cout << "Hola" << '\n';
    //Esta función no devuelve un valor, por lo que no se necesita una declaración de devolución
}

int main ()
{
    returnNothing(); // bien: se llama a la función returnNothing () no se devuelve ningún valor 
    //std::cout<< returnNothing (); // error: esta linea no se compilara.
    return 0;
}