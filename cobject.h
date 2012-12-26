#ifndef COBJECT_H
#define COBJECT_H

#include <QString>
#include <QtXml/QtXml>

typedef enum {
    GenericType,
    ProjectType,
    DataSourceType
} ObjectType;

class CObject {
protected:
    ObjectType type;
    long id;
    QString name;
    CObject* parent;
public:
    CObject();
    CObject(CObject* parent_,ObjectType type_ = GenericType,long id_ = -1,QString name_ = "Object");
    ~CObject();

    long getId();
    void setName(QString name_);
    QString getName();
    bool hasParent();
    void setParent(CObject* parent_);
    CObject* getParent();

    virtual bool hasChildren() = 0;
    virtual int getNChildren() = 0;
    virtual CObject* getChild(long id_) = 0;

    virtual void exportToXML(QDomNode* node_) = 0;
};

#endif // COBJECT_H
