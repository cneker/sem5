#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->ma->setFixedSize(ui->centralwidget->width(), ui->centralwidget->height());
    QStringList headers;
    headers << "sdf";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "U" << "I" << "R" << "Q");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    srand(time(0));
    for(int i = 0; i < 15; i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(rand() % 100 + 10)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(rand() % 100 + 10)));
        ui->tableWidget->item(i, 0)->setToolTip(QString::number(ui->tableWidget->item(i, 0)->text().toInt()));
        ui->tableWidget->item(i, 1)->setToolTip(QString::number(ui->tableWidget->item(i, 1)->text().toInt()));
    }

    R = new QShortcut(this);
    R->setKey(Qt::CTRL + Qt::Key_R);
    connect(R, SIGNAL(activated()), this, SLOT(on_R_clicked()));

    Q = new QShortcut(this);
    Q->setKey(Qt::CTRL + Qt::Key_Q);
    connect(Q, SIGNAL(activated()), this, SLOT(on_Q_clicked()));

    //ui->label_3->setText(QString::number(0));
    //ui->label_4->setText(QString::number(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_R_clicked()
{
    int count = 0;
    double U, I;
    for(int i = 0; i < 15; i++){
        U = ui->tableWidget->item(i, 0)->text().toInt();
        I = ui->tableWidget->item(i, 1)->text().toInt();
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(U / I)));
        if(ui->tableWidget->item(i, 2)->text().toDouble() >= 100 && ui->tableWidget->item(i, 2)->text().toDouble() <= 1000){
            ui->tableWidget->item(i, 2)->setBackground(Qt::red);
            count++;
        }
        ui->tableWidget->item(i, 2)->setToolTip(QString::number(ui->tableWidget->item(i, 2)->text().toInt()));
    }
    //ui->tableWidget->horizontalHeaderItem(2)->setText(QString::number(count));
    ui->label_3->setText(QString::number(count));
}


void MainWindow::on_Q_clicked()
{
    int count = 0;
    double t = 10.0;
    double R, I;
    double res;
    for(int i = 0; i < 15; i++){
        I = ui->tableWidget->item(i, 1)->text().toInt();
        R = ui->tableWidget->item(i, 2)->text().toDouble();
        res = I * I * R * t;
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(res)));
        if(ui->tableWidget->item(i, 3)->text().toDouble() >= 1000 && ui->tableWidget->item(i, 3)->text().toDouble() <= 10000){
            ui->tableWidget->item(i, 3)->setBackground(Qt::blue);
            count++;
        }
        ui->tableWidget->item(i, 3)->setToolTip(QString::number(ui->tableWidget->item(i, 3)->text().toInt()));
    }
    //ui->tableWidget->horizontalHeaderItem(3)->setText(QString::number(count));
    ui->label_4->setText(QString::number(count));
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    ui->tableWidget->item(item->row(), item->column())
            ->setToolTip(QString::number(ui->tableWidget->item(item->row(), item->column())->text().toDouble()));
}
