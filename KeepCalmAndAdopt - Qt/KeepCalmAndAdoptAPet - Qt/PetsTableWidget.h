#ifndef STUDENTSWIDGET_H
#define STUDENTSWIDGET_H
#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Repository.h"

class PetsTableWidget : public QWidget
{
	Q_OBJECT

public:
	PetsTableWidget(Repository &r, QAbstractItemModel* model, bool isMain = false, QWidget *parent = 0);
	~PetsTableWidget();

	QVBoxLayout *verticalLayout;
	QTableView *studentsTableView;

private:

	Repository& repo;

	bool isMainAdmin;	// specifies if this is the widget for the main teacher
	std::string group;  // if the dialog is NOT for the main teacher, show only the specific group
	QAbstractItemModel* tableModel;
};
#endif // STUDENTSWIDGET_H

