#ifndef QPLOTWINDOW_H
#define QPLOTWINDOW_H

#include <QWidget>
#include <QGraphicsView>

#include "cplot.h"

namespace Ui {
class QPlotWindow;
}

class QPlotWindow : public QWidget {

    Q_OBJECT

    CPlot* plot;

    //QGraphicsView* graphicsView;
    
public:
    explicit QPlotWindow(CPlot* plot_,QWidget *parent = 0);
    ~QPlotWindow();
    
private:
    Ui::QPlotWindow *ui;

public slots:

    void on_plot_nameChanged();

};

#endif // QPLOTWINDOW_H
