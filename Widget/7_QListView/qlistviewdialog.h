#ifndef QLISTVIEWDIALOG_H
#define QLISTVIEWDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QStandardItemModel>

namespace Ui {
class QListViewDialog;
}

class QListViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QListViewDialog(QWidget *parent = 0);
    ~QListViewDialog();

private:
    Ui::QListViewDialog *ui;
    QStringListModel *model;
    QStandardItemModel *itemModel;

private slots:
    void showClickIndex(QModelIndex index);
};

#endif // QLISTVIEWDIALOG_H
