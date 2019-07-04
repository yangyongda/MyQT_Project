#include "qdialogbuttonboxdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialogButtonBoxDialog w;
    w.show();

    return a.exec();
}
