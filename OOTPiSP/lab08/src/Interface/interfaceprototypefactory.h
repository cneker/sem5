#ifndef INTERFACEPROTOTYPEFACTORY_H
#define INTERFACEPROTOTYPEFACTORY_H


#include <interfacefactory.h>
#include <interface.h>
#include <field.h>
#include <button.h>
#include <language.h>
#include <list.h>

class InterfacePrototypeFactory : public InterfaceFactory
{
public:
    InterfacePrototypeFactory(Interface *interface, Field *field, Button *button, Language *language, List *list);
    virtual Interface* MakeInterface() const;
    virtual Field*  MakeField() const;
    virtual Button* MakeButton() const;
    virtual Language* MakeLanguage() const;
    virtual List* MakeList() const;
private:
    Interface* _prototypeInterface;
    Field* _prototypeField;
    Button* _prototypeButton;
    Language* _prototypeLanguage;
    List* _prototypeList;
};

#endif // INTERFACEPROTOTYPEFACTORY_H
