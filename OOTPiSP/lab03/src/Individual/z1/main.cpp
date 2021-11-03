#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int A, B;
    QTextStream in(stdin);
    qDebug() << "A: ";
    A = in.readLine().toInt();
    qDebug() << "B: ";
    B = in.readLine().toInt();
    if (A != B)
        A = B = A + B;
    else
        A = B = 0;
    qDebug() << "A: " << A << " B: " << B;

    return a.exec();
}
