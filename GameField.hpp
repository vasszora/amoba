#ifndef GAMEFIELD_HPP_INCLUDED
#define GAMEFIELD_HPP_INCLUDED

#include "GameLogic.hpp"
#include "Window.hpp"
#include "SimpleText.hpp"
#include "NavigationButton.hpp"
#include <map>
#include <vector>

class GameLogic;
class GameField : public Window{
protected:
    static const int sizeOfField=15;
    //ez logicba
    const int gridSize=max_X/sizeOfField;
    GameLogic * logic; //ez kell ebbe?
    //a kiírandó stringek és hozzájuk tartozó SimpleText pointerek
    //std::map<std::string, SimpleText*> names;
    std::vector<NavigationButton *> navig;
    bool gameGoing=false;
    bool wantToExit=false;
public:
    //GameField();
    virtual void openingScreen() {};
    virtual void openGame() {};
    virtual void exit() {};
    virtual void endScreen() {};
    virtual void eventLoop() {};
    virtual void newGame() {};
    /*ezek logicba
    void changeState(int player, int i, int j);
    bool isFull();*/
    /*ezek nem is biztos hogy kellenek..
    int gridWidth() {return gridSize;};
    int fieldSize() {return sizeOfField;};*/
    //virtual ~GameField();
};

#endif // GAMEFIELD_HPP_INCLUDED
