/** Array stack class
  * @file ArrayStack.h
  * @author Keara Taylor Lopez
*/
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "StackInterface.h"
#include <cassert>

const int MAX_ELEMENTS = 100;

template <typename T>
class ArrayStack : public StackInterface<T> {
public:
	/**
	    Constructs an ArrayStack with its top equal to -1
	*/
	ArrayStack();

	/**
	    Allows an ArrayStack to execute code at the time of its destruction
	*/
	~ArrayStack();

	/**
	    Adds a new entry to the top of this ArrayStack
	    @param T the new item to be added
	    @return true if addition is successful or false if not
	*/
	bool push(const T&);

	/**
	    Removes the top of this ArrayStack
	    @return true if the removal is successful or false if not
	*/
	bool pop();

	/**
	    Returns the top of this ArrayStack
	    @return T the item at the top of this ArrayStack
	*/
	T peek();

	/**
	    Determines whether this ArrayStack is empty
	    @return true if the ArrayStack is empty or false if not
	*/
	bool isEmpty();

	/**
	    Determines whether this ArrayStack is full
	    @return true if the ArrayStack is full or false if not
	*/
	bool isFull();



private:
	T theStack[MAX_ELEMENTS];
	int top;
};

#endif // ARRAYSTACK_H

template<typename T>
ArrayStack<T>::ArrayStack() {
	top = -1;
}//end default constructor

template<typename T>
ArrayStack<T>::~ArrayStack() {
	//dtor
}//end destructor




/* ADD TO THIS FUNCTION
    if (top == MAX_ELEMENTS -1) //I have an isFull() function, maybe just call that here?
    throw runtime_error("ArrayStack is full");
    pushed = false;
    //as soon as you throw an excetpion, the function terminates and returns to the calling function

    //wont get to these lines if it is full
    //top++
    //theStack[top] = newItem;
*/
template<typename T>
bool ArrayStack<T>::push(const T& newItem) {
	bool pushed = false;

	if(!isFull()) {
		top++;
		theStack[top] = newItem;
		pushed = true;
	}//end if

	return pushed;
}//end push()

template<typename T>
bool ArrayStack<T>::pop() {
	bool popped = false;

	if(!isEmpty()) {
		top--;
		popped = true;
	}//end if

	return popped;
}//end pop()

template<typename T>
T ArrayStack<T>::peek() {
	assert(!isEmpty());

	return theStack[top];
}//end peek()

template<typename T>
bool ArrayStack<T>::isEmpty() {
	return top == -1;
}//end isEmpty()

template<typename T>
bool ArrayStack<T>::isFull() {
	return top == MAX_ELEMENTS - 1;
}//end isFull()
