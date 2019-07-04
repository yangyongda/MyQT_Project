#include "qtreeviewdialog.h"
#include "ui_qtreeviewdialog.h"
#include <QDebug>

QTreeViewDialog::QTreeViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTreeViewDialog)
{
    ui->setupUi(this);

    //定义3个节点，2列
    model = new QStandardItemModel(3, 2);
    //列名称
    model->setHeaderData(0, Qt:: Horizontal, "第一列") ;
    model->setHeaderData(1, Qt:: Horizontal, "第二列") ;
    //定义节点
    QStandardItem *item1 = new QStandardItem("数学") ;
    item1->setIcon(QIcon(":/image/image/folder")) ;
    QStandardItem *item2 = new QStandardItem("语文") ;
    item2->setIcon(QIcon(":/image/image/folder")) ;
    QStandardItem *item3 = new QStandardItem("外语") ;
    item3->setIcon(QIcon(":/image/image/folder")) ;
    //外语子项
    QStandardItem *item4 = new QStandardItem("英语") ;
    item4->setIcon(QIcon(":/image/image/math")) ;
    item3->appendRow(item4);
    //将节点添加至 QStandardItemModel
    model->setItem(0, 0,item1) ;
    model->setItem(1, 0,item2) ;
    model->setItem(2, 0,item3) ;
    //将 QStandardItemModel 数据绑定 QTreeView 控件
    ui->treeView->setModel(model);

    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(showIndex(QModelIndex)));
}

QTreeViewDialog::~QTreeViewDialog()
{
    delete ui;
}

void QTreeViewDialog::showIndex(QModelIndex index)
{
    qDebug()<< index.row() <<" = "<<index.data().toString();
}
