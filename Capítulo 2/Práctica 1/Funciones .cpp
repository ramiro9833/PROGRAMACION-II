#include <iostream> // para std :: cout

//Definición de la función definida por el usuario doPrint ()
void doPrint () // doPrint () es la funcion llamda en este ejemplo
{
    std:: cout << "En doPrint () \n";
}

// Definición de la función main ()
int main()
{
    std :: cout << "Iniciando main () \n";
    doPrint (); // Interrumpe main () haciendo una llamada de función a doPrint (), main() es la persona que llama.
    std :: cout << "Finalizando main() \n"; // Esta sentencia se ejecuta despues de que termine doPrint ()

    return 0;
}

