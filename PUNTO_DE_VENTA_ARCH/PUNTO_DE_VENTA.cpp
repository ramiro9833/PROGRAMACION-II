#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //USO DE LA LIBRERIA fstream PARA EL MANEJO DE ARCHIVOS
#include <windows.h>
using namespace std;
struct usersdatos//ESTRUCTURA USUARIOS
{
    string user;
    string password;
};
struct usersdatos base[3]; //MATRIZ USERS
//VARIABLES DE TIPO GLOBALES PARA EL PROGRAMA
bool encontrado = false;
int m1, opc;
char opc2, op3;
string nom;
string nomproduc;
int idcliente=0, auxclavecliente=0, credito, adeudo, auxabono, total_cliente, opn, ncredito;
int idproducto=0, auxclave=0,stock, cantidad, precio;
int auxstock, stock_final, cantidad_total, precio_total, ct, total;
//FUNCIONES PARA CADA OPCION DE LOS PRODUCTOS
void productos();
void nuevo_producto();
void eliminar_producto();
void ver_producto();
//FUNCIONES PARA CADA OPCION DE LOS CLIENTES
void clientes();
void nuevo_cliente();
void eliminar_cliente();
void adeudo_cliente();
void ver_cliente();
//FUNCIONES PARA CADA OPCION DE LAS VENTAS
void rgventas();
void nueva_venta();
void ver_ventas();
//FUNCIONES PARA CADA OPCION DEL STOCK DE LOS PRODUCTOS
void fnstock();
void nuevo_stock();
void eliminar_stock();
void ver_stocks();
//FUNCION CORTE DE CAJA
void cortecaja();
//FUNCION PARA USUARIOS REGRISTRADOS
void usuariosabarrotes();
bool buscarusuario(string, bool);
int validarDato();
void menu();

