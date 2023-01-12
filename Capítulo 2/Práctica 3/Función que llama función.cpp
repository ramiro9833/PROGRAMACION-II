#include <iostream> // para std :: cout

void doB()
{
    std::cout << "en doB () \n";
}

void doA()
{
    std::cout << "Iniciando doA () \n";
    doB ();
    std::cout << "Finalizando doA () \n";
}

// Definicion de la funcion main ()
int main ()
{
    std::cout << "Iniciando main () \n";
    doA();
    std::cout << "Finalizando main () \n";
    return 0;
}