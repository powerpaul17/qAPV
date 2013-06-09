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

bool CObjectProperties::setProperty(QString name_,int value_) {
    if(hasProperty(name_)) {
        if(m_properties[name_]->getType() == "int") {
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

QFormLayout *CObjectProperties::returnPropertiesWidget(QWidget *parent_) {
    // TODO
    QFormLayout* layout = new QFormLayout();
    QMap<QString,CObjectProperty*>::const_iterator i;
    for(i = m_properties.begin();i != m_properties.end();++i) {
        layout->addRow(i.key(),i.value()->returnWidget(0));
    }
    return layout;
}
