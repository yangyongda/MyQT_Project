#ifndef QRADIOBUTTONDIALOG_H
#define QRADIOBUTTONDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class QRadioButtonDialog;
}

class QRadioButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRadioButtonDialog(QWidget *parent = 0);
    ~QRadioButtonDialog();

private:
    Ui::QRadioButtonDialog *ui;

private slots:  //自定义槽
    void changeText(void);
    void isCorrect(void);
};

#endif // QRADIOBUTTONDIALOG_H
