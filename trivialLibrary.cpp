/*
 *Alexander Furones Acosta
 *S00756228
 *COMP 315 - Introduction to data structures
 *University Ana G Mendez
 *Gurabo Campus
 *School of Engineering

 *Book Library
 *This is a driver program that utilized various classes
 *and data structures to represent a collection of books
 *organized by genres
 
*/

#include <string>
#include <iostream>
#include "AuthorList.h"
#include "GenreTree.h"
using namespace std;

/*
 *This function will print the main menu
 *does not receive any parameters
 *does not return any values
*/
void printMenu(){
	cout<<"Options:"<<endl;
	cout<<"1. Add a genre"<<endl;
	cout<<"2. Add a book"<<endl;
	cout<<"3. Modify a book"<<endl;
	cout<<"4. List all genres"<<endl;
	cout<<"5. List all books by genre"<<endl;
	cout<<"6. List all books for a selected genre"<<endl;
	cout<<"7. Search for a book"<<endl;
	cout<<"8. Exit"<<endl;
}

/*
 *This function will add a new genre to the genre tree
 *it will check to see if the genre exists and only add it
 *if it doesn't exists
 *@params:
	-genres: a pointer to the genre tree
*/
template<class T>
void addGenre(GenreTree<T> *genres){
	string genre;
	cout<<"What is the genre you wish to add?"<<endl;
	cin>>genre;
	if(genres->search(genre) != 0){
		cout<<"That genre is already in the list"<<endl;	
	}else{
		BookList<string> *books = new BookList<string>();
		genres->insert(genre,books);
	}
	
}

/*
 *This function will add a new a new book to a genre
 *it will check to see if the book exists and only add it
 *if it doesn't exists it will also make sure that the user
 *selects an available genre
 *@params:
	-genres: a pointer to the genre tree
*/
template <class T>
void addBook(GenreTree<T> *genres){
	cout<<"What genre is the book of? (Write your selection)"<<endl;
	listGenres(genres);
	string userGenre;
	cin>>userGenre;
	GenreNode<T> *genre = genres->search(userGenre);
	//check if genre exists
	if(genre != 0){
		string title;
		string plot;
		string editor;
		int year;
		
		cout<<"Enter a book title"<<endl;
		cin.ignore(); //handle trailing whitespace character
		getline(cin, title);
		//check if book already exists
		BookNode<T> *exists = genre->getBooks()->findBook(title);
		if(exists == 0){
			cout<<"Enter a plot"<<endl;
			getline(cin, plot);
			cout<<"Enter a editor"<<endl;
			getline(cin, editor);
			cout<<"Enter a publication year"<<endl;
			cin>>year;
			
			AuthorList<string> *list = new AuthorList<string>();
			cout<<"What are the author(s) of the book?"<<endl;
			int addMore = 0;
			do {
				string first;
				string last;
				cout<<"Enter author's first name"<<endl;
				cin>>first;
				cout<<"Enter author's last name"<<endl;
				cin>>last;

				list->sortInsert(first, last);
				cout<<"The list is"<<endl;
				list->printList();
				cout<<"Add another author? 1 for yes, 0 for no"<<endl;
				cin>>addMore;
			} while(addMore != 0);
			
			genre->getBooks()->sortInsert(title,plot,list,editor,year);
			cout<<"Successfuly added"<<endl;
		} else {
			cout<<"That book exists already!"<<endl;
		}
	} else {
		cout<<"That genre doesn't exists. Please check your spelling or add the genre."<<endl;
	}
}

