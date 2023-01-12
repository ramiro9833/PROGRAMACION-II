#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;
    //ESTRUCTURAS DE PRODUCTOS
struct productos1
{
    string nomproduc;
    string desc;
};
struct productos2
{
    int idproducto;
    int stock;
    float precio;
};

    //ESTRUCTURAS DE CLIENTES
struct clientes1
{
    string nom;
};
struct clientes2
{
    int idcliente;
    int credito;
    int adeudo;
};

int m1, m2;
char opc2;

void basedatosproductos();
void productos();
void stock();
void rgventas();
void clientes();
bool comprobarid(int, bool);
bool comprobaridcliente(int, bool);

    //MATRICES DONDE SE GUARDAN LOS DATOS DE CLIENTES Y PRODUCTOS
productos1 productosready [20] [2];
productos2 productosready2 [20] [3];

clientes1 clientesready [20];
clientes2 clientesready2 [20] [3];

int main()
{
	int opc;
    cout<<"\n\tPUNTO DE VENTA --A B A R R O T E S--";
    cout<<"\n\n";
    cout<<"\n\tOPCIONES";
    cout<<"\n\t1- Productos";
    cout<<"\n\t2- STOCK";
    cout<<"\n\t3- Registro de ventas";
    cout<<"\n\t4- Clientes";
    cout<<"\n\t5- SALIR";    
    cout<<"\n\n";
    cout<<"\n\tIngrese una opcion: ";
    cin>>opc;
    system("cls");
    switch (opc)
    {
        case 1:
            productos();
        break;
        case 2:
            stock();
        break;
        case 3:
        	rgventas();
        break;
        case 4:
        	clientes();
        break;
        case 5:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
    
    getch();
    return 0;
}

void productos()
{
	int opc, id;
    cout<<"\n\t--P R O D U C T O S--";
    cout<<"\n\n\tOPCIONES";
    cout<<"\n";
    cout<<"\n\t1- Ingresar nuevo producto";
    cout<<"\n\t2- Ver productos";
    cout<<"\n\t3- Volver al menu principal";
    cout<<"\n\t4- SALIR";    
    cout<<"\n";
    cout<<"\n\tIngrese una opcion: ";
    cin>>opc;
    system("cls");
    switch (opc)
    {
        case 1:
            do
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        cout<<"\n\tNombre del producto: ";
                        cin>>productosready [i] [j].nomproduc;
                        cout<<"\n\tID (identificador): ";
                        cin>>productosready2 [i] [j].idproducto;
                        cout<<"\n\tDescripcion: ";
                        cin>>productosready [i] [j].desc;
                        cout<<"\n\tPrecio de venta: $";
                        cin>>productosready2 [i] [j].precio;
                        cout<<"\n\tStock: ";
                        cin>>productosready2 [i] [j].stock;
                        cout<<"\n\tDesea volver a agregar otro producto(s)? S/N ";
                        cin>>opc2;
                        m1 = i;
                        m2 = j;
                    }
                }
            } while (opc2 == 'S'); return productos();
        case 2:
            cout<<"\n\tIngrese el ID del producto: ";
            cin>>id;
            system("cls");
                if (comprobarid(id, true))
                {
                    if (productosready2[m1] [m2].idproducto == id)
                    {
                        do
                        {
                            for (int i = 0; i < 20; i++)
                            {
                                for (int j = 0; j < 20; j++)
                                {
                                    cout<<"\n\tNombre del producto: "<<productosready [i] [j].nomproduc;
                                    cout<<"\n\tID (identificador): "<<productosready2 [i] [j].idproducto;
                                    cout<<"\n\tDescripcion: "<<productosready [i] [j].desc;
                                    cout<<"\n\tPrecio de venta: $"<<productosready2 [i] [j].precio;
                                    cout<<"\n\tStock: "<<productosready2 [i] [j].stock;
                                    cout<<"\n\tDesea volver al menu? S/N ";
                                    cin>>opc2;
                                    m1 = i;
                                    m2 = j;
                                }
                            }
                        } while (opc2 == 'S'); return productos();
                    }
                }
        break;
        case 3:
        	main();
        break;
        case 4:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
}

