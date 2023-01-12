#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;
    //ESTRUCTURA DE DATOS PARA LA MATRIZ DE LOS USUARIOS
struct datos1
{
    string user;
    string password;
};
struct datos2
{
    int saldo;
    int numtarj;
};
    //DECLARACION DE VARIABLES GLOBALES EN EL CODIGO
int cont=0, conta2=0, m1, trdin, numtjr, monto;
float ingreso, final=0, retiro;
char op;
string nip2;
struct datos1 base[3];
struct datos2 base2[3];

void usuariosatm();
void menuatm();
bool buscarusuario(string, bool);
void ingresardin();
void retirardin();
void consultarmonto();
void transferirdin();
void cambionip();

int main()
{
    usuariosatm();
    string user1, password1;
        //LOGIN DE USUARIO
    cout<<"\n\n";
    cout<<"\t\tIngrese Usuario: ";
    cin>>user1;

    if (buscarusuario(user1, true))
    {

        cout<<"\t\tIngrese contraseña: ";
        cin>>password1;
        if (buscarusuario(password1, false))
        {
            system("cls");
                    //VERIFICAR USUARIO Y CONTADOR DE INTENTOS PARA EL ACCESO AL ATM
            if ((base[m1].user==user1) && (base[m1].password==password1))
            {
                menuatm();
            }
            else
            {
                cout<<"\n\n\n";
                cout<<"------------------------------------------------";
                cout<<"\t\tUsuario y/o Contraseña incorrectos";
                cout<<"------------------------------------------------";
            }
        }
        else
        {
            cout<<"\t\nPIN invalido";
        }
    }
    else
    {
        cout<<"\t\nUsuario incorrecto";
    }

    getch();
    return 0;
}

void menuatm()
{
    int opc;
    cout<<"\t\t      BIENVENIDO"<<endl;
    cout<<"\t--C A J E R O  A U T O M A T I C O--"<<endl;
    cout<<"\n";
        //MENU DE OPCIONES ATM
    cout<<"\tEliga una opcion"<<endl;
    cout<<"\t1- Ingresar dinero"<<endl;
    cout<<"\t2- Retirar dinero"<<endl;
    cout<<"\t3- Consultar saldo"<<endl;
    cout<<"\t4- Transferir dinero"<<endl;
    cout<<"\t5- Cambio de NIP"<<endl;
    cout<<"\t6- Salir\n"<<endl;
    cout<<"\tOpcion: ";
    cin>>opc;
    system("cls");
            //OPCIONES DEL CAJERO
        switch (opc)
        {
            //INGRESAR DINERO A CUENTA
        case 1:
            ingresardin();
        break;
            //RETIRAR DINERO DE CUENTA
        case 2:
            retirardin();
        break;
            //CONSULTA DE SALDO
        case 3:
            consultarmonto();
        break;
            //TRANSFERIR DINERO
        case 4:
            transferirdin();
        break;
            //CAMBIO DE NIP
        case 5:
            cambionip();
        break;
            //SALIR
        case 6:
            cout<<"\n \n \n";
            cout<<"\t\tG R A C I A S   P O R   S U   V I S I T A";
        break;
        }
    system("cls");
}
    //FUNCIONES DEL CAJERO
