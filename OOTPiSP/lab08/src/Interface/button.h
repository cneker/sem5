#ifndef BUTTON_H
#define BUTTON_H


#include <interfaceobject.h>

class Button : public InterfaceObject {
public:
    Button();
    virtual void add() override;
    virtual Button * clone();
};

#endif // BUTTON_H
