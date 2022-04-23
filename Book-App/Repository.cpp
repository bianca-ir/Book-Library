#include "Repository.h"

Repository::Repository()
{
}

bool Repository::addBook(Book newBook)
{
	if (searchBook(booksList, newBook.getTitle()) != -1)
		return false;
	booksList.push_back(newBook);
	return true;
}

bool Repository::deleteBook(string givenTitle)
{
	int foundIndex = searchBook(booksList, givenTitle);
	if (foundIndex == -1)
		return false;
	booksList.erase(booksList.begin() + foundIndex);
	return true;
}

bool Repository::updateBook(Book updatedBook)
{
	int foundIndex = searchBook(booksList, updatedBook.getTitle());
	if (foundIndex == -1)
		return false;
	booksList[foundIndex] = updatedBook;
	return true;
}

int Repository::searchBook(vector<Book> givenList, string givenTitle)
{
	for (int i = 0; i < givenList.size(); ++i)
		if (givenList[i].getTitle() == givenTitle)
			return i;
	return -1;
}

vector<Book> Repository::getBooksList()
{
	return this->booksList;
}

vector<Book> Repository::getToReadList()
{
	return this->toReadList;
}

bool Repository::addBookToReadList(Book book)
{
	if (searchBook(toReadList, book.getTitle()) != -1)
		return false;
	toReadList.push_back(book);
	return true;
}

bool Repository::deleteBookFromReadList(string givenTitle)
{
	int foundIndex = searchBook(toReadList, givenTitle);
	if (foundIndex == -1)
		return false;
	toReadList.erase(toReadList.begin() + foundIndex);
	return true;
}

vector<Book> Repository::getBooksByGenre(string givenGenre)
{
	vector<Book> filteredBooks;
	vector<Book> booksList = getBooksList();
	Book book("", "", 0, "", 0, "");

	for (int i = 0; i < booksList.size(); ++i) {
		book = booksList[i];
		if (book.getGenre() == givenGenre)
			filteredBooks.push_back(book);
	}

	return filteredBooks;
}

void Repository::defaultBooks()
{
	Book b1("Charles Dickens", "A Tale of Two Cities", 1, "Pinguin Books", 1859, "Historical fiction");
	addBook(b1);

	Book b2("Antoine de Saint-Exupery", "The Little Prince", 2, "Oxford University Press", 1943, "Novel");
	addBook(b2);

	Book b3("Agatha Christie", "And then there were none", 3, "HarperCollins", 1939, "Mystery");
	addBook(b3);

	Book b4("Gabriel García Márquez", "One Hundred Years of Solitude", 3, "HarperCollins", 1967, "Magic realism");
	addBook(b4);

	Book b5("Vladimir Nabokov", "Lolita", 5, "Pearson", 1955, "Novel");
	addBook(b5);


}

