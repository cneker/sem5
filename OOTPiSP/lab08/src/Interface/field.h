#ifndef FIELD_H
#define FIELD_H


#include <interfaceobject.h>

class Field : public InterfaceObject
{
public:
    Field();
    virtual void add() override;
    virtual Field * clone();
};

#endif // FIELD_H
