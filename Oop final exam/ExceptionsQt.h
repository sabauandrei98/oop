#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <iostream>
#include <string>
#include <qmessagebox.h>


namespace Ui {
	class ExceptionsQt;
}

class ExceptionsQt : public QMainWindow
{
	Q_OBJECT
public:
	ExceptionsQt(std::string message, QWidget *parent = 0);
};
