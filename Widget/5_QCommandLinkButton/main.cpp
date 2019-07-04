#include "qcommandlinkbuttondialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLinkButtonDialog w;
    w.show();

    return a.exec();
}
