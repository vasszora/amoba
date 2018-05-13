#ifndef GAMELOGIC_HPP_INCLUDED
#define GAMELOGIC_HPP_INCLUDED

#include "GameField.hpp"
#include <vector>
class GameField;
class GameLogic
{
protected:
    int player=1;
    int stepsMade=0;

public:
    GameLogic() {};
    void switchPlayer ();
    int whichPlayer () {return player;};
    virtual bool won() {return false;};
    virtual bool validStep(int i, int j) {return false;};
    virtual void stepMade(int i, int j) {};
    virtual bool gameOver()=0;
    virtual ~GameLogic() {};
};

#endif // GAMELOGIC_HPP_INCLUDED
