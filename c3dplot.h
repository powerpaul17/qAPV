#ifndef C3DPLOT_H
#define C3DPLOT_H

#include "cplot.h"
#include "caxis.h"

class C3DPlot:public CPlot {

    CAxis x,y,z;

    QGraphicsScene* scene;

    QWidget* constructSettingsWidget(QWidget* parent_);

public:

    C3DPlot();
    virtual ~C3DPlot();

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

#endif // C3DPLOT_H
