#include "wmainwindow.h"
#include "ui_wmainwindow.h"

WMainWindow::WMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WMainWindow)
{
    ui->setupUi(this);

    statusBar()->showMessage("Welcome to qAPV!");
}

WMainWindow::~WMainWindow()
{
    delete ui;
}

//WMainWindow::
