/** Airport class implementation file
  * @file Airport.cpp
  * @author Keara Taylor Lopez
*/
#include "Airport.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

Airport::Airport() {
	name = "";
	state = "";
	city = "";
	code = "";
	numPassengers = 0;
	numFlights = 0;
	freight = 0;
}

Airport::Airport(string line) {
	stringstream ss(line);
	string temp = "";

	getline(ss, name, ',');
	getline(ss, state, ',');
	getline(ss, city, ',');
	getline(ss, code, ',');
	getline(ss, temp, ',');
	numPassengers = stol(temp);
	getline(ss, temp, ',');
	numFlights = stol(temp);
	getline(ss, temp, ',');
	freight = stol(temp);

}

Airport::~Airport() {}

//----------setters and getters----------
void Airport::setName(string name) {
	this->name = name;
}

void Airport::setState(string state) {
	this->state = state;
}

void Airport::setCity(string city) {
	this->city = city;
}

void Airport::setCode(string code) {
	this->code = code;
}

void Airport::setNumPassengers(long numPassengers) {
	this->numPassengers = numPassengers;
}

void Airport::setNumFlights(long numFlights) {
	this->numFlights = numFlights;
}

void Airport::setFreight(long freight) {
	this->freight = freight;
}

string Airport::getName() {
	return name;
}

string Airport::getState() {
	return state;
}

string Airport::getCity() {
	return city;
}

string Airport::getCode() {
	return code;
}

long Airport::getNumPassengers() {
	return numPassengers;
}

long Airport::getNumFlights() {
	return numFlights;
}

long Airport::getFreight() {
	return freight;
}


bool Airport::operator==(const Airport &a) const {
	bool same = false;

	if(name == a.name && state == a.state && city == a.city && code == a.code &&
	        numPassengers == a.numPassengers && numFlights == a.numFlights && freight == a.freight)
		same = true;

	return same;
}

bool Airport::operator==(string code) const {
	bool same = false;

	if(code == this->code)
		same = true;

	return same;
}

bool Airport::operator!=(const Airport &a) const {
	return (freight != a.freight);
}

bool Airport::operator<(const Airport &a) const {
	return (numPassengers < a.numPassengers);
}

bool Airport::operator>(const Airport &a) const {
	return (numPassengers > a.numPassengers);
}

Airport& Airport::operator+=(int flightsToAdd) {
	numFlights += flightsToAdd;
	return *this;
}


ostream &operator<<(ostream &out, const Airport &a) {

	out << setfill(' ') << setw(62) << left << a.name;
	out << setfill(' ') << setw(6) << left << a.state;
	out << setfill(' ') << setw(21) << left << a.city;
	out << setfill(' ') << setw(6) << left << a.code;
	out << setfill(' ') << setw(9) << left << a.numPassengers;
	out << setfill(' ') << setw(8) << left << a.numFlights;
	out << setfill(' ') << setw(6) << left << a.freight << endl;

	return out;
}

