/** Minimum number of flights finder specification file
  * @file MinNumFlightsFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef MINNUMFLIGHTSFINDER_H
#define MINNUMFLIGHTSFINDER_H
#include <vector>
#include "Airport.h"

using namespace std;

class MinNumFlightsFinder : public Visitor {
public:

	/**
	    Constructs a Minimum number of flights finder with its
	    minimum number of flights set to 0
	*/
	MinNumFlightsFinder();


	/**
	    Allows a MinNumFlightsFinder to execute code at the time of its destruction
	*/
	~MinNumFlightsFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    find the Airport with the smallest number of flights
	    @param a the Airport object with the smallest number of flights
	*/
	void visit(Airport a);


	/**
	    Returns a vector containing the Airport with the lowest number of flights
	    @return the vector containing the lowest number of flights
	*/
	vector<Airport> getMinNumFlights();



private:
	long minNumFlights = 1000000;
	vector<Airport>minNumFlightsList;
};

MinNumFlightsFinder::MinNumFlightsFinder() {
	minNumFlights = 0;
}


MinNumFlightsFinder::~MinNumFlightsFinder() {}



void MinNumFlightsFinder::visit(Airport a) {
	if(a.getNumFlights() > minNumFlights)
		minNumFlights = a.getNumFlights();

	minNumFlightsList.push_back(a);

}

vector<Airport> MinNumFlightsFinder::getMinNumFlights() {
	return minNumFlightsList;
}



#endif // MINNUMFLIGHTSFINDER_H
