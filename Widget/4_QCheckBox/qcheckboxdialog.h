#ifndef QCHECKBOXDIALOG_H
#define QCHECKBOXDIALOG_H

#include <QDialog>

namespace Ui {
class QCheckBoxDialog;
}

class QCheckBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QCheckBoxDialog(QWidget *parent = 0);
    ~QCheckBoxDialog();

private:
    Ui::QCheckBoxDialog *ui;

private slots:
    void showResult();
};

#endif // QCHECKBOXDIALOG_H
