#include <QCoreApplication>
#include <QQueue>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QQueue<int> que;
    QTextStream in(stdin);
    qDebug() << "Elements in queue ";
    int count = (in.readLine()).toInt();
    qDebug() << "Values ";
    for (int i = 0; i < count; i++){
        int num = (in.readLine()).toInt();
        que.enqueue(num);
    }
    qDebug() << "queue consist of " << que;
    int len = que.length();
    for (int i = 0; i < len; i++){
        int num = que.dequeue();
        if (num % 2 == 0)
            num += 3;
        que.enqueue(num);
    }
    qDebug() << "queue consist of " << que;
    return a.exec();
}
