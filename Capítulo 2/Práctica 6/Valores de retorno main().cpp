#include <iostream>

int main()
{
    // Obtener un valor del usuario
    std:: cout << "Ingrese un entero: ";
    int num{};
    std::cin >> num;

    // Imprime el valor suplicado
    std::cout << num << " duplicado es: " << num * 2 << '\n';

    return 0;
}