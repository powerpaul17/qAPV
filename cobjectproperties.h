#ifndef COBJECTPROPERTIES_H
#define COBJECTPROPERTIES_H

#include <QMap>
#include <QtWidgets/QtWidgets>
#include <QtXml/QtXml>

#include "cobjectproperty.h"

class CObjectProperties : public QObject {

    Q_OBJECT

    QMap<QString,CObjectProperty*> m_properties;

public:

    CObjectProperties();
    virtual ~CObjectProperties();

    void addProperty(CObjectProperty *property_);
    QVariant getPropertyValue(QString name_);
    bool hasProperty(QString name_);
    bool setProperty(QString name_, QString value_);
    bool setProperty(QString name_, qlonglong value_);
    bool setProperty(QString name_, bool value_);

    CObjectProperty* getProperty(QString name_);

    //void exportPropertiesToXML(QXmlStreamWriter* xml_);
    void exportPropertiesToXML(QDomDocument* doc_, QDomElement* node_);

    QFormLayout *returnPropertiesWidget(QWidget* parent_);

signals:

    void signal_propertyAdded(CObjectProperty* property_);

};

#endif // COBJECTPROPERTIES_H
