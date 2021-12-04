#include "driver.h"

Driver::Driver(int id, string name, string surname, string birthdate)
{
    this->birthdate = birthdate;
    this->id = id;
    this->name = name;
    this->surname = surname;
}

void Driver::set_cars()
{
        QString str = "SELECT * FROM CarDriver WHERE DriverId =  '%1'";
        str = str.arg(this->id);
        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            while(query.next()) {
                QString number = query.value(rec.indexOf("CarNumber")).toString();

                str = "SELECT * FROM Car WHERE Number =  '%1'";
                str = str.arg(number);
                QSqlQuery querry;
                b = querry.exec(str);
                if(!b){
                    qDebug() << querry.lastError();
                }
                else{
                    QSqlRecord recc = querry.record();

                    querry.next();
                    QString brand = query.value(recc.indexOf("Brand")).toString();

                    Car car(number.toStdString(), brand.toStdString());
                    this->cars.push_back(car);
                }
            }
        }
}
