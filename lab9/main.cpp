#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

//void fillTheVectors(HashTable theAirports);
//const int prime = 40;

using namespace std;

int main()
{
    ifstream infile;
    string line;
    string code;
    infile.open("us-airports-1 (1).csv");


    if(!infile){
        cout << "file not found"<< endl;
        exit(0);
   }

    getline(infile, line); //advance past first line

    Node* hashTable[prime];
    initializeTable(hashTable);


    getline(infile, line);
    Airport a(line);
    code = a.getCode();
    insertTable(hashTable, code);


    displayTable(hashTable);



    return 0;
}


/*
void fillTheVectors(HashTable theAirports) {
    vector<Airport> listOfVectors[36];
   ifstream infile;
   infile.open("us-airports-1 (1).csv");
   string line;

   if(!infile){
      cout << "file not found"<< endl;
      exit(0);
   }

   getline(infile, line); //advance past first line

    getline(infile, line);

    Airport a(line);

    string code = a.getCode();

    //cout << sizeof(code) << endl; -- 32 bits

    //cout << code << endl;

    theAirports.insert(a, code);

    //theAirports.displayHashTable(listOfVectors[]);



   }
   */


