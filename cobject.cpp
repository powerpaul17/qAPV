#include "cobject.h"

CObject::CObject() {
    this->parent = 0;
    this->type = Generic;
    this->name = "Object";
}

CObject::CObject(CObject* parent_, ObjectType type_, long id_, QString name_) {
    this->parent = parent_;
    this->type = type_;
    this->id = id_;
    this->name = name_;
}

CObject::~CObject() {

}

void CObject::setId(long id_) {
    this->id = id_;
}

long CObject::getId() {
    return id;
}

void CObject::setName(QString name_) {
    name = name_;
}

QString CObject::getName() {
    return name;
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
