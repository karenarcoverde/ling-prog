/*****************************************************************************/
/******************************* Arquivo Nacional.h **************************/

#include <iostream>
#include <string>
#include <vector>

#include "Estadual.h"

using namespace std;

class Nacional{
    public:
        void insereEstado (Estadual &);

        void mostraNumeroDeObitosBrasil ();
        void mostraNumeroDeObitosEstados ();
        void mostraMediaMovelBrasil (int);
        void mostraMediaMovelEstados (int);

        void mostraEstabilidadeEstados(int);
        void mostraEstabilidadeBrasil(int);

        
        void mostraMaiorPorcentagemRisco (int);
        void mostraMenorPorcentagemRisco (int);


    private:
        // Vector para armazenamento de estados 
        vector <Estadual> estados;




};