#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
    Constructs a LinkedList with a null pointer for the head and the numberofElements set to 0
*/
LinkedList::LinkedList()
{
    head = nullptr;
    numElements = 0;
}

/**
    Allows a LinkedList to execute code at the time of its destruction
*/
LinkedList::~LinkedList()
{
    //dtor
}

/**
    Displays rows of data in sets of 10 integers
*/
void LinkedList::displayInRows() {
    Node *temp = head;
    while (temp != nullptr) {
        for (int rowCounter = 0; rowCounter < 10; rowCounter++) {
            cout << temp->getValue() << " ";
            temp = temp->next;
        }//end for
    cout << '\n';
    }//end while
}//end displayInRows()



//Failed to make insertInOrder work

//*****************Second attempt attempt at insertInOrder*************

/**
    Uses external file data to sort data in chronological order
    @param n the integer to be sorted chronologically
*/
/*
void LinkedList::insertInOrder(int n) {
Node *node = new Node();
node->setValue(n);
//head = node;
Node *temp = node;
Node *prev; //=node; = head;



while (temp != nullptr) {

    //Condition #1- empty list
    if (head == nullptr) {
        head = node;
    }//end if

    //Condition #2 - new node smaller than head
    if (node->getValue() < head->getValue()) {
        //head = node;
        //head->next = prev;
        temp->next = head;
        head = node;
        prev = node;

    }//end if
    else if (node->getValue() > head->getValue()) {

        //temp = node;
        prev = prev->next;
        prev->next = temp;

    }//end else


    //Condition #3 - new node value in between prev and temp
    if ((node->getValue() > prev->getValue()) && (node->getValue() < temp->getValue())) {
        prev->next = node;
        temp->next = prev->next;
    }//end if

    //Condition #4 - temp->next is nullptr so put new node at tail
   if (temp->next == nullptr) {
       prev->next = node;
       temp = temp->next;
   }//end if

    //temp=temp->next;

}//end while


}//end insertInOrder()
*/

//*****First attempt to make insertInOrder work*******

/*
void LinkedList::insertInOrder(int n) {

    Node* node = new Node();
    node->setValue(n);

    if (head == nullptr || head->getValue() >= n) {
        (node->next)->setValue(head->next->getValue());
        head = node;
    }//end if
    else {
        Node* current = head;
        while (current->next != nullptr && (current->next)->getValue() < n) {
            current = current->next;
        }//end while
        node->next->setValue(current->next->getValue());
        current->setValue(node->getValue());
    }//end else
}//end insertInOrder
*/


/**
    Displays data from the beginning of the list until n
    @param n the last data point to get displayed
*/
void LinkedList::displayFromFrontToN(int n) {
    Node *temp;
    temp = head;
    int index, indexOfN;

    bool found = false;

    while (temp != nullptr && temp) {
        cout << temp->getValue() << endl;
        index++;
        temp = temp->next;
        if (temp->getValue() == n) {
            found = true;
            indexOfN = index;
            cout << temp->getValue() << endl;
            break;
        }//end if
    }//end while

}//end displayFromFrontToN()


/**
    Displays from user-provided n to the end of the list
    @param n the first integer that gets displayed until the end of the list
*/
void LinkedList::displayFromNToEnd(int n) {
   Node *temp;
   temp = head;
   int index, indexOfN;

   bool found = false;


   while (temp != nullptr) {
        if (temp->getValue() == n) {
            found = true;
            indexOfN = index;
            while (temp!= nullptr) {
                cout << temp->getValue() << endl;
                temp = temp->next;
            }//end inner while
        }//end if
        index++;
        temp = temp->next;
   }//end while


}//end displayFromNToEnd()


/**
    Counts the frequency in which an int appears in the linked list
    @param item the data item that gets counted for the number of times it appears
    @return count the number of times the item appears in the list
*/
int LinkedList::countFrequencyOf(int item) {
    int count = 0;
    Node *temp;
    temp = head;

    while (temp != nullptr) {
        if (temp->getValue() == item)
            count++;
        temp = temp->next;
    }//end while

    return count;

}//end countFrequencyOf()


/**
    Searches the list for the appearance of a data item in the linked list
    @param item the item to be searched for
    @return found is true if item is found at least once
*/
bool LinkedList::searchVal(int item) {
    bool found = false;

    Node *temp;
    temp = head;

    while (temp != nullptr) {
         if (temp->getValue() == item)
            found = true;
         temp = temp->next;
    }//end while


    return found;

}//end searchVal()

/**
    Displays the linked list
*/
void LinkedList::printList() {
    Node *temp;

    temp = head;

    while (temp != nullptr) {
        cout << temp->getValue() << endl;
        temp = temp->next;
    }//end while

}//end printList()

/**
    Takes in data from an external file and builds a linked list
*/
void LinkedList::fillListFromFile() {
    ifstream infile;
    string line;
    int num;

    infile.open("linkedListData1.txt");

    if(!infile.is_open()) {
        cout << "no file found..." << endl;
        exit(0);
    }//end if


     Node *n = new Node();
     Node *temp;
     temp = n;
     head = n;


     getline(infile, line);
        num = stoi(line);

        //****not working******
        //insertInOrder(num);

        n->setValue(num);
        numElements++;



        while (!infile.eof() && infile.good()) {
        n = new Node();
        getline(infile, line);
        num = stoi(line);

        //****not working******
        //insertInOrder(num);

        n->setValue(num);
        temp->next = n;
        temp = temp->next;

        numElements++;
        }//end while

    //infile.close();

}//end fillListFromFile()

/**
    Returns the size of the linked list
    @return numElements the number of elements in the linked list
*/
int LinkedList::getSize() {
    return numElements;
}//end getSize()
