#include "shipping.h"

Shipping::Shipping(int id, Car *car, Driver *driver, Fuel *fuel, int mialege, string date)
{
    this->id = id;
    this->car = car;
    this->date = date;
    this->driver = driver;
    this->fuel = fuel;
    this->mialege = mialege;
}
