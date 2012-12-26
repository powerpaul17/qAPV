#ifndef WMAINWINDOW_H
#define WMAINWINDOW_H

#include <QMainWindow>

#include "cproject.h"

namespace Ui {
class WMainWindow;
}

class WMainWindow : public QMainWindow
{
    Q_OBJECT

    CProject* project;
    
public:
    explicit WMainWindow(QWidget *parent = 0);
    ~WMainWindow();

    void onMenuFileNewProject();
    void onMenuFileOpenProject();
    
private:
    Ui::WMainWindow *ui;
};

#endif // WMAINWINDOW_H
