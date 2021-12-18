#ifndef LIST_H
#define LIST_H

#include <interfaceobject.h>

class List : public InterfaceObject
{
public:
    List();
    virtual void add() override;
    virtual List * clone();
};

#endif // LIST_H
