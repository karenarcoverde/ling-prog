/***************************************************************************/
/*************************** paciente.h  **********************************/

#ifndef paciente_h
#define paciente_h
#include <string>

using namespace std;

class Paciente {

    friend istream &operator >>(istream &, Paciente &);
    friend ostream &operator <<(ostream &, Paciente &);

    public:
        string paciente_caracteristicas;

        virtual string &getNomeDoPaciente();

        bool operator>(const Paciente &);
        bool operator<(const Paciente &); 
        bool operator==(const Paciente &); 

        Paciente(string);
        Paciente();
        Paciente(const Paciente &);
    
    private:
        string nome_do_paciente;
};


//usando o conceito de herança -- Pacientes derivados
class Paciente_Numero_Consultas: public Paciente{
    public:
        Paciente_Numero_Consultas();
        void setNumero_Consultas (int);
    private:
        int numero_consultas = 1;
};

class Paciente_Doenca: public Paciente {
    public:
        Paciente_Doenca();
        void setTipo_Doenca(string);
    private:
        string tipo_doenca = "Saudavel";    
};
#endif
