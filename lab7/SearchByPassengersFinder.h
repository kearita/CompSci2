/** Search by number of passengers finder specification file
  * @file SearchByPassengersFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef SEARCHBYPASSENGERSFINDER_H
#define SEARCHBYPASSENGERSFINDER_H
#include <vector>
#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class SearchByPassengersFinder : public Visitor {
public:

	/**
	    Constructs a Search by Passengers finder that reads the number of passengers
	    as input and displays Airports containing greater than input number of
	    passengers
	    @param numPassengers the number of Passengers to be searched
	*/
	SearchByPassengersFinder(long numPassengers);

	/**
	    Allows a SearchByPassengersFinder to execute code at the time of its destruction
	*/
	~SearchByPassengersFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    search for an Airport by number of passengers
	    @param a the Airport object with user-inputted number of passengers
	*/
	void visit(Airport a);


	/**
	    Returns a vector containing Airports which have a greater number
	    of passengers than inputted number of passengers
	    @return the vector containing the results of Airports with a
	    greater number of passengers than inputted number of passengers
	*/
	vector<Airport> getMinNumPassengers();



private:
	long minPassengers;
	vector<Airport>passengersList;
};


SearchByPassengersFinder::SearchByPassengersFinder(long numPassengers) {
	minPassengers = numPassengers;
}

SearchByPassengersFinder::~SearchByPassengersFinder() {}


void SearchByPassengersFinder::visit(Airport a) {
	if(a.getNumPassengers() > minPassengers)
		passengersList.push_back(a);
}


vector<Airport> SearchByPassengersFinder::getMinNumPassengers() {
	return passengersList;
}



#endif // SEARCHBYPASSENGERSFINDER_H
