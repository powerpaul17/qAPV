#include "cproject.h"
#include "cdatasourcefactory.h"
#include "cplotfactory.h"

CProject::CProject():CObject(0,"Project",0,"Project",true) {
    addProperty("filename","Filename","Filename",QString(""),false,true);
    addProperty("changed","Changed?","Project has changed?",false,false,true);
    addProperty("currId","Current ID","Current ID",qlonglong(1),false,true);
}

CProject::~CProject() {

}

CProject::CProject(QString filename_) {
    CProject();
    setProperty("filename",filename_);
    loadProjectFromFile();
}

void CProject::constructFromXML(QXmlStreamReader* xml_) {
    CObject::constructFromXML(xml_);

    CDataSourceFactory dataSourceFactory;
    CPlotFactory plotFactory;

    while(xml_->readNextStartElement()) {
        if(xml_->name()=="Datasource") {
            CDataSource* newDataSource = dataSourceFactory.createDataSource(xml_->attributes().value("dataSourceType").toString());
            newDataSource->constructFromXML(xml_);
            this->addChild(newDataSource);
        } else if (xml_->name()=="Plot") {
            CPlot* newPlot = plotFactory.createPlot(xml_->attributes().value("plotType").toString());
            newPlot->constructFromXML(xml_);
            this->addChild(newPlot);
        }
    }
    xml_->skipCurrentElement();
}

int CProject::loadProjectFromFile() {
    QDomDocument doc("qAPV");
    QFile file(getStringPropertyValue("filename"));
    if(!file.open(QIODevice::ReadOnly)) {
        return -1;
    }
    if(!doc.setContent(&file)) {
        file.close();
        return -2;
    }
    file.close();

    QDomElement rootNode = doc.documentElement();
    if(rootNode.tagName() != "qAPV") {
        return -3;
    }

    QDomNode node = rootNode.firstChild();
    while(!node.isNull()) {
        QDomElement element = node.toElement();
        if(!element.isNull()) {
            if(element.tagName() == "Project") {

            }
        }
        node = node.nextSibling();
    }

    return 0;
}

void CProject::saveProjectToFile() {
    QDomDocument doc("qAPV");
    QDomElement rootNode = doc.createElement("qAPV");

    exportToXML(&doc,&rootNode);

    doc.appendChild(rootNode);

    QFile file(getStringPropertyValue("filename"));
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream textStream(&file);
        textStream << doc.toString();
        file.close();
        setChanged(false);
    } else {
        // TODO
    }
}

QString CProject::getFilename() {
    return getStringPropertyValue("filename");
}

void CProject::setFilename(QString filename_) {
    setPropertyValue("filename",filename_);
}

bool CProject::isChanged() {
    return getBoolPropertyValue("changed");
}

void CProject::setChanged(bool changed_) {
    setPropertyValue("changed",changed_);
    //emit projectChanged();
}

/*void CProject::projectChanged() {
    //TODO
}*/
