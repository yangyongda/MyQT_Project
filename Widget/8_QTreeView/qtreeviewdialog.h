#ifndef QTREEVIEWDIALOG_H
#define QTREEVIEWDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class QTreeViewDialog;
}

class QTreeViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QTreeViewDialog(QWidget *parent = 0);
    ~QTreeViewDialog();

private:
    Ui::QTreeViewDialog *ui;
    QStandardItemModel *model;

private slots:
    void showIndex(QModelIndex index);
};

#endif // QTREEVIEWDIALOG_H
