//esta funcion no toma parametros
//no depende de la persona que llama para nada
void doPrint()
{
    std::cout<<"En doPrint () \ n";
}
//esta funcion toma un parametro entero llamado x
//la persona que llama proporciona el valor de x
void printValue(int x)
{
    std::cout<< x << '\ n';
}
//esta funcion tiene dos parametros enteros, uno llamado x y otro llamado y
//la persona que llama proporciona el valor tanto de x como de y
int add(int x, int y)
{
    return x + y;
}