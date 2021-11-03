#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    srand(time(0));
    int M = ui->lineEdit->text().toInt();
    int N = ui->lineEdit_2->text().toInt();
    QString output;
    if (M == 0 || N == 0)
        return;
    int **arr = new int*[M];
    for(int i = 0; i < M; i++) {
       arr[i] = new int[N];
    }
    int temp[M], n[M];
    for(int i = 0; i < M; i++) {
        n[i] = 0;
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 50;
            output.append(QString::number(arr[i][j]) + " ");
            n[i] += arr[i][j];
        }
        n[i] = n[i] / N;
        output.append("\n");
    }
    ui->textEdit->setText(output);
    for(int i = 0; i < M; i++){
        temp[i] = 0;
        for(int j = 0; j < N; j++){
            if (arr[i][j] > n[i])
                temp[i]++;
        }
        ui->textEdit_2->setText(QString::number(temp[i]) + "\n" + ui->textEdit_2->toPlainText());
    }
}
