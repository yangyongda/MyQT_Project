#ifndef QDIALOGBUTTONBOXDIALOG_H
#define QDIALOGBUTTONBOXDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class QDialogButtonBoxDialog;
}

class QDialogButtonBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QDialogButtonBoxDialog(QWidget *parent = 0);
    ~QDialogButtonBoxDialog();

private:
    Ui::QDialogButtonBoxDialog *ui;

private slots:
    void OkSlot();
    void CancelSolt();
};

#endif // QDIALOGBUTTONBOXDIALOG_H
