#ifndef CPOLARPLOT_H
#define CPOLARPLOT_H

#include "cplot.h"
#include "caxis.h"

class CPolarPlot:public CPlot {

    CAxis r,phi;

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:

    CPolarPlot();
    ~CPolarPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChildById(long id_);
    CObject* getChildByPosition(long pos_);

    void exportToXML(QXmlStreamWriter* xml_);
    void constructFromXML(QXmlStreamReader *xml_);

    QWidget* getSettingsWidget();

    void drawPlot(QGraphicsScene *scene_);

    static CPlot* CreatePlot();

};

#endif // CPOLARPLOT_H
