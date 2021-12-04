#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include <QtSql>
#include <algorithm>
#include "shipping.h"
#include "car.h"
#include "driver.h"
#include "fuel.h"

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

    void set_drivers_combobox();
    void set_fuel_combobox();

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Add *ui;

    list<Driver> drivers;
    list<Fuel> fuels;
};

#endif // ADD_H