void ingresardin()
{
    do
    {
        for (int i=0; i <= 3; i++)
        {
            usuariosatm();
            cout<<"\t---I N R E S A R  D I N E R O---\n"<<endl;
            cout<<"\tMonto que desea ingresar:";
            cin>>ingreso;
                //SUMA DEL MONTO A INGRESAR CON EL ACTUAL EN MATRIZ
            final = base2[m1].saldo + ingreso;
            cout<<"\n\n";
                //CONFIRMACION
            cout<<"Ingrse su NIP para confirmar la transaccion";
            cin>>nip2;
            if (nip2 == base[m1].password)
            {
            	cout<<"\n\n";
                system("cls");
                cout<<"\tSaldo final es: $"<<final;
                cout<<"\n\n";
                cout<<"\tDesea hacer otro movimiento? (S/N) ";
                cin>>op;
                system("cls");
            }
            else
            {
                while (conta2 <= 3)
                {
                	cout<<"\n\n";
                    cout<<"Su NIP es incorrecto intentelo de nuevo: ";
                    cin>>nip2;
                    conta2++;
                }
                while (conta2 = 3)
                {
                	cout<<"\n\n";
                    cout<<"Intentos cumplidos, Transaccion cancelada";
                }return retirardin();
            }
        }
    }while (op == 'S');
    system("cls");
    return menuatm();
}

void retirardin()
{
    for (int i=0; i <=3; i++)
    {
        do
        {
        cout<<"\t--R E T I T A R  D I N E R O---";
		cout<<"\n\n";       
        cout<<"\tMonto que desea retirar: ";
        cin>>retiro;
        cout<<"\n\n";
            //CONFIRMACION
        cout<<"Ingrse su NIP para confirmar la transaccion";
        cin>>nip2;
        system("cls");
        if (nip2 == base[m1].password)
        {
            if (retiro>base2[m1].saldo)
            {
                cout<<"\n\n";
                cout<<"\tSaldo  insuficiente"<<endl;
            }
            else
            {
                    //RESTA DEL MONTO A RETIRAR POR EL USUARIO
                final = base2[m1].saldo - retiro;
                cout<<"\n\n";
                cout<<"\tMonto retirado: $"<<retiro;
                cout<<"\n\n";
                cout<<"\tSaldo final es: $"<<final;
            }
        }
        else
        {
            while (conta2 <= 3)
            {
            	cout<<"\n\n";
                cout<<"Su NIP es incorrecto intentelo de nuevo: ";
                cin>>nip2;
                conta2++;
            }
            while (conta2 = 3)
            {
            	cout<<"\n\n";
                cout<<"Intentos cumplidos, Transaccion cancelada";
            }return retirardin();
        }
        cout<<"\n\n";
        cout<<"\tDesea hacer otro movimiento? (S/N) ";
        cin>>op;
        system("cls");
        } while (op == 'S');
        return menuatm();
    }

}

void consultarmonto()
{
    usuariosatm();
    for (int i = 0; i < 3; i++)
    {
        do
        {
            cout<<"\t--C O N S U L T A  D E  S A L D O--\n\n";
            cout<<"\n\n";
            cout<<"\tUsuario: "<<base[m1].user;
            cout<<"\n\n";
            cout<<"\tNumero de tarjeta: "<<base2[m1].numtarj;
            cout<<"\n\n";
            cout<<"\tEl saldo de su cuenta es de: $"<<base2[m1].saldo;
            cout<<"\n\n";
            cout<<"\tDesea volver a ver su saldo? (S/N) ";
            cin>>op;
            system("cls");
        } while (op == 'S');
        return menuatm();
    }
}

