#ifndef GARAJ_H
#define GARAJ_H

#include <QMainWindow>
#include "add.h"
#include "updatedelete.h"
#include <QtSql>
#include <list>
#include "shipping.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Garaj; }
QT_END_NAMESPACE

class Garaj : public QMainWindow
{
    Q_OBJECT

public:
    Garaj(QWidget *parent = nullptr);

    ~Garaj();

signals:
    void sendData(Shipping *shipping);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_6_clicked();

private:
    Ui::Garaj *ui;
    UpdateDelete *updel;
    list<Shipping> shippings;
    list<Driver> drivers;
    list<Car> cars;
    list<Fuel> fuels;
    QSqlDatabase sbd;
    void SetTableItems();
    void SetDrivers();
    void SetCars();
    void SetFuels();
    void SetConnection();
};
#endif // GARAJ_H
