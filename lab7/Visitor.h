/** Visitor specification file
  * @file Visitor.h
  * @author Keara Taylor Lopez
*/
#ifndef VISITOR_H
#define VISITOR_H

#include "Airport.h"
#include <vector>

using namespace std;

class Visitor {
public:

	/**
	    Constructs a Visitor
	*/
	inline Visitor();

	/**
	    Allows a Visitor to execute code at the time of its destruction
	*/
	inline ~Visitor();

	/**
	    Visits the Binary Search tree taking in the airport object
	    @param a the Airport object
	*/
	virtual void visit(Airport a) = 0;


private:
};

Visitor::Visitor() {}

Visitor::~Visitor() {}


#endif // VISITOR_H




