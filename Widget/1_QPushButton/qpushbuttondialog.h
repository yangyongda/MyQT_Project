#ifndef QPUSHBUTTONDIALOG_H
#define QPUSHBUTTONDIALOG_H

#include <QDialog>

namespace Ui {
class QPushButtonDialog;
}

class QPushButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QPushButtonDialog(QWidget *parent = 0);
    ~QPushButtonDialog();

private:
    Ui::QPushButtonDialog *ui;
};

#endif // QPUSHBUTTONDIALOG_H
