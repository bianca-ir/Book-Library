#include <QtWidgets/QApplication>
#include "GUI.h"
#include "BooksApp.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    Repository repository; 
    repository.defaultBooks(); 
    AdminService adminService{ repository }; 
    UserService userService{ repository }; 

    GUI gui{ adminService, userService }; 

    gui.show(); 
   

    return a.exec();
}
