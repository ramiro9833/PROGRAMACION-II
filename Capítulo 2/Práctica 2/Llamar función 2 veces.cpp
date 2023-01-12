#include <iostream> // para std :: cout

void doPrint ()
{
    std :: cout << "En doPrint () \n";
}

// Definición de la función main ()
int main ()
{
    std :: cout << "Iniciando main () \n";
    doPrint(); // doPrint() llamado por primera vez
    doPrint(); // doPrint() llamado por segunda vez
    std :: cout << "Finalizanfo main () \n";

    return 0;
}