#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->previous,SIGNAL(clicked(bool)), this, SLOT(sendPreviousSignal()));
    QObject::connect(ui->next,SIGNAL(clicked(bool)),this, SLOT(sendNextSignal()));
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::sendNextSignal()
{
    QString find = ui->textEdit->toPlainText();
    Qt::CheckState caseSensitive = ui->checkBox->checkState();
    emit FindNext(find, caseSensitive);
}

void FindDialog::sendPreviousSignal()
{
    QString find = ui->textEdit->toPlainText();
    Qt::CheckState caseSensitive = ui->checkBox->checkState();
    emit FindPrevious(find, caseSensitive);
}
