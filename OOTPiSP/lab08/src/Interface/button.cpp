#include "button.h"
#include <iostream>

Button::Button()
{
    std::cout << "button created" << std::endl;
}

void Button::add()
{
    std::cout << "button is added" << std::endl;
}

Button * Button::clone()
{
    return new Button(*this);
}
