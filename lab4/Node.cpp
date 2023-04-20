#include "Node.h"

/**
    Constructs a Node with a null pointer for next and an initial value of 0
*/
Node::Node()
{
    value = 0;
    next = nullptr;
}

/**
    Allows Node to execute code at the time of its destruction
*/
Node::~Node()
{
    //dtor
}

/**
    Sets the value of a Node
    @param value the new value of a Node
*/
void Node::setValue(int value){
    this->value = value;
}
/**
    Returns the name of a Node
    @return value
*/
int Node::getValue(){
    return value;
}
