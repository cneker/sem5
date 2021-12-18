#ifndef WEBLANGUAGE_H
#define WEBLANGUAGE_H

#include "language.h"

class WebLanguage : public Language
{
public:
    WebLanguage();
    void add() override;
    Language* clone() override;
};


#endif // WEBLANGUAGE_H
