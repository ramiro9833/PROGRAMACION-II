#include <iostream>

int main(){
	
	std::cout<< "ingresasaste un entero: ";
	int x{};
	std::cin>> x;
	
	
	if (x == 0)
	std::cout<<"el valor es cero\n";
	if(x != 0)
	std::cout<<"el valor no es cero :(\n";
	
	return 0;
}
