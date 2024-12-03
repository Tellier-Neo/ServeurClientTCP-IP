#include "CPPNetworkClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPPNetworkClient w;
    w.show();
    return a.exec();
}
