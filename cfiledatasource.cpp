#include <QtUiTools>

#include "cfiledatasource.h"

CFileDataSource::CFileDataSource():CDataSource("File",true) {
    setName("FileDataSource");

    addProperty("filename","Filename","Filename",QString(""),true,true);
}

CFileDataSource::CFileDataSource(QString filename_):CDataSource("File",true) {
    addProperty("filename","Filename","Filename",filename_,true,true);
}

QWidget* CFileDataSource::constructSettingsWidget(QWidget* parent_) {
    QUiLoader loader;
    QFile file("cfiledatasource_settings.ui");
    file.open(QFile::ReadOnly);
    QWidget* settingsWidget = loader.load(&file,parent_);
    file.close();
    return settingsWidget;
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

CObject* CFileDataSource::getChildById(long id_) {
    return 0;
}

CObject* CFileDataSource::getChildByPosition(long pos_) {
    return 0;
}

int CFileDataSource::getPositionOfChild(CObject* child_) {
    return -1;
}

void CFileDataSource::addChild(CObject *child_) {

}

void CFileDataSource::removeChild(CObject *child_) {

}

void CFileDataSource::removeChild(long id_) {

}

void CFileDataSource::constructFromXML(QXmlStreamReader *xml_) {
    setName(xml_->attributes().value("name").toString());
    //m_filename = xml_->attributes().value("filename").toString();
    xml_->skipCurrentElement();
}

QWidget* CFileDataSource::getSettingsWidget(QWidget* parent_) {
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
    return constructSettingsWidget(parent_);
}

CData* CFileDataSource::getData() {
    return m_data;
}

CDataSource* CFileDataSource::CreateDataSource() {
    return new CFileDataSource();
}

void CFileDataSource::slot_childDestroyed(CObject *child_) {

}
