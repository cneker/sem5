#include "garaj.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Garaj w;
    w.show();
    return a.exec();
}
