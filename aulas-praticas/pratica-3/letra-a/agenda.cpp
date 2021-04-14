/*****************************************************************************/
/***************************** Arquivo agenda.cpp ****************************/

#include "agenda.h"

Agenda::Agenda (int n){
    maxNomes = n;
}

void Agenda::insereNome (string str){
    str = verificaNome (str);

    if (v.size () > maxNomes)
        cout << "Agenda cheia!" << endl;
    else
        v.push_back (str);

}

void Agenda::mostraNomes (){
    for (int i = 0; i < v.size (); i++){
        cout << "Nome [" << i  <<"] "
             << v.at (i) << endl;         
    }
}

string Agenda::verificaNome (string str){
    if (str.length () > 10){
        cout << "Nome com mais de 10 caracteres, reduzindo para 10...";
        cout << endl;
        // Trunca o nome com método substr
        str = str.substr (0,10);
    }

    return str;
}