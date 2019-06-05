#include "grafo.h"

Grafo::Grafo(int n, bool direc){
    vOrder = n;
    direcionado = direc;
    adjList = new list<int>[vOrder];
}

Grafo::~Grafo(){
    for (int i = 0; i < vOrder; i++){
        adjList[i].clear();
    }
    delete[] adjList;
}

void Grafo::addAresta(int orig, int dest){
    adjList[orig].push_back(dest);
    if (! direcionado){
        adjList[dest].push_back(orig);
    }
}

void Grafo::removeAresta(int orig, int dest){
    removeFromList( adjList[orig], dest);
    removeFromList( adjList[dest], orig);
}

void Grafo::removeFromList(list<int> &lista, int value){
    if (! lista.empty() ){
        list<int>::iterator it;
        for (it = lista.begin(); it != lista.end(); it++){
            if (*it == value){
                lista.erase(it);
                break;
            }
        }
    }
}

bool Grafo::temAresta(int orig, int dest){
    list<int>::iterator it;
    for (it = adjList[orig].begin(); it != adjList[orig].end; it++){
        if (*it == dest){
            return true;
        }
    }
    return false;
}

void Grafo::printAdjList(){
    for (int i = 0; i < vOrder; i++){
        cout << "Lista de adjacências do vértice " << i << ": ";
        for (const auto &vertex : adjList[i]){
            cout << vertex << " ";
        }
        cout << endl;
    }
}
