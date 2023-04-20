/** Edit number of flights finder file
  * @file EditNumFlightsFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef EDITNUMFLIGHTSFINDER_H
#define EDITNUMFLIGHTSFINDER_H

#include <vector>
#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class EditNumFlightsFinder: public Visitor {
public:

	/**
	    Constructs a Edit number of flights finder that reads in an airport
	    code from the user, allows user to change number of flights and displays the change
	    @param code the airport code read from input
	*/
	EditNumFlightsFinder(string code);

	/**
	    Allows a SearchByPassengersFinder to execute code at the time of its destruction
	*/
	~EditNumFlightsFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    edit number of flights at this Airport
	    @param a the Airport object with the number of flights to be edited
	*/
	void visit(Airport a);

	/**
	    Returns a vector containing Airports which have a greater number
	    of passengers than inputted number of passengers
	    @return the vector containing the results of Airports with a
	    greater number of passengers than inputted number of passengers
	*/
	vector<Airport> getEditNumFlights();



private:
	long flightToEdit;
	string airportCode;
	vector<Airport>editFlightList;
};


EditNumFlightsFinder::EditNumFlightsFinder(string code) {
	airportCode = code;
}

EditNumFlightsFinder::~EditNumFlightsFinder() {}


void EditNumFlightsFinder::visit(Airport a) {
	if(a.getCode() == airportCode)
		editFlightList.push_back(a);
}


vector<Airport> EditNumFlightsFinder::getEditNumFlights() {
	return editFlightList;
}


#endif // EDITNUMFLIGHTSFINDER_H
