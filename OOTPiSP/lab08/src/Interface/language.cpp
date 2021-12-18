#include "language.h"
#include <iostream>

Language::Language()
{
    std::cout << "language created" << std::endl;
}

void Language::add()
{
    std::cout << "language is added" << std::endl;
}

Language * Language::clone()
{
    return new Language(*this);
}
