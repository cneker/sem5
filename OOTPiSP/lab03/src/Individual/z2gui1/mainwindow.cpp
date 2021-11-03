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
    int N = ui->lineEdit->text().toInt();
    QString output;
    int* arr = new int[N];
    srand(time(0));
    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 20;
        output.append(QString::number(arr[i]) + " ");
    }
    ui->lineEdit_2->setText(output);
    output.clear();
    output.append(QString::number(arr[0]) + " ");
    for(int i = 1; i < N - 1; i++){
        if(arr[i] % 2 == 0)
            arr[i] += arr[0];
        output.append(QString::number(arr[i]) + " ");
    }
    output.append(QString::number(arr[N - 1]) + " ");
    ui->lineEdit_3->setText(output);
    delete[] arr;
}

