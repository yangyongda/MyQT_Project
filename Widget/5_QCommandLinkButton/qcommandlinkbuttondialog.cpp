#include "qcommandlinkbuttondialog.h"
#include "ui_qcommandlinkbuttondialog.h"
#include <QDebug>

QCommandLinkButtonDialog::QCommandLinkButtonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QCommandLinkButtonDialog)
{
    ui->setupUi(this);

    dialog = new SecondDialog();

    //连接信号和槽
    connect(ui->commandLinkButton, SIGNAL(clicked(bool)), this, SLOT(showDialog()));
}

QCommandLinkButtonDialog::~QCommandLinkButtonDialog()
{
    delete ui;
}

void QCommandLinkButtonDialog::showDialog()
{

    if(this->close())
    {
        //在程序输出窗口上输出调试信息
        qDebug() << "Close";
    }
    else
    {
        qDebug() << "No Close";
    }
    //显示第二个窗口
    dialog->show();
    dialog->exec();


}
