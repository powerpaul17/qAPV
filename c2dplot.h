#ifndef C2DPLOT_H
#define C2DPLOT_H

#include "cplot.h"
#include "caxis.h"

class C2DPlot:public CPlot {

    CAxis* m_x,m_y;

    QGraphicsScene* m_scene;

    QWidget* constructSettingsWidget(QWidget* parent_);

public:

    C2DPlot();
    virtual ~C2DPlot();

    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget(QWidget* parent_);

    QGraphicsScene* getGraphicsScene();

    static CPlot* CreatePlot();

};

#endif // C2DPLOT_H
