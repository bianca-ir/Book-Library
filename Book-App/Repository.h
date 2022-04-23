#pragma once
#include "Book.h"

class Repository
{
private:
	vector<Book> booksList = {};
	vector<Book> toReadList = {};
public:
	/**
	 * Repository constructor.
	 * Creates an object of type Repository
	 */
	Repository();

	/**
	 * Adds a new item to the list.
	 * Output: true if the book was successfully added, false otherwise
	 */

	bool addBook(Book newBook);

	/**
	 * Deletes an item from the list.
	 * Output: true if the book was successfully deleted, false otherwise
	 */
	bool deleteBook(string givenTitle);

	/**
	 * Updates an item with the given parameter.
	 * Output: true if the book was successfully updated, false otherwise
	 */
	bool updateBook(Book updatedBook);

	/**
	 * Searches an item within the list.
	 * Output: position of the desired book in the list
	 */
	int searchBook(vector<Book> givenList, string givenTitle);

	/**
	 * Returns the list.
	 * Output: a vector of objects of type Book
	 */
	vector<Book> getBooksList();

	/**
	 * Returns the user to-read booklist.
	 * Output: a vector of objects of type Book
	 */

	vector<Book> getToReadList();

	/**
	 * Adds a new item to the user to-read booklist.
	 * Output: true if the book was successfully added, false otherwise
	 */

	bool addBookToReadList(Book book);

	/**
	 * Deletes an item from the user to-read booklist.
	 * Output: true if the book was successfully deleted, false otherwise
	 */

	bool deleteBookFromReadList(string givenTitle);

	/**
	 * Returns a list of items filtered by genre.
	 * Output: a vector of objects of type Book, filtered
	 */
	vector<Book> getBooksByGenre(string givenGenre);

	/**
	 * Initializes the list with some default items.
	 */

	void defaultBooks();
};




