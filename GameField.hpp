#ifndef GAMEFIELD_HPP_INCLUDED
#define GAMEFIELD_HPP_INCLUDED

#include "GameLogic.hpp"
#include "Window.hpp"
#include "NavigationButton.hpp"
#include <vector>

class GameLogic;
class GameField : public Window{
protected:
    static const int sizeOfField=15;
    const int gridSize=max_X/sizeOfField;
    GameLogic * logic;
    std::vector<NavigationButton *> navig; //a navigáló gombok
    //bool gameGoing=false;
    //bool wantToExit=false;
public:
    //GameField() {};
    virtual void openingScreen() {};
    virtual void openGame() {};
    virtual void exit() {};
    virtual void endScreen() {};
    virtual void eventLoop() {};
    virtual void newGame() {};
    //virtual ~GameField();
};

#endif // GAMEFIELD_HPP_INCLUDED
