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
    int A = ui->lineEdit->text().toInt();
    int B = ui->lineEdit_2->text().toInt();
    if (A != B)
        A = B = A + B;
    else
        A = B = 0;
    ui->lineEdit_3->setText(QString::number(A));
    ui->lineEdit_4->setText(QString::number(B));
}
