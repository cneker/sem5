#include "interfaceprototypefactory.h"

InterfacePrototypeFactory::InterfacePrototypeFactory(Interface *interface, Field *field, Button *button, Language *language, List *list)
{
    this->_prototypeButton = button;
    this->_prototypeField = field;
    this->_prototypeInterface = interface;
    this->_prototypeLanguage = language;
    this->_prototypeList = list;
}


Interface * InterfacePrototypeFactory::MakeInterface() const
{
    return this->_prototypeInterface->clone();
}

Field *  InterfacePrototypeFactory::MakeField() const
{
    return this->_prototypeField->clone();
}

Button * InterfacePrototypeFactory::MakeButton() const
{
    return this->_prototypeButton->clone();
}

Language * InterfacePrototypeFactory::MakeLanguage() const
{
    return this->_prototypeLanguage->clone();
}

List * InterfacePrototypeFactory::MakeList() const
{
    return this->_prototypeList->clone();
}
