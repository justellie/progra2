#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <iostream>
using namespace std;



template<class Elemento>
class Lista
{

private:
	//*****************|| ATRIBUTOS ||********************//	
	Nodo<Elemento> *cabeza,*cola;				 // La cabeza apunta al inicio de la lista mientras que la cola apunta al fin de la lista para asi hacer mas rapido el insertado al final de la misma
	int longitud;								// Indica la logitud de la cola
public:
	//*****************|| Constructores ||********************//
	 Lista();									 // No recibe ningun parametro
	 Lista(Lista<Elemento> &);				    // Constructor copia
	//*****************|| Destructores||********************//
	~ Lista();
	//*****************|| Metodo Publicos||********************//
	void copiar(const Lista<Elemento>&); 
	bool esVacia();
	int  obtLongitud(); 
	void insertar(Elemento, const int&); 	  //Inserta un elemento segun posicion 
	Elemento consultar(const int&); 	     // retorna el elemento en la posicion (pos) de la Lista
	void print(); 
	void printCriminal();
	void eliminar(int pos);						    //Imprime los valores de una lista
	Lista<Elemento> subLista(int,int);												// retorna una subLista desde un indice hasta el otro	
	Elemento menor();
	Elemento mayor();
	void invertir();
	void invertir(int , int );
	void ordenar(bool ascendete);//Ordena de forma ascendente y descendente
	void modificar(Elemento,int);
	bool esta(Elemento); 																		// devuelve si un elemento esta o no	
	void vaciar(); 
	void mezclarOrdenada(Lista<Elemento> &a, Lista<Elemento> &b);																		// vacia la lista y elimina todos sus nodos
	//void mezclarOrdenada(Lista<Elemento>&,Lista<Elemento>&);
	
};

