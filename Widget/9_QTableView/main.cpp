#include "qtableviewdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableViewDialog w;
    w.show();

    return a.exec();
}
