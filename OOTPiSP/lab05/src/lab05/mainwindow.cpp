#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Artist *art = new Artist();
    art->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    Cd *cd = new Cd();
    cd->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    Track *track = new Track;
    track->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    if(sbd.open()) {
        QString name = ui->lineEdit->text();
        QString str = "SELECT id FROM artist WHERE name = '%1';";
        str = str.arg(name);

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            int artistid = 0;
            if(query.next()) {
                artistid = query.value(rec.indexOf("id")).toInt();

                str = "SELECT id FROM cd WHERE artistid = '%1';";
                str = str.arg(artistid);

                b = query.exec(str);
                if(!b)
                    qDebug() << query.lastError();
                else {
                    int count = 0;
                    while(query.next())
                        count++;
                    QMessageBox msg;
                    msg.setText(name + " выпустил " + QString::number(count) + " дисков");
                    msg.exec();
                }
            }
            else {
                QMessageBox msg;
                msg.setText("Такого исполнителя нет!");
                msg.exec();
            }
        }
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(sbd.open()) {
        QString title = ui->lineEdit_2->text();
        QString str = "SELECT id FROM cd WHERE title = '%1';";
        str = str.arg(title);

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            int cdid = 0;
            if(query.next()){
                cdid = query.value(rec.indexOf("id")).toInt();

                str = "SELECT id FROM track WHERE cdid = '%1';";
                str = str.arg(cdid);

                b = query.exec(str);
                if(!b)
                    qDebug() << query.lastError();
                else {
                    int count = 0;
                    while(query.next())
                        count++;
                    QMessageBox msg;
                    msg.setText("Количество треков на диске " + title + ": " + QString::number(count));
                    msg.exec();
                }
            }
            else {
                QMessageBox msg;
                msg.setText("Такого диска нет!");
                msg.exec();
            }
        }
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(sbd.open()) {
        QString year = ui->lineEdit_3->text();
        QString str = "SELECT * FROM cd WHERE year = '%1';";
        str = str.arg(year);

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            int count = 0;
            while(query.next())
                count++;
            QMessageBox msg;
            if (count != 0)
                msg.setText("Дисков вышло за " + year + "год: " + QString::number(count));
            else
                msg.setText("Ни один диск не вышел в этот год!");
            msg.exec();
        }
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(2);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setHorizontalHeaderLabels(QStringList() << "Имя" << "Страна");

    if(sbd.open()) {
        QString str = "SELECT * FROM artist";

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            int count = 0;
            while(query.next()) {
                table->insertRow(count);
                QString name = query.value(rec.indexOf("name")).toString();
                table->setItem(count, 0, new QTableWidgetItem(name));
                QString country = query.value(rec.indexOf("country")).toString();
                table->setItem(count, 1, new QTableWidgetItem(country));
                count++;
            }
        }
        table->show();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(3);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setHorizontalHeaderLabels(QStringList() << "Исполнитель" << "Название" << "Год");

    if(sbd.open()){
        QString str = "SELECT * FROM cd";

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            int count = 0;
            while(query.next()) {
                int artid = query.value(rec.indexOf("artistid")).toInt();
                QString title = query.value(rec.indexOf("title")).toString();
                int year = query.value(rec.indexOf("year")).toInt();
                str = "SELECT name FROM artist WHERE id = '%1';";
                str = str.arg(artid);
                QSqlQuery querry;
                b = querry.exec(str);
                if(!b)
                    qDebug() << querry.lastError();
                else {
                    QSqlRecord rc = querry.record();
                    querry.next();
                    QString name = querry.value(rc.indexOf("name")).toString();
                    table->insertRow(count);
                    table->setItem(count, 0, new QTableWidgetItem(name));
                    table->setItem(count, 1, new QTableWidgetItem(title));
                    table->setItem(count, 2, new QTableWidgetItem(QString::number(year)));
                }
                count++;
            }
        }
        table->show();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(4);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setHorizontalHeaderLabels(QStringList() << "Диск" << "Номер" << "Название" << "Длительность");

    if(sbd.open()) {
        QString str = "SELECT * FROM track";

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            int count = 0;
            while(query.next()) {
                int cdid = query.value(rec.indexOf("cdid")).toInt();
                int number = query.value(rec.indexOf("number")).toInt();
                QString title = query.value(rec.indexOf("title")).toString();
                int duration = query.value(rec.indexOf("duration")).toInt();
                str = "SELECT title FROM cd WHERE id = '%1';";
                str = str.arg(cdid);
                QSqlQuery querry;
                b = querry.exec(str);
                if(!b)
                    qDebug() << querry.lastError();
                else {
                    QSqlRecord rc = querry.record();
                    querry.next();
                    QString ttle = querry.value(rc.indexOf("title")).toString();
                    table->insertRow(count);
                    table->setItem(count, 0, new QTableWidgetItem(ttle));
                    table->setItem(count, 1, new QTableWidgetItem(QString::number(number)));
                    table->setItem(count, 2, new QTableWidgetItem(title));
                    table->setItem(count, 3, new QTableWidgetItem(QString::number(duration)));
                }
                count++;
            }
        }
        table->show();
    }
}

void MainWindow::SetConnection()
{
    sbd = QSqlDatabase::addDatabase("QSQLITE");
    sbd.setDatabaseName("D:\\SQLiteManager\\mydatabase.sqlite");
    if(!sbd.open()){
        qDebug() << sbd.lastError().text();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(sbd.open()) {
        QString _out = adasd;
        QString t_out = adasd;
        QString t_in = adasd;
        QString t_all = adasd;
        QString str = "SELECT id FROM reys WHERE t_out = '%1' AND t_in = '%2' AND = '%3';";
        str = str.arg(t_out).arg(t_in).arg(t_all);

        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QMessageBox msg;
            QString text = "Spisok ";
            QSqlRecord rec = query.record();
            while(query.next()){

                str = "SELECT id FROM machine WHERE _out = '%1';";
                str = str.arg(_out);
                QSqlQuery query2;
                b = query2.exec(str);
                if(!b)
                    qDebug() << query2.lastError();
                else {
                    while(query2.next())
                    {
                    QSqlRecord rc = query2.record();

                    int id = query2.value(rc.indexOf("id")).toInt();
                    text += QString::number(id) + " ";

                    }
                }
            }
            msg.setText(text);
            msg.exec();
        }
    }
}
