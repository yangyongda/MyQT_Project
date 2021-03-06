#include "mainwindow.h"
#include <QApplication>
#include <QTableWidget>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QTableWidget是QT程序中常用的显示数据表格的控件
    QTableWidget* tableWidget = new QTableWidget;
    tableWidget->setWindowTitle("QTableWidget");
    tableWidget->resize(350, 250);
    tableWidget->setRowCount(6);
    tableWidget->setColumnCount(3);

    QStringList header;
    header.append("One");
    header.append("Two");
    header.append("zhangsan");
    tableWidget->setHorizontalHeaderLabels(header); //添加表格头部字段（列名）

    QStringList strList;
    strList.append("1");
    strList.append("2");
    strList.append("3");
    QComboBox *combox = new QComboBox;
    combox->addItems(strList);

    //添加单元格数据
    tableWidget->setCellWidget(0,0, combox);
    tableWidget->setItem(1,0, new QTableWidgetItem("B"));
    tableWidget->setItem(2,0, new QTableWidgetItem("C"));
    tableWidget->setItem(3,0, new QTableWidgetItem("D"));
    tableWidget->setItem(4,0, new QTableWidgetItem("E"));
    tableWidget->setItem(0,1, new QTableWidgetItem(QIcon(":/images/green_keyboard03.png"), "data"));
    tableWidget->setItem(1,1, new QTableWidgetItem(QIcon(":/images/green_keyboard03.png"), "decision"));
    tableWidget->setItem(2,1, new QTableWidgetItem(QIcon(":/images/green_keyboard03.png"), "document"));
    tableWidget->setItem(3,1, new QTableWidgetItem(QIcon(":/images/green_keyboard03.png"), "printer"));
    tableWidget->setItem(4,1, new QTableWidgetItem(QIcon(":/images/green_keyboard03.png"), "process"));
    //显示TableWigdet
    tableWidget->show();

    return a.exec();
}
