#ifndef QPROJECTTREEMODEL_H
#define QPROJECTTREEMODEL_H

#include <QtCore/QAbstractItemModel>

#include "cproject.h"

class QProjectTreeModel:public QAbstractItemModel {
    Q_OBJECT
public:
    QProjectTreeModel(QObject* parent_,CProject* project_);
    ~QProjectTreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:

    CProject* project;
};


#endif // QPROJECTTREEMODEL_H
