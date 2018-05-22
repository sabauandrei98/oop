#include "ExceptionsQt.h"
#include <QCoreApplication>

ExceptionsQt::ExceptionsQt(std::string message, QWidget *parent)
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Message!");
	QString str = QString::fromStdString(message);
	msgBox.setText(str);
	msgBox.exec();
}