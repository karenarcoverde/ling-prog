/*****************************************************************************/
/***************************** Arquivo grafo.cpp *****************************/

#include "grafo.h"

//para pegar todas as palavras do texto mesmo que tenha repetido palavra
void Grafo::setTodosOsVertices (Vertice &v_2){ 
    vertices_modificado.push_back(v_2);
}

Vertice *Grafo::getVerticeEspecifico (int qtdVertices){
    return &vertices_modificado[qtdVertices];
}



void Grafo::insereVertice (Vertice &v){ //pega todas as palavras não repetidas no texto

    bool incluido_vertices = true;

    if (vertices.size() == 0)
        vertices.push_back (v);

    else{
        for (unsigned int indice = 0; indice < vertices.size(); indice++)
        {
            if (vertices[indice].getPalavra() == v.getPalavra()){
                vertices[indice].setPesoPalavra(); //adiciona 1 sempre que a palavra nova for igual a alguma já colocada no vetor de vertices
                incluido_vertices = false;
           }
        }
        if (incluido_vertices)
            vertices.push_back (v);      
    }
}

void Grafo::mostraMaiorPesoPalavra (){
    int maior_peso = 0;

    for (unsigned int indice = 0; indice < vertices.size(); indice++)
    {
        if (vertices [indice].getPesoPalavra() > maior_peso)
            maior_peso = vertices[indice].getPesoPalavra();
    }

    for (unsigned int indice = 0; indice < vertices.size(); indice++)
    {
        if (vertices[indice].getPesoPalavra() == maior_peso)
            cout << vertices[indice].getPalavra() << endl;
    }
}


void Grafo::insereAresta (Aresta &a){

    bool incluido_arestas = true;

    if (arestas.size() == 0)
        arestas.push_back (a);

    else{
        for (unsigned int indice = 0; indice < arestas.size(); indice++)
        {
            if (arestas[indice].getPrimeiroVertice() == a.getPrimeiroVertice() && arestas[indice].getSegundoVertice() == a.getSegundoVertice()){
                arestas[indice].setPesoAresta(); //adiciona 1 sempre que a aresta nova for igual a alguma já colocada no vetor de arestas
                incluido_arestas = false;
            }
        }
        if (incluido_arestas)
            arestas.push_back (a);      
    }
}

void Grafo::mostraMaiorPesoPalavraDupla (){

    int maior_peso = 0;

    for (unsigned int indice = 0; indice < arestas.size(); indice++)
    {
        if (arestas [indice].getPesoAresta() > maior_peso)
            maior_peso = arestas[indice].getPesoAresta();
    }

    for (unsigned int indice = 0; indice < arestas.size(); indice++)
    {
        if (arestas[indice].getPesoAresta() == maior_peso)
            cout << arestas[indice].getPesoAresta() << endl;
    }
}