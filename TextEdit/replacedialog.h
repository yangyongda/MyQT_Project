#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = 0);
    ~ReplaceDialog();

private:
    Ui::ReplaceDialog *ui;

private slots:
    void sendReplaceSignal();
    void snedReplaceAllSignal();

signals:
    void sendReplace(QString source, QString target, Qt::CheckState caseSensitive);
    void sendReplaceAll(QString source, QString target, Qt::CheckState caseSensitive);
};

#endif // REPLACEDIALOG_H
