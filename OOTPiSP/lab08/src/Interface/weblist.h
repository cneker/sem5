#ifndef WEBLIST_H
#define WEBLIST_H

#include "list.h"

class WebList : public List
{
public:
    WebList();
    void add() override;
    List* clone() override;
};

#endif // WEBLIST_H
