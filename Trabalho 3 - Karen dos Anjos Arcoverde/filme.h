/*****************************************************************************/
/***************************** Arquivo filme.h *****************************/

#include <iostream>
#include <string>

using namespace std;

struct filme {
    string nomeDoFilme;
    string nomeDaProdutora;
    double notaDoFilme;
};


istream &operator>>(istream &, filme &);
ostream &operator<<(ostream &, const filme &);

