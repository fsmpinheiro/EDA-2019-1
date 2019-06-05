#ifndef GRAFO_H
#define GRAFO_H



class Grafo{
private:
    int **adjMat;       //a matriz de adjacências
    int vOrder;         //a ordem da matriz -- |V(G)|
    bool direcionado;   //boleano que diz se o grafo é direcionado ou não

public:
    Grafo(int n, bool direc);

    ~Grafo();

    void addAresta(int orig, int dest);
    void removeAresta(int orig, int dest);

    bool temAresta(int orig, int dest);

    void imprimeVizinhos(int u);
    void imprimeAdjMatrix();

    int grau(int v);
    //o grau de um vértice v, representado por d(v), é o número
    //de arestas que incidem nele (loops são contados duas vezes)

    //int maisPopular(Grafo &graff);
    int ordem();
};

#endif // GRAFO_H
