#ifndef C3DPLOT_H
#define C3DPLOT_H

#include "cplot.h"

class C3DPlot:public CPlot {

    QWidget* settingsWidget;

    void constructSettingsWidget();

public:

    C3DPlot();
    ~C3DPlot();

    bool hasChildren();
    int getNChildren();
    CObject* getChild(long id_);

    void exportToXML(QDomNode* node_);

    QWidget* getSettingsWidget();

    static CPlot* CreatePlot();

};

#endif // C3DPLOT_H
