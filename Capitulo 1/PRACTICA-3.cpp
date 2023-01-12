#include <iostream>
void doB()
{
    std::cout<<"en doB() \n";
}
void doA()
{
    std::cout<<"inicializando doA";
    doB();
    std::cout<<"Finalizando doA() \n";
}
int main()
{
    std::cout<<"iniciando main() \n";
    doA();
    std::cout<<"Finalizando main() \n";
    return 0;
}