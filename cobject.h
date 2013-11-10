#ifndef COBJECT_H
#define COBJECT_H

#include <QString>
#include <QtXml/QtXml>
//#include <QWidget>

#include "cobjectproperties.h"

class CObject : public QObject {

    Q_OBJECT

    CObjectProperties m_properties;

    bool m_canHaveChildren;
    QList<CObject*> m_children;

protected:

    // QString m_type;
    long m_id;
    // QString m_name;
    CObject* m_parent;

public:

    CObject();
    CObject(CObject* parent_, QString type_ = "Object", qlonglong id_ = -1, QString name_ = "Object", bool canHaveChildren_ = false);
    virtual ~CObject();

    void setId(long id_);
    qlonglong getId();
    void setName(QString name_);
    QString getName();
    QString getType();
    void setType(QString type_);
    void enableChildren(bool enable_);
    bool childrenEnabled();
    bool hasParent();
    void setParent(CObject* parent_);
    CObject* getParent();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);
    int getPositionOfChild(CObject* child_);
    void addChild(CObject* child_);
    void removeChild(CObject* child_);
    void removeChild(long id_);

    void constructFromXML(QDomElement* node_);
    QDomElement exportToXML(QDomDocument* doc_, QDomElement* rootNode_);

    void addProperty(CObjectProperty* property_);
    void addProperty(QString name_, QString title_, QString description_,QString value_,bool visible_ = true, bool editable_ = true);
    void addProperty(QString name_, QString title_, QString description_, qlonglong value_, bool visible_ = true, bool editable_ = true);
    void addProperty(QString name_, QString title_, QString description_,bool value_, bool visible_ = true, bool editable_ = true);

    QFormLayout *returnPropertiesWidget(QWidget* parent_);

    bool setPropertyValue(QString name_,QString value_);
    bool setPropertyValue(QString name_, qlonglong value_);
    bool setPropertyValue(QString name_,bool value_);

    QString getStringPropertyValue(QString name_);
    qlonglong getQLongLongPropertyValue(QString name_);
    bool getBoolPropertyValue(QString name_);

signals:

    void signal_objectDestroyed(CObject* obj_);
    void signal_nameChanged();
    void signal_childAdded(CObject* obj_);

public slots:

    void slot_childDestroyed(CObject* child_);

};

#endif // COBJECT_H
