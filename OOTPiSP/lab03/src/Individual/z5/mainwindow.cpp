#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString output;
    cars << "bmw";
    cars << "audi";
    cars << "ford";
    cars << "fiat";
    cars << "lada";
    QSet<QString>::iterator it = cars.begin();
    for(; it != cars.end(); ++it)
        output.append(*it + " ");
    ui->textEdit_3->setText(output);

    output.clear();
    Belarus << "bmw" << "audi" << "ford";
    USA << "bmw" << "audi";
    Russia << "bmw" << "audi";

    output.append("Belarus: ");
    it = Belarus.begin();
    for(; it != Belarus.end(); ++it)
        output.append(*it + " ");
    output.append("\n");
    output.append("USA: ");
    it = USA.begin();
    for(; it != USA.end(); ++it)
        output.append(*it + " ");
    output.append("\n");
    output.append("Russia: ");
    it = Russia.begin();
    for(; it != Russia.end(); ++it)
        output.append(*it + " ");
    ui->textEdit_2->setText(output);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString output;
    QSet<QString> temp, unite, all, tmp;
    unite = Belarus;
    unite.unite(USA);
    unite.unite(Russia);

    output.append("Доставлены во все страны: ");
    temp = Belarus;
    temp.intersect(USA);
    temp.intersect(Russia);
    all = temp;
    QSet<QString>::iterator it = temp.begin();
    for(; it != temp.end(); ++it)
        output.append(*it + " ");

    output.append("\nДоставлены в некоторые страны: ");
    temp = cars;
    temp.subtract(all);
    tmp = cars;
    tmp.subtract(unite);
    temp.subtract(tmp);
    it = temp.begin();
    for(; it != temp.end(); ++it)
        output.append(*it + " ");

    output.append("\nНе доставлены ни в одну страну: ");
    temp = cars;
    temp.subtract(unite);

    it = temp.begin();
    for(; it != temp.end(); ++it)
        output.append(*it + " ");
    ui->textEdit->setText(output);
}
