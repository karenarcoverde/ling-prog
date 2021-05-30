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

        virtual ~Paciente(){};
        virtual string &getNomeDoPaciente();
        virtual void setCaracteristicas();

        bool operator>(const Paciente &);
        bool operator<(const Paciente &); 
        bool operator==(const Paciente &); 

        Paciente(string);
        Paciente();
        Paciente(const Paciente &);
    

    private:
        string nome_do_paciente;
};

class Paciente_Numero_Consultas: public Paciente{
    public:
        Paciente_Numero_Consultas();

        void setCaracteristicas();

    private:
        unsigned int numero_consultas = 1;
};

class Paciente_Risco: public Paciente {
    public:
        Paciente_Risco();

        double getRisco_paciente();
        
        void setCaracteristicas();

    private:
        double paciente_risco = 1.0;    
};
#endif
