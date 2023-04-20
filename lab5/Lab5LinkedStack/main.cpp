/** Main
  * @file main.cpp
  * @author Keara Taylor Lopez
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "LinkedStack.h"

using namespace std;

/**
    Instantiates a linked list-based implementation with candy data from an external
    file and outputs the candy with the highest calorie count
    @author Keara Taylor Lopez
    @date March 7, 2023
*/
int main() {
	LinkedStack<string>theCandies;

	ifstream infile;
	string line, candyName;
	string temp = "";
	int calorie, highestCalorie, numHighestCalCandy;
	infile.open("halloweenCandy.csv");

	if(!infile.is_open()) {
		cout << "no file found..." << endl;
		exit(0);
	}//end if


	getline(infile, line);
	stringstream firstss(line);
	getline(firstss, candyName, ',');

	getline(firstss, temp);
	highestCalorie = stoi(temp);
	numHighestCalCandy = 1;
	theCandies.push(candyName);
	string highestCandyName = theCandies.peek();
	theCandies.pop();
	string thirdHighestCandy;
	string secondHighestCandy;


	while(getline(infile, line)) {
		stringstream ss(line);
		getline(ss, candyName, ',');
		getline(ss, temp);
		calorie = stoi(temp);

		if(calorie > highestCalorie) {
			highestCalorie = calorie;
			theCandies.push(candyName);
		}

		if(calorie == highestCalorie) {
			numHighestCalCandy++;
			theCandies.push(candyName);
		}
	}//end while

	thirdHighestCandy = theCandies.peek();
	theCandies.pop();
	secondHighestCandy = theCandies.peek();


	cout << "\nHighest calorie count: " << highestCalorie << endl;
	cout << "Candy with " << highestCalorie << " calories per serving: ";
	cout << highestCandyName << ", " << secondHighestCandy << ", " << thirdHighestCandy << endl;



	return 0;
}
