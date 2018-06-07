#include "PetsTableWidget.h"

PetsTableWidget::PetsTableWidget(Repository &r, QAbstractItemModel* model, bool isMain, QWidget *parent)
	: QWidget(parent), repo{ r }, isMainAdmin{ isMain }, tableModel{ model }
{
	if (this->objectName().isEmpty())
		this->setObjectName(QStringLiteral("PetsWidget"));
	this->resize(554, 300);
	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setSpacing(6);
	verticalLayout->setContentsMargins(11, 11, 11, 11);
	verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
	studentsTableView = new QTableView(this);
	studentsTableView->setObjectName(QStringLiteral("PetsTableView"));

	verticalLayout->addWidget(studentsTableView);


	this->setWindowTitle(QApplication::translate("PetsWidget", "PetsWidget", nullptr));

	QMetaObject::connectSlotsByName(this);
	
	this->studentsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	
	this->studentsTableView->setModel(this->tableModel);
	if (this->isMainAdmin)
	{
		this->studentsTableView->setSortingEnabled(true);
	}
	else
	{
		this->studentsTableView->hideColumn(0);
		this->studentsTableView->hideColumn(2);
	}
}

PetsTableWidget::~PetsTableWidget()
{

}
