#ifndef HEAP_H
#define HEAP_H

//#define parent(i) {i/2}
//#define left(i) {2*i}
//#define right(i) {(2*i)+1}
//#define swap( x, y ) {typeof(x) temp = x; x = y; y = temp;}

//void swap(int *x, int *y ) {
//}

class MaxHeap{
    int *hArray;     //Ponteiro para array de inteiros
    int length;     //Capacidade total do vetor
    int heapSize;   //Tamanho atual do heap

public:
    MaxHeap(int arraySize);     //construtor

    ~MaxHeap();     //destrutor

    void buildMaxHeap();      //construir um heap em tempo Linear

    int heapMaximum();      //Feita - retorna a chave máxima do Heap

    int heapExtracMax();    //remove e retorna o máximo do Heap

    void maxHeapfy(int *nArray, int i);      //Feita - faz o elemento de índice 'i' descer na árvore até encontrar sua posição correta

    void heapIncreaseKey(int *nArray, int i, int key);   //Feita - incrementa o valor do elemento no índice 'i' para o valor contido em 'key'

    void maxHeapInsert(int *nArray, int key);            //Feita - insere o valor de 'key' no heap, mantendo o propriedade de heap máximo

    bool isEmpty();                         //retorna 'True' se o heap estiver vazio

    int parent(int i);
    int left (int i);
    int right (int i);

};

#endif // HEAP_H
