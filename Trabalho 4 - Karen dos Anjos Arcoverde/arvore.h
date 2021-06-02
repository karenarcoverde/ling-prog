/***************************************************************************/
/*************************** arvore.h  **********************************/

#include <iostream>
#include <string>
#include <vector>
#include "paciente.h"



//wrapper para t = Paciente/Paciente_Doenca/paciente_consulta 
template <class T>
class No{
    T dado;
    No<T> *esquerda;
    No<T> *direita;
    friend class Arvore;
};

//t = paciente
template <class T>
class Arvore{

    template <class unused>
    friend ostream &operator<<(ostream & saida, Arvore<T> & arvore);

    public:
        Arvore();
        ~Arvore();
        T *operator+=(const T &AdicionarNaArvore);
        T *operator()(const string & nome_paciente);
        

    private:
        //void Exibe(No<T> *inicio, ostream & saida);                                    
        No<T> *Insere(No<T> *inicio, const T &AdicionarNaArvore);       

        template <class type_data>
        No<T> *Procura(No<T> *inicio, const type_data &nome_paciente);

        No<T> *InicioArvore = NULL;
};


template <class T>
Arvore<T>::Arvore(){}

template <class T>
Arvore<T>::~Arvore(){
    vector<T *> raizes;
    No<T> * raiz=InicioArvore;
    if (!InicioArvore)
        return;

    while (raiz){
        if (raiz->direita)
            raiz=raiz->direita;
        else if (raiz->esquerda)
            raiz = raiz->esquerda;
        else
            raizes.back(raiz);
    }
    for(auto r : raizes)
        delete r;
    
        
}

template <class T>
T *Arvore<T>::operator+=(const T & AdicionarNaArvore){

    if (InicioArvore == NULL){
        InicioArvore = new No<T>;
        InicioArvore->paciente = AdicionarNaArvore;

        return &(InicioArvore->paciente);
    }
    else
        return &(Insere(InicioArvore, AdicionarNaArvore));
}

template <class T>
ostream &operator<<(ostream & saida, Arvore<T> & arvore){
    No<T> *noPtr = arvore.InicioArvore;

    while(noPtr){
        if(noPtr->direita)
            noPtr=noPtr->direita;

        saida << noPtr->paciente << endl;

        if (noPtr->esquerda)
            noPtr=noPtr->esquerda;
    }
    return saida;
}
/*
template <class T>
void Arvore<T>::Exibe(No<T> *inicio, ostream & saida){
    if (inicio->direita)
        Exibe(inicio->direita, saida);

    saida << inicio->paciente << endl;

    if (inicio->esquerda)
        Exibe(inicio->esquerda, saida);
}*/


template <class T>
T *Arvore<T>::operator()(const string & nome_paciente){
    return &(Procura(InicioArvore, nome_paciente)->paciente);
}

template <class T>
template <class type_data>

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


template <class T>
No<T> *Arvore<T>::Insere(No<T> *inicio, const T & AdicionarNaArvore){
  
    if (inicio->paciente > AdicionarNaArvore){

        if (inicio->direita == NULL){
            inicio->direita = new No<T>;
            inicio->direita->paciente = AdicionarNaArvore;

            return inicio->direita->paciente;
        }
        else
            return Insere(inicio->direita, AdicionarNaArvore);
    }
    else{
        if (inicio->esquerda == NULL){
            inicio->esquerda = new No<T>;
            inicio->esquerda->paciente = AdicionarNaArvore;

            return inicio->esquerda->paciente;
        }
        else
            return Insere(inicio->esquerda, AdicionarNaArvore);
    }
}