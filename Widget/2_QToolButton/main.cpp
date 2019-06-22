#include "qtoolbuttondialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QToolButtonDialog w;
    w.show();

    return a.exec();
}
