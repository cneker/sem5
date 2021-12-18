#ifndef APPLICATION_H
#define APPLICATION_H


#include <interfacefactory.h>
#include <interface.h>

class Application
{
public:
    Application();
    Interface * createApplication(InterfaceFactory &factory);
};

#endif // APPLICATION_H
