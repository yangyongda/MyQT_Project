#include "qcolumnviewdialog.h"
#include "ui_qcolumnviewdialog.h"

QColumnViewDialog::QColumnViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QColumnViewDialog)
{
    ui->setupUi(this);

    model = new QStandardItemModel;
    QStandardItem *item1 = new QStandardItem("草帽海贼团");
    QStandardItem *item2 = new QStandardItem("白胡子海贼团");
    model->appendRow(item1);
    model->appendRow(item2);
    //子选项
    QStandardItem *firstName = new QStandardItem("路飞");
    QStandardItem *secondName = new QStandardItem("乔巴");
    item1->appendRow(firstName);
    item1->appendRow(secondName);
    //子选项
    QStandardItem *thirdName = new QStandardItem("艾斯");
    QStandardItem *forthName = new QStandardItem("马尔科");
    item2->appendRow(thirdName);
    item2->appendRow(forthName);

    ui->columnView->setModel(model);
}

QColumnViewDialog::~QColumnViewDialog()
{
    delete ui;
}
