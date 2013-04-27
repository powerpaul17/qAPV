#include "cobject.h"

CObject::CObject() : QObject() {
    m_parent = 0;
    m_type = "Object";
    m_name = "Object";
    m_canHaveChildren = false;
}

CObject::CObject(CObject* parent_, QString type_, long id_, QString name_, bool canHaveChildren_) : QObject(parent_) {
    m_parent = parent_;
    m_type = type_;
    m_id = id_;
    m_name = name_;
    m_canHaveChildren = canHaveChildren_;
}

CObject::~CObject() {
    emit signal_objectDestroyed(this);
}

void CObject::setId(long id_) {
    m_id = id_;
}

long CObject::getId() {
    return m_id;
}

void CObject::setName(QString name_) {
    m_name = name_;
    emit signal_nameChanged();
}

QString CObject::getName() {
    return m_name;
}

QString CObject::getType() {
    return m_type;
}

void CObject::setType(QString type_) {
    m_type = type_;
}

void CObject::enableChildren(bool enable_) {
    m_canHaveChildren = enable_;
}

bool CObject::childrenEnabled() {
    return m_canHaveChildren;
}

void CObject::setParent(CObject* parent_) {
    m_parent = parent_;
}

CObject* CObject::getParent() {
    return m_parent;
}

bool CObject::hasParent() {
    return m_parent!=0;
}

bool CObject::hasChildren() {
    return m_children.size()>0;
}

int CObject::getNChildren() {
    return m_children.size();
}

CObject* CObject::getChildById(long id_) {
    for(QList<CObject*>::iterator it = m_children.begin(); it != m_children.end(); it++) {
        if((*it)->getId() == id_) return *it;
    }
    return 0;
}

CObject* CObject::getChildByPosition(long pos_) {
    if(pos_<m_children.size()) {
        return m_children[pos_];
    }
    return 0;
}

int CObject::getPositionOfChild(CObject* child_) {
    for(int i = 0; i < m_children.size(); i++) {
        if(m_children[i] == child_) return i;
    }
    return -1;
}

void CObject::addChild(CObject* child_) {
    child_->setParent(this);
    m_children.append(child_);
    QObject::connect(child_,SIGNAL(signal_objectDestroyed(CObject*)),this,SLOT(slot_childDestroyed(CObject*)));
    emit signal_childAdded(child_);
}

void CObject::removeChild(CObject *child_) {
    m_children.removeAt(getPositionOfChild(child_));
}

void CObject::removeChild(long id_) {
    m_children.removeAt(getPositionOfChild(getChildById(id_)));
}

void CObject::slot_childDestroyed(CObject *child_) {
    removeChild(child_);
}
