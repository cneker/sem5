#include "interface.h"
#include <iostream>

Interface::Interface()
{

}

void Interface::addList(List *list)
{
    std::cout << "adding list to interface" << std::endl;
}

void Interface::addInputField(Field *field)
{
    std::cout << "adding input field to interface" << std::endl;
}

void Interface::addButton(Button *button)
{
    std::cout << "adding button to interface" << std::endl;
}

void Interface::addDisplayLanguage(Language *language)
{
    std::cout << "adding dispaly language to interface" << std::endl;
}

Interface * Interface::clone()
{
    return new Interface(*this);
}
