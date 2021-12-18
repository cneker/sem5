#include "weblist.h"

#include <iostream>

WebList::WebList() {
    std::cout << "Web language constructor" << std::endl;
}

void WebList::add() {
    std::cout << "Web List added into interface" << std::endl;
}

List* WebList::clone() {
    return new WebList(*this);
}
