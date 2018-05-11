#include "Game.hpp"
#include "FiveInARowField.hpp"


Game::Game()
{
    field = new FiveInARowField;
}

void Game::game()
{
    field->eventLoop();
}
