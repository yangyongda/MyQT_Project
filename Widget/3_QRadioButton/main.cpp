#include "qradiobuttondialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRadioButtonDialog w;
    w.show();

    return a.exec();
}
