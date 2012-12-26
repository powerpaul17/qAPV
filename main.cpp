#include "wmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WMainWindow w;
    w.show();
    
    return a.exec();
}
