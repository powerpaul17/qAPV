#include "cfiledatasource.h"

CFileDataSource::CFileDataSource(QString filename_):CDataSource(true) {
    this->filename = filename_;
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
    // TODO
}
