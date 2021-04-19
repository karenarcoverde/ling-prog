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
        //void mostraMediaMovelBrasil ();
        void mostraMediaMovelEstados ();

        void setMaiorPorcentagemRisco (double);
        string getMaiorPorcentagemRisco ();

        void setMenorPorcentagemRisco (double);
        string getMenorPorcentagemRisco ();


    private:
        // Vector para armazenamento de estados 
        vector <Estadual> estados;




};