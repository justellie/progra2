#ifndef COLA_H
#define COLA_H

#include "Listas.h"

template <class Elemento>
class Cola : protected Lista<Elemento>
{
protected:
  Nodo<Elemento> *ultimo;

public:
  Cola();
  bool esVacia();
  void encolar(Elemento elemento);
  void desencolar();
  void print();
  Elemento frente();
  int obtLongitud();
};

template <class Elemento>
Cola<Elemento>::Cola()
{
  this->ultimo = NULL;
}

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
    Lista<T>::insertar(elemento, 0);
    this->ultimo = this->primero;
  }
  else
  {
    aux = new Nodo<Elemento>;
    aux->modInfo(elemento);
    aux->modProx(NULL);
    (this->ultimo)->modProx(aux);
    this->ultimo = aux;
    this->longitud += 1;
  }
}

template <class Elemento>
void Cola<Elemento>::desencolar()
{
  Lista<Elemento>::eliminar(0);
  if (this->longitud == 0)
  {
    this->ultimo = NULL;
  }
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

#endif