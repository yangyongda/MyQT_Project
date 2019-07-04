#ifndef QCOLUMNVIEWDIALOG_H
#define QCOLUMNVIEWDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class QColumnViewDialog;
}

class QColumnViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QColumnViewDialog(QWidget *parent = 0);
    ~QColumnViewDialog();

private:
    Ui::QColumnViewDialog *ui;
    QStandardItemModel *model;
};

#endif // QCOLUMNVIEWDIALOG_H