template<class Elemento>
Lista<Elemento>::Lista(){ 
	this->cabeza=NULL;
	this->cola=NULL;
	this->longitud=0;

}
template<class Elemento>
Lista<Elemento>::Lista(Lista<Elemento> &l){
	this->vaciar();
	this->copiar(l);

}
template <class Elemento>
void Lista<Elemento>::copiar(const Lista<Elemento>&l){
	Nodo<Elemento> *actual=l.cabeza, *nuevo;//actual es un puntero al primer nodo de la lista l y nuevo cumplira la funcion de añardir los nodos que se encuentren en esa lista l que sean distinto de la cabeza
	this->vaciar();
	nuevo=new Nodo<Elemento>;//creo el nodo a utilizar
	nuevo->modInfo(actual->obtInfo());//copio el contenido del nodo actual en el nuevo nodo
	nuevo->modProx(NULL);//apunto el prox a NULL
	cola=nuevo;//cola apunta a nuevo ya que cola se supone que aqui solo existe un solo nodo
	actual=(actual->obtProx());
	this->cabeza=nuevo;//La cabeza apunta al nuevo nodo
	if(l.longitud>0)
	{
		while(actual!=NULL)
		{
			nuevo= new Nodo<Elemento>;//El nuevo nodo es creado
			nuevo->modInfo(actual->obtInfo());//la infomacion del nodo l en que nos encontramos es copiada al nuevo nodo
		  	nuevo->modProx(NULL);//nuevo nodo apunta a null porque se supone que sera añadido al final de la lista
			cola->modProx(nuevo);//cola que apunta al anterior final de la lista ahora apunta al nuevo finial que sera el nuevo nodo
			actual=(actual->obtProx());//actual se mueve al proximo nodo 
			cola=nuevo;//cola apunta al nuevo nodo que es el nuevo final
		}	

	}
	else 
		this->cabeza=NULL;
		this->cola=NULL;
	this->longitud=l.longitud;
};
template<class Elemento>
bool Lista<Elemento>::esVacia(){
	return this->cabeza==NULL;
}
template<class Elemento>
int Lista<Elemento>::obtLongitud(){
	return this->longitud;
}
template<class Elemento>
void Lista<Elemento>::insertar(Elemento e, const int& pos){
	Nodo<Elemento> *nuevo,*aux;
	int i;

	if(pos<0||pos>this->longitud+1)//Si la posicion no es valida lanza un mensaje
	{
		cout<<"Posicion no valida"<<endl;
	}
	else
	{
		nuevo= new Nodo<Elemento>;//De ser la posicion valida se crea un nuevo nodo y se añade el elemento en el campo respectivo
		nuevo->modInfo(e);
		if(pos==0)//Si la posicion es 0
		{
			nuevo->modProx(this->cabeza);//Se apunta el nuevo nodo a la cabeza 
			this->cabeza=nuevo;//Y la cabeza al nuevo nodo
		}
		else//Si no 
		{
			aux=this->cabeza;//Apunta al inicio de la lista
			for(i=1;i<pos;i++)//Me muevo una posicion hasta llegar a la posicion requerida
			{
				aux=(aux->obtProx());
			}
			nuevo->modProx(aux->obtProx());//apunto el nuevo nodo al nodo que corresponde al siguiente del actual
			aux->modProx(nuevo);//apunto el actual al nuevo nodo
			if(pos==this->longitud+1)//Si la posicion es la final o la final mas uno entonces se punta la cola a ese nodo
			{
				this->cola=nuevo;
			}
			
		}
		this->longitud = this->longitud + 1;//Se suma uno a la logitud
	}

}
template<class Elemento>
Elemento Lista<Elemento>::consultar(const int& pos){
	Nodo<Elemento> *aux;
	int i;
	Elemento resp;

	if (pos<0||pos>this->longitud+1)
	{
		cout<<"Posicion no valida"<<endl;
	}
	else
	{
		if(pos==this->longitud)
		{
			aux=this->cola
			resp=aux->obtInfo();
		}
		else{
				aux=this->cabeza;//Apunta al inicio de la lista
				for(i=0;i<pos;i++)//Me muevo una posicion hasta llegar a la posicion requerida
				{
					aux=(aux->obtProx());
				}
				resp=aux->obtInfo();
			}
	
	}
	return(resp);	
}
template <class Elemento>
void Lista<Elemento>::print()
{
	Nodo<Elemento>* aux;

	aux = this->cabeza;
	while(aux != NULL)
	{
		cout << aux->obtInfo() << " ";
		aux = aux->obtProx();
	}
	cout << endl;
}
template <class Elemento>
void Lista<Elemento>::printCriminal()
{
	Nodo<Elemento>* aux;

	aux = this->cabeza;
	while(aux != NULL)
	{
		cout <<"|" <<aux->obtInfo() << "|"<<"->";
		aux = aux->obtProx();
	}
	cout <<"NULL"<< endl;
}

template<class Elemento>
Lista<Elemento> Lista<Elemento>::subLista(int inicio, int fin)
{
	Nodo<Elemento> *nuevo, *actual;
	Lista<Elemento> resultado;
	int i;
	if(inicio>=0 && inicio<=fin && fin< this->longitud)
	{
		actual=this->cabeza;
		for (i=0;i<inicio;i++)
		{
			actual=actual->obtProx();//Pone el puntero actual al inicio 
		}
		nuevo= new Nodo<Elemento>;//crea el nodo que va a copiar el dato 
		nuevo->modInfo(actual->obtInfo());//copia el dato
		nuevo->modProx(NULL);//apunta a NUll
		resultado.cabeza=nuevo;//el nuevo nodo que es el inicio del 
		resultado.cola=nuevo;//cola apunta el nuevo nodo
		actual=actual->obtProx();// el apuntador se mueve al nodo siguiente
		for(i=inicio;i<fin;i++)//empiezo a copiar el resto
		{
			nuevo= new Nodo<Elemento>;//El nuevo nodo es creado
			nuevo->modInfo(actual->obtInfo());//la infomacion del nodo l en que nos encontramos es copiada al nuevo nodo
		  	nuevo->modProx(NULL);//nuevo nodo apunta a null porque se supone que sera añadido al final de la lista
			resultado.cola->modProx(nuevo);//cola que apunta al anterior final de la lista ahora apunta al nuevo finial que sera el nuevo nodo
			actual=(actual->obtProx());//actual se mueve al proximo nodo 
			resultado.cola=nuevo;//cola apunta al nuevo no

		}
		resultado.longitud=fin-inicio+1;//la logitud es uno puesto que es el primer nodo



	}

	return(resultado);

}
template <class Elemento>
Elemento Lista<Elemento>::mayor()
{
	Nodo<Elemento> *aux;
	Elemento may;

	aux = this->cabeza;
	may = aux->obtInfo();
	aux = aux->obtProx();

	while(aux!=NULL)
	{
		if(aux->obtInfo()>may)
		{
			may = aux->obtInfo();
		}
		aux = aux->obtProx();
	}

	return may;
}

