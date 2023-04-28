#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include "Airport.h"
#include "Node.h"

using namespace std;

const int prime = 11;

class HashTable {

	public :
	    HashTable();
	    ~HashTable();

        int hashFunction(string key);
        void initializeTable(Node* []);
        void insertTable(Node* [], string str);
        void deleteTable(Node* []);
        int findInTable(Node* [], string str);
        void displayTable(Node* []);


    private :
        int numberOfBuckets = 40;

};


HashTable::HashTable() {
    numberOfBuckets = 100 ;
}

HashTable::~HashTable() {}


int hashFunction(string key) {
    int hash = 0;

    int index;
    //index = key.length(); //number of characters in string

    for (int i = 0; i < key.length(); i++) {
        hash += (int)key[i];
        //cout << "Hash = " << hash << endl;
    }

    //grabs ascii values that are stored in each letter of string
    //cout << "key[0] = " << (int)key[0] << endl; // = 80 etc
    //cout << "key[1] = " << (int)key[1] << endl;
    //cout << "key[2] = " << (int)key[2] << endl;

    //hash = 402, numberOfBuckets = 100; index = 2
    index = hash % prime;

    return index;
}


void initializeTable(Node* hashTable[]) {
    for (int i = 0; i < prime; i++)
        hashTable[i] = nullptr;
}

void insertTable(Node* hashTable[], string str) {
    int location;
    Node* nextPtr;
    Node* nodePtr;

    location = hashFunction(str); //location = index



    if (hashTable[location] == nullptr) {
        nodePtr = new Node();
        nodePtr->data = str;
        nodePtr->nextPtr = nullptr;
        hashTable[location] = nodePtr;
    }

    else {
        nextPtr = hashTable[location];
        nodePtr->data = str;
        nodePtr->nextPtr = hashTable[location];
        hashTable[location] = nodePtr;
    }




}







void deleteTable(Node* hashTable[]) {
    Node* currentPtr;
    Node* savedPtr;

    for (int i = 0; i < prime; i++) {
        currentPtr = hashTable[i];
        while (currentPtr != nullptr) {
            savedPtr = currentPtr->nextPtr;
            delete currentPtr;
            currentPtr = savedPtr;
        }
    }

    cout << "Hash table is empty" << endl;
}


int findInTable(Node* hashTable[], string str) {
    int location;
    Node* currentPtr;

    location = hashFunction(str);
    currentPtr = hashTable[location];

    if (currentPtr == nullptr)
        return -1;

    while (currentPtr != nullptr) {
        if (currentPtr->data == str)
            return location;
        else
            currentPtr = currentPtr->nextPtr;
    }

    return -1;

}



void displayTable(Node* hashTable[]) {
    int location;
    Node* currentPtr;

    for (location = 0; location < prime; location++) {
        cout << "Location " << location;
        currentPtr = hashTable[location];

        if (currentPtr == nullptr)
            cout << ": " << endl;
        else {
            cout << ": ";
            while (currentPtr != nullptr) {
                cout << currentPtr->data << " // ";
                currentPtr = currentPtr->nextPtr;
            }
            cout << endl;
        }
    }

    cout << "\n***End of hash table contents***" << endl;
}


/*
HashTable(int numberOfBuckets);

		HashTable (Airport a);

		HashTable();

		~HashTable();

		void insert(Airport a, string code);

		void erase(string code);

		int find(string code);

		void displayHashTable(vector<Airport> listOfVectors[]);

		int hashFunction(Airport a, string code);


	private:
	    Airport a;
	    int numberOfBuckets;
		vector<string> listOfVectors[36];
		string code;
*/



/*
HashTable::HashTable() {}

HashTable::HashTable(int numberOfBuckets) {
    this->numberOfBuckets = numberOfBuckets;
}

HashTable::~HashTable() {}

HashTable::HashTable(Airport a){
	this->code = a.getCode();
}


int HashTable::hashFunction(Airport a, string code){
	int length = code.length();
	int value = 0;


	//for (int i = 0; i < length; i++) {
        //value = (value + 255 * code.at(i)) % prime;
	//}


	value = length % prime; //bad hash function
	//cout << value; -- value is 3

	return value;
}


void HashTable::insert(Airport a, string code){
    code = a.getCode();
    int index = hashFunction(a, code);
	listOfVectors[index].push_back(code);
}


int HashTable::find(string code){
	bool found = false;
	int index = hashFunction(a, code);
	int queries = 0;
	for (Airport i : listOfVectors[index]) {
		queries++;
		if (a.getCode() == i.getCode())
			found = true;
	}

	return queries;

}


void displayHashTable(vector<Airport> listOfVectors[]) {
    for (int i = 0; i < 36; i++) {
        cout << "Elements at index " << i << ": ";
        for (auto element : listOfVectors[i])
            cout << element << " ";
        cout << endl;
    }
}

void HashTable::erase(string code){
	vector<string> &bucket = listOfVectors[hashFunction(a, code)];  //must be & so that the bucket can change
	vector<string>::iterator iter = bucket.begin();
	while (iter != bucket.end()){
		if (a == *iter){
			bucket.erase(iter);
			break;
		}
		iter++;
	}
}
*/

#endif // HASHTABLE_H
