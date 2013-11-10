#ifndef QPROJECTTREEVIEW_H
#define QPROJECTTREEVIEW_H

#include <QtWidgets/QTreeView>

class QProjectTreeView:public QTreeView {
public:
        QProjectTreeView(QWidget* parent_);
        ~QProjectTreeView();

        void contextMenuEvent(QContextMenuEvent* event_);

public Q_SLOTS:

        // void itemPressed(const QModelIndex& index_);
};

#endif // QPROJECTTREEVIEW_H
