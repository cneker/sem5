#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500, 500);
    auto timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(5);
}

void MainWindow::animate()
{
    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    QFont font("Times", 13, 10);
//    font.setBold(true);
//    painter.setFont(font);
//    painter.save();
//    painter.translate(20, 350);
//    painter.rotate(-90);
//    painter.drawText(0, 0, QString::fromStdString("Графические примитивы а библиотеке QT"));

//    painter.restore();

//    painter.translate(250, 250);

//    QPolygon polygon;
//    polygon << QPoint(15 + x2, 5 + y2) << QPoint(25 + x2, 5 + y2)
//            << QPoint(25 + x2, 12 + y2) << QPoint(35 + x2, 12 + y2)
//            << QPoint(35 + x2, 20 + y2) << QPoint(5 + x2, 20 + y2)
//            << QPoint(5 + x2, 10 + y2) << QPoint(15 + x2, 10 + y2);

//    QRect rect(x1 + 10, y1 - 15, 20, 20);

//    if (a >= 0)
//    {
//        x2=x1-(r*a*sin(a));
//        y2=y1+(r*a*cos(a));
//        rect.moveTo(x2 + 10, y2 - 15);
//        a-=0.01;
//    }

//    QPainterPath path;
//    path.addPolygon(polygon);
//    painter.fillPath(path, QBrush(Qt::yellow));
//    painter.fillRect(rect, QBrush(Qt::green));
//    painter.drawRect(rect);
//    painter.drawPolygon(polygon);
    painter.translate(250, 250);
    QPen pen(Qt::red, 2, Qt::SolidLine);
    painter.setPen(pen);
    QPolygon polygon;
    QRect rect1(20 + q, 0, 20, 20);
    QRect rect2(-30 + q, 10, 10, 10);
    QRect rect3(34 + q, 5, 3, 3);

    polygon << QPoint(0 + q, 0) << QPoint(10 + q, 0) << QPoint(10 + q, 10)
            << QPoint(-10 + q, 10) << QPoint(-10 + q, -10) << QPoint(20 + q, -10)
            << QPoint(20 + q, 20) << QPoint(-20 + q, 20) << QPoint(-20 + q, -20)
            << QPoint(30 + q, -20) << QPoint(30 + q, 0);



    q+=0.7;
    QPainterPath path;
    path.addPolygon(polygon);
    painter.fillPath(path, QBrush(Qt::yellow));
    painter.drawPolygon(polygon);
    painter.drawRect(rect1);
    painter.drawRect(rect2);
    painter.drawRect(rect3);
}
