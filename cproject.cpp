#include "cproject.h"
#include "cdatasourcefactory.h"
#include "cplotfactory.h"

CProject::CProject():CObject(0,"Project",0,"Project",true) {
    currId = 1;
    changed = false;

    addProperty("filename","Filename","Filename",QString(""),false,true);
}

CProject::~CProject() {

}

CProject::CProject(QString filename_) {
    CProject();
    setProperty("filename",filename_);
    loadProjectFromFile();
}

void CProject::constructFromXML(QXmlStreamReader* xml_) {
    CDataSourceFactory dataSourceFactory;
    CPlotFactory plotFactory;

    this->setName(xml_->attributes().value("name").toString());
    this->currId = xml_->attributes().value("currId").toString().toInt();
    while(xml_->readNextStartElement()) {
        if(xml_->name()=="DataSource") {
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
    QXmlStreamReader* xml = new QXmlStreamReader();

    QFile file(getStringPropertyValue("filename"));
    if(file.open(QIODevice::ReadOnly)) {
        xml->setDevice(&file);
        if(xml->readNextStartElement()) {
            if((xml->name()=="qAPV") && (xml->attributes().value("version")=="1.0")) {
                if(xml->readNextStartElement()) {
                    if(xml->name()=="Project") {
                        this->constructFromXML(xml);
                    } else {
                        return 3;
                    }
                } else {
                    return 2;
                }
            } else {
                return 3;
            }
        } else {
            return 2;
        }
        file.close();
        setChanged(false);
    } else {
        return 1;
    }

    delete xml;
    return 0;
}

void CProject::saveProjectToFile() {
    QXmlStreamWriter* xml = new QXmlStreamWriter();
    xml->setAutoFormatting(true);

    QFile file(getStringPropertyValue("filename"));
    if(file.open(QIODevice::WriteOnly)) {
        xml->setDevice(&file);
        xml->writeStartDocument();
        xml->writeDTD("<!DOCTYPE qAPV>");
        xml->writeStartElement("qAPV");
            xml->writeAttribute("version","1.0");
        exportToXML(xml);
        xml->writeEndDocument();

        file.close();
        setChanged(false);
    } else {
        // TODO
    }

    delete xml;
}

QString CProject::getFilename() {
    return getStringPropertyValue("filename");
}

void CProject::setFilename(QString filename_) {
    setPropertyValue("filename",filename_);
}

bool CProject::isChanged() {
    return changed;
}

void CProject::setChanged(bool changed_) {
    changed = changed_;
    //emit projectChanged();
}

/*void CProject::projectChanged() {
    //TODO
}*/
