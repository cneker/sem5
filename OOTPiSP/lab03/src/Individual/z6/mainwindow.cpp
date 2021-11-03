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
    QFile myFile("D:\\testi\\qt\\f.txt");
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
    QFile myFile("D:\\testi\\qt\\g.txt");
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
    stream << "Чётные числа: ";
    for(int i = 0; i < numbers.length(); i++) {
        if (numbers[i].toInt() % 2 == 0){
            stream << QString::number(numbers[i].toInt()) + " ";
        }
    }
    stream << "\r\n";
    stream << "Делятся на 3 и не делятся на 7: ";
    for(int i = 0; i < numbers.length(); i++) {
        if (numbers[i].toInt() % 3 == 0 && numbers[i].toInt() % 7 != 0){
            stream << QString::number(numbers[i].toInt()) + " ";
        }
    }
    stream << "\r\n";
    stream << "Точные квадраты: ";
    double temp;
    for(int i = 0; i < numbers.length(); i++) {
        temp = sqrt(numbers[i].toDouble());
        if ((temp - (int)temp) == 0){
            stream << QString::number(numbers[i].toInt()) + " ";
        }
    }
    myFile.close();

    if(!myFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this,"Ошибка","Файл нельзя открыть для записи");
        return;
    }
    QString buffer = stream.readAll();
    ui->textEdit_2->setText(buffer);
    myFile.close();
}

