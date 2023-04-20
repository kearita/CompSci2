/** List airports and average passengers/day finder specification file
  * @file ListAvgPassengers.h
  * @author Keara Taylor Lopez
*/
#ifndef LISTAVGPASSENGERS_H
#define LISTAVGPASSENGERS_H
#include <vector>
#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

class ListAvgPassengersFinder : public Visitor {
public:

	/**
	    Constructs a List average flights finder with average flights set to 0
	*/
	ListAvgPassengersFinder();


	/**
	    Allows a list average passengers finder to execute code at the time of its destruction
	*/
	~ListAvgPassengersFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    list average passengers at this Airport
	    @param a the Airport object with the average number of passengers to be displayed
	*/
	void visit(Airport a);

	/**
	    Returns a vector containing Airports with their average number of
	    passengers per day listed
	    @return the vector containing the results of Airports with their average
	    number of passengers per day listed
	*/
	vector<Airport> getAvgPassengers();



private:
	long avgPassengers;
	vector<Airport>avgPassengersList;
};

ListAvgPassengersFinder::ListAvgPassengersFinder() {
	avgPassengers = 0;
}


ListAvgPassengersFinder::~ListAvgPassengersFinder() {}



void ListAvgPassengersFinder::visit(Airport a) {
	avgPassengersList.push_back(a);
}


vector<Airport> ListAvgPassengersFinder::getAvgPassengers() {
	return avgPassengersList;
}



#endif // LISTAVGPASSENGERSFINDER_H
