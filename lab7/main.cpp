/** Main
  * @file main.cpp
  * @author Keara Taylor Lopez
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Airport.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "SearchByCodeFinder.h"
#include "SearchByStateFinder.h"
#include "SearchByPassengersFinder.h"
#include "ListAvgPassengersFinder.h"
#include "ListAvgFlightsFinder.h"
#include "MaxNumPassengersFinder.h"
#include "MaxNumFlightsFinder.h"
#include "MaxFreightFinder.h"
#include "MinNumPassengersFinder.h"
#include "MinNumFlightsFinder.h"
#include "MinFreightFinder.h"
#include "EditNumPassengersFinder.h"
#include "EditFreightFinder.h"
#include "EditNumFlightsFinder.h"

using namespace std;

//----------prototypes----------
vector<Airport> readFile();
BinarySearchTree<Airport>* buildTree(vector<Airport> airportVector);
void mainMenu(BinarySearchTree<Airport> &theAirports);
void searchMenu(BinarySearchTree<Airport> &theAirports);
void generateReportsMenu(BinarySearchTree<Airport> &theAirports);
void maxMinsMenu(BinarySearchTree<Airport> &theAirports);
void editAirportMenu(BinarySearchTree<Airport> &theAirports);
void searchByCode(BinarySearchTree<Airport> &theAirports);
void searchByState(BinarySearchTree<Airport> &theAirports);
void searchByPassengers(BinarySearchTree<Airport> &theAirports);
void listAllAirports(BinarySearchTree<Airport> &theAirports);
void listAveragePassengers(BinarySearchTree<Airport> &theAirports);
void listAverageFlights(BinarySearchTree<Airport> &theAirports);
void maxNumPassengers(BinarySearchTree<Airport> &theAirports);
void maxNumFlights(BinarySearchTree<Airport> &theAirports);
void maxFreight(BinarySearchTree<Airport> &theAirports);
void minNumPassengers(BinarySearchTree<Airport> &theAirports);
void minNumFlights(BinarySearchTree<Airport> &theAirports);
void minFreight(BinarySearchTree<Airport> &theAirports);
void editNumPassengers(BinarySearchTree<Airport> &theAirports);
void editFreight(BinarySearchTree<Airport> &theAirports);
void editNumFlights(BinarySearchTree<Airport> &theAirports);


/**
    A system of menus that allows a user to display, edit or search for data about Airports
    in a Binary Search Tree. Application closes once user requests to quit.
    @author Keara Taylor Lopez
    @date April 11, 2023
*/
int main() {
	vector<Airport> airports = readFile();
	BinarySearchTree<Airport>* theAirports = new BinarySearchTree<Airport>();
	theAirports = buildTree(airports);

	mainMenu(*theAirports);


	return 0;
}


/**
    Prompts the user to enter an Airport by code and a freight value in order
    to edit original freight data for this Airport
    @param theAirports the Airport to be edited
*/
void editFreight(BinarySearchTree<Airport> &theAirports) {
	string userCode;
	string userNum;
	int found = false;

	cout << "Enter an airport code: ";
	getline(cin, userCode);

	EditFreightFinder editFreight(userCode);
	theAirports.inOrderVisit(editFreight);
	vector<Airport> results = editFreight.getEditFreight();

	if(results.empty())
		cout << "There is no airport with code " << userCode << "." << endl;
	else {
		cout << "Enter a number to change the freight at this airport: ";
		getline(cin, userNum);
		found = userNum.find('.');

		while(isalpha(userNum[0]) || (found != string::npos) || stol(userNum) < 0) {
			cout << "Please re-enter a positive integer to edit freight: ";
			getline(cin, userNum);
			found = userNum.find('.');
		}

		for(Airport a : results) {
			cout << "\nOriginal freight: " << endl;
			cout << a << endl;
		}
	}//end else

	for(Airport a : results) {
		cout << "New freight: " << endl;
		a.setFreight(stol(userNum));
		cout << a << endl;
	}

	cout << '\n';
}


