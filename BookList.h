/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Books circular doubly linked list
 *This class implements a circular doubly linked list using templates
 *to represent a collection of books
 *Each list has one attribute:
	-head: a pointer to the first book

 *Considerations:
	1. head points to zero in an empty list
	2. There is no tail pointer
	3. the list is sorted alphabetically by book title
*/

/*
 *Import book node class file
*/

#include "BookNode.h"
template <class T>
/*
 *Class Declaration
*/
class BookList{
public:
	BookList(); //Default constructor: creates an empty book list
	~BookList(); //Destructor: deallocate dynamic memory
	void addToHead(T, T, AuthorList<T> *, T, int); //Create a new book at the head of list, head becomes this new book
	void addToTail(T, T, AuthorList<T> *, T, int); //Create a new book at the end of list
	void deleteFromHead(); //Delete book at the beginning of list, head becomes next book, if only one book head points to zero
	bool isEmpty(); //Returns true if the list is empty, false otherwise
	void sortInsert(T, T, AuthorList<T> *, T, int); //Insert a new book in the list alphabetically by title
	void printList(); //Prints out all the books in order
	void printRevList(); //Prints out all the books in reverse order
	BookNode<T>* findBook(T); //find a book that matches the parameter

private:
	BookNode<T> *head; //A pointer to the first book
};

/*
 *Default constructor: creates an empty book list
 *Head points to zero
*/
template <class T>
BookList<T>::BookList(){
	head = 0;
}

/*
 *Destructor: deallocate dynamic memory removing each book from the list
*/
template <class T>
BookList<T>::~BookList(){
	while(!isEmpty())	
		this->deleteFromHead();
}


