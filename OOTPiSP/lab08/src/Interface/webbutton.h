#ifndef WEBBUTTON_H
#define WEBBUTTON_H

#include "button.h"

class WebButton : public Button
{
public:
    WebButton();
    void add() override;
    Button* clone() override;
};


#endif // WEBBUTTON_H
