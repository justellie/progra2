#include <iostream>
#include "Nodo.h"
#include "Listas.h"
#include "Cola.h"
#include "Pila.h"



using namespace std;
int main(int argc, char const *argv[])
{
	//Nodo<int> a;
	//Pila<int> a;
	Cola<int> b;
	
	

	int i=0;
	
	while(i<1000)
	{
			//cout<<"Introduzca un valor para lista A"<<endl;
			//cin>>n;
			b.encolar(i+1);
			//a.apilar(i+1);

			i++;
	}

	//a.print();
	b.print();
	b.vaciar();
	//a.vaciar();
	return 0;
}