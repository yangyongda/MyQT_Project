#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();

private:
    Ui::FindDialog *ui;

private slots:
    void sendNextSignal();
    void sendPreviousSignal();
signals:
    void FindNext(QString str, Qt::CheckState caseSensitive);
    void FindPrevious(QString str, Qt::CheckState caseSensitive);

};

#endif // FINDDIALOG_H
