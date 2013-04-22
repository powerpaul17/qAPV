#include "cobject.h"

CObject::CObject() : QObject() {
    this->parent = 0;
    this->type = "Object";
    this->name = "Object";
    this->canHaveChildren = false;
}

CObject::CObject(CObject* parent_, QString type_, long id_, QString name_, bool canHaveChildren_) : QObject(parent_) {
    this->parent = parent_;
    this->type = type_;
    this->id = id_;
    this->name = name_;
    this->canHaveChildren = canHaveChildren_;
}

CObject::~CObject() {
    emit signal_objectDestroyed(this);
}

void CObject::setId(long id_) {
    this->id = id_;
}

long CObject::getId() {
    return id;
}

void CObject::setName(QString name_) {
    name = name_;
    emit signal_nameChanged();
}

QString CObject::getName() {
    return name;
}

QString CObject::getType() {
    return this->type;
}

void CObject::setType(QString type_) {
    this->type = type_;
}

void CObject::enableChildren(bool enable_) {
    canHaveChildren = enable_;
}

bool CObject::childrenEnabled() {
    return canHaveChildren;
}

void CObject::setParent(CObject* parent_) {
    parent = parent_;
}

CObject* CObject::getParent() {
    return parent;
}

bool CObject::hasParent() {
    return parent!=0;
}

bool CObject::hasChildren() {
    return (children.size()>0);
}

int CObject::getNChildren() {
    return children.size();
}

CObject* CObject::getChildById(long id_) {
    for(QList<CObject*>::iterator it = children.begin(); it != children.end(); it++) {
        if((*it)->getId() == id_) return *it;
    }
    return 0;
}

CObject* CObject::getChildByPosition(long pos_) {
    if(pos_<children.size()) {
        return children[pos_];
    }
    return 0;
}

int CObject::getPositionOfChild(CObject* child_) {
    for(int i = 0; i < children.size(); i++) {
        if(children[i] == child_) return i;
    }
    return -1;
}

void CObject::addChild(CObject* child_) {
    child_->setParent(this);
    children.append(child_);
    //TODO
}

void CObject::removeChild(CObject *child_) {
    //TODO
}

void CObject::removeChild(long id_) {
    //TODO
}

void CObject::slot_childDestroyed(CObject *child_) {
    //TODO
}
