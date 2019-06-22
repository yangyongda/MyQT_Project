#include "qpushbuttondialog.h"
#include "ui_qpushbuttondialog.h"

QPushButtonDialog::QPushButtonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QPushButtonDialog)
{
    ui->setupUi(this);
    //添加信号与槽
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(close()));

}

QPushButtonDialog::~QPushButtonDialog()
{
    delete ui;
}
