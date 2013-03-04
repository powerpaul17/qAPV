#include <QtUiTools/QtUiTools>
#include <QtWidgets>

#include "cfiledatasource.h"

CFileDataSource::CFileDataSource():CDataSource("File",true) {
    this->name = "FileDataSource";
    this->filename = "";
    constructSettingsWidget();
}

CFileDataSource::CFileDataSource(QString filename_):CDataSource("File",true) {
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

CObject* CFileDataSource::getChildById(long id_) {
    return 0;
}

CObject* CFileDataSource::getChildByPosition(long pos_) {
    return 0;
}

void CFileDataSource::exportToXML(QXmlStreamWriter *xml_) {
    xml_->writeStartElement("DataSource");
    xml_->writeAttribute("type",QVariant(this->type).toString());
    xml_->writeAttribute("dataSourceType",QVariant(this->datasourcetype).toString());
    xml_->writeAttribute("filename",QString(this->filename));
    // TODO
    xml_->writeEndElement();
}

void CFileDataSource::constructFromXML(QXmlStreamReader *xml_) {
    this->filename = xml_->attributes().value("filename").toString();
    xml_->skipCurrentElement();
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

