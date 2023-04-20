/** Queue interface class
  * @file QueueInterface.h
  * @author Keara Taylor Lopez
*/
#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template <typename T>
class QueueInterface {
public:

    /**
        Determines whether this queue is empty
        @return true if the queue is empty or false if not
    */
	virtual bool isEmpty() = 0;

	/**
        Adds a new entry to the back of this queue
        @param T the new item to be added
        @return true if addition is successful or false if not
    */
	virtual bool enqueue(T) = 0;

	/**
        Removes the front of this queue
        @return true if the removal is successful or false if not
    */
	virtual bool dequeue() = 0;

	/**
	   Returns the front of this queue
	   @return T the item at the front of this queue
	*/
	virtual T peek() = 0;
};

#endif // QUEUEINTERFACE_H
