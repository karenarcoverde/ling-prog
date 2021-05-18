/*****************************************************************************/
/***************************** Arquivo catalogo.h ***************************/

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "filme.h"

class Catalogo {
    friend ostream &operator<<(ostream &, const Catalogo &);

    friend const Catalogo &operator-=(Catalogo &, const filme &);
    friend const Catalogo &operator+=(Catalogo &, const filme &);
    friend const Catalogo &operator+=(Catalogo &, const vector <filme> &);
    
    friend bool operator==(const filme &, const filme &);
    friend bool operator>(const filme &, const double &);
    friend bool operator>(const filme &, const filme &);
    
    public:
        Catalogo();

        void ExibeFilmeBemAvaliado();
        void RenovarCatalogo();

        filme *operator()(string);
        filme *operator()(string, string);
        filme *operator()(string, double);

    private:
        const static int tamanhoMaximoNumeroDeFilmes = 20;
        string arquivo;
        vector <filme> conjuntoDeFilmes;
};