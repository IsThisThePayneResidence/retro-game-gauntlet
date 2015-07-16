#include "qtablemodel.h"

#include <QStringListModel>

QTableModel::QTableModel(int _rows, int _columns, QObject* _parent) :
    QAbstractTableModel(_parent),
    rows(_rows),
    columns(_columns)
{
}



QTableModel::~QTableModel()
{

}

QVariant QTableModel::data(const QModelIndex &_index, int _role) const
{
    if(!_index.isValid())
        return QVariant();
    QString str = QString("%1,%2").arg(_index.row() + 1).arg(_index.column() + 1);
    return (_role == Qt::DisplayRole || _role == Qt::EditRole ? hash.value(_index, QVariant(str)) : QVariant());
}

bool QTableModel::setData(const QModelIndex &_index, const QVariant &_value, int _role)
{
    if(_index.isValid() && _role == Qt::EditRole)
    {
        hash[_index] = _value;
        emit dataChanged(_index, _index);
        return true;
    }
    return false;
}

int QTableModel::rowCount(const QModelIndex &) const
{
    return rows;
}

int QTableModel::columnCount(const QModelIndex &) const
{
    return columns;
}

Qt::ItemFlags QTableModel::flags(const QModelIndex &_index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(_index);
    return _index.isValid() ? (flags | Qt::ItemIsEditable) : flags;
}

QStringList QTableModel::toStringList()
{
    QStringList values;
    for(int i = 0; i < this->rowCount(); i++)
        for(int j = 0; j < this->columnCount(); j++)
            values << this->data(this->index(i, j), Qt::EditRole).toString();
    return values;
}

