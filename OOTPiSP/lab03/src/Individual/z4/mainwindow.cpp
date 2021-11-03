#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString output;
    srand(time(0));
    for(int i = 0; i < 8; i++){
        que.enqueue(rand() % 50 - 20);
        output.append(QString::number(que[i]) + " ");
    }
    ui->textEdit_3->setText(output);

    output.clear();

    for(int i = 0; i < 8; i++){
        st.append(rand() % 50);
        output.append(QString::number(st[i]) + " ");
    }
    ui->textEdit->setText(output);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStack<int> st1;
    for(int i = 0, j = st.count() - 1; i < st.count() && j >= 0; i++, j--){
        st1.append(st[i] * st[j]);
        ui->textEdit_2->setText(QString::number(st1[i]) + " " + ui->textEdit_2->toPlainText());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    srand(time(0));
    int n, k;
    QString output;
    for(int i = 0, j = 1; i < 8 && j < 8; i += 2, j += 2){
        n = que.dequeue();
        k = que.dequeue();
        que.enqueue((n + k) / 2);
    }
    for(int i = 0; i < que.count(); i++){
        output.append(QString::number(que[i]) + " ");
    }
    ui->textEdit_4->setText(output);
}

