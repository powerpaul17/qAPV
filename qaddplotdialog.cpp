#include "qaddplotdialog.h"
#include "ui_qaddplotdialog.h"

QAddPlotDialog::QAddPlotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAddPlotDialog)
{
    ui->setupUi(this);

    newPlot = 0;

    QMapIterator<QString,CreatePlotFunc> it = plotFactory.getPlots();
    it.toFront();
    while(it.hasNext()) {
        it.next();
        ui->comboBox->addItem(it.key());
    }
    ui->comboBox->setCurrentIndex(0);
    comboBoxIndexChanged(ui->comboBox->currentText());

    QObject::connect(ui->comboBox,SIGNAL(activated(QString)),this,SLOT(comboBoxIndexChanged(QString)));

}

QAddPlotDialog::~QAddPlotDialog()
{
    //ui->settingsWidget->setParent(0);
    delete ui;
}

void QAddPlotDialog::comboBoxIndexChanged(QString text_) {
    delete newPlot;
    newPlot = plotFactory.createPlot(text_);
    ui->settingsWidget->close();
    ui->settingsWidget = newPlot->getSettingsWidget(this);
    ui->verticalLayout->insertWidget(1,ui->settingsWidget);
    ui->verticalLayout->update();
}

CPlot* QAddPlotDialog::getPlot() {
    return newPlot;
}
