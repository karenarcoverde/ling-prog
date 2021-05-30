/***************************************************************************/
/*************************** arvore.h  **********************************/

#include <iostream>
#include <string>

#include "paciente.h"

template <typename type_data>
struct No{
    type_data paciente;
    No *direita;
    No *esquerda;
    No();
};

template <typename type_data>
No<type_data>::No() : direita(NULL), esquerda(NULL){};

template <typename T>
class Arvore{

    template <typename ArvoreTipo>
    friend ostream &operator<<(ostream & saida, Arvore<T> & arvore);

    public:
        Arvore();
        ~Arvore();
        T *operator+=(const T &AdicionarNaArvore);
        T *operator()(const string & nome_paciente);
        void exibicao(ostream & saida);

    private:
        void Exibe(No<T> *inicio, ostream & saida);           
        void Deleta(No<T> *inicio);                           
        No<T> *Insere(No<T> *inicio, const T &AdicionarNaArvore);       

        template <typename type_data>
        No<T> *Procura(No<T> *inicio, const type_data &nome_paciente);

        No<T> *InicioArvore = NULL;
};


template <typename T>
Arvore<T>::Arvore(){}

template <typename T>
Arvore<T>::~Arvore(){
    if (InicioArvore != NULL)
        Deleta(InicioArvore);
}

template <typename T>
T *Arvore<T>::operator+=(const T & AdicionarNaArvore){

    if (InicioArvore == NULL){
        InicioArvore = new No<T>;
        InicioArvore->paciente = AdicionarNaArvore;

        return &(InicioArvore->paciente);
    }
    else
        return &(Insere(InicioArvore, AdicionarNaArvore)->paciente);
}

template <typename T>
ostream &operator<<(ostream & saida, Arvore<T> & Arvore){
    Arvore.exibicao(saida);

    return saida;
}

template <typename T>
void Arvore<T>::exibicao(ostream & saida){
    if (InicioArvore)
        Exibe(InicioArvore, saida);
}

template <typename T>
void Arvore<T>::Exibe(No<T> *inicio, ostream & saida){
    if (inicio->direita)
        Exibe(inicio->direita, saida);

    saida << inicio->paciente << endl;

    if (inicio->esquerda)
        Exibe(inicio->esquerda, saida);
}

template <typename T>
void Arvore<T>::Deleta(No<T> *inicio){
    if (inicio->direita)
        Deleta(inicio->direita);

    if (inicio->esquerda)
        Deleta(inicio->esquerda);

    delete inicio;
}

template <typename T>
No<T> *Arvore<T>::Insere(No<T> *inicio, const T & AdicionarNaArvore){
  
    if (inicio->paciente < AdicionarNaArvore){
        if (inicio->esquerda == NULL){
            inicio->esquerda = new No<T>;
            inicio->esquerda->paciente = AdicionarNaArvore;

            return inicio->esquerda;
        }
        else
            return Insere(inicio->esquerda, AdicionarNaArvore);
    }
    else{
        if (inicio->direita == NULL){
            inicio->direita = new No<T>;
            inicio->direita->paciente = AdicionarNaArvore;

            return inicio->direita;
        }
        else
            return Insere(inicio->direita, AdicionarNaArvore);
    }
}


template <typename T>
T *Arvore<T>::operator()(const string & nome_paciente){
    return &(Procura(InicioArvore, nome_paciente)->paciente);
}

template <typename T>
template <typename type_data>

No<T> *Arvore<T>::Procura(No<T> *inicio, const type_data &valor){
    if (inicio == NULL)
        return NULL;

    else if (inicio->paciente == valor)
        return inicio;

    else if (inicio->paciente < valor)
        return Procura(inicio->esquerda, valor);

    else
        return Procura(inicio->direita, valor);
}