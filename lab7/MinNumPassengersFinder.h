/** Minimum number of passengers finder specification file
  * @file MinNumPassengersFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef MINNUMPASSENGERSFINDER_H
#define MINNUMPASSENGERSFINDER_H
#include <vector>
#include "Airport.h"

using namespace std;

class MinNumPassengersFinder : public Visitor {
public:

	/**
	    Constructs a Minimum number of passengers finder with its minimum
	    number of passengers set to 0
	*/
	MinNumPassengersFinder();


	/**
	    Allows a MinNumPassengersFinder to execute code at the time of its destruction
	*/
	~MinNumPassengersFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    find the Airport with the smallest number of passengers
	    @param a the Airport object with the smallest number of passengers
	*/
	void visit(Airport a);


	/**
	    Returns a vector containing the Airport with the lowest number of passengers
	    @return the vector containing the lowest number of passengers
	*/
	vector<Airport> getMinNumPassengers();



private:
	long minPassengers = 70000000;
	vector<Airport>minPassengersList;
};

MinNumPassengersFinder::MinNumPassengersFinder() {
	minPassengers = 0;
}



MinNumPassengersFinder::~MinNumPassengersFinder() {}



void MinNumPassengersFinder::visit(Airport a) {
	if(a.getNumPassengers() < minPassengers)
		minPassengers = a.getNumPassengers();

	minPassengersList.push_back(a);

}


vector<Airport> MinNumPassengersFinder::getMinNumPassengers() {
	return minPassengersList;
}



#endif // MINNUMPASSENGERSFINDER_H
