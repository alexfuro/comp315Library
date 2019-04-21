/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Genre binary tree node
 *This class implements a binary tree node using templates
 *to represent a generebooks
 *Each node has the following attributes:
	-genre: stores the genre
	-books: store a list of the books in the genre
	-left: a pointer to the genres that are alphabetically lower
	-right: a pointer to the genres that are alphabetically higher

*/

/*
 *include necesarry libraries 
 *and set name space
*/
#include "BookList.h"
#include <iostream>
using namespace std;
/*
 *Class Declaration
*/
template <class T>
class GenreNode{
public:
	GenreNode(); //Default constructor creates empty node
	GenreNode(GenreNode<T>*, T, BookList<T>*, GenreNode<T>*); //Special constructor
	T getGenre(); //This method will return the genre
	GenreNode<T>* getLeft(); //This method will return the left genre
	GenreNode<T>* getRight(); //This method will return the right genre
	BookList<T>* getBooks(); //This method will return the books of the genre
	void setGenre(T); //This method will set the genre 
	void setBooks(BookList<T> *); //This method will set the bookList
	void setLeft(GenreNode<T> *); //Set left genre node
	void setRight(GenreNode<T> *); //Set right genre node
private:
	
	GenreNode<T> *left;//Points to the left genre
	T genre; //Genre name
	BookList<T> *books; //Circular doubly linked list of books
	GenreNode<T> *right; //Points to the right genre
};


/*
 *Default constructor
 *Creates a empty genre node
*/
template <class T>
GenreNode<T>::GenreNode(){
	right = left = 0;
}

/*
 *Special constructor create a new genre node
 *@params:		
	l: the genre's left child to be stored
	g: the genre's name to be stored
	b: the genre's books to be stored
	r: the genre's right child to be stored
*/
template <class T>
GenreNode<T>::GenreNode(GenreNode<T> *l, T g, BookList<T> *b, GenreNode<T> *r){	
	left = l; 
	genre = g;
	books = b;
	right = r;
}

/*
 *this method will return the genre of the node
*/
template <class T>
T GenreNode<T>::getGenre(){ 
	return genre;
}

/*
 *this method will return the right child genre of the node
*/
template <class T>
GenreNode<T> *GenreNode<T>::getRight(){
	return right;
}

/*
 *this method will return the left child genre of the node
*/
template <class T>
GenreNode<T> *GenreNode<T>::getLeft(){
	return left;
}

/*
 *this method will return the books of the genre node
*/
template <class T>
BookList<T>* GenreNode<T>::getBooks(){
	return books;
}

/*
 *this method will set the genre of the node
 *@params:
	-g: the genre to be stored
*/
template <class T>
void GenreNode<T>::setGenre(T g){ 
	genre = g;
}

/*
 *this method will set the right child genre of the node
*/
template <class T>
void GenreNode<T>::setRight(GenreNode<T> *r = 0){ 
	right = r;
}

/*
 *this method will set the left child genre of the node
*/
template <class T>
void GenreNode<T>::setLeft(GenreNode<T> *l = 0){ 
	left = l;
}
