/***************************************************************************/
/*************************** arvore.h  **********************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "paciente.h"


template <class  T>
class No{
    public:
        T dado;
        No *esquerda=nullptr;
        No *direita=nullptr;
};

//t = paciente
template <class T>
class Arvore{

    template <class unused>
    friend ostream &operator<<(ostream & saida, Arvore<T> & arvore);

    public:
        ~Arvore();
        T *operator+=(const T &AdicionarNaArvore);
        T *operator()(const string & nome_paciente);
        
    
        No<T> *InicioArvore = nullptr;

    private:                                   
        No<T> *Insere(No<T> *inicio, const T &AdicionarNaArvore);       

        template <class type_data>
        No<T> *Procura(No<T> *inicio, const type_data &nome_paciente);


};



template <class T>
Arvore<T>::~Arvore(){

    stack<No<T>*> stack;
    No<T>* curr = InicioArvore;

    while (!stack.empty() || curr != nullptr)
    {

        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->direita;
        }
        else {
            curr = stack.top();
            stack.pop();
            curr = curr->esquerda;
            delete curr;
        }
    }
       
}

template <class T>
T *Arvore<T>::operator+=(const T & AdicionarNaArvore){

    if (InicioArvore == NULL){
        InicioArvore = new No<T>;
        InicioArvore->dado = AdicionarNaArvore;

        return &InicioArvore->dado;
    }
    else
        return &(Insere(InicioArvore, AdicionarNaArvore)->dado);
}

template <class T>
ostream &operator<<(ostream & saida, Arvore<T> & arvore){

   
    stack<No<T>*> stack;
 
    No<T>* curr = arvore.InicioArvore;
 
    while (!stack.empty() || curr != nullptr)
    {

        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->direita;
        }
        else {
            curr = stack.top();
            stack.pop();
            cout << curr->dado << endl;
 
            curr = curr->esquerda;
        }
    }
    
    return saida;
}

template <class T>
T *Arvore<T>::operator()(const string & nome_paciente){
    return &(Procura(InicioArvore, nome_paciente)->dado);
}

template <class T>
template <class type_data>

No<T> *Arvore<T>::Procura(No<T> *inicio, const type_data &valor){
    if (inicio == NULL)
        return NULL;

    else if (inicio->dado == valor)
        return inicio;

    else if (inicio->dado < valor)
        return Procura(inicio->esquerda, valor);

    else
        return Procura(inicio->direita, valor);
}


template <class T>
No<T> *Arvore<T>::Insere(No<T> *inicio, const T & AdicionarNaArvore){
  
    if (inicio->dado==AdicionarNaArvore){
        return nullptr;
    }
    if (inicio->dado > AdicionarNaArvore){

        if (inicio->direita == NULL){
            inicio->direita = new No<T>;
            inicio->direita->dado = AdicionarNaArvore;

            return inicio->direita;
        }
        else
            return Insere(inicio->direita, AdicionarNaArvore);
    }
    else{
        if (inicio->esquerda == NULL){
            inicio->esquerda = new No<T>;
            inicio->esquerda->dado = AdicionarNaArvore;

            return inicio->esquerda;
        }
        else
            return Insere(inicio->esquerda, AdicionarNaArvore);
    }
}