/**
    Prompts the user to enter an Airport by code and a number of flights value in order
    to edit original number of flights data for this Airport
    @param theAirports the Airport to be edited
*/
void editNumFlights(BinarySearchTree<Airport> &theAirports) {
	string userCode;
	string userNum;
	int found = false;

	cout << "Enter an airport code: ";
	getline(cin, userCode);

	EditNumFlightsFinder editFlights(userCode);
	theAirports.inOrderVisit(editFlights);
	vector<Airport> results = editFlights.getEditNumFlights();

	if(results.empty())
		cout << "There is no airport with code " << userCode << "." << endl;
	else {
		cout << "Enter a number to change the number of flights at this airport: ";
		getline(cin, userNum);
		found = userNum.find('.');

		while(isalpha(userNum[0]) || (found != string::npos) || stol(userNum) < 0) {
			cout << "Please re-enter a positive integer to edit number of flights: ";
			getline(cin, userNum);
			found = userNum.find('.');
		}

		for(Airport a : results) {
			cout << "\nOriginal number of flights: " << endl;
			cout << a << endl;
		}
	}//end else

	for(Airport a : results) {
		cout << "New number of flights: " << endl;
		a.setNumFlights(stol(userNum));
		cout << a << endl;
	}

	cout << '\n';
}


/**
    Prompts the user to enter an Airport by code and a number of passengers value in order
    to edit original number of passengers data for this Airport
    @param theAirports the Airport to be edited
*/
void editNumPassengers(BinarySearchTree<Airport> &theAirports) {
	string userCode;
	string userNum;
	int found = false;

	cout << "Enter an airport code: ";
	getline(cin, userCode);

	EditNumPassengersFinder editPassengers(userCode);
	theAirports.inOrderVisit(editPassengers);
	vector<Airport> results = editPassengers.getEditNumPassengers();

	if(results.empty())
		cout << "There is no airport with code " << userCode << "." << endl;
	else {
		cout << "Enter a number to change the number of passengers at this airport: ";
		getline(cin, userNum);
		found = userNum.find('.');

		while(isalpha(userNum[0]) || (found != string::npos) || stol(userNum) < 0) {
			cout << "Please re-enter a positive integer to edit number of passengers: ";
			getline(cin, userNum);
			found = userNum.find('.');
		}

		for(Airport a : results) {
			cout << "\nOriginal number of passengers: " << endl;
			cout << a << endl;
		}
	}//end else

	for(Airport a : results) {
		cout << "New number of passengers: " << endl;
		a.setNumPassengers(stol(userNum));
		cout << a << endl;
	}

	cout << '\n';
}


/**
    Allows user to display the Airport with the lowest freight value
    @param theAirports the Airport object found to have the lowest freight
*/
void minFreight(BinarySearchTree<Airport> &theAirports) {
	long minFreight = 80000000;

	MinFreightFinder findMinFreight;
	theAirports.inOrderVisit(findMinFreight);
	vector<Airport> results = findMinFreight.getMinFreight();

	cout << "Airport with the smallest freight: " << endl;

	for(Airport a : results) {
		if(a.getFreight() < minFreight)
			minFreight = a.getFreight();
	}

	for(Airport a : results) {
		if(a.getFreight() == minFreight) {
			cout << a.getName() << ", ";
			cout << a.getCode() << ", ";
			cout << minFreight << endl;
		}
	}

	cout << '\n';
}


/**
    Allows user to display the Airport with the lowest number of flights
    @param theAirports the Airport object found to have the lowest number of flights
*/
void minNumFlights(BinarySearchTree<Airport> &theAirports) {
	long minFlights = 1000000;

	MinNumFlightsFinder findMinFlights;
	theAirports.inOrderVisit(findMinFlights);
	vector<Airport> results = findMinFlights.getMinNumFlights();

	cout << "Airport with the lowest number of flights: " << endl;

	for(Airport a : results) {
		if(a.getNumFlights() < minFlights)
			minFlights = a.getNumFlights();
	}

	for(Airport a : results) {
		if(a.getNumFlights() == minFlights) {
			cout << a.getName() << ", ";
			cout << a.getCode() << ", ";
			cout << minFlights << endl;
		}
	}

	cout << '\n';
}