/*
 *This method will add a new book at the beginning of the list
 *and will set head to the new book
 *@params:		
	bookTitle: the book's title to be store
	bookPlot: the book's plot to be stored
	bookAuthors: the book's authors to be stored
	bookEditor: the book's editor to be stored
	bookYear: the book's publication year to be stored
*/
template<class T>
void BookList<T>::addToHead(T bookTitle, T bookPlot, AuthorList<T> *bookAuthors, T bookEditor, int bookYear){
	//if the list isn't empty
	if (head != 0){
		BookNode<T> *temp;
		temp = new BookNode<T>(head->getPrev(), bookTitle, bookPlot, bookAuthors, bookEditor, bookYear, head);
		head->getPrev()->setNext(temp);
		head->setPrev(temp);
		head=temp;
	}else{
		//the list is empty
		head = new BookNode<T>(0, bookTitle, bookPlot, bookAuthors, bookEditor, bookYear, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

/*
 *This method will add a new book at the end of the list
 *@params:		
	bookTitle: the book's title to be store
	bookPlot: the book's plot to be stored
	bookAuthors: the book's authors to be stored
	bookEditor: the book's editor to be stored
	bookYear: the book's publication year to be stored
*/
template<class T> 	
void BookList<T>::addToTail(T bookTitle, T bookPlot, AuthorList<T> *bookAuthors, T bookEditor, int bookYear){
	//if the list is not empty
	if (head!=0){
		BookNode<T> *temp;
		temp=new BookNode<T>(head->getPrev(), bookTitle, bookPlot, bookAuthors, bookEditor, bookYear, head);
		head->getPrev()->setNext(temp);
		head->setPrev(temp);
	}else{
		//if the list is empty
		head = new BookNode<T>(0, bookTitle, bookPlot, bookAuthors, bookEditor, bookYear, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

/*
 *This method will remove the book at the front of the list
 *the head will point towards the next book
 *if there is only one book head will point to zero
*/
template<class T>
void BookList<T>::deleteFromHead(){
	//check if list is empty
	if (head !=0){
		BookNode<T> *temp;
		temp = head;
		//Check if there is only one node
		if (head == head->getNext()){
			head = 0;
		}else{ 
			head->getNext()->setPrev(head->getPrev());
			head->getPrev()->setNext(head->getNext());
			head = head->getNext();
		}
		delete temp;
	}
}

/*
 *This method will return true is booklist is empty
 *false otherwise
*/
template<class T>
bool BookList<T>::isEmpty(){
	if(head == 0)
		return true;
	else
		return false;
}

/*
 *This method will add a new book in ascending order to the list
 *the list is sorted by book title
 *@params:		
	bookTitle: the book's title to be store
	bookPlot: the book's plot to be stored
	bookAuthors: the book's authors to be stored
	bookEditor: the book's editor to be stored
	bookYear: the book's publication year to be stored
*/
template<class T>
void BookList<T>::sortInsert(T bookTitle, T bookPlot, AuthorList<T> *bookAuthors, T bookEditor, int bookYear){
	//if list is empty add node to head
	if(head == 0){
		addToHead(bookTitle, bookPlot, bookAuthors, bookEditor, bookYear);
	}else{
		BookNode<T> *temp, *temp2;
		temp = head;
		while((bookTitle > temp->getTitle()) && (temp->getNext() != head)){
			temp2 = temp;
			temp = temp->getNext();
		}
		if((temp->getNext() == head) && (bookTitle >= temp->getTitle()))
			addToTail(bookTitle, bookPlot, bookAuthors, bookEditor, bookYear);
		else{
			if((temp== head) && (bookTitle <= temp->getTitle()))
				addToHead(bookTitle, bookPlot, bookAuthors, bookEditor, bookYear);
			else{
				BookNode<T> *newNode = new BookNode<T>(temp2, bookTitle, bookPlot, bookAuthors, bookEditor, bookYear, temp);
				temp2->setNext(newNode);
				temp->setPrev(newNode);
			}
		}
	}
}

/*
 *This method will print the list
*/
template<class T>
void BookList<T>::printList(){
	BookNode<T> *temp;
	temp = head;
	//check if the list isn't empty
	if(temp != 0){
		while (temp->getNext() != head){
			cout<<"\ttitle: "<<temp->getTitle()<<endl;
			cout<<"\teditor: "<<temp->getEditor()<<endl;
			cout<<"\tyear: "<<temp->getYear()<<endl; 
			temp=temp->getNext();
		}
		cout<<"\ttitle: "<<temp->getTitle()<<endl;
		cout<<"\teditor: "<<temp->getEditor()<<endl;
		cout<<"\tyear: "<<temp->getYear()<<endl; 
	}
}

/*
 *This method will print the list in reverse order
*/
template<class T>
void BookList<T>::printRevList(){
	BookNode<T> *temp;
	temp = head;
	//check if the list isn't empty
	if(temp != 0){
		while (temp->getPrev() !=head){
			temp=temp->getPrev();
			cout<<"\ttitle: "<<temp->getTitle()<<endl;
			cout<<"\tplot: "<<temp->getPlot()<<endl;
			cout<<"\tauthors : ";
			temp->getAuthors()->printList();
			cout<<"\teditor: "<<temp->getEditor()<<endl;
			cout<<"\tyear: "<<temp->getYear()<<endl; 
		}
		cout<<"\ttitle: "<<temp->getTitle()<<endl;
		cout<<"\tplot: "<<temp->getPlot()<<endl;
		cout<<"\tauthors : ";
		temp->getAuthors()->printList();
		cout<<"\teditor: "<<temp->getEditor()<<endl;
		cout<<"\tyear: "<<temp->getYear()<<endl; 
	}
}

/*
 *This method will return a pointer to a book that mathches the search criteria
 *@params:
	-bookTitle: title of book to be searched
*/
template <class T>
BookNode<T>* BookList<T>::findBook(T bookTitle){
	BookNode<T> *book = 0;
	if(head != 0){
		BookNode<T> *temp;
		temp = head;
		while(temp->getNext() != head && temp->getTitle() != bookTitle){
			temp = temp->getNext();
		}
		if(temp->getTitle() == bookTitle)
			book = temp;
	}
	return book;
}
