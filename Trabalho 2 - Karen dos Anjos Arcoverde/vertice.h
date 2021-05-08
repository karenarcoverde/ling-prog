/*****************************************************************************/
/***************************** Arquivo vertice.h *****************************/
#include <iostream>
#include <vector>

using namespace std;

#ifndef VERTICE_H
#define VERTICE_H

class Vertice{
    public:
        void setPalavra (string);
        string getPalavra ();

        void setPesoPalavra ();
        int getPesoPalavra ();

    private:
        int peso = 1;
        string palavra;    
};

#endif