int main()
{
	usuariosabarrotes();
    string user1, password1;
        //LOGIN DE USUARIO
    cout<<"\n\t\t--B I E N V E N I D O--";
    cout<<"\n\n";
    cout<<"\t\tIngrese Usuario: ";
    cin>>user1;
    if (buscarusuario(user1, true))
    {
        cout<<"\t\tIngrese contrasena: ";
        cin>>password1;
        if (buscarusuario(password1, false))
        {
            system("cls");
                    //VERIFICAR USUARIO Y CONTADOR DE INTENTOS PARA EL ACCESO AL PUNTO DE VENTA
            if ((base[m1].user==user1) && (base[m1].password==password1))
            {
                menu();
            }
            else
            {
            	system("cls");
                cout<<"\n\n\n";
                cout<<"\t------------------------------------------------\n";
                cout<<"\t\t     Usuario y/o Contraseña incorrectos";
                cout<<"\n\t------------------------------------------------\n\n";
                system("pause");
		        system("cls"); return main();
            }
        }
        else
        {
            system("cls");
        	cout<<"\n\n\n";
            cout<<"\t------------------------------------------------\n";
            cout<<"\t\t          PIN invalido";
            cout<<"\n\t------------------------------------------------\n\n";
            system("pause");
            system("cls"); return main();
        }
    }
    else
    {
        system("cls");
        cout<<"\n\n\n";
        cout<<"\t------------------------------------------------\n";
        cout<<"\t\t        Usuario incorrecto";
        cout<<"\n\t------------------------------------------------\n\n";
        system("pause");
        system("cls"); return main();
    }
    system("cls");
    getch();
    return 0;
}
void menu()
{
    int opc;
    cout<<"\n\tPUNTO DE VENTA --A B A R R O T E S  D O N A  M A R T H A-- \n\n"; //MENU PRINCIPAL
    std::cout<<"\t --------------------------";
    std::cout<<"\n\t|       1- Productos       |"<<endl;
    std::cout<<"\t --------------------------";
    std::cout<<"\n\t|         2- STOCK         |"<<endl;
    std::cout<<"\t --------------------------";
    std::cout<<"\n\t|        3- Clientes       |"<<endl;
    std::cout<<"\t --------------------------";
    std::cout<<"\n\t|   4- Registro de ventas  |"<<endl;
    std::cout<<"\t --------------------------";
    std::cout<<"\n\t|     5- Corte de caja     |"<<endl;
    std::cout<<"\t --------------------------";
    std::cout<<"\n\t|         6- Salir         |"<<endl;
    std::cout<<"\t --------------------------";   
    cout<<"\n\n";
    cout<<"\n\tIngrese una opcion: ";
    opc=validarDato();
    switch (opc)
    {				//FUNCIONES PRINCIPALES
        case 1: 
        	system("cls");
            productos();
        break;
        case 2:
        	system("cls");
            fnstock();
        break;
        case 3:
        	system("cls");
            clientes();
        break;
        case 4:
        	system("cls");
        	rgventas();
        break;
        case 5:
        	system("cls");
            cortecaja();
        break;
        case 6:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
    getch();
}
void productos()
{
	int opc;
    cout<<"\n\t--P R O D U C T O S--";
    cout<<"\n\n\tOPCIONES\n";   
    std::cout<<"\t -------------------------------------";
    std::cout<<"\n\t|    1- Ingresar nuevo producto(s)    |"<<endl;
    std::cout<<"\t -------------------------------------";
    std::cout<<"\n\t|          2- Ver producto(s)         |"<<endl;
    std::cout<<"\t -------------------------------------";
    std::cout<<"\n\t|       3- Eliminar producto(s)       |"<<endl;
    std::cout<<"\t -------------------------------------";
    std::cout<<"\n\t|              4- Volver              |"<<endl;
    std::cout<<"\t -------------------------------------";
    std::cout<<"\n\t|              5- Salir               |"<<endl;
    std::cout<<"\t -------------------------------------";
    cout<<"\n\tIngrese una opcion: ";
    opc=validarDato();
    system("cls");
    switch (opc)
    {
        case 1://DECLARACION DE UN NUEVO PRODUCTO     
            system("cls");
            nuevo_producto();
        break;
        case 2://VER PRODUCTOS  
            system("cls");
            ver_producto();
        break;
        case 3://ELIMINACION DE UN PRODUCTO
            system("cls");
            eliminar_producto();   
        break;
        case 4:
        	menu();
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
void nuevo_producto()
{
    //Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ifstream consulta;

    do{
	    escritura.open("productos.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
	    consulta.open("productos.txt", ios::in);//solamente consulta o lee usando la variable sobre el ararchivo físico productos.txt
        if (escritura.is_open() && consulta.is_open())
        {
            bool repetido=false;
            cout<<"\n\t--N U E V O  P R O D U C T O--\n";
            cout<<"\tIngrese el ID del producto: ";
            cin>>auxclave;
            //A continuación se aplica el tipo de lectura de archivos secuencial
            consulta>>idproducto;
            while (!consulta.eof()){
                consulta>>nomproduc>>stock>>precio;
                if (auxclave==idproducto){
                    repetido=true;
                    cout<<"\t\tLa clave de este producto ya se encuentra registrada...\n";
                    break;
                }
                consulta>>idproducto;
            }
            if (repetido==false){
                cin.ignore();
                cout<<"\tIngresa el nombre del producto:  ";
                std::getline(cin,nomproduc);
                cout<<"\tIngresa el stock del producto: ";
                cin>>stock;
                cout<<"\tIngrese el precio del producto:  $";
                cin>>precio;
                //ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
                escritura<<auxclave<<" "<<nomproduc<<" "<<stock<<" "<<precio<<" "<<endl;
                cout<<"\n\tProducto agregado...\n";
            }
            cout<<"\n\tDeseas ingresar otro producto? (S/N): ";
            cin>>opc2;
        }else{
            cout<<"\n\tEl archivo no se pudo abrir...\n";
        }
        escritura.close();
        consulta.close();
    }while (opc2=='N' or opc2=='n');
    system("cls");
    return productos();
}
void eliminar_producto()
{
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("auxiliar_productos.txt", ios::out);
    lectura.open("productos.txt", ios::in);
    if (aux.is_open() && lectura.is_open()){
        cout<<"\n\t--E L I M I N A R  P R O D U C T O--"; 
        cout<<"\n\n";
        cout<<"\tIngresa la clave del producto que deseas eliminar: ";
        cin>>auxclave;
        ///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
        ///hasta llegar al final del archivo gracias a la función .eof()
        lectura>>idproducto;
        while (!lectura.eof()){
            lectura>>nomproduc>>stock>>precio;
            if (auxclave==idproducto)
            {
                encontrado=true;
                cout<<"\n";
                cout<<"\tID producto: "<<idproducto<<endl;
                cout<<"\tNombre: "<<nomproduc<<endl;
                cout<<"\tStock: "<<stock<<endl;
                cout<<"\tPrecio: $"<<precio<<endl;;
                cout<<"\t________________________________\n\n";
                cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                cin>>opc2;
                if ((opc2=='S')||(opc2=='s')){
                    cout<<"\n\n\t\t\tProducto "<<nomproduc<<" eliminado...\n\n\t\t\a";
                    cout<<"\n\tDesea eliminar otro producto? S | N ";cin>>op3;
                    if(op3=='S' or op3=='s')
					{
						cout<<"\n\t";system("pause");system("cls");return eliminar_producto();
					}
					else
					{
						cout<<"\n\tRegresando al menu...\n\t";
						system("pause");system("cls");return productos();
					}
                }
                else
                {
                    aux<<idproducto<<" "<<nomproduc<<" "<<stock<<" "<<precio<<" "<<endl;
                }
            }
            else
            {
                aux<<idproducto<<" "<<nomproduc<<" "<<stock<<" "<<precio<<" "<<endl;;
            }
            lectura>>idproducto;
        }
    }
    else
    {
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false)
    {
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
        cout<<"\n\Intentelo de nuevo... \n\t";system("pause");system("cls");return eliminar_producto();
    }
    aux.close();
    lectura.close();
    remove ("productos.txt");
    rename("auxiliar_productos.txt", "productos.txt");
    system("pause");
	system("cls");
	return productos();
}
void ver_producto()
{  //Lectura de archivos
    ifstream lectura;
    lectura.open("productos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       cout<<"\n\t--P R O D U C T O S--\n\n";
       lectura>>idproducto;
       while (!lectura.eof())
       {
            lectura>>nomproduc>>stock>>precio;
            cout<<"\n";
            cout<<"\tID producto: "<<idproducto<<endl;
            cout<<"\tNombre: "<<nomproduc<<endl;
            cout<<"\tStock: "<<stock<<endl;
            cout<<"\tPrecio: $"<<precio<<endl;
            lectura>>idproducto;
            cout<<"\t________________________________\n";
            Sleep(1000);
       }cout<<"\n\t";system("pause");
    }
    else
    {
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
	system("cls");
	return productos();
}
void fnstock()
{
	int opc;
    cout<<"\n\t--S T O C K--";
    cout<<"\n\n\tOPCIONES\n";
    std::cout<<"\t ---------------------------------------------";
    std::cout<<"\n\t|    1- Ingresar nuevo stock de product(s)    |"<<endl;
    std::cout<<"\t ---------------------------------------------";
    std::cout<<"\n\t|       2- Eliminar stock a producto(s)       |"<<endl;
    std::cout<<"\t ---------------------------------------------";
    std::cout<<"\n\t|                3- Ver stocks                |"<<endl;
    std::cout<<"\t ---------------------------------------------";
    std::cout<<"\n\t|                  4- Volver                  |"<<endl;
    std::cout<<"\t ---------------------------------------------";
    std::cout<<"\n\t|                  5- Salir                   |"<<endl;
    std::cout<<"\t ---------------------------------------------";
    cout<<"\n\tIngrese una opcion: ";
    opc=validarDato();
	system("cls");
    switch (opc)
    {
        case 1:
            system("cls");
            nuevo_stock();
        break;
        case 2:
            system("cls");
            eliminar_stock();
        break;
        case 3:
            system("cls");
            ver_stocks();
        break;
        case 4:
        	menu();
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
void nuevo_stock()
{
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("auxiliar_productos.txt", ios::out);
    lectura.open("productos.txt", ios::in);
    if (aux.is_open() && lectura.is_open())
    {
    	cout<<"\n\t--N U E V O  S T O C K--\n\n";
        cout<<"\tIngresa la clave del producto que deseas modificar: ";
        cin>>auxclave;
        lectura>>idproducto;
        while (!lectura.eof())
        {
            lectura>>nomproduc>>stock>>cantidad>>precio;
            if (auxclave==idproducto)
            {
                cout<<"\n";
                cout<<"\tID producto: "<<idproducto<<endl;
                cout<<"\tNombre: "<<nomproduc<<endl;
                cout<<"\tStock: "<<stock<<endl;
                cout<<"\tPrecio: $"<<precio<<endl;
                cout<<"\t________________________________\n\n";
                cout<<"\tIngresa el nuevo stock del producto: "<<auxclave<<"\n\n\t---> ";cin>>auxstock;
                if(auxstock <= 0)
                {
                	cout<<"\n\tCantidad invalida...";
                	cout<<"\n\tIntentelo de nuevo\n\t";system("pause");system("cls");return nuevo_stock();
				}
				else
				{
					aux<<idproducto<<" "<<nomproduc<<" "<<auxstock<<" "<<precio<<" "<<endl;
                	cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
                	cout<<"Desea cambiar el stock de otro producto? S | N ";cin>>opc2;
                	if((opc2=='S')||(opc2=='s'))
                	{
                		cout<<"\n\tRegresando...\n\t";system("pause");system("cls");return nuevo_stock();
					}
					else
					{
                		cout<<"\n\tRegresando al menu...\n\t";system("pause");system("cls");return fnstock();
					}
				}
				encontrado=true;
				break;
            }
            else
            {
                aux<<idproducto<<" "<<nomproduc<<" "<<stock<<" "<<cantidad<<" "<<precio<<" "<<endl;
            }
            lectura>>idproducto;
        }
    }
    else
    {
    	cout<<"\n\tError...";
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    if (encontrado==false)
	{
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
        cout<<"Intentelo de nuevo...\n\t";system("pause");system("cls");return nuevo_stock();
	}
    aux.close();
    lectura.close();
    remove ("productos.txt");
    rename("auxiliar_productos.txt", "productos.txt");
    system("pause");system("cls");return fnstock();
}
void eliminar_stock()
{
    ofstream auxfn;
    ifstream lectura;
    encontrado=false;
    auxfn.open("auxiliar_productos.txt", ios::out);
    lectura.open("productos.txt", ios::in);
    if (auxfn.is_open() && lectura.is_open())
    {
        cout<<"\n";
        cout<<"\tIngresa la clave del producto modificar el stock: ";
        cin>>auxclave;
        lectura>>idproducto;
        while (!lectura.eof())
        {
            lectura>>nomproduc>>stock>>cantidad>>precio;
            if (auxclave==idproducto)
            {
                encontrado=true;
                cout<<"\n";
                cout<<"\tID producto: "<<idproducto<<endl;
                cout<<"\tNombre: "<<nomproduc<<endl;
                cout<<"\tStock actual: "<<stock<<endl;
                cout<<"\tPrecio: $"<<precio<<endl;
                cout<<"\t________________________________\n\n";
                cout<<"\tSeguro que desea realizar eliminar el stock del producto: "<<idproducto<<"? S | N";cin>>opc2;
                if((opc2=='S')||(opc2=='s'))
                {
                	cout<<"\tel nuevo stock del producto: "<<auxclave<<", es: "<<0;
	                auxstock = 0;
	                auxfn<<idproducto<<" "<<nomproduc<<" "<<auxstock<<" "<<cantidad<<" "<<precio<<" "<<endl;
	                cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
				}
				else
				{
					auxfn<<idproducto<<" "<<nomproduc<<" "<<stock<<" "<<cantidad<<" "<<precio<<endl;
					cout<<"\n\tCambio de stock cancelado, Regresando al menu...";
					system("pause");system("cls");return fnstock();
				}
            }
            else
            {
                auxfn<<idproducto<<" "<<nomproduc<<" "<<stock<<" "<<cantidad<<" "<<precio<<endl;
            }
            lectura>>idproducto;
        }
    }
    else
    {
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    if (encontrado==false)
	{
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
	}
    auxfn.close();
    lectura.close();
    remove ("productos.txt");
    rename("auxiliar_productos.txt", "productos.txt");
    system("pause");system("cls");return fnstock();
}
void ver_stocks()
{
	ifstream lectura;
    lectura.open("productos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>idproducto;
       while (!lectura.eof())
       {
            lectura>>nomproduc>>stock>>precio;
            cout<<"\n";
            cout<<"\tID producto: "<<idproducto<<endl;
            cout<<"\tNombre: "<<nomproduc<<endl;
            cout<<"\tStock: "<<stock<<endl;
            cout<<"\tPrecio: $"<<precio<<endl;
            lectura>>idproducto;
            cout<<"\t________________________________\n";
       }cout<<"\n\t";system("pause");
    }
    else
    {
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
	system("cls");return fnstock();
}
void rgventas()
{
	cout<<"\n\t--R E G I S T R O S  D E  V E N T A S--";
    cout<<"\n\n\tOPCIONES";
    cout<<"\n";
    std::cout<<"\t ---------------------------------";
    std::cout<<"\n\t|    1- Ingresar nueva venta(s)   |"<<endl;
    std::cout<<"\t ---------------------------------";
    std::cout<<"\n\t|          2- Ver ventas          |"<<endl;
    std::cout<<"\t ---------------------------------";
    std::cout<<"\n\t|            3- Volver            |"<<endl;
    std::cout<<"\t ---------------------------------";
    std::cout<<"\n\t|            4- Salir             |"<<endl;
    std::cout<<"\t ---------------------------------";
    cout<<"\n\tIngrese una opcion: ";
    opc=validarDato();
	system("cls");
    switch (opc)
    {
        case 1:
            system("cls");
            nueva_venta();
        break;
        case 2:
            system("cls");
            ver_ventas();
        break;
        case 3:
        	menu();
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
void nueva_venta()
{
	///Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ofstream cambio;
    ifstream consulta;
    bool repetido=false;

    escritura.open("ventas.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
    cambio.open("productos.txt", ios::out | ios::app);
    consulta.open("productos.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico productos.txt
    if (escritura.is_open() && consulta.is_open())
    {
        cout<<"\n\t--N U E V A  V E N T A--";
        cout<<"\n";
        cout<<"\tIngresa el ID del producto: ";cin>>auxclave;
        consulta>>idproducto;     //A continuación se aplica el tipo de lectura de archivos secuencial para la variable idproducto
        while (!consulta.eof())
        {
            consulta>>nomproduc>>stock>>precio;
            if (auxclave==idproducto)
            {
                cout<<"\n\tCantidad comprada del producto: ";
                cin>>ct;
                if(ct > stock)
                {
                	cout<<"\n\tCantidad invalida...";cout<<"\n\tIngrese una cantidad menor a "<<stock<<" del producto seleccionado\n\t";
                	system("pause");system("cls");return nueva_venta();
				}
				else
				{
					cantidad_total = cantidad_total + ct;
	                stock_final = stock - ct;
	                total = ct * precio;
	                cout<<"\n\tTotal: "<<total;
	                precio_total = precio_total + total;
	                escritura<<auxclave<<" "<<nomproduc<<" "<<ct<<" "<<total<<" "<<stock_final<<" "<<endl;
	                cambio<<idproducto<<" "<<nomproduc<<" "<<stock_final<<" "<<precio<<" "<<endl;
	                cout<<"\n\tDeseas ingresar otro venta? S | N ";cin>>opc2;
	                if(opc2=='N' or opc2=='n')
		            {
		                cout<<"\n\tRegresando al menu de ventas...";
		                system("pause");system("cls");return rgventas();
		            }
		            else
		            {
		            	cout<<"\n\tRegresando...";
		                system("pause");system("cls");return nueva_venta();
		            }
				}
                repetido=true;
                break;
            }
            consulta>>idproducto;   
        }
        if (repetido==false)
        {
            cout<<"\t\tEl producto con el ID: "<<auxclave<<" No se encuentra...\n";
        }
    }
    else
    {
        cout<<"\n\tError...";
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    escritura.close();
    cambio.close();
    consulta.close();
    system("pause");system("cls");return rgventas();
}
void ver_ventas()
{
	 //Lectura de archivos
    ifstream lectura;
    lectura.open("ventas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>idproducto;
       while (!lectura.eof())
       {
            lectura>>nomproduc>>ct>>total>>stock_final;
            cout<<"\n";
            cout<<"\tID producto: "<<auxclave<<endl;
            cout<<"\tNombre: "<<nomproduc<<endl;
            cout<<"\tCantidad comprada: "<<ct<<endl;
            cout<<"\tTotal: $"<<total<<endl;
            cout<<"\tStock final: "<<stock_final<<endl;
            lectura>>idproducto;
            cout<<"\t________________________________\n";
       }cout<<"\n\t";system("pause");
    }
	else
	{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
    system("pause");system("cls");return rgventas();
}
void clientes()
{
	cout<<"\n\t--C L I E N T E S--";
    cout<<"\n\n\tOPCIONES";
    cout<<"\n";
    std::cout<<"\t --------------------------------";
    std::cout<<"\n\t|    1- Ingresar nuevo cliente   |"<<endl;
    std::cout<<"\t --------------------------------";
    std::cout<<"\n\t|          2- Ver cliente        |"<<endl;
    std::cout<<"\t --------------------------------";
    std::cout<<"\n\t|        3- Adeudo cliente       |"<<endl;
    std::cout<<"\t --------------------------------";
    std::cout<<"\n\t|       4- Eliminar cliente      |"<<endl;
    std::cout<<"\t --------------------------------";
    std::cout<<"\n\t|            5- Volver           |"<<endl;
    std::cout<<"\t --------------------------------";
    std::cout<<"\n\t|            6- Salir            |"<<endl;
    std::cout<<"\t --------------------------------";
    cout<<"\n\tIngrese una opcion: ";
    opc=validarDato();
	system("cls");
    switch (opc)
    {
        case 1:
        	nuevo_cliente();
        break;
        case 2:
            ver_cliente();
        break;
        case 3:
        	adeudo_cliente();
        break;
        case 4:
            eliminar_cliente();
        break;
        case 5:
        	menu();
        break;
        case 6:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
}
void nuevo_cliente()
{
    //Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ifstream consulta;
    
    escritura.open("clientes_PV.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
    consulta.open("clientes_PV.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico clientes_PV.txt
    if (escritura.is_open() && consulta.is_open())
    {  //INGRESAR NUEVO CLIENTE
        bool repetido=false;   
        system("cls");
        cout<<"\n\t--N U E V O  C L I E N T E --";
        cout<<"\n\tID (identificador): ";
        cin>>auxclavecliente;
        //APLICAMOS LA LECTURA DE ARCHIVOS SECUENCIAL
        consulta>>idcliente;
        while (!consulta.eof())
        {
            consulta>>nom>>credito>>adeudo;
            if (auxclavecliente==idcliente)
            {
                repetido=true;
                cout<<"\t\tYa existe la clave del cliente...\n";
                return nuevo_cliente();
                break;
            }
            consulta>>idcliente;
        }
        if(repetido == false)
        {
            cin.ignore();
            cout<<"\n\tNombre: ";
            getline(cin, nom);
            cout<<"\n\tCredito: $";
            cin>>credito;
            cout<<"\n\tAdeudo: $";
            cin>>adeudo;
            escritura<<auxclavecliente<<" "<<nom<<" "<<credito<<" "<<adeudo<<" "<<endl;
            cout<<"\n\tCliente agregado...\n";
            cout<<"\nDesea ingresar otro cliente? S/N ";
            cin>>opc2;
            if(opc2=='S' or opc2=='s')
            {
				cout<<"\n\t";system("pause");system("Cls");return nuevo_cliente();
            }
            else
            {
                cout<<"\n\tLimpiando pantalla";
                system("pause");return nuevo_cliente();
            }
            system("cls");
        }
    }
    else
    {
        cout<<"El archivo no se pudo abrir \n";
    }
    escritura.close();
    consulta.close();
    system("cls");return clientes();
}
void adeudo_cliente()
{
	ofstream aux;
    ifstream lectura;
    
    encontrado=false;

    aux.open("aux_clientes_PV.txt", ios::out);
    lectura.open("clientes_PV.txt", ios::in);
    if (aux.is_open() && lectura.is_open())
	{
        cout<<"\n";
        cout<<"\tIngresa la clave del cliente: ";
        cin>>auxclavecliente;
        lectura>>idcliente;
        while (!lectura.eof())
		{
            lectura>>nom>>credito>>adeudo;
            if (auxclavecliente==idcliente)
			{
				encontrado = true;
				cout<<"\n\tQue desea hacer...";
				cout<<"\n\t1- Abonar al adeudo del cliente";
				cout<<"\n\t2- Sumar al adeudo del cliente";
				cout<<"\n\t3- Volver al menu";
				cout<<"\n\n\tOpcion: ";
				opn=validarDato();
				switch(opn)
				{
					case 1:
						system("cls");
						if(adeudo == 0)
						{
							cout<<"\n\tEl adeudo del cliente es de $0, no se puede abonar mas...\n\t";
							system("pause");system("cls");return adeudo_cliente();
						}
						else
						{
							cout<<"\n";
			                cout<<"\tID cliente: "<<idcliente<<endl;
			                cout<<"\tNombre: "<<nom<<endl;
			                cout<<"\tCredito: $"<<credito<<endl;
			                cout<<"\tAdeudo: $"<<adeudo<<endl;
			                cout<<"\t________________________________\n\n";
			                cout<<"\tIngresa el abono del cliente "<<nom<<" \n\n\t---> $";
			                cin>>auxabono;
			                if(auxabono <= 0)
			                {
			                	cout<<"\n\tError...";
			                	cout<<"\n\tIngrese una cantidad valida \n\t";
								system("pause");system("cls");return adeudo_cliente();
							}
							else
							{
								total_cliente = adeudo - auxabono;
				                aux<<idcliente<<" "<<nom<<" "<<credito<<" "<<total_cliente<<" "<<endl;
				                cout<<"\n\n\t\t\tAdeudo del cliente "<<nom<<" restado...\n\t\t\a";
				                cout<<"\n\t\tAdeudo final es: $"<<total_cliente<<"\n";system("pause");
							}
						}
					break;
					case 2:
						system("cls");
						cout<<"\n";
		                cout<<"\tID cliente: "<<idcliente<<endl;
		                cout<<"\tNombre: "<<nom<<endl;
		                cout<<"\tCredito: $"<<credito<<endl;
		                cout<<"\tAdeudo: $"<<adeudo<<endl;
		                cout<<"\t________________________________\n\n";
		                cout<<"\tIngresa el adeudo del cliente "<<nom<<" \n\n\t---> $";
		                cin>>auxabono;
		                if(auxabono <= 0)
		                {
		                	cout<<"\n\tError...";
		                	cout<<"\n\tIngrese una cantidad valida \n\t";
							system("pause");system("cls");return adeudo_cliente();
						}
						else if(auxabono > credito)
						{
							cout<<"\n\tLa cantidad excede el credito del cliente";
		                	cout<<"\n\tDesea aumentar el credito o cancelar el movimiento: ";
		                	opn=validarDato();
		                	switch(opn)
		                	{
		                		case 1:
		                			total_cliente = adeudo + auxabono;
		                			ncredito = total_cliente;
					                aux<<idcliente<<" "<<nom<<" "<<ncredito<<" "<<total_cliente<<" "<<endl;
					                cout<<"\n\n\t\t\tAdeudo del cliente "<<nom<<" aumentado...\n\t\t\a";
					                cout<<"\n\t\tAdeudo final es: $"<<total_cliente<<"\n";system("pause");
		                		break;
		                		case 2:
		                			cout<<"\n\tMovimiento cancelado...";
				                	cout<<"\n\tRegresando al menu \n\t";
									system("pause");system("cls");return adeudo_cliente();
		                		break;
							}
						}
						else
						{
							total_cliente = adeudo + auxabono;
			                aux<<idcliente<<" "<<nom<<" "<<credito<<" "<<total_cliente<<" "<<endl;
			                cout<<"\n\n\t\t\tAdeudo del cliente "<<nom<<" aumentado...\n\t\t\a";
			                cout<<"\n\t\tAdeudo final es: $"<<total_cliente<<"\n";system("pause");
						}
					break;
					case 3:
						cout<<"\n\tRegresando al menu de clientes...\n\t";
						system("pause");system("cls");return clientes();
					break;system("cls");
				}   
            }
			else
			{
            	aux<<idcliente<<" "<<nom<<" "<<credito<<" "<<adeudo<<" "<<endl;
            }lectura>>idcliente;
        }
    }
	else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    if (encontrado==false)
	{
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclavecliente<<"\n\n\t\t\t";
	}
    aux.close();
    lectura.close();
    remove ("clientes_PV.txt");
    rename("aux_clientes_PV.txt", "clientes_PV.txt");
    system("pause");system("cls");return clientes();
}
void eliminar_cliente()
{
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("aux_clientes_PV.txt", ios::out);
    lectura.open("clientes_PV.txt", ios::in);
    if (aux.is_open() && lectura.is_open())
    {
		cout<<"\n\t--E L I M I N A R  C L I E N T E --";
        cout<<"\n";
        cout<<"\tIngresa la clave del cliente que deseas eliminar: ";
        cin>>auxclavecliente;       
        //De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
        //hasta llegar al final del archivo gracias a la función .eof()
        lectura>>idcliente;
        while (!lectura.eof())
        {
            lectura>>nom>>credito>>adeudo;
            if (auxclavecliente==idcliente)
            {
                encontrado=true;
                cout<<"\n";
                cout<<"\tID cliente:  "<<idcliente<<endl;
                cout<<"\tNombre:   "<<nom<<endl;
                cout<<"\tCredito: $"<<credito<<endl;
                cout<<"\tAdeudo:  $"<<adeudo<<endl;
                cout<<"\t________________________________\n\n";
                cout<<"\tRealmente deseas eliminar el registro actual? (S/N) ---> ";
                cin>>opc2;
                if (opc2=='S' or opc2=='s')
                {
                    cout<<"\n\n\t\t\tRegistro del cliente --"<<nom<<"-- eliminado...\n\n\t\t\a";
                    cout<<"\n\tDesea eliminar otro cliente? S | N ";cin>>op3;
                    if(op3=='S' or op3=='s')
					{
						cout<<"\n\t";system("pause");system("cls");return eliminar_cliente();
					}
					else
					{
						cout<<"\n\tRegresando al menu...\n\t";
						system("pause");system("cls");return clientes();
					}
                }
                else
                {
                    aux<<idcliente<<" "<<nom<<" "<<credito<<" "<<adeudo<<" "<<endl;
                }
            }
            else
            {
                aux<<idcliente<<" "<<nom<<" "<<credito<<" "<<adeudo<<" "<<endl;
            }lectura>>idcliente;
        }
    }
    else
    {
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    if(encontrado==false)
    {
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclavecliente<<"\n\n\t\t\t";
        cout<<"\n\Intentelo de nuevo... \n\t";system("pause");system("cls");return eliminar_cliente();
    }
    aux.close();
    lectura.close();
    remove("clientes_PV.txt");
    rename("aux_clientes_PV.txt", "clientes_PV.txt");
    system("pause");system("cls");return clientes();
}
void ver_cliente()
{
	//Lectura de archivos
    ifstream lectura;
    lectura.open("aux_clientes_PV.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open())
    {
        system("cls");
        cout<<"\n\t--V E R  C L I E N T E S--";
        //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
        lectura>>idcliente;
        while (!lectura.eof())
        {
            lectura>>nom>>credito>>adeudo;
            cout<<"\n\n";
            cout<<"\tID cliente: "<<idcliente<<endl;
            cout<<"\tNombre:  "<<nom<<endl;
            cout<<"\tCredito: $"<<credito<<endl;
            cout<<"\tAdeudo:  $"<<adeudo<<endl;
            lectura>>idcliente;
            cout<<"\t________________________________\n";   
			Sleep(1000);
        }cout<<"\n\n\t";system("pause");
    }
    else
    {
    	cout<<"\n\tError...";
        cout<<"\n\tEl archivo no se pudo abrir \n";system("pause");
    }
	system("cls");
	return clientes();
}
void cortecaja()
{
    int opc, id;
    char opc2;
	cout<<"\n\t--C O R T E  D E  C A J A S--";
    cout<<"\n\n\tOPCIONES\n";
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|   1- Realizar corte    |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|       2- Volver        |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|       3- Salir         |"<<endl;
    std::cout<<"\t -------------------------";
    cout<<"\n\tIngrese una opcion: ";
    opc=validarDato();
	system("cls");
    switch (opc)
    {
        case 1:
	    	do
	        {
				system("cls");
				cout<<"\n\t--C O R T E  D E L  D I A--";
				ofstream imp("corte.txt");
				cout<<"\n\tTotal de productos vendidos, por unidad: "<< cantidad_total << "\n \n";
				cout<<"Total acumulado de ventas:   "<< precio_total << "\n \n";
				imp<<"TOTAL DE PRODUCTOS VENDIDOS: " << cantidad_total << "\n \n";
				imp<<"TOTAL DE VENTAS: $" << precio_total << "\n \n";		
				imp.close();	
				cout<<"\n\nDATOS IMPRESOS CORRECTAMENTE\n\n\n";
	            cout<<"\tDesea volver a ver el corte? (S/N) ";
	            cin>>opc2;
	            system("pause");
	            system("cls");
			} while (opc2 == 'S'); return menu();
        break;
        case 2:
			system("cls");
			return menu();
        break;
        case 3:
            system("cls");
            cout<<"\n \n \n";
            cout<<"\t\t--G R A C I A S   P O R   S U   V I S I T A--";
            getch();
        break;
    }
    system("cls");
}
int validarDato() 
{
    int datoleido(0);
    do
    {
        cin>>datoleido;
        while (datoleido<0) //Por si ingresa un numero negativo
        {
            cout<<"\n\tError, Vuelva a intentar: ";
            cin>>datoleido;
        }
        if (cin.fail()==true) //Por si ingresa una letra
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"\n\tError, Vuelva a intentar: ";
        }
        else
        {
            break;
        }
    } while (true); return datoleido;
}
void usuariosabarrotes() //DECLARACION DE USERS POR DEFAULT
{
    base[0].user = "ramiro";
    base[0].password = "123";
    
    base[1].user = "marcos";
    base[1].password = "579";
    
    base[2].user = "juan";
    base[2].password = "777";
}
bool buscarusuario(string bs, bool up) //BUSQUEDA Y COMPROBACION DEL ID DEl USER
{
	int i=0;
	if(up == true)
	{
		for(i=0; i<= 3; i++)
		{
			if(base[i].user == bs)
			{
				m1 = i;
				return true;
			}
		}
	}
	else
	{
		for(i=0; i<= 3; i++)
		{
			if(base[i].password == bs)
			{
				return true;
			}
		}
	}
}