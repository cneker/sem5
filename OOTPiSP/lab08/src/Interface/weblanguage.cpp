#include "weblanguage.h"

#include <iostream>

WebLanguage::WebLanguage() {
    std::cout << "Web language constructor" << std::endl;
}

void WebLanguage::add() {
    std::cout << "Web Interface Language added into interface" << std::endl;
}

Language* WebLanguage::clone() {
    return new WebLanguage(*this);
}
