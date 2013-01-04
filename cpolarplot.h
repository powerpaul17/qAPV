#ifndef CPOLARPLOT_H
#define CPOLARPLOT_H

#include "cplot.h"

class CPolarPlot:public CPlot {

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:

    CPolarPlot();
    ~CPolarPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChild(long id_);

    void exportToXML(QDomNode *node_);

    QWidget* getSettingsWidget();

    static CPlot* CreatePlot();

};

#endif // CPOLARPLOT_H
