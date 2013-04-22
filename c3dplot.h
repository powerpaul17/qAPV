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

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget(QWidget* parent_);

    QGraphicsScene* getGraphicsScene();

    static CPlot* CreatePlot();

};

#endif // C3DPLOT_H
