/*****************************************************************************/
/***************************** Arquivo grafo.h *****************************/
#include <iostream>
#include <vector>
#include <string>


#include "aresta.h"


using namespace std;

class Grafo{
    public:
        void insereVertice (Vertice &);
        void mostraMaiorPesoPalavra ();

        void insereAresta (Aresta &);
        void mostraMaiorPesoPalavraDupla ();
        
        void mostraMaiorPesopalavraN ();


    private:
        vector <Vertice> vertices;
        vector <Aresta> arestas;
};