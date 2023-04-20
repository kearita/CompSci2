/** Main
  * @file main.cpp
  * @author Keara Taylor Lopez
*/
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"

using namespace std;

/**
    Instantiates a linked list-based implementation of a queue with car data
    from an external file and repeatedly asks the user if they would like a
    car removed from the queue until user prompts to end search and removal
    @author Keara Taylor Lopez
    @date March 12, 2023
*/
int main() {
	LinkedQueue<string> theCars;
	LinkedQueue<string> copyQueue;

	string carData;
	string input;
	bool found = false;
	char userChoice;
	ifstream infile;

	do {
        //***Open file and check it is open***
		infile.open("carMake.csv");

		if(!infile.is_open()) {
			cout << "No file found..." << endl;
			exit(0);
		}

		getline(infile, carData); //advance past first line

		//***Build theCars and copy elements to copyQueue***
		while(getline(infile, carData)) {
			for(int i = 0; i < carData.length(); i++) {
				if(isupper(carData[i])) {
					carData[i] = (char)tolower(carData[i]);
				}
			}

			theCars.enqueue(carData);
		}

		copyQueue = theCars;

		//***Display theCars***
		cout << "The queue contains: " << endl;
		//COMMENT OUT THIS WHILE LOOP IF OUTPUT DOESNT WORK
            while (!theCars.isEmpty()) {
                cout << theCars.peek() << endl;
                theCars.dequeue();
            }
		//COMMENT OUT THIS WHILE LOOP IF OUTPUT DOESNT WORK


        //***Get user string and make case insensitive***
		cout << "Your input? ";
		cin >> input;
		cin.clear();

		for(int i = 0; i < input.length(); i++) {
			if(isupper(input[i])) {
				input[i] = (char)tolower(input[i]);
			}
		}//end for

        //***Search for user input and remove if instance of input in queue***
		while(!copyQueue.isEmpty()) {
			if(input.compare(copyQueue.peek()) == 0) {
				found = true;
				copyQueue.dequeue();
			}

			else {
				cout << copyQueue.peek() << endl;
				copyQueue.dequeue();
			}


		}//end while

		if(!found)
			cout << '\n' << input << " is not in this queue..." << endl;

		cout << "Remove another (Y/N)? ";
		cin >> userChoice;

		infile.close();

	}//*******END DO*******

	while(userChoice == 'Y');


	cout << "Program terminating..." << endl;


	return 0;
}
