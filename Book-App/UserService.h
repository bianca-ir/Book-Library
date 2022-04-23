#pragma once
#include "Repository.h"

class UserService
{
private:

	Repository repository;
public:
	/**
	 * Constructor.
	 * Creates an object of type UserService containing the given repository
	 */
	UserService(Repository repository);

	/**
	 * Returns list of books.
	 * Output: a vector of objects of type Book containing all the available items
	 */

	vector<Book> getBookListUser();

	/**
	 * Adds an item to the to-read booklist.
	 * Output: true if item was successfully added, false otherwise
	 */

	bool addBookToReadListUser(Book book);

	/**
	* Deletes an item to the to-read booklist.
	* Output: true if item was successfully deleted, false otherwise
	*/

	bool deleteBookToReadListUser(string givenTitle);

	/**
	 * Returns list of to-read booklist.
	 * Output: a vector of objects of type Book containing current to-read books
	 */
	vector<Book> getToReadListUser();

	/**
	 * Returns list of books, filtered by genre.
	 * Output: a vector of objects of type Book, filtered
	 */

	vector<Book> getBooksByGenreUser(string givenGenre);



};

