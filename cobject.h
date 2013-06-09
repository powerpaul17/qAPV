#ifndef COBJECT_H
#define COBJECT_H

#include <QString>
#include <QtXml/QtXml>
#include <QWidget>

#include "cobjectproperties.h"

class CObject : public QObject {

    Q_OBJECT

    CObjectProperties m_properties;

    bool m_canHaveChildren;
    QList<CObject*> m_children;

protected:

    QString m_type;
    long m_id;
    QString m_name;
    CObject* m_parent;

public:

    CObject();
    CObject(CObject* parent_,QString type_ = "Object",long id_ = -1,QString name_ = "Object",bool canHaveChildren_ = false);
    virtual ~CObject();

    void setId(long id_);
    long getId();
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

    virtual void exportToXML(QXmlStreamWriter* xml_) = 0;
    virtual void constructFromXML(QXmlStreamReader* xml_) = 0;

    void addProperty(CObjectProperty* property_);
    void addProperty(QString name_,QString description_,QString value_);
    void addProperty(QString name_,QString description_,int value_);
    void addProperty(QString name_,QString description_,bool value_);

    QFormLayout *returnPropertiesWidget(QWidget* parent_);

signals:

    void signal_objectDestroyed(CObject* obj_);
    void signal_nameChanged();
    void signal_childAdded(CObject* obj_);

public slots:

    void slot_childDestroyed(CObject* child_);

};

#endif // COBJECT_H
