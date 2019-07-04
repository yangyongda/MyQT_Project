#ifndef QTABLEVIEWDIALOG_H
#define QTABLEVIEWDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class QTableViewDialog;
}

class QTableViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QTableViewDialog(QWidget *parent = 0);
    ~QTableViewDialog();

private:
    Ui::QTableViewDialog *ui;
    QStandardItemModel *model;
};

#endif // QTABLEVIEWDIALOG_H
