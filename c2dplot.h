#ifndef C2DPLOT_H
#define C2DPLOT_H

#include "cplot.h"
#include "caxis.h"

class C2DPlot:public CPlot {

    CAxis* x,y;

    QGraphicsScene* scene;

    QWidget* constructSettingsWidget(QWidget* parent_);

public:

    C2DPlot();
    virtual ~C2DPlot();

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget(QWidget* parent_);

    QGraphicsScene* getGraphicsScene();

    static CPlot* CreatePlot();

};

#endif // C2DPLOT_H
