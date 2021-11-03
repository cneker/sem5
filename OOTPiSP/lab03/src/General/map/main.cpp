#include <QCoreApplication>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //1
    QMap<QString, int> map1;
    map1["ten"] = 10;
    map1["twenty"] = 20;
    map1["thirty"] = 30;
    QMap<QString, int>::iterator it1 = map1.begin();
    for(; it1 != map1.end(); ++it1) {
        qDebug() << "key: " << it1.key() << " value: " << it1.value();
    }
    //2
    QMap<QString, int> map2;
    map2.insert("ten", 10);
    map2.insert("twenty", 20);
    map2.insert("thirty", 30);
    QMap<QString, int>::iterator it2 = map2.begin();
    for(; it2 != map1.end(); ++it2) {
        qDebug() << "key: " << it2.key() << " value: " << it2.value();
    }
    return a.exec();
}
