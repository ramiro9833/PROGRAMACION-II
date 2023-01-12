#include <iostream>

enum class Errorcode 
{
	success,
	negative_number
};
Errorcode doSomething(int value)
{
	if (value < 0)
	{ //Devoluci�n anticipada
		return Errorcode::negative_number;

	}
	// C�digo de la funci�n
	return Errorcode::success;
}

int main()
{
	std::cout << "Ingrese un numero positivo: ";
	int x{};
	std::cin >> x;

	if (doSomething(x) == Errorcode::negative_number)
	{
		std::cout << "Ingresa un numero negativo: !\n";
	}
	else
	{
		std::cout << "Funciono!!!\n";
	}

	return 0;
}