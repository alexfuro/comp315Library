/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Genre Binary Search Tree
 *This class implements a Genre Binary Search Tree using templates
 *Each tree has one attribute:
	-root: is a pointer to the first genre of the tree

 *Considerations:
	1. if the tree is empty root points to zero

******************/

/*
 *include necesarry libraries 
 *and set name space
*/
#include "GenreNode.h"
template <class T>
class GenreTree{
public:
	GenreTree(); //Default constructor: creates an empty genre tree
	~GenreTree(); //Destructor: deallocate dynamic memory 
	void insert(T g, BookList<T> *); //insert(T val): creates a new node with val as info,
	GenreNode<T>* search(T g); //return the first genre node that matches
	bool isEmpty(); //returns true if tree is empty, false otherwise
	void printInOrder(); //Prints inorder the tree
	void printBooksInOrder(); //Prints all books inorder
	BookNode<T>* findBook(T); //Finds a book in the tree
private:
	GenreNode<T> *root; //A pointer to the first node
	void visitInOrder(GenreNode<T> *node);//Recursive support method for printInOrder
	void visitBooksInOrder(GenreNode<T> *node); //Recursive support method for printBooksInOrder();
	void removePostOrder(GenreNode<T>* node);//Recursive support method for the destructor
	GenreNode<T>* recursiveSearch(GenreNode<T> *node, T g);//Recursive support method for search
	GenreNode<T>* recursiveBookSearch(GenreNode<T> *node, T g);//Recursive support method for search
};

/*
 *Default constructor: creates an empty Binary Search tree
*/
template <class T>
GenreTree<T>::GenreTree()
{
	root = 0;
}

/*
 *Destructor: free dynamic memory
*/
template <class T>
GenreTree<T>::~GenreTree(){
	removePostOrder(root);
}

/*
 *this method is a helper funciton for the destructor
*/
template <class T>
void GenreTree<T>::removePostOrder(GenreNode<T> *node){
	if(node != 0){
		removePostOrder(node -> getLeft());
		removePostOrder(node -> getRight());
		delete node;
	}
}


/*
 *this method will insert a new genre node
 *@params:		
	g: the genre's name to be stored
	b: the genre's books to be stored
*/
template <class T>
void GenreTree<T>::insert(T g, BookList<T> *b){
		if(root == 0){
			root = new GenreNode<T>(0,g,b,0);
		} else {
			GenreNode<T> *prev, *curr;
			curr = root;
			while(curr != 0){
				prev = curr;
				if(curr -> getGenre() > g){
					curr = curr -> getLeft();
				} else {
					curr = curr -> getRight();
				}
			}
			if (prev -> getGenre() > g){
				prev -> setLeft(new GenreNode<T>(0,g,b,0));
			}else{
				prev -> setRight(new GenreNode<T>(0,g,b,0));
			}
		}
		
}

/*
 *This method determines if the tree is empty
 *return true is its empty, false otherwise
*/
template <class T>
bool GenreTree<T>::isEmpty(){
	if(root == 0){
		return true;
	}
	return false;
}

//This is a helper function to traverse the tree in order
template <class T>
void GenreTree<T>::visitInOrder(GenreNode<T> *node){
	if(node != 0) {
		visitInOrder(node -> getLeft());
		cout<<"-"<<node -> getGenre() <<"-";		
		visitInOrder(node -> getRight());
	}
}

//This is a helper function to traverse the tree's books in order
template <class T>
void GenreTree<T>::visitBooksInOrder(GenreNode<T> *node){
	if(node != 0) {
		visitBooksInOrder(node -> getLeft());
		cout<<"-"<<node -> getGenre() <<"-"<<endl;
		node->getBooks()->printList();
		visitBooksInOrder(node -> getRight());
	}
}

//This function will print the tree in order
template <class T>
void GenreTree<T>::printInOrder(){
	visitInOrder(root);
}

//This function will print the tree's books in order
template <class T>
void GenreTree<T>::printBooksInOrder(){
	visitBooksInOrder(root);
}

/*
 *this method will traverse the tree in search for a genre node
 *that matches the given parameter
 *returns a pointer to the matched node or zero if not found
 *@params:		
	g: the genre's name to be found
*/
template <class T>
GenreNode<T>* GenreTree<T>::search(T g){
	return recursiveSearch(root,g);
}

//This is a helper function to find a node with value val
//it will recurse through the tree until it either finds the node
//or will return 0 if it does not find it
//it receives via parameters a node and a val to search for
template <class T>
GenreNode<T>* GenreTree<T>::recursiveSearch(GenreNode<T> *node, T val){
	GenreNode<T> *result = 0;
	if(node != 0){
		if(node -> getGenre() == val)
			result = node;
		else if(node -> getGenre() > val) 
			result = recursiveSearch(node -> getLeft(),val);
		else 
			result = recursiveSearch(node -> getRight(),val);
	}
	return result;
}

/*
 *this method will traverse the tree in search for a book node
 *that matches the given parameter
 *returns a pointer to the matched book node or zero if not found
 *@params:		
	bookTitle: the genre's name to be found
*/
template <class T>
BookNode<T>* GenreTree<T>::findBook(T bookTitle){
	GenreNode<T> *temp = recursiveBookSearch(root, bookTitle);
	if(temp != 0){
		return temp->getBooks()->findBook(bookTitle);
	}
	return 0;
}

/*
 *this is a helper method to find a book node within the genre tree
 *@params:		
	node: a pointer to a genre node to be searched
	bookTitle: the genre's name to be found
*/
template <class T>
GenreNode<T>* GenreTree<T>::recursiveBookSearch(GenreNode<T> *node, T bookTitle){
	GenreNode<T> *temp = 0;
	if(node != 0){
		temp = node;
		if(temp->getBooks()->findBook(bookTitle) != 0){
			return temp;
		}
		temp = recursiveBookSearch(node->getLeft(), bookTitle);
		if(temp != 0 && temp->getBooks()->findBook(bookTitle) != 0){
			return temp;
		}
		temp = recursiveBookSearch(node->getRight(), bookTitle);
		if(temp != 0 && temp->getBooks()->findBook(bookTitle) != 0){
			return temp;
		}

	}
	return temp;
}
