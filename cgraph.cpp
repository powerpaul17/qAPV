#include "cgraph.h"

CGraph::CGraph():CObject(0,"Graph",-1,"Graph",true) {

}

CGraph::CGraph(CObject* parent_):CObject(parent_,"Graph",-1,"Graph",true) {

}

CGraph::~CGraph() {

}

void CGraph::constructFromXML(QXmlStreamReader* xml_) {
    //TODO
}
