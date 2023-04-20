/** Binary search tree specification file
  * @file BinarySearchTree.h
  * @author Keara Taylor Lopez
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BSTInterface.h"
#include "Node.h"
#include "Airport.h"
#include "SearchByCodeFinder.h"
#include <iostream>


using namespace std;


template <typename T>
class BinarySearchTree : public BSTInterface<T> {
public:

	/**
	    Constructs a Binary Search Tree with the root pointing to null
	*/
	BinarySearchTree();

	/**
	    Allows a Binary Search Tree to execute code at the time of its destruction
	*/
	~BinarySearchTree();

	/**
	   Outward facing method that allows adding to Binary Search Tree
	   @param newItem the newItem to be added
	   @return bool true if new item was added and false otherwise
	*/
	bool add(const T& newItem);

	/**
	    Outward facing method that determines if an item exists in the
	    Binary Search Tree
	    @param findItem the item to determine if exists in the BST
	    @return bool true if item exists in BST and false otherwise
	*/
	bool contains(const T& findItem) const ;

	/**
	   Outward facing method that pre-order traverses the Binary
	   Search Tree
	*/
	void preOrderTraverse() const ;

	/**
	   Outward facing method that post-order traverses the Binary
	   Search Tree
	*/
	void postOrderTraverse() const;

	/**
	    Outward facing method that allows a visitor to in-order traverse
	    the Binary Search Tree
	    @param t the Visitor that in-order traverses the BST
	*/
	void inOrderVisit(Visitor &visitor) const;


private:

	Node<T> *root;
	Node<T>* add(Node<T>* currentRoot, Node<T> * newNode);
	bool contains(Node<T> *currentRoot, const T& item) const;
	void preOrderTraverse(Node<T>* currentRoot) const;
	void postOrderTraverse(Node<T>* currentRoot) const;
	void inOrderVisit(Node<T>* currentRoot, Visitor &visitor) const;
	void inOrderVisit(Node<T>* currentRoot, Airport &a) const;

};


template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}


template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {}


template <typename T>
bool BinarySearchTree<T>::add(const T& data) {
	Node<T>* n = new Node<T>(data);
	root = add(root, n); //call internal add method
	return true;
}

template <typename T>
Node<T>* BinarySearchTree<T>::add(Node<T>* currentRoot, Node<T>* newNode) {
	if(currentRoot == nullptr)
		return newNode;
	else {
		if(newNode->getItem() < currentRoot->getItem()) {
			Node<T>* tempPtr = add(currentRoot->getLeftChild(), newNode);
			currentRoot->setLeftChild(tempPtr);
		} else {
			currentRoot->setRightChild(add(currentRoot->getRightChild(), newNode));
		}
	}//end else
}


template <typename T>
void BinarySearchTree<T>::preOrderTraverse() const {
	if(root == nullptr) {
		cout << "Empty tree" << endl;
		return;
	}

	preOrderTraverse(root);
}

template <typename T>
void BinarySearchTree<T>::preOrderTraverse(Node<T>* currentRoot) const {
	if(currentRoot != nullptr) {
		cout << currentRoot->getItem() << endl;
		preOrderTraverse(currentRoot->getLeftChild());
		preOrderTraverse(currentRoot->getRightChild());
	}
}

template <typename T>
void BinarySearchTree<T>::postOrderTraverse() const {
	if(root == nullptr) {
		cout << "Empty tree" << endl;
		return;
	}

	postOrderTraverse(root);
}

template <typename T>
void BinarySearchTree<T>::postOrderTraverse(Node<T>* currentRoot) const {
	if(currentRoot != nullptr) {
		postOrderTraverse(currentRoot->getLeftChild());
		postOrderTraverse(currentRoot->getRightChild());
		cout << currentRoot->getItem() << endl;
	}
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& toFind) const {
	return contains(root, toFind);
}

template <typename T>
bool BinarySearchTree<T>::contains(Node<T>* currentRoot, const T& toFind) const {
	if(currentRoot == nullptr)
		return false;
	else if(toFind == currentRoot->getItem())
		return true;
	else if(toFind < currentRoot->getItem())
		return contains(currentRoot->getLeftChild(), toFind);
	else
		return contains(currentRoot->getRightChild(), toFind);
}


template <typename T> //outward facing
void BinarySearchTree<T>::inOrderVisit(Visitor &visitor) const {
	if(root == nullptr) {
		cout << "empty tree" << endl;
		return;
	}

	inOrderVisit(root, visitor);
}


template <typename T> //internal method
void BinarySearchTree<T>::inOrderVisit(Node<T>* currentRoot, Visitor &visitor) const {
	if(currentRoot != nullptr) {
		inOrderVisit(currentRoot->getLeftChild(), visitor);
		visitor.visit(currentRoot->getItem());
		inOrderVisit(currentRoot->getRightChild(), visitor);
	}
}


#endif // BINARYSEARCHTREE_H
