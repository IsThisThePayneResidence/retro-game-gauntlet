#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>

class QStringListModel;

class QTableModel : public QAbstractTableModel
{
private:
    int rows;
    int columns;
    QHash<QModelIndex, QVariant> hash;
public:
    QTableModel(int _rows, int _columns, QObject* _parent = nullptr);
    ~QTableModel();
    QVariant data(const QModelIndex& _index, int _role) const;
    bool setData(const QModelIndex& _index, const QVariant& _value, int _role);
    int rowCount(const QModelIndex& = QModelIndex()) const;
    int columnCount(const QModelIndex& = QModelIndex()) const;
    Qt::ItemFlags flags(const QModelIndex& _index) const;
    QStringList toStringList();
};

#endif // QTABLEMODEL_H
