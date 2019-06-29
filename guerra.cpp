#include <iostream>
#include "Nodo.h"
#include "Listas.h"
#include "Cola.h"
#include <fstream>

void guerra(Cola<int>&,Cola<int>&);


using namespace std;

int main()
{
    Cola<int> uno, dos;//cola para los jugadores
    



    int a , b,i,cont;
    i=0;//i es el interador se encarga de llevar el conteo de encolado
    cont=0;//cont es el encarcado de llevar el conteo de juegos
    cin>> a;//a es el numero de juegos
    while(cont<a){
        i=0;
        while(i<26)
        {
            cin>>b;
            uno.encolar(b);//b recibe los datos y encola
            i+=1;
        }
        i=0;
        b=0;
        while(i<26)
        {
            cin>>b;
            dos.encolar(b);
            i+=1;
        }
    
        guerra(uno,dos);//se llama a guerra
        uno.vaciar();//se vacian ambas para si evitar la errores
        dos.vaciar();
        cont+=1;
    }//se finaliza el ciclo de jugadas
    return 0;

    

}
void guerra(Cola<int>& jugador1,Cola<int>&jugador2)//se reciben a los dos mazos
{
    Cola<int> aux;//mazo auxiliar de guerra es una cola
    int n, carta1,carta2,carta12,carta13,carta22,carta23;//guardara los valores de las cartas
    n=0;//contador de jugadas
    while(!jugador1.esVacia() && !jugador2.esVacia())//mientras existan cartas en el maso
    {   
        
        n+=1;//cada vez que se saquen cartas de los mazos se sumara uno 
        carta1=jugador1.frente();//se guardan los datos en las cartas 1 y 2
        carta2=jugador2.frente();
        jugador1.desencolar();//sacamos del mazo
        jugador2.desencolar();
       
        if(carta1>carta2)//si la carta uno es mayor a la dos
        {
            jugador1.encolar(carta1);//se lleva ambas cartas jugador 1
            jugador1.encolar(carta2);
           
            
        }
        else
        {
            if(carta1<carta2)//si la carta dos es mayor que la 1
            {

                jugador2.encolar(carta1);//se lleva ambas cartas el jugador 2
                jugador2.encolar(carta2);
                
            }
            else
            {
                if(carta1==carta2)//si ambas cartas son iguales guerra!
                {
                    while((carta1==carta2)&&!jugador1.esVacia()&&!jugador2.esVacia())//mientras ambas carta sean iguales y los mazos no esten vacios
                    {
                        aux.encolar(carta1);//encolamos esas dos primeras cartas en aux
                        aux.encolar(carta2);
                        
                        //Sacamos dos cartas de cada mazo y evaluamos el segundo par que es sacado

                        carta12=jugador1.frente();//estas son las cartas boca abajo
                        jugador1.desencolar();
                        carta22=jugador2.frente();
                        jugador2.desencolar();
                        n+=1;//aumentamos el contador de jugadas porque sacamos cartas
                        aux.encolar(carta12);//encolamos en primer par de cartas que sacamos
                        aux.encolar(carta22);

                        
                       
                        
                        if(!jugador1.esVacia()&&!jugador2.esVacia())//SI DESPUES DE SACAR EL PRIMER PAR AUN HAY CARTAS SACAMOS LA SEGUNDA
                        {
                            carta13=jugador1.frente();
                            carta23=jugador2.frente();
                            aux.encolar(carta12);
                            aux.encolar(carta22);
                            jugador1.desencolar();
                            jugador2.desencolar();
                            n+=1;//aumentamos el contador de jugadas porque sacamos cartas
                            carta1=carta13;//le asignamos el valor de las cartas "boca arriba" a las cartas 1 y 2 para ser evaluadas
                            carta2=carta23;
                        }
                        
                        

                    }
                    if(carta1>carta2)//si la guerra termino y la carta1 es mayor a la 2 el jugador dos toma todas las cartas de  maso auxiliar
                    {
                        jugador1.copiar(aux);
                        aux.vaciar();
                    }
                    else
                    {
                        if(carta1<carta2)//en caso contrario el segundo jugador hace lo propio
                        {
                            jugador2.copiar(aux);
                            aux.vaciar(); 
                        }
                        
                    }
                    
                }

            }
            
        }
        
        
      
    }

    
    if(aux.esVacia())//si el mazo auxiliar es vacio entonces no hubo empate
    {
        if(jugador1.esVacia())
        {
            cout<<"Jugador_2"<<endl;
        }
        else
        {
         cout<<"Jugador_1"<<endl;   
        }
        
    }
    else
    {
        cout<<"Empate"<<endl;
    }
    cout<<n<<endl;


}