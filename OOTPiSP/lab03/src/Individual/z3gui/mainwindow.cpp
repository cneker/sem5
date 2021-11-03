#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString output;
    srand(time(0));
    for(int i = 0; i < 10; i++){
        list.append(rand() % 90);
        output.append(QString::number(list[i]) + " ");
    }
    ui->textEdit->setText(output);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    int N, K;
    QString output;
    QList<int>::iterator itt = list.begin();
    for(; itt < list.end(); ++itt){
        output.append(QString::number(*itt) + " ");
    }
    ui->textEdit->setText(output);
    N = ui->lineEdit->text().toInt();
    K = ui->lineEdit_2->text().toInt();
    if (!(N >= K || N > list.count() || K > list.count())){
        QMutableListIterator<int> it(list);
        int i = 0;
        it.next();
        while(it.hasNext()) {
            if (i >= N && i <= K) {
                it.remove();
            }
            it.next();
            i++;
        }
    }
    output.clear();
    QList<int>::iterator i = list.begin();
    for(; i < list.end(); ++i){
        output.append(QString::number(*i) + " ");
    }
    ui->textEdit_2->setText(output);
}

