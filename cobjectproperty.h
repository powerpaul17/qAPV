#ifndef COBJECTPROPERTY_H
#define COBJECTPROPERTY_H

#include <QString>
#include <QVariant>

class CObjectProperty : public QObject {

    Q_OBJECT

    QString m_name;
    QString m_description;
    QString m_type;

    QVariant m_property;

public:

    CObjectProperty();
    virtual ~CObjectProperty();
    CObjectProperty(QString name_,QString description_);
    CObjectProperty(QString name_,QString description_,int value_);
    CObjectProperty(QString name_,QString description_,QString value_);
    CObjectProperty(QString name_,QString description_,bool value_);

    QString getName();
    void setName(QString name_);
    QString getDescription();
    void setDescription(QString description_);
    QString getType();
    QVariant getPropertyValue();

    bool setPropertyValue(QString value_);
    bool setPropertyValue(int value_);
    bool setPropertyValue(bool value_);

    QWidget* returnWidget(QWidget* parent_);

signals:

    void signal_propertyChanged(QVariant property_);
    void signal_propertyChanged(QString string_);
    void signal_propertyChanged(int integer_);
    void signal_propertyChanged(bool boolean_);

public slots:

    void slot_propertyChanged(QVariant property_);
    void slot_propertyChanged(QString string_);
    void slot_propertyChanged(int integer_);
    void slot_propertyChanged(bool boolean_);

};

#endif // COBJECTPROPERTY_H
