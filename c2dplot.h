#ifndef C2DPLOT_H
#define C2DPLOT_H

#include "cplot.h"

class C2DPlot:public CPlot {

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:

    C2DPlot();
    ~C2DPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);

    QWidget* getSettingsWidget();

    static CPlot* CreatePlot();

};

#endif // C2DPLOT_H
