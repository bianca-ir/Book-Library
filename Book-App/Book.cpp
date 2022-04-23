#include "Book.h"



Book::Book(const string& author, const string& title, const short int edition, const string& publisher, const int yearPublished, const string& genre)
{
	this->author = author; 
	this->title = title; 
	this->edition = edition; 
	this->publisher = publisher; 
	this->yearPublished = yearPublished; 
	this->genre = genre;
}

const string& Book::getAuthor() {
	return this->author; 
}

const string& Book::getTitle()
{
	
	return this->title; 
}

const short int Book::getEdition()
{
	return this->edition; 
}

const string& Book::getPublisher()
{
	
	return this->publisher; 
}

const int Book::getYear()
{
	return this->yearPublished; 
}

const string& Book::getGenre()
{
	return this->genre; 
}

bool Book::operator==(const Book& book) const
{
	return (this->title == book.title); 
}

string Book::toString()
{
	return this->author + ", " + this->title + ", " + to_string(this->edition) + ", " + this->publisher + ", " + to_string(this->yearPublished) + ", " +  this->genre; 
}




