/** Packet class implementation file
  * @file Packet.cpp
  * @author Keara Taylor Lopez
*/
#include "Packet.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Packet::Packet()
{
    long long IDnumber = 0;
    int fileSize = 0;
    int priorityNumber = 0;
}

Packet::Packet(string line) {
    stringstream ss(line);
    string temp = "";

    getline(ss, temp, ',');
    IDNumber = stoll(temp);
    getline(ss, temp, ',');
    fileSize = stoi(temp);
    getline(ss, temp, ',');
    priorityNumber = stoi(temp);

}

Packet::~Packet() {}

void Packet::setIDNumber(long long IDNumber) {
    this->IDNumber = IDNumber;
}

void Packet::setFileSize(int fileSize) {
    this->fileSize = fileSize;
}

void Packet::setPriorityNumber(int priorityNumber) {
    this->priorityNumber = priorityNumber;
}

long long Packet::getIDNumber() {
    return IDNumber;
}

int Packet::getFileSize() {
    return fileSize;
}

int Packet::getPriorityNumber() {
    return priorityNumber;
}

/*
bool Packet::operator<(const Packet& p) const {
    return ((IDNumber < p.IDNumber) && (fileSize < p.fileSize) &&
            (priorityNumber < p.priorityNumber));
}
*/

bool Packet::operator<(const Packet& p) const {
    return ((priorityNumber < p.priorityNumber));
}

bool Packet::operator==(const Packet& p) const {
    return ((priorityNumber == p.priorityNumber));
}


/*
bool Packet::operator>(const Packet& p) const {
    return ((IDNumber > p.IDNumber) && (fileSize > p.fileSize) &&
            (priorityNumber > p.priorityNumber));
}
*/

bool Packet::operator>(const Packet& p) const {
    return ((priorityNumber > p.priorityNumber));
}

ostream &operator<<(ostream &out, const Packet &p) {
    out << p.IDNumber << " " << p.fileSize << " " << p.priorityNumber << endl;

    return out;
}
