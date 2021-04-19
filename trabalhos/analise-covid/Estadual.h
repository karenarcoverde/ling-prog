/*****************************************************************************/
/******************************* Arquivo Estadual.h **************************/

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Estadual{
    public:
        void setNomeEstado(string);
        string getNomeEstado ();

        void setMortesDiarias (vector <int>);
        vector <int> getMortesDiarias ();

        float getMediaMovel (int);
        
        float getPorcentagemRisco (int);

        int getNumeroDeObitos ();
       

    private:
        string siglaEstado;
        vector <int> mortesEstado_dias;
};