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
    QFile myFile("D:\\testi\\1.txt");
    if(!myFile.exists()) {
        QMessageBox::warning(this,"Ошибка","Файл не найден");
        return;
    }
    if(!myFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this,"Ошибка","Файл нельзя открыть для чтения");
        return;
    }
    QTextStream stream(&myFile);
    QString buffer = stream.readAll();
    ui->textEdit->setText(buffer);
    myFile.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    QFile myFile("D:\\testi\\2.txt");
    if(!myFile.exists()) {
        QMessageBox::warning(this,"Ошибка","Файл не найден");
        return;
    }
    if(!myFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this,"Ошибка","Файл нельзя открыть для записи");
        return;
    }
    QTextStream stream(&myFile);
    QStringList numbers = ui->textEdit->toPlainText().split(" ", Qt::SkipEmptyParts);
    int val;
    for(int i = 0; i < numbers.length(); i++) {
        val = numbers[i].toInt() * 2;
        stream << QString::number(val) + " ";
    }
    myFile.close();
}

