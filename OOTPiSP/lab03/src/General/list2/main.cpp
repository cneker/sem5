#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    list << 3 << 4 << 5 << 6 << 7;
    qDebug() << list;
    int firstNumber = list.takeFirst();
    qDebug() << firstNumber;
    list.move(0, 1);
    qDebug() << list;
    QList<int>::iterator it = list.begin();
    while(it != list.end()){
        *it *= (*it);
        ++it;
    }
    qDebug() << list;
    return a.exec();
}
