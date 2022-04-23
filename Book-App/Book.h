#pragma once
#include <assert.h>
#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 

class Book
{
private: 
	string author; 
	string title; 
	short int edition; 
	string publisher; 
	int yearPublished; 
	string genre; 

public: 
	/**
	 * .
	 * Book constructor: creates an object of type Book 
	 * Default parameters - when the constructor is called, the variables are initialized by default 
	 * \param author - author of the book 
	 * \param title - title of the book 
	 * \param edition - edition of the book 
	 * \param publisher - publisher of the book 
	 * \param yearPublished - year when the book was published
	 * \param genre - genre of the book 
	 */
	Book(const string& author = "", const string& title = "", const short int edition = 0, const string& publisher="", const int yearPublished = 0, const string& genre="" );

	/**
	 * Author getter. Returns the author of the book. 
	 */
	const string& getAuthor(); 

	/**
	* Title getter. Returns the title of the book.
	*/
	const string& getTitle(); 

	/**
	* Edition getter. Returns the edition of the book.
	*/
	const short int getEdition(); 

	/**
	* Publisher getter. Returns the publisher of the book.
	*/
	const string& getPublisher(); 

	/**
	* Year getter. Returns the year of publication of the book.
	*/
	const int getYear(); 

	/**
	* Genre getter. Returns the genre of the book.
	*/
	const string& getGenre(); 

	/**
	 * redefines the equality operator for objects of type Book.
	 * input: the other book to be compared 
	 * output: true if the books have the same title 
	 *			false otherwise 
	 */

	bool operator==(const Book& book) const; 
	
	string toString(); 
};




