#include <QCoreApplication>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStack<int> stack1, stack2;
    qDebug() << "num: "; QTextStream in(stdin);
    int count = (in.readLine()).toInt();
    //int count; in >> count;
    qDebug() << "el:";
    for (int i = 0; i < count; i++){
        int num = (in.readLine()).toInt();
        //int num; in >> num;
        stack1.push(num);
    }
    qDebug() << "Stack1 " << stack1;
    while(!stack1.empty()){
        int num = stack1.pop();
        if (num % 2 == 0)
            num += 3;
        stack2.push(num);
    }
    qDebug() << "Stack2 " << stack2;
    while(!stack2.empty())
        stack1.push(stack2.pop());
    qDebug() << "Stack1 " << stack1;

    return a.exec();
}
