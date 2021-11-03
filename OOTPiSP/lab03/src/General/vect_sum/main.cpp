#include <QCoreApplication>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> vect;
    for (int i = 0; i < 10; i++){
        vect.push_back(i);
    }
    qDebug() << vect;
    vect.replace(2, 65);
    qDebug() << vect;
    int sum = 0;
    for (int i = 0; i < vect.size(); i++){
        sum += vect[i];
    }
    qDebug() << "Sum = " << sum;
    return a.exec();
}
