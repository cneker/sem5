#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //1
    QList<int> list1;
    list1 << 1 << 2 << 3;
    qDebug() << list1;
    //2
    QList<int> list2;
    list2.append(1);
    list2.append(2);
    list2.append(3);
    qDebug() << list2;
    return a.exec();
}
