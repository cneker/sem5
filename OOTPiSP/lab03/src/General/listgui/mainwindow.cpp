#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 10; i++) {
    list.append(10+i*2);
     ui->textEdit->append(QString::number(list.at(i)) + " ");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked())
    {
        list.removeLast();
    }
    else if (ui->radioButton_2->isChecked())
    {
        int n=ui->lineEdit->text().toInt();
        list.push_front(n);
         //добавляем введенный в lineEdit элемент в начало
    }
    else if (ui->radioButton_3->isChecked())
    {
        int a,b;
        QStringList st = ui->lineEdit_2->text().split(",");
        a = st[0].toInt(); b = st[1].toInt();
        list.swapItemsAt(a, b);
    }
    ui->textEdit->clear();
    QList<int>::iterator it = list.begin();
    while(it != list.end())
    {
        ui->textEdit->append(QString::number(*it) + "");
        it++;
    }
}

