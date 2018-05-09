#include "graphics.hpp"
#include "Widget.hpp"
#include "Window.hpp"
#include "GameField.hpp"
#include "GameLogic.hpp"
#include "Game.hpp"
#include "GameButton.hpp"
#include <iostream>
using namespace genv;


int main()
{
    Game * amoba = new Game();
    amoba->game();
    delete amoba;
    return 0;
}
