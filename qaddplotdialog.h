#ifndef QADDPLOTDIALOG_H
#define QADDPLOTDIALOG_H

#include <QtWidgets/QDialog>

#include "cplotfactory.h"

namespace Ui {
class QAddPlotDialog;
}

class QAddPlotDialog : public QDialog
{
    Q_OBJECT

    CPlotFactory plotFactory;
    CPlot* newPlot;

public slots:

    void comboBoxIndexChanged(QString text_);
    
public:
    explicit QAddPlotDialog(QWidget *parent = 0);
    ~QAddPlotDialog();

    CPlot* getPlot();
    
private:
    Ui::QAddPlotDialog *ui;
};

#endif // QADDPLOTDIALOG_H
