#include <iostream>
#include <language.h>
#include <application.h>
#include <interfaceprototypefactory.h>
#include <weblist.h>
#include <webinterfacefactory.h>
#include <webfield.h>

int main()
{
//    MazeGame game;
//    MazePrototypeFactory factory(new Maze(), new Wall(), new Room(1), new Door());
//    game.createMaze(factory);

    Application app;
    WebInterfaceFactory web;
    app.createApplication(web);

    InterfacePrototypeFactory prototype(new Interface(), new WebField(), new WebButton, new WebLanguage, new WebList);
    app.createApplication(prototype);

    return 0;
}
