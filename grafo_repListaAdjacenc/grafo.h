#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
using namespace std;


class Grafo{
private:
    int vOrder;         //numero de vértices |V(G)|
    bool direcionado;   //boleano que diz se o grafo é direcionado ou não
    list<int> *adjList; //lista de vetores de inteiros
    void removeFromList(list<int> &lista, int v);

public:
    Grafo(int n, bool direc);
    ~Grafo();

    void addAresta(int orig, int dest);
    void removeAresta(int orig, int dest);

    bool temAresta(int orig, int dest);
    void printAdjList();
};

#endif // GRAFO_H
