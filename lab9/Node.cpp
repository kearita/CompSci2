#include "Node.h"

Node::Node()
{
    data = "";
    nextPtr = nullptr;
}

Node::~Node() {}

string Node::getData() {
    return data;
}
