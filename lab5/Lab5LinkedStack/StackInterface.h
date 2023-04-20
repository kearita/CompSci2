/** Stack interface class
  * @file StackInterface.h
  * @author Keara Taylor Lopez
*/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H


template <typename T>
class StackInterface {
public:

    /**
        Adds a new entry to the top of this stack
        @param T the new item to be added
        @return true if addition is successful or false if not
    */
    virtual bool push(const T&) = 0;

    /**
        Removes the top of this stack
        @return true if the removal is successful or false if not
    */
    virtual bool pop() = 0;

	/**
	   Returns the top of this stack
	   @return T the item at the top of this stack
	*/
    virtual T peek() = 0;

    /**
        Determines whether this stack is empty
        @return true if the stack is empty or false if not
    */
    virtual bool isEmpty() = 0;


};

#endif // STACKINTERFACE_H
