#ifndef C2DPLOT_H
#define C2DPLOT_H

#include "cplot.h"
#include "caxis.h"

class C2DPlot:public CPlot {

    CAxis x,y;

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:

    C2DPlot();
    ~C2DPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);

    void exportToXML(QXmlStreamWriter* xml_);

    QWidget* getSettingsWidget();

    void drawPlot(QGraphicsScene *scene_);

    static CPlot* CreatePlot();

};

#endif // C2DPLOT_H
