#ifndef COBJECTPROPERTIES_H
#define COBJECTPROPERTIES_H

#include<QMap>
#include<QtWidgets>

#include "cobjectproperty.h"

class CObjectProperties : public QObject {

    Q_OBJECT

    QMap<QString,CObjectProperty*> m_properties;

public:

    CObjectProperties();
    virtual ~CObjectProperties();

    void addProperty(CObjectProperty *property_);
    QVariant getProperty(QString name_);

    QFormLayout *returnPropertiesWidget(QWidget* parent_);

signals:

    void signal_propertyAdded(CObjectProperty* property_);

};

#endif // COBJECTPROPERTIES_H
