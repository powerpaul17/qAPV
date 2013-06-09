#include "qprojecttreemodel.h"

QProjectTreeModel::QProjectTreeModel(QObject* parent_,CProject* project_):QAbstractItemModel(parent_) {
    project=project_;

    // QObject::connect(project_,SIGNAL(projectChanged(void)),this,SLOT(projectChanged(void)));
}

QProjectTreeModel::~QProjectTreeModel() {

}

QModelIndex QProjectTreeModel::index(int row,int column,const QModelIndex& parent) const {
//	if(!hasIndex(row,column,parent)) return QModelIndex();
    if(project!=0) {
        CObject* obj=0;
        if(!parent.isValid()) {
            //obj=project;
            return createIndex(0,0,project);
        } else {
            obj=static_cast<CObject*>(parent.internalPointer());
        }
        if(obj==0) return QModelIndex();
        obj=obj->getChildByPosition(row);
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
            if(obj->hasParent()) {
                return createIndex((obj->getParent())->getPositionOfChild(obj),0,obj);
            } else {
                return createIndex(0,0,obj);
            }
        } else {
            return QModelIndex();
        }
    }
}

int QProjectTreeModel::rowCount(const QModelIndex& parent) const {
    if(project!=0) {
        if(!parent.isValid()) {
            //return project->getNChildren();
            return 1;
        } else {
            CObject* obj=static_cast<CObject*>(parent.internalPointer());
            return obj->getNChildren();
        }
    } else {
        return 0;
    }
}

int QProjectTreeModel::columnCount(const QModelIndex& parent) const {
    return 2;
}

QVariant QProjectTreeModel::data(const QModelIndex& index,int role) const {
    if(!index.isValid()) {
        return QVariant();
    } else {
        if(role!=Qt::DisplayRole) {
            return QVariant();
        } else {
            CObject* obj=static_cast<CObject*>(index.internalPointer());
            if(index.column() == 0) {
                return QVariant(obj->getName());
            } else if(index.column() == 1) {
                return QVariant(obj->getType());
            } else {
                return QVariant();
            }
        }
    }
}

Qt::ItemFlags QProjectTreeModel::flags(const QModelIndex& index) const {
    if(!index.isValid()) return 0;
    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if(index.column() == 0) {
        flags |= Qt::ItemIsEditable;
    } else {
    }
    return flags;
}

QVariant QProjectTreeModel::headerData(int section,Qt::Orientation orientation,int role) const {
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole) {
        if(section == 0) {
            return QVariant("Name");
        } else if(section == 1) {
            return QVariant("Type");
        } else {
            return QVariant();
        }
    } else {
        return QVariant();
    }
}

void QProjectTreeModel::projectChanged() {
    //TODO
    emit QProjectTreeModel::dataChanged(index(0,0),index(rowCount()-1,0));
}

bool QProjectTreeModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role == Qt::EditRole) {
        CObject* obj = static_cast<CObject*>(index.internalPointer());
        obj->setName(value.toString());
        emit dataChanged(index,index);
    }
    return true;
}
