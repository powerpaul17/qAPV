#ifndef QADDDATASOURCEDIALOG_H
#define QADDDATASOURCEDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QVBoxLayout>

#include "cdatasourcefactory.h"

namespace Ui {
class QAddDataSourceDialog;
}

class QAddDataSourceDialog : public QDialog
{
    Q_OBJECT

    CDataSourceFactory dataSourceFactory;
    CDataSource* newDataSource;

    //QVBoxLayout* layout;
    //QComboBox* comboBox;
    //QWidget* settingsWidget;

public slots:

    void comboBoxIndexChanged(QString text_);
    
public:
    explicit QAddDataSourceDialog(QWidget *parent = 0);
    ~QAddDataSourceDialog();

    CDataSource* getDataSource();
    
private:
    Ui::QAddDataSourceDialog *ui;
};

#endif // QADDDATASOURCEDIALOG_H
