#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node
{
    public:
        Node();
        ~Node();

        string getData();
        Node* nextPtr;

        string data;
};

#endif // NODE_H
