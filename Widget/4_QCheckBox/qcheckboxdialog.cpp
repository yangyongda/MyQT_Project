#include "qcheckboxdialog.h"
#include "ui_qcheckboxdialog.h"

QCheckBoxDialog::QCheckBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QCheckBoxDialog)
{
    ui->setupUi(this);
    //绑定信号和槽,这里的信号最好使用toggled，使用clicked也可以
    connect(ui->apple, SIGNAL(toggled(bool)), this, SLOT(showResult()));
    connect(ui->juicypeach, SIGNAL(toggled(bool)), this, SLOT(showResult()));
    connect(ui->banana, SIGNAL(toggled(bool)), this, SLOT(showResult()));
    connect(ui->pear, SIGNAL(toggled(bool)), this, SLOT(showResult()));

}

QCheckBoxDialog::~QCheckBoxDialog()
{
    delete ui;
}

void QCheckBoxDialog::showResult()
{
    QString str;
    if(ui->apple->isChecked())
    {
        str.append(" 苹果");
    }
    if(ui->pear->isChecked())
    {
        str.append(" 梨");
    }
    if(ui->juicypeach->isChecked())
    {
        str.append(" 水蜜桃");
    }
    if(ui->banana->isChecked())
    {
        str.append(" 香蕉");
    }

    ui->result->setText(str);
}
