#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <qfont.h>
#include <qlabel.h>
#include <qevent.h>
#include <qkeyeventtransition.h>
#include "UserService.h"
#include "AdminService.h"

class GUI : public QListWidget
{
private: 
	char mode; 

	UserService& userService; 
	AdminService& adminService; 
	QListWidget* booksListWidget, * toReadListWidget; 
	QLineEdit* authorLine, * titleLine, * editionLine, * publisherLine, * yearLine, * genreLine; 
	QPushButton* addButton, * removeButton, * updateButton, * listButton, * filterButton, * removeReadButton, * modeButton; 

public: 
	GUI(AdminService& adminService, UserService& userService); 

private: 
	void initGUI(); 
	void populateList(); 
	void makeConnections(); 

	int getSelectedIndex(); 
	void addBookGUI(); 
	void updateBookGUI(); 
	void removeBookGUI(); 


};

