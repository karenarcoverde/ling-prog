/***************************************************************************/
/*************************** paciente.cpp  **********************************/

#include <string>
#include <iostream>
#include "paciente.h"

using namespace std;


void Paciente_Numero_Consultas::setNumero_Consultas (int numero_de_consultas){
        numero_consultas = numero_de_consultas;
        paciente_caracteristicas = "Numero de consultas = " + to_string(numero_consultas);
}

void Paciente_Doenca::setTipo_Doenca (string tipo_de_doenca){
        tipo_doenca = tipo_de_doenca;
        paciente_caracteristicas = "Tipo de doenca = " + tipo_doenca;
}

istream &operator >>(istream & entrada,Paciente & paciente){

    cin.ignore();
    getline(entrada,paciente.nome_do_paciente);
    
    return entrada;
}

ostream &operator <<(ostream & saida, Paciente & paciente){
    saida << " Nome: " << paciente.getNomeDoPaciente() << endl;
    saida << "Caracteristicas: "<< paciente.paciente_caracteristicas << endl;
    saida << endl;

    return saida;
}

bool Paciente::operator>(const Paciente & paciente){
    return this->nome_do_paciente > paciente.nome_do_paciente;
}

bool Paciente::operator<(const Paciente & paciente){
    return this->nome_do_paciente < paciente.nome_do_paciente;
}

bool Paciente::operator==(const Paciente & paciente){
    return this->nome_do_paciente == paciente.nome_do_paciente;
}


Paciente::Paciente(string nome_paciente){
    nome_do_paciente = nome_paciente;
}

string &Paciente::getNomeDoPaciente(){
    return nome_do_paciente;
}

Paciente::Paciente(const Paciente & paciente){
    this->nome_do_paciente = paciente.nome_do_paciente;
    this->paciente_caracteristicas = paciente.paciente_caracteristicas;
}

Paciente::Paciente(){
    paciente_caracteristicas = "Sem informacoes sobre o paciente.";
}

Paciente_Doenca::Paciente_Doenca(){
    paciente_caracteristicas = "Tipo de doenca = " + tipo_doenca;
}

Paciente_Numero_Consultas::Paciente_Numero_Consultas(){
    paciente_caracteristicas = "Numero de consultas = " + to_string(numero_consultas);
}