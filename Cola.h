#ifndef COLA_H
#define COLA_H

#include "Listas.h"

template <class Elemento>
class Cola : protected Lista<Elemento>
{
private:
  Nodo<Elemento> *cola;	
public:
  
  bool esVacia();
  void encolar(Elemento elemento);
  void desencolar();
  void print();
  Elemento frente();
  int obtLongitud();
  void vaciar(); 

};




template <class Elemento>
bool Cola<Elemento>::esVacia()
{
  return Lista<Elemento>::esVacia();
}

template <class Elemento>
void Cola<Elemento>::encolar(Elemento elemento)
{
  Nodo<Elemento> *aux;

  if (this->longitud == 0)
  {
    Lista<Elemento>::insertar(elemento, 0);
    this->cola = this->cabeza;
  }
  else
  {
    aux = new Nodo<Elemento>;
    aux->modInfo(elemento);
    aux->modProx(NULL);
    (this->cola)->modProx(aux);
    this->cola = aux;
    this->longitud += 1;
  }
}

template <class Elemento>
void Cola<Elemento>::desencolar()
{
  Lista<Elemento>::eliminar(0);
}

template <class Elemento>
void Cola<Elemento>::print()
{
  Lista<Elemento>::print();
}

template <class Elemento>
Elemento Cola<Elemento>::frente()
{
  return Lista<Elemento>::consultar(0);
}

template <class Elemento>
int Cola<Elemento>::obtLongitud()
{
  return Lista<Elemento>::obtLongitud();
}
template <class Elemento>
void Cola<Elemento>::vaciar()
{
   Lista<Elemento>::vaciar();
}

#endif