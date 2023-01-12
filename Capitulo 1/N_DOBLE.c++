#include <iostream>
#include <conio.h>
#include <cstring>
#include <time.h> //para clock_t, clock(), CLOCKS_PER_SEC
#include <cstdlib>

using namespace std;

const int tam = 200;
const int MAXIMO = 500;
	
void busquedabinaria();
void busquedalineal();

int opc, aux, clave=0, bajo, alto, valorcentral;
int a[tam] = { 0 };
int i;
bool enctr = false;

int main()
{
	clock_t begin = clock();
		// para almacenar el tiempo de ejecución del código
    double time_spent = 0.0;

        //MENU DE OPCIONES 
    cout<<"\tEliga una opcion"<<endl;
	cout<<"\n\n";
    cout<<"\t1- BUSQUEDA BINARIA"<<endl;
    cout<<"\t2- BUSQUEDA LINEAL"<<endl;
    cout<<"\tOpcion: ";
    cin>>opc;
    system("cls");
	switch (opc)
	{
		case 1: 	//BUSQUEDA BINARIA
			busquedabinaria();
		break;
		case 2:		//BUSQUEDA LINEAL
			busquedalineal();
		break;
	}
 
    clock_t end = clock();
 
    // calcula el tiempo transcurrido encontrando la diferencia (end - begin) y
    // dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	cout<<"\nTiempo trasncurrido: "<<time_spent<<" segundos";

	getch();
	return 0;
}

void busquedabinaria()
{
	srand( time( 0 ) );	//LLENADO DEL VECTOR
	for (int i = 0; i < 200; ++i )
		a[i] = rand() % MAXIMO + 1;
	cout << "Los valores del arreglo son:\n\n";
	for (int i = 0; i < 200; ++i )
	{
		cout <<"a[" << i << "] = " << a[ i ];
		cout << "\n";
	}
	cout<<"Ingrese la clave: ";
	cin>>clave;

	while (!enctr && bajo <= alto)
	{
		aux=0;
		for (int e;e<=200;e++)
		{
			for (i=0;i<=200;i++)
			{
				if(a[i]>a[i+1])
				{
					aux=a[i+1];
					a[i+1]=a[i];
					a[i]=aux;
					bajo = 0;		
					alto = sizeof(a) - 1;

					valorcentral = (int)((bajo + alto)/2);
					if (clave == a[valorcentral])
						enctr = true;
					else if (clave < a[valorcentral])
						alto = valorcentral - 1;
							else
								bajo =  valorcentral + 1;
				}
			}
		}

		
	}

	if (enctr)
	{
		cout<<"La clave se encuentra y esta en la posicion: "<<valorcentral +1<<endl;
		cout<<"Limite inferior: "<<bajo<<endl;
		cout<<"Limite superior: "<<alto<<endl;
		cout<<"Valor central: "<<valorcentral;
	}
	else
	{
		cout<<"La clave ingresada no se encuentra";
	}
}

void busquedalineal()
{
	srand( time( 0 ) );	//LLENADO DEL VECTOR
	for (int i = 0; i < 200; ++i )
		a[i] = rand() % MAXIMO + 1;
	cout << "Los valores del arreglo son:\n\n";
	for (int i = 0; i < 200; ++i )
	{
		cout <<"a[" << i << "] = " << a[ i ];
		cout << "\n";
	}
	cout<<"Ingrese la clave: ";
	cin>>clave;

	while (clave == a[i])
	{
		aux=0;
		for (int e;e<=200;e++)
		{
			for (i=0;i<=200;i++)
			{
				if(a[i]>a[i+1])
				{
					aux=a[i+1];
					a[i+1]=a[i];
					a[i]=aux;
				}
			}
		}
			
	}
	if (enctr)
	{
		for (int e = 0; e < 200; e++)
		{
			cout<< "Su valor se encuentra en arreglo[ ]";
		}
	}
	else
	{
		cout<<"La clave ingresada no se encuentra";
	}
}