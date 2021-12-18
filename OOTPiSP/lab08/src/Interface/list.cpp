#include "list.h"
#include <iostream>

List::List()
{
    std::cout << "list created" << std::endl;
}

void List::add()
{
    std::cout << "list is added" << std::endl;
}

List * List::clone()
{
    return new List(*this);
}
