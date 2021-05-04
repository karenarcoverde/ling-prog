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
        
        void setTodosOsVertices (Vertice &);
        Vertice getVerticeEspecifico (int);


    private:
        vector <Vertice> vertices;
        vector <Aresta> arestas;
        vector <Vertice> vertices_modificado;
};