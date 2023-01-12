#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream> //USO DE LA LIBRERIA fstream PARA EL MANEJO DE ARCHIVOS
#include <windows.h>

using namespace std;

//DECLARACION DE VARIABLES GLOBALES EN EL CODIGO
string user, auxuser;
int numtarjt, auxnumtarjt, nip, np, auxnip, auxnip2, m1;
float saldo=0, auxsaldo=0, ingreso=0, auxingreso=0, retiro=0, auxretiro=0,  anterior=0, cantidad=0, transferencia=0;
bool encontrado = false;
char op;
string linea;
//LLAMADO DE FUNCIONES
void menuatm();
void ingresardin();
void retirardin();
void consultarmonto();
void transferirdin();
void cambionip();
void imprimir();
//Funcion para validar datos (por si el usuario ingresa un numero negativo o una letra)
float ValidarDato() 
{
    float datoleido(0);
    bool confirmar = false;
    do
    {
        std::cin>>datoleido;

        while ((datoleido<0)||(datoleido>8)) //Por si ingresa un numero negativo
        {
            std::cout<<"\n\t\t\t\t\tError, Vuelva a intentar: ";
            std::cin>>datoleido;
        }

        if (std::cin.fail()==true) //Por si ingresa una letra
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"\n\t\t\t\t\tError, Vuelva a intentar: ";
        }
        else
        {
			confirmar=true;
            break;
        }
        
    } while (true);
    return datoleido;
}
int main()
{
    ifstream lectura; //Lectura de archivos
    lectura.open("usuarioscajero.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE EL ARCHIVO
    if (lectura.is_open())
	{
		system("cls");
	    cout<<"\n\t\t--B I E N V E N I D O--";
	    cout<<"\n\n";
	    cout<<"\t\tIngrese Usuario: ";
	    cin>>user;
	    cout<<"\t\tIngrese PIN: ";
	    cin>>np;
	    lectura>>nip;
        while (!lectura.eof())
		{
			lectura>>user>>numtarjt>>anterior>>saldo>>ingreso>>retiro>>transferencia;
            if (np==nip)
			{
				system("cls");
				menuatm();
                encontrado=true;	
				break;                 
			}lectura>>nip;
        } 	
        if (encontrado==false)
		{
	        cout<<"\n\tNIP o Usuario incorrecto...Intentelo de nuevo...\n\n\t\t\t";
	        system("pause");system("cls");main();
		}
	}
	else
	{
        std::cout<<"\n\tERROR...";
        std::cout<<"\n\tIntentelo de nuevo\n\t";
        system("pause");system("cls");main();
    }
    lectura.close();
    system("pause");
	system("cls");
}
void menuatm()
{
    int opc;
    std::cout<<"\t\t      BIENVENIDO"<<endl;
    std::cout<<"\t--C A J E R O  A U T O M A T I C O--"<<endl;
    std::cout<<"\n";
        //MENU DE OPCIONES ATM
    std::cout<<"\n\tEliga una opcion"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|    1- Ingresar dinero   |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|    2- Retirar dinero    |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|    3- Consultar saldo   |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|   4- Transferir dinero  |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|     5- Cambio de NIP    |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t| 6- Imprimir movimientos |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\t|         7- Salir        |"<<endl;
    std::cout<<"\t -------------------------";
    std::cout<<"\n\tOpcion: ";
    opc=ValidarDato();
    system("cls");
	switch (opc) //OPCIONES DEL CAJERO
	{
	    case 1: //INGRESAR DINERO A CUENTA
	    	system("cls");
	        ingresardin();
	    break;
	    case 2: //RETIRAR DINERO DE CUENTA
	    	system("cls");
	        retirardin();
	    break;
	    case 3: //CONSULTA DE SALDO
	    	system("cls");
	        consultarmonto();
	    break;
	    case 4: //TRANSFERIR DINERO
	    	system("cls");
	    	transferirdin();
	    break;
	    case 5: //CAMBIO DE NIP
	    	system("cls");
	        cambionip();
	    break;
	    case 6: //IMPRIMIR LOS ULTIMOS MOVIMIENTOS HECHOS 
	    	system("cls");
	    	imprimir();
	    break;
	    case 7: //SALIR AL MENU DE INICIO
	    	system("cls");
	        cout<<"\n\n\n\t\t--G R A C I A S   P O R   S U   V I S I T A--\n\n\t\t";
	        system("pause");
			main();
	    break;
	}system("cls");
}                          //FUNCIONES DEL CAJERO
void ingresardin()
{
	ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("auxiliar_usuarios.txt", ios::out);
    lectura.open("usuarioscajero.txt", ios::in);
    if (aux.is_open() && lectura.is_open()){
		cout<<"\t---I N R E S A R  D I N E R O---\n"<<endl;
        cout<<"\n";
        cout<<"\tMonto que desea ingresar: $";
        cin>>auxingreso;
        if(auxingreso <= 0)
        {
        	cout<<"\n\tCantidad invalida...";
			cout<<"\n\tIntentelo de nueva con otra cantidad...\n\t";
			system("pause");system("cls");return ingresardin();
		}
		else
		{
			cout<<"\n\tIngrese su NIP, para confirmar: ";
			cin>>np;
			lectura>>nip;
			while (!lectura.eof())
			{
				lectura>>user>>numtarjt>>anterior>>saldo>>ingreso>>retiro;
				if (np==nip)
				{
					encontrado=true;
					anterior = saldo;
					auxsaldo = saldo + auxingreso;
					cout<<"\n";
					cout<<"\tUsuario:    "<<user<<endl;
					cout<<"\tSaldo anterior:   "<<anterior<<endl;
					cout<<"\tIngreso: "<<auxingreso<<endl;
					cout<<"\tSaldo actual:    "<<auxsaldo<<endl;
					cout<<"\t________________________________\n\n";
					cout<<"Seguro que desea ingresar el monto de $"<<auxingreso<<" a su cuenta? S | N ";
					cin>>op;
					if((op=='S')||(op=='s'))
					{
						aux<<nip<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<auxsaldo<<" "<<auxingreso<<" "<<retiro<<" "<<transferencia<<" "<<endl;
						cout<<"\n\n\t\t\tIngreso exitoso...\n\t\t\a";
						system("pause");system("cls");return menuatm();
					}
					else
					{
						aux<<nip<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<saldo<<" "<<ingreso<<" "<<retiro<<" "<<transferencia<<" "<<endl;
						cout<<"\n\tMovimiento cancelado";
						cout<<"\n\tRegresando al menu...";
						system("pause");system("cls");return menuatm();
					}               
				}
				else
				{
					aux<<nip<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<saldo<<" "<<ingreso<<" "<<retiro<<" "<<transferencia<<" "<<endl;
				}lectura>>nip; 
			}
		}
    }
	else
	{
        std::cout<<"\n\tERROR...";
        std::cout<<"\n\tIntentelo de nuevo\n\t";
        system("pause");system("cls");return menuatm();
    }
    if (encontrado==false)
	{
		cout<<"\n\tNIP incorrecto, intentelo de nuevo...\n\t";
		system("pause");system("cls");return ingresardin();
	}
    
    aux.close();
    lectura.close();
    remove ("usuarioscajero.txt");
    rename("auxiliar_usuarios.txt", "usuarioscajero.txt");
	system("cls");return menuatm();
}

void retirardin()
{
	ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("auxiliar_usuarios.txt", ios::out);
    lectura.open("usuarioscajero.txt", ios::in);
    if (aux.is_open() && lectura.is_open()){
		cout<<"\t--R E T I T A R  D I N E R O---";
		cout<<"\n\n";       
		cout<<"\tEl saldo en su cuenta es de: $"<<saldo;
		cout<<"\n\n";
		cout<<"\tMonto que desea retirar: ";
		cin>>auxretiro;
		if((auxretiro<=0)||(auxretiro>=saldo))
		{
			cout<<"\n\tCantidad insuficiente...";
			cout<<"\n\tIntentelo de nueva con otra cantidad...\n\t";
			system("pause");system("cls");return retirardin();
		}
		else
		{
			cout<<"\n\tIngrese su NIP, para confirmar: ";
			cin>>np;
			lectura>>nip;
	        while (!lectura.eof())
			{
				lectura>>user>>numtarjt>>anterior>>saldo>>ingreso>>retiro>>transferencia;
	            if (np==nip)
				{
	                encontrado=true;
					anterior = saldo;
					auxsaldo = saldo - auxretiro;
					cout<<"\n";
	                cout<<"\tUsuario: "<<user<<endl;
	                cout<<"\tSaldo anterior: $"<<anterior<<endl;
	                cout<<"\tRetiro: $"<<auxretiro<<endl;
	                cout<<"\tSaldo actual: $"<<auxsaldo<<endl;
	                cout<<"\t________________________________\n\n";
					cout<<"Seguro que desea retirar el monto de $"<<auxretiro<<" de su cuenta? S | N ";
					cin>>op;
					if((op=='S')||(op=='s'))
					{
						aux<<nip<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<auxsaldo<<" "<<ingreso<<" "<<auxretiro<<" "<<transferencia<<" "<<endl;
						cout<<"\n\n\t\t\tRetiro exitoso...\n\t\t\a";
						system("pause");system("cls");return menuatm();
					}
					else
					{
						cout<<"\n\tMovimiento cancelado";
						cout<<"\n\tRegresando al menu...\n\t";
						system("pause");system("cls");return menuatm();
					}                    
				}
				else
				{
					aux<<nip<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<saldo<<" "<<ingreso<<" "<<retiro<<" "<<transferencia<<" "<<endl;
				}lectura>>nip;
	        } 
		}
    }
	else
	{
        std::cout<<"\n\tERROR...";
        std::cout<<"\n\tIntentelo de nuevo\n\t";
        system("pause");system("cls");return menuatm();
    }
    if (encontrado==false)
	{
        cout<<"\n\tNIP incorrecto, intentelo de nuevo...\n\t";
		system("pause");system("cls");return ingresardin();
	}
    aux.close();
    lectura.close();
    remove ("usuarioscajero.txt");
    rename("auxiliar_usuarios.txt", "usuarioscajero.txt");
	system("cls");return menuatm();
}
void consultarmonto()
{
	ifstream lectura; //Lectura de archivos
    lectura.open("usuarioscajero.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE EL ARCHIVO
    if (lectura.is_open())
	{
		cout<<"\n\n";
        cout<<"\t--C O N S U L T A  D E  S A L D O--";
        cout<<"\n\n";
        cout<<"\tIngrese su NIP: ";
        cin>>np;
		lectura>>nip;
        while (!lectura.eof())
		{
			lectura>>user>>numtarjt>>anterior>>saldo>>ingreso>>retiro>>transferencia;
            if (np==nip)
			{
				system("cls");
				cout<<"\t--C O N S U L T A  D E  S A L D O--";
        		cout<<"\n\n";
				cout<<"\tUsuario: "<<user<<endl;
				cout<<"\n\tSaldo anterior: $"<<anterior<<endl;
				cout<<"\n\tSaldo agregado: $"<<ingreso<<endl;
				cout<<"\n\tSaldo retirado: $"<<retiro<<endl;
				cout<<"\n\tSaldo transferido: $"<<transferencia<<endl;
				cout<<"\n\tSaldo actual: $"<<saldo<<endl;
				cout<<"\t________________________________\n";
                encontrado=true;	
				break;                 
			}lectura>>nip;
        } 	
        if (encontrado==false)
		{
	        cout<<"\n\tNIP incorrecto...Intentelo de nuevo...\n\n\t\t\t";
	        system("pause");system("cls");return consultarmonto();
		}
	}
	else
	{
        std::cout<<"\n\tERROR...";
        std::cout<<"\n\tIntentelo de nuevo\n\t";
        system("pause");system("cls");return menuatm();
    }
    lectura.close();
    system("pause");system("cls");return menuatm();
}
void transferirdin()
{
	
	ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("auxiliar_usuarios.txt", ios::out);
    lectura.open("usuarioscajero.txt", ios::in);
    if (aux.is_open() && lectura.is_open())
	{
		cout<<"\n\n";
	    cout<<"\t--T R A N S F E R E N C I A--";
	    cout<<"\n\n";
		cout<<"\n\tIngrese el numero de cuenta al que desea transferir: ";
		cin>>auxnumtarjt;
		lectura>>numtarjt;
        while (!lectura.eof())
		{
			lectura>>nip>>user>>anterior>>saldo>>ingreso>>retiro>>transferencia;
            if(auxnumtarjt==numtarjt)
			{
				system("cls");
				cout<<"\t--T R A N S F E R E N C I A--";
        		cout<<"\n\n";
				cout<<"\tUsuario: "<<user<<endl;
				cout<<"\n\tNumero de tarjeta: $"<<numtarjt<<endl;
				cout<<"\t________________________________\n";
				cout<<"\n\tIngrese la cantidad que desea transferir: $";cin>>cantidad;
				if(cantidad<=0)
				{
					cout<<"\n\tError...";
					cout<<"\n\tIngrese un cantidad valida...\n\t";system("pause");system("cls");return transferirdin();
				}
				else if(cantidad>saldo)
				{
					cout<<"\n\tError...";
					cout<<"\n\tLa cantidad dada, excede su saldo en su cuenta...";
					cout<<"\n\tIngrese otra cantidad...\n\t";system("pause");system("cls");return transferirdin();	
				}
				else
				{
					anterior = saldo;
					auxsaldo = saldo - cantidad;
					cout<<"\n\t";
					cout<<"\n\tSaldo anterior: $"<<anterior<<endl;
					cout<<"\n\tSaldo transferido: $"<<cantidad<<endl;
					cout<<"\n\tSaldo actual: $"<<auxsaldo<<endl;
					cout<<"\t________________________________\n";
					cout<<"\n\tIngrese su NIP para confirmar: ";cin>>np;
					lectura>>nip;
					{
						cout<<"\n\tLa cantidad transferida de $"<<cantidad<<" Fue enviada a la cuenta "<<auxnumtarjt;
						aux<<nip<<" "<<user<<" "<<anterior<<" "<<auxsaldo<<" "<<ingreso<<" "<<retiro<<" "<<cantidad<<" "<<endl;
					}
				}
                encontrado=true;	
				break;                 
			}lectura>>numtarjt;
        } 	
        if (encontrado==false)
		{
	        cout<<"\n\tNumero de tarjeta incorrecto...Intentelo de nuevo...\n\n\t\t\t";
	        system("pause");system("cls");return transferirdin();
		}
	}
	else
	{
        std::cout<<"\n\tERROR...";
        std::cout<<"\n\tIntentelo de nuevo\n\t";
        system("pause");system("cls");return menuatm();
    }
    aux.close();
    lectura.close();
    remove ("usuarioscajero.txt");
    rename("auxiliar_usuarios.txt", "usuarioscajero.txt");
    system("pause");system("cls");return menuatm();
	
}
void cambionip()
{
	ofstream aux;
    ifstream lectura;
    encontrado=false;
    aux.open("auxiliar_usuarios.txt", ios::out);
    lectura.open("usuarioscajero.txt", ios::in);
    if (aux.is_open() && lectura.is_open()){
		cout<<"\n\n";
        cout<<"\t--C A M B I O  D E  N I P--";
        cout<<"\n\n";
		cout<<"\n\tIngrese su NIP actual: ";
		cin>>auxnip;
		lectura>>nip;
		while (!lectura.eof())
		{
			lectura>>user>>numtarjt>>anterior>>saldo>>ingreso>>retiro>>transferencia;
			if (np==nip)
			{
				encontrado=true;
				cout<<"\n";
				cout<<"\tUsuario: "<<user<<endl;
				cout<<"\tNIP: "<<nip<<endl;
				cout<<"\t________________________________\n\n";
				cout<<"\tIngresa la nueva clave de seguiridad-NIP: ";
				cin>>auxnip;
				cout<<"\tVuelva a ingresar su nueva clave de seguridad-NIP: ";
				cin>>auxnip2;
				if(auxnip==auxnip2)
				{
					cout<<"\n\t-Seguro que desea cambiar la clave de seguridad-NIP? S | N ";
					cin>>op;
					if((op=='S')||(op=='s'))
					{
						aux<<auxnip2<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<saldo<<" "<<ingreso<<" "<<retiro<<" "<<transferencia<<" "<<endl;
						cout<<"\n\n\t\t\tClave de seguridad-NIP modificado...\n\t\t\a";
						system("pause");system("cls");return menuatm();
					}
					else 
					{
						aux<<nip<<" "<<user<<" "<<numtarjt<<" "<<anterior<<" "<<saldo<<" "<<ingreso<<" "<<retiro<<" "<<transferencia<<" "<<endl;
						cout<<"\n\tSe cancelo el cambio de NIP...";Sleep(1000);
						cout<<"\n\tRegresando al menu...";
						system("pause");system("cls");return menuatm();
					}
				}
				else
				{
					cout<<"\n\tError...";
					cout<<"\n\tLas claves nuevas de coinciden...";Sleep(1000);
					cout<<"\n\tIntentelo de nuevo...";
					cout<<"\n\tRegresando al menu...";
					system("pause");system("cls");return menuatm();
				}
			}lectura>>nip;
		}
    }
	else
	{
        std::cout<<"\n\tERROR...";
        std::cout<<"\n\tIntentelo de nuevo\n\t";
        system("pause");system("cls");return menuatm();
    }
	if (encontrado==false)
	{
        cout<<"\n\tNo se encontro ningun registro con el NIP otorgado...Intentelo de nuevo...\n\n\t\t\t";
        system("pause");system("cls");return menuatm();
	}
    aux.close();
    lectura.close();
    remove ("usuarioscajero.txt");
    rename("auxiliar_usuarios.txt", "usuarioscajero.txt");
    system("cls");
    return menuatm();
}
void imprimir()
{           //FUNCION QUE IMPRIME LOS ULTIMOS MOVIMIENTOS HECHOS POR LE USUARIO EN SECION, EN UN TIPO DE FORMATO DE TICKET
	do
	{
		system("cls");
		cout<<"\tMOVIMIENTOS\n\n";
		ofstream imp("imprime.txt");
		Sleep(1000);
		cout<<"USUARIO        :   "<< user << "\n \n";
		Sleep(1000);
		cout<<"SALDO ANTERIOR :   "<< anterior << "\n \n";
		Sleep(1000);
		cout<<"SALDO RETIRO   :   "<< auxretiro << "\n \n";
		Sleep(1000);
		cout<<"SALDO TRANSFERIDO  :   "<< cantidad << "\n \n";
		Sleep(1000);
		cout<<"SALDO AGREGADO :   "<< auxingreso << "\n \n";
		Sleep(1000);
		cout<<"SALDO ACTUAL   :   "<< auxsaldo << "\n \n";
		Sleep(1000);
		imp<<"USUARIO        :   " << user << "\n \n";		
		imp<<"SALDO ANTERIOR :   " << anterior << "\n \n";	
		imp<<"SALDO RETIRO   :   " << auxretiro << "\n \n";
		imp<<"SALDO TRANSFERIDO :   "<< cantidad << "\n \n";	
		imp<<"SALDO AGREGADO :   " << auxingreso << "\n \n";	
		imp<<"SALDO ACTUAL   :   " << auxsaldo << "\n \n";
		imp.close();	
		cout<<"\n\nDATOS IMPRESOS CORRECTAMENTE\n\n\n";
		cout<<"\tDesea volver a ver su saldo? (S/N) ";
		cin>>op;
		system("pause");system("cls");
	} while (op=='S'); menuatm();
}