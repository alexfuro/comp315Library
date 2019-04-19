/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Author linked list
 *This class implements a singly linked list for authors using templates
 *Each list has two attributes:
	-head: first author in the list
	-tail: last author in the list

 *Considerations:
	1. If the list is empty head and tail point to zero
	2. The next of tail will be zero
*/

/*
 *Inlcude author node file
*/
#include "AuthorNode.h"

/*
 *Class Declaration
*/
template <class T>
class AuthorList{
public:
	AuthorList(); //Default constructor - creates an empty author list	
	~AuthorList(); //Destructor: deallocate dynamic memory used
	void addToHead(T first, T last); //Adds author to the beginning of list and sets head to new author
	void addToTail(T first, T last); //Adds author to the end of list and sets tail to new author
	void deleteFromHead(); //Removes author at head, sets head to next author, if only one author head and tail point to zero
	void deleteFromTail(); //Removes author at tail, sets tail to previous author, if only one author head and tail point to zero
	bool isEmpty(); //If the list is empty return true, otherwise return false
	void sortInsert(T first, T last); //creates a new author node and inserts it sorted alphabetically by last name
	void printList(); //prints all authors in the list
private:
	AuthorNode<T> *head; //A pointer to the first node
	AuthorNode<T> *tail; //A pointer to the last node
};

/*
 *Default constructor: creates an empty author list
 *set head and tail to point to zero
*/
template <class T>
AuthorList<T>::AuthorList(){
	head = tail = 0;
}

/*
 *Destructor: deallocate dynamic memory by removing each author from the list
*/
template <class T>
AuthorList<T>::~AuthorList(){
	while(head != 0)
		deleteFromHead();
}

/*
 *This method will add a new author at the begging of the list and 
 *set head to that new author
 *@params:
	first: first name
	last: last name
*/
template <class T>
void AuthorList<T>::addToHead(T first, T last){
	//create a new author and set head to the new author
	//and next of head to the previous location of head
	head = new AuthorNode<T>(first, last, head);
	//if the list was empty then tail will be pointing to 0
	if(tail == 0){
		//update tail to point to the new author
		tail = head;
	}
}

/*
 *This method will add a new author at the end of the list and 
 *set tail to that new author
 *@params:
	first: first name
	last: last name
*/
template <class T>
void AuthorList<T>::addToTail(T first, T last){
	//if the list isnt empty then set the next of tail to 
	//a new author and set tail to point towards new author
	if(tail != 0){
		tail->setNext(new AuthorNode<T>(first, last, 0));
		tail = tail->getNext();
	} else {
		//if list is empty then create a new author
		//and point both head and tail to the new author
		head = tail = new AuthorNode<T>(first, last, 0);
	}
}

/*
 *This method will remove the author at the head of the list
 *and will set head to the next author
*/
template <class T>
void AuthorList<T>::deleteFromHead(){
	//check if the list isn't empty
	if(head!=0){
		//create a temporary pointer to an author
		//and set it to point at the same node as head
		AuthorNode<T> *temp;
		temp = head;
		//set head equals to the next author
		head = head->getNext();
		//if head now points to null set tail to null as well
		if(head == 0){
			tail = 0;
		}
		//delete node at temp position
		delete temp;
	}
}

/*
 *This method will remove the author at the tail of the list
 *and will set tail to the previous author
*/
template <class T> 
void AuthorList<T>::deleteFromTail(){
	//Check if the list isn't empty
	if(head != 0){
		//create a temporary pointer to a node
		//and set it to point at the same node as head
		AuthorNode<T> *temp;
		temp = head;
		//check if the list has only one node
		if(head != tail){
			//move until temp's next is tail
			while(temp->getNext() != tail){
				temp = temp->getNext();
			}
			//set tail to temp
			tail = temp;
			//move to temp last node
			temp = temp->getNext();
			//set next of tail to null
			tail->setNext(0);
		}else {
			//if there was only one node then set head
			//and tail to point to null
			head = tail = 0;
		}
		//delete that node
		delete temp;
	}
}

/*
 *This method will add a new author alphabetically sorted
 *by last name
 *@params:
	first: first name
	last: last name
*/
template <class T>
void AuthorList<T>::sortInsert(T first, T last){
	//Check if the list is empty, if so add a new author
	if(head == 0){
		addToHead(first, last);
	}else {
		//if the list inst empty create two pointers to authors
		AuthorNode<T> *curr,*prev;
		curr = head;
		//keep moving both pointers until the value of the current node
		//is greater than the @param last and the first pointer isn't equal
		//to tail
		while((last > curr->getLName()) && (curr != tail)){
			prev = curr;
			curr = curr->getNext();
		}
		//if the first pointer is equal to tail and the @param last is more than
		//the value at tail add a new node with lName last at the end of list
		if((curr == tail) && (last > curr->getLName())){
			addToTail(first, last);
		}else{
			//if the first pointer is at head and the @param last is less
			//than the value at that node then add a new author at the beginning
			//of the list
			if((curr == head) && (last < curr->getLName())){
				addToHead(first, last);
			}else {
				//else the sorted position is somewhere in between head
				//and the tail
				//create a new node that will follow the node at the 
				//second pointer and its next will be the node at the first pointer
				prev->setNext(new AuthorNode<T>(first, last, curr));
			}
		}
	}
}

/*
 *This method will print the list
*/
template <class T>
void AuthorList<T>::printList(){
	AuthorNode<T> *curr;
	curr = head;
	while(curr != 0){
		cout<<curr->getLName()<<",";
		cout<<curr->getFName()<<" - ";
		curr = curr->getNext();
	}
}

/*
 *This method will determine if the list is empty
 *if empty will return true, false otherwise
*/
template <class T>
bool AuthorList<T>::isEmpty(){
	if(head == 0)
		return true;
	else
		return false;
}
