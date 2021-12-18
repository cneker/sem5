#ifndef INTERFACEFACTORY_H
#define INTERFACEFACTORY_H


#include <interface.h>
#include <button.h>
#include <field.h>
#include <language.h>
#include <list.h>

class InterfaceFactory
{
public:
    InterfaceFactory();
    virtual Interface* makeInterface() const;
    virtual Button* makeButton() const;
    virtual Field* makeField() const;
    virtual Language* makeLanguage() const;
    virtual List* makeList() const;
};

#endif // INTERFACEFACTORY_H
