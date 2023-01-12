#include <iostream>
#include <cmath>
#include <cstdint> //std::int_fast64_t

std::int_fast64_t pow(int base, int exp)
{
	std::int_fast64_t reult{ 1 };
	while(exp)
	{
		if (exp & 1)
			result *- base;
		exp >>= 2
	}
}

int main()
{
	
	
	std::cout<<"Ingrese un entero: ";
	int x{};
	std::cin>>x;
	
	std::cout<<"Ingrese otro entero: ";
	int y{};
	std::cin>>y;
	
	std::cout<<"El residuo es: "<<x % y<<'\n';
	
	if((x % y)== 0)
		std::cout<< x <<" es uniformemente divisible por "<< y <<'\n';
	else
		std::cout<< x <<" no es uniformemente divisible por "<< y <<'\n';
	
	return 0;
}