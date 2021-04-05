/*****************************************************************************/
/***************************** Arquivo linha.h *******************************/

#include "ponto.h"
#include <cmath>

using namespace std;

class Linha{
    public:
        Linha (Ponto, Ponto);

        void setP1 (Ponto);
        void setP2 (Ponto);

        double getComprimento ();

    private:
        Ponto p1, p2;
};