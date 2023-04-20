/** Minimum freight finder specification file
  * @file MinFreightFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef MINFREIGHTFINDER_H
#define MINFREIGHTFINDER_H
#include <vector>
#include "Airport.h"

using namespace std;

class MinFreightFinder : public Visitor {
public:

	/**
	    Constructs a minimum freight finder with its minimum
	    freight set to 0
	*/
	MinFreightFinder();

	/**
	    Allows a MinFreightFinder to execute code at the time of its destruction
	*/
	~MinFreightFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    find the Airport with the smallest freight
	    @param a the Airport object with the smallest freight
	*/
	void visit(Airport a);

	/**
	    Returns a vector containing the Airport that has the lowest freight
	    @return the vector containing the lowest freight
	*/
	vector<Airport> getMinFreight();



private:
	long minFreight = 80000000;
	vector<Airport>minFreightList;
};

MinFreightFinder::MinFreightFinder() {
	minFreight = 0;
}


MinFreightFinder::~MinFreightFinder() {}



void MinFreightFinder::visit(Airport a) {
	if(a.getFreight() < minFreight)
		minFreight = a.getFreight();

	minFreightList.push_back(a);

}


vector<Airport> MinFreightFinder::getMinFreight() {
	return minFreightList;
}



#endif // MINFREIGHTFINDER_H
