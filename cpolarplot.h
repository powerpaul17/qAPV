#ifndef CPOLARPLOT_H
#define CPOLARPLOT_H

#include "cplot.h"
#include "caxis.h"

class CPolarPlot:public CPlot {

    CAxis m_r,m_phi;

    QGraphicsScene* m_scene;

    QWidget* constructSettingsWidget(QWidget* parent_);

public:

    CPolarPlot();
    virtual ~CPolarPlot();

    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget(QWidget* parent_);

    QGraphicsScene* getGraphicsScene();

    static CPlot* CreatePlot();

};

#endif // CPOLARPLOT_H
