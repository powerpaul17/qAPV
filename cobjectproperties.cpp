#include "cobjectproperties.h"

CObjectProperties::CObjectProperties() {
    m_properties.clear();
}

CObjectProperties::~CObjectProperties() {
    m_properties.clear();
}

void CObjectProperties::addProperty(CObjectProperty* property_) {
    m_properties[property_->getName()] = property_;
    emit signal_propertyAdded(property_);
}

QVariant CObjectProperties::getPropertyValue(QString name_) {
    return m_properties[name_]->getPropertyValue();
}

bool CObjectProperties::hasProperty(QString name_) {
    return m_properties.contains(name_);
}

bool CObjectProperties::setProperty(QString name_,QString value_) {
    if(hasProperty(name_)) {
        if(m_properties[name_]->getType() == "string") {
            m_properties[name_]->setPropertyValue(value_);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool CObjectProperties::setProperty(QString name_, qlonglong value_) {
    if(hasProperty(name_)) {
        if(m_properties[name_]->getType() == "longlong") {
            m_properties[name_]->setPropertyValue(value_);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool CObjectProperties::setProperty(QString name_,bool value_) {
    if(hasProperty(name_)) {
        if(m_properties[name_]->getType() == "bool") {
            m_properties[name_]->setPropertyValue(value_);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

CObjectProperty* CObjectProperties::getProperty(QString name_) {
    if(hasProperty(name_)) {
        return m_properties[name_];
    } else {
        return 0;
    }
}

void CObjectProperties::exportPropertiesToXML(QDomDocument *doc_, QDomElement *node_) {
    QMap<QString,CObjectProperty*>::const_iterator i;
    QDomElement propertyNode;
    for(i = m_properties.begin(); i != m_properties.end(); ++i) {
        propertyNode = doc_->createElement(i.key());
        propertyNode.setAttribute("title",i.value()->getTitle());
        propertyNode.setAttribute("description",i.value()->getDescription());
        propertyNode.setAttribute("value",i.value()->getPropertyValue().toString());
        node_->appendChild(propertyNode);
    }
}

QFormLayout *CObjectProperties::returnPropertiesWidget(QWidget *parent_) {
    QFormLayout* layout = new QFormLayout();
    QMap<QString,CObjectProperty*>::const_iterator i;
    for(i = m_properties.begin();i != m_properties.end();++i) {
        if(i.value()->isVisible()) layout->addRow(i.value()->getTitle(),i.value()->returnWidget(0));
    }
    return layout;
}
