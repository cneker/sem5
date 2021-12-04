#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include <list>
#include <QtSql>
#include "car.h"

using namespace std;

class Driver
{
private:
    QSqlDatabase sbd;

public:
    int id;
    string name;
    string surname;
    string birthdate;
    list<Car> cars;

    Driver(int id, string name, string surname, string birthdate);
    void set_cars();
};

#endif // DRIVER_H
