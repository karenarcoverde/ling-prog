/*****************************************************************************/
/***************************** Arquivo aresta.h ******************************/
#include <iostream>

#include "vertice.h"

using namespace std;

class Aresta{
    public:
        Aresta (Vertice, Vertice); //construtor

        void setPesoAresta ();
        int getPesoAresta ();

        Vertice getPrimeiroVertice ();
        Vertice getSegundoVertice ();

        string getNomePrimeiroVertice ();
        string getNomeSegundoVertice ();


    private:
        int peso = 1;
        Vertice primeiroVertice, segundoVertice; 
};