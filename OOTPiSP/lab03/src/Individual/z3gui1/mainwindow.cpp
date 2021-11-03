#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    QString output;
    for(int i = 0; i < 10; i++){
        list.append(rand() % 90);
        output.append(QString::number(list[i]) + " ");
    }
    ui->lineEdit->setText(output);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool comp(const int &one, const int &two){
    return one > two;
}

void MainWindow::on_pushButton_clicked()
{
    std::sort(list.begin(), list.end(), comp);
    QString output;
    QList<int>::iterator itt = list.begin();
    for(; itt < list.end(); ++itt){
        output.append(QString::number(*itt) + " ");
    }
    ui->lineEdit_2->setText(output);
}