template <class Elemento>
Elemento Lista<Elemento>::menor()
{
	Nodo<Elemento> *aux;
	Elemento men;

	aux = this->cabeza;
	men = aux->obtInfo();
	aux = aux->obtProx();

	while(aux!=NULL)
	{
		if(aux->obtInfo()<men)
		{
			men = aux->obtInfo();
		}
		aux = aux->obtProx();
	}

	return men;
}

template <class Elemento>
void Lista<Elemento>::ordenar(bool ascendete)//Este algoritmo es como el algoritmo de ordenamiento burbuja
{
	Nodo<Elemento> *aux1, *aux2;
	Elemento elemento;
	int i, j;

	if(ascendete)
	{
		for(i=0;i<this->longitud -1 ;i++)
		{
			aux1 = this->cabeza;
			aux2 = aux1->obtProx();

			for(j=0; j < (this->longitud - i -1); j++)
			{
				if(aux1->obtInfo() > aux2->obtInfo())
				{
					elemento = aux1->obtInfo();
					aux1->modInfo(aux2->obtInfo());
					aux2->modInfo(elemento);
				}
				aux1 = aux2;
				aux2 = aux2->obtProx();
			}
		}
	}
	else
	{
		for(i=0;i<this->longitud -1;i++)
		{
			aux1 = this->cabeza;
			aux2 = aux1->obtProx();

			for(j=0; j < (this->longitud - i -1); j++)
			{
				if(aux1->obtInfo() < aux2->obtInfo())
				{
					elemento = aux1->obtInfo();
					aux1->modInfo(aux2->obtInfo());
					aux2->modInfo(elemento);
				}
				aux1 = aux2;
				aux2 = aux2->obtProx();
			}
		}
	}
}

template <class Elemento>
void Lista<Elemento>::eliminar(int pos)
{
	Nodo<Elemento> *aux, *aux2;
	int i;

	if(pos < 0 || pos >= this->longitud+1)
	{
		return;
	}
	else
	{
		aux = this->cabeza;

		if(pos == 0)
		{
			this->cabeza = aux->obtProx();
			delete aux;
		}
		else
		{
			for(i = 1; i < pos; i++)
			{
				aux = aux->obtProx();
			}
			
			aux2 = aux->obtProx();
			aux->modProx(aux2->obtProx());
			if(pos==this->longitud-1)
			{
				this->cola=aux;
			}
			delete aux2;
		}
		this->longitud = this->longitud - 1;
	}
}
template<class Elemento>
void Lista<Elemento>::invertir()
{
	Nodo<Elemento> *actual,*prev,*proximo;
	prev=NULL;
	proximo=NULL;
	
	
	actual=this->cabeza;
	while( actual!= NULL)
	{
			proximo=actual->obtProx();
			actual->modProx(prev);
			prev=actual;
			actual= proximo;
	}
	this->cola=this->cabeza;
	this->cabeza=prev;

}

