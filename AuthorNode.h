/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Author linked node
 *This class implements a singly linked node using templates
 *to represent an author
 *Each nodes the following attributes:
	-fName: stores the first name of an author
	-lName: stores the last name of an author
	-next: a pointer to the next author in the list
*/


/*
 *include necesarry libraries 
 *and set name space
*/

#include <iostream>
using namespace std;

/*
 *Class Declaration
*/

template <class T>
class AuthorNode{
public:
	AuthorNode(); //Default constructor
	AuthorNode(T, T, AuthorNode<T>*); //Special constructor
	T getFName(); //get author's first name
	T getLName(); //get author's last name
	AuthorNode<T>* getNext(); // getNext Author
	void setFName(T); //set author's first name
	void setLName(T); //set author's last name
	void setNext(AuthorNode<T> *); //Set next Author
private:
	T fName; //Author's first name
	T lName; //Author's last name
	AuthorNode<T> *next; //Points to the next node in the list
};


/*
 *Default constructor
 *Creates a empty node
 *next is zero by default
*/
template <class T>
AuthorNode<T>::AuthorNode(){
	next = 0;
}

/*
 *Special constructor:
 *Creates an author node with fName attribute of first
 *and a lName attribute of last and next pointing to zero
 *@params:
	first: first name
	last: last name
	*n: pointer to the next author node
*/
template <class T>
AuthorNode<T>::AuthorNode(T first, T last, AuthorNode<T> *n = 0){ 
	fName = first;
	lName = last;
	next = n;
}

/*
 *This function returns the first name of author
*/
template <class T>
T AuthorNode<T>::getFName(){
	return fName;
}

/*
 *This method returns the last name of author
*/
template <class T>
T AuthorNode<T>::getLName(){
	return lName;
}

/*
 *This method will return a pointer to the next author
*/
template <class T>
AuthorNode<T> *AuthorNode<T>::getNext(){
	return next;
}

/*
 *This method will set first as the fName attribute
*/
template <class T>
void AuthorNode<T>::setFName(T first){
	fName = first;
}

/*
 *This method will set last as the lName attribute
*/
template <class T>
void AuthorNode<T>::setLName(T last){
	lName = last;
}

/*
 *This method sets next to point towards the next author node
*/
template <class T>
void AuthorNode<T>::setNext(AuthorNode<T> *n = 0){
	next = n;
}
