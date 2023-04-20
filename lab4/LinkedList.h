#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        bool searchVal(int);
        int countFrequencyOf(int);
        int getSize();
        void displayFromFrontToN(int);
        void displayFromNToEnd(int);
        void insertInOrder(int);
        void fillListFromFile();
        void displayInRows();
        void printList();
        void insertAtHead(int);


    private:
        Node *head;
        int numElements;
};

#endif // LINKEDLIST_H
