#ifndef QCOMMANDLINKBUTTONDIALOG_H
#define QCOMMANDLINKBUTTONDIALOG_H

#include <QDialog>
#include "seconddialog.h"

namespace Ui {
class QCommandLinkButtonDialog;
}

class QCommandLinkButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QCommandLinkButtonDialog(QWidget *parent = 0);
    ~QCommandLinkButtonDialog();

private:
    Ui::QCommandLinkButtonDialog *ui;
    SecondDialog *dialog;

private slots:
    void showDialog();
};

#endif // QCOMMANDLINKBUTTONDIALOG_H
