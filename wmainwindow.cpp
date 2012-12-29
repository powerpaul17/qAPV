#include <QMessageBox>
#include <QFileDialog>

#include "wmainwindow.h"
#include "ui_wmainwindow.h"

WMainWindow::WMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WMainWindow)
{
    ui->setupUi(this);

    treeView = findChild<QProjectTreeView*>("treeView");

    QObject::connect(this,SIGNAL(signalProjectClosed(bool)),findChild<QMenu*>("menuProject"),SLOT(setDisabled(bool)));
    QObject::connect(this,SIGNAL(signalProjectOpened(bool)),findChild<QMenu*>("menuProject"),SLOT(setEnabled(bool)));

    QObject::connect(this,SIGNAL(signalProjectClosed(bool)),findChild<QAction*>("actionClose_project"),SLOT(setDisabled(bool)));
    QObject::connect(this,SIGNAL(signalProjectClosed(bool)),findChild<QAction*>("actionSave_project"),SLOT(setDisabled(bool)));
    QObject::connect(this,SIGNAL(signalProjectClosed(bool)),findChild<QAction*>("actionSave_project_as"),SLOT(setDisabled(bool)));
    QObject::connect(this,SIGNAL(signalProjectOpened(bool)),findChild<QAction*>("actionClose_project"),SLOT(setEnabled(bool)));
    QObject::connect(this,SIGNAL(signalProjectOpened(bool)),findChild<QAction*>("actionSave_project"),SLOT(setEnabled(bool)));
    QObject::connect(this,SIGNAL(signalProjectOpened(bool)),findChild<QAction*>("actionSave_project_as"),SLOT(setEnabled(bool)));

    this->project = 0;

    this->treeModel = 0;

    statusBar()->showMessage("Welcome to qAPV!");
}

WMainWindow::~WMainWindow()
{
    delete ui;
}

void WMainWindow::on_actionNew_project_triggered() {
    on_actionClose_project_triggered();
    project = new CProject();
    treeModel = new QProjectTreeModel(this,project);
    treeView->setModel(treeModel);
    emit signalProjectOpened(true);
}

void WMainWindow::on_actionOpen_project_triggered() {
    QString filename=QFileDialog::getOpenFileName(this,"Open project file...");
    if(!filename.isEmpty()) {
        on_actionClose_project_triggered();
        project=new CProject();
        project->setFilename(filename);
        if(project->loadProjectFromFile()!=0) {
            QMessageBox::critical(this,"","Not a valid project file!",QMessageBox::Ok);
            delete project;
            project=0;
            return;
        }
        treeModel=new QProjectTreeModel(this,project);
        treeView->setModel(treeModel);
    }
}

void WMainWindow::on_actionSave_project_triggered() {
    if(project!=0) {
        if(project->getFilename()!="") {
            project->saveProjectToFile();
        } else {
            on_actionSave_project_as_triggered();
        }
    }
}

void WMainWindow::on_actionSave_project_as_triggered() {
    if(project!=0) {
        QString filename=QFileDialog::getSaveFileName(this,"Save file as...");
        if(!filename.isEmpty()) {
            project->setFilename(filename);
            project->saveProjectToFile();
        }
    }
}

void WMainWindow::on_actionClose_project_triggered() {
    if(this->project != 0) {
        if(this->project->isChanged()) {
            if(QMessageBox::question(this,"","Project has been changed. Save?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes) {
                if(project->getFilename()!="") {
                    project->saveProjectToFile();
                } else {
                    on_actionSave_project_as_triggered();
                }
            }
        }
        treeView->setModel(0);
        delete treeModel;
        treeModel=0;
        delete project;
        project=0;
        emit signalProjectClosed(true);
    }
}

void WMainWindow::closeEvent(QCloseEvent *event) {
    on_actionClose_project_triggered();
}
