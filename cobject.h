#ifndef COBJECT_H
#define COBJECT_H

#include <QString>
#include <QtXml/QtXml>

class CObject : public QObject {

    Q_OBJECT

public:

typedef enum {
    Generic,
    Project,
    DataSource,
    Plot,
    Axis
} ObjectType;

protected:
    ObjectType type;
    long id;
    QString name;
    CObject* parent;

public:
    CObject();
    CObject(CObject* parent_,ObjectType type_ = Generic,long id_ = -1,QString name_ = "Object");
    virtual ~CObject();

    void setId(long id_);
    long getId();
    void setName(QString name_);
    QString getName();
    ObjectType getType();
    void setType(ObjectType type_);
    bool hasParent();
    void setParent(CObject* parent_);
    CObject* getParent();

    virtual bool hasChildren() = 0;
    virtual int getNChildren() = 0;
    virtual CObject* getChildById(long id_) = 0;
    virtual CObject* getChildByPosition(long pos_) = 0;
    virtual int getPositionOfChild(CObject* child_) = 0;

    virtual void exportToXML(QXmlStreamWriter* xml_) = 0;
    virtual void constructFromXML(QXmlStreamReader* xml_) = 0;

signals:

    void signal_nameChanged();

};

#endif // COBJECT_H
