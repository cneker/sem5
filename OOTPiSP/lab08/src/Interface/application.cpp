#include "application.h"
#include "list.h"
#include "button.h"
#include "field.h"
#include "language.h"

Application::Application()
{

}

Interface * Application::createApplication(InterfaceFactory &factory)
{
    Interface * interface = factory.makeInterface();
    Button* b1 = factory.makeButton();
    Field* f1 = factory.makeField();
    Language* l1 = factory.makeLanguage();
    List* lst1 = factory.makeList();

    interface->addButton(b1);
    interface->addDisplayLanguage(l1);
    interface->addInputField(f1);
    interface->addList(lst1);


    return  interface;
}
