#include "webinterfacefactory.h"
#include <iostream>
WebInterfaceFactory::WebInterfaceFactory() {
    std::cout << "web interface factory constructor" << std::endl;
}

Field* WebInterfaceFactory::makeField() const {
    return new WebField();
}

Button* WebInterfaceFactory::makeButton() const {
    return new WebButton();
}

Language* WebInterfaceFactory::makeLanguage() const {
    return new WebLanguage();
}

List* WebInterfaceFactory::makeList() const {
    return new WebList();
}
