#ifndef CDATASOURCE_H
#define CDATASOURCE_H

#include <QtGui>

#include "cobject.h"

class CDataSource:public CObject {
    bool isstatic;

public:
    CDataSource(bool isstatic_);

    bool getIsStatic();
    void setIsStatic(bool isstatic_);

    virtual QWidget* getSettingsWidget() = 0;
};

#endif // CDATASOURCE_H