void transferirdin()
{
	usuariosatm();
    cout<<"\t--T R A N S F E R E N C I A--";
    cout<<"\n\n";
    cout<<"\tIngrese el numero de tarjeta al que desea transferir";
    cout<<"\n\n";
    cout<<"\tNumero de tarjeta: ";
    cin>>numtjr;
        //COMPROABR QUE LA TARJETA ESTA CORRECTA    if(base2[m1].numtarj == numtjr)
    for	(int i; i <= 3; i++)
    {
	    if (base2[m1].numtarj == numtjr)
	    {				
			system("cls");																			                	
	        cout<<"\n\n";
	        cout<<"\tIngrese la cantidad a transferir: $";
	        cin>>trdin;
	        if (trdin < base2[m1].saldo)
	    	{ 
	                //SUMA Y RESTA DE LOS SALDOS EN LAS CUENTAS CORRESPONDIENTES
	            for (int j; j <= 3; j++)
	            {
		            base2[j].saldo = base2[j].saldo - trdin;
		            base2[j].saldo = base2[j].saldo + trdin;
		            trdin = 0;
		            m1 = j;
	        	}
	                //CONFIRMACIN DE TRASNGER MEDIANTE NIP
	            cout<<"\n\n";
	            if (base[m1].password == nip2 )
	    		{
	                do
					{	
						cout<<"Ingrese su NIP para continuar: ";
	                	cin>>nip2;
	                	cout<<"\tTranferencia !EXITOSA¡\n";
	                	cout<<"\tSu nuevo saldo es: $"<<base2[m1].saldo;
	                	cout<<"\n\n";
	                	system("cls");
	                	cout<<"\tDesea hacer otro movimiento? (S/N) ";
	                	cin>>op;
	                }while (op == 'S'); return menuatm();
	            }
	            else if(base[m1].password != nip2)
	            {
	                if (conta2 <= 3)
	                {
	                	cout<<"\n\n";
	                    cout<<"Su NIP es incorrecto intentelo de nuevo: ";
	                    cin>>nip2;
	                    conta2++;
	                }
	                else 
	                {
	                	cout<<"\n\n";
	                    cout<<"Intentos cumplidos, Transaccion cancelada";
	                }return transferirdin();
	            }
	        }
	        else if (trdin > base2[m1].saldo)
		    {
		        system("cls");
		        cout<<"\n\n";
		        cout<<"\tNo cuenta con el monto suficiente\n";
		        cout<<"\tIngrese una cantidad valida ";
		        return transferirdin();
		    }
		}
	    else if (base2[m1].numtarj != numtjr)
	    {
	        cout<<"\tNumero de tarjeta incorrecto";
	        cout<<"\n\n";
	        cout<<"\tIntentelo de nuevo";
	        system("cls");
	        return transferirdin();
	    }
	}
    system("cls");
}

void cambionip()
{
    if (base[m1].user == base[m1].user)
    {
        cout<<"\n\n";
        cout<<"\t--C A M B I O  D E  N I P--";
        cout<<"\n\n";
        cout<<"\tIngrese su NIP acutal";
        cin>>nip2;
        if(nip2 != base[m1].password)
        {
            while (conta2 <= 3)
            {
                system("cls");
                cout<<"\n\n";
                cout<< "\n\tSu NIP es incorrecto.\n";
                cout<< "\tPor favor vuelva a intentar: ";
                cin>>nip2;
                conta2++;
            }
            while (conta2 = 3)
            {
            	cout<<"\n\n";
                cout<<"Intentos cumplidos, Movimiento cancelado";
            }return cambionip();
        }
        else if (nip2 == base[m1].password)
        {
	        //CAMBIO DE NIP
	        cout<<"\n\n";
	        cout<<"\tIngrese su nuevo NIP: ";
	        cin>>nip2;
	        nip2=base[m1].password;
	        cout<<"\n\n";
	        cout <<"\tCambio !EXITOSO¡\n";
	        cout<<"\n\n";
	        cout <<"\tPrecione cualquier tecla para volver al menu principal";
	        getch();
    	}
    }
    system("cls");
    return menuatm();
}
    //DELCARACION DE LA INFORMACIOPN "BANCARIA" DE CADA USUARIO
void usuariosatm()
{
    base[0].user = "ramiro";
    base[0].password = "123";
    base2[0].numtarj = 1548812049;
    base2[0].saldo = 10000;

    base[1].user = "carlos";
    base[1].password = "579";
    base2[1].numtarj = 1548032003;
    base2[1].saldo = 10000;

    base[2].user = "cristiano";
    base[2].password = "777";
    base2[2].numtarj = 1599830100;
    base2[2].saldo = 10000;
}
    //COMPROBAR QUE EL USER INGRESADO ES CORRECTO
bool buscarusuario(string bs, bool up)
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