#ifndef INTERFACE_H
#define INTERFACE_H


#include <list.h>
#include <field.h>
#include <button.h>
#include <language.h>

class Interface
{
public:
    Interface();
    void addList(List *list);
    void addInputField(Field *fiel);
    void addButton(Button *button);
    void addDisplayLanguage(Language *language);
    virtual Interface * clone();
};

#endif // INTERFACE_H
