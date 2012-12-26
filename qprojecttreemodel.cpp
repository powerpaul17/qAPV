#include "qprojecttreemodel.h"

QProjectTreeModel::QProjectTreeModel(QObject* parent_,CProject* project_):QAbstractItemModel(parent_) {
    project=project_;
}

QProjectTreeModel::~QProjectTreeModel() {

}

QModelIndex QProjectTreeModel::index(int row,int column,const QModelIndex& parent) const {
//	if(!hasIndex(row,column,parent)) return QModelIndex();
    if(project!=0) {
        CObject* obj=0;
        if(!parent.isValid()) {
            obj=project;
        } else {
            obj=static_cast<CObject*>(parent.internalPointer());
        }
        if(obj==0) return QModelIndex();
        obj=obj->getChild(row);
        if(obj!=0) {
            return createIndex(row,column,obj);
        } else {
            return QModelIndex();
        }
    } else {
        return QModelIndex();
    }
}

QModelIndex QProjectTreeModel::parent(const QModelIndex& index) const {
    if(!index.isValid()) {
        return QModelIndex();
    } else {
        CObject* obj=static_cast<CObject*>(index.internalPointer());
        if(obj==0) return QModelIndex();
        obj=obj->getParent();
        if(obj!=0) {
            if(obj->getId()>=0) {
                return createIndex(obj->getId(),0,obj);
            } else {
                return QModelIndex();
            }
        } else {
            return QModelIndex();
        }
    }
}

int QProjectTreeModel::rowCount(const QModelIndex& parent) const {
    if(project!=0) {
        if(!parent.isValid()) {
            return project->getNChildren();
        } else {
            CObject* obj=static_cast<CObject*>(parent.internalPointer());
            return obj->getNChildren();
        }
    } else {
        return 0;
    }
}

int QProjectTreeModel::columnCount(const QModelIndex& parent) const {
    return 1;
}

QVariant QProjectTreeModel::data(const QModelIndex& index,int role) const {
    if(!index.isValid()) {
        return QVariant();
    } else {
        if(role!=Qt::DisplayRole) {
            return QVariant();
        } else {
            CObject* obj=static_cast<CObject*>(index.internalPointer());
            return QVariant(obj->getName());
        }
    }
}

Qt::ItemFlags QProjectTreeModel::flags(const QModelIndex& index) const {
    if(!index.isValid()) return 0;
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant QProjectTreeModel::headerData(int section,Qt::Orientation orientation,int role) const {
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole) {
        return QVariant("Name");
    } else {
        return QVariant();
    }
}

