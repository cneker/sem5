#ifndef SHIPPING_H
#define SHIPPING_H
#include <string>
#include "fuel.h"
#include "car.h"
#include "driver.h"

using namespace std;

class Shipping
{
public:
    int id;
    Car *car;
    Driver *driver;
    Fuel *fuel;
    int mialege;
    string date;

    Shipping(int id, Car *car, Driver *driver, Fuel *fuel, int mialege, string date);
};

#endif // SHIPPING_H
