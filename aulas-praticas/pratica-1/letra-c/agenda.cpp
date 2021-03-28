/*****************************************************************************/
/***************************** Arquivo agenda.cpp ****************************/

#include "agenda.h"

void Agenda::setNames (){
    string name;

    for (int i = 0; i < 3;i++)
    {
        cout << "Entre com o nome " << (i+1) << ": " << endl;
        getline (cin, name);
        names[i] = checkName (name);
    }
}

void Agenda::getNames (){
    cout << "\nOs nomes na agenda sao: " << endl;

    for (int i = 0; i < 3; i++)
        cout << names[i] << endl;
}

string Agenda::checkName (string name){
    if (name.length () > 10){
        name = name.substr (0,10);
        cout << "Nome truncado para: " << name << endl;
    }

    return name;
}

