#include "qpushbuttondialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButtonDialog w;
    w.show();

    return a.exec();
}
