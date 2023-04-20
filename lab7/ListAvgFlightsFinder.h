/** List airports & average flights/day finder specification file
  * @file ListAvgFlightsFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef LISTAVGFLIGHTS_H
#define LISTAVGFLIGHTS_H
#include <vector>
#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class ListAvgFlightsFinder : public Visitor {
public:

	/**
	    Constructs a List average flights finder with average flights set to 0
	*/
	ListAvgFlightsFinder();

	/**
	    Allows a List average flights finder to execute code at the time of its destruction
	*/
	~ListAvgFlightsFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    list average flights at this Airport
	    @param a the Airport object with the average number of flights to be displayed
	*/
	void visit(Airport a);


	/**
	    Returns a vector containing Airports with their average number of
	    flights per day listed
	    @return the vector containing the results of Airports with their average
	    number of flights per day listed
	*/
	vector<Airport> getAvgFlights();



private:
	long avgFlights;
	vector<Airport>avgFlightsList;
};


ListAvgFlightsFinder::ListAvgFlightsFinder() {
	avgFlights = 0;
}


ListAvgFlightsFinder::~ListAvgFlightsFinder() {}


void ListAvgFlightsFinder::visit(Airport a) {
	avgFlightsList.push_back(a);
}


vector<Airport> ListAvgFlightsFinder::getAvgFlights() {
	return avgFlightsList;
}


#endif // LISTAVGFLIGHTSFINDER_H
