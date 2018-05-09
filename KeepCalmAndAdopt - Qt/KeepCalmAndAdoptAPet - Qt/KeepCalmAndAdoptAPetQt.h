#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KeepCalmAndAdoptAPetQt.h"

class KeepCalmAndAdoptAPetQt : public QMainWindow
{
	Q_OBJECT

public:
	KeepCalmAndAdoptAPetQt(QWidget *parent = Q_NULLPTR);

private:
	Ui::KeepCalmAndAdoptAPetQtClass ui;
};
