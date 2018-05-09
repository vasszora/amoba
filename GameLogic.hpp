#ifndef GAMELOGIC_HPP_INCLUDED
#define GAMELOGIC_HPP_INCLUDED

#include "GameField.hpp"
#include <vector>
class GameField;
class GameLogic
{
private:
    int player=1;
//    int gamesWon=0;
//    int gamesLost=0;
    int stepsMade=0;
    GameField * field;

public:
    GameLogic(GameField * _field) : field(_field) {};
    void switchPlayer ();
    int whichPlayer () {return player;};
    void computerPlayer();
    bool InARow(int howMany);
    bool InAColumn(int howMany);
    bool Across(int howMany);
    bool won();
    void stepMade() {stepsMade++;};
};

#endif // GAMELOGIC_HPP_INCLUDED
