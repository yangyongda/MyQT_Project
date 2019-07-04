#include "qcolumnviewdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QColumnViewDialog w;
    w.show();

    return a.exec();
}
