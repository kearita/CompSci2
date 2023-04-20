/** Maximum number of passengers finder specification file
  * @file MaxNumPassengersFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef MAXNUMPASSENGERSFINDER_H
#define MAXNUMPASSENGERSFINDER_H
#include <vector>
#include "Airport.h"

using namespace std;

class MaxNumPassengersFinder : public Visitor {
public:

	/**
	    Constructs a Max number of passengers finder with its maximum
	    number of passengers set to 0
	*/
	MaxNumPassengersFinder();


	/**
	    Allows a MaxNumPassengersFinder to execute code at the time of its destruction
	*/
	~MaxNumPassengersFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    find the Airport with the highest number of passengers
	    @param a the Airport object with the highest number of passengers
	*/
	void visit(Airport a);


	/**
	    Returns a vector containing the Airport with the maximum
	    number of passengers
	    @return the vector containing the max number of passengers
	*/
	vector<Airport> getMaxNumPassengers();




private:
	long maxPassengers = 0;
	vector<Airport>maxPassengersList;
};

MaxNumPassengersFinder::MaxNumPassengersFinder() {
	maxPassengers = 0;
}


MaxNumPassengersFinder::~MaxNumPassengersFinder() {}


void MaxNumPassengersFinder::visit(Airport a) {
	if(a.getNumPassengers() > maxPassengers)
		maxPassengers = a.getNumPassengers();

	maxPassengersList.push_back(a);
}



vector<Airport> MaxNumPassengersFinder::getMaxNumPassengers() {
	return maxPassengersList;
}

#endif // MAXNUMPASSENGERSFINDER_H
