/** Node specification file
  * @file Node.h
  * @author Keara Taylor Lopez
*/
#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <iostream>

template <typename T>
class Node {
public:

	/**
	    Constructs a Node with the left and right child pointing to null
	*/
	Node();

	/**
	    Allows a Node to execute code at the time of its destruction
	*/
	~Node();

	/**
	    Constructs a Node with a new item
	    @param newItem the newItem the Node will be created with
	    @param left the left child pointing to null
	    @param right the right child pointing to null
	*/
	Node(const T& newItem,
	     Node<T>* left = nullptr,  //initialize the pointers to nullptr
	     Node<T>* right = nullptr);


	/**
	    Constructs a Node with original Node data
	    @param orig the original data that the Node with be constructed with
	*/
	Node(const Node& orig);


	/**
	    Returns a data item
	    @T the data item
	*/
	T getItem() const;

	/**
	    Sets a new Item of this Node
	    @param newItem the new Item for this Node
	*/
	void setItem(const T& newItem);


	/**
	    Returns the left child data
	    @return Node the Node containing left child data
	*/
	Node<T>* getLeftChild() const;

	/**
	    Returns the right child data
	    @return Node the Node containing the right child data
	*/
	Node<T>* getRightChild() const;

	/**
	    Sets the new left child for this Node
	    @param the new left child for this Node
	*/
	void setLeftChild(Node<T>* left);

	/**
	    Sets the new right child for this Node
	    @param the new right child for this Node
	*/
	void setRightChild(Node<T>* right);


	/**
	    Determines if a Node is a leaf
	    @return bool returns true if Node is a leaf and false otherwise
	*/
	bool isLeaf() const;


private:
	T item;
	Node<T>* leftChild;
	Node<T>* rightChild;
};

template <typename T>
Node<T>::Node() {
	leftChild = nullptr;
	rightChild = nullptr;

}



template <typename T>
Node<T>::Node(const T& newItem,
              Node<T>* left, Node<T>* right) {

	item = newItem;
	leftChild = left;
	rightChild = right;
}




template <typename T>
Node<T>::Node(const Node& orig) {
	item = orig.item;
	leftChild = orig.leftChild;
	rightChild = orig.rightChild;
}




template <typename T>
Node<T>::~Node() {}




template <typename T>
T Node<T>::getItem() const {
	return item;
}



template <typename T>
void Node<T>::setItem(const T& newItem) {
	item = newItem;
}



template <typename T>
Node<T>* Node<T>::getLeftChild() const {
	return leftChild;
}




template <typename T>
Node<T>* Node<T>::getRightChild() const {
	return rightChild;
}



template <typename T>
void Node<T>::setLeftChild(Node<T>* left) {
	leftChild = left;
}



template <typename T>
void Node<T>::setRightChild(Node<T>* right) {
	rightChild = right;
}





template <typename T>
bool Node<T>::isLeaf() const {
	return (leftChild == nullptr && rightChild == nullptr);
}


#endif // NODE_H