/*
 *This function will edit a book's information
 *it will check to see if the book exists and only allow edits
 *if it doesn't exists it will also make sure that the user
 *really wants to edit
 *@params:
	-genres: a pointer to the genre tree
*/
template <class T>
void editBook(GenreTree<T> *genres){
	string bookTitle;
	cout<<"What is the title of the book you want to edit?"<<endl;
	cin.ignore();
	getline(cin,bookTitle);
	BookNode<T> *book = genres->findBook(bookTitle);
	if(book != 0){
		cout<<"We found the book."<<endl;
		cout<<"The details are:"<<endl;
		cout<<"title: "<<book->getTitle()<<endl;
		cout<<"plot: "<<book->getPlot()<<endl;
		cout<<"authors : ";
		book->getAuthors()->printList();
		cout<<"editor: "<<book->getEditor()<<endl;
		cout<<"year: "<<book->getYear()<<endl; 
		
		int choice = 0;
		cout<<"Do you want to edit this book? Enter 1 for yes, 0 for no."<<endl;
		cin>>choice;
		if(choice == 1){
			string title, plot, editor, first, last;
			int year;
			AuthorList<string> *authors;		
			cout<<"What is the book title?"<<endl;
			cin.ignore();
			getline(cin, title);
			cout<<"Enter a plot"<<endl;
			getline(cin, plot);
			cout<<"Enter a editor"<<endl;
			getline(cin, editor);
			cout<<"Enter a publication year"<<endl;
			cin>>year;
			
			book->setTitle(title);
			book->setPlot(plot);
			book->setEditor(editor);
			book->setYear(year);
		}else{
			cout<<"Edit cancelled."<<endl;
		}			
	}else{
		cout<<"We couldn't find the book. Did you spell the title correctly?"<<endl;
	}
}

/*
 *This function will list all available genres
 *@params:
	-genres: a pointer to the genre tree
*/
template <class T>
void listGenres(GenreTree<T> *genres){
	cout<<"The genres are:"<<endl;
	genres->printInOrder();
	cout<<endl;
}

/*
 *This function will list all books by genre
 *@params:
	-genres: a pointer to the genre tree
*/
template <class T>
void listAllBooksByGenre(GenreTree<T> *genres){
	cout<<"Books by genre are:"<<endl;
	genres->printBooksInOrder();
	cout<<endl;
}

/*
 *This function will list all books of the selected genre
 *@params:
	-genres: a pointer to the genre tree
*/
template <class T>
void listBooksByGenre(GenreTree<T> *genres){
	cout<<"What genre do you wish to see the books of? (Write your selection)"<<endl;
	listGenres(genres);
	string userGenre;
	cin>>userGenre;
	GenreNode<T> *genre = genres->search(userGenre);
	//check that the genre was found
	if(genre != 0){
		genre->getBooks()->printList();
		cout<<endl;
	}else{
		cout<<"Error genre not found. Did you spell it corretly?"<<endl;
	}
}

/*
 *This function will search for a book
 *@params:
	-genres: a pointer to the genre tree
*/
template <class T>
void findBook(GenreTree<T> *genres){
	string bookTitle;
	cout<<"What is the title of the book you are looking for?"<<endl;
	cin.ignore();
	getline(cin,bookTitle);
	BookNode<T> *book = genres->findBook(bookTitle);
	if(book != 0){
		cout<<"We found the book."<<endl;
		cout<<"The details are:"<<endl;
		cout<<"title: "<<book->getTitle()<<endl;
		cout<<"plot: "<<book->getPlot()<<endl;
		cout<<"authors : ";
		book->getAuthors()->printList();
		cout<<"editor: "<<book->getEditor()<<endl;
		cout<<"year: "<<book->getYear()<<endl; 
			
	}else{
		cout<<"We couldn't find the book. Did you spell the title correctly?"<<endl;
	}
}

int main(int argc, char* argv[]){
	GenreTree<string> *genres = new GenreTree<string>();
	int choice = 0;
	do {
		printMenu();
		cout<<"what is your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				addGenre(genres);
				break;
			case 2:
				addBook(genres);
				break;
			case 3:
				editBook(genres);
				break;
			case 4:
				listGenres(genres);
				break;
			case 5:
				listAllBooksByGenre(genres);
				break;
			case 6:
				listBooksByGenre(genres);
				break;
			case 7:
				findBook(genres);
				break;
			case 8:
				cout<<"Goodbye!"<<endl;
				break;
			default:
				cout<<"error"<<endl;
		}
	} while(choice != 8);
	return 0;
}
