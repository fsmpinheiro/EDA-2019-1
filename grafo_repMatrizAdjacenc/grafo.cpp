#include <iostream>
#include <iomanip>
#include "grafo.h"

using namespace std;

Grafo::Grafo(int n, bool direc){
    vOrder = n;
    direcionado = direc ;
    adjMat = new int*[n];

    for (int i = 0; i < n; i++){
        adjMat[i] = new int [n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adjMat[i][j] = 0;
        }
    }
}

Grafo::~Grafo(){
    for (int i = 0; i < vOrder; i++){
        delete [] adjMat[i];
    }
    delete [] adjMat;
}

void Grafo::addAresta(int orig, int dest){
    adjMat[orig][dest] = 1;
    if (! direcionado){
        adjMat[dest][orig] = 1;
    }
}

void Grafo::removeAresta(int orig, int dest){
    adjMat[orig][dest] = 0;
    if (! direcionado){
        adjMat[dest][orig] = 0;
    }
}

bool Grafo::temAresta(int orig, int dest){
    return adjMat[orig][dest];
}

void Grafo::imprimeVizinhos(int u){
    cout << "::> Vizinhos do vértice " << u << ": ";
    for (int v = 0; v < vOrder; v++){
        if (adjMat[u][v]){
            cout << v << " ";
        }
        cout << endl;
    }
}

void Grafo::imprimeAdjMatrix(){
    for (int u = 0; u < vOrder; u++){
        for (int v = 0; v < vOrder; v++){
            cout << std::setw(3) << adjMat[u][v];
        }
        cout << endl;
    }
}

int Grafo::grau(int v){
    int grau = 0;
    for (int u = 0; u < vOrder; u++){
        if (adjMat[v][u]){
            grau = grau + 1;
        }
    }
    return grau;
}

int Grafo::ordem(){
    return vOrder;
}

int maisPopular(Grafo &graff){
    int max = 0;
    int grau_max = graff.grau(0);
    for (int u = 1; u < graff.ordem(); u++){
        int grau_atual = graff.grau(u);
        if (grau_atual > grau_max){
            grau_max = grau_atual;
            max = u;
        }
    }
    return max;
}
