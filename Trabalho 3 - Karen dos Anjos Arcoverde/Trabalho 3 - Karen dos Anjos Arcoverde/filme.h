/*****************************************************************************/
/***************************** Arquivo filme.h *****************************/

#include <iostream>
#include <string>

using namespace std;


istream &operator>>(istream &, filme &);
ostream &operator<<(ostream &, const filme &);

struct filme {
    string nomeDoFilme;
    string nomeDaProdutora;
    double notaDoFilme;
};

