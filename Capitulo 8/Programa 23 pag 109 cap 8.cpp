#include <iostream>

unsigned int PRNG()
{
	// Nuestra semilla inicial inicial es 5323
	static unsigned int seed{ 5323 };

	// Tome	la semilla actual y genera un nuevo valor a partir de ella
	// Debido a nuestro uso de grandes constantes y desbordamiento, ser�a
	// Es dificil para alguien predecir casualmente c�al es el pr�ximo n�mero
	// va a ser del anterior
	seed = 8253729 * seed + 2396403

		// Toma la semilla y devuelve un valor entre 0 y 32767
		return seed % 32768;

}

int main()
{
	// Imprime 100 numeros aleatorios
	for (int count{ 1 }; count <= 100; ++count)
	{

		std::cout << PRNG() << '\t';

		// Si imprimimos 5 n�meros, comience una fila
		if (count % 5 == 0)
			std::cout << '\n';
	
	}

	return 0;
}