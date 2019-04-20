/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Book doubly linked node
 *This class implements a doubly linked node using templates
 *to represent a book
 *Each node has the following attributes:
	-title: stores the title
	-plot: store a synopsis of the book
	-authors: stores list of all the authors
	-editor: stores the name of the editor
	-year: stores the publication year
	-next: a pointer to the next book in the list
	-prev: a pointer to the previous book in the list
*/


/*
 *include necesarry libraries 
 *and set name space
*/
//#include "AuthorList.h"
#include <iostream>
using namespace std;
/*
 *Class Declaration
*/
template <class T>
class BookNode{
public:
	BookNode(); //Default constructor
	BookNode(BookNode<T>*, T, T, AuthorList<T>*, T, int, BookNode<T>*); //Special constructor
	T getTitle(); //Returns the title of the book 
	T getPlot(); //Returns the plot of the book 
	AuthorList<T>* getAuthors(); //Returns the authors of the book which is a single linked list
	T getEditor(); //Returns the editor of the book
	int getYear(); //Returns the publication year
	BookNode<T>* getNext(); // get next book
	BookNode<T>* getPrev(); // get previous book
	void setTitle(T); //This method will set the book's title
	void setPlot(T); //This method will set the book's plot
	void setEditor(T); //This method will set the book's editor
	void setAuthors(AuthorList<T>*); //This method will set the author list
	void setYear(int); //This method set the year of the publication 
	void setNext(BookNode<T> *); //Set next
	void setPrev(BookNode<T> *); //Set Prev
private:
	
	BookNode<T> *prev;//Points to the previous book in the list
	T title; //This is the title of the book
	T plot; //This is the plot of the book or synopsis
	AuthorList<T> *authors; //This is the list of the book's authors
	T editor; //This is the book's editor
	int year; //This is the book's publication year	
	BookNode<T> *next; //Points to the next book in the list
};


/*
 *Default constructor
 *Creates an empty book
*/
template <class T>
BookNode<T>::BookNode(){
	next = prev = 0;
}

/*
 *Special constructor:
 *Creates a book with value bookTitle in the title attribute
 *bookPlot in the plot attribute
 *and next pointing to null
 *@params:
	*p: pointer to the previous node		
	bookTitle: the book's title to be store
	bookPlot: the book's plot to be stored
	bookAuthors: the book's authors to be stored
	bookEditor: the book's editor to be stored
	bookYear: the book's publication year to be stored
	*n: pointer to the next node
*/
template <class T>
BookNode<T>::BookNode(BookNode<T> *p, T bookTitle, T bookPlot, AuthorList<T> *bookAuthors,T bookEditor, int bookYear,  BookNode<T> *n){ 
	prev = p;
	title = bookTitle;
	plot = bookPlot;
	editor = bookEditor;
	year = bookYear;
	authors = bookAuthors;
	next = n;
}

/*
 *This method will return the book's title
*/
template <class T>
T BookNode<T>::getTitle(){
	return title;
}

/*
 *This method will return the book's plot
*/
template <class T>
T BookNode<T>::getPlot(){
	return plot;
}

/*
 *This method will return the book's editor
*/
template <class T>
T BookNode<T>::getEditor(){
	return editor;
}

/*
 *This method will return the book's publication year
*/
template <class T>
int BookNode<T>::getYear(){
	return year;
}

/*
 *This method will return the book's authors
*/
template <class T>
AuthorList<T>* BookNode<T>::getAuthors(){
	return authors;
}

/*
 *This method will return a pointer to the next book
*/
template <class T>
BookNode<T>* BookNode<T>::getNext(){
	return next;
}

/*
 *This method will return a pointer to the previous book
*/
template <class T>
BookNode<T>* BookNode<T>::getPrev(){
	return prev;
}


/*
 *This method will set the title attribute
*/
template <class T>
void BookNode<T>::setTitle(T bookTitle){ 
	title = bookTitle;
}

/*
 *This method will set the plot attribute
*/
template <class T>
void BookNode<T>::setPlot(T bookPlot){ 
	plot = bookPlot;
}

/*
 *This method will set the editor attribute
*/
template <class T>
void BookNode<T>::setEditor(T bookEditor){ 
	editor = bookEditor;
}

/*
 *This method will set the authors attribute
*/
template <class T>
void BookNode<T>::setAuthors(AuthorList<T> *bookAuthors){ 
	authors = bookAuthors;
}

/*
 *This method will set the year attribute
*/
template <class T>
void BookNode<T>::setYear(int bookYear){ 
	year = bookYear;
}

/*
 *This methods sets the next pointer to point to the next book	
*/
template <class T>
void BookNode<T>::setNext(BookNode<T> *n = 0){ 
	next = n;
}

/*
 *This methods sets the prev pointer to point to the previous book	
*/
template <class T>
void BookNode<T>::setPrev(BookNode<T> *p = 0){
	prev = p;
}
