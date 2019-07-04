#include "qtableviewdialog.h"
#include "ui_qtableviewdialog.h"

QTableViewDialog::QTableViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTableViewDialog)
{
    ui->setupUi(this);

    //实例数据模型
    model = new QStandardItemModel() ;
    //定义列
    model->setHorizontalHeaderItem(0, new QStandardItem("姓名")) ;
    model->setHorizontalHeaderItem(1, new QStandardItem("语文")) ;
    model->setHorizontalHeaderItem(2, new QStandardItem("外语")) ;
    //行数据 0 行,0 列
    model->setItem(0, 0, new QStandardItem("丽丽"));
    model->setItem(1, 0, new QStandardItem("可尔康"));
    model->setItem(2, 0, new QStandardItem("双双"));

    model->setItem(0, 1, new QStandardItem("95"));
    model->setItem(1, 1, new QStandardItem("80"));
    model->setItem(2, 1, new QStandardItem("99"));

    model->setItem(0, 2, new QStandardItem("99"));
    model->setItem(1, 2, new QStandardItem("95"));
    model->setItem(2, 2, new QStandardItem("100"));
    //将数据模型绑定控件
    ui->tableView->setModel(model) ;
    //设置为不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

QTableViewDialog::~QTableViewDialog()
{
    delete ui;
}
