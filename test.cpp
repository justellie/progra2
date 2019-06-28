#include <iostream>
#include "Nodo.h"
#include "Listas.h"


using namespace std;
int main(int argc, char const *argv[])
{
	Nodo<int> a;
	Lista<int> b,c,d;
	
	int n;

	int i=0;
	
	while(i<30000)
	{
			//cout<<"Introduzca un valor para lista A"<<endl;
			//cin>>n;
			b.insertar((i*3),i);
			i++;
	}

	i=0;
	while(i<15000)
	{
			//cout<<"Introduzca un valor para lista B"<<endl;
			//cin>>n;
			c.insertar((i*2),i);
			i++;
	}
		
	
	//b.print();
	
	//c.print();
	//cout<<"Antes de invertir"<<endl;
	//b.printCriminal();
	//c.printCriminal();
	d.mezclarOrdenada(c,b);

	d.printCriminal();
	//cout<<b.consultar(0)<<endl;
	b.vaciar();
	c.vaciar();
	d.vaciar();
	//cout<<"Despues de invertir"<<endl;
	//b.invertir();
	//b.printCriminal();
	//b.eliminar(6);
	//b.printCriminal();
	return 0;
}