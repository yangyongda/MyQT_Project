#include "qdialogbuttonboxdialog.h"
#include "ui_qdialogbuttonboxdialog.h"
#include <QDebug>

QDialogButtonBoxDialog::QDialogButtonBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogButtonBoxDialog)
{
    ui->setupUi(this);

    //将按钮上的文本改为所需文本
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确定");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(OkSlot()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(CancelSolt()));
}

QDialogButtonBoxDialog::~QDialogButtonBoxDialog()
{
    delete ui;
}

void QDialogButtonBoxDialog::OkSlot()
{
    qDebug()<<"确定";
}

void QDialogButtonBoxDialog::CancelSolt()
{
    qDebug()<<"取消";
}



