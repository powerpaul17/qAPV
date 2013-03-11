#include "qplotwindow.h"
#include "ui_qplotwindow.h"

QPlotWindow::QPlotWindow(CPlot* plot_,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPlotWindow)
{
    ui->setupUi(this);

    //graphicsView = findChild<QGraphicsView*>("graphicsView");

    this->plot = plot_;

    ui->settingsWidget->close();
    ui->settingsWidget = plot->getSettingsWidget();
    ui->horizontalLayout->addWidget(ui->settingsWidget);
    ui->horizontalLayout->update();

    this->setWindowTitle(plot->getName());

    QObject::connect(plot,SIGNAL(signal_nameChanged()),this,SLOT(slot_plot_nameChanged()));
}

QPlotWindow::~QPlotWindow() {
    ui->settingsWidget->setParent(0);
    delete ui;
}

long QPlotWindow::getPlotId() {
    return plot->getId();
}

void QPlotWindow::slot_plot_nameChanged() {
    this->setWindowTitle(plot->getName());
}
