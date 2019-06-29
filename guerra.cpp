#include <iostream>
#include "Nodo.h"
#include "Listas.h"
#include "Cola.h"
#include <fstream>



using namespace std;

int main()
{
    Cola<int> uno, dos;
    //ifstream myfile;

   

    int a , b,i;
    i=0;
    cin>> a;
    
    while(i<26)
    {
        cin>>b;
        uno.encolar(b);
        i+=1;
    }
    i=0;
    while(i<26)
    {
        cin>>b;
        dos.encolar(b);
        i+=1;
    }
    uno.print();
    dos.print();

    

}