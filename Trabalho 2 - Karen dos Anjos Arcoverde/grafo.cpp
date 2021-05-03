/*****************************************************************************/
/***************************** Arquivo grafo.cpp *****************************/

#include "grafo.h"


void Grafo::insereVertice (Vertice &v){

    bool incluido_vertices = true;

    if (vertices.size() == 0)
        vertices.push_back (v);

    else{
        for (int indice = 0; indice < vertices.size(); indice++)
        {
            if (vertices[indice].getPalavra() == v.getPalavra())
                vertices[indice].setPesoPalavra(); //adiciona 1 sempre que a palavra nova for igual a alguma já colocada no vetor de vertices
                incluido_vertices = false;
        }
        if (incluido_vertices)
            vertices.push_back (v);      
    }
}

void Grafo::mostraMaiorPesoPalavra (){
    int maior_peso = 0;

    for (int indice = 0; indice < vertices.size(); indice++)
    {
        if (vertices [indice].getPesoPalavra() > maior_peso)
            maior_peso = vertices[indice].getPesoPalavra();
    }

    for (int indice = 0; indice < vertices.size(); indice++)
    {
        if (vertices[indice].getPesoPalavra() == maior_peso)
            cout << vertices[indice].getPalavra() << endl;
    }
}