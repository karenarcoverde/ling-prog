/*****************************************************************************/
/******************************* Arquivo Estadual.h **************************/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Estadual{
    public:
        void setSiglaEstado(string);
        string getSiglaEstado ();

        void setMortesDiarias (vector);
        int getMortesDiarias ();


        void setMediaMovel (vector, int);
        double getMediaMovel ();

    private:
        string siglaEstado;
        vector <int> dias;
};