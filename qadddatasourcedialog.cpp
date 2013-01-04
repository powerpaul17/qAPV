#include "qadddatasourcedialog.h"
#include "ui_qadddatasourcedialog.h"

#include <QMessageBox>

QAddDataSourceDialog::QAddDataSourceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAddDataSourceDialog)
{
    ui->setupUi(this);

    newDataSource = 0;

    //layout = findChild<QVBoxLayout*>("verticalLayout");

    //comboBox = findChild<QComboBox*>("comboBox");
    QMapIterator<QString,CreateDataSourceFunc> it = dataSourceFactory.getDataSources();
    it.toFront();
    while(it.hasNext()) {
        it.next();
        ui->comboBox->addItem(it.key());
    }
    QObject::connect(ui->comboBox,SIGNAL(activated(QString)),this,SLOT(comboBoxIndexChanged(QString)));

    //settingsWidget = findChild<QWidget*>("settingsWidget");
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
