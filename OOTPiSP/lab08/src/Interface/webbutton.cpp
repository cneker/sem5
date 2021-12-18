#include "webbutton.h"

#include <iostream>

WebButton::WebButton() {
    std::cout << "Web button constructor" << std::endl;
}

void WebButton::add() {
    std::cout << "Web Button added into interface" << std::endl;
}

Button* WebButton::clone() {
    return new WebButton(*this);
}
