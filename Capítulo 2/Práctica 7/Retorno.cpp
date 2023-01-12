#include <iostream>

// int es el tipo de retorno
// Un tipo de retorno de int significa que la función devolverá algún valor entero a la persona llama (el valor específico)
int returnFive ()
{
    // La declaración de retorno indica el calor específico que se devolverá
    return 5; // devuelve el calor específico 5 a la persona que llama 
}

int main ()
{
    std:: cout << returnFive () <<'\n'; //imprime 5
    std:: cout << returnFive () + 2 << '\n'; // imprime 7
    returnFive (); // bien: se devuelve el valor 5, pero se ignora ya que main () no hace nada con él
    return 0;
}