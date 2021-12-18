#ifndef WEBFIELD_H
#define WEBFIELD_H


#include "field.h"

class WebField : public Field
{
public:
    WebField();
    void add() override;
    Field* clone() override;
};

#endif // WEBFIELD_H
