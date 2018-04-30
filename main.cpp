#include "graphics.hpp"
#include "Widget.hpp"
#include "Window.hpp"
#include "GameField.hpp"
#include "GameLogic.hpp"
#include <iostream>
using namespace genv;


int main()
{
    Window* field=new GameField;
    field->eventLoop();
    delete field;
    return 0;
}
