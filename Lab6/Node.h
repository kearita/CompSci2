/** Node class
  * @file Node.h
  * @author Keara Taylor Lopez
*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:

    /**
	    Constructs a Node with its next pointer pointing to null
	*/
	Node<T>();

	/**
	    Allows a Node to execute code at the time of its destruction
	*/
	~Node<T>();

	/**
	    Constructs a Node with data and a next pointer
	    @param T the data item for this Node
	    @param Node<T> * the next pointer for this Node
	*/
	Node<T>(T, Node<T> *);

	/**
	    Returns the data in this Node
	    @return T the data in this Node
	*/
	T getData();

	/**
	    Sets the next pointer for this Node
	    @param Node <T> * the next pointer
	*/
	void setNext(Node<T> *);

	/**
	    Returns where the next pointer of this Node is pointing to
	    @return Node<T> the Node that this Node is pointing to
	*/
	Node<T>* getNext();

private:
	T data;
	Node<T> *next;
};


template<typename T>
Node<T>::Node() {
	next = nullptr;
}

template<typename T>
Node<T>::~Node() {
	//dtor
}

template<typename T>
Node<T>::Node(T data, Node<T> *next) {
	this->data = data;
	this->next = next;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
	this->next = next;
}

template<typename T>
T Node<T>::getData() {
	return data;
}

template<typename T>
Node<T>* Node<T>::getNext() {
	return next;
}
#endif // NODE_H
