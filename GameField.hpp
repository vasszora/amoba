#ifndef GAMEFIELD_HPP_INCLUDED
#define GAMEFIELD_HPP_INCLUDED

#include "GameLogic.hpp"
#include "Window.hpp"
#include "SimpleText.hpp"
#include "NavigationButton.hpp"
#include <map>
#include <iostream>
#include <vector>

class GameLogic;
class GameField : public Window{
protected:
    static const int sizeOfField=15;
    int stateOfField[sizeOfField][sizeOfField] ={};  //0-ra inicializalva
    // 0, 1-es es 2-es szammal jelzem majd, hogy milyen allapotban vannak a palya egyes elemei.
    //0-ures. 1-elso jatekose. 2-kettes jatekose.
    const int gridSize=max_X/sizeOfField;
    GameLogic * logic;
    //a kiírandó stringek és hozzájuk tartozó SimpleText pointerek
    std::map<std::string, SimpleText*> names;
    std::vector<NavigationButton *> navig;
    bool gameGoing=false;
    bool wantToExit=false;
public:
    GameField();
    void openingScreen();
    void openGame();
    void exit();
    void endScreen();
    void eventLoop();
    void newGame();
    void emptyField();
    int state(int i, int j) {return stateOfField[i][j];};
    void changeState(int player, int i, int j);
    bool isFull();
    int gridWidth() {return gridSize;};
    int fieldSize() {return sizeOfField;};
    //~GameField();
};

#endif // GAMEFIELD_HPP_INCLUDED
