#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "PriorityQueueInterface.h"
#include <iostream>

using namespace std;

template <typename T>
class MaxHeap : public PriorityQueueInterface<T>
{
    public:
        MaxHeap();
        ~MaxHeap();

        bool isEmpty() const;
        int getNumberOfNodes() const;
        T peek() const;
        bool add(const T& newData);
        bool remove();
        void clear();

        void displayHeap();


    private:
        static const int CAPACITY = 5000;
        int itemCount = 0;
        void percolateDown(int currentNode);

        int getParent(int currentNode) const;
        int getRightChild(int currentNode) const;
        int getLeftChild(int currentNode) const;
        bool isLeaf(int currentNode) const;

        T *heapArray;
};

template <typename T>
MaxHeap<T>::MaxHeap() {
    itemCount = 0;
    heapArray = new T[CAPACITY];
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete [] heapArray;
}


template <typename T>
bool MaxHeap<T>::isEmpty() const {
    return (itemCount == 0);
}

template <typename T>
int MaxHeap<T>::getNumberOfNodes() const {
    return itemCount;
}

template <typename T>
void MaxHeap<T>::clear() {
    itemCount = 0;
}

template <typename T>
void MaxHeap<T>::displayHeap() {
    for (int i = 0; i < itemCount; i++)
        cout << heapArray[i] << endl;
}

template <typename T>
T MaxHeap<T>::peek() const {
    if (isEmpty()) {
        cout << "Empty heap..." << endl;
    }
    return heapArray[0];
}

template <typename T>
int MaxHeap<T>::getParent(int currentNode) const {
    return (currentNode - 1) / 2;
}

template <typename T>
int MaxHeap<T>::getLeftChild(int currentNode) const {
    return currentNode * 2 + 1;
}

template <typename T>
int MaxHeap<T>::getRightChild(int currentNode) const {
    return currentNode * 2 + 2;
}

template <typename T>
bool MaxHeap<T>::isLeaf(int currentNode) const {
    return (getLeftChild(currentNode) >= itemCount);
}

template <typename T>
bool MaxHeap<T>::add(const T& newData) {
    if (itemCount >= CAPACITY) {
        cout << "Heap full" << endl;
        return false;
    }

    heapArray[itemCount] = newData;

    int currentPosition = itemCount;
    bool inPlace = false;

    //percolate up
    while (currentPosition > 0 && !inPlace) {
        int parent = getParent(currentPosition);
        //cout << "this is parent" << parent << endl;
        if (heapArray[currentPosition] < heapArray[parent])
            inPlace = true;
        else {
            swap(heapArray[currentPosition], heapArray[parent]);
            //cout << "swapping " << heapArray[currentPosition] << " and " << heapArray[parent] << endl;
            currentPosition = parent;
        }
    }//end while

    itemCount++;
    return true;
}

template <typename T>
void MaxHeap<T>::percolateDown(int currentNode) {
    if (!isLeaf(currentNode)) {
        int leftChild = getLeftChild(currentNode);
        int maxChild = leftChild;
        int rightChild = getRightChild(currentNode);

        if (rightChild < itemCount) {
            if(heapArray[rightChild] > heapArray[leftChild])
            maxChild = rightChild;
        }

        if (heapArray[currentNode] < heapArray[maxChild]) {
            swap(heapArray[currentNode], heapArray[maxChild]);
            percolateDown(maxChild);
        }
    }
}

template <typename T>
bool MaxHeap<T>::remove() {
    if (isEmpty()) {
        cout << "Empty heap" << endl;
        return false;
    }
    else {
        itemCount--;
        heapArray[0] = heapArray[itemCount];
        percolateDown(0);
    }
    return true;
}


#endif // MAXHEAP_H
