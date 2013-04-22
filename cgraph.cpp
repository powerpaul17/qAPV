#include "cgraph.h"

CGraph::CGraph():CObject(0,"Graph",-1,"Graph") {

}

CGraph::CGraph(CObject* parent_):CObject(parent_,"Graph",-1,"Graph") {

}

CGraph::~CGraph() {

}

void CGraph::exportToXML(QXmlStreamWriter* xml_) {
    //TODO
}

void CGraph::constructFromXML(QXmlStreamReader* xml_) {
    //TODO
}