/**
    Allows user to display the Airport with the lowest number of passengers
    @param theAirports the Airport object found to have the lowest number of passengers
*/
void minNumPassengers(BinarySearchTree<Airport> &theAirports) {
	long minPassengers = 70000000;

	MinNumPassengersFinder findMinPassengers;
	theAirports.inOrderVisit(findMinPassengers);
	vector<Airport> results = findMinPassengers.getMinNumPassengers();

	cout << "Airport with the lowest number of passengers: " << endl;

	for(Airport a : results) {
		if(a.getNumPassengers() < minPassengers)
			minPassengers = a.getNumPassengers();
	}

	for(Airport a : results) {
		if(a.getNumPassengers() == minPassengers) {
			cout << a.getName() << ", ";
			cout << a.getCode() << ", ";
			cout << minPassengers << endl;
		}
	}

	cout << '\n';
}


/**
    Allows user to display the Airport with the highest freight value
    @param theAirports the Airport object found to have the highest freight
*/
void maxFreight(BinarySearchTree<Airport> &theAirports) {
	long maxFreight = 0;

	MaxFreightFinder findMaxFreight;
	theAirports.inOrderVisit(findMaxFreight);
	vector<Airport> results = findMaxFreight.getMaxFreight();

	cout << "Airport with the largest freight: " << endl;

	for(Airport a : results) {
		if(a.getFreight() > maxFreight)
			maxFreight = a.getFreight();
	}

	for(Airport a : results) {
		if(a.getFreight() == maxFreight) {
			cout << a.getName() << ", ";
			cout << a.getCode() << ", ";
			cout << maxFreight << endl;
		}
	}

	cout << '\n';
}


/**
    Allows user to display the Airport with the highest number of flights
    @param theAirports the Airport object found to have the highest number of flights
*/
void maxNumFlights(BinarySearchTree<Airport> &theAirports) {
	long maxFlights = 0;

	MaxNumFlightsFinder findMaxFlights;
	theAirports.inOrderVisit(findMaxFlights);
	vector<Airport> results = findMaxFlights.getMaxNumFlights();

	cout << "Airport with the highest number of flights: " << endl;

	for(Airport a : results) {
		if(a.getNumFlights() > maxFlights)
			maxFlights = a.getNumFlights();
	}

	for(Airport a : results) {
		if(a.getNumFlights() == maxFlights) {
			cout << a.getName() << ", ";
			cout << a.getCode() << ", ";
			cout << maxFlights << endl;
		}
	}

	cout << '\n';
}


/**
    Allows user to display the Airport with the highest number of passengers
    @param theAirports the Airport object found to have the highest number of passengers
*/
void maxNumPassengers(BinarySearchTree<Airport> &theAirports) {
	long maxPassengers = 0;

	MaxNumPassengersFinder findMaxPassengers;
	theAirports.inOrderVisit(findMaxPassengers);
	vector<Airport> results = findMaxPassengers.getMaxNumPassengers();

	cout << "Airport with the highest number of passengers: " << endl;

	for(Airport a : results) {
		if(a.getNumPassengers() > maxPassengers)
			maxPassengers = a.getNumPassengers();
	}

	for(Airport a : results) {
		if(a.getNumPassengers() == maxPassengers) {
			cout << a.getName() << ", ";
			cout << a.getCode() << ", ";
			cout << maxPassengers << endl;
		}
	}

	cout << '\n';
}


