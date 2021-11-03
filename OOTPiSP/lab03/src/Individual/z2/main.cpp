#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //1
    int N;
    QTextStream in(stdin);
    qDebug() << "N:";
    N = in.readLine().toInt();
    int arr[N];
    qDebug() << "Enter elements:";
    for(int i = 0; i < N; i++){
        arr[i] = in.readLine().toInt();
    }
    for(int i = 1; i < N - 1; i++) {
        if (arr[i] % 2 == 0)
            arr[i] += arr[0];
    }
    qDebug() << "After:";
    for(int i = 0; i < N; i++){
        qDebug() << arr[i];
    }
    qDebug() << "\n\n\n\n";

    //2
    qDebug() << "M:";
    int M = in.readLine().toInt();
    qDebug() << "N:";
    N = in.readLine().toInt();
    int **arrr = new int*[M];
    for(int i = 0; i < M; i++) {
       arrr[i] = new int[N];
    }
    int temp[M], n[M];
    for(int i = 0; i < M; i++) {
        n[i] = 0;
        for(int j = 0; j < N; j++) {
            arrr[i][j] = i + j * 2;
            n[i] += arrr[i][j];
            cout << arrr[i][j] << " ";
        }
        n[i] = n[i] / N;
        cout << endl;
    }

    cout << endl;
    for(int i = 0; i < M; i++){
        temp[i] = 0;
        for(int j = 0; j < N; j++){
            if (arrr[i][j] > n[i])
                temp[i]++;
        }
        cout << temp[i] << "\n";
    }

    for(int i = 0; i < M; i++){
        delete []arrr[i];
    }
    delete []arrr;
    return a.exec();
}
