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
	bool remove(T g); //removes the first genre node that matches and returns a boolean of success
	GenreNode<T>* search(T g); //return the first genre node that matches
	bool isEmpty(); //returns true if tree is empty, false otherwise
	void printInOrder(); //Prints inorder the tree
	void printBooksInOrder(); //Prints all books inorder
	void printPreOrder(); //Prints in preorder the tree
	void printPostOrder(); //Prints in postorder the tree
	BookNode<T>* findBook(T); //Finds a book in the tree
private:
	GenreNode<T> *root; //A pointer to the first node
	void visitInOrder(GenreNode<T> *node);//Recursive support method for printInOrder
	void visitBooksInOrder(GenreNode<T> *node); //Recursive support method for printBooksInOrder();
	void visitPreOrder(GenreNode<T> *node);//Recursive support method for printPreOrder
	void visitPostOrder(GenreNode<T> *node);//Recursive support method for printPostOrder
	void removePostOrder(GenreNode<T>* node);//Recursive support method for the destructor
	GenreNode<T>* recursiveSearch(GenreNode<T> *node, T g);//Recursive support method for search
	GenreNode<T>* recursiveBookSearch(GenreNode<T> *node, T g);//Recursive support method for search
	bool recursiveSearchForRemove(GenreNode<T> *node, T g);//Recursive support method for remove
	GenreNode<T>* findLowest(GenreNode<T> *node);//Extract the lowest node in a subtree rooted on node
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

//This is a helper function to traverse the tree in pre order
template <class T>
void GenreTree<T>::visitPreOrder(GenreNode<T> *node){
	if(node != 0){
		cout<<"-"<<node -> getGenre()<<"-";
		visitPreOrder(node -> getLeft());
		visitPreOrder(node -> getRight());	
	}	
}

//This is a helper function to traverse the tree in post order
template <class T>
void GenreTree<T>::visitPostOrder(GenreNode<T> *node){
	if(node != 0) {
		visitPostOrder(node -> getLeft());
		visitPostOrder(node -> getRight());
		cout<<"-"<<node -> getGenre()<<"-";
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

//This function will print the tree in pre order
template <class T>
void GenreTree<T>::printPreOrder(){
	visitPreOrder(root);
}

//This function will print the tree in post order
template <class T>
void GenreTree<T>::printPostOrder(){
	visitPostOrder(root);
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

//This function will remove a node from the tree
//it will return true if it succeded and false otherwise
//it will receive as a parameter a value val of type t to be removed
//it will remove the first found instance
template <class T>
bool GenreTree<T>::remove(T val){
	bool erased = false;
	//make sure the tree isnt empty
	if(root != 0){
		//check if root is the value to be removed
		if(root -> getGenre() == val){
			//check if root is the only node
			if(root -> getLeft() == 0 && root -> getRight() == 0){
				//delete root and set pointer to zero
				delete root;
				root = 0;
			} else {
				//root has children
				GenreNode<T> *temp;
				temp = root;
				//check if root has no left child
				if(root -> getLeft() == 0){
					//root should now be right child
					root = root -> getRight();
				} else if(root -> getRight() == 0){
					//root has no right child
					//root should now be left child
					root = root -> getLeft();
				} else {
					//root has left and right children
					//must find the lowest of all the greater children
					GenreNode<T> *low = findLowest(root -> getRight());
					//check if the right child happens to be the lowest
					if(root -> getRight() == low) {
						//set left of lowest to be equal to left of root
						low -> setLeft(root -> getLeft());
						//root should now be lowest
						root = low;
					} else {
						//right child is not the lowest
						//root should be lowest
						root = low;
						//set left child of root equal to left of temp
						root -> setLeft(temp -> getLeft());
						//set right of root to be equal to right of temp
						root -> setRight(temp -> getRight());
					}
				}
				delete temp;				
			}
			erased = true;
		} else {
			//the node to be removed is not the root
			//use recursive search to remove node
			erased = recursiveSearchForRemove(root, val);
		}
	}
	return erased;	
}

//This function will find the lowest child of all greater children
//and return a pointer to that node
//it receives as a parameter a root node of a tree or subtree
template <class T>
GenreNode<T>* GenreTree<T>::findLowest(GenreNode<T> *node) {
	GenreNode<T> *temp;
	//check if there is no left child
	if (node->getLeft()==0) {
		//lowest must be node
		temp=node;
	} else { 
		//lowest must be leftward
		//while grandchild is not zero move one level down
		while(node->getLeft()->getLeft()!=0)
			node=node->getLeft();
		temp=node->getLeft();
		//adjust left child of node to be the right node
		//because node will not become a root of a subtree
		node->setLeft(temp->getRight());
	}
	return temp;
}

//This function will recurse through the tree looking for a node with val
//it will match the first instance and delete that node
//it will return true if successful and false otherwise
//it receives as a parameter a root to a tree or subtree
template <class T>
bool GenreTree<T>::recursiveSearchForRemove(GenreNode<T> *node, T val){
	bool erased = false;
	GenreNode<T> *temp, *found;
	//check that root has left children and that val is less than root
	if(node -> getLeft() != 0 && node -> getGenre() > val) {
		//check if value could be at the left
		//check if left child is the desired node
		if(node -> getLeft() -> getGenre() == val) {
			//left child is desired node
			found = node -> getLeft();
			//check if node has no right child
			if(found -> getRight() == 0){
				//set node left child to found's right child
				node -> setLeft(found -> getLeft());
			} else {
				//node has right children
				//find the lowest of greater children of node
				temp = findLowest(found -> getRight());
				//set left of node equal to temp
				node -> setLeft(temp);
				//set left child of temp equal to left of found
				temp -> setLeft(found -> getLeft());
				//check that temp wasnt the lowest of greater children
				if(temp != found -> getRight()){
					//adjust right of temp to be right of found
					temp -> setRight(found -> getRight());
				}
			}
			delete found;
			erased = true;
		} else {
			//recursive search towards the left searching for the desired node
			erased = recursiveSearchForRemove(node -> getLeft(), val);
		}
	} else if (node -> getRight() != 0 && node -> getGenre() < val) {
		//if node has right children and val is larger that root val
		//check if right child is the desired node
		if(node -> getRight() -> getGenre() == val){
			//then desired node is the right child
			found = node -> getRight();
			//Check if found has no right children
			if(found -> getRight() == 0) {
				node -> setRight(found -> getLeft());
			} else {
				//find lowest of greates children to become new root
				temp = findLowest(found -> getRight());
				//set right of node to be temp
				node -> setRight(temp);
				//set left of temp equal to left of found
				temp -> setLeft(found -> getLeft());
				//check if temp wasnt the lowest of greater children
				if(temp != found -> getRight()){
					temp -> setRight(found -> getRight());
				}
			}
			delete found;
			erased = true;
		} else {
			//recursively search the right for the desired node
			erased = recursiveSearchForRemove(node -> getRight(), val);
		}
	}
	return erased;
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
