/** Maximum freight finder specification file
  * @file MaxFreightFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef MAXFREIGHTFINDER_H
#define MAXFREIGHTFINDER_H
#include <vector>
#include "Airport.h"

using namespace std;

class MaxFreightFinder : public Visitor {
public:

	/**
	    Constructs a Maximum Freight Finder with the maximum freight set to 0
	*/
	MaxFreightFinder();


	/**
	    Allows a Max freight finder to execute code at the time of its destruction
	*/
	~MaxFreightFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    find the Airport with the highest freight
	    @param a the Airport object with the highest freight
	*/
	void visit(Airport a);

	/**
	    Returns the vector containing the Airport with the highest freight
	    @return the vector containing the highest freight
	*/
	vector<Airport> getMaxFreight();



private:
	long maxFreight;
	vector<Airport>maxFreightList;
};

MaxFreightFinder::MaxFreightFinder() {
	maxFreight = 0;
}


MaxFreightFinder::~MaxFreightFinder() {}


void MaxFreightFinder::visit(Airport a) {
	if(a.getFreight() > maxFreight)
		maxFreight = a.getFreight();

	maxFreightList.push_back(a);
}


vector<Airport> MaxFreightFinder::getMaxFreight() {
	return maxFreightList;
}



#endif // MAXFREIGHTFINDER_H
