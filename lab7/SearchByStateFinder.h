/** Search by state finder specification file
  * @file SearchByStateFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef SEARCHBYSTATEFINDER_H
#define SEARCHBYSTATEFINDER_H
#include <iostream>
#include <vector>
#include <string>
#include "Airport.h"

using namespace std;

class SearchByStateFinder : public Visitor {
public:

	/**
	    Constructs a Search by state finder with its state set to an empty string
	*/
	SearchByStateFinder();

	/**
	    Constructs a Search by state finder reading a inputted state to be searched
	*/
	SearchByStateFinder(string state);

	/**
	    Allows a SearchByStateFinder to execute code at the time of its destruction
	*/
	~SearchByStateFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    search for an Airport by state
	    @param a the Airport object with user-inputted state
	*/
	void visit(Airport a);


	/**
	    Returns a vector containing the Airport located in that state
	    @return the vector containing the Airport located in that state
	*/
	vector<Airport> getAirportState();



private:
	string airportState;
	vector<Airport>stateList;
};


SearchByStateFinder::SearchByStateFinder() {
	airportState = "";
}



SearchByStateFinder::SearchByStateFinder(string state) {
	airportState = state;
}

SearchByStateFinder::~SearchByStateFinder() {}


void SearchByStateFinder::visit(Airport a) {
	if(a.getState() == airportState) {
		stateList.push_back(a);

	}

}


vector<Airport> SearchByStateFinder::getAirportState() {
	return stateList;
}



#endif // SEARCHBYSTATEFINDER_H


