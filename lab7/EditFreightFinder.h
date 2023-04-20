/** Edit freight finder specification file
  * @file EditFreightFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef EDITFREIGHTFINDER_H
#define EDITFREIGHTFINDER_H

#include <vector>
#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class EditFreightFinder : public Visitor {
public:

	/**
	    Constructs a Edit Freight finder that reads in an airport code from the user,
	    allows user to change freight amount and displays the change
	    @param code the airport code read from input
	*/
	EditFreightFinder(string code);

	/**
	    Allows a SearchByPassengersFinder to execute code at the time of its destruction
	*/
	~EditFreightFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    edit freight at this Airport
	    @param a the Airport object with the freight to be edited
	*/
	void visit(Airport a);

	/**
	    Returns a vector containing Airports which have a greater number
	    of passengers than inputted number of passengers
	    @return the vector containing the results of Airports with a
	    greater number of passengers than inputted number of passengers
	*/
	vector<Airport> getEditFreight();



private:
	long freightToEdit;
	string airportCode;
	vector<Airport>editFreightList;
};


EditFreightFinder::EditFreightFinder(string code) {
	airportCode = code;
}

EditFreightFinder::~EditFreightFinder() {}


void EditFreightFinder::visit(Airport a) {
	if(a.getCode() == airportCode)
		editFreightList.push_back(a);
}


vector<Airport> EditFreightFinder::getEditFreight() {
	return editFreightList;
}



#endif // EDITFREIGHTFINDER_H
