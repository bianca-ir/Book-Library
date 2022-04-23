#include "AdminService.h"

AdminService::AdminService(Repository repository)
{
	this->repository = repository;
}

bool AdminService::addBookAdmin(string author, string title, short int edition, string publisher, int year, string genre)
{
	Book newBook(author, title, edition, publisher, year, genre);
	return repository.addBook(newBook);
}

bool AdminService::deleteBookAdmin(string givenTitle)
{
	return repository.deleteBook(givenTitle);
}

bool AdminService::updateBookAdmin(string author, string title, short int edition, string publisher, int year, string genre)
{
	Book newBook(author, title, edition, publisher, year, genre);
	return repository.updateBook(newBook);
}

vector<Book> AdminService::getBooksListAdmin()
{
	return repository.getBooksList();
}
