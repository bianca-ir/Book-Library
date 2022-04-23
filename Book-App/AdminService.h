#pragma once
#include "Repository.h"
class AdminService
{
private:
	Repository repository;
public:

	/**
	 * Constructor.
	 * Creates an object of type AdminService, containing the repository
	 */
	AdminService(Repository repository);

	/**
	 * Adds a book to the admin booklist.
	 * Output: true if book was successfully added, false otherwise
	 */

	bool addBookAdmin(string author, string title, short int edition, string publisher, int year, string genre);


	/**
	 * Deletes a book from the admin booklist.
	 * Output: true if book was successfully deleted, false otherwise
	 */
	bool deleteBookAdmin(string givenTitle);

	/**
	 * Updates a book from the admin booklist, with all attributes.
	 * Output: true if book was successfully updated, false otherwise
	 */

	bool updateBookAdmin(string author, string title, short int edition, string publisher, int year, string genre);


	/**
	 * Returns the admin booklist.
	 * Output: a vector of objects of type Book
	 */
	vector<Book> getBooksListAdmin();
};

