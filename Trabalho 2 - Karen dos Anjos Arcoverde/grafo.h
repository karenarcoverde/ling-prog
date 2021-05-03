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


    private:
        vector <Vertice> vertices;

};