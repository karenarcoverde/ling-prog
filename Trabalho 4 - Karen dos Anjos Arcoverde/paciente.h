/***************************************************************************/
/*************************** paciente.h  **********************************/

#include <string>

using namespace std;

class Paciente {

    friend istream &operator >>(istream &, Paciente &);
    friend ostream &operator <<(ostream &, Paciente &);

    public:
        string paciente_caracteristicas;

        virtual ~Paciente(){};
        virtual string &getName();
        virtual void setCaracteristicas();

        bool operator>(Paciente const &);
        bool operator<(Paciente const &); 
        bool operator==(Paciente const &); 

        Paciente(string);
        Paciente();
        Paciente(const Paciente &);
    

    private:
        string nome_do_paciente;
};

class Paciente_Caracteristicas: public Paciente {
    public:
        Paciente_Caracteristicas();

        double getRisco_paciente();
        
        void setCaracteristicas();

    private:
        double paciente_risco = 1.0;    
};

class Paciente_Numero_Consultas: public Paciente{
    public:
        Paciente_Numero_Consultas();

        void setCaracteristicas();

    private:
        unsigned int numero_consultas = 1;
};