/** Edit number of passengers finder file
  * @file EditNumPassengersFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef EDITNUMPASSENGERSFINDER_H
#define EDITNUMPASSENGERSFINDER_H
#include <vector>
#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class EditNumPassengersFinder : public Visitor {
public:

	/**
	    Constructs a Edit number of passengers finder that reads in an airport
	    code from the user, allows user to change number of passengers and displays the change
	    @param code the airport code read from input
	*/
	EditNumPassengersFinder(string code);

	/**
	    Allows a SearchByPassengersFinder to execute code at the time of its destruction
	*/
	~EditNumPassengersFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    edit number of passengers at this Airport
	    @param a the Airport object with the number of passengers to be edited
	*/
	void visit(Airport a);

	/**
	    Returns a vector containing Airports which have a greater number
	    of passengers than inputted number of passengers
	    @return the vector containing the results of Airports with a
	    greater number of passengers than inputted number of passengers
	*/
	vector<Airport> getEditNumPassengers();



private:
	long numPassengersToEdit;
	string airportCode;
	vector<Airport>editPassengersList;
};



EditNumPassengersFinder::EditNumPassengersFinder(string code) {
	airportCode = code;
}

EditNumPassengersFinder::~EditNumPassengersFinder() {}



void EditNumPassengersFinder::visit(Airport a) {
	if(a.getCode() == airportCode)
		editPassengersList.push_back(a);
}


vector<Airport> EditNumPassengersFinder::getEditNumPassengers() {
	return editPassengersList;
}


#endif // EDITNUMPASSENGERSFINDER_H