void stock()
{
    basedatosproductos();
	int opc, id, stockn;
    cout<<"\n\t--S T O C K--";
    cout<<"\n\n\tOPCIONES";
    cout<<"\n";
    cout<<"\n\t1- Ingresar nuevo stock de producto(s)";
    cout<<"\n\t2- Eliminar stock al producto(s)";
    cout<<"\n\t3- Ver STOCK";
    cout<<"\n\t4- Volver al menu principal";
    cout<<"\n\t5- SALIR";
    cout<<"\n";
    cout<<"\n\t";
    cout<<"\n\tIngrese una opcion: ";
    cin>>opc;
	system("cls");
    switch (opc)
    {
        case 1:
            cout<<"\n\tIngrese el ID del producto: ";
            cin>>id;
            system("cls");
                if (comprobarid(id, true))
                {
                    if (productosready2[m1] [m2].idproducto == id)
                    {
                        do
                        {
                            for (int i = 0; i < 20; i++)
                            {
                                for (int j = 0; j < 20; j++)
                                {
                                    cout<<"\n\tStock actual: "<<productosready2[m1] [m2].stock;
                                    cout<<"\n\tNuevo Stock: ";
                                    cin>>stockn;
                                    productosready2[m1] [m2].stock += stockn;
                                    cout<<"\n\tDesea volver a modificar el stock? S/N ";
                                    cin>>opc2;
                                    m1 = i;
                                    m2 = j;
                                }
                            }
                        } while (opc2 == 'S'); return stock();
                    }
                }
        break;
        case 2:
            cout<<"\n\tIngrese el ID del producto: ";
            cin>>id;
            system("cls");
                if (comprobarid(id, true))
                {
                    if (productosready2[m1] [m2].idproducto == id)
                    {
                        do
                        {
                            for (int i = 0; i < 20; i++)
                            {
                                for (int j = 0; j < 20; j++)
                                {
                                    cout<<"\n\tStock actual: "<<productosready2[m1] [m2].stock;
                                    cout<<"\n\tNuevo Stock: ";
                                    cin>>stockn;
                                    productosready2[m1] [m2].stock -= stockn;
                                    cout<<"\n\tDesea volver a modificar el stock? S/N ";
                                    cin>>opc2;
                                    m1 = i;
                                    m2 = j;
                                }
                            }
                        } while (opc2 == 'S'); return stock();
                    }
                }
        break;
        case 3:
            cout<<"\n\tIngrese el ID del producto: ";
            cin>>id;
            system("cls");
                if (comprobarid(id, true))
                {
                    if (productosready2[m1] [m2].idproducto == id)
                    {
                        do
                        {
                            for (int i = 0; i < 20; i++)
                            {   
                                for (int j = 0; j < 3; j++)
                                {
                                    cout<<"\n\tStock actual: "<<productosready2[m1] [m2].stock;
                                    cout<<"\n\tDesea volver a ver el stock? S/N ";
                                    cin>>opc2;
                                    m1 = i;
                                    m2 = j;
                                }
                            }
                        } while (opc2 == 'S'); return stock();
                    }
                }
        break;
        case 4:
        	main();
        break;
        case 5:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
}

void rgventas()
{
	int opc;
	cout<<"\n\t--R E G I S T R O S  D E  V E N T A S--";
    cout<<"\n\n\tOPCIONES";
    cout<<"\n";
    cout<<"\n\t1- Ingresar nueva venta(s)";
    cout<<"\n\t2- Ver ventas";
    cout<<"\n\t3- Volver al menu principal";
    cout<<"\n\t4- SALIR";
    cout<<"\n";
    cout<<"\n\t";
    cout<<"\n\tIngrese una opcion: ";
    cin>>opc;
	system("cls");
    switch (opc)
    {
        case 1:
            
        break;
        case 2:
            
        break;
        case 3:
        	main();
        break;
        case 4:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
}

void clientes()
{
	int opc, id;
	cout<<"\n\t--C L I E N T E S--";
    cout<<"\n\n\tOPCIONES";
    cout<<"\n";
    cout<<"\n\t1- Ingresar nuevo cliente(s)";
    cout<<"\n\t2- Ver clientes";
    cout<<"\n\t3- Volver al menu principal";
    cout<<"\n\t4- SALIR";
    cout<<"\n";
    cout<<"\n\t";
    cout<<"\n\tIngrese una opcion: ";
    cin>>opc;
	system("cls");
    switch (opc)
    {
        case 1:
            do
            {
                for (int i = 0; i < 20; i++)
                {   
                    for (int j = 0; j < 3; j++)
                    {
                        cout<<"\n\tNombre: ";
                        cin>>clientesready [i].nom;
                        cout<<"\n\tID (identificador): ";
                        cin>>clientesready2 [i] [j].idcliente;
                        cout<<"\n\tCredito: ";
                        cin>>clientesready2 [i] [j].credito;
                        cout<<"\n\tAdeudo: ";
                        cin>>clientesready2 [i] [j].adeudo;
                        m1 = i;
                        m2 = j;
                    }
                }
            } while (opc2 == 'S'); return stock();
        break;
        case 2:
            cout<<"\n\tIngrese el ID del cliente: ";
            cin>>id;
            system("cls");
                if (comprobaridcliente(id, true))
                {
                    if (clientesready2 [m1] [m2].idcliente == id)
                    {
                        do
                        {
                            for (int i = 0; i < 20; i++)
                            {   
                                for (int j = 0; j < 3; j++)
                                {
                                    cout<<"\n\tNombre: "<<clientesready [i].nom;
                                    cout<<"\n\tID (identificador): "<<clientesready2 [0] [j].idcliente;
                                    cout<<"\n\tCredito: "<<clientesready2 [i] [j].credito;
                                    cout<<"\n\tAdeudo: "<<clientesready2 [i] [j].adeudo;
                                    m1 = i;
                                    m2 = j;
                                }
                            }
                        } while (opc2 == 'S'); return stock();
                    }
                }
        break;
        case 3:
        	main();
        break;
        case 4:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
}

void basedatosproductos()
{
    productosready [0] [0].nomproduc = "PAN BIMBO";
    productosready [1] [1].desc = "Harina de trigo, agua, levadura, aceite vegetal (girasol), sal, conservadores (E 282, E 200), \n emulgentes (E 471, E 472e), vinagre de vino, harina de haba, almidón de trigo y maíz, \n agentes de tratamiento de la harina (E 300, E 341). Puede contener semillas de sésamo y/o soja.\n\n";
    productosready2 [0] [0].idproducto = 01;
    productosready2 [1] [1].precio = 40;
    productosready2 [2] [2].stock = 5;

    productosready [1] [0].nomproduc = "LECHE";
    productosready [3] [1].desc = "Leche entera de vaca, Lactasa, Vitamina A (microgramos equivalentes de retinol) \n y Vitamina D, Grasa de leche 33 g/L, Proteina de leche 32 g/L, \n Lactosa 0 g/L, Glucosa: 16 g/L, Galactosa: 16 g/L, \n contiene 5 microgramos de Vitamina D/L y \n 664 microgramos equivalentes de retinol (Vitamina A)/L.\n\n";
    productosready2 [3] [0].idproducto = 02;
    productosready2 [4] [1].precio = 15;
    productosready2 [5] [2].stock = 5;
}

void basedatosclientes()
{
    clientesready [0].nom = "ramiro";
    clientesready2 [0] [0].idcliente = 001;
    clientesready2 [1] [1].credito = 5000;
    clientesready2 [2] [2].adeudo = 250;

    clientesready [1].nom = "messi";
    clientesready2 [3] [0].idcliente = 002;
    clientesready2 [4] [1].credito = 5000;
    clientesready2 [5] [2].adeudo = 650;
}

bool comprobarid(int bs, bool up)
{
	int i = 0;
	if(up == true)
	{
		for(i=0; i<= 20; i++)
		{
            for (int j = 0; j < 3; j++)
            {
                if(productosready2 [i] [j].idproducto == bs)
                {
                    m1 = i;
                    m2 = j;
                    return true;
                }
            }
		}
	}
}

bool comprobaridcliente(int bs, bool up)
{
	int i = 0;
	if(up == true)
	{
		for(i=0; i<= 20; i++)
		{
            for (int j = 0; j < 3; j++)
            {
                if(clientesready2 [i] [j].idcliente == bs)
                {
                    m1 = i;
                    m2 = j;
                    return true;
                }
            }
		}
	}
}