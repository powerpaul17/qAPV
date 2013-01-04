#include "qplotwindow.h"
#include "ui_qplotwindow.h"

QPlotWindow::QPlotWindow(CPlot* plot_,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPlotWindow)
{
    ui->setupUi(this);

    //graphicsView = findChild<QGraphicsView*>("graphicsView");

    this->plot = plot_;
}

QPlotWindow::~QPlotWindow()
{
    delete ui;
}
