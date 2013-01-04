#ifndef WMAINWINDOW_H
#define WMAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

#include "cproject.h"
#include "qprojecttreemodel.h"
#include "qprojecttreeview.h"

namespace Ui {
class WMainWindow;
}

class WMainWindow : public QMainWindow
{
    Q_OBJECT

    CProject* project;
    
    QProjectTreeModel* treeModel;

public:
    explicit WMainWindow(QWidget *parent = 0);
    ~WMainWindow();

signals:

    void signalProjectClosed(bool a_);
    void signalProjectOpened(bool a_);

public slots:

    void on_actionNew_project_triggered();
    void on_actionOpen_project_triggered();
    void on_actionSave_project_triggered();
    void on_actionSave_project_as_triggered();
    void on_actionClose_project_triggered();

    void on_actionNew_data_source_triggered();
    void on_actionNew_plot_triggered();
    
private:
    Ui::WMainWindow *ui;

    void closeEvent(QCloseEvent* event);
};

#endif // WMAINWINDOW_H
