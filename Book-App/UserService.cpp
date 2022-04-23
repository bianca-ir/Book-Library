#include "UserService.h"

UserService::UserService(Repository repository)
{
	this->repository = repository;
}

vector<Book> UserService::getBookListUser()
{
	return this->repository.getBooksList();
}

bool UserService::addBookToReadListUser(Book book)
{
	return this->repository.addBookToReadList(book);
}

bool UserService::deleteBookToReadListUser(string givenTitle)
{
	return this->repository.deleteBookFromReadList(givenTitle);
}

vector<Book> UserService::getToReadListUser()
{
	return this->repository.getToReadList();
}

vector<Book> UserService::getBooksByGenreUser(string givenGenre)
{
	return this->repository.getBooksByGenre(givenGenre);
}
