#include <QCoreApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //1
    QFile file1("D:\\testi\\A.txt");
    QFile file2("D:\\testi\\B.txt");
    QFile file3("D:\\testi\\C.txt");
    if(file1.exists() && file1.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file1);
        QStringList buffer = stream.readAll().split(" ", Qt::SkipEmptyParts);
        if(file2.exists() && file2.open(QIODevice::WriteOnly)) {
            QTextStream streamB(&file2);
            int val = 0;
            for(int i = 0; i < buffer.count(); i++) {
                val += buffer[i].toInt();
            }
            streamB << QString::number(val);
            file2.close();
        }
        if(file3.exists() && file3.open(QIODevice::WriteOnly)) {
            QTextStream streamC(&file3);
            int val = buffer[buffer.count() - 1].toInt();
            streamC << QString::number(val);
            file3.close();
        }
    }

    return a.exec();
}
