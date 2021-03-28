/***************************************************************************/
/*************************** Programa Principal ****************************/

#include <iostream>
#include <string>
#include "agenda.h"

/* Programa do Laboratório 1: 
   Agenda para 3 nomes.
   Autor: Karen dos Anjos Arcoverde */

using namespace std;

int main (){
    //Objeto da classe Agenda
    Agenda agenda;

    agenda.setNames ();
    agenda.getNames ();

    return 0;
}