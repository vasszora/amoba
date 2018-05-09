#include "Game.hpp"
#include "GameField.hpp"
#include "GameLogic.hpp"

Game::Game()
{
    field = new GameField;
}

void Game::game()
{
    field->eventLoop();
}
