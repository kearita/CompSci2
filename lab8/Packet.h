/** Packet class specification file
  * @file Packet.h
  * @author Keara Taylor Lopez
*/
#ifndef PACKET_H
#define PACKET_H

#include <iostream>
#include <string>

using namespace std;

class Packet
{
    public:
        Packet();
        Packet(string line);
        virtual ~Packet();

        void setIDNumber(long long IDNumber);
        void setFileSize(int fileSize);
        void setPriorityNumber(int priorityNumber);

        long long getIDNumber();
        int getFileSize();
        int getPriorityNumber();

        bool operator<(const Packet& p) const;
        bool operator>(const Packet& p) const;
        bool operator==(const Packet& p) const;
        friend ostream& operator<<(ostream &out, const Packet& p);


    private:
        long long IDNumber;
        int fileSize;
        int priorityNumber;
};

#endif // PACKET_H
