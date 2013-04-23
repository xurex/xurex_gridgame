#include <QtGui/QApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main w(&a);
    w.show();
    return a.exec();
}
