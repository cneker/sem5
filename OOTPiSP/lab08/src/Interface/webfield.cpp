#include "webfield.h"

#include <iostream>

WebField::WebField() {
    std::cout << "Web field constructor" << std::endl;
}

void WebField::add() {
    std::cout << "Web Input Field added into interface" << std::endl;
}

Field* WebField::clone() {
    return new WebField(*this);
}
