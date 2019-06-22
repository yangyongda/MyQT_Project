#ifndef QTOOLBUTTONDIALOG_H
#define QTOOLBUTTONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QToolBar>
#include <QVBoxLayout>
#include <QMenu>

namespace Ui {
class QToolButtonDialog;
}

class QToolButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QToolButtonDialog(QWidget *parent = 0);
    ~QToolButtonDialog();
private slots:
    void showDialog();

private:
    Ui::QToolButtonDialog *ui;
};

#endif // QTOOLBUTTONDIALOG_H
