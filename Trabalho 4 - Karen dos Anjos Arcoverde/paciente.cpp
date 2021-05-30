/***************************************************************************/
/*************************** paciente.cpp  **********************************/

#include <string>
#include <iostream>
#include "paciente.h"

using namespace std;


istream &operator >>(istream & entrada,Paciente & paciente){

    getline(entrada, paciente.nome_do_paciente);

    entrada >> paciente.nome_do_paciente;
    
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


void Paciente::setPaciente(string nome_paciente){
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
    setCaracteristicas();
}

void Paciente::setCaracteristicas(){
    paciente_caracteristicas = "Sem informacoes sobre o paciente.";
}

double Paciente_Risco::getRisco_paciente(){
    return paciente_risco;
}

void Paciente_Risco::setCaracteristicas(){
    paciente_caracteristicas = "Paciente em risco, grau do risco = " + to_string(paciente_risco);
}

void Paciente_Numero_Consultas::setCaracteristicas(){
    paciente_caracteristicas = "Paciente com consultas, numero de consultas = " + to_string(numero_consultas);
}


Paciente_Risco::Paciente_Risco(){
    setCaracteristicas();
}

Paciente_Numero_Consultas::Paciente_Numero_Consultas(){
    setCaracteristicas();
}