/**
    Displays all Airports and their average number of flights per day
    @param theAirports the Airports to be displayed
*/
void listAverageFlights(BinarySearchTree<Airport> &theAirports) {
	ListAvgFlightsFinder listAvgFlights;
	theAirports.inOrderVisit(listAvgFlights);
	vector<Airport> results = listAvgFlights.getAvgFlights();

	cout << "All airports listed with the average number of flights per day: \n" << endl;

	for(Airport i : results) {
		cout << i.getName() << ", ";
		cout << i.getCity() << ", ";
		cout << i.getState() << ", ";
		cout << i.getCode() << endl;
		cout << "Average number of flights per day: " << i.getNumFlights() / 365 << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
	}

	cout << '\n';
}


/**
    Displays all Airports and their average number of passengers per day
    @param theAirports the Airports to be displayed
*/
void listAveragePassengers(BinarySearchTree<Airport> &theAirports) {
	ListAvgPassengersFinder listAvgPassengers;
	theAirports.inOrderVisit(listAvgPassengers);
	vector<Airport> results = listAvgPassengers.getAvgPassengers();

	cout << "All airports listed with the average number of passengers per day: \n" << endl;

	for(Airport i : results) {
		cout << i.getName() << ", ";
		cout << i.getCity() << ", ";
		cout << i.getState() << ", ";
		cout << i.getCode() << endl;
		cout << "Average number of passengers per day: " << i.getNumPassengers() / 365 << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
	}

	cout << '\n';
}


/**
    Displays all Airports
    @param theAirports the Airports to be displayed
*/
void listAllAirports(BinarySearchTree<Airport> &theAirports) {
	cout << "Here is a list of all airports: \n" << endl;
	theAirports.preOrderTraverse();
}


/**
    Allows a user to enter a minimum number of passengers and displays all
    Airports with more than inputted number of passengers
    @param theAirports the Airports found with a greater number of passengers
*/
void searchByPassengers(BinarySearchTree<Airport> &theAirports) {
	string minNumPassengers;
	cout << "Enter a minimum number of passengers: ";
	getline(cin, minNumPassengers);

	SearchByPassengersFinder searchPassengers(stol(minNumPassengers));
	theAirports.inOrderVisit(searchPassengers);
	vector<Airport> results = searchPassengers.getMinNumPassengers();

	if(results.empty())
		cout << "There are no airports with " << minNumPassengers << " passengers." << endl;
	else {
		cout << "\nThe airports with a greater number of passengers than ";
		cout << minNumPassengers << ": \n" << endl;

		for(Airport i : results)
			cout << i << endl;
	}

	cout << '\n';
}


/**
    Allows a user to enter a state and displays all Airports located in inputted state
    @param theAirports the Airports found located in inputted state
*/
void searchByState(BinarySearchTree<Airport> &theAirports) {
	string userState;
	cout << "Enter a state to search for an airport: ";
	getline(cin, userState);

	SearchByStateFinder searchState(userState);
	theAirports.inOrderVisit(searchState);
	vector<Airport> results = searchState.getAirportState();

	if(results.empty())
		cout << "There are no airports in " << userState << "." << endl;
	else {
		cout << "\nAirport(s) in " << userState << ": \n" << endl;

		for(Airport i : results) {
			cout << i.getName() << ", " << i.getCity() << ", " << i.getCode() << endl;
			cout << '\n';
		}

	}

	cout << '\n';
}


/**
    Allows a user to enter a airport code and displays the Airport associated
    with inputted airport code
    @param theAirports the Airport with inputted airport code
*/
void searchByCode(BinarySearchTree<Airport> &theAirports) {
	string userCode;
	cout << "Enter an airport code: ";
	getline(cin, userCode);

	SearchByCodeFinder searchCode(userCode);
	theAirports.inOrderVisit(searchCode);
	vector<Airport> results = searchCode.getAirportCode();

	if(results.empty())
		cout << "There are no airports with this code." << endl;
	else {
		cout << "\nAirport with code " << userCode << ": " << endl;

		for(Airport i : results) {
			cout << "\nAirport name: " << i.getName() << endl;
			cout << "City: " << i.getCity() << endl;
			cout << "State: " << i.getState() << endl;
			cout << "Airport code: " << i.getCode() << endl;
			cout << "Number of passengers: " << i.getNumPassengers() << endl;
			cout << "Number of flights: " << i.getNumFlights() << endl;
			cout << "Freight: " << i.getFreight() << endl;
			cout << "---------------------------------------------------------------------------" << endl;

		}
	}//end else

	cout << '\n';
}


