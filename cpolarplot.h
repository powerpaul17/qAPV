#ifndef CPOLARPLOT_H
#define CPOLARPLOT_H

#include "cplot.h"
#include "caxis.h"

class CPolarPlot:public CPlot {

    CAxis r,phi;

    QGraphicsScene* scene;

    QWidget* constructSettingsWidget(QWidget* parent_);

public:

    CPolarPlot();
    virtual ~CPolarPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);
    int getPositionOfChild(CObject* child_);
    void addChild(CObject *child_);
    void removeChild(CObject *child_);
    void removeChild(long id_);

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget(QWidget* parent_);

    QGraphicsScene* getGraphicsScene();

    static CPlot* CreatePlot();

public slots:

    virtual void slot_childDestroyed(CObject *child_);

};

#endif // CPOLARPLOT_H
