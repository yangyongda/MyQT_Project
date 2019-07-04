#include "qlistviewdialog.h"
#include "ui_qlistviewdialog.h"
#include <QDebug>

QListViewDialog::QListViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QListViewDialog)
{
    ui->setupUi(this);

    QStringList list;
    list<<"数学"<<"语文"<<"英语"<<"地理";
    //model = new QStringListModel(list);
    //ui->listView->setModel(model);

    itemModel = new QStandardItemModel(this);
    for(int i = 0; i < list.size(); i++)
    {
       QString string = static_cast<QString>(list.at(i));
       QStandardItem *item = new QStandardItem(string);
       itemModel->appendRow(item);
    }
    ui->listView->setModel(itemModel);

    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(showClickIndex(QModelIndex)));

}

QListViewDialog::~QListViewDialog()
{
    delete ui;
}

void QListViewDialog::showClickIndex(QModelIndex index)
{
    qDebug()<< index.data().toString();
}
