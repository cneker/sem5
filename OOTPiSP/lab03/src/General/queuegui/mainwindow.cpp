#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 1; i < 5 ;i++) {
       que.enqueue(i);
       ui->textEdit->setText(QString::number(i) + "\n" + ui->textEdit->toPlainText());
    }
    n = 4;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    n++;
    que.enqueue(n);
    ui->textEdit->clear();
    for(int i = 0; i < que.count(); i++) {
        ui->textEdit->setText(QString::number(que[i]) + "\n" + ui->textEdit->toPlainText());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString::number(que.dequeue()));
    ui->textEdit->clear();
    for(int i = 0; i < que.count(); i++) {
        ui->textEdit->setText(QString::number(que[i]) + "\n" + ui->textEdit->toPlainText());
    }
}

