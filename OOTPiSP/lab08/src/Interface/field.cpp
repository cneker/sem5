#include "field.h"
#include <iostream>

Field::Field()
{
    std::cout << "field created" << std::endl;
}

void Field::add()
{
    std::cout << "field is added" << std::endl;
}

Field * Field::clone()
{
    return new Field(*this);
}
