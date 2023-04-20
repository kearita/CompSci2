/** Linked stack class
  * @file LinkedStack.h
  * @author Keara Taylor Lopez
*/
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "StackInterface.h"

template <typename T>
class LinkedStack : public StackInterface<T> {
public:
	/**
	    Constructs a LinkedStack with its head pointer pointing to null
	*/
	LinkedStack();

	/**
	    Allows a LinkedStack to execute code at the time of its destruction
	*/
	~LinkedStack();

	/**
	    Adds a new entry to the top of this LinkedStack
	    @param T the new item to be added
	    @return true if addition is successful or false if not
	*/
	bool push(const T&);

	/**
	    Removes the top of this LinkedStack
	    @return true if the removal is successful or false if not
	*/
	bool pop();

	/**
	    Determines whether this LinkedStack is empty
	    @return true if the LinkedStack is empty or false if not
	*/
	bool isEmpty();

	/**
	    Returns the top of this LinkedStack
	    @return T the item at the top of this LinkedStack
	*/
	T peek();

private:
	Node<T> *head;
};

#endif // LINKEDSTACK_H

template <typename T>
LinkedStack<T>::LinkedStack() {
	head = nullptr;
}//ctor

template <typename T>
LinkedStack<T>::~LinkedStack() {
}//dtor

template <typename T>
bool LinkedStack<T>::isEmpty() {
	return head == nullptr;
}//end isEmpty()

template <typename T>
bool LinkedStack<T>::push(const T& newData) {
	Node<T> *n = new Node<T> (newData, nullptr);
	n->setNext(head);
	head = n;

	return true;

}//end push()


template <typename T>
T LinkedStack<T>::peek() {
	return head->getData();
}//end peek

template <typename T>
bool LinkedStack<T>::pop() {
	bool popped = false;

	if(!isEmpty()) {
		Node<T> *nodeToDelete = head;
		head = head->getNext();
		nodeToDelete->setNext(nullptr);
		delete nodeToDelete;
		nodeToDelete = nullptr;

		popped = true;
	}//end if

	return popped;
}//end pop
