#ifndef QOBJECTPROPERTIESWINDOW_H
#define QOBJECTPROPERTIESWINDOW_H

#include <QtWidgets>

#include "cobject.h"

class QObjectPropertiesWindow : public QWidget {

public:

    QObjectPropertiesWindow();
    QObjectPropertiesWindow(QWidget* parent_);
    virtual ~QObjectPropertiesWindow();

signals:

public slots:

    void slot_objectChanged(CObject* object_);

};

#endif // QOBJECTPROPERTIESWINDOW_H
