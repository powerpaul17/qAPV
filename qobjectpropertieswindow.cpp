#include "qobjectpropertieswindow.h"

QObjectPropertiesWindow::QObjectPropertiesWindow():QWidget() {

}

QObjectPropertiesWindow::QObjectPropertiesWindow(QWidget* parent_):QWidget(parent_) {

}

QObjectPropertiesWindow::~QObjectPropertiesWindow() {

}

void QObjectPropertiesWindow::slot_objectChanged(CObject* object_) {
    // TODO
    QFormLayout* newLayout = object_->returnPropertiesWidget(0);

    QLayout* layout = this->layout();
    if (layout != 0) {
        QLayoutItem* item;
        while((item = layout->takeAt(0)) != 0) {
            if(item->widget() != 0) {
                delete item->widget();
            }
            delete item;
        }
        delete this->layout();
    }
    this->setLayout(newLayout);
}
