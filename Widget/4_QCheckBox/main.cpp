#include "qcheckboxdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCheckBoxDialog w;
    w.show();

    return a.exec();
}
