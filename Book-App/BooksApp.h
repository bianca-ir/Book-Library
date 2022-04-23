#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BooksApp.h"

class BooksApp : public QMainWindow
{
    Q_OBJECT

public:
    BooksApp(QWidget* parent = Q_NULLPTR);

private:
    Ui::BooksAppClass ui;
};
