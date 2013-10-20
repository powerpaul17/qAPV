#include <QtWidgets>

#include "cobject.h"

CObject::CObject() : QObject() {
    m_parent = 0;
    m_canHaveChildren = false;

    m_children.clear();

    addProperty("name","Name","Name","Object");
    addProperty("type","Type","Type","Object",false,true);

    QObject::connect(m_properties.getProperty("name"),SIGNAL(signal_propertyChanged(QString)),this,SIGNAL(signal_nameChanged()));
}

CObject::CObject(CObject* parent_, QString type_, qlonglong id_, QString name_, bool canHaveChildren_) : QObject(parent_) {
    m_parent = parent_;
    m_id = id_;
    m_canHaveChildren = canHaveChildren_;

    m_children.clear();

    addProperty("name","Name","Name",name_);
    addProperty("type","Type","Type",type_,false,false);

    QObject::connect(m_properties.getProperty("name"),SIGNAL(signal_propertyChanged(QString)),this,SIGNAL(signal_nameChanged()));
}

CObject::~CObject() {
    while(m_children.size()>0) {
        delete m_children.takeAt(0);
    }
    m_children.clear();
    emit signal_objectDestroyed(this);
}

void CObject::setId(long id_) {
    m_id = id_;
}

qlonglong CObject::getId() {
    return m_id;
}

void CObject::setName(QString name_) {
    setPropertyValue("name",name_);
    emit signal_nameChanged();
}

QString CObject::getName() {
    return m_properties.getPropertyValue("name").toString();
}

QString CObject::getType() {
    return m_properties.getPropertyValue("type").toString();
}

void CObject::setType(QString type_) {
    setProperty("type",type_);
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

void CObject::exportToXML(QXmlStreamWriter* xml_) {
    //TODO
    xml_->writeStartElement(getStringPropertyValue("type"));
    m_properties.exportPropertiesToXML(xml_);
    for(QList<CObject*>::iterator it = m_children.begin(); it != m_children.end(); it++) {
        (*it)->exportToXML(xml_);
    }
    xml_->writeEndElement();
}

void CObject::constructFromXML(QXmlStreamReader* xml_) {
    //TODO
}

void CObject::slot_childDestroyed(CObject *child_) {
    removeChild(child_);
}

void CObject::addProperty(CObjectProperty* property_) {
    m_properties.addProperty(property_);
}

void CObject::addProperty(QString name_, QString title_, QString description_, QString value_, bool visible_, bool editable_) {
    CObjectProperty* newProperty = new CObjectProperty(name_,title_,description_,value_,visible_,editable_);
    m_properties.addProperty(newProperty);
}

void CObject::addProperty(QString name_, QString title_, QString description_, qlonglong value_, bool visible_, bool editable_) {
    CObjectProperty* newProperty = new CObjectProperty(name_,title_,description_,value_,visible_,editable_);
    m_properties.addProperty(newProperty);
}

void CObject::addProperty(QString name_, QString title_, QString description_, bool value_, bool visible_, bool editable_) {
    CObjectProperty* newProperty = new CObjectProperty(name_,title_,description_,value_,visible_,editable_);
    m_properties.addProperty(newProperty);
}

QFormLayout* CObject::returnPropertiesWidget(QWidget *parent_) {
    return m_properties.returnPropertiesWidget(parent_);
}

bool CObject::setPropertyValue(QString name_,QString value_) {
    if(m_properties.hasProperty(name_)) {
        m_properties.setProperty(name_,value_);
        return true;
    } else {
        return false;
    }
}

bool CObject::setPropertyValue(QString name_, qlonglong value_) {
    if(m_properties.hasProperty(name_)) {
        m_properties.setProperty(name_,value_);
        return true;
    } else {
        return false;
    }
}

bool CObject::setPropertyValue(QString name_,bool value_) {
    if(m_properties.hasProperty(name_)) {
        m_properties.setProperty(name_,value_);
        return true;
    } else {
        return false;
    }
}

QString CObject::getStringPropertyValue(QString name_) {
    return m_properties.getPropertyValue(name_).toString();
}

qlonglong CObject::getQLongLongPropertyValue(QString name_) {
    return m_properties.getPropertyValue(name_).toLongLong();
}

bool CObject::getBoolPropertyValue(QString name_) {
    return m_properties.getPropertyValue(name_).toBool();
}
