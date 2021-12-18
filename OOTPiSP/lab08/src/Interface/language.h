#ifndef LANGUAGE_H
#define LANGUAGE_H


#include <interfaceobject.h>

class Language : public InterfaceObject
{
public:
    Language();
    virtual void add() override;
    virtual Language * clone();
};

#endif // LANGUAGE_H
