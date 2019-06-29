#ifndef Pila_H
#define Pila_H

#include "Listas.h"

template <class Elemento>
class Pila : protected Lista<Elemento>
{
public:
  
  bool esVacia();
  void apilar(Elemento elemento);
  void desapilar();
  void print();
  Elemento tope();
  int obtLongitud();
  void vaciar();
};




template <class Elemento>
bool Pila<Elemento>::esVacia()
{
  return Lista<Elemento>::esVacia();
}

template <class Elemento>
void Pila<Elemento>::apilar(Elemento elemento)
{

    Lista<Elemento>::insertar(elemento, 0);
 
 
}

template <class Elemento>
void Pila<Elemento>::desapilar()
{
  Lista<Elemento>::eliminar(0);
}

template <class Elemento>
void Pila<Elemento>::print()
{
  Lista<Elemento>::print();
}

template <class Elemento>
Elemento Pila<Elemento>::tope()
{
  return Lista<Elemento>::consultar(0);
}

template <class Elemento>
int Pila<Elemento>::obtLongitud()
{
  return Lista<Elemento>::obtLongitud();
}
template <class Elemento>
void Pila<Elemento>::vaciar()
{
 Lista<Elemento>::vaciar();
}
#endif