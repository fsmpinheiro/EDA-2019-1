#include <iostream>
#include "heap.h"


void swap1(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


MaxHeap::MaxHeap(int arraySize){
    heapSize = 0;
    length = arraySize;
    hArray = new int [arraySize];
    std::cout << "::> Array de inteiros alocado com sucesso! :D " << std::endl;
}

MaxHeap::~MaxHeap(){
    delete hArray;

}

void MaxHeap::maxHeapfy(int *nArray, int i){
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if (l <= heapSize && nArray[l] > nArray[r]){
        largest = l;
    }else{
        largest = i;

        if (r <= heapSize && nArray[r] > nArray[largest] ){
            largest = r;
        }
    }
    if (largest != i){
        swap1(&nArray[i], &nArray[largest]);
    }
    maxHeapfy(nArray, largest);
}

void MaxHeap::heapIncreaseKey(int *nArray, int i, int key){
    if(key < nArray[i]){
        std::cout << "erro: new key is menó que a key atual :S";
    }else{
        nArray[i] = key;
        while (i > 1 && nArray[parent(i)] < nArray[i]){
            swap1(&nArray[i], &nArray[parent(i)]);
            i = parent(i);
        }
    }

}

int MaxHeap::heapMaximum(){
    return hArray[1];
}

void MaxHeap::maxHeapInsert(int *nArray, int key){
    heapSize = heapSize + 1;
    nArray[heapSize] = (key - 1);
    heapIncreaseKey(nArray, heapSize, key);
}


int MaxHeap::parent(int i){
    return (i/2);
}
int MaxHeap::left(int i){
    return (2*i);
}
int MaxHeap::right(int i){
    return ((2*i)+1);
}
