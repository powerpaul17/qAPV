#include "qadddatasourcedialog.h"
#include "ui_qadddatasourcedialog.h"

#include <QMessageBox>

QAddDataSourceDialog::QAddDataSourceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAddDataSourceDialog)
{
    ui->setupUi(this);

    newDataSource = 0;

    QMapIterator<QString,CreateDataSourceFunc> it = dataSourceFactory.getDataSources();
    it.toFront();
    while(it.hasNext()) {
        it.next();
        ui->comboBox->addItem(it.key());
    }
    ui->comboBox->setCurrentIndex(0);
    comboBoxIndexChanged(ui->comboBox->currentText());

    QObject::connect(ui->comboBox,SIGNAL(activated(QString)),this,SLOT(comboBoxIndexChanged(QString)));
}

QAddDataSourceDialog::~QAddDataSourceDialog()
{
    delete ui;
}

void QAddDataSourceDialog::comboBoxIndexChanged(QString text_) {
    delete newDataSource;
    newDataSource = dataSourceFactory.createDataSource(text_);
    ui->settingsWidget->close();
    ui->settingsWidget = newDataSource->getSettingsWidget();
    ui->verticalLayout->insertWidget(1,ui->settingsWidget);
    ui->verticalLayout->update();
}

CDataSource* QAddDataSourceDialog::getDataSource() {
    return newDataSource;
}
