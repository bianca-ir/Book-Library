#include "GUI.h"

GUI::GUI(AdminService& adminService, UserService& userService) : adminService{ adminService }, userService{ userService }
{
	this->initGUI(); 
	this->populateList(); 
	this->makeConnections(); 
}

void GUI::initGUI()
{
	booksListWidget = new QListWidget{}; 

	authorLine = new QLineEdit{}; 
	titleLine = new QLineEdit{};
	editionLine = new QLineEdit{};
	publisherLine = new QLineEdit{};
	yearLine = new QLineEdit{};
	genreLine = new QLineEdit{};

	addButton = new QPushButton{ "Add" }; 
	removeButton = new QPushButton{ "Remove" }; 
	updateButton = new QPushButton{ "Update" }; 

	QVBoxLayout* mainLayout = new QVBoxLayout{ this }; 
	mainLayout->addWidget(booksListWidget); 

	QFormLayout* formLayout = new QFormLayout{}; 
	formLayout->addRow("Author", authorLine); 
	formLayout->addRow("Title", titleLine);
	formLayout->addRow("Edition", editionLine);
	formLayout->addRow("Publisher", publisherLine);
	formLayout->addRow("Year", yearLine); 
	formLayout->addRow("Genre", genreLine);
	mainLayout->addLayout(formLayout); 

	QGridLayout* buttonsLayout = new QGridLayout{}; 
	buttonsLayout->addWidget(addButton, 0, 0); 
	buttonsLayout->addWidget(removeButton, 0, 1); 
	buttonsLayout->addWidget(updateButton, 0, 2); 
	mainLayout->addLayout(buttonsLayout); 





}

void GUI::populateList()
{
	booksListWidget->clear(); 

	vector<Book> booksList = adminService.getBooksListAdmin(); 

	for (int i = 0; i < booksList.size(); ++i)
		booksListWidget->addItem(QString::fromStdString(booksList[i].toString())); 
}

void GUI::makeConnections()
{
	QObject::connect(booksListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = getSelectedIndex();
		if (selectedIndex == -1)
			return;
		vector<Book> booksList = adminService.getBooksListAdmin();
		Book selectedBook = booksList[selectedIndex];
		authorLine->setText(QString::fromStdString(selectedBook.getAuthor()));
		titleLine->setText(QString::fromStdString(selectedBook.getTitle()));
		editionLine->setText(QString::fromStdString(to_string(selectedBook.getEdition())));
		publisherLine->setText(QString::fromStdString(selectedBook.getPublisher()));
		yearLine->setText(QString::fromStdString(to_string(selectedBook.getYear())));
		genreLine->setText(QString::fromStdString(selectedBook.getGenre()));

		}); 

		QObject::connect(addButton, &QPushButton::clicked, this, &GUI::addBookGUI); 
		QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::updateBookGUI);
		QObject::connect(removeButton, &QPushButton::clicked, this, &GUI::removeBookGUI);


		
}

int GUI::getSelectedIndex()
{
	QModelIndexList selectedIndexes = booksListWidget->selectionModel()->selectedIndexes(); 
	if (selectedIndexes.size() == 0)
		return -1; 
	int selectedIndex = selectedIndexes.at(0).row(); 
	return selectedIndex; 
}

void GUI::addBookGUI()
{
	string author, title, publisher, genre; 
	short int edition; 
	int year; 

	author = authorLine->text().toStdString(); 
	title = titleLine->text().toStdString(); 
	edition = editionLine->text().toInt(); 
	publisher = publisherLine->text().toStdString(); 
	year = yearLine->text().toInt();
	genre = genreLine->text().toStdString(); 

	bool ok = adminService.addBookAdmin(author, title, edition, publisher, year, genre); 
	if (ok == false) {
		QMessageBox::critical(this, "Error!", "Book already exists."); 
		return;
	}

	else {
		this->populateList(); 
		vector<Book> booksList = adminService.getBooksListAdmin(); 
		booksListWidget->setCurrentRow(booksList.size() - 1); 
	}

}

void GUI::updateBookGUI()
{
	string author, title, publisher, genre;
	short int edition;
	int year;

	author = authorLine->text().toStdString();
	title = titleLine->text().toStdString();
	edition = editionLine->text().toInt();
	publisher = publisherLine->text().toStdString();
	year = yearLine->text().toInt();
	genre = genreLine->text().toStdString();

	bool ok = adminService.updateBookAdmin(author, title, edition, publisher, year, genre);
	if (ok == false) {
		QMessageBox::critical(this, "Error!", "Book already exists.");
		return;
	}

	else {
		this->populateList(); 
		vector<Book> booksList = adminService.getBooksListAdmin();
		for (int i = 0; i < booksList.size(); ++i) {
			if (booksList[i].getTitle() == title) {
				booksListWidget->setCurrentRow(i); 
				return; 
			}
		}
		
	}

}

void GUI::removeBookGUI()
{
	string title; 

	title = titleLine->text().toStdString(); 

	bool ok = adminService.deleteBookAdmin(title);
	if (ok == false) {
		QMessageBox::critical(this, "Error!", "Book does not exist.");
		return;
	}

	else {
		this->populateList();
		return; 
	}

	
}
