#include "cproject.h"
#include "cdatasourcefactory.h"
#include "cplotfactory.h"

CProject::CProject():CObject(0,Project,0,"Project") {
    //type = ProjectType;
    //name = "Project";

    filename = "";
    currId = 1;
    children.clear();
    changed = false;
}

CProject::~CProject() {
    while(children.size()>0) {
        delete children[0];
        children.removeFirst();
    }
    children.clear();
}

CProject::CProject(QString filename_) {
    CProject();
    filename = filename_;
    loadProjectFromFile();
}

bool CProject::hasChildren() {
    return (children.size()>0);
}

int CProject::getNChildren() {
    return children.size();
}

CObject* CProject::getChildById(long id_) {
    for(QList<CObject*>::iterator it = children.begin(); it != children.end(); it++) {
        if((*it)->getId() == id_) return *it;
    }
    return 0;
}

CObject* CProject::getChildByPosition(long pos_) {
    if(pos_<children.size()) {
        return children[pos_];
    }
    return 0;
}

int CProject::getPositionOfChild(CObject* child_) {
    for(int i = 0; i < children.size(); i++) {
        if(children[i] == child_) return i;
    }
    return -1;
}

void CProject::exportToXML(QXmlStreamWriter* xml_) {
    xml_->writeStartElement("Project");
    xml_->writeAttribute("currId",QVariant(currId).toString());
    for(QList<CObject*>::iterator it = children.begin(); it != children.end(); it++) {
        (*it)->exportToXML(xml_);
    }
    xml_->writeEndElement();
}

void CProject::constructFromXML(QXmlStreamReader* xml_) {
    CDataSourceFactory dataSourceFactory;
    CPlotFactory plotFactory;

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

    QFile file(filename);
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

    QFile file(filename);
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
    return filename;
}

void CProject::setFilename(QString filename_) {
    filename = filename_;
}

bool CProject::isChanged() {
    return changed;
}

void CProject::setChanged(bool changed_) {
    changed = changed_;
    //emit projectChanged();
}

void CProject::addChild(CObject* child_) {
    child_->setId(currId);
    child_->setParent(this);
    currId++;
    children.append(child_);
    setChanged();
}

/*void CProject::projectChanged() {
    //TODO
}*/
