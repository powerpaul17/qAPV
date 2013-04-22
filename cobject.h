#ifndef COBJECT_H
#define COBJECT_H

#include <QString>
#include <QtXml/QtXml>

class CObject : public QObject {

    Q_OBJECT

    bool canHaveChildren;
    QList<CObject*> children;

public:

protected:
    QString type;
    long id;
    QString name;
    CObject* parent;

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

signals:

    void signal_objectDestroyed(CObject* obj_);
    void signal_nameChanged();

public slots:

    void slot_childDestroyed(CObject* child_);

};

#endif // COBJECT_H
