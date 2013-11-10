#include "wmainwindow.h"
//#include <QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WMainWindow w;
    w.show();
    
    return a.exec();
}
