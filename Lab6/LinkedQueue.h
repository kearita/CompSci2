/** Linked queue class
  * @file LinkedQueue.h
  * @author Keara Taylor Lopez
*/
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "QueueInterface.h"
#include "Node.h"

template <typename T>
class LinkedQueue : public QueueInterface<T> {
public:

    /**
	    Constructs a LinkedQueue with its head pointer pointing to null
	*/
	LinkedQueue();

	/**
	    Allows a LinkedQueue to execute code at the time of its destruction
	*/
	~LinkedQueue();

	/**
	    Determines whether this LinkedQueue is empty
	    @return true if the LinkedQueue is empty or false if not
	*/
	bool isEmpty();

	/**
	    Adds a new entry to the back of this LinkedQueue
	    @param T the new item to be added
	    @return true if addition is successful or false if not
	*/
	bool enqueue(T);

	/**
	    Removes the front of this LinkedQueue
	    @return true if the removal is successful or false if not
	*/
	bool dequeue();

	/**
	    Returns the front of this LinkedQueue
	    @return T the item at the front of this LinkedQueue
	*/
	T peek();

private:
	Node<T> *front;
	Node<T> *back;
};

template<typename T>
LinkedQueue<T>::LinkedQueue() {
	front = nullptr;
	back = nullptr;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
	//dtor
}

template<typename T>
bool LinkedQueue<T>::isEmpty() {
	return front == nullptr && back == nullptr;
}

template<typename T>
bool LinkedQueue<T>::enqueue(T newItem) {
	Node<T> *n = new Node<T> (newItem, nullptr);

	if(isEmpty()) {
		front = n;
	} else {
		back->setNext(n);
	}

	back = n;

	return true;
}

template<typename T>
bool LinkedQueue<T>::dequeue() {
	bool success = false;

	if(!isEmpty()) {
		Node<T> *n = front;

		if(front == back) {
			front = nullptr;
			back = nullptr;
		} else {
			front = front->getNext();
		}

		n->setNext(nullptr);
		delete n;
		n = nullptr;

		success = true;
	}

	return true;
}

template<typename T>
T LinkedQueue<T>::peek() {
	return front->getData();
}

#endif // LINKEDQUEUE_H
