#include <QtWidgets>

#include "cobjectproperty.h"

CObjectProperty::CObjectProperty() {
    m_name = "Property";
    m_description = "Random generic property";
    m_type = "none";
}

CObjectProperty::CObjectProperty(QString name_, QString description_) {
    m_name = name_;
    m_description = description_;
}

CObjectProperty::CObjectProperty(QString name_, QString description_, int value_) {
    m_name = name_;
    m_description = description_;
    m_type = "int";
    m_property = value_;
}

CObjectProperty::CObjectProperty(QString name_, QString description_, QString value_) {
    m_name = name_;
    m_description = description_;
    m_type = "string";
    m_property = value_;
}

CObjectProperty::CObjectProperty(QString name_,QString description_, bool value_) {
    m_name = name_;
    m_description = description_;
    m_type = "bool";
    m_property = value_;
}

CObjectProperty::~CObjectProperty() {

}

QString CObjectProperty::getName() {
    return m_name;
}

void CObjectProperty::setName(QString name_) {
    m_name = name_;
}

QString CObjectProperty::getDescription() {
    return m_description;
}

void CObjectProperty::setDescription(QString description_) {
    m_description = description_;
}

QString CObjectProperty::getType() {
    return m_type;
}

QVariant CObjectProperty::getPropertyValue() {
    return m_property;
}

bool CObjectProperty::setPropertyValue(QString value_) {
    if(m_type == "string") {
        m_property = value_;
        return true;
    } else {
        return false;
    }
}

bool CObjectProperty::setPropertyValue(int value_) {
    if(m_type == "int") {
        m_property = value_;
        return true;
    } else {
        return false;
    }
}

bool CObjectProperty::setPropertyValue(bool value_) {
    if(m_type == "bool") {
        m_property = value_;
        return true;
    } else {
        return false;
    }
}

QWidget* CObjectProperty::returnWidget(QWidget *parent_) {
    if(m_type == "string") {
        QLineEdit* newWidget = new QLineEdit(parent_);
        newWidget->setText(m_property.toString());
        QObject::connect(this,SIGNAL(signal_propertyChanged(QString)),newWidget,SLOT(setText(QString)));
        QObject::connect(newWidget,SIGNAL(textChanged(QString)),this,SLOT(slot_propertyChanged(QString)));
        return newWidget;
    } else if(m_type == "int") {
        QLineEdit* newWidget = new QLineEdit(parent_);
        QValidator* validator = new QIntValidator();
        newWidget->setValidator(validator);
        newWidget->setText(m_property.toString());
        QObject::connect(this,SIGNAL(signal_propertyChanged(QString)),newWidget,SLOT(setText(QString)));
        QObject::connect(newWidget,SIGNAL(textChanged(QString)),this,SLOT(slot_propertyChanged(QString)));
        return newWidget;
    } else if(m_type == "bool") {
        QCheckBox* newWidget = new QCheckBox(parent_);
        newWidget->setChecked(m_property.toBool());
        QObject::connect(this,SIGNAL(signal_propertyChanged(bool)),newWidget,SLOT(setChecked(bool)));
        QObject::connect(newWidget,SIGNAL(toggled(bool)),this,SLOT(slot_propertyChanged(bool)));
        return newWidget;
    }
    return 0;
}

void CObjectProperty::slot_propertyChanged(QVariant property_) {
    m_property = property_;
    emit signal_propertyChanged(m_property);
}

void CObjectProperty::slot_propertyChanged(QString string_) {
    if(m_type == "int") {
        m_property = string_.toInt();
    } else {
        m_property = string_;
    }
    emit signal_propertyChanged(m_property.toString());
}

void CObjectProperty::slot_propertyChanged(int integer_) {
    m_property = integer_;
    emit signal_propertyChanged(m_property.toInt());
}

void CObjectProperty::slot_propertyChanged(bool boolean_) {
    m_property = boolean_;
    emit signal_propertyChanged(m_property.toBool());
}
