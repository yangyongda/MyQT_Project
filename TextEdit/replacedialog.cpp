#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    //绑定信号和槽
    QObject::connect(ui->replace, SIGNAL(clicked(bool)),this, SLOT(sendReplaceSignal()));
    QObject::connect(ui->replaceAll, SIGNAL(clicked(bool)),this, SLOT(snedReplaceAllSignal()));
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::sendReplaceSignal()
{
    QString source = ui->source->toPlainText();
    QString target = ui->target->toPlainText();
    Qt::CheckState caseSensitive = ui->checkBox->checkState();
    emit sendReplace(source, target, caseSensitive); //发送信号
}

void ReplaceDialog::snedReplaceAllSignal()
{
    QString source = ui->source->toPlainText();
    QString target = ui->target->toPlainText();
    Qt::CheckState caseSensitive = ui->checkBox->checkState();
    emit sendReplaceAll(source, target, caseSensitive); //发送信号
}
