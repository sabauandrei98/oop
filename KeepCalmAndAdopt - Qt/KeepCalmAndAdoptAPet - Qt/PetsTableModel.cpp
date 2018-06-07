#include "PetsTableModel.h"
#include <qbrush.h>
#include <qcolor.h>

PetsTableModel::~PetsTableModel()
{
}

int PetsTableModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getSize();
}

int PetsTableModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant PetsTableModel::data(const QModelIndex & index, int role) const
{
	Dog currentDog = this->repo.getDynamicArray().getAllElems()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		
			return QString::fromStdString(currentDog.getBreed());
		case 1:		
			return QString::fromStdString(currentDog.getName());
		case 2:		
			return QString::number(currentDog.getAge());
		case 3:		
			return QString::fromStdString(currentDog.getPhotograph());
		default:
			break;
		}
	}

	return QVariant();
}

QVariant PetsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Breed" };
			case 1:
				return QString{ "Name" };
			case 2:
				return QString{ "Age" };
			case 3:
				return QString{ "Photograph" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool PetsTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	Dog& currentDog = this->repo.getDynamicArray().getAllElems()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
		{
		}
		case 1:
			break;
		case 2:
			break;
		case 3:
		{
			currentDog.setPhotograph(value.toString().toStdString());
		}
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags PetsTableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 || col == 1 || col == 2)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}
