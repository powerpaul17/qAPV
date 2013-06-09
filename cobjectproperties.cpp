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

QVariant CObjectProperties::getProperty(QString name_) {
    return m_properties[name_]->getProperty();
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
