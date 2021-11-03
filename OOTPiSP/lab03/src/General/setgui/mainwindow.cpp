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
    int from = ui->spinBox->value();
    int to = ui->spinBox_2->value();
    bool is = false;
    for(int i = from; i <= to; i++) {
        is = false;
        if (i % 3 == 0)
            ui->textEdit->setText(QString::number(i) + "\n" + ui->textEdit->toPlainText());
        for(int j = 2; j < i; j++) {
            if (i % j == 0) {
                ui->textEdit_3->setText(QString::number(i) + "\n" + ui->textEdit_3->toPlainText());
                is = true;
                break;
            }
        }
        if(!is)
            ui->textEdit_2->setText(QString::number(i) + "\n" + ui->textEdit_2->toPlainText());
    }
}

