#include <QtWidgets>

#include "cobjectproperty.h"

CObjectProperty::CObjectProperty() {
    m_name = "property";
    m_title = "Property";
    m_description = "Random generic property";
    m_type = "none";
    m_visible = true;
    m_editable = true;
}

CObjectProperty::CObjectProperty(QString name_, QString title_, QString description_, bool visible_, bool editable_) {
    m_name = name_;
    m_title = title_;
    m_description = description_;
    m_visible = visible_;
    m_editable = editable_;
}

CObjectProperty::CObjectProperty(QString name_, QString title_, QString description_, qlonglong value_, bool visible_, bool editable_) {
    m_name = name_;
    m_title = title_;
    m_description = description_;
    m_type = "longlong";
    m_property = value_;
    m_visible = visible_;
    m_editable = editable_;
}

CObjectProperty::CObjectProperty(QString name_, QString title_, QString description_, QString value_, bool visible_, bool editable_) {
    m_name = name_;
    m_title = title_;
    m_description = description_;
    m_type = "string";
    m_property = value_;
    m_visible = visible_;
    m_editable = editable_;
}

CObjectProperty::CObjectProperty(QString name_,QString title_, QString description_, bool value_, bool visible_, bool editable_) {
    m_name = name_;
    m_title = title_;
    m_description = description_;
    m_type = "bool";
    m_property = value_;
    m_visible = visible_;
    m_editable = editable_;
}

CObjectProperty::~CObjectProperty() {

}

QString CObjectProperty::getName() {
    return m_name;
}

void CObjectProperty::setName(QString name_) {
    m_name = name_;
}

QString CObjectProperty::getTitle() {
    return m_title;
}

void CObjectProperty::setTitle(QString title_) {
    m_title = title_;
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

bool CObjectProperty::isVisible() {
    return m_visible;
}

void CObjectProperty::setVisible(bool visible_) {
    m_visible = visible_;
}

bool CObjectProperty::isEditable() {
    return m_editable;
}

void CObjectProperty::setEditable(bool editable_) {
    m_editable = editable_;
}

QVariant CObjectProperty::getPropertyValue() {
    return m_property;
}

bool CObjectProperty::setPropertyValue(QString value_) {
    if((m_type == "string") && m_editable) {
        m_property = value_;
        emit signal_propertyChanged(value_);
        return true;
    } else {
        return false;
    }
}

bool CObjectProperty::setPropertyValue(qlonglong value_) {
    if((m_type == "longlong") && m_editable){
        m_property = value_;
        emit signal_propertyChanged(value_);
        return true;
    } else {
        return false;
    }
}

bool CObjectProperty::setPropertyValue(bool value_) {
    if((m_type == "bool") && m_editable) {
        m_property = value_;
        emit signal_propertyChanged(value_);
        return true;
    } else {
        return false;
    }
}

QWidget* CObjectProperty::returnWidget(QWidget *parent_) {
    if(m_visible) {
        if(m_type == "string") {
            QLineEdit* newWidget = new QLineEdit(parent_);
            if(!m_editable) newWidget->setEnabled(false);
            newWidget->setText(m_property.toString());
            QObject::connect(this,SIGNAL(signal_propertyChanged(QString)),newWidget,SLOT(setText(QString)));
            QObject::connect(newWidget,SIGNAL(textChanged(QString)),this,SLOT(slot_propertyChanged(QString)));
            return newWidget;
        } else if(m_type == "longlong") {
            QLineEdit* newWidget = new QLineEdit(parent_);
            if(!m_editable) newWidget->setEnabled(false);
            QValidator* validator = new QIntValidator();
            newWidget->setValidator(validator);
            newWidget->setText(m_property.toString());
            QObject::connect(this,SIGNAL(signal_propertyChanged(QString)),newWidget,SLOT(setText(QString)));
            QObject::connect(newWidget,SIGNAL(textChanged(QString)),this,SLOT(slot_propertyChanged(QString)));
            return newWidget;
        } else if(m_type == "bool") {
            QCheckBox* newWidget = new QCheckBox(parent_);
            if(!m_editable) newWidget->setEnabled(false);
            newWidget->setChecked(m_property.toBool());
            QObject::connect(this,SIGNAL(signal_propertyChanged(bool)),newWidget,SLOT(setChecked(bool)));
            QObject::connect(newWidget,SIGNAL(toggled(bool)),this,SLOT(slot_propertyChanged(bool)));
            return newWidget;
        }
    }
    return 0;
}

void CObjectProperty::slot_propertyChanged(QVariant property_) {
    m_property = property_;
    emit signal_propertyChanged(m_property);
}

void CObjectProperty::slot_propertyChanged(QString string_) {
    if(m_type == "longlong") {
        m_property = string_.toLongLong();
    } else {
        m_property = string_;
    }
    emit signal_propertyChanged(m_property.toString());
}

void CObjectProperty::slot_propertyChanged(qlonglong integer_) {
    m_property = integer_;
    emit signal_propertyChanged(m_property.toLongLong());
}

void CObjectProperty::slot_propertyChanged(bool boolean_) {
    m_property = boolean_;
    emit signal_propertyChanged(m_property.toBool());
}
