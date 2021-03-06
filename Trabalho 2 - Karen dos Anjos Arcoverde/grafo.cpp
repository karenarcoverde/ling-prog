/*****************************************************************************/
/***************************** Arquivo grafo.cpp *****************************/

#include "grafo.h"

//para pegar todas as palavras do texto mesmo que tenha repetido palavra
void Grafo::setTodosOsVertices (Vertice &v_2){ 
    vertices_modificado.push_back(v_2);
}

Vertice Grafo::getVerticeEspecifico (int qtdVertices){
    return vertices_modificado[qtdVertices]; //pega um vertice especifico escolhido na main.cpp
}



void Grafo::insereVertice (Vertice &v){ //pega todas as palavras não repetidas no texto

    int incluido_vertices = 1;

    if (vertices.size() == 0)
        vertices.push_back (v);

    else{
        for (unsigned int indice = 0; indice < vertices.size(); indice++)
        {
            if (vertices[indice].getPalavra() == v.getPalavra()){ //se ja tiver uma palavra igual no vetor de vertices
                vertices[indice].setPesoPalavra(); //adiciona 1 sempre que a palavra nova for igual a alguma já colocada no vetor de vertices
                incluido_vertices = 0;
           }
        }
        if (incluido_vertices == 1) //se a palavra nao tiver sido repetida no vetor de vertices, inclui no vetor
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
        if (vertices[indice].getPesoPalavra() == maior_peso) //imprime a palavra sempre que o maior peso for repetido mais de uma vez
            cout << vertices[indice].getPalavra() << endl;
    }
}


void Grafo::insereAresta (Aresta &a){

    int incluido_arestas = 1;

    if (arestas.size() == 0)
        arestas.push_back (a);

    else{
        for (unsigned int indice = 0; indice < arestas.size(); indice++)
        {
            if (arestas[indice].getNomePrimeiroVertice () == a.getNomePrimeiroVertice () && arestas[indice].getNomeSegundoVertice () == a.getNomeSegundoVertice()){
                arestas[indice].setPesoAresta(); //adiciona 1 sempre que a aresta nova for igual a alguma já colocada no vetor de arestas
                incluido_arestas = 0;
            }
        }
        if (incluido_arestas == 1)
            arestas.push_back (a);      
    }
}

void Grafo::mostraMaiorPesoPalavraDupla (){

    int maior_peso = 0;

    for (unsigned int indice = 0; indice < arestas.size(); indice++) //pega o maior peso e guarda numa variavel
    {
        if (arestas [indice].getPesoAresta() > maior_peso) //enquanto guarda um valor, compara para ver se tem outro maior, caso tenha, substitui o valor
            maior_peso = arestas[indice].getPesoAresta();
    }

    for (unsigned int indice = 0; indice < arestas.size(); indice++)
    {
        if (arestas[indice].getPesoAresta() == maior_peso)
            cout << arestas[indice].getNomePrimeiroVertice () << " " << arestas[indice].getNomeSegundoVertice () << endl;
    }
}