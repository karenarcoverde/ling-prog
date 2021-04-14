/*****************************************************************************/
/***************************** Arquivo agenda.cpp ****************************/

#include "agenda.h"

int Agenda::numeroNomes = 0;


void Agenda::insereNome (string str){
    str = verificaNome (str);

    if (numeroNomes >= maxNomes)
        cout << "Agenda cheia!" << endl;
    else
        nomes [numeroNomes++] = str;
}

void Agenda::mostraNomes (){
    for (int i = 0; i < numeroNomes; i++){
        cout << "Nome [" << i  <<"] "
             << nomes [i] << endl;         
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