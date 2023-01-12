#include <iostream>

int foo()//no longer inside of main()
{
    std::cout<<"¡foo \n";
    return 0;
}
int main()
{
    foo(); 
    return 0;
}