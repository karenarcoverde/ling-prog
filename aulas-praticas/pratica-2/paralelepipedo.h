/*****************************************************************************/
/************************ Arquivo paralelepipedo.h ***************************/

#include <iostream>

using namespace std;

class Paralelepipedo {
    public:
        Paralelepipedo (double, double, double);

        void setDimX (double);
        void setDimY (double);
        void setDimZ (double);

        double getVolume ();

    private:
        double dimX, dimY, dimZ;
        double computeVolume ();

};