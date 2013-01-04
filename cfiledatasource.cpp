#include <QtUiTools/QtUiTools>
#include <QtWidgets>

#include "cfiledatasource.h"

CFileDataSource::CFileDataSource():CDataSource(FileDataSource,true) {
    this->filename = "";
    constructSettingsWidget();
}

CFileDataSource::CFileDataSource(QString filename_):CDataSource(FileDataSource,true) {
    this->filename = filename_;
    constructSettingsWidget();
}

void CFileDataSource::constructSettingsWidget() {
    QUiLoader loader;
    QFile file("cfiledatasource_settings.ui");
    file.open(QFile::ReadOnly);
    settingsWidget = loader.load(&file);
    file.close();
}

CFileDataSource::~CFileDataSource() {
    // TODO
}

bool CFileDataSource::hasChildren() {
    return false;
}

int CFileDataSource::getNChildren() {
    return 0;
}

CObject* CFileDataSource::getChild(long id_) {
    return 0;
}

void CFileDataSource::exportToXML(QDomNode* node_) {
    QDomElement* node = new QDomElement();
    node->setTagName("Data Source");
    //node->setAttribute("currId",currId);
    node_->appendChild(*node);
    // TODO
}

QWidget* CFileDataSource::getSettingsWidget() {
//    QTabWidget* tabwidget = new QTabWidget();
//    QWidget* page_general = new QWidget();
//        QGridLayout* pageGeneralGridLayout = new QGridLayout();
//        page_general->setLayout(pageGeneralGridLayout);
//        QLabel* labelFileName = new QLabel("Filename:");
//        pageGeneralGridLayout->addWidget(labelFileName,0,0);
//        QLineEdit* fileName = new QLineEdit();
//            fileName->setReadOnly(true);
//        pageGeneralGridLayout->addWidget(fileName,0,1);
//        QPushButton* chooseFile = new QPushButton("Choose");
//        pageGeneralGridLayout->addWidget(chooseFile,0,2);
//        QLabel*
//    QWidget* page_ascii = new QWidget();
//        page_ascii->setLayout(new QGridLayout());
//    QWidget* page_binary = new QWidget();
//        page_binary->setLayout(new QGridLayout());
//    tabwidget->addTab(page_general,"General");
//    tabwidget->addTab(page_ascii,"ASCII");
//    tabwidget->addTab(page_binary,"Binary");

    // TODO
    return settingsWidget;
}

CData* CFileDataSource::getData() {
    return data;
}

CDataSource* CFileDataSource::CreateDataSource() {
    return new CFileDataSource();
}

