#include <iostream>

int main(){
	
	std::cout<<"ingrese un numero: ";
	int x{};
	std::cin>> x;
	
	if(x > 0)
	std::cout<<"el valor es positivo\n";
	else if(x < 0)
	std::cout<<"el valor es negativo\n";
	else
	std::cout<<"el valor es cero\n";
	
	
	return 0;
	
	
	
	
}
