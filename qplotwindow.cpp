#include "qplotwindow.h"
#include "ui_qplotwindow.h"

QPlotWindow::QPlotWindow(CPlot* plot_,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPlotWindow)
{
    ui->setupUi(this);

    //graphicsView = findChild<QGraphicsView*>("graphicsView");

    this->plot = plot_;

    this->setWindowTitle(plot->getName());

    QObject::connect(plot,SIGNAL(signal_nameChanged()),this,SLOT(on_plot_nameChanged()));
}

QPlotWindow::~QPlotWindow() {
    delete ui;
}

void QPlotWindow::on_plot_nameChanged() {
    this->setWindowTitle(plot->getName());
}
