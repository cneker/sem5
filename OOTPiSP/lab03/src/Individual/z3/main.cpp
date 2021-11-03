#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //1
    QList<int> list;
    list << 2 << 34 << 12 << 34 << 13 << 89 << 56 << 45 << 3 << 1;
    int N, K;
    QTextStream in(stdin);
    qDebug() << "From:";
    N = in.readLine().toInt();
    qDebug() << "To:";
    K = in.readLine().toInt();
    if (!(N >= K || N > list.count() || K > list.count())){
        QMutableListIterator<int> it(list);
        int i = 0;
        it.next();
        while(it.hasNext()) {
            if (i >= N && i <= K) {
                it.remove();
            }
            it.next();
            i++;
        }
        qDebug() << list;
    }
    return a.exec();
}
