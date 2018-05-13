#include "graphics.hpp"
#include "Game.hpp"
using namespace genv;


int main()
{
    Game * amoba = new Game();
    amoba->game();
    delete amoba;
    return 0;
}
