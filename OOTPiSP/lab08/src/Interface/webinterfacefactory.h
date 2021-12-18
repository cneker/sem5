#ifndef WEBINTERFACEFACTORY_H
#define WEBINTERFACEFACTORY_H
#include "interfacefactory.h"
#include "button.h"
#include "field.h"
#include "language.h"
#include "weblist.h"
#include "webfield.h"
#include "webbutton.h"
#include "weblanguage.h"

class WebInterfaceFactory : public InterfaceFactory
{
public:
    WebInterfaceFactory();
    Field* makeField() const override;
    Button* makeButton() const override;
    Language* makeLanguage() const override;
    List* makeList() const override;
};

#endif // WEBINTERFACEFACTORY_H
