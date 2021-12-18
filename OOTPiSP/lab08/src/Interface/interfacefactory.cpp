#include <interfacefactory.h>
#include <iostream>

InterfaceFactory::InterfaceFactory()
{
    std::cout << "creating interface factory" << std::endl;
}

Interface* InterfaceFactory::makeInterface() const
{
    return new Interface();
}

Button* InterfaceFactory::makeButton() const
{
    return new Button();
}

Field* InterfaceFactory::makeField() const
{
    return new Field();
}

Language* InterfaceFactory::makeLanguage() const
{
    return new Language();
}

List* InterfaceFactory::makeList() const
{
    return new List();
}
