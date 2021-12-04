#include "updatedelete.h"
#include "ui_updatedelete.h"

UpdateDelete::UpdateDelete(list<Driver> drivers, list<Fuel> fuels, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateDelete)
{
    ui->setupUi(this);
    this->drivers = drivers;
    this->fuels = fuels;
    set_drivers_combobox();
    set_fuel_combobox();
}

UpdateDelete::~UpdateDelete()
{
    delete ui;
}

void UpdateDelete::recieveData(Shipping *shipping)
{
    shippingId = shipping->id;
    QString driver = QString::number(shipping->driver->id);
    QString car = QString::fromStdString(shipping->car->number);
    QString fuel = QString::number(shipping->fuel->id);
    QString mialege = QString::number(shipping->mialege);
    QString date = QString::fromStdString(shipping->date);
    ui->comboBox->setCurrentText(driver);
    ui->comboBox_2->setCurrentText(car);
    ui->comboBox_3->setCurrentText(fuel);
    ui->lineEdit_4->setText(mialege);
    ui->lineEdit_5->setText(date);
}

void UpdateDelete::set_drivers_combobox()
{
    //сука где-то здесь я прям чую
        QString str = "SELECT * FROM Driver";
        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            while(query.next()) {
                int id = query.value(rec.indexOf("Id")).toInt();
                QString name = query.value(rec.indexOf("Name")).toString();
                QString surname = query.value(rec.indexOf("Surname")).toString();
                QString birthdate = query.value(rec.indexOf("Birthdate")).toString();

                Driver driver(id, name.toStdString(), surname.toStdString(), birthdate.toStdString());
                driver.set_cars();

                drivers.push_back(driver);
                //эта херня вызывает курент текст ченджет
                ui->comboBox->addItem(QString::number(driver.id));
            }
        }
        ui->comboBox_2->clear();
}

void UpdateDelete::set_fuel_combobox()
{
    ui->comboBox_3->clear();
    QString str = "SELECT * FROM Fuel";
    QSqlQuery query;
    bool b = query.exec(str);
    if(!b)
        qDebug() << query.lastError();
    else {
        QSqlRecord rec = query.record();
        while(query.next()) {
            int id = query.value(rec.indexOf("Id")).toInt();
            QString name = query.value(rec.indexOf("Brand")).toString();

            Fuel fuel(id, name.toStdString());
            fuels.push_back(fuel);

            ui->comboBox_3->addItem(QString::fromStdString(fuel.brand));
        }
    }
}


void UpdateDelete::on_pushButton_clicked()
{
    this->close();
}

//delete
void UpdateDelete::on_pushButton_3_clicked()
{
    QString str = "DELETE FROM Shipping WHERE Id = '%1'";
    str = str.arg(QString::number(shippingId));
    QSqlQuery query;
    query.exec(str);
    this->close();
}

//update
void UpdateDelete::on_pushButton_2_clicked()
{
    QString string = "UPDATE Shipping SET Car = '%2', Driver = '%3', Fuel = '%4', Mialege = '%5', Date = '%6' WHERE Id = '%1'";
    QString car = ui->comboBox_2->currentText();
    int driver = ui->comboBox->currentText().toInt();
    QString fuel = ui->comboBox_3->currentText();
    int mialege = ui->lineEdit_4->text().toInt();
    QString date = ui->lineEdit_5->text();
    int fuelId;
    QString str = "SELECT Id FROM Fuel WHERE Brand = '%1'";
    str = str.arg(fuel);
    QSqlQuery query;
    bool b = query.exec(str);
    QSqlRecord rec = query.record();
    query.next();
    fuelId = query.value(rec.indexOf("Id")).toInt();

    string = string.arg(shippingId).arg(car).arg(driver).arg(fuelId).arg(mialege).arg(date);
    b = query.exec(string);
    if(!b)
        qDebug() << query.lastError();
    this->close();
}

void UpdateDelete::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->clear();

    for(Driver driver : drivers)
    {
        if(driver.id == arg1.toInt())
        {
                for(Car car : driver.cars)
                {
                    ui->comboBox_2->addItem(QString::fromStdString(car.number));
                }
        }
    }
}

