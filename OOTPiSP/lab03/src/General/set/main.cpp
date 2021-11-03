#include <QCoreApplication>
#include <QSet>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"rus");
    QSet <QString> singers;
    QSet <QString> dancers;
    singers << "Иван" << "Евгений" << "Анастасия" << "Александр" << "Ксения" ;
    qDebug() << singers;
    dancers << "Марина" << "Петр" << "Иван" << "Ксения" ;
    qDebug() << dancers;
    QSet<QString> result = singers;
    result.unite(dancers);
    qDebug() << "Объединение множеств: ";
    qDebug() << result;
    result = singers;
    result.intersect(dancers);
    qDebug() << "Пересечение множеств: ";
    qDebug() << result; result = singers;
    result.subtract(dancers);
    qDebug() << "Разность множеств singers - dancers: ";
    qDebug() << result;
    result = dancers;
    result.subtract(singers);
    qDebug() << "Разность множеств dancers - singers: ";
    qDebug() << result;
    return a.exec();
}
