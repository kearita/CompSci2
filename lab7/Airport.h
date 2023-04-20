/** Airport class specification file
  * @file Airport.h
  * @author Keara Taylor Lopez
*/
#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>

using namespace std;

class Airport {
public:
	/**
	    Constructs a Airport with empty strings for airport name, state, city, and
	    airport code, and 0 for the number of passengers, number of flights and
	    freight
	*/
	Airport();

	/**
	    Constructs a Airport by reading airport data as a line from an external
	    file and parses all data in that line as individual airport data
	    @param line the line that contains airport data
	*/
	Airport(string line);

	/**
	    Allows a Airport to execute code at the time of its destruction
	*/
	virtual ~Airport();

	/**
	    Sets the airport name of this Airport
	    @param name the new name of this Airport
	*/
	void setName(string name);

	/**
	    Sets the state as the location of this Airport
	    @param state the new state of this Airport
	*/
	void setState(string state);

	/**
	    Sets the city as the location of this Airport
	    @param city the new city of this Airport
	*/
	void setCity(string city);

	/**
	    Sets the airport code of this Airport
	    @param code the new airport code of this Airport
	*/
	void setCode(string code);

	/**
	    Sets the number of passengers of this Airport
	    @param numPassengers the new number of passengers at this Airport
	*/
	void setNumPassengers(long numPassengers);

	/**
	    Sets the number of flights of this Airport
	    @param numFlights the new number of flights at this Airport
	*/
	void setNumFlights(long numFlights);

	/**
	    Sets the freight of this Airport
	    @param freight the new freight of this Airport
	*/
	void setFreight(long freight);

	/**
	    Returns the name of this Airport
	    @return name
	*/
	string getName();

	/**
	    Returns the state where this Airport is located
	    @return state
	*/
	string getState();

	/**
	    Returns the city where this Airport is located
	    @return city
	*/
	string getCity();

	/**
	    Returns the code of this Airport
	    @return code
	*/
	string getCode();

	/**
	    Returns the number of passengers at this Airport
	    @return numPassengers
	*/
	long getNumPassengers();

	/**
	    Returns the number of flights at this Airport
	    @return numFlights
	*/
	long getNumFlights();

	/**
	    Returns the amount of freight at this Airport
	    @return freight
	*/
	long getFreight();

	/**
	    Overloads the == operator in order to compare two Airport objects
	    @param &a the Airport object to be compared
	    @return true if equal and false otherwise
	*/
	bool operator==(const Airport &a) const;

	/**
	    Overloads the == operator in order to compare an Airport object
	    and a string
	    @param code the string to be compared to the Airport object
	    @return true if equal and false otherwise
	*/
	bool operator==(string code) const;

	/**
	    Overloads the != operator in order to compare the freight
	    of two Airports
	    @param &a the Airport object to be compared
	    @return true if freight of one Airport is not the same as another and false otherwise
	*/
	bool operator!=(const Airport &a) const;

	/**
	    Overloads the < operator in order to compare the number of passengers
	    of two Airport objects
	    @param &a the Airport object to be compared
	    @return true if number of passengers of this Airport is less than another Airport
	*/
	bool operator<(const Airport &a) const;

	/**
	    Overloads the > operator in order to compare the number of passengers
	    of two Airport objects
	    @param &a the Airport object to be compared
	    @return true if number of passengers of this Airport is more than another Airport
	*/
	bool operator>(const Airport &a) const;

	/**
	    Overloads the += operator to increase the number of flights at an Airport
	    @param flightsToAdd the number of flights to add to current number of flights of this Airport
	    @return the Airport with increased number of flights
	*/
	Airport& operator+=(int flightsToAdd);

	/**
	    Overloads the << operator in order to display the current state of
	    an Airport object
	    @param &out the ostream object to output Airport object
	    @param a& the Airport to be displayed
	    @return the ostream that displays attributes of this Airport
	*/
	friend ostream& operator<<(ostream &out, const Airport &a);

	/**
	    Overloads the >> operator to allow the user to enter an Airport
	    into the data structure
	    @param &in the istream object to take in Airport object data
	    @param &a the Airport to be read from input
	    @return the istream that inputs attributes of this Airport entered by user
	*/
	friend istream& operator>>(istream &in, const Airport &a);

private:
	string name;
	string state;
	string city;
	string code;
	long numPassengers;
	long numFlights;
	long freight;
};

#endif // AIRPORT_H
