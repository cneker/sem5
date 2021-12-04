#ifndef UPDATEDELETE_H
#define UPDATEDELETE_H

#include <QWidget>
#include "shipping.h"

namespace Ui {
class UpdateDelete;
}

class UpdateDelete : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateDelete(list<Driver> drivers, list<Fuel> fuels, QWidget *parent = nullptr);
    ~UpdateDelete();

    list<Driver> drivers;
    list<Fuel> fuels;

    void set_drivers_combobox();
    void set_fuel_combobox();

public slots:
    void recieveData(Shipping *shipping);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::UpdateDelete *ui;
    int shippingId;

};

#endif // UPDATEDELETE_H