template <class Elemento>
void Lista<Elemento>::invertir(int inicio, int fin)
{
	Nodo<Elemento> *ini,*fi,*actual,*proximo,*prev,*con;
	int i;
	ini=this->cabeza;
	if(inicio>0 && fin < this->longitud)
	{

		for(i=0;i<inicio;i++)
		{
			prev=ini;
			ini=ini->obtProx();

		}
		fi=ini;
		for(i=inicio;i<fin;i++)
		{
			fi=fi->obtProx();
			
		}
		i=0;
		con=prev;
		actual=ini;
		proximo=NULL;
		while(fin>1)
		{
			proximo=actual->obtProx();
			actual->modProx(prev);
			prev=actual;
			actual= proximo;
			fin--;
			
		}
		if (con != NULL) {
            con->modProx(prev);
        } 

        ini->modProx(actual);
		
	}
	else
	{
		if(inicio==0 && fin==this->longitud)
		{
			this->invertir();
		}
		else
		{
			if(inicio>0 && fin==this->longitud)
			{

				for(i=0;i<inicio;i++)
				{
					prev=ini;
					ini=ini->obtProx();

				}
				fi=ini;
				for(i=inicio;i<fin;i++)
				{
					fi=fi->obtProx();
			
				}
				i=0;
				con=prev;
				actual=ini;
				proximo=NULL;
				while(fin>1)
				{
					proximo=actual->obtProx();
					actual->modProx(prev);
					prev=actual;
					actual= proximo;
					fin--;
			
				}
				if (con != NULL) {
            		con->modProx(prev);
        		} 

        		ini->modProx(actual);
        		this->cola=actual;						

			}
			else
			{
				if(inicio==0 && fin < this->longitud)
				{

					for(i=0;i<inicio;i++)
					{
						prev=ini;
						ini=ini->obtProx();

					}
					fi=ini;
					for(i=inicio;i<fin;i++)
					{
						fi=fi->obtProx();
			
					}
					i=0;
					con=prev;
					actual=ini;
					proximo=NULL;
					while(fin>1)
					{
						proximo=actual->obtProx();
						actual->modProx(prev);
						prev=actual;
						actual= proximo;
						fin--;
			
					}
					if (con != NULL) {
            			con->modProx(prev);
        			} 

        			ini->modProx(actual);
        			this->cabeza=prev;						

				}
				else
				{
					cout<<"Error de indices"<<endl;
				}
			}

		}

	}
}

template <class Elemento>
void Lista<Elemento>::modificar(Elemento e, int pos)
{
	Nodo<Elemento> *p;
	int i;

	if(pos>=0 && pos < this->longitud)
	{
		p = this->cabeza;
		for(i=0;i<pos;i++)
		{
			p = p->obtProx();
		}
		p->modInfo(e);
	}
	else
	{
		"** ERROR DE INDICES EN MODIFICAR UN ELEMENTO DE LA SIGUIENTE LISTA ** -> ";
		this->print();
	}
}

template <class Elemento>
bool Lista<Elemento>::esta(Elemento e)
{
	Nodo<Elemento>* aux;
	bool result;

	aux = this->primero;
	result = false;

	while(!result && aux != NULL)
	{
		if(aux->obtInfo() == e)
		{
			result = true;
		}
		else
		{
			aux = aux->obtProx();
		}
	}

	return result;
}

template <class Elemento>
void Lista<Elemento>::vaciar()
{
  Nodo<Elemento> *aux;

  aux = this->cabeza;
  while(this->cabeza!= NULL)
  {
    this->cabeza= (this->cabeza)->obtProx();
    delete aux;
    aux = this->cabeza;
  }

	this->cabeza = NULL;
  	this->longitud = 0;
  	this->cola=NULL;

}

template <class Elemento>
void Lista<Elemento>::mezclarOrdenada(Lista<Elemento> &a, Lista<Elemento> &b)
{
  

  while( !(a.esVacia())&& !(b.esVacia()) )
  {
    
    
    if(a.consultar(0) <= b.consultar(0))
    {
      this->insertar(a.consultar(0),0);
      a.eliminar(0);
    }
    else
    {
      this->insertar(b.consultar(0),0);
      b.eliminar(0);
    }
  }
  while(!(a.esVacia()))
  {
    this->insertar(a.consultar(0),0);
    a.eliminar(0);
  }
  while(!(b.esVacia()))
  {
    this->insertar(b.consultar(0),0);
    b.eliminar(0);
  }
  this->invertir();

}

template <class Elemento>
Lista<Elemento>::~Lista()
{
	this->vaciar();
} 
#endif