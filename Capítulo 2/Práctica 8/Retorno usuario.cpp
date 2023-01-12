#include <iostream>

int getValueFromUser()
{
    std::cout << "Ingrese un entero: ";
    int input{};
    std::cin >> input;

    return input; //Devuelve el valor que el usuario ingresó
}

int main()
{
    int num{getValueFromUser()}; //inicia num con el valor de retorno de getValueFromUser()
    std::cout << num << " duplicado es: " << num * 2 << '\n';
    return 0;
}