/**
    Builds the binary search tree of Airports using airport data from airport vector
    @param airportVector the vector that contains all airport data
    @return the binary search tree of made of Airports
*/
BinarySearchTree<Airport>* buildTree(vector<Airport> airportVector) {
	BinarySearchTree<Airport>* theAirports;

	int size = airportVector.size();

	for(int i = 0; i < size; i++) {
		theAirports->add(airportVector[i]);
	}

	return theAirports;
}


/**
    Opens and reads the external file that contains airport data
    @return the Airport vector to be added to the binary search tree
*/
vector<Airport> readFile() {
	vector<Airport> airportVector;
	ifstream infile;
	string line;

	infile.open("us-airports-1.csv");

	if(!infile.is_open()) {
		cout << "No file found..." << endl;
		exit(0);
	}

	getline(infile, line); //advanced past first line

	while(getline(infile, line)) {
		Airport a(line);
		airportVector.push_back(a);
	}//end while


	return airportVector;

}


/**
    Opens at the start of the program and allows user to choose a
    submenu or quit application
    @param theAirports the Airports and their data to be utilized
*/
void mainMenu(BinarySearchTree<Airport> &theAirports) {
	cout << "MAIN MENU" << endl;
	cout << "1. Search Menu" << endl;
	cout << "2. Generate reports Menu" << endl;
	cout << "3. Maximums and minimums Menu" << endl;
	cout << "4. Edit Airport Menu" << endl;
	cout << "5. Quit" << endl;
	cout << "\nWhich menu would you like to open? ";

	string choice;
	int found = false;
	getline(cin, choice);
	found = choice.find('.');
	cout << '\n';

	while(isalpha(choice[0]) || (found != string::npos) || stoi(choice) != 1 &&
	        stoi(choice) != 2 && stoi(choice) != 3 && stoi(choice) != 4 && stoi(choice) != 5) {
		cout << "Please re-enter an integer between 1 - 5 to select an option: ";
		getline(cin, choice);
		found = choice.find('.');
	}

	if(stoi(choice) == 1)
		searchMenu(theAirports);

	if(stoi(choice) == 2)
		generateReportsMenu(theAirports);

	if(stoi(choice) == 3)
		maxMinsMenu(theAirports);

	if(stoi(choice) == 4)
		editAirportMenu(theAirports);

	if(stoi(choice) == 5)
		exit(0);

}


/**
    Opens the Search submenu and allows user to choose an option to search for an Airport
    @param theAirports the Airports and their data to be searched
*/
void searchMenu(BinarySearchTree<Airport> &theAirports) {
	string choice;
	int found = false;

	cout << "\nSEARCH MENU" << endl;
	cout << "1. Search by airport code" << endl;
	cout << "2. Search by state" << endl;
	cout << "3. Search by minimum number of passengers" << endl;
	cout << "4. Return to main menu" << endl;

	cout << "\nEnter a number to choose an option: ";
	getline(cin, choice);
	found = choice.find('.');
	cout << '\n';

	while(isalpha(choice[0]) || (found != string::npos) || stoi(choice) != 1 &&
	        stoi(choice) != 2 && stoi(choice) != 3 && stoi(choice) != 4) {
		cout << "Please re-enter an integer between 1 - 4 to select an option: ";
		getline(cin, choice);
		found = choice.find('.');
	}

	if(stoi(choice) == 1) {
		searchByCode(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 2) {
		searchByState(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 3) {
		searchByPassengers(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 4)
		mainMenu(theAirports);

}


/**
    Opens the Generate reports submenu and allows user to choose an option to display Airports
    @param theAirports the Airports with their data to be displayed
*/
void generateReportsMenu(BinarySearchTree<Airport> &theAirports) {
	string choice;
	int found = false;

	cout << "\nGENERATE REPORTS MENU" << endl;
	cout << "1. List all airports" << endl;
	cout << "2. List all airports & average number of passengers per day" << endl;
	cout << "3. List all airports & average number of flights per day" << endl;
	cout << "4. List all airports with a post-order traversal" << endl;
	cout << "5. Return to main menu" << endl;

	cout << "\nEnter a number to choose an option: ";
	getline(cin, choice);
	found = choice.find('.');
	cout << '\n';

	while(isalpha(choice[0]) || (found != string::npos) || stoi(choice) != 1 &&
	        stoi(choice) != 2 && stoi(choice) != 3 && stoi(choice) != 4 && stoi(choice) != 5) {
		cout << "Please re-enter an integer between 1 - 5 to select an option: ";
		getline(cin, choice);
		found = choice.find('.');
	}

	if(stoi(choice) == 1) {
		listAllAirports(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 2) {
		listAveragePassengers(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 3) {
		listAverageFlights(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 4) {
		theAirports.postOrderTraverse();
		mainMenu(theAirports);
	}

	if(stoi(choice) == 5)
		mainMenu(theAirports);

}


/**
    Opens the Maximums and minimums submenu and allows user to choose an option to display Airport data
    @param theAirports the Airports to be displayed
*/
void maxMinsMenu(BinarySearchTree<Airport> &theAirports) {
	string choice;
	int found = false;

	cout << "\nMAXIMUMS AND MINIMUMS MENU" << endl;
	cout << "1. Display airport with maximum number of passengers" << endl;
	cout << "2. Display airport with maximum freight" << endl;
	cout << "3. Display airport with maximum number of flights" << endl;
	cout << "4. Display airport with minimum number of passengers" << endl;
	cout << "5. Display airport with minimum freight" << endl;
	cout << "6. Display airport with minimum number of flights" << endl;
	cout << "7. Return to main menu" << endl;

	cout << "\nEnter a number to choose an option: ";
	getline(cin, choice);
	found = choice.find('.');
	cout << '\n';

	while(isalpha(choice[0]) || (found != string::npos) || stoi(choice) != 1 &&
	        stoi(choice) != 2 && stoi(choice) != 3 && stoi(choice) != 4 &&
	        stoi(choice) != 5 && stoi(choice) != 6 && stoi(choice) != 7) {
		cout << "Please re-enter an integer between 1 - 7 to select an option: ";
		getline(cin, choice);
		found = choice.find('.');
	}

	if(stoi(choice) == 1) {
		maxNumPassengers(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 2) {
		maxFreight(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 3) {
		maxNumFlights(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 4) {
		minNumPassengers(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 5) {
		minFreight(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 6) {
		minNumFlights(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 7)
		mainMenu(theAirports);

}


/**
    Opens the Edit Airport submenu and allows user to choose an option to edit an Airport
    @param theAirports the Airport to be edited
*/
void editAirportMenu(BinarySearchTree<Airport> &theAirports) {
	string choice;
	int found = false;

	cout << "\nEDIT AIRPORT MENU" << endl;
	cout << "1. Edit number of passengers" << endl;
	cout << "2. Edit amount of freight" << endl;
	cout << "3. Edit number of flights" << endl;
	cout << "4. Return to main menu" << endl;

	cout << "\nEnter a number to choose an option: ";
	getline(cin, choice);
	found = choice.find('.');
	cout << '\n';

	while(isalpha(choice[0]) || (found != string::npos) || stoi(choice) != 1 &&
	        stoi(choice) != 2 && stoi(choice) != 3 && stoi(choice) != 4) {
		cout << "Please re-enter an integer between 1 - 4 to select an option: ";
		getline(cin, choice);
		found = choice.find('.');
	}

	if(stoi(choice) == 1) {
		editNumPassengers(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 2) {
		editFreight(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 3) {
		editNumFlights(theAirports);
		mainMenu(theAirports);
	}

	if(stoi(choice) == 4)
		mainMenu(theAirports);

}

