/** Search by airport code finder specification file
  * @file SearchByCodeFinder.h
  * @author Keara Taylor Lopez
*/
#ifndef SEARCHBYCODEFINDER_H
#define SEARCHBYCODEFINDER_H
#include <iostream>
#include <string>
#include <vector>
#include "Airport.h"

using namespace std;

class SearchByCodeFinder : public Visitor {
public:

	/**
	    Constructs a Search by code finder reading an inputted airport code
	    @param code the code to be searched
	*/
	SearchByCodeFinder(string code);

	/**
	    Allows a SearchByCodeFinder to execute code at the time of its destruction
	*/
	~SearchByCodeFinder();

	/**
	    Visits the Binary Search tree taking in the airport object in order to
	    search for an Airport by code
	    @param a the Airport object with user-inputted airport code
	*/
	void visit(Airport a);

	/**
	    Returns a vector that contains the Airport with input airport code
	    @return the vector that contains the Airport with input airport code
	*/
	vector<Airport> getAirportCode();



private:
	string airportCode;
	vector<Airport>codeList;
};



SearchByCodeFinder::SearchByCodeFinder(string code) : Visitor() {
	airportCode = code;
}

SearchByCodeFinder::~SearchByCodeFinder() {}


void SearchByCodeFinder::visit(Airport a) {
	if(a.getCode() == airportCode) {
		codeList.push_back(a);
	}
}


vector<Airport> SearchByCodeFinder::getAirportCode() {
	return codeList;
}

#endif // SEARCHBYCODEFINDER_H




