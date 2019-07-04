#include "qtreeviewdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTreeViewDialog w;
    w.show();

    return a.exec();
}
