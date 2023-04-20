/** Maximum number of flights finder specification file
  * @file MaxNumFlightsFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef MAXNUMFLIGHTSFINDER_H
#define MAXNUMFLIGHTSFINDER_H
#include <vector>
#include "Airport.h"

using namespace std;

class MaxNumFlightsFinder : public Visitor {
public:

	/**
	    Constructs a Maximum number of flights finder the max number
	    of flights set to 0
	*/
	MaxNumFlightsFinder();


	/**
	    Allows a MaxNumFlightsFinder to execute code at the time of its destruction
	*/
	~MaxNumFlightsFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    find the Airport with the highest number of flights
	    @param a the Airport object with the highest number of flights
	*/
	void visit(Airport a);


	/**
	    Returns the vector containing the Airport with the maximum
	    number of flights
	    @return the vector containing the maximum number of flights
	*/
	vector<Airport> getMaxNumFlights();



private:
	long maxNumFlights;
	vector<Airport>maxNumFlightsList;
};

MaxNumFlightsFinder::MaxNumFlightsFinder() {
	maxNumFlights = 0;
}


MaxNumFlightsFinder::~MaxNumFlightsFinder() {}



void MaxNumFlightsFinder::visit(Airport a) {
	if(a.getNumFlights() > maxNumFlights)
		maxNumFlights = a.getNumFlights();

	maxNumFlightsList.push_back(a);

}


vector<Airport> MaxNumFlightsFinder::getMaxNumFlights() {
	return maxNumFlightsList;
}



#endif // MAXNUMFLIGHTSFINDER_H
