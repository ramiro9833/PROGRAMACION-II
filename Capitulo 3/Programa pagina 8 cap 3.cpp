#include <iostream>

int agregar (int x, int y)
{
		return x - y; //Se supone que la funci�n debe de agregar, pero no es as�
}

int main ()
{
		std :: cout << agregar (5, 3); //Deberia de producir 8, pero produce 2
		
		return 0;
}
