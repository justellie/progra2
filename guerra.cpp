#include <iostream>
#include "Nodo.h"
#include "Listas.h"
#include "Cola.h"
#include <fstream>

void guerra(Cola<int>&,Cola<int>&);


using namespace std;

int main()
{
    Cola<int> uno, dos;
    //ifstream myfile;



    int a , b,i,cont;
    i=0;
    cont=0;
    cin>> a;
    while(cont<a){
        i=0;
        while(i<26)
        {
            cin>>b;
            uno.encolar(b);
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
        //uno.print();
        //dos.print();
        guerra(uno,dos);
        uno.vaciar();
        dos.vaciar();
        cont+=1;
    }
    return 0;

    

}
void guerra(Cola<int>& jugador1,Cola<int>&jugador2)
{
    Cola<int> aux;
    int n, carta1,carta2,carta12,carta13,carta22,carta23;
    n=0;
    bool estanGuerra;
    estanGuerra=false;
    while(!jugador1.esVacia() && !jugador2.esVacia())
    {   
        
        n+=1;
        carta1=jugador1.frente();
        carta2=jugador2.frente();
        jugador1.desencolar();
        jugador2.desencolar();
       
        if(carta1>carta2)
        {
            jugador1.encolar(carta1);
            jugador1.encolar(carta2);
           
            
        }
        else
        {
            if(carta1<carta2)
            {

                jugador2.encolar(carta1);
                jugador2.encolar(carta2);
                
            }
            else
            {
                if(carta1==carta2)
                {
                    while((carta1==carta2)&&!jugador1.esVacia()&&!jugador2.esVacia())
                    {
                        aux.encolar(carta1);
                        aux.encolar(carta2);
                        if(!jugador1.esVacia()&&!jugador2.esVacia())
                        {
                            carta12=jugador1.frente();
                            jugador1.desencolar();
                            carta22=jugador2.frente();
                            jugador2.desencolar();
                            n+=1;
                            aux.encolar(carta12);
                            aux.encolar(carta22);

                        }
                       
                        
                        if(!jugador1.esVacia()&&!jugador2.esVacia())
                        {
                            carta13=jugador1.frente();
                            carta23=jugador2.frente();
                            aux.encolar(carta12);
                            aux.encolar(carta22);
                            jugador1.desencolar();
                            jugador2.desencolar();
                            n+=1;
                            carta1=carta13;
                            carta2=carta23;
                        }
                        
                        

                    }
                    if(carta1>carta2)
                    {
                        jugador1.copiar(aux);
                        aux.vaciar();
                    }
                    else
                    {
                        if(carta1<carta2)
                        {
                            jugador2.copiar(aux);
                            aux.vaciar(); 
                        }
                        
                    }
                    
                }

            }
            
        }
        
        
      
    }

    
    if(aux.esVacia())
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