#ifndef COBJECTPROPERTY_H
#define COBJECTPROPERTY_H

#include <QString>
#include <QVariant>

class CObjectProperty : public QObject {

    Q_OBJECT

    QString m_name;
    QString m_title;
    QString m_description;
    QString m_type;
    bool m_visible;
    bool m_editable;

    QVariant m_property;

public:

    CObjectProperty();
    virtual ~CObjectProperty();
    CObjectProperty(QString name_, QString title_, QString description_, bool visible_, bool editable_);
    CObjectProperty(QString name_, QString title_, QString description_, qlonglong value_, bool visible_ = true, bool editable_ = true);
    CObjectProperty(QString name_, QString title_, QString description_, QString value_, bool visible_ = true, bool editable_ = true);
    CObjectProperty(QString name_, QString title_, QString description_, bool value_, bool visible_ = true, bool editable_ = true);

    QString getName();
    void setName(QString name_);
    QString getTitle();
    void setTitle(QString title_);
    QString getDescription();
    void setDescription(QString description_);
    QString getType();
    QVariant getPropertyValue();
    bool isVisible();
    void setVisible(bool visible_);
    bool isEditable();
    void setEditable(bool editable_);

    bool setPropertyValue(QString value_);
    bool setPropertyValue(qlonglong value_);
    bool setPropertyValue(bool value_);

    QWidget* returnWidget(QWidget* parent_);

signals:

    void signal_propertyChanged(QVariant property_);
    void signal_propertyChanged(QString string_);
    void signal_propertyChanged(qlonglong integer_);
    void signal_propertyChanged(bool boolean_);

public slots:

    void slot_propertyChanged(QVariant property_);
    void slot_propertyChanged(QString string_);
    void slot_propertyChanged(qlonglong integer_);
    void slot_propertyChanged(bool boolean_);

};

#endif // COBJECTPROPERTY_H
