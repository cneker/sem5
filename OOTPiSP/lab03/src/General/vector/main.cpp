#include <QCoreApplication>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //1
    QVector<int> vect1(3);
    vect1[0] = 1;
    vect1[1] = 2;
    vect1[2] = 3;
    qDebug() << vect1;
    //2
    QVector<int> vect2(5, 3);
    qDebug() << vect2;
    //3
    QVector<int> vect3;
    vect3.push_back(1);
    vect3.push_back(2);
    vect3.push_back(3);
    qDebug() << vect3;
    //4
    QVector<int> vect4;
    vect4.append(1);
    vect4.append(2);
    vect4.append(3);
    qDebug() << vect4;
    //5
    QVector<int> vect5;
    vect5.prepend(1);
    vect5.prepend(2);
    vect5.prepend(3);
    qDebug() << vect5;
    return a.exec();
}
