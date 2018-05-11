#ifndef GAMELOGIC_HPP_INCLUDED
#define GAMELOGIC_HPP_INCLUDED

#include "GameField.hpp"
#include <vector>
class GameField;
class GameLogic
{
protected:
    int player=1;
//    int gamesWon=0;
//    int gamesLost=0;
    int stepsMade=0;
    GameField * field;

public:
    GameLogic(GameField * _field) : field(_field) {};
    void switchPlayer ();
    int whichPlayer () {return player;};
    //virtual void computerPlayer();
    virtual bool won() {return false;};
    virtual bool validStep(int i, int j) {return false;};
    void stepMade() {stepsMade++;};
    virtual ~GameLogic() {};
};

#endif // GAMELOGIC_HPP_INCLUDED
