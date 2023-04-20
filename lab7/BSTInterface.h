/** Binary search tree interface
  * @file BSTInterface.h
  * @author Keara Taylor Lopez
*/
#ifndef BSTINTERFACE_H
#define BSTINTERFACE_H

#include "Visitor.h"


template <typename T>
class BSTInterface {
public:

	/**
	    Abstract method that allows adding to Binary Search Tree
	    @param newItem the newItem to be added
	    @return bool true if new item was added and false otherwise
	 */
	virtual bool add(const T& newItem) = 0;

	/**
	    Abstract method that determines if an item exists in the
	    Binary Search Tree
	    @param findItem the item to determine if exists in the BST
	    @return bool true if item exists in BST and false otherwise
	*/
	virtual bool contains(const T& findItem) const = 0;

	/**
	    Abstract method that pre-order traverses the Binary
	    Search Tree
	 */
	virtual void preOrderTraverse() const = 0;

	/**
	    Abstract method that post-order traverses the Binary
	    Search Tree
	 */
	virtual void postOrderTraverse() const = 0;

	/**
	    Abstract method that allows a visitor to in-order traverse
	    the Binary Search Tree
	    @param t the Visitor that in-order traverses the BST
	*/
	virtual void inOrderVisit(Visitor &t) const = 0;

};

#endif // BSTINTERFACE_H
