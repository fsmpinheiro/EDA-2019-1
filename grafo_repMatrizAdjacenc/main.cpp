#include <iostream>
#include "grafo.h"
using namespace std;

#define DIRECIONADO true
#define NAO_DIRECIONADO false

Grafo *ler_grafo(bool direc){
    int numVertices , numArestas , cont , edgOrigem , edgDestin;
    cout << "Entre com |V| e com |E|: ";
    cin >> numVertices >> numArestas;

    Grafo *graff = new Grafo(numVertices, direc);

    for (cont = 0; cont < numArestas ; cont++){
        cout << "Entre com a aresta " << cont+1 << ": ";
        cin >> edgOrigem >> edgDestin;
        graff->addAresta(edgOrigem,edgDestin);
    }
    return graff;
}

int main(){
    cout << "Hello World!" << endl << endl;

    Grafo *g = ler_grafo(DIRECIONADO);

    g->imprimeAdjMatrix();

    delete g;

}
