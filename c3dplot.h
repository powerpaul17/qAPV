#ifndef C3DPLOT_H
#define C3DPLOT_H

#include "cplot.h"
#include "caxis.h"

class C3DPlot:public CPlot {

    CAxis x,y,z;

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:

    C3DPlot();
    ~C3DPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);

    void exportToXML(QXmlStreamWriter* xml_);

    QWidget* getSettingsWidget();

    void drawPlot(QGraphicsScene *scene_);

    static CPlot* CreatePlot();

};

#endif // C3DPLOT